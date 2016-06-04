/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 1 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"


#include <assert.h>
#include "lyutils.h"
#include "astree.h"



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 1
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 208 "parser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   659

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNRULES -- Number of states.  */
#define YYNSTATES  154

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   302

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    54,     2,     2,     2,    53,     2,     2,
      57,    61,    51,    49,    62,    50,    56,    52,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    59,
       2,    48,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    55,     2,    63,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    60,     2,    58,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    11,    14,    18,    22,    23,
      26,    29,    33,    38,    42,    44,    46,    48,    50,    52,
      54,    56,    61,    66,    71,    76,    79,    83,    87,    90,
      93,    96,    99,   102,   104,   106,   108,   110,   112,   114,
     117,   119,   124,   130,   136,   144,   147,   151,   153,   155,
     157,   159,   163,   165,   167,   170,   173,   176,   179,   182,
     186,   190,   194,   198,   202,   206,   210,   214,   218,   222,
     226,   230,   235,   241,   247,   251,   254,   258,   262,   264,
     268,   273,   275,   277,   279,   281,   283
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      65,     0,    -1,    66,    -1,    66,    67,    -1,    66,    71,
      -1,    66,    76,    -1,    66,     1,    58,    -1,    66,     1,
      59,    -1,    -1,    68,    58,    -1,    68,    69,    -1,    12,
      24,    60,    -1,    70,    17,    24,    59,    -1,    70,    24,
      59,    -1,     3,    -1,     4,    -1,     5,    -1,     6,    -1,
       7,    -1,    31,    -1,    24,    -1,    73,    72,    61,    74,
      -1,    73,    72,    61,    59,    -1,    73,    57,    61,    74,
      -1,    73,    57,    61,    59,    -1,    57,    73,    -1,    72,
      62,    73,    -1,    70,    17,    24,    -1,    70,    24,    -1,
      75,    58,    -1,    60,    58,    -1,    75,    76,    -1,    60,
      76,    -1,    60,    -1,    74,    -1,    77,    -1,    78,    -1,
      79,    -1,    80,    -1,    81,    59,    -1,    59,    -1,    73,
      48,    81,    59,    -1,    10,    57,    81,    61,    76,    -1,
       8,    57,    81,    61,    76,    -1,     8,    57,    81,    61,
      76,     9,    76,    -1,    11,    59,    -1,    11,    81,    59,
      -1,    82,    -1,    83,    -1,    84,    -1,    85,    -1,    57,
      81,    61,    -1,    87,    -1,    88,    -1,    49,    81,    -1,
      50,    81,    -1,    54,    81,    -1,    47,    81,    -1,    46,
      81,    -1,    81,    49,    81,    -1,    81,    50,    81,    -1,
      81,    51,    81,    -1,    81,    52,    81,    -1,    81,    48,
      81,    -1,    81,    53,    81,    -1,    81,    20,    81,    -1,
      81,    21,    81,    -1,    81,    22,    81,    -1,    81,    23,
      81,    -1,    81,    18,    81,    -1,    81,    19,    81,    -1,
      16,    24,    57,    61,    -1,    16,     7,    57,    81,    61,
      -1,    16,    70,    55,    81,    63,    -1,    24,    57,    61,
      -1,    86,    61,    -1,    24,    57,    81,    -1,    86,    62,
      81,    -1,    24,    -1,    81,    56,    24,    -1,    81,    55,
      81,    63,    -1,    25,    -1,    26,    -1,    27,    -1,    14,
      -1,    13,    -1,    15,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    43,    43,    46,    47,    48,    49,    50,    52,    55,
      60,    61,    66,    70,    76,    77,    78,    79,    80,    81,
      82,    85,    90,    95,   100,   107,   110,   113,   116,   121,
     125,   131,   134,   137,   142,   143,   144,   145,   146,   147,
     151,   154,   160,   166,   170,   177,   181,   187,   188,   189,
     190,   191,   195,   196,   199,   200,   201,   202,   203,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   220,   224,   228,   234,   238,   244,   247,   253,   254,
     257,   263,   264,   265,   266,   267,   268
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_VOID", "TOK_BOOL", "TOK_CHAR",
  "TOK_INT", "TOK_STRING", "TOK_IF", "TOK_ELSE", "TOK_WHILE", "TOK_RETURN",
  "TOK_STRUCT", "TOK_FALSE", "TOK_TRUE", "TOK_NULL", "TOK_NEW",
  "TOK_ARRAY", "TOK_EQ", "TOK_NE", "TOK_LT", "TOK_LE", "TOK_GT", "TOK_GE",
  "TOK_IDENT", "TOK_INTCON", "TOK_CHARCON", "TOK_STRINGCON", "TOK_ROOT",
  "TOK_FIELD", "TOK_DECLID", "TOK_TYPEID", "TOK_INDEX", "TOK_POS",
  "TOK_NEG", "TOK_CALL", "TOK_NEWARRAY", "TOK_NEWSTRING", "TOK_IFELSE",
  "TOK_RETURNVOID", "TOK_BLOCK", "TOK_VARDECL", "TOK_FUNCTION",
  "TOK_PARAMLIST", "TOK_PROTOTYPE", "TOK_INITDECL", "TOK_ORD", "TOK_CHR",
  "'='", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "'['", "'.'", "'('",
  "'}'", "';'", "'{'", "')'", "','", "']'", "$accept", "start", "program",
  "structdef", "structbase", "fielddecl", "basetype", "function",
  "funcstart", "identdecl", "block", "blockstart", "statement", "vardecl",
  "while", "ifelse", "return", "expr", "unop", "binop", "allocator",
  "call", "callbase", "variable", "constant", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,    61,    43,
      45,    42,    47,    37,    33,    91,    46,    40,   125,    59,
     123,    41,    44,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    64,    65,    66,    66,    66,    66,    66,    66,    67,
      68,    68,    69,    69,    70,    70,    70,    70,    70,    70,
      70,    71,    71,    71,    71,    72,    72,    73,    73,    74,
      74,    75,    75,    75,    76,    76,    76,    76,    76,    76,
      76,    77,    78,    79,    79,    80,    80,    81,    81,    81,
      81,    81,    81,    81,    82,    82,    82,    82,    82,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    84,    84,    84,    85,    85,    86,    86,    87,    87,
      87,    88,    88,    88,    88,    88,    88
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     3,     3,     0,     2,
       2,     3,     4,     3,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     4,     2,     3,     3,     2,     2,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     2,
       1,     4,     5,     5,     7,     2,     3,     1,     1,     1,
       1,     3,     1,     1,     2,     2,     2,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     4,     5,     5,     3,     2,     3,     3,     1,     3,
       4,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       8,     0,     0,     1,     0,    14,    15,    16,    17,    18,
       0,     0,     0,     0,    85,    84,    86,     0,    78,    81,
      82,    83,    19,     0,     0,     0,     0,     0,     0,    40,
       0,     3,     0,     0,     4,     0,    34,     0,     5,    35,
      36,    37,    38,     0,    47,    48,    49,    50,     0,    52,
      53,     6,     7,     0,     0,    78,    45,     0,     0,    18,
      20,     0,     0,    58,    57,    54,    55,    56,     0,    30,
       0,    32,    20,     9,    10,     0,     0,    28,     0,     0,
       0,    29,    31,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    39,    75,     0,
       0,     0,    46,    11,     0,     0,     0,    74,    76,    51,
       0,     0,    27,     0,     0,    25,     0,     0,    69,    70,
      65,    66,    67,    68,    63,    59,    60,    61,    62,    64,
       0,    79,    77,     0,     0,     0,    71,     0,     0,    13,
      41,    24,    23,    22,    21,    26,    80,    43,    42,    72,
      73,    12,     0,    44
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    31,    32,    74,    33,    34,    80,    70,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -113
static const yytype_int16 yypact[] =
{
    -113,     3,   120,  -113,   -53,  -113,  -113,  -113,  -113,  -113,
     -23,   -18,   348,    24,  -113,  -113,  -113,    40,     8,  -113,
    -113,  -113,  -113,   411,   411,   411,   411,   411,   411,  -113,
     178,  -113,    11,    14,  -113,   -21,  -113,   236,  -113,  -113,
    -113,  -113,  -113,   537,  -113,  -113,  -113,  -113,   -33,  -113,
    -113,  -113,  -113,   411,   411,    18,  -113,   579,     1,    42,
      44,    15,   342,     7,     7,    41,    41,     7,   421,  -113,
      20,  -113,  -113,  -113,  -113,    16,    74,  -113,   411,     6,
     -10,  -113,  -113,   411,   411,   411,   411,   411,   411,   411,
     411,   411,   411,   411,   411,   411,    81,  -113,  -113,   411,
     465,   479,  -113,  -113,   411,     5,   411,  -113,   603,  -113,
      82,    48,  -113,   591,    13,  -113,    17,   134,     4,     4,
       4,     4,     4,     4,   603,    41,    41,     7,     7,     7,
     360,  -113,   603,   294,   294,   523,  -113,   399,    49,  -113,
    -113,  -113,  -113,  -113,  -113,  -113,  -113,   100,  -113,  -113,
    -113,  -113,   294,  -113
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -113,  -113,  -113,  -113,  -113,  -113,     9,  -113,  -113,    -1,
    -112,  -113,   -30,  -113,  -113,  -113,  -113,    -4,  -113,  -113,
    -113,  -113,  -113,  -113,  -113
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -21
static const yytype_int16 yytable[] =
{
      71,    35,   142,     3,   144,    51,    52,    82,    57,     5,
       6,     7,     8,     9,     5,     6,     7,     8,     9,    63,
      64,    65,    66,    67,    68,   -20,    61,    78,    98,    99,
      72,    76,   -20,   110,    53,    72,    79,    22,    77,    54,
     111,    75,    22,     5,     6,     7,     8,    59,    58,   100,
     101,   116,   117,    90,    91,    92,    93,    94,   108,    95,
      96,   103,    95,    96,    60,    62,   136,   114,    78,    73,
     106,    22,   141,    30,   113,    62,   143,    30,   115,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,    92,    93,    94,   132,    95,    96,   112,   104,
     135,   105,   137,   147,   148,   131,   138,   139,   151,   152,
       0,     0,     0,     0,     0,     0,   145,     0,     0,     0,
      -2,     4,   153,     5,     6,     7,     8,     9,    10,     0,
      11,    12,    13,    14,    15,    16,    17,     5,     6,     7,
       8,     9,     0,     0,    18,    19,    20,    21,     0,     0,
       0,    22,     0,     0,     0,     0,     0,     0,    72,     0,
       0,     0,     0,     0,     0,    22,    23,    24,     0,    25,
      26,     0,     0,     0,    27,     0,     0,    28,     0,    29,
      30,     5,     6,     7,     8,     9,    10,     0,    11,    12,
       0,    14,    15,    16,    17,     0,     0,     0,     0,     0,
       0,     0,    18,    19,    20,    21,     0,     0,     0,    22,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    23,    24,     0,    25,    26,     0,
       0,     0,    27,     0,     0,    28,    69,    29,    30,     5,
       6,     7,     8,     9,    10,     0,    11,    12,     0,    14,
      15,    16,    17,     0,     0,     0,     0,     0,     0,     0,
      18,    19,    20,    21,     0,     0,     0,    22,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    23,    24,     0,    25,    26,     0,     0,     0,
      27,     0,     0,    28,    81,    29,    30,     5,     6,     7,
       8,     9,    10,     0,    11,    12,     0,    14,    15,    16,
      17,     0,     0,     0,     0,     0,     0,     0,    18,    19,
      20,    21,     0,     0,     0,    22,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      23,    24,     0,    25,    26,     0,     0,     0,    27,     0,
       0,    28,     0,    29,    30,    14,    15,    16,    17,     0,
       0,    14,    15,    16,    17,     0,    55,    19,    20,    21,
       0,     0,    55,    19,    20,    21,     0,     0,    83,    84,
      85,    86,    87,    88,     0,     0,     0,     0,    23,    24,
       0,    25,    26,     0,    23,    24,    27,    25,    26,    28,
       0,     0,    27,   107,     0,    28,     0,    56,    89,    90,
      91,    92,    93,    94,     0,    95,    96,    83,    84,    85,
      86,    87,    88,   146,    14,    15,    16,    17,     0,     0,
       0,     0,     0,     0,     0,    55,    19,    20,    21,    83,
      84,    85,    86,    87,    88,     0,     0,    89,    90,    91,
      92,    93,    94,     0,    95,    96,     0,    23,    24,     0,
      25,    26,   150,     0,     0,    27,     0,     0,    28,    89,
      90,    91,    92,    93,    94,     0,    95,    96,     0,     0,
       0,     0,   109,    83,    84,    85,    86,    87,    88,     0,
       0,     0,     0,     0,     0,     0,     0,    83,    84,    85,
      86,    87,    88,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    89,    90,    91,    92,    93,    94,     0,
      95,    96,     0,     0,     0,     0,   133,    89,    90,    91,
      92,    93,    94,     0,    95,    96,     0,     0,     0,     0,
     134,    83,    84,    85,    86,    87,    88,     0,     0,     0,
       0,     0,     0,     0,     0,    83,    84,    85,    86,    87,
      88,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    89,    90,    91,    92,    93,    94,     0,    95,    96,
       0,     0,     0,     0,   149,    89,    90,    91,    92,    93,
      94,     0,    95,    96,     0,     0,    97,    83,    84,    85,
      86,    87,    88,     0,     0,     0,     0,     0,     0,    83,
      84,    85,    86,    87,    88,     0,     0,     0,     0,     0,
       0,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,     0,    95,    96,     0,     0,   102,    89,
      90,    91,    92,    93,    94,     0,    95,    96,     0,     0,
     140,    89,    90,    91,    92,    93,    94,     0,    95,    96
};

static const yytype_int16 yycheck[] =
{
      30,     2,   114,     0,   116,    58,    59,    37,    12,     3,
       4,     5,     6,     7,     3,     4,     5,     6,     7,    23,
      24,    25,    26,    27,    28,    17,    17,    48,    61,    62,
      24,    17,    24,    17,    57,    24,    57,    31,    24,    57,
      24,    32,    31,     3,     4,     5,     6,     7,    24,    53,
      54,    61,    62,    49,    50,    51,    52,    53,    62,    55,
      56,    60,    55,    56,    24,    57,    61,    61,    48,    58,
      55,    31,    59,    60,    78,    57,    59,    60,    79,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    51,    52,    53,    99,    55,    56,    24,    57,
     104,    57,   106,   133,   134,    24,    24,    59,    59,     9,
      -1,    -1,    -1,    -1,    -1,    -1,   117,    -1,    -1,    -1,
       0,     1,   152,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    12,    13,    14,    15,    16,     3,     4,     5,
       6,     7,    -1,    -1,    24,    25,    26,    27,    -1,    -1,
      -1,    31,    -1,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    46,    47,    -1,    49,
      50,    -1,    -1,    -1,    54,    -1,    -1,    57,    -1,    59,
      60,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    25,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    -1,    49,    50,    -1,
      -1,    -1,    54,    -1,    -1,    57,    58,    59,    60,     3,
       4,     5,     6,     7,     8,    -1,    10,    11,    -1,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    25,    26,    27,    -1,    -1,    -1,    31,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    -1,    49,    50,    -1,    -1,    -1,
      54,    -1,    -1,    57,    58,    59,    60,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    13,    14,    15,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    25,
      26,    27,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    47,    -1,    49,    50,    -1,    -1,    -1,    54,    -1,
      -1,    57,    -1,    59,    60,    13,    14,    15,    16,    -1,
      -1,    13,    14,    15,    16,    -1,    24,    25,    26,    27,
      -1,    -1,    24,    25,    26,    27,    -1,    -1,    18,    19,
      20,    21,    22,    23,    -1,    -1,    -1,    -1,    46,    47,
      -1,    49,    50,    -1,    46,    47,    54,    49,    50,    57,
      -1,    -1,    54,    61,    -1,    57,    -1,    59,    48,    49,
      50,    51,    52,    53,    -1,    55,    56,    18,    19,    20,
      21,    22,    23,    63,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    25,    26,    27,    18,
      19,    20,    21,    22,    23,    -1,    -1,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    -1,    46,    47,    -1,
      49,    50,    63,    -1,    -1,    54,    -1,    -1,    57,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    -1,    -1,
      -1,    -1,    61,    18,    19,    20,    21,    22,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    20,
      21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    49,    50,    51,    52,    53,    -1,
      55,    56,    -1,    -1,    -1,    -1,    61,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    -1,    -1,    -1,    -1,
      61,    18,    19,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    18,    19,    20,    21,    22,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    48,    49,    50,    51,    52,    53,    -1,    55,    56,
      -1,    -1,    -1,    -1,    61,    48,    49,    50,    51,    52,
      53,    -1,    55,    56,    -1,    -1,    59,    18,    19,    20,
      21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    18,
      19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,    18,    19,    20,    21,    22,    23,    48,    49,    50,
      51,    52,    53,    -1,    55,    56,    -1,    -1,    59,    48,
      49,    50,    51,    52,    53,    -1,    55,    56,    -1,    -1,
      59,    48,    49,    50,    51,    52,    53,    -1,    55,    56
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    65,    66,     0,     1,     3,     4,     5,     6,     7,
       8,    10,    11,    12,    13,    14,    15,    16,    24,    25,
      26,    27,    31,    46,    47,    49,    50,    54,    57,    59,
      60,    67,    68,    70,    71,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    58,    59,    57,    57,    24,    59,    81,    24,     7,
      24,    70,    57,    81,    81,    81,    81,    81,    81,    58,
      73,    76,    24,    58,    69,    70,    17,    24,    48,    57,
      72,    58,    76,    18,    19,    20,    21,    22,    23,    48,
      49,    50,    51,    52,    53,    55,    56,    59,    61,    62,
      81,    81,    59,    60,    57,    57,    55,    61,    81,    61,
      17,    24,    24,    81,    61,    73,    61,    62,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    24,    81,    61,    61,    81,    61,    81,    24,    59,
      59,    59,    74,    59,    74,    73,    63,    76,    76,    61,
      63,    59,     9,    76
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 43 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { yyparse_astree = (yyvsp[(1) - (1)]); ;}
    break;

  case 3:
#line 46 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 4:
#line 47 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 5:
#line 48 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 6:
#line 49 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = (yyvsp[(1) - (3)]); ;}
    break;

  case 7:
#line 50 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = (yyvsp[(1) - (3)]); ;}
    break;

  case 8:
#line 52 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = new_parseroot(); ;}
    break;

  case 9:
#line 55 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    {
                free_ast ((yyvsp[(2) - (2)]));
                (yyval) = (yyvsp[(1) - (2)]);
            ;}
    break;

  case 10:
#line 60 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 11:
#line 61 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    {
                free_ast ((yyvsp[(3) - (3)]));
                (yyval) = adopt1 ((yyvsp[(1) - (3)]), adoptsymbol ((yyvsp[(2) - (3)]), TOK_TYPEID));
            ;}
    break;

  case 12:
