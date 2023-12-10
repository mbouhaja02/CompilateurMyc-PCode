/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "lang.y"


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
    strcat(res, "[bp].int_value");
    for (int i = 1; i < depth; i++) {
        strcat(res, "].int_value");
    }
    }
}

 char* type;
 int typet;
 int bdl;
 int tab[10];
 char str[1000];
 char result[1000];

 void imprimerTableau(int tableau[], int taille) {
    for (int i = 0; i < taille; i++) {
        printf("%d\n", tableau[i]);
    }
}

int comparerValeur(int tableau[], int taille, int valeur) {
    for (int i = 0; i < taille; i++) {
        if (tableau[i] != valeur) {
            return 1;
        }
    }
    return 0;
}

 int makeOffset(){
  return offset++;
 }


#line 143 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    NUM = 258,                     /* NUM  */
    DEC = 259,                     /* DEC  */
    INT = 260,                     /* INT  */
    FLOAT = 261,                   /* FLOAT  */
    VOID = 262,                    /* VOID  */
    ID = 263,                      /* ID  */
    AO = 264,                      /* AO  */
    AF = 265,                      /* AF  */
    PO = 266,                      /* PO  */
    PF = 267,                      /* PF  */
    PV = 268,                      /* PV  */
    CO = 269,                      /* CO  */
    CF = 270,                      /* CF  */
    VIR = 271,                     /* VIR  */
    RETURN = 272,                  /* RETURN  */
    EQ = 273,                      /* EQ  */
    IF = 274,                      /* IF  */
    ELSE = 275,                    /* ELSE  */
    WHILE = 276,                   /* WHILE  */
    AND = 277,                     /* AND  */
    OR = 278,                      /* OR  */
    NOT = 279,                     /* NOT  */
    DIFF = 280,                    /* DIFF  */
    EQUAL = 281,                   /* EQUAL  */
    SUP = 282,                     /* SUP  */
    INF = 283,                     /* INF  */
    PLUS = 284,                    /* PLUS  */
    MOINS = 285,                   /* MOINS  */
    STAR = 286,                    /* STAR  */
    DIV = 287,                     /* DIV  */
    DOT = 288,                     /* DOT  */
    ARR = 289,                     /* ARR  */
    IFX = 290,                     /* IFX  */
    UNA = 291                      /* UNA  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define NUM 258
#define DEC 259
#define INT 260
#define FLOAT 261
#define VOID 262
#define ID 263
#define AO 264
#define AF 265
#define PO 266
#define PF 267
#define PV 268
#define CO 269
#define CF 270
#define VIR 271
#define RETURN 272
#define EQ 273
#define IF 274
#define ELSE 275
#define WHILE 276
#define AND 277
#define OR 278
#define NOT 279
#define DIFF 280
#define EQUAL 281
#define SUP 282
#define INF 283
#define PLUS 284
#define MOINS 285
#define STAR 286
#define DIV 287
#define DOT 288
#define ARR 289
#define IFX 290
#define UNA 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 73 "lang.y"
 
  struct ATTRIBUTE * symbol_value;
  char * string_value;
  int int_value;
  float float_value;
  int type_value;
  int label_value;
  int offset_value;

#line 278 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUM = 3,                        /* NUM  */
  YYSYMBOL_DEC = 4,                        /* DEC  */
  YYSYMBOL_INT = 5,                        /* INT  */
  YYSYMBOL_FLOAT = 6,                      /* FLOAT  */
  YYSYMBOL_VOID = 7,                       /* VOID  */
  YYSYMBOL_ID = 8,                         /* ID  */
  YYSYMBOL_AO = 9,                         /* AO  */
  YYSYMBOL_AF = 10,                        /* AF  */
  YYSYMBOL_PO = 11,                        /* PO  */
  YYSYMBOL_PF = 12,                        /* PF  */
  YYSYMBOL_PV = 13,                        /* PV  */
  YYSYMBOL_CO = 14,                        /* CO  */
  YYSYMBOL_CF = 15,                        /* CF  */
  YYSYMBOL_VIR = 16,                       /* VIR  */
  YYSYMBOL_RETURN = 17,                    /* RETURN  */
  YYSYMBOL_EQ = 18,                        /* EQ  */
  YYSYMBOL_IF = 19,                        /* IF  */
  YYSYMBOL_ELSE = 20,                      /* ELSE  */
  YYSYMBOL_WHILE = 21,                     /* WHILE  */
  YYSYMBOL_AND = 22,                       /* AND  */
  YYSYMBOL_OR = 23,                        /* OR  */
  YYSYMBOL_NOT = 24,                       /* NOT  */
  YYSYMBOL_DIFF = 25,                      /* DIFF  */
  YYSYMBOL_EQUAL = 26,                     /* EQUAL  */
  YYSYMBOL_SUP = 27,                       /* SUP  */
  YYSYMBOL_INF = 28,                       /* INF  */
  YYSYMBOL_PLUS = 29,                      /* PLUS  */
  YYSYMBOL_MOINS = 30,                     /* MOINS  */
  YYSYMBOL_STAR = 31,                      /* STAR  */
  YYSYMBOL_DIV = 32,                       /* DIV  */
  YYSYMBOL_DOT = 33,                       /* DOT  */
  YYSYMBOL_ARR = 34,                       /* ARR  */
  YYSYMBOL_IFX = 35,                       /* IFX  */
  YYSYMBOL_UNA = 36,                       /* UNA  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_prog = 38,                      /* prog  */
  YYSYMBOL_glob_decl_list = 39,            /* glob_decl_list  */
  YYSYMBOL_fun = 40,                       /* fun  */
  YYSYMBOL_fun_head = 41,                  /* fun_head  */
  YYSYMBOL_params = 42,                    /* params  */
  YYSYMBOL_vir = 43,                       /* vir  */
  YYSYMBOL_fun_body = 44,                  /* fun_body  */
  YYSYMBOL_fao = 45,                       /* fao  */
  YYSYMBOL_faf = 46,                       /* faf  */
  YYSYMBOL_block = 47,                     /* block  */
  YYSYMBOL_decl_list = 48,                 /* decl_list  */
  YYSYMBOL_decl = 49,                      /* decl  */
  YYSYMBOL_var_decl = 50,                  /* var_decl  */
  YYSYMBOL_vlist = 51,                     /* vlist  */
  YYSYMBOL_type = 52,                      /* type  */
  YYSYMBOL_typename = 53,                  /* typename  */
  YYSYMBOL_inst_list = 54,                 /* inst_list  */
  YYSYMBOL_pv = 55,                        /* pv  */
  YYSYMBOL_inst = 56,                      /* inst  */
  YYSYMBOL_ao = 57,                        /* ao  */
  YYSYMBOL_af = 58,                        /* af  */
  YYSYMBOL_aff = 59,                       /* aff  */
  YYSYMBOL_ret = 60,                       /* ret  */
  YYSYMBOL_cond = 61,                      /* cond  */
  YYSYMBOL_elsop = 62,                     /* elsop  */
  YYSYMBOL_bool_cond = 63,                 /* bool_cond  */
  YYSYMBOL_if = 64,                        /* if  */
  YYSYMBOL_else = 65,                      /* else  */
  YYSYMBOL_loop = 66,                      /* loop  */
  YYSYMBOL_while_cond = 67,                /* while_cond  */
  YYSYMBOL_while = 68,                     /* while  */
  YYSYMBOL_exp = 69,                       /* exp  */
  YYSYMBOL_app = 70,                       /* app  */
  YYSYMBOL_fid = 71,                       /* fid  */
  YYSYMBOL_args = 72,                      /* args  */
  YYSYMBOL_arglist = 73                    /* arglist  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Second part of user prologue.  */
