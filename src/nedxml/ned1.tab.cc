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
#define yyparse         ned1yyparse
#define yylex           ned1yylex
#define yyerror         ned1yyerror
#define yydebug         ned1yydebug
#define yynerrs         ned1yynerrs

#define yylval          ned1yylval
#define yychar          ned1yychar
#define yylloc          ned1yylloc

/* Copy the first part of user declarations.  */
#line 77 "ned1.y" /* yacc.c:339  */


/*
 * Note:
 * This file contains about 5 shift-reduce conflicts, 3 of them around 'expression'.
 *
 * Plus one (real) ambiguity exists between submodule display string
 * and compound module display string if no connections are present.
 */


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "nedyydefs.h"
#include "nedutil.h"
#include "nederror.h"
#include "nedexception.h"
#include "stringutil.h"
#include "commonutil.h"

#define YYDEBUG 1           /* allow debugging */
#define YYDEBUGGING_ON 0    /* turn on/off debugging */

#if YYDEBUG != 0
#define YYERROR_VERBOSE     /* more detailed error messages */
#include <string.h>         /* YYVERBOSE needs it */
#endif

#define yylloc ned1yylloc
#define yyin ned1yyin
#define yyout ned1yyout
#define yyrestart ned1yyrestart
#define yy_scan_string ned1yy_scan_string
#define yy_delete_buffer ned1yy_delete_buffer
extern FILE *yyin;
extern FILE *yyout;
struct yy_buffer_state;
struct yy_buffer_state *yy_scan_string(const char *str);
void yy_delete_buffer(struct yy_buffer_state *);
void yyrestart(FILE *);
int yylex();
void yyerror (const char *s);

#include "nedparser.h"
#include "nedfilebuffer.h"
#include "nedelements.h"
#include "nedutil.h"
#include "nedyylib.h"

USING_NAMESPACE

static struct NED1ParserState
{
    bool inLoop;
    bool inNetwork;
    bool inGroup;

    YYLTYPE exprPos;

    /* tmp flags, used with msg fields */
    bool isAbstract;
    bool isReadonly;

    /* NED-I: modules, channels, networks */
    NedFileElement *nedfile;
    CommentElement *comment;
    ImportElement *import;
    ExtendsElement *extends;
    ChannelElement *channel;
    NEDElement *module;  // in fact, CompoundModuleElement* or SimpleModule*
    ParametersElement *params;
    ParamElement *param;
    ParametersElement *substparams;
    ParamElement *substparam;
    PropertyElement *property;
    PropertyKeyElement *propkey;
    GatesElement *gates;
    GateElement *gate;
    GatesElement *gatesizes;
    GateElement *gatesize;
    SubmodulesElement *submods;
    SubmoduleElement *submod;
    ConnectionsElement *conns;
    ConnectionGroupElement *conngroup;
    ConnectionElement *conn;
    LoopElement *loop;
    ConditionElement *condition;
} ps;

static void resetParserState()
{
    static NED1ParserState cleanps;
    ps = cleanps;
}

void removeRedundantConnectionParams();
void createSubstparamsElementIfNotExists();
void createGatesizesElementIfNotExists();


#line 177 "ned1.tab.cc" /* yacc.c:339  */

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
   by #include "ned1.tab.hh".  */
#ifndef YY_NED1YY_NED1_TAB_HH_INCLUDED
# define YY_NED1YY_NED1_TAB_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int ned1yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INCLUDE = 258,
    SIMPLE = 259,
    CHANNEL = 260,
    MODULE = 261,
    PARAMETERS = 262,
    GATES = 263,
    GATESIZES = 264,
    SUBMODULES = 265,
    CONNECTIONS = 266,
    DISPLAY = 267,
    IN = 268,
    OUT = 269,
    NOCHECK = 270,
    LEFT_ARROW = 271,
    RIGHT_ARROW = 272,
    FOR = 273,
    TO = 274,
    DO = 275,
    IF = 276,
    LIKE = 277,
    NETWORK = 278,
    ENDSIMPLE = 279,
    ENDMODULE = 280,
    ENDCHANNEL = 281,
    ENDNETWORK = 282,
    ENDFOR = 283,
    MACHINES = 284,
    ON = 285,
    CHANATTRNAME = 286,
    INTCONSTANT = 287,
    REALCONSTANT = 288,
    NAME = 289,
    STRINGCONSTANT = 290,
    CHARCONSTANT = 291,
    TRUE_ = 292,
    FALSE_ = 293,
    INPUT_ = 294,
    XMLDOC = 295,
    REF = 296,
    ANCESTOR = 297,
    CONSTDECL = 298,
    NUMERICTYPE = 299,
    STRINGTYPE = 300,
    BOOLTYPE = 301,
    XMLTYPE = 302,
    ANYTYPE = 303,
    CPLUSPLUS = 304,
    CPLUSPLUSBODY = 305,
    MESSAGE = 306,
    CLASS = 307,
    STRUCT = 308,
    ENUM = 309,
    NONCOBJECT = 310,
    EXTENDS = 311,
    FIELDS = 312,
    PROPERTIES = 313,
    ABSTRACT = 314,
    READONLY = 315,
    CHARTYPE = 316,
    SHORTTYPE = 317,
    INTTYPE = 318,
    LONGTYPE = 319,
    DOUBLETYPE = 320,
    UNSIGNED_ = 321,
    SIZEOF = 322,
    SUBMODINDEX = 323,
    PLUSPLUS = 324,
    EQ = 325,
    NE = 326,
    GT = 327,
    GE = 328,
    LS = 329,
    LE = 330,
    AND = 331,
    OR = 332,
    XOR = 333,
    NOT = 334,
    BIN_AND = 335,
    BIN_OR = 336,
    BIN_XOR = 337,
    BIN_COMPL = 338,
    SHIFT_LEFT = 339,
    SHIFT_RIGHT = 340,
    INVALID_CHAR = 341,
    UMIN = 342
  };
#endif
/* Tokens.  */
#define INCLUDE 258
#define SIMPLE 259
#define CHANNEL 260
#define MODULE 261
#define PARAMETERS 262
#define GATES 263
#define GATESIZES 264
#define SUBMODULES 265
#define CONNECTIONS 266
#define DISPLAY 267
#define IN 268
#define OUT 269
#define NOCHECK 270
#define LEFT_ARROW 271
#define RIGHT_ARROW 272
#define FOR 273
#define TO 274
#define DO 275
#define IF 276
#define LIKE 277
#define NETWORK 278
#define ENDSIMPLE 279
#define ENDMODULE 280
#define ENDCHANNEL 281
#define ENDNETWORK 282
#define ENDFOR 283
#define MACHINES 284
#define ON 285
#define CHANATTRNAME 286
#define INTCONSTANT 287
#define REALCONSTANT 288
#define NAME 289
#define STRINGCONSTANT 290
#define CHARCONSTANT 291
#define TRUE_ 292
#define FALSE_ 293
#define INPUT_ 294
#define XMLDOC 295
#define REF 296
#define ANCESTOR 297
#define CONSTDECL 298
#define NUMERICTYPE 299
#define STRINGTYPE 300
#define BOOLTYPE 301
#define XMLTYPE 302
#define ANYTYPE 303
#define CPLUSPLUS 304
#define CPLUSPLUSBODY 305
#define MESSAGE 306
#define CLASS 307
#define STRUCT 308
#define ENUM 309
#define NONCOBJECT 310
#define EXTENDS 311
#define FIELDS 312
#define PROPERTIES 313
#define ABSTRACT 314
#define READONLY 315
#define CHARTYPE 316
#define SHORTTYPE 317
#define INTTYPE 318
#define LONGTYPE 319
#define DOUBLETYPE 320
#define UNSIGNED_ 321
#define SIZEOF 322
#define SUBMODINDEX 323
#define PLUSPLUS 324
#define EQ 325
#define NE 326
#define GT 327
#define GE 328
#define LS 329
#define LE 330
#define AND 331
#define OR 332
#define XOR 333
#define NOT 334
#define BIN_AND 335
#define BIN_OR 336
#define BIN_XOR 337
#define BIN_COMPL 338
#define SHIFT_LEFT 339
#define SHIFT_RIGHT 340
#define INVALID_CHAR 341
#define UMIN 342

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE ned1yylval;
extern YYLTYPE ned1yylloc;
int ned1yyparse (void);