#line 66 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    {
                free_ast ((yyvsp[(4) - (4)]));
                (yyval) = adopt2 ((yyvsp[(2) - (4)]), (yyvsp[(1) - (4)]), adoptsymbol ((yyvsp[(3) - (4)]), TOK_FIELD));
            ;}
    break;

  case 13:
#line 70 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    {
                free_ast ((yyvsp[(3) - (3)]));
                (yyval) = adopt1 ((yyvsp[(1) - (3)]), adoptsymbol ((yyvsp[(2) - (3)]), TOK_FIELD));
            ;}
    break;

  case 14:
#line 76 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 15:
#line 77 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 16:
#line 78 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 17:
#line 79 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 18:
#line 80 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 19:
#line 81 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 20:
#line 82 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = adoptsymbol ((yyvsp[(1) - (1)]), TOK_TYPEID); ;}
    break;

  case 21:
#line 85 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    {
                free_ast ((yyvsp[(3) - (4)]));
                (yyval) = adopt3 (new_astree (TOK_FUNCTION,
                (yyvsp[(1) - (4)])->filenr, (yyvsp[(1) - (4)])->linenr, (yyvsp[(1) - (4)])->offset, ""), (yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
            ;}
    break;

  case 22:
#line 90 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    {
                free_ast2 ((yyvsp[(4) - (4)]), (yyvsp[(3) - (4)]));
                (yyval) = adopt2 (new_astree (TOK_PROTOTYPE,
                (yyvsp[(1) - (4)])->filenr, (yyvsp[(1) - (4)])->linenr, (yyvsp[(1) - (4)])->offset, ""), (yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]));
            ;}
    break;

  case 23:
