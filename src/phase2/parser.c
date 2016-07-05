/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
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
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "parser.y"

#include<stdio.h>
#include "symtable.h"
#include "quads.c"
#include <stdlib.h> 
#include <string.h>
struct table *globalcurrentfunctions;
struct expr *headforcall;
int arraysnot=0;
int yyerror(char *yaccProvidedMessage);
int yylex(void);
extern int problem;
int rafa;
int kleftis;
extern int yylineno;
extern char* yytext; 
char* tempyytext;
char* symbol;  
extern FILE* yyin;

struct table *head;
struct mara *headf;
struct quad* quadtest;
char* temp=NULL;
struct expr* pinakastemp;
struct expr* objecttemp;
struct expr* insertelement;
struct expr* oneexpr;
struct expr* twoexpr;
struct expr* threeexpr;
struct expr* fourexpr;
struct expr* fiveexpr;
struct expr* sixexpr;
struct expr* coste;
struct expr* current_temp;
struct expr* break_head;	//per
struct expr* continue_head=NULL;//per
int funct_scope=0,scope=0;
int actif=0,actfuc=0;

int diaperasi=0;
int diaperasi2=0;
int activefunction=0;
int found=0;
int NoNameInt=0;
int exprnoname=0;
unsigned int total=0;
char bufferforint[9],nonamefunctionall[20],nonamedefault[12]="_f";
char bufferforexpr[9],nonameexpr[20],exprdefault[2]="_t";

int wehaveanstmt=0;
int NumOfLocVar=0;

int offset=1;
int global_offset=0;
int whichoffset=0;


int is_while;
int counter=0;
int tableitem=0;
int elistflag=0;
int indexedflag=0;
int coolflag=0;
int memberlvalue=0;
char* stringsave;
int CALLi=0;
int create=0;
int lineofnewfile=1;
int pincounter=0;
int help=0;

int anelistbegin=0;

int breakaccess=0;
int continueaccess=0;
  
double loop_counter=0;

int  global_a_counter=0,
  local_a_counter=0,
  formal_a_counter=0,
  bool_a_counter=0,
  string_a_counter=0,
  constnum_a_counter=0,
  number_a_counter=0,
  userfunc_a_counter=0,
  libfunc_a_counter=0,
  nil_a_counter=0;


/* Line 268 of yacc.c  */
#line 163 "parser.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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

/* Line 293 of yacc.c  */
#line 168 "parser.y"

	 char* stringVal;
	 int intValue;
	 double realVal;
	 struct expr* express;



