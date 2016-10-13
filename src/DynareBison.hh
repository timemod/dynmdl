// A Bison parser, made by GNU Bison 3.0.2.

// Skeleton interface for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2013 Free Software Foundation, Inc.

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
#line 28 "DynareBison.yy" // lalr1.cc:372

#include "ExprNode.hh"
#include "CodeInterpreter.hh"

#line 49 "DynareBison.hh" // lalr1.cc:372


# include <vector>
# include <iostream>
# include <stdexcept>
# include <string>
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
#line 120 "DynareBison.hh" // lalr1.cc:372





  /// A Bison parser.
  class parser
  {
  public:
#ifndef YYSTYPE
    /// Symbol semantic values.
    union semantic_type
    {
    #line 49 "DynareBison.yy" // lalr1.cc:372

  string *string_val;
  expr_t node_val;
  SymbolType symbol_type_val;
  vector<string *> *vector_string_val;
  vector<int> *vector_int_val;
  pair<string *, string *> *string_pair_val;
  vector<pair<string *, string *> *> *vector_string_pair_val;
  PriorDistributions prior_distributions_val;

#line 145 "DynareBison.hh" // lalr1.cc:372
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
        BVAR_PRIOR_DECAY = 274,
        BVAR_PRIOR_FLAT = 275,
        BVAR_PRIOR_LAMBDA = 276,
        BVAR_PRIOR_MU = 277,
        BVAR_PRIOR_OMEGA = 278,
        BVAR_PRIOR_TAU = 279,
        BVAR_PRIOR_TRAIN = 280,
        BVAR_REPLIC = 281,
        BYTECODE = 282,
        ALL_VALUES_REQUIRED = 283,
        PROPOSAL_DISTRIBUTION = 284,
        CALIB_SMOOTHER = 285,
        CHANGE_TYPE = 286,
        CHECK = 287,
        CONDITIONAL_FORECAST = 288,
        CONDITIONAL_FORECAST_PATHS = 289,
        CONF_SIG = 290,
        CONSTANT = 291,
        CONTROLLED_VAREXO = 292,
        CORR = 293,
        COVAR = 294,
        CUTOFF = 295,
        CYCLE_REDUCTION = 296,
        LOGARITHMIC_REDUCTION = 297,
        CONSIDER_ALL_ENDOGENOUS = 298,
        CONSIDER_ONLY_OBSERVED = 299,
        DATAFILE = 300,
        FILE = 301,
        SERIES = 302,
        DOUBLING = 303,
        DR_CYCLE_REDUCTION_TOL = 304,
        DR_LOGARITHMIC_REDUCTION_TOL = 305,
        DR_LOGARITHMIC_REDUCTION_MAXITER = 306,
        DR_ALGO = 307,
        DROP = 308,
        DSAMPLE = 309,
        DYNASAVE = 310,
        DYNATYPE = 311,
        CALIBRATION = 312,
        DIFFERENTIATE_FORWARD_VARS = 313,
        END = 314,
        ENDVAL = 315,
        EQUAL = 316,
        ESTIMATION = 317,
        ESTIMATED_PARAMS = 318,
        ESTIMATED_PARAMS_BOUNDS = 319,
        ESTIMATED_PARAMS_INIT = 320,
        EXTENDED_PATH = 321,
        ENDOGENOUS_PRIOR = 322,
        FILENAME = 323,
        DIRNAME = 324,
        FILTER_STEP_AHEAD = 325,
        FILTERED_VARS = 326,
        FIRST_OBS = 327,
        LAST_OBS = 328,
        SET_TIME = 329,
        OSR_PARAMS_BOUNDS = 330,
        FLOAT_NUMBER = 331,
        DATES = 332,
        DEFAULT = 333,
        FIXED_POINT = 334,
        OPT_ALGO = 335,
        FORECAST = 336,
        K_ORDER_SOLVER = 337,
        INSTRUMENTS = 338,
        SHIFT = 339,
        MEAN = 340,
        STDEV = 341,
        VARIANCE = 342,
        MODE = 343,
        INTERVAL = 344,
        SHAPE = 345,
        DOMAINN = 346,
        GAMMA_PDF = 347,
        GRAPH = 348,
        GRAPH_FORMAT = 349,
        CONDITIONAL_VARIANCE_DECOMPOSITION = 350,
        NOCHECK = 351,
        STD = 352,
        HISTVAL = 353,
        HISTVAL_FILE = 354,
        HOMOTOPY_SETUP = 355,
        HOMOTOPY_MODE = 356,
        HOMOTOPY_STEPS = 357,
        HOMOTOPY_FORCE_CONTINUE = 358,
        HP_FILTER = 359,
        HP_NGRID = 360,
        HYBRID = 361,
        ONE_SIDED_HP_FILTER = 362,
        IDENTIFICATION = 363,
        INF_CONSTANT = 364,
        INITVAL = 365,
        INITVAL_FILE = 366,
        BOUNDS = 367,
        JSCALE = 368,
        INIT = 369,
        INFILE = 370,
        INVARS = 371,
        INT_NUMBER = 372,
        INV_GAMMA_PDF = 373,
        INV_GAMMA1_PDF = 374,
        INV_GAMMA2_PDF = 375,
        IRF = 376,
        IRF_SHOCKS = 377,
        IRF_PLOT_THRESHOLD = 378,
        IRF_CALIBRATION = 379,
        FAST_KALMAN_FILTER = 380,
        KALMAN_ALGO = 381,
        KALMAN_TOL = 382,
        DIFFUSE_KALMAN_TOL = 383,
        SUBSAMPLES = 384,
        OPTIONS = 385,
        TOLF = 386,
        TOLX = 387,
        LAPLACE = 388,
        LIK_ALGO = 389,
        LIK_INIT = 390,
        LINEAR = 391,
        LOAD_IDENT_FILES = 392,
        LOAD_MH_FILE = 393,
        LOAD_PARAMS_AND_STEADY_STATE = 394,
        LOGLINEAR = 395,
        LOGDATA = 396,
        LYAPUNOV = 397,
        LINEAR_APPROXIMATION = 398,
        LYAPUNOV_FIXED_POINT_TOL = 399,
        LYAPUNOV_DOUBLING_TOL = 400,
        LYAPUNOV_SQUARE_ROOT_SOLVER_TOL = 401,
        LOG_DEFLATOR = 402,
        LOG_TREND_VAR = 403,
        LOG_GROWTH_FACTOR = 404,
        MARKOWITZ = 405,
        MARGINAL_DENSITY = 406,
        MAX = 407,
        MAXIT = 408,
        MFS = 409,
        MH_CONF_SIG = 410,
        MH_DROP = 411,
        MH_INIT_SCALE = 412,
        MH_JSCALE = 413,
        MH_MODE = 414,
        MH_NBLOCKS = 415,
        MH_REPLIC = 416,
        MH_RECOVER = 417,
        POSTERIOR_MAX_SUBSAMPLE_DRAWS = 418,
        MIN = 419,
        MINIMAL_SOLVING_PERIODS = 420,
        MODE_CHECK = 421,
        MODE_CHECK_NEIGHBOURHOOD_SIZE = 422,
        MODE_CHECK_SYMMETRIC_PLOTS = 423,
        MODE_CHECK_NUMBER_OF_POINTS = 424,
        MODE_COMPUTE = 425,
        MODE_FILE = 426,
        MODEL = 427,
        MODEL_COMPARISON = 428,
        MODEL_INFO = 429,
        MSHOCKS = 430,
        ABS = 431,
        SIGN = 432,
        MODEL_DIAGNOSTICS = 433,
        MODIFIEDHARMONICMEAN = 434,
        MOMENTS_VARENDO = 435,
        CONTEMPORANEOUS_CORRELATION = 436,
        DIFFUSE_FILTER = 437,
        SUB_DRAWS = 438,
        TAPER_STEPS = 439,
        GEWEKE_INTERVAL = 440,
        MCMC_JUMPING_COVARIANCE = 441,
        MOMENT_CALIBRATION = 442,
        NUMBER_OF_PARTICLES = 443,
        RESAMPLING = 444,
        SYSTEMATIC = 445,
        GENERIC = 446,
        RESAMPLING_THRESHOLD = 447,
        RESAMPLING_METHOD = 448,
        KITAGAWA = 449,
        STRATIFIED = 450,
        SMOOTH = 451,
        CPF_WEIGHTS = 452,
        AMISANOTRISTANI = 453,
        MURRAYJONESPARSLOW = 454,
        FILTER_ALGORITHM = 455,
        PROPOSAL_APPROXIMATION = 456,
        CUBATURE = 457,
        UNSCENTED = 458,
        MONTECARLO = 459,
        DISTRIBUTION_APPROXIMATION = 460,
        NAME = 461,
        NAN_CONSTANT = 462,
        NO_STATIC = 463,
        NOBS = 464,
        NOCONSTANT = 465,
        NODISPLAY = 466,
        NOCORR = 467,
        NODIAGNOSTIC = 468,
        NOFUNCTIONS = 469,
        NO_HOMOTOPY = 470,
        NOGRAPH = 471,
        NOMOMENTS = 472,
        NOPRINT = 473,
        NORMAL_PDF = 474,
        SAVE_DRAWS = 475,
        OBSERVATION_TRENDS = 476,
        OPTIM = 477,
        OPTIM_WEIGHTS = 478,
        ORDER = 479,
        OSR = 480,
        OSR_PARAMS = 481,
        MAX_DIM_COVA_GROUP = 482,
        ADVANCED = 483,
        OUTFILE = 484,
        OUTVARS = 485,
        OVERWRITE = 486,
        PARALLEL_LOCAL_FILES = 487,
        PARAMETERS = 488,
        PARAMETER_SET = 489,
        PARTIAL_INFORMATION = 490,
        PERIODS = 491,
        PERIOD = 492,
        PLANNER_OBJECTIVE = 493,
        PLOT_CONDITIONAL_FORECAST = 494,
        PLOT_PRIORS = 495,
        PREFILTER = 496,
        PRESAMPLE = 497,
        PERFECT_FORESIGHT_SETUP = 498,
        PERFECT_FORESIGHT_SOLVER = 499,
        NO_POSTERIOR_KERNEL_DENSITY = 500,
        FUNCTION = 501,
        PRINT = 502,
        PRIOR_MC = 503,
        PRIOR_TRUNC = 504,
        PRIOR_MODE = 505,
        PRIOR_MEAN = 506,
        POSTERIOR_MODE = 507,
        POSTERIOR_MEAN = 508,
        POSTERIOR_MEDIAN = 509,
        MLE_MODE = 510,
        PRUNING = 511,
        QUOTED_STRING = 512,
        QZ_CRITERIUM = 513,
        QZ_ZERO_THRESHOLD = 514,
        FULL = 515,
        DSGE_VAR = 516,
        DSGE_VARLAG = 517,
        DSGE_PRIOR_WEIGHT = 518,
        TRUNCATE = 519,
        RELATIVE_IRF = 520,
        REPLIC = 521,
        SIMUL_REPLIC = 522,
        RPLOT = 523,
        SAVE_PARAMS_AND_STEADY_STATE = 524,
        PARAMETER_UNCERTAINTY = 525,
        SHOCKS = 526,
        SHOCK_DECOMPOSITION = 527,
        SHOCK_GROUPS = 528,
        USE_SHOCK_GROUPS = 529,
        SIGMA_E = 530,
        SIMUL = 531,
        SIMUL_ALGO = 532,
        SIMUL_SEED = 533,
        ENDOGENOUS_TERMINAL_PERIOD = 534,
        SMOOTHER = 535,
        SMOOTHER2HISTVAL = 536,
        SQUARE_ROOT_SOLVER = 537,
        STACK_SOLVE_ALGO = 538,
        STEADY_STATE_MODEL = 539,
        SOLVE_ALGO = 540,
        SOLVER_PERIODS = 541,
        STDERR = 542,
        STEADY = 543,
        STOCH_SIMUL = 544,
        SURPRISE = 545,
        SYLVESTER = 546,
        SYLVESTER_FIXED_POINT_TOL = 547,
        REGIMES = 548,
        REGIME = 549,
        TEX = 550,
        RAMSEY_MODEL = 551,
        RAMSEY_POLICY = 552,
        RAMSEY_CONSTRAINTS = 553,
        PLANNER_DISCOUNT = 554,
        DISCRETIONARY_POLICY = 555,
        DISCRETIONARY_TOL = 556,
        TEX_NAME = 557,
        UNIFORM_PDF = 558,
        UNIT_ROOT_VARS = 559,
        USE_DLL = 560,
        USEAUTOCORR = 561,
        GSA_SAMPLE_FILE = 562,
        USE_UNIVARIATE_FILTERS_IF_SINGULARITY_IS_DETECTED = 563,
        VALUES = 564,
        VAR = 565,
        VAREXO = 566,
        VAREXO_DET = 567,
        VAROBS = 568,
        PREDETERMINED_VARIABLES = 569,
        WRITE_LATEX_DYNAMIC_MODEL = 570,
        WRITE_LATEX_STATIC_MODEL = 571,
        WRITE_LATEX_ORIGINAL_MODEL = 572,
        XLS_SHEET = 573,
        XLS_RANGE = 574,
        LMMCP = 575,
        OCCBIN = 576,
        BANDPASS_FILTER = 577,
        COLORMAP = 578,
        COMMA = 579,
        EQUAL_EQUAL = 580,
        EXCLAMATION_EQUAL = 581,
        LESS = 582,
        GREATER = 583,
        LESS_EQUAL = 584,
        GREATER_EQUAL = 585,
        PLUS = 586,
        MINUS = 587,
        TIMES = 588,
        DIVIDE = 589,
        UMINUS = 590,
        UPLUS = 591,
        POWER = 592,
        EXP = 593,
        LOG = 594,
        LN = 595,
        LOG10 = 596,
        SIN = 597,
        COS = 598,
        TAN = 599,
        ASIN = 600,
        ACOS = 601,
        ATAN = 602,
        SINH = 603,
        COSH = 604,
        TANH = 605,
        ERF = 606,
        ASINH = 607,
        ACOSH = 608,
        ATANH = 609,
        SQRT = 610,
        NORMCDF = 611,
        NORMPDF = 612,
        STEADY_STATE = 613,
        EXPECTATION = 614,
        DYNARE_SENSITIVITY = 615,
        MORRIS = 616,
        STAB = 617,
        REDFORM = 618,
        PPRIOR = 619,
        PRIOR_RANGE = 620,
        PPOST = 621,
        ILPTAU = 622,
        MORRIS_NLIV = 623,
        MORRIS_NTRA = 624,
        NSAM = 625,
        LOAD_REDFORM = 626,
        LOAD_RMSE = 627,
        LOAD_STAB = 628,
        ALPHA2_STAB = 629,
        KSSTAT = 630,
        LOGTRANS_REDFORM = 631,
        THRESHOLD_REDFORM = 632,
        KSSTAT_REDFORM = 633,
        ALPHA2_REDFORM = 634,
        NAMENDO = 635,
        NAMLAGENDO = 636,
        NAMEXO = 637,
        RMSE = 638,
        LIK_ONLY = 639,
        VAR_RMSE = 640,
        PFILT_RMSE = 641,
        ISTART_RMSE = 642,
        ALPHA_RMSE = 643,
        ALPHA2_RMSE = 644,
        FREQ = 645,
        INITIAL_YEAR = 646,
        INITIAL_SUBPERIOD = 647,
        FINAL_YEAR = 648,
        FINAL_SUBPERIOD = 649,
        DATA = 650,
        VLIST = 651,
        LOG_VAR = 652,
        PERCENT_VAR = 653,
        VLISTLOG = 654,
        VLISTPER = 655,
        SPECTRAL_DENSITY = 656,
        RESTRICTION = 657,
        RESTRICTION_FNAME = 658,
        CROSS_RESTRICTIONS = 659,
        NLAGS = 660,
        CONTEMP_REDUCED_FORM = 661,
        REAL_PSEUDO_FORECAST = 662,
        DUMMY_OBS = 663,
        NSTATES = 664,
        INDXSCALESSTATES = 665,
        NO_BAYESIAN_PRIOR = 666,
        SPECIFICATION = 667,
        SIMS_ZHA = 668,
        ALPHA = 669,
        BETA = 670,
        ABAND = 671,
        NINV = 672,
        CMS = 673,
        NCMS = 674,
        CNUM = 675,
        GAMMA = 676,
        INV_GAMMA = 677,
        INV_GAMMA1 = 678,
        INV_GAMMA2 = 679,
        NORMAL = 680,
        UNIFORM = 681,
        EPS = 682,
        PDF = 683,
        FIG = 684,
        DR = 685,
        NONE = 686,
        PRIOR = 687,
        PRIOR_VARIANCE = 688,
        HESSIAN = 689,
        IDENTITY_MATRIX = 690,
        DIRICHLET = 691,
        GSIG2_LMDM = 692,
        Q_DIAG = 693,
        FLAT_PRIOR = 694,
        NCSK = 695,
        NSTD = 696,
        WEIBULL = 697,
        WEIBULL_PDF = 698,
        INDXPARR = 699,
        INDXOVR = 700,
        INDXAP = 701,
        APBAND = 702,
        INDXIMF = 703,
        IMFBAND = 704,
        INDXFORE = 705,
        FOREBAND = 706,
        INDXGFOREHAT = 707,
        INDXGIMFHAT = 708,
        INDXESTIMA = 709,
        INDXGDLS = 710,
        EQ_MS = 711,
        FILTER_COVARIANCE = 712,
        FILTER_DECOMPOSITION = 713,
        EQ_CMS = 714,
        TLINDX = 715,
        TLNUMBER = 716,
        BANACT = 717,
        RESTRICTIONS = 718,
        POSTERIOR_SAMPLER_OPTIONS = 719,
        OUTPUT_FILE_TAG = 720,
        DRAWS_NBR_BURN_IN_1 = 721,
        DRAWS_NBR_BURN_IN_2 = 722,
        HORIZON = 723,
        SBVAR = 724,
        TREND_VAR = 725,
        DEFLATOR = 726,
        GROWTH_FACTOR = 727,
        MS_IRF = 728,
        MS_VARIANCE_DECOMPOSITION = 729,
        MS_ESTIMATION = 730,
        MS_SIMULATION = 731,
        MS_COMPUTE_MDD = 732,
        MS_COMPUTE_PROBABILITIES = 733,
        MS_FORECAST = 734,
        SVAR_IDENTIFICATION = 735,
        EQUATION = 736,
        EXCLUSION = 737,
        LAG = 738,
        UPPER_CHOLESKY = 739,
        LOWER_CHOLESKY = 740,
        MONTHLY = 741,
        QUARTERLY = 742,
        MARKOV_SWITCHING = 743,
        CHAIN = 744,
        DURATION = 745,
        NUMBER_OF_REGIMES = 746,
        NUMBER_OF_LAGS = 747,
        SVAR = 748,
        SVAR_GLOBAL_IDENTIFICATION_CHECK = 749,
        COEFF = 750,
        COEFFICIENTS = 751,
        VARIANCES = 752,
        CONSTANTS = 753,
        EQUATIONS = 754,
        EXTERNAL_FUNCTION = 755,
        EXT_FUNC_NAME = 756,
        EXT_FUNC_NARGS = 757,
        FIRST_DERIV_PROVIDED = 758,
        SECOND_DERIV_PROVIDED = 759,
        SELECTED_VARIABLES_ONLY = 760,
        COVA_COMPUTE = 761,
        SIMULATION_FILE_TAG = 762,
        FILE_TAG = 763,
        NO_ERROR_BANDS = 764,
        ERROR_BAND_PERCENTILES = 765,
        SHOCKS_PER_PARAMETER = 766,
        NO_CREATE_INIT = 767,
        SHOCK_DRAWS = 768,
        FREE_PARAMETERS = 769,
        MEDIAN = 770,
        DATA_OBS_NBR = 771,
        NEIGHBORHOOD_WIDTH = 772,
        PVALUE_KS = 773,
        PVALUE_CORR = 774,
        FILTERED_PROBABILITIES = 775,
        REAL_TIME_SMOOTHED = 776,
        PRIOR_FUNCTION = 777,
        POSTERIOR_FUNCTION = 778,
        SAMPLING_DRAWS = 779,
        PROPOSAL_TYPE = 780,
        PROPOSAL_UPPER_BOUND = 781,
        PROPOSAL_LOWER_BOUND = 782,
        PROPOSAL_DRAWS = 783,
        USE_MEAN_CENTER = 784,
        ADAPTIVE_MH_DRAWS = 785,
        THINNING_FACTOR = 786,
        COEFFICIENTS_PRIOR_HYPERPARAMETERS = 787,
        CONVERGENCE_STARTING_VALUE = 788,
        CONVERGENCE_ENDING_VALUE = 789,
        CONVERGENCE_INCREMENT_VALUE = 790,
        MAX_ITERATIONS_STARTING_VALUE = 791,
        MAX_ITERATIONS_INCREMENT_VALUE = 792,
        MAX_BLOCK_ITERATIONS = 793,
        MAX_REPEATED_OPTIMIZATION_RUNS = 794,
        FUNCTION_CONVERGENCE_CRITERION = 795,
        PARAMETER_CONVERGENCE_CRITERION = 796,
        NUMBER_OF_LARGE_PERTURBATIONS = 797,
        NUMBER_OF_SMALL_PERTURBATIONS = 798,
        NUMBER_OF_POSTERIOR_DRAWS_AFTER_PERTURBATION = 799,
        MAX_NUMBER_OF_STAGES = 800,
        RANDOM_FUNCTION_CONVERGENCE_CRITERION = 801,
        RANDOM_PARAMETER_CONVERGENCE_CRITERION = 802,
        SYMBOL_VEC = 803
      };
    };

    /// (External) token type, as returned by yylex.
    typedef token::yytokentype token_type;

    /// Internal symbol number.
    typedef int symbol_number_type;

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

      ~basic_symbol ();

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

      /// Steal the symbol type from \a that.
      void move (by_type& that);

      /// The (internal) type number (corresponding to \a type).
      /// -1 when this symbol is empty.
      symbol_number_type type_get () const;

      /// The token.
      token_type token () const;

      enum { empty = 0 };

      /// The symbol type.
      /// -1 when this symbol is empty.
      token_number_type type;
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
    /// \param yytoken   the lookahead token type, or yyempty_.
    virtual std::string yysyntax_error_ (state_type yystate,
                                         symbol_number_type yytoken) const;

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

      /// Steal the symbol type from \a that.
      void move (by_state& that);

      /// The (internal) type number (corresponding to \a state).
      /// "empty" when empty.
      symbol_number_type type_get () const;

      enum { empty = 0 };

      /// The state.
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

    // Constants.
    enum
    {
      yyeof_ = 0,
      yylast_ = 10697,     ///< Last index in yytable_.
      yynnts_ = 647,  ///< Number of nonterminal symbols.
      yyempty_ = -2,
      yyfinal_ = 359, ///< Termination state number.
      yyterror_ = 1,
      yyerrcode_ = 256,
      yyntokens_ = 557  ///< Number of tokens.
    };


    // User arguments.
    ParsingDriver &driver;
  };



} // Dynare
#line 1018 "DynareBison.hh" // lalr1.cc:372




#endif // !YY_DYNARE_DYNAREBISON_HH_INCLUDED