#line 95 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    {
                free_ast ((yyvsp[(3) - (4)]));
                (yyval) = adopt3 (new_astree (TOK_FUNCTION,
                (yyvsp[(1) - (4)])->filenr, (yyvsp[(1) - (4)])->linenr, (yyvsp[(1) - (4)])->offset, ""), (yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)]));
            ;}
    break;

  case 24:
#line 100 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    {
                free_ast2 ((yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
                (yyval) = adopt2 (new_astree (TOK_PROTOTYPE,
                (yyvsp[(1) - (4)])->filenr, (yyvsp[(1) - (4)])->linenr, (yyvsp[(1) - (4)])->offset, ""), (yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]));
            ;}
    break;

  case 25:
#line 107 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    {
                (yyval) = adopt1 (adoptsymbol ((yyvsp[(1) - (2)]), TOK_PARAMLIST), (yyvsp[(2) - (2)]));
            ;}
    break;

  case 26:
#line 110 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));;}
    break;

  case 27:
#line 113 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    {
                (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), adoptsymbol ((yyvsp[(3) - (3)]), TOK_DECLID));
            ;}
    break;

  case 28:
#line 116 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    {
                (yyval) = adopt1 ((yyvsp[(1) - (2)]), adoptsymbol ((yyvsp[(2) - (2)]), TOK_DECLID));
            ;}
    break;

  case 29:
#line 121 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    {
                free_ast ((yyvsp[(2) - (2)]));
                (yyval) = adoptsymbol ((yyvsp[(1) - (2)]), TOK_BLOCK);
            ;}
    break;

  case 30:
#line 125 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    {
                free_ast ((yyvsp[(2) - (2)]));
                (yyval) = adoptsymbol ((yyvsp[(1) - (2)]), TOK_BLOCK);
            ;}
    break;

  case 31:
#line 131 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    {
                (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
            ;}
    break;

  case 32:
#line 134 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    {
                (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
            ;}
    break;

  case 33:
#line 137 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    {
                (yyval) = adoptsymbol ((yyvsp[(1) - (1)]), TOK_BLOCK);
            ;}
    break;

  case 34:
#line 142 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 35:
#line 143 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 36:
#line 144 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 37:
#line 145 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 38:
#line 146 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 39:
#line 147 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    {
                free_ast ((yyvsp[(2) - (2)]));
                (yyval) = (yyvsp[(1) - (2)]);
            ;}
    break;

  case 40:
#line 151 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 41:
#line 154 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    {
                free_ast ((yyvsp[(4) - (4)]));
                (yyval) = adoptsymbol ((adopt2 ((yyvsp[(2) - (4)]), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]))), TOK_VARDECL);
            ;}
    break;

  case 42:
#line 160 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    {
                free_ast2 ((yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]));
                (yyval) = adopt2 ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]));
            ;}
    break;

  case 43:
#line 166 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    {
                free_ast2 ((yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]));
                (yyval) = adopt2 ((yyvsp[(1) - (5)]), (yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]));
            ;}
    break;

  case 44:
#line 170 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    {
                free_ast2 ((yyvsp[(2) - (7)]), (yyvsp[(4) - (7)]));
                free_ast ((yyvsp[(6) - (7)]));
                (yyval) = adopt3 (adoptsymbol ((yyvsp[(1) - (7)]), TOK_IFELSE), (yyvsp[(3) - (7)]), (yyvsp[(5) - (7)]), (yyvsp[(7) - (7)]));
            ;}
    break;

  case 45:
#line 177 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    {
                free_ast ((yyvsp[(2) - (2)]));
                (yyval) = adoptsymbol ((yyvsp[(1) - (2)]), TOK_RETURNVOID);
            ;}
    break;

  case 46:
#line 181 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    {
                free_ast ((yyvsp[(3) - (3)]));
                (yyval) = adopt1 ((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)]));
            ;}
    break;

  case 47:
#line 187 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 48:
#line 188 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 49:
#line 189 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 50:
#line 190 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 51:
#line 191 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    {
                free_ast2 ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
                (yyval) = (yyvsp[(2) - (3)]);
            ;}
    break;

  case 52:
#line 195 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 53:
#line 196 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 54:
#line 199 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = adopt1 (adoptsymbol ((yyvsp[(1) - (2)]), TOK_POS), (yyvsp[(2) - (2)])); ;}
    break;

  case 55:
#line 200 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = adopt1 (adoptsymbol ((yyvsp[(1) - (2)]), TOK_NEG), (yyvsp[(2) - (2)])); ;}
    break;

  case 56:
#line 201 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 57:
#line 202 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 58:
#line 203 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = adopt1 ((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 59:
#line 206 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 60:
#line 207 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 61:
#line 208 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 62:
#line 209 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 63:
#line 210 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 64:
#line 211 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 65:
#line 212 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 66:
#line 213 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 67:
#line 214 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 68:
#line 215 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 69:
#line 216 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 70:
#line 217 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 71:
#line 220 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    {
                free_ast2 ((yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
                (yyval) = adopt1 ((yyvsp[(1) - (4)]), adoptsymbol ((yyvsp[(2) - (4)]), TOK_TYPEID));
            ;}
    break;

  case 72:
#line 224 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    {
                free_ast2 ((yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]));
                (yyval) = adopt1 (adoptsymbol ((yyvsp[(1) - (5)]), TOK_NEWSTRING), (yyvsp[(4) - (5)]));
            ;}
    break;

  case 73:
