%{

#include "Table_des_symboles.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  
extern int yylex();
extern int yyparse();

void yyerror (char* s) {
  printf ("%s\n",s);
  exit(0);
  }
		
//----------- Tracker variables 
 int num_cond=-1; //Numéro de condition

 int depth=0; // block depth
 int offset=0; // block offset

 int convert=1;//convert int to float
 int store=0;//STOREP
 int NumWhile=-1; //Numéro de condition while
 int inside=0;// inside block
 int insidemain=0;
 int param_num=0; // number of paramaters

 char* id;

 void printStackAccess(int depth, char* res) {
    if (depth==0) {strcpy(res, "bp");}
    else{ strcpy(res, "stack");
    for (int i = 1; i < depth; i++) {
        strcat(res, "[stack");
    }
    strcat(res, "[bp]");
    for (int i = 1; i < depth; i++) {
        strcat(res, "]");
    }
    }
}

 char* type;
 int typet;
 int bdl;

 int makeOffset(){
  return offset++;
 }

%}

%union { 
  struct ATTRIBUTE * symbol_value;
  char * string_value;
  int int_value;
  float float_value;
  int type_value;
  int label_value;
  int offset_value;
}

%token <int_value> NUM
%token <float_value> DEC


%token INT FLOAT VOID

%token <string_value> ID
%token AO AF PO PF PV VIR
%token RETURN  EQ
%token <label_value> IF ELSE WHILE

%token <label_value> AND OR NOT DIFF EQUAL SUP INF
%token PLUS MOINS STAR DIV
%token DOT ARR

%nonassoc IFX
%left OR                       // higher priority on ||
%left AND                      // higher priority on &&
%left DIFF EQUAL SUP INF       // higher priority on comparison
%left PLUS MOINS               // higher priority on + - 
%left STAR DIV                 // higher priority on * /
%left DOT ARR                  // higher priority on . and -> 
%nonassoc UNA                  // highest priority on unary operator
%nonassoc ELSE


%{
char * type2string (int c) {
  switch (c)
    {
    case INT:
      return("int");
    case FLOAT:
      return("float");
    case VOID:
      return("void");
    default:
      return("type error");
    }  
};

  
  %}


%start prog  

// liste de tous les non terminaux dont vous voulez manipuler l'attribut
%type <type_value> type exp  typename
%type <string_value> fun_head

 /* Attention, la rêgle de calcul par défaut $$=$1 
    peut créer des demandes/erreurs de type d'attribut */

%%

 // O. Déclaration globale

prog : glob_decl_list              {}

glob_decl_list : glob_decl_list fun {}
| glob_decl_list decl PV       {offset++;}
|                              {} // empty glob_decl_list shall be forbidden, but usefull for offset computation

// I. Functions

fun : type fun_head fun_body   {}
;

fun_head : ID PO PF            {
  // Pas de déclaration de fonction à l'intérieur de fonctions !
  if (depth>0) yyerror("Function must be declared at top level~!\n");
  if(strcmp($1, "main")==0){
    printf("void pcode_main() {\n");
    inside=1;
    insidemain=1;
  }
  }

| ID PO params PF              {
   // Pas de déclaration de fonction à l'intérieur de fonctions !
  if (depth>0) yyerror("Function must be declared at top level~!\n");
  else if(strcmp($1, "main")!=0){
    inside =1;
    printf("void pcode_%s() {\n", $1);
    for(int i=1; i<(param_num+1); i++){
      printf("// Argument  of function %s in TDS with offset -%d\n", $1, i );
    }
  }
 }
;

params: type ID vir params     {param_num++;                      
                                attribute r = makeSymbol(typet, -param_num, 1);
                                sid sym = string_to_sid($2);
                                r = set_symbol_value(sym, r);}
                                 // récursion droite pour numéroter les paramètres du dernier au premier

| type ID                      {param_num++;                           
                                attribute r = makeSymbol(typet, -param_num, 1);
                                sid sym = string_to_sid($2);
                                r = set_symbol_value(sym, r);
                                }


vir : VIR                      {}
;

fun_body : fao block faf       {}
;

fao : AO                       {}
;
faf : AF                       {}
;


// II. Block
block:
decl_list inst_list            {}
;

// III. Declarations

decl_list : decl_list decl PV   {} 
|                               {}
;

decl: var_decl                  {}
;

var_decl : type vlist          {}
;

