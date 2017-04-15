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




/* Copy the first part of user declarations.  */
#line 1 "abstree.y" /* yacc.c:339  */
 
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "abstree.h"
    #include "symboltable.h"
    #include "symboltable.c"
    #include "aa.c"
    #include "codegen.c"
    #include "userdtype.c"
    #include "typecheck.h"
    #include "typecheck.c"

    int yylex();
    void yyerror(char const *s);
    struct ASTNode *head1,*head;
    int result;
    FILE * fp;
    extern FILE *yyin;
    extern int yylineno;
    struct Fieldlist *ftemp;
    struct Typetable *declarationType ,*FdeclarationType,*functype,*temp1,*temp2;
    struct Classtable *CdeclarationType;
	struct CFunclist *cftemp1;
    struct CVarlist *cvtemp;

    struct Gsymbol *Gtemp;
    struct Lsymbol *Ltemp;
    struct Paramstruct *Argtemp1, *Argtemp2;
    int indicator = 0; //for no.of arguments passed
    int declcount = 0,defcount = 0,exprcount = 0;
    int init_counter=0, f_counter=0;	//to check whether initialize is called or not.
    int is_classdef = 0,is_classtype=0,wr=0;
    union Constant cindicator; //number of arguments for class function calls

#line 102 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    NUM = 258,
    ID = 259,
    PLUS = 260,
    MUL = 261,
    DIV = 262,
    MOD = 263,
    ASGN = 264,
    READ = 265,
    WRITE = 266,
    MINUS = 267,
    NEWLINE = 268,
    LT = 269,
    GT = 270,
    DEQ = 271,
    NEQ = 272,
    ELSE = 273,
    IF = 274,
    THEN = 275,
    ENDIF = 276,
    ENDWHILE = 277,
    WHILE = 278,
    DO = 279,
    START = 280,
    END = 281,
    DECL = 282,
    ENDDECL = 283,
    INT = 284,
    STR = 285,
    LE = 286,
    GE = 287,
    NOT = 288,
    AND = 289,
    OR = 290,
    MAIN = 291,
    RETURN = 292,
    ALLOC = 293,
    FREE = 294,
    INIT = 295,
    BRK = 296,
    CONTINUE = 297,
    BRKP = 298,
    TYPE = 299,
    ENDTYPE = 300,
    NILL = 301,
    DEQNILL = 302,
    NEQNILL = 303,
    STRVAL = 304,
    CLASS = 305,
    ENDCLASS = 306,
    EXTENDS = 307,
    NEW = 308,
    THIS = 309
  };
#endif
/* Tokens.  */
#define NUM 258
#define ID 259
#define PLUS 260
#define MUL 261
#define DIV 262
#define MOD 263
#define ASGN 264
#define READ 265
#define WRITE 266
#define MINUS 267
#define NEWLINE 268
#define LT 269
#define GT 270
#define DEQ 271
#define NEQ 272
#define ELSE 273
#define IF 274
#define THEN 275
#define ENDIF 276
#define ENDWHILE 277
#define WHILE 278
#define DO 279
#define START 280
#define END 281
#define DECL 282
#define ENDDECL 283
#define INT 284
#define STR 285
#define LE 286
#define GE 287
#define NOT 288
#define AND 289
#define OR 290
#define MAIN 291
#define RETURN 292
#define ALLOC 293
#define FREE 294
#define INIT 295
#define BRK 296
#define CONTINUE 297
#define BRKP 298
#define TYPE 299
#define ENDTYPE 300
#define NILL 301
#define DEQNILL 302
#define NEQNILL 303
#define STRVAL 304
#define CLASS 305
#define ENDCLASS 306
#define EXTENDS 307
#define NEW 308
#define THIS 309

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 38 "abstree.y" /* yacc.c:355  */

    struct ASTNode *nptr;

#line 254 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 271 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   654

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  124
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  306

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   309

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      58,    59,     2,     2,    62,     2,    63,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    57,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    60,     2,    61,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    55,     2,    56,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    99,    99,   103,   109,   112,   117,   118,   121,   126,
     127,   130,   140,   143,   146,   147,   150,   158,   170,   171,
     174,   200,   205,   214,   225,   226,   229,   235,   244,   248,
     255,   264,   268,   277,   278,   279,   288,   289,   290,   305,
     306,   307,   317,   318,   319,   322,   325,   331,   332,   335,
     400,   401,   404,   405,   408,   411,   415,   421,   461,   464,
     469,   480,   487,   492,   506,   511,   515,   519,   539,   544,
     549,   554,   559,   572,   583,   593,   597,   606,   616,   620,
     632,   637,   641,   644,   647,   657,   664,   672,   686,   694,
     704,   709,   755,   759,   770,   774,   778,   782,   786,   790,
     794,   798,   802,   806,   810,   814,   818,   822,   826,   829,
     832,   835,   839,   843,   847,   851,   877,   881,   885,   889,
     893,   897,   903,   931,   939
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "ID", "PLUS", "MUL", "DIV", "MOD",
  "ASGN", "READ", "WRITE", "MINUS", "NEWLINE", "LT", "GT", "DEQ", "NEQ",
  "ELSE", "IF", "THEN", "ENDIF", "ENDWHILE", "WHILE", "DO", "START", "END",
  "DECL", "ENDDECL", "INT", "STR", "LE", "GE", "NOT", "AND", "OR", "MAIN",
  "RETURN", "ALLOC", "FREE", "INIT", "BRK", "CONTINUE", "BRKP", "TYPE",
  "ENDTYPE", "NILL", "DEQNILL", "NEQNILL", "STRVAL", "CLASS", "ENDCLASS",
  "EXTENDS", "NEW", "THIS", "'{'", "'}'", "';'", "'('", "')'", "'['",
  "']'", "','", "'.'", "$accept", "program", "TypeDefBlock", "TypeDefList",
  "TypeDef", "FieldDeclList", "FieldDecl", "ClassDefBlock", "ClassDefList",
  "ClassDef", "ClassDeclList", "ClassDecl", "gdeclaration", "GDeclList",
  "GDecl", "Gidlist", "FieldType", "TypeName", "FType", "ParamList",
  "Param", "fvlist", "fdeflist", "fdef", "LdeclBlock", "ldlist", "ldec",
  "lvlist", "mainblock", "Body", "Retstmt", "Slist", "Stmt", "FIELD",
  "exprlist", "Expr", YY_NULLPTR
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
     305,   306,   307,   308,   309,   123,   125,    59,    40,    41,
      91,    93,    44,    46
};
# endif