#endif /* !YY_NED1YY_NED1_TAB_HH_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 416 "ned1.tab.cc" /* yacc.c:358  */

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   781

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  104
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  108
/* YYNRULES -- Number of rules.  */
#define YYNRULES  241
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  419

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   342

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    93,     2,     2,
     101,   102,    91,    89,    97,    90,   103,    92,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    88,    96,
       2,   100,     2,    87,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    98,     2,    99,    94,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    95
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   185,   185,   189,   190,   194,   196,   198,   200,   202,
     210,   215,   216,   220,   233,   241,   253,   255,   260,   270,
     283,   284,   291,   302,   311,   312,   319,   333,   342,   343,
     350,   351,   355,   382,   383,   388,   387,   399,   400,   404,
     409,   420,   426,   432,   437,   442,   447,   452,   457,   462,
     467,   478,   479,   484,   483,   495,   496,   500,   501,   502,
     503,   507,   508,   512,   520,   530,   531,   535,   543,   556,
     557,   562,   561,   573,   574,   578,   579,   584,   583,   595,
     594,   607,   606,   619,   618,   634,   643,   645,   649,   650,
     655,   654,   661,   660,   673,   674,   678,   679,   683,   691,
     690,   703,   711,   715,   716,   723,   725,   729,   730,   735,
     734,   741,   740,   753,   754,   758,   759,   763,   777,   798,
     805,   806,   811,   810,   821,   820,   833,   834,   838,   839,
     843,   844,   849,   848,   863,   864,   868,   879,   886,   890,
     909,   913,   914,   918,   925,   933,   941,   953,   954,   958,
     966,   976,   981,   985,   993,  1002,  1010,  1022,  1023,  1027,
    1032,  1039,  1044,  1048,  1056,  1061,  1065,  1074,  1082,  1086,
    1087,  1091,  1103,  1113,  1127,  1137,  1143,  1147,  1158,  1160,
    1165,  1166,  1169,  1171,  1173,  1175,  1177,  1179,  1182,  1186,
    1188,  1190,  1192,  1194,  1196,  1199,  1201,  1203,  1206,  1210,
    1212,  1214,  1217,  1220,  1222,  1224,  1227,  1229,  1231,  1234,
    1236,  1238,  1240,  1242,  1247,  1248,  1249,  1253,  1258,  1263,
    1268,  1273,  1281,  1283,  1285,  1290,  1291,  1292,  1296,  1301,
    1303,  1308,  1310,  1312,  1317,  1318,  1319,  1320,  1323,  1323,
    1325,  1325
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INCLUDE", "SIMPLE", "CHANNEL", "MODULE",
  "PARAMETERS", "GATES", "GATESIZES", "SUBMODULES", "CONNECTIONS",
  "DISPLAY", "IN", "OUT", "NOCHECK", "LEFT_ARROW", "RIGHT_ARROW", "FOR",
  "TO", "DO", "IF", "LIKE", "NETWORK", "ENDSIMPLE", "ENDMODULE",
  "ENDCHANNEL", "ENDNETWORK", "ENDFOR", "MACHINES", "ON", "CHANATTRNAME",
  "INTCONSTANT", "REALCONSTANT", "NAME", "STRINGCONSTANT", "CHARCONSTANT",
  "TRUE_", "FALSE_", "INPUT_", "XMLDOC", "REF", "ANCESTOR", "CONSTDECL",
  "NUMERICTYPE", "STRINGTYPE", "BOOLTYPE", "XMLTYPE", "ANYTYPE",
  "CPLUSPLUS", "CPLUSPLUSBODY", "MESSAGE", "CLASS", "STRUCT", "ENUM",
  "NONCOBJECT", "EXTENDS", "FIELDS", "PROPERTIES", "ABSTRACT", "READONLY",
  "CHARTYPE", "SHORTTYPE", "INTTYPE", "LONGTYPE", "DOUBLETYPE",
  "UNSIGNED_", "SIZEOF", "SUBMODINDEX", "PLUSPLUS", "EQ", "NE", "GT", "GE",
  "LS", "LE", "AND", "OR", "XOR", "NOT", "BIN_AND", "BIN_OR", "BIN_XOR",
  "BIN_COMPL", "SHIFT_LEFT", "SHIFT_RIGHT", "INVALID_CHAR", "'?'", "':'",
  "'+'", "'-'", "'*'", "'/'", "'%'", "'^'", "UMIN", "';'", "','", "'['",
  "']'", "'='", "'('", "')'", "'.'", "$accept", "networkdescription",
  "somedefinitions", "definition", "import", "filenames", "filename",
  "channeldefinition", "channelheader", "opt_channelattrblock",
  "channelattrblock", "endchannel", "simpledefinition", "simpleheader",
  "endsimple", "moduledefinition", "moduleheader", "endmodule",
  "opt_displayblock", "displayblock", "opt_paramblock", "paramblock",
  "$@1", "opt_parameters", "parameters", "parameter", "opt_gateblock",
  "gateblock", "$@2", "opt_gates", "gates", "gatesI", "gateI", "gatesO",
  "gateO", "opt_submodblock", "submodblock", "$@3", "opt_submodules",
  "submodules", "submodule", "$@4", "$@5", "$@6", "$@7", "submodule_body",
  "opt_substparamblocks", "substparamblocks", "substparamblock", "$@8",
  "$@9", "opt_substparameters", "substparameters", "substparameter",
  "$@10", "inputvalue", "opt_gatesizeblocks", "gatesizeblocks",
  "gatesizeblock", "$@11", "$@12", "opt_gatesizes", "gatesizes",
  "gatesize", "opt_submod_displayblock", "opt_connblock", "connblock",
  "$@13", "$@14", "opt_connections", "connections", "connection",
  "loopconnection", "$@15", "loopvarlist", "loopvar", "opt_conncondition",
  "opt_conn_displaystr", "notloopconnections", "notloopconnection",
  "leftgatespec", "leftmod", "leftgate", "parentleftgate", "rightgatespec",
  "rightmod", "rightgate", "parentrightgate", "channeldescr",
  "channelattrs", "chanattr", "networkdefinition", "networkheader",
  "endnetwork", "vector", "expression", "xmldocvalue", "expr",
  "simple_expr", "parameter_expr", "special_expr", "literal",
  "stringliteral", "boolliteral", "numliteral", "quantity",
  "opt_semicolon", "comma_or_semicolon", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,    63,    58,    43,
      45,    42,    47,    37,    94,   342,    59,    44,    91,    93,
      61,    40,    41,    46
};
# endif

#define YYPACT_NINF -341

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-341)))

#define YYTABLE_NINF -169

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -341,    31,   166,  -341,    14,     6,    30,    68,   102,  -341,
    -341,  -341,   123,  -341,   134,  -341,   134,  -341,   154,  -341,
      26,  -341,  -341,  -341,  -341,    86,   236,   157,   146,   100,
     202,  -341,   202,     1,   169,   154,  -341,  -341,    14,   190,
     192,   195,   136,  -341,  -341,  -341,   141,    85,    12,   150,
     161,   162,   163,   165,   290,   290,   290,   290,   144,  -341,
     601,  -341,  -341,  -341,  -341,  -341,  -341,  -341,   107,    -5,
    -341,   236,  -341,   159,   228,  -341,   262,   236,  -341,   144,
    -341,  -341,  -341,   144,  -341,  -341,    83,   240,  -341,   245,
    -341,   252,   290,   290,   290,   253,   186,  -341,  -341,  -341,
     411,  -341,  -341,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   261,   263,   144,  -341,   144,    -6,
    -341,    -2,  -341,   208,   287,  -341,   212,   268,  -341,  -341,
    -341,   312,   -67,  -341,  -341,   444,   477,   510,   204,  -341,
    -341,   164,   164,   164,   164,   164,   164,   676,   626,   651,
     687,   200,   249,   126,   126,   576,    88,    88,   213,   213,
     213,   213,  -341,  -341,  -341,  -341,   220,   276,  -341,    47,
    -341,   139,   144,  -341,  -341,     5,   299,  -341,  -341,   214,
    -341,    62,  -341,   290,  -341,   240,  -341,  -341,  -341,  -341,
    -341,   290,   188,  -341,  -341,    -6,   278,   279,  -341,   151,
    -341,   282,   229,  -341,   230,   296,  -341,   268,   160,  -341,
     268,   345,   234,   601,   286,   301,  -341,  -341,  -341,  -341,
    -341,   247,    79,  -341,   248,    90,  -341,   278,   279,   259,
    -341,   282,  -341,  -341,     8,   313,     0,  -341,  -341,  -341,
    -341,  -341,   290,  -341,  -341,  -341,  -341,   250,  -341,   278,
     251,  -341,   279,    94,   110,   317,  -341,     8,  -341,   -62,
    -341,     8,  -341,  -341,  -341,   187,   256,  -341,   258,   144,
    -341,   255,   378,  -341,  -341,  -341,  -341,  -341,  -341,   -10,
    -341,   318,  -341,   236,   257,  -341,    78,    78,   327,  -341,
    -341,    66,  -341,   290,  -341,   328,    -9,  -341,   264,   343,
     269,   266,   236,    -8,   346,   265,  -341,   354,   340,  -341,
     346,   355,   -55,  -341,  -341,    33,   543,   144,   341,  -341,
     154,   236,   342,   318,  -341,  -341,  -341,   271,   236,   365,
     344,   347,  -341,   365,   347,  -341,  -341,   360,  -341,  -341,
    -341,   144,   154,  -341,   370,   379,    98,  -341,  -341,  -341,
     372,   112,   -36,  -341,   -59,   346,   112,   346,   298,   154,
    -341,  -341,     4,   396,   370,  -341,   236,   144,  -341,  -341,
    -341,  -341,  -341,  -341,  -341,   365,  -341,   365,  -341,  -341,
     154,   236,  -341,   322,  -341,  -341,  -341,  -341,   112,   112,
    -341,   323,   390,   377,  -341,  -341,  -341,   315,  -341,   116,
    -341,   332,   390,  -341,  -341,   390,  -341,  -341,  -341
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,     0,     0,     0,     0,     0,     3,
       5,     6,    16,     7,    34,     8,    34,     9,    87,    13,
       0,    12,    23,    15,    27,     0,     0,     0,    17,     0,
      52,    33,    52,     0,     0,    86,    89,    10,     0,     0,
     231,   232,   217,   228,   229,   230,     0,     0,     0,     0,
       0,     0,     0,   222,     0,     0,     0,     0,   239,   177,
     176,   180,   214,   215,   216,   225,   226,   227,   233,   239,
      14,     0,    35,     0,     0,    51,    70,     0,    90,   239,
     172,    88,    11,   239,   236,   237,     0,     0,   218,     0,
     221,     0,     0,     0,     0,     0,     0,   198,   202,   188,
       0,   238,    19,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   239,    21,   239,    38,
      53,   239,    22,     0,   121,    69,     0,    95,   174,   173,
     209,     0,     0,   219,   220,     0,     0,     0,     0,   223,
     181,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     199,   200,   201,   203,   204,     0,   182,   183,   184,   185,
     186,   187,   234,   235,    20,    18,    41,     0,    36,     0,
      40,    56,   239,    25,    71,     0,    31,   120,    92,     0,
      91,     0,    97,     0,   210,     0,   179,   208,   206,   207,
     224,     0,     0,    43,    37,     0,     0,     0,    54,    55,
      24,    74,     0,   124,     0,     0,    30,    95,     0,    94,
       0,     0,     0,   205,    44,    42,    47,    48,    49,    50,
      39,    64,     0,    62,    68,     0,    66,     0,     0,     0,
      72,    73,    76,   122,   127,     0,   239,    26,    93,    99,
      98,    96,     0,   211,   178,    45,    46,     0,    58,     0,
       0,    60,     0,     0,     0,     0,    75,   127,   132,   155,
     125,   126,   129,   130,   131,     0,     0,   148,     0,   239,
      29,   104,     0,    63,    61,    67,    65,    57,    59,   239,
     123,     0,   156,     0,   154,   128,     0,     0,     0,    32,
      28,     0,   100,     0,   212,     0,   239,    77,     0,     0,
     135,     0,     0,   165,   138,     0,   158,     0,   167,   169,
     138,     0,   152,   147,   103,     0,     0,   239,     0,    79,
      87,     0,     0,     0,   175,   171,   166,   164,     0,   140,
       0,     0,   170,   140,     0,   153,   151,     0,   102,   213,
      81,   239,    87,    78,   106,     0,     0,   142,   134,   137,
       0,     0,   162,   157,   165,   138,     0,   138,     0,    87,
      83,    80,     0,   119,   105,   108,     0,   239,   141,   139,
     241,   240,   145,   163,   161,   140,   143,   140,   101,    82,
      87,     0,   109,     0,    85,   107,   136,   133,     0,     0,
      84,     0,   114,     0,   146,   144,   111,     0,   110,     0,
     116,     0,   114,   117,   113,     0,   118,   112,   115
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -341,  -341,  -341,  -341,  -341,  -341,   393,  -341,  -341,  -341,
    -341,  -341,  -341,  -341,  -341,  -341,  -341,  -341,  -341,  -341,
     417,  -341,  -341,  -341,  -341,   235,   409,  -341,  -341,  -341,
    -341,   206,   185,   207,   184,  -341,  -341,  -341,  -341,  -341,
     216,  -341,  -341,  -341,  -341,  -331,   443,  -341,   429,  -341,
    -341,   260,  -341,   246,  -341,  -341,  -341,  -341,    99,  -341,
    -341,    64,  -341,    59,  -341,  -341,  -341,  -341,  -341,   211,
    -341,   219,  -341,  -341,   173,  -341,  -315,  -340,  -341,  -305,
    -341,  -341,  -341,  -341,  -184,  -341,  -341,  -341,   182,  -341,
     176,  -341,  -341,  -341,  -265,   -71,  -341,   -38,  -341,  -341,
    -341,  -341,   -85,  -341,  -341,  -341,   -68,  -261
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     9,    10,    20,    21,    11,    12,    27,
      28,    70,    13,    14,   132,    15,    16,   247,   215,   216,
      30,    31,   129,   178,   179,   180,    74,    75,   181,   208,
     209,   232,   233,   235,   236,   134,   135,   211,   240,   241,
     242,   330,   352,   369,   390,   353,   354,    35,    36,   137,
     217,   190,   191,   192,   281,   302,   373,   374,   375,   402,
     412,   408,   409,   410,   394,   186,   187,   267,   244,   270,
     271,   272,   273,   291,   309,   310,   339,   361,   356,   274,
     275,   276,   323,   277,   314,   315,   363,   316,   317,   318,
     319,    17,    18,    80,   337,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,   102,   382
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     128,   127,   142,   366,   294,   343,   136,   292,  -168,  -168,
     336,   138,   305,   328,   345,   139,    97,    98,    99,   100,
     212,   371,    77,  -168,   306,   391,   268,   357,   176,   126,
     195,     3,   182,   383,   279,   196,   293,   177,   389,   293,
      22,  -150,   269,   293,  -160,   398,    90,   399,   141,    19,
     385,   378,   387,    91,   145,   146,   147,   346,   174,   400,
     175,   336,   293,   183,    23,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   101,   101,   293,    78,
     293,   101,   392,   213,   101,  -160,   101,   384,    40,    41,
      42,    43,    24,    44,    45,   386,    46,    47,    48,   312,
     222,    49,   313,   320,   210,    40,    41,    42,    43,    88,
      44,    45,    37,    38,    47,    48,   377,    89,    49,    50,
     347,    51,   269,    52,    53,   348,    25,   404,   405,   124,
     125,    29,   413,   204,   205,    54,    50,   250,    51,    55,
      52,    53,   206,   207,    26,   221,    56,   365,   219,   220,
     367,    33,    54,   223,   237,   238,    55,    57,   324,     4,
       5,     6,     7,    56,    39,   258,   259,    71,   280,   120,
     121,   122,   123,    69,    57,   140,   261,   262,    72,     8,
     287,   259,    40,    41,    42,    43,    79,    44,    45,   249,
      46,    47,    48,   296,   297,    49,   288,   262,   380,   381,
      73,   300,   414,   415,   282,   118,   119,   120,   121,   122,
     123,   307,   311,    50,    83,    51,    84,    52,    53,    85,
     325,   224,   225,   226,   227,   228,   229,    86,   329,    54,
     101,   335,    87,    55,   112,   113,   114,   130,   115,   116,
      56,    92,   131,   118,   119,   120,   121,   122,   123,   350,
     355,    57,    93,    94,    95,   326,    96,   359,    40,    41,
      42,    43,   133,    44,    45,    43,    46,    47,    48,   143,
     112,    49,   114,   370,   115,   116,   144,   148,   149,   118,
     119,   120,   121,   122,   123,   172,   184,   173,   185,    50,
     188,    51,   189,    52,    53,   396,   200,   123,   202,   397,
     203,   214,   231,   234,   218,    54,   239,   243,   245,    55,
     401,   246,    40,    41,    42,    43,    56,    44,    45,   112,
     255,    47,    48,   115,   116,    49,   254,    57,   118,   119,
     120,   121,   122,   123,   256,   257,   260,   265,   278,   283,
     285,   289,   308,    50,   299,    51,   301,    52,    53,   298,
    -149,   322,   327,   332,   331,   334,   333,   338,   340,    54,
     341,   312,   344,    55,  -159,   351,   269,   360,   362,   372,
      56,   364,   103,   104,   105,   106,   107,   108,   109,   110,
     111,    57,   112,   113,   114,   368,   115,   116,   376,   117,
     388,   118,   119,   120,   121,   122,   123,   379,   393,   193,
     403,   406,   411,   293,   194,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   407,   112,   113,   114,   416,   115,
     116,    82,   117,    32,   118,   119,   120,   121,   122,   123,
     230,    76,   252,   263,   284,   264,   286,   253,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   266,   112,   113,
     114,    34,   115,   116,    81,   117,   251,   118,   119,   120,
     121,   122,   123,   395,   418,   303,   417,   248,   290,   321,
     304,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     295,   112,   113,   114,   342,   115,   116,     0,   117,     0,
     118,   119,   120,   121,   122,   123,   358,     0,     0,     0,
       0,     0,     0,   150,   103,   104,   105,   106,   107,   108,
     109,   110,   111,     0,   112,   113,   114,     0,   115,   116,
       0,   117,     0,   118,   119,   120,   121,   122,   123,     0,
       0,     0,     0,     0,     0,     0,   197,   103,   104,   105,
     106,   107,   108,   109,   110,   111,     0,   112,   113,   114,
       0,   115,   116,     0,   117,     0,   118,   119,   120,   121,
     122,   123,     0,     0,     0,     0,     0,     0,     0,   198,
     103,   104,   105,   106,   107,   108,   109,   110,   111,     0,
     112,   113,   114,     0,   115,   116,     0,   117,     0,   118,
     119,   120,   121,   122,   123,     0,     0,     0,     0,     0,
       0,     0,   199,   103,   104,   105,   106,   107,   108,   109,
     110,   111,     0,   112,   113,   114,     0,   115,   116,     0,
     117,     0,   118,   119,   120,   121,   122,   123,     0,     0,
       0,     0,     0,     0,     0,   349,   103,   104,   105,   106,
     107,   108,   109,   110,   111,     0,   112,   113,   114,     0,
     115,   116,     0,   117,   201,   118,   119,   120,   121,   122,
     123,   103,   104,   105,   106,   107,   108,   109,   110,   111,
       0,   112,   113,   114,     0,   115,   116,     0,   117,     0,
     118,   119,   120,   121,   122,   123,   103,   104,   105,   106,
     107,   108,   109,     0,   111,     0,   112,   113,   114,     0,
     115,   116,     0,     0,     0,   118,   119,   120,   121,   122,
     123,   103,   104,   105,   106,   107,   108,   109,     0,     0,
       0,   112,   113,   114,     0,   115,   116,     0,     0,     0,
     118,   119,   120,   121,   122,   123,   103,   104,   105,   106,
     107,   108,     0,     0,     0,     0,   112,   113,   114,     0,
     115,   116,     0,     0,     0,   118,   119,   120,   121,   122,
     123,   115,   116,     0,     0,     0,   118,   119,   120,   121,
     122,   123
};

