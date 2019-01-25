// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton interface for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

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
 ** \file DynareBison.hh
 ** Define the Dynare::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

#ifndef YY_DYNARE_DYNAREBISON_HH_INCLUDED
# define YY_DYNARE_DYNAREBISON_HH_INCLUDED
// //                    "%code requires" blocks.
#line 28 "lex_yacc/DynareBison.yy" // lalr1.cc:377

#include "ExprNode.hh"
#include "CodeInterpreter.hh"

#line 49 "DynareBison.hh" // lalr1.cc:377


# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>
# include "stack.hh"
# include "location.hh"


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

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif


namespace Dynare {
#line 121 "DynareBison.hh" // lalr1.cc:377





  /// A Bison parser.
  class parser
  {
  public:
#ifndef YYSTYPE
    /// Symbol semantic values.
    union semantic_type
    {
    #line 49 "lex_yacc/DynareBison.yy" // lalr1.cc:377

  string *string_val;
  expr_t node_val;
  SymbolType symbol_type_val;
  vector<string *> *vector_string_val;
  vector<int> *vector_int_val;
  pair<string *, string *> *string_pair_val;
  vector<pair<string *, string *> *> *vector_string_pair_val;
  PriorDistributions prior_distributions_val;

#line 146 "DynareBison.hh" // lalr1.cc:377
    };
#else
    typedef YYSTYPE semantic_type;
#endif
    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m);
      location_type location;
    };

    /// Tokens.
    struct token
    {
      enum yytokentype
      {
        AIM_SOLVER = 258,
        ANALYTIC_DERIVATION = 259,
        ANALYTIC_DERIVATION_MODE = 260,
        AR = 261,
        AUTOCORR = 262,
        POSTERIOR_SAMPLING_METHOD = 263,
        BAYESIAN_IRF = 264,
        BETA_PDF = 265,
        BLOCK = 266,
        USE_CALIBRATION = 267,
        SILENT_OPTIMIZER = 268,
        BVAR_DENSITY = 269,
        BVAR_FORECAST = 270,
        NODECOMPOSITION = 271,
        DR_DISPLAY_TOL = 272,
        HUGE_NUMBER = 273,
        FIG_NAME = 274,
        WRITE_XLS = 275,
        BVAR_PRIOR_DECAY = 276,
        BVAR_PRIOR_FLAT = 277,
        BVAR_PRIOR_LAMBDA = 278,
        INTERACTIVE = 279,
        SCREEN_SHOCKS = 280,
        STEADYSTATE = 281,
        BVAR_PRIOR_MU = 282,
        BVAR_PRIOR_OMEGA = 283,
        BVAR_PRIOR_TAU = 284,
        BVAR_PRIOR_TRAIN = 285,
        DETAIL_PLOT = 286,
        TYPE = 287,
        BVAR_REPLIC = 288,
        BYTECODE = 289,
        ALL_VALUES_REQUIRED = 290,
        PROPOSAL_DISTRIBUTION = 291,
        REALTIME = 292,
        VINTAGE = 293,
        CALIB_SMOOTHER = 294,
        CHANGE_TYPE = 295,
        CHECK = 296,
        CONDITIONAL_FORECAST = 297,
        CONDITIONAL_FORECAST_PATHS = 298,
        CONF_SIG = 299,
        CONSTANT = 300,
        CONTROLLED_VAREXO = 301,
        CORR = 302,
        COVAR = 303,
        CUTOFF = 304,
        CYCLE_REDUCTION = 305,
        LOGARITHMIC_REDUCTION = 306,
        CONSIDER_ALL_ENDOGENOUS = 307,
        CONSIDER_ONLY_OBSERVED = 308,
        INITIAL_CONDITION_DECOMPOSITION = 309,
        DATAFILE = 310,
        FILE = 311,
        SERIES = 312,
        DOUBLING = 313,
        DR_CYCLE_REDUCTION_TOL = 314,
        DR_LOGARITHMIC_REDUCTION_TOL = 315,
        DR_LOGARITHMIC_REDUCTION_MAXITER = 316,
        DR_ALGO = 317,
        DROP = 318,
        DSAMPLE = 319,
        DYNASAVE = 320,
        DYNATYPE = 321,
        CALIBRATION = 322,
        DIFFERENTIATE_FORWARD_VARS = 323,
        END = 324,
        ENDVAL = 325,
        EQUAL = 326,
        ESTIMATION = 327,
        ESTIMATED_PARAMS = 328,
        ESTIMATED_PARAMS_BOUNDS = 329,
        ESTIMATED_PARAMS_INIT = 330,
        EXTENDED_PATH = 331,
        ENDOGENOUS_PRIOR = 332,
        FILENAME = 333,
        DIRNAME = 334,
        FILTER_STEP_AHEAD = 335,
        FILTERED_VARS = 336,
        FIRST_OBS = 337,
        LAST_OBS = 338,
        SET_TIME = 339,
        OSR_PARAMS_BOUNDS = 340,
        KEEP_KALMAN_ALGO_IF_SINGULARITY_IS_DETECTED = 341,
        FLOAT_NUMBER = 342,
        DATES = 343,
        DEFAULT = 344,
        FIXED_POINT = 345,
        OPT_ALGO = 346,
        FORECAST = 347,
        K_ORDER_SOLVER = 348,
        INSTRUMENTS = 349,
        SHIFT = 350,
        MEAN = 351,
        STDEV = 352,
        VARIANCE = 353,
        MODE = 354,
        INTERVAL = 355,
        SHAPE = 356,
        DOMAINN = 357,
        GAMMA_PDF = 358,
        GRAPH = 359,
        GRAPH_FORMAT = 360,
        CONDITIONAL_VARIANCE_DECOMPOSITION = 361,
        NOCHECK = 362,
        STD = 363,
        HISTVAL = 364,
        HISTVAL_FILE = 365,
        HOMOTOPY_SETUP = 366,
        HOMOTOPY_MODE = 367,
        HOMOTOPY_STEPS = 368,
        HOMOTOPY_FORCE_CONTINUE = 369,
        HP_FILTER = 370,
        HP_NGRID = 371,
        HYBRID = 372,
        ONE_SIDED_HP_FILTER = 373,
        IDENTIFICATION = 374,
        INF_CONSTANT = 375,
        INITVAL = 376,
        INITVAL_FILE = 377,
        BOUNDS = 378,
        JSCALE = 379,
        INIT = 380,
        INFILE = 381,
        INVARS = 382,
        INT_NUMBER = 383,
        INV_GAMMA_PDF = 384,
        INV_GAMMA1_PDF = 385,
        INV_GAMMA2_PDF = 386,
        IRF = 387,
        IRF_SHOCKS = 388,
        IRF_PLOT_THRESHOLD = 389,
        IRF_CALIBRATION = 390,
        FAST_KALMAN_FILTER = 391,
        KALMAN_ALGO = 392,
        KALMAN_TOL = 393,
        DIFFUSE_KALMAN_TOL = 394,
        SUBSAMPLES = 395,
        OPTIONS = 396,
        TOLF = 397,
        TOLX = 398,
        PLOT_INIT_DATE = 399,
        PLOT_END_DATE = 400,
        LAPLACE = 401,
        LIK_ALGO = 402,
        LIK_INIT = 403,
        LINEAR = 404,
        LOAD_IDENT_FILES = 405,
        LOAD_MH_FILE = 406,
        LOAD_RESULTS_AFTER_LOAD_MH = 407,
        LOAD_PARAMS_AND_STEADY_STATE = 408,
        LOGLINEAR = 409,
        LOGDATA = 410,
        LYAPUNOV = 411,
        LINEAR_APPROXIMATION = 412,
        LYAPUNOV_FIXED_POINT_TOL = 413,
        LYAPUNOV_DOUBLING_TOL = 414,
        LYAPUNOV_SQUARE_ROOT_SOLVER_TOL = 415,
        LOG_DEFLATOR = 416,
        LOG_TREND_VAR = 417,
        LOG_GROWTH_FACTOR = 418,
        MARKOWITZ = 419,
        MARGINAL_DENSITY = 420,
        MAX = 421,
        MAXIT = 422,
        MFS = 423,
        MH_CONF_SIG = 424,
        MH_DROP = 425,
        MH_INIT_SCALE = 426,
        MH_JSCALE = 427,
        MH_MODE = 428,
        MH_NBLOCKS = 429,
        MH_REPLIC = 430,
        MH_RECOVER = 431,
        POSTERIOR_MAX_SUBSAMPLE_DRAWS = 432,
        MIN = 433,
        MINIMAL_SOLVING_PERIODS = 434,
        MODE_CHECK = 435,
        MODE_CHECK_NEIGHBOURHOOD_SIZE = 436,
        MODE_CHECK_SYMMETRIC_PLOTS = 437,
        MODE_CHECK_NUMBER_OF_POINTS = 438,
        MODE_COMPUTE = 439,
        MODE_FILE = 440,
        MODEL = 441,
        MODEL_COMPARISON = 442,
        MODEL_INFO = 443,
        MSHOCKS = 444,
        ABS = 445,
        SIGN = 446,
        MODEL_DIAGNOSTICS = 447,
        MODIFIEDHARMONICMEAN = 448,
        MOMENTS_VARENDO = 449,
        CONTEMPORANEOUS_CORRELATION = 450,
        DIFFUSE_FILTER = 451,
        SUB_DRAWS = 452,
        TAPER_STEPS = 453,
        GEWEKE_INTERVAL = 454,
        RAFTERY_LEWIS_QRS = 455,
        RAFTERY_LEWIS_DIAGNOSTICS = 456,
        MCMC_JUMPING_COVARIANCE = 457,
        MOMENT_CALIBRATION = 458,
        NUMBER_OF_PARTICLES = 459,
        RESAMPLING = 460,
        SYSTEMATIC = 461,
        GENERIC = 462,
        RESAMPLING_THRESHOLD = 463,
        RESAMPLING_METHOD = 464,
        KITAGAWA = 465,
        STRATIFIED = 466,
        SMOOTH = 467,
        CPF_WEIGHTS = 468,
        AMISANOTRISTANI = 469,
        MURRAYJONESPARSLOW = 470,
        WRITE_EQUATION_TAGS = 471,
        NONLINEAR_FILTER_INITIALIZATION = 472,
        FILTER_ALGORITHM = 473,
        PROPOSAL_APPROXIMATION = 474,
        CUBATURE = 475,
        UNSCENTED = 476,
        MONTECARLO = 477,
        DISTRIBUTION_APPROXIMATION = 478,
        NAME = 479,
        USE_PENALIZED_OBJECTIVE_FOR_HESSIAN = 480,
        INIT_STATE = 481,
        RESCALE_PREDICTION_ERROR_COVARIANCE = 482,
        NAN_CONSTANT = 483,
        NO_STATIC = 484,
        NOBS = 485,
        NOCONSTANT = 486,
        NODISPLAY = 487,
        NOCORR = 488,
        NODIAGNOSTIC = 489,
        NOFUNCTIONS = 490,
        NO_HOMOTOPY = 491,
        NOGRAPH = 492,
        POSTERIOR_NOGRAPH = 493,
        POSTERIOR_GRAPH = 494,
        NOMOMENTS = 495,
        NOPRINT = 496,
        NORMAL_PDF = 497,
        SAVE_DRAWS = 498,
        OBSERVATION_TRENDS = 499,
        OPTIM = 500,
        OPTIM_WEIGHTS = 501,
        ORDER = 502,
        OSR = 503,
        OSR_PARAMS = 504,
        MAX_DIM_COVA_GROUP = 505,
        ADVANCED = 506,
        OUTFILE = 507,
        OUTVARS = 508,
        OVERWRITE = 509,
        PARALLEL_LOCAL_FILES = 510,
        PARAMETERS = 511,
        PARAMETER_SET = 512,
        PARTIAL_INFORMATION = 513,
        PERIODS = 514,
        PERIOD = 515,
        PLANNER_OBJECTIVE = 516,
        PLOT_CONDITIONAL_FORECAST = 517,
        PLOT_PRIORS = 518,
        PREFILTER = 519,
        PRESAMPLE = 520,
        PERFECT_FORESIGHT_SETUP = 521,
        PERFECT_FORESIGHT_SOLVER = 522,
        NO_POSTERIOR_KERNEL_DENSITY = 523,
        FUNCTION = 524,
        PRINT = 525,
        PRIOR_MC = 526,
        PRIOR_TRUNC = 527,
        PRIOR_MODE = 528,
        PRIOR_MEAN = 529,
        POSTERIOR_MODE = 530,
        POSTERIOR_MEAN = 531,
        POSTERIOR_MEDIAN = 532,
        MLE_MODE = 533,
        PRUNING = 534,
        QUOTED_STRING = 535,
        QZ_CRITERIUM = 536,
        QZ_ZERO_THRESHOLD = 537,
        FULL = 538,
        DSGE_VAR = 539,
        DSGE_VARLAG = 540,
        DSGE_PRIOR_WEIGHT = 541,
        TRUNCATE = 542,
        RELATIVE_IRF = 543,
        REPLIC = 544,
        SIMUL_REPLIC = 545,
        RPLOT = 546,
        SAVE_PARAMS_AND_STEADY_STATE = 547,
        PARAMETER_UNCERTAINTY = 548,
        SHOCKS = 549,
        SHOCK_DECOMPOSITION = 550,
        SHOCK_GROUPS = 551,
        USE_SHOCK_GROUPS = 552,
        SIGMA_E = 553,
        SIMUL = 554,
        SIMUL_ALGO = 555,
        SIMUL_SEED = 556,
        ENDOGENOUS_TERMINAL_PERIOD = 557,
        SMOOTHER = 558,
        SMOOTHER2HISTVAL = 559,
        SQUARE_ROOT_SOLVER = 560,
        STACK_SOLVE_ALGO = 561,
        STEADY_STATE_MODEL = 562,
        SOLVE_ALGO = 563,
        SOLVER_PERIODS = 564,
        ROBUST_LIN_SOLVE = 565,
        STDERR = 566,
        STEADY = 567,
        STOCH_SIMUL = 568,
        SURPRISE = 569,
        SYLVESTER = 570,
        SYLVESTER_FIXED_POINT_TOL = 571,
        REGIMES = 572,
        REGIME = 573,
        REALTIME_SHOCK_DECOMPOSITION = 574,
        TEX = 575,
        RAMSEY_MODEL = 576,
        RAMSEY_POLICY = 577,
        RAMSEY_CONSTRAINTS = 578,
        PLANNER_DISCOUNT = 579,
        DISCRETIONARY_POLICY = 580,
        DISCRETIONARY_TOL = 581,
        TEX_NAME = 582,
        UNIFORM_PDF = 583,
        UNIT_ROOT_VARS = 584,
        USE_DLL = 585,
        USEAUTOCORR = 586,
        GSA_SAMPLE_FILE = 587,
        USE_UNIVARIATE_FILTERS_IF_SINGULARITY_IS_DETECTED = 588,
        VALUES = 589,
        VAR = 590,
        VAREXO = 591,
        VAREXO_DET = 592,
        VAROBS = 593,
        PREDETERMINED_VARIABLES = 594,
        PLOT_SHOCK_DECOMPOSITION = 595,
        WRITE_LATEX_DYNAMIC_MODEL = 596,
        WRITE_LATEX_STATIC_MODEL = 597,
        WRITE_LATEX_ORIGINAL_MODEL = 598,
        XLS_SHEET = 599,
        XLS_RANGE = 600,
        LMMCP = 601,
        OCCBIN = 602,
        BANDPASS_FILTER = 603,
        COLORMAP = 604,
        QOQ = 605,
        YOY = 606,
        AOA = 607,
        COMMA = 608,
        EQUAL_EQUAL = 609,
        EXCLAMATION_EQUAL = 610,
        LESS = 611,
        GREATER = 612,
        LESS_EQUAL = 613,
        GREATER_EQUAL = 614,
        PLUS = 615,
        MINUS = 616,
        TIMES = 617,
        DIVIDE = 618,
        UMINUS = 619,
        UPLUS = 620,
        POWER = 621,
        EXP = 622,
        LOG = 623,
        LN = 624,
        LOG10 = 625,
        SIN = 626,
        COS = 627,
        TAN = 628,
        ASIN = 629,
        ACOS = 630,
        ATAN = 631,
        SINH = 632,
        COSH = 633,
        TANH = 634,
        ERF = 635,
        ASINH = 636,
        ACOSH = 637,
        ATANH = 638,
        SQRT = 639,
        NORMCDF = 640,
        NORMPDF = 641,
        STEADY_STATE = 642,
        EXPECTATION = 643,
        DYNARE_SENSITIVITY = 644,
        MORRIS = 645,
        STAB = 646,
        REDFORM = 647,
        PPRIOR = 648,
        PRIOR_RANGE = 649,
        PPOST = 650,
        ILPTAU = 651,
        MORRIS_NLIV = 652,
        MORRIS_NTRA = 653,
        NSAM = 654,
        LOAD_REDFORM = 655,
        LOAD_RMSE = 656,
        LOAD_STAB = 657,
        ALPHA2_STAB = 658,
        LOGTRANS_REDFORM = 659,
        THRESHOLD_REDFORM = 660,
        KSSTAT_REDFORM = 661,
        ALPHA2_REDFORM = 662,
        NAMENDO = 663,
        NAMLAGENDO = 664,
        NAMEXO = 665,
        RMSE = 666,
        LIK_ONLY = 667,
        VAR_RMSE = 668,
        PFILT_RMSE = 669,
        ISTART_RMSE = 670,
        ALPHA_RMSE = 671,
        ALPHA2_RMSE = 672,
        FREQ = 673,
        INITIAL_YEAR = 674,
        INITIAL_SUBPERIOD = 675,
        FINAL_YEAR = 676,
        FINAL_SUBPERIOD = 677,
        DATA = 678,
        VLIST = 679,
        LOG_VAR = 680,
        PERCENT_VAR = 681,
        VLISTLOG = 682,
        VLISTPER = 683,
        SPECTRAL_DENSITY = 684,
        RESTRICTION = 685,
        RESTRICTION_FNAME = 686,
        CROSS_RESTRICTIONS = 687,
        NLAGS = 688,
        CONTEMP_REDUCED_FORM = 689,
        REAL_PSEUDO_FORECAST = 690,
        DUMMY_OBS = 691,
        NSTATES = 692,
        INDXSCALESSTATES = 693,
        NO_BAYESIAN_PRIOR = 694,
        SPECIFICATION = 695,
        SIMS_ZHA = 696,
        ALPHA = 697,
        BETA = 698,
        ABAND = 699,
        NINV = 700,
        CMS = 701,
        NCMS = 702,
        CNUM = 703,
        GAMMA = 704,
        INV_GAMMA = 705,
        INV_GAMMA1 = 706,
        INV_GAMMA2 = 707,
        NORMAL = 708,
        UNIFORM = 709,
        EPS = 710,
        PDF = 711,
        FIG = 712,
        DR = 713,
        NONE = 714,
        PRIOR = 715,
        PRIOR_VARIANCE = 716,
        HESSIAN = 717,
        IDENTITY_MATRIX = 718,
        DIRICHLET = 719,
        GSIG2_LMDM = 720,
        Q_DIAG = 721,
        FLAT_PRIOR = 722,
        NCSK = 723,
        NSTD = 724,
        WEIBULL = 725,
        WEIBULL_PDF = 726,
        INDXPARR = 727,
        INDXOVR = 728,
        INDXAP = 729,
        APBAND = 730,
        INDXIMF = 731,
        IMFBAND = 732,
        INDXFORE = 733,
        FOREBAND = 734,
        INDXGFOREHAT = 735,
        INDXGIMFHAT = 736,
        INDXESTIMA = 737,
        INDXGDLS = 738,
        EQ_MS = 739,
        FILTER_COVARIANCE = 740,
        FILTER_DECOMPOSITION = 741,
        SMOOTHED_STATE_UNCERTAINTY = 742,
        EQ_CMS = 743,
        TLINDX = 744,
        TLNUMBER = 745,
        BANACT = 746,
        RESTRICTIONS = 747,
        POSTERIOR_SAMPLER_OPTIONS = 748,
        OUTPUT_FILE_TAG = 749,
        DRAWS_NBR_BURN_IN_1 = 750,
        DRAWS_NBR_BURN_IN_2 = 751,
        HORIZON = 752,
        SBVAR = 753,
        TREND_VAR = 754,
        DEFLATOR = 755,
        GROWTH_FACTOR = 756,
        MS_IRF = 757,
        MS_VARIANCE_DECOMPOSITION = 758,
        MS_ESTIMATION = 759,
        MS_SIMULATION = 760,
        MS_COMPUTE_MDD = 761,
        MS_COMPUTE_PROBABILITIES = 762,
        MS_FORECAST = 763,
        SVAR_IDENTIFICATION = 764,
        EQUATION = 765,
        EXCLUSION = 766,
        LAG = 767,
        UPPER_CHOLESKY = 768,
        LOWER_CHOLESKY = 769,
        MONTHLY = 770,
        QUARTERLY = 771,
        MARKOV_SWITCHING = 772,
        CHAIN = 773,
        DURATION = 774,
        NUMBER_OF_REGIMES = 775,
        NUMBER_OF_LAGS = 776,
        SVAR = 777,
        SVAR_GLOBAL_IDENTIFICATION_CHECK = 778,
        COEFF = 779,
        COEFFICIENTS = 780,
        VARIANCES = 781,
        CONSTANTS = 782,
        EQUATIONS = 783,
        EXTERNAL_FUNCTION = 784,
        EXT_FUNC_NAME = 785,
        EXT_FUNC_NARGS = 786,
        FIRST_DERIV_PROVIDED = 787,
        SECOND_DERIV_PROVIDED = 788,
        SELECTED_VARIABLES_ONLY = 789,
        COVA_COMPUTE = 790,
        SIMULATION_FILE_TAG = 791,
        FILE_TAG = 792,
        NO_ERROR_BANDS = 793,
        ERROR_BAND_PERCENTILES = 794,
        SHOCKS_PER_PARAMETER = 795,
        NO_CREATE_INIT = 796,
        SHOCK_DRAWS = 797,
        FREE_PARAMETERS = 798,
        MEDIAN = 799,
        DATA_OBS_NBR = 800,
        NEIGHBORHOOD_WIDTH = 801,
        PVALUE_KS = 802,
        PVALUE_CORR = 803,
        FILTERED_PROBABILITIES = 804,
        REAL_TIME_SMOOTHED = 805,
        PRIOR_FUNCTION = 806,
        POSTERIOR_FUNCTION = 807,
        SAMPLING_DRAWS = 808,
        PROPOSAL_TYPE = 809,
        PROPOSAL_UPPER_BOUND = 810,
        PROPOSAL_LOWER_BOUND = 811,
        PROPOSAL_DRAWS = 812,
        USE_MEAN_CENTER = 813,
        ADAPTIVE_MH_DRAWS = 814,
        THINNING_FACTOR = 815,
        COEFFICIENTS_PRIOR_HYPERPARAMETERS = 816,
        CONVERGENCE_STARTING_VALUE = 817,
        CONVERGENCE_ENDING_VALUE = 818,
        CONVERGENCE_INCREMENT_VALUE = 819,
        MAX_ITERATIONS_STARTING_VALUE = 820,
        MAX_ITERATIONS_INCREMENT_VALUE = 821,
        MAX_BLOCK_ITERATIONS = 822,
        MAX_REPEATED_OPTIMIZATION_RUNS = 823,
        FUNCTION_CONVERGENCE_CRITERION = 824,
        SAVE_REALTIME = 825,
        PARAMETER_CONVERGENCE_CRITERION = 826,
        NUMBER_OF_LARGE_PERTURBATIONS = 827,
        NUMBER_OF_SMALL_PERTURBATIONS = 828,
        NUMBER_OF_POSTERIOR_DRAWS_AFTER_PERTURBATION = 829,
        MAX_NUMBER_OF_STAGES = 830,
        RANDOM_FUNCTION_CONVERGENCE_CRITERION = 831,
        RANDOM_PARAMETER_CONVERGENCE_CRITERION = 832,
        SYMBOL_VEC = 833
      };
    };

    /// (External) token type, as returned by yylex.
    typedef token::yytokentype token_type;

    /// Symbol type: an internal symbol number.
    typedef int symbol_number_type;

    /// The symbol type number to denote an empty symbol.
    enum { empty_symbol = -2 };

    /// Internal symbol number for tokens (subsumed by symbol_number_type).
    typedef unsigned short int token_number_type;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol type
    /// via type_get().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol ();

      /// Copy constructor.
      basic_symbol (const basic_symbol& other);

      /// Constructor for valueless symbols.
      basic_symbol (typename Base::kind_type t,
                    const location_type& l);

      /// Constructor for symbols with semantic value.
      basic_symbol (typename Base::kind_type t,
                    const semantic_type& v,
                    const location_type& l);

      /// Destroy the symbol.
      ~basic_symbol ();

      /// Destroy contents, and record that is empty.
      void clear ();

      /// Whether empty.
      bool empty () const;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

      /// The location.
      location_type location;

    private:
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& other);
    };

    /// Type access provider for token (enum) based symbols.
    struct by_type
    {
      /// Default constructor.
      by_type ();

      /// Copy constructor.
      by_type (const by_type& other);

      /// The symbol type as needed by the constructor.
      typedef token_type kind_type;

      /// Constructor from (external) token numbers.
      by_type (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_type& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_number_type type_get () const;

      /// The token.
      token_type token () const;

      /// The symbol type.
      /// \a empty_symbol when empty.
      /// An int, not token_number_type, to be able to store empty_symbol.
      int type;
    };

    /// "External" symbols: returned by the scanner.
    typedef basic_symbol<by_type> symbol_type;


    /// Build a parser object.
    parser (ParsingDriver &driver_yyarg);
    virtual ~parser ();

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

  private:
    /// This class is not copyable.
    parser (const parser&);
    parser& operator= (const parser&);

    /// State numbers.
    typedef int state_type;

    /// Generate an error message.
    /// \param yystate   the state where the error occurred.
    /// \param yyla      the lookahead token.
    virtual std::string yysyntax_error_ (state_type yystate,
                                         const symbol_type& yyla) const;

    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const short int yypact_ninf_;
    static const short int yytable_ninf_;

    /// Convert a scanner token number \a t to a symbol number.
    static token_number_type yytranslate_ (int t);

    // Tables.
  // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
  // STATE-NUM.
  static const short int yypact_[];

  // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
  // Performed when YYTABLE does not specify something else to do.  Zero
  // means the default is an error.
  static const unsigned short int yydefact_[];

  // YYPGOTO[NTERM-NUM].
  static const short int yypgoto_[];

  // YYDEFGOTO[NTERM-NUM].
  static const short int yydefgoto_[];

  // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
  // positive, shift that token.  If negative, reduce the rule whose
  // number is the opposite.  If YYTABLE_NINF, syntax error.
  static const short int yytable_[];

  static const short int yycheck_[];

  // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
  // symbol of state STATE-NUM.
  static const unsigned short int yystos_[];

  // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
  static const unsigned short int yyr1_[];

  // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
  static const unsigned char yyr2_[];


    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *n);


    /// For a symbol, its name in clear.
    static const char* const yytname_[];