#line 109 "lang.y"

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

  
  

#line 396 "y.tab.c"


#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   158

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  118

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   141,   141,   143,   144,   145,   149,   152,   162,   175,
     182,   190,   193,   196,   198,   204,   209,   210,   213,   216,
     219,   220,   256,   260,   261,   262,   267,   268,   271,   275,
     276,   277,   278,   279,   280,   285,   288,   294,   309,   310,
     319,   322,   323,   326,   329,   332,   337,   340,   342,   350,
     352,   375,   398,   421,   444,   445,   455,   456,   457,   462,
     463,   465,   467,   469,   471,   472,   479,   481,   483,   484,
     487,   488
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUM", "DEC", "INT",
  "FLOAT", "VOID", "ID", "AO", "AF", "PO", "PF", "PV", "CO", "CF", "VIR",
  "RETURN", "EQ", "IF", "ELSE", "WHILE", "AND", "OR", "NOT", "DIFF",
  "EQUAL", "SUP", "INF", "PLUS", "MOINS", "STAR", "DIV", "DOT", "ARR",
  "IFX", "UNA", "$accept", "prog", "glob_decl_list", "fun", "fun_head",
  "params", "vir", "fun_body", "fao", "faf", "block", "decl_list", "decl",
  "var_decl", "vlist", "type", "typename", "inst_list", "pv", "inst", "ao",
  "af", "aff", "ret", "cond", "elsop", "bool_cond", "if", "else", "loop",
  "while_cond", "while", "exp", "app", "fid", "args", "arglist", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-40)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-68)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -40,     2,   119,   -40,   -40,   -40,   -40,   -40,    -6,   -40,
       5,   -40,   -40,    -1,    11,    12,    60,   -40,   -40,   -40,
     -40,    18,   -40,    46,    52,    66,   114,   -40,   -40,    12,
     -40,   -40,    45,   -40,   -40,    51,   -40,   -40,    65,    71,
       6,   -40,   -40,   -40,    69,    69,   -40,    84,   -40,    96,
     119,    53,   -40,   -40,    99,     0,    53,    53,   115,   -40,
     117,   -40,   -40,   -40,   120,   -40,   -40,    53,     6,    53,
       6,   -40,    53,   115,   -40,    62,   -40,   -40,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,   -40,
     -40,    74,   109,    86,   -40,   -40,    10,   126,    39,    39,
      39,    39,   -26,   -26,   -40,   -40,   115,   122,   116,   -40,
     -40,   -40,     6,   -40,   -40,    53,   -40,   115
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     2,     1,    23,    24,    25,     3,     0,    18,
       0,    22,     4,    21,     0,    19,     0,    13,     6,    17,
      11,     0,     7,     0,     0,     0,     0,    20,     8,    10,
      14,    12,     0,    35,    28,     0,    44,    48,     0,     0,
      15,    34,    27,    17,     0,     0,    32,     0,    33,     0,
       0,     0,    57,    58,    55,     0,     0,     0,    38,    56,
       0,    16,    21,    26,     0,    30,    31,     0,     0,     0,
       0,     9,     0,    37,    39,     0,    59,    49,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    69,    36,
      29,     0,    42,     0,    46,    54,    64,    65,    63,    62,
      61,    60,    50,    51,    52,    53,    71,     0,    68,    43,
      45,    40,     0,    47,    66,     0,    41,    70
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -40,   -40,   -40,   -40,   -40,    89,   107,   -40,   -40,   -40,
     106,   -40,   124,   -40,   -40,     7,   -40,   -40,   -27,   -39,
     -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,
     -40,   -40,   -35,   -40,   -40,   -40,   -40
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,     7,    14,    23,    21,    18,    19,    31,
      25,    26,     8,     9,    15,    24,    11,    40,    41,    42,
      43,    90,    44,    45,    46,   111,    68,    47,   112,    48,
      70,    49,    75,    59,    60,   107,   108
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      58,    63,     3,    52,    53,    86,    87,    12,    54,    10,
      16,    72,    74,    13,    32,    33,    73,    65,    66,    34,
      17,    76,    77,    35,    56,    36,    27,    37,    20,    92,
      57,    94,    91,    39,    93,    80,    81,    82,    83,    84,
      85,    86,    87,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,    52,    53,    52,    53,    28,    54,
      29,    54,    55,    51,    72,     4,     5,     6,    84,    85,
      86,    87,    22,   116,    95,    56,    30,    56,    61,    62,
     117,    57,    34,    57,    78,    79,   109,    80,    81,    82,
      83,    84,    85,    86,    87,    67,    78,    79,   113,    80,
      81,    82,    83,    84,    85,    86,    87,    69,    78,    79,
     -67,    80,    81,    82,    83,    84,    85,    86,    87,     4,
       5,     6,    32,    33,     4,     5,     6,    34,    88,   110,
      89,    35,   115,    36,   114,    37,    50,    78,    79,    71,
      80,    81,    82,    83,    84,    85,    86,    87,    78,    64,
      38,    80,    81,    82,    83,    84,    85,    86,    87
};