static const yytype_int16 yycheck[] =
{
      71,    69,    87,   343,   269,   320,    77,    69,    16,    17,
      69,    79,    22,    22,    69,    83,    54,    55,    56,    57,
      15,   352,    21,    31,   289,    21,    18,   332,    34,    34,
      97,     0,    34,    69,    34,   102,    98,    43,   369,    98,
      34,   103,    34,    98,   103,   385,    34,   387,    86,    35,
     365,   356,   367,    41,    92,    93,    94,   322,   126,   390,
     128,    69,    98,   131,    34,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,    96,    96,    98,    88,
      98,    96,    88,    88,    96,   103,    96,   362,    32,    33,
      34,    35,    34,    37,    38,   366,    40,    41,    42,    31,
     195,    45,    34,   297,   182,    32,    33,    34,    35,    34,
      37,    38,    96,    97,    41,    42,    28,    42,    45,    63,
      97,    65,    34,    67,    68,   102,    34,   398,   399,    32,
      33,     7,   407,    96,    97,    79,    63,   218,    65,    83,
      67,    68,    13,    14,    31,   193,    90,   341,    96,    97,
     344,     7,    79,   201,    13,    14,    83,   101,   102,     3,
       4,     5,     6,    90,    88,    96,    97,    31,   246,    91,
      92,    93,    94,    26,   101,   102,    96,    97,    88,    23,
      96,    97,    32,    33,    34,    35,    27,    37,    38,    39,
      40,    41,    42,    16,    17,    45,    96,    97,    96,    97,
       8,   279,    96,    97,   252,    89,    90,    91,    92,    93,
      94,   289,   293,    63,    34,    65,    34,    67,    68,    34,
     301,    43,    44,    45,    46,    47,    48,   101,   306,    79,
      96,   312,   101,    83,    80,    81,    82,    88,    84,    85,
      90,   101,    24,    89,    90,    91,    92,    93,    94,   327,
     331,   101,   101,   101,   101,   303,   101,   338,    32,    33,
      34,    35,    10,    37,    38,    35,    40,    41,    42,    34,
      80,    45,    82,   351,    84,    85,    34,    34,   102,    89,
      90,    91,    92,    93,    94,    34,    88,    34,    11,    63,
      88,    65,    34,    67,    68,   376,   102,    94,    88,   377,
      34,    12,    34,    34,   100,    79,    34,    88,    88,    83,
     391,    25,    32,    33,    34,    35,    90,    37,    38,    80,
      44,    41,    42,    84,    85,    45,   102,   101,    89,    90,
      91,    92,    93,    94,    43,    98,    98,    88,    35,    99,
      99,    34,    34,    63,    96,    65,   101,    67,    68,   103,
     103,    34,    34,    20,   100,    99,    97,    21,   103,    79,
      16,    31,    17,    83,   103,    34,    34,    12,    34,     9,
      90,    34,    70,    71,    72,    73,    74,    75,    76,    77,
      78,   101,    80,    81,    82,    35,    84,    85,    19,    87,
     102,    89,    90,    91,    92,    93,    94,    35,    12,    97,
      88,    88,    35,    98,   102,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    34,    80,    81,    82,    96,    84,
      85,    38,    87,    16,    89,    90,    91,    92,    93,    94,
     205,    32,    97,   237,   259,   238,   262,   102,    70,    71,
      72,    73,    74,    75,    76,    77,    78,   241,    80,    81,
      82,    18,    84,    85,    35,    87,   220,    89,    90,    91,
      92,    93,    94,   374,   415,    97,   412,   217,   267,   297,
     102,    70,    71,    72,    73,    74,    75,    76,    77,    78,
     271,    80,    81,    82,   318,    84,    85,    -1,    87,    -1,
      89,    90,    91,    92,    93,    94,   333,    -1,    -1,    -1,
      -1,    -1,    -1,   102,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    -1,    80,    81,    82,    -1,    84,    85,
      -1,    87,    -1,    89,    90,    91,    92,    93,    94,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   102,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    -1,    80,    81,    82,
      -1,    84,    85,    -1,    87,    -1,    89,    90,    91,    92,
      93,    94,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   102,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    -1,
      80,    81,    82,    -1,    84,    85,    -1,    87,    -1,    89,
      90,    91,    92,    93,    94,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   102,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    -1,    80,    81,    82,    -1,    84,    85,    -1,
      87,    -1,    89,    90,    91,    92,    93,    94,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   102,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    -1,    80,    81,    82,    -1,
      84,    85,    -1,    87,    88,    89,    90,    91,    92,    93,
      94,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      -1,    80,    81,    82,    -1,    84,    85,    -1,    87,    -1,
      89,    90,    91,    92,    93,    94,    70,    71,    72,    73,
      74,    75,    76,    -1,    78,    -1,    80,    81,    82,    -1,
      84,    85,    -1,    -1,    -1,    89,    90,    91,    92,    93,
      94,    70,    71,    72,    73,    74,    75,    76,    -1,    -1,
      -1,    80,    81,    82,    -1,    84,    85,    -1,    -1,    -1,
      89,    90,    91,    92,    93,    94,    70,    71,    72,    73,
      74,    75,    -1,    -1,    -1,    -1,    80,    81,    82,    -1,
      84,    85,    -1,    -1,    -1,    89,    90,    91,    92,    93,
      94,    84,    85,    -1,    -1,    -1,    89,    90,    91,    92,
      93,    94
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   105,   106,     0,     3,     4,     5,     6,    23,   107,
     108,   111,   112,   116,   117,   119,   120,   195,   196,    35,
     109,   110,    34,    34,    34,    34,    31,   113,   114,     7,
     124,   125,   124,     7,   150,   151,   152,    96,    97,    88,
      32,    33,    34,    35,    37,    38,    40,    41,    42,    45,
      63,    65,    67,    68,    79,    83,    90,   101,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,    26,
     115,    31,    88,     8,   130,   131,   130,    21,    88,    27,
     197,   152,   110,    34,    34,    34,   101,   101,    34,    42,
      34,    41,   101,   101,   101,   101,   101,   201,   201,   201,
     201,    96,   210,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    80,    81,    82,    84,    85,    87,    89,    90,
      91,    92,    93,    94,    32,    33,    34,   210,   199,   126,
      88,    24,   118,    10,   139,   140,   199,   153,   210,   210,
     102,   201,   206,    34,    34,   201,   201,   201,    34,   102,
     102,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,    34,    34,   210,   210,    34,    43,   127,   128,
     129,   132,    34,   210,    88,    11,   169,   170,    88,    34,
     155,   156,   157,    97,   102,    97,   102,   102,   102,   102,
     102,    88,    88,    34,    96,    97,    13,    14,   133,   134,
     210,   141,    15,    88,    12,   122,   123,   154,   100,    96,
      97,   201,   206,   201,    43,    44,    45,    46,    47,    48,
     129,    34,   135,   136,    34,   137,   138,    13,    14,    34,
     142,   143,   144,    88,   172,    88,    25,   121,   155,    39,
     199,   157,    97,   102,   102,    44,    43,    98,    96,    97,
      98,    96,    97,   135,   137,    88,   144,   171,    18,    34,
     173,   174,   175,   176,   183,   184,   185,   187,    35,    34,
     210,   158,   201,    99,   136,    99,   138,    96,    96,    34,
     173,   177,    69,    98,   198,   175,    16,    17,   103,    96,
     210,   101,   159,    97,   102,    22,   198,   210,    34,   178,
     179,   199,    31,    34,   188,   189,   191,   192,   193,   194,
     188,   192,    34,   186,   102,   199,   201,    34,    22,   210,
     145,   100,    20,    97,    99,   199,    69,   198,    21,   180,
     103,    16,   194,   180,    17,    69,   198,    97,   102,   102,
     210,    34,   146,   149,   150,   199,   182,   183,   178,   199,
      12,   181,    34,   190,    34,   188,   181,   188,    35,   147,
     210,   149,     9,   160,   161,   162,    19,    28,   183,    35,
      96,    97,   211,    69,   198,   180,   211,   180,   102,   149,
     148,    21,    88,    12,   168,   162,   199,   210,   181,   181,
     149,   199,   163,    88,   211,   211,    88,    34,   165,   166,
     167,    35,   164,   198,    96,    97,    96,   165,   167
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   104,   105,   106,   106,   107,   107,   107,   107,   107,
     108,   109,   109,   110,   111,   112,   113,   113,   114,   114,
     115,   115,   116,   117,   118,   118,   119,   120,   121,   121,
     122,   122,   123,   124,   124,   126,   125,   127,   127,   128,
     128,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   130,   130,   132,   131,   133,   133,   134,   134,   134,
     134,   135,   135,   136,   136,   137,   137,   138,   138,   139,
     139,   141,   140,   142,   142,   143,   143,   145,   144,   146,
     144,   147,   144,   148,   144,   149,   150,   150,   151,   151,
     153,   152,   154,   152,   155,   155,   156,   156,   157,   158,
     157,   159,   159,   159,   159,   160,   160,   161,   161,   163,
     162,   164,   162,   165,   165,   166,   166,   167,   168,   168,
     169,   169,   171,   170,   172,   170,   173,   173,   174,   174,
     175,   175,   177,   176,   178,   178,   179,   180,   180,   181,
     181,   182,   182,   183,   183,   183,   183,   184,   184,   185,
     185,   186,   186,   186,   187,   187,   187,   188,   188,   189,
     189,   190,   190,   190,   191,   191,   191,   192,   193,   193,
     193,   194,   195,   196,   197,   198,   199,   199,   200,   200,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   201,   201,   201,   201,   201,   201,
     201,   201,   201,   201,   202,   202,   202,   203,   203,   203,
     203,   203,   204,   204,   204,   205,   205,   205,   206,   207,
     207,   208,   208,   208,   209,   209,   209,   209,   210,   210,
     211,   211
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     1,     1,     1,
       3,     3,     1,     1,     3,     2,     0,     1,     4,     3,
       3,     2,     4,     2,     3,     2,     7,     2,     3,     2,
       1,     0,     4,     1,     0,     0,     4,     2,     0,     3,
       1,     1,     3,     2,     3,     4,     4,     3,     3,     3,
       3,     1,     0,     0,     4,     1,     0,     4,     3,     4,
       3,     3,     1,     3,     1,     3,     1,     3,     1,     1,
       0,     0,     4,     1,     0,     2,     1,     0,     6,     0,
       7,     0,     8,     0,     9,     3,     1,     0,     2,     1,
       0,     4,     0,     6,     2,     0,     3,     1,     3,     0,
       5,     5,     3,     2,     0,     1,     0,     2,     1,     0,
       4,     0,     6,     2,     0,     3,     1,     2,     4,     0,
       1,     0,     0,     5,     0,     4,     1,     0,     2,     1,
       1,     1,     0,     7,     3,     1,     5,     2,     0,     2,
       0,     2,     1,     6,     8,     6,     8,     3,     1,     2,
       1,     2,     1,     2,     2,     1,     2,     3,     1,     2,
       1,     2,     1,     2,     2,     1,     2,     1,     1,     1,
       2,     2,     3,     5,     2,     3,     1,     1,     6,     4,
       1,     3,     3,     3,     3,     3,     3,     3,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     3,
       3,     3,     2,     3,     3,     5,     4,     4,     4,     3,
       4,     6,     8,    10,     1,     1,     1,     1,     2,     3,
       3,     2,     1,     3,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     2,     2,     1,     0,
       1,     1
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 6:
#line 197 "ned1.y" /* yacc.c:1646  */
    { if (np->getStoreSourceFlag()) storeComponentSourceCode(ps.channel, (yylsp[0])); }
#line 2004 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 7:
#line 199 "ned1.y" /* yacc.c:1646  */
    { if (np->getStoreSourceFlag()) storeComponentSourceCode(ps.module, (yylsp[0])); }
#line 2010 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 8:
#line 201 "ned1.y" /* yacc.c:1646  */
    { if (np->getStoreSourceFlag()) storeComponentSourceCode(ps.module, (yylsp[0])); }
#line 2016 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 9:
#line 203 "ned1.y" /* yacc.c:1646  */
    { if (np->getStoreSourceFlag()) storeComponentSourceCode(ps.module, (yylsp[0])); }
#line 2022 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 13:
#line 221 "ned1.y" /* yacc.c:1646  */
    {
                  ps.import = (ImportElement *)createElementWithTag(NED_IMPORT, ps.nedfile );
                  ps.import->setImportSpec(toString(trimQuotes((yylsp[0]))));
                  storeBannerAndRightComments(ps.import,(yylsp[0]));
                  storePos(ps.import, (yyloc));
                }
#line 2033 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 14:
#line 234 "ned1.y" /* yacc.c:1646  */
    {
                  storePos(ps.channel, (yyloc));
                  storeTrailingComment(ps.channel,(yyloc));
                }
#line 2042 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 15:
#line 242 "ned1.y" /* yacc.c:1646  */
    {
                  ps.channel = (ChannelElement *)createElementWithTag(NED_CHANNEL, ps.nedfile);
                  ps.channel->setName(toString((yylsp[0])));
                  ps.extends = (ExtendsElement *)createElementWithTag(NED_EXTENDS, ps.channel);
                  ps.extends->setName("ned.DatarateChannel");  // NED-1 channels are implicitly DatarateChannels
                  ps.params = (ParametersElement *)createElementWithTag(NED_PARAMETERS, ps.channel);
                  ps.params->setIsImplicit(true);
                  storeBannerAndRightComments(ps.channel,(yylsp[-1]),(yylsp[0]));
                }
#line 2056 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 17:
#line 256 "ned1.y" /* yacc.c:1646  */
    { storePos(ps.params, (yyloc)); }
#line 2062 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 18:
#line 261 "ned1.y" /* yacc.c:1646  */
    {
                  const char *name = toString((yylsp[-2]));
                  if (strcmp(name,"error")==0) name = "ber";  // "error" got renamed to "ber" in 4.0
                  ps.params->setIsImplicit(false);
                  ps.param = addParameter(ps.params, name, (yylsp[-2]));
                  addExpression(ps.param, "value",(yylsp[-1]),(yyvsp[-1]));
                  storeBannerAndRightComments(ps.param,(yylsp[-2]),(yylsp[-1]));
                  storePos(ps.param, (yylsp[-2]),(yylsp[0]));
                }
#line 2076 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 19:
#line 271 "ned1.y" /* yacc.c:1646  */
    {
                  const char *name = toString((yylsp[-2]));
                  if (strcmp(name,"error")==0) name = "ber"; // "error" got renamed to "ber" in 4.0
                  ps.params->setIsImplicit(false);
                  ps.param = addParameter(ps.params, name, (yylsp[-2]));
                  addExpression(ps.param, "value",(yylsp[-1]),(yyvsp[-1]));
                  storeBannerAndRightComments(ps.param,(yylsp[-2]),(yylsp[-1]));
                  storePos(ps.param, (yyloc));
                }
#line 2090 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 22:
#line 295 "ned1.y" /* yacc.c:1646  */
    {
                  storePos(ps.module, (yyloc));
                  storeTrailingComment(ps.module,(yyloc));
                }
#line 2099 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 23:
#line 303 "ned1.y" /* yacc.c:1646  */
    {
                  ps.module = (SimpleModuleElement *)createElementWithTag(NED_SIMPLE_MODULE, ps.nedfile );
                  ((SimpleModuleElement *)ps.module)->setName(toString((yylsp[0])));
                  storeBannerAndRightComments(ps.module,(yylsp[-1]),(yylsp[0]));
                }
#line 2109 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 26:
#line 326 "ned1.y" /* yacc.c:1646  */
    {
                  storePos(ps.module, (yyloc));
                  storeTrailingComment(ps.module,(yyloc));
                }
#line 2118 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 27:
#line 334 "ned1.y" /* yacc.c:1646  */
    {
                  ps.module = (CompoundModuleElement *)createElementWithTag(NED_COMPOUND_MODULE, ps.nedfile );
                  ((CompoundModuleElement *)ps.module)->setName(toString((yylsp[0])));
                  storeBannerAndRightComments(ps.module,(yylsp[-1]),(yylsp[0]));
                }
#line 2128 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 32:
#line 356 "ned1.y" /* yacc.c:1646  */
    {
                  ps.property = addComponentProperty(ps.module, "display");
                  ps.params = (ParametersElement *)ps.module->getFirstChildWithTag(NED_PARAMETERS); // previous line doesn't set it
                  ps.propkey = (PropertyKeyElement *)createElementWithTag(NED_PROPERTY_KEY, ps.property);
                  LiteralElement *literal = (LiteralElement *)createElementWithTag(NED_LITERAL);
                  literal->setType(NED_CONST_STRING);
                  try {
                      std::string displaystring = DisplayStringUtil::upgradeBackgroundDisplayString(opp_parsequotedstr(toString((yylsp[-1]))).c_str());
                      literal->setValue(displaystring.c_str());
                      // NOTE: no setText(): it would cause the OLD form to be exported into NED2 too
                  }
                  catch (std::exception& e) {
                      np->getErrors()->addError(ps.property, e.what());
                  }
                  ps.propkey->appendChild(literal);
                  storePos(ps.propkey, (yyloc));
                  storePos(literal, (yylsp[-1]));
                  storePos(ps.property, (yyloc));
                  storeBannerAndRightComments(ps.property,(yyloc));
                }
#line 2153 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 35:
#line 388 "ned1.y" /* yacc.c:1646  */
    {
                  ps.params = (ParametersElement *)getOrCreateElementWithTag(NED_PARAMETERS, ps.module); // network header may have created it for @isNetwork
                  storeBannerAndRightComments(ps.params,(yylsp[-1]),(yylsp[0]));
                }
#line 2162 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 36:
#line 393 "ned1.y" /* yacc.c:1646  */
    {
                  storePos(ps.params, (yyloc));
                }
#line 2170 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 39:
#line 405 "ned1.y" /* yacc.c:1646  */
    {
                  storePos(ps.param, (yylsp[0]));
                  storeBannerAndRightComments(ps.param,(yylsp[0]));
                }
#line 2179 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 40:
#line 410 "ned1.y" /* yacc.c:1646  */
    {
                  storePos(ps.param, (yylsp[0]));
                  storeBannerAndRightComments(ps.param,(yylsp[0]));
                }
#line 2188 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 41:
#line 421 "ned1.y" /* yacc.c:1646  */
    {
                  ps.param = addParameter(ps.params, (yylsp[0]));
                  ps.param->setType(NED_PARTYPE_DOUBLE);
                  ps.param->setIsVolatile(true); // because CONST is missing
                }
#line 2198 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 42:
#line 427 "ned1.y" /* yacc.c:1646  */
    {
                  ps.param = addParameter(ps.params, (yylsp[-2]));
                  ps.param->setType(NED_PARTYPE_DOUBLE);
                  ps.param->setIsVolatile(true); // because CONST is missing
                }
#line 2208 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 43:
#line 433 "ned1.y" /* yacc.c:1646  */
    {
                  ps.param = addParameter(ps.params, (yylsp[0]));
                  ps.param->setType(NED_PARTYPE_DOUBLE);
                }
#line 2217 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 44:
#line 438 "ned1.y" /* yacc.c:1646  */
    {
                  ps.param = addParameter(ps.params, (yylsp[-2]));
                  ps.param->setType(NED_PARTYPE_DOUBLE);
                }
#line 2226 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 45:
#line 443 "ned1.y" /* yacc.c:1646  */
    {
                  ps.param = addParameter(ps.params, (yylsp[-3]));
                  ps.param->setType(NED_PARTYPE_DOUBLE);
                }
#line 2235 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 46:
#line 448 "ned1.y" /* yacc.c:1646  */
    {
                  ps.param = addParameter(ps.params, (yylsp[-3]));
                  ps.param->setType(NED_PARTYPE_DOUBLE);
                }
#line 2244 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 47:
#line 453 "ned1.y" /* yacc.c:1646  */
    {
                  ps.param = addParameter(ps.params, (yylsp[-2]));
                  ps.param->setType(NED_PARTYPE_STRING);
                }
#line 2253 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 48:
#line 458 "ned1.y" /* yacc.c:1646  */
    {
                  ps.param = addParameter(ps.params, (yylsp[-2]));
                  ps.param->setType(NED_PARTYPE_BOOL);
                }
#line 2262 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 49:
#line 463 "ned1.y" /* yacc.c:1646  */
    {
                  ps.param = addParameter(ps.params, (yylsp[-2]));
                  ps.param->setType(NED_PARTYPE_XML);
                }
#line 2271 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 50:
#line 468 "ned1.y" /* yacc.c:1646  */
    {
                  np->getErrors()->addError(ps.params,"type 'anytype' no longer supported");
                  ps.param = addParameter(ps.params, (yylsp[-2])); // add anyway to prevent crash
                }
#line 2280 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 53:
#line 484 "ned1.y" /* yacc.c:1646  */
    {
                  ps.gates = (GatesElement *)createElementWithTag(NED_GATES, ps.module );
                  storeBannerAndRightComments(ps.gates,(yylsp[-1]),(yylsp[0]));
                }
#line 2289 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 54:
#line 489 "ned1.y" /* yacc.c:1646  */
    {
                  storePos(ps.gates, (yyloc));
                }
#line 2297 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 63:
#line 513 "ned1.y" /* yacc.c:1646  */
    {
                  ps.gate = addGate(ps.gates, (yylsp[-2]));
                  ps.gate->setType(NED_GATETYPE_INPUT);
                  ps.gate->setIsVector(true);
                  storeBannerAndRightComments(ps.gate,(yylsp[-2]),(yylsp[0]));
                  storePos(ps.gate, (yyloc));
                }
#line 2309 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 64:
#line 521 "ned1.y" /* yacc.c:1646  */
    {
                  ps.gate = addGate(ps.gates, (yylsp[0]));
                  ps.gate->setType(NED_GATETYPE_INPUT);
                  storeBannerAndRightComments(ps.gate,(yylsp[0]));
                  storePos(ps.gate, (yyloc));
                }
#line 2320 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 67:
#line 536 "ned1.y" /* yacc.c:1646  */
    {
                  ps.gate = addGate(ps.gates, (yylsp[-2]));
                  ps.gate->setType(NED_GATETYPE_OUTPUT);
                  ps.gate->setIsVector(true);
                  storeBannerAndRightComments(ps.gate,(yylsp[-2]),(yylsp[0]));
                  storePos(ps.gate, (yyloc));
                }
#line 2332 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 68:
#line 544 "ned1.y" /* yacc.c:1646  */
    {
                  ps.gate = addGate(ps.gates, (yylsp[0]));
                  ps.gate->setType(NED_GATETYPE_OUTPUT);
                  storeBannerAndRightComments(ps.gate,(yylsp[0]),(yylsp[0]));
                  storePos(ps.gate, (yyloc));
                }
#line 2343 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 71:
#line 562 "ned1.y" /* yacc.c:1646  */
    {
                  ps.submods = (SubmodulesElement *)createElementWithTag(NED_SUBMODULES, ps.module );
                  storeBannerAndRightComments(ps.submods,(yylsp[-1]),(yylsp[0]));
                }
#line 2352 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 72:
#line 567 "ned1.y" /* yacc.c:1646  */
    {
                  storePos(ps.submods, (yyloc));
                }
#line 2360 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 77:
#line 584 "ned1.y" /* yacc.c:1646  */
    {
                  ps.submod = (SubmoduleElement *)createElementWithTag(NED_SUBMODULE, ps.submods);
                  ps.submod->setName(toString((yylsp[-3])));
                  ps.submod->setType(toString((yylsp[-1])));
                  storeBannerAndRightComments(ps.submod,(yylsp[-3]),(yylsp[0]));
                }
#line 2371 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 78:
#line 591 "ned1.y" /* yacc.c:1646  */
    {
                  storePos(ps.submod, (yyloc));
                }
#line 2379 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 79:
#line 595 "ned1.y" /* yacc.c:1646  */
    {
                  ps.submod = (SubmoduleElement *)createElementWithTag(NED_SUBMODULE, ps.submods);
                  ps.submod->setName(toString((yylsp[-4])));
                  ps.submod->setType(toString((yylsp[-2])));
                  addExpression(ps.submod, "vector-size",ps.exprPos,(yyvsp[-1]));
                  storeBannerAndRightComments(ps.submod,(yylsp[-4]),(yylsp[0]));
                }
#line 2391 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 80:
#line 603 "ned1.y" /* yacc.c:1646  */
    {
                  storePos(ps.submod, (yyloc));
                }
#line 2399 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 81:
#line 607 "ned1.y" /* yacc.c:1646  */
    {
                  ps.submod = (SubmoduleElement *)createElementWithTag(NED_SUBMODULE, ps.submods);
                  ps.submod->setName(toString((yylsp[-5])));
                  ps.submod->setLikeType(toString((yylsp[-1])));
                  ps.submod->setLikeExpr(toString((yylsp[-3]))); //TODO store as expression
                  storeBannerAndRightComments(ps.submod,(yylsp[-5]),(yylsp[0]));
                }
#line 2411 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 82:
#line 615 "ned1.y" /* yacc.c:1646  */
    {
                  storePos(ps.submod, (yyloc));
                }
#line 2419 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 83:
#line 619 "ned1.y" /* yacc.c:1646  */
    {
                  ps.submod = (SubmoduleElement *)createElementWithTag(NED_SUBMODULE, ps.submods);
                  ps.submod->setName(toString((yylsp[-6])));
                  ps.submod->setLikeType(toString((yylsp[-1])));
                  ps.submod->setLikeExpr(toString((yylsp[-4]))); //TODO store as expression
                  addExpression(ps.submod, "vector-size",ps.exprPos,(yyvsp[-3]));
                  storeBannerAndRightComments(ps.submod,(yylsp[-6]),(yylsp[0]));
                }
#line 2432 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 84:
#line 628 "ned1.y" /* yacc.c:1646  */
    {
                  storePos(ps.submod, (yyloc));
                }
#line 2440 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 86:
#line 644 "ned1.y" /* yacc.c:1646  */
    { storePos(ps.substparams, (yyloc)); /*must do it here because there might be multiple (conditional) gatesizes/parameters sections */ }
#line 2446 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 90:
#line 655 "ned1.y" /* yacc.c:1646  */
    {
                  createSubstparamsElementIfNotExists();
                  storeBannerAndRightComments(ps.substparams,(yylsp[-1]),(yylsp[0]));
                }
#line 2455 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 92:
#line 661 "ned1.y" /* yacc.c:1646  */
    {
                  createSubstparamsElementIfNotExists();
                  delete (yyvsp[-1]);
                  np->getErrors()->addError(ps.substparams,
                                    "conditional parameters no longer supported -- "
                                    "please rewrite parameter assignments to use "
                                    "conditional expression syntax (cond ? a : b)");
                }
#line 2468 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 98:
#line 684 "ned1.y" /* yacc.c:1646  */
    {
                  ps.substparam = addParameter(ps.substparams,(yylsp[-2]));
                  addExpression(ps.substparam, "value",(yylsp[0]),(yyvsp[0]));
                  storeBannerAndRightComments(ps.substparam,(yylsp[-2]),(yylsp[0]));
                  storePos(ps.substparam, (yyloc));
                }
#line 2479 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 99:
#line 691 "ned1.y" /* yacc.c:1646  */
    {
                  ps.substparam = addParameter(ps.substparams,(yylsp[-2]));
                  ps.substparam->setIsDefault(true);
                }
#line 2488 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 100:
#line 696 "ned1.y" /* yacc.c:1646  */
    {
                  storeBannerAndRightComments(ps.substparam,(yylsp[-4]),(yylsp[0]));
                  storePos(ps.substparam, (yyloc));
                }
#line 2497 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 101:
#line 704 "ned1.y" /* yacc.c:1646  */
    {
                  addExpression(ps.substparam, "value",(yylsp[-3]),(yyvsp[-3]));

                  PropertyElement *prop = addProperty(ps.substparam, "prompt");
                  PropertyKeyElement *propkey = (PropertyKeyElement *)createElementWithTag(NED_PROPERTY_KEY, prop);
                  propkey->appendChild(createStringLiteral((yylsp[-1])));
                }
#line 2509 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 102:
#line 712 "ned1.y" /* yacc.c:1646  */
    {
                  addExpression(ps.substparam, "value",(yylsp[-1]),(yyvsp[-1]));
                }
#line 2517 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 105:
#line 724 "ned1.y" /* yacc.c:1646  */
    { storePos(ps.gatesizes, (yyloc)); /*must do it here because there might be multiple (conditional) gatesizes/parameters sections */ }
#line 2523 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 109:
#line 735 "ned1.y" /* yacc.c:1646  */
    {
                  createGatesizesElementIfNotExists();
                  storeBannerAndRightComments(ps.gatesizes,(yylsp[-1]),(yylsp[0]));
                }
#line 2532 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 111:
#line 741 "ned1.y" /* yacc.c:1646  */
    {
                  createSubstparamsElementIfNotExists();
                  delete (yyvsp[-1]);
                  np->getErrors()->addError(ps.substparams,
                                    "conditional gatesizes no longer supported -- "
                                    "please rewrite gatesize assignments to use "
                                    "conditional expression syntax (cond ? a : b)");
                }
#line 2545 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 117:
#line 764 "ned1.y" /* yacc.c:1646  */
    {
                  ps.gatesize = addGate(ps.gatesizes,(yylsp[-1]));
                  ps.gatesize->setIsVector(true);
                  addExpression(ps.gatesize, "vector-size",ps.exprPos,(yyvsp[0]));
                  storeBannerAndRightComments(ps.gatesize,(yylsp[-1]),(yylsp[0]));
                  storePos(ps.gatesize, (yyloc));
                }
#line 2557 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 118:
#line 778 "ned1.y" /* yacc.c:1646  */
    {
                  ps.property = addComponentProperty(ps.submod, "display");
                  ps.substparams = (ParametersElement *)ps.submod->getFirstChildWithTag(NED_PARAMETERS); // previous line doesn't set it
                  ps.propkey = (PropertyKeyElement *)createElementWithTag(NED_PROPERTY_KEY, ps.property);
                  LiteralElement *literal = (LiteralElement *)createElementWithTag(NED_LITERAL);
                  literal->setType(NED_CONST_STRING);
                  try {
                      std::string displaystring = DisplayStringUtil::upgradeSubmoduleDisplayString(opp_parsequotedstr(toString((yylsp[-1]))).c_str());
                      literal->setValue(displaystring.c_str());
                      // NOTE: no setText(): it would cause the OLD form to be exported into NED2 too
                  }
                  catch (std::exception& e) {
                      np->getErrors()->addError(ps.property, e.what());
                  }
                  ps.propkey->appendChild(literal);
                  storePos(ps.propkey, (yyloc));
                  storePos(literal, (yylsp[-1]));
                  storePos(ps.property, (yyloc));
                  storeBannerAndRightComments(ps.property,(yyloc));
                }
#line 2582 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 122:
#line 811 "ned1.y" /* yacc.c:1646  */
    {
                  ps.conns = (ConnectionsElement *)createElementWithTag(NED_CONNECTIONS, ps.module );
                  ps.conns->setAllowUnconnected(true);
                  storeBannerAndRightComments(ps.conns,(yylsp[-2]),(yylsp[0]));
                }
#line 2592 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 123:
#line 817 "ned1.y" /* yacc.c:1646  */
    {
                  storePos(ps.conns, (yyloc));
                }
#line 2600 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 124:
#line 821 "ned1.y" /* yacc.c:1646  */
    {
                  ps.conns = (ConnectionsElement *)createElementWithTag(NED_CONNECTIONS, ps.module );
                  ps.conns->setAllowUnconnected(false);
                  storeBannerAndRightComments(ps.conns,(yylsp[-1]),(yylsp[0]));
                }
#line 2610 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 125:
#line 827 "ned1.y" /* yacc.c:1646  */
    {
                  storePos(ps.conns, (yyloc));
                }
#line 2618 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 132:
#line 849 "ned1.y" /* yacc.c:1646  */
    {
                  ps.conngroup = (ConnectionGroupElement *)createElementWithTag(NED_CONNECTION_GROUP, ps.conns);
                  ps.inLoop=1;
                }
#line 2627 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 133:
#line 854 "ned1.y" /* yacc.c:1646  */
    {
                  ps.inLoop=0;
                  storePos(ps.conngroup, (yyloc));
                  storeBannerAndRightComments(ps.conngroup,(yylsp[-6]),(yylsp[-3])); // "for..do"
                  storeTrailingComment(ps.conngroup,(yyloc));
                }
#line 2638 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 136:
#line 869 "ned1.y" /* yacc.c:1646  */
    {
                  ps.loop = (LoopElement *)createElementWithTag(NED_LOOP, ps.conngroup);
                  ps.loop->setParamName( toString((yylsp[-4])) );
                  addExpression(ps.loop, "from-value",(yylsp[-2]),(yyvsp[-2]));
                  addExpression(ps.loop, "to-value",(yylsp[0]),(yyvsp[0]));
                  storePos(ps.loop, (yyloc));
                }
#line 2650 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 137:
#line 880 "ned1.y" /* yacc.c:1646  */
    {
                  // add condition to conn
                  ps.condition = (ConditionElement *)createElementWithTag(NED_CONDITION, ps.conn);
                  addExpression(ps.condition, "condition",(yylsp[0]),(yyvsp[0]));
                  storePos(ps.condition, (yyloc));
                }
#line 2661 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 139:
#line 891 "ned1.y" /* yacc.c:1646  */
    {
                  ps.property = addComponentProperty(ps.conn, "display");
                  ps.propkey = (PropertyKeyElement *)createElementWithTag(NED_PROPERTY_KEY, ps.property);
                  LiteralElement *literal = (LiteralElement *)createElementWithTag(NED_LITERAL);
                  literal->setType(NED_CONST_STRING);
                  try {
                      std::string displaystring = DisplayStringUtil::upgradeConnectionDisplayString(opp_parsequotedstr(toString((yylsp[0]))).c_str());
                      literal->setValue(displaystring.c_str());
                  }
                  catch (std::exception& e) {
                      np->getErrors()->addError(ps.property, e.what());
                  }
                  // NOTE: no setText(): it would cause the OLD form to be exported into NED2 too
                  ps.propkey->appendChild(literal);
                  storePos(ps.propkey, (yyloc));
                  storePos(literal, (yylsp[0]));
                  storePos(ps.property, (yyloc));
                }
#line 2684 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 143:
#line 919 "ned1.y" /* yacc.c:1646  */
    {
                  ps.conn->setIsBidirectional(false);
                  ps.conn->setIsForwardArrow(true);
                  storeBannerAndRightComments(ps.conn,(yyloc));
                  storePos(ps.conn, (yyloc));
                }
#line 2695 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 144:
#line 926 "ned1.y" /* yacc.c:1646  */
    {
                  ps.conn->setIsBidirectional(false);
                  ps.conn->setIsForwardArrow(true);
                  removeRedundantConnectionParams();
                  storeBannerAndRightComments(ps.conn,(yyloc));
                  storePos(ps.conn, (yyloc));
                }
#line 2707 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 145:
#line 934 "ned1.y" /* yacc.c:1646  */
    {
                  swapConnection(ps.conn);
                  ps.conn->setIsBidirectional(false);
                  ps.conn->setIsForwardArrow(false);
                  storeBannerAndRightComments(ps.conn,(yyloc));
                  storePos(ps.conn, (yyloc));
                }
#line 2719 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 146:
#line 942 "ned1.y" /* yacc.c:1646  */
    {
                  swapConnection(ps.conn);
                  ps.conn->setIsBidirectional(false);
                  ps.conn->setIsForwardArrow(false);
                  removeRedundantConnectionParams();
                  storeBannerAndRightComments(ps.conn,(yyloc));
                  storePos(ps.conn, (yyloc));
                }
#line 2732 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 149:
#line 959 "ned1.y" /* yacc.c:1646  */
    {
                  ps.conn = (ConnectionElement *)createElementWithTag(NED_CONNECTION, ps.inLoop ? (NEDElement *)ps.conngroup : (NEDElement*)ps.conns );
                  ps.params = (ParametersElement *)createElementWithTag(NED_PARAMETERS, ps.conn);
                  ps.params->setIsImplicit(true);
                  ps.conn->setSrcModule( toString((yylsp[-1])) );
                  addExpression(ps.conn, "src-module-index",ps.exprPos,(yyvsp[0]));
                }
#line 2744 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 150:
#line 967 "ned1.y" /* yacc.c:1646  */
    {
                  ps.conn = (ConnectionElement *)createElementWithTag(NED_CONNECTION, ps.inLoop ? (NEDElement *)ps.conngroup : (NEDElement*)ps.conns );
                  ps.params = (ParametersElement *)createElementWithTag(NED_PARAMETERS, ps.conn);
                  ps.params->setIsImplicit(true);
                  ps.conn->setSrcModule( toString((yylsp[0])) );
                }
#line 2755 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 151:
#line 977 "ned1.y" /* yacc.c:1646  */
    {
                  ps.conn->setSrcGate( toString( (yylsp[-1])) );
                  addExpression(ps.conn, "src-gate-index",ps.exprPos,(yyvsp[0]));
                }
#line 2764 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 152:
#line 982 "ned1.y" /* yacc.c:1646  */
    {
                  ps.conn->setSrcGate( toString( (yylsp[0])) );
                }
#line 2772 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 153:
#line 986 "ned1.y" /* yacc.c:1646  */
    {
                  ps.conn->setSrcGate( toString( (yylsp[-1])) );
                  ps.conn->setSrcGatePlusplus(true);
                }
#line 2781 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 154:
#line 994 "ned1.y" /* yacc.c:1646  */
    {
                  ps.conn = (ConnectionElement *)createElementWithTag(NED_CONNECTION, ps.inLoop ? (NEDElement *)ps.conngroup : (NEDElement*)ps.conns );
                  ps.params = (ParametersElement *)createElementWithTag(NED_PARAMETERS, ps.conn);
                  ps.params->setIsImplicit(true);
                  ps.conn->setSrcModule("");
                  ps.conn->setSrcGate(toString((yylsp[-1])));
                  addExpression(ps.conn, "src-gate-index",ps.exprPos,(yyvsp[0]));
                }
#line 2794 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 155:
#line 1003 "ned1.y" /* yacc.c:1646  */
    {
                  ps.conn = (ConnectionElement *)createElementWithTag(NED_CONNECTION, ps.inLoop ? (NEDElement *)ps.conngroup : (NEDElement*)ps.conns );
                  ps.params = (ParametersElement *)createElementWithTag(NED_PARAMETERS, ps.conn);
                  ps.params->setIsImplicit(true);
                  ps.conn->setSrcModule("");
                  ps.conn->setSrcGate(toString((yylsp[0])));
                }
#line 2806 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 156:
#line 1011 "ned1.y" /* yacc.c:1646  */
    {
                  ps.conn = (ConnectionElement *)createElementWithTag(NED_CONNECTION, ps.inLoop ? (NEDElement *)ps.conngroup : (NEDElement*)ps.conns );
                  ps.params = (ParametersElement *)createElementWithTag(NED_PARAMETERS, ps.conn);
                  ps.params->setIsImplicit(true);
                  ps.conn->setSrcModule("");
                  ps.conn->setSrcGate(toString((yylsp[-1])));
                  ps.conn->setSrcGatePlusplus(true);
                }
#line 2819 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 159:
#line 1028 "ned1.y" /* yacc.c:1646  */
    {
                  ps.conn->setDestModule( toString((yylsp[-1])) );
                  addExpression(ps.conn, "dest-module-index",ps.exprPos,(yyvsp[0]));
                }
#line 2828 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 160:
#line 1033 "ned1.y" /* yacc.c:1646  */
    {
                  ps.conn->setDestModule( toString((yylsp[0])) );
                }
#line 2836 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 161:
#line 1040 "ned1.y" /* yacc.c:1646  */
    {
                  ps.conn->setDestGate( toString( (yylsp[-1])) );
                  addExpression(ps.conn, "dest-gate-index",ps.exprPos,(yyvsp[0]));
                }
#line 2845 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 162:
#line 1045 "ned1.y" /* yacc.c:1646  */
    {
                  ps.conn->setDestGate( toString( (yylsp[0])) );
                }
#line 2853 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 163:
#line 1049 "ned1.y" /* yacc.c:1646  */
    {
                  ps.conn->setDestGate( toString( (yylsp[-1])) );
                  ps.conn->setDestGatePlusplus(true);
                }
#line 2862 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 164:
#line 1057 "ned1.y" /* yacc.c:1646  */
    {
                  ps.conn->setDestGate( toString( (yylsp[-1])) );
                  addExpression(ps.conn, "dest-gate-index",ps.exprPos,(yyvsp[0]));
                }
#line 2871 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 165:
#line 1062 "ned1.y" /* yacc.c:1646  */
    {
                  ps.conn->setDestGate( toString( (yylsp[0])) );
                }
#line 2879 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 166:
#line 1066 "ned1.y" /* yacc.c:1646  */
    {
                  ps.conn->setDestGate( toString( (yylsp[-1])) );
                  ps.conn->setDestGatePlusplus(true);
                }
#line 2888 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 167:
#line 1075 "ned1.y" /* yacc.c:1646  */
    {
                  if (ps.conn->getFirstChildWithTag(NED_PARAMETERS)!=NULL)
                      storePos(ps.params, (yyloc));
                }
#line 2897 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 168:
#line 1083 "ned1.y" /* yacc.c:1646  */
    {
                  ps.conn->setType(toString((yylsp[0])));
                }
#line 2905 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 171:
#line 1092 "ned1.y" /* yacc.c:1646  */
    {
                  ps.param = addParameter(ps.params, (yylsp[-1]));
                  addExpression(ps.param, "value",(yylsp[0]),(yyvsp[0]));
                  storePos(ps.param, (yyloc));
                }
#line 2915 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 172:
#line 1106 "ned1.y" /* yacc.c:1646  */
    {
                  storePos(ps.module, (yyloc));
                  storeTrailingComment(ps.module,(yyloc));
                }
#line 2924 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 173:
#line 1114 "ned1.y" /* yacc.c:1646  */
    {
                  ps.module = (CompoundModuleElement *)createElementWithTag(NED_COMPOUND_MODULE, ps.nedfile );
                  ((CompoundModuleElement *)ps.module)->setName(toString((yylsp[-3])));
                  ps.extends = (ExtendsElement *)createElementWithTag(NED_EXTENDS, ps.module);
                  ps.extends->setName(toString((yylsp[-1])));
                  storeBannerAndRightComments(ps.module,(yylsp[-4]),(yylsp[0]));
                  storePos(ps.extends, (yylsp[-1]));
                  setIsNetworkProperty(ps.module);
                  ps.inNetwork=1;
                }
#line 2939 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 174:
#line 1128 "ned1.y" /* yacc.c:1646  */
    {
                  ps.inNetwork=0;
                }
#line 2947 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 175:
#line 1138 "ned1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); ps.exprPos = (yylsp[-1]); }
#line 2953 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 176:
#line 1144 "ned1.y" /* yacc.c:1646  */
    {
                  if (np->getParseExpressionsFlag()) (yyval) = createExpression((yyvsp[0]));
                }
#line 2961 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 177:
#line 1148 "ned1.y" /* yacc.c:1646  */
    {
                  if (np->getParseExpressionsFlag()) (yyval) = createExpression((yyvsp[0]));
                }
#line 2969 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 178:
#line 1159 "ned1.y" /* yacc.c:1646  */
    { if (np->getParseExpressionsFlag()) (yyval) = createFunction("xmldoc", (yyvsp[-3]), (yyvsp[-1])); }
#line 2975 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 179:
#line 1161 "ned1.y" /* yacc.c:1646  */
    { if (np->getParseExpressionsFlag()) (yyval) = createFunction("xmldoc", (yyvsp[-1])); }
#line 2981 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 181:
#line 1167 "ned1.y" /* yacc.c:1646  */
    { (yyval) = (yyvsp[-1]); }
#line 2987 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 182:
#line 1170 "ned1.y" /* yacc.c:1646  */
    { if (np->getParseExpressionsFlag()) (yyval) = createOperator("+", (yyvsp[-2]), (yyvsp[0])); }
#line 2993 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 183:
#line 1172 "ned1.y" /* yacc.c:1646  */
    { if (np->getParseExpressionsFlag()) (yyval) = createOperator("-", (yyvsp[-2]), (yyvsp[0])); }
#line 2999 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 184:
#line 1174 "ned1.y" /* yacc.c:1646  */
    { if (np->getParseExpressionsFlag()) (yyval) = createOperator("*", (yyvsp[-2]), (yyvsp[0])); }
#line 3005 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 185:
#line 1176 "ned1.y" /* yacc.c:1646  */
    { if (np->getParseExpressionsFlag()) (yyval) = createOperator("/", (yyvsp[-2]), (yyvsp[0])); }
#line 3011 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 186:
#line 1178 "ned1.y" /* yacc.c:1646  */
    { if (np->getParseExpressionsFlag()) (yyval) = createOperator("%", (yyvsp[-2]), (yyvsp[0])); }
#line 3017 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 187:
#line 1180 "ned1.y" /* yacc.c:1646  */
    { if (np->getParseExpressionsFlag()) (yyval) = createOperator("^", (yyvsp[-2]), (yyvsp[0])); }
#line 3023 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 188:
#line 1184 "ned1.y" /* yacc.c:1646  */
    { if (np->getParseExpressionsFlag()) (yyval) = unaryMinus((yyvsp[0])); }
#line 3029 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 189:
#line 1187 "ned1.y" /* yacc.c:1646  */
    { if (np->getParseExpressionsFlag()) (yyval) = createOperator("==", (yyvsp[-2]), (yyvsp[0])); }
#line 3035 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 190:
#line 1189 "ned1.y" /* yacc.c:1646  */
    { if (np->getParseExpressionsFlag()) (yyval) = createOperator("!=", (yyvsp[-2]), (yyvsp[0])); }
#line 3041 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 191:
#line 1191 "ned1.y" /* yacc.c:1646  */
    { if (np->getParseExpressionsFlag()) (yyval) = createOperator(">", (yyvsp[-2]), (yyvsp[0])); }
#line 3047 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 192:
#line 1193 "ned1.y" /* yacc.c:1646  */
    { if (np->getParseExpressionsFlag()) (yyval) = createOperator(">=", (yyvsp[-2]), (yyvsp[0])); }
#line 3053 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 193:
#line 1195 "ned1.y" /* yacc.c:1646  */
    { if (np->getParseExpressionsFlag()) (yyval) = createOperator("<", (yyvsp[-2]), (yyvsp[0])); }
#line 3059 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 194:
#line 1197 "ned1.y" /* yacc.c:1646  */
    { if (np->getParseExpressionsFlag()) (yyval) = createOperator("<=", (yyvsp[-2]), (yyvsp[0])); }
#line 3065 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 195:
#line 1200 "ned1.y" /* yacc.c:1646  */
    { if (np->getParseExpressionsFlag()) (yyval) = createOperator("&&", (yyvsp[-2]), (yyvsp[0])); }
#line 3071 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 196:
#line 1202 "ned1.y" /* yacc.c:1646  */
    { if (np->getParseExpressionsFlag()) (yyval) = createOperator("||", (yyvsp[-2]), (yyvsp[0])); }
#line 3077 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 197:
#line 1204 "ned1.y" /* yacc.c:1646  */
    { if (np->getParseExpressionsFlag()) (yyval) = createOperator("##", (yyvsp[-2]), (yyvsp[0])); }
#line 3083 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 198:
#line 1208 "ned1.y" /* yacc.c:1646  */
    { if (np->getParseExpressionsFlag()) (yyval) = createOperator("!", (yyvsp[0])); }
#line 3089 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 199:
#line 1211 "ned1.y" /* yacc.c:1646  */
    { if (np->getParseExpressionsFlag()) (yyval) = createOperator("&", (yyvsp[-2]), (yyvsp[0])); }
#line 3095 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 200:
#line 1213 "ned1.y" /* yacc.c:1646  */
    { if (np->getParseExpressionsFlag()) (yyval) = createOperator("|", (yyvsp[-2]), (yyvsp[0])); }
#line 3101 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 201:
#line 1215 "ned1.y" /* yacc.c:1646  */
    { if (np->getParseExpressionsFlag()) (yyval) = createOperator("#", (yyvsp[-2]), (yyvsp[0])); }
#line 3107 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 202:
#line 1219 "ned1.y" /* yacc.c:1646  */
    { if (np->getParseExpressionsFlag()) (yyval) = createOperator("~", (yyvsp[0])); }
#line 3113 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 203:
#line 1221 "ned1.y" /* yacc.c:1646  */
    { if (np->getParseExpressionsFlag()) (yyval) = createOperator("<<", (yyvsp[-2]), (yyvsp[0])); }
#line 3119 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 204:
#line 1223 "ned1.y" /* yacc.c:1646  */
    { if (np->getParseExpressionsFlag()) (yyval) = createOperator(">>", (yyvsp[-2]), (yyvsp[0])); }
#line 3125 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 205:
#line 1225 "ned1.y" /* yacc.c:1646  */
    { if (np->getParseExpressionsFlag()) (yyval) = createOperator("?:", (yyvsp[-4]), (yyvsp[-2]), (yyvsp[0])); }
#line 3131 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 206:
#line 1228 "ned1.y" /* yacc.c:1646  */
    { if (np->getParseExpressionsFlag()) (yyval) = createFunction(toString((yylsp[-3])), (yyvsp[-1])); }
#line 3137 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 207:
#line 1230 "ned1.y" /* yacc.c:1646  */
    { if (np->getParseExpressionsFlag()) (yyval) = createFunction(toString((yylsp[-3])), (yyvsp[-1])); }
#line 3143 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 208:
#line 1232 "ned1.y" /* yacc.c:1646  */
    { if (np->getParseExpressionsFlag()) (yyval) = createFunction(toString((yylsp[-3])), (yyvsp[-1])); }
#line 3149 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 209:
#line 1235 "ned1.y" /* yacc.c:1646  */
    { if (np->getParseExpressionsFlag()) (yyval) = createFunction(toString((yylsp[-2]))); }
#line 3155 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 210:
#line 1237 "ned1.y" /* yacc.c:1646  */
    { if (np->getParseExpressionsFlag()) (yyval) = createFunction(toString((yylsp[-3])), (yyvsp[-1])); }
#line 3161 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 211:
#line 1239 "ned1.y" /* yacc.c:1646  */
    { if (np->getParseExpressionsFlag()) (yyval) = createFunction(toString((yylsp[-5])), (yyvsp[-3]), (yyvsp[-1])); }
#line 3167 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 212:
#line 1241 "ned1.y" /* yacc.c:1646  */
    { if (np->getParseExpressionsFlag()) (yyval) = createFunction(toString((yylsp[-7])), (yyvsp[-5]), (yyvsp[-3]), (yyvsp[-1])); }
#line 3173 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 213:
#line 1243 "ned1.y" /* yacc.c:1646  */
    { if (np->getParseExpressionsFlag()) (yyval) = createFunction(toString((yylsp[-9])), (yyvsp[-7]), (yyvsp[-5]), (yyvsp[-3]), (yyvsp[-1])); }
#line 3179 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 217:
#line 1254 "ned1.y" /* yacc.c:1646  */
    {
                  // if there's no modifier, might be a loop variable too
                  if (np->getParseExpressionsFlag()) (yyval) = createIdent((yylsp[0]));
                }
#line 3188 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 218:
#line 1259 "ned1.y" /* yacc.c:1646  */
    {
                  if (np->getParseExpressionsFlag()) (yyval) = createIdent((yylsp[0]));
                  np->getErrors()->addError(ps.substparams,"`ref' modifier no longer supported (add `volatile' modifier to destination parameter instead)");
                }
#line 3197 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 219:
#line 1264 "ned1.y" /* yacc.c:1646  */
    {
                  if (np->getParseExpressionsFlag()) (yyval) = createIdent((yylsp[0]));
                  np->getErrors()->addError(ps.substparams,"`ancestor' and `ref' modifiers no longer supported");
                }
#line 3206 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 220:
#line 1269 "ned1.y" /* yacc.c:1646  */
    {
                  if (np->getParseExpressionsFlag()) (yyval) = createIdent((yylsp[0]));
                  np->getErrors()->addError(ps.substparams,"`ancestor' and `ref' modifiers no longer supported");
                }
#line 3215 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 221:
#line 1274 "ned1.y" /* yacc.c:1646  */
    {
                  if (np->getParseExpressionsFlag()) (yyval) = createIdent((yylsp[0]));
                  np->getErrors()->addError(ps.substparams,"`ancestor' modifier no longer supported");
                }
#line 3224 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 222:
#line 1282 "ned1.y" /* yacc.c:1646  */
    { if (np->getParseExpressionsFlag()) (yyval) = createFunction("index"); }
#line 3230 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 223:
#line 1284 "ned1.y" /* yacc.c:1646  */
    { if (np->getParseExpressionsFlag()) (yyval) = createFunction("index"); }
#line 3236 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 224:
#line 1286 "ned1.y" /* yacc.c:1646  */
    { if (np->getParseExpressionsFlag()) (yyval) = createFunction("sizeof", createIdent((yylsp[-1]))); }
#line 3242 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 228:
#line 1297 "ned1.y" /* yacc.c:1646  */
    { if (np->getParseExpressionsFlag()) (yyval) = createStringLiteral((yylsp[0])); }
#line 3248 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 229:
#line 1302 "ned1.y" /* yacc.c:1646  */
    { if (np->getParseExpressionsFlag()) (yyval) = createLiteral(NED_CONST_BOOL, (yylsp[0]), (yylsp[0])); }
#line 3254 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 230:
#line 1304 "ned1.y" /* yacc.c:1646  */
    { if (np->getParseExpressionsFlag()) (yyval) = createLiteral(NED_CONST_BOOL, (yylsp[0]), (yylsp[0])); }
#line 3260 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 231:
#line 1309 "ned1.y" /* yacc.c:1646  */
    { if (np->getParseExpressionsFlag()) (yyval) = createLiteral(NED_CONST_INT, (yylsp[0]), (yylsp[0])); }
#line 3266 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 232:
#line 1311 "ned1.y" /* yacc.c:1646  */
    { if (np->getParseExpressionsFlag()) (yyval) = createLiteral(NED_CONST_DOUBLE, (yylsp[0]), (yylsp[0])); }
#line 3272 "ned1.tab.cc" /* yacc.c:1646  */
    break;

  case 233:
#line 1313 "ned1.y" /* yacc.c:1646  */
    { if (np->getParseExpressionsFlag()) (yyval) = createQuantityLiteral((yylsp[0])); }
#line 3278 "ned1.tab.cc" /* yacc.c:1646  */
    break;


#line 3282 "ned1.tab.cc" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
#line 1327 "ned1.y" /* yacc.c:1906  */


//----------------------------------------------------------------------
// general bison/flex stuff:
//
int ned1yylex_destroy();  // from lex.XXX.cc file

NEDElement *doParseNED1(NEDParser *p, const char *nedtext)
{
#if YYDEBUG != 0      /* #if added --VA */
    yydebug = YYDEBUGGING_ON;
#endif

    ned1yylex_destroy();

    NONREENTRANT_NED_PARSER(p);

    // reset the lexer
    pos.co = 0;
    pos.li = 1;
    prevpos = pos;

    yyin = NULL;
    yyout = stderr; // not used anyway

    // alloc buffer
    struct yy_buffer_state *handle = yy_scan_string(nedtext);
    if (!handle)
        {np->getErrors()->addError("", "unable to allocate work memory"); return NULL;}

    // create parser state and NEDFileElement
    resetParserState();
    ps.nedfile = new NedFileElement();

    // store file name with slashes always, even on Windows -- neddoc relies on that
    ps.nedfile->setFilename(slashifyFilename(np->getFileName()).c_str());
    ps.nedfile->setVersion("1");

    // store file comment
    storeFileComment(ps.nedfile);

    if (np->getStoreSourceFlag())
        storeSourceCode(ps.nedfile, np->getSource()->getFullTextPos());

    // parse
    try
    {
        yyparse();
    }
    catch (NEDException& e)
    {
        yyerror((std::string("error during parsing: ")+e.what()).c_str());
        yy_delete_buffer(handle);
        return NULL;
    }

    yy_delete_buffer(handle);

    //FIXME TODO: fill in @documentation properties from comments
    return ps.nedfile;
}

void yyerror(const char *s)
{
    // chop newline
    char buf[250];
    strcpy(buf, s);
    if (buf[strlen(buf)-1] == '\n')
        buf[strlen(buf)-1] = '\0';

    np->error(buf, pos.li);
}

void createSubstparamsElementIfNotExists()
{
   // check if already exists (multiple blocks must be merged)
   NEDElement *parent = ps.inNetwork ? (NEDElement *)ps.module : (NEDElement *)ps.submod;
   ps.substparams = (ParametersElement *)parent->getFirstChildWithTag(NED_PARAMETERS);
   if (!ps.substparams)
       ps.substparams = (ParametersElement *)createElementWithTag(NED_PARAMETERS, parent);
}

void createGatesizesElementIfNotExists()
{
   // check if already exists (multiple blocks must be merged)
   ps.gatesizes = (GatesElement *)ps.submod->getFirstChildWithTag(NED_GATES);
   if (!ps.gatesizes)
       ps.gatesizes = (GatesElement *)createElementWithTag(NED_GATES, ps.submod);
}

void removeRedundantConnectionParams()
{
    if (!ps.params->getFirstChild())
        delete ps.conn->removeChild(ps.params);
}