vlist: vlist vir ID            {} // récursion gauche pour traiter les variables déclararées de gauche à droite
| ID                           {depth=inside;
                                if(insidemain==1){
                                  makeOffset();
                                  insidemain=0;
                                }
                                attribute r = makeSymbol(typet, offset, depth);
                                sid sym = string_to_sid($1);
                                $<symbol_value>0 = set_symbol_value(sym, r);
                                if(type=="int"){
                                  printf("// Declare %s of type %s with offset %d at depth %d \nLOADI(0)\n\n", $1, type,offset, depth);
                                }
                                else if(type=="float"){
                                  printf("// Declare %s of type %s with offset %d at depth %d \nLOADF(0.0)\n\n", $1, type,offset, depth);
                                }}
;

type
: typename                     {typet=$1;type=type2string($1);}
;

typename
: INT                          {$$=INT;}
| FLOAT                        {$$=FLOAT;}
| VOID                         {$$=VOID;}
;

// IV. Intructions

inst_list: inst_list inst   {} 
| inst                      {}
;

pv : PV                       {}
;
 
inst:
ao block af                   {}
| aff pv                      {}
| ret pv                      {}
| cond                        {}
| loop                        {}
| pv                          {}
;

// Accolades explicites pour gerer l'entrée et la sortie d'un sous-bloc

ao : AO                       {printf("SAVEBP // entering block\n"); inside++;}
;

af : AF                       {if (inside>1) {remove_symbols(inside);};printf("RESTOREBP // exiting block\n");inside--;}
;


// IV.1 Affectations

aff : ID EQ exp               { sid sym = string_to_sid($1);
                                attribute r = get_symbol_value(sym);
                                if(r->depth==0){
                                  printf("STOREP(%d) // storing %s value\n", r->offset, $1);
                                }
                                else{
                                  char res[1000];
                                  printStackAccess(inside - r->depth, res);
                                  printf("STOREP(%s + %d) // storing %s value in current block\n", res, r->offset, $1);
                                }
                                }
;


// IV.2 Return
ret : RETURN  exp             {if(inside>1){printf("return;\n");}else{printf("return;\n}\n");}}
| RETURN PO PF cond               {printf("}\n");}
;

// IV.3. Conditionelles
//           N.B. ces rêgles génèrent un conflit déclage reduction
//           qui est résolu comme on le souhaite par un décalage (shift)
//           avec ELSE en entrée (voir y.output)

cond :
if bool_cond inst  elsop       {printf("End_%d:\n", $<label_value>0);printf("// Fin conditionelle %d\n", $<label_value>0);inside--;}
;

elsop : else inst              {}
|                  %prec IFX   {} // juste un "truc" pour éviter le message de conflit shift / reduce
;

bool_cond : PO exp PF         {printf("IFN(False_%d) \n// la condition %d est vraie\n", num_cond, num_cond);}
;

if : IF                       {num_cond++;$<label_value>0=num_cond;printf("// Debut conditionelle %d\n", $<label_value>0);}
;

else : ELSE                   {printf("GOTO(End_%d)\nFalse_%d\n",$<label_value>-3, $<label_value>-3);printf("//la condition %d est fausse\n", $<label_value>-3);};
;

// IV.4. Iterations

loop : while while_cond inst  {printf("GOTO(StartLoop_%d)\n//Fin boucle while %d\nEndLoop_%d:\n", NumWhile, NumWhile, NumWhile);NumWhile--;}
;

while_cond : PO exp PF        {printf("IFN(EndLoop_%d)\n// Debut boucle while %d \n", NumWhile, NumWhile);}

while : WHILE                 {NumWhile++;printf("StartLoop_%d: // chargement condition boucle while %d\n", NumWhile, NumWhile);}
;


// V. Expressions

exp
// V.1 Exp. arithmetiques
: MOINS exp %prec UNA         {}
         // -x + y lue comme (- x) + y  et pas - (x + y)
| exp PLUS exp                {if(($1==FLOAT && $3==INT) || ($3==FLOAT && $1==INT)){
                                    if(convert==1){
                                      printf("I2F");
                                      convert++;
                                    }
                                    else{
                                      printf("I2F%d", convert);
                                    }
                                    if($1==INT){
                                      printf(" // converting first arg to float\nADDF \n");
                                      $1=FLOAT;
                                    }
                                    else{
                                      printf(" // converting second arg to float\nADDF \n");
                                      $3==FLOAT;
                                    }
                                }
                                else if($1==FLOAT || $3==FLOAT){
                                  printf("ADDF \n");
                                }
                                else{
                                  printf("ADDI \n");
                                }}
