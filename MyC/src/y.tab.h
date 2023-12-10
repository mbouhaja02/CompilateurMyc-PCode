/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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

#line 149 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
