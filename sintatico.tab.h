/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_SINTATICO_TAB_H_INCLUDED
# define YY_YY_SINTATICO_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    FUNCTION = 258,
    CHARACTER = 259,
    VOID = 260,
    INT = 261,
    NUM_INTEGER = 262,
    CHAR = 263,
    RETURN = 264,
    BREAK = 265,
    SWITCH = 266,
    CASE = 267,
    DEFAULT = 268,
    DO_WHILE = 269,
    WHILE = 270,
    FOR = 271,
    IF = 272,
    ELSE = 273,
    TYPEDEF = 274,
    STRUCT = 275,
    PLUS = 276,
    MINUS = 277,
    MULTIPLY = 278,
    DIV = 279,
    REMAINDER = 280,
    INC = 281,
    DEC = 282,
    BITWISE_AND = 283,
    BITWISE_OR = 284,
    BITWISE_NOT = 285,
    BITWISE_XOR = 286,
    NOT = 287,
    LOGICAL_AND = 288,
    LOGICAL_OR = 289,
    EQUAL = 290,
    NOT_EQUAL = 291,
    LESS_THAN = 292,
    GREATER_THAN = 293,
    GREATER_EQUAL = 294,
    LESS_EQUAL = 295,
    R_SHIFT = 296,
    L_SHIFT = 297,
    ASSIGN = 298,
    ADD_ASSIGN = 299,
    MINUS_ASSIGN = 300,
    SEMICOLON = 301,
    COMMA = 302,
    COLON = 303,
    L_PARENTESE = 304,
    R_PARENTESE = 305,
    L_CURLY_BRACKET = 306,
    R_CURLY_BRACKET = 307,
    L_SQUARE_BRACKET = 308,
    R_SQUARE_BRACKET = 309,
    TERNARY_CONDITIONAL = 310,
    NUMBER_SIGN = 311,
    POINTER = 312,
    PRINTF = 313,
    SCANF = 314,
    DEFINE = 315,
    EXIT = 316,
    IDENTIFIER = 317,
    RETURN_TYPE = 318,
    VARIABLE = 319,
    TYPE = 320,
    PARAMETER = 321,
    END_FUNCTION = 322,
    GLOBAL = 323,
    STRING = 324,
    VALUE = 325,
    CONSTANT = 326
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 12 "sintatico.y"

    char *str;
    int num;
    float real;
    Parametros *parametros;
    Variaveis *variaveis;
    Cmd_expressao *expressao;
    Comandos *comandos;
    Expressao *expr;
    Function_struct *lista_funcoes;

#line 141 "sintatico.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SINTATICO_TAB_H_INCLUDED  */
