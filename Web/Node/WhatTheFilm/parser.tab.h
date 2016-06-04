/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
     TOK_VOID = 258,
     TOK_BOOL = 259,
     TOK_CHAR = 260,
     TOK_INT = 261,
     TOK_STRING = 262,
     TOK_IF = 263,
     TOK_ELSE = 264,
     TOK_WHILE = 265,
     TOK_RETURN = 266,
     TOK_STRUCT = 267,
     TOK_FALSE = 268,
     TOK_TRUE = 269,
     TOK_NULL = 270,
     TOK_NEW = 271,
     TOK_ARRAY = 272,
     TOK_EQ = 273,
     TOK_NE = 274,
     TOK_LT = 275,
     TOK_LE = 276,
     TOK_GT = 277,
     TOK_GE = 278,
     TOK_IDENT = 279,
     TOK_INTCON = 280,
     TOK_CHARCON = 281,
     TOK_STRINGCON = 282,
     TOK_ROOT = 283,
     TOK_FIELD = 284,
     TOK_DECLID = 285,
     TOK_TYPEID = 286,
     TOK_INDEX = 287,
     TOK_POS = 288,
     TOK_NEG = 289,
     TOK_CALL = 290,
     TOK_NEWARRAY = 291,
     TOK_NEWSTRING = 292,
     TOK_IFELSE = 293,
     TOK_RETURNVOID = 294,
     TOK_BLOCK = 295,
     TOK_VARDECL = 296,
     TOK_FUNCTION = 297,
     TOK_PARAMLIST = 298,
     TOK_PROTOTYPE = 299,
     TOK_INITDECL = 300,
     TOK_ORD = 301,
     TOK_CHR = 302
   };
#endif
/* Tokens.  */
#define TOK_VOID 258
#define TOK_BOOL 259
#define TOK_CHAR 260
#define TOK_INT 261
#define TOK_STRING 262
#define TOK_IF 263
#define TOK_ELSE 264
#define TOK_WHILE 265
#define TOK_RETURN 266
#define TOK_STRUCT 267
#define TOK_FALSE 268
#define TOK_TRUE 269
#define TOK_NULL 270
#define TOK_NEW 271
#define TOK_ARRAY 272
#define TOK_EQ 273
#define TOK_NE 274
#define TOK_LT 275
#define TOK_LE 276
#define TOK_GT 277
#define TOK_GE 278
#define TOK_IDENT 279
#define TOK_INTCON 280
#define TOK_CHARCON 281
#define TOK_STRINGCON 282
#define TOK_ROOT 283
#define TOK_FIELD 284
#define TOK_DECLID 285
#define TOK_TYPEID 286
#define TOK_INDEX 287
#define TOK_POS 288
#define TOK_NEG 289
#define TOK_CALL 290
#define TOK_NEWARRAY 291
#define TOK_NEWSTRING 292
#define TOK_IFELSE 293
#define TOK_RETURNVOID 294
#define TOK_BLOCK 295
#define TOK_VARDECL 296
#define TOK_FUNCTION 297
#define TOK_PARAMLIST 298
#define TOK_PROTOTYPE 299
#define TOK_INITDECL 300
#define TOK_ORD 301
#define TOK_CHR 302




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

