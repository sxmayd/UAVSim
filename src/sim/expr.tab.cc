/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         expryyparse
#define yylex           expryylex
#define yyerror         expryyerror
#define yydebug         expryydebug
#define yynerrs         expryynerrs

#define yylval          expryylval
#define yychar          expryychar

/* Copy the first part of user declarations.  */
#line 43 "expr.y" /* yacc.c:339  */


#include <stdio.h>
#include <stdlib.h>
#include "expryydefs.h"
#include "commonutil.h"

#define YYDEBUG 1           /* allow debugging */
#define YYDEBUGGING_ON 0    /* turn on/off debugging */

#if YYDEBUG != 0
#define YYERROR_VERBOSE     /* more detailed error messages */
#include <string.h>         /* YYVERBOSE needs it */
#endif

#define yyin expryyin
#define yyout expryyout
#define yyrestart expryyrestart
#define yy_scan_string expryy_scan_string
#define yy_delete_buffer expryy_delete_buffer
extern FILE *yyin;
extern FILE *yyout;
struct yy_buffer_state;
struct yy_buffer_state *yy_scan_string(const char *str);
void yy_delete_buffer(struct yy_buffer_state *);
void yyrestart(FILE *);
int yylex();
void yyerror (const char *s);

LineColumn xpos, xprevpos;


#include "cdynamicexpression.h"
#include "cpar.h"
#include "cxmlelement.h"
#include "cexception.h"
#include "globals.h"
#include "cnedmathfunction.h"
#include "cnedfunction.h"
#include "nedsupport.h"
#include "stringutil.h"
#include "unitconversion.h"

USING_NAMESPACE

static cDynamicExpression::Elem *e;

static char *expryyconcat(char *s1, char *s2, char *s3=NULL)
{
    char *d = new char[strlen(s1)+strlen(s2)+strlen(s3?s3:"")+4];
    strcpy(d, s1);
    strcat(d, " ");
    strcat(d, s2);
    if (s3) {strcat(d, " "); strcat(d, s3);}
    delete [] s1; delete [] s2; delete [] s3;
    return d;
}

static void addFunction(const char *funcname, int argc)
{
    cNEDMathFunction *f = cNEDMathFunction::find(funcname, argc);
    if (f) {
        *e++ = f;
        return;
    }
    cNEDFunction *nf = cNEDFunction::find(funcname);
    if (nf) {
        if (argc < nf->getMinArgs() || (argc > nf->getMaxArgs() && !nf->hasVarArgs()))
            yyerror(opp_stringf("function `%s' does not accept %d arguments", nf->getSignature(), argc).c_str());
        (e++)->set(nf,argc);
        return;
    }
    yyerror(opp_stringf("function `%s()' (with %d args) not found (Define_NED_Function() or Define_NED_Math_Function() missing from C++ code?)", funcname, argc).c_str());
}

static double parseQuantity(const char *text, std::string& unit)
{
    try {
        // evaluate quantities like "5s 230ms"
        return UnitConversion::parseQuantity(text, unit);
    }
    catch (std::exception& e) {
        yyerror(e.what());
        return 0;
    }
}


#line 163 "expr.tab.cc" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "expr.tab.hh".  */
#ifndef YY_EXPRYY_EXPR_TAB_HH_INCLUDED
# define YY_EXPRYY_EXPR_TAB_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int expryydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    DOUBLETYPE = 258,
    INTTYPE = 259,
    STRINGTYPE = 260,
    BOOLTYPE = 261,
    XMLTYPE = 262,
    TRUE_ = 263,
    FALSE_ = 264,
    THIS_ = 265,
    ASK_ = 266,
    DEFAULT_ = 267,
    CONST_ = 268,
    SIZEOF_ = 269,
    INDEX_ = 270,
    XMLDOC_ = 271,
    NAME = 272,
    INTCONSTANT = 273,
    REALCONSTANT = 274,
    STRINGCONSTANT = 275,
    EQ_ = 276,
    NE_ = 277,
    GE_ = 278,
    LE_ = 279,
    AND_ = 280,
    OR_ = 281,
    XOR_ = 282,
    NOT_ = 283,
    BINAND_ = 284,
    BINOR_ = 285,
    BINXOR_ = 286,
    BINCOMPL_ = 287,
    SHIFTLEFT_ = 288,
    SHIFTRIGHT_ = 289,
    INVALID_CHAR = 290,
    UMIN_ = 291
  };