#define YYPACT_NINF -251

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-251)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -14,    17,    48,    47,    49,     6,  -251,  -251,   133,   134,
       7,  -251,  -251,    75,     2,  -251,   199,   199,  -251,  -251,
    -251,   116,  -251,   143,   163,   199,  -251,  -251,  -251,  -251,
    -251,   103,  -251,   171,    14,   199,  -251,  -251,  -251,  -251,
     137,   141,   144,  -251,   197,  -251,  -251,   151,    87,   152,
     168,  -251,  -251,  -251,   199,  -251,  -251,    59,   221,   235,
    -251,   263,   221,   215,   241,  -251,   221,  -251,  -251,  -251,
     272,    -2,  -251,   217,   201,   120,   233,  -251,   207,  -251,
    -251,  -251,   221,  -251,   221,   278,   253,   285,   266,  -251,
     213,   229,   285,   221,   298,   285,  -251,  -251,   298,   328,
     136,  -251,   504,   281,   298,   283,  -251,   126,  -251,  -251,
      30,   282,   294,   296,   301,    12,   302,   286,   304,   305,
     300,   338,   504,  -251,     5,  -251,   309,  -251,  -251,   362,
     181,    12,   363,     1,   183,    12,    12,  -251,   186,   365,
      12,  -251,   307,    12,   142,   372,   367,  -251,  -251,  -251,
     370,  -251,   357,  -251,   166,   381,  -251,  -251,   332,   335,
     337,   329,   403,    57,  -251,    35,   333,   -46,   336,   248,
     279,   310,  -251,  -251,     0,    12,   391,  -251,   288,   394,
     341,  -251,  -251,    12,    12,    12,    12,    12,    12,    12,
      12,    12,    12,    12,    12,    12,  -251,   -21,   177,   392,
    -251,   344,   348,   334,   416,  -251,    -3,   353,  -251,   409,
    -251,   405,   359,    12,   421,   369,   423,   379,   419,   417,
    -251,   230,   619,    94,   382,   384,  -251,   522,   319,   319,
     319,   522,   288,   288,   226,   426,   288,   288,   522,   522,
     387,   388,   219,   390,  -251,  -251,  -251,   397,   389,   400,
     190,    12,  -251,   107,   399,  -251,   271,  -251,   578,   578,
    -251,    12,  -251,   148,   159,  -251,  -251,   406,   447,   413,
     414,  -251,  -251,  -251,   460,   425,   428,   429,   479,   538,
     619,  -251,   239,  -251,   247,   476,  -251,  -251,  -251,  -251,
     430,  -251,  -251,   578,   431,   436,  -251,  -251,   200,  -251,
     552,  -251,  -251,  -251,   439,  -251
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,    13,     0,     0,     7,     1,     0,    23,
       0,     4,     6,     0,     0,    15,     0,     0,    35,    33,
      34,     0,    10,     0,     0,     0,    12,    14,    38,    36,
      37,     0,    24,     0,     0,     0,    47,     3,     8,     9,
       0,     0,     0,    19,     0,    22,    25,    27,     0,     0,
       0,    48,     2,    11,     0,    16,    18,     0,    44,     0,
      26,     0,    44,     0,     0,    21,    44,    41,    39,    40,
       0,     0,    42,     0,    30,     0,     0,    17,     0,    46,
      45,    29,     0,    28,    44,     0,     0,    51,     0,    43,
       0,     0,    51,     0,     0,    51,    32,    31,     0,     0,
       0,    52,     0,     0,     0,     0,    55,     0,    50,    53,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    62,     0,    57,     0,    49,    54,     0,
       0,     0,     0,     0,     0,     0,     0,   110,   113,     0,
       0,   112,     0,     0,   109,     0,     0,    81,    82,    83,
       0,    59,     0,    61,     0,     0,    20,    56,     0,     0,
       0,     0,     0,     0,    90,     0,     0,     0,     0,     0,
       0,     0,   117,   118,     0,     0,     0,   111,   107,     0,
       0,   119,   120,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    60,     0,     0,     0,
      58,     0,     0,   109,     0,    91,     0,     0,    78,     0,
      63,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     116,     0,    92,     0,    90,     0,   108,    94,    96,    97,
      98,    95,    99,   101,   103,   104,   100,   102,   105,   106,
       0,     0,     0,     0,    79,    73,    74,     0,     0,     0,
       0,     0,    65,     0,     0,    77,     0,    67,     0,     0,
     115,     0,   114,     0,     0,    75,    76,     0,     0,     0,
       0,    71,    80,    86,     0,     0,     0,     0,     0,     0,
      93,   121,     0,   123,     0,     0,    85,    72,    84,    64,
       0,    88,    89,     0,     0,     0,   122,   124,     0,    66,
       0,    68,    70,    87,     0,    69
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -251,  -251,  -251,  -251,   494,  -251,   480,  -251,  -251,   489,
     451,   -23,  -251,  -251,   475,  -251,  -251,   119,     3,   -37,
     427,  -251,  -251,   472,   236,  -251,   410,  -251,   477,   -64,
     402,  -250,  -120,  -102,    36,  -108
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     5,     6,    21,    22,     9,    14,    15,
      42,    43,    17,    31,    32,    48,    23,    44,    70,    71,
      72,    80,    35,    36,    94,   100,   101,   107,    37,   103,
     121,   122,   123,   144,   221,   222
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     124,   247,   153,   137,   138,   165,    13,   145,   278,   279,
       4,    18,   139,   215,   154,   137,   138,   155,    49,    56,
     124,     4,   162,   163,   139,    75,   169,   170,   171,    78,
       1,   167,   178,   140,   105,   180,    19,    20,   240,   130,
     126,    56,   132,   300,   198,   140,   204,    90,     7,   141,
      50,    11,   203,    26,   142,   166,   248,    81,   143,   220,
      82,   141,   183,   184,   185,   186,   142,   223,   155,   187,
     143,   188,   189,   190,   191,   227,   228,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   192,   193,
     131,   194,   195,   132,   212,   213,    99,     8,   132,   183,
     184,   185,   186,    99,    10,   253,   187,    28,   188,   189,
     190,   191,   183,   184,   185,   186,    65,    66,   211,   187,
      18,   188,   189,   190,   191,   192,   193,    24,   194,   195,
      25,    45,    29,    30,   268,    33,    34,    13,   192,   193,
      67,   194,   195,   274,    60,    19,    20,    40,    28,    61,
      33,   137,   138,   280,    34,   262,   124,   124,   153,   153,
     139,    16,   137,   138,   108,    68,    69,    41,   275,   137,
     138,   139,    38,    29,    30,    47,   124,   124,   139,    86,
     153,   140,    82,   128,   137,   138,   137,   138,   129,   181,
     182,   124,   140,   139,    53,   139,    54,   141,   124,   140,
      55,    57,   142,    28,   201,   155,   143,   281,   141,    58,
      62,    59,   202,   142,   140,   141,   140,   143,   283,   158,
     142,   159,   137,   138,   143,    67,    63,   160,    29,    30,
     141,   139,   141,   172,   173,   161,   241,   168,    73,   143,
     155,   143,   190,   191,   174,    28,   175,   273,   264,   176,
      68,    69,   140,   183,   184,   185,   186,   303,   264,    84,
     187,    85,   188,   189,   190,   191,    88,    74,   141,    82,
      29,    30,    96,   267,    76,    82,    79,   143,    83,   192,
     193,    91,   194,   195,   183,   184,   185,   186,    87,   260,
      97,   187,   261,   188,   189,   190,   191,    77,   296,   282,
     284,   261,    -1,    -1,   190,   191,   297,   217,    92,   261,
     192,   193,    93,   194,   195,   183,   184,   185,   186,    -1,
      -1,    95,   187,   102,   188,   189,   190,   191,    98,   264,
     277,   104,   106,   188,   189,   190,   191,   125,   218,   127,
     133,   192,   193,   147,   194,   195,   183,   184,   185,   186,
     192,   193,   134,   187,   135,   188,   189,   190,   191,   136,
     146,   148,   149,   150,   151,   156,   157,   164,   177,   219,
     179,   197,   192,   193,   199,   194,   195,   183,   184,   185,
     186,   181,   182,   200,   187,   205,   188,   189,   190,   191,
     206,   245,   209,   207,   208,   224,   214,   155,   225,   216,
     226,   242,   243,   192,   193,   244,   194,   195,   183,   184,
     185,   186,   249,   250,   251,   187,   252,   188,   189,   190,
     191,   183,   184,   185,   186,   254,   255,   256,   187,   196,
     188,   189,   190,   191,   192,   193,   257,   194,   195,   258,
     263,   259,   264,   191,   265,   266,   271,   192,   193,   269,
     194,   195,   183,   184,   185,   186,   270,   272,   276,   187,
     210,   188,   189,   190,   191,   183,   184,   185,   186,   285,
     287,   288,   187,   246,   188,   189,   190,   191,   192,   193,
     298,   194,   195,   110,   290,   291,   292,   299,   301,   111,
     112,   192,   193,   302,   194,   195,   305,   293,   113,    12,
     294,    39,   114,    27,   286,    64,    46,    51,   110,    89,
     109,     0,    52,     0,   111,   112,     0,   289,   116,     0,
     117,   118,   119,   113,   152,     0,     0,   114,   184,   185,
     186,     0,     0,   120,     0,     0,   188,   189,   190,   191,
       0,   115,   110,   116,     0,   117,   118,   119,   111,   112,
       0,     0,     0,   192,   193,     0,   110,   113,   120,     0,
     295,   114,   111,   112,     0,     0,     0,     0,     0,     0,
       0,   113,     0,   304,     0,   114,     0,   116,     0,   117,
     118,   119,   110,     0,     0,     0,     0,     0,   111,   112,
       0,   116,   120,   117,   118,   119,     0,   113,     0,     0,
       0,   114,     0,     0,     0,     0,   120,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   116,     0,   117,
     118,   119,     0,     0,   183,   184,   185,   186,     0,     0,
       0,   187,   120,   188,   189,   190,   191,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     192,   193,     0,   194,   195
};

