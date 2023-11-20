%{

#include "Table_des_symboles.h"

#include <stdio.h>
#include <stdlib.h>
  
extern int yylex();
extern int yyparse();

void yyerror (char* s) {
  printf ("%s\n",s);
  exit(0);
  }
		
 int depth=0; // block depth
 
 
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
| glob_decl_list decl PV       {}
|                              {} // empty glob_decl_list shall be forbidden, but usefull for offset computation

// I. Functions

fun : type fun_head fun_body   {}
;

fun_head : ID PO PF            {
  // Pas de déclaration de fonction à l'intérieur de fonctions !
  if (depth>0) yyerror("Function must be declared at top level~!\n");
  }

| ID PO params PF              {
   // Pas de déclaration de fonction à l'intérieur de fonctions !
  if (depth>0) yyerror("Function must be declared at top level~!\n");
 }
;

params: type ID vir params     {} // récursion droite pour numéroter les paramètres du dernier au premier
| type ID                      {}


vir : VIR                      {}
;

fun_body : AO block AF         {}
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
| ID                           {}
;

type
: typename                     {}
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

ao : AO                       {}
;

af : AF                       {}
;


// IV.1 Affectations

aff : ID EQ exp               {}
;


// IV.2 Return
ret : RETURN exp              {}
| RETURN PO PF                {}
;

// IV.3. Conditionelles
//           N.B. ces rêgles génèrent un conflit déclage reduction
//           qui est résolu comme on le souhaite par un décalage (shift)
//           avec ELSE en entrée (voir y.output)

cond :
if bool_cond inst  elsop       {}
;

elsop : else inst              {}
|                  %prec IFX   {} // juste un "truc" pour éviter le message de conflit shift / reduce
;

bool_cond : PO exp PF         {}
;

if : IF                       {}
;

else : ELSE                   {}
;

// IV.4. Iterations

loop : while while_cond inst  {}
;

while_cond : PO exp PF        {}

while : WHILE                 {}
;


// V. Expressions

exp
// V.1 Exp. arithmetiques
: MOINS exp %prec UNA         {}
         // -x + y lue comme (- x) + y  et pas - (x + y)
| exp PLUS exp                {}
| exp MOINS exp               {}
| exp STAR exp                {}
| exp DIV exp                 {}
| PO exp PF                   {}
| ID                          {}
| app                         {}
| NUM                         {}
| DEC                         {}


// V.2. Booléens

| NOT exp %prec UNA           {}
| exp INF exp                 {}
| exp SUP exp                 {}
| exp EQUAL exp               {}
| exp DIFF exp                {}
| exp AND exp                 {}
| exp OR exp                  {}

;

// V.3 Applications de fonctions

app : ID PO args PF           {}
;

args :  arglist               {}
|                             {}
;

arglist : arglist VIR exp     {} // récursion gauche pour empiler les arguements de la fonction de gauche à droite
| exp                         {}
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
return track[sp-1].int_value;\n\
}\n";  

 printf("%s\n",header); // ouput header
  
return yyparse ();
 
 
} 