#endif
/* Tokens.  */
#define DOUBLETYPE 258
#define INTTYPE 259
#define STRINGTYPE 260
#define BOOLTYPE 261
#define XMLTYPE 262
#define TRUE_ 263
#define FALSE_ 264
#define THIS_ 265
#define ASK_ 266
#define DEFAULT_ 267
#define CONST_ 268
#define SIZEOF_ 269
#define INDEX_ 270
#define XMLDOC_ 271
#define NAME 272
#define INTCONSTANT 273
#define REALCONSTANT 274
#define STRINGCONSTANT 275
#define EQ_ 276
#define NE_ 277
#define GE_ 278
#define LE_ 279
#define AND_ 280
#define OR_ 281
#define XOR_ 282
#define NOT_ 283
#define BINAND_ 284
#define BINOR_ 285
#define BINXOR_ 286
#define BINCOMPL_ 287
#define SHIFTLEFT_ 288
#define SHIFTRIGHT_ 289
#define INVALID_CHAR 290
#define UMIN_ 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE expryylval;

int expryyparse (void);

#endif /* !YY_EXPRYY_EXPR_TAB_HH_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 286 "expr.tab.cc" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  49
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   778

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  12
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  162

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    44,     2,     2,
      47,    48,    42,    40,    49,    41,    50,    43,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    37,     2,
      39,     2,    38,    36,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    51,     2,    52,    45,     2,     2,     2,     2,     2,
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
      35,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   135,   135,   136,   138,   140,   145,   146,   147,   150,
     152,   154,   156,   158,   160,   163,   167,   169,   171,   173,
     175,   177,   180,   182,   184,   187,   191,   193,   195,   198,
     201,   203,   205,   208,   210,   212,   215,   217,   219,   221,
     223,   225,   227,   229,   231,   233,   235,   240,   241,   242,
     246,   247,   249,   254,   256,   258,   260,   265,   267,   269,
     271,   273,   275,   280,   281,   282,   286,   291,   293,   298,
     300,   302,   313,   315,   317,   319
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DOUBLETYPE", "INTTYPE", "STRINGTYPE",
  "BOOLTYPE", "XMLTYPE", "TRUE_", "FALSE_", "THIS_", "ASK_", "DEFAULT_",
  "CONST_", "SIZEOF_", "INDEX_", "XMLDOC_", "NAME", "INTCONSTANT",
  "REALCONSTANT", "STRINGCONSTANT", "EQ_", "NE_", "GE_", "LE_", "AND_",
  "OR_", "XOR_", "NOT_", "BINAND_", "BINOR_", "BINXOR_", "BINCOMPL_",
  "SHIFTLEFT_", "SHIFTRIGHT_", "INVALID_CHAR", "'?'", "':'", "'>'", "'<'",
  "'+'", "'-'", "'*'", "'/'", "'%'", "'^'", "UMIN_", "'('", "')'", "','",
  "'.'", "'['", "']'", "$accept", "expression", "expr", "simple_expr",
  "funcname", "identifier", "special_expr", "literal", "stringliteral",
  "boolliteral", "numliteral", "quantity", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,    63,    58,    62,    60,
      43,    45,    42,    47,    37,    94,   291,    40,    41,    44,
      46,    91,    93
};
# endif

#define YYPACT_NINF -39

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-39)))