#if YYDEBUG
  // YYRLINE[YYN] -- Source line where rule number YYN was defined.
  static const unsigned short int yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r);
    /// Print the state stack on the debug stream.
    virtual void yystack_print_ ();

    // Debugging.
    int yydebug_;
    std::ostream* yycdebug_;

    /// \brief Display a symbol type, value and location.
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
      by_state ();

      /// The symbol type as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s);

      /// Copy constructor.
      by_state (const by_state& other);

      /// Record that this symbol is empty.
      void clear ();

      /// Steal the symbol type from \a that.
      void move (by_state& that);

      /// The (internal) type number (corresponding to \a state).
      /// \a empty_symbol when empty.
      symbol_number_type type_get () const;

      /// The state number used to denote an empty symbol.
      enum { empty_state = -1 };

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
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, symbol_type& sym);
      /// Assignment, needed by push_back.
      stack_symbol_type& operator= (const stack_symbol_type& that);
    };

    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, stack_symbol_type& s);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, state_type s, symbol_type& sym);

    /// Pop \a n symbols the three stacks.
    void yypop_ (unsigned int n = 1);

    /// Constants.
    enum
    {
      yyeof_ = 0,
      yylast_ = 11709,     ///< Last index in yytable_.
      yynnts_ = 692,  ///< Number of nonterminal symbols.
      yyfinal_ = 375, ///< Termination state number.
      yyterror_ = 1,
      yyerrcode_ = 256,
      yyntokens_ = 587  ///< Number of tokens.
    };


    // User arguments.
    ParsingDriver &driver;
  };



} // Dynare
#line 1065 "DynareBison.hh" // lalr1.cc:377




#endif // !YY_DYNARE_DYNAREBISON_HH_INCLUDED