/* Line 293 of yacc.c  */
#line 272 "parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 284 "parser.c"

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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
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
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  86
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   636

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  127
/* YYNRULES -- Number of states.  */
#define YYNSTATES  208

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    41,     2,     2,
      45,    46,    39,    37,    34,    38,    42,    40,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    50,    47,
      35,    33,    36,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    43,     2,    44,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,     2,    49,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,     8,    11,    14,    16,    18,
      20,    22,    24,    26,    28,    30,    32,    34,    36,    40,
      42,    43,    45,    47,    49,    51,    53,    55,    57,    59,
      61,    63,    65,    67,    69,    73,    76,    79,    82,    85,
      88,    91,    93,    95,    97,    99,   103,   105,   107,   109,
     113,   116,   119,   122,   125,   130,   134,   136,   142,   144,
     148,   151,   158,   160,   162,   166,   169,   175,   178,   182,
     189,   196,   202,   208,   209,   211,   213,   216,   219,   220,
     221,   227,   229,   231,   233,   235,   237,   239,   243,   247,
     250,   252,   255,   258,   260,   264,   269,   273,   278,   280,
     284,   286,   290,   292,   296,   302,   304,   308,   310,   315,
     318,   323,   326,   330,   334,   335,   336,   340,   342,   346,
     350,   351,   352,   353,   354,   362,   370,   373
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      52,     0,    -1,    53,    -1,    -1,    54,    -1,    53,    54,
      -1,    55,    47,    -1,    85,    -1,    92,    -1,    98,    -1,
      86,    -1,    71,    -1,    67,    -1,    29,    -1,    30,    -1,
      99,    -1,   100,    -1,    66,    -1,    55,    56,    55,    -1,
      57,    -1,    -1,    37,    -1,    38,    -1,    39,    -1,    40,
      -1,    41,    -1,    36,    -1,    13,    -1,    35,    -1,    15,
      -1,    14,    -1,    16,    -1,    17,    -1,    18,    -1,    45,
      55,    46,    -1,    38,    55,    -1,    19,    55,    -1,    20,
      76,    -1,    76,    20,    -1,    21,    76,    -1,    76,    21,
      -1,    58,    -1,    76,    -1,    62,    -1,    75,    -1,    45,
      67,    46,    -1,    74,    -1,    59,    -1,    32,    -1,    32,
      33,    55,    -1,    20,    32,    -1,    21,    32,    -1,    32,
      20,    -1,    32,    21,    -1,    32,    45,    61,    46,    -1,
      59,    42,     3,    -1,    60,    -1,    59,    42,     3,    33,
      55,    -1,    55,    -1,    55,    34,    61,    -1,    76,    63,
      -1,    45,    67,    46,    45,    79,    46,    -1,    64,    -1,
      65,    -1,    45,    79,    46,    -1,    64,    64,    -1,    23,
       3,    45,    79,    46,    -1,    65,    65,    -1,    76,    33,
      55,    -1,    24,    68,    45,    78,    46,    71,    -1,    24,
      69,    45,    78,    46,    71,    -1,    24,    69,    45,    46,
      71,    -1,    24,    68,    45,    46,    71,    -1,    -1,     3,
      -1,    54,    -1,    70,    54,    -1,    48,    49,    -1,    -1,
      -1,    48,    72,    70,    73,    49,    -1,     4,    -1,     5,
      -1,    31,    -1,    28,    -1,    25,    -1,    26,    -1,    43,
      82,    44,    -1,    43,    80,    44,    -1,    43,    44,    -1,
       3,    -1,    27,     3,    -1,    22,     3,    -1,    77,    -1,
      76,    42,     3,    -1,    76,    43,    55,    44,    -1,    62,
      42,     3,    -1,    62,    43,    55,    44,    -1,     3,    -1,
      78,    34,     3,    -1,    55,    -1,    79,    34,    55,    -1,
      55,    -1,    80,    34,    55,    -1,    48,    55,    50,    55,
      49,    -1,    81,    -1,    82,    34,    81,    -1,     8,    -1,
       6,    45,    55,    46,    -1,    84,    54,    -1,    84,    54,
      83,    54,    -1,    10,    47,    -1,    10,    55,    47,    -1,
      10,    24,    47,    -1,    -1,    -1,    87,    54,    88,    -1,
       7,    -1,    45,    55,    46,    -1,    90,    91,    89,    -1,
      -1,    -1,    -1,    -1,     9,    45,    79,    47,    96,    55,
      47,    -1,    97,    93,    79,    46,    94,    89,    95,    -1,
      11,    47,    -1,    12,    47,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   176,   176,   179,   182,   183,   186,   202,   206,   210,
     214,   218,   225,   230,   234,   238,   247,   263,   264,   274,
     278,   281,   286,   291,   296,   301,   306,   311,   316,   321,
     326,   331,   336,   341,   348,   355,   362,   371,   382,   393,
     404,   415,   424,   429,   498,   503,   507,   512,   515,   520,
     524,   528,   532,   536,   540,   545,   549,   552,   557,   560,
     563,   574,   580,   586,   592,   607,   610,   615,   618,   836,
     851,   865,   879,   896,   945,   989,   993,   998,  1003,  1008,
    1000,  1039,  1045,  1049,  1055,  1059,  1066,  1075,  1082,  1089,
    1097,  1177,  1198,  1223,  1230,  1262,  1365,  1369,  1378,  1409,
    1442,  1451,  1466,  1480,  1494,  1513,  1518,  1540,  1556,  1576,
    1586,  1607,  1617,  1627,  1653,  1660,  1664,  1671,  1684,  1695,
    1710,  1718,  1724,  1729,  1734,  1747,  1768,  1785
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "INTEGER", "FLOAT", "ifstmt",
  "whilestmt", "elsestmt", "forstmt", "returnstmt", "breakstmt",
  "continuestmt", "lesseq", "beq", "greq", "bne", "AND", "OR", "NOT",
  "plusplus", "minusminus", "dblakt", "dblt", "functionstmt", "truestmt",
  "falsestmt", "local", "nil", "onelcomm", "mullcomm", "string2",
  "librfunc", "'='", "','", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'",
  "'%'", "'.'", "'['", "']'", "'('", "')'", "';'", "'{'", "'}'", "':'",
  "$accept", "program", "teststmt2", "stmt", "expr", "op", "term",
  "primary", "lib", "lassign", "lexpr", "call", "callsuffix", "normcall",
  "methodcall", "assginexpr", "funcdef", "Nonamefucid", "fucid",
  "teststmt", "block", "$@1", "$@2", "const", "objectdef", "lvalue",
  "member", "idlist", "elist", "objelist", "indexedelem", "indexed",
  "elseprefix", "ifprefix", "if", "return", "loopstart", "loopend",
  "loopstmt", "whilestart", "whilesecond", "while", "N1", "N2", "N3", "M",
  "forprefix", "for", "break", "continue", 0
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
     285,   286,   287,    61,    44,    60,    62,    43,    45,    42,
      47,    37,    46,    91,    93,    40,    41,    59,   123,   125,
      58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    52,    53,    53,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    55,    55,    55,
      55,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    57,    57,    57,    57,    57,    57,
      57,    57,    58,    58,    58,    58,    58,    58,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    60,    61,    61,
      62,    62,    63,    63,    64,    64,    65,    65,    66,    67,
      67,    67,    67,    68,    69,    70,    70,    71,    72,    73,
      71,    74,    74,    74,    74,    74,    74,    75,    75,    75,
      76,    76,    76,    76,    77,    77,    77,    77,    78,    78,
      79,    79,    80,    80,    81,    82,    82,    83,    84,    85,
      85,    86,    86,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     2,     2,     2,     2,     2,
       2,     1,     1,     1,     1,     3,     1,     1,     1,     3,
       2,     2,     2,     2,     4,     3,     1,     5,     1,     3,
       2,     6,     1,     1,     3,     2,     5,     2,     3,     6,
       6,     5,     5,     0,     1,     1,     2,     2,     0,     0,
       5,     1,     1,     1,     1,     1,     1,     3,     3,     2,
       1,     2,     2,     1,     3,     4,     3,     4,     1,     3,
       1,     3,     1,     3,     5,     1,     3,     1,     4,     2,
       4,     2,     3,     3,     0,     0,     3,     1,     3,     3,
       0,     0,     0,     0,     7,     7,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      20,    90,    81,    82,     0,   117,     0,    20,     0,     0,
      20,     0,     0,     0,    73,    85,    86,     0,    84,    13,
      14,    83,    48,    20,    20,    20,    78,     0,    20,     4,
       0,    19,    41,    47,    56,    43,    17,    12,    11,    46,
      44,    42,    93,    20,     7,    10,     0,     8,   120,     9,
      15,    16,    20,    20,     0,   111,     0,   126,   127,    36,
      50,     0,     0,    37,    51,    39,    92,    74,     0,     0,
      91,    52,    53,    20,    20,    35,    89,    20,   102,     0,
     105,     0,     0,     0,    77,    20,     1,     5,    27,    30,
      29,    31,    32,    33,    28,    26,    21,    22,    23,    24,
      25,     6,    20,     0,     0,    20,    38,    40,     0,    20,
       0,    20,    20,    60,    62,    63,   109,    20,   114,    20,
       0,   100,     0,   113,   112,     0,     0,     0,    49,    58,
       0,     0,    20,    88,     0,    87,    34,    45,    75,    20,
      18,    55,    96,     0,     0,    68,    94,     0,     0,    65,
      67,   107,    20,     0,    20,   119,     0,   108,    20,   123,
       0,    98,     0,     0,     0,     0,    20,    54,    20,   103,
     106,    20,    76,     0,    20,    97,    20,    95,    64,   110,
     118,   115,   121,   101,    20,    72,     0,     0,    71,     0,
      59,     0,     0,    80,    57,     0,   116,   114,     0,    99,
      69,    70,   104,    61,    66,   122,   124,   125
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    27,    28,    29,    30,   102,    31,    32,    33,    34,
     130,    35,   113,   114,   115,    36,    37,    68,    69,   139,
      38,    85,   173,    39,    40,    41,    42,   163,   122,    79,
      80,    81,   152,    43,    44,    45,   154,   196,   155,    46,
     118,    47,   119,   197,   207,   184,    48,    49,    50,    51
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -112
static const yytype_int16 yypact[] =
{
     175,  -112,  -112,  -112,   -38,  -112,   -23,    54,   -34,    -4,
     328,    61,    81,    44,    65,  -112,  -112,    66,  -112,  -112,
    -112,  -112,   111,   328,     6,   115,    23,    87,   221,  -112,
     405,  -112,  -112,    35,  -112,    -3,  -112,  -112,  -112,  -112,
    -112,   129,  -112,   298,  -112,  -112,    45,  -112,  -112,  -112,
    -112,  -112,   328,   328,    47,  -112,   418,  -112,  -112,  -112,
    -112,    72,    -3,   147,  -112,   147,  -112,  -112,    55,    62,
    -112,  -112,  -112,   328,   328,   169,  -112,   328,   595,   -20,
    -112,   -14,   466,    76,  -112,   298,  -112,  -112,  -112,  -112,
    -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,
    -112,  -112,   328,   121,   124,   328,  -112,  -112,   135,   328,
     145,   328,   328,  -112,   109,   132,   149,   328,  -112,   328,
     500,   595,   -32,  -112,  -112,   117,     2,     9,   595,   588,
     119,   361,   328,  -112,   118,  -112,  -112,   123,  -112,   251,
     595,   140,  -112,   546,   131,   595,  -112,   556,   -11,   109,
     132,  -112,   298,   512,   298,  -112,    -5,  -112,   328,  -112,
     123,  -112,   143,    75,   143,    77,   328,  -112,   328,   595,
    -112,   328,  -112,   134,   328,  -112,   328,  -112,  -112,  -112,
    -112,  -112,  -112,   595,   328,  -112,   185,   143,  -112,   143,
    -112,   368,    83,  -112,   595,    99,  -112,  -112,   453,  -112,
    -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -112,  -112,  -112,   -24,    -7,  -112,  -112,  -112,  -112,  -112,
      27,    41,  -112,   -93,   -79,  -112,   -19,  -112,  -112,  -112,
     -73,  -112,  -112,  -112,  -112,    51,  -112,    71,  -111,  -112,
      78,  -112,  -112,  -112,  -112,  -112,  -112,  -112,    14,  -112,
    -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112,  -112
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -80
static const yytype_int16 yytable[] =
{
      56,   148,   158,    59,    87,   161,    83,    52,   156,     1,
       2,     3,   161,    57,   132,   159,    75,    78,    82,   116,
     134,   149,    53,   158,   133,    10,    11,    12,    13,   158,
     135,    15,    16,    17,    18,   178,   150,    21,    22,   104,
     105,   182,   125,    58,    23,   120,   121,    66,   162,    24,
      76,    25,    62,    62,    77,   164,   149,     1,     2,     3,
     192,   138,    63,    65,     1,   195,   128,   129,    67,    70,
     131,   150,    84,    10,    11,    12,    13,   103,    54,    15,
      16,    17,    18,    13,     1,    21,    22,    86,    17,   185,
     117,   188,    23,    60,   123,   140,    14,    24,   143,    25,
     126,    55,   145,    13,   147,   121,    61,   127,    17,   186,
     153,   186,   121,    64,   200,   172,   201,   158,     1,     2,
       3,   187,   137,   189,   141,   169,    61,   142,   179,   203,
     181,    71,    72,   158,    10,    11,    12,    13,   144,    14,
      15,    16,    17,    18,    73,   204,    21,    22,   146,   106,
     107,   183,   108,    23,   112,   108,    74,   151,    24,   129,
      25,   191,   109,   160,   121,   167,    77,   194,   171,   121,
     108,   110,   111,   174,   112,    -3,   176,   198,     1,     2,
       3,     4,     5,   193,     6,     7,     8,     9,   199,   110,
     111,    26,   112,   190,    10,    11,    12,    13,   165,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    98,    99,
     100,   205,   170,    23,     0,     0,     0,     0,    24,     0,
      25,    -2,     0,    26,     1,     2,     3,     4,     5,     0,
       6,     7,     8,     9,     0,     0,     0,     0,     0,     0,
      10,    11,    12,    13,     0,    14,    15,    16,    17,    18,
      19,    20,    21,    22,     1,     2,     3,     4,     5,    23,
       6,     7,     8,     9,    24,     0,    25,     0,     0,    26,
      10,    11,    12,    13,     0,    14,    15,    16,    17,    18,
      19,    20,    21,    22,     0,     0,     0,     0,     0,    23,
       0,     0,     0,     0,    24,     0,    25,     0,     0,    26,
     -79,     1,     2,     3,     4,     5,     0,     6,     7,     8,
       9,     0,     0,     0,     0,     0,     0,    10,    11,    12,
      13,     0,    14,    15,    16,    17,    18,    19,    20,    21,
      22,     1,     2,     3,     0,     0,    23,     0,     0,     0,
       0,    24,     0,    25,     0,     0,    26,    10,    11,    12,
      13,     0,     0,    15,    16,    17,    18,     0,     0,    21,
      22,     0,     0,     0,     0,     0,    23,     0,     0,     0,
       0,    24,     0,    25,    88,    89,    90,    91,    92,    93,
       0,    88,    89,    90,    91,    92,    93,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    94,    95,    96,    97,
      98,    99,   100,    94,    95,    96,    97,    98,    99,   100,
       0,   168,     0,     0,     0,     0,     0,   202,    88,    89,
      90,    91,    92,    93,     0,     0,     0,     0,     0,     0,
       0,    88,    89,    90,    91,    92,    93,     0,     0,     0,
      94,    95,    96,    97,    98,    99,   100,     0,     0,     0,
       0,     0,   101,    94,    95,    96,    97,    98,    99,   100,
       0,     0,     0,     0,     0,   124,    88,    89,    90,    91,
      92,    93,     0,     0,     0,     0,     0,     0,     0,    88,
      89,    90,    91,    92,    93,     0,     0,     0,    94,    95,
      96,    97,    98,    99,   100,     0,     0,     0,     0,     0,
     206,    94,    95,    96,    97,    98,    99,   100,     0,     0,
       0,     0,   136,    88,    89,    90,    91,    92,    93,     0,
       0,     0,     0,     0,     0,    88,    89,    90,    91,    92,
      93,     0,     0,     0,     0,    94,    95,    96,    97,    98,
      99,   100,     0,     0,     0,     0,   157,    94,    95,    96,
      97,    98,    99,   100,     0,     0,     0,     0,   180,    88,
      89,    90,    91,    92,    93,     0,     0,     0,     0,    88,
      89,    90,    91,    92,    93,     0,     0,     0,     0,     0,
       0,    94,    95,    96,    97,    98,    99,   100,     0,     0,
     175,    94,    95,    96,    97,    98,    99,   100,     0,     0,
     177,    88,    89,    90,    91,    92,    93,     0,    88,    89,
      90,    91,    92,    93,     0,     0,     0,     0,     0,     0,
       0,     0,   166,    94,    95,    96,    97,    98,    99,   100,
      94,    95,    96,    97,    98,    99,   100
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-112))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       7,   112,    34,    10,    28,     3,    25,    45,   119,     3,
       4,     5,     3,    47,    34,    47,    23,    24,    25,    43,
      34,   114,    45,    34,    44,    19,    20,    21,    22,    34,
      44,    25,    26,    27,    28,    46,   115,    31,    32,    42,
      43,    46,    61,    47,    38,    52,    53,     3,    46,    43,
      44,    45,    11,    12,    48,    46,   149,     3,     4,     5,
     171,    85,    11,    12,     3,   176,    73,    74,     3,     3,
      77,   150,    49,    19,    20,    21,    22,    42,    24,    25,
      26,    27,    28,    22,     3,    31,    32,     0,    27,   162,
      45,   164,    38,    32,    47,   102,    24,    43,   105,    45,
      45,    47,   109,    22,   111,   112,    45,    45,    27,    34,
     117,    34,   119,    32,   187,   139,   189,    34,     3,     4,
       5,    46,    46,    46,     3,   132,    45,     3,   152,    46,
     154,    20,    21,    34,    19,    20,    21,    22,     3,    24,
      25,    26,    27,    28,    33,    46,    31,    32,     3,    20,
      21,   158,    23,    38,    45,    23,    45,     8,    43,   166,
      45,   168,    33,    46,   171,    46,    48,   174,    45,   176,
      23,    42,    43,    33,    45,     0,    45,   184,     3,     4,
       5,     6,     7,    49,     9,    10,    11,    12,     3,    42,
      43,    48,    45,   166,    19,    20,    21,    22,   127,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    39,    40,
      41,   197,   134,    38,    -1,    -1,    -1,    -1,    43,    -1,
      45,     0,    -1,    48,     3,     4,     5,     6,     7,    -1,
       9,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    20,    21,    22,    -1,    24,    25,    26,    27,    28,
      29,    30,    31,    32,     3,     4,     5,     6,     7,    38,
       9,    10,    11,    12,    43,    -1,    45,    -1,    -1,    48,
      19,    20,    21,    22,    -1,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    43,    -1,    45,    -1,    -1,    48,
      49,     3,     4,     5,     6,     7,    -1,     9,    10,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,
      22,    -1,    24,    25,    26,    27,    28,    29,    30,    31,
      32,     3,     4,     5,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    43,    -1,    45,    -1,    -1,    48,    19,    20,    21,
      22,    -1,    -1,    25,    26,    27,    28,    -1,    -1,    31,
      32,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    43,    -1,    45,    13,    14,    15,    16,    17,    18,
      -1,    13,    14,    15,    16,    17,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,    38,
      39,    40,    41,    35,    36,    37,    38,    39,    40,    41,
      -1,    50,    -1,    -1,    -1,    -1,    -1,    49,    13,    14,
      15,    16,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    13,    14,    15,    16,    17,    18,    -1,    -1,    -1,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    47,    35,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    47,    13,    14,    15,    16,
      17,    18,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      14,    15,    16,    17,    18,    -1,    -1,    -1,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      47,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    46,    13,    14,    15,    16,    17,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    13,    14,    15,    16,    17,
      18,    -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    46,    35,    36,    37,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    46,    13,
      14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,    13,
      14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      44,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      44,    13,    14,    15,    16,    17,    18,    -1,    13,    14,
      15,    16,    17,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    35,    36,    37,    38,    39,    40,    41,
      35,    36,    37,    38,    39,    40,    41
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     9,    10,    11,    12,
      19,    20,    21,    22,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    38,    43,    45,    48,    52,    53,    54,
      55,    57,    58,    59,    60,    62,    66,    67,    71,    74,
      75,    76,    77,    84,    85,    86,    90,    92,    97,    98,
      99,   100,    45,    45,    24,    47,    55,    47,    47,    55,
      32,    45,    62,    76,    32,    76,     3,     3,    68,    69,
       3,    20,    21,    33,    45,    55,    44,    48,    55,    80,
      81,    82,    55,    67,    49,    72,     0,    54,    13,    14,
      15,    16,    17,    18,    35,    36,    37,    38,    39,    40,
      41,    47,    56,    42,    42,    43,    20,    21,    23,    33,
      42,    43,    45,    63,    64,    65,    54,    45,    91,    93,
      55,    55,    79,    47,    47,    67,    45,    45,    55,    55,
      61,    55,    34,    44,    34,    44,    46,    46,    54,    70,
      55,     3,     3,    55,     3,    55,     3,    55,    79,    64,
      65,     8,    83,    55,    87,    89,    79,    46,    34,    47,
      46,     3,    46,    78,    46,    78,    34,    46,    50,    55,
      81,    45,    54,    73,    33,    44,    45,    44,    46,    54,
      46,    54,    46,    55,    96,    71,    34,    46,    71,    46,
      61,    55,    79,    49,    55,    79,    88,    94,    55,     3,
      71,    71,    49,    46,    46,    89,    47,    95
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
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


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Discard the shifted token.  */
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