#define YYTABLE_NINF -51

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     139,   -33,   -16,    10,   -39,   -39,   -39,   -37,   -39,    15,
      16,    25,    29,   -39,   -29,    11,    63,   -39,   174,   174,
     174,   174,    82,   683,   -39,    46,   -39,   -39,   -39,   -39,
     -39,   -39,    72,   174,   174,   174,    77,   174,   174,    -5,
      47,    79,   139,   -39,   -39,   -39,   -39,   -39,   462,   -39,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   174,
     174,    51,    80,    85,   490,   518,   546,   -39,   574,   602,
      54,   -21,   -39,   -39,    61,   -39,    44,    44,    44,    44,
     733,   733,   733,    67,    67,    67,   -34,   -34,   658,    44,
      44,   -19,   -19,    69,    69,    69,    69,   -39,   201,   -39,
     -39,   -39,   -39,   -39,   -39,   -39,    89,   -39,    98,   139,
      66,   174,   -39,   174,    70,    71,    68,   104,   708,   230,
     -39,   -39,    73,   -39,   -39,   174,   107,   259,    83,   -39,
     174,   -39,   288,   -39,   174,   317,   -39,   174,   346,   -39,
     174,   375,   -39,   174,   404,   -39,   174,   433,   -39,   174,
     630,   -39
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,    52,    67,    68,     0,     3,     4,
       0,     0,    57,    51,    53,    69,    70,    66,     0,     0,
       0,     0,     0,     2,     6,     0,    47,    48,    49,    63,
      64,    65,    71,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    74,    75,    25,    29,    15,     0,     1,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    54,     0,     0,
       0,     0,    58,    55,     0,     7,    16,    17,    19,    21,
      22,    23,    24,    26,    27,    28,    30,    31,     0,    18,
      20,     9,    10,    11,    12,    13,    14,    36,     0,    72,
      73,    34,    33,    35,     5,     8,     0,    59,     0,     0,
       0,     0,    37,     0,     0,     0,     0,     0,    32,     0,
      60,    61,     0,    56,    38,     0,     0,     0,     0,    39,
       0,    62,     0,    40,     0,     0,    41,     0,     0,    42,
       0,     0,    43,     0,     0,    44,     0,     0,    45,     0,
       0,    46
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -39,   -38,   -18,   -39,   -39,   -39,   -39,   -39,   -39,   -39,
     -39,   -39
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,    46,    47,    48,    84,    80,    65,    66,    67,    68,
      69,    70,    81,    36,    33,    74,    75,    76,   -50,    78,
      79,    41,    42,    67,    68,    69,    70,   117,    43,   118,
     119,    34,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   108,     1,     2,     3,    35,     4,     5,
       6,     7,    37,    38,    10,    11,    12,    13,    14,    15,
      16,    17,    39,    57,    58,    59,    40,    60,    61,    18,
      44,   126,    49,    19,    65,    66,    67,    68,    69,    70,
      72,    73,    20,    71,    77,    82,    83,   109,    21,   107,
      60,    61,   110,   128,   116,   129,   124,    65,    66,    67,
      68,    69,    70,   120,    70,   125,   127,   137,   130,   131,
     132,   133,   142,   136,   138,     0,   145,     0,     0,   148,
       0,   141,   151,     0,     0,   154,     0,     0,   157,     0,
       0,   160,     1,     2,     3,     0,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
       0,     0,     0,     0,     0,     0,     0,    18,     0,     0,
       0,    19,     0,     0,     0,     0,     0,     1,     2,     3,
      20,     4,     5,     6,     7,     0,    21,    10,    11,    12,
      13,    14,    15,    16,    17,     0,     0,     0,     0,     0,
       0,     0,    18,     0,     0,     0,    19,     0,     0,     0,
       0,     0,     0,     0,     0,    20,     0,     0,     0,     0,
       0,    21,    50,    51,    52,    53,    54,    55,    56,     0,
      57,    58,    59,     0,    60,    61,     0,    62,     0,    63,
      64,    65,    66,    67,    68,    69,    70,     0,     0,   122,
     123,    50,    51,    52,    53,    54,    55,    56,     0,    57,
      58,    59,     0,    60,    61,     0,    62,     0,    63,    64,
      65,    66,    67,    68,    69,    70,     0,     0,   134,   135,
      50,    51,    52,    53,    54,    55,    56,     0,    57,    58,
      59,     0,    60,    61,     0,    62,     0,    63,    64,    65,
      66,    67,    68,    69,    70,     0,     0,   139,   140,    50,
      51,    52,    53,    54,    55,    56,     0,    57,    58,    59,
       0,    60,    61,     0,    62,     0,    63,    64,    65,    66,
      67,    68,    69,    70,     0,     0,   143,   144,    50,    51,
      52,    53,    54,    55,    56,     0,    57,    58,    59,     0,
      60,    61,     0,    62,     0,    63,    64,    65,    66,    67,
      68,    69,    70,     0,     0,   146,   147,    50,    51,    52,
      53,    54,    55,    56,     0,    57,    58,    59,     0,    60,
      61,     0,    62,     0,    63,    64,    65,    66,    67,    68,
      69,    70,     0,     0,   149,   150,    50,    51,    52,    53,
      54,    55,    56,     0,    57,    58,    59,     0,    60,    61,
       0,    62,     0,    63,    64,    65,    66,    67,    68,    69,
      70,     0,     0,   152,   153,    50,    51,    52,    53,    54,
      55,    56,     0,    57,    58,    59,     0,    60,    61,     0,
      62,     0,    63,    64,    65,    66,    67,    68,    69,    70,
       0,     0,   155,   156,    50,    51,    52,    53,    54,    55,
      56,     0,    57,    58,    59,     0,    60,    61,     0,    62,
       0,    63,    64,    65,    66,    67,    68,    69,    70,     0,
       0,   158,   159,    50,    51,    52,    53,    54,    55,    56,
       0,    57,    58,    59,     0,    60,    61,     0,    62,     0,
      63,    64,    65,    66,    67,    68,    69,    70,     0,     0,
      85,    50,    51,    52,    53,    54,    55,    56,     0,    57,
      58,    59,     0,    60,    61,     0,    62,     0,    63,    64,
      65,    66,    67,    68,    69,    70,     0,     0,   111,    50,
      51,    52,    53,    54,    55,    56,     0,    57,    58,    59,
       0,    60,    61,     0,    62,     0,    63,    64,    65,    66,
      67,    68,    69,    70,     0,     0,   112,    50,    51,    52,
      53,    54,    55,    56,     0,    57,    58,    59,     0,    60,
      61,     0,    62,     0,    63,    64,    65,    66,    67,    68,
      69,    70,     0,     0,   113,    50,    51,    52,    53,    54,
      55,    56,     0,    57,    58,    59,     0,    60,    61,     0,
      62,     0,    63,    64,    65,    66,    67,    68,    69,    70,
       0,     0,   114,    50,    51,    52,    53,    54,    55,    56,
       0,    57,    58,    59,     0,    60,    61,     0,    62,     0,
      63,    64,    65,    66,    67,    68,    69,    70,     0,     0,
     115,    50,    51,    52,    53,    54,    55,    56,     0,    57,
      58,    59,     0,    60,    61,     0,    62,     0,    63,    64,
      65,    66,    67,    68,    69,    70,     0,     0,   161,    50,
      51,    52,    53,    54,    55,    56,     0,    57,    58,    59,
       0,    60,    61,     0,    62,   121,    63,    64,    65,    66,
      67,    68,    69,    70,    50,    51,    52,    53,    54,    55,
      56,     0,    57,    58,    59,     0,    60,    61,     0,    62,
       0,    63,    64,    65,    66,    67,    68,    69,    70,    50,
      51,    52,    53,    54,    55,    56,     0,    57,    58,    59,
       0,    60,    61,     0,     0,     0,    63,    64,    65,    66,
      67,    68,    69,    70,    50,    51,    52,    53,     0,     0,
       0,     0,    57,    58,    59,     0,    60,    61,     0,     0,
       0,    63,    64,    65,    66,    67,    68,    69,    70
};

