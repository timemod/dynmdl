// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton interface for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


/**
 ** \file pkg/src/DynareBison.hh
 ** Define the Dynare::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_DYNARE_PKG_SRC_DYNAREBISON_HH_INCLUDED
# define YY_DYNARE_PKG_SRC_DYNAREBISON_HH_INCLUDED
// "%code requires" blocks.
#line 28 "pkg/src/lex_yacc/DynareBison.yy"

#include "ExprNode.hh"
#include "CodeInterpreter.hh"

#line 54 "pkg/src/DynareBison.hh"


# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif
# include "location.hh"


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

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

namespace Dynare {
#line 189 "pkg/src/DynareBison.hh"




  /// A Bison parser.
  class parser
  {
  public:
#ifdef YYSTYPE
# ifdef __GNUC__
#  pragma GCC message "bison: do not #define YYSTYPE in C++, use %define api.value.type"
# endif
    typedef YYSTYPE value_type;
#else
    /// Symbol semantic values.
    union value_type
    {
#line 49 "pkg/src/lex_yacc/DynareBison.yy"

  string *string_val;
  expr_t node_val;
  SymbolType symbol_type_val;
  vector<string *> *vector_string_val;
  vector<int> *vector_int_val;
  pair<string *, string *> *string_pair_val;
  vector<pair<string *, string *> *> *vector_string_pair_val;
  PriorDistributions prior_distributions_val;

#line 218 "pkg/src/DynareBison.hh"

    };
#endif
    /// Backward compatibility (Bison 3.8).
    typedef value_type semantic_type;

    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        YYEMPTY = -2,
    YYEOF = 0,                     // "end of file"
    YYerror = 256,                 // error
    YYUNDEF = 257,                 // "invalid token"
    AIM_SOLVER = 258,              // AIM_SOLVER
    ANALYTIC_DERIVATION = 259,     // ANALYTIC_DERIVATION
    ANALYTIC_DERIVATION_MODE = 260, // ANALYTIC_DERIVATION_MODE
    AR = 261,                      // AR
    AUTOCORR = 262,                // AUTOCORR
    POSTERIOR_SAMPLING_METHOD = 263, // POSTERIOR_SAMPLING_METHOD
    BAYESIAN_IRF = 264,            // BAYESIAN_IRF
    BETA_PDF = 265,                // BETA_PDF
    BLOCK = 266,                   // BLOCK
    USE_CALIBRATION = 267,         // USE_CALIBRATION
    SILENT_OPTIMIZER = 268,        // SILENT_OPTIMIZER
    BVAR_DENSITY = 269,            // BVAR_DENSITY
    BVAR_FORECAST = 270,           // BVAR_FORECAST
    NODECOMPOSITION = 271,         // NODECOMPOSITION
    DR_DISPLAY_TOL = 272,          // DR_DISPLAY_TOL
    HUGE_NUMBER = 273,             // HUGE_NUMBER
    FIG_NAME = 274,                // FIG_NAME
    WRITE_XLS = 275,               // WRITE_XLS
    BVAR_PRIOR_DECAY = 276,        // BVAR_PRIOR_DECAY
    BVAR_PRIOR_FLAT = 277,         // BVAR_PRIOR_FLAT
    BVAR_PRIOR_LAMBDA = 278,       // BVAR_PRIOR_LAMBDA
    INTERACTIVE = 279,             // INTERACTIVE
    SCREEN_SHOCKS = 280,           // SCREEN_SHOCKS
    STEADYSTATE = 281,             // STEADYSTATE
    BVAR_PRIOR_MU = 282,           // BVAR_PRIOR_MU
    BVAR_PRIOR_OMEGA = 283,        // BVAR_PRIOR_OMEGA
    BVAR_PRIOR_TAU = 284,          // BVAR_PRIOR_TAU
    BVAR_PRIOR_TRAIN = 285,        // BVAR_PRIOR_TRAIN
    DETAIL_PLOT = 286,             // DETAIL_PLOT
    TYPE = 287,                    // TYPE
    BVAR_REPLIC = 288,             // BVAR_REPLIC
    BYTECODE = 289,                // BYTECODE
    ALL_VALUES_REQUIRED = 290,     // ALL_VALUES_REQUIRED
    PROPOSAL_DISTRIBUTION = 291,   // PROPOSAL_DISTRIBUTION
    REALTIME = 292,                // REALTIME
    VINTAGE = 293,                 // VINTAGE
    CALIB_SMOOTHER = 294,          // CALIB_SMOOTHER
    CHANGE_TYPE = 295,             // CHANGE_TYPE
    CHECK = 296,                   // CHECK
    CONDITIONAL_FORECAST = 297,    // CONDITIONAL_FORECAST
    CONDITIONAL_FORECAST_PATHS = 298, // CONDITIONAL_FORECAST_PATHS
    CONF_SIG = 299,                // CONF_SIG
    CONSTANT = 300,                // CONSTANT
    CONTROLLED_VAREXO = 301,       // CONTROLLED_VAREXO
    CORR = 302,                    // CORR
    COVAR = 303,                   // COVAR
    CUTOFF = 304,                  // CUTOFF
    CYCLE_REDUCTION = 305,         // CYCLE_REDUCTION
    LOGARITHMIC_REDUCTION = 306,   // LOGARITHMIC_REDUCTION
    CONSIDER_ALL_ENDOGENOUS = 307, // CONSIDER_ALL_ENDOGENOUS
    CONSIDER_ONLY_OBSERVED = 308,  // CONSIDER_ONLY_OBSERVED
    INITIAL_CONDITION_DECOMPOSITION = 309, // INITIAL_CONDITION_DECOMPOSITION
    DATAFILE = 310,                // DATAFILE
    FILE = 311,                    // FILE
    SERIES = 312,                  // SERIES
    DOUBLING = 313,                // DOUBLING
    DR_CYCLE_REDUCTION_TOL = 314,  // DR_CYCLE_REDUCTION_TOL
    DR_LOGARITHMIC_REDUCTION_TOL = 315, // DR_LOGARITHMIC_REDUCTION_TOL
    DR_LOGARITHMIC_REDUCTION_MAXITER = 316, // DR_LOGARITHMIC_REDUCTION_MAXITER
    DR_ALGO = 317,                 // DR_ALGO
    DROP = 318,                    // DROP
    DSAMPLE = 319,                 // DSAMPLE
    DYNASAVE = 320,                // DYNASAVE
    DYNATYPE = 321,                // DYNATYPE
    CALIBRATION = 322,             // CALIBRATION
    DIFFERENTIATE_FORWARD_VARS = 323, // DIFFERENTIATE_FORWARD_VARS
    END = 324,                     // END
    ENDVAL = 325,                  // ENDVAL
    EQUAL = 326,                   // EQUAL
    ESTIMATION = 327,              // ESTIMATION
    ESTIMATED_PARAMS = 328,        // ESTIMATED_PARAMS
    ESTIMATED_PARAMS_BOUNDS = 329, // ESTIMATED_PARAMS_BOUNDS
    ESTIMATED_PARAMS_INIT = 330,   // ESTIMATED_PARAMS_INIT
    EXTENDED_PATH = 331,           // EXTENDED_PATH
    ENDOGENOUS_PRIOR = 332,        // ENDOGENOUS_PRIOR
    FILENAME = 333,                // FILENAME
    DIRNAME = 334,                 // DIRNAME
    FILTER_STEP_AHEAD = 335,       // FILTER_STEP_AHEAD
    FILTERED_VARS = 336,           // FILTERED_VARS
    FIRST_OBS = 337,               // FIRST_OBS
    LAST_OBS = 338,                // LAST_OBS
    SET_TIME = 339,                // SET_TIME
    OSR_PARAMS_BOUNDS = 340,       // OSR_PARAMS_BOUNDS
    KEEP_KALMAN_ALGO_IF_SINGULARITY_IS_DETECTED = 341, // KEEP_KALMAN_ALGO_IF_SINGULARITY_IS_DETECTED
    FLOAT_NUMBER = 342,            // FLOAT_NUMBER
    DATES = 343,                   // DATES
    DEFAULT = 344,                 // DEFAULT
    FIXED_POINT = 345,             // FIXED_POINT
    OPT_ALGO = 346,                // OPT_ALGO
    FORECAST = 347,                // FORECAST
    K_ORDER_SOLVER = 348,          // K_ORDER_SOLVER
    INSTRUMENTS = 349,             // INSTRUMENTS
    SHIFT = 350,                   // SHIFT
    MEAN = 351,                    // MEAN
    STDEV = 352,                   // STDEV
    VARIANCE = 353,                // VARIANCE
    MODE = 354,                    // MODE
    INTERVAL = 355,                // INTERVAL
    SHAPE = 356,                   // SHAPE
    DOMAINN = 357,                 // DOMAINN
    GAMMA_PDF = 358,               // GAMMA_PDF
    GRAPH = 359,                   // GRAPH
    GRAPH_FORMAT = 360,            // GRAPH_FORMAT
    CONDITIONAL_VARIANCE_DECOMPOSITION = 361, // CONDITIONAL_VARIANCE_DECOMPOSITION
    NOCHECK = 362,                 // NOCHECK
    STD = 363,                     // STD
    HISTVAL = 364,                 // HISTVAL
    HISTVAL_FILE = 365,            // HISTVAL_FILE
    HOMOTOPY_SETUP = 366,          // HOMOTOPY_SETUP
    HOMOTOPY_MODE = 367,           // HOMOTOPY_MODE
    HOMOTOPY_STEPS = 368,          // HOMOTOPY_STEPS
    HOMOTOPY_FORCE_CONTINUE = 369, // HOMOTOPY_FORCE_CONTINUE
    HP_FILTER = 370,               // HP_FILTER
    HP_NGRID = 371,                // HP_NGRID
    HYBRID = 372,                  // HYBRID
    ONE_SIDED_HP_FILTER = 373,     // ONE_SIDED_HP_FILTER
    IDENTIFICATION = 374,          // IDENTIFICATION
    INF_CONSTANT = 375,            // INF_CONSTANT
    INITVAL = 376,                 // INITVAL
    INITVAL_FILE = 377,            // INITVAL_FILE
    BOUNDS = 378,                  // BOUNDS
    JSCALE = 379,                  // JSCALE
    INIT = 380,                    // INIT
    INFILE = 381,                  // INFILE
    INVARS = 382,                  // INVARS
    INT_NUMBER = 383,              // INT_NUMBER
    INV_GAMMA_PDF = 384,           // INV_GAMMA_PDF
    INV_GAMMA1_PDF = 385,          // INV_GAMMA1_PDF
    INV_GAMMA2_PDF = 386,          // INV_GAMMA2_PDF
    IRF = 387,                     // IRF
    IRF_SHOCKS = 388,              // IRF_SHOCKS
    IRF_PLOT_THRESHOLD = 389,      // IRF_PLOT_THRESHOLD
    IRF_CALIBRATION = 390,         // IRF_CALIBRATION
    FAST_KALMAN_FILTER = 391,      // FAST_KALMAN_FILTER
    KALMAN_ALGO = 392,             // KALMAN_ALGO
    KALMAN_TOL = 393,              // KALMAN_TOL
    DIFFUSE_KALMAN_TOL = 394,      // DIFFUSE_KALMAN_TOL
    SUBSAMPLES = 395,              // SUBSAMPLES
    OPTIONS = 396,                 // OPTIONS
    TOLF = 397,                    // TOLF
    TOLX = 398,                    // TOLX
    PLOT_INIT_DATE = 399,          // PLOT_INIT_DATE
    PLOT_END_DATE = 400,           // PLOT_END_DATE
    LAPLACE = 401,                 // LAPLACE
    LIK_ALGO = 402,                // LIK_ALGO
    LIK_INIT = 403,                // LIK_INIT
    LINEAR = 404,                  // LINEAR
    LOAD_IDENT_FILES = 405,        // LOAD_IDENT_FILES
    LOAD_MH_FILE = 406,            // LOAD_MH_FILE
    LOAD_RESULTS_AFTER_LOAD_MH = 407, // LOAD_RESULTS_AFTER_LOAD_MH
    LOAD_PARAMS_AND_STEADY_STATE = 408, // LOAD_PARAMS_AND_STEADY_STATE
    LOGLINEAR = 409,               // LOGLINEAR
    LOGDATA = 410,                 // LOGDATA
    LYAPUNOV = 411,                // LYAPUNOV
    LINEAR_APPROXIMATION = 412,    // LINEAR_APPROXIMATION
    LYAPUNOV_FIXED_POINT_TOL = 413, // LYAPUNOV_FIXED_POINT_TOL
    LYAPUNOV_DOUBLING_TOL = 414,   // LYAPUNOV_DOUBLING_TOL
    LYAPUNOV_SQUARE_ROOT_SOLVER_TOL = 415, // LYAPUNOV_SQUARE_ROOT_SOLVER_TOL
    LOG_DEFLATOR = 416,            // LOG_DEFLATOR
    LOG_TREND_VAR = 417,           // LOG_TREND_VAR
    LOG_GROWTH_FACTOR = 418,       // LOG_GROWTH_FACTOR
    MARKOWITZ = 419,               // MARKOWITZ
    MARGINAL_DENSITY = 420,        // MARGINAL_DENSITY
    MAX = 421,                     // MAX
    MAXIT = 422,                   // MAXIT
    MFS = 423,                     // MFS
    MH_CONF_SIG = 424,             // MH_CONF_SIG
    MH_DROP = 425,                 // MH_DROP
    MH_INIT_SCALE = 426,           // MH_INIT_SCALE
    MH_JSCALE = 427,               // MH_JSCALE
    MH_MODE = 428,                 // MH_MODE
    MH_NBLOCKS = 429,              // MH_NBLOCKS
    MH_REPLIC = 430,               // MH_REPLIC
    MH_RECOVER = 431,              // MH_RECOVER
    POSTERIOR_MAX_SUBSAMPLE_DRAWS = 432, // POSTERIOR_MAX_SUBSAMPLE_DRAWS
    MIN = 433,                     // MIN
    MINIMAL_SOLVING_PERIODS = 434, // MINIMAL_SOLVING_PERIODS
    MODE_CHECK = 435,              // MODE_CHECK
    MODE_CHECK_NEIGHBOURHOOD_SIZE = 436, // MODE_CHECK_NEIGHBOURHOOD_SIZE
    MODE_CHECK_SYMMETRIC_PLOTS = 437, // MODE_CHECK_SYMMETRIC_PLOTS
    MODE_CHECK_NUMBER_OF_POINTS = 438, // MODE_CHECK_NUMBER_OF_POINTS
    MODE_COMPUTE = 439,            // MODE_COMPUTE
    MODE_FILE = 440,               // MODE_FILE
    MODEL = 441,                   // MODEL
    MODEL_COMPARISON = 442,        // MODEL_COMPARISON
    MODEL_INFO = 443,              // MODEL_INFO
    MSHOCKS = 444,                 // MSHOCKS
    ABS = 445,                     // ABS
    SIGN = 446,                    // SIGN
    MODEL_DIAGNOSTICS = 447,       // MODEL_DIAGNOSTICS
    MODIFIEDHARMONICMEAN = 448,    // MODIFIEDHARMONICMEAN
    MOMENTS_VARENDO = 449,         // MOMENTS_VARENDO
    CONTEMPORANEOUS_CORRELATION = 450, // CONTEMPORANEOUS_CORRELATION
    DIFFUSE_FILTER = 451,          // DIFFUSE_FILTER
    SUB_DRAWS = 452,               // SUB_DRAWS
    TAPER_STEPS = 453,             // TAPER_STEPS
    GEWEKE_INTERVAL = 454,         // GEWEKE_INTERVAL
    RAFTERY_LEWIS_QRS = 455,       // RAFTERY_LEWIS_QRS
    RAFTERY_LEWIS_DIAGNOSTICS = 456, // RAFTERY_LEWIS_DIAGNOSTICS
    MCMC_JUMPING_COVARIANCE = 457, // MCMC_JUMPING_COVARIANCE
    MOMENT_CALIBRATION = 458,      // MOMENT_CALIBRATION
    NUMBER_OF_PARTICLES = 459,     // NUMBER_OF_PARTICLES
    RESAMPLING = 460,              // RESAMPLING
    SYSTEMATIC = 461,              // SYSTEMATIC
    GENERIC = 462,                 // GENERIC
    RESAMPLING_THRESHOLD = 463,    // RESAMPLING_THRESHOLD
    RESAMPLING_METHOD = 464,       // RESAMPLING_METHOD
    KITAGAWA = 465,                // KITAGAWA
    STRATIFIED = 466,              // STRATIFIED
    SMOOTH = 467,                  // SMOOTH
    CPF_WEIGHTS = 468,             // CPF_WEIGHTS
    AMISANOTRISTANI = 469,         // AMISANOTRISTANI
    MURRAYJONESPARSLOW = 470,      // MURRAYJONESPARSLOW
    WRITE_EQUATION_TAGS = 471,     // WRITE_EQUATION_TAGS
    NONLINEAR_FILTER_INITIALIZATION = 472, // NONLINEAR_FILTER_INITIALIZATION
    FILTER_ALGORITHM = 473,        // FILTER_ALGORITHM
    PROPOSAL_APPROXIMATION = 474,  // PROPOSAL_APPROXIMATION
    CUBATURE = 475,                // CUBATURE
    UNSCENTED = 476,               // UNSCENTED
    MONTECARLO = 477,              // MONTECARLO
    DISTRIBUTION_APPROXIMATION = 478, // DISTRIBUTION_APPROXIMATION
    NAME = 479,                    // NAME
    USE_PENALIZED_OBJECTIVE_FOR_HESSIAN = 480, // USE_PENALIZED_OBJECTIVE_FOR_HESSIAN
    INIT_STATE = 481,              // INIT_STATE
    RESCALE_PREDICTION_ERROR_COVARIANCE = 482, // RESCALE_PREDICTION_ERROR_COVARIANCE
    NAN_CONSTANT = 483,            // NAN_CONSTANT
    NO_STATIC = 484,               // NO_STATIC
    NOBS = 485,                    // NOBS
    NOCONSTANT = 486,              // NOCONSTANT
    NODISPLAY = 487,               // NODISPLAY
    NOCORR = 488,                  // NOCORR
    NODIAGNOSTIC = 489,            // NODIAGNOSTIC
    NOFUNCTIONS = 490,             // NOFUNCTIONS
    NO_HOMOTOPY = 491,             // NO_HOMOTOPY
    NOGRAPH = 492,                 // NOGRAPH
    POSTERIOR_NOGRAPH = 493,       // POSTERIOR_NOGRAPH
    POSTERIOR_GRAPH = 494,         // POSTERIOR_GRAPH
    NOMOMENTS = 495,               // NOMOMENTS
    NOPRINT = 496,                 // NOPRINT
    NORMAL_PDF = 497,              // NORMAL_PDF
    SAVE_DRAWS = 498,              // SAVE_DRAWS
    OBSERVATION_TRENDS = 499,      // OBSERVATION_TRENDS
    OPTIM = 500,                   // OPTIM
    OPTIM_WEIGHTS = 501,           // OPTIM_WEIGHTS
    ORDER = 502,                   // ORDER
    OSR = 503,                     // OSR
    OSR_PARAMS = 504,              // OSR_PARAMS
    MAX_DIM_COVA_GROUP = 505,      // MAX_DIM_COVA_GROUP
    ADVANCED = 506,                // ADVANCED
    OUTFILE = 507,                 // OUTFILE
    OUTVARS = 508,                 // OUTVARS
    OVERWRITE = 509,               // OVERWRITE
    PARALLEL_LOCAL_FILES = 510,    // PARALLEL_LOCAL_FILES
    PARAMETERS = 511,              // PARAMETERS
    PARAMETER_SET = 512,           // PARAMETER_SET
    PARTIAL_INFORMATION = 513,     // PARTIAL_INFORMATION
    PERIODS = 514,                 // PERIODS
    PERIOD = 515,                  // PERIOD
    PLANNER_OBJECTIVE = 516,       // PLANNER_OBJECTIVE
    PLOT_CONDITIONAL_FORECAST = 517, // PLOT_CONDITIONAL_FORECAST
    PLOT_PRIORS = 518,             // PLOT_PRIORS
    PREFILTER = 519,               // PREFILTER
    PRESAMPLE = 520,               // PRESAMPLE
    PERFECT_FORESIGHT_SETUP = 521, // PERFECT_FORESIGHT_SETUP
    PERFECT_FORESIGHT_SOLVER = 522, // PERFECT_FORESIGHT_SOLVER
    NO_POSTERIOR_KERNEL_DENSITY = 523, // NO_POSTERIOR_KERNEL_DENSITY
    FUNCTION = 524,                // FUNCTION
    PRINT = 525,                   // PRINT
    PRIOR_MC = 526,                // PRIOR_MC
    PRIOR_TRUNC = 527,             // PRIOR_TRUNC
    PRIOR_MODE = 528,              // PRIOR_MODE
    PRIOR_MEAN = 529,              // PRIOR_MEAN
    POSTERIOR_MODE = 530,          // POSTERIOR_MODE
    POSTERIOR_MEAN = 531,          // POSTERIOR_MEAN
    POSTERIOR_MEDIAN = 532,        // POSTERIOR_MEDIAN
    MLE_MODE = 533,                // MLE_MODE
    PRUNING = 534,                 // PRUNING
    QUOTED_STRING = 535,           // QUOTED_STRING
    QZ_CRITERIUM = 536,            // QZ_CRITERIUM
    QZ_ZERO_THRESHOLD = 537,       // QZ_ZERO_THRESHOLD
    FULL = 538,                    // FULL
    DSGE_VAR = 539,                // DSGE_VAR
    DSGE_VARLAG = 540,             // DSGE_VARLAG
    DSGE_PRIOR_WEIGHT = 541,       // DSGE_PRIOR_WEIGHT
    TRUNCATE = 542,                // TRUNCATE
    RELATIVE_IRF = 543,            // RELATIVE_IRF
    REPLIC = 544,                  // REPLIC
    SIMUL_REPLIC = 545,            // SIMUL_REPLIC
    RPLOT = 546,                   // RPLOT
    SAVE_PARAMS_AND_STEADY_STATE = 547, // SAVE_PARAMS_AND_STEADY_STATE
    PARAMETER_UNCERTAINTY = 548,   // PARAMETER_UNCERTAINTY
    SHOCKS = 549,                  // SHOCKS
    SHOCK_DECOMPOSITION = 550,     // SHOCK_DECOMPOSITION
    SHOCK_GROUPS = 551,            // SHOCK_GROUPS
    USE_SHOCK_GROUPS = 552,        // USE_SHOCK_GROUPS
    SIGMA_E = 553,                 // SIGMA_E
    SIMUL = 554,                   // SIMUL
    SIMUL_ALGO = 555,              // SIMUL_ALGO
    SIMUL_SEED = 556,              // SIMUL_SEED
    ENDOGENOUS_TERMINAL_PERIOD = 557, // ENDOGENOUS_TERMINAL_PERIOD
    SMOOTHER = 558,                // SMOOTHER
    SMOOTHER2HISTVAL = 559,        // SMOOTHER2HISTVAL
    SQUARE_ROOT_SOLVER = 560,      // SQUARE_ROOT_SOLVER
    STACK_SOLVE_ALGO = 561,        // STACK_SOLVE_ALGO
    STEADY_STATE_MODEL = 562,      // STEADY_STATE_MODEL
    SOLVE_ALGO = 563,              // SOLVE_ALGO
    SOLVER_PERIODS = 564,          // SOLVER_PERIODS
    ROBUST_LIN_SOLVE = 565,        // ROBUST_LIN_SOLVE
    STDERR = 566,                  // STDERR
    STEADY = 567,                  // STEADY
    STOCH_SIMUL = 568,             // STOCH_SIMUL
    SURPRISE = 569,                // SURPRISE
    SYLVESTER = 570,               // SYLVESTER
    SYLVESTER_FIXED_POINT_TOL = 571, // SYLVESTER_FIXED_POINT_TOL
    REGIMES = 572,                 // REGIMES
    REGIME = 573,                  // REGIME
    REALTIME_SHOCK_DECOMPOSITION = 574, // REALTIME_SHOCK_DECOMPOSITION
    TEX = 575,                     // TEX
    RAMSEY_MODEL = 576,            // RAMSEY_MODEL
    RAMSEY_POLICY = 577,           // RAMSEY_POLICY
    RAMSEY_CONSTRAINTS = 578,      // RAMSEY_CONSTRAINTS
    PLANNER_DISCOUNT = 579,        // PLANNER_DISCOUNT
    DISCRETIONARY_POLICY = 580,    // DISCRETIONARY_POLICY
    DISCRETIONARY_TOL = 581,       // DISCRETIONARY_TOL
    TEX_NAME = 582,                // TEX_NAME
    UNIFORM_PDF = 583,             // UNIFORM_PDF
    UNIT_ROOT_VARS = 584,          // UNIT_ROOT_VARS
    USE_DLL = 585,                 // USE_DLL
    USEAUTOCORR = 586,             // USEAUTOCORR
    GSA_SAMPLE_FILE = 587,         // GSA_SAMPLE_FILE
    USE_UNIVARIATE_FILTERS_IF_SINGULARITY_IS_DETECTED = 588, // USE_UNIVARIATE_FILTERS_IF_SINGULARITY_IS_DETECTED
    VALUES = 589,                  // VALUES
    VAR = 590,                     // VAR
    VAREXO = 591,                  // VAREXO
    VAREXO_DET = 592,              // VAREXO_DET
    VAROBS = 593,                  // VAROBS
    PREDETERMINED_VARIABLES = 594, // PREDETERMINED_VARIABLES
    PLOT_SHOCK_DECOMPOSITION = 595, // PLOT_SHOCK_DECOMPOSITION
    WRITE_LATEX_DYNAMIC_MODEL = 596, // WRITE_LATEX_DYNAMIC_MODEL
    WRITE_LATEX_STATIC_MODEL = 597, // WRITE_LATEX_STATIC_MODEL
    WRITE_LATEX_ORIGINAL_MODEL = 598, // WRITE_LATEX_ORIGINAL_MODEL
    XLS_SHEET = 599,               // XLS_SHEET
    XLS_RANGE = 600,               // XLS_RANGE
    LMMCP = 601,                   // LMMCP
    OCCBIN = 602,                  // OCCBIN
    BANDPASS_FILTER = 603,         // BANDPASS_FILTER
    COLORMAP = 604,                // COLORMAP
    QOQ = 605,                     // QOQ
    YOY = 606,                     // YOY
    AOA = 607,                     // AOA
    COMMA = 608,                   // COMMA
    EQUAL_EQUAL = 609,             // EQUAL_EQUAL
    EXCLAMATION_EQUAL = 610,       // EXCLAMATION_EQUAL
    LESS = 611,                    // LESS
    GREATER = 612,                 // GREATER
    LESS_EQUAL = 613,              // LESS_EQUAL
    GREATER_EQUAL = 614,           // GREATER_EQUAL
    PLUS = 615,                    // PLUS
    MINUS = 616,                   // MINUS
    TIMES = 617,                   // TIMES
    DIVIDE = 618,                  // DIVIDE
    UMINUS = 619,                  // UMINUS
    UPLUS = 620,                   // UPLUS
    POWER = 621,                   // POWER
    EXP = 622,                     // EXP
    LOG = 623,                     // LOG
    LN = 624,                      // LN
    LOG10 = 625,                   // LOG10
    LINLOG = 626,                  // LINLOG
    LINPOW = 627,                  // LINPOW
    SIN = 628,                     // SIN
    COS = 629,                     // COS
    TAN = 630,                     // TAN
    ASIN = 631,                    // ASIN
    ACOS = 632,                    // ACOS
    ATAN = 633,                    // ATAN
    SINH = 634,                    // SINH
    COSH = 635,                    // COSH
    TANH = 636,                    // TANH
    ERF = 637,                     // ERF
    ASINH = 638,                   // ASINH
    ACOSH = 639,                   // ACOSH
    ATANH = 640,                   // ATANH
    SQRT = 641,                    // SQRT
    NORMCDF = 642,                 // NORMCDF
    NORMPDF = 643,                 // NORMPDF
    STEADY_STATE = 644,            // STEADY_STATE
    EXPECTATION = 645,             // EXPECTATION
    DYNARE_SENSITIVITY = 646,      // DYNARE_SENSITIVITY
    MORRIS = 647,                  // MORRIS
    STAB = 648,                    // STAB
    REDFORM = 649,                 // REDFORM
    PPRIOR = 650,                  // PPRIOR
    PRIOR_RANGE = 651,             // PRIOR_RANGE
    PPOST = 652,                   // PPOST
    ILPTAU = 653,                  // ILPTAU
    MORRIS_NLIV = 654,             // MORRIS_NLIV
    MORRIS_NTRA = 655,             // MORRIS_NTRA
    NSAM = 656,                    // NSAM
    LOAD_REDFORM = 657,            // LOAD_REDFORM
    LOAD_RMSE = 658,               // LOAD_RMSE
    LOAD_STAB = 659,               // LOAD_STAB
    ALPHA2_STAB = 660,             // ALPHA2_STAB
    LOGTRANS_REDFORM = 661,        // LOGTRANS_REDFORM
    THRESHOLD_REDFORM = 662,       // THRESHOLD_REDFORM
    KSSTAT_REDFORM = 663,          // KSSTAT_REDFORM
    ALPHA2_REDFORM = 664,          // ALPHA2_REDFORM
    NAMENDO = 665,                 // NAMENDO
    NAMLAGENDO = 666,              // NAMLAGENDO
    NAMEXO = 667,                  // NAMEXO
    RMSE = 668,                    // RMSE
    LIK_ONLY = 669,                // LIK_ONLY
    VAR_RMSE = 670,                // VAR_RMSE
    PFILT_RMSE = 671,              // PFILT_RMSE
    ISTART_RMSE = 672,             // ISTART_RMSE
    ALPHA_RMSE = 673,              // ALPHA_RMSE
    ALPHA2_RMSE = 674,             // ALPHA2_RMSE
    FREQ = 675,                    // FREQ
    INITIAL_YEAR = 676,            // INITIAL_YEAR
    INITIAL_SUBPERIOD = 677,       // INITIAL_SUBPERIOD
    FINAL_YEAR = 678,              // FINAL_YEAR
    FINAL_SUBPERIOD = 679,         // FINAL_SUBPERIOD
    DATA = 680,                    // DATA
    VLIST = 681,                   // VLIST
    LOG_VAR = 682,                 // LOG_VAR
    PERCENT_VAR = 683,             // PERCENT_VAR
    VLISTLOG = 684,                // VLISTLOG
    VLISTPER = 685,                // VLISTPER
    SPECTRAL_DENSITY = 686,        // SPECTRAL_DENSITY
    RESTRICTION = 687,             // RESTRICTION
    RESTRICTION_FNAME = 688,       // RESTRICTION_FNAME
    CROSS_RESTRICTIONS = 689,      // CROSS_RESTRICTIONS
    NLAGS = 690,                   // NLAGS
    CONTEMP_REDUCED_FORM = 691,    // CONTEMP_REDUCED_FORM
    REAL_PSEUDO_FORECAST = 692,    // REAL_PSEUDO_FORECAST
    DUMMY_OBS = 693,               // DUMMY_OBS
    NSTATES = 694,                 // NSTATES
    INDXSCALESSTATES = 695,        // INDXSCALESSTATES
    NO_BAYESIAN_PRIOR = 696,       // NO_BAYESIAN_PRIOR
    SPECIFICATION = 697,           // SPECIFICATION
    SIMS_ZHA = 698,                // SIMS_ZHA
    ALPHA = 699,                   // ALPHA
    BETA = 700,                    // BETA
    ABAND = 701,                   // ABAND
    NINV = 702,                    // NINV
    CMS = 703,                     // CMS
    NCMS = 704,                    // NCMS
    CNUM = 705,                    // CNUM
    GAMMA = 706,                   // GAMMA
    INV_GAMMA = 707,               // INV_GAMMA
    INV_GAMMA1 = 708,              // INV_GAMMA1
    INV_GAMMA2 = 709,              // INV_GAMMA2
    NORMAL = 710,                  // NORMAL
    UNIFORM = 711,                 // UNIFORM
    EPS = 712,                     // EPS
    PDF = 713,                     // PDF
    FIG = 714,                     // FIG
    DR = 715,                      // DR
    NONE = 716,                    // NONE
    PRIOR = 717,                   // PRIOR
    PRIOR_VARIANCE = 718,          // PRIOR_VARIANCE
    HESSIAN = 719,                 // HESSIAN
    IDENTITY_MATRIX = 720,         // IDENTITY_MATRIX
    DIRICHLET = 721,               // DIRICHLET
    GSIG2_LMDM = 722,              // GSIG2_LMDM
    Q_DIAG = 723,                  // Q_DIAG
    FLAT_PRIOR = 724,              // FLAT_PRIOR
    NCSK = 725,                    // NCSK
    NSTD = 726,                    // NSTD
    WEIBULL = 727,                 // WEIBULL
    WEIBULL_PDF = 728,             // WEIBULL_PDF
    INDXPARR = 729,                // INDXPARR
    INDXOVR = 730,                 // INDXOVR
    INDXAP = 731,                  // INDXAP
    APBAND = 732,                  // APBAND
    INDXIMF = 733,                 // INDXIMF
    IMFBAND = 734,                 // IMFBAND
    INDXFORE = 735,                // INDXFORE
    FOREBAND = 736,                // FOREBAND
    INDXGFOREHAT = 737,            // INDXGFOREHAT
    INDXGIMFHAT = 738,             // INDXGIMFHAT
    INDXESTIMA = 739,              // INDXESTIMA
    INDXGDLS = 740,                // INDXGDLS
    EQ_MS = 741,                   // EQ_MS
    FILTER_COVARIANCE = 742,       // FILTER_COVARIANCE
    FILTER_DECOMPOSITION = 743,    // FILTER_DECOMPOSITION
    SMOOTHED_STATE_UNCERTAINTY = 744, // SMOOTHED_STATE_UNCERTAINTY
    EQ_CMS = 745,                  // EQ_CMS
    TLINDX = 746,                  // TLINDX
    TLNUMBER = 747,                // TLNUMBER
    BANACT = 748,                  // BANACT
    RESTRICTIONS = 749,            // RESTRICTIONS
    POSTERIOR_SAMPLER_OPTIONS = 750, // POSTERIOR_SAMPLER_OPTIONS
    OUTPUT_FILE_TAG = 751,         // OUTPUT_FILE_TAG
    DRAWS_NBR_BURN_IN_1 = 752,     // DRAWS_NBR_BURN_IN_1
    DRAWS_NBR_BURN_IN_2 = 753,     // DRAWS_NBR_BURN_IN_2
    HORIZON = 754,                 // HORIZON
    SBVAR = 755,                   // SBVAR
    TREND_VAR = 756,               // TREND_VAR
    DEFLATOR = 757,                // DEFLATOR
    GROWTH_FACTOR = 758,           // GROWTH_FACTOR
    MS_IRF = 759,                  // MS_IRF
    MS_VARIANCE_DECOMPOSITION = 760, // MS_VARIANCE_DECOMPOSITION
    MS_ESTIMATION = 761,           // MS_ESTIMATION
    MS_SIMULATION = 762,           // MS_SIMULATION
    MS_COMPUTE_MDD = 763,          // MS_COMPUTE_MDD
    MS_COMPUTE_PROBABILITIES = 764, // MS_COMPUTE_PROBABILITIES
    MS_FORECAST = 765,             // MS_FORECAST
    SVAR_IDENTIFICATION = 766,     // SVAR_IDENTIFICATION
    EQUATION = 767,                // EQUATION
    EXCLUSION = 768,               // EXCLUSION
    LAG = 769,                     // LAG
    UPPER_CHOLESKY = 770,          // UPPER_CHOLESKY
    LOWER_CHOLESKY = 771,          // LOWER_CHOLESKY
    MONTHLY = 772,                 // MONTHLY
    QUARTERLY = 773,               // QUARTERLY
    MARKOV_SWITCHING = 774,        // MARKOV_SWITCHING
    CHAIN = 775,                   // CHAIN
    DURATION = 776,                // DURATION
    NUMBER_OF_REGIMES = 777,       // NUMBER_OF_REGIMES
    NUMBER_OF_LAGS = 778,          // NUMBER_OF_LAGS
    SVAR = 779,                    // SVAR
    SVAR_GLOBAL_IDENTIFICATION_CHECK = 780, // SVAR_GLOBAL_IDENTIFICATION_CHECK
    COEFF = 781,                   // COEFF
    COEFFICIENTS = 782,            // COEFFICIENTS
    VARIANCES = 783,               // VARIANCES
    CONSTANTS = 784,               // CONSTANTS
    EQUATIONS = 785,               // EQUATIONS
    EXTERNAL_FUNCTION = 786,       // EXTERNAL_FUNCTION
    EXT_FUNC_NAME = 787,           // EXT_FUNC_NAME
    EXT_FUNC_NARGS = 788,          // EXT_FUNC_NARGS
    FIRST_DERIV_PROVIDED = 789,    // FIRST_DERIV_PROVIDED
    SECOND_DERIV_PROVIDED = 790,   // SECOND_DERIV_PROVIDED
    SELECTED_VARIABLES_ONLY = 791, // SELECTED_VARIABLES_ONLY
    COVA_COMPUTE = 792,            // COVA_COMPUTE
    SIMULATION_FILE_TAG = 793,     // SIMULATION_FILE_TAG
    FILE_TAG = 794,                // FILE_TAG
    NO_ERROR_BANDS = 795,          // NO_ERROR_BANDS
    ERROR_BAND_PERCENTILES = 796,  // ERROR_BAND_PERCENTILES
    SHOCKS_PER_PARAMETER = 797,    // SHOCKS_PER_PARAMETER
    NO_CREATE_INIT = 798,          // NO_CREATE_INIT
    SHOCK_DRAWS = 799,             // SHOCK_DRAWS
    FREE_PARAMETERS = 800,         // FREE_PARAMETERS
    MEDIAN = 801,                  // MEDIAN
    DATA_OBS_NBR = 802,            // DATA_OBS_NBR
    NEIGHBORHOOD_WIDTH = 803,      // NEIGHBORHOOD_WIDTH
    PVALUE_KS = 804,               // PVALUE_KS
    PVALUE_CORR = 805,             // PVALUE_CORR
    FILTERED_PROBABILITIES = 806,  // FILTERED_PROBABILITIES
    REAL_TIME_SMOOTHED = 807,      // REAL_TIME_SMOOTHED
    PRIOR_FUNCTION = 808,          // PRIOR_FUNCTION
    POSTERIOR_FUNCTION = 809,      // POSTERIOR_FUNCTION
    SAMPLING_DRAWS = 810,          // SAMPLING_DRAWS
    PROPOSAL_TYPE = 811,           // PROPOSAL_TYPE
    PROPOSAL_UPPER_BOUND = 812,    // PROPOSAL_UPPER_BOUND
    PROPOSAL_LOWER_BOUND = 813,    // PROPOSAL_LOWER_BOUND
    PROPOSAL_DRAWS = 814,          // PROPOSAL_DRAWS
    USE_MEAN_CENTER = 815,         // USE_MEAN_CENTER
    ADAPTIVE_MH_DRAWS = 816,       // ADAPTIVE_MH_DRAWS
    THINNING_FACTOR = 817,         // THINNING_FACTOR
    COEFFICIENTS_PRIOR_HYPERPARAMETERS = 818, // COEFFICIENTS_PRIOR_HYPERPARAMETERS
    CONVERGENCE_STARTING_VALUE = 819, // CONVERGENCE_STARTING_VALUE
    CONVERGENCE_ENDING_VALUE = 820, // CONVERGENCE_ENDING_VALUE
    CONVERGENCE_INCREMENT_VALUE = 821, // CONVERGENCE_INCREMENT_VALUE
    MAX_ITERATIONS_STARTING_VALUE = 822, // MAX_ITERATIONS_STARTING_VALUE
    MAX_ITERATIONS_INCREMENT_VALUE = 823, // MAX_ITERATIONS_INCREMENT_VALUE
    MAX_BLOCK_ITERATIONS = 824,    // MAX_BLOCK_ITERATIONS
    MAX_REPEATED_OPTIMIZATION_RUNS = 825, // MAX_REPEATED_OPTIMIZATION_RUNS
    FUNCTION_CONVERGENCE_CRITERION = 826, // FUNCTION_CONVERGENCE_CRITERION
    SAVE_REALTIME = 827,           // SAVE_REALTIME
    PARAMETER_CONVERGENCE_CRITERION = 828, // PARAMETER_CONVERGENCE_CRITERION
    NUMBER_OF_LARGE_PERTURBATIONS = 829, // NUMBER_OF_LARGE_PERTURBATIONS
    NUMBER_OF_SMALL_PERTURBATIONS = 830, // NUMBER_OF_SMALL_PERTURBATIONS
    NUMBER_OF_POSTERIOR_DRAWS_AFTER_PERTURBATION = 831, // NUMBER_OF_POSTERIOR_DRAWS_AFTER_PERTURBATION
    MAX_NUMBER_OF_STAGES = 832,    // MAX_NUMBER_OF_STAGES
    RANDOM_FUNCTION_CONVERGENCE_CRITERION = 833, // RANDOM_FUNCTION_CONVERGENCE_CRITERION
    RANDOM_PARAMETER_CONVERGENCE_CRITERION = 834, // RANDOM_PARAMETER_CONVERGENCE_CRITERION
    SYMBOL_VEC = 835               // SYMBOL_VEC
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::token_kind_type token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 589, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_AIM_SOLVER = 3,                        // AIM_SOLVER
        S_ANALYTIC_DERIVATION = 4,               // ANALYTIC_DERIVATION
        S_ANALYTIC_DERIVATION_MODE = 5,          // ANALYTIC_DERIVATION_MODE
        S_AR = 6,                                // AR
        S_AUTOCORR = 7,                          // AUTOCORR
        S_POSTERIOR_SAMPLING_METHOD = 8,         // POSTERIOR_SAMPLING_METHOD
        S_BAYESIAN_IRF = 9,                      // BAYESIAN_IRF
        S_BETA_PDF = 10,                         // BETA_PDF
        S_BLOCK = 11,                            // BLOCK
        S_USE_CALIBRATION = 12,                  // USE_CALIBRATION
        S_SILENT_OPTIMIZER = 13,                 // SILENT_OPTIMIZER
        S_BVAR_DENSITY = 14,                     // BVAR_DENSITY
        S_BVAR_FORECAST = 15,                    // BVAR_FORECAST
        S_NODECOMPOSITION = 16,                  // NODECOMPOSITION
        S_DR_DISPLAY_TOL = 17,                   // DR_DISPLAY_TOL
        S_HUGE_NUMBER = 18,                      // HUGE_NUMBER
        S_FIG_NAME = 19,                         // FIG_NAME
        S_WRITE_XLS = 20,                        // WRITE_XLS
        S_BVAR_PRIOR_DECAY = 21,                 // BVAR_PRIOR_DECAY
        S_BVAR_PRIOR_FLAT = 22,                  // BVAR_PRIOR_FLAT
        S_BVAR_PRIOR_LAMBDA = 23,                // BVAR_PRIOR_LAMBDA
        S_INTERACTIVE = 24,                      // INTERACTIVE
        S_SCREEN_SHOCKS = 25,                    // SCREEN_SHOCKS
        S_STEADYSTATE = 26,                      // STEADYSTATE
        S_BVAR_PRIOR_MU = 27,                    // BVAR_PRIOR_MU
        S_BVAR_PRIOR_OMEGA = 28,                 // BVAR_PRIOR_OMEGA
        S_BVAR_PRIOR_TAU = 29,                   // BVAR_PRIOR_TAU
        S_BVAR_PRIOR_TRAIN = 30,                 // BVAR_PRIOR_TRAIN
        S_DETAIL_PLOT = 31,                      // DETAIL_PLOT
        S_TYPE = 32,                             // TYPE
        S_BVAR_REPLIC = 33,                      // BVAR_REPLIC
        S_BYTECODE = 34,                         // BYTECODE
        S_ALL_VALUES_REQUIRED = 35,              // ALL_VALUES_REQUIRED
        S_PROPOSAL_DISTRIBUTION = 36,            // PROPOSAL_DISTRIBUTION
        S_REALTIME = 37,                         // REALTIME
        S_VINTAGE = 38,                          // VINTAGE
        S_CALIB_SMOOTHER = 39,                   // CALIB_SMOOTHER
        S_CHANGE_TYPE = 40,                      // CHANGE_TYPE
        S_CHECK = 41,                            // CHECK
        S_CONDITIONAL_FORECAST = 42,             // CONDITIONAL_FORECAST
        S_CONDITIONAL_FORECAST_PATHS = 43,       // CONDITIONAL_FORECAST_PATHS
        S_CONF_SIG = 44,                         // CONF_SIG
        S_CONSTANT = 45,                         // CONSTANT
        S_CONTROLLED_VAREXO = 46,                // CONTROLLED_VAREXO
        S_CORR = 47,                             // CORR
        S_COVAR = 48,                            // COVAR
        S_CUTOFF = 49,                           // CUTOFF
        S_CYCLE_REDUCTION = 50,                  // CYCLE_REDUCTION
        S_LOGARITHMIC_REDUCTION = 51,            // LOGARITHMIC_REDUCTION
        S_CONSIDER_ALL_ENDOGENOUS = 52,          // CONSIDER_ALL_ENDOGENOUS
        S_CONSIDER_ONLY_OBSERVED = 53,           // CONSIDER_ONLY_OBSERVED
        S_INITIAL_CONDITION_DECOMPOSITION = 54,  // INITIAL_CONDITION_DECOMPOSITION
        S_DATAFILE = 55,                         // DATAFILE
        S_FILE = 56,                             // FILE
        S_SERIES = 57,                           // SERIES
        S_DOUBLING = 58,                         // DOUBLING
        S_DR_CYCLE_REDUCTION_TOL = 59,           // DR_CYCLE_REDUCTION_TOL
        S_DR_LOGARITHMIC_REDUCTION_TOL = 60,     // DR_LOGARITHMIC_REDUCTION_TOL
        S_DR_LOGARITHMIC_REDUCTION_MAXITER = 61, // DR_LOGARITHMIC_REDUCTION_MAXITER
        S_DR_ALGO = 62,                          // DR_ALGO
        S_DROP = 63,                             // DROP
        S_DSAMPLE = 64,                          // DSAMPLE
        S_DYNASAVE = 65,                         // DYNASAVE
        S_DYNATYPE = 66,                         // DYNATYPE
        S_CALIBRATION = 67,                      // CALIBRATION
        S_DIFFERENTIATE_FORWARD_VARS = 68,       // DIFFERENTIATE_FORWARD_VARS
        S_END = 69,                              // END
        S_ENDVAL = 70,                           // ENDVAL
        S_EQUAL = 71,                            // EQUAL
        S_ESTIMATION = 72,                       // ESTIMATION
        S_ESTIMATED_PARAMS = 73,                 // ESTIMATED_PARAMS
        S_ESTIMATED_PARAMS_BOUNDS = 74,          // ESTIMATED_PARAMS_BOUNDS
        S_ESTIMATED_PARAMS_INIT = 75,            // ESTIMATED_PARAMS_INIT
        S_EXTENDED_PATH = 76,                    // EXTENDED_PATH
        S_ENDOGENOUS_PRIOR = 77,                 // ENDOGENOUS_PRIOR
        S_FILENAME = 78,                         // FILENAME
        S_DIRNAME = 79,                          // DIRNAME
        S_FILTER_STEP_AHEAD = 80,                // FILTER_STEP_AHEAD
        S_FILTERED_VARS = 81,                    // FILTERED_VARS
        S_FIRST_OBS = 82,                        // FIRST_OBS
        S_LAST_OBS = 83,                         // LAST_OBS
        S_SET_TIME = 84,                         // SET_TIME
        S_OSR_PARAMS_BOUNDS = 85,                // OSR_PARAMS_BOUNDS
        S_KEEP_KALMAN_ALGO_IF_SINGULARITY_IS_DETECTED = 86, // KEEP_KALMAN_ALGO_IF_SINGULARITY_IS_DETECTED
        S_FLOAT_NUMBER = 87,                     // FLOAT_NUMBER
        S_DATES = 88,                            // DATES
        S_DEFAULT = 89,                          // DEFAULT
        S_FIXED_POINT = 90,                      // FIXED_POINT
        S_OPT_ALGO = 91,                         // OPT_ALGO
        S_FORECAST = 92,                         // FORECAST
        S_K_ORDER_SOLVER = 93,                   // K_ORDER_SOLVER
        S_INSTRUMENTS = 94,                      // INSTRUMENTS
        S_SHIFT = 95,                            // SHIFT
        S_MEAN = 96,                             // MEAN
        S_STDEV = 97,                            // STDEV
        S_VARIANCE = 98,                         // VARIANCE
        S_MODE = 99,                             // MODE
        S_INTERVAL = 100,                        // INTERVAL
        S_SHAPE = 101,                           // SHAPE
        S_DOMAINN = 102,                         // DOMAINN
        S_GAMMA_PDF = 103,                       // GAMMA_PDF
        S_GRAPH = 104,                           // GRAPH
        S_GRAPH_FORMAT = 105,                    // GRAPH_FORMAT
        S_CONDITIONAL_VARIANCE_DECOMPOSITION = 106, // CONDITIONAL_VARIANCE_DECOMPOSITION
        S_NOCHECK = 107,                         // NOCHECK
        S_STD = 108,                             // STD
        S_HISTVAL = 109,                         // HISTVAL
        S_HISTVAL_FILE = 110,                    // HISTVAL_FILE
        S_HOMOTOPY_SETUP = 111,                  // HOMOTOPY_SETUP
        S_HOMOTOPY_MODE = 112,                   // HOMOTOPY_MODE
        S_HOMOTOPY_STEPS = 113,                  // HOMOTOPY_STEPS
        S_HOMOTOPY_FORCE_CONTINUE = 114,         // HOMOTOPY_FORCE_CONTINUE
        S_HP_FILTER = 115,                       // HP_FILTER
        S_HP_NGRID = 116,                        // HP_NGRID
        S_HYBRID = 117,                          // HYBRID
        S_ONE_SIDED_HP_FILTER = 118,             // ONE_SIDED_HP_FILTER
        S_IDENTIFICATION = 119,                  // IDENTIFICATION
        S_INF_CONSTANT = 120,                    // INF_CONSTANT
        S_INITVAL = 121,                         // INITVAL
        S_INITVAL_FILE = 122,                    // INITVAL_FILE
        S_BOUNDS = 123,                          // BOUNDS
        S_JSCALE = 124,                          // JSCALE
        S_INIT = 125,                            // INIT
        S_INFILE = 126,                          // INFILE
        S_INVARS = 127,                          // INVARS
        S_INT_NUMBER = 128,                      // INT_NUMBER
        S_INV_GAMMA_PDF = 129,                   // INV_GAMMA_PDF
        S_INV_GAMMA1_PDF = 130,                  // INV_GAMMA1_PDF
        S_INV_GAMMA2_PDF = 131,                  // INV_GAMMA2_PDF
        S_IRF = 132,                             // IRF
        S_IRF_SHOCKS = 133,                      // IRF_SHOCKS
        S_IRF_PLOT_THRESHOLD = 134,              // IRF_PLOT_THRESHOLD
        S_IRF_CALIBRATION = 135,                 // IRF_CALIBRATION
        S_FAST_KALMAN_FILTER = 136,              // FAST_KALMAN_FILTER
        S_KALMAN_ALGO = 137,                     // KALMAN_ALGO
        S_KALMAN_TOL = 138,                      // KALMAN_TOL
        S_DIFFUSE_KALMAN_TOL = 139,              // DIFFUSE_KALMAN_TOL
        S_SUBSAMPLES = 140,                      // SUBSAMPLES
        S_OPTIONS = 141,                         // OPTIONS
        S_TOLF = 142,                            // TOLF
        S_TOLX = 143,                            // TOLX
        S_PLOT_INIT_DATE = 144,                  // PLOT_INIT_DATE
        S_PLOT_END_DATE = 145,                   // PLOT_END_DATE
        S_LAPLACE = 146,                         // LAPLACE
        S_LIK_ALGO = 147,                        // LIK_ALGO
        S_LIK_INIT = 148,                        // LIK_INIT
        S_LINEAR = 149,                          // LINEAR
        S_LOAD_IDENT_FILES = 150,                // LOAD_IDENT_FILES
        S_LOAD_MH_FILE = 151,                    // LOAD_MH_FILE
        S_LOAD_RESULTS_AFTER_LOAD_MH = 152,      // LOAD_RESULTS_AFTER_LOAD_MH
        S_LOAD_PARAMS_AND_STEADY_STATE = 153,    // LOAD_PARAMS_AND_STEADY_STATE
        S_LOGLINEAR = 154,                       // LOGLINEAR
        S_LOGDATA = 155,                         // LOGDATA
        S_LYAPUNOV = 156,                        // LYAPUNOV
        S_LINEAR_APPROXIMATION = 157,            // LINEAR_APPROXIMATION
        S_LYAPUNOV_FIXED_POINT_TOL = 158,        // LYAPUNOV_FIXED_POINT_TOL
        S_LYAPUNOV_DOUBLING_TOL = 159,           // LYAPUNOV_DOUBLING_TOL
        S_LYAPUNOV_SQUARE_ROOT_SOLVER_TOL = 160, // LYAPUNOV_SQUARE_ROOT_SOLVER_TOL
        S_LOG_DEFLATOR = 161,                    // LOG_DEFLATOR
        S_LOG_TREND_VAR = 162,                   // LOG_TREND_VAR
        S_LOG_GROWTH_FACTOR = 163,               // LOG_GROWTH_FACTOR
        S_MARKOWITZ = 164,                       // MARKOWITZ
        S_MARGINAL_DENSITY = 165,                // MARGINAL_DENSITY
        S_MAX = 166,                             // MAX
        S_MAXIT = 167,                           // MAXIT
        S_MFS = 168,                             // MFS
        S_MH_CONF_SIG = 169,                     // MH_CONF_SIG
        S_MH_DROP = 170,                         // MH_DROP
        S_MH_INIT_SCALE = 171,                   // MH_INIT_SCALE
        S_MH_JSCALE = 172,                       // MH_JSCALE
        S_MH_MODE = 173,                         // MH_MODE
        S_MH_NBLOCKS = 174,                      // MH_NBLOCKS
        S_MH_REPLIC = 175,                       // MH_REPLIC
        S_MH_RECOVER = 176,                      // MH_RECOVER
        S_POSTERIOR_MAX_SUBSAMPLE_DRAWS = 177,   // POSTERIOR_MAX_SUBSAMPLE_DRAWS
        S_MIN = 178,                             // MIN
        S_MINIMAL_SOLVING_PERIODS = 179,         // MINIMAL_SOLVING_PERIODS
        S_MODE_CHECK = 180,                      // MODE_CHECK
        S_MODE_CHECK_NEIGHBOURHOOD_SIZE = 181,   // MODE_CHECK_NEIGHBOURHOOD_SIZE
        S_MODE_CHECK_SYMMETRIC_PLOTS = 182,      // MODE_CHECK_SYMMETRIC_PLOTS
        S_MODE_CHECK_NUMBER_OF_POINTS = 183,     // MODE_CHECK_NUMBER_OF_POINTS
        S_MODE_COMPUTE = 184,                    // MODE_COMPUTE
        S_MODE_FILE = 185,                       // MODE_FILE
        S_MODEL = 186,                           // MODEL
        S_MODEL_COMPARISON = 187,                // MODEL_COMPARISON
        S_MODEL_INFO = 188,                      // MODEL_INFO
        S_MSHOCKS = 189,                         // MSHOCKS
        S_ABS = 190,                             // ABS
        S_SIGN = 191,                            // SIGN
        S_MODEL_DIAGNOSTICS = 192,               // MODEL_DIAGNOSTICS
        S_MODIFIEDHARMONICMEAN = 193,            // MODIFIEDHARMONICMEAN
        S_MOMENTS_VARENDO = 194,                 // MOMENTS_VARENDO
        S_CONTEMPORANEOUS_CORRELATION = 195,     // CONTEMPORANEOUS_CORRELATION
        S_DIFFUSE_FILTER = 196,                  // DIFFUSE_FILTER
        S_SUB_DRAWS = 197,                       // SUB_DRAWS
        S_TAPER_STEPS = 198,                     // TAPER_STEPS
        S_GEWEKE_INTERVAL = 199,                 // GEWEKE_INTERVAL
        S_RAFTERY_LEWIS_QRS = 200,               // RAFTERY_LEWIS_QRS
        S_RAFTERY_LEWIS_DIAGNOSTICS = 201,       // RAFTERY_LEWIS_DIAGNOSTICS
        S_MCMC_JUMPING_COVARIANCE = 202,         // MCMC_JUMPING_COVARIANCE
        S_MOMENT_CALIBRATION = 203,              // MOMENT_CALIBRATION
        S_NUMBER_OF_PARTICLES = 204,             // NUMBER_OF_PARTICLES
        S_RESAMPLING = 205,                      // RESAMPLING
        S_SYSTEMATIC = 206,                      // SYSTEMATIC
        S_GENERIC = 207,                         // GENERIC
        S_RESAMPLING_THRESHOLD = 208,            // RESAMPLING_THRESHOLD
        S_RESAMPLING_METHOD = 209,               // RESAMPLING_METHOD
        S_KITAGAWA = 210,                        // KITAGAWA
        S_STRATIFIED = 211,                      // STRATIFIED
        S_SMOOTH = 212,                          // SMOOTH
        S_CPF_WEIGHTS = 213,                     // CPF_WEIGHTS
        S_AMISANOTRISTANI = 214,                 // AMISANOTRISTANI
        S_MURRAYJONESPARSLOW = 215,              // MURRAYJONESPARSLOW
        S_WRITE_EQUATION_TAGS = 216,             // WRITE_EQUATION_TAGS
        S_NONLINEAR_FILTER_INITIALIZATION = 217, // NONLINEAR_FILTER_INITIALIZATION
        S_FILTER_ALGORITHM = 218,                // FILTER_ALGORITHM
        S_PROPOSAL_APPROXIMATION = 219,          // PROPOSAL_APPROXIMATION
        S_CUBATURE = 220,                        // CUBATURE
        S_UNSCENTED = 221,                       // UNSCENTED
        S_MONTECARLO = 222,                      // MONTECARLO
        S_DISTRIBUTION_APPROXIMATION = 223,      // DISTRIBUTION_APPROXIMATION
        S_NAME = 224,                            // NAME
        S_USE_PENALIZED_OBJECTIVE_FOR_HESSIAN = 225, // USE_PENALIZED_OBJECTIVE_FOR_HESSIAN
        S_INIT_STATE = 226,                      // INIT_STATE
        S_RESCALE_PREDICTION_ERROR_COVARIANCE = 227, // RESCALE_PREDICTION_ERROR_COVARIANCE
        S_NAN_CONSTANT = 228,                    // NAN_CONSTANT
        S_NO_STATIC = 229,                       // NO_STATIC
        S_NOBS = 230,                            // NOBS
        S_NOCONSTANT = 231,                      // NOCONSTANT
        S_NODISPLAY = 232,                       // NODISPLAY
        S_NOCORR = 233,                          // NOCORR
        S_NODIAGNOSTIC = 234,                    // NODIAGNOSTIC
        S_NOFUNCTIONS = 235,                     // NOFUNCTIONS
        S_NO_HOMOTOPY = 236,                     // NO_HOMOTOPY
        S_NOGRAPH = 237,                         // NOGRAPH
        S_POSTERIOR_NOGRAPH = 238,               // POSTERIOR_NOGRAPH
        S_POSTERIOR_GRAPH = 239,                 // POSTERIOR_GRAPH
        S_NOMOMENTS = 240,                       // NOMOMENTS
        S_NOPRINT = 241,                         // NOPRINT
        S_NORMAL_PDF = 242,                      // NORMAL_PDF
        S_SAVE_DRAWS = 243,                      // SAVE_DRAWS
        S_OBSERVATION_TRENDS = 244,              // OBSERVATION_TRENDS
        S_OPTIM = 245,                           // OPTIM
        S_OPTIM_WEIGHTS = 246,                   // OPTIM_WEIGHTS
        S_ORDER = 247,                           // ORDER
        S_OSR = 248,                             // OSR
        S_OSR_PARAMS = 249,                      // OSR_PARAMS
        S_MAX_DIM_COVA_GROUP = 250,              // MAX_DIM_COVA_GROUP
        S_ADVANCED = 251,                        // ADVANCED
        S_OUTFILE = 252,                         // OUTFILE
        S_OUTVARS = 253,                         // OUTVARS
        S_OVERWRITE = 254,                       // OVERWRITE
        S_PARALLEL_LOCAL_FILES = 255,            // PARALLEL_LOCAL_FILES
        S_PARAMETERS = 256,                      // PARAMETERS
        S_PARAMETER_SET = 257,                   // PARAMETER_SET
        S_PARTIAL_INFORMATION = 258,             // PARTIAL_INFORMATION
        S_PERIODS = 259,                         // PERIODS
        S_PERIOD = 260,                          // PERIOD
        S_PLANNER_OBJECTIVE = 261,               // PLANNER_OBJECTIVE
        S_PLOT_CONDITIONAL_FORECAST = 262,       // PLOT_CONDITIONAL_FORECAST
        S_PLOT_PRIORS = 263,                     // PLOT_PRIORS
        S_PREFILTER = 264,                       // PREFILTER
        S_PRESAMPLE = 265,                       // PRESAMPLE
        S_PERFECT_FORESIGHT_SETUP = 266,         // PERFECT_FORESIGHT_SETUP
        S_PERFECT_FORESIGHT_SOLVER = 267,        // PERFECT_FORESIGHT_SOLVER
        S_NO_POSTERIOR_KERNEL_DENSITY = 268,     // NO_POSTERIOR_KERNEL_DENSITY
        S_FUNCTION = 269,                        // FUNCTION
        S_PRINT = 270,                           // PRINT
        S_PRIOR_MC = 271,                        // PRIOR_MC
        S_PRIOR_TRUNC = 272,                     // PRIOR_TRUNC
        S_PRIOR_MODE = 273,                      // PRIOR_MODE
        S_PRIOR_MEAN = 274,                      // PRIOR_MEAN
        S_POSTERIOR_MODE = 275,                  // POSTERIOR_MODE
        S_POSTERIOR_MEAN = 276,                  // POSTERIOR_MEAN
        S_POSTERIOR_MEDIAN = 277,                // POSTERIOR_MEDIAN
        S_MLE_MODE = 278,                        // MLE_MODE
        S_PRUNING = 279,                         // PRUNING
        S_QUOTED_STRING = 280,                   // QUOTED_STRING
        S_QZ_CRITERIUM = 281,                    // QZ_CRITERIUM
        S_QZ_ZERO_THRESHOLD = 282,               // QZ_ZERO_THRESHOLD
        S_FULL = 283,                            // FULL
        S_DSGE_VAR = 284,                        // DSGE_VAR
        S_DSGE_VARLAG = 285,                     // DSGE_VARLAG
        S_DSGE_PRIOR_WEIGHT = 286,               // DSGE_PRIOR_WEIGHT
        S_TRUNCATE = 287,                        // TRUNCATE
        S_RELATIVE_IRF = 288,                    // RELATIVE_IRF
        S_REPLIC = 289,                          // REPLIC
        S_SIMUL_REPLIC = 290,                    // SIMUL_REPLIC
        S_RPLOT = 291,                           // RPLOT
        S_SAVE_PARAMS_AND_STEADY_STATE = 292,    // SAVE_PARAMS_AND_STEADY_STATE
        S_PARAMETER_UNCERTAINTY = 293,           // PARAMETER_UNCERTAINTY
        S_SHOCKS = 294,                          // SHOCKS
        S_SHOCK_DECOMPOSITION = 295,             // SHOCK_DECOMPOSITION
        S_SHOCK_GROUPS = 296,                    // SHOCK_GROUPS
        S_USE_SHOCK_GROUPS = 297,                // USE_SHOCK_GROUPS
        S_SIGMA_E = 298,                         // SIGMA_E
        S_SIMUL = 299,                           // SIMUL
        S_SIMUL_ALGO = 300,                      // SIMUL_ALGO
        S_SIMUL_SEED = 301,                      // SIMUL_SEED
        S_ENDOGENOUS_TERMINAL_PERIOD = 302,      // ENDOGENOUS_TERMINAL_PERIOD
        S_SMOOTHER = 303,                        // SMOOTHER
        S_SMOOTHER2HISTVAL = 304,                // SMOOTHER2HISTVAL
        S_SQUARE_ROOT_SOLVER = 305,              // SQUARE_ROOT_SOLVER
        S_STACK_SOLVE_ALGO = 306,                // STACK_SOLVE_ALGO
        S_STEADY_STATE_MODEL = 307,              // STEADY_STATE_MODEL
        S_SOLVE_ALGO = 308,                      // SOLVE_ALGO
        S_SOLVER_PERIODS = 309,                  // SOLVER_PERIODS
        S_ROBUST_LIN_SOLVE = 310,                // ROBUST_LIN_SOLVE
        S_STDERR = 311,                          // STDERR
        S_STEADY = 312,                          // STEADY
        S_STOCH_SIMUL = 313,                     // STOCH_SIMUL
        S_SURPRISE = 314,                        // SURPRISE
        S_SYLVESTER = 315,                       // SYLVESTER
        S_SYLVESTER_FIXED_POINT_TOL = 316,       // SYLVESTER_FIXED_POINT_TOL
        S_REGIMES = 317,                         // REGIMES
        S_REGIME = 318,                          // REGIME
        S_REALTIME_SHOCK_DECOMPOSITION = 319,    // REALTIME_SHOCK_DECOMPOSITION
        S_TEX = 320,                             // TEX
        S_RAMSEY_MODEL = 321,                    // RAMSEY_MODEL
        S_RAMSEY_POLICY = 322,                   // RAMSEY_POLICY
        S_RAMSEY_CONSTRAINTS = 323,              // RAMSEY_CONSTRAINTS
        S_PLANNER_DISCOUNT = 324,                // PLANNER_DISCOUNT
        S_DISCRETIONARY_POLICY = 325,            // DISCRETIONARY_POLICY
        S_DISCRETIONARY_TOL = 326,               // DISCRETIONARY_TOL
        S_TEX_NAME = 327,                        // TEX_NAME
        S_UNIFORM_PDF = 328,                     // UNIFORM_PDF
        S_UNIT_ROOT_VARS = 329,                  // UNIT_ROOT_VARS
        S_USE_DLL = 330,                         // USE_DLL
        S_USEAUTOCORR = 331,                     // USEAUTOCORR
        S_GSA_SAMPLE_FILE = 332,                 // GSA_SAMPLE_FILE
        S_USE_UNIVARIATE_FILTERS_IF_SINGULARITY_IS_DETECTED = 333, // USE_UNIVARIATE_FILTERS_IF_SINGULARITY_IS_DETECTED
        S_VALUES = 334,                          // VALUES
        S_VAR = 335,                             // VAR
        S_VAREXO = 336,                          // VAREXO
        S_VAREXO_DET = 337,                      // VAREXO_DET
        S_VAROBS = 338,                          // VAROBS
        S_PREDETERMINED_VARIABLES = 339,         // PREDETERMINED_VARIABLES
        S_PLOT_SHOCK_DECOMPOSITION = 340,        // PLOT_SHOCK_DECOMPOSITION
        S_WRITE_LATEX_DYNAMIC_MODEL = 341,       // WRITE_LATEX_DYNAMIC_MODEL
        S_WRITE_LATEX_STATIC_MODEL = 342,        // WRITE_LATEX_STATIC_MODEL
        S_WRITE_LATEX_ORIGINAL_MODEL = 343,      // WRITE_LATEX_ORIGINAL_MODEL
        S_XLS_SHEET = 344,                       // XLS_SHEET
        S_XLS_RANGE = 345,                       // XLS_RANGE
        S_LMMCP = 346,                           // LMMCP
        S_OCCBIN = 347,                          // OCCBIN
        S_BANDPASS_FILTER = 348,                 // BANDPASS_FILTER
        S_COLORMAP = 349,                        // COLORMAP
        S_QOQ = 350,                             // QOQ
        S_YOY = 351,                             // YOY
        S_AOA = 352,                             // AOA
        S_COMMA = 353,                           // COMMA
        S_EQUAL_EQUAL = 354,                     // EQUAL_EQUAL
        S_EXCLAMATION_EQUAL = 355,               // EXCLAMATION_EQUAL
        S_LESS = 356,                            // LESS
        S_GREATER = 357,                         // GREATER
        S_LESS_EQUAL = 358,                      // LESS_EQUAL
        S_GREATER_EQUAL = 359,                   // GREATER_EQUAL
        S_PLUS = 360,                            // PLUS
        S_MINUS = 361,                           // MINUS
        S_TIMES = 362,                           // TIMES
        S_DIVIDE = 363,                          // DIVIDE
        S_UMINUS = 364,                          // UMINUS
        S_UPLUS = 365,                           // UPLUS
        S_POWER = 366,                           // POWER
        S_EXP = 367,                             // EXP
        S_LOG = 368,                             // LOG
        S_LN = 369,                              // LN
        S_LOG10 = 370,                           // LOG10
        S_LINLOG = 371,                          // LINLOG
        S_LINPOW = 372,                          // LINPOW
        S_SIN = 373,                             // SIN
        S_COS = 374,                             // COS
        S_TAN = 375,                             // TAN
        S_ASIN = 376,                            // ASIN
        S_ACOS = 377,                            // ACOS
        S_ATAN = 378,                            // ATAN
        S_SINH = 379,                            // SINH
        S_COSH = 380,                            // COSH
        S_TANH = 381,                            // TANH
        S_ERF = 382,                             // ERF
        S_ASINH = 383,                           // ASINH
        S_ACOSH = 384,                           // ACOSH
        S_ATANH = 385,                           // ATANH
        S_SQRT = 386,                            // SQRT
        S_NORMCDF = 387,                         // NORMCDF
        S_NORMPDF = 388,                         // NORMPDF
        S_STEADY_STATE = 389,                    // STEADY_STATE
        S_EXPECTATION = 390,                     // EXPECTATION
        S_DYNARE_SENSITIVITY = 391,              // DYNARE_SENSITIVITY
        S_MORRIS = 392,                          // MORRIS
        S_STAB = 393,                            // STAB
        S_REDFORM = 394,                         // REDFORM
        S_PPRIOR = 395,                          // PPRIOR
        S_PRIOR_RANGE = 396,                     // PRIOR_RANGE
        S_PPOST = 397,                           // PPOST
        S_ILPTAU = 398,                          // ILPTAU
        S_MORRIS_NLIV = 399,                     // MORRIS_NLIV
        S_MORRIS_NTRA = 400,                     // MORRIS_NTRA
        S_NSAM = 401,                            // NSAM
        S_LOAD_REDFORM = 402,                    // LOAD_REDFORM
        S_LOAD_RMSE = 403,                       // LOAD_RMSE
        S_LOAD_STAB = 404,                       // LOAD_STAB
        S_ALPHA2_STAB = 405,                     // ALPHA2_STAB
        S_LOGTRANS_REDFORM = 406,                // LOGTRANS_REDFORM
        S_THRESHOLD_REDFORM = 407,               // THRESHOLD_REDFORM
        S_KSSTAT_REDFORM = 408,                  // KSSTAT_REDFORM
        S_ALPHA2_REDFORM = 409,                  // ALPHA2_REDFORM
        S_NAMENDO = 410,                         // NAMENDO
        S_NAMLAGENDO = 411,                      // NAMLAGENDO
        S_NAMEXO = 412,                          // NAMEXO
        S_RMSE = 413,                            // RMSE
        S_LIK_ONLY = 414,                        // LIK_ONLY
        S_VAR_RMSE = 415,                        // VAR_RMSE
        S_PFILT_RMSE = 416,                      // PFILT_RMSE
        S_ISTART_RMSE = 417,                     // ISTART_RMSE
        S_ALPHA_RMSE = 418,                      // ALPHA_RMSE
        S_ALPHA2_RMSE = 419,                     // ALPHA2_RMSE
        S_FREQ = 420,                            // FREQ
        S_INITIAL_YEAR = 421,                    // INITIAL_YEAR
        S_INITIAL_SUBPERIOD = 422,               // INITIAL_SUBPERIOD
        S_FINAL_YEAR = 423,                      // FINAL_YEAR
        S_FINAL_SUBPERIOD = 424,                 // FINAL_SUBPERIOD
        S_DATA = 425,                            // DATA
        S_VLIST = 426,                           // VLIST
        S_LOG_VAR = 427,                         // LOG_VAR
        S_PERCENT_VAR = 428,                     // PERCENT_VAR
        S_VLISTLOG = 429,                        // VLISTLOG
        S_VLISTPER = 430,                        // VLISTPER
        S_SPECTRAL_DENSITY = 431,                // SPECTRAL_DENSITY
        S_RESTRICTION = 432,                     // RESTRICTION
        S_RESTRICTION_FNAME = 433,               // RESTRICTION_FNAME
        S_CROSS_RESTRICTIONS = 434,              // CROSS_RESTRICTIONS
        S_NLAGS = 435,                           // NLAGS
        S_CONTEMP_REDUCED_FORM = 436,            // CONTEMP_REDUCED_FORM
        S_REAL_PSEUDO_FORECAST = 437,            // REAL_PSEUDO_FORECAST
        S_DUMMY_OBS = 438,                       // DUMMY_OBS
        S_NSTATES = 439,                         // NSTATES
        S_INDXSCALESSTATES = 440,                // INDXSCALESSTATES
        S_NO_BAYESIAN_PRIOR = 441,               // NO_BAYESIAN_PRIOR
        S_SPECIFICATION = 442,                   // SPECIFICATION
        S_SIMS_ZHA = 443,                        // SIMS_ZHA
        S_ALPHA = 444,                           // ALPHA
        S_BETA = 445,                            // BETA
        S_ABAND = 446,                           // ABAND
        S_NINV = 447,                            // NINV
        S_CMS = 448,                             // CMS
        S_NCMS = 449,                            // NCMS
        S_CNUM = 450,                            // CNUM
        S_GAMMA = 451,                           // GAMMA
        S_INV_GAMMA = 452,                       // INV_GAMMA
        S_INV_GAMMA1 = 453,                      // INV_GAMMA1
        S_INV_GAMMA2 = 454,                      // INV_GAMMA2
        S_NORMAL = 455,                          // NORMAL
        S_UNIFORM = 456,                         // UNIFORM
        S_EPS = 457,                             // EPS
        S_PDF = 458,                             // PDF
        S_FIG = 459,                             // FIG
        S_DR = 460,                              // DR
        S_NONE = 461,                            // NONE
        S_PRIOR = 462,                           // PRIOR
        S_PRIOR_VARIANCE = 463,                  // PRIOR_VARIANCE
        S_HESSIAN = 464,                         // HESSIAN
        S_IDENTITY_MATRIX = 465,                 // IDENTITY_MATRIX
        S_DIRICHLET = 466,                       // DIRICHLET
        S_GSIG2_LMDM = 467,                      // GSIG2_LMDM
        S_Q_DIAG = 468,                          // Q_DIAG
        S_FLAT_PRIOR = 469,                      // FLAT_PRIOR
        S_NCSK = 470,                            // NCSK
        S_NSTD = 471,                            // NSTD
        S_WEIBULL = 472,                         // WEIBULL
        S_WEIBULL_PDF = 473,                     // WEIBULL_PDF
        S_INDXPARR = 474,                        // INDXPARR
        S_INDXOVR = 475,                         // INDXOVR
        S_INDXAP = 476,                          // INDXAP
        S_APBAND = 477,                          // APBAND
        S_INDXIMF = 478,                         // INDXIMF
        S_IMFBAND = 479,                         // IMFBAND
        S_INDXFORE = 480,                        // INDXFORE
        S_FOREBAND = 481,                        // FOREBAND
        S_INDXGFOREHAT = 482,                    // INDXGFOREHAT
        S_INDXGIMFHAT = 483,                     // INDXGIMFHAT
        S_INDXESTIMA = 484,                      // INDXESTIMA
        S_INDXGDLS = 485,                        // INDXGDLS
        S_EQ_MS = 486,                           // EQ_MS
        S_FILTER_COVARIANCE = 487,               // FILTER_COVARIANCE
        S_FILTER_DECOMPOSITION = 488,            // FILTER_DECOMPOSITION
        S_SMOOTHED_STATE_UNCERTAINTY = 489,      // SMOOTHED_STATE_UNCERTAINTY
        S_EQ_CMS = 490,                          // EQ_CMS
        S_TLINDX = 491,                          // TLINDX
        S_TLNUMBER = 492,                        // TLNUMBER
        S_BANACT = 493,                          // BANACT
        S_RESTRICTIONS = 494,                    // RESTRICTIONS
        S_POSTERIOR_SAMPLER_OPTIONS = 495,       // POSTERIOR_SAMPLER_OPTIONS
        S_OUTPUT_FILE_TAG = 496,                 // OUTPUT_FILE_TAG
        S_DRAWS_NBR_BURN_IN_1 = 497,             // DRAWS_NBR_BURN_IN_1
        S_DRAWS_NBR_BURN_IN_2 = 498,             // DRAWS_NBR_BURN_IN_2
        S_HORIZON = 499,                         // HORIZON
        S_SBVAR = 500,                           // SBVAR
        S_TREND_VAR = 501,                       // TREND_VAR
        S_DEFLATOR = 502,                        // DEFLATOR
        S_GROWTH_FACTOR = 503,                   // GROWTH_FACTOR
        S_MS_IRF = 504,                          // MS_IRF
        S_MS_VARIANCE_DECOMPOSITION = 505,       // MS_VARIANCE_DECOMPOSITION
        S_MS_ESTIMATION = 506,                   // MS_ESTIMATION
        S_MS_SIMULATION = 507,                   // MS_SIMULATION
        S_MS_COMPUTE_MDD = 508,                  // MS_COMPUTE_MDD
        S_MS_COMPUTE_PROBABILITIES = 509,        // MS_COMPUTE_PROBABILITIES
        S_MS_FORECAST = 510,                     // MS_FORECAST
        S_SVAR_IDENTIFICATION = 511,             // SVAR_IDENTIFICATION
        S_EQUATION = 512,                        // EQUATION
        S_EXCLUSION = 513,                       // EXCLUSION
        S_LAG = 514,                             // LAG
        S_UPPER_CHOLESKY = 515,                  // UPPER_CHOLESKY
        S_LOWER_CHOLESKY = 516,                  // LOWER_CHOLESKY
        S_MONTHLY = 517,                         // MONTHLY
        S_QUARTERLY = 518,                       // QUARTERLY
        S_MARKOV_SWITCHING = 519,                // MARKOV_SWITCHING
        S_CHAIN = 520,                           // CHAIN
        S_DURATION = 521,                        // DURATION
        S_NUMBER_OF_REGIMES = 522,               // NUMBER_OF_REGIMES
        S_NUMBER_OF_LAGS = 523,                  // NUMBER_OF_LAGS
        S_SVAR = 524,                            // SVAR
        S_SVAR_GLOBAL_IDENTIFICATION_CHECK = 525, // SVAR_GLOBAL_IDENTIFICATION_CHECK
        S_COEFF = 526,                           // COEFF
        S_COEFFICIENTS = 527,                    // COEFFICIENTS
        S_VARIANCES = 528,                       // VARIANCES
        S_CONSTANTS = 529,                       // CONSTANTS
        S_EQUATIONS = 530,                       // EQUATIONS
        S_EXTERNAL_FUNCTION = 531,               // EXTERNAL_FUNCTION
        S_EXT_FUNC_NAME = 532,                   // EXT_FUNC_NAME
        S_EXT_FUNC_NARGS = 533,                  // EXT_FUNC_NARGS
        S_FIRST_DERIV_PROVIDED = 534,            // FIRST_DERIV_PROVIDED
        S_SECOND_DERIV_PROVIDED = 535,           // SECOND_DERIV_PROVIDED
        S_SELECTED_VARIABLES_ONLY = 536,         // SELECTED_VARIABLES_ONLY
        S_COVA_COMPUTE = 537,                    // COVA_COMPUTE
        S_SIMULATION_FILE_TAG = 538,             // SIMULATION_FILE_TAG
        S_FILE_TAG = 539,                        // FILE_TAG
        S_NO_ERROR_BANDS = 540,                  // NO_ERROR_BANDS
        S_ERROR_BAND_PERCENTILES = 541,          // ERROR_BAND_PERCENTILES
        S_SHOCKS_PER_PARAMETER = 542,            // SHOCKS_PER_PARAMETER
        S_NO_CREATE_INIT = 543,                  // NO_CREATE_INIT
        S_SHOCK_DRAWS = 544,                     // SHOCK_DRAWS
        S_FREE_PARAMETERS = 545,                 // FREE_PARAMETERS
        S_MEDIAN = 546,                          // MEDIAN
        S_DATA_OBS_NBR = 547,                    // DATA_OBS_NBR
        S_NEIGHBORHOOD_WIDTH = 548,              // NEIGHBORHOOD_WIDTH
        S_PVALUE_KS = 549,                       // PVALUE_KS
        S_PVALUE_CORR = 550,                     // PVALUE_CORR
        S_FILTERED_PROBABILITIES = 551,          // FILTERED_PROBABILITIES
        S_REAL_TIME_SMOOTHED = 552,              // REAL_TIME_SMOOTHED
        S_PRIOR_FUNCTION = 553,                  // PRIOR_FUNCTION
        S_POSTERIOR_FUNCTION = 554,              // POSTERIOR_FUNCTION
        S_SAMPLING_DRAWS = 555,                  // SAMPLING_DRAWS
        S_PROPOSAL_TYPE = 556,                   // PROPOSAL_TYPE
        S_PROPOSAL_UPPER_BOUND = 557,            // PROPOSAL_UPPER_BOUND
        S_PROPOSAL_LOWER_BOUND = 558,            // PROPOSAL_LOWER_BOUND
        S_PROPOSAL_DRAWS = 559,                  // PROPOSAL_DRAWS
        S_USE_MEAN_CENTER = 560,                 // USE_MEAN_CENTER
        S_ADAPTIVE_MH_DRAWS = 561,               // ADAPTIVE_MH_DRAWS
        S_THINNING_FACTOR = 562,                 // THINNING_FACTOR
        S_COEFFICIENTS_PRIOR_HYPERPARAMETERS = 563, // COEFFICIENTS_PRIOR_HYPERPARAMETERS
        S_CONVERGENCE_STARTING_VALUE = 564,      // CONVERGENCE_STARTING_VALUE
        S_CONVERGENCE_ENDING_VALUE = 565,        // CONVERGENCE_ENDING_VALUE
        S_CONVERGENCE_INCREMENT_VALUE = 566,     // CONVERGENCE_INCREMENT_VALUE
        S_MAX_ITERATIONS_STARTING_VALUE = 567,   // MAX_ITERATIONS_STARTING_VALUE
        S_MAX_ITERATIONS_INCREMENT_VALUE = 568,  // MAX_ITERATIONS_INCREMENT_VALUE
        S_MAX_BLOCK_ITERATIONS = 569,            // MAX_BLOCK_ITERATIONS
        S_MAX_REPEATED_OPTIMIZATION_RUNS = 570,  // MAX_REPEATED_OPTIMIZATION_RUNS
        S_FUNCTION_CONVERGENCE_CRITERION = 571,  // FUNCTION_CONVERGENCE_CRITERION
        S_SAVE_REALTIME = 572,                   // SAVE_REALTIME
        S_PARAMETER_CONVERGENCE_CRITERION = 573, // PARAMETER_CONVERGENCE_CRITERION
        S_NUMBER_OF_LARGE_PERTURBATIONS = 574,   // NUMBER_OF_LARGE_PERTURBATIONS
        S_NUMBER_OF_SMALL_PERTURBATIONS = 575,   // NUMBER_OF_SMALL_PERTURBATIONS
        S_NUMBER_OF_POSTERIOR_DRAWS_AFTER_PERTURBATION = 576, // NUMBER_OF_POSTERIOR_DRAWS_AFTER_PERTURBATION
        S_MAX_NUMBER_OF_STAGES = 577,            // MAX_NUMBER_OF_STAGES
        S_RANDOM_FUNCTION_CONVERGENCE_CRITERION = 578, // RANDOM_FUNCTION_CONVERGENCE_CRITERION
        S_RANDOM_PARAMETER_CONVERGENCE_CRITERION = 579, // RANDOM_PARAMETER_CONVERGENCE_CRITERION
        S_SYMBOL_VEC = 580,                      // SYMBOL_VEC
        S_581_ = 581,                            // ';'
        S_582_ = 582,                            // '('
        S_583_ = 583,                            // ')'
        S_584_ = 584,                            // '['
        S_585_ = 585,                            // ']'
        S_586_ = 586,                            // '#'
        S_587_ = 587,                            // ':'
        S_588_ = 588,                            // '.'
        S_YYACCEPT = 589,                        // $accept
        S_statement_list = 590,                  // statement_list
        S_statement = 591,                       // statement
        S_dsample = 592,                         // dsample
        S_rplot = 593,                           // rplot
        S_trend_var = 594,                       // trend_var
        S_595_1 = 595,                           // $@1
        S_trend_var_list = 596,                  // trend_var_list
        S_log_trend_var = 597,                   // log_trend_var
        S_598_2 = 598,                           // $@2
        S_log_trend_var_list = 599,              // log_trend_var_list
        S_var = 600,                             // var
        S_601_3 = 601,                           // $@3
        S_602_4 = 602,                           // $@4
        S_nonstationary_var_list = 603,          // nonstationary_var_list
        S_varexo = 604,                          // varexo
        S_varexo_det = 605,                      // varexo_det
        S_predetermined_variables = 606,         // predetermined_variables
        S_parameters = 607,                      // parameters
        S_named_var_elem = 608,                  // named_var_elem
        S_named_var_1 = 609,                     // named_var_1
        S_named_var = 610,                       // named_var
        S_var_list = 611,                        // var_list
        S_varexo_list = 612,                     // varexo_list
        S_varexo_det_list = 613,                 // varexo_det_list
        S_parameter_list = 614,                  // parameter_list
        S_predetermined_variables_list = 615,    // predetermined_variables_list
        S_change_type = 616,                     // change_type
        S_change_type_arg = 617,                 // change_type_arg
        S_change_type_var_list = 618,            // change_type_var_list
        S_periods = 619,                         // periods
        S_init_param = 620,                      // init_param
        S_expression = 621,                      // expression
        S_622_5 = 622,                           // $@5
        S_comma_expression = 623,                // comma_expression
        S_expression_or_empty = 624,             // expression_or_empty
        S_initval = 625,                         // initval
        S_initval_file = 626,                    // initval_file
        S_endval = 627,                          // endval
        S_initval_list = 628,                    // initval_list
        S_initval_elem = 629,                    // initval_elem
        S_histval = 630,                         // histval
        S_histval_list = 631,                    // histval_list
        S_histval_elem = 632,                    // histval_elem
        S_histval_file = 633,                    // histval_file
        S_model_options = 634,                   // model_options
        S_model_options_list = 635,              // model_options_list
        S_model = 636,                           // model
        S_637_6 = 637,                           // $@6
        S_638_7 = 638,                           // $@7
        S_equation_list = 639,                   // equation_list
        S_equation = 640,                        // equation
        S_tags_list = 641,                       // tags_list
        S_tag_pair = 642,                        // tag_pair
        S_hand_side = 643,                       // hand_side
        S_644_8 = 644,                           // $@8
        S_comma_hand_side = 645,                 // comma_hand_side
        S_pound_expression = 646,                // pound_expression
        S_shocks = 647,                          // shocks
        S_shock_list = 648,                      // shock_list
        S_shock_elem = 649,                      // shock_elem
        S_det_shock_elem = 650,                  // det_shock_elem
        S_svar_identification = 651,             // svar_identification
        S_652_9 = 652,                           // $@9
        S_svar_identification_list = 653,        // svar_identification_list
        S_svar_identification_elem = 654,        // svar_identification_elem
        S_655_10 = 655,                          // $@10
        S_656_11 = 656,                          // $@11
        S_svar_equation_list = 657,              // svar_equation_list
        S_svar_var_list = 658,                   // svar_var_list
        S_restriction_expression = 659,          // restriction_expression
        S_restriction_expression_1 = 660,        // restriction_expression_1
        S_restriction_elem_expression = 661,     // restriction_elem_expression
        S_svar_global_identification_check = 662, // svar_global_identification_check
        S_markov_switching = 663,                // markov_switching
        S_ms_options_list = 664,                 // ms_options_list
        S_ms_options = 665,                      // ms_options
        S_svar = 666,                            // svar
        S_svar_options_list = 667,               // svar_options_list
        S_svar_options = 668,                    // svar_options
        S_mshocks = 669,                         // mshocks
        S_mshock_list = 670,                     // mshock_list
        S_period_list = 671,                     // period_list
        S_sigma_e = 672,                         // sigma_e
        S_value_list = 673,                      // value_list
        S_triangular_matrix = 674,               // triangular_matrix
        S_triangular_row = 675,                  // triangular_row
        S_steady = 676,                          // steady
        S_steady_options_list = 677,             // steady_options_list
        S_steady_options = 678,                  // steady_options
        S_check = 679,                           // check
        S_check_options_list = 680,              // check_options_list
        S_check_options = 681,                   // check_options
        S_model_info = 682,                      // model_info
        S_model_info_options_list = 683,         // model_info_options_list
        S_model_info_options = 684,              // model_info_options
        S_perfect_foresight_setup = 685,         // perfect_foresight_setup
        S_perfect_foresight_setup_options_list = 686, // perfect_foresight_setup_options_list
        S_perfect_foresight_setup_options = 687, // perfect_foresight_setup_options
        S_perfect_foresight_solver = 688,        // perfect_foresight_solver
        S_perfect_foresight_solver_options_list = 689, // perfect_foresight_solver_options_list
        S_perfect_foresight_solver_options = 690, // perfect_foresight_solver_options
        S_prior_function = 691,                  // prior_function
        S_posterior_function = 692,              // posterior_function
        S_prior_posterior_function_options_list = 693, // prior_posterior_function_options_list
        S_prior_posterior_function_options = 694, // prior_posterior_function_options
        S_simul = 695,                           // simul
        S_simul_options_list = 696,              // simul_options_list
        S_simul_options = 697,                   // simul_options
        S_external_function = 698,               // external_function
        S_external_function_options_list = 699,  // external_function_options_list
        S_external_function_options = 700,       // external_function_options
        S_stoch_simul = 701,                     // stoch_simul
        S_stoch_simul_options_list = 702,        // stoch_simul_options_list
        S_stoch_simul_primary_options = 703,     // stoch_simul_primary_options
        S_stoch_simul_options = 704,             // stoch_simul_options
        S_symbol_list = 705,                     // symbol_list
        S_symbol_list_ext = 706,                 // symbol_list_ext
        S_signed_integer = 707,                  // signed_integer
        S_non_negative_number = 708,             // non_negative_number
        S_signed_number = 709,                   // signed_number
        S_signed_inf = 710,                      // signed_inf
        S_signed_number_w_inf = 711,             // signed_number_w_inf
        S_estimated_params = 712,                // estimated_params
        S_estimated_list = 713,                  // estimated_list
        S_estimated_elem = 714,                  // estimated_elem
        S_estimated_elem1 = 715,                 // estimated_elem1
        S_estimated_elem2 = 716,                 // estimated_elem2
        S_estimated_elem3 = 717,                 // estimated_elem3
        S_estimated_params_init = 718,           // estimated_params_init
        S_estimated_init_list = 719,             // estimated_init_list
        S_estimated_init_elem = 720,             // estimated_init_elem
        S_estimated_params_bounds = 721,         // estimated_params_bounds
        S_estimated_bounds_list = 722,           // estimated_bounds_list
        S_estimated_bounds_elem = 723,           // estimated_bounds_elem
        S_osr_params_bounds = 724,               // osr_params_bounds
        S_osr_bounds_list = 725,                 // osr_bounds_list
        S_osr_bounds_elem = 726,                 // osr_bounds_elem
        S_prior_distribution = 727,              // prior_distribution
        S_prior_pdf = 728,                       // prior_pdf
        S_date_str = 729,                        // date_str
        S_date_expr = 730,                       // date_expr
        S_set_time = 731,                        // set_time
        S_data = 732,                            // data
        S_data_options_list = 733,               // data_options_list
        S_data_options = 734,                    // data_options
        S_subsamples = 735,                      // subsamples
        S_subsamples_eq = 736,                   // subsamples_eq
        S_subsamples_eq_opt = 737,               // subsamples_eq_opt
        S_subsamples_name_list = 738,            // subsamples_name_list
        S_prior = 739,                           // prior
        S_740_12 = 740,                          // $@12
        S_741_13 = 741,                          // $@13
        S_742_14 = 742,                          // $@14
        S_743_15 = 743,                          // $@15
        S_744_16 = 744,                          // $@16
        S_745_17 = 745,                          // $@17
        S_746_18 = 746,                          // $@18
        S_prior_options_list = 747,              // prior_options_list
        S_prior_options = 748,                   // prior_options
        S_joint_prior_options_list = 749,        // joint_prior_options_list
        S_joint_prior_options = 750,             // joint_prior_options
        S_prior_eq = 751,                        // prior_eq
        S_prior_eq_opt = 752,                    // prior_eq_opt
        S_options = 753,                         // options
        S_options_options_list = 754,            // options_options_list
        S_options_options = 755,                 // options_options
        S_options_eq = 756,                      // options_eq
        S_options_eq_opt = 757,                  // options_eq_opt
        S_estimation = 758,                      // estimation
        S_estimation_options_list = 759,         // estimation_options_list
        S_estimation_options = 760,              // estimation_options
        S_list_optim_option = 761,               // list_optim_option
        S_optim_options = 762,                   // optim_options
        S_list_sub_sampling_option = 763,        // list_sub_sampling_option
        S_sub_sampling_options = 764,            // sub_sampling_options
        S_list_sampling_option = 765,            // list_sampling_option
        S_sampling_options = 766,                // sampling_options
        S_varobs = 767,                          // varobs
        S_768_19 = 768,                          // $@19
        S_varobs_list = 769,                     // varobs_list
        S_observation_trends = 770,              // observation_trends
        S_trend_list = 771,                      // trend_list
        S_trend_element = 772,                   // trend_element
        S_unit_root_vars = 773,                  // unit_root_vars
        S_optim_weights = 774,                   // optim_weights
        S_optim_weights_list = 775,              // optim_weights_list
        S_osr_params = 776,                      // osr_params
        S_osr_options_list = 777,                // osr_options_list
        S_osr_options = 778,                     // osr_options
        S_osr = 779,                             // osr
        S_dynatype = 780,                        // dynatype
        S_dynasave = 781,                        // dynasave
        S_load_params_and_steady_state = 782,    // load_params_and_steady_state
        S_save_params_and_steady_state = 783,    // save_params_and_steady_state
        S_identification = 784,                  // identification
        S_identification_options_list = 785,     // identification_options_list
        S_identification_option = 786,           // identification_option
        S_model_comparison = 787,                // model_comparison
        S_filename = 788,                        // filename
        S_parallel_local_filename_list = 789,    // parallel_local_filename_list
        S_mc_filename_list = 790,                // mc_filename_list
        S_planner_objective = 791,               // planner_objective
        S_792_20 = 792,                          // $@20
        S_793_21 = 793,                          // $@21
        S_ramsey_model = 794,                    // ramsey_model
        S_ramsey_policy = 795,                   // ramsey_policy
        S_ramsey_policy_list = 796,              // ramsey_policy_list
        S_ramsey_policy_element = 797,           // ramsey_policy_element
        S_ramsey_constraints = 798,              // ramsey_constraints
        S_ramsey_constraints_list = 799,         // ramsey_constraints_list
        S_ramsey_constraint = 800,               // ramsey_constraint
        S_discretionary_policy = 801,            // discretionary_policy
        S_discretionary_policy_options_list = 802, // discretionary_policy_options_list
        S_discretionary_policy_options = 803,    // discretionary_policy_options
        S_ramsey_model_options_list = 804,       // ramsey_model_options_list
        S_ramsey_model_options = 805,            // ramsey_model_options
        S_ramsey_policy_options_list = 806,      // ramsey_policy_options_list
        S_ramsey_policy_options = 807,           // ramsey_policy_options
        S_write_latex_dynamic_model = 808,       // write_latex_dynamic_model
        S_write_latex_static_model = 809,        // write_latex_static_model
        S_write_latex_original_model = 810,      // write_latex_original_model
        S_shock_decomposition = 811,             // shock_decomposition
        S_realtime_shock_decomposition = 812,    // realtime_shock_decomposition
        S_plot_shock_decomposition = 813,        // plot_shock_decomposition
        S_initial_condition_decomposition = 814, // initial_condition_decomposition
        S_bvar_prior_option = 815,               // bvar_prior_option
        S_bvar_common_option = 816,              // bvar_common_option
        S_bvar_density_options_list = 817,       // bvar_density_options_list
        S_bvar_density = 818,                    // bvar_density
        S_bvar_forecast_option = 819,            // bvar_forecast_option
        S_bvar_forecast_options_list = 820,      // bvar_forecast_options_list
        S_bvar_forecast = 821,                   // bvar_forecast
        S_sbvar_option = 822,                    // sbvar_option
        S_sbvar_options_list = 823,              // sbvar_options_list
        S_sbvar = 824,                           // sbvar
        S_ms_variance_decomposition_option = 825, // ms_variance_decomposition_option
        S_ms_variance_decomposition_options_list = 826, // ms_variance_decomposition_options_list
        S_ms_variance_decomposition = 827,       // ms_variance_decomposition
        S_ms_forecast_option = 828,              // ms_forecast_option
        S_ms_forecast_options_list = 829,        // ms_forecast_options_list
        S_ms_forecast = 830,                     // ms_forecast
        S_ms_irf_option = 831,                   // ms_irf_option
        S_ms_irf_options_list = 832,             // ms_irf_options_list
        S_ms_irf = 833,                          // ms_irf
        S_ms_compute_probabilities_option = 834, // ms_compute_probabilities_option
        S_ms_compute_probabilities_options_list = 835, // ms_compute_probabilities_options_list
        S_ms_compute_probabilities = 836,        // ms_compute_probabilities
        S_ms_compute_mdd_option = 837,           // ms_compute_mdd_option
        S_ms_compute_mdd_options_list = 838,     // ms_compute_mdd_options_list
        S_ms_compute_mdd = 839,                  // ms_compute_mdd
        S_ms_simulation_option = 840,            // ms_simulation_option
        S_ms_simulation_options_list = 841,      // ms_simulation_options_list
        S_ms_simulation = 842,                   // ms_simulation
        S_ms_estimation_option = 843,            // ms_estimation_option
        S_ms_estimation_options_list = 844,      // ms_estimation_options_list
        S_ms_estimation = 845,                   // ms_estimation
        S_dynare_sensitivity = 846,              // dynare_sensitivity
        S_dynare_sensitivity_options_list = 847, // dynare_sensitivity_options_list
        S_dynare_sensitivity_option = 848,       // dynare_sensitivity_option
        S_shock_decomposition_options_list = 849, // shock_decomposition_options_list
        S_shock_decomposition_option = 850,      // shock_decomposition_option
        S_realtime_shock_decomposition_options_list = 851, // realtime_shock_decomposition_options_list
        S_realtime_shock_decomposition_option = 852, // realtime_shock_decomposition_option
        S_plot_shock_decomposition_options_list = 853, // plot_shock_decomposition_options_list
        S_plot_shock_decomposition_option = 854, // plot_shock_decomposition_option
        S_initial_condition_decomposition_options_list = 855, // initial_condition_decomposition_options_list
        S_initial_condition_decomposition_option = 856, // initial_condition_decomposition_option
        S_homotopy_setup = 857,                  // homotopy_setup
        S_homotopy_list = 858,                   // homotopy_list
        S_homotopy_item = 859,                   // homotopy_item
        S_forecast = 860,                        // forecast
        S_forecast_options = 861,                // forecast_options
        S_forecast_option = 862,                 // forecast_option
        S_conditional_forecast = 863,            // conditional_forecast
        S_conditional_forecast_options = 864,    // conditional_forecast_options
        S_conditional_forecast_option = 865,     // conditional_forecast_option
        S_plot_conditional_forecast = 866,       // plot_conditional_forecast
        S_conditional_forecast_paths = 867,      // conditional_forecast_paths
        S_conditional_forecast_paths_shock_list = 868, // conditional_forecast_paths_shock_list
        S_conditional_forecast_paths_shock_elem = 869, // conditional_forecast_paths_shock_elem
        S_steady_state_model = 870,              // steady_state_model
        S_871_22 = 871,                          // $@22
        S_steady_state_equation_list = 872,      // steady_state_equation_list
        S_steady_state_equation = 873,           // steady_state_equation
        S_calib_smoother = 874,                  // calib_smoother
        S_calib_smoother_options_list = 875,     // calib_smoother_options_list
        S_calib_smoother_option = 876,           // calib_smoother_option
        S_extended_path = 877,                   // extended_path
        S_extended_path_options_list = 878,      // extended_path_options_list
        S_extended_path_option = 879,            // extended_path_option
        S_model_diagnostics = 880,               // model_diagnostics
        S_calibration_range = 881,               // calibration_range
        S_moment_calibration = 882,              // moment_calibration
        S_moment_calibration_list = 883,         // moment_calibration_list
        S_moment_calibration_item = 884,         // moment_calibration_item
        S_irf_calibration = 885,                 // irf_calibration
        S_irf_calibration_list = 886,            // irf_calibration_list
        S_irf_calibration_item = 887,            // irf_calibration_item
        S_smoother2histval = 888,                // smoother2histval
        S_smoother2histval_options_list = 889,   // smoother2histval_options_list
        S_smoother2histval_option = 890,         // smoother2histval_option
        S_shock_groups = 891,                    // shock_groups
        S_shock_group_list = 892,                // shock_group_list
        S_shock_group_element = 893,             // shock_group_element
        S_shock_name_list = 894,                 // shock_name_list
        S_o_dr_algo = 895,                       // o_dr_algo
        S_o_solve_algo = 896,                    // o_solve_algo
        S_o_simul_algo = 897,                    // o_simul_algo
        S_o_stack_solve_algo = 898,              // o_stack_solve_algo
        S_o_robust_lin_solve = 899,              // o_robust_lin_solve
        S_o_endogenous_terminal_period = 900,    // o_endogenous_terminal_period
        S_o_linear = 901,                        // o_linear
        S_o_order = 902,                         // o_order
        S_o_replic = 903,                        // o_replic
        S_o_drop = 904,                          // o_drop
        S_o_ar = 905,                            // o_ar
        S_o_nocorr = 906,                        // o_nocorr
        S_o_nofunctions = 907,                   // o_nofunctions
        S_o_nomoments = 908,                     // o_nomoments
        S_o_irf = 909,                           // o_irf
        S_o_irf_shocks = 910,                    // o_irf_shocks
        S_o_hp_filter = 911,                     // o_hp_filter
        S_o_hp_ngrid = 912,                      // o_hp_ngrid
        S_o_one_sided_hp_filter = 913,           // o_one_sided_hp_filter
        S_o_periods = 914,                       // o_periods
        S_o_solver_periods = 915,                // o_solver_periods
        S_o_extended_path_order = 916,           // o_extended_path_order
        S_o_hybrid = 917,                        // o_hybrid
        S_o_steady_maxit = 918,                  // o_steady_maxit
        S_o_simul_maxit = 919,                   // o_simul_maxit
        S_o_bandpass_filter = 920,               // o_bandpass_filter
        S_o_dp_maxit = 921,                      // o_dp_maxit
        S_o_osr_maxit = 922,                     // o_osr_maxit
        S_o_osr_tolf = 923,                      // o_osr_tolf
        S_o_pf_tolf = 924,                       // o_pf_tolf
        S_o_pf_tolx = 925,                       // o_pf_tolx
        S_o_steady_tolf = 926,                   // o_steady_tolf
        S_o_opt_algo = 927,                      // o_opt_algo
        S_o_cutoff = 928,                        // o_cutoff
        S_o_markowitz = 929,                     // o_markowitz
        S_o_minimal_solving_periods = 930,       // o_minimal_solving_periods
        S_o_mfs = 931,                           // o_mfs
        S_o_simul = 932,                         // o_simul
        S_o_simul_replic = 933,                  // o_simul_replic
        S_o_simul_seed = 934,                    // o_simul_seed
        S_o_qz_criterium = 935,                  // o_qz_criterium
        S_o_qz_zero_threshold = 936,             // o_qz_zero_threshold
        S_o_file = 937,                          // o_file
        S_o_series = 938,                        // o_series
        S_o_datafile = 939,                      // o_datafile
        S_o_dirname = 940,                       // o_dirname
        S_o_huge_number = 941,                   // o_huge_number
        S_o_nobs = 942,                          // o_nobs
        S_o_conditional_variance_decomposition = 943, // o_conditional_variance_decomposition
        S_o_est_first_obs = 944,                 // o_est_first_obs
        S_o_posterior_sampling_method = 945,     // o_posterior_sampling_method
        S_o_first_obs = 946,                     // o_first_obs
        S_o_data_first_obs = 947,                // o_data_first_obs
        S_o_data_last_obs = 948,                 // o_data_last_obs
        S_o_keep_kalman_algo_if_singularity_is_detected = 949, // o_keep_kalman_algo_if_singularity_is_detected
        S_o_data_nobs = 950,                     // o_data_nobs
        S_o_shift = 951,                         // o_shift
        S_o_shape = 952,                         // o_shape
        S_o_mode = 953,                          // o_mode
        S_o_mean = 954,                          // o_mean
        S_o_mean_vec = 955,                      // o_mean_vec
        S_o_truncate = 956,                      // o_truncate
        S_o_stdev = 957,                         // o_stdev
        S_o_jscale = 958,                        // o_jscale
        S_o_init = 959,                          // o_init
        S_o_bounds = 960,                        // o_bounds
        S_o_domain = 961,                        // o_domain
        S_o_interval = 962,                      // o_interval
        S_o_variance = 963,                      // o_variance
        S_o_variance_mat = 964,                  // o_variance_mat
        S_o_prefilter = 965,                     // o_prefilter
        S_o_presample = 966,                     // o_presample
        S_o_lik_algo = 967,                      // o_lik_algo
        S_o_lik_init = 968,                      // o_lik_init
        S_o_nograph = 969,                       // o_nograph
        S_o_posterior_nograph = 970,             // o_posterior_nograph
        S_o_shock_decomposition_nograph = 971,   // o_shock_decomposition_nograph
        S_o_init_state = 972,                    // o_init_state
        S_o_shock_decomposition_presample = 973, // o_shock_decomposition_presample
        S_o_shock_decomposition_forecast = 974,  // o_shock_decomposition_forecast
        S_o_save_realtime = 975,                 // o_save_realtime
        S_o_nodisplay = 976,                     // o_nodisplay
        S_o_psd_nodisplay = 977,                 // o_psd_nodisplay
        S_o_graph_format = 978,                  // o_graph_format
        S_o_psd_graph_format = 979,              // o_psd_graph_format
        S_allowed_graph_formats = 980,           // allowed_graph_formats
        S_list_allowed_graph_formats = 981,      // list_allowed_graph_formats
        S_o_subsample_name = 982,                // o_subsample_name
        S_o_bvar_conf_sig = 983,                 // o_bvar_conf_sig
        S_o_forecasts_conf_sig = 984,            // o_forecasts_conf_sig
        S_o_conditional_forecast_conf_sig = 985, // o_conditional_forecast_conf_sig
        S_o_mh_conf_sig = 986,                   // o_mh_conf_sig
        S_o_mh_replic = 987,                     // o_mh_replic
        S_o_posterior_max_subsample_draws = 988, // o_posterior_max_subsample_draws
        S_o_mh_drop = 989,                       // o_mh_drop
        S_o_mh_jscale = 990,                     // o_mh_jscale
        S_o_optim = 991,                         // o_optim
        S_o_posterior_sampler_options = 992,     // o_posterior_sampler_options
        S_o_proposal_distribution = 993,         // o_proposal_distribution
        S_o_no_posterior_kernel_density = 994,   // o_no_posterior_kernel_density
        S_o_mh_init_scale = 995,                 // o_mh_init_scale
        S_o_mode_file = 996,                     // o_mode_file
        S_o_mode_compute = 997,                  // o_mode_compute
        S_o_mode_check = 998,                    // o_mode_check
        S_o_mode_check_neighbourhood_size = 999, // o_mode_check_neighbourhood_size
        S_o_mode_check_number_of_points = 1000,  // o_mode_check_number_of_points
        S_o_mode_check_symmetric_plots = 1001,   // o_mode_check_symmetric_plots
        S_o_prior_trunc = 1002,                  // o_prior_trunc
        S_o_mh_mode = 1003,                      // o_mh_mode
        S_o_mh_nblocks = 1004,                   // o_mh_nblocks
        S_o_load_mh_file = 1005,                 // o_load_mh_file
        S_o_load_results_after_load_mh = 1006,   // o_load_results_after_load_mh
        S_o_loglinear = 1007,                    // o_loglinear
        S_o_linear_approximation = 1008,         // o_linear_approximation
        S_o_logdata = 1009,                      // o_logdata
        S_o_nodiagnostic = 1010,                 // o_nodiagnostic
        S_o_bayesian_irf = 1011,                 // o_bayesian_irf
        S_o_dsge_var = 1012,                     // o_dsge_var
        S_o_dsge_varlag = 1013,                  // o_dsge_varlag
        S_o_tex = 1014,                          // o_tex
        S_o_forecast = 1015,                     // o_forecast
        S_o_smoother = 1016,                     // o_smoother
        S_o_moments_varendo = 1017,              // o_moments_varendo
        S_o_contemporaneous_correlation = 1018,  // o_contemporaneous_correlation
        S_o_filtered_vars = 1019,                // o_filtered_vars
        S_o_relative_irf = 1020,                 // o_relative_irf
        S_o_fast_kalman_filter = 1021,           // o_fast_kalman_filter
        S_o_kalman_algo = 1022,                  // o_kalman_algo
        S_o_kalman_tol = 1023,                   // o_kalman_tol
        S_o_diffuse_kalman_tol = 1024,           // o_diffuse_kalman_tol
        S_o_marginal_density = 1025,             // o_marginal_density
        S_o_print = 1026,                        // o_print
        S_o_noprint = 1027,                      // o_noprint
        S_o_xls_sheet = 1028,                    // o_xls_sheet
        S_o_xls_range = 1029,                    // o_xls_range
        S_o_filter_step_ahead = 1030,            // o_filter_step_ahead
        S_o_taper_steps = 1031,                  // o_taper_steps
        S_o_geweke_interval = 1032,              // o_geweke_interval
        S_o_raftery_lewis_diagnostics = 1033,    // o_raftery_lewis_diagnostics
        S_o_raftery_lewis_qrs = 1034,            // o_raftery_lewis_qrs
        S_o_constant = 1035,                     // o_constant
        S_o_noconstant = 1036,                   // o_noconstant
        S_o_mh_recover = 1037,                   // o_mh_recover
        S_o_diffuse_filter = 1038,               // o_diffuse_filter
        S_o_plot_priors = 1039,                  // o_plot_priors
        S_o_aim_solver = 1040,                   // o_aim_solver
        S_o_partial_information = 1041,          // o_partial_information
        S_o_sub_draws = 1042,                    // o_sub_draws
        S_o_planner_discount = 1043,             // o_planner_discount
        S_o_sylvester = 1044,                    // o_sylvester
        S_o_sylvester_fixed_point_tol = 1045,    // o_sylvester_fixed_point_tol
        S_o_lyapunov = 1046,                     // o_lyapunov
        S_o_lyapunov_fixed_point_tol = 1047,     // o_lyapunov_fixed_point_tol
        S_o_lyapunov_doubling_tol = 1048,        // o_lyapunov_doubling_tol
        S_o_dr = 1049,                           // o_dr
        S_o_dr_cycle_reduction_tol = 1050,       // o_dr_cycle_reduction_tol
        S_o_dr_logarithmic_reduction_tol = 1051, // o_dr_logarithmic_reduction_tol
        S_o_dr_logarithmic_reduction_maxiter = 1052, // o_dr_logarithmic_reduction_maxiter
        S_o_psd_detail_plot = 1053,              // o_psd_detail_plot
        S_o_icd_detail_plot = 1054,              // o_icd_detail_plot
        S_o_psd_interactive = 1055,              // o_psd_interactive
        S_o_psd_screen_shocks = 1056,            // o_psd_screen_shocks
        S_o_psd_steadystate = 1057,              // o_psd_steadystate
        S_o_icd_steadystate = 1058,              // o_icd_steadystate
        S_o_psd_fig_name = 1059,                 // o_psd_fig_name
        S_o_psd_type = 1060,                     // o_psd_type
        S_o_icd_type = 1061,                     // o_icd_type
        S_o_icd_plot_init_date = 1062,           // o_icd_plot_init_date
        S_o_icd_plot_end_date = 1063,            // o_icd_plot_end_date
        S_o_psd_plot_init_date = 1064,           // o_psd_plot_init_date
        S_o_psd_plot_end_date = 1065,            // o_psd_plot_end_date
        S_o_icd_write_xls = 1066,                // o_icd_write_xls
        S_o_psd_write_xls = 1067,                // o_psd_write_xls
        S_o_psd_realtime = 1068,                 // o_psd_realtime
        S_o_psd_vintage = 1069,                  // o_psd_vintage
        S_o_bvar_prior_tau = 1070,               // o_bvar_prior_tau
        S_o_bvar_prior_decay = 1071,             // o_bvar_prior_decay
        S_o_bvar_prior_lambda = 1072,            // o_bvar_prior_lambda
        S_o_bvar_prior_mu = 1073,                // o_bvar_prior_mu
        S_o_bvar_prior_omega = 1074,             // o_bvar_prior_omega
        S_o_bvar_prior_flat = 1075,              // o_bvar_prior_flat
        S_o_bvar_prior_train = 1076,             // o_bvar_prior_train
        S_o_bvar_replic = 1077,                  // o_bvar_replic
        S_o_number_of_particles = 1078,          // o_number_of_particles
        S_o_resampling = 1079,                   // o_resampling
        S_o_resampling_threshold = 1080,         // o_resampling_threshold
        S_o_resampling_method = 1081,            // o_resampling_method
        S_o_cpf_weights = 1082,                  // o_cpf_weights
        S_o_filter_algorithm = 1083,             // o_filter_algorithm
        S_o_nonlinear_filter_initialization = 1084, // o_nonlinear_filter_initialization
        S_o_proposal_approximation = 1085,       // o_proposal_approximation
        S_o_distribution_approximation = 1086,   // o_distribution_approximation
        S_o_gsa_identification = 1087,           // o_gsa_identification
        S_o_gsa_morris = 1088,                   // o_gsa_morris
        S_o_gsa_stab = 1089,                     // o_gsa_stab
        S_o_gsa_redform = 1090,                  // o_gsa_redform
        S_o_gsa_pprior = 1091,                   // o_gsa_pprior
        S_o_gsa_prior_range = 1092,              // o_gsa_prior_range
        S_o_gsa_ppost = 1093,                    // o_gsa_ppost
        S_o_gsa_ilptau = 1094,                   // o_gsa_ilptau
        S_o_gsa_morris_nliv = 1095,              // o_gsa_morris_nliv
        S_o_gsa_morris_ntra = 1096,              // o_gsa_morris_ntra
        S_o_gsa_nsam = 1097,                     // o_gsa_nsam
        S_o_gsa_load_redform = 1098,             // o_gsa_load_redform
        S_o_gsa_load_rmse = 1099,                // o_gsa_load_rmse
        S_o_gsa_load_stab = 1100,                // o_gsa_load_stab
        S_o_gsa_alpha2_stab = 1101,              // o_gsa_alpha2_stab
        S_o_gsa_logtrans_redform = 1102,         // o_gsa_logtrans_redform
        S_o_gsa_threshold_redform = 1103,        // o_gsa_threshold_redform
        S_o_gsa_ksstat_redform = 1104,           // o_gsa_ksstat_redform
        S_o_gsa_alpha2_redform = 1105,           // o_gsa_alpha2_redform
        S_o_gsa_namendo = 1106,                  // o_gsa_namendo
        S_o_gsa_namlagendo = 1107,               // o_gsa_namlagendo
        S_o_gsa_namexo = 1108,                   // o_gsa_namexo
        S_o_gsa_rmse = 1109,                     // o_gsa_rmse
        S_o_gsa_lik_only = 1110,                 // o_gsa_lik_only
        S_o_gsa_var_rmse = 1111,                 // o_gsa_var_rmse
        S_o_gsa_pfilt_rmse = 1112,               // o_gsa_pfilt_rmse
        S_o_gsa_istart_rmse = 1113,              // o_gsa_istart_rmse
        S_o_gsa_alpha_rmse = 1114,               // o_gsa_alpha_rmse
        S_o_gsa_alpha2_rmse = 1115,              // o_gsa_alpha2_rmse
        S_o_gsa_sample_file = 1116,              // o_gsa_sample_file
        S_o_gsa_neighborhood_width = 1117,       // o_gsa_neighborhood_width
        S_o_gsa_pvalue_ks = 1118,                // o_gsa_pvalue_ks
        S_o_gsa_pvalue_corr = 1119,              // o_gsa_pvalue_corr
        S_o_load_ident_files = 1120,             // o_load_ident_files
        S_o_useautocorr = 1121,                  // o_useautocorr
        S_o_prior_mc = 1122,                     // o_prior_mc
        S_o_advanced = 1123,                     // o_advanced
        S_o_max_dim_cova_group = 1124,           // o_max_dim_cova_group
        S_o_homotopy_mode = 1125,                // o_homotopy_mode
        S_o_homotopy_steps = 1126,               // o_homotopy_steps
        S_o_homotopy_force_continue = 1127,      // o_homotopy_force_continue
        S_o_nocheck = 1128,                      // o_nocheck
        S_o_controlled_varexo = 1129,            // o_controlled_varexo
        S_o_parameter_set = 1130,                // o_parameter_set
        S_o_nodecomposition = 1131,              // o_nodecomposition
        S_o_spectral_density = 1132,             // o_spectral_density
        S_o_ms_drop = 1133,                      // o_ms_drop
        S_o_ms_mh_replic = 1134,                 // o_ms_mh_replic
        S_o_freq = 1135,                         // o_freq
        S_o_initial_year = 1136,                 // o_initial_year
        S_o_initial_subperiod = 1137,            // o_initial_subperiod
        S_o_final_year = 1138,                   // o_final_year
        S_o_final_subperiod = 1139,              // o_final_subperiod
        S_o_data = 1140,                         // o_data
        S_o_vlist = 1141,                        // o_vlist
        S_o_vlistlog = 1142,                     // o_vlistlog
        S_o_vlistper = 1143,                     // o_vlistper
        S_o_restriction_fname = 1144,            // o_restriction_fname
        S_o_nlags = 1145,                        // o_nlags
        S_o_cross_restrictions = 1146,           // o_cross_restrictions
        S_o_contemp_reduced_form = 1147,         // o_contemp_reduced_form
        S_o_real_pseudo_forecast = 1148,         // o_real_pseudo_forecast
        S_o_no_bayesian_prior = 1149,            // o_no_bayesian_prior
        S_o_dummy_obs = 1150,                    // o_dummy_obs
        S_o_nstates = 1151,                      // o_nstates
        S_o_indxscalesstates = 1152,             // o_indxscalesstates
        S_o_alpha = 1153,                        // o_alpha
        S_o_beta = 1154,                         // o_beta
        S_o_gsig2_lmdm = 1155,                   // o_gsig2_lmdm
        S_o_specification = 1156,                // o_specification
        S_o_q_diag = 1157,                       // o_q_diag
        S_o_flat_prior = 1158,                   // o_flat_prior
        S_o_ncsk = 1159,                         // o_ncsk
        S_o_nstd = 1160,                         // o_nstd
        S_o_ninv = 1161,                         // o_ninv
        S_o_indxparr = 1162,                     // o_indxparr
        S_o_indxovr = 1163,                      // o_indxovr
        S_o_aband = 1164,                        // o_aband
        S_o_indxap = 1165,                       // o_indxap
        S_o_apband = 1166,                       // o_apband
        S_o_indximf = 1167,                      // o_indximf
        S_o_indxfore = 1168,                     // o_indxfore
        S_o_foreband = 1169,                     // o_foreband
        S_o_indxgforhat = 1170,                  // o_indxgforhat
        S_o_indxgimfhat = 1171,                  // o_indxgimfhat
        S_o_indxestima = 1172,                   // o_indxestima
        S_o_indxgdls = 1173,                     // o_indxgdls
        S_o_eq_ms = 1174,                        // o_eq_ms
        S_o_cms = 1175,                          // o_cms
        S_o_ncms = 1176,                         // o_ncms
        S_o_eq_cms = 1177,                       // o_eq_cms
        S_o_tlindx = 1178,                       // o_tlindx
        S_o_tlnumber = 1179,                     // o_tlnumber
        S_o_cnum = 1180,                         // o_cnum
        S_o_k_order_solver = 1181,               // o_k_order_solver
        S_o_pruning = 1182,                      // o_pruning
        S_o_chain = 1183,                        // o_chain
        S_o_restrictions = 1184,                 // o_restrictions
        S_o_duration = 1185,                     // o_duration
        S_o_number_of_regimes = 1186,            // o_number_of_regimes
        S_o_number_of_lags = 1187,               // o_number_of_lags
        S_o_parameters = 1188,                   // o_parameters
        S_o_coefficients = 1189,                 // o_coefficients
        S_o_variances = 1190,                    // o_variances
        S_o_equations = 1191,                    // o_equations
        S_o_silent_optimizer = 1192,             // o_silent_optimizer
        S_o_instruments = 1193,                  // o_instruments
        S_o_ext_func_name = 1194,                // o_ext_func_name
        S_o_ext_func_nargs = 1195,               // o_ext_func_nargs
        S_o_first_deriv_provided = 1196,         // o_first_deriv_provided
        S_o_second_deriv_provided = 1197,        // o_second_deriv_provided
        S_o_filter_covariance = 1198,            // o_filter_covariance
        S_o_filter_decomposition = 1199,         // o_filter_decomposition
        S_o_smoothed_state_uncertainty = 1200,   // o_smoothed_state_uncertainty
        S_o_selected_variables_only = 1201,      // o_selected_variables_only
        S_o_cova_compute = 1202,                 // o_cova_compute
        S_o_output_file_tag = 1203,              // o_output_file_tag
        S_o_file_tag = 1204,                     // o_file_tag
        S_o_no_create_init = 1205,               // o_no_create_init
        S_o_simulation_file_tag = 1206,          // o_simulation_file_tag
        S_o_coefficients_prior_hyperparameters = 1207, // o_coefficients_prior_hyperparameters
        S_o_convergence_starting_value = 1208,   // o_convergence_starting_value
        S_o_convergence_ending_value = 1209,     // o_convergence_ending_value
        S_o_convergence_increment_value = 1210,  // o_convergence_increment_value
        S_o_max_iterations_starting_value = 1211, // o_max_iterations_starting_value
        S_o_max_iterations_increment_value = 1212, // o_max_iterations_increment_value
        S_o_max_block_iterations = 1213,         // o_max_block_iterations
        S_o_max_repeated_optimization_runs = 1214, // o_max_repeated_optimization_runs
        S_o_function_convergence_criterion = 1215, // o_function_convergence_criterion
        S_o_parameter_convergence_criterion = 1216, // o_parameter_convergence_criterion
        S_o_number_of_large_perturbations = 1217, // o_number_of_large_perturbations
        S_o_number_of_small_perturbations = 1218, // o_number_of_small_perturbations
        S_o_number_of_posterior_draws_after_perturbation = 1219, // o_number_of_posterior_draws_after_perturbation
        S_o_max_number_of_stages = 1220,         // o_max_number_of_stages
        S_o_random_function_convergence_criterion = 1221, // o_random_function_convergence_criterion
        S_o_random_parameter_convergence_criterion = 1222, // o_random_parameter_convergence_criterion
        S_o_thinning_factor = 1223,              // o_thinning_factor
        S_o_adaptive_mh_draws = 1224,            // o_adaptive_mh_draws
        S_o_save_draws = 1225,                   // o_save_draws
        S_o_proposal_draws = 1226,               // o_proposal_draws
        S_o_use_mean_center = 1227,              // o_use_mean_center
        S_o_proposal_type = 1228,                // o_proposal_type
        S_o_proposal_lower_bound = 1229,         // o_proposal_lower_bound
        S_o_proposal_upper_bound = 1230,         // o_proposal_upper_bound
        S_o_parameter_uncertainty = 1231,        // o_parameter_uncertainty
        S_o_horizon = 1232,                      // o_horizon
        S_o_filtered_probabilities = 1233,       // o_filtered_probabilities
        S_o_real_time_smoothed = 1234,           // o_real_time_smoothed
        S_o_no_error_bands = 1235,               // o_no_error_bands
        S_o_error_band_percentiles = 1236,       // o_error_band_percentiles
        S_o_shock_draws = 1237,                  // o_shock_draws
        S_o_shocks_per_parameter = 1238,         // o_shocks_per_parameter
        S_o_free_parameters = 1239,              // o_free_parameters
        S_o_median = 1240,                       // o_median
        S_o_regimes = 1241,                      // o_regimes
        S_o_regime = 1242,                       // o_regime
        S_o_data_obs_nbr = 1243,                 // o_data_obs_nbr
        S_o_discretionary_tol = 1244,            // o_discretionary_tol
        S_o_analytic_derivation = 1245,          // o_analytic_derivation
        S_o_analytic_derivation_mode = 1246,     // o_analytic_derivation_mode
        S_o_endogenous_prior = 1247,             // o_endogenous_prior
        S_o_use_univariate_filters_if_singularity_is_detected = 1248, // o_use_univariate_filters_if_singularity_is_detected
        S_o_mcmc_jumping_covariance = 1249,      // o_mcmc_jumping_covariance
        S_o_rescale_prediction_error_covariance = 1250, // o_rescale_prediction_error_covariance
        S_o_use_penalized_objective_for_hessian = 1251, // o_use_penalized_objective_for_hessian
        S_o_irf_plot_threshold = 1252,           // o_irf_plot_threshold
        S_o_dr_display_tol = 1253,               // o_dr_display_tol
        S_o_consider_all_endogenous = 1254,      // o_consider_all_endogenous
        S_o_consider_only_observed = 1255,       // o_consider_only_observed
        S_o_no_homotopy = 1256,                  // o_no_homotopy
        S_o_infile = 1257,                       // o_infile
        S_o_invars = 1258,                       // o_invars
        S_o_period = 1259,                       // o_period
        S_o_outfile = 1260,                      // o_outfile
        S_o_outvars = 1261,                      // o_outvars
        S_o_lmmcp = 1262,                        // o_lmmcp
        S_o_function = 1263,                     // o_function
        S_o_sampling_draws = 1264,               // o_sampling_draws
        S_o_use_shock_groups = 1265,             // o_use_shock_groups
        S_o_colormap = 1266,                     // o_colormap
        S_range = 1267,                          // range
        S_integer_range = 1268,                  // integer_range
        S_signed_integer_range = 1269,           // signed_integer_range
        S_vec_int_number = 1270,                 // vec_int_number
        S_vec_int_elem = 1271,                   // vec_int_elem
        S_vec_int_1 = 1272,                      // vec_int_1
        S_vec_int = 1273,                        // vec_int
        S_vec_value_1 = 1274,                    // vec_value_1
        S_vec_value = 1275,                      // vec_value
        S_vec_value_list = 1276,                 // vec_value_list
        S_vec_of_vec_value = 1277,               // vec_of_vec_value
        S_vec_value_1_w_inf = 1278,              // vec_value_1_w_inf
        S_vec_value_w_inf = 1279,                // vec_value_w_inf
        S_symbol = 1280                          // symbol
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol () YY_NOEXCEPT
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value (std::move (that.value))
        , location (std::move (that.location))
      {}
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);
      /// Constructor for valueless symbols.
      basic_symbol (typename Base::kind_type t,
                    YY_MOVE_REF (location_type) l);

      /// Constructor for symbols with semantic value.
      basic_symbol (typename Base::kind_type t,
                    YY_RVREF (value_type) v,
                    YY_RVREF (location_type) l);

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }



      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
      {
        Base::clear ();
      }

      /// The user-facing name of this symbol.
      std::string name () const YY_NOEXCEPT
      {
        return parser::symbol_name (this->kind ());
      }

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      value_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Default constructor.
      by_kind () YY_NOEXCEPT;

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that) YY_NOEXCEPT;
#endif

      /// Copy constructor.
      by_kind (const by_kind& that) YY_NOEXCEPT;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t) YY_NOEXCEPT;



      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {};

    /// Build a parser object.
    parser (ParsingDriver &driver_yyarg);
    virtual ~parser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    parser (const parser&) = delete;
    /// Non copyable.
    parser& operator= (const parser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static std::string symbol_name (symbol_kind_type yysymbol);



    class context
    {
    public:
      context (const parser& yyparser, const symbol_type& yyla);
      const symbol_type& lookahead () const YY_NOEXCEPT { return yyla_; }
      symbol_kind_type token () const YY_NOEXCEPT { return yyla_.kind (); }
      const location_type& location () const YY_NOEXCEPT { return yyla_.location; }

      /// Put in YYARG at most YYARGN of the expected tokens, and return the
      /// number of tokens stored in YYARG.  If YYARG is null, return the
      /// number of expected tokens (guaranteed to be less than YYNTOKENS).
      int expected_tokens (symbol_kind_type yyarg[], int yyargn) const;

    private:
      const parser& yyparser_;
      const symbol_type& yyla_;
    };

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    parser (const parser&);
    /// Non copyable.
    parser& operator= (const parser&);
#endif


    /// Stored state numbers (used for stacks).
    typedef short state_type;

    /// The arguments of the error message.
    int yy_syntax_error_arguments_ (const context& yyctx,
                                    symbol_kind_type yyarg[], int yyargn) const;

    /// Generate an error message.
    /// \param yyctx     the context in which the error occurred.
    virtual std::string yysyntax_error_ (const context& yyctx) const;
    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT;

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT;

    static const short yypact_ninf_;
    static const short yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_kind_type enum.
    static symbol_kind_type yytranslate_ (int t) YY_NOEXCEPT;

    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *yystr);

    /// For a symbol, its name in clear.
    static const char* const yytname_[];


    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const short yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const short yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const short yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const short yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
    // state STATE-NUM.
    static const short yystos_[];

    // YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.
    static const short yyr1_[];

    // YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200) YY_NOEXCEPT
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range) YY_NOEXCEPT
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1) YY_NOEXCEPT;

    /// Constants.
    enum
    {
      yylast_ = 11972,     ///< Last index in yytable_.
      yynnts_ = 692,  ///< Number of nonterminal symbols.
      yyfinal_ = 375 ///< Termination state number.
    };


    // User arguments.
    ParsingDriver &driver;

  };


} // Dynare
#line 2656 "pkg/src/DynareBison.hh"




#endif // !YY_DYNARE_PKG_SRC_DYNAREBISON_HH_INCLUDED