#line 228 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    {
                free_ast2 ((yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]));
                (yyval) = adopt2 (adoptsymbol ((yyvsp[(1) - (5)]), TOK_NEWARRAY), (yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]));
            ;}
    break;

  case 74:
#line 234 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    {
                free_ast ((yyvsp[(3) - (3)]));
                (yyval) = adopt1 (adoptsymbol ((yyvsp[(2) - (3)]), TOK_CALL), (yyvsp[(1) - (3)]));
            ;}
    break;

  case 75:
#line 238 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    {
                free_ast ((yyvsp[(2) - (2)]));
                (yyval) = (yyvsp[(1) - (2)]);
            ;}
    break;

  case 76:
#line 244 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    {
                (yyval) = adopt2 (adoptsymbol ((yyvsp[(2) - (3)]), TOK_CALL), (yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
            ;}
    break;

  case 77:
#line 247 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    {
                free_ast ((yyvsp[(2) - (3)]));
                (yyval) = adopt1 ((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
            ;}
    break;

  case 78:
#line 253 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 79:
#line 254 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    {
                (yyval) = adopt2 ((yyvsp[(2) - (3)]), (yyvsp[(1) - (3)]), adoptsymbol ((yyvsp[(3) - (3)]), TOK_FIELD));
            ;}
    break;

  case 80:
#line 257 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    {
                free_ast ((yyvsp[(4) - (4)]));
                (yyval) = adopt2 (adoptsymbol ((yyvsp[(2) - (4)]), TOK_INDEX), (yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
            ;}
    break;

  case 81:
#line 263 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 82:
#line 264 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 83:
#line 265 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 84:
#line 266 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 85:
#line 267 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 86:
#line 268 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2171 "parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 271 "/Users/Joshua/Dropbox/School/UCSC/Classes/2016 - 3rd Quarter - Spring/CMPS 104A/CMPS 104A 4/CMPS 104A/parser.y"


const char *get_yytname (int symbol) {
    return yytname [YYTRANSLATE (symbol)];
}


bool is_defined_token (int symbol) {
    return YYTRANSLATE (symbol) > YYUNDEFTOK;
}