static const yytype_int16 yycheck[] =
{
      18,    19,    20,    21,    42,    10,    40,    41,    42,    43,
      44,    45,    17,    50,    47,    33,    34,    35,    47,    37,
      38,    50,    51,    42,    43,    44,    45,    48,    17,    50,
      51,    47,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     3,     4,     5,    47,     7,     8,
       9,    10,    47,    47,    13,    14,    15,    16,    17,    18,
      19,    20,    47,    29,    30,    31,    47,    33,    34,    28,
      17,   119,     0,    32,    40,    41,    42,    43,    44,    45,
      18,    19,    41,    47,    17,    48,    17,    17,    47,    48,
      33,    34,    17,   121,    50,   123,    17,    40,    41,    42,
      43,    44,    45,    52,    45,    17,    50,   135,    48,    48,
      52,    17,   140,    50,    17,    -1,   144,    -1,    -1,   147,
      -1,    48,   150,    -1,    -1,   153,    -1,    -1,   156,    -1,
      -1,   159,     3,     4,     5,    -1,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,
      -1,    32,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
      41,     7,     8,     9,    10,    -1,    47,    13,    14,    15,
      16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    28,    -1,    -1,    -1,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,    -1,
      -1,    47,    21,    22,    23,    24,    25,    26,    27,    -1,
      29,    30,    31,    -1,    33,    34,    -1,    36,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    -1,    -1,    48,
      49,    21,    22,    23,    24,    25,    26,    27,    -1,    29,
      30,    31,    -1,    33,    34,    -1,    36,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    -1,    -1,    48,    49,
      21,    22,    23,    24,    25,    26,    27,    -1,    29,    30,
      31,    -1,    33,    34,    -1,    36,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    -1,    -1,    48,    49,    21,
      22,    23,    24,    25,    26,    27,    -1,    29,    30,    31,
      -1,    33,    34,    -1,    36,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    -1,    -1,    48,    49,    21,    22,
      23,    24,    25,    26,    27,    -1,    29,    30,    31,    -1,
      33,    34,    -1,    36,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    -1,    -1,    48,    49,    21,    22,    23,
      24,    25,    26,    27,    -1,    29,    30,    31,    -1,    33,
      34,    -1,    36,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    -1,    -1,    48,    49,    21,    22,    23,    24,
      25,    26,    27,    -1,    29,    30,    31,    -1,    33,    34,
      -1,    36,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    -1,    -1,    48,    49,    21,    22,    23,    24,    25,
      26,    27,    -1,    29,    30,    31,    -1,    33,    34,    -1,
      36,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      -1,    -1,    48,    49,    21,    22,    23,    24,    25,    26,
      27,    -1,    29,    30,    31,    -1,    33,    34,    -1,    36,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    -1,
      -1,    48,    49,    21,    22,    23,    24,    25,    26,    27,
      -1,    29,    30,    31,    -1,    33,    34,    -1,    36,    -1,
      38,    39,    40,    41,    42,    43,    44,    45,    -1,    -1,
      48,    21,    22,    23,    24,    25,    26,    27,    -1,    29,
      30,    31,    -1,    33,    34,    -1,    36,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    -1,    -1,    48,    21,
      22,    23,    24,    25,    26,    27,    -1,    29,    30,    31,
      -1,    33,    34,    -1,    36,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    -1,    -1,    48,    21,    22,    23,
      24,    25,    26,    27,    -1,    29,    30,    31,    -1,    33,
      34,    -1,    36,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    -1,    -1,    48,    21,    22,    23,    24,    25,
      26,    27,    -1,    29,    30,    31,    -1,    33,    34,    -1,
      36,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      -1,    -1,    48,    21,    22,    23,    24,    25,    26,    27,
      -1,    29,    30,    31,    -1,    33,    34,    -1,    36,    -1,
      38,    39,    40,    41,    42,    43,    44,    45,    -1,    -1,
      48,    21,    22,    23,    24,    25,    26,    27,    -1,    29,
      30,    31,    -1,    33,    34,    -1,    36,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    -1,    -1,    48,    21,
      22,    23,    24,    25,    26,    27,    -1,    29,    30,    31,
      -1,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    21,    22,    23,    24,    25,    26,
      27,    -1,    29,    30,    31,    -1,    33,    34,    -1,    36,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    21,
      22,    23,    24,    25,    26,    27,    -1,    29,    30,    31,
      -1,    33,    34,    -1,    -1,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    29,    30,    31,    -1,    33,    34,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    45
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    28,    32,
      41,    47,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    47,    47,    47,    50,    47,    47,    47,
      47,    50,    51,    17,    17,    55,    55,    55,    55,     0,
      21,    22,    23,    24,    25,    26,    27,    29,    30,    31,
      33,    34,    36,    38,    39,    40,    41,    42,    43,    44,
      45,    47,    18,    19,    55,    55,    55,    17,    55,    55,
      10,    17,    48,    17,    54,    48,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    48,    55,    17,
      17,    48,    48,    48,    48,    48,    50,    48,    50,    51,
      52,    37,    48,    49,    17,    17,    54,    50,    55,    55,
      48,    48,    52,    17,    48,    49,    50,    55,    17,    48,
      49,    48,    55,    48,    49,    55,    48,    49,    55,    48,
      49,    55,    48,    49,    55,    48,    49,    55,    48,    49,
      55,    48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    54,    54,    54,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    56,    56,    56,
      57,    57,    57,    58,    58,    58,    58,    59,    59,    59,
      59,    59,    59,    60,    60,    60,    61,    62,    62,    63,
      63,    63,    64,    64,    64,    64
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     4,     1,     3,     4,     3,
       3,     3,     3,     3,     3,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     3,     3,     3,     2,
       3,     3,     5,     4,     4,     4,     3,     4,     6,     8,
      10,    12,    14,    16,    18,    20,    22,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     6,     1,     3,     4,
       6,     6,     9,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     2,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
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

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
      yychar = yylex ();
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 3:
#line 137 "expr.y" /* yacc.c:1646  */
    { yyerror("\"ask\" is not supported here"); }
#line 1593 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 4:
#line 139 "expr.y" /* yacc.c:1646  */
    { yyerror("\"default\" is not supported here"); }
#line 1599 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 5:
#line 141 "expr.y" /* yacc.c:1646  */
    { yyerror("\"default()\" is not supported here"); }
#line 1605 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 8:
#line 148 "expr.y" /* yacc.c:1646  */
    { yyerror("const() is not supported here"); }
#line 1611 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 9:
#line 151 "expr.y" /* yacc.c:1646  */
    { *e++ = cDynamicExpression::ADD; }
#line 1617 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 10:
#line 153 "expr.y" /* yacc.c:1646  */
    { *e++ = cDynamicExpression::SUB; }
#line 1623 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 11:
#line 155 "expr.y" /* yacc.c:1646  */
    { *e++ = cDynamicExpression::MUL; }
#line 1629 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 12:
#line 157 "expr.y" /* yacc.c:1646  */
    { *e++ = cDynamicExpression::DIV; }
#line 1635 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 13:
#line 159 "expr.y" /* yacc.c:1646  */
    { *e++ = cDynamicExpression::MOD; }
#line 1641 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 14:
#line 161 "expr.y" /* yacc.c:1646  */
    { *e++ = cDynamicExpression::POW; }
#line 1647 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 15:
#line 165 "expr.y" /* yacc.c:1646  */
    { *e++ = cDynamicExpression::NEG; }
#line 1653 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 16:
#line 168 "expr.y" /* yacc.c:1646  */
    { *e++ = cDynamicExpression::EQ; }
#line 1659 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 17:
#line 170 "expr.y" /* yacc.c:1646  */
    { *e++ = cDynamicExpression::NE; }
#line 1665 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 18:
#line 172 "expr.y" /* yacc.c:1646  */
    { *e++ = cDynamicExpression::GT; }
#line 1671 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 19:
#line 174 "expr.y" /* yacc.c:1646  */
    { *e++ = cDynamicExpression::GE; }
#line 1677 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 20:
#line 176 "expr.y" /* yacc.c:1646  */
    { *e++ = cDynamicExpression::LT; }
#line 1683 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 21:
#line 178 "expr.y" /* yacc.c:1646  */
    { *e++ = cDynamicExpression::LE; }
#line 1689 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 22:
#line 181 "expr.y" /* yacc.c:1646  */
    { *e++ = cDynamicExpression::AND; }
#line 1695 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 23:
#line 183 "expr.y" /* yacc.c:1646  */
    { *e++ = cDynamicExpression::OR; }
#line 1701 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 24:
#line 185 "expr.y" /* yacc.c:1646  */
    { *e++ = cDynamicExpression::XOR; }
#line 1707 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 25:
#line 189 "expr.y" /* yacc.c:1646  */
    { *e++ = cDynamicExpression::NOT; }
#line 1713 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 26:
#line 192 "expr.y" /* yacc.c:1646  */
    { *e++ = cDynamicExpression::BIN_AND; }
#line 1719 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 27:
#line 194 "expr.y" /* yacc.c:1646  */
    { *e++ = cDynamicExpression::BIN_OR; }
#line 1725 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 28:
#line 196 "expr.y" /* yacc.c:1646  */
    { *e++ = cDynamicExpression::BIN_XOR; }
#line 1731 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 29:
#line 200 "expr.y" /* yacc.c:1646  */
    { *e++ = cDynamicExpression::BIN_NOT; }
#line 1737 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 30:
#line 202 "expr.y" /* yacc.c:1646  */
    { *e++ = cDynamicExpression::LSHIFT; }
#line 1743 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 31:
#line 204 "expr.y" /* yacc.c:1646  */
    { *e++ = cDynamicExpression::RSHIFT; }
#line 1749 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 32:
#line 206 "expr.y" /* yacc.c:1646  */
    { *e++ = cDynamicExpression::IIF; }
#line 1755 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 33:
#line 209 "expr.y" /* yacc.c:1646  */
    { addFunction("int",1); }
#line 1761 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 34:
#line 211 "expr.y" /* yacc.c:1646  */
    { addFunction("double",1); }
#line 1767 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 35:
#line 213 "expr.y" /* yacc.c:1646  */
    { addFunction("string",1); }
#line 1773 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 36:
#line 216 "expr.y" /* yacc.c:1646  */
    { addFunction((yyvsp[-2]),0); delete [] (yyvsp[-2]); }
#line 1779 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 37:
#line 218 "expr.y" /* yacc.c:1646  */
    { addFunction((yyvsp[-3]),1); delete [] (yyvsp[-3]); }
#line 1785 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 38:
#line 220 "expr.y" /* yacc.c:1646  */
    { addFunction((yyvsp[-5]),2); delete [] (yyvsp[-5]); }
#line 1791 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 39:
#line 222 "expr.y" /* yacc.c:1646  */
    { addFunction((yyvsp[-7]),3); delete [] (yyvsp[-7]); }
#line 1797 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 40:
#line 224 "expr.y" /* yacc.c:1646  */
    { addFunction((yyvsp[-9]),4); delete [] (yyvsp[-9]); }
#line 1803 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 41:
#line 226 "expr.y" /* yacc.c:1646  */
    { addFunction((yyvsp[-11]),5); delete [] (yyvsp[-11]); }
#line 1809 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 42:
#line 228 "expr.y" /* yacc.c:1646  */
    { addFunction((yyvsp[-13]),6); delete [] (yyvsp[-13]); }
#line 1815 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 43:
#line 230 "expr.y" /* yacc.c:1646  */
    { addFunction((yyvsp[-15]),7); delete [] (yyvsp[-15]); }
#line 1821 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 44:
#line 232 "expr.y" /* yacc.c:1646  */
    { addFunction((yyvsp[-17]),8); delete [] (yyvsp[-17]); }
#line 1827 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 45:
#line 234 "expr.y" /* yacc.c:1646  */
    { addFunction((yyvsp[-19]),9); delete [] (yyvsp[-19]); }
#line 1833 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 46:
#line 236 "expr.y" /* yacc.c:1646  */
    { addFunction((yyvsp[-21]),10); delete [] (yyvsp[-21]); }
#line 1839 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 51:
#line 248 "expr.y" /* yacc.c:1646  */
    { (yyval) = opp_strdup("xmldoc"); }
#line 1845 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 52:
#line 250 "expr.y" /* yacc.c:1646  */
    { (yyval) = opp_strdup("xml"); }
#line 1851 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 53:
#line 255 "expr.y" /* yacc.c:1646  */
    { *e++ = new NEDSupport::ParameterRef((yyvsp[0]), true, false); delete [] (yyvsp[0]); }
#line 1857 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 54:
#line 257 "expr.y" /* yacc.c:1646  */
    { *e++ = new NEDSupport::ParameterRef((yyvsp[0]), false, true); delete [] (yyvsp[0]); }
#line 1863 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 55:
#line 259 "expr.y" /* yacc.c:1646  */
    { *e++ = new NEDSupport::SiblingModuleParameterRef((yyvsp[-2]), (yyvsp[0]), true, false); delete [] (yyvsp[-2]); delete [] (yyvsp[0]); }
#line 1869 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 56:
#line 261 "expr.y" /* yacc.c:1646  */
    { *e++ = new NEDSupport::SiblingModuleParameterRef((yyvsp[-5]), (yyvsp[0]), true, true); delete [] (yyvsp[-5]); delete [] (yyvsp[0]); }
#line 1875 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 57:
#line 266 "expr.y" /* yacc.c:1646  */
    { *e++ = new NEDSupport::ModuleIndex(); }
#line 1881 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 58:
#line 268 "expr.y" /* yacc.c:1646  */
    { *e++ = new NEDSupport::ModuleIndex(); }
#line 1887 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 59:
#line 270 "expr.y" /* yacc.c:1646  */
    { *e++ = new NEDSupport::Sizeof((yyvsp[-1]), true, false); delete [] (yyvsp[-1]); }
#line 1893 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 60:
#line 272 "expr.y" /* yacc.c:1646  */
    { *e++ = new NEDSupport::Sizeof((yyvsp[-1]), false, false); delete [] (yyvsp[-1]); }
#line 1899 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 61:
#line 274 "expr.y" /* yacc.c:1646  */
    { delete [] (yyvsp[-3]); delete [] (yyvsp[-1]); yyerror("sizeof(submodule.gate) notation not supported here"); }
#line 1905 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 62:
#line 276 "expr.y" /* yacc.c:1646  */
    { delete [] (yyvsp[-6]); delete [] (yyvsp[-1]); yyerror("sizeof(submodule[index].gate) notation not supported here"); }
#line 1911 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 66:
#line 287 "expr.y" /* yacc.c:1646  */
    { *e++ = opp_parsequotedstr((yyvsp[0])).c_str(); delete [] (yyvsp[0]); }
#line 1917 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 67:
#line 292 "expr.y" /* yacc.c:1646  */
    { *e++ = true; }
#line 1923 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 68:
#line 294 "expr.y" /* yacc.c:1646  */
    { *e++ = false; }
#line 1929 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 69:
#line 299 "expr.y" /* yacc.c:1646  */
    { *e++ = opp_atol((yyvsp[0])); delete [] (yyvsp[0]); }
#line 1935 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 70:
#line 301 "expr.y" /* yacc.c:1646  */
    { *e++ = opp_atof((yyvsp[0])); delete [] (yyvsp[0]); }
#line 1941 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 71:
#line 303 "expr.y" /* yacc.c:1646  */
    {
                  std::string unit;
                  *e++ = parseQuantity((yyvsp[0]), unit);
                  if (!unit.empty())
                      (e-1)->setUnit(unit.c_str());
                  delete [] (yyvsp[0]);
                }
#line 1953 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 72:
#line 314 "expr.y" /* yacc.c:1646  */
    { (yyval) = expryyconcat((yyvsp[-2]),(yyvsp[-1]),(yyvsp[0])); }
#line 1959 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 73:
#line 316 "expr.y" /* yacc.c:1646  */
    { (yyval) = expryyconcat((yyvsp[-2]),(yyvsp[-1]),(yyvsp[0])); }
#line 1965 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 74:
#line 318 "expr.y" /* yacc.c:1646  */
    { (yyval) = expryyconcat((yyvsp[-1]),(yyvsp[0])); }
#line 1971 "expr.tab.cc" /* yacc.c:1646  */
    break;

  case 75:
#line 320 "expr.y" /* yacc.c:1646  */
    { (yyval) = expryyconcat((yyvsp[-1]),(yyvsp[0])); }
#line 1977 "expr.tab.cc" /* yacc.c:1646  */
    break;


#line 1981 "expr.tab.cc" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 323 "expr.y" /* yacc.c:1906  */


//----------------------------------------------------------------------

void doParseExpression(const char *nedtext, cDynamicExpression::Elem *&elems, int& nelems)
{
    NONREENTRANT_PARSER();

    elems = NULL;
    nelems = 0;

    // reset the lexer
    xpos.co = 0;
    xpos.li = 1;
    xprevpos = xpos;

    yyin = NULL;
    yyout = stderr; // not used anyway

    // alloc buffer
    struct yy_buffer_state *handle = yy_scan_string(nedtext);
    if (!handle)
        throw std::runtime_error("parser is unable to allocate work memory");

    cDynamicExpression::Elem *v = new cDynamicExpression::Elem[100]; // overestimate for now; XXX danger of overrun
    e = v;

    // parse
    try
    {
        yyparse();
    }
    catch (std::exception& e)
    {
        yy_delete_buffer(handle);
        delete [] v;
        throw;
    }
    yy_delete_buffer(handle);

    // copy v[] and return
    nelems = e - v;
    elems = new cDynamicExpression::Elem[nelems];
    for (int i=0; i<nelems; i++)
        elems[i] = v[i];
    delete [] v;
}

void yyerror(const char *s)
{
    // chop newline
    char buf[250];
    strcpy(buf, s);
    if (buf[strlen(buf)-1] == '\n')
        buf[strlen(buf)-1] = '\0';

    throw std::runtime_error(buf);
}

