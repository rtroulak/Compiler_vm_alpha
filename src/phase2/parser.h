/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     INTEGER = 259,
     FLOAT = 260,
     ifstmt = 261,
     whilestmt = 262,
     elsestmt = 263,
     forstmt = 264,
     returnstmt = 265,
     breakstmt = 266,
     continuestmt = 267,
     lesseq = 268,
     beq = 269,
     greq = 270,
     bne = 271,
     AND = 272,
     OR = 273,
     NOT = 274,
     plusplus = 275,
     minusminus = 276,
     dblakt = 277,
     dblt = 278,
     functionstmt = 279,
     truestmt = 280,
     falsestmt = 281,
     local = 282,
     nil = 283,
     onelcomm = 284,
     mullcomm = 285,
     string2 = 286,
     librfunc = 287
   };
#endif
/* Tokens.  */
#define ID 258
#define INTEGER 259
#define FLOAT 260
#define ifstmt 261
#define whilestmt 262
#define elsestmt 263
#define forstmt 264
#define returnstmt 265
#define breakstmt 266
#define continuestmt 267
#define lesseq 268
#define beq 269
#define greq 270
#define bne 271
#define AND 272
#define OR 273
#define NOT 274
#define plusplus 275
#define minusminus 276
#define dblakt 277
#define dblt 278
#define functionstmt 279
#define truestmt 280
#define falsestmt 281
#define local 282
#define nil 283
#define onelcomm 284
#define mullcomm 285
#define string2 286
#define librfunc 287




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 168 "parser.y"

	 char* stringVal;
	 int intValue;
	 double realVal;
	 struct expr* express;



/* Line 2068 of yacc.c  */
#line 123 "parser.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