| exp MOINS exp               {if(($1==FLOAT && $3==INT) || ($3==FLOAT && $1==INT)){
                                    if(convert==1){
                                      printf("I2F");
                                      convert++;
                                    }
                                    else{
                                      printf("I2F%d", convert);
                                    }
                                    if($1==INT){
                                      printf(" // converting first arg to float\nSUBF \n");
                                      $1=FLOAT;
                                    }
                                    else{
                                      printf(" // converting second arg to float\nSUBF \n");
                                      $3==FLOAT;
                                    }
                                }
                                else if($1==FLOAT || $3==FLOAT){
                                  printf("SUBF \n");
                                }
                                else{
                                  printf("SUBI \n");
                                }}
| exp STAR exp                {if(($1==FLOAT && $3==INT) || ($3==FLOAT && $1==INT)){
                                    if(convert==1){
                                      printf("I2F");
                                      convert++;
                                    }
                                    else{
                                      printf("I2F%d", convert);
                                    }
                                    if($1==INT){
                                      printf(" // converting first arg to float\nMULTF \n");
                                      $1=FLOAT;
                                    }
                                    else{
                                      printf(" // converting second arg to float\nMULTF \n");
                                      $3==FLOAT;
                                    }
                                }
                                else if($1==FLOAT || $3==FLOAT){
                                  printf("MULTF \n");
                                }
                                else{
                                  printf("MULTI \n");
                                }}
| exp DIV exp                 {if(($1==FLOAT && $3==INT) || ($3==FLOAT && $1==INT)){
                                    if(convert==1){
                                      printf("I2F");
                                      convert++;
                                    }
                                    else{
                                      printf("I2F%d", convert);
                                    }
                                    if($1==INT){
                                      printf(" // converting first arg to float\nDIVF \n");
                                      $1=FLOAT;
                                    }
                                    else{
                                      printf(" // converting second arg to float\nDIVF \n");
                                      $3==FLOAT;
                                    }
                                }
                                else if($1==FLOAT || $3==FLOAT){
                                  printf("DIVF \n");
                                }
                                else{
                                  printf("DIVI \n");
                                }}
| PO exp PF                   {}
| ID                          {attribute r = get_symbol_value($1);
                              if(type2string(r->type)=="float"){$$=FLOAT;}else if(type2string(r->type)=="int"){$$=INT;};
                              if(r->depth==0){
                                printf("LOADP(%d) // loading %s value\n", r->offset, $1);
                              }
                              else{
                                char res[1000];
                                printStackAccess(inside - r->depth, res);
                                printf("LOADP(%s+%d) // loading %s value\n", res, r->offset, $1);
                              }}
| app                         {printf("ENDCALL(%d)  // unloading %d args of function %s\n", param_num, param_num, id);}
| NUM                         {printf("LOADI(%d)\n", $1); $$=INT;}
| DEC                         {printf("LOADF(%f)\n", $1); $$=FLOAT;}


// V.2. Booléens

| NOT exp %prec UNA           {printf("NOT\n");}
| exp INF exp                 {if ($1==FLOAT || $3==FLOAT) {printf("LTF\n");}
                              else {printf("LTI\n");}}
| exp SUP exp                 {if ($1==FLOAT || $3==FLOAT) {printf("GTF\n");}
                              else {printf("GTI\n");}}
| exp EQUAL exp               {if ($1==FLOAT || $3==FLOAT) {printf("EQF\n");}
                              else {printf("EQI\n");}}
| exp DIFF exp                {if ($1==FLOAT || $3==FLOAT) {printf("NEQF\n");}
                              else {printf("NEQI\n");}}
| exp AND exp                 {printf("AND\n");}
| exp OR exp                  {printf("OR\n");}

;

// V.3 Applications de fonctions


app : fid PO args PF          {printf("RESTOREBP \n");}

fid : ID                      {id=$1;printf("// loading function %s arguments\n", $1);}

args :  arglist               {printf("CALL(pcode_%s) \n", id);}
|                             {}
;

arglist : arglist VIR exp     {printf("SAVEBP \n");} // récursion gauche pour empiler les arguements de la fonction de gauche à droite
| exp                         {if(param_num==1)printf("SAVEBP \n");}
;



%% 
int main () {

  /* Ici on peut ouvrir le fichier source, avec les messages 
     d'erreur usuel si besoin, et rediriger l'entrée standard 
     sur ce fichier pour lancer dessus la compilation.
   */

char * header=
"// PCode Header\n\
#include \"PCode.h\"\n\
\n\
int main() {\n\
pcode_main();\n\
return stack[sp-1].int_value;\n\
}\n";  

 printf("%s\n",header); // ouput header

  
return yyparse ();
 
 
} 