static const yytype_int16 yycheck[] =
{
     102,     4,   122,     3,     4,     4,     4,   115,   258,   259,
       4,     4,    12,    59,     9,     3,     4,    63,     4,    42,
     122,     4,   130,   131,    12,    62,   134,   135,   136,    66,
      44,   133,   140,    33,    98,   143,    29,    30,    59,     9,
     104,    64,    63,   293,   146,    33,   154,    84,     0,    49,
      36,    45,   154,    51,    54,    54,    59,    59,    58,    59,
      62,    49,     5,     6,     7,     8,    54,   175,    63,    12,
      58,    14,    15,    16,    17,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,    31,    32,
      60,    34,    35,    63,    59,    60,    93,    50,    63,     5,
       6,     7,     8,   100,    55,   213,    12,     4,    14,    15,
      16,    17,     5,     6,     7,     8,    57,    58,    61,    12,
       4,    14,    15,    16,    17,    31,    32,    52,    34,    35,
      55,    28,    29,    30,   242,    16,    17,     4,    31,    32,
       4,    34,    35,   251,    57,    29,    30,     4,     4,    62,
      31,     3,     4,   261,    35,    61,   258,   259,   278,   279,
      12,    27,     3,     4,    28,    29,    30,     4,    61,     3,
       4,    12,    56,    29,    30,     4,   278,   279,    12,    59,
     300,    33,    62,    57,     3,     4,     3,     4,    62,    47,
      48,   293,    33,    12,    57,    12,    55,    49,   300,    33,
      56,     4,    54,     4,    38,    63,    58,    59,    49,    58,
      58,    60,    46,    54,    33,    49,    33,    58,    59,    38,
      54,    40,     3,     4,    58,     4,    58,    46,    29,    30,
      49,    12,    49,    47,    48,    54,    59,    54,     3,    58,
      63,    58,    16,    17,    58,     4,    60,    57,    58,    63,
      29,    30,    33,     5,     6,     7,     8,    57,    58,    58,
      12,    60,    14,    15,    16,    17,    59,     4,    49,    62,
      29,    30,    59,    54,    59,    62,     4,    58,    61,    31,
      32,     3,    34,    35,     5,     6,     7,     8,    55,    59,
      61,    12,    62,    14,    15,    16,    17,    56,    59,   263,
     264,    62,    14,    15,    16,    17,    59,    59,    55,    62,
      31,    32,    27,    34,    35,     5,     6,     7,     8,    31,
      32,    55,    12,    25,    14,    15,    16,    17,    92,    58,
      59,    95,     4,    14,    15,    16,    17,    56,    59,    56,
      58,    31,    32,    57,    34,    35,     5,     6,     7,     8,
      31,    32,    58,    12,    58,    14,    15,    16,    17,    58,
      58,    57,    57,    63,    26,    56,     4,     4,     3,    59,
      63,     4,    31,    32,     4,    34,    35,     5,     6,     7,
       8,    47,    48,    26,    12,     4,    14,    15,    16,    17,
      58,    57,    63,    58,    57,     4,    63,    63,     4,    63,
      59,     9,    58,    31,    32,    57,    34,    35,     5,     6,
       7,     8,    59,     4,     9,    12,    57,    14,    15,    16,
      17,     5,     6,     7,     8,     4,    57,     4,    12,    57,
      14,    15,    16,    17,    31,    32,    57,    34,    35,    20,
      58,    24,    58,    17,    57,    57,    57,    31,    32,    59,
      34,    35,     5,     6,     7,     8,    59,    57,    59,    12,
      57,    14,    15,    16,    17,     5,     6,     7,     8,    63,
      57,    57,    12,    57,    14,    15,    16,    17,    31,    32,
       4,    34,    35,     4,    59,    57,    57,    57,    57,    10,
      11,    31,    32,    57,    34,    35,    57,    18,    19,     5,
      21,    21,    23,    14,    57,    54,    31,    35,     4,    82,
     100,    -1,    35,    -1,    10,    11,    -1,    57,    39,    -1,
      41,    42,    43,    19,   122,    -1,    -1,    23,     6,     7,
       8,    -1,    -1,    54,    -1,    -1,    14,    15,    16,    17,
      -1,    37,     4,    39,    -1,    41,    42,    43,    10,    11,
      -1,    -1,    -1,    31,    32,    -1,     4,    19,    54,    -1,
      22,    23,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    -1,    21,    -1,    23,    -1,    39,    -1,    41,
      42,    43,     4,    -1,    -1,    -1,    -1,    -1,    10,    11,
      -1,    39,    54,    41,    42,    43,    -1,    19,    -1,    -1,
      -1,    23,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    41,
      42,    43,    -1,    -1,     5,     6,     7,     8,    -1,    -1,
      -1,    12,    54,    14,    15,    16,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    32,    -1,    34,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    44,    65,    66,     4,    67,    68,     0,    50,    71,
      55,    45,    68,     4,    72,    73,    27,    76,     4,    29,
      30,    69,    70,    80,    52,    55,    51,    73,     4,    29,
      30,    77,    78,    81,    81,    86,    87,    92,    56,    70,
       4,     4,    74,    75,    81,    28,    78,     4,    79,     4,
      36,    87,    92,    57,    55,    56,    75,     4,    58,    60,
      57,    62,    58,    58,    74,    57,    58,     4,    29,    30,
      82,    83,    84,     3,     4,    83,    59,    56,    83,     4,
      85,    59,    62,    61,    58,    60,    59,    55,    59,    84,
      83,     3,    55,    27,    88,    55,    59,    61,    88,    82,
      89,    90,    25,    93,    88,    93,     4,    91,    28,    90,
       4,    10,    11,    19,    23,    37,    39,    41,    42,    43,
      54,    94,    95,    96,    97,    56,    93,    56,    57,    62,
       9,    60,    63,    58,    58,    58,    58,     3,     4,    12,
      33,    49,    54,    58,    97,    99,    58,    57,    57,    57,
      63,    26,    94,    96,     9,    63,    56,     4,    38,    40,
      46,    54,    99,    99,     4,     4,    54,    97,    54,    99,
      99,    99,    47,    48,    58,    60,    63,     3,    99,    63,
      99,    47,    48,     5,     6,     7,     8,    12,    14,    15,
      16,    17,    31,    32,    34,    35,    57,     4,    97,     4,
      26,    38,    46,    97,    99,     4,    58,    58,    57,    63,
      57,    61,    59,    60,    63,    59,    63,    59,    59,    59,
      59,    98,    99,    99,     4,     4,    59,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      59,    59,     9,    58,    57,    57,    57,     4,    59,    59,
       4,     9,    57,    99,     4,    57,     4,    57,    20,    24,
      59,    62,    61,    58,    58,    57,    57,    54,    99,    59,
      59,    57,    57,    57,    99,    61,    59,    59,    95,    95,
      99,    59,    98,    59,    98,    63,    57,    57,    57,    57,
      59,    57,    57,    18,    21,    22,    59,    59,     4,    57,
      95,    57,    57,    57,    21,    57
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    64,    65,    65,    66,    66,    67,    67,    68,    69,
      69,    70,    71,    71,    72,    72,    73,    73,    74,    74,
      75,    75,    76,    76,    77,    77,    78,    79,    79,    79,
      79,    79,    79,    80,    80,    80,    81,    81,    81,    82,
      82,    82,    83,    83,    83,    84,    85,    86,    86,    87,
      88,    88,    89,    89,    90,    91,    91,    92,    93,    93,
      94,    95,    95,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      97,    97,    98,    98,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     4,     3,     0,     2,     1,     4,     2,
       1,     3,     3,     0,     2,     1,     4,     6,     2,     1,
       9,     3,     3,     0,     1,     2,     3,     1,     4,     4,
       3,     6,     6,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     0,     2,     1,     1,     2,     9,
       3,     0,     1,     2,     3,     1,     3,     8,     4,     3,
       3,     2,     1,     4,     7,     5,     8,     5,     8,    10,
       8,     6,     6,     4,     4,     5,     5,     5,     4,     4,
       6,     2,     2,     2,     7,     6,     6,     8,     7,     7,
       3,     3,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     1,
       1,     2,     1,     1,     4,     4,     3,     2,     2,     2,
       2,     5,     6,     5,     6
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
        case 2:
#line 99 "abstree.y" /* yacc.c:1646  */
    {
                			                                            fclose(intermediate);
                			                                            exit(1);
                                        								}
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 103 "abstree.y" /* yacc.c:1646  */
    {
            		                                            fclose(intermediate);
            		                                            exit(1);
                                                			 }
#line 1633 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 109 "abstree.y" /* yacc.c:1646  */
    {
                                                start();
                                            }
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 112 "abstree.y" /* yacc.c:1646  */
    {
                                                start();
                                            }
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 121 "abstree.y" /* yacc.c:1646  */
    { 
	                                    TInstall((yyvsp[-3].nptr) -> name,0,Fhead); //size is initialized to 0. actual size is calculated in TInstall 
                               		}
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 130 "abstree.y" /* yacc.c:1646  */
    {
	                                if(FLookup((yyvsp[-1].nptr) -> name,Fhead) != NULL)
	                                {
	                                    yyerror("Re-declaration of field element\n");
	                                    exit(1);
	                                }
						            FInstall(declarationType,(yyvsp[-1].nptr) -> name);
								}
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 140 "abstree.y" /* yacc.c:1646  */
    {
                                                is_classdef = 1;
                                            }
#line 1678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 150 "abstree.y" /* yacc.c:1646  */
    { 
                                        CInstall((yyvsp[-3].nptr) -> name,CFhead,CVhead);
                                        CFuncIndex(CLookup((yyvsp[-3].nptr) -> name));
                                        CFhead = NULL;
                                        CFtail = NULL;
                                        CVhead = NULL;
                                        CVtail = NULL;
                                    }
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 158 "abstree.y" /* yacc.c:1646  */
    {
                                                    CInstall((yyvsp[-5].nptr) -> name,CFhead,CVhead);
                                                    extends((yyvsp[-5].nptr) -> name, (yyvsp[-3].nptr) -> name);
                                                    extends_var((yyvsp[-5].nptr) -> name, (yyvsp[-3].nptr) -> name);
                                        			CFuncIndex(CLookup((yyvsp[-5].nptr) -> name));
                                                    CFhead = NULL;
                                                    CFtail = NULL;
                                                    CVhead = NULL;
                                                    CVtail = NULL;
                                                    }
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 174 "abstree.y" /* yacc.c:1646  */
    {
                                                                     (yyvsp[-7].nptr) -> Lentry = Lhead;

                                                                    fprintf(intermediate, "#F%d:\n",fbind);
                                                                    fprintf(intermediate, "PUSH BP\n");
                                                                    fprintf(intermediate, "MOV BP,SP\n");

                                                                    Ltemp = Lhead;

                                                                    while(Ltemp != NULL)
                                                                    {                                                               
                                                                        fprintf(intermediate, "PUSH R0\n");
                                                                        Ltemp = Ltemp -> next;
                                                                    }                                                               

                                                                    codegen((yyvsp[-1].nptr));

                                                                    CFuncInstall(fbind,(yyvsp[-7].nptr) -> name,Phead); 
                                                                    
                                                                    Phead = NULL;
                                                                    Ptail = NULL;
                                                                    Lhead = NULL;
                                                                    Ltail = NULL;

                                                                    fbind++;
                                                                }
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 200 "abstree.y" /* yacc.c:1646  */
    {
                                                                    CVarInstall((yyvsp[-1].nptr) -> name, declarationType);
                                                                }
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 205 "abstree.y" /* yacc.c:1646  */
    {
    										fprintf(intermediate, "START:\n");
											fprintf(intermediate, "MOV SP,%d\n",totalCount - 1);
    										fprintf(intermediate, "MOV BP,%d\n",totalCount);
   											 fprintf(intermediate, "PUSH R0\n");
    										fprintf(intermediate, "CALL MAIN\n");
   											 fprintf(intermediate, "INT 10\n");
   											 fprintf(intermediate, "RET\n");
                                        }
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 214 "abstree.y" /* yacc.c:1646  */
    {
                							fprintf(intermediate, "START:\n");
											fprintf(intermediate, "MOV SP,%d\n",totalCount - 1);
    										fprintf(intermediate, "MOV BP,%d\n",totalCount);
   											 fprintf(intermediate, "PUSH R0\n");
    										fprintf(intermediate, "CALL MAIN\n");
   											 fprintf(intermediate, "INT 10\n");
   											 fprintf(intermediate, "RET\n");
                                        }
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 225 "abstree.y" /* yacc.c:1646  */
    {}
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 226 "abstree.y" /* yacc.c:1646  */
    {}
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 229 "abstree.y" /* yacc.c:1646  */
    {
                                    if(is_classtype)
                                        is_classtype = 0;
                                }
#line 1794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 235 "abstree.y" /* yacc.c:1646  */
    {
                            if(is_classtype)
                            	CGInstall((yyvsp[0].nptr) -> name,CdeclarationType,1,NULL);                                
                            else
                            {
                             verify((yyvsp[0].nptr),1,0,0,NULL);
                             GInstall((yyvsp[0].nptr) -> name,declarationType,1,NULL);                                
                            }
                        }
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 244 "abstree.y" /* yacc.c:1646  */
    {
                         verify((yyvsp[-3].nptr),1,0,0,NULL);
                         install_id((yyvsp[-3].nptr),(yyvsp[-1].nptr),declarationType);
                        }
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 248 "abstree.y" /* yacc.c:1646  */
    {
                                declcount++; //  to keep track of number of functions declared
                                verify((yyvsp[-3].nptr),1,0,0,NULL);
                                GInstall((yyvsp[-3].nptr) -> name,declarationType,-1, Phead);
                                Phead = NULL;
                                Ptail = NULL;
                            }
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 255 "abstree.y" /* yacc.c:1646  */
    {
                                if(is_classtype)
                                 	CGInstall((yyvsp[0].nptr) -> name,CdeclarationType,1,NULL);                                
                                else
                                {
                                    verify((yyvsp[0].nptr),1,0,0,NULL);
                                    GInstall((yyvsp[0].nptr) -> name,declarationType,1,NULL);
                                }
                          }
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 264 "abstree.y" /* yacc.c:1646  */
    {
                                    verify((yyvsp[-3].nptr),1,0,0,NULL);
                                    install_id((yyvsp[-3].nptr),(yyvsp[-1].nptr),declarationType);
                                  }
#line 1852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 268 "abstree.y" /* yacc.c:1646  */
    {
                                            declcount++; //  to keep track of number of functions declared
                                            verify((yyvsp[-3].nptr),1,0,0,NULL);
                                            GInstall((yyvsp[-3].nptr) -> name,declarationType,-1, Phead);
                                            Phead = NULL;
                                            Ptail = NULL;
                                          }
#line 1864 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 277 "abstree.y" /* yacc.c:1646  */
    {declarationType = TLookup("integer");}
#line 1870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 278 "abstree.y" /* yacc.c:1646  */
    {declarationType = TLookup("string");}
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 279 "abstree.y" /* yacc.c:1646  */
    {
                        declarationType = TLookup((yyvsp[0].nptr) -> name);
                        if(declarationType == NULL)
                        {
                            declarationType = TLookup("dummy");
                        }
                    }
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 288 "abstree.y" /* yacc.c:1646  */
    {declarationType = TLookup("integer");}
#line 1894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 289 "abstree.y" /* yacc.c:1646  */
    {declarationType = TLookup("string");}
#line 1900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 290 "abstree.y" /* yacc.c:1646  */
    {
                        declarationType = TLookup((yyvsp[0].nptr) -> name);
                        if(declarationType == NULL)
                        {
                            CdeclarationType = CLookup((yyvsp[0].nptr) -> name);
                            is_classtype = 1;
                            if(CdeclarationType == NULL)
                            {
                                yyerror("Unknown user-defined/class type\n");
                                exit(1);
                            }
                        }
                    }
#line 1918 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 305 "abstree.y" /* yacc.c:1646  */
    {FdeclarationType = TLookup("integer");}
#line 1924 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 306 "abstree.y" /* yacc.c:1646  */
    {FdeclarationType = TLookup("string");}
#line 1930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 307 "abstree.y" /* yacc.c:1646  */
    {
                   FdeclarationType = TLookup((yyvsp[0].nptr) -> name);
                    if(FdeclarationType == NULL)
                    {
                        yyerror("Unknown user-defined/class type\n");
                        exit(1);
                    }
                }
#line 1943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 317 "abstree.y" /* yacc.c:1646  */
    {}
#line 1949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 318 "abstree.y" /* yacc.c:1646  */
    {}
#line 1955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 322 "abstree.y" /* yacc.c:1646  */
    {}
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 325 "abstree.y" /* yacc.c:1646  */
    {
                                        verify((yyvsp[0].nptr),0,0,1,NULL);
                                        PInstall((yyvsp[0].nptr) -> name,FdeclarationType); 
                                    }
#line 1970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 331 "abstree.y" /* yacc.c:1646  */
    {}
#line 1976 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 332 "abstree.y" /* yacc.c:1646  */
    {}
#line 1982 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 335 "abstree.y" /* yacc.c:1646  */
    {  
                                                                defcount++; //  to keep track of number of functions defined

                                                                Gtemp = GLookup((yyvsp[-7].nptr) -> name);

                                                                if(Gtemp == NULL)
                                                                {
                                                                    printf("Function not declared in GST\n");
                                                                    exit(1);
                                                                }

                                                                //storing arguments in LST

                                                                Argtemp1 = Phead;
                                                                Argtemp2 = Gtemp -> paramlist;

                                                                while((Argtemp1 != NULL)&&(Argtemp2 != NULL))
                                                                {
                                                                    if (strcmp(Argtemp1 -> name,Argtemp2 -> name) == 0)
                                                                    {
                                                                        if (Argtemp1 -> type != Argtemp2 -> type)
                                                                        {
                                                                            printf("Conflict in argument types \n");
                                                                            exit(1);
                                                                        }
                                                                    }
                                                                    else
                                                                    {
                                                                        printf("Conflict in argument names \n");
                                                                        exit(1);
                                                                    }

                                                                    Argtemp1 = Argtemp1 -> next;
                                                                    Argtemp2 = Argtemp2 -> next;
                                                                }

                                                                if((Argtemp1 != NULL)||(Argtemp2 != NULL))
                                                                {
                                                                    printf("Unequal number of arguments \n");
                                                                    exit(1);
                                                                }

                                                                (yyvsp[-7].nptr) -> Lentry = Lhead;

                                                                fprintf(intermediate, "F%d:\n",Gtemp -> binding);
                                                                fprintf(intermediate, "PUSH BP\n");
                                                                fprintf(intermediate, "MOV BP,SP\n");

                                                                Ltemp = Lhead;

                                                                while(Ltemp != NULL)
                                                                {                                                               
                                                                    fprintf(intermediate, "PUSH R0\n");
                                                                    Ltemp = Ltemp -> next;
                                                                }                                                               

                                                                codegen((yyvsp[-1].nptr));

                                                                Phead = NULL;
                                                                Ptail = NULL;
                                                                Lhead = NULL;
                                                                Ltail = NULL;
                                                            }
#line 2050 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 400 "abstree.y" /* yacc.c:1646  */
    {}
#line 2056 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 401 "abstree.y" /* yacc.c:1646  */
    {}
#line 2062 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 404 "abstree.y" /* yacc.c:1646  */
    {}
#line 2068 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 405 "abstree.y" /* yacc.c:1646  */
    {}
#line 2074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 408 "abstree.y" /* yacc.c:1646  */
    {}
#line 2080 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 411 "abstree.y" /* yacc.c:1646  */
    {
                            verify((yyvsp[0].nptr),0,1,0,NULL);
                            LInstall((yyvsp[0].nptr) -> name,FdeclarationType);
                         }
#line 2089 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 415 "abstree.y" /* yacc.c:1646  */
    {
                            verify((yyvsp[0].nptr),0,1,0,NULL);
                            LInstall((yyvsp[0].nptr) -> name,FdeclarationType);
                        }
#line 2098 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 422 "abstree.y" /* yacc.c:1646  */
    {
                                if(declcount != defcount)
                                {
                                    yyerror("All functions declared need to be defined\n");
                                    exit(1);
                                }
                                if(declarationType != TLookup("integer"))
                                {
                                    yyerror("Main return type should be of integer type\n");
                                    exit(1);
                                }

                                if(is_classdef)
                                    class_setmem();

                                fprintf(intermediate, "MAIN:\n");
                                fprintf(intermediate, "PUSH BP\n");
                                fprintf(intermediate, "MOV BP,SP\n");

                                Ltemp = Lhead;

                                while(Ltemp != NULL)
                                {                                                                
                                    fprintf(intermediate, "PUSH R0\n");
                                    Ltemp = Ltemp -> next;
                                }

                                if(is_classdef)
                                {
                                    fprintf(intermediate, "CALL F%d\n",(fbind-1));
                                }
                                
                                codegen((yyvsp[-1].nptr));

                                Lhead = NULL;
                                Ltail = NULL;
                            }
#line 2140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 461 "abstree.y" /* yacc.c:1646  */
    {
                                    (yyval.nptr) = TreeCreate(TLookup("void"), DEFAULT, NULL,NULL,NULL,(yyvsp[-2].nptr),(yyvsp[-1].nptr),NULL);
                                }
#line 2148 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 464 "abstree.y" /* yacc.c:1646  */
    {
                                    (yyval.nptr) = TreeCreate(TLookup("void"), DEFAULT, NULL,NULL,NULL,NULL,(yyvsp[-1].nptr),NULL);
                                }
#line 2156 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 469 "abstree.y" /* yacc.c:1646  */
    {   
                                if(declarationType == (yyvsp[-1].nptr) -> type) 
                                    (yyval.nptr) = TreeCreate((yyvsp[-1].nptr)->type, NODE_RET,NULL,NULL,NULL,NULL,(yyvsp[-1].nptr),NULL);
                                else
                                {
                                    yyerror("return type do not match with the function return type\n");
                                    exit(1);
                                }
                            }
#line 2170 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 480 "abstree.y" /* yacc.c:1646  */
    {
                            head = (struct ASTNode *)malloc(sizeof(struct ASTNode ));
                            head -> nodetype = DEFAULT;
                            head -> ptr1 = (yyvsp[-1].nptr);
                            head -> ptr2 = (yyvsp[0].nptr);
                            (yyval.nptr) = head;
                        }
#line 2182 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 487 "abstree.y" /* yacc.c:1646  */
    {
                            (yyval.nptr) = (yyvsp[0].nptr);
                        }
#line 2190 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 492 "abstree.y" /* yacc.c:1646  */
    {
                                    type_assign((yyvsp[-3].nptr),NULL,0,0,0,0,0);
                                    if(((yyvsp[-3].nptr) -> nodetype == NODE_FIELD) || ((yyvsp[-1].nptr) -> nodetype == NODE_FIELD))
                                    {
                                    	head = get_last((yyvsp[-3].nptr));
                                    	head1 = get_last((yyvsp[-1].nptr));
                                    	type_comp(head -> type, head1 -> type , 'a');
                                    }
                                    else
                                    {
                                    	type_comp((yyvsp[-3].nptr) -> type, (yyvsp[-1].nptr) -> type , 'a');
                                    }
                                    (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASGN,NULL,NULL,NULL,(yyvsp[-3].nptr),(yyvsp[-1].nptr),NULL);  
                                }
#line 2209 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 506 "abstree.y" /* yacc.c:1646  */
    {
                                            type_assign_arr((yyvsp[-6].nptr),(yyvsp[-4].nptr),0);
                                            type_comp((yyvsp[-6].nptr)-> type,(yyvsp[-1].nptr) -> type,'a'); 
                                            (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ARRAY_ASGN,NULL,NULL,NULL,(yyvsp[-6].nptr),(yyvsp[-4].nptr),(yyvsp[-1].nptr)); 
                                          }
#line 2219 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 511 "abstree.y" /* yacc.c:1646  */
    {
                                 type_assign((yyvsp[-2].nptr),NULL,0,0,0,0,1);
                                 (yyval.nptr) = TreeCreate(TLookup("void"), NODE_READ,NULL,NULL,NULL,NULL,(yyvsp[-2].nptr),NULL); 
                                }
#line 2228 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 515 "abstree.y" /* yacc.c:1646  */
    {
                                                type_assign_arr((yyvsp[-5].nptr),(yyvsp[-3].nptr),0);
                                                (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ARRAY_READ,NULL,NULL,NULL,NULL,(yyvsp[-5].nptr),(yyvsp[-3].nptr)); 
                                            }
#line 2237 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 519 "abstree.y" /* yacc.c:1646  */
    {
                                    if((yyvsp[-2].nptr) -> type == TLookup("integer") || (yyvsp[-2].nptr) -> type == TLookup("string"))
                                    {
                                        (yyval.nptr) = TreeCreate(TLookup("void"), NODE_WRITE,NULL,NULL,NULL,NULL,(yyvsp[-2].nptr),NULL);
                                    }
                                    else
                                    {
                                        head = get_last((yyvsp[-2].nptr));
                                        if(head -> type == TLookup("integer") || head -> type == TLookup("string"))
                                        {
                                            (yyval.nptr) = TreeCreate(TLookup("void"), NODE_WRITE,NULL,NULL,NULL,NULL,(yyvsp[-2].nptr),NULL);
                                        }
                                        else
                                        {
                                            yyerror("Cannot write a udt type\n");
                                            exit(1);
                                        }
                                    }
                                    
                                }
#line 2262 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 540 "abstree.y" /* yacc.c:1646  */
    { 
                               		type_comp((yyvsp[-5].nptr) -> type, TLookup("boolean"),'i');
                                    (yyval.nptr) = TreeCreate(TLookup("void"), NODE_IF,NULL,NULL,NULL,(yyvsp[-5].nptr),(yyvsp[-2].nptr),NULL); 
                               }
#line 2271 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 545 "abstree.y" /* yacc.c:1646  */
    { 
                               		type_comp((yyvsp[-7].nptr) -> type, TLookup("boolean"),'e');
                                    (yyval.nptr) = TreeCreate(TLookup("void"), NODE_IF_ELSE,NULL,NULL,NULL,(yyvsp[-7].nptr),(yyvsp[-4].nptr),(yyvsp[-2].nptr)); 
                                }
#line 2280 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 550 "abstree.y" /* yacc.c:1646  */
    { 
                               		type_comp((yyvsp[-5].nptr) -> type, TLookup("boolean"),'w');
                                    (yyval.nptr) = TreeCreate(TLookup("void"), NODE_WHILE,NULL,NULL,NULL,(yyvsp[-5].nptr),(yyvsp[-2].nptr),NULL); 
                                }
#line 2289 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 554 "abstree.y" /* yacc.c:1646  */
    {
        								type_assign((yyvsp[-5].nptr),NULL,1,0,1,0,0);
                                        head = TreeCreate(TLookup("integer"),NODE_ALLOC,NULL,NULL,NULL,NULL,NULL,NULL);
                                        (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASGN,NULL,NULL,NULL,(yyvsp[-5].nptr),head,NULL);
                                    }
#line 2299 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 559 "abstree.y" /* yacc.c:1646  */
    {
                                            head = get_last((yyvsp[-5].nptr));
                                            if(head -> type == TLookup("integer") || head -> type == TLookup("string") )
                                            {
                                               yyerror("Cannot ALLOC to string or integer variable\n");
                                                    exit(1);
                                            }
                                            else
                                            {
                                                head = TreeCreate(TLookup("integer"),NODE_ALLOC,NULL,NULL,NULL,NULL,NULL,NULL);
                                                (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASGN,NULL,NULL,NULL,(yyvsp[-5].nptr),head,NULL);        
                                            }
                                        }
#line 2317 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 572 "abstree.y" /* yacc.c:1646  */
    {
                                            head = get_last((yyvsp[-3].nptr));
                                            head1 = get_last((yyvsp[-1].nptr));
                                            if(head1 -> type == head -> type)
                                                (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASGN,NULL,NULL,NULL,(yyvsp[-3].nptr),(yyvsp[-1].nptr),NULL);        
                                            else
                                            {
                                                yyerror("conflicting assignment types in field1\n");
                                                exit(1);
                                            }
                                        }
#line 2333 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 583 "abstree.y" /* yacc.c:1646  */
    {
                                            head = get_last((yyvsp[-3].nptr));
                                            if((yyvsp[-1].nptr) -> type == head -> type)
                                                (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASGN,NULL,NULL,NULL,(yyvsp[-3].nptr),(yyvsp[-1].nptr),NULL);        
                                            else
                                            {
                                                yyerror("conflicting assignment types in field2\n");
                                                exit(1);
                                            }
                                        }
#line 2348 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 593 "abstree.y" /* yacc.c:1646  */
    {
                                            type_assign((yyvsp[-2].nptr),NULL,1,1,0,0,0);
                                            (yyval.nptr) = TreeCreate(TLookup("void"),NODE_FREE,NULL,NULL,NULL,NULL,(yyvsp[-2].nptr),NULL); 
                                        }
#line 2357 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 597 "abstree.y" /* yacc.c:1646  */
    {
                                            head = get_last((yyvsp[-2].nptr));
                                            if(head -> type == TLookup("integer") || head -> type == TLookup("string"))
                                            {
                                                yyerror("cannot FREE non-udt\n");
                                                exit(1);
                                            }
                                            (yyval.nptr) = TreeCreate(TLookup("void"),NODE_FREE,NULL,NULL,NULL,NULL,(yyvsp[-2].nptr),NULL); 
	                                    }
#line 2371 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 606 "abstree.y" /* yacc.c:1646  */
    {
                                            head = get_last((yyvsp[-2].nptr));
                                            
                                            if(head -> type != TLookup("integer") && head -> type != TLookup("string") )
                                            {
                                                yyerror("cannot READ a udt type\n");
                                                exit(1);
                                            }
                                            (yyval.nptr) = TreeCreate(TLookup("void"),NODE_READ,NULL,NULL,NULL,NULL,(yyvsp[-2].nptr),NULL); 
	                                    }
#line 2386 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 616 "abstree.y" /* yacc.c:1646  */
    {
			                                type_assign((yyvsp[-3].nptr),NULL,1,0,0,0,0);
			                                (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASGN,NULL,NULL,NULL,(yyvsp[-3].nptr),(yyvsp[-1].nptr),NULL);
			        					}
#line 2395 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 620 "abstree.y" /* yacc.c:1646  */
    {
                                head = get_last((yyvsp[-3].nptr));
                                
                                if(head -> type == TLookup("integer") || head -> type == TLookup("string")
                                    || head -> type == TLookup("array_integer") || head -> type == TLookup("array_string"))
                                {
                                    yyerror("cannot assign null to a non-udt\n");
                                    exit(1);
                                }
								(yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASGN,NULL,NULL,NULL,(yyvsp[-3].nptr),(yyvsp[-1].nptr),NULL); 
						    }
#line 2411 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 632 "abstree.y" /* yacc.c:1646  */
    {
		                                head = TreeCreate(TLookup("void"), NODE_INIT,NULL,NULL,NULL,NULL,NULL,NULL);
										(yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASGN,NULL,NULL,NULL,(yyvsp[-5].nptr),head,NULL); 
									}
#line 2420 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 637 "abstree.y" /* yacc.c:1646  */
    {
                            (yyval.nptr) = TreeCreate(TLookup("void"), NODE_BRK, NULL,NULL,NULL,NULL,NULL,NULL);
                        }
#line 2428 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 641 "abstree.y" /* yacc.c:1646  */
    {
                            (yyval.nptr) = TreeCreate(TLookup("void"), NODE_CONTINUE, NULL,NULL,NULL,NULL,NULL,NULL);
                        }
#line 2436 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 644 "abstree.y" /* yacc.c:1646  */
    {
                        (yyval.nptr) = TreeCreate(TLookup("void"), NODE_BRKP, NULL,NULL,NULL,NULL,NULL,NULL);
                    }
#line 2444 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 647 "abstree.y" /* yacc.c:1646  */
    {
                                        (yyvsp[-6].nptr) -> type = NULL;
                                        (yyvsp[-6].nptr) -> ctype = CLookup((yyvsp[-2].nptr) -> name);
                                        (yyvsp[-6].nptr) -> Gentry = GLookup((yyvsp[-6].nptr) -> name);
                                        (yyvsp[-2].nptr) -> type = NULL;

                                        head1 = TreeCreate(TLookup("integer"),NODE_ALLOC,NULL,NULL,NULL,NULL,NULL,NULL);
                                        head = TreeCreate(TLookup("integer"),NODE_NEW,NULL,NULL,NULL,head1,(yyvsp[-2].nptr),NULL);
                                        (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASGN,NULL,NULL,NULL,(yyvsp[-6].nptr),head,NULL);
                                     }
#line 2459 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 657 "abstree.y" /* yacc.c:1646  */
    {
                                        cvtemp = CVLookup((yyvsp[-3].nptr) -> name,CVhead);
                                        (yyvsp[-3].nptr) -> type = cvtemp -> type;
                                        (yyvsp[-3].nptr) -> value.intval = cvtemp -> ClassVarIndex; 
                                        head = TreeCreate(TLookup("void"),NODE_THIS,NULL,NULL,NULL,(yyvsp[-3].nptr),NULL,NULL);
                                        (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASGN,NULL,NULL,NULL,head,(yyvsp[-1].nptr),NULL);
                                    }
#line 2471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 664 "abstree.y" /* yacc.c:1646  */
    {

                                        cvtemp = CVLookup((yyvsp[-1].nptr) -> name,CVhead);
                                        (yyvsp[-1].nptr) -> type = cvtemp -> type;
                                        (yyvsp[-1].nptr) -> value.intval = cvtemp -> ClassVarIndex; 
                                        head = TreeCreate(TLookup("void"),NODE_THIS,NULL,NULL,NULL,(yyvsp[-1].nptr),NULL,NULL);
                                        (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASGN,NULL,NULL,NULL,(yyvsp[-5].nptr),head,NULL);
                                    }
#line 2484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 672 "abstree.y" /* yacc.c:1646  */
    {
                                            cvtemp = CVLookup((yyvsp[-5].nptr) -> name,CVhead);
                                            (yyvsp[-5].nptr) -> type = cvtemp -> type;
                                            (yyvsp[-5].nptr) -> value.intval = cvtemp -> ClassVarIndex; 
                                            head = TreeCreate(TLookup("void"),NODE_THIS,NULL,NULL,NULL,(yyvsp[-5].nptr),NULL,NULL);
                                            
                                            cvtemp = CVLookup((yyvsp[-1].nptr) -> name,CVhead);
                                            (yyvsp[-1].nptr) -> type = cvtemp -> type;
                                            (yyvsp[-1].nptr) -> value.intval = cvtemp -> ClassVarIndex; 
                                            
                                            head1 = TreeCreate(TLookup("void"),NODE_THIS,NULL,NULL,NULL,(yyvsp[-1].nptr),NULL,NULL);
                                            
                                            (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASGN,NULL,NULL,NULL,head,head1,NULL);
                                        }
#line 2503 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 686 "abstree.y" /* yacc.c:1646  */
    {

                                        cvtemp = CVLookup((yyvsp[-2].nptr) -> name,CVhead);
                                        (yyvsp[-2].nptr) -> type = cvtemp -> type;
                                        (yyvsp[-2].nptr) -> value.intval = cvtemp -> ClassVarIndex; 
                                        head = TreeCreate(TLookup("void"),NODE_THIS,NULL,NULL,NULL,(yyvsp[-2].nptr),NULL,NULL);
                                        (yyval.nptr) = TreeCreate(TLookup("void"), NODE_READ,NULL,NULL,NULL,NULL,head,NULL); 
                                    }
#line 2516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 694 "abstree.y" /* yacc.c:1646  */
    {

                                        cvtemp = CVLookup((yyvsp[-2].nptr) -> name,CVhead);
                                        (yyvsp[-2].nptr) -> type = cvtemp -> type;
                                        (yyvsp[-2].nptr) -> value.intval = cvtemp -> ClassVarIndex; 
                                        head = TreeCreate(TLookup("void"),NODE_THIS,NULL,NULL,NULL,(yyvsp[-2].nptr),NULL,NULL);
                                        (yyval.nptr) = TreeCreate(TLookup("void"), NODE_WRITE,NULL,NULL,NULL,NULL,head,NULL);
                                    }
#line 2529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 704 "abstree.y" /* yacc.c:1646  */
    {
                            (yyvsp[-2].nptr) -> nodetype = NODE_FIELD;
                            type_assign((yyvsp[-2].nptr),(yyvsp[0].nptr),1,0,0,1,0);
                            (yyval.nptr) = (yyvsp[-2].nptr);
                        }
#line 2539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 709 "abstree.y" /* yacc.c:1646  */
    {
                            head1 = head = get_last((yyvsp[-2].nptr));
                            
                            temp1 = head -> type;
                            if(temp1 != TLookup("string") && temp1 != TLookup("integer")
                                && temp1 != TLookup("array_integer") && temp1 != TLookup("array_string"))
                            {
                                if(temp1 == NULL)
                                {
                                    cvtemp = CVLookup((yyvsp[0].nptr) -> name,head -> ctype -> CVars);
                                    if(cvtemp != NULL)
                                    {
                                        (yyvsp[0].nptr) -> type = cvtemp -> type;
                                        head -> ptr2 = (yyvsp[0].nptr);
                                        (yyval.nptr) = (yyvsp[-2].nptr);
                                    }
                                    else
                                    {
                                        yyerror("Un-declared class-field variable\n");
                                        exit(1);
                                    }
                                }
                                else
                                {
                                    ftemp = FLookup((yyvsp[0].nptr) -> name,temp1 -> fields);
                                    if(ftemp != NULL)
                                    {
                                        (yyvsp[0].nptr) -> type = ftemp -> type;
                                        head -> ptr2 = (yyvsp[0].nptr);
                                        (yyval.nptr) = (yyvsp[-2].nptr);
                                    }
                                    else
                                    {
                                        yyerror("Un-declared field variable\n");
                                        exit(1);
                                    }
                                }
                            }
                            else
                            {
                                yyerror("Illegal access of identifier\n");
                                exit(1);
                            }
                        }
#line 2588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 755 "abstree.y" /* yacc.c:1646  */
    {
                                    exprcount = 1;
                                    (yyval.nptr) = (yyvsp[0].nptr);
                                }
#line 2597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 759 "abstree.y" /* yacc.c:1646  */
    {
                                    indicator = 1;
                                    exprcount++;
                                    head = (struct ASTNode*) malloc(sizeof(struct ASTNode));
                                    head -> nodetype = NODE_EXPR;
                                    head -> ptr1 = (yyvsp[0].nptr);
                                    head -> ptr2 = (yyvsp[-2].nptr);
                                    (yyval.nptr) = head;
                                }
#line 2611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 770 "abstree.y" /* yacc.c:1646  */
    {
                                type_comp((yyvsp[-2].nptr)->type,(yyvsp[0].nptr)->type,'+');
                                (yyval.nptr) = TreeCreate(TLookup("integer"), NODE_PLUS , NULL,NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                            }
#line 2620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 774 "abstree.y" /* yacc.c:1646  */
    {
                                type_comp((yyvsp[-2].nptr)->type,(yyvsp[0].nptr)->type,'-');
                                (yyval.nptr) = TreeCreate(TLookup("integer"), NODE_MINUS , NULL,NULL , NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);                                
                            }
#line 2629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 778 "abstree.y" /* yacc.c:1646  */
    {
                                type_comp((yyvsp[-2].nptr)->type,(yyvsp[0].nptr)->type,'*');
                                (yyval.nptr) = TreeCreate(TLookup("integer"), NODE_MUL , NULL,NULL , NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);                                
                            }
#line 2638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 782 "abstree.y" /* yacc.c:1646  */
    {
                                type_comp((yyvsp[-2].nptr)->type,(yyvsp[0].nptr)->type,'/');
                                (yyval.nptr) = TreeCreate(TLookup("integer"), NODE_DIV , NULL,NULL , NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);                                
                            }
#line 2647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 786 "abstree.y" /* yacc.c:1646  */
    {
                                type_comp((yyvsp[-2].nptr)->type,(yyvsp[0].nptr)->type,'%');
                                (yyval.nptr) = TreeCreate(TLookup("integer"), NODE_MOD , NULL,NULL , NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                            }
#line 2656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 790 "abstree.y" /* yacc.c:1646  */
    {
                                type_comp((yyvsp[-2].nptr)->type,(yyvsp[0].nptr)->type,'<');
                                (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_LT , NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                            }
#line 2665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 794 "abstree.y" /* yacc.c:1646  */
    {
                                type_comp((yyvsp[-2].nptr)->type,(yyvsp[0].nptr)->type,'#');
                                (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_LE , NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                            }
#line 2674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 798 "abstree.y" /* yacc.c:1646  */
    {
                                type_comp((yyvsp[-2].nptr)->type,(yyvsp[0].nptr)->type,'>');
                                (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_GT , NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                            }
#line 2683 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 802 "abstree.y" /* yacc.c:1646  */
    {
                                type_comp((yyvsp[-2].nptr)->type,(yyvsp[0].nptr)->type,'$');
                                (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_GE , NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                            }
#line 2692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 806 "abstree.y" /* yacc.c:1646  */
    {
                                type_comp((yyvsp[-2].nptr)->type,(yyvsp[0].nptr)->type,'d');
                                (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_DEQ, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                            }
#line 2701 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 810 "abstree.y" /* yacc.c:1646  */
    {
                                type_comp((yyvsp[-2].nptr)->type,(yyvsp[0].nptr)->type,'n');
                                (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_NEQ, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                            }
#line 2710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 814 "abstree.y" /* yacc.c:1646  */
    {
                                type_comp((yyvsp[-2].nptr)->type,(yyvsp[0].nptr)->type,'&');
                                (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_AND, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                            }
#line 2719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 818 "abstree.y" /* yacc.c:1646  */
    {
                                type_comp((yyvsp[-2].nptr)->type,(yyvsp[0].nptr)->type,'|');
                                (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_OR, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                            }
#line 2728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 822 "abstree.y" /* yacc.c:1646  */
    {
                                type_comp((yyvsp[0].nptr)->type,NULL,'!');
                                (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_NOT, NULL, NULL, NULL, NULL, (yyvsp[0].nptr), NULL);
                            }
#line 2737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 826 "abstree.y" /* yacc.c:1646  */
    {
                                (yyval.nptr) = (yyvsp[-1].nptr);
                            }
#line 2745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 829 "abstree.y" /* yacc.c:1646  */
    {
                                (yyval.nptr) = (yyvsp[0].nptr);
                            }
#line 2753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 832 "abstree.y" /* yacc.c:1646  */
    {
                                (yyval.nptr) = (yyvsp[0].nptr);
                            }
#line 2761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 835 "abstree.y" /* yacc.c:1646  */
    {
                                (yyvsp[0].nptr) -> value.intval = ((yyvsp[0].nptr) -> value.intval)*-1;   //negating the value
                                (yyval.nptr) = (yyvsp[0].nptr);
                            }
#line 2770 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 839 "abstree.y" /* yacc.c:1646  */
    {
                                
        						(yyval.nptr) = (yyvsp[0].nptr);
        					}
#line 2779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 843 "abstree.y" /* yacc.c:1646  */
    {
				    			type_assign((yyvsp[0].nptr),NULL,0,0,0,0,0);
				    			(yyval.nptr) = (yyvsp[0].nptr);
				            }
#line 2788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 847 "abstree.y" /* yacc.c:1646  */
    {
								type_assign_arr((yyvsp[-3].nptr),(yyvsp[-1].nptr),0);
								(yyval.nptr) = TreeCreate((yyvsp[-3].nptr) -> type,NODE_ARRAY,NULL,NULL,NULL,(yyvsp[-3].nptr),(yyvsp[-1].nptr),NULL);
                            }
#line 2797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 851 "abstree.y" /* yacc.c:1646  */
    {
        						type_assign_arr((yyvsp[-3].nptr),(yyvsp[-1].nptr),1);

                                (yyvsp[-1].nptr) -> ptr3 = Gtemp -> paramlist;
                                Arg_callee = Gtemp -> paramlist;
                                while(Arg_callee != NULL)
                                {
                                    exprcount--;
                                    Arg_callee = Arg_callee -> next;
                                }
                                if(exprcount)
                                {
                                    yyerror("Unequal number of arguments\n");
                                    exit(1);
                                }
                                //differentiating b/w one and more than one arguments
                                if(indicator == 1)
                                {
                                    (yyval.nptr) = TreeCreate((yyvsp[-3].nptr) -> type,NODE_FUNC,(yyvsp[-3].nptr) -> name,NULL,Gtemp -> paramlist,NULL,(yyvsp[-1].nptr),NULL);
                                    indicator = 0;
                                }

                                else
                                    (yyval.nptr) = TreeCreate((yyvsp[-3].nptr) -> type,NODE_FUNC,(yyvsp[-3].nptr) -> name,NULL,Gtemp -> paramlist,NULL,NULL,(yyvsp[-1].nptr));
                            }
#line 2827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 877 "abstree.y" /* yacc.c:1646  */
    {
    							type_assign_arr((yyvsp[-2].nptr),NULL,1);
                                (yyval.nptr) = TreeCreate((yyvsp[-2].nptr) -> type,NODE_FUNC,(yyvsp[-2].nptr) -> name,NULL,Gtemp -> paramlist,NULL,NULL,NULL);
                            }
#line 2836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 881 "abstree.y" /* yacc.c:1646  */
    {
	   						    type_assign((yyvsp[-1].nptr),NULL,1,0,0,0,0);
		                    	(yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_DEQ, NULL, NULL, NULL, (yyvsp[-1].nptr), (yyvsp[0].nptr), NULL);
			    			}
#line 2845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 885 "abstree.y" /* yacc.c:1646  */
    {
	   						    type_assign((yyvsp[-1].nptr),NULL,1,0,0,0,0);
	                        	(yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_NEQ, NULL, NULL, NULL, (yyvsp[-1].nptr), (yyvsp[0].nptr), NULL);
	        				}
#line 2854 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 889 "abstree.y" /* yacc.c:1646  */
    {
	                            type_comp((yyvsp[-1].nptr),NULL,'=');
	                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_DEQ, NULL, NULL, NULL, (yyvsp[-1].nptr), (yyvsp[0].nptr), NULL);
	        				}
#line 2863 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 893 "abstree.y" /* yacc.c:1646  */
    {
	                            type_comp((yyvsp[-1].nptr),NULL,'^');
	                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_NEQ, NULL, NULL, NULL, (yyvsp[-1].nptr), (yyvsp[0].nptr), NULL);
	        				}
#line 2872 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 897 "abstree.y" /* yacc.c:1646  */
    {
                                (yyvsp[-4].nptr) -> type = NULL;
                                (yyvsp[-4].nptr) -> Gentry = GLookup((yyvsp[-4].nptr) -> name);
                                (yyvsp[-4].nptr) -> ctype = (yyvsp[-4].nptr) -> Gentry -> ctype; 
                                (yyval.nptr) = TreeCreate(TLookup("integer"),NODE_CLASS_FUNC,NULL,NULL,NULL,(yyvsp[-4].nptr),(yyvsp[-2].nptr),NULL);
                            }
#line 2883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 903 "abstree.y" /* yacc.c:1646  */
    {
            
            						(yyvsp[-5].nptr) -> type = NULL;
                                    (yyvsp[-5].nptr) -> Gentry = GLookup((yyvsp[-5].nptr) -> name);
                                    (yyvsp[-5].nptr) -> ctype = (yyvsp[-5].nptr) -> Gentry -> ctype;
		 							Gtemp = GLookup((yyvsp[-5].nptr) -> name);
		 							cftemp1 = CFPcountLookup((yyvsp[-3].nptr) -> name, Gtemp -> ctype -> CFuncs,exprcount);
                                    exprcount = 0;
		 							if(cftemp1 == NULL)
                                    {
                                        yyerror("No such function in the class\n");
                                        exit(0);
                                    }
                                    (yyvsp[-1].nptr) -> ptr3 = cftemp1 -> paramlist;

                                    if(indicator == 1) //differentiating b/w one and more than one arguments
                                    {
                                        cindicator.intval = 1;
                                        (yyval.nptr) = TreeCreate(TLookup("integer"),NODE_CLASS_FUNC,NULL,&cindicator,NULL,(yyvsp[-5].nptr),(yyvsp[-3].nptr),(yyvsp[-1].nptr));
                                        cindicator.intval = 0;
                                        indicator = 0;
                                    }
                                    else
                                    {
                                        cindicator.intval = 0;
                                        (yyval.nptr) = TreeCreate(TLookup("integer"),NODE_CLASS_FUNC,NULL,&cindicator,NULL,(yyvsp[-5].nptr),(yyvsp[-3].nptr),(yyvsp[-1].nptr));
                                    }
                            }
#line 2916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 931 "abstree.y" /* yacc.c:1646  */
    {
                                cftemp1 = CFLookup((yyvsp[-2].nptr) -> name, CFhead);
                                if(cftemp1 == NULL)
                                {
                                    yyerror("cannot find the function with in the class\n");
                                }
                                (yyval.nptr) = TreeCreate(TLookup("integer"),NODE_FUNC,(yyvsp[-2].nptr) -> name,NULL,cftemp1 -> paramlist,NULL,NULL,NULL);
                            }
#line 2929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 939 "abstree.y" /* yacc.c:1646  */
    {
                                        cftemp1 = CFPcountLookup((yyvsp[-3].nptr) -> name, CFhead,exprcount);
                                        exprcount = 0;
                                        if(cftemp1 == NULL)
                                        {
                                            yyerror("No such function in the class\n");
                                            exit(0);
                                        }

                                        (yyvsp[-1].nptr) -> ptr3 = cftemp1 -> paramlist;
                                        cindicator.intval = cftemp1 -> label;
                                        if(indicator == 1) //differentiating b/w one and more than one arguments
                                        {
                                            (yyval.nptr) = TreeCreate(TLookup("integer"),NODE_FUNC,(yyvsp[-3].nptr) -> name,&cindicator,cftemp1 -> paramlist,NULL,(yyvsp[-1].nptr),NULL);
                                            indicator = 0;
                                        }
                                        else
                                            (yyval.nptr) = TreeCreate(TLookup("integer"),NODE_FUNC,(yyvsp[-3].nptr) -> name,&cindicator,cftemp1 -> paramlist,NULL,NULL,(yyvsp[-1].nptr));

                                        cindicator.intval = 0;
                                    }
#line 2955 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2959 "y.tab.c" /* yacc.c:1646  */
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
#line 962 "abstree.y" /* yacc.c:1906  */


void yyerror(char const *s) 
{ 
    printf("yyerror  %s\n",s); 
    return ;
} 

int main(int argc,char* argv[]) 
{ 
    TInstall("integer",1,NULL);
    TInstall("string",1,NULL);
    TInstall("boolean",1,NULL);
    TInstall("array_integer",1,NULL);
    TInstall("array_string",1,NULL);
    TInstall("void",0,NULL);
    TInstall("dummy",0,NULL); // This is for creating the fieldlist in case of udt 
    
    if(argc > 1)
    {
        fp = fopen(argv[1],"r");
        if(fp)
            yyin = fp;
    }    
    yyparse(); 
    return 1; 
}