/* Line 1806 of yacc.c  */
#line 176 "parser.y"
    {
/* 		printf("One progrⒶ m \n"); */
		}
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 187 "parser.y"
    { 
		  memberlvalue=0;
		  diaperasi=0;
		  diaperasi2=0;
		  exprnoname=0;
		  help=0;
		  pincounter=0;
		  fiveexpr=NULL;
		if(kleftis==1){
		    kleftis=0;
		    ErrorM("Using ProgramFunc as an lvalue");
		  }
		  (yyval.express)=tempexpr(var_e,var_s,programvarmvar,0,0,lineofnewfile);//kati trelo
		  //head=ST_Insert( head , temp, GLOBAL , 0 , yylineno , 1 );
		}
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 203 "parser.y"
    {
/* 		  printf("Here we have statement if\n"); */
		}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 207 "parser.y"
    {
/* 		  printf("Here we have statement while\n"); */
		}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 211 "parser.y"
    {
/* 		  printf("Here we have statement for\n"); */
		}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 215 "parser.y"
    {
/* 		  printf("Here we have statement return\n"); */
		}
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 219 "parser.y"
    {
/* 		  printf("Here we have statement block\n"); */
		// printf("BLOCKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK $$=%d $1=%d\n",$$->sym->line,$1->sym->line);
		 (yyval.express)=(yyvsp[(1) - (1)].express);  //perister for if
		
		}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 226 "parser.y"
    {
/* 		  printf("Here we have statement funcdef\n"); */
		}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 231 "parser.y"
    {
/* 		  printf("Here we have one line comment\n"); */
		}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 235 "parser.y"
    {
/* 		  printf("Here we have multiline comment\n"); */
		}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 239 "parser.y"
    {
		if(breakaccess){
		  break_head=break_insert(break_head,(yyvsp[(1) - (1)].express),loop_counter);   //insert break to breaklist
		  breakaccess=0;
		}
		
/* 		printf("Here we have statement break\n"); */
		}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 248 "parser.y"
    {  
		
		if(continueaccess){
		  continue_insert(continue_head,(yyvsp[(1) - (1)].express),loop_counter);   //insert break to breaklist
		  continueaccess=0;
		  }
		
		
/* 		printf("Here we have statement continue\n"); */
		}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 265 "parser.y"
    { (yyval.express)=tempexpr(var_e,var_s,programvarmvar,0,0,0);
		    emit(get_op((yyvsp[(2) - (3)].stringVal)),(yyvsp[(1) - (3)].express),(yyvsp[(3) - (3)].express),(yyval.express),0,lineofnewfile,yylineno);
		     
		         current_temp=(yyval.express); //perister
		
		    lineofnewfile++;
		}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 275 "parser.y"
    {
		  (yyval.express)=(yyvsp[(1) - (1)].express);
		}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 282 "parser.y"
    {
		  (yyval.stringVal)="+";
/* 		  printf("Here we have operator +\n"); */
		}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 287 "parser.y"
    { 
		  (yyval.stringVal)="-";
/* 		  printf("Here we have operator -'\n"); */
		}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 292 "parser.y"
    {  
		  (yyval.stringVal)="*";	
/* 		printf("Here we have operator *\n"); */
		}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 297 "parser.y"
    { 
		  (yyval.stringVal)="/";
/* 		printf("Here we have operator /\n"); */
		}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 302 "parser.y"
    { 
		  (yyval.stringVal)="%";
/* 		printf("Here we have operator percent \n"); */
		}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 307 "parser.y"
    { 
		  (yyval.stringVal)=">";
/* 		printf("Here we have operator >\n"); */
		}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 312 "parser.y"
    { 
		  (yyval.stringVal)="<=";
/* 		printf("Here we have operator <=\n"); */
		}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 317 "parser.y"
    { 
		  (yyval.stringVal)="<";
/* 		  printf("Here we have operator <\n"); */
		}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 322 "parser.y"
    { 
		  (yyval.stringVal)=">=";
/* 		printf("Here we have operator >=\n"); */
		}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 327 "parser.y"
    { 
		  (yyval.stringVal)="==";
/* 		printf("Here we have operator ==\n"); */
		}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 332 "parser.y"
    { 
		  (yyval.stringVal)="!=";
/* 		 printf("Here we have operator !=\n"); */
		}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 337 "parser.y"
    { 
		  (yyval.stringVal)="&&";
/* 		printf("Here we have operator &&\n"); */
		}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 342 "parser.y"
    { 
		  (yyval.stringVal)="||";
/* 		  printf("Here we have operator ||\n"); */
		}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 349 "parser.y"
    {
		  		  
		   current_temp=tempexpr(var_e,var_s,programvarmvar,0,0,0);
		  (yyval.express)=(yyvsp[(2) - (3)].express);
/* 		  printf("Here we have term (expr)\n"); */
		}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 356 "parser.y"
    {
		   (yyval.express)=tempexpr(var_e,var_s,programvarmvar,0,0,0);
		  emit(uminus,(yyvsp[(2) - (2)].express),NULL,(yyval.express),0,lineofnewfile,yylineno);
		  lineofnewfile++;
/* 		  printf("Here we have term -expr\n"); */
		}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 363 "parser.y"
    {
		
		  sixexpr=tempexpr(var_e,var_s,programvarmvar,0,0,0);
		  (yyval.express)=sixexpr;
		  emit(not,(yyvsp[(2) - (2)].express),NULL,sixexpr,0,lineofnewfile,yylineno);
		  lineofnewfile++;
/* 		 printf("Here we have term !expr\n"); */
		}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 372 "parser.y"
    {
		  oneexpr=constnewexpr(costnum_e,1);
		  (yyval.express)=tempexpr(var_e,var_s,programvarmvar,0,0,0);
		   current_temp=(yyval.express); //perister
		  emit(add,(yyvsp[(2) - (2)].express),oneexpr,(yyval.express),0,lineofnewfile,yylineno);
		   lineofnewfile++;
		  emit(assign,(yyval.express),NULL,(yyvsp[(2) - (2)].express),0,lineofnewfile,yylineno);
		   lineofnewfile++;
/* 		  printf("Here we have term ++expr\n"); */
		}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 383 "parser.y"
    {
		  oneexpr=constnewexpr(costnum_e,1);
		  (yyval.express)=tempexpr(var_e,var_s,programvarmvar,0,0,0);
		    
		  emit(add,(yyvsp[(1) - (2)].express),oneexpr,(yyval.express),0,lineofnewfile,yylineno);
		   lineofnewfile++;
		  emit(assign,(yyval.express),NULL,(yyvsp[(1) - (2)].express),0,lineofnewfile,yylineno);
		   lineofnewfile++;
/* 		  printf("Here we have term expr++\n"); */
		}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 394 "parser.y"
    {
		  oneexpr=constnewexpr(costnum_e,1);
		  (yyval.express)=tempexpr(var_e,var_s,programvarmvar,0,0,0);
		 
		  emit(sub,(yyvsp[(2) - (2)].express),oneexpr,(yyval.express),0,lineofnewfile,yylineno);
		   lineofnewfile++;
		  emit(assign,(yyval.express),NULL,(yyvsp[(2) - (2)].express),0,lineofnewfile,yylineno);
		    lineofnewfile++;
/* 		  printf("Here we have term --expr\n"); */
		}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 405 "parser.y"
    {
		  oneexpr=constnewexpr(costnum_e,1);
		  (yyval.express)=tempexpr(var_e,var_s,programvarmvar,0,0,0);
		
		  emit(sub,(yyvsp[(1) - (2)].express),oneexpr,(yyval.express),0,lineofnewfile,yylineno);
		   lineofnewfile++;
		  emit(assign,(yyval.express),NULL,(yyvsp[(1) - (2)].express),0,lineofnewfile,yylineno);
		     lineofnewfile++;
/* 		  printf("Here we have term expr--\n"); */
		}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 415 "parser.y"
    {
		  (yyval.express)=(yyvsp[(1) - (1)].express);
		  
		
/* 		  printf("Here we have primary expr\n"); */
		  
		}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 425 "parser.y"
    {
		  (yyval.express)=(yyvsp[(1) - (1)].express);
/* 		  printf("Here we have primary lvalue\n"); */
		}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 430 "parser.y"
    {
		
	
		struct expr *tmpexprlook;
		
/* 		struct expr *exprlook(struct expr *head,char * name); */
			 
		
		 if(CALLi==0)
		  ST_DeleteTheLast(head);
		  
		  
		    
		 if(globalcurrentfunctions->name!=NULL) 
		  tempyytext=strdup(globalcurrentfunctions->name);
		 else 
		  tempyytext="noname";
		 
     // printf("\n\t\t\t\t\t\t\t\t\ttempyytext=%s-uuuu=%s\n",tempyytext,globalcurrentfunctions->name);  
		  if(!ST_Lookup(head,tempyytext,scope,USERFUNC,actfuc))
		  {
		    ErrorM("Function Not founded to call");
		  }
		  else
		  {
		   
		  
		  
		  if( strcmp(globalcurrentfunctions->name,"print")==0|| strcmp(globalcurrentfunctions->name,"input")==0|| strcmp(globalcurrentfunctions->name,"objectmemberkeys")==0|| strcmp(globalcurrentfunctions->name,"objecttotalmembers")==0|| strcmp(globalcurrentfunctions->name,"objectcopy")==0|| strcmp(globalcurrentfunctions->name,"totalarguments")==0|| strcmp(globalcurrentfunctions->name,"typeof")==0|| strcmp(globalcurrentfunctions->name,"strtonum")==0|| strcmp(globalcurrentfunctions->name,"sqrt")==0|| strcmp(globalcurrentfunctions->name,"cos")==0|| strcmp(globalcurrentfunctions->name,"sin")==0){
		   
		   
		    (yyval.express)=lvaluenewexpr(libraryfunc_e,libraryfunc_s,strdup(globalcurrentfunctions->name),functionlocal,1,scope,yylineno);
		    emit(call,NULL,NULL,(yyval.express),0,lineofnewfile,yylineno);
		       lineofnewfile++;
		       
		       
		    (yyval.express)=tempexpr(conststring_e,var_s,programvarmvar,0,0,0);
		   
		    emit(getretval,NULL,NULL,(yyval.express),0,lineofnewfile,yylineno);
		       lineofnewfile++;
		    }
		  else{
		    tmpexprlook=exprlook(headforcall,globalcurrentfunctions->name);
		 //   tmpexprlook->sym->type=7;
		    
		    emit(call,NULL,NULL,tmpexprlook,0,lineofnewfile,yylineno);
		       lineofnewfile++;
		      
		    
		    (yyval.express)=tempexpr(var_e,var_s,programvarmvar,0,0,0);
		   
		    emit(getretval,NULL,NULL,(yyval.express),0,lineofnewfile,yylineno);
		       lineofnewfile++;
		       
		    }
// 		/* while($1!=NULL){
// 			 // emit(param,lvaluenewexpr(var_e,var_s,$1->sym->name,formalarg,1,scope,yylineno),NULL,NULL,0,lineofnewfile,yylineno);
// 			  //lineofnewfile++;
// 			  $1=$1->next;
// 		   }*/
		  }
		  
		 
		
		 
		  
/* 		 printf("Here we have primary call\n"); */
		}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 499 "parser.y"
    {
		  (yyval.express)=(yyvsp[(1) - (1)].express);
/* 		  printf("Heere we have primary objectdef\n"); */
		}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 504 "parser.y"
    {
/* 		  printf("Here we have primary (funcdef)\n"); */
		}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 508 "parser.y"
    {
		  (yyval.express)=(yyvsp[(1) - (1)].express);
/* 		  printf("Here we have primary const\n"); */
		}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 516 "parser.y"
    {
		  
/* 		  ErrorM("Variable used as library function"); */
		}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 521 "parser.y"
    {
/* 		  ErrorM("Variable used as library function1"); */
		}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 525 "parser.y"
    {
/* 		  ErrorM("Variable used as library function2"); */
		}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 529 "parser.y"
    {
/* 		  ErrorM("Variable used as library function3"); */
		}
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 533 "parser.y"
    {
/* 		  ErrorM("Variable used as library function4"); */
		}
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 537 "parser.y"
    {
/* 		  ErrorM("Variable used as library function5"); */
		}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 541 "parser.y"
    {
		    
/* 		  printf("Here we have primary librfunc\n"); */
		}
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 546 "parser.y"
    {
/* 		  printf("Here we have librfunc.ID\n"); */
		}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 553 "parser.y"
    {
/* 		  printf("Here we have librfunc lvalue \n"); */
		}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 557 "parser.y"
    {
/* 		    printf("lexpr\n"); */
		}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 564 "parser.y"
    {
		
		 
		 (yyval.express)=(yyvsp[(2) - (2)].express);
		 
		   
		
		  
/* 		  printf("Here we have call lvalue callsuffix\n"); */
		}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 575 "parser.y"
    {
/* 		  printf("Here we have call (funcdef) (elist)\n"); */
		}
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 581 "parser.y"
    {
		  (yyval.express)=(yyvsp[(1) - (1)].express);
		  kleftis=2;
/* 		  printf("Here we have callsuffix normcall\n"); */
		}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 587 "parser.y"
    {
/* 		  printf("Here we have callsuffix methodcall\n"); */
		}
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 593 "parser.y"
    {
		  (yyval.express)=(yyvsp[(2) - (3)].express);
		emit(param,(yyval.express),NULL,NULL,0,lineofnewfile,yylineno);
		lineofnewfile++;
		/*while($$!=NULL){
		printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!%s\n",$$->sym->name);
		
		
		$$=$$->next;
		
		}*/
		
/* 		printf("Here we have normcall\n"); */
		}
    break;

  case 66:

/* Line 1806 of yacc.c  */
#line 611 "parser.y"
    {
		
/* 		printf("Here we have methodcall\n"); */
		}
    break;

  case 68:

/* Line 1806 of yacc.c  */
#line 619 "parser.y"
    {
/* 		  printf("Here we have an assignment\n"); */
		  
		if( tableitem == 1 ){
		    create=0;
		    if( elistflag ==1 ){//if [x,x,x]
		      oneexpr=(yyvsp[(3) - (3)].express);
		      while( oneexpr->next != NULL ){
			oneexpr->type=tableitem_e;
			oneexpr=oneexpr->next;
		      }
/* 		      printf("\n\n"); */
		      elistflag=0;

		      (yyvsp[(1) - (3)].express)->type=tableitem_e;
		      (yyvsp[(1) - (3)].express)->index=(yyvsp[(3) - (3)].express);
		    
		     
		      emit(assign,objecttemp,NULL,(yyvsp[(1) - (3)].express),0,lineofnewfile,yylineno);
		         lineofnewfile++;
		    }
		    else if( indexedflag ==1 ){//if [x:y,x:y,x:y]
		      oneexpr=(yyvsp[(3) - (3)].express);
		      while( oneexpr->next != NULL ){
			oneexpr->type=tableitem_e;
			oneexpr=oneexpr->next;
		      }
/* 		      printf("\n\n"); */
		      indexedflag=0;

		      (yyvsp[(1) - (3)].express)->type=tableitem_e;
		      (yyvsp[(1) - (3)].express)->index=(yyvsp[(3) - (3)].express);
		      
		      
		      emit(assign,objecttemp,NULL,(yyvsp[(1) - (3)].express),0,lineofnewfile,yylineno);
		         lineofnewfile++;
		    }
		    else{
		      (yyvsp[(1) - (3)].express)->type=tableitem_e;
		      (yyvsp[(1) - (3)].express)->index=(yyvsp[(3) - (3)].express);
		     
		   
		      emit(tablecreate,NULL,NULL,(yyvsp[(1) - (3)].express),0,lineofnewfile,yylineno);
		         lineofnewfile++;
		    }
		    tableitem=0;
		  }
		  else if( diaperasi2 == 1 ){
/* 		    ErrorM("Table not found"); */
		  }
		  else if ( diaperasi == 1 ){
/* 		    printf("\n!!DIAPERASI!!\n"); */
		    if( (yyvsp[(1) - (3)].express)->index == NULL ){// diladi einai tis morfis x=t[x]
		    
		     
		      emit(tablegetelem,pinakastemp,(yyvsp[(3) - (3)].express),(yyvsp[(1) - (3)].express),0,lineofnewfile,yylineno);
		         lineofnewfile++;
		      diaperasi == 0;
		    }
		    else if( (yyvsp[(3) - (3)].express)->index == NULL ){// diladi einai tis morfis t[x]=x
/* 		      printf("YO2"); */
		      diaperasi= 2;
		    }
		  }
		  else if ( diaperasi == 3 ){
/* 		    printf("\n!!DIAPERASI EMPTY!!\n"); */
		    if( (yyvsp[(3) - (3)].express) == NULL ){// diladi einai tis morfis x=t[x]
/* 		      printf("x=t[x]\n"); */
		      
		     
		      emit(tablegetelem,NULL,NULL,(yyvsp[(1) - (3)].express),0,lineofnewfile,yylineno);
		         lineofnewfile++;
		    }		    
		    else{// diladi einai tis morfis t[x]=x
/* 		      printf("t[x]=x\n"); */
		      
		      insertelement->index=(yyvsp[(3) - (3)].express);
		      pinakastemp->index=insertelement;
		      emit(tablesetelem,insertelement,(yyvsp[(3) - (3)].express),pinakastemp,0,lineofnewfile,yylineno);
		         lineofnewfile++;
		    }
		    diaperasi= 0;
		  }
		  else if ( diaperasi == 4 ){
/* 		    printf("\n!!DIAPERASI NEW ENTRY!!\n"); */
		    //printf("{%s=%f}",$1->sym->name,$3->numConst);
		    if( (yyvsp[(3) - (3)].express) == NULL ){// diladi einai tis morfis x=t[x]
/* 		      printf("x=t[x]\n"); */
		      
		   
		      emit(tablegetelem,NULL,NULL,(yyvsp[(1) - (3)].express),0,lineofnewfile,yylineno);
		         lineofnewfile++;
		    }		    
		    else{// diladi einai tis morfis t[x]=x
/* 		      printf("t[x]=x\n"); */
		      oneexpr=pinakastemp;
		      oneexpr=oneexpr->index;//paw sto prwto stoixeio
		      twoexpr=oneexpr;//to prwto stoixeio
		      while( oneexpr != NULL ){
			  twoexpr=oneexpr;
			  oneexpr=oneexpr->next;
		      }
		      insertelement->index=(yyvsp[(3) - (3)].express);
		      twoexpr->next=insertelement;
		      
		      
		      emit(tablesetelem,insertelement,(yyvsp[(3) - (3)].express),pinakastemp,0,lineofnewfile,yylineno);
		         lineofnewfile++;
		    }
		    diaperasi= 0;
		  }
		  else if( memberlvalue == 1 ){
		    if( found == 1 ){
			      found=0;
			      memberlvalue=0;
			      counter=0;
			      quadtest=quads;
			      while( counter < currQuad ){
				if( strcmp(quadtest->result->sym->name,(yyvsp[(1) - (3)].express)->sym->name) == 0 ){//an vrethei o pinakas
				  oneexpr=quadtest->result;
				  if( oneexpr->index != NULL ){//an exei indexes
				    oneexpr=oneexpr->index;//paw sto prwto stoixeio
				    if( oneexpr->index == NULL ){
				      ErrorR(":wrong type of table",(yyvsp[(1) - (3)].express)->sym->name);
				      break;
				    }
				    twoexpr=oneexpr;//to prwto stoixeio
				    threeexpr=oneexpr;
/* 				    printf("\n"); */
				    while( oneexpr != NULL ){
/* 					printf("{%s}",oneexpr->sym->name); */
					if( oneexpr->sym!=NULL && (yyvsp[(3) - (3)].express)->sym != NULL ){
					  if( strcmp((yyvsp[(1) - (3)].express)->index->sym->name,oneexpr->sym->name) == 0 ){
					    oneexpr->index=(yyvsp[(3) - (3)].express);
					    coolflag=1;
					    break;
					  }
					}
					else {
					  if( (yyvsp[(3) - (3)].express)->numConst == oneexpr->numConst ){
					    (yyval.express)=oneexpr;
/* 					    printf("\n!!FOUND!!\n"); */
					    coolflag=1;
					    break;
					  }
					}
					twoexpr=oneexpr;
					oneexpr=oneexpr->next;
				    }
				    if( coolflag == 1 ){
				      //printf("\n{%s}\n",$$->strConst);
				       			     
				      emit(tablesetelem,(yyvsp[(1) - (3)].express)->index,(yyvsp[(3) - (3)].express),quadtest->result,0,lineofnewfile,yylineno);
				         lineofnewfile++;
				      coolflag=0;
				      break;
				    }
				    if( coolflag == 0 ){
				      //insert
				      (yyvsp[(1) - (3)].express)->index->index=(yyvsp[(3) - (3)].express);
				      twoexpr->next=(yyvsp[(1) - (3)].express)->index;
/* 				      printf("\ninserted\n"); */
							      while( threeexpr != NULL ){
/* 								printf("{%s}",threeexpr->sym->name); */
								threeexpr=threeexpr->next;
							      }
/* 							      printf("\n"); */
							       
				      emit(tablesetelem,(yyvsp[(1) - (3)].express)->index,(yyvsp[(3) - (3)].express),quadtest->result,0,lineofnewfile,yylineno);
				      lineofnewfile++;
				      break;
				    }
				    coolflag=0;
				  }
				  else{
				    //insert
/* 				    printf("\nempty inserted{%s->%s}\n",oneexpr->sym->name,$1->index->sym->name); */
				    if((yyvsp[(3) - (3)].express) != NULL){
				    }
				    (yyvsp[(1) - (3)].express)->index->index=(yyvsp[(3) - (3)].express);
				    oneexpr->index=(yyvsp[(1) - (3)].express)->index;
				     
				 
				    emit(tablesetelem,(yyvsp[(1) - (3)].express)->index,(yyvsp[(3) - (3)].express),quadtest->result,0,lineofnewfile,yylineno);
				       lineofnewfile++;
				    break;
				  }
				}
				quadtest++;
				counter++;
			      }
		    }
		  }
		  else{
		   
		    (yyval.express)=tempexpr(var_e,var_s,programvarmvar,0,0,0);
		    emit(assign,(yyvsp[(3) - (3)].express),NULL,(yyval.express),0,lineofnewfile,yylineno);
			lineofnewfile++;
		    emit(assign,(yyval.express),NULL,(yyvsp[(1) - (3)].express),0,lineofnewfile,yylineno);
		       lineofnewfile++;
		  }
		  
		  
		  if ( diaperasi == 2 ){
/* 		    printf("\n!!update!!\n"); */
		    
		    insertelement->index=(yyvsp[(3) - (3)].express);
		    
		    emit(tablesetelem,insertelement,(yyvsp[(3) - (3)].express),pinakastemp,0,lineofnewfile,yylineno);
		       lineofnewfile++;
		    diaperasi == 0;
		  }
/* 		  printf("Here we have a table insertion\n"); */
		    //printf("\n[%s]\n",yytext);
		}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 837 "parser.y"
    {
		 
		  activefunction--;
		  
		  (yyvsp[(2) - (6)].express)->NumberOfLocalVar=NumOfLocVar;
		  (yyvsp[(2) - (6)].express)->IntermediateCodesLineENDforfunc=lineofnewfile;
		  NumOfLocVar=0;
		  
		  whichoffset=0;
		  offset=0;
		  emit(funcend, NULL, NULL,(yyvsp[(2) - (6)].express), 0, lineofnewfile,yylineno);
		     lineofnewfile++;
/* 		  printf("Here we have funcdef functionstmt\n"); */
		}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 852 "parser.y"
    {
	 
		   activefunction--;
		
		  (yyvsp[(2) - (6)].express)->NumberOfLocalVar=NumOfLocVar;
		  (yyvsp[(2) - (6)].express)->IntermediateCodesLineENDforfunc=lineofnewfile;
		  NumOfLocVar=0;
		  whichoffset=0;
		  offset=0;
		  emit(funcend, NULL, NULL,(yyvsp[(2) - (6)].express), 0, lineofnewfile,yylineno);
		    lineofnewfile++;
/* 		  printf("Here we have funcdef functionstmtBlock\n"); */
		}
    break;

  case 71:

/* Line 1806 of yacc.c  */
#line 866 "parser.y"
    {
	 
		   activefunction--;
		
		  (yyvsp[(2) - (5)].express)->NumberOfLocalVar=NumOfLocVar;
		  (yyvsp[(2) - (5)].express)->IntermediateCodesLineENDforfunc=lineofnewfile;
		  NumOfLocVar=0;
		  whichoffset=0;
		  offset=0;
		  emit(funcend, NULL, NULL,(yyvsp[(2) - (5)].express), 0, lineofnewfile,yylineno);
		    lineofnewfile++;
/* 		  printf("Here we have funcdef functionstmtBlock\n"); */
		}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 880 "parser.y"
    {
		  
		  activefunction--;
		  
		  (yyvsp[(2) - (5)].express)->NumberOfLocalVar=NumOfLocVar;
		  (yyvsp[(2) - (5)].express)->IntermediateCodesLineENDforfunc=lineofnewfile;
		  NumOfLocVar=0;
		  whichoffset=0;
		  offset=0;
		  emit(funcend, NULL, NULL,(yyvsp[(2) - (5)].express), 0, lineofnewfile,yylineno);
		     lineofnewfile++;
/* 		  printf("Here we have funcdef functionstmt\n"); */
		}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 896 "parser.y"
    {  
		   activefunction++;
		  int i;
		  
		  NoNameInt++;
		  sprintf(bufferforint, "%d", NoNameInt); 
		 
		  strcpy (nonamefunctionall,nonamedefault);
		  strcat (nonamefunctionall,bufferforint); 
		  
		    
		  
		 
		  
		  i=ST_Lookup(head,nonamefunctionall,scope,USERFUNC,actfuc);
		  
		  if( i==0 ){
		    head=ST_Insert( head , nonamefunctionall, USERFUNC , scope , yylineno , 1 ,actfuc);
		    if(actfuc!=0)
		    {   
		     
		      ST_InsArg(head,  headf->name, funct_scope, nonamefunctionall, scope); 
		    }
		    
		    
		    
		    
		    
		  }
		  
		   if(activefunction==0)
		      (yyval.express)=lvaluenewexpr(programfunc_e,programfunc_s,strdup(nonamefunctionall),programvarmvar,0,scope,yylineno);		//NSERT IN THE NEWEXPR FUNCTION HERE!!!!!!!!!!!!!
		    else
		      (yyval.express)=lvaluenewexpr(programfunc_e,programfunc_s,strdup(nonamefunctionall),functionlocal,0,scope,yylineno);		//INSERT IN THE NEWEXPR FUNCTION HERE!!!!!!!!!!!!!
		  
		  funct_scope=scope;
		  symbol=strdup(nonamefunctionall);
		  actfuc++;
		  headf=F_Insert(headf,symbol);
	 
		  (yyval.express)->IntermediateCodesLine=lineofnewfile;
		  whichoffset=1;
		  emit(funcstart, NULL, NULL,(yyval.express), 0, lineofnewfile,yylineno);
		     lineofnewfile++;
/* 		  printf("Here we have function Noname ID\n"); */
		  
		  }
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 946 "parser.y"
    {
		
		  activefunction++;
		  
		  int i;
		  problem=0;
		  i=ST_Lookup(head,yytext,scope,USERFUNC,actfuc);
		  
	
		  if(problem)
		  {
		    i=2; 
		  }

		  if( i==0 ){
		    head=ST_Insert( head , yytext, USERFUNC , scope , yylineno , 1 ,actfuc);
		    if(actfuc!=0)
		    {   
		      
		      ST_InsArg(head, headf->name, funct_scope, strdup(yytext), scope); 
		    }
		    
		    
		  }
		  
		  if(activefunction==0)
		      (yyval.express)=lvaluenewexpr(programfunc_e,programfunc_s,strdup(yytext),programvarmvar,0,scope,yylineno);		//NSERT IN THE NEWEXPR FUNCTION HERE!!!!!!!!!!!!!
		    else
		      (yyval.express)=lvaluenewexpr(programfunc_e,programfunc_s,strdup(yytext),functionlocal,0,scope,yylineno);		//INSERT IN THE NEWEXPR FUNCTION HERE!!!!!!!!!!!!!
		  
		  funct_scope=scope;
		  symbol=strdup(yytext);
		  headf=F_Insert(headf,symbol);
		  actfuc++;
	 
		  (yyval.express)->IntermediateCodesLine=lineofnewfile;
		  whichoffset=1;
		emit(funcstart, NULL, NULL,(yyval.express),0, lineofnewfile,yylineno);
		    lineofnewfile++;
/* 		  printf("Here we have function name ID\n"); */
		}
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 990 "parser.y"
    {
		 
		}
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 994 "parser.y"
    {
		  
		}
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 999 "parser.y"
    {(yyval.express)=tempexpr(var_e,var_s,programvarmvar,0,0,lineofnewfile); }
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 1003 "parser.y"
    {
			
			scope++;
		}
    break;

  case 79:

/* Line 1806 of yacc.c  */
#line 1008 "parser.y"
    {
			int ready=0;
			
			scope--;
			  
			  
		
		if(actfuc!=0)
			{
			  
			   ST_Hide(head,headf->name,funct_scope);
			   
			   actfuc--;
			   headf=F_Delete(headf);
			   funct_scope--;
			 }
			 wehaveanstmt=0;
		}
    break;

  case 80:

/* Line 1806 of yacc.c  */
#line 1028 "parser.y"
    { (yyval.express)=tempexpr(var_e,var_s,programvarmvar,0,0,lineofnewfile);  //perister for if end of statement
		    
			  	
			  }
    break;

  case 81:

/* Line 1806 of yacc.c  */
#line 1040 "parser.y"
    {
		  (yyval.express)=constnewexpr(costnum_e,atoi(yytext));
		  fourexpr=(yyval.express);
/* 		  printf("Here we have const integer\n"); */
		}
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 1046 "parser.y"
    {
/* 		  printf("Here we have const float\n"); */
		}
    break;

  case 83:

/* Line 1806 of yacc.c  */
#line 1050 "parser.y"
    {
		  (yyval.express)=stringnewexpr(strdup(stringsave));
		  fourexpr=(yyval.express);
/* 		  printf("Here we have const string\n"); */
		}
    break;

  case 84:

/* Line 1806 of yacc.c  */
#line 1056 "parser.y"
    {
/* 		  printf("Here we have const nil\n"); */
		}
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 1060 "parser.y"
    {

		  (yyval.express)=boolnewexpr(true);
		  fourexpr=(yyval.express);
/* 		  printf("Here we have const true\n"); */
		}
    break;

  case 86:

/* Line 1806 of yacc.c  */
#line 1067 "parser.y"
    {
		  (yyval.express)=boolnewexpr(false);
		  fourexpr=(yyval.express);
/* 		  printf("Here we have const true\n"); */
/* 		  printf("Here we have const false\n"); */
		}
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 1076 "parser.y"
    {
		  indexedflag=1;
		  tableitem=1;  
		  (yyval.express)=(yyvsp[(2) - (3)].express);
/* 		  printf("Here we have [x:y,x:y,x:y]\n"); */
		}
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 1083 "parser.y"
    {
		  indexedflag=1;
		  tableitem=1;
		  (yyval.express)=(yyvsp[(2) - (3)].express);
/* 		  printf("Here we have [x,x,x] \n"); */
		}
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 1090 "parser.y"
    {
		  tableitem=1;//new table
/* 		  printf("Here we have [ ] \n"); */
		}
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 1098 "parser.y"
    {
		
		char * tmpyy;
		tmpyy=strdup(yytext);
		//tmpyy[strlen(tmpyy)-1] = '\0';
		//printf("%s",tmpyy);
		if(ST_LookupFunc(head,yytext,scope,USERFUNC)==1){
		    
		
		 
		    printf("\nvrike userfunc\n");
		
		  }else if(ST_LookupFunc(head,tmpyy,scope,LIBFUNC)==3){
		  
		    
		    
		    
		    
		    printf("\nvrike librfunc\n");
		  
		  }
		  else{
		  int i,j;
		  if(anelistbegin==0){
		    tempyytext=strdup(yytext);
		      
		      }
		  i=ST_Lookup(head,yytext,scope,GLOBAL,actfuc);
		  j=ST_Lookup(head,yytext,scope,LOCAL,actfuc);

		  if(j!=0){
		      i=j;
		  }

		  if(problem)
		  {
		    i=2; 
		  }
      
		  CALLi=i;
	      
		  if( i==0 ){
		  
		    if(scope==0){
		      head=ST_Insert( head , yytext, GLOBAL , scope , yylineno , 1 ,actfuc);
		    }
		    else{
		      head=ST_Insert( head , yytext, LOCAL , scope , yylineno , 1 ,actfuc);
		      if(actfuc!=0)
		      {   
			ST_InsArg(head, headf->name, funct_scope, strdup(yytext), scope); 
		      }
		    }
		    
		    //quad
		 
		 

		  }

		  
		  if(activefunction==0){
		    global_offset++;
		    (yyval.express)=lvaluenewexpr(var_e,var_s,strdup(yytext),programvarmvar,global_offset,scope,yylineno);		//INSERT IN THE NEWEXPR FUNCTION HERE!!!!!!!!!!!!!
		    
		    
		    fourexpr=(yyval.express);
		  }
		  else{
		    (yyval.express)=lvaluenewexpr(var_e,var_s,strdup(yytext),functionlocal,offset,scope,yylineno);		//INSERT IN THE NEWEXPR FUNCTION HERE!!!!!!!!!!!!!
		    offset++;
		    fourexpr=(yyval.express);
		    NumOfLocVar++;
		    }
		    
		    
		    
/* 		  printf("Here we lvalue=%s\n",tempyytext); */}
		}
    break;

  case 91:

/* Line 1806 of yacc.c  */
#line 1178 "parser.y"
    {
		  int i;
		  i=ST_Lookup(head,yytext,scope,LOCAL,actfuc);
		  if( i==0 ){
		    head=ST_Insert( head , yytext, LOCAL , scope , yylineno , 1 ,actfuc);
		    if(actfuc!=0)
		      {   
		
			ST_InsArg(head, headf->name, funct_scope, strdup(yytext), scope); 
		      }
		      
		      if(activefunction==0)
			(yyval.express)=lvaluenewexpr(var_e,var_s,strdup(yytext),programvarmvar,1,scope,yylineno);		//INSERT IN THE NEWEXPR FUNCTION HERE!!!!!!!!!!!!!
		      else{
			(yyval.express)=lvaluenewexpr(var_e,var_s,strdup(yytext),functionlocal,1,scope,yylineno);		//INSERT IN THE NEWEXPR FUNCTION HERE!!!!!!!!!!!!!
			NumOfLocVar++;
			}
		  }
/* 		  printf("Here we have const local ID\n"); */
		}
    break;

  case 92:

/* Line 1806 of yacc.c  */
#line 1199 "parser.y"
    {
		  int i;
		  
		  i=ST_Lookup(head,yytext,0,GLOBAL,actfuc);
		  //printf("\nname=%s scope=%d\n",yytext,scope);
		  if( i==0 && scope==0){
		    head=ST_Insert( head , yytext, GLOBAL , scope , yylineno , 1 ,actfuc);
		    if(actfuc!=0)
		      {   
		
			ST_InsArg(head, headf->name, funct_scope, strdup(yytext), scope); 
		      }
		      
		      if(activefunction==0)
			(yyval.express)=lvaluenewexpr(var_e,var_s,strdup(yytext),programvarmvar,1,scope,yylineno);		//INSERT IN THE NEWEXPR FUNCTION HERE!!!!!!!!!!!!!
		      else
			(yyval.express)=lvaluenewexpr(var_e,var_s,strdup(yytext),functionlocal,1,scope,yylineno);		//INSERT IN THE NEWEXPR FUNCTION HERE!!!!!!!!!!!!!
		      
		  }
		  else if( i==0 && scope!=0){
		    ErrorM("Global Variable doesnot exist");
		  }
/* 		  printf("Here we have const global ID\n"); */
		}
    break;

  case 93:

/* Line 1806 of yacc.c  */
#line 1224 "parser.y"
    {
		  (yyval.express)=(yyvsp[(1) - (1)].express);
/* 		  printf("Here we have const member\n"); */
		}
    break;

  case 94:

/* Line 1806 of yacc.c  */
#line 1231 "parser.y"
    {
		  memberlvalue=1;
		  quadtest=quads;
		  counter=0;
		  found=0;
		  oneexpr=lvaluenewexpr(var_e,var_s,strdup(yytext),programvarmvar,1,scope,yylineno);
		  while( counter < currQuad ){
		    if( (yyvsp[(1) - (3)].express) == NULL ){
		      break;
		    }
		    
		    /**ERROR MUST BE IMPROVED TRWEI SEMG*/
		   /* if(strcmp(quadtest->result->sym->name,$1->sym->name) == 0 )
		      found=1;
		     }*/
		    quadtest++;
		    counter++;
		  }
		    if( (yyvsp[(1) - (3)].express) == NULL ){
		      break;
		    }
		  if( found == 0 ){
		    if(  (yyvsp[(1) - (3)].express)->sym != NULL ) 
		      ErrorR("is not a table",(yyvsp[(1) - (3)].express)->sym->name);
		    else
		      ErrorM("Not a table");
		  }
		  (yyvsp[(1) - (3)].express)->index=oneexpr;//test
		  (yyval.express)=(yyvsp[(1) - (3)].express);
		  printf("Here we have lvalue.ID\n");
		}
    break;

  case 95:

/* Line 1806 of yacc.c  */
#line 1263 "parser.y"
    {
		  help++;
		  if( fourexpr != NULL ){
		    if( fourexpr->sym != NULL )
		    printf("->%s<-,%d\n",fourexpr->sym->name,help);
		    else if( fourexpr->boolConst != null )
		    printf("->%s<-,%d\n",bool_array[fourexpr->boolConst],help);
		    else
		    printf("->%f<-,%d\n",fourexpr->numConst,help);

		  }
		  if( fiveexpr == NULL ){
		    fiveexpr=(yyvsp[(1) - (4)].express);
		  }
		  counter=0;
		  quadtest=quads;
		  while( counter < currQuad ){
		    printf("\nSearching:%s\n",fiveexpr->sym->name);
		    if( strcmp(quadtest->result->sym->name,fiveexpr->sym->name) == 0 ){//an vrethei o pinakas
/* 		      printf("\nPINAKAS FOUND\n"); */
		      found=1;
		      pinakastemp=quadtest->result;//o pinakas
		      oneexpr=quadtest->result;
		      if( oneexpr->index != NULL ){//an exei indexes
			oneexpr=oneexpr->index;//paw sto prwto stoixeio
			if( oneexpr->index == NULL ){
			  ErrorR(":wrong type of table",fiveexpr->sym->name);
			  break;
			}
			twoexpr=oneexpr;//to prwto stoixeio
			threeexpr=oneexpr;
			printf("\n");
			while( oneexpr != NULL ){
			    if( oneexpr->sym != NULL && fourexpr->sym != NULL ){
			      if( strcmp(fourexpr->sym->name,oneexpr->sym->name) == 0 ){
				(yyval.express)=oneexpr;
				fiveexpr=(yyval.express)->index;
/* 				printf("\n!!FOUND!!\n"); */
				diaperasi=1;
				insertelement=fourexpr;
				coolflag=1;
				break;
			      }
			    }
			    else {
				if( fourexpr->numConst == oneexpr->numConst ){
				  (yyval.express)=oneexpr;
				  fiveexpr=(yyval.express)->index;
/* 				  printf("\n!!FOUND!!\n"); */
				  diaperasi=1;
				  insertelement=fourexpr;
				  coolflag=1;
				  break;
			      }
			    }
			    twoexpr=oneexpr;
			    oneexpr=oneexpr->next;
			}
			if( coolflag == 1 ){
			  //printf("\n{%s}\n",$$->strConst);
			  coolflag=0;
			  break;
			}
			if( coolflag == 0 ){
			  //insert
			  (yyval.express)=NULL;
			  insertelement=(yyvsp[(3) - (4)].express);
			  fourexpr=NULL;
/* 			  printf("\n!!NOT FOUND!!\n"); */
			  if( help != 1)
			    diaperasi2=1;
			  else
			    diaperasi=4;
			  break;
			}
			coolflag=0;
		      }
		      else{
			//insert
			(yyval.express)=NULL;
			insertelement=(yyvsp[(3) - (4)].express);
			if( help != 1)
			  diaperasi2=1;
			else
			  diaperasi=3;
			fourexpr=NULL;
/* 			printf("\nempty\n"); */
			break;
		      }
		    }
		    quadtest++;
		    counter++;
		  }
		  if( found == 0 ){
		      if( fourexpr->sym != NULL )
			ErrorR("is not a table",fourexpr->sym->name);
		      else
			ErrorM("Table doesnot exist");
		  }
		  found=0;
/* 		  printf("Here we have [ expr ]\n"); */
		}
    break;

  case 96:

/* Line 1806 of yacc.c  */
#line 1366 "parser.y"
    {
/* 		  printf("Here we have call.ID\n"); */
		}
    break;

  case 97:

/* Line 1806 of yacc.c  */
#line 1370 "parser.y"
    {
/* 		  printf("Here we have call[ expr ]\n"); */
		}
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 1379 "parser.y"
    {
		  scope++;
		  int i;
		  i=ST_Lookup(head,yytext,scope,FORMAL,actfuc);

		  
		  
	
		  if(problem)
		  {
		    i=2;
		  }

		  if( i==0 ){
		    head=ST_Insert( head , yytext, FORMAL , scope , yylineno , 1 ,actfuc);
		    if(actfuc!=0)
		      {   
			
			ST_InsArg(head, headf->name, funct_scope, strdup(yytext), scope); 
		      }
		      
			(yyval.express)=lvaluenewexpr(var_e,var_s,strdup(yytext),formalarg,1,scope,yylineno);		//INSERT IN THE NEWEXPR FUNCTION HERE!!!!!!!!!!!!!
			 
		/*	emit(param,$$,NULL,NULL,0,lineofnewfile,yylineno);
			   lineofnewfile++;
		   */
		  }
/* 		  printf("Here we have ID\n"); */
		  scope--;
		}
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 1410 "parser.y"
    {
		  scope++;
		  int i;
		  i=ST_Lookup(head,yytext,scope,FORMAL,actfuc);
		  
		
		  if(problem)
		  {
		    i=2;
		  }

		  if( i==0 ){
		  head=ST_Insert( head , yytext, FORMAL , scope , yylineno , 1 ,actfuc);
		  if(actfuc!=0)
		      {   
			
			ST_InsArg(head, headf->name, funct_scope, strdup(yytext), scope); 
		      }
		      
		      (yyval.express)=lvaluenewexpr(var_e,var_s,strdup(yytext),formalarg,1,scope,yylineno);		//INSERT IN THE NEWEXPR FUNCTION HERE!!!!!!!!!!!!!
		     /*
		      emit(param,$$,NULL,NULL,0,lineofnewfile,yylineno);
		         lineofnewfile++;
		      */
		  }
/* 		  printf("Here we have idlist,ID\n"); */
		  scope--;
		 }
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 1443 "parser.y"
    {
		  //$$=$1;
		/*
		  emit(param,$$,NULL,NULL,0,lineofnewfile,yylineno);
		  lineofnewfile++;
		*/
/* 		  printf("Here we have lexpr\n"); */
		}
    break;

  case 101:

/* Line 1806 of yacc.c  */
#line 1452 "parser.y"
    {
		
		  (yyvsp[(3) - (3)].express)->next=(yyvsp[(1) - (3)].express);
		  (yyval.express)=(yyvsp[(3) - (3)].express);
		 /* 
		  emit(param,$$,NULL,NULL,0,lineofnewfile,yylineno);
		  lineofnewfile++;
		 */
		
/* 		  printf("Here we have elist,expr\n"); */
		}
    break;

  case 102:

/* Line 1806 of yacc.c  */
#line 1467 "parser.y"
    {
		 
		  objecttemp=tempexpr(var_e,var_s,programvarmvar,0,0,lineofnewfile); 
		  emit(tablecreate,NULL,NULL,objecttemp,0,lineofnewfile,yylineno);
		  lineofnewfile++;
		  coste=constnewexpr(costnum_e,pincounter);
		  coste->index=(yyvsp[(1) - (1)].express);
		  emit(tablesetelem,coste,(yyvsp[(1) - (1)].express),objecttemp,0,lineofnewfile,yylineno);
		     lineofnewfile++;
		  pincounter++;
		  (yyval.express)=coste;
/* 		  printf("Here we have objexpr\n"); */
		}
    break;

  case 103:

/* Line 1806 of yacc.c  */
#line 1481 "parser.y"
    {
		  coste=constnewexpr(costnum_e,pincounter);
		  coste->index=(yyvsp[(3) - (3)].express);
		  coste->next=(yyvsp[(1) - (3)].express);
		  (yyval.express)=coste;

		  emit(tablesetelem,coste,(yyvsp[(3) - (3)].express),objecttemp,0,lineofnewfile,yylineno);
		     lineofnewfile++;
		  pincounter++;
/* 		  printf("Here we have objelist,expr\n"); */
		}
    break;

  case 104:

/* Line 1806 of yacc.c  */
#line 1495 "parser.y"
    {
		  (yyvsp[(2) - (5)].express)->index=(yyvsp[(4) - (5)].express);
		  (yyval.express)=(yyvsp[(2) - (5)].express);
		  if( create == 0 ){
		 
		    objecttemp=tempexpr(var_e,var_s,programvarmvar,0,0,lineofnewfile); 
		    emit(tablecreate,NULL,NULL,objecttemp,0,lineofnewfile,yylineno);
		       lineofnewfile++;
		    create=1;
		  }
		 
		  emit(tablesetelem,(yyvsp[(2) - (5)].express),(yyvsp[(4) - (5)].express),objecttemp,0,lineofnewfile,yylineno);
		     lineofnewfile++;
/* 		  printf("Here we have expr : expr\n"); */
		}
    break;

  case 105:

/* Line 1806 of yacc.c  */
#line 1514 "parser.y"
    {
		  (yyval.express)=(yyvsp[(1) - (1)].express);
/* 		  printf("Here we have indexedelem\n"); */
		}
    break;

  case 106:

/* Line 1806 of yacc.c  */
#line 1519 "parser.y"
    {
		  (yyvsp[(3) - (3)].express)->next=(yyvsp[(1) - (3)].express);
		  (yyval.express)=(yyvsp[(3) - (3)].express);
/* 		  printf("Here we have indexed ','indexedelem\n"); */
		}
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 1541 "parser.y"
    { 
/* 		  printf("\t\t\t\t\t\tELSE 1111111111\n");  */
		
		  wehaveanstmt=1;
		 
		  
		 
		 (yyval.express)=tempexpr(var_e,var_s,programvarmvar,0,0,lineofnewfile); 
		   emit(jump,NULL,NULL,NULL,0,lineofnewfile,yylineno);
		      lineofnewfile++;
		  }
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 1557 "parser.y"
    {//printf("BEGIN IFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF\n"); 
		
		  wehaveanstmt=1;
		 
		  
		 emit(if_eq,current_temp,boolnewexpr(true),NULL,lineofnewfile+2,lineofnewfile,yylineno);  //perister  
		    lineofnewfile++;
		
	 
 
		 (yyval.express)=tempexpr(var_e,var_s,programvarmvar,0,0,lineofnewfile); 
		  emit(jump,NULL,NULL,NULL,0,lineofnewfile,yylineno);
		  lineofnewfile++; 
		  
		   
		}
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 1577 "parser.y"
    { 	
/* 		 printf("\t\t\t\t\t\tif1\n"); */
		  
	 
		 
		 patchlabel((yyvsp[(2) - (2)].express)->sym->line,(yyvsp[(1) - (2)].express)->sym->line);
		
		 wehaveanstmt=1; }
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 1587 "parser.y"
    {  
/* 		    printf("\t\t\t\t\t\tif2\n"); */
		
		   
		     patchlabel((yyvsp[(2) - (4)].express)->sym->line+1,(yyvsp[(1) - (4)].express)->sym->line);
		     patchlabel((yyvsp[(4) - (4)].express)->sym->line,(yyvsp[(3) - (4)].express)->sym->line);
		
		   }
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 1608 "parser.y"
    {
		  if( scope == 0 ){
		    ErrorM("Use of 'return' while not in a funtion");
		  }else{
		   
		  emit(ret,NULL, NULL, NULL, 0, lineofnewfile,yylineno);
		  lineofnewfile++;}
/* 		  printf("Here we have return;\n"); */
		}
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 1618 "parser.y"
    {
		  if( scope == 0 ){
		    ErrorM("Use of 'return' while not in a funtion");
		  }else{
		   
		 emit(ret,NULL, NULL, (yyvsp[(2) - (3)].express), 0, lineofnewfile,yylineno);
		 lineofnewfile++;}
/* 		  printf("Here we have return expr;\n"); */
		 }
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 1653 "parser.y"
    {
if(loop_counter==0)
 {break_head=tempexpr(constbool_e,var_s,programvarmvar,0,0,0); //init breaklist with null
  continue_head=tempexpr(constbool_e,var_s,programvarmvar,0,0,0); //init continuelist with null
 }
loop_counter++;}
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 1660 "parser.y"
    {loop_counter--;
 
}
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 1665 "parser.y"
    {(yyval.express)=(yyvsp[(2) - (3)].express);
    
    
    }
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 1672 "parser.y"
    {     
/* 		      printf("*****************************************************************************************************************************************\n"); */
		     
		
		      (yyval.express)=tempexpr(constbool_e,var_s,programvarmvar,0,0,lineofnewfile);
		  
		   
		  
		  }
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 1685 "parser.y"
    {  emit(if_eq,current_temp,boolnewexpr(true),NULL,lineofnewfile+2,lineofnewfile,yylineno);
		  lineofnewfile++;
		  emit(jump,NULL,NULL,NULL,0,lineofnewfile,yylineno);
		    lineofnewfile++;
		    (yyval.express)=tempexpr(constbool_e,var_s,programvarmvar,0,0,lineofnewfile);
		  ;}
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 1696 "parser.y"
    {              
		wehaveanstmt=1;
		
		emit(jump,NULL,NULL,NULL,(yyvsp[(1) - (3)].express)->sym->line,lineofnewfile,yylineno);
		 lineofnewfile++;
		 patchlabel(lineofnewfile,(yyvsp[(2) - (3)].express)->sym->line-1);
	      patchbreak(break_head,lineofnewfile,loop_counter+1);   //??????
	      
/* 	      printf("WHILESTART LINE=%d\n",$1->sym->line); */
		 patchcontinue(continue_head,(yyvsp[(1) - (3)].express)->sym->line,loop_counter+1);   //??????
		}
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 1710 "parser.y"
    {//printf("N11111111111111111111111111111111111111111111111111111111\n");
	(yyval.express)=tempexpr(var_e,var_s,programvarmvar,0,0,lineofnewfile); 
	emit(jump,NULL,NULL,NULL,0,lineofnewfile,yylineno);
	lineofnewfile++;
 

}
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 1718 "parser.y"
    {	(yyval.express)=tempexpr(var_e,var_s,programvarmvar,0,0,lineofnewfile); 
	//printf("N2222222222222222222222222222222222222222222\n");
	 emit(jump,NULL,NULL,NULL,0,lineofnewfile,yylineno);
		  lineofnewfile++; 
	
	}
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 1724 "parser.y"
    {	(yyval.express)=tempexpr(var_e,var_s,programvarmvar,0,0,lineofnewfile); 
	//printf("N333333333333333333333333333333333\n");
	 emit(jump,NULL,NULL,NULL,0,lineofnewfile,yylineno);
		  lineofnewfile++; 
	}
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 1729 "parser.y"
    {	(yyval.express)=tempexpr(var_e,var_s,programvarmvar,0,0,lineofnewfile); 
	//printf("NMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM\n");

	}
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 1735 "parser.y"
    {
	  //break_head=tempexpr(constbool_e,var_s,programvarmvar,0,0,0); //init breaklist with null
	 //continue_head=tempexpr(constbool_e,var_s,programvarmvar,0,0,0); //init continuelist with n
	(yyval.express)=(yyvsp[(5) - (7)].express); 
	(yyval.express)->next=tempexpr(var_e,var_s,programvarmvar,0,0,lineofnewfile);;
	emit(if_eq,current_temp,boolnewexpr(true),NULL,0,lineofnewfile,yylineno);
	 lineofnewfile++; 
	
	}
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 1748 "parser.y"
    {
		  wehaveanstmt=1;
		//  printf("forrrrrrr $1=%d \n",$1->sym->line);
		    patchlabel((yyvsp[(5) - (7)].express)->sym->line+1,(yyvsp[(1) - (7)].express)->next->sym->line);//ok
		    patchlabel(lineofnewfile,(yyvsp[(2) - (7)].express)->sym->line); //ok
	             patchlabel((yyvsp[(1) - (7)].express)->sym->line,(yyvsp[(5) - (7)].express)->sym->line);//ok
	            
	            patchlabel((yyvsp[(2) - (7)].express)->sym->line+1,(yyvsp[(7) - (7)].express)->sym->line);
	            
	            
	            patchbreak(break_head,lineofnewfile,loop_counter+1);
	           patchcontinue(continue_head,(yyvsp[(1) - (7)].express)->sym->line,loop_counter+1);
	             
		 
/* 		  printf("Here we have for(elist;expr;elist)\n"); */
		}
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 1769 "parser.y"
    {  
		  if( scope == 0 ){
		    breakaccess=0;
		    ErrorM("Use of 'break' while not in a loop");
		  } 
		  else  //we are in loop
		  {
		  printf("BREAKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK\n");
		  (yyval.express)=tempexpr(var_e,var_s,programvarmvar,0,0,lineofnewfile); 
		   emit(jump,NULL,NULL,NULL,0,lineofnewfile,yylineno);
		   lineofnewfile++; 
		
		  	  breakaccess=1; 
		   }}
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 1786 "parser.y"
    {
		
		
		  if( scope == 0 ){
		    ErrorM("Use of 'continue' while not in a loop");
		  }
		  else
		  {
		  printf("CONTINUe EMIT\n");
		  (yyval.express)=tempexpr(var_e,var_s,programvarmvar,0,0,lineofnewfile); 
		  emit(jump,NULL,NULL,NULL,0,lineofnewfile,yylineno);
		  lineofnewfile++; 
		  continueaccess=1; //why????
		  }
/* 		  printf("Here we have continue;\n"); */
		}
    break;



/* Line 1806 of yacc.c  */
#line 3830 "parser.c"
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
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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
      if (!yypact_value_is_default (yyn))
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
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



/* Line 2067 of yacc.c  */
#line 1825 "parser.y"

int yyerror (char* yaccProvidedMessage)
{

  fprintf(stderr,"%s:at line %d,before token: %s\n",yaccProvidedMessage, yylineno,yytext);
  fprintf(stderr,"INPUT NOT VALID\n");
  exit(0);

}



//funcdef  function [id] (idlist) block

int main(int argc,char** argv){
  if(argc >1){
    if(!(yyin=fopen(argv[1],"r"))){
      fprintf(stderr,"Cannot read file %s\n",argv[1]);
      return 1;
    }
    
    }else
      yyin=stdin;
    
    //Insert Library Functions
    head=ST_Insert( head , "print", LIBFUNC , scope , yylineno , 1 ,-1);
    head=ST_Insert( head , "input", LIBFUNC , scope , yylineno , 1 ,-1);
    head=ST_Insert( head , "objectmemberkeys", LIBFUNC , scope , yylineno , 1 ,-1);
    head=ST_Insert( head , "objecttotalmembers", LIBFUNC , scope , yylineno , 1 ,-1);
    head=ST_Insert( head , "objectcopy", LIBFUNC , scope , yylineno , 1 ,-1);
    head=ST_Insert( head , "totalarguments", LIBFUNC , scope , yylineno , 1 ,-1);
    head=ST_Insert( head , "argument", LIBFUNC , scope , yylineno , 1 ,-1);
    head=ST_Insert( head , "typeof", LIBFUNC , scope , yylineno , 1 ,-1);
    head=ST_Insert( head , "strtonum", LIBFUNC , scope , yylineno , 1 ,-1);
    head=ST_Insert( head , "sqrt", LIBFUNC , scope , yylineno , 1 ,-1);
    head=ST_Insert( head , "cos", LIBFUNC , scope , yylineno , 1 ,-1);
    head=ST_Insert( head , "sin", LIBFUNC , scope , yylineno , 1 ,-1);

    yyparse();
    ST_Print (head);
   // PrintFunc(head);
    print_lines();
    print_quad (quads);
    produce_quad (quads);
    produce_ins(quads);

      
   print_incomplete_jump();
    patch_inclomplete_jumps();//new perister  


    produce_finalquad(instructions);
    //printreturnList(returnLists);
   

    ReplaceJumpsFromFuncs(instructions); 
     
     arraysnot=1;
     produce_finalquad(instructions);
     
     
    print_taddresses(quads); //new
    create_bin(instructions);
    system("./exc"); 
    return 0;
    }
    