static const yytype_int8 yycheck[] =
{
      35,    40,     0,     3,     4,    31,    32,    13,     8,     2,
      11,    11,    12,     8,     8,     9,    51,    44,    45,    13,
       9,    56,    57,    17,    24,    19,     8,    21,    16,    68,
      30,    70,    67,    26,    69,    25,    26,    27,    28,    29,
      30,    31,    32,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,     3,     4,     3,     4,    12,     8,
       8,     8,    11,    18,    11,     5,     6,     7,    29,    30,
      31,    32,    12,   112,    12,    24,    10,    24,    13,     8,
     115,    30,    13,    30,    22,    23,    12,    25,    26,    27,
      28,    29,    30,    31,    32,    11,    22,    23,    12,    25,
      26,    27,    28,    29,    30,    31,    32,    11,    22,    23,
      11,    25,    26,    27,    28,    29,    30,    31,    32,     5,
       6,     7,     8,     9,     5,     6,     7,    13,    11,    20,
      10,    17,    16,    19,    12,    21,    29,    22,    23,    50,
      25,    26,    27,    28,    29,    30,    31,    32,    22,    43,
      26,    25,    26,    27,    28,    29,    30,    31,    32
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    38,    39,     0,     5,     6,     7,    40,    49,    50,
      52,    53,    13,     8,    41,    51,    11,     9,    44,    45,
      16,    43,    12,    42,    52,    47,    48,     8,    12,     8,
      10,    46,     8,     9,    13,    17,    19,    21,    49,    52,
      54,    55,    56,    57,    59,    60,    61,    64,    66,    68,
      43,    18,     3,     4,     8,    11,    24,    30,    69,    70,
      71,    13,     8,    56,    47,    55,    55,    11,    63,    11,
      67,    42,    11,    69,    12,    69,    69,    69,    22,    23,
      25,    26,    27,    28,    29,    30,    31,    32,    11,    10,
      58,    69,    56,    69,    56,    12,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    72,    73,    12,
      20,    62,    65,    12,    12,    16,    56,    69
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    39,    40,    41,    41,    42,
      42,    43,    44,    45,    46,    47,    48,    48,    49,    50,
      51,    51,    52,    53,    53,    53,    54,    54,    55,    56,
      56,    56,    56,    56,    56,    57,    58,    59,    60,    60,
      61,    62,    62,    63,    64,    65,    66,    67,    68,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    70,    71,    72,    72,
      73,    73
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     3,     0,     3,     3,     4,     4,
       2,     1,     3,     1,     1,     2,     3,     0,     1,     2,
       3,     1,     1,     1,     1,     1,     2,     1,     1,     3,
       2,     2,     1,     1,     1,     1,     1,     3,     2,     3,
       4,     2,     0,     3,     1,     1,     3,     3,     1,     2,
       3,     3,     3,     3,     3,     1,     1,     1,     1,     2,
       3,     3,     3,     3,     3,     3,     4,     1,     1,     0,
       3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* prog: glob_decl_list  */
#line 141 "lang.y"
                                   {}
#line 1438 "y.tab.c"
    break;

  case 3: /* glob_decl_list: glob_decl_list fun  */
#line 143 "lang.y"
                                    {}
#line 1444 "y.tab.c"
    break;

  case 4: /* glob_decl_list: glob_decl_list decl PV  */
#line 144 "lang.y"
                               {offset++;}
#line 1450 "y.tab.c"
    break;

  case 5: /* glob_decl_list: %empty  */
#line 145 "lang.y"
                               {}
#line 1456 "y.tab.c"
    break;

  case 6: /* fun: type fun_head fun_body  */
#line 149 "lang.y"
                               {}
#line 1462 "y.tab.c"
    break;

  case 7: /* fun_head: ID PO PF  */
#line 152 "lang.y"
                               {
  // Pas de déclaration de fonction à l'intérieur de fonctions !
  if (depth>0) yyerror("Function must be declared at top level~!\n");
  if(strcmp((yyvsp[-2].string_value), "main")==0){
    printf("void pcode_main() {\n");
    inside=1;
    insidemain=1;
  }
  }
#line 1476 "y.tab.c"
    break;

  case 8: /* fun_head: ID PO params PF  */
#line 162 "lang.y"
                               {
   // Pas de déclaration de fonction à l'intérieur de fonctions !
  if (depth>0) yyerror("Function must be declared at top level~!\n");
  else if(strcmp((yyvsp[-3].string_value), "main")!=0){
    inside =1;
    printf("void pcode_%s() {\n", (yyvsp[-3].string_value));
    for(int i=1; i<(param_num+1); i++){
      printf("// Argument  of function %s in TDS with offset -%d\n", (yyvsp[-3].string_value), i );
    }
  }
 }
#line 1492 "y.tab.c"
    break;

  case 9: /* params: type ID vir params  */
#line 175 "lang.y"
                               {tab[param_num]=typet;
                                param_num++;                      
                                attribute r = makeSymbol(typet, -param_num, 1);
                                sid sym = string_to_sid((yyvsp[-2].string_value));
                                r = set_symbol_value(sym, r);}
#line 1502 "y.tab.c"
    break;

  case 10: /* params: type ID  */
#line 182 "lang.y"
                               {tab[param_num]=typet;
                                param_num++;                           
                                attribute r = makeSymbol(typet, -param_num, 1);
                                sid sym = string_to_sid((yyvsp[0].string_value));
                                r = set_symbol_value(sym, r);
                                }
#line 1513 "y.tab.c"
    break;

  case 11: /* vir: VIR  */
#line 190 "lang.y"
                               {}
#line 1519 "y.tab.c"
    break;

  case 12: /* fun_body: fao block faf  */
#line 193 "lang.y"
                               {}
#line 1525 "y.tab.c"
    break;

  case 13: /* fao: AO  */
#line 196 "lang.y"
                               {}
#line 1531 "y.tab.c"
    break;

  case 14: /* faf: AF  */
#line 198 "lang.y"
                               {remove_symbols(inside);printf("// Exiting function block, removing loc var and arg from TDS\n");printf("}\n");}
#line 1537 "y.tab.c"
    break;

  case 15: /* block: decl_list inst_list  */
#line 204 "lang.y"
                               {}
#line 1543 "y.tab.c"
    break;

  case 16: /* decl_list: decl_list decl PV  */
#line 209 "lang.y"
                                {}
#line 1549 "y.tab.c"
    break;

  case 17: /* decl_list: %empty  */
#line 210 "lang.y"
                                {}
#line 1555 "y.tab.c"
    break;

  case 18: /* decl: var_decl  */
#line 213 "lang.y"
                                {}
#line 1561 "y.tab.c"
    break;

  case 19: /* var_decl: type vlist  */
#line 216 "lang.y"
                               {}
#line 1567 "y.tab.c"
    break;

  case 20: /* vlist: vlist vir ID  */
#line 219 "lang.y"
                               {}
#line 1573 "y.tab.c"
    break;

  case 21: /* vlist: ID  */
#line 220 "lang.y"
                               {depth=inside;
                                if(insidemain==1){
                                  makeOffset();
                                  insidemain=0;
                                }
                                else if(depth!=0){
                                  makeOffset();
                                }
                                attribute r = makeSymbol(typet, offset, depth);
                                sid sym = string_to_sid((yyvsp[0].string_value));
                                (yyvsp[-1].symbol_value) = set_symbol_value(sym, r);
                                if(depth>0){
                                  if(type=="int"){
                                  //sprintf(str, "// Declare %s of type %s with offset %d at depth %d \nLOADI(0)\n\n", $1, type,offset, r->depth);
                                  printf("// Declare %s of type %s with offset %d at depth %d \nLOADI(0)\n\n", (yyvsp[0].string_value), type,offset, r->depth);
                                }
                                else if(type=="float"){
                                  //sprintf(str, "// Declare %s of type %s with offset %d at depth %d \nLOADF(0.0)\n\n", $1, type,offset, depth);
                                  printf("// Declare %s of type %s with offset %d at depth %d \nLOADF(0.0)\n\n", (yyvsp[0].string_value), type,offset, depth);
                                }
                                }
                                else{
                                  if(type=="int"){
                                  sprintf(str, "// Declare %s of type %s with offset %d at depth %d \nLOADI(0)\n\n", (yyvsp[0].string_value), type,offset, r->depth);
                                  //printf("// Declare %s of type %s with offset %d at depth %d \nLOADI(0)\n\n", $1, type,offset, r->depth);
                                }
                                else if(type=="float"){
                                  sprintf(str, "// Declare %s of type %s with offset %d at depth %d \nLOADF(0.0)\n\n", (yyvsp[0].string_value), type,offset, depth);
                                  //printf("// Declare %s of type %s with offset %d at depth %d \nLOADF(0.0)\n\n", $1, type,offset, depth);
                                }
                                  strcat(result, str);
                                }
                                }
#line 1611 "y.tab.c"
    break;

  case 22: /* type: typename  */
#line 256 "lang.y"
                               {typet=(yyvsp[0].type_value);type=type2string((yyvsp[0].type_value));}
#line 1617 "y.tab.c"
    break;

  case 23: /* typename: INT  */
#line 260 "lang.y"
                               {(yyval.type_value)=INT;}
#line 1623 "y.tab.c"
    break;

  case 24: /* typename: FLOAT  */
#line 261 "lang.y"
                               {(yyval.type_value)=FLOAT;}
#line 1629 "y.tab.c"
    break;

  case 25: /* typename: VOID  */
#line 262 "lang.y"
                               {(yyval.type_value)=VOID;}
#line 1635 "y.tab.c"
    break;

  case 26: /* inst_list: inst_list inst  */
#line 267 "lang.y"
                            {}
#line 1641 "y.tab.c"
    break;

  case 27: /* inst_list: inst  */
#line 268 "lang.y"
                            {}
#line 1647 "y.tab.c"
    break;

  case 28: /* pv: PV  */
#line 271 "lang.y"
                              {}
#line 1653 "y.tab.c"
    break;

  case 29: /* inst: ao block af  */
#line 275 "lang.y"
                              {}
#line 1659 "y.tab.c"
    break;

  case 30: /* inst: aff pv  */
#line 276 "lang.y"
                              {}
#line 1665 "y.tab.c"
    break;

  case 31: /* inst: ret pv  */
#line 277 "lang.y"
                              {}
#line 1671 "y.tab.c"
    break;

  case 32: /* inst: cond  */
#line 278 "lang.y"
                              {}
#line 1677 "y.tab.c"
    break;

  case 33: /* inst: loop  */
#line 279 "lang.y"
                              {}
#line 1683 "y.tab.c"
    break;

  case 34: /* inst: pv  */
#line 280 "lang.y"
                              {}
#line 1689 "y.tab.c"
    break;

  case 35: /* ao: AO  */
#line 285 "lang.y"
                              {offset=0;printf("SAVEBP // entering block\n"); inside++;}
#line 1695 "y.tab.c"
    break;

  case 36: /* af: AF  */
#line 288 "lang.y"
                              {if (inside>0) {remove_symbols(inside);};printf("RESTOREBP // exiting block\n");inside--;}
#line 1701 "y.tab.c"
    break;

  case 37: /* aff: ID EQ exp  */
#line 294 "lang.y"
                              { sid sym = string_to_sid((yyvsp[-2].string_value));
                                attribute r = get_symbol_value(sym);
                                if(r->depth==0){
                                  printf("STOREP(%d) // storing %s value\n", r->offset, (yyvsp[-2].string_value));
                                }
                                else{
                                  char res[1000];
                                  printStackAccess(inside - r->depth, res);
                                  printf("STOREP(%s + %d) // storing %s value in current block\n", res, r->offset, (yyvsp[-2].string_value));
                                }
                                }
#line 1717 "y.tab.c"
    break;

  case 38: /* ret: RETURN exp  */
#line 309 "lang.y"
                              {printf("return;\n");}
#line 1723 "y.tab.c"
    break;

  case 39: /* ret: RETURN PO PF  */
#line 310 "lang.y"
                             {}
#line 1729 "y.tab.c"
    break;

  case 40: /* cond: if bool_cond inst elsop  */
#line 319 "lang.y"
                               {printf("End_%d:\n", (yyvsp[-4].label_value));printf("// Fin conditionelle %d\n", (yyvsp[-4].label_value));inside--;}
#line 1735 "y.tab.c"
    break;

  case 41: /* elsop: else inst  */
#line 322 "lang.y"
                               {}
#line 1741 "y.tab.c"
    break;

  case 42: /* elsop: %empty  */
#line 323 "lang.y"
                               {}
#line 1747 "y.tab.c"
    break;

  case 43: /* bool_cond: PO exp PF  */
#line 326 "lang.y"
                              {printf("IFN(False_%d) \n// la condition %d est vraie\n", num_cond, num_cond);}
#line 1753 "y.tab.c"
    break;

  case 44: /* if: IF  */
#line 329 "lang.y"
                              {num_cond++;(yyvsp[-1].label_value)=num_cond;printf("// Debut conditionelle %d\n", (yyvsp[-1].label_value));}
#line 1759 "y.tab.c"
    break;

  case 45: /* else: ELSE  */
#line 332 "lang.y"
                              {printf("GOTO(End_%d)\nFalse_%d:\n",(yyvsp[(-3) - (1)].label_value), (yyvsp[(-3) - (1)].label_value));printf("//la condition %d est fausse\n", (yyvsp[(-3) - (1)].label_value));}
#line 1765 "y.tab.c"
    break;

  case 46: /* loop: while while_cond inst  */
#line 337 "lang.y"
                              {printf("GOTO(StartLoop_%d)\n//Fin boucle while %d\nEndLoop_%d:\n", NumWhile, NumWhile, NumWhile);NumWhile--;}
#line 1771 "y.tab.c"
    break;

  case 47: /* while_cond: PO exp PF  */
#line 340 "lang.y"
                              {printf("IFN(EndLoop_%d)\n// Debut boucle while %d \n", NumWhile, NumWhile);}
#line 1777 "y.tab.c"
    break;

  case 48: /* while: WHILE  */
#line 342 "lang.y"
                              {NumWhile++;printf("StartLoop_%d: // chargement condition boucle while %d\n", NumWhile, NumWhile);}
#line 1783 "y.tab.c"
    break;

  case 49: /* exp: MOINS exp  */
#line 350 "lang.y"
                              {}
#line 1789 "y.tab.c"
    break;

  case 50: /* exp: exp PLUS exp  */
#line 352 "lang.y"
                              {if(((yyvsp[-2].type_value)==FLOAT && (yyvsp[0].type_value)==INT) || ((yyvsp[0].type_value)==FLOAT && (yyvsp[-2].type_value)==INT)){
                                    if(convert==1){
                                      printf("I2F");
                                      convert++;
                                    }
                                    else{
                                      printf("I2F%d", convert);
                                    }
                                    if((yyvsp[-2].type_value)==INT){
                                      printf(" // converting first arg to float\nADDF \n");
                                      (yyvsp[-2].type_value)=FLOAT;
                                    }
                                    else{
                                      printf(" // converting second arg to float\nADDF \n");
                                      (yyvsp[0].type_value)==FLOAT;
                                    }
                                }
                                else if((yyvsp[-2].type_value)==FLOAT || (yyvsp[0].type_value)==FLOAT){
                                  printf("ADDF \n");
                                }
                                else{
                                  printf("ADDI \n");
                                }}
#line 1817 "y.tab.c"
    break;

  case 51: /* exp: exp MOINS exp  */
#line 375 "lang.y"
                              {if(((yyvsp[-2].type_value)==FLOAT && (yyvsp[0].type_value)==INT) || ((yyvsp[0].type_value)==FLOAT && (yyvsp[-2].type_value)==INT)){
                                    if(convert==1){
                                      printf("I2F");
                                      convert++;
                                    }
                                    else{
                                      printf("I2F%d", convert);
                                    }
                                    if((yyvsp[-2].type_value)==INT){
                                      printf(" // converting first arg to float\nSUBF \n");
                                      (yyvsp[-2].type_value)=FLOAT;
                                    }
                                    else{
                                      printf(" // converting second arg to float\nSUBF \n");
                                      (yyvsp[0].type_value)==FLOAT;
                                    }
                                }
                                else if((yyvsp[-2].type_value)==FLOAT || (yyvsp[0].type_value)==FLOAT){
                                  printf("SUBF \n");
                                }
                                else{
                                  printf("SUBI \n");
                                }}
#line 1845 "y.tab.c"
    break;

  case 52: /* exp: exp STAR exp  */
#line 398 "lang.y"
                              {if(((yyvsp[-2].type_value)==FLOAT && (yyvsp[0].type_value)==INT) || ((yyvsp[0].type_value)==FLOAT && (yyvsp[-2].type_value)==INT)){
                                    if(convert==1){
                                      printf("I2F");
                                      convert++;
                                    }
                                    else{
                                      printf("I2F%d", convert);
                                    }
                                    if((yyvsp[-2].type_value)==INT){
                                      printf(" // converting first arg to float\nMULTF \n");
                                      (yyvsp[-2].type_value)=FLOAT;
                                    }
                                    else{
                                      printf(" // converting second arg to float\nMULTF \n");
                                      (yyvsp[0].type_value)==FLOAT;
                                    }
                                }
                                else if((yyvsp[-2].type_value)==FLOAT || (yyvsp[0].type_value)==FLOAT){
                                  printf("MULTF \n");
                                }
                                else{
                                  printf("MULTI \n");
                                }}
#line 1873 "y.tab.c"
    break;

  case 53: /* exp: exp DIV exp  */
#line 421 "lang.y"
                              {if(((yyvsp[-2].type_value)==FLOAT && (yyvsp[0].type_value)==INT) || ((yyvsp[0].type_value)==FLOAT && (yyvsp[-2].type_value)==INT)){
                                    if(convert==1){
                                      printf("I2F");
                                      convert++;
                                    }
                                    else{
                                      printf("I2F%d", convert);
                                    }
                                    if((yyvsp[-2].type_value)==INT){
                                      printf(" // converting first arg to float\nDIVF \n");
                                      (yyvsp[-2].type_value)=FLOAT;
                                    }
                                    else{
                                      printf(" // converting second arg to float\nDIVF \n");
                                      (yyvsp[0].type_value)==FLOAT;
                                    }
                                }
                                else if((yyvsp[-2].type_value)==FLOAT || (yyvsp[0].type_value)==FLOAT){
                                  printf("DIVF \n");
                                }
                                else{
                                  printf("DIVI \n");
                                }}
#line 1901 "y.tab.c"
    break;

  case 54: /* exp: PO exp PF  */
#line 444 "lang.y"
                              {}
#line 1907 "y.tab.c"
    break;

  case 55: /* exp: ID  */
#line 445 "lang.y"
                              {attribute r = get_symbol_value((yyvsp[0].string_value));
                              if(type2string(r->type)=="float"){(yyval.type_value)=FLOAT;}else if(type2string(r->type)=="int"){(yyval.type_value)=INT;};
                              if(r->depth==0){
                                printf("LOADP(%d) // loading %s value\n", r->offset, (yyvsp[0].string_value));
                              }
                              else{
                                char res[1000];
                                printStackAccess(inside - r->depth, res);
                                printf("LOADP(%s+%d) // loading %s value\n", res, r->offset, (yyvsp[0].string_value));
                              }}
#line 1922 "y.tab.c"
    break;

  case 56: /* exp: app  */
#line 455 "lang.y"
                              {printf("ENDCALL(%d)  // unloading %d args of function %s\n", param_num, param_num, id);}
#line 1928 "y.tab.c"
    break;

  case 57: /* exp: NUM  */
#line 456 "lang.y"
                              {printf("LOADI(%d)\n", (yyvsp[0].int_value)); (yyval.type_value)=INT;if(comparerValeur(tab, param_num, typet)==1){printf("I2F\n");};}
#line 1934 "y.tab.c"
    break;

  case 58: /* exp: DEC  */
#line 457 "lang.y"
                              {printf("LOADF(%f)\n", (yyvsp[0].float_value)); (yyval.type_value)=FLOAT;}
#line 1940 "y.tab.c"
    break;

  case 59: /* exp: NOT exp  */
#line 462 "lang.y"
                              {printf("NOT\n");}
#line 1946 "y.tab.c"
    break;

  case 60: /* exp: exp INF exp  */
#line 463 "lang.y"
                              {if ((yyvsp[-2].type_value)==FLOAT || (yyvsp[0].type_value)==FLOAT) {printf("LTF\n");}
                              else {printf("LTI\n");}}
#line 1953 "y.tab.c"
    break;

  case 61: /* exp: exp SUP exp  */
#line 465 "lang.y"
                              {if ((yyvsp[-2].type_value)==FLOAT || (yyvsp[0].type_value)==FLOAT) {printf("GTF\n");}
                              else {printf("GTI\n");}}
#line 1960 "y.tab.c"
    break;

  case 62: /* exp: exp EQUAL exp  */
#line 467 "lang.y"
                              {if ((yyvsp[-2].type_value)==FLOAT || (yyvsp[0].type_value)==FLOAT) {printf("EQF\n");}
                              else {printf("EQI\n");}}
#line 1967 "y.tab.c"
    break;

  case 63: /* exp: exp DIFF exp  */
#line 469 "lang.y"
                              {if ((yyvsp[-2].type_value)==FLOAT || (yyvsp[0].type_value)==FLOAT) {printf("NEQF\n");}
                              else {printf("NEQI\n");}}
#line 1974 "y.tab.c"
    break;

  case 64: /* exp: exp AND exp  */
#line 471 "lang.y"
                              {printf("AND\n");}
#line 1980 "y.tab.c"
    break;

  case 65: /* exp: exp OR exp  */
#line 472 "lang.y"
                              {printf("OR\n");}
#line 1986 "y.tab.c"
    break;

  case 66: /* app: fid PO args PF  */
#line 479 "lang.y"
                              {printf("RESTOREBP \n");}
#line 1992 "y.tab.c"
    break;

  case 67: /* fid: ID  */
#line 481 "lang.y"
                              {id=(yyvsp[0].string_value);printf("// loading function %s arguments\n", (yyvsp[0].string_value));}
#line 1998 "y.tab.c"
    break;

  case 68: /* args: arglist  */
#line 483 "lang.y"
                              {printf("CALL(pcode_%s) \n", id);}
#line 2004 "y.tab.c"
    break;

  case 69: /* args: %empty  */
#line 484 "lang.y"
                              {}
#line 2010 "y.tab.c"
    break;

  case 70: /* arglist: arglist VIR exp  */
#line 487 "lang.y"
                              {printf("SAVEBP \n");}
#line 2016 "y.tab.c"
    break;

  case 71: /* arglist: exp  */
#line 488 "lang.y"
                              {if(param_num==1)printf("SAVEBP \n");}
#line 2022 "y.tab.c"
    break;


#line 2026 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 493 "lang.y"
 
int main () {

  /* Ici on peut ouvrir le fichier source, avec les messages 
     d'erreur usuel si besoin, et rediriger l'entrée standard 
     sur ce fichier pour lancer dessus la compilation.
   */


    char *include =
        "// PCode Header\n"
        "#include \"../PCode/PCode.h\"\n"
        "\n";

    printf("%s\n", include);

    // Supposons que yyparse() est défini ailleurs
    yyparse();

    char *header =
        "int main() {"
        "\n";

    char *mainCode =
        "pcode_main();\n"
        "return stack[sp-1].int_value;\n"
        "}\n";

    // Affichez le contenu de header et mainCode
    printf("%s%s", header, result);
    printf("%s\n", mainCode);
  
return 1;
 
 
} 

