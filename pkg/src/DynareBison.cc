// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

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

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

// "%code top" blocks.
#line 24 "pkg/src/lex_yacc/DynareBison.yy"

class ParsingDriver;

#line 43 "pkg/src/DynareBison.cc"

// Take the name prefix into account.
#define yylex   Dynarelex



#include "DynareBison.hh"


// Unqualified %code blocks.
#line 60 "pkg/src/lex_yacc/DynareBison.yy"

/* Little hack: we redefine the macro which computes the locations, because
   we need to access the location from within the parsing driver for error
   and warning messages. */
#define YYLLOC_DEFAULT(Current, Rhs, N)                         \
  do {                                                          \
    if (N)                                                      \
      {                                                         \
        (Current).begin = YYRHSLOC(Rhs, 1).begin;               \
        (Current).end   = YYRHSLOC(Rhs, N).end;                 \
      }                                                         \
    else                                                        \
      {                                                         \
        (Current).begin = (Current).end = YYRHSLOC(Rhs, 0).end;	\
      }                                                         \
    driver.location = (Current);                                \
  } while(false)

#include "ParsingDriver.hh"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex

#line 81 "pkg/src/DynareBison.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace Dynare {
#line 173 "pkg/src/DynareBison.cc"

  /// Build a parser object.
  parser::parser (ParsingDriver &driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      driver (driver_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value (that.value)
    , location (that.location)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_MOVE_REF (location_type) l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, YY_RVREF (value_type) v, YY_RVREF (location_type) l)
    : Base (t)
    , value (YY_MOVE (v))
    , location (YY_MOVE (l))
  {}


  template <typename Base>
  parser::symbol_kind_type
  parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    value = YY_MOVE (s.value);
    location = YY_MOVE (s.location);
  }

  // by_kind.
  parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  parser::symbol_kind_type
  parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  parser::symbol_kind_type
  parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.value), YY_MOVE (that.location))
  {
#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.value), YY_MOVE (that.location))
  {
    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YY_USE (yysym.kind ());
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    // User initialization code.
#line 40 "pkg/src/lex_yacc/DynareBison.yy"
{
  // Initialize the locations' filenames to the filename maintained by the lexer
  yyla.location.begin.filename = yyla.location.end.filename = &(driver.lexer->filename);
}

#line 518 "pkg/src/DynareBison.cc"


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, &yyla.location, driver));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;

      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 100: // dsample: DSAMPLE INT_NUMBER ';'
#line 300 "pkg/src/lex_yacc/DynareBison.yy"
          { driver.dsample((yystack_[1].value.string_val)); }
#line 656 "pkg/src/DynareBison.cc"
    break;

  case 101: // dsample: DSAMPLE INT_NUMBER INT_NUMBER ';'
#line 302 "pkg/src/lex_yacc/DynareBison.yy"
          { driver.dsample((yystack_[2].value.string_val), (yystack_[1].value.string_val)); }
#line 662 "pkg/src/DynareBison.cc"
    break;

  case 102: // rplot: RPLOT symbol_list ';'
#line 305 "pkg/src/lex_yacc/DynareBison.yy"
                              { driver.rplot(); }
#line 668 "pkg/src/DynareBison.cc"
    break;

  case 103: // $@1: %empty
#line 307 "pkg/src/lex_yacc/DynareBison.yy"
                                              { driver.begin_trend(); }
#line 674 "pkg/src/DynareBison.cc"
    break;

  case 104: // trend_var: TREND_VAR '(' GROWTH_FACTOR EQUAL $@1 hand_side ')' trend_var_list ';'
#line 308 "pkg/src/lex_yacc/DynareBison.yy"
            { driver.end_trend_var((yystack_[3].value.node_val)); }
#line 680 "pkg/src/DynareBison.cc"
    break;

  case 105: // trend_var_list: trend_var_list symbol
#line 312 "pkg/src/lex_yacc/DynareBison.yy"
                 { driver.declare_trend_var(false, (yystack_[0].value.string_val)); }
#line 686 "pkg/src/DynareBison.cc"
    break;

  case 106: // trend_var_list: trend_var_list COMMA symbol
#line 314 "pkg/src/lex_yacc/DynareBison.yy"
                 { driver.declare_trend_var(false, (yystack_[0].value.string_val)); }
#line 692 "pkg/src/DynareBison.cc"
    break;

  case 107: // trend_var_list: symbol
#line 316 "pkg/src/lex_yacc/DynareBison.yy"
                 { driver.declare_trend_var(false, (yystack_[0].value.string_val)); }
#line 698 "pkg/src/DynareBison.cc"
    break;

  case 108: // trend_var_list: trend_var_list symbol TEX_NAME
#line 318 "pkg/src/lex_yacc/DynareBison.yy"
                 { driver.declare_trend_var(false, (yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 704 "pkg/src/DynareBison.cc"
    break;

  case 109: // trend_var_list: trend_var_list COMMA symbol TEX_NAME
#line 320 "pkg/src/lex_yacc/DynareBison.yy"
                 { driver.declare_trend_var(false, (yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 710 "pkg/src/DynareBison.cc"
    break;

  case 110: // trend_var_list: symbol TEX_NAME
#line 322 "pkg/src/lex_yacc/DynareBison.yy"
                 { driver.declare_trend_var(false, (yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 716 "pkg/src/DynareBison.cc"
    break;

  case 111: // $@2: %empty
#line 325 "pkg/src/lex_yacc/DynareBison.yy"
                                                          { driver.begin_trend(); }
#line 722 "pkg/src/DynareBison.cc"
    break;

  case 112: // log_trend_var: LOG_TREND_VAR '(' LOG_GROWTH_FACTOR EQUAL $@2 hand_side ')' log_trend_var_list ';'
#line 326 "pkg/src/lex_yacc/DynareBison.yy"
                { driver.end_trend_var((yystack_[3].value.node_val)); }
#line 728 "pkg/src/DynareBison.cc"
    break;

  case 113: // log_trend_var_list: log_trend_var_list symbol
#line 330 "pkg/src/lex_yacc/DynareBison.yy"
                     { driver.declare_trend_var(true, (yystack_[0].value.string_val)); }
#line 734 "pkg/src/DynareBison.cc"
    break;

  case 114: // log_trend_var_list: log_trend_var_list COMMA symbol
#line 332 "pkg/src/lex_yacc/DynareBison.yy"
                     { driver.declare_trend_var(true, (yystack_[0].value.string_val)); }
#line 740 "pkg/src/DynareBison.cc"
    break;

  case 115: // log_trend_var_list: symbol
#line 334 "pkg/src/lex_yacc/DynareBison.yy"
                     { driver.declare_trend_var(true, (yystack_[0].value.string_val)); }
#line 746 "pkg/src/DynareBison.cc"
    break;

  case 116: // log_trend_var_list: log_trend_var_list symbol TEX_NAME
#line 336 "pkg/src/lex_yacc/DynareBison.yy"
                     { driver.declare_trend_var(true, (yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 752 "pkg/src/DynareBison.cc"
    break;

  case 117: // log_trend_var_list: log_trend_var_list COMMA symbol TEX_NAME
#line 338 "pkg/src/lex_yacc/DynareBison.yy"
                     { driver.declare_trend_var(true, (yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 758 "pkg/src/DynareBison.cc"
    break;

  case 118: // log_trend_var_list: symbol TEX_NAME
#line 340 "pkg/src/lex_yacc/DynareBison.yy"
                     { driver.declare_trend_var(true, (yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 764 "pkg/src/DynareBison.cc"
    break;

  case 120: // $@3: %empty
#line 344 "pkg/src/lex_yacc/DynareBison.yy"
                             { driver.begin_trend(); }
#line 770 "pkg/src/DynareBison.cc"
    break;

  case 121: // var: VAR '(' DEFLATOR EQUAL $@3 hand_side ')' nonstationary_var_list ';'
#line 345 "pkg/src/lex_yacc/DynareBison.yy"
      { driver.end_nonstationary_var(false, (yystack_[3].value.node_val)); }
#line 776 "pkg/src/DynareBison.cc"
    break;

  case 122: // $@4: %empty
#line 346 "pkg/src/lex_yacc/DynareBison.yy"
                                 { driver.begin_trend(); }
#line 782 "pkg/src/DynareBison.cc"
    break;

  case 123: // var: VAR '(' LOG_DEFLATOR EQUAL $@4 hand_side ')' nonstationary_var_list ';'
#line 347 "pkg/src/lex_yacc/DynareBison.yy"
      { driver.end_nonstationary_var(true, (yystack_[3].value.node_val)); }
#line 788 "pkg/src/DynareBison.cc"
    break;

  case 124: // nonstationary_var_list: nonstationary_var_list symbol
#line 351 "pkg/src/lex_yacc/DynareBison.yy"
                         { driver.declare_nonstationary_var((yystack_[0].value.string_val)); }
#line 794 "pkg/src/DynareBison.cc"
    break;

  case 125: // nonstationary_var_list: nonstationary_var_list COMMA symbol
#line 353 "pkg/src/lex_yacc/DynareBison.yy"
                         { driver.declare_nonstationary_var((yystack_[0].value.string_val)); }
#line 800 "pkg/src/DynareBison.cc"
    break;

  case 126: // nonstationary_var_list: symbol
#line 355 "pkg/src/lex_yacc/DynareBison.yy"
                         { driver.declare_nonstationary_var((yystack_[0].value.string_val)); }
#line 806 "pkg/src/DynareBison.cc"
    break;

  case 127: // nonstationary_var_list: nonstationary_var_list symbol named_var
#line 357 "pkg/src/lex_yacc/DynareBison.yy"
                         { driver.declare_nonstationary_var((yystack_[1].value.string_val), NULL, (yystack_[0].value.vector_string_pair_val)); }
#line 812 "pkg/src/DynareBison.cc"
    break;

  case 128: // nonstationary_var_list: nonstationary_var_list COMMA symbol named_var
#line 359 "pkg/src/lex_yacc/DynareBison.yy"
                         { driver.declare_nonstationary_var((yystack_[1].value.string_val), NULL, (yystack_[0].value.vector_string_pair_val)); }
#line 818 "pkg/src/DynareBison.cc"
    break;

  case 129: // nonstationary_var_list: symbol named_var
#line 361 "pkg/src/lex_yacc/DynareBison.yy"
                         { driver.declare_nonstationary_var((yystack_[1].value.string_val), NULL, (yystack_[0].value.vector_string_pair_val)); }
#line 824 "pkg/src/DynareBison.cc"
    break;

  case 130: // nonstationary_var_list: nonstationary_var_list symbol TEX_NAME
#line 363 "pkg/src/lex_yacc/DynareBison.yy"
                         { driver.declare_nonstationary_var((yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 830 "pkg/src/DynareBison.cc"
    break;

  case 131: // nonstationary_var_list: nonstationary_var_list COMMA symbol TEX_NAME
#line 365 "pkg/src/lex_yacc/DynareBison.yy"
                         { driver.declare_nonstationary_var((yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 836 "pkg/src/DynareBison.cc"
    break;

  case 132: // nonstationary_var_list: symbol TEX_NAME
#line 367 "pkg/src/lex_yacc/DynareBison.yy"
                         { driver.declare_nonstationary_var((yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 842 "pkg/src/DynareBison.cc"
    break;

  case 133: // nonstationary_var_list: nonstationary_var_list symbol TEX_NAME named_var
#line 369 "pkg/src/lex_yacc/DynareBison.yy"
                         { driver.declare_nonstationary_var((yystack_[2].value.string_val), (yystack_[1].value.string_val), (yystack_[0].value.vector_string_pair_val)); }
#line 848 "pkg/src/DynareBison.cc"
    break;

  case 134: // nonstationary_var_list: nonstationary_var_list COMMA symbol TEX_NAME named_var
#line 371 "pkg/src/lex_yacc/DynareBison.yy"
                         { driver.declare_nonstationary_var((yystack_[2].value.string_val), (yystack_[1].value.string_val), (yystack_[0].value.vector_string_pair_val)); }
#line 854 "pkg/src/DynareBison.cc"
    break;

  case 135: // nonstationary_var_list: symbol TEX_NAME named_var
#line 373 "pkg/src/lex_yacc/DynareBison.yy"
                         { driver.declare_nonstationary_var((yystack_[2].value.string_val), (yystack_[1].value.string_val), (yystack_[0].value.vector_string_pair_val)); }
#line 860 "pkg/src/DynareBison.cc"
    break;

  case 140: // named_var_elem: symbol EQUAL QUOTED_STRING
#line 385 "pkg/src/lex_yacc/DynareBison.yy"
               {
                  pair<string *, string *> *pr = new pair<string *, string *>((yystack_[2].value.string_val), (yystack_[0].value.string_val));
                  (yylhs.value.string_pair_val) = pr;
               }
#line 869 "pkg/src/DynareBison.cc"
    break;

  case 141: // named_var_1: '(' named_var_elem
#line 391 "pkg/src/lex_yacc/DynareBison.yy"
              {
                (yylhs.value.vector_string_pair_val) = new vector<pair<string *, string *> *>();
                (yylhs.value.vector_string_pair_val)->push_back((yystack_[0].value.string_pair_val));
              }
#line 878 "pkg/src/DynareBison.cc"
    break;

  case 142: // named_var_1: '(' COMMA named_var_elem
#line 396 "pkg/src/lex_yacc/DynareBison.yy"
              {
                (yylhs.value.vector_string_pair_val) = new vector<pair<string *, string *> *>();
                (yylhs.value.vector_string_pair_val)->push_back((yystack_[0].value.string_pair_val));
              }
#line 887 "pkg/src/DynareBison.cc"
    break;

  case 143: // named_var_1: named_var_1 named_var_elem
#line 401 "pkg/src/lex_yacc/DynareBison.yy"
              {
                (yystack_[1].value.vector_string_pair_val)->push_back((yystack_[0].value.string_pair_val));
                (yylhs.value.vector_string_pair_val) = (yystack_[1].value.vector_string_pair_val);
              }
#line 896 "pkg/src/DynareBison.cc"
    break;

  case 144: // named_var_1: named_var_1 COMMA named_var_elem
#line 406 "pkg/src/lex_yacc/DynareBison.yy"
              {
                (yystack_[2].value.vector_string_pair_val)->push_back((yystack_[0].value.string_pair_val));
                (yylhs.value.vector_string_pair_val) = (yystack_[2].value.vector_string_pair_val);
              }
#line 905 "pkg/src/DynareBison.cc"
    break;

  case 145: // named_var: named_var_1 ')'
#line 412 "pkg/src/lex_yacc/DynareBison.yy"
                            { (yylhs.value.vector_string_pair_val) = (yystack_[1].value.vector_string_pair_val); }
#line 911 "pkg/src/DynareBison.cc"
    break;

  case 146: // named_var: named_var_1 COMMA ')'
#line 413 "pkg/src/lex_yacc/DynareBison.yy"
                                  { (yylhs.value.vector_string_pair_val) = (yystack_[2].value.vector_string_pair_val); }
#line 917 "pkg/src/DynareBison.cc"
    break;

  case 147: // var_list: var_list symbol
#line 417 "pkg/src/lex_yacc/DynareBison.yy"
           { driver.declare_endogenous((yystack_[0].value.string_val)); }
#line 923 "pkg/src/DynareBison.cc"
    break;

  case 148: // var_list: var_list COMMA symbol
#line 419 "pkg/src/lex_yacc/DynareBison.yy"
           { driver.declare_endogenous((yystack_[0].value.string_val)); }
#line 929 "pkg/src/DynareBison.cc"
    break;

  case 149: // var_list: symbol
#line 421 "pkg/src/lex_yacc/DynareBison.yy"
           { driver.declare_endogenous((yystack_[0].value.string_val)); }
#line 935 "pkg/src/DynareBison.cc"
    break;

  case 150: // var_list: var_list symbol named_var
#line 423 "pkg/src/lex_yacc/DynareBison.yy"
           { driver.declare_endogenous((yystack_[1].value.string_val), NULL, (yystack_[0].value.vector_string_pair_val)); }
#line 941 "pkg/src/DynareBison.cc"
    break;

  case 151: // var_list: var_list COMMA symbol named_var
#line 425 "pkg/src/lex_yacc/DynareBison.yy"
           { driver.declare_endogenous((yystack_[1].value.string_val), NULL, (yystack_[0].value.vector_string_pair_val)); }
#line 947 "pkg/src/DynareBison.cc"
    break;

  case 152: // var_list: symbol named_var
#line 427 "pkg/src/lex_yacc/DynareBison.yy"
           { driver.declare_endogenous((yystack_[1].value.string_val), NULL, (yystack_[0].value.vector_string_pair_val)); }
#line 953 "pkg/src/DynareBison.cc"
    break;

  case 153: // var_list: var_list symbol TEX_NAME
#line 429 "pkg/src/lex_yacc/DynareBison.yy"
           { driver.declare_endogenous((yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 959 "pkg/src/DynareBison.cc"
    break;

  case 154: // var_list: var_list COMMA symbol TEX_NAME
#line 431 "pkg/src/lex_yacc/DynareBison.yy"
           { driver.declare_endogenous((yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 965 "pkg/src/DynareBison.cc"
    break;

  case 155: // var_list: symbol TEX_NAME
#line 433 "pkg/src/lex_yacc/DynareBison.yy"
           { driver.declare_endogenous((yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 971 "pkg/src/DynareBison.cc"
    break;

  case 156: // var_list: var_list symbol TEX_NAME named_var
#line 435 "pkg/src/lex_yacc/DynareBison.yy"
           { driver.declare_endogenous((yystack_[2].value.string_val), (yystack_[1].value.string_val), (yystack_[0].value.vector_string_pair_val)); }
#line 977 "pkg/src/DynareBison.cc"
    break;

  case 157: // var_list: var_list COMMA symbol TEX_NAME named_var
#line 437 "pkg/src/lex_yacc/DynareBison.yy"
           { driver.declare_endogenous((yystack_[2].value.string_val), (yystack_[1].value.string_val), (yystack_[0].value.vector_string_pair_val)); }
#line 983 "pkg/src/DynareBison.cc"
    break;

  case 158: // var_list: symbol TEX_NAME named_var
#line 439 "pkg/src/lex_yacc/DynareBison.yy"
           { driver.declare_endogenous((yystack_[2].value.string_val), (yystack_[1].value.string_val), (yystack_[0].value.vector_string_pair_val)); }
#line 989 "pkg/src/DynareBison.cc"
    break;

  case 159: // varexo_list: varexo_list symbol
#line 443 "pkg/src/lex_yacc/DynareBison.yy"
              { driver.declare_exogenous((yystack_[0].value.string_val)); }
#line 995 "pkg/src/DynareBison.cc"
    break;

  case 160: // varexo_list: varexo_list COMMA symbol
#line 445 "pkg/src/lex_yacc/DynareBison.yy"
              { driver.declare_exogenous((yystack_[0].value.string_val)); }
#line 1001 "pkg/src/DynareBison.cc"
    break;

  case 161: // varexo_list: symbol
#line 447 "pkg/src/lex_yacc/DynareBison.yy"
              { driver.declare_exogenous((yystack_[0].value.string_val)); }
#line 1007 "pkg/src/DynareBison.cc"
    break;

  case 162: // varexo_list: varexo_list symbol named_var
#line 449 "pkg/src/lex_yacc/DynareBison.yy"
              { driver.declare_exogenous((yystack_[1].value.string_val), NULL, (yystack_[0].value.vector_string_pair_val)); }
#line 1013 "pkg/src/DynareBison.cc"
    break;

  case 163: // varexo_list: varexo_list COMMA symbol named_var
#line 451 "pkg/src/lex_yacc/DynareBison.yy"
              { driver.declare_exogenous((yystack_[1].value.string_val), NULL, (yystack_[0].value.vector_string_pair_val)); }
#line 1019 "pkg/src/DynareBison.cc"
    break;

  case 164: // varexo_list: symbol named_var
#line 453 "pkg/src/lex_yacc/DynareBison.yy"
              { driver.declare_exogenous((yystack_[1].value.string_val), NULL, (yystack_[0].value.vector_string_pair_val)); }
#line 1025 "pkg/src/DynareBison.cc"
    break;

  case 165: // varexo_list: varexo_list symbol TEX_NAME
#line 455 "pkg/src/lex_yacc/DynareBison.yy"
              { driver.declare_exogenous((yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 1031 "pkg/src/DynareBison.cc"
    break;

  case 166: // varexo_list: varexo_list COMMA symbol TEX_NAME
#line 457 "pkg/src/lex_yacc/DynareBison.yy"
              { driver.declare_exogenous((yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 1037 "pkg/src/DynareBison.cc"
    break;

  case 167: // varexo_list: symbol TEX_NAME
#line 459 "pkg/src/lex_yacc/DynareBison.yy"
              { driver.declare_exogenous((yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 1043 "pkg/src/DynareBison.cc"
    break;

  case 168: // varexo_list: varexo_list symbol TEX_NAME named_var
#line 461 "pkg/src/lex_yacc/DynareBison.yy"
              { driver.declare_exogenous((yystack_[2].value.string_val), (yystack_[1].value.string_val), (yystack_[0].value.vector_string_pair_val)); }
#line 1049 "pkg/src/DynareBison.cc"
    break;

  case 169: // varexo_list: varexo_list COMMA symbol TEX_NAME named_var
#line 463 "pkg/src/lex_yacc/DynareBison.yy"
              { driver.declare_exogenous((yystack_[2].value.string_val), (yystack_[1].value.string_val), (yystack_[0].value.vector_string_pair_val)); }
#line 1055 "pkg/src/DynareBison.cc"
    break;

  case 170: // varexo_list: symbol TEX_NAME named_var
#line 465 "pkg/src/lex_yacc/DynareBison.yy"
              { driver.declare_exogenous((yystack_[2].value.string_val), (yystack_[1].value.string_val), (yystack_[0].value.vector_string_pair_val)); }
#line 1061 "pkg/src/DynareBison.cc"
    break;

  case 171: // varexo_det_list: varexo_det_list symbol
#line 469 "pkg/src/lex_yacc/DynareBison.yy"
                  { driver.declare_exogenous_det((yystack_[0].value.string_val)); }
#line 1067 "pkg/src/DynareBison.cc"
    break;

  case 172: // varexo_det_list: varexo_det_list COMMA symbol
#line 471 "pkg/src/lex_yacc/DynareBison.yy"
                  { driver.declare_exogenous_det((yystack_[0].value.string_val)); }
#line 1073 "pkg/src/DynareBison.cc"
    break;

  case 173: // varexo_det_list: symbol
#line 473 "pkg/src/lex_yacc/DynareBison.yy"
                  { driver.declare_exogenous_det((yystack_[0].value.string_val)); }
#line 1079 "pkg/src/DynareBison.cc"
    break;

  case 174: // varexo_det_list: varexo_det_list symbol named_var
#line 475 "pkg/src/lex_yacc/DynareBison.yy"
                  { driver.declare_exogenous_det((yystack_[1].value.string_val), NULL, (yystack_[0].value.vector_string_pair_val)); }
#line 1085 "pkg/src/DynareBison.cc"
    break;

  case 175: // varexo_det_list: varexo_det_list COMMA symbol named_var
#line 477 "pkg/src/lex_yacc/DynareBison.yy"
                  { driver.declare_exogenous_det((yystack_[1].value.string_val), NULL, (yystack_[0].value.vector_string_pair_val)); }
#line 1091 "pkg/src/DynareBison.cc"
    break;

  case 176: // varexo_det_list: symbol named_var
#line 479 "pkg/src/lex_yacc/DynareBison.yy"
                  { driver.declare_exogenous_det((yystack_[1].value.string_val), NULL, (yystack_[0].value.vector_string_pair_val)); }
#line 1097 "pkg/src/DynareBison.cc"
    break;

  case 177: // varexo_det_list: varexo_det_list symbol TEX_NAME
#line 481 "pkg/src/lex_yacc/DynareBison.yy"
                  { driver.declare_exogenous_det((yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 1103 "pkg/src/DynareBison.cc"
    break;

  case 178: // varexo_det_list: varexo_det_list COMMA symbol TEX_NAME
#line 483 "pkg/src/lex_yacc/DynareBison.yy"
                  { driver.declare_exogenous_det((yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 1109 "pkg/src/DynareBison.cc"
    break;

  case 179: // varexo_det_list: symbol TEX_NAME
#line 485 "pkg/src/lex_yacc/DynareBison.yy"
                   { driver.declare_exogenous_det((yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 1115 "pkg/src/DynareBison.cc"
    break;

  case 180: // varexo_det_list: varexo_det_list symbol TEX_NAME named_var
#line 487 "pkg/src/lex_yacc/DynareBison.yy"
                  { driver.declare_exogenous_det((yystack_[2].value.string_val), (yystack_[1].value.string_val), (yystack_[0].value.vector_string_pair_val)); }
#line 1121 "pkg/src/DynareBison.cc"
    break;

  case 181: // varexo_det_list: varexo_det_list COMMA symbol TEX_NAME named_var
#line 489 "pkg/src/lex_yacc/DynareBison.yy"
                  { driver.declare_exogenous_det((yystack_[2].value.string_val), (yystack_[1].value.string_val), (yystack_[0].value.vector_string_pair_val)); }
#line 1127 "pkg/src/DynareBison.cc"
    break;

  case 182: // varexo_det_list: symbol TEX_NAME named_var
#line 491 "pkg/src/lex_yacc/DynareBison.yy"
                   { driver.declare_exogenous_det((yystack_[2].value.string_val), (yystack_[1].value.string_val), (yystack_[0].value.vector_string_pair_val)); }
#line 1133 "pkg/src/DynareBison.cc"
    break;

  case 183: // parameter_list: parameter_list symbol
#line 495 "pkg/src/lex_yacc/DynareBison.yy"
                 { driver.declare_parameter((yystack_[0].value.string_val)); }
#line 1139 "pkg/src/DynareBison.cc"
    break;

  case 184: // parameter_list: parameter_list COMMA symbol
#line 497 "pkg/src/lex_yacc/DynareBison.yy"
                 { driver.declare_parameter((yystack_[0].value.string_val)); }
#line 1145 "pkg/src/DynareBison.cc"
    break;

  case 185: // parameter_list: symbol
#line 499 "pkg/src/lex_yacc/DynareBison.yy"
                 { driver.declare_parameter((yystack_[0].value.string_val)); }
#line 1151 "pkg/src/DynareBison.cc"
    break;

  case 186: // parameter_list: parameter_list symbol named_var
#line 501 "pkg/src/lex_yacc/DynareBison.yy"
                 { driver.declare_parameter((yystack_[1].value.string_val), NULL, (yystack_[0].value.vector_string_pair_val)); }
#line 1157 "pkg/src/DynareBison.cc"
    break;

  case 187: // parameter_list: parameter_list COMMA symbol named_var
#line 503 "pkg/src/lex_yacc/DynareBison.yy"
                 { driver.declare_parameter((yystack_[1].value.string_val), NULL, (yystack_[0].value.vector_string_pair_val)); }
#line 1163 "pkg/src/DynareBison.cc"
    break;

  case 188: // parameter_list: symbol named_var
#line 505 "pkg/src/lex_yacc/DynareBison.yy"
                 { driver.declare_parameter((yystack_[1].value.string_val), NULL, (yystack_[0].value.vector_string_pair_val)); }
#line 1169 "pkg/src/DynareBison.cc"
    break;

  case 189: // parameter_list: parameter_list symbol TEX_NAME
#line 507 "pkg/src/lex_yacc/DynareBison.yy"
                 { driver.declare_parameter((yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 1175 "pkg/src/DynareBison.cc"
    break;

  case 190: // parameter_list: parameter_list COMMA symbol TEX_NAME
#line 509 "pkg/src/lex_yacc/DynareBison.yy"
                 { driver.declare_parameter((yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 1181 "pkg/src/DynareBison.cc"
    break;

  case 191: // parameter_list: symbol TEX_NAME
#line 511 "pkg/src/lex_yacc/DynareBison.yy"
                 { driver.declare_parameter((yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 1187 "pkg/src/DynareBison.cc"
    break;

  case 192: // parameter_list: parameter_list symbol TEX_NAME named_var
#line 513 "pkg/src/lex_yacc/DynareBison.yy"
                 { driver.declare_parameter((yystack_[2].value.string_val), (yystack_[1].value.string_val), (yystack_[0].value.vector_string_pair_val)); }
#line 1193 "pkg/src/DynareBison.cc"
    break;

  case 193: // parameter_list: parameter_list COMMA symbol TEX_NAME named_var
#line 515 "pkg/src/lex_yacc/DynareBison.yy"
                 { driver.declare_parameter((yystack_[2].value.string_val), (yystack_[1].value.string_val), (yystack_[0].value.vector_string_pair_val)); }
#line 1199 "pkg/src/DynareBison.cc"
    break;

  case 194: // parameter_list: symbol TEX_NAME named_var
#line 517 "pkg/src/lex_yacc/DynareBison.yy"
                 { driver.declare_parameter((yystack_[2].value.string_val), (yystack_[1].value.string_val), (yystack_[0].value.vector_string_pair_val)); }
#line 1205 "pkg/src/DynareBison.cc"
    break;

  case 195: // predetermined_variables_list: predetermined_variables_list symbol
#line 521 "pkg/src/lex_yacc/DynareBison.yy"
                               { driver.add_predetermined_variable((yystack_[0].value.string_val)); }
#line 1211 "pkg/src/DynareBison.cc"
    break;

  case 196: // predetermined_variables_list: predetermined_variables_list COMMA symbol
#line 523 "pkg/src/lex_yacc/DynareBison.yy"
                               { driver.add_predetermined_variable((yystack_[0].value.string_val)); }
#line 1217 "pkg/src/DynareBison.cc"
    break;

  case 197: // predetermined_variables_list: symbol
#line 525 "pkg/src/lex_yacc/DynareBison.yy"
                               { driver.add_predetermined_variable((yystack_[0].value.string_val)); }
#line 1223 "pkg/src/DynareBison.cc"
    break;

  case 198: // change_type: CHANGE_TYPE '(' change_type_arg ')' change_type_var_list ';'
#line 529 "pkg/src/lex_yacc/DynareBison.yy"
              { driver.change_type((yystack_[3].value.symbol_type_val), (yystack_[1].value.vector_string_val)); }
#line 1229 "pkg/src/DynareBison.cc"
    break;

  case 199: // change_type_arg: PARAMETERS
#line 533 "pkg/src/lex_yacc/DynareBison.yy"
                  { (yylhs.value.symbol_type_val) = eParameter; }
#line 1235 "pkg/src/DynareBison.cc"
    break;

  case 200: // change_type_arg: VAR
#line 535 "pkg/src/lex_yacc/DynareBison.yy"
                  { (yylhs.value.symbol_type_val) = eEndogenous; }
#line 1241 "pkg/src/DynareBison.cc"
    break;

  case 201: // change_type_arg: VAREXO
#line 537 "pkg/src/lex_yacc/DynareBison.yy"
                  { (yylhs.value.symbol_type_val) = eExogenous; }
#line 1247 "pkg/src/DynareBison.cc"
    break;

  case 202: // change_type_arg: VAREXO_DET
#line 539 "pkg/src/lex_yacc/DynareBison.yy"
                  { (yylhs.value.symbol_type_val) = eExogenousDet; }
#line 1253 "pkg/src/DynareBison.cc"
    break;

  case 203: // change_type_var_list: symbol
#line 543 "pkg/src/lex_yacc/DynareBison.yy"
                       { (yylhs.value.vector_string_val) = new vector<string *>(); (yylhs.value.vector_string_val)->push_back((yystack_[0].value.string_val)); }
#line 1259 "pkg/src/DynareBison.cc"
    break;

  case 204: // change_type_var_list: change_type_var_list symbol
#line 545 "pkg/src/lex_yacc/DynareBison.yy"
                       { (yylhs.value.vector_string_val) = (yystack_[1].value.vector_string_val); (yystack_[1].value.vector_string_val)->push_back((yystack_[0].value.string_val)); }
#line 1265 "pkg/src/DynareBison.cc"
    break;

  case 205: // change_type_var_list: change_type_var_list COMMA symbol
#line 547 "pkg/src/lex_yacc/DynareBison.yy"
                       { (yylhs.value.vector_string_val) = (yystack_[2].value.vector_string_val); (yystack_[2].value.vector_string_val)->push_back((yystack_[0].value.string_val)); }
#line 1271 "pkg/src/DynareBison.cc"
    break;

  case 206: // periods: PERIODS INT_NUMBER ';'
#line 551 "pkg/src/lex_yacc/DynareBison.yy"
          { driver.periods((yystack_[1].value.string_val)); }
#line 1277 "pkg/src/DynareBison.cc"
    break;

  case 207: // periods: PERIODS EQUAL INT_NUMBER ';'
#line 553 "pkg/src/lex_yacc/DynareBison.yy"
          { driver.periods((yystack_[1].value.string_val)); }
#line 1283 "pkg/src/DynareBison.cc"
    break;

  case 208: // init_param: symbol EQUAL expression ';'
#line 556 "pkg/src/lex_yacc/DynareBison.yy"
                                         { driver.init_param((yystack_[3].value.string_val), (yystack_[1].value.node_val)); }
#line 1289 "pkg/src/DynareBison.cc"
    break;

  case 209: // expression: '(' expression ')'
#line 559 "pkg/src/lex_yacc/DynareBison.yy"
             { (yylhs.value.node_val) = (yystack_[1].value.node_val);}
#line 1295 "pkg/src/DynareBison.cc"
    break;

  case 210: // expression: symbol
#line 561 "pkg/src/lex_yacc/DynareBison.yy"
             { (yylhs.value.node_val) = driver.add_expression_variable((yystack_[0].value.string_val)); }
#line 1301 "pkg/src/DynareBison.cc"
    break;

  case 211: // expression: non_negative_number
#line 563 "pkg/src/lex_yacc/DynareBison.yy"
             { (yylhs.value.node_val) = driver.add_non_negative_constant((yystack_[0].value.string_val)); }
#line 1307 "pkg/src/DynareBison.cc"
    break;

  case 212: // expression: expression PLUS expression
#line 565 "pkg/src/lex_yacc/DynareBison.yy"
             { (yylhs.value.node_val) = driver.add_plus((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1313 "pkg/src/DynareBison.cc"
    break;

  case 213: // expression: expression MINUS expression
#line 567 "pkg/src/lex_yacc/DynareBison.yy"
             { (yylhs.value.node_val) = driver.add_minus((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1319 "pkg/src/DynareBison.cc"
    break;

  case 214: // expression: expression DIVIDE expression
#line 569 "pkg/src/lex_yacc/DynareBison.yy"
             { (yylhs.value.node_val) = driver.add_divide((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1325 "pkg/src/DynareBison.cc"
    break;

  case 215: // expression: expression TIMES expression
#line 571 "pkg/src/lex_yacc/DynareBison.yy"
             { (yylhs.value.node_val) = driver.add_times((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1331 "pkg/src/DynareBison.cc"
    break;

  case 216: // expression: expression POWER expression
#line 573 "pkg/src/lex_yacc/DynareBison.yy"
             { (yylhs.value.node_val) = driver.add_power((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1337 "pkg/src/DynareBison.cc"
    break;

  case 217: // expression: expression LESS expression
#line 575 "pkg/src/lex_yacc/DynareBison.yy"
             { (yylhs.value.node_val) = driver.add_less((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1343 "pkg/src/DynareBison.cc"
    break;

  case 218: // expression: expression GREATER expression
#line 577 "pkg/src/lex_yacc/DynareBison.yy"
             { (yylhs.value.node_val) = driver.add_greater((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1349 "pkg/src/DynareBison.cc"
    break;

  case 219: // expression: expression LESS_EQUAL expression
#line 579 "pkg/src/lex_yacc/DynareBison.yy"
             { (yylhs.value.node_val) = driver.add_less_equal((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1355 "pkg/src/DynareBison.cc"
    break;

  case 220: // expression: expression GREATER_EQUAL expression
#line 581 "pkg/src/lex_yacc/DynareBison.yy"
             { (yylhs.value.node_val) = driver.add_greater_equal((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1361 "pkg/src/DynareBison.cc"
    break;

  case 221: // expression: expression EQUAL_EQUAL expression
#line 583 "pkg/src/lex_yacc/DynareBison.yy"
             { (yylhs.value.node_val) = driver.add_equal_equal((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1367 "pkg/src/DynareBison.cc"
    break;

  case 222: // expression: expression EXCLAMATION_EQUAL expression
#line 585 "pkg/src/lex_yacc/DynareBison.yy"
             { (yylhs.value.node_val) = driver.add_different((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1373 "pkg/src/DynareBison.cc"
    break;

  case 223: // expression: MINUS expression
#line 587 "pkg/src/lex_yacc/DynareBison.yy"
             { (yylhs.value.node_val) = driver.add_uminus((yystack_[0].value.node_val)); }
#line 1379 "pkg/src/DynareBison.cc"
    break;

  case 224: // expression: PLUS expression
#line 589 "pkg/src/lex_yacc/DynareBison.yy"
             { (yylhs.value.node_val) = (yystack_[0].value.node_val); }
#line 1385 "pkg/src/DynareBison.cc"
    break;

  case 225: // expression: EXP '(' expression ')'
#line 591 "pkg/src/lex_yacc/DynareBison.yy"
             { (yylhs.value.node_val) = driver.add_exp((yystack_[1].value.node_val)); }
#line 1391 "pkg/src/DynareBison.cc"
    break;

  case 226: // expression: LOG '(' expression ')'
#line 593 "pkg/src/lex_yacc/DynareBison.yy"
             { (yylhs.value.node_val) = driver.add_log((yystack_[1].value.node_val)); }
#line 1397 "pkg/src/DynareBison.cc"
    break;

  case 227: // expression: LN '(' expression ')'
#line 595 "pkg/src/lex_yacc/DynareBison.yy"
             { (yylhs.value.node_val) = driver.add_log((yystack_[1].value.node_val)); }
#line 1403 "pkg/src/DynareBison.cc"
    break;

  case 228: // expression: LOG10 '(' expression ')'
#line 597 "pkg/src/lex_yacc/DynareBison.yy"
             { (yylhs.value.node_val) = driver.add_log10((yystack_[1].value.node_val)); }
#line 1409 "pkg/src/DynareBison.cc"
    break;

  case 229: // expression: SIN '(' expression ')'
#line 599 "pkg/src/lex_yacc/DynareBison.yy"
             { (yylhs.value.node_val) = driver.add_sin((yystack_[1].value.node_val)); }
#line 1415 "pkg/src/DynareBison.cc"
    break;

  case 230: // expression: COS '(' expression ')'
#line 601 "pkg/src/lex_yacc/DynareBison.yy"
             { (yylhs.value.node_val) = driver.add_cos((yystack_[1].value.node_val)); }
#line 1421 "pkg/src/DynareBison.cc"
    break;

  case 231: // expression: TAN '(' expression ')'
#line 603 "pkg/src/lex_yacc/DynareBison.yy"
             { (yylhs.value.node_val) = driver.add_tan((yystack_[1].value.node_val)); }
#line 1427 "pkg/src/DynareBison.cc"
    break;

  case 232: // expression: ASIN '(' expression ')'
#line 605 "pkg/src/lex_yacc/DynareBison.yy"
             { (yylhs.value.node_val) = driver.add_asin((yystack_[1].value.node_val)); }
#line 1433 "pkg/src/DynareBison.cc"
    break;

  case 233: // expression: ACOS '(' expression ')'
#line 607 "pkg/src/lex_yacc/DynareBison.yy"
             { (yylhs.value.node_val) = driver.add_acos((yystack_[1].value.node_val)); }
#line 1439 "pkg/src/DynareBison.cc"
    break;

  case 234: // expression: ATAN '(' expression ')'
#line 609 "pkg/src/lex_yacc/DynareBison.yy"
             { (yylhs.value.node_val) = driver.add_atan((yystack_[1].value.node_val)); }
#line 1445 "pkg/src/DynareBison.cc"
    break;

  case 235: // expression: SQRT '(' expression ')'
#line 611 "pkg/src/lex_yacc/DynareBison.yy"
             { (yylhs.value.node_val) = driver.add_sqrt((yystack_[1].value.node_val)); }
#line 1451 "pkg/src/DynareBison.cc"
    break;

  case 236: // expression: ABS '(' expression ')'
#line 613 "pkg/src/lex_yacc/DynareBison.yy"
             { (yylhs.value.node_val) = driver.add_abs((yystack_[1].value.node_val)); }
#line 1457 "pkg/src/DynareBison.cc"
    break;

  case 237: // expression: SIGN '(' expression ')'
#line 615 "pkg/src/lex_yacc/DynareBison.yy"
             { (yylhs.value.node_val) = driver.add_sign((yystack_[1].value.node_val)); }
#line 1463 "pkg/src/DynareBison.cc"
    break;

  case 238: // expression: MAX '(' expression COMMA expression ')'
#line 617 "pkg/src/lex_yacc/DynareBison.yy"
             { (yylhs.value.node_val) = driver.add_max((yystack_[3].value.node_val), (yystack_[1].value.node_val)); }
#line 1469 "pkg/src/DynareBison.cc"
    break;

  case 239: // expression: MIN '(' expression COMMA expression ')'
#line 619 "pkg/src/lex_yacc/DynareBison.yy"
             { (yylhs.value.node_val) = driver.add_min((yystack_[3].value.node_val), (yystack_[1].value.node_val)); }
#line 1475 "pkg/src/DynareBison.cc"
    break;

  case 240: // expression: LINLOG '(' expression ')'
#line 621 "pkg/src/lex_yacc/DynareBison.yy"
             { (yylhs.value.node_val) = driver.add_linlog((yystack_[1].value.node_val)); }
#line 1481 "pkg/src/DynareBison.cc"
    break;

  case 241: // expression: LINLOG '(' expression COMMA expression ')'
#line 623 "pkg/src/lex_yacc/DynareBison.yy"
             { (yylhs.value.node_val) = driver.add_linlog((yystack_[3].value.node_val), (yystack_[1].value.node_val)); }
#line 1487 "pkg/src/DynareBison.cc"
    break;

  case 242: // expression: LINPOW '(' expression COMMA expression ')'
#line 625 "pkg/src/lex_yacc/DynareBison.yy"
             { (yylhs.value.node_val) = driver.add_linpow((yystack_[3].value.node_val), (yystack_[1].value.node_val)); }
#line 1493 "pkg/src/DynareBison.cc"
    break;

  case 243: // expression: LINPOW '(' expression COMMA expression COMMA expression ')'
#line 627 "pkg/src/lex_yacc/DynareBison.yy"
             { (yylhs.value.node_val) = driver.add_linpow((yystack_[5].value.node_val), (yystack_[3].value.node_val), (yystack_[1].value.node_val)); }
#line 1499 "pkg/src/DynareBison.cc"
    break;

  case 244: // $@5: %empty
#line 628 "pkg/src/lex_yacc/DynareBison.yy"
                    { driver.push_external_function_arg_vector_onto_stack(); }
#line 1505 "pkg/src/DynareBison.cc"
    break;

  case 245: // expression: symbol $@5 '(' comma_expression ')'
#line 629 "pkg/src/lex_yacc/DynareBison.yy"
             { (yylhs.value.node_val) = driver.add_model_var_or_external_function((yystack_[4].value.string_val), false); }
#line 1511 "pkg/src/DynareBison.cc"
    break;

  case 246: // expression: NORMCDF '(' expression COMMA expression COMMA expression ')'
#line 631 "pkg/src/lex_yacc/DynareBison.yy"
             { (yylhs.value.node_val) = driver.add_normcdf((yystack_[5].value.node_val), (yystack_[3].value.node_val), (yystack_[1].value.node_val)); }
#line 1517 "pkg/src/DynareBison.cc"
    break;

  case 247: // expression: NORMCDF '(' expression ')'
#line 633 "pkg/src/lex_yacc/DynareBison.yy"
             { (yylhs.value.node_val) = driver.add_normcdf((yystack_[1].value.node_val)); }
#line 1523 "pkg/src/DynareBison.cc"
    break;

  case 248: // expression: NORMPDF '(' expression COMMA expression COMMA expression ')'
#line 635 "pkg/src/lex_yacc/DynareBison.yy"
             { (yylhs.value.node_val) = driver.add_normpdf((yystack_[5].value.node_val), (yystack_[3].value.node_val), (yystack_[1].value.node_val)); }
#line 1529 "pkg/src/DynareBison.cc"
    break;

  case 249: // expression: NORMPDF '(' expression ')'
#line 637 "pkg/src/lex_yacc/DynareBison.yy"
             { (yylhs.value.node_val) = driver.add_normpdf((yystack_[1].value.node_val)); }
#line 1535 "pkg/src/DynareBison.cc"
    break;

  case 250: // expression: ERF '(' expression ')'
#line 639 "pkg/src/lex_yacc/DynareBison.yy"
             { (yylhs.value.node_val) = driver.add_erf((yystack_[1].value.node_val)); }
#line 1541 "pkg/src/DynareBison.cc"
    break;

  case 251: // expression: NAN_CONSTANT
#line 641 "pkg/src/lex_yacc/DynareBison.yy"
             { (yylhs.value.node_val) = driver.add_nan_constant(); }
#line 1547 "pkg/src/DynareBison.cc"
    break;

  case 252: // expression: INF_CONSTANT
#line 643 "pkg/src/lex_yacc/DynareBison.yy"
             { (yylhs.value.node_val) = driver.add_inf_constant(); }
#line 1553 "pkg/src/DynareBison.cc"
    break;

  case 253: // comma_expression: expression
#line 647 "pkg/src/lex_yacc/DynareBison.yy"
                   { driver.add_external_function_arg((yystack_[0].value.node_val)); }
#line 1559 "pkg/src/DynareBison.cc"
    break;

  case 254: // comma_expression: comma_expression COMMA expression
#line 649 "pkg/src/lex_yacc/DynareBison.yy"
                   { driver.add_external_function_arg((yystack_[0].value.node_val)); }
#line 1565 "pkg/src/DynareBison.cc"
    break;

  case 255: // expression_or_empty: %empty
#line 652 "pkg/src/lex_yacc/DynareBison.yy"
                      {(yylhs.value.node_val) = driver.add_nan_constant();}
#line 1571 "pkg/src/DynareBison.cc"
    break;

  case 256: // expression_or_empty: expression
#line 653 "pkg/src/lex_yacc/DynareBison.yy"
                      { (yylhs.value.node_val) = (yystack_[0].value.node_val); }
#line 1577 "pkg/src/DynareBison.cc"
    break;

  case 257: // initval: INITVAL ';' initval_list END ';'
#line 657 "pkg/src/lex_yacc/DynareBison.yy"
          { driver.end_initval(false); }
#line 1583 "pkg/src/DynareBison.cc"
    break;

  case 258: // initval: INITVAL '(' ALL_VALUES_REQUIRED ')' ';' initval_list END ';'
#line 659 "pkg/src/lex_yacc/DynareBison.yy"
          { driver.end_initval(true); }
#line 1589 "pkg/src/DynareBison.cc"
    break;

  case 259: // initval_file: INITVAL_FILE '(' FILENAME EQUAL filename ')' ';'
#line 663 "pkg/src/lex_yacc/DynareBison.yy"
               { driver.initval_file((yystack_[2].value.string_val)); }
#line 1595 "pkg/src/DynareBison.cc"
    break;

  case 260: // endval: ENDVAL ';' initval_list END ';'
#line 667 "pkg/src/lex_yacc/DynareBison.yy"
         { driver.end_endval(false); }
#line 1601 "pkg/src/DynareBison.cc"
    break;

  case 261: // endval: ENDVAL '(' ALL_VALUES_REQUIRED ')' ';' initval_list END ';'
#line 669 "pkg/src/lex_yacc/DynareBison.yy"
         { driver.end_endval(true); }
#line 1607 "pkg/src/DynareBison.cc"
    break;

  case 264: // initval_elem: symbol EQUAL expression ';'
#line 676 "pkg/src/lex_yacc/DynareBison.yy"
                                           { driver.init_val((yystack_[3].value.string_val), (yystack_[1].value.node_val)); }
#line 1613 "pkg/src/DynareBison.cc"
    break;

  case 265: // histval: HISTVAL ';' histval_list END ';'
#line 679 "pkg/src/lex_yacc/DynareBison.yy"
          { driver.end_histval(false); }
#line 1619 "pkg/src/DynareBison.cc"
    break;

  case 266: // histval: HISTVAL '(' ALL_VALUES_REQUIRED ')' ';' histval_list END ';'
#line 681 "pkg/src/lex_yacc/DynareBison.yy"
          { driver.end_histval(true); }
#line 1625 "pkg/src/DynareBison.cc"
    break;

  case 269: // histval_elem: symbol '(' signed_integer ')' EQUAL expression ';'
#line 688 "pkg/src/lex_yacc/DynareBison.yy"
                                                                  { driver.hist_val((yystack_[6].value.string_val), (yystack_[4].value.string_val), (yystack_[1].value.node_val)); }
#line 1631 "pkg/src/DynareBison.cc"
    break;

  case 270: // histval_file: HISTVAL_FILE '(' FILENAME EQUAL filename ')' ';'
#line 691 "pkg/src/lex_yacc/DynareBison.yy"
               { driver.histval_file((yystack_[2].value.string_val)); }
#line 1637 "pkg/src/DynareBison.cc"
    break;

  case 271: // model_options: BLOCK
#line 694 "pkg/src/lex_yacc/DynareBison.yy"
                      { driver.block(); }
#line 1643 "pkg/src/DynareBison.cc"
    break;

  case 274: // model_options: BYTECODE
#line 697 "pkg/src/lex_yacc/DynareBison.yy"
                         { driver.byte_code(); }
#line 1649 "pkg/src/DynareBison.cc"
    break;

  case 275: // model_options: USE_DLL
#line 698 "pkg/src/lex_yacc/DynareBison.yy"
                        { driver.use_dll(); }
#line 1655 "pkg/src/DynareBison.cc"
    break;

  case 276: // model_options: NO_STATIC
#line 699 "pkg/src/lex_yacc/DynareBison.yy"
                          { driver.no_static();}
#line 1661 "pkg/src/DynareBison.cc"
    break;

  case 277: // model_options: DIFFERENTIATE_FORWARD_VARS
#line 700 "pkg/src/lex_yacc/DynareBison.yy"
                                           { driver.differentiate_forward_vars_all(); }
#line 1667 "pkg/src/DynareBison.cc"
    break;

  case 278: // model_options: DIFFERENTIATE_FORWARD_VARS EQUAL '(' symbol_list ')'
#line 701 "pkg/src/lex_yacc/DynareBison.yy"
                                                                     { driver.differentiate_forward_vars_some(); }
#line 1673 "pkg/src/DynareBison.cc"
    break;

  case 283: // $@6: %empty
#line 710 "pkg/src/lex_yacc/DynareBison.yy"
                  { driver.begin_model(); }
#line 1679 "pkg/src/DynareBison.cc"
    break;

  case 284: // model: MODEL ';' $@6 equation_list END ';'
#line 711 "pkg/src/lex_yacc/DynareBison.yy"
                              { driver.end_model(); }
#line 1685 "pkg/src/DynareBison.cc"
    break;

  case 285: // $@7: %empty
#line 712 "pkg/src/lex_yacc/DynareBison.yy"
                                             { driver.begin_model(); }
#line 1691 "pkg/src/DynareBison.cc"
    break;

  case 286: // model: MODEL '(' model_options_list ')' ';' $@7 equation_list END ';'
#line 713 "pkg/src/lex_yacc/DynareBison.yy"
                              { driver.end_model(); }
#line 1697 "pkg/src/DynareBison.cc"
    break;

  case 291: // equation: hand_side EQUAL hand_side ';'
#line 723 "pkg/src/lex_yacc/DynareBison.yy"
           { (yylhs.value.node_val) = driver.add_model_equal((yystack_[3].value.node_val), (yystack_[1].value.node_val)); }
#line 1703 "pkg/src/DynareBison.cc"
    break;

  case 292: // equation: hand_side ';'
#line 725 "pkg/src/lex_yacc/DynareBison.yy"
           { (yylhs.value.node_val) = driver.add_model_equal_with_zero_rhs((yystack_[1].value.node_val)); }
#line 1709 "pkg/src/DynareBison.cc"
    break;

  case 293: // equation: '[' tags_list ']' hand_side EQUAL hand_side ';'
#line 727 "pkg/src/lex_yacc/DynareBison.yy"
           { (yylhs.value.node_val) = driver.add_model_equal((yystack_[3].value.node_val), (yystack_[1].value.node_val)); }
#line 1715 "pkg/src/DynareBison.cc"
    break;

  case 294: // equation: '[' tags_list ']' hand_side ';'
#line 729 "pkg/src/lex_yacc/DynareBison.yy"
           { (yylhs.value.node_val) = driver.add_model_equal_with_zero_rhs((yystack_[1].value.node_val)); }
#line 1721 "pkg/src/DynareBison.cc"
    break;

  case 297: // tag_pair: NAME EQUAL QUOTED_STRING
#line 737 "pkg/src/lex_yacc/DynareBison.yy"
           { driver.add_equation_tags((yystack_[2].value.string_val), (yystack_[0].value.string_val)); }
#line 1727 "pkg/src/DynareBison.cc"
    break;

  case 298: // tag_pair: NAME
#line 739 "pkg/src/lex_yacc/DynareBison.yy"
           { driver.add_equation_tags((yystack_[0].value.string_val), new string()); }
#line 1733 "pkg/src/DynareBison.cc"
    break;

  case 299: // hand_side: '(' hand_side ')'
#line 743 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.node_val) = (yystack_[1].value.node_val);}
#line 1739 "pkg/src/DynareBison.cc"
    break;

  case 300: // hand_side: symbol
#line 745 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.node_val) = driver.add_model_variable((yystack_[0].value.string_val)); }
#line 1745 "pkg/src/DynareBison.cc"
    break;

  case 301: // hand_side: non_negative_number
#line 747 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.node_val) = driver.add_non_negative_constant((yystack_[0].value.string_val)); }
#line 1751 "pkg/src/DynareBison.cc"
    break;

  case 302: // hand_side: hand_side PLUS hand_side
#line 749 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.node_val) = driver.add_plus((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1757 "pkg/src/DynareBison.cc"
    break;

  case 303: // hand_side: hand_side MINUS hand_side
#line 751 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.node_val) = driver.add_minus((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1763 "pkg/src/DynareBison.cc"
    break;

  case 304: // hand_side: hand_side DIVIDE hand_side
#line 753 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.node_val) = driver.add_divide((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1769 "pkg/src/DynareBison.cc"
    break;

  case 305: // hand_side: hand_side TIMES hand_side
#line 755 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.node_val) = driver.add_times((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1775 "pkg/src/DynareBison.cc"
    break;

  case 306: // hand_side: hand_side LESS hand_side
#line 757 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.node_val) = driver.add_less((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1781 "pkg/src/DynareBison.cc"
    break;

  case 307: // hand_side: hand_side GREATER hand_side
#line 759 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.node_val) = driver.add_greater((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1787 "pkg/src/DynareBison.cc"
    break;

  case 308: // hand_side: hand_side LESS_EQUAL hand_side
#line 761 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.node_val) = driver.add_less_equal((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1793 "pkg/src/DynareBison.cc"
    break;

  case 309: // hand_side: hand_side GREATER_EQUAL hand_side
#line 763 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.node_val) = driver.add_greater_equal((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1799 "pkg/src/DynareBison.cc"
    break;

  case 310: // hand_side: hand_side EQUAL_EQUAL hand_side
#line 765 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.node_val) = driver.add_equal_equal((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1805 "pkg/src/DynareBison.cc"
    break;

  case 311: // hand_side: hand_side EXCLAMATION_EQUAL hand_side
#line 767 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.node_val) = driver.add_different((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1811 "pkg/src/DynareBison.cc"
    break;

  case 312: // hand_side: hand_side POWER hand_side
#line 769 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.node_val) = driver.add_power((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1817 "pkg/src/DynareBison.cc"
    break;

  case 313: // hand_side: EXPECTATION '(' signed_integer ')' '(' hand_side ')'
#line 771 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.node_val) = driver.add_expectation((yystack_[4].value.string_val), (yystack_[1].value.node_val)); }
#line 1823 "pkg/src/DynareBison.cc"
    break;

  case 314: // hand_side: MINUS hand_side
#line 773 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.node_val) = driver.add_uminus((yystack_[0].value.node_val)); }
#line 1829 "pkg/src/DynareBison.cc"
    break;

  case 315: // hand_side: PLUS hand_side
#line 775 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.node_val) = (yystack_[0].value.node_val); }
#line 1835 "pkg/src/DynareBison.cc"
    break;

  case 316: // hand_side: EXP '(' hand_side ')'
#line 777 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.node_val) = driver.add_exp((yystack_[1].value.node_val)); }
#line 1841 "pkg/src/DynareBison.cc"
    break;

  case 317: // hand_side: LOG '(' hand_side ')'
#line 779 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.node_val) = driver.add_log((yystack_[1].value.node_val)); }
#line 1847 "pkg/src/DynareBison.cc"
    break;

  case 318: // hand_side: LN '(' hand_side ')'
#line 781 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.node_val) = driver.add_log((yystack_[1].value.node_val)); }
#line 1853 "pkg/src/DynareBison.cc"
    break;

  case 319: // hand_side: LOG10 '(' hand_side ')'
#line 783 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.node_val) = driver.add_log10((yystack_[1].value.node_val)); }
#line 1859 "pkg/src/DynareBison.cc"
    break;

  case 320: // hand_side: SIN '(' hand_side ')'
#line 785 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.node_val) = driver.add_sin((yystack_[1].value.node_val)); }
#line 1865 "pkg/src/DynareBison.cc"
    break;

  case 321: // hand_side: COS '(' hand_side ')'
#line 787 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.node_val) = driver.add_cos((yystack_[1].value.node_val)); }
#line 1871 "pkg/src/DynareBison.cc"
    break;

  case 322: // hand_side: TAN '(' hand_side ')'
#line 789 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.node_val) = driver.add_tan((yystack_[1].value.node_val)); }
#line 1877 "pkg/src/DynareBison.cc"
    break;

  case 323: // hand_side: ASIN '(' hand_side ')'
#line 791 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.node_val) = driver.add_asin((yystack_[1].value.node_val)); }
#line 1883 "pkg/src/DynareBison.cc"
    break;

  case 324: // hand_side: ACOS '(' hand_side ')'
#line 793 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.node_val) = driver.add_acos((yystack_[1].value.node_val)); }
#line 1889 "pkg/src/DynareBison.cc"
    break;

  case 325: // hand_side: ATAN '(' hand_side ')'
#line 795 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.node_val) = driver.add_atan((yystack_[1].value.node_val)); }
#line 1895 "pkg/src/DynareBison.cc"
    break;

  case 326: // hand_side: SQRT '(' hand_side ')'
#line 797 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.node_val) = driver.add_sqrt((yystack_[1].value.node_val)); }
#line 1901 "pkg/src/DynareBison.cc"
    break;

  case 327: // hand_side: ABS '(' hand_side ')'
#line 799 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.node_val) = driver.add_abs((yystack_[1].value.node_val)); }
#line 1907 "pkg/src/DynareBison.cc"
    break;

  case 328: // hand_side: SIGN '(' hand_side ')'
#line 801 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.node_val) = driver.add_sign((yystack_[1].value.node_val)); }
#line 1913 "pkg/src/DynareBison.cc"
    break;

  case 329: // hand_side: MAX '(' hand_side COMMA hand_side ')'
#line 803 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.node_val) = driver.add_max((yystack_[3].value.node_val), (yystack_[1].value.node_val)); }
#line 1919 "pkg/src/DynareBison.cc"
    break;

  case 330: // hand_side: MIN '(' hand_side COMMA hand_side ')'
#line 805 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.node_val) = driver.add_min((yystack_[3].value.node_val), (yystack_[1].value.node_val)); }
#line 1925 "pkg/src/DynareBison.cc"
    break;

  case 331: // hand_side: LINLOG '(' hand_side ')'
#line 807 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.node_val) = driver.add_linlog((yystack_[1].value.node_val)); }
#line 1931 "pkg/src/DynareBison.cc"
    break;

  case 332: // hand_side: LINLOG '(' hand_side COMMA hand_side ')'
#line 809 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.node_val) = driver.add_linlog((yystack_[3].value.node_val), (yystack_[1].value.node_val)); }
#line 1937 "pkg/src/DynareBison.cc"
    break;

  case 333: // hand_side: LINPOW '(' hand_side COMMA hand_side ')'
#line 811 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.node_val) = driver.add_linpow((yystack_[3].value.node_val), (yystack_[1].value.node_val)); }
#line 1943 "pkg/src/DynareBison.cc"
    break;

  case 334: // hand_side: LINPOW '(' hand_side COMMA hand_side COMMA hand_side ')'
#line 813 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.node_val) = driver.add_linpow((yystack_[5].value.node_val), (yystack_[3].value.node_val), (yystack_[1].value.node_val)); }
#line 1949 "pkg/src/DynareBison.cc"
    break;

  case 335: // $@8: %empty
#line 814 "pkg/src/lex_yacc/DynareBison.yy"
                   { driver.push_external_function_arg_vector_onto_stack(); }
#line 1955 "pkg/src/DynareBison.cc"
    break;

  case 336: // hand_side: symbol $@8 '(' comma_hand_side ')'
#line 815 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.node_val) = driver.add_model_var_or_external_function((yystack_[4].value.string_val), true); }
#line 1961 "pkg/src/DynareBison.cc"
    break;

  case 337: // hand_side: NORMCDF '(' hand_side COMMA hand_side COMMA hand_side ')'
#line 817 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.node_val) = driver.add_normcdf((yystack_[5].value.node_val), (yystack_[3].value.node_val), (yystack_[1].value.node_val)); }
#line 1967 "pkg/src/DynareBison.cc"
    break;

  case 338: // hand_side: NORMCDF '(' hand_side ')'
#line 819 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.node_val) = driver.add_normcdf((yystack_[1].value.node_val)); }
#line 1973 "pkg/src/DynareBison.cc"
    break;

  case 339: // hand_side: NORMPDF '(' hand_side COMMA hand_side COMMA hand_side ')'
#line 821 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.node_val) = driver.add_normpdf((yystack_[5].value.node_val), (yystack_[3].value.node_val), (yystack_[1].value.node_val)); }
#line 1979 "pkg/src/DynareBison.cc"
    break;

  case 340: // hand_side: NORMPDF '(' hand_side ')'
#line 823 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.node_val) = driver.add_normpdf((yystack_[1].value.node_val)); }
#line 1985 "pkg/src/DynareBison.cc"
    break;

  case 341: // hand_side: ERF '(' hand_side ')'
#line 825 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.node_val) = driver.add_erf((yystack_[1].value.node_val)); }
#line 1991 "pkg/src/DynareBison.cc"
    break;

  case 342: // hand_side: STEADY_STATE '(' hand_side ')'
#line 827 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.node_val) = driver.add_steady_state((yystack_[1].value.node_val)); }
#line 1997 "pkg/src/DynareBison.cc"
    break;

  case 343: // comma_hand_side: hand_side
#line 831 "pkg/src/lex_yacc/DynareBison.yy"
                  { driver.add_external_function_arg((yystack_[0].value.node_val)); }
#line 2003 "pkg/src/DynareBison.cc"
    break;

  case 344: // comma_hand_side: comma_hand_side COMMA hand_side
#line 833 "pkg/src/lex_yacc/DynareBison.yy"
                  { driver.add_external_function_arg((yystack_[0].value.node_val)); }
#line 2009 "pkg/src/DynareBison.cc"
    break;

  case 345: // pound_expression: '#' symbol EQUAL hand_side ';'
#line 837 "pkg/src/lex_yacc/DynareBison.yy"
                  { driver.declare_and_init_model_local_variable((yystack_[3].value.string_val), (yystack_[1].value.node_val)); }
#line 2015 "pkg/src/DynareBison.cc"
    break;

  case 346: // shocks: SHOCKS ';' shock_list END ';'
#line 839 "pkg/src/lex_yacc/DynareBison.yy"
                                       { driver.end_shocks(false); }
#line 2021 "pkg/src/DynareBison.cc"
    break;

  case 347: // shocks: SHOCKS '(' OVERWRITE ')' ';' shock_list END ';'
#line 840 "pkg/src/lex_yacc/DynareBison.yy"
                                                         { driver.end_shocks(true); }
#line 2027 "pkg/src/DynareBison.cc"
    break;

  case 351: // shock_elem: VAR symbol ';' STDERR expression ';'
#line 849 "pkg/src/lex_yacc/DynareBison.yy"
             { driver.add_stderr_shock((yystack_[4].value.string_val), (yystack_[1].value.node_val)); }
#line 2033 "pkg/src/DynareBison.cc"
    break;

  case 352: // shock_elem: VAR symbol EQUAL expression ';'
#line 851 "pkg/src/lex_yacc/DynareBison.yy"
             { driver.add_var_shock((yystack_[3].value.string_val), (yystack_[1].value.node_val)); }
#line 2039 "pkg/src/DynareBison.cc"
    break;

  case 353: // shock_elem: VAR symbol COMMA symbol EQUAL expression ';'
#line 853 "pkg/src/lex_yacc/DynareBison.yy"
             { driver.add_covar_shock((yystack_[5].value.string_val), (yystack_[3].value.string_val), (yystack_[1].value.node_val)); }
#line 2045 "pkg/src/DynareBison.cc"
    break;

  case 354: // shock_elem: CORR symbol COMMA symbol EQUAL expression ';'
#line 855 "pkg/src/lex_yacc/DynareBison.yy"
             { driver.add_correl_shock((yystack_[5].value.string_val), (yystack_[3].value.string_val), (yystack_[1].value.node_val)); }
#line 2051 "pkg/src/DynareBison.cc"
    break;

  case 355: // det_shock_elem: VAR symbol ';' PERIODS period_list ';' VALUES value_list ';'
#line 859 "pkg/src/lex_yacc/DynareBison.yy"
                 { driver.add_det_shock((yystack_[7].value.string_val), false); }
#line 2057 "pkg/src/DynareBison.cc"
    break;

  case 356: // $@9: %empty
#line 862 "pkg/src/lex_yacc/DynareBison.yy"
                                          {driver.begin_svar_identification();}
#line 2063 "pkg/src/DynareBison.cc"
    break;

  case 357: // svar_identification: SVAR_IDENTIFICATION $@9 ';' svar_identification_list END ';'
#line 863 "pkg/src/lex_yacc/DynareBison.yy"
                      { driver.end_svar_identification(); }
#line 2069 "pkg/src/DynareBison.cc"
    break;

  case 360: // svar_identification_elem: EXCLUSION LAG INT_NUMBER ';' svar_equation_list
#line 871 "pkg/src/lex_yacc/DynareBison.yy"
                           { driver.combine_lag_and_restriction((yystack_[2].value.string_val)); }
#line 2075 "pkg/src/DynareBison.cc"
    break;

  case 361: // svar_identification_elem: EXCLUSION CONSTANTS ';'
#line 873 "pkg/src/lex_yacc/DynareBison.yy"
                           { driver.add_constants_exclusion(); }
#line 2081 "pkg/src/DynareBison.cc"
    break;

  case 362: // $@10: %empty
#line 875 "pkg/src/lex_yacc/DynareBison.yy"
                         { driver.add_restriction_equation_nbr((yystack_[1].value.string_val));}
#line 2087 "pkg/src/DynareBison.cc"
    break;

  case 363: // $@11: %empty
#line 877 "pkg/src/lex_yacc/DynareBison.yy"
                                {driver.add_restriction_equal();}
#line 2093 "pkg/src/DynareBison.cc"
    break;

  case 365: // svar_identification_elem: UPPER_CHOLESKY ';'
#line 880 "pkg/src/lex_yacc/DynareBison.yy"
                           { driver.add_upper_cholesky(); }
#line 2099 "pkg/src/DynareBison.cc"
    break;

  case 366: // svar_identification_elem: LOWER_CHOLESKY ';'
#line 882 "pkg/src/lex_yacc/DynareBison.yy"
                           { driver.add_lower_cholesky(); }
#line 2105 "pkg/src/DynareBison.cc"
    break;

  case 367: // svar_equation_list: svar_equation_list EQUATION INT_NUMBER COMMA svar_var_list ';'
#line 886 "pkg/src/lex_yacc/DynareBison.yy"
                     { driver.add_restriction_in_equation((yystack_[3].value.string_val)); }
#line 2111 "pkg/src/DynareBison.cc"
    break;

  case 368: // svar_equation_list: EQUATION INT_NUMBER COMMA svar_var_list ';'
#line 888 "pkg/src/lex_yacc/DynareBison.yy"
                     { driver.add_restriction_in_equation((yystack_[3].value.string_val)); }
#line 2117 "pkg/src/DynareBison.cc"
    break;

  case 369: // svar_var_list: svar_var_list COMMA symbol
#line 892 "pkg/src/lex_yacc/DynareBison.yy"
                { driver.add_in_svar_restriction_symbols((yystack_[0].value.string_val)); }
#line 2123 "pkg/src/DynareBison.cc"
    break;

  case 370: // svar_var_list: symbol
#line 894 "pkg/src/lex_yacc/DynareBison.yy"
                { driver.add_in_svar_restriction_symbols((yystack_[0].value.string_val)); }
#line 2129 "pkg/src/DynareBison.cc"
    break;

  case 371: // restriction_expression: expression
#line 897 "pkg/src/lex_yacc/DynareBison.yy"
                                    {driver.check_restriction_expression_constant((yystack_[0].value.node_val));}
#line 2135 "pkg/src/DynareBison.cc"
    break;

  case 375: // restriction_elem_expression: COEFF '(' symbol COMMA INT_NUMBER ')'
#line 906 "pkg/src/lex_yacc/DynareBison.yy"
                                 { driver.add_positive_restriction_element((yystack_[3].value.string_val),(yystack_[1].value.string_val));}
#line 2141 "pkg/src/DynareBison.cc"
    break;

  case 376: // restriction_elem_expression: PLUS COEFF '(' symbol COMMA INT_NUMBER ')'
#line 908 "pkg/src/lex_yacc/DynareBison.yy"
                                 { driver.add_positive_restriction_element((yystack_[3].value.string_val),(yystack_[1].value.string_val));}
#line 2147 "pkg/src/DynareBison.cc"
    break;

  case 377: // restriction_elem_expression: MINUS COEFF '(' symbol COMMA INT_NUMBER ')'
#line 910 "pkg/src/lex_yacc/DynareBison.yy"
                                 { driver.add_negative_restriction_element((yystack_[3].value.string_val),(yystack_[1].value.string_val));}
#line 2153 "pkg/src/DynareBison.cc"
    break;

  case 378: // restriction_elem_expression: expression TIMES COEFF '(' symbol COMMA INT_NUMBER ')'
#line 912 "pkg/src/lex_yacc/DynareBison.yy"
                                 { driver.add_positive_restriction_element((yystack_[7].value.node_val),(yystack_[3].value.string_val),(yystack_[1].value.string_val));}
#line 2159 "pkg/src/DynareBison.cc"
    break;

  case 379: // svar_global_identification_check: SVAR_GLOBAL_IDENTIFICATION_CHECK ';'
#line 916 "pkg/src/lex_yacc/DynareBison.yy"
                                  { driver.add_svar_global_identification_check(); }
#line 2165 "pkg/src/DynareBison.cc"
    break;

  case 380: // markov_switching: MARKOV_SWITCHING '(' ms_options_list ')' ';'
#line 920 "pkg/src/lex_yacc/DynareBison.yy"
                   { driver.markov_switching(); }
#line 2171 "pkg/src/DynareBison.cc"
    break;

  case 389: // svar: SVAR '(' svar_options_list ')' ';'
#line 936 "pkg/src/lex_yacc/DynareBison.yy"
       { driver.svar(); }
#line 2177 "pkg/src/DynareBison.cc"
    break;

  case 396: // mshocks: MSHOCKS ';' mshock_list END ';'
#line 949 "pkg/src/lex_yacc/DynareBison.yy"
                                          { driver.end_mshocks(false); }
#line 2183 "pkg/src/DynareBison.cc"
    break;

  case 397: // mshocks: MSHOCKS '(' OVERWRITE ')' ';' mshock_list END ';'
#line 950 "pkg/src/lex_yacc/DynareBison.yy"
                                                            { driver.end_mshocks(true); }
#line 2189 "pkg/src/DynareBison.cc"
    break;

  case 400: // period_list: period_list COMMA INT_NUMBER
#line 958 "pkg/src/lex_yacc/DynareBison.yy"
              { driver.add_period((yystack_[0].value.string_val)); }
#line 2195 "pkg/src/DynareBison.cc"
    break;

  case 401: // period_list: period_list INT_NUMBER
#line 960 "pkg/src/lex_yacc/DynareBison.yy"
              { driver.add_period((yystack_[0].value.string_val)); }
#line 2201 "pkg/src/DynareBison.cc"
    break;

  case 402: // period_list: period_list COMMA INT_NUMBER ':' INT_NUMBER
#line 962 "pkg/src/lex_yacc/DynareBison.yy"
              { driver.add_period((yystack_[2].value.string_val), (yystack_[0].value.string_val)); }
#line 2207 "pkg/src/DynareBison.cc"
    break;

  case 403: // period_list: period_list INT_NUMBER ':' INT_NUMBER
#line 964 "pkg/src/lex_yacc/DynareBison.yy"
              { driver.add_period((yystack_[2].value.string_val), (yystack_[0].value.string_val)); }
#line 2213 "pkg/src/DynareBison.cc"
    break;

  case 404: // period_list: INT_NUMBER ':' INT_NUMBER
#line 966 "pkg/src/lex_yacc/DynareBison.yy"
              { driver.add_period((yystack_[2].value.string_val), (yystack_[0].value.string_val)); }
#line 2219 "pkg/src/DynareBison.cc"
    break;

  case 405: // period_list: INT_NUMBER
#line 968 "pkg/src/lex_yacc/DynareBison.yy"
              { driver.add_period((yystack_[0].value.string_val)); }
#line 2225 "pkg/src/DynareBison.cc"
    break;

  case 406: // sigma_e: SIGMA_E EQUAL '[' triangular_matrix ']' ';'
#line 971 "pkg/src/lex_yacc/DynareBison.yy"
                                                      { driver.do_sigma_e(); }
#line 2231 "pkg/src/DynareBison.cc"
    break;

  case 407: // value_list: value_list COMMA '(' expression ')'
#line 974 "pkg/src/lex_yacc/DynareBison.yy"
             { driver.add_value((yystack_[1].value.node_val)); }
#line 2237 "pkg/src/DynareBison.cc"
    break;

  case 408: // value_list: value_list '(' expression ')'
#line 976 "pkg/src/lex_yacc/DynareBison.yy"
             { driver.add_value((yystack_[1].value.node_val)); }
#line 2243 "pkg/src/DynareBison.cc"
    break;

  case 409: // value_list: '(' expression ')'
#line 978 "pkg/src/lex_yacc/DynareBison.yy"
             { driver.add_value((yystack_[1].value.node_val)); }
#line 2249 "pkg/src/DynareBison.cc"
    break;

  case 410: // value_list: value_list COMMA signed_number
#line 980 "pkg/src/lex_yacc/DynareBison.yy"
             { driver.add_value((yystack_[0].value.string_val)); }
#line 2255 "pkg/src/DynareBison.cc"
    break;

  case 411: // value_list: value_list signed_number
#line 982 "pkg/src/lex_yacc/DynareBison.yy"
             { driver.add_value((yystack_[0].value.string_val)); }
#line 2261 "pkg/src/DynareBison.cc"
    break;

  case 412: // value_list: signed_number
#line 984 "pkg/src/lex_yacc/DynareBison.yy"
             { driver.add_value((yystack_[0].value.string_val)); }
#line 2267 "pkg/src/DynareBison.cc"
    break;

  case 413: // triangular_matrix: triangular_matrix ';' triangular_row
#line 988 "pkg/src/lex_yacc/DynareBison.yy"
                    { driver.end_of_row(); }
#line 2273 "pkg/src/DynareBison.cc"
    break;

  case 414: // triangular_matrix: triangular_row
#line 990 "pkg/src/lex_yacc/DynareBison.yy"
                    { driver.end_of_row(); }
#line 2279 "pkg/src/DynareBison.cc"
    break;

  case 415: // triangular_row: triangular_row COMMA '(' expression ')'
#line 994 "pkg/src/lex_yacc/DynareBison.yy"
                 { driver.add_to_row((yystack_[1].value.node_val)); }
#line 2285 "pkg/src/DynareBison.cc"
    break;

  case 416: // triangular_row: triangular_row COMMA signed_number
#line 996 "pkg/src/lex_yacc/DynareBison.yy"
                 { driver.add_to_row_const((yystack_[0].value.string_val)); }
#line 2291 "pkg/src/DynareBison.cc"
    break;

  case 417: // triangular_row: triangular_row '(' expression ')'
#line 998 "pkg/src/lex_yacc/DynareBison.yy"
                 { driver.add_to_row((yystack_[1].value.node_val)); }
#line 2297 "pkg/src/DynareBison.cc"
    break;

  case 418: // triangular_row: triangular_row signed_number
#line 1000 "pkg/src/lex_yacc/DynareBison.yy"
                 { driver.add_to_row_const((yystack_[0].value.string_val)); }
#line 2303 "pkg/src/DynareBison.cc"
    break;

  case 419: // triangular_row: '(' expression ')'
#line 1002 "pkg/src/lex_yacc/DynareBison.yy"
                 { driver.add_to_row((yystack_[1].value.node_val)); }
#line 2309 "pkg/src/DynareBison.cc"
    break;

  case 420: // triangular_row: signed_number
#line 1004 "pkg/src/lex_yacc/DynareBison.yy"
                 { driver.add_to_row_const((yystack_[0].value.string_val)); }
#line 2315 "pkg/src/DynareBison.cc"
    break;

  case 421: // steady: STEADY ';'
#line 1008 "pkg/src/lex_yacc/DynareBison.yy"
         { driver.steady(); }
#line 2321 "pkg/src/DynareBison.cc"
    break;

  case 422: // steady: STEADY '(' steady_options_list ')' ';'
#line 1010 "pkg/src/lex_yacc/DynareBison.yy"
         { driver.steady(); }
#line 2327 "pkg/src/DynareBison.cc"
    break;

  case 433: // check: CHECK ';'
#line 1028 "pkg/src/lex_yacc/DynareBison.yy"
        { driver.check(); }
#line 2333 "pkg/src/DynareBison.cc"
    break;

  case 434: // check: CHECK '(' check_options_list ')' ';'
#line 1030 "pkg/src/lex_yacc/DynareBison.yy"
        { driver.check(); }
#line 2339 "pkg/src/DynareBison.cc"
    break;

  case 439: // model_info: MODEL_INFO ';'
#line 1042 "pkg/src/lex_yacc/DynareBison.yy"
             { driver.model_info(); }
#line 2345 "pkg/src/DynareBison.cc"
    break;

  case 440: // model_info: MODEL_INFO '(' model_info_options_list ')' ';'
#line 1044 "pkg/src/lex_yacc/DynareBison.yy"
              { driver.model_info(); }
#line 2351 "pkg/src/DynareBison.cc"
    break;

  case 444: // perfect_foresight_setup: PERFECT_FORESIGHT_SETUP ';'
#line 1053 "pkg/src/lex_yacc/DynareBison.yy"
                          { driver.perfect_foresight_setup(); }
#line 2357 "pkg/src/DynareBison.cc"
    break;

  case 445: // perfect_foresight_setup: PERFECT_FORESIGHT_SETUP '(' perfect_foresight_setup_options_list ')' ';'
#line 1055 "pkg/src/lex_yacc/DynareBison.yy"
                          { driver.perfect_foresight_setup(); }
#line 2363 "pkg/src/DynareBison.cc"
    break;

  case 450: // perfect_foresight_solver: PERFECT_FORESIGHT_SOLVER ';'
#line 1067 "pkg/src/lex_yacc/DynareBison.yy"
                          { driver.perfect_foresight_solver(); }
#line 2369 "pkg/src/DynareBison.cc"
    break;

  case 451: // perfect_foresight_solver: PERFECT_FORESIGHT_SOLVER '(' perfect_foresight_solver_options_list ')' ';'
#line 1069 "pkg/src/lex_yacc/DynareBison.yy"
                          { driver.perfect_foresight_solver(); }
#line 2375 "pkg/src/DynareBison.cc"
    break;

  case 466: // prior_function: PRIOR_FUNCTION '(' prior_posterior_function_options_list ')' ';'
#line 1091 "pkg/src/lex_yacc/DynareBison.yy"
                { driver.prior_posterior_function(true); }
#line 2381 "pkg/src/DynareBison.cc"
    break;

  case 467: // posterior_function: POSTERIOR_FUNCTION '(' prior_posterior_function_options_list ')' ';'
#line 1095 "pkg/src/lex_yacc/DynareBison.yy"
                    { driver.prior_posterior_function(false); }
#line 2387 "pkg/src/DynareBison.cc"
    break;

  case 472: // simul: SIMUL ';'
#line 1107 "pkg/src/lex_yacc/DynareBison.yy"
        { driver.simul(); }
#line 2393 "pkg/src/DynareBison.cc"
    break;

  case 473: // simul: SIMUL '(' simul_options_list ')' ';'
#line 1109 "pkg/src/lex_yacc/DynareBison.yy"
        { driver.simul(); }
#line 2399 "pkg/src/DynareBison.cc"
    break;

  case 478: // external_function: EXTERNAL_FUNCTION '(' external_function_options_list ')' ';'
#line 1121 "pkg/src/lex_yacc/DynareBison.yy"
                    { driver.external_function(); }
#line 2405 "pkg/src/DynareBison.cc"
    break;

  case 485: // stoch_simul: STOCH_SIMUL ';'
#line 1135 "pkg/src/lex_yacc/DynareBison.yy"
              { driver.stoch_simul(); }
#line 2411 "pkg/src/DynareBison.cc"
    break;

  case 486: // stoch_simul: STOCH_SIMUL '(' stoch_simul_options_list ')' ';'
#line 1137 "pkg/src/lex_yacc/DynareBison.yy"
              { driver.stoch_simul(); }
#line 2417 "pkg/src/DynareBison.cc"
    break;

  case 487: // stoch_simul: STOCH_SIMUL symbol_list ';'
#line 1139 "pkg/src/lex_yacc/DynareBison.yy"
              { driver.stoch_simul(); }
#line 2423 "pkg/src/DynareBison.cc"
    break;

  case 488: // stoch_simul: STOCH_SIMUL '(' stoch_simul_options_list ')' symbol_list ';'
#line 1141 "pkg/src/lex_yacc/DynareBison.yy"
              { driver.stoch_simul(); }
#line 2429 "pkg/src/DynareBison.cc"
    break;

  case 539: // symbol_list: symbol_list symbol
#line 1201 "pkg/src/lex_yacc/DynareBison.yy"
               { driver.add_in_symbol_list((yystack_[0].value.string_val)); }
#line 2435 "pkg/src/DynareBison.cc"
    break;

  case 540: // symbol_list: symbol_list COMMA symbol
#line 1203 "pkg/src/lex_yacc/DynareBison.yy"
               { driver.add_in_symbol_list((yystack_[0].value.string_val)); }
#line 2441 "pkg/src/DynareBison.cc"
    break;

  case 541: // symbol_list: symbol
#line 1205 "pkg/src/lex_yacc/DynareBison.yy"
               { driver.add_in_symbol_list((yystack_[0].value.string_val)); }
#line 2447 "pkg/src/DynareBison.cc"
    break;

  case 543: // symbol_list_ext: ':'
#line 1210 "pkg/src/lex_yacc/DynareBison.yy"
                  {
                    string *colon = new string(":");
                    driver.add_in_symbol_list(colon);
                  }
#line 2456 "pkg/src/DynareBison.cc"
    break;

  case 544: // signed_integer: PLUS INT_NUMBER
#line 1217 "pkg/src/lex_yacc/DynareBison.yy"
                 { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 2462 "pkg/src/DynareBison.cc"
    break;

  case 545: // signed_integer: MINUS INT_NUMBER
#line 1219 "pkg/src/lex_yacc/DynareBison.yy"
                { (yystack_[0].value.string_val)->insert(0, "-"); (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 2468 "pkg/src/DynareBison.cc"
    break;

  case 546: // signed_integer: INT_NUMBER
#line 1220 "pkg/src/lex_yacc/DynareBison.yy"
                 { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 2474 "pkg/src/DynareBison.cc"
    break;

  case 547: // non_negative_number: INT_NUMBER
#line 1223 "pkg/src/lex_yacc/DynareBison.yy"
                      { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 2480 "pkg/src/DynareBison.cc"
    break;

  case 548: // non_negative_number: FLOAT_NUMBER
#line 1224 "pkg/src/lex_yacc/DynareBison.yy"
                      { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 2486 "pkg/src/DynareBison.cc"
    break;

  case 549: // signed_number: PLUS non_negative_number
#line 1228 "pkg/src/lex_yacc/DynareBison.yy"
               { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 2492 "pkg/src/DynareBison.cc"
    break;

  case 550: // signed_number: MINUS non_negative_number
#line 1230 "pkg/src/lex_yacc/DynareBison.yy"
               { (yystack_[0].value.string_val)->insert(0, "-"); (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 2498 "pkg/src/DynareBison.cc"
    break;

  case 551: // signed_number: non_negative_number
#line 1231 "pkg/src/lex_yacc/DynareBison.yy"
                { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 2504 "pkg/src/DynareBison.cc"
    break;

  case 552: // signed_inf: PLUS INF_CONSTANT
#line 1235 "pkg/src/lex_yacc/DynareBison.yy"
             { (yylhs.value.string_val) = new string ("Inf"); }
#line 2510 "pkg/src/DynareBison.cc"
    break;

  case 553: // signed_inf: MINUS INF_CONSTANT
#line 1237 "pkg/src/lex_yacc/DynareBison.yy"
             { (yylhs.value.string_val) = new string ("-Inf"); }
#line 2516 "pkg/src/DynareBison.cc"
    break;

  case 554: // signed_inf: INF_CONSTANT
#line 1239 "pkg/src/lex_yacc/DynareBison.yy"
             { (yylhs.value.string_val) = new string ("Inf"); }
#line 2522 "pkg/src/DynareBison.cc"
    break;

  case 555: // signed_number_w_inf: signed_inf
#line 1242 "pkg/src/lex_yacc/DynareBison.yy"
                      { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 2528 "pkg/src/DynareBison.cc"
    break;

  case 556: // signed_number_w_inf: signed_number
#line 1243 "pkg/src/lex_yacc/DynareBison.yy"
                      { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 2534 "pkg/src/DynareBison.cc"
    break;

  case 557: // estimated_params: ESTIMATED_PARAMS ';' estimated_list END ';'
#line 1246 "pkg/src/lex_yacc/DynareBison.yy"
                                                               { driver.estimated_params(); }
#line 2540 "pkg/src/DynareBison.cc"
    break;

  case 558: // estimated_list: estimated_list estimated_elem
#line 1249 "pkg/src/lex_yacc/DynareBison.yy"
                 { driver.add_estimated_params_element(); }
#line 2546 "pkg/src/DynareBison.cc"
    break;

  case 559: // estimated_list: estimated_elem
#line 1251 "pkg/src/lex_yacc/DynareBison.yy"
                 { driver.add_estimated_params_element(); }
#line 2552 "pkg/src/DynareBison.cc"
    break;

  case 562: // estimated_elem1: STDERR symbol
#line 1258 "pkg/src/lex_yacc/DynareBison.yy"
                  {
                    driver.estim_params.type = 1;
                    driver.estim_params.name = *(yystack_[0].value.string_val);
                    delete (yystack_[0].value.string_val);
                  }
#line 2562 "pkg/src/DynareBison.cc"
    break;

  case 563: // estimated_elem1: symbol
#line 1264 "pkg/src/lex_yacc/DynareBison.yy"
                  {
                    driver.estim_params.type = 2;
                    driver.estim_params.name = *(yystack_[0].value.string_val);
                    delete (yystack_[0].value.string_val);
                  }
#line 2572 "pkg/src/DynareBison.cc"
    break;

  case 564: // estimated_elem1: CORR symbol COMMA symbol
#line 1270 "pkg/src/lex_yacc/DynareBison.yy"
                  {
                    driver.estim_params.type = 3;
                    driver.estim_params.name = *(yystack_[2].value.string_val);
                    driver.estim_params.name2 = *(yystack_[0].value.string_val);
                    delete (yystack_[2].value.string_val);
                    delete (yystack_[0].value.string_val);
                  }
#line 2584 "pkg/src/DynareBison.cc"
    break;

  case 565: // estimated_elem1: DSGE_PRIOR_WEIGHT
#line 1278 "pkg/src/lex_yacc/DynareBison.yy"
                  {
                    driver.estim_params.type = 2;
                    driver.estim_params.name = "dsge_prior_weight";
                  }
#line 2593 "pkg/src/DynareBison.cc"
    break;

  case 566: // estimated_elem2: prior_pdf COMMA estimated_elem3
#line 1285 "pkg/src/lex_yacc/DynareBison.yy"
                  {
                    driver.estim_params.prior = (yystack_[2].value.prior_distributions_val);
                  }
#line 2601 "pkg/src/DynareBison.cc"
    break;

  case 567: // estimated_elem2: expression_or_empty COMMA prior_pdf COMMA estimated_elem3
#line 1289 "pkg/src/lex_yacc/DynareBison.yy"
                  {
                    driver.estim_params.init_val = (yystack_[4].value.node_val);
                    driver.estim_params.prior = (yystack_[2].value.prior_distributions_val);
                  }
#line 2610 "pkg/src/DynareBison.cc"
    break;

  case 568: // estimated_elem2: expression_or_empty COMMA expression_or_empty COMMA expression_or_empty COMMA prior_pdf COMMA estimated_elem3
#line 1294 "pkg/src/lex_yacc/DynareBison.yy"
                  {
                    driver.estim_params.init_val = (yystack_[8].value.node_val);
                    driver.estim_params.low_bound = (yystack_[6].value.node_val);
                    driver.estim_params.up_bound = (yystack_[4].value.node_val);
                    driver.estim_params.prior = (yystack_[2].value.prior_distributions_val);
                  }
#line 2621 "pkg/src/DynareBison.cc"
    break;

  case 569: // estimated_elem2: expression
#line 1301 "pkg/src/lex_yacc/DynareBison.yy"
                  {
                    driver.estim_params.init_val = (yystack_[0].value.node_val);
                  }
#line 2629 "pkg/src/DynareBison.cc"
    break;

  case 570: // estimated_elem2: expression_or_empty COMMA expression_or_empty COMMA expression_or_empty
#line 1305 "pkg/src/lex_yacc/DynareBison.yy"
                  {
                    driver.estim_params.init_val = (yystack_[4].value.node_val);
                    driver.estim_params.low_bound = (yystack_[2].value.node_val);
                    driver.estim_params.up_bound = (yystack_[0].value.node_val);
                  }
#line 2639 "pkg/src/DynareBison.cc"
    break;

  case 571: // estimated_elem3: expression_or_empty COMMA expression_or_empty
#line 1313 "pkg/src/lex_yacc/DynareBison.yy"
                  {
                    driver.estim_params.mean = (yystack_[2].value.node_val);
                    driver.estim_params.std = (yystack_[0].value.node_val);
                  }
#line 2648 "pkg/src/DynareBison.cc"
    break;

  case 572: // estimated_elem3: expression_or_empty COMMA expression_or_empty COMMA expression_or_empty
#line 1318 "pkg/src/lex_yacc/DynareBison.yy"
                  {
                    driver.estim_params.mean = (yystack_[4].value.node_val);
                    driver.estim_params.std = (yystack_[2].value.node_val);
                    driver.estim_params.p3 = (yystack_[0].value.node_val);
                  }
#line 2658 "pkg/src/DynareBison.cc"
    break;

  case 573: // estimated_elem3: expression_or_empty COMMA expression_or_empty COMMA expression_or_empty COMMA expression_or_empty
#line 1324 "pkg/src/lex_yacc/DynareBison.yy"
                  {
                    driver.estim_params.mean = (yystack_[6].value.node_val);
                    driver.estim_params.std = (yystack_[4].value.node_val);
                    driver.estim_params.p3 = (yystack_[2].value.node_val);
                    driver.estim_params.p4 = (yystack_[0].value.node_val);
                  }
#line 2669 "pkg/src/DynareBison.cc"
    break;

  case 574: // estimated_elem3: expression_or_empty COMMA expression_or_empty COMMA expression_or_empty COMMA expression_or_empty COMMA expression
#line 1331 "pkg/src/lex_yacc/DynareBison.yy"
                  {
                    driver.estim_params.mean = (yystack_[8].value.node_val);
                    driver.estim_params.std = (yystack_[6].value.node_val);
                    driver.estim_params.p3 = (yystack_[4].value.node_val);
                    driver.estim_params.p4 = (yystack_[2].value.node_val);
                    driver.estim_params.jscale = (yystack_[0].value.node_val);
                  }
#line 2681 "pkg/src/DynareBison.cc"
    break;

  case 575: // estimated_params_init: ESTIMATED_PARAMS_INIT ';' estimated_init_list END ';'
#line 1341 "pkg/src/lex_yacc/DynareBison.yy"
                        { driver.estimated_params_init(); }
#line 2687 "pkg/src/DynareBison.cc"
    break;

  case 576: // estimated_params_init: ESTIMATED_PARAMS_INIT '(' USE_CALIBRATION ')' ';' END ';'
#line 1343 "pkg/src/lex_yacc/DynareBison.yy"
                        { driver.estimated_params_init(true); }
#line 2693 "pkg/src/DynareBison.cc"
    break;

  case 577: // estimated_params_init: ESTIMATED_PARAMS_INIT '(' USE_CALIBRATION ')' ';' estimated_init_list END ';'
#line 1345 "pkg/src/lex_yacc/DynareBison.yy"
                        { driver.estimated_params_init(true); }
#line 2699 "pkg/src/DynareBison.cc"
    break;

  case 578: // estimated_init_list: estimated_init_list estimated_init_elem
#line 1349 "pkg/src/lex_yacc/DynareBison.yy"
                      { driver.add_estimated_params_element(); }
#line 2705 "pkg/src/DynareBison.cc"
    break;

  case 579: // estimated_init_list: estimated_init_elem
#line 1351 "pkg/src/lex_yacc/DynareBison.yy"
                      { driver.add_estimated_params_element(); }
#line 2711 "pkg/src/DynareBison.cc"
    break;

  case 580: // estimated_init_elem: STDERR symbol COMMA expression ';'
#line 1355 "pkg/src/lex_yacc/DynareBison.yy"
                      {
                        driver.estim_params.type = 1;
                        driver.estim_params.name = *(yystack_[3].value.string_val);
                        driver.estim_params.init_val = (yystack_[1].value.node_val);
                        delete (yystack_[3].value.string_val);
                      }
#line 2722 "pkg/src/DynareBison.cc"
    break;

  case 581: // estimated_init_elem: CORR symbol COMMA symbol COMMA expression ';'
#line 1362 "pkg/src/lex_yacc/DynareBison.yy"
                      {
                        driver.estim_params.type = 3;
                        driver.estim_params.name = *(yystack_[5].value.string_val);
                        driver.estim_params.name2 = *(yystack_[3].value.string_val);
                        driver.estim_params.init_val = (yystack_[1].value.node_val);
                        delete (yystack_[5].value.string_val);
                        delete (yystack_[3].value.string_val);
                      }
#line 2735 "pkg/src/DynareBison.cc"
    break;

  case 582: // estimated_init_elem: symbol COMMA expression ';'
#line 1371 "pkg/src/lex_yacc/DynareBison.yy"
                      {
                        driver.estim_params.type = 2;
                        driver.estim_params.name = *(yystack_[3].value.string_val);
                        driver.estim_params.init_val = (yystack_[1].value.node_val);
                        delete (yystack_[3].value.string_val);
                      }
#line 2746 "pkg/src/DynareBison.cc"
    break;

  case 583: // estimated_params_bounds: ESTIMATED_PARAMS_BOUNDS ';' estimated_bounds_list END ';'
#line 1380 "pkg/src/lex_yacc/DynareBison.yy"
                          { driver.estimated_params_bounds(); }
#line 2752 "pkg/src/DynareBison.cc"
    break;

  case 584: // estimated_bounds_list: estimated_bounds_list estimated_bounds_elem
#line 1383 "pkg/src/lex_yacc/DynareBison.yy"
                        { driver.add_estimated_params_element(); }
#line 2758 "pkg/src/DynareBison.cc"
    break;

  case 585: // estimated_bounds_list: estimated_bounds_elem
#line 1385 "pkg/src/lex_yacc/DynareBison.yy"
                        { driver.add_estimated_params_element(); }
#line 2764 "pkg/src/DynareBison.cc"
    break;

  case 586: // estimated_bounds_elem: STDERR symbol COMMA expression COMMA expression ';'
#line 1389 "pkg/src/lex_yacc/DynareBison.yy"
                        {
                          driver.estim_params.type = 1;
                          driver.estim_params.name = *(yystack_[5].value.string_val);
                          driver.estim_params.low_bound = (yystack_[3].value.node_val);
                          driver.estim_params.up_bound = (yystack_[1].value.node_val);
                          delete (yystack_[5].value.string_val);
                        }
#line 2776 "pkg/src/DynareBison.cc"
    break;

  case 587: // estimated_bounds_elem: CORR symbol COMMA symbol COMMA expression COMMA expression ';'
#line 1397 "pkg/src/lex_yacc/DynareBison.yy"
                        {
                          driver.estim_params.type = 3;
                          driver.estim_params.name = *(yystack_[7].value.string_val);
                          driver.estim_params.name2 = *(yystack_[5].value.string_val);
                          driver.estim_params.low_bound = (yystack_[3].value.node_val);
                          driver.estim_params.up_bound = (yystack_[1].value.node_val);
                          delete (yystack_[7].value.string_val);
                          delete (yystack_[5].value.string_val);
                        }
#line 2790 "pkg/src/DynareBison.cc"
    break;

  case 588: // estimated_bounds_elem: symbol COMMA expression COMMA expression ';'
#line 1407 "pkg/src/lex_yacc/DynareBison.yy"
                        {
                          driver.estim_params.type = 2;
                          driver.estim_params.name = *(yystack_[5].value.string_val);
                          driver.estim_params.low_bound = (yystack_[3].value.node_val);
                          driver.estim_params.up_bound = (yystack_[1].value.node_val);
                          delete (yystack_[5].value.string_val);
                        }
#line 2802 "pkg/src/DynareBison.cc"
    break;

  case 589: // osr_params_bounds: OSR_PARAMS_BOUNDS ';' osr_bounds_list END ';'
#line 1417 "pkg/src/lex_yacc/DynareBison.yy"
                    { driver.osr_params_bounds(); }
#line 2808 "pkg/src/DynareBison.cc"
    break;

  case 590: // osr_bounds_list: osr_bounds_list osr_bounds_elem
#line 1420 "pkg/src/lex_yacc/DynareBison.yy"
                  { driver.add_osr_params_element(); }
#line 2814 "pkg/src/DynareBison.cc"
    break;

  case 591: // osr_bounds_list: osr_bounds_elem
#line 1422 "pkg/src/lex_yacc/DynareBison.yy"
                  { driver.add_osr_params_element(); }
#line 2820 "pkg/src/DynareBison.cc"
    break;

  case 592: // osr_bounds_elem: symbol COMMA expression COMMA expression ';'
#line 1426 "pkg/src/lex_yacc/DynareBison.yy"
                  {
                    driver.osr_params.name = *(yystack_[5].value.string_val);
                    driver.osr_params.low_bound = (yystack_[3].value.node_val);
                    driver.osr_params.up_bound = (yystack_[1].value.node_val);
                    delete (yystack_[5].value.string_val);
                  }
#line 2831 "pkg/src/DynareBison.cc"
    break;

  case 593: // prior_distribution: BETA
#line 1435 "pkg/src/lex_yacc/DynareBison.yy"
                     { (yylhs.value.prior_distributions_val) = eBeta; }
#line 2837 "pkg/src/DynareBison.cc"
    break;

  case 594: // prior_distribution: GAMMA
#line 1437 "pkg/src/lex_yacc/DynareBison.yy"
                     { (yylhs.value.prior_distributions_val) = eGamma; }
#line 2843 "pkg/src/DynareBison.cc"
    break;

  case 595: // prior_distribution: NORMAL
#line 1439 "pkg/src/lex_yacc/DynareBison.yy"
                     { (yylhs.value.prior_distributions_val) = eNormal; }
#line 2849 "pkg/src/DynareBison.cc"
    break;

  case 596: // prior_distribution: INV_GAMMA
#line 1441 "pkg/src/lex_yacc/DynareBison.yy"
                     { (yylhs.value.prior_distributions_val) = eInvGamma; }
#line 2855 "pkg/src/DynareBison.cc"
    break;

  case 597: // prior_distribution: INV_GAMMA1
#line 1443 "pkg/src/lex_yacc/DynareBison.yy"
                     { (yylhs.value.prior_distributions_val) = eInvGamma1; }
#line 2861 "pkg/src/DynareBison.cc"
    break;

  case 598: // prior_distribution: UNIFORM
#line 1445 "pkg/src/lex_yacc/DynareBison.yy"
                     { (yylhs.value.prior_distributions_val) = eUniform; }
#line 2867 "pkg/src/DynareBison.cc"
    break;

  case 599: // prior_distribution: INV_GAMMA2
#line 1447 "pkg/src/lex_yacc/DynareBison.yy"
                     { (yylhs.value.prior_distributions_val) = eInvGamma2; }
#line 2873 "pkg/src/DynareBison.cc"
    break;

  case 600: // prior_distribution: DIRICHLET
#line 1449 "pkg/src/lex_yacc/DynareBison.yy"
                     { (yylhs.value.prior_distributions_val) = eDirichlet; }
#line 2879 "pkg/src/DynareBison.cc"
    break;

  case 601: // prior_distribution: WEIBULL
#line 1451 "pkg/src/lex_yacc/DynareBison.yy"
                     { (yylhs.value.prior_distributions_val) = eWeibull; }
#line 2885 "pkg/src/DynareBison.cc"
    break;

  case 602: // prior_pdf: BETA_PDF
#line 1455 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.prior_distributions_val) = eBeta; }
#line 2891 "pkg/src/DynareBison.cc"
    break;

  case 603: // prior_pdf: GAMMA_PDF
#line 1457 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.prior_distributions_val) = eGamma; }
#line 2897 "pkg/src/DynareBison.cc"
    break;

  case 604: // prior_pdf: NORMAL_PDF
#line 1459 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.prior_distributions_val) = eNormal; }
#line 2903 "pkg/src/DynareBison.cc"
    break;

  case 605: // prior_pdf: INV_GAMMA_PDF
#line 1461 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.prior_distributions_val) = eInvGamma; }
#line 2909 "pkg/src/DynareBison.cc"
    break;

  case 606: // prior_pdf: INV_GAMMA1_PDF
#line 1463 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.prior_distributions_val) = eInvGamma1; }
#line 2915 "pkg/src/DynareBison.cc"
    break;

  case 607: // prior_pdf: UNIFORM_PDF
#line 1465 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.prior_distributions_val) = eUniform; }
#line 2921 "pkg/src/DynareBison.cc"
    break;

  case 608: // prior_pdf: INV_GAMMA2_PDF
#line 1467 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.prior_distributions_val) = eInvGamma2; }
#line 2927 "pkg/src/DynareBison.cc"
    break;

  case 609: // prior_pdf: WEIBULL_PDF
#line 1469 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.prior_distributions_val) = eWeibull; }
#line 2933 "pkg/src/DynareBison.cc"
    break;

  case 610: // date_str: DATES
#line 1472 "pkg/src/lex_yacc/DynareBison.yy"
                 { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 2939 "pkg/src/DynareBison.cc"
    break;

  case 611: // date_expr: date_str
#line 1475 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 2945 "pkg/src/DynareBison.cc"
    break;

  case 612: // date_expr: date_expr PLUS INT_NUMBER
#line 1477 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.string_val) = (yystack_[2].value.string_val); (yylhs.value.string_val)->append("+").append(*(yystack_[0].value.string_val)); }
#line 2951 "pkg/src/DynareBison.cc"
    break;

  case 613: // set_time: SET_TIME '(' date_expr ')' ';'
#line 1481 "pkg/src/lex_yacc/DynareBison.yy"
           { driver.set_time((yystack_[2].value.string_val)); }
#line 2957 "pkg/src/DynareBison.cc"
    break;

  case 614: // data: DATA '(' data_options_list ')' ';'
#line 1485 "pkg/src/lex_yacc/DynareBison.yy"
       { driver.estimation_data(); }
#line 2963 "pkg/src/DynareBison.cc"
    break;

  case 624: // subsamples: subsamples_eq_opt '(' subsamples_name_list ')' ';'
#line 1502 "pkg/src/lex_yacc/DynareBison.yy"
             { driver.set_subsamples((yystack_[4].value.vector_string_val)->at(0), (yystack_[4].value.vector_string_val)->at(1)); }
#line 2969 "pkg/src/DynareBison.cc"
    break;

  case 625: // subsamples_eq: subsamples_eq_opt EQUAL subsamples_eq_opt ';'
#line 1506 "pkg/src/lex_yacc/DynareBison.yy"
                {
                  driver.copy_subsamples((yystack_[3].value.vector_string_val)->at(0), (yystack_[3].value.vector_string_val)->at(1), (yystack_[1].value.vector_string_val)->at(0), (yystack_[1].value.vector_string_val)->at(1));
                  delete (yystack_[3].value.vector_string_val);
                  delete (yystack_[1].value.vector_string_val);
                }
#line 2979 "pkg/src/DynareBison.cc"
    break;

  case 626: // subsamples_eq_opt: symbol '.' SUBSAMPLES
#line 1514 "pkg/src/lex_yacc/DynareBison.yy"
                    {
                      (yylhs.value.vector_string_val) = new vector<string *>();
                      (yylhs.value.vector_string_val)->push_back((yystack_[2].value.string_val));
                      (yylhs.value.vector_string_val)->push_back(new string (""));
                    }
#line 2989 "pkg/src/DynareBison.cc"
    break;

  case 627: // subsamples_eq_opt: STD '(' symbol ')' '.' SUBSAMPLES
#line 1520 "pkg/src/lex_yacc/DynareBison.yy"
                    {
                      (yylhs.value.vector_string_val) = new vector<string *>();
                      (yylhs.value.vector_string_val)->push_back((yystack_[3].value.string_val));
                      (yylhs.value.vector_string_val)->push_back(new string (""));
                    }
#line 2999 "pkg/src/DynareBison.cc"
    break;

  case 628: // subsamples_eq_opt: CORR '(' symbol COMMA symbol ')' '.' SUBSAMPLES
#line 1526 "pkg/src/lex_yacc/DynareBison.yy"
                    {
                      (yylhs.value.vector_string_val) = new vector<string *>();
                      (yylhs.value.vector_string_val)->push_back((yystack_[5].value.string_val));
                      (yylhs.value.vector_string_val)->push_back((yystack_[3].value.string_val));
                    }
#line 3009 "pkg/src/DynareBison.cc"
    break;

  case 631: // $@12: %empty
#line 1537 "pkg/src/lex_yacc/DynareBison.yy"
                         { driver.set_prior_variance(); driver.prior_shape = eNoShape; }
#line 3015 "pkg/src/DynareBison.cc"
    break;

  case 632: // prior: symbol '.' PRIOR $@12 '(' prior_options_list ')' ';'
#line 1538 "pkg/src/lex_yacc/DynareBison.yy"
        { driver.set_prior((yystack_[7].value.string_val), new string ("")); }
#line 3021 "pkg/src/DynareBison.cc"
    break;

  case 633: // $@13: %empty
#line 1539 "pkg/src/lex_yacc/DynareBison.yy"
                                    { driver.set_prior_variance(); driver.prior_shape = eNoShape; }
#line 3027 "pkg/src/DynareBison.cc"
    break;

  case 634: // prior: symbol '.' symbol '.' PRIOR $@13 '(' prior_options_list ')' ';'
#line 1540 "pkg/src/lex_yacc/DynareBison.yy"
        { driver.set_prior((yystack_[9].value.string_val), (yystack_[7].value.string_val)); }
#line 3033 "pkg/src/DynareBison.cc"
    break;

  case 635: // $@14: %empty
#line 1541 "pkg/src/lex_yacc/DynareBison.yy"
                             { driver.set_prior_variance(); driver.prior_shape = eNoShape; }
#line 3039 "pkg/src/DynareBison.cc"
    break;

  case 636: // prior: SYMBOL_VEC '.' PRIOR $@14 '(' joint_prior_options_list ')' ';'
#line 1542 "pkg/src/lex_yacc/DynareBison.yy"
        { driver.set_joint_prior((yystack_[7].value.vector_string_val)); }
#line 3045 "pkg/src/DynareBison.cc"
    break;

  case 637: // $@15: %empty
#line 1543 "pkg/src/lex_yacc/DynareBison.yy"
                                     { driver.set_prior_variance(); driver.prior_shape = eNoShape; }
#line 3051 "pkg/src/DynareBison.cc"
    break;

  case 638: // prior: STD '(' symbol ')' '.' PRIOR $@15 '(' prior_options_list ')' ';'
#line 1544 "pkg/src/lex_yacc/DynareBison.yy"
        { driver.set_std_prior((yystack_[8].value.string_val), new string ("")); }
#line 3057 "pkg/src/DynareBison.cc"
    break;

  case 639: // $@16: %empty
#line 1545 "pkg/src/lex_yacc/DynareBison.yy"
                                                { driver.set_prior_variance(); driver.prior_shape = eNoShape; }
#line 3063 "pkg/src/DynareBison.cc"
    break;

  case 640: // prior: STD '(' symbol ')' '.' symbol '.' PRIOR $@16 '(' prior_options_list ')' ';'
#line 1546 "pkg/src/lex_yacc/DynareBison.yy"
        { driver.set_std_prior((yystack_[10].value.string_val), (yystack_[7].value.string_val)); }
#line 3069 "pkg/src/DynareBison.cc"
    break;

  case 641: // $@17: %empty
#line 1547 "pkg/src/lex_yacc/DynareBison.yy"
                                                   { driver.set_prior_variance(); driver.prior_shape = eNoShape; }
#line 3075 "pkg/src/DynareBison.cc"
    break;

  case 642: // prior: CORR '(' symbol COMMA symbol ')' '.' PRIOR $@17 '(' prior_options_list ')' ';'
#line 1548 "pkg/src/lex_yacc/DynareBison.yy"
        { driver.set_corr_prior((yystack_[10].value.string_val), (yystack_[8].value.string_val), new string ("")); }
#line 3081 "pkg/src/DynareBison.cc"
    break;

  case 643: // $@18: %empty
#line 1549 "pkg/src/lex_yacc/DynareBison.yy"
                                                              { driver.set_prior_variance(); driver.prior_shape = eNoShape; }
#line 3087 "pkg/src/DynareBison.cc"
    break;

  case 644: // prior: CORR '(' symbol COMMA symbol ')' '.' symbol '.' PRIOR $@18 '(' prior_options_list ')' ';'
#line 1550 "pkg/src/lex_yacc/DynareBison.yy"
        { driver.set_corr_prior((yystack_[12].value.string_val), (yystack_[10].value.string_val), (yystack_[7].value.string_val)); }
#line 3093 "pkg/src/DynareBison.cc"
    break;

  case 669: // prior_eq: prior_eq_opt EQUAL prior_eq_opt ';'
#line 1586 "pkg/src/lex_yacc/DynareBison.yy"
           {
             driver.copy_prior((yystack_[3].value.vector_string_val)->at(0), (yystack_[3].value.vector_string_val)->at(1), (yystack_[3].value.vector_string_val)->at(2), (yystack_[3].value.vector_string_val)->at(3),
                               (yystack_[1].value.vector_string_val)->at(0), (yystack_[1].value.vector_string_val)->at(1), (yystack_[1].value.vector_string_val)->at(2), (yystack_[1].value.vector_string_val)->at(3));
             delete (yystack_[3].value.vector_string_val);
             delete (yystack_[1].value.vector_string_val);
           }
#line 3104 "pkg/src/DynareBison.cc"
    break;

  case 670: // prior_eq_opt: symbol '.' PRIOR
#line 1595 "pkg/src/lex_yacc/DynareBison.yy"
               {
                 (yylhs.value.vector_string_val) = new vector<string *>();
                 (yylhs.value.vector_string_val)->push_back(new string ("par"));
                 (yylhs.value.vector_string_val)->push_back((yystack_[2].value.string_val));
                 (yylhs.value.vector_string_val)->push_back(new string (""));
                 (yylhs.value.vector_string_val)->push_back(new string (""));
               }
#line 3116 "pkg/src/DynareBison.cc"
    break;

  case 671: // prior_eq_opt: symbol '.' symbol '.' PRIOR
#line 1603 "pkg/src/lex_yacc/DynareBison.yy"
               {
                 (yylhs.value.vector_string_val) = new vector<string *>();
                 (yylhs.value.vector_string_val)->push_back(new string ("par"));
                 (yylhs.value.vector_string_val)->push_back((yystack_[4].value.string_val));
                 (yylhs.value.vector_string_val)->push_back(new string (""));
                 (yylhs.value.vector_string_val)->push_back((yystack_[2].value.string_val));
               }
#line 3128 "pkg/src/DynareBison.cc"
    break;

  case 672: // prior_eq_opt: STD '(' symbol ')' '.' PRIOR
#line 1611 "pkg/src/lex_yacc/DynareBison.yy"
               {
                 (yylhs.value.vector_string_val) = new vector<string *>();
                 (yylhs.value.vector_string_val)->push_back(new string ("std"));
                 (yylhs.value.vector_string_val)->push_back((yystack_[3].value.string_val));
                 (yylhs.value.vector_string_val)->push_back(new string (""));
                 (yylhs.value.vector_string_val)->push_back(new string (""));
               }
#line 3140 "pkg/src/DynareBison.cc"
    break;

  case 673: // prior_eq_opt: STD '(' symbol ')' '.' symbol '.' PRIOR
#line 1619 "pkg/src/lex_yacc/DynareBison.yy"
               {
                 (yylhs.value.vector_string_val) = new vector<string *>();
                 (yylhs.value.vector_string_val)->push_back(new string ("std"));
                 (yylhs.value.vector_string_val)->push_back((yystack_[5].value.string_val));
                 (yylhs.value.vector_string_val)->push_back(new string (""));
                 (yylhs.value.vector_string_val)->push_back((yystack_[2].value.string_val));
               }
#line 3152 "pkg/src/DynareBison.cc"
    break;

  case 674: // prior_eq_opt: CORR '(' symbol COMMA symbol ')' '.' PRIOR
#line 1627 "pkg/src/lex_yacc/DynareBison.yy"
               {
                 (yylhs.value.vector_string_val) = new vector<string *>();
                 (yylhs.value.vector_string_val)->push_back(new string ("corr"));
                 (yylhs.value.vector_string_val)->push_back((yystack_[5].value.string_val));
                 (yylhs.value.vector_string_val)->push_back((yystack_[3].value.string_val));
                 (yylhs.value.vector_string_val)->push_back(new string (""));
               }
#line 3164 "pkg/src/DynareBison.cc"
    break;

  case 675: // prior_eq_opt: CORR '(' symbol COMMA symbol ')' '.' symbol '.' PRIOR
#line 1635 "pkg/src/lex_yacc/DynareBison.yy"
               {
                 (yylhs.value.vector_string_val) = new vector<string *>();
                 (yylhs.value.vector_string_val)->push_back(new string ("corr"));
                 (yylhs.value.vector_string_val)->push_back((yystack_[7].value.string_val));
                 (yylhs.value.vector_string_val)->push_back((yystack_[5].value.string_val));
                 (yylhs.value.vector_string_val)->push_back((yystack_[2].value.string_val));
               }
#line 3176 "pkg/src/DynareBison.cc"
    break;

  case 676: // options: symbol '.' OPTIONS '(' options_options_list ')' ';'
#line 1645 "pkg/src/lex_yacc/DynareBison.yy"
          { driver.set_options((yystack_[6].value.string_val), new string ("")); }
#line 3182 "pkg/src/DynareBison.cc"
    break;

  case 677: // options: symbol '.' symbol '.' OPTIONS '(' options_options_list ')' ';'
#line 1647 "pkg/src/lex_yacc/DynareBison.yy"
          { driver.set_options((yystack_[8].value.string_val), (yystack_[6].value.string_val)); }
#line 3188 "pkg/src/DynareBison.cc"
    break;

  case 678: // options: STD '(' symbol ')' '.' OPTIONS '(' options_options_list ')' ';'
#line 1649 "pkg/src/lex_yacc/DynareBison.yy"
          { driver.set_std_options((yystack_[7].value.string_val), new string ("")); }
#line 3194 "pkg/src/DynareBison.cc"
    break;

  case 679: // options: STD '(' symbol ')' '.' symbol '.' OPTIONS '(' options_options_list ')' ';'
#line 1651 "pkg/src/lex_yacc/DynareBison.yy"
          { driver.set_std_options((yystack_[9].value.string_val), (yystack_[6].value.string_val)); }
#line 3200 "pkg/src/DynareBison.cc"
    break;

  case 680: // options: CORR '(' symbol COMMA symbol ')' '.' OPTIONS '(' options_options_list ')' ';'
#line 1653 "pkg/src/lex_yacc/DynareBison.yy"
          { driver.set_corr_options((yystack_[9].value.string_val), (yystack_[7].value.string_val), new string ("")); }
#line 3206 "pkg/src/DynareBison.cc"
    break;

  case 681: // options: CORR '(' symbol COMMA symbol ')' '.' symbol '.' OPTIONS '(' options_options_list ')' ';'
#line 1655 "pkg/src/lex_yacc/DynareBison.yy"
          { driver.set_corr_options((yystack_[11].value.string_val), (yystack_[9].value.string_val), (yystack_[6].value.string_val)); }
#line 3212 "pkg/src/DynareBison.cc"
    break;

  case 687: // options_eq: options_eq_opt EQUAL options_eq_opt ';'
#line 1668 "pkg/src/lex_yacc/DynareBison.yy"
             {
               driver.copy_options((yystack_[3].value.vector_string_val)->at(0), (yystack_[3].value.vector_string_val)->at(1), (yystack_[3].value.vector_string_val)->at(2), (yystack_[3].value.vector_string_val)->at(3),
                                   (yystack_[1].value.vector_string_val)->at(0), (yystack_[1].value.vector_string_val)->at(1), (yystack_[1].value.vector_string_val)->at(2), (yystack_[1].value.vector_string_val)->at(3));
               delete (yystack_[3].value.vector_string_val);
               delete (yystack_[1].value.vector_string_val);
             }
#line 3223 "pkg/src/DynareBison.cc"
    break;

  case 688: // options_eq_opt: symbol '.' OPTIONS
#line 1677 "pkg/src/lex_yacc/DynareBison.yy"
                 {
                   (yylhs.value.vector_string_val) = new vector<string *>();
                   (yylhs.value.vector_string_val)->push_back(new string ("par"));
                   (yylhs.value.vector_string_val)->push_back((yystack_[2].value.string_val));
                   (yylhs.value.vector_string_val)->push_back(new string (""));
                   (yylhs.value.vector_string_val)->push_back(new string (""));
                 }
#line 3235 "pkg/src/DynareBison.cc"
    break;

  case 689: // options_eq_opt: symbol '.' symbol '.' OPTIONS
#line 1685 "pkg/src/lex_yacc/DynareBison.yy"
                 {
                   (yylhs.value.vector_string_val) = new vector<string *>();
                   (yylhs.value.vector_string_val)->push_back(new string ("par"));
                   (yylhs.value.vector_string_val)->push_back((yystack_[4].value.string_val));
                   (yylhs.value.vector_string_val)->push_back(new string (""));
                   (yylhs.value.vector_string_val)->push_back((yystack_[2].value.string_val));
                 }
#line 3247 "pkg/src/DynareBison.cc"
    break;

  case 690: // options_eq_opt: STD '(' symbol ')' '.' OPTIONS
#line 1693 "pkg/src/lex_yacc/DynareBison.yy"
                 {
                   (yylhs.value.vector_string_val) = new vector<string *>();
                   (yylhs.value.vector_string_val)->push_back(new string ("std"));
                   (yylhs.value.vector_string_val)->push_back((yystack_[3].value.string_val));
                   (yylhs.value.vector_string_val)->push_back(new string (""));
                   (yylhs.value.vector_string_val)->push_back(new string (""));
                 }
#line 3259 "pkg/src/DynareBison.cc"
    break;

  case 691: // options_eq_opt: STD '(' symbol ')' '.' symbol '.' OPTIONS
#line 1701 "pkg/src/lex_yacc/DynareBison.yy"
                 {
                   (yylhs.value.vector_string_val) = new vector<string *>();
                   (yylhs.value.vector_string_val)->push_back(new string ("std"));
                   (yylhs.value.vector_string_val)->push_back((yystack_[5].value.string_val));
                   (yylhs.value.vector_string_val)->push_back(new string (""));
                   (yylhs.value.vector_string_val)->push_back((yystack_[2].value.string_val));
                 }
#line 3271 "pkg/src/DynareBison.cc"
    break;

  case 692: // options_eq_opt: CORR '(' symbol COMMA symbol ')' '.' OPTIONS
#line 1709 "pkg/src/lex_yacc/DynareBison.yy"
                 {
                   (yylhs.value.vector_string_val) = new vector<string *>();
                   (yylhs.value.vector_string_val)->push_back(new string ("corr"));
                   (yylhs.value.vector_string_val)->push_back((yystack_[5].value.string_val));
                   (yylhs.value.vector_string_val)->push_back((yystack_[3].value.string_val));
                   (yylhs.value.vector_string_val)->push_back(new string (""));
                 }
#line 3283 "pkg/src/DynareBison.cc"
    break;

  case 693: // options_eq_opt: CORR '(' symbol COMMA symbol ')' '.' symbol '.' OPTIONS
#line 1717 "pkg/src/lex_yacc/DynareBison.yy"
                 {
                   (yylhs.value.vector_string_val) = new vector<string *>();
                   (yylhs.value.vector_string_val)->push_back(new string ("corr"));
                   (yylhs.value.vector_string_val)->push_back((yystack_[7].value.string_val));
                   (yylhs.value.vector_string_val)->push_back((yystack_[5].value.string_val));
                   (yylhs.value.vector_string_val)->push_back((yystack_[2].value.string_val));
                 }
#line 3295 "pkg/src/DynareBison.cc"
    break;

  case 694: // estimation: ESTIMATION ';'
#line 1727 "pkg/src/lex_yacc/DynareBison.yy"
             { driver.run_estimation(); }
#line 3301 "pkg/src/DynareBison.cc"
    break;

  case 695: // estimation: ESTIMATION '(' estimation_options_list ')' ';'
#line 1729 "pkg/src/lex_yacc/DynareBison.yy"
             { driver.run_estimation(); }
#line 3307 "pkg/src/DynareBison.cc"
    break;

  case 696: // estimation: ESTIMATION symbol_list ';'
#line 1731 "pkg/src/lex_yacc/DynareBison.yy"
             { driver.run_estimation(); }
#line 3313 "pkg/src/DynareBison.cc"
    break;

  case 697: // estimation: ESTIMATION '(' estimation_options_list ')' symbol_list ';'
#line 1733 "pkg/src/lex_yacc/DynareBison.yy"
             { driver.run_estimation(); }
#line 3319 "pkg/src/DynareBison.cc"
    break;

  case 810: // list_optim_option: QUOTED_STRING COMMA QUOTED_STRING
#line 1853 "pkg/src/lex_yacc/DynareBison.yy"
                    { driver.optim_options_string((yystack_[2].value.string_val), (yystack_[0].value.string_val)); }
#line 3325 "pkg/src/DynareBison.cc"
    break;

  case 811: // list_optim_option: QUOTED_STRING COMMA signed_number
#line 1855 "pkg/src/lex_yacc/DynareBison.yy"
                    { driver.optim_options_num((yystack_[2].value.string_val), (yystack_[0].value.string_val)); }
#line 3331 "pkg/src/DynareBison.cc"
    break;

  case 814: // list_sub_sampling_option: QUOTED_STRING COMMA QUOTED_STRING
#line 1863 "pkg/src/lex_yacc/DynareBison.yy"
                           {
                             (yystack_[2].value.string_val)->insert(0, "''");
                             (yystack_[2].value.string_val)->append("'', ''");
                             (yystack_[2].value.string_val)->append(*(yystack_[0].value.string_val));
                             (yystack_[2].value.string_val)->append("''");
                             (yylhs.value.string_val) = (yystack_[2].value.string_val);
                           }
#line 3343 "pkg/src/DynareBison.cc"
    break;

  case 815: // list_sub_sampling_option: QUOTED_STRING COMMA signed_number
#line 1871 "pkg/src/lex_yacc/DynareBison.yy"
                           {
                             (yystack_[2].value.string_val)->insert(0, "''");
                             (yystack_[2].value.string_val)->append("'',");
                             (yystack_[2].value.string_val)->append(*(yystack_[0].value.string_val));
                             (yylhs.value.string_val) = (yystack_[2].value.string_val);
                           }
#line 3354 "pkg/src/DynareBison.cc"
    break;

  case 816: // sub_sampling_options: list_sub_sampling_option
#line 1880 "pkg/src/lex_yacc/DynareBison.yy"
                       { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 3360 "pkg/src/DynareBison.cc"
    break;

  case 817: // sub_sampling_options: sub_sampling_options COMMA list_sub_sampling_option
#line 1882 "pkg/src/lex_yacc/DynareBison.yy"
                       {
                         (yystack_[2].value.string_val)->append(",");
                         (yystack_[2].value.string_val)->append(*(yystack_[0].value.string_val));
                         (yylhs.value.string_val) = (yystack_[2].value.string_val);
                       }
#line 3370 "pkg/src/DynareBison.cc"
    break;

  case 818: // list_sampling_option: QUOTED_STRING COMMA QUOTED_STRING
#line 1890 "pkg/src/lex_yacc/DynareBison.yy"
                       { driver.sampling_options_string((yystack_[2].value.string_val), (yystack_[0].value.string_val)); }
#line 3376 "pkg/src/DynareBison.cc"
    break;

  case 819: // list_sampling_option: QUOTED_STRING COMMA signed_number
#line 1892 "pkg/src/lex_yacc/DynareBison.yy"
                       { driver.sampling_options_num((yystack_[2].value.string_val), (yystack_[0].value.string_val)); }
#line 3382 "pkg/src/DynareBison.cc"
    break;

  case 820: // list_sampling_option: QUOTED_STRING COMMA '(' sub_sampling_options ')'
#line 1894 "pkg/src/lex_yacc/DynareBison.yy"
                       {
                         (yystack_[1].value.string_val)->insert(0,"(");
                         (yystack_[1].value.string_val)->append(")");
                         driver.sampling_options_string((yystack_[4].value.string_val), (yystack_[1].value.string_val));
                       }
#line 3392 "pkg/src/DynareBison.cc"
    break;

  case 823: // $@19: %empty
#line 1905 "pkg/src/lex_yacc/DynareBison.yy"
                { driver.check_varobs(); }
#line 3398 "pkg/src/DynareBison.cc"
    break;

  case 825: // varobs_list: varobs_list symbol
#line 1908 "pkg/src/lex_yacc/DynareBison.yy"
              { driver.add_varobs((yystack_[0].value.string_val)); }
#line 3404 "pkg/src/DynareBison.cc"
    break;

  case 826: // varobs_list: varobs_list COMMA symbol
#line 1910 "pkg/src/lex_yacc/DynareBison.yy"
              { driver.add_varobs((yystack_[0].value.string_val)); }
#line 3410 "pkg/src/DynareBison.cc"
    break;

  case 827: // varobs_list: symbol
#line 1912 "pkg/src/lex_yacc/DynareBison.yy"
              { driver.add_varobs((yystack_[0].value.string_val)); }
#line 3416 "pkg/src/DynareBison.cc"
    break;

  case 828: // observation_trends: OBSERVATION_TRENDS ';' trend_list END ';'
#line 1915 "pkg/src/lex_yacc/DynareBison.yy"
                                                               { driver.set_trends(); }
#line 3422 "pkg/src/DynareBison.cc"
    break;

  case 831: // trend_element: symbol '(' expression ')' ';'
#line 1921 "pkg/src/lex_yacc/DynareBison.yy"
                                               { driver.set_trend_element((yystack_[4].value.string_val), (yystack_[2].value.node_val)); }
#line 3428 "pkg/src/DynareBison.cc"
    break;

  case 832: // unit_root_vars: UNIT_ROOT_VARS symbol_list ';'
#line 1923 "pkg/src/lex_yacc/DynareBison.yy"
                                                { driver.set_unit_root_vars(); }
#line 3434 "pkg/src/DynareBison.cc"
    break;

  case 833: // optim_weights: OPTIM_WEIGHTS ';' optim_weights_list END ';'
#line 1925 "pkg/src/lex_yacc/DynareBison.yy"
                                                             { driver.optim_weights(); }
#line 3440 "pkg/src/DynareBison.cc"
    break;

  case 834: // optim_weights_list: optim_weights_list symbol expression ';'
#line 1928 "pkg/src/lex_yacc/DynareBison.yy"
                     { driver.set_optim_weights((yystack_[2].value.string_val), (yystack_[1].value.node_val)); }
#line 3446 "pkg/src/DynareBison.cc"
    break;

  case 835: // optim_weights_list: optim_weights_list symbol COMMA symbol expression ';'
#line 1930 "pkg/src/lex_yacc/DynareBison.yy"
                     { driver.set_optim_weights((yystack_[4].value.string_val), (yystack_[2].value.string_val), (yystack_[1].value.node_val)); }
#line 3452 "pkg/src/DynareBison.cc"
    break;

  case 836: // optim_weights_list: symbol expression ';'
#line 1932 "pkg/src/lex_yacc/DynareBison.yy"
                     { driver.set_optim_weights((yystack_[2].value.string_val), (yystack_[1].value.node_val)); }
#line 3458 "pkg/src/DynareBison.cc"
    break;

  case 837: // optim_weights_list: symbol COMMA symbol expression ';'
#line 1934 "pkg/src/lex_yacc/DynareBison.yy"
                     { driver.set_optim_weights((yystack_[4].value.string_val), (yystack_[2].value.string_val), (yystack_[1].value.node_val)); }
#line 3464 "pkg/src/DynareBison.cc"
    break;

  case 838: // osr_params: OSR_PARAMS symbol_list ';'
#line 1937 "pkg/src/lex_yacc/DynareBison.yy"
                                        { driver.set_osr_params(); }
#line 3470 "pkg/src/DynareBison.cc"
    break;

  case 848: // osr: OSR ';'
#line 1954 "pkg/src/lex_yacc/DynareBison.yy"
      { driver.run_osr(); }
#line 3476 "pkg/src/DynareBison.cc"
    break;

  case 849: // osr: OSR '(' osr_options_list ')' ';'
#line 1956 "pkg/src/lex_yacc/DynareBison.yy"
      { driver.run_osr(); }
#line 3482 "pkg/src/DynareBison.cc"
    break;

  case 850: // osr: OSR symbol_list ';'
#line 1958 "pkg/src/lex_yacc/DynareBison.yy"
      { driver.run_osr(); }
#line 3488 "pkg/src/DynareBison.cc"
    break;

  case 851: // osr: OSR '(' osr_options_list ')' symbol_list ';'
#line 1960 "pkg/src/lex_yacc/DynareBison.yy"
      {driver.run_osr(); }
#line 3494 "pkg/src/DynareBison.cc"
    break;

  case 852: // dynatype: DYNATYPE '(' filename ')' ';'
#line 1964 "pkg/src/lex_yacc/DynareBison.yy"
           { driver.run_dynatype((yystack_[2].value.string_val)); }
#line 3500 "pkg/src/DynareBison.cc"
    break;

  case 853: // dynatype: DYNATYPE '(' filename ')' symbol_list ';'
#line 1966 "pkg/src/lex_yacc/DynareBison.yy"
           { driver.run_dynatype((yystack_[3].value.string_val)); }
#line 3506 "pkg/src/DynareBison.cc"
    break;

  case 854: // dynasave: DYNASAVE '(' filename ')' ';'
#line 1970 "pkg/src/lex_yacc/DynareBison.yy"
           { driver.run_dynasave((yystack_[2].value.string_val)); }
#line 3512 "pkg/src/DynareBison.cc"
    break;

  case 855: // dynasave: DYNASAVE '(' filename ')' symbol_list ';'
#line 1972 "pkg/src/lex_yacc/DynareBison.yy"
           { driver.run_dynasave((yystack_[3].value.string_val)); }
#line 3518 "pkg/src/DynareBison.cc"
    break;

  case 856: // load_params_and_steady_state: LOAD_PARAMS_AND_STEADY_STATE '(' filename ')' ';'
#line 1976 "pkg/src/lex_yacc/DynareBison.yy"
                               { driver.run_load_params_and_steady_state((yystack_[2].value.string_val)); }
#line 3524 "pkg/src/DynareBison.cc"
    break;

  case 857: // save_params_and_steady_state: SAVE_PARAMS_AND_STEADY_STATE '(' filename ')' ';'
#line 1980 "pkg/src/lex_yacc/DynareBison.yy"
                               { driver.run_save_params_and_steady_state((yystack_[2].value.string_val)); }
#line 3530 "pkg/src/DynareBison.cc"
    break;

  case 858: // identification: IDENTIFICATION ';'
#line 1984 "pkg/src/lex_yacc/DynareBison.yy"
                 { driver.run_identification(); }
#line 3536 "pkg/src/DynareBison.cc"
    break;

  case 859: // identification: IDENTIFICATION '(' identification_options_list ')' ';'
#line 1986 "pkg/src/lex_yacc/DynareBison.yy"
                 { driver.run_identification(); }
#line 3542 "pkg/src/DynareBison.cc"
    break;

  case 882: // model_comparison: MODEL_COMPARISON mc_filename_list ';'
#line 2016 "pkg/src/lex_yacc/DynareBison.yy"
                   { driver.run_model_comparison(); }
#line 3548 "pkg/src/DynareBison.cc"
    break;

  case 883: // model_comparison: MODEL_COMPARISON '(' o_marginal_density ')' mc_filename_list ';'
#line 2018 "pkg/src/lex_yacc/DynareBison.yy"
                   { driver.run_model_comparison(); }
#line 3554 "pkg/src/DynareBison.cc"
    break;

  case 884: // filename: symbol
#line 2021 "pkg/src/lex_yacc/DynareBison.yy"
           { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 3560 "pkg/src/DynareBison.cc"
    break;

  case 885: // filename: QUOTED_STRING
#line 2022 "pkg/src/lex_yacc/DynareBison.yy"
           { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 3566 "pkg/src/DynareBison.cc"
    break;

  case 886: // parallel_local_filename_list: filename
#line 2026 "pkg/src/lex_yacc/DynareBison.yy"
                               { driver.add_parallel_local_file((yystack_[0].value.string_val)); }
#line 3572 "pkg/src/DynareBison.cc"
    break;

  case 887: // parallel_local_filename_list: parallel_local_filename_list COMMA filename
#line 2028 "pkg/src/lex_yacc/DynareBison.yy"
                               { driver.add_parallel_local_file((yystack_[0].value.string_val)); }
#line 3578 "pkg/src/DynareBison.cc"
    break;

  case 888: // mc_filename_list: filename
#line 2032 "pkg/src/lex_yacc/DynareBison.yy"
                   { driver.add_mc_filename((yystack_[0].value.string_val)); }
#line 3584 "pkg/src/DynareBison.cc"
    break;

  case 889: // mc_filename_list: filename '(' non_negative_number ')'
#line 2034 "pkg/src/lex_yacc/DynareBison.yy"
                   { driver.add_mc_filename((yystack_[3].value.string_val), (yystack_[1].value.string_val)); }
#line 3590 "pkg/src/DynareBison.cc"
    break;

  case 890: // mc_filename_list: mc_filename_list filename
#line 2036 "pkg/src/lex_yacc/DynareBison.yy"
                   { driver.add_mc_filename((yystack_[0].value.string_val)); }
#line 3596 "pkg/src/DynareBison.cc"
    break;

  case 891: // mc_filename_list: mc_filename_list filename '(' non_negative_number ')'
#line 2038 "pkg/src/lex_yacc/DynareBison.yy"
                   { driver.add_mc_filename((yystack_[3].value.string_val), (yystack_[1].value.string_val)); }
#line 3602 "pkg/src/DynareBison.cc"
    break;

  case 892: // mc_filename_list: mc_filename_list COMMA filename
#line 2040 "pkg/src/lex_yacc/DynareBison.yy"
                   { driver.add_mc_filename((yystack_[0].value.string_val)); }
#line 3608 "pkg/src/DynareBison.cc"
    break;

  case 893: // mc_filename_list: mc_filename_list COMMA filename '(' non_negative_number ')'
#line 2042 "pkg/src/lex_yacc/DynareBison.yy"
                   { driver.add_mc_filename((yystack_[3].value.string_val), (yystack_[1].value.string_val)); }
#line 3614 "pkg/src/DynareBison.cc"
    break;

  case 894: // $@20: %empty
#line 2045 "pkg/src/lex_yacc/DynareBison.yy"
                                      { driver.begin_planner_objective(); }
#line 3620 "pkg/src/DynareBison.cc"
    break;

  case 895: // $@21: %empty
#line 2046 "pkg/src/lex_yacc/DynareBison.yy"
                              { driver.end_planner_objective((yystack_[0].value.node_val)); }
#line 3626 "pkg/src/DynareBison.cc"
    break;

  case 897: // ramsey_model: RAMSEY_MODEL ';'
#line 2049 "pkg/src/lex_yacc/DynareBison.yy"
                { driver.ramsey_model(); }
#line 3632 "pkg/src/DynareBison.cc"
    break;

  case 898: // ramsey_model: RAMSEY_MODEL '(' ramsey_model_options_list ')' ';'
#line 2051 "pkg/src/lex_yacc/DynareBison.yy"
                { driver.ramsey_model(); }
#line 3638 "pkg/src/DynareBison.cc"
    break;

  case 899: // ramsey_model: RAMSEY_MODEL symbol_list ';'
#line 2053 "pkg/src/lex_yacc/DynareBison.yy"
                { driver.ramsey_model(); }
#line 3644 "pkg/src/DynareBison.cc"
    break;

  case 900: // ramsey_model: RAMSEY_MODEL '(' ramsey_model_options_list ')' symbol_list ';'
#line 2055 "pkg/src/lex_yacc/DynareBison.yy"
                { driver.ramsey_model(); }
#line 3650 "pkg/src/DynareBison.cc"
    break;

  case 901: // ramsey_policy: RAMSEY_POLICY ';'
#line 2059 "pkg/src/lex_yacc/DynareBison.yy"
                { driver.ramsey_policy(); }
#line 3656 "pkg/src/DynareBison.cc"
    break;

  case 902: // ramsey_policy: RAMSEY_POLICY '(' ramsey_policy_options_list ')' ';'
#line 2061 "pkg/src/lex_yacc/DynareBison.yy"
                { driver.ramsey_policy(); }
#line 3662 "pkg/src/DynareBison.cc"
    break;

  case 903: // ramsey_policy: RAMSEY_POLICY symbol_list ';'
#line 2063 "pkg/src/lex_yacc/DynareBison.yy"
                { driver.ramsey_policy(); }
#line 3668 "pkg/src/DynareBison.cc"
    break;

  case 904: // ramsey_policy: RAMSEY_POLICY '(' ramsey_policy_options_list ')' ramsey_policy_list ';'
#line 2065 "pkg/src/lex_yacc/DynareBison.yy"
                { driver.ramsey_policy(); }
#line 3674 "pkg/src/DynareBison.cc"
    break;

  case 907: // ramsey_policy_element: symbol
#line 2072 "pkg/src/lex_yacc/DynareBison.yy"
                               { driver.add_to_ramsey_policy_list((yystack_[0].value.string_val)); }
#line 3680 "pkg/src/DynareBison.cc"
    break;

  case 908: // ramsey_constraints: RAMSEY_CONSTRAINTS ';' ramsey_constraints_list END ';'
#line 2076 "pkg/src/lex_yacc/DynareBison.yy"
                     { driver.add_ramsey_constraints_statement(); }
#line 3686 "pkg/src/DynareBison.cc"
    break;

  case 911: // ramsey_constraint: NAME LESS expression ';'
#line 2084 "pkg/src/lex_yacc/DynareBison.yy"
                    { driver.ramsey_constraint_add_less((yystack_[3].value.string_val),(yystack_[1].value.node_val)); }
#line 3692 "pkg/src/DynareBison.cc"
    break;

  case 912: // ramsey_constraint: NAME GREATER expression ';'
#line 2086 "pkg/src/lex_yacc/DynareBison.yy"
                    { driver.ramsey_constraint_add_greater((yystack_[3].value.string_val),(yystack_[1].value.node_val)); }
#line 3698 "pkg/src/DynareBison.cc"
    break;

  case 913: // ramsey_constraint: NAME LESS_EQUAL expression ';'
#line 2088 "pkg/src/lex_yacc/DynareBison.yy"
                    { driver.ramsey_constraint_add_less_equal((yystack_[3].value.string_val),(yystack_[1].value.node_val)); }
#line 3704 "pkg/src/DynareBison.cc"
    break;

  case 914: // ramsey_constraint: NAME GREATER_EQUAL expression ';'
#line 2090 "pkg/src/lex_yacc/DynareBison.yy"
                    { driver.ramsey_constraint_add_greater_equal((yystack_[3].value.string_val),(yystack_[1].value.node_val)); }
#line 3710 "pkg/src/DynareBison.cc"
    break;

  case 915: // discretionary_policy: DISCRETIONARY_POLICY ';'
#line 2094 "pkg/src/lex_yacc/DynareBison.yy"
                       { driver.discretionary_policy(); }
#line 3716 "pkg/src/DynareBison.cc"
    break;

  case 916: // discretionary_policy: DISCRETIONARY_POLICY '(' discretionary_policy_options_list ')' ';'
#line 2096 "pkg/src/lex_yacc/DynareBison.yy"
                       { driver.discretionary_policy(); }
#line 3722 "pkg/src/DynareBison.cc"
    break;

  case 917: // discretionary_policy: DISCRETIONARY_POLICY symbol_list ';'
#line 2098 "pkg/src/lex_yacc/DynareBison.yy"
                       { driver.discretionary_policy(); }
#line 3728 "pkg/src/DynareBison.cc"
    break;

  case 918: // discretionary_policy: DISCRETIONARY_POLICY '(' discretionary_policy_options_list ')' symbol_list ';'
#line 2100 "pkg/src/lex_yacc/DynareBison.yy"
                       { driver.discretionary_policy(); }
#line 3734 "pkg/src/DynareBison.cc"
    break;

  case 933: // write_latex_dynamic_model: WRITE_LATEX_DYNAMIC_MODEL ';'
#line 2130 "pkg/src/lex_yacc/DynareBison.yy"
                            { driver.write_latex_dynamic_model(false); }
#line 3740 "pkg/src/DynareBison.cc"
    break;

  case 934: // write_latex_dynamic_model: WRITE_LATEX_DYNAMIC_MODEL '(' WRITE_EQUATION_TAGS ')' ';'
#line 2132 "pkg/src/lex_yacc/DynareBison.yy"
                            { driver.write_latex_dynamic_model(true); }
#line 3746 "pkg/src/DynareBison.cc"
    break;

  case 935: // write_latex_static_model: WRITE_LATEX_STATIC_MODEL ';'
#line 2136 "pkg/src/lex_yacc/DynareBison.yy"
                           { driver.write_latex_static_model(); }
#line 3752 "pkg/src/DynareBison.cc"
    break;

  case 936: // write_latex_original_model: WRITE_LATEX_ORIGINAL_MODEL ';'
#line 2140 "pkg/src/lex_yacc/DynareBison.yy"
                           { driver.write_latex_original_model(); }
#line 3758 "pkg/src/DynareBison.cc"
    break;

  case 937: // shock_decomposition: SHOCK_DECOMPOSITION ';'
#line 2144 "pkg/src/lex_yacc/DynareBison.yy"
                      {driver.shock_decomposition(); }
#line 3764 "pkg/src/DynareBison.cc"
    break;

  case 938: // shock_decomposition: SHOCK_DECOMPOSITION '(' shock_decomposition_options_list ')' ';'
#line 2146 "pkg/src/lex_yacc/DynareBison.yy"
                      { driver.shock_decomposition(); }
#line 3770 "pkg/src/DynareBison.cc"
    break;

  case 939: // shock_decomposition: SHOCK_DECOMPOSITION symbol_list ';'
#line 2148 "pkg/src/lex_yacc/DynareBison.yy"
                      { driver.shock_decomposition(); }
#line 3776 "pkg/src/DynareBison.cc"
    break;

  case 940: // shock_decomposition: SHOCK_DECOMPOSITION '(' shock_decomposition_options_list ')' symbol_list ';'
#line 2150 "pkg/src/lex_yacc/DynareBison.yy"
                      { driver.shock_decomposition(); }
#line 3782 "pkg/src/DynareBison.cc"
    break;

  case 941: // realtime_shock_decomposition: REALTIME_SHOCK_DECOMPOSITION ';'
#line 2154 "pkg/src/lex_yacc/DynareBison.yy"
                               {driver.realtime_shock_decomposition(); }
#line 3788 "pkg/src/DynareBison.cc"
    break;

  case 942: // realtime_shock_decomposition: REALTIME_SHOCK_DECOMPOSITION '(' realtime_shock_decomposition_options_list ')' ';'
#line 2156 "pkg/src/lex_yacc/DynareBison.yy"
                               { driver.realtime_shock_decomposition(); }
#line 3794 "pkg/src/DynareBison.cc"
    break;

  case 943: // realtime_shock_decomposition: REALTIME_SHOCK_DECOMPOSITION symbol_list ';'
#line 2158 "pkg/src/lex_yacc/DynareBison.yy"
                               { driver.realtime_shock_decomposition(); }
#line 3800 "pkg/src/DynareBison.cc"
    break;

  case 944: // realtime_shock_decomposition: REALTIME_SHOCK_DECOMPOSITION '(' realtime_shock_decomposition_options_list ')' symbol_list ';'
#line 2160 "pkg/src/lex_yacc/DynareBison.yy"
                               { driver.realtime_shock_decomposition(); }
#line 3806 "pkg/src/DynareBison.cc"
    break;

  case 945: // plot_shock_decomposition: PLOT_SHOCK_DECOMPOSITION ';'
#line 2164 "pkg/src/lex_yacc/DynareBison.yy"
                           {driver.plot_shock_decomposition(); }
#line 3812 "pkg/src/DynareBison.cc"
    break;

  case 946: // plot_shock_decomposition: PLOT_SHOCK_DECOMPOSITION '(' plot_shock_decomposition_options_list ')' ';'
#line 2166 "pkg/src/lex_yacc/DynareBison.yy"
                           { driver.plot_shock_decomposition(); }
#line 3818 "pkg/src/DynareBison.cc"
    break;

  case 947: // plot_shock_decomposition: PLOT_SHOCK_DECOMPOSITION symbol_list ';'
#line 2168 "pkg/src/lex_yacc/DynareBison.yy"
                           { driver.plot_shock_decomposition(); }
#line 3824 "pkg/src/DynareBison.cc"
    break;

  case 948: // plot_shock_decomposition: PLOT_SHOCK_DECOMPOSITION '(' plot_shock_decomposition_options_list ')' symbol_list ';'
#line 2170 "pkg/src/lex_yacc/DynareBison.yy"
                           { driver.plot_shock_decomposition(); }
#line 3830 "pkg/src/DynareBison.cc"
    break;

  case 949: // initial_condition_decomposition: INITIAL_CONDITION_DECOMPOSITION ';'
#line 2174 "pkg/src/lex_yacc/DynareBison.yy"
                                  {driver.initial_condition_decomposition(); }
#line 3836 "pkg/src/DynareBison.cc"
    break;

  case 950: // initial_condition_decomposition: INITIAL_CONDITION_DECOMPOSITION '(' initial_condition_decomposition_options_list ')' ';'
#line 2176 "pkg/src/lex_yacc/DynareBison.yy"
                                  { driver.initial_condition_decomposition(); }
#line 3842 "pkg/src/DynareBison.cc"
    break;

  case 951: // initial_condition_decomposition: INITIAL_CONDITION_DECOMPOSITION symbol_list ';'
#line 2178 "pkg/src/lex_yacc/DynareBison.yy"
                                  { driver.initial_condition_decomposition(); }
#line 3848 "pkg/src/DynareBison.cc"
    break;

  case 952: // initial_condition_decomposition: INITIAL_CONDITION_DECOMPOSITION '(' initial_condition_decomposition_options_list ')' symbol_list ';'
#line 2180 "pkg/src/lex_yacc/DynareBison.yy"
                                  { driver.initial_condition_decomposition(); }
#line 3854 "pkg/src/DynareBison.cc"
    break;

  case 972: // bvar_density: BVAR_DENSITY INT_NUMBER ';'
#line 2209 "pkg/src/lex_yacc/DynareBison.yy"
               { driver.bvar_density((yystack_[1].value.string_val)); }
#line 3860 "pkg/src/DynareBison.cc"
    break;

  case 973: // bvar_density: BVAR_DENSITY '(' bvar_density_options_list ')' INT_NUMBER ';'
#line 2211 "pkg/src/lex_yacc/DynareBison.yy"
               { driver.bvar_density((yystack_[1].value.string_val)); }
#line 3866 "pkg/src/DynareBison.cc"
    break;

  case 980: // bvar_forecast: BVAR_FORECAST INT_NUMBER ';'
#line 2225 "pkg/src/lex_yacc/DynareBison.yy"
                { driver.bvar_forecast((yystack_[1].value.string_val)); }
#line 3872 "pkg/src/DynareBison.cc"
    break;

  case 981: // bvar_forecast: BVAR_FORECAST '(' bvar_forecast_options_list ')' INT_NUMBER ';'
#line 2227 "pkg/src/lex_yacc/DynareBison.yy"
                { driver.bvar_forecast((yystack_[1].value.string_val)); }
#line 3878 "pkg/src/DynareBison.cc"
    break;

  case 1032: // sbvar: SBVAR ';'
#line 2285 "pkg/src/lex_yacc/DynareBison.yy"
        { driver.sbvar(); }
#line 3884 "pkg/src/DynareBison.cc"
    break;

  case 1033: // sbvar: SBVAR '(' sbvar_options_list ')' ';'
#line 2287 "pkg/src/lex_yacc/DynareBison.yy"
        { driver.sbvar(); }
#line 3890 "pkg/src/DynareBison.cc"
    break;

  case 1050: // ms_variance_decomposition: MS_VARIANCE_DECOMPOSITION ';'
#line 2311 "pkg/src/lex_yacc/DynareBison.yy"
                            { driver.ms_variance_decomposition(); }
#line 3896 "pkg/src/DynareBison.cc"
    break;

  case 1051: // ms_variance_decomposition: MS_VARIANCE_DECOMPOSITION '(' ms_variance_decomposition_options_list ')' ';'
#line 2313 "pkg/src/lex_yacc/DynareBison.yy"
                            { driver.ms_variance_decomposition(); }
#line 3902 "pkg/src/DynareBison.cc"
    break;

  case 1068: // ms_forecast: MS_FORECAST ';'
#line 2337 "pkg/src/lex_yacc/DynareBison.yy"
              { driver.ms_forecast(); }
#line 3908 "pkg/src/DynareBison.cc"
    break;

  case 1069: // ms_forecast: MS_FORECAST '(' ms_forecast_options_list ')' ';'
#line 2339 "pkg/src/lex_yacc/DynareBison.yy"
              { driver.ms_forecast(); }
#line 3914 "pkg/src/DynareBison.cc"
    break;

  case 1086: // ms_irf: MS_IRF ';'
#line 2363 "pkg/src/lex_yacc/DynareBison.yy"
         { driver.ms_irf(); }
#line 3920 "pkg/src/DynareBison.cc"
    break;

  case 1087: // ms_irf: MS_IRF '(' ms_irf_options_list ')' ';'
#line 2365 "pkg/src/lex_yacc/DynareBison.yy"
         { driver.ms_irf(); }
#line 3926 "pkg/src/DynareBison.cc"
    break;

  case 1088: // ms_irf: MS_IRF symbol_list ';'
#line 2367 "pkg/src/lex_yacc/DynareBison.yy"
         { driver.ms_irf(); }
#line 3932 "pkg/src/DynareBison.cc"
    break;

  case 1089: // ms_irf: MS_IRF '(' ms_irf_options_list ')' symbol_list ';'
#line 2369 "pkg/src/lex_yacc/DynareBison.yy"
         { driver.ms_irf(); }
#line 3938 "pkg/src/DynareBison.cc"
    break;

  case 1096: // ms_compute_probabilities: MS_COMPUTE_PROBABILITIES ';'
#line 2383 "pkg/src/lex_yacc/DynareBison.yy"
                           { driver.ms_compute_probabilities(); }
#line 3944 "pkg/src/DynareBison.cc"
    break;

  case 1097: // ms_compute_probabilities: MS_COMPUTE_PROBABILITIES '(' ms_compute_probabilities_options_list ')' ';'
#line 2385 "pkg/src/lex_yacc/DynareBison.yy"
                           { driver.ms_compute_probabilities(); }
#line 3950 "pkg/src/DynareBison.cc"
    break;

  case 1108: // ms_compute_mdd: MS_COMPUTE_MDD ';'
#line 2403 "pkg/src/lex_yacc/DynareBison.yy"
                 { driver.ms_compute_mdd(); }
#line 3956 "pkg/src/DynareBison.cc"
    break;

  case 1109: // ms_compute_mdd: MS_COMPUTE_MDD '(' ms_compute_mdd_options_list ')' ';'
#line 2405 "pkg/src/lex_yacc/DynareBison.yy"
                 { driver.ms_compute_mdd(); }
#line 3962 "pkg/src/DynareBison.cc"
    break;

  case 1119: // ms_simulation: MS_SIMULATION ';'
#line 2422 "pkg/src/lex_yacc/DynareBison.yy"
                { driver.ms_simulation(); }
#line 3968 "pkg/src/DynareBison.cc"
    break;

  case 1120: // ms_simulation: MS_SIMULATION '(' ms_simulation_options_list ')' ';'
#line 2424 "pkg/src/lex_yacc/DynareBison.yy"
                { driver.ms_simulation(); }
#line 3974 "pkg/src/DynareBison.cc"
    break;

  case 1158: // ms_estimation: MS_ESTIMATION ';'
#line 2469 "pkg/src/lex_yacc/DynareBison.yy"
                { driver.ms_estimation(); }
#line 3980 "pkg/src/DynareBison.cc"
    break;

  case 1159: // ms_estimation: MS_ESTIMATION '(' ms_estimation_options_list ')' ';'
#line 2471 "pkg/src/lex_yacc/DynareBison.yy"
                { driver.ms_estimation(); }
#line 3986 "pkg/src/DynareBison.cc"
    break;

  case 1160: // dynare_sensitivity: DYNARE_SENSITIVITY ';'
#line 2475 "pkg/src/lex_yacc/DynareBison.yy"
                     { driver.dynare_sensitivity(); }
#line 3992 "pkg/src/DynareBison.cc"
    break;

  case 1161: // dynare_sensitivity: DYNARE_SENSITIVITY '(' dynare_sensitivity_options_list ')' ';'
#line 2477 "pkg/src/lex_yacc/DynareBison.yy"
                     { driver.dynare_sensitivity(); }
#line 3998 "pkg/src/DynareBison.cc"
    break;

  case 1262: // homotopy_setup: HOMOTOPY_SETUP ';' homotopy_list END ';'
#line 2601 "pkg/src/lex_yacc/DynareBison.yy"
               { driver.end_homotopy();}
#line 4004 "pkg/src/DynareBison.cc"
    break;

  case 1265: // homotopy_item: symbol COMMA expression COMMA expression ';'
#line 2608 "pkg/src/lex_yacc/DynareBison.yy"
                { driver.homotopy_val((yystack_[5].value.string_val), (yystack_[3].value.node_val), (yystack_[1].value.node_val));}
#line 4010 "pkg/src/DynareBison.cc"
    break;

  case 1266: // homotopy_item: symbol COMMA expression ';'
#line 2610 "pkg/src/lex_yacc/DynareBison.yy"
                { driver.homotopy_val((yystack_[3].value.string_val), NULL, (yystack_[1].value.node_val));}
#line 4016 "pkg/src/DynareBison.cc"
    break;

  case 1267: // forecast: FORECAST ';'
#line 2613 "pkg/src/lex_yacc/DynareBison.yy"
                       {driver.forecast();}
#line 4022 "pkg/src/DynareBison.cc"
    break;

  case 1268: // forecast: FORECAST '(' forecast_options ')' ';'
#line 2614 "pkg/src/lex_yacc/DynareBison.yy"
                                                  {driver.forecast();}
#line 4028 "pkg/src/DynareBison.cc"
    break;

  case 1269: // forecast: FORECAST symbol_list ';'
#line 2615 "pkg/src/lex_yacc/DynareBison.yy"
                                     {driver.forecast();}
#line 4034 "pkg/src/DynareBison.cc"
    break;

  case 1270: // forecast: FORECAST '(' forecast_options ')' symbol_list ';'
#line 2616 "pkg/src/lex_yacc/DynareBison.yy"
                                                              {driver.forecast();}
#line 4040 "pkg/src/DynareBison.cc"
    break;

  case 1278: // conditional_forecast: CONDITIONAL_FORECAST '(' conditional_forecast_options ')' ';'
#line 2631 "pkg/src/lex_yacc/DynareBison.yy"
                       { driver.conditional_forecast(); }
#line 4046 "pkg/src/DynareBison.cc"
    break;

  case 1286: // plot_conditional_forecast: PLOT_CONDITIONAL_FORECAST symbol_list ';'
#line 2646 "pkg/src/lex_yacc/DynareBison.yy"
                            { driver.plot_conditional_forecast(); }
#line 4052 "pkg/src/DynareBison.cc"
    break;

  case 1287: // plot_conditional_forecast: PLOT_CONDITIONAL_FORECAST '(' PERIODS EQUAL INT_NUMBER ')' symbol_list ';'
#line 2648 "pkg/src/lex_yacc/DynareBison.yy"
                            { driver.plot_conditional_forecast((yystack_[3].value.string_val)); }
#line 4058 "pkg/src/DynareBison.cc"
    break;

  case 1288: // conditional_forecast_paths: CONDITIONAL_FORECAST_PATHS ';' conditional_forecast_paths_shock_list END ';'
#line 2652 "pkg/src/lex_yacc/DynareBison.yy"
                             { driver.conditional_forecast_paths(); }
#line 4064 "pkg/src/DynareBison.cc"
    break;

  case 1291: // conditional_forecast_paths_shock_elem: VAR symbol ';' PERIODS period_list ';' VALUES value_list ';'
#line 2660 "pkg/src/lex_yacc/DynareBison.yy"
                                        { driver.add_det_shock((yystack_[7].value.string_val), true); }
#line 4070 "pkg/src/DynareBison.cc"
    break;

  case 1292: // $@22: %empty
#line 2663 "pkg/src/lex_yacc/DynareBison.yy"
                                            { driver.begin_steady_state_model(); }
#line 4076 "pkg/src/DynareBison.cc"
    break;

  case 1293: // steady_state_model: STEADY_STATE_MODEL ';' $@22 steady_state_equation_list END ';'
#line 2664 "pkg/src/lex_yacc/DynareBison.yy"
                                                        { driver.reset_data_tree(); }
#line 4082 "pkg/src/DynareBison.cc"
    break;

  case 1296: // steady_state_equation: symbol EQUAL expression ';'
#line 2672 "pkg/src/lex_yacc/DynareBison.yy"
                        { driver.add_steady_state_model_equal((yystack_[3].value.string_val), (yystack_[1].value.node_val)); }
#line 4088 "pkg/src/DynareBison.cc"
    break;

  case 1297: // steady_state_equation: '[' symbol_list ']' EQUAL expression ';'
#line 2674 "pkg/src/lex_yacc/DynareBison.yy"
                        { driver.add_steady_state_model_equal_multiple((yystack_[1].value.node_val)); }
#line 4094 "pkg/src/DynareBison.cc"
    break;

  case 1298: // calib_smoother: CALIB_SMOOTHER ';'
#line 2678 "pkg/src/lex_yacc/DynareBison.yy"
                 { driver.calib_smoother(); }
#line 4100 "pkg/src/DynareBison.cc"
    break;

  case 1299: // calib_smoother: CALIB_SMOOTHER '(' calib_smoother_options_list ')' ';'
#line 2680 "pkg/src/lex_yacc/DynareBison.yy"
                 { driver.calib_smoother(); }
#line 4106 "pkg/src/DynareBison.cc"
    break;

  case 1300: // calib_smoother: CALIB_SMOOTHER symbol_list ';'
#line 2682 "pkg/src/lex_yacc/DynareBison.yy"
                 { driver.calib_smoother(); }
#line 4112 "pkg/src/DynareBison.cc"
    break;

  case 1301: // calib_smoother: CALIB_SMOOTHER '(' calib_smoother_options_list ')' symbol_list ';'
#line 2684 "pkg/src/lex_yacc/DynareBison.yy"
                 { driver.calib_smoother(); }
#line 4118 "pkg/src/DynareBison.cc"
    break;

  case 1314: // extended_path: EXTENDED_PATH ';'
#line 2704 "pkg/src/lex_yacc/DynareBison.yy"
                { driver.extended_path(); }
#line 4124 "pkg/src/DynareBison.cc"
    break;

  case 1315: // extended_path: EXTENDED_PATH '(' extended_path_options_list ')' ';'
#line 2706 "pkg/src/lex_yacc/DynareBison.yy"
                { driver.extended_path(); }
#line 4130 "pkg/src/DynareBison.cc"
    break;

  case 1323: // model_diagnostics: MODEL_DIAGNOSTICS ';'
#line 2721 "pkg/src/lex_yacc/DynareBison.yy"
                    { driver.model_diagnostics(); }
#line 4136 "pkg/src/DynareBison.cc"
    break;

  case 1324: // calibration_range: '[' signed_number_w_inf signed_number_w_inf ']'
#line 2725 "pkg/src/lex_yacc/DynareBison.yy"
                    {
                      (yylhs.value.vector_string_val) = new vector<string *>();
                      (yylhs.value.vector_string_val)->push_back((yystack_[2].value.string_val));
                      (yylhs.value.vector_string_val)->push_back((yystack_[1].value.string_val));
                    }
#line 4146 "pkg/src/DynareBison.cc"
    break;

  case 1325: // calibration_range: '[' signed_number_w_inf COMMA signed_number_w_inf ']'
#line 2731 "pkg/src/lex_yacc/DynareBison.yy"
                    {
                      (yylhs.value.vector_string_val) = new vector<string *>();
                      (yylhs.value.vector_string_val)->push_back((yystack_[3].value.string_val));
                      (yylhs.value.vector_string_val)->push_back((yystack_[1].value.string_val));
                    }
#line 4156 "pkg/src/DynareBison.cc"
    break;

  case 1326: // calibration_range: PLUS
#line 2737 "pkg/src/lex_yacc/DynareBison.yy"
                    {
                      (yylhs.value.vector_string_val) = new vector<string *>();
                      (yylhs.value.vector_string_val)->push_back(new string("0"));
                      (yylhs.value.vector_string_val)->push_back(new string("inf"));
                    }
#line 4166 "pkg/src/DynareBison.cc"
    break;

  case 1327: // calibration_range: MINUS
#line 2743 "pkg/src/lex_yacc/DynareBison.yy"
                    {
                      (yylhs.value.vector_string_val) = new vector<string *>();
                      (yylhs.value.vector_string_val)->push_back(new string("-inf"));
                      (yylhs.value.vector_string_val)->push_back(new string("0"));
                    }
#line 4176 "pkg/src/DynareBison.cc"
    break;

  case 1328: // moment_calibration: MOMENT_CALIBRATION ';' moment_calibration_list END ';'
#line 2751 "pkg/src/lex_yacc/DynareBison.yy"
                     { driver.end_moment_calibration(); }
#line 4182 "pkg/src/DynareBison.cc"
    break;

  case 1331: // moment_calibration_item: symbol COMMA symbol COMMA calibration_range ';'
#line 2759 "pkg/src/lex_yacc/DynareBison.yy"
                          { driver.add_moment_calibration_item((yystack_[5].value.string_val), (yystack_[3].value.string_val), new string("0"), (yystack_[1].value.vector_string_val)); }
#line 4188 "pkg/src/DynareBison.cc"
    break;

  case 1332: // moment_calibration_item: symbol COMMA symbol '(' signed_integer ')' COMMA calibration_range ';'
#line 2761 "pkg/src/lex_yacc/DynareBison.yy"
                          { driver.add_moment_calibration_item((yystack_[8].value.string_val), (yystack_[6].value.string_val), (yystack_[4].value.string_val), (yystack_[1].value.vector_string_val)); }
#line 4194 "pkg/src/DynareBison.cc"
    break;

  case 1333: // moment_calibration_item: symbol COMMA symbol '(' signed_integer_range ')' COMMA calibration_range ';'
#line 2763 "pkg/src/lex_yacc/DynareBison.yy"
                          { driver.add_moment_calibration_item((yystack_[8].value.string_val), (yystack_[6].value.string_val), (yystack_[4].value.string_val), (yystack_[1].value.vector_string_val)); }
#line 4200 "pkg/src/DynareBison.cc"
    break;

  case 1334: // irf_calibration: IRF_CALIBRATION ';' irf_calibration_list END ';'
#line 2767 "pkg/src/lex_yacc/DynareBison.yy"
                  { driver.end_irf_calibration(); }
#line 4206 "pkg/src/DynareBison.cc"
    break;

  case 1335: // irf_calibration: IRF_CALIBRATION '(' o_relative_irf ')' ';' irf_calibration_list END ';'
#line 2769 "pkg/src/lex_yacc/DynareBison.yy"
                  { driver.end_irf_calibration(); }
#line 4212 "pkg/src/DynareBison.cc"
    break;

  case 1338: // irf_calibration_item: symbol COMMA symbol COMMA calibration_range ';'
#line 2777 "pkg/src/lex_yacc/DynareBison.yy"
                       { driver.add_irf_calibration_item((yystack_[5].value.string_val), new string("1"), (yystack_[3].value.string_val), (yystack_[1].value.vector_string_val)); }
#line 4218 "pkg/src/DynareBison.cc"
    break;

  case 1339: // irf_calibration_item: symbol '(' INT_NUMBER ')' COMMA symbol COMMA calibration_range ';'
#line 2779 "pkg/src/lex_yacc/DynareBison.yy"
                       { driver.add_irf_calibration_item((yystack_[8].value.string_val), (yystack_[6].value.string_val), (yystack_[3].value.string_val), (yystack_[1].value.vector_string_val)); }
#line 4224 "pkg/src/DynareBison.cc"
    break;

  case 1340: // irf_calibration_item: symbol '(' integer_range ')' COMMA symbol COMMA calibration_range ';'
#line 2781 "pkg/src/lex_yacc/DynareBison.yy"
                       { driver.add_irf_calibration_item((yystack_[8].value.string_val), (yystack_[6].value.string_val), (yystack_[3].value.string_val), (yystack_[1].value.vector_string_val)); }
#line 4230 "pkg/src/DynareBison.cc"
    break;

  case 1341: // smoother2histval: SMOOTHER2HISTVAL ';'
#line 2785 "pkg/src/lex_yacc/DynareBison.yy"
                   { driver.smoother2histval(); }
#line 4236 "pkg/src/DynareBison.cc"
    break;

  case 1342: // smoother2histval: SMOOTHER2HISTVAL '(' smoother2histval_options_list ')' ';'
#line 2787 "pkg/src/lex_yacc/DynareBison.yy"
                   { driver.smoother2histval(); }
#line 4242 "pkg/src/DynareBison.cc"
    break;

  case 1350: // shock_groups: SHOCK_GROUPS ';' shock_group_list END ';'
#line 2801 "pkg/src/lex_yacc/DynareBison.yy"
                                                        {driver.end_shock_groups(new string("default"));}
#line 4248 "pkg/src/DynareBison.cc"
    break;

  case 1351: // shock_groups: SHOCK_GROUPS '(' NAME EQUAL symbol ')' ';' shock_group_list END ';'
#line 2803 "pkg/src/lex_yacc/DynareBison.yy"
               {driver.end_shock_groups((yystack_[5].value.string_val));}
#line 4254 "pkg/src/DynareBison.cc"
    break;

  case 1354: // shock_group_element: symbol EQUAL shock_name_list ';'
#line 2810 "pkg/src/lex_yacc/DynareBison.yy"
                                                       { driver.add_shock_group((yystack_[3].value.string_val)); }
#line 4260 "pkg/src/DynareBison.cc"
    break;

  case 1355: // shock_group_element: QUOTED_STRING EQUAL shock_name_list ';'
#line 2811 "pkg/src/lex_yacc/DynareBison.yy"
                                                              { driver.add_shock_group((yystack_[3].value.string_val)); }
#line 4266 "pkg/src/DynareBison.cc"
    break;

  case 1356: // shock_name_list: shock_name_list COMMA symbol
#line 2814 "pkg/src/lex_yacc/DynareBison.yy"
                                               {driver.add_shock_group_element((yystack_[0].value.string_val));}
#line 4272 "pkg/src/DynareBison.cc"
    break;

  case 1357: // shock_name_list: shock_name_list symbol
#line 2815 "pkg/src/lex_yacc/DynareBison.yy"
                                         {driver.add_shock_group_element((yystack_[0].value.string_val));}
#line 4278 "pkg/src/DynareBison.cc"
    break;

  case 1358: // shock_name_list: symbol
#line 2816 "pkg/src/lex_yacc/DynareBison.yy"
                         {driver.add_shock_group_element((yystack_[0].value.string_val));}
#line 4284 "pkg/src/DynareBison.cc"
    break;

  case 1359: // o_dr_algo: DR_ALGO EQUAL INT_NUMBER
#line 2819 "pkg/src/lex_yacc/DynareBison.yy"
                                     {
                                       if (*(yystack_[0].value.string_val) == string("0"))
                                         driver.warning("dr_algo option is now deprecated, and may be removed in a future version of Dynare");
                                       else
                                         driver.error("dr_algo=1 option is no longer supported");
                                     }
#line 4295 "pkg/src/DynareBison.cc"
    break;

  case 1360: // o_solve_algo: SOLVE_ALGO EQUAL INT_NUMBER
#line 2825 "pkg/src/lex_yacc/DynareBison.yy"
                                           { driver.option_num("solve_algo", (yystack_[0].value.string_val)); }
#line 4301 "pkg/src/DynareBison.cc"
    break;

  case 1361: // o_simul_algo: SIMUL_ALGO EQUAL INT_NUMBER
#line 2826 "pkg/src/lex_yacc/DynareBison.yy"
                                           {
                                             if (*(yystack_[0].value.string_val) == string("0"))
                                               driver.warning("simul_algo option is now deprecated, and may be removed in a future version of Dynare");
                                             else
                                               driver.error("simul_algo=1 option is no longer supported");
                                           }
#line 4312 "pkg/src/DynareBison.cc"
    break;

  case 1362: // o_stack_solve_algo: STACK_SOLVE_ALGO EQUAL INT_NUMBER
#line 2832 "pkg/src/lex_yacc/DynareBison.yy"
                                                       { driver.option_num("stack_solve_algo", (yystack_[0].value.string_val)); }
#line 4318 "pkg/src/DynareBison.cc"
    break;

  case 1363: // o_robust_lin_solve: ROBUST_LIN_SOLVE
#line 2833 "pkg/src/lex_yacc/DynareBison.yy"
                                      { driver.option_num("simul.robust_lin_solve", "1"); }
#line 4324 "pkg/src/DynareBison.cc"
    break;

  case 1364: // o_endogenous_terminal_period: ENDOGENOUS_TERMINAL_PERIOD
#line 2834 "pkg/src/lex_yacc/DynareBison.yy"
                                                          { driver.option_num("endogenous_terminal_period", "1"); }
#line 4330 "pkg/src/DynareBison.cc"
    break;

  case 1365: // o_linear: LINEAR
#line 2835 "pkg/src/lex_yacc/DynareBison.yy"
                  { driver.linear(); }
#line 4336 "pkg/src/DynareBison.cc"
    break;

  case 1366: // o_order: ORDER EQUAL INT_NUMBER
#line 2836 "pkg/src/lex_yacc/DynareBison.yy"
                                 { driver.option_num("order", (yystack_[0].value.string_val)); }
#line 4342 "pkg/src/DynareBison.cc"
    break;

  case 1367: // o_replic: REPLIC EQUAL INT_NUMBER
#line 2837 "pkg/src/lex_yacc/DynareBison.yy"
                                   { driver.option_num("replic", (yystack_[0].value.string_val)); }
#line 4348 "pkg/src/DynareBison.cc"
    break;

  case 1368: // o_drop: DROP EQUAL INT_NUMBER
#line 2838 "pkg/src/lex_yacc/DynareBison.yy"
                               { driver.option_num("drop", (yystack_[0].value.string_val)); }
#line 4354 "pkg/src/DynareBison.cc"
    break;

  case 1369: // o_ar: AR EQUAL INT_NUMBER
#line 2839 "pkg/src/lex_yacc/DynareBison.yy"
                           { driver.option_num("ar", (yystack_[0].value.string_val)); }
#line 4360 "pkg/src/DynareBison.cc"
    break;

  case 1370: // o_nocorr: NOCORR
#line 2840 "pkg/src/lex_yacc/DynareBison.yy"
                  { driver.option_num("nocorr", "1"); }
#line 4366 "pkg/src/DynareBison.cc"
    break;

  case 1371: // o_nofunctions: NOFUNCTIONS
#line 2841 "pkg/src/lex_yacc/DynareBison.yy"
                            { driver.option_num("nofunctions", "1"); }
#line 4372 "pkg/src/DynareBison.cc"
    break;

  case 1372: // o_nomoments: NOMOMENTS
#line 2842 "pkg/src/lex_yacc/DynareBison.yy"
                        { driver.option_num("nomoments", "1"); }
#line 4378 "pkg/src/DynareBison.cc"
    break;

  case 1373: // o_irf: IRF EQUAL INT_NUMBER
#line 2843 "pkg/src/lex_yacc/DynareBison.yy"
                             { driver.option_num("irf", (yystack_[0].value.string_val)); }
#line 4384 "pkg/src/DynareBison.cc"
    break;

  case 1374: // o_irf_shocks: IRF_SHOCKS EQUAL '(' symbol_list ')'
#line 2844 "pkg/src/lex_yacc/DynareBison.yy"
                                                    { driver.option_symbol_list("irf_shocks"); }
#line 4390 "pkg/src/DynareBison.cc"
    break;

  case 1375: // o_hp_filter: HP_FILTER EQUAL non_negative_number
#line 2845 "pkg/src/lex_yacc/DynareBison.yy"
                                                  { driver.option_num("hp_filter", (yystack_[0].value.string_val)); }
#line 4396 "pkg/src/DynareBison.cc"
    break;

  case 1376: // o_hp_ngrid: HP_NGRID EQUAL INT_NUMBER
#line 2846 "pkg/src/lex_yacc/DynareBison.yy"
                                       { driver.option_num("hp_ngrid", (yystack_[0].value.string_val)); }
#line 4402 "pkg/src/DynareBison.cc"
    break;

  case 1377: // o_one_sided_hp_filter: ONE_SIDED_HP_FILTER EQUAL non_negative_number
#line 2847 "pkg/src/lex_yacc/DynareBison.yy"
                                                                      { driver.option_num("one_sided_hp_filter", (yystack_[0].value.string_val)); }
#line 4408 "pkg/src/DynareBison.cc"
    break;

  case 1378: // o_periods: PERIODS EQUAL INT_NUMBER
#line 2848 "pkg/src/lex_yacc/DynareBison.yy"
                                     { driver.option_num("periods", (yystack_[0].value.string_val)); }
#line 4414 "pkg/src/DynareBison.cc"
    break;

  case 1379: // o_solver_periods: SOLVER_PERIODS EQUAL INT_NUMBER
#line 2849 "pkg/src/lex_yacc/DynareBison.yy"
                                                   { driver.option_num("ep.periods", (yystack_[0].value.string_val)); }
#line 4420 "pkg/src/DynareBison.cc"
    break;

  case 1380: // o_extended_path_order: ORDER EQUAL INT_NUMBER
#line 2850 "pkg/src/lex_yacc/DynareBison.yy"
                                               { driver.option_num("ep.stochastic.order", (yystack_[0].value.string_val)); }
#line 4426 "pkg/src/DynareBison.cc"
    break;

  case 1381: // o_hybrid: HYBRID
#line 2851 "pkg/src/lex_yacc/DynareBison.yy"
                  { driver.option_num("ep.stochastic.hybrid_order", "2"); }
#line 4432 "pkg/src/DynareBison.cc"
    break;

  case 1382: // o_steady_maxit: MAXIT EQUAL INT_NUMBER
#line 2852 "pkg/src/lex_yacc/DynareBison.yy"
                                        { driver.option_num("steady.maxit", (yystack_[0].value.string_val)); }
#line 4438 "pkg/src/DynareBison.cc"
    break;

  case 1383: // o_simul_maxit: MAXIT EQUAL INT_NUMBER
#line 2853 "pkg/src/lex_yacc/DynareBison.yy"
                                       { driver.option_num("simul.maxit", (yystack_[0].value.string_val)); }
#line 4444 "pkg/src/DynareBison.cc"
    break;

  case 1384: // o_bandpass_filter: BANDPASS_FILTER
#line 2854 "pkg/src/lex_yacc/DynareBison.yy"
                                    { driver.option_num("bandpass.indicator", "1"); }
#line 4450 "pkg/src/DynareBison.cc"
    break;

  case 1385: // o_bandpass_filter: BANDPASS_FILTER EQUAL vec_int
#line 2856 "pkg/src/lex_yacc/DynareBison.yy"
                    {
                      driver.option_num("bandpass.indicator", "1");
                      driver.option_vec_int("bandpass.passband", (yystack_[0].value.vector_int_val));
                    }
#line 4459 "pkg/src/DynareBison.cc"
    break;

  case 1386: // o_dp_maxit: MAXIT EQUAL INT_NUMBER
#line 2861 "pkg/src/lex_yacc/DynareBison.yy"
                                    { driver.option_num("dp.maxit", (yystack_[0].value.string_val)); }
#line 4465 "pkg/src/DynareBison.cc"
    break;

  case 1387: // o_osr_maxit: MAXIT EQUAL INT_NUMBER
#line 2862 "pkg/src/lex_yacc/DynareBison.yy"
                                     { driver.option_num("osr.maxit", (yystack_[0].value.string_val)); }
#line 4471 "pkg/src/DynareBison.cc"
    break;

  case 1388: // o_osr_tolf: TOLF EQUAL non_negative_number
#line 2863 "pkg/src/lex_yacc/DynareBison.yy"
                                            { driver.option_num("osr.tolf", (yystack_[0].value.string_val)); }
#line 4477 "pkg/src/DynareBison.cc"
    break;

  case 1389: // o_pf_tolf: TOLF EQUAL non_negative_number
#line 2864 "pkg/src/lex_yacc/DynareBison.yy"
                                           { driver.option_num("dynatol.f", (yystack_[0].value.string_val)); }
#line 4483 "pkg/src/DynareBison.cc"
    break;

  case 1390: // o_pf_tolx: TOLX EQUAL non_negative_number
#line 2865 "pkg/src/lex_yacc/DynareBison.yy"
                                           { driver.option_num("dynatol.x", (yystack_[0].value.string_val)); }
#line 4489 "pkg/src/DynareBison.cc"
    break;

  case 1391: // o_steady_tolf: TOLF EQUAL non_negative_number
#line 2866 "pkg/src/lex_yacc/DynareBison.yy"
                                               { driver.option_num("solve_tolf", (yystack_[0].value.string_val)); }
#line 4495 "pkg/src/DynareBison.cc"
    break;

  case 1392: // o_opt_algo: OPT_ALGO EQUAL INT_NUMBER
#line 2867 "pkg/src/lex_yacc/DynareBison.yy"
                                       { driver.option_num("osr.opt_algo", (yystack_[0].value.string_val)); }
#line 4501 "pkg/src/DynareBison.cc"
    break;

  case 1393: // o_opt_algo: OPT_ALGO EQUAL filename
#line 2868 "pkg/src/lex_yacc/DynareBison.yy"
                                     { driver.option_str("osr.opt_algo", (yystack_[0].value.string_val)); }
#line 4507 "pkg/src/DynareBison.cc"
    break;

  case 1394: // o_cutoff: CUTOFF EQUAL non_negative_number
#line 2870 "pkg/src/lex_yacc/DynareBison.yy"
                                            { driver.cutoff((yystack_[0].value.string_val)); }
#line 4513 "pkg/src/DynareBison.cc"
    break;

  case 1395: // o_markowitz: MARKOWITZ EQUAL non_negative_number
#line 2871 "pkg/src/lex_yacc/DynareBison.yy"
                                                  { driver.option_num("markowitz", (yystack_[0].value.string_val)); }
#line 4519 "pkg/src/DynareBison.cc"
    break;

  case 1396: // o_minimal_solving_periods: MINIMAL_SOLVING_PERIODS EQUAL non_negative_number
#line 2872 "pkg/src/lex_yacc/DynareBison.yy"
                                                                              { driver.option_num("minimal_solving_periods", (yystack_[0].value.string_val)); }
#line 4525 "pkg/src/DynareBison.cc"
    break;

  case 1397: // o_mfs: MFS EQUAL INT_NUMBER
#line 2873 "pkg/src/lex_yacc/DynareBison.yy"
                             { driver.mfs((yystack_[0].value.string_val)); }
#line 4531 "pkg/src/DynareBison.cc"
    break;

  case 1399: // o_simul_replic: SIMUL_REPLIC EQUAL INT_NUMBER
#line 2875 "pkg/src/lex_yacc/DynareBison.yy"
                                               { driver.option_num("simul_replic", (yystack_[0].value.string_val)); }
#line 4537 "pkg/src/DynareBison.cc"
    break;

  case 1400: // o_simul_seed: SIMUL_SEED EQUAL INT_NUMBER
#line 2876 "pkg/src/lex_yacc/DynareBison.yy"
                                           { driver.error("'simul_seed' option is no longer supported; use 'set_dynare_seed' command instead"); }
#line 4543 "pkg/src/DynareBison.cc"
    break;

  case 1401: // o_qz_criterium: QZ_CRITERIUM EQUAL non_negative_number
#line 2877 "pkg/src/lex_yacc/DynareBison.yy"
                                                        { driver.option_num("qz_criterium", (yystack_[0].value.string_val)); }
#line 4549 "pkg/src/DynareBison.cc"
    break;

  case 1402: // o_qz_zero_threshold: QZ_ZERO_THRESHOLD EQUAL non_negative_number
#line 2878 "pkg/src/lex_yacc/DynareBison.yy"
                                                                  { driver.option_num("qz_zero_threshold", (yystack_[0].value.string_val)); }
#line 4555 "pkg/src/DynareBison.cc"
    break;

  case 1403: // o_file: FILE EQUAL filename
#line 2879 "pkg/src/lex_yacc/DynareBison.yy"
                             { driver.option_str("file", (yystack_[0].value.string_val)); }
#line 4561 "pkg/src/DynareBison.cc"
    break;

  case 1404: // o_series: SERIES EQUAL symbol
#line 2880 "pkg/src/lex_yacc/DynareBison.yy"
                               { driver.option_str("series", (yystack_[0].value.string_val)); }
#line 4567 "pkg/src/DynareBison.cc"
    break;

  case 1405: // o_datafile: DATAFILE EQUAL filename
#line 2881 "pkg/src/lex_yacc/DynareBison.yy"
                                     { driver.option_str("datafile", (yystack_[0].value.string_val)); }
#line 4573 "pkg/src/DynareBison.cc"
    break;

  case 1406: // o_dirname: DIRNAME EQUAL filename
#line 2882 "pkg/src/lex_yacc/DynareBison.yy"
                                   { driver.option_str("dirname", (yystack_[0].value.string_val)); }
#line 4579 "pkg/src/DynareBison.cc"
    break;

  case 1407: // o_huge_number: HUGE_NUMBER EQUAL non_negative_number
#line 2883 "pkg/src/lex_yacc/DynareBison.yy"
                                                      { driver.option_num("huge_number", (yystack_[0].value.string_val)); }
#line 4585 "pkg/src/DynareBison.cc"
    break;

  case 1408: // o_nobs: NOBS EQUAL vec_int
#line 2885 "pkg/src/lex_yacc/DynareBison.yy"
         { driver.option_vec_int("nobs", (yystack_[0].value.vector_int_val)); }
#line 4591 "pkg/src/DynareBison.cc"
    break;

  case 1409: // o_nobs: NOBS EQUAL vec_int_number
#line 2887 "pkg/src/lex_yacc/DynareBison.yy"
         { driver.option_vec_int("nobs", (yystack_[0].value.vector_int_val)); }
#line 4597 "pkg/src/DynareBison.cc"
    break;

  case 1410: // o_conditional_variance_decomposition: CONDITIONAL_VARIANCE_DECOMPOSITION EQUAL vec_int
#line 2890 "pkg/src/lex_yacc/DynareBison.yy"
                                       { driver.option_vec_int("conditional_variance_decomposition", (yystack_[0].value.vector_int_val)); }
#line 4603 "pkg/src/DynareBison.cc"
    break;

  case 1411: // o_conditional_variance_decomposition: CONDITIONAL_VARIANCE_DECOMPOSITION EQUAL vec_int_number
#line 2892 "pkg/src/lex_yacc/DynareBison.yy"
                                       { driver.option_vec_int("conditional_variance_decomposition", (yystack_[0].value.vector_int_val)); }
#line 4609 "pkg/src/DynareBison.cc"
    break;

  case 1412: // o_est_first_obs: FIRST_OBS EQUAL vec_int
#line 2895 "pkg/src/lex_yacc/DynareBison.yy"
                  { driver.option_vec_int("first_obs", (yystack_[0].value.vector_int_val)); }
#line 4615 "pkg/src/DynareBison.cc"
    break;

  case 1413: // o_est_first_obs: FIRST_OBS EQUAL vec_int_number
#line 2897 "pkg/src/lex_yacc/DynareBison.yy"
                  { driver.option_vec_int("first_obs", (yystack_[0].value.vector_int_val)); }
#line 4621 "pkg/src/DynareBison.cc"
    break;

  case 1414: // o_posterior_sampling_method: POSTERIOR_SAMPLING_METHOD EQUAL QUOTED_STRING
#line 2900 "pkg/src/lex_yacc/DynareBison.yy"
                              { driver.option_str("posterior_sampler_options.posterior_sampling_method", (yystack_[0].value.string_val)); }
#line 4627 "pkg/src/DynareBison.cc"
    break;

  case 1415: // o_first_obs: FIRST_OBS EQUAL INT_NUMBER
#line 2901 "pkg/src/lex_yacc/DynareBison.yy"
                                         { driver.option_num("first_obs", (yystack_[0].value.string_val)); }
#line 4633 "pkg/src/DynareBison.cc"
    break;

  case 1416: // o_data_first_obs: FIRST_OBS EQUAL date_expr
#line 2902 "pkg/src/lex_yacc/DynareBison.yy"
                                             { driver.option_date("firstobs", (yystack_[0].value.string_val)); }
#line 4639 "pkg/src/DynareBison.cc"
    break;

  case 1417: // o_data_last_obs: LAST_OBS EQUAL date_expr
#line 2903 "pkg/src/lex_yacc/DynareBison.yy"
                                           { driver.option_date("lastobs", (yystack_[0].value.string_val)); }
#line 4645 "pkg/src/DynareBison.cc"
    break;

  case 1418: // o_keep_kalman_algo_if_singularity_is_detected: KEEP_KALMAN_ALGO_IF_SINGULARITY_IS_DETECTED
#line 2904 "pkg/src/lex_yacc/DynareBison.yy"
                                                                                            { driver.option_num("kalman.keep_kalman_algo_if_singularity_is_detected", "1"); }
#line 4651 "pkg/src/DynareBison.cc"
    break;

  case 1419: // o_data_nobs: NOBS EQUAL INT_NUMBER
#line 2905 "pkg/src/lex_yacc/DynareBison.yy"
                                    { driver.option_num("nobs", (yystack_[0].value.string_val)); }
#line 4657 "pkg/src/DynareBison.cc"
    break;

  case 1420: // o_shift: SHIFT EQUAL signed_number
#line 2906 "pkg/src/lex_yacc/DynareBison.yy"
                                    { driver.option_num("shift", (yystack_[0].value.string_val)); }
#line 4663 "pkg/src/DynareBison.cc"
    break;

  case 1421: // o_shape: SHAPE EQUAL prior_distribution
#line 2907 "pkg/src/lex_yacc/DynareBison.yy"
                                         { driver.prior_shape = (yystack_[0].value.prior_distributions_val); }
#line 4669 "pkg/src/DynareBison.cc"
    break;

  case 1422: // o_mode: MODE EQUAL signed_number
#line 2908 "pkg/src/lex_yacc/DynareBison.yy"
                                  { driver.option_num("mode", (yystack_[0].value.string_val)); }
#line 4675 "pkg/src/DynareBison.cc"
    break;

  case 1423: // o_mean: MEAN EQUAL signed_number
#line 2909 "pkg/src/lex_yacc/DynareBison.yy"
                                  { driver.option_num("mean", (yystack_[0].value.string_val)); }
#line 4681 "pkg/src/DynareBison.cc"
    break;

  case 1424: // o_mean_vec: MEAN EQUAL vec_value
#line 2910 "pkg/src/lex_yacc/DynareBison.yy"
                                  { driver.option_num("mean", (yystack_[0].value.string_val)); }
#line 4687 "pkg/src/DynareBison.cc"
    break;

  case 1425: // o_truncate: TRUNCATE EQUAL vec_value
#line 2911 "pkg/src/lex_yacc/DynareBison.yy"
                                      { driver.option_num("truncate", (yystack_[0].value.string_val)); }
#line 4693 "pkg/src/DynareBison.cc"
    break;

  case 1426: // o_stdev: STDEV EQUAL non_negative_number
#line 2912 "pkg/src/lex_yacc/DynareBison.yy"
                                          { driver.option_num("stdev", (yystack_[0].value.string_val)); }
#line 4699 "pkg/src/DynareBison.cc"
    break;

  case 1427: // o_jscale: JSCALE EQUAL non_negative_number
#line 2913 "pkg/src/lex_yacc/DynareBison.yy"
                                            { driver.option_num("jscale", (yystack_[0].value.string_val)); }
#line 4705 "pkg/src/DynareBison.cc"
    break;

  case 1428: // o_init: INIT EQUAL signed_number
#line 2914 "pkg/src/lex_yacc/DynareBison.yy"
                                  { driver.option_num("init", (yystack_[0].value.string_val)); }
#line 4711 "pkg/src/DynareBison.cc"
    break;

  case 1429: // o_bounds: BOUNDS EQUAL vec_value_w_inf
#line 2915 "pkg/src/lex_yacc/DynareBison.yy"
                                        { driver.option_num("bounds", (yystack_[0].value.string_val)); }
#line 4717 "pkg/src/DynareBison.cc"
    break;

  case 1430: // o_domain: DOMAINN EQUAL vec_value
#line 2916 "pkg/src/lex_yacc/DynareBison.yy"
                                   { driver.option_num("domain", (yystack_[0].value.string_val)); }
#line 4723 "pkg/src/DynareBison.cc"
    break;

  case 1431: // o_interval: INTERVAL EQUAL vec_value
#line 2917 "pkg/src/lex_yacc/DynareBison.yy"
                                      { driver.option_num("interval", (yystack_[0].value.string_val)); }
#line 4729 "pkg/src/DynareBison.cc"
    break;

  case 1432: // o_variance: VARIANCE EQUAL expression
#line 2918 "pkg/src/lex_yacc/DynareBison.yy"
                                       { driver.set_prior_variance((yystack_[0].value.node_val)); }
#line 4735 "pkg/src/DynareBison.cc"
    break;

  case 1433: // o_variance_mat: VARIANCE EQUAL vec_of_vec_value
#line 2919 "pkg/src/lex_yacc/DynareBison.yy"
                                                 { driver.option_num("variance",(yystack_[0].value.string_val)); }
#line 4741 "pkg/src/DynareBison.cc"
    break;

  case 1434: // o_prefilter: PREFILTER EQUAL INT_NUMBER
#line 2920 "pkg/src/lex_yacc/DynareBison.yy"
                                         { driver.option_num("prefilter", (yystack_[0].value.string_val)); }
#line 4747 "pkg/src/DynareBison.cc"
    break;

  case 1435: // o_presample: PRESAMPLE EQUAL INT_NUMBER
#line 2921 "pkg/src/lex_yacc/DynareBison.yy"
                                         { driver.option_num("presample", (yystack_[0].value.string_val)); }
#line 4753 "pkg/src/DynareBison.cc"
    break;

  case 1436: // o_lik_algo: LIK_ALGO EQUAL INT_NUMBER
#line 2922 "pkg/src/lex_yacc/DynareBison.yy"
                                       { driver.option_num("lik_algo", (yystack_[0].value.string_val)); }
#line 4759 "pkg/src/DynareBison.cc"
    break;

  case 1437: // o_lik_init: LIK_INIT EQUAL INT_NUMBER
#line 2923 "pkg/src/lex_yacc/DynareBison.yy"
                                       { driver.option_num("lik_init", (yystack_[0].value.string_val)); }
#line 4765 "pkg/src/DynareBison.cc"
    break;

  case 1438: // o_nograph: NOGRAPH
#line 2925 "pkg/src/lex_yacc/DynareBison.yy"
            { driver.option_num("nograph","1"); }
#line 4771 "pkg/src/DynareBison.cc"
    break;

  case 1439: // o_nograph: GRAPH
#line 2927 "pkg/src/lex_yacc/DynareBison.yy"
            { driver.option_num("nograph", "0"); }
#line 4777 "pkg/src/DynareBison.cc"
    break;

  case 1440: // o_posterior_nograph: POSTERIOR_NOGRAPH
#line 2930 "pkg/src/lex_yacc/DynareBison.yy"
            { driver.option_num("no_graph.posterior","1"); }
#line 4783 "pkg/src/DynareBison.cc"
    break;

  case 1441: // o_posterior_nograph: POSTERIOR_GRAPH
#line 2932 "pkg/src/lex_yacc/DynareBison.yy"
            { driver.option_num("no_graph.posterior", "0"); }
#line 4789 "pkg/src/DynareBison.cc"
    break;

  case 1442: // o_shock_decomposition_nograph: NOGRAPH
#line 2934 "pkg/src/lex_yacc/DynareBison.yy"
                                        { driver.option_num("no_graph.shock_decomposition", "1"); }
#line 4795 "pkg/src/DynareBison.cc"
    break;

  case 1443: // o_init_state: INIT_STATE EQUAL INT_NUMBER
#line 2935 "pkg/src/lex_yacc/DynareBison.yy"
                                           { driver.option_num("shock_decomp.init_state", (yystack_[0].value.string_val)); }
#line 4801 "pkg/src/DynareBison.cc"
    break;

  case 1444: // o_shock_decomposition_presample: PRESAMPLE EQUAL INT_NUMBER
#line 2936 "pkg/src/lex_yacc/DynareBison.yy"
                                                             { driver.option_num("shock_decomp.presample", (yystack_[0].value.string_val)); }
#line 4807 "pkg/src/DynareBison.cc"
    break;

  case 1445: // o_shock_decomposition_forecast: FORECAST EQUAL INT_NUMBER
#line 2937 "pkg/src/lex_yacc/DynareBison.yy"
                                                           { driver.option_num("shock_decomp.forecast", (yystack_[0].value.string_val)); }
#line 4813 "pkg/src/DynareBison.cc"
    break;

  case 1446: // o_save_realtime: SAVE_REALTIME EQUAL vec_int
#line 2938 "pkg/src/lex_yacc/DynareBison.yy"
                                              { driver.option_vec_int("shock_decomp.save_realtime", (yystack_[0].value.vector_int_val)); }
#line 4819 "pkg/src/DynareBison.cc"
    break;

  case 1447: // o_nodisplay: NODISPLAY
#line 2939 "pkg/src/lex_yacc/DynareBison.yy"
                        { driver.option_num("nodisplay","1"); }
#line 4825 "pkg/src/DynareBison.cc"
    break;

  case 1448: // o_psd_nodisplay: NODISPLAY
#line 2940 "pkg/src/lex_yacc/DynareBison.yy"
                            { driver.option_num("plot_shock_decomp.nodisplay","1"); }
#line 4831 "pkg/src/DynareBison.cc"
    break;

  case 1449: // o_graph_format: GRAPH_FORMAT EQUAL allowed_graph_formats
#line 2942 "pkg/src/lex_yacc/DynareBison.yy"
                 { driver.process_graph_format_option(); }
#line 4837 "pkg/src/DynareBison.cc"
    break;

  case 1450: // o_graph_format: GRAPH_FORMAT EQUAL '(' list_allowed_graph_formats ')'
#line 2944 "pkg/src/lex_yacc/DynareBison.yy"
                 { driver.process_graph_format_option(); }
#line 4843 "pkg/src/DynareBison.cc"
    break;

  case 1451: // o_psd_graph_format: GRAPH_FORMAT EQUAL allowed_graph_formats
#line 2947 "pkg/src/lex_yacc/DynareBison.yy"
                     { driver.plot_shock_decomp_process_graph_format_option(); }
#line 4849 "pkg/src/DynareBison.cc"
    break;

  case 1452: // o_psd_graph_format: GRAPH_FORMAT EQUAL '(' list_allowed_graph_formats ')'
#line 2949 "pkg/src/lex_yacc/DynareBison.yy"
                     { driver.plot_shock_decomp_process_graph_format_option(); }
#line 4855 "pkg/src/DynareBison.cc"
    break;

  case 1453: // allowed_graph_formats: EPS
#line 2952 "pkg/src/lex_yacc/DynareBison.yy"
                        { driver.add_graph_format("eps"); }
#line 4861 "pkg/src/DynareBison.cc"
    break;

  case 1454: // allowed_graph_formats: FIG
#line 2954 "pkg/src/lex_yacc/DynareBison.yy"
                        { driver.add_graph_format("fig"); }
#line 4867 "pkg/src/DynareBison.cc"
    break;

  case 1455: // allowed_graph_formats: PDF
#line 2956 "pkg/src/lex_yacc/DynareBison.yy"
                        { driver.add_graph_format("pdf"); }
#line 4873 "pkg/src/DynareBison.cc"
    break;

  case 1456: // allowed_graph_formats: NONE
#line 2958 "pkg/src/lex_yacc/DynareBison.yy"
                        { driver.add_graph_format("none"); }
#line 4879 "pkg/src/DynareBison.cc"
    break;

  case 1459: // o_subsample_name: symbol EQUAL date_expr ':' date_expr
#line 2965 "pkg/src/lex_yacc/DynareBison.yy"
                   { driver.set_subsample_name_equal_to_date_range((yystack_[4].value.string_val), (yystack_[2].value.string_val), (yystack_[0].value.string_val)); }
#line 4885 "pkg/src/DynareBison.cc"
    break;

  case 1460: // o_bvar_conf_sig: CONF_SIG EQUAL non_negative_number
#line 2967 "pkg/src/lex_yacc/DynareBison.yy"
                                                     { driver.option_num("bvar.conf_sig", (yystack_[0].value.string_val)); }
#line 4891 "pkg/src/DynareBison.cc"
    break;

  case 1461: // o_forecasts_conf_sig: CONF_SIG EQUAL non_negative_number
#line 2968 "pkg/src/lex_yacc/DynareBison.yy"
                                                          { driver.option_num("forecasts.conf_sig", (yystack_[0].value.string_val)); }
#line 4897 "pkg/src/DynareBison.cc"
    break;

  case 1462: // o_conditional_forecast_conf_sig: CONF_SIG EQUAL non_negative_number
#line 2969 "pkg/src/lex_yacc/DynareBison.yy"
                                                                     { driver.option_num("conditional_forecast.conf_sig", (yystack_[0].value.string_val)); }
#line 4903 "pkg/src/DynareBison.cc"
    break;

  case 1463: // o_mh_conf_sig: MH_CONF_SIG EQUAL non_negative_number
#line 2970 "pkg/src/lex_yacc/DynareBison.yy"
                                                      { driver.option_num("mh_conf_sig", (yystack_[0].value.string_val)); }
#line 4909 "pkg/src/DynareBison.cc"
    break;

  case 1464: // o_mh_replic: MH_REPLIC EQUAL INT_NUMBER
#line 2971 "pkg/src/lex_yacc/DynareBison.yy"
                                         { driver.option_num("mh_replic", (yystack_[0].value.string_val)); }
#line 4915 "pkg/src/DynareBison.cc"
    break;

  case 1465: // o_posterior_max_subsample_draws: POSTERIOR_MAX_SUBSAMPLE_DRAWS EQUAL INT_NUMBER
#line 2972 "pkg/src/lex_yacc/DynareBison.yy"
                                                                                 { driver.option_num("posterior_max_subsample_draws", (yystack_[0].value.string_val)); }
#line 4921 "pkg/src/DynareBison.cc"
    break;

  case 1466: // o_mh_drop: MH_DROP EQUAL non_negative_number
#line 2973 "pkg/src/lex_yacc/DynareBison.yy"
                                              { driver.option_num("mh_drop", (yystack_[0].value.string_val)); }
#line 4927 "pkg/src/DynareBison.cc"
    break;

  case 1467: // o_mh_jscale: MH_JSCALE EQUAL non_negative_number
#line 2974 "pkg/src/lex_yacc/DynareBison.yy"
                                                  { driver.option_num("mh_jscale", (yystack_[0].value.string_val)); }
#line 4933 "pkg/src/DynareBison.cc"
    break;

  case 1470: // o_proposal_distribution: PROPOSAL_DISTRIBUTION EQUAL symbol
#line 2977 "pkg/src/lex_yacc/DynareBison.yy"
                                                             { driver.option_str("posterior_sampler_options.posterior_sampling_method.proposal_distribution", (yystack_[0].value.string_val)); }
#line 4939 "pkg/src/DynareBison.cc"
    break;

  case 1471: // o_no_posterior_kernel_density: NO_POSTERIOR_KERNEL_DENSITY
#line 2979 "pkg/src/lex_yacc/DynareBison.yy"
                             { driver.option_num("estimation.moments_posterior_density.indicator", "0"); }
#line 4945 "pkg/src/DynareBison.cc"
    break;

  case 1472: // o_mh_init_scale: MH_INIT_SCALE EQUAL non_negative_number
#line 2981 "pkg/src/lex_yacc/DynareBison.yy"
                                                          { driver.option_num("mh_init_scale", (yystack_[0].value.string_val)); }
#line 4951 "pkg/src/DynareBison.cc"
    break;

  case 1473: // o_mode_file: MODE_FILE EQUAL filename
#line 2982 "pkg/src/lex_yacc/DynareBison.yy"
                                       { driver.option_str("mode_file", (yystack_[0].value.string_val)); }
#line 4957 "pkg/src/DynareBison.cc"
    break;

  case 1474: // o_mode_compute: MODE_COMPUTE EQUAL INT_NUMBER
#line 2983 "pkg/src/lex_yacc/DynareBison.yy"
                                               { driver.option_num("mode_compute", (yystack_[0].value.string_val)); }
#line 4963 "pkg/src/DynareBison.cc"
    break;

  case 1475: // o_mode_compute: MODE_COMPUTE EQUAL symbol
#line 2984 "pkg/src/lex_yacc/DynareBison.yy"
                                           { driver.option_str("mode_compute", (yystack_[0].value.string_val)); }
#line 4969 "pkg/src/DynareBison.cc"
    break;

  case 1476: // o_mode_check: MODE_CHECK
#line 2985 "pkg/src/lex_yacc/DynareBison.yy"
                          { driver.option_num("mode_check.status", "1"); }
#line 4975 "pkg/src/DynareBison.cc"
    break;

  case 1477: // o_mode_check_neighbourhood_size: MODE_CHECK_NEIGHBOURHOOD_SIZE EQUAL signed_number_w_inf
#line 2986 "pkg/src/lex_yacc/DynareBison.yy"
                                                                                          { driver.option_num("mode_check.neighbourhood_size", (yystack_[0].value.string_val)); }
#line 4981 "pkg/src/DynareBison.cc"
    break;

  case 1478: // o_mode_check_number_of_points: MODE_CHECK_NUMBER_OF_POINTS EQUAL INT_NUMBER
#line 2987 "pkg/src/lex_yacc/DynareBison.yy"
                                                                             { driver.option_num("mode_check.number_of_points", (yystack_[0].value.string_val)); }
#line 4987 "pkg/src/DynareBison.cc"
    break;

  case 1479: // o_mode_check_symmetric_plots: MODE_CHECK_SYMMETRIC_PLOTS EQUAL INT_NUMBER
#line 2988 "pkg/src/lex_yacc/DynareBison.yy"
                                                                           { driver.option_num("mode_check.symmetric_plots", (yystack_[0].value.string_val)); }
#line 4993 "pkg/src/DynareBison.cc"
    break;

  case 1480: // o_prior_trunc: PRIOR_TRUNC EQUAL non_negative_number
#line 2989 "pkg/src/lex_yacc/DynareBison.yy"
                                                      { driver.option_num("prior_trunc", (yystack_[0].value.string_val)); }
#line 4999 "pkg/src/DynareBison.cc"
    break;

  case 1481: // o_mh_mode: MH_MODE EQUAL INT_NUMBER
#line 2990 "pkg/src/lex_yacc/DynareBison.yy"
                                     { driver.option_num("mh_mode", (yystack_[0].value.string_val)); }
#line 5005 "pkg/src/DynareBison.cc"
    break;

  case 1482: // o_mh_nblocks: MH_NBLOCKS EQUAL INT_NUMBER
#line 2991 "pkg/src/lex_yacc/DynareBison.yy"
                                           { driver.option_num("mh_nblck", (yystack_[0].value.string_val)); }
#line 5011 "pkg/src/DynareBison.cc"
    break;

  case 1483: // o_load_mh_file: LOAD_MH_FILE
#line 2992 "pkg/src/lex_yacc/DynareBison.yy"
                              { driver.option_num("load_mh_file", "1"); }
#line 5017 "pkg/src/DynareBison.cc"
    break;

  case 1484: // o_load_results_after_load_mh: LOAD_RESULTS_AFTER_LOAD_MH
#line 2993 "pkg/src/lex_yacc/DynareBison.yy"
                                                          { driver.option_num("load_results_after_load_mh", "1"); }
#line 5023 "pkg/src/DynareBison.cc"
    break;

  case 1485: // o_loglinear: LOGLINEAR
#line 2994 "pkg/src/lex_yacc/DynareBison.yy"
                        { driver.option_num("loglinear", "1"); }
#line 5029 "pkg/src/DynareBison.cc"
    break;

  case 1486: // o_linear_approximation: LINEAR_APPROXIMATION
#line 2995 "pkg/src/lex_yacc/DynareBison.yy"
                                              { driver.option_num("linear_approximation", "1"); }
#line 5035 "pkg/src/DynareBison.cc"
    break;

  case 1487: // o_logdata: LOGDATA
#line 2996 "pkg/src/lex_yacc/DynareBison.yy"
                    { driver.option_num("logdata", "1"); }
#line 5041 "pkg/src/DynareBison.cc"
    break;

  case 1488: // o_nodiagnostic: NODIAGNOSTIC
#line 2997 "pkg/src/lex_yacc/DynareBison.yy"
                              { driver.option_num("nodiagnostic", "1"); }
#line 5047 "pkg/src/DynareBison.cc"
    break;

  case 1489: // o_bayesian_irf: BAYESIAN_IRF
#line 2998 "pkg/src/lex_yacc/DynareBison.yy"
                              { driver.option_num("bayesian_irf", "1"); }
#line 5053 "pkg/src/DynareBison.cc"
    break;

  case 1490: // o_dsge_var: DSGE_VAR EQUAL non_negative_number
#line 3000 "pkg/src/lex_yacc/DynareBison.yy"
             { driver.option_num("dsge_var", (yystack_[0].value.string_val)); }
#line 5059 "pkg/src/DynareBison.cc"
    break;

  case 1491: // o_dsge_var: DSGE_VAR EQUAL INF_CONSTANT
#line 3002 "pkg/src/lex_yacc/DynareBison.yy"
             { driver.option_num("dsge_var", "Inf"); }
#line 5065 "pkg/src/DynareBison.cc"
    break;

  case 1492: // o_dsge_var: DSGE_VAR
#line 3004 "pkg/src/lex_yacc/DynareBison.yy"
             { driver.option_str("dsge_var", "NaN"); }
#line 5071 "pkg/src/DynareBison.cc"
    break;

  case 1493: // o_dsge_varlag: DSGE_VARLAG EQUAL INT_NUMBER
#line 3006 "pkg/src/lex_yacc/DynareBison.yy"
                                             { driver.option_num("dsge_varlag", (yystack_[0].value.string_val)); }
#line 5077 "pkg/src/DynareBison.cc"
    break;

  case 1494: // o_tex: TEX
#line 3007 "pkg/src/lex_yacc/DynareBison.yy"
            { driver.option_num("TeX", "1"); }
#line 5083 "pkg/src/DynareBison.cc"
    break;

  case 1495: // o_forecast: FORECAST EQUAL INT_NUMBER
#line 3008 "pkg/src/lex_yacc/DynareBison.yy"
                                       { driver.option_num("forecast", (yystack_[0].value.string_val)); }
#line 5089 "pkg/src/DynareBison.cc"
    break;

  case 1496: // o_smoother: SMOOTHER
#line 3009 "pkg/src/lex_yacc/DynareBison.yy"
                      { driver.option_num("smoother", "1"); }
#line 5095 "pkg/src/DynareBison.cc"
    break;

  case 1497: // o_moments_varendo: MOMENTS_VARENDO
#line 3010 "pkg/src/lex_yacc/DynareBison.yy"
                                    { driver.option_num("moments_varendo", "1"); }
#line 5101 "pkg/src/DynareBison.cc"
    break;

  case 1498: // o_contemporaneous_correlation: CONTEMPORANEOUS_CORRELATION
#line 3011 "pkg/src/lex_yacc/DynareBison.yy"
                                                            { driver.option_num("contemporaneous_correlation", "1"); }
#line 5107 "pkg/src/DynareBison.cc"
    break;

  case 1499: // o_filtered_vars: FILTERED_VARS
#line 3012 "pkg/src/lex_yacc/DynareBison.yy"
                                { driver.option_num("filtered_vars", "1"); }
#line 5113 "pkg/src/DynareBison.cc"
    break;

  case 1500: // o_relative_irf: RELATIVE_IRF
#line 3013 "pkg/src/lex_yacc/DynareBison.yy"
                              { driver.option_num("relative_irf", "1"); }
#line 5119 "pkg/src/DynareBison.cc"
    break;

  case 1501: // o_fast_kalman_filter: FAST_KALMAN_FILTER
#line 3014 "pkg/src/lex_yacc/DynareBison.yy"
                                           { driver.option_num("fast_kalman_filter", "1"); }
#line 5125 "pkg/src/DynareBison.cc"
    break;

  case 1502: // o_kalman_algo: KALMAN_ALGO EQUAL INT_NUMBER
#line 3015 "pkg/src/lex_yacc/DynareBison.yy"
                                             { driver.option_num("kalman_algo", (yystack_[0].value.string_val)); }
#line 5131 "pkg/src/DynareBison.cc"
    break;

  case 1503: // o_kalman_tol: KALMAN_TOL EQUAL non_negative_number
#line 3016 "pkg/src/lex_yacc/DynareBison.yy"
                                                    { driver.option_num("kalman_tol", (yystack_[0].value.string_val)); }
#line 5137 "pkg/src/DynareBison.cc"
    break;

  case 1504: // o_diffuse_kalman_tol: DIFFUSE_KALMAN_TOL EQUAL non_negative_number
#line 3017 "pkg/src/lex_yacc/DynareBison.yy"
                                                                    { driver.option_num("diffuse_kalman_tol", (yystack_[0].value.string_val)); }
#line 5143 "pkg/src/DynareBison.cc"
    break;

  case 1505: // o_marginal_density: MARGINAL_DENSITY EQUAL LAPLACE
#line 3019 "pkg/src/lex_yacc/DynareBison.yy"
                     { driver.option_str("mc_marginal_density", "laplace"); }
#line 5149 "pkg/src/DynareBison.cc"
    break;

  case 1506: // o_marginal_density: MARGINAL_DENSITY EQUAL MODIFIEDHARMONICMEAN
#line 3021 "pkg/src/lex_yacc/DynareBison.yy"
                     { driver.option_str("mc_marginal_density", "modifiedharmonicmean"); }
#line 5155 "pkg/src/DynareBison.cc"
    break;

  case 1507: // o_print: PRINT
#line 3023 "pkg/src/lex_yacc/DynareBison.yy"
                { driver.option_num("noprint", "0"); }
#line 5161 "pkg/src/DynareBison.cc"
    break;

  case 1508: // o_noprint: NOPRINT
#line 3024 "pkg/src/lex_yacc/DynareBison.yy"
                    { driver.option_num("noprint", "1"); }
#line 5167 "pkg/src/DynareBison.cc"
    break;

  case 1509: // o_xls_sheet: XLS_SHEET EQUAL symbol
#line 3025 "pkg/src/lex_yacc/DynareBison.yy"
                                     { driver.option_str("xls_sheet", (yystack_[0].value.string_val)); }
#line 5173 "pkg/src/DynareBison.cc"
    break;

  case 1510: // o_xls_range: XLS_RANGE EQUAL range
#line 3026 "pkg/src/lex_yacc/DynareBison.yy"
                                    { driver.option_str("xls_range", (yystack_[0].value.string_val)); }
#line 5179 "pkg/src/DynareBison.cc"
    break;

  case 1511: // o_filter_step_ahead: FILTER_STEP_AHEAD EQUAL vec_int
#line 3027 "pkg/src/lex_yacc/DynareBison.yy"
                                                      { driver.option_vec_int("filter_step_ahead", (yystack_[0].value.vector_int_val)); }
#line 5185 "pkg/src/DynareBison.cc"
    break;

  case 1512: // o_taper_steps: TAPER_STEPS EQUAL vec_int
#line 3028 "pkg/src/lex_yacc/DynareBison.yy"
                                          { driver.option_vec_int("convergence.geweke.taper_steps", (yystack_[0].value.vector_int_val)); }
#line 5191 "pkg/src/DynareBison.cc"
    break;

  case 1513: // o_geweke_interval: GEWEKE_INTERVAL EQUAL vec_value
#line 3029 "pkg/src/lex_yacc/DynareBison.yy"
                                                    { driver.option_num("convergence.geweke.geweke_interval",(yystack_[0].value.string_val)); }
#line 5197 "pkg/src/DynareBison.cc"
    break;

  case 1514: // o_raftery_lewis_diagnostics: RAFTERY_LEWIS_DIAGNOSTICS
#line 3030 "pkg/src/lex_yacc/DynareBison.yy"
                                                        { driver.option_num("convergence.rafterylewis.indicator", "1"); }
#line 5203 "pkg/src/DynareBison.cc"
    break;

  case 1515: // o_raftery_lewis_qrs: RAFTERY_LEWIS_QRS EQUAL vec_value
#line 3031 "pkg/src/lex_yacc/DynareBison.yy"
                                                        { driver.option_num("convergence.rafterylewis.qrs",(yystack_[0].value.string_val)); }
#line 5209 "pkg/src/DynareBison.cc"
    break;

  case 1516: // o_constant: CONSTANT
#line 3032 "pkg/src/lex_yacc/DynareBison.yy"
                      { driver.option_num("noconstant", "0"); }
#line 5215 "pkg/src/DynareBison.cc"
    break;

  case 1517: // o_noconstant: NOCONSTANT
#line 3033 "pkg/src/lex_yacc/DynareBison.yy"
                          { driver.option_num("noconstant", "1"); }
#line 5221 "pkg/src/DynareBison.cc"
    break;

  case 1518: // o_mh_recover: MH_RECOVER
#line 3034 "pkg/src/lex_yacc/DynareBison.yy"
                          { driver.option_num("mh_recover", "1"); }
#line 5227 "pkg/src/DynareBison.cc"
    break;

  case 1519: // o_diffuse_filter: DIFFUSE_FILTER
#line 3035 "pkg/src/lex_yacc/DynareBison.yy"
                                 {driver.option_num("diffuse_filter", "1"); }
#line 5233 "pkg/src/DynareBison.cc"
    break;

  case 1520: // o_plot_priors: PLOT_PRIORS EQUAL INT_NUMBER
#line 3036 "pkg/src/lex_yacc/DynareBison.yy"
                                            {driver.option_num("plot_priors", (yystack_[0].value.string_val)); }
#line 5239 "pkg/src/DynareBison.cc"
    break;

  case 1521: // o_aim_solver: AIM_SOLVER
#line 3037 "pkg/src/lex_yacc/DynareBison.yy"
                         {driver.option_num("aim_solver", "1"); }
#line 5245 "pkg/src/DynareBison.cc"
    break;

  case 1522: // o_partial_information: PARTIAL_INFORMATION
#line 3038 "pkg/src/lex_yacc/DynareBison.yy"
                                            {driver.option_num("partial_information", "1"); }
#line 5251 "pkg/src/DynareBison.cc"
    break;

  case 1523: // o_sub_draws: SUB_DRAWS EQUAL INT_NUMBER
#line 3039 "pkg/src/lex_yacc/DynareBison.yy"
                                        {driver.option_num("sub_draws",(yystack_[0].value.string_val));}
#line 5257 "pkg/src/DynareBison.cc"
    break;

  case 1524: // o_planner_discount: PLANNER_DISCOUNT EQUAL expression
#line 3040 "pkg/src/lex_yacc/DynareBison.yy"
                                                       { driver.declare_optimal_policy_discount_factor_parameter((yystack_[0].value.node_val)); }
#line 5263 "pkg/src/DynareBison.cc"
    break;

  case 1525: // o_sylvester: SYLVESTER EQUAL FIXED_POINT
#line 3041 "pkg/src/lex_yacc/DynareBison.yy"
                                          {driver.option_num("sylvester_fp", "1"); }
#line 5269 "pkg/src/DynareBison.cc"
    break;

  case 1526: // o_sylvester: SYLVESTER EQUAL DEFAULT
#line 3042 "pkg/src/lex_yacc/DynareBison.yy"
                                         {driver.option_num("sylvester_fp", "0"); }
#line 5275 "pkg/src/DynareBison.cc"
    break;

  case 1527: // o_sylvester_fixed_point_tol: SYLVESTER_FIXED_POINT_TOL EQUAL non_negative_number
#line 3043 "pkg/src/lex_yacc/DynareBison.yy"
                                                                                  {driver.option_num("sylvester_fixed_point_tol",(yystack_[0].value.string_val));}
#line 5281 "pkg/src/DynareBison.cc"
    break;

  case 1528: // o_lyapunov: LYAPUNOV EQUAL FIXED_POINT
#line 3044 "pkg/src/lex_yacc/DynareBison.yy"
                                        {driver.option_num("lyapunov_fp", "1"); }
#line 5287 "pkg/src/DynareBison.cc"
    break;

  case 1529: // o_lyapunov: LYAPUNOV EQUAL DOUBLING
#line 3045 "pkg/src/lex_yacc/DynareBison.yy"
                                        {driver.option_num("lyapunov_db", "1"); }
#line 5293 "pkg/src/DynareBison.cc"
    break;

  case 1530: // o_lyapunov: LYAPUNOV EQUAL SQUARE_ROOT_SOLVER
#line 3046 "pkg/src/lex_yacc/DynareBison.yy"
                                                  {driver.option_num("lyapunov_srs", "1"); }
#line 5299 "pkg/src/DynareBison.cc"
    break;

  case 1531: // o_lyapunov: LYAPUNOV EQUAL DEFAULT
#line 3047 "pkg/src/lex_yacc/DynareBison.yy"
                                       {driver.option_num("lyapunov_fp", "0");driver.option_num("lyapunov_db", "0"); driver.option_num("lyapunov_srs", "0");}
#line 5305 "pkg/src/DynareBison.cc"
    break;

  case 1532: // o_lyapunov_fixed_point_tol: LYAPUNOV_FIXED_POINT_TOL EQUAL non_negative_number
#line 3048 "pkg/src/lex_yacc/DynareBison.yy"
                                                                                {driver.option_num("lyapunov_fixed_point_tol",(yystack_[0].value.string_val));}
#line 5311 "pkg/src/DynareBison.cc"
    break;

  case 1533: // o_lyapunov_doubling_tol: LYAPUNOV_DOUBLING_TOL EQUAL non_negative_number
#line 3049 "pkg/src/lex_yacc/DynareBison.yy"
                                                                          {driver.option_num("lyapunov_doubling_tol",(yystack_[0].value.string_val));}
#line 5317 "pkg/src/DynareBison.cc"
    break;

  case 1534: // o_dr: DR EQUAL CYCLE_REDUCTION
#line 3050 "pkg/src/lex_yacc/DynareBison.yy"
                                {driver.option_num("dr_cycle_reduction", "1"); }
#line 5323 "pkg/src/DynareBison.cc"
    break;

  case 1535: // o_dr: DR EQUAL LOGARITHMIC_REDUCTION
#line 3051 "pkg/src/lex_yacc/DynareBison.yy"
                                        {driver.option_num("dr_logarithmic_reduction", "1"); }
#line 5329 "pkg/src/DynareBison.cc"
    break;

  case 1536: // o_dr: DR EQUAL DEFAULT
#line 3052 "pkg/src/lex_yacc/DynareBison.yy"
                          {driver.option_num("dr_cycle_reduction", "0"); driver.option_num("dr_logarithmic_reduction", "0");}
#line 5335 "pkg/src/DynareBison.cc"
    break;

  case 1537: // o_dr_cycle_reduction_tol: DR_CYCLE_REDUCTION_TOL EQUAL non_negative_number
#line 3053 "pkg/src/lex_yacc/DynareBison.yy"
                                                                            {driver.option_num("dr_cycle_reduction_tol",(yystack_[0].value.string_val));}
#line 5341 "pkg/src/DynareBison.cc"
    break;

  case 1538: // o_dr_logarithmic_reduction_tol: DR_LOGARITHMIC_REDUCTION_TOL EQUAL non_negative_number
#line 3054 "pkg/src/lex_yacc/DynareBison.yy"
                                                                                        {driver.option_num("dr_logarithmic_reduction_tol",(yystack_[0].value.string_val));}
#line 5347 "pkg/src/DynareBison.cc"
    break;

  case 1539: // o_dr_logarithmic_reduction_maxiter: DR_LOGARITHMIC_REDUCTION_MAXITER EQUAL INT_NUMBER
#line 3055 "pkg/src/lex_yacc/DynareBison.yy"
                                                                                       {driver.option_num("dr_logarithmic_reduction_maxiter",(yystack_[0].value.string_val));}
#line 5353 "pkg/src/DynareBison.cc"
    break;

  case 1540: // o_psd_detail_plot: DETAIL_PLOT
#line 3056 "pkg/src/lex_yacc/DynareBison.yy"
                                { driver.option_num("plot_shock_decomp.detail_plot", "1"); }
#line 5359 "pkg/src/DynareBison.cc"
    break;

  case 1541: // o_icd_detail_plot: DETAIL_PLOT
#line 3057 "pkg/src/lex_yacc/DynareBison.yy"
                                { driver.option_num("initial_condition_decomp.detail_plot", "1"); }
#line 5365 "pkg/src/DynareBison.cc"
    break;

  case 1542: // o_psd_interactive: INTERACTIVE
#line 3058 "pkg/src/lex_yacc/DynareBison.yy"
                                { driver.option_num("plot_shock_decomp.interactive", "1"); }
#line 5371 "pkg/src/DynareBison.cc"
    break;

  case 1543: // o_psd_screen_shocks: SCREEN_SHOCKS
#line 3059 "pkg/src/lex_yacc/DynareBison.yy"
                                    { driver.option_num("plot_shock_decomp.screen_shocks", "1"); }
#line 5377 "pkg/src/DynareBison.cc"
    break;

  case 1544: // o_psd_steadystate: STEADYSTATE
#line 3060 "pkg/src/lex_yacc/DynareBison.yy"
                                { driver.option_num("plot_shock_decomp.steadystate", "1"); }
#line 5383 "pkg/src/DynareBison.cc"
    break;

  case 1545: // o_icd_steadystate: STEADYSTATE
#line 3061 "pkg/src/lex_yacc/DynareBison.yy"
                                { driver.option_num("initial_condition_decomp.steadystate", "1"); }
#line 5389 "pkg/src/DynareBison.cc"
    break;

  case 1546: // o_psd_fig_name: FIG_NAME EQUAL filename
#line 3062 "pkg/src/lex_yacc/DynareBison.yy"
                                         { driver.option_str("plot_shock_decomp.fig_name", (yystack_[0].value.string_val)); }
#line 5395 "pkg/src/DynareBison.cc"
    break;

  case 1547: // o_psd_type: TYPE EQUAL QOQ
#line 3064 "pkg/src/lex_yacc/DynareBison.yy"
             { driver.option_str("plot_shock_decomp.type", "qoq"); }
#line 5401 "pkg/src/DynareBison.cc"
    break;

  case 1548: // o_psd_type: TYPE EQUAL YOY
#line 3066 "pkg/src/lex_yacc/DynareBison.yy"
             { driver.option_str("plot_shock_decomp.type", "yoy"); }
#line 5407 "pkg/src/DynareBison.cc"
    break;

  case 1549: // o_psd_type: TYPE EQUAL AOA
#line 3068 "pkg/src/lex_yacc/DynareBison.yy"
             { driver.option_str("plot_shock_decomp.type", "aoa"); }
#line 5413 "pkg/src/DynareBison.cc"
    break;

  case 1550: // o_icd_type: TYPE EQUAL QOQ
#line 3071 "pkg/src/lex_yacc/DynareBison.yy"
             { driver.option_str("initial_condition_decomp.type", "qoq"); }
#line 5419 "pkg/src/DynareBison.cc"
    break;

  case 1551: // o_icd_type: TYPE EQUAL YOY
#line 3073 "pkg/src/lex_yacc/DynareBison.yy"
             { driver.option_str("initial_condition_decomp.type", "yoy"); }
#line 5425 "pkg/src/DynareBison.cc"
    break;

  case 1552: // o_icd_type: TYPE EQUAL AOA
#line 3075 "pkg/src/lex_yacc/DynareBison.yy"
             { driver.option_str("initial_condition_decomp.type", "aoa"); }
#line 5431 "pkg/src/DynareBison.cc"
    break;

  case 1553: // o_icd_plot_init_date: PLOT_INIT_DATE EQUAL date_expr
#line 3077 "pkg/src/lex_yacc/DynareBison.yy"
                                                      { driver.option_date("initial_condition_decomp.plot_init_date", (yystack_[0].value.string_val)); }
#line 5437 "pkg/src/DynareBison.cc"
    break;

  case 1554: // o_icd_plot_end_date: PLOT_END_DATE EQUAL date_expr
#line 3078 "pkg/src/lex_yacc/DynareBison.yy"
                                                    { driver.option_date("initial_condition_decomp.plot_end_date", (yystack_[0].value.string_val)); }
#line 5443 "pkg/src/DynareBison.cc"
    break;

  case 1555: // o_psd_plot_init_date: PLOT_INIT_DATE EQUAL date_expr
#line 3079 "pkg/src/lex_yacc/DynareBison.yy"
                                                      { driver.option_date("plot_shock_decomp.plot_init_date", (yystack_[0].value.string_val)); }
#line 5449 "pkg/src/DynareBison.cc"
    break;

  case 1556: // o_psd_plot_end_date: PLOT_END_DATE EQUAL date_expr
#line 3080 "pkg/src/lex_yacc/DynareBison.yy"
                                                    { driver.option_date("plot_shock_decomp.plot_end_date", (yystack_[0].value.string_val)); }
#line 5455 "pkg/src/DynareBison.cc"
    break;

  case 1557: // o_icd_write_xls: WRITE_XLS
#line 3081 "pkg/src/lex_yacc/DynareBison.yy"
                            { driver.option_num("initial_condition_decomp.write_xls", "1"); }
#line 5461 "pkg/src/DynareBison.cc"
    break;

  case 1558: // o_psd_write_xls: WRITE_XLS
#line 3082 "pkg/src/lex_yacc/DynareBison.yy"
                            { driver.option_num("plot_shock_decomp.write_xls", "1"); }
#line 5467 "pkg/src/DynareBison.cc"
    break;

  case 1559: // o_psd_realtime: REALTIME EQUAL INT_NUMBER
#line 3083 "pkg/src/lex_yacc/DynareBison.yy"
                                           { driver.option_num("plot_shock_decomp.realtime", (yystack_[0].value.string_val)); }
#line 5473 "pkg/src/DynareBison.cc"
    break;

  case 1560: // o_psd_vintage: VINTAGE EQUAL INT_NUMBER
#line 3084 "pkg/src/lex_yacc/DynareBison.yy"
                                         { driver.option_num("plot_shock_decomp.vintage", (yystack_[0].value.string_val)); }
#line 5479 "pkg/src/DynareBison.cc"
    break;

  case 1561: // o_bvar_prior_tau: BVAR_PRIOR_TAU EQUAL signed_number
#line 3085 "pkg/src/lex_yacc/DynareBison.yy"
                                                      { driver.option_num("bvar_prior_tau", (yystack_[0].value.string_val)); }
#line 5485 "pkg/src/DynareBison.cc"
    break;

  case 1562: // o_bvar_prior_decay: BVAR_PRIOR_DECAY EQUAL non_negative_number
#line 3086 "pkg/src/lex_yacc/DynareBison.yy"
                                                                { driver.option_num("bvar_prior_decay", (yystack_[0].value.string_val)); }
#line 5491 "pkg/src/DynareBison.cc"
    break;

  case 1563: // o_bvar_prior_lambda: BVAR_PRIOR_LAMBDA EQUAL signed_number
#line 3087 "pkg/src/lex_yacc/DynareBison.yy"
                                                            { driver.option_num("bvar_prior_lambda", (yystack_[0].value.string_val)); }
#line 5497 "pkg/src/DynareBison.cc"
    break;

  case 1564: // o_bvar_prior_mu: BVAR_PRIOR_MU EQUAL non_negative_number
#line 3088 "pkg/src/lex_yacc/DynareBison.yy"
                                                          { driver.option_num("bvar_prior_mu", (yystack_[0].value.string_val)); }
#line 5503 "pkg/src/DynareBison.cc"
    break;

  case 1565: // o_bvar_prior_omega: BVAR_PRIOR_OMEGA EQUAL INT_NUMBER
#line 3089 "pkg/src/lex_yacc/DynareBison.yy"
                                                       { driver.option_num("bvar_prior_omega", (yystack_[0].value.string_val)); }
#line 5509 "pkg/src/DynareBison.cc"
    break;

  case 1566: // o_bvar_prior_flat: BVAR_PRIOR_FLAT
#line 3090 "pkg/src/lex_yacc/DynareBison.yy"
                                    { driver.option_num("bvar_prior_flat", "1"); }
#line 5515 "pkg/src/DynareBison.cc"
    break;

  case 1567: // o_bvar_prior_train: BVAR_PRIOR_TRAIN EQUAL INT_NUMBER
#line 3091 "pkg/src/lex_yacc/DynareBison.yy"
                                                       { driver.option_num("bvar_prior_train", (yystack_[0].value.string_val)); }
#line 5521 "pkg/src/DynareBison.cc"
    break;

  case 1568: // o_bvar_replic: BVAR_REPLIC EQUAL INT_NUMBER
#line 3092 "pkg/src/lex_yacc/DynareBison.yy"
                                             { driver.option_num("bvar_replic", (yystack_[0].value.string_val)); }
#line 5527 "pkg/src/DynareBison.cc"
    break;

  case 1569: // o_number_of_particles: NUMBER_OF_PARTICLES EQUAL INT_NUMBER
#line 3094 "pkg/src/lex_yacc/DynareBison.yy"
                                                             { driver.option_num("particle.number_of_particles", (yystack_[0].value.string_val)); }
#line 5533 "pkg/src/DynareBison.cc"
    break;

  case 1571: // o_resampling: RESAMPLING EQUAL NONE
#line 3096 "pkg/src/lex_yacc/DynareBison.yy"
                                      {driver.option_num("particle.resampling.status.systematic", "0"); driver.option_num("particle.resampling.status.none", "1"); }
#line 5539 "pkg/src/DynareBison.cc"
    break;

  case 1572: // o_resampling: RESAMPLING EQUAL GENERIC
#line 3097 "pkg/src/lex_yacc/DynareBison.yy"
                                         {driver.option_num("particle.resampling.status.systematic", "0"); driver.option_num("particle.resampling.status.generic", "1"); }
#line 5545 "pkg/src/DynareBison.cc"
    break;

  case 1573: // o_resampling_threshold: RESAMPLING_THRESHOLD EQUAL non_negative_number
#line 3098 "pkg/src/lex_yacc/DynareBison.yy"
                                                                        { driver.option_num("particle.resampling.threshold", (yystack_[0].value.string_val)); }
#line 5551 "pkg/src/DynareBison.cc"
    break;

  case 1574: // o_resampling_method: RESAMPLING_METHOD EQUAL KITAGAWA
#line 3099 "pkg/src/lex_yacc/DynareBison.yy"
                                                       {driver.option_num("particle.resampling.method.kitagawa", "1"); driver.option_num("particle.resampling.method.smooth", "0"); driver.option_num("particle.resampling.smethod.stratified", "0"); }
#line 5557 "pkg/src/DynareBison.cc"
    break;

  case 1575: // o_resampling_method: RESAMPLING_METHOD EQUAL SMOOTH
#line 3100 "pkg/src/lex_yacc/DynareBison.yy"
                                               {driver.option_num("particle.resampling.method.kitagawa", "0"); driver.option_num("particle.resampling.method.smooth", "1"); driver.option_num("particle.resampling.smethod.stratified", "0"); }
#line 5563 "pkg/src/DynareBison.cc"
    break;

  case 1576: // o_resampling_method: RESAMPLING_METHOD EQUAL STRATIFIED
#line 3101 "pkg/src/lex_yacc/DynareBison.yy"
                                                   {driver.option_num("particle.resampling.method.kitagawa", "0"); driver.option_num("particle.resampling.method.smooth", "0"); driver.option_num("particle.resampling.method.stratified", "1"); }
#line 5569 "pkg/src/DynareBison.cc"
    break;

  case 1577: // o_cpf_weights: CPF_WEIGHTS EQUAL AMISANOTRISTANI
#line 3102 "pkg/src/lex_yacc/DynareBison.yy"
                                                  {driver.option_num("particle.cpf_weights_method.amisanotristani", "1"); driver.option_num("particle.cpf_weights_method.murrayjonesparslow", "0"); }
#line 5575 "pkg/src/DynareBison.cc"
    break;

  case 1578: // o_cpf_weights: CPF_WEIGHTS EQUAL MURRAYJONESPARSLOW
#line 3103 "pkg/src/lex_yacc/DynareBison.yy"
                                                     {driver.option_num("particle.cpf_weights_method.amisanotristani", "0"); driver.option_num("particle.cpf_weights_method.murrayjonesparslow", "1"); }
#line 5581 "pkg/src/DynareBison.cc"
    break;

  case 1579: // o_filter_algorithm: FILTER_ALGORITHM EQUAL symbol
#line 3104 "pkg/src/lex_yacc/DynareBison.yy"
                                                   { driver.option_str("particle.filter_algorithm", (yystack_[0].value.string_val)); }
#line 5587 "pkg/src/DynareBison.cc"
    break;

  case 1580: // o_nonlinear_filter_initialization: NONLINEAR_FILTER_INITIALIZATION EQUAL INT_NUMBER
#line 3105 "pkg/src/lex_yacc/DynareBison.yy"
                                                                                     { driver.option_num("particle.initialization", (yystack_[0].value.string_val)); }
#line 5593 "pkg/src/DynareBison.cc"
    break;

  case 1581: // o_proposal_approximation: PROPOSAL_APPROXIMATION EQUAL CUBATURE
#line 3106 "pkg/src/lex_yacc/DynareBison.yy"
                                                                 {driver.option_num("particle.proposal_approximation.cubature", "1"); driver.option_num("particle.proposal_approximation.unscented", "0"); driver.option_num("particle.proposal_approximation.montecarlo", "0");}
#line 5599 "pkg/src/DynareBison.cc"
    break;

  case 1582: // o_proposal_approximation: PROPOSAL_APPROXIMATION EQUAL UNSCENTED
#line 3107 "pkg/src/lex_yacc/DynareBison.yy"
                                                         {driver.option_num("particle.proposal_approximation.cubature", "0"); driver.option_num("particle.proposal_approximation.unscented", "1"); driver.option_num("particle.proposal_approximation.montecarlo", "0");}
#line 5605 "pkg/src/DynareBison.cc"
    break;

  case 1583: // o_proposal_approximation: PROPOSAL_APPROXIMATION EQUAL MONTECARLO
#line 3108 "pkg/src/lex_yacc/DynareBison.yy"
                                                          {driver.option_num("particle.proposal_approximation.cubature", "0"); driver.option_num("particle.proposal_approximation.unscented", "0"); driver.option_num("particle.proposal_approximation.montecarlo", "1");}
#line 5611 "pkg/src/DynareBison.cc"
    break;

  case 1584: // o_distribution_approximation: DISTRIBUTION_APPROXIMATION EQUAL CUBATURE
#line 3109 "pkg/src/lex_yacc/DynareBison.yy"
                                                                         {driver.option_num("particle.distribution_approximation.cubature", "1"); driver.option_num("particle.distribution_approximation.unscented", "0"); driver.option_num("particle.distribution_approximation.montecarlo", "0");}
#line 5617 "pkg/src/DynareBison.cc"
    break;

  case 1585: // o_distribution_approximation: DISTRIBUTION_APPROXIMATION EQUAL UNSCENTED
#line 3110 "pkg/src/lex_yacc/DynareBison.yy"
                                                             {driver.option_num("particle.distribution_approximation.cubature", "0"); driver.option_num("particle.distribution_approximation.unscented", "1"); driver.option_num("particle.distribution_approximation.montecarlo", "0");}
#line 5623 "pkg/src/DynareBison.cc"
    break;

  case 1586: // o_distribution_approximation: DISTRIBUTION_APPROXIMATION EQUAL MONTECARLO
#line 3111 "pkg/src/lex_yacc/DynareBison.yy"
                                                              {driver.option_num("particle.distribution_approximation.cubature", "0"); driver.option_num("particle.distribution_approximation.unscented", "0"); driver.option_num("particle.distribution_approximation.montecarlo", "1");}
#line 5629 "pkg/src/DynareBison.cc"
    break;

  case 1587: // o_gsa_identification: IDENTIFICATION EQUAL INT_NUMBER
#line 3114 "pkg/src/lex_yacc/DynareBison.yy"
                                                       { driver.option_num("identification", (yystack_[0].value.string_val)); }
#line 5635 "pkg/src/DynareBison.cc"
    break;

  case 1588: // o_gsa_morris: MORRIS EQUAL INT_NUMBER
#line 3115 "pkg/src/lex_yacc/DynareBison.yy"
                                       { driver.option_num("morris", (yystack_[0].value.string_val)); }
#line 5641 "pkg/src/DynareBison.cc"
    break;

  case 1589: // o_gsa_stab: STAB EQUAL INT_NUMBER
#line 3116 "pkg/src/lex_yacc/DynareBison.yy"
                                    { driver.option_num("stab", (yystack_[0].value.string_val)); }
#line 5647 "pkg/src/DynareBison.cc"
    break;

  case 1590: // o_gsa_redform: REDFORM EQUAL INT_NUMBER
#line 3117 "pkg/src/lex_yacc/DynareBison.yy"
                                          { driver.option_num("redform", (yystack_[0].value.string_val)); }
#line 5653 "pkg/src/DynareBison.cc"
    break;

  case 1591: // o_gsa_pprior: PPRIOR EQUAL INT_NUMBER
#line 3118 "pkg/src/lex_yacc/DynareBison.yy"
                                        { driver.option_num("pprior", (yystack_[0].value.string_val)); }
#line 5659 "pkg/src/DynareBison.cc"
    break;

  case 1592: // o_gsa_prior_range: PRIOR_RANGE EQUAL INT_NUMBER
#line 3119 "pkg/src/lex_yacc/DynareBison.yy"
                                                  { driver.option_num("prior_range", (yystack_[0].value.string_val)); }
#line 5665 "pkg/src/DynareBison.cc"
    break;

  case 1593: // o_gsa_ppost: PPOST EQUAL INT_NUMBER
#line 3120 "pkg/src/lex_yacc/DynareBison.yy"
                                      { driver.option_num("ppost", (yystack_[0].value.string_val)); }
#line 5671 "pkg/src/DynareBison.cc"
    break;

  case 1594: // o_gsa_ilptau: ILPTAU EQUAL INT_NUMBER
#line 3121 "pkg/src/lex_yacc/DynareBison.yy"
                                       { driver.option_num("ilptau", (yystack_[0].value.string_val)); }
#line 5677 "pkg/src/DynareBison.cc"
    break;

  case 1595: // o_gsa_morris_nliv: MORRIS_NLIV EQUAL INT_NUMBER
#line 3122 "pkg/src/lex_yacc/DynareBison.yy"
                                                 { driver.option_num("morris_nliv", (yystack_[0].value.string_val)); }
#line 5683 "pkg/src/DynareBison.cc"
    break;

  case 1596: // o_gsa_morris_ntra: MORRIS_NTRA EQUAL INT_NUMBER
#line 3123 "pkg/src/lex_yacc/DynareBison.yy"
                                                 { driver.option_num("morris_ntra", (yystack_[0].value.string_val)); }
#line 5689 "pkg/src/DynareBison.cc"
    break;

  case 1597: // o_gsa_nsam: NSAM EQUAL INT_NUMBER
#line 3124 "pkg/src/lex_yacc/DynareBison.yy"
                                   { driver.option_num("Nsam", (yystack_[0].value.string_val)); }
#line 5695 "pkg/src/DynareBison.cc"
    break;

  case 1598: // o_gsa_load_redform: LOAD_REDFORM EQUAL INT_NUMBER
#line 3125 "pkg/src/lex_yacc/DynareBison.yy"
                                                   { driver.option_num("load_redform", (yystack_[0].value.string_val)); }
#line 5701 "pkg/src/DynareBison.cc"
    break;

  case 1599: // o_gsa_load_rmse: LOAD_RMSE EQUAL INT_NUMBER
#line 3126 "pkg/src/lex_yacc/DynareBison.yy"
                                             { driver.option_num("load_rmse", (yystack_[0].value.string_val)); }
#line 5707 "pkg/src/DynareBison.cc"
    break;

  case 1600: // o_gsa_load_stab: LOAD_STAB EQUAL INT_NUMBER
#line 3127 "pkg/src/lex_yacc/DynareBison.yy"
                                             { driver.option_num("load_stab", (yystack_[0].value.string_val)); }
#line 5713 "pkg/src/DynareBison.cc"
    break;

  case 1601: // o_gsa_alpha2_stab: ALPHA2_STAB EQUAL non_negative_number
#line 3128 "pkg/src/lex_yacc/DynareBison.yy"
                                                          { driver.option_num("alpha2_stab", (yystack_[0].value.string_val)); }
#line 5719 "pkg/src/DynareBison.cc"
    break;

  case 1602: // o_gsa_logtrans_redform: LOGTRANS_REDFORM EQUAL INT_NUMBER
#line 3129 "pkg/src/lex_yacc/DynareBison.yy"
                                                           { driver.option_num("logtrans_redform", (yystack_[0].value.string_val)); }
#line 5725 "pkg/src/DynareBison.cc"
    break;

  case 1603: // o_gsa_threshold_redform: THRESHOLD_REDFORM EQUAL vec_value_w_inf
#line 3130 "pkg/src/lex_yacc/DynareBison.yy"
                                                                  { driver.option_num("threshold_redform",(yystack_[0].value.string_val)); }
#line 5731 "pkg/src/DynareBison.cc"
    break;

  case 1604: // o_gsa_ksstat_redform: KSSTAT_REDFORM EQUAL non_negative_number
#line 3131 "pkg/src/lex_yacc/DynareBison.yy"
                                                                { driver.option_num("ksstat_redform", (yystack_[0].value.string_val)); }
#line 5737 "pkg/src/DynareBison.cc"
    break;

  case 1605: // o_gsa_alpha2_redform: ALPHA2_REDFORM EQUAL non_negative_number
#line 3132 "pkg/src/lex_yacc/DynareBison.yy"
                                                                { driver.option_num("alpha2_redform", (yystack_[0].value.string_val)); }
#line 5743 "pkg/src/DynareBison.cc"
    break;

  case 1606: // o_gsa_namendo: NAMENDO EQUAL '(' symbol_list_ext ')'
#line 3133 "pkg/src/lex_yacc/DynareBison.yy"
                                                      { driver.option_symbol_list("namendo"); }
#line 5749 "pkg/src/DynareBison.cc"
    break;

  case 1607: // o_gsa_namlagendo: NAMLAGENDO EQUAL '(' symbol_list_ext ')'
#line 3134 "pkg/src/lex_yacc/DynareBison.yy"
                                                            { driver.option_symbol_list("namlagendo"); }
#line 5755 "pkg/src/DynareBison.cc"
    break;

  case 1608: // o_gsa_namexo: NAMEXO EQUAL '(' symbol_list_ext ')'
#line 3135 "pkg/src/lex_yacc/DynareBison.yy"
                                                    { driver.option_symbol_list("namexo"); }
#line 5761 "pkg/src/DynareBison.cc"
    break;

  case 1609: // o_gsa_rmse: RMSE EQUAL INT_NUMBER
#line 3136 "pkg/src/lex_yacc/DynareBison.yy"
                                   { driver.option_num("rmse", (yystack_[0].value.string_val)); }
#line 5767 "pkg/src/DynareBison.cc"
    break;

  case 1610: // o_gsa_lik_only: LIK_ONLY EQUAL INT_NUMBER
#line 3137 "pkg/src/lex_yacc/DynareBison.yy"
                                           { driver.option_num("lik_only", (yystack_[0].value.string_val)); }
#line 5773 "pkg/src/DynareBison.cc"
    break;

  case 1611: // o_gsa_var_rmse: VAR_RMSE EQUAL '(' symbol_list_ext ')'
#line 3138 "pkg/src/lex_yacc/DynareBison.yy"
                                                        { driver.option_symbol_list("var_rmse"); }
#line 5779 "pkg/src/DynareBison.cc"
    break;

  case 1612: // o_gsa_pfilt_rmse: PFILT_RMSE EQUAL non_negative_number
#line 3139 "pkg/src/lex_yacc/DynareBison.yy"
                                                        { driver.option_num("pfilt_rmse", (yystack_[0].value.string_val)); }
#line 5785 "pkg/src/DynareBison.cc"
    break;

  case 1613: // o_gsa_istart_rmse: ISTART_RMSE EQUAL INT_NUMBER
#line 3140 "pkg/src/lex_yacc/DynareBison.yy"
                                                 { driver.option_num("istart_rmse", (yystack_[0].value.string_val)); }
#line 5791 "pkg/src/DynareBison.cc"
    break;

  case 1614: // o_gsa_alpha_rmse: ALPHA_RMSE EQUAL non_negative_number
#line 3141 "pkg/src/lex_yacc/DynareBison.yy"
                                                        { driver.option_num("alpha_rmse", (yystack_[0].value.string_val)); }
#line 5797 "pkg/src/DynareBison.cc"
    break;

  case 1615: // o_gsa_alpha2_rmse: ALPHA2_RMSE EQUAL non_negative_number
#line 3142 "pkg/src/lex_yacc/DynareBison.yy"
                                                          { driver.option_num("alpha2_rmse", (yystack_[0].value.string_val)); }
#line 5803 "pkg/src/DynareBison.cc"
    break;

  case 1616: // o_gsa_sample_file: GSA_SAMPLE_FILE EQUAL INT_NUMBER
#line 3144 "pkg/src/lex_yacc/DynareBison.yy"
                    { driver.option_num("gsa_sample_file", (yystack_[0].value.string_val)); }
#line 5809 "pkg/src/DynareBison.cc"
    break;

  case 1617: // o_gsa_sample_file: GSA_SAMPLE_FILE EQUAL filename
#line 3146 "pkg/src/lex_yacc/DynareBison.yy"
                    { driver.option_str("gsa_sample_file", (yystack_[0].value.string_val)); }
#line 5815 "pkg/src/DynareBison.cc"
    break;

  case 1618: // o_gsa_neighborhood_width: NEIGHBORHOOD_WIDTH EQUAL non_negative_number
#line 3148 "pkg/src/lex_yacc/DynareBison.yy"
                                                                        { driver.option_num("neighborhood_width", (yystack_[0].value.string_val)); }
#line 5821 "pkg/src/DynareBison.cc"
    break;

  case 1619: // o_gsa_pvalue_ks: PVALUE_KS EQUAL non_negative_number
#line 3149 "pkg/src/lex_yacc/DynareBison.yy"
                                                       { driver.option_num("pvalue_ks", (yystack_[0].value.string_val)); }
#line 5827 "pkg/src/DynareBison.cc"
    break;

  case 1620: // o_gsa_pvalue_corr: PVALUE_CORR EQUAL non_negative_number
#line 3150 "pkg/src/lex_yacc/DynareBison.yy"
                                                           { driver.option_num("pvalue_corr", (yystack_[0].value.string_val)); }
#line 5833 "pkg/src/DynareBison.cc"
    break;

  case 1621: // o_load_ident_files: LOAD_IDENT_FILES EQUAL INT_NUMBER
#line 3151 "pkg/src/lex_yacc/DynareBison.yy"
                                                       { driver.option_num("load_ident_files", (yystack_[0].value.string_val)); }
#line 5839 "pkg/src/DynareBison.cc"
    break;

  case 1622: // o_useautocorr: USEAUTOCORR EQUAL INT_NUMBER
#line 3152 "pkg/src/lex_yacc/DynareBison.yy"
                                             { driver.option_num("useautocorr", (yystack_[0].value.string_val)); }
#line 5845 "pkg/src/DynareBison.cc"
    break;

  case 1623: // o_prior_mc: PRIOR_MC EQUAL INT_NUMBER
#line 3153 "pkg/src/lex_yacc/DynareBison.yy"
                                       { driver.option_num("prior_mc", (yystack_[0].value.string_val)); }
#line 5851 "pkg/src/DynareBison.cc"
    break;

  case 1624: // o_advanced: ADVANCED EQUAL signed_integer
#line 3154 "pkg/src/lex_yacc/DynareBison.yy"
                                           { driver.option_num("advanced", (yystack_[0].value.string_val)); }
#line 5857 "pkg/src/DynareBison.cc"
    break;

  case 1625: // o_max_dim_cova_group: MAX_DIM_COVA_GROUP EQUAL INT_NUMBER
#line 3155 "pkg/src/lex_yacc/DynareBison.yy"
                                                           { driver.option_num("max_dim_cova_group", (yystack_[0].value.string_val)); }
#line 5863 "pkg/src/DynareBison.cc"
    break;

  case 1626: // o_homotopy_mode: HOMOTOPY_MODE EQUAL INT_NUMBER
#line 3157 "pkg/src/lex_yacc/DynareBison.yy"
                                                 {driver.option_num("homotopy_mode",(yystack_[0].value.string_val)); }
#line 5869 "pkg/src/DynareBison.cc"
    break;

  case 1627: // o_homotopy_steps: HOMOTOPY_STEPS EQUAL INT_NUMBER
#line 3158 "pkg/src/lex_yacc/DynareBison.yy"
                                                   {driver.option_num("homotopy_steps",(yystack_[0].value.string_val)); }
#line 5875 "pkg/src/DynareBison.cc"
    break;

  case 1628: // o_homotopy_force_continue: HOMOTOPY_FORCE_CONTINUE EQUAL INT_NUMBER
#line 3159 "pkg/src/lex_yacc/DynareBison.yy"
                                                                    { driver.option_num("homotopy_force_continue",(yystack_[0].value.string_val)); }
#line 5881 "pkg/src/DynareBison.cc"
    break;

  case 1629: // o_nocheck: NOCHECK
#line 3160 "pkg/src/lex_yacc/DynareBison.yy"
                    {driver.option_num("steadystate.nocheck","1"); }
#line 5887 "pkg/src/DynareBison.cc"
    break;

  case 1630: // o_controlled_varexo: CONTROLLED_VAREXO EQUAL '(' symbol_list ')'
#line 3162 "pkg/src/lex_yacc/DynareBison.yy"
                                                                  { driver.option_symbol_list("controlled_varexo"); }
#line 5893 "pkg/src/DynareBison.cc"
    break;

  case 1631: // o_parameter_set: PARAMETER_SET EQUAL PRIOR_MODE
#line 3164 "pkg/src/lex_yacc/DynareBison.yy"
                  { driver.option_str("parameter_set", "prior_mode"); }
#line 5899 "pkg/src/DynareBison.cc"
    break;

  case 1632: // o_parameter_set: PARAMETER_SET EQUAL PRIOR_MEAN
#line 3166 "pkg/src/lex_yacc/DynareBison.yy"
                  { driver.option_str("parameter_set", "prior_mean"); }
#line 5905 "pkg/src/DynareBison.cc"
    break;

  case 1633: // o_parameter_set: PARAMETER_SET EQUAL POSTERIOR_MEAN
#line 3168 "pkg/src/lex_yacc/DynareBison.yy"
                  { driver.option_str("parameter_set", "posterior_mean"); }
#line 5911 "pkg/src/DynareBison.cc"
    break;

  case 1634: // o_parameter_set: PARAMETER_SET EQUAL POSTERIOR_MODE
#line 3170 "pkg/src/lex_yacc/DynareBison.yy"
                  { driver.option_str("parameter_set", "posterior_mode"); }
#line 5917 "pkg/src/DynareBison.cc"
    break;

  case 1635: // o_parameter_set: PARAMETER_SET EQUAL POSTERIOR_MEDIAN
#line 3172 "pkg/src/lex_yacc/DynareBison.yy"
                  { driver.option_str("parameter_set", "posterior_median"); }
#line 5923 "pkg/src/DynareBison.cc"
    break;

  case 1636: // o_parameter_set: PARAMETER_SET EQUAL MLE_MODE
#line 3174 "pkg/src/lex_yacc/DynareBison.yy"
                  { driver.option_str("parameter_set", "mle_mode"); }
#line 5929 "pkg/src/DynareBison.cc"
    break;

  case 1637: // o_parameter_set: PARAMETER_SET EQUAL CALIBRATION
#line 3176 "pkg/src/lex_yacc/DynareBison.yy"
                  { driver.option_str("parameter_set", "calibration"); }
#line 5935 "pkg/src/DynareBison.cc"
    break;

  case 1638: // o_nodecomposition: NODECOMPOSITION
#line 3178 "pkg/src/lex_yacc/DynareBison.yy"
                                    { driver.option_num("nodecomposition", "1"); }
#line 5941 "pkg/src/DynareBison.cc"
    break;

  case 1639: // o_spectral_density: SPECTRAL_DENSITY
#line 3179 "pkg/src/lex_yacc/DynareBison.yy"
                                      { driver.option_num("SpectralDensity.trigger", "1"); }
#line 5947 "pkg/src/DynareBison.cc"
    break;

  case 1640: // o_ms_drop: DROP EQUAL INT_NUMBER
#line 3180 "pkg/src/lex_yacc/DynareBison.yy"
                                  { driver.option_num("ms.drop", (yystack_[0].value.string_val)); }
#line 5953 "pkg/src/DynareBison.cc"
    break;

  case 1641: // o_ms_mh_replic: MH_REPLIC EQUAL INT_NUMBER
#line 3181 "pkg/src/lex_yacc/DynareBison.yy"
                                            { driver.option_num("ms.mh_replic", (yystack_[0].value.string_val)); }
#line 5959 "pkg/src/DynareBison.cc"
    break;

  case 1642: // o_freq: FREQ EQUAL INT_NUMBER
#line 3183 "pkg/src/lex_yacc/DynareBison.yy"
         { driver.option_num("ms.freq",(yystack_[0].value.string_val)); }
#line 5965 "pkg/src/DynareBison.cc"
    break;

  case 1643: // o_freq: FREQ EQUAL MONTHLY
#line 3185 "pkg/src/lex_yacc/DynareBison.yy"
         { driver.option_num("ms.freq","12"); }
#line 5971 "pkg/src/DynareBison.cc"
    break;

  case 1644: // o_freq: FREQ EQUAL QUARTERLY
#line 3187 "pkg/src/lex_yacc/DynareBison.yy"
         { driver.option_num("ms.freq","4"); }
#line 5977 "pkg/src/DynareBison.cc"
    break;

  case 1645: // o_initial_year: INITIAL_YEAR EQUAL INT_NUMBER
#line 3189 "pkg/src/lex_yacc/DynareBison.yy"
                                               {driver.option_num("ms.initial_year",(yystack_[0].value.string_val)); }
#line 5983 "pkg/src/DynareBison.cc"
    break;

  case 1646: // o_initial_subperiod: INITIAL_SUBPERIOD EQUAL INT_NUMBER
#line 3190 "pkg/src/lex_yacc/DynareBison.yy"
                                                         {driver.option_num("ms.initial_subperiod",(yystack_[0].value.string_val)); }
#line 5989 "pkg/src/DynareBison.cc"
    break;

  case 1647: // o_final_year: FINAL_YEAR EQUAL INT_NUMBER
#line 3191 "pkg/src/lex_yacc/DynareBison.yy"
                                           {driver.option_num("ms.final_year",(yystack_[0].value.string_val)); }
#line 5995 "pkg/src/DynareBison.cc"
    break;

  case 1648: // o_final_subperiod: FINAL_SUBPERIOD EQUAL INT_NUMBER
#line 3192 "pkg/src/lex_yacc/DynareBison.yy"
                                                     {driver.option_num("ms.final_subperiod",(yystack_[0].value.string_val)); }
#line 6001 "pkg/src/DynareBison.cc"
    break;

  case 1649: // o_data: DATA EQUAL filename
#line 3193 "pkg/src/lex_yacc/DynareBison.yy"
                             { driver.option_str("ms.data", (yystack_[0].value.string_val)); }
#line 6007 "pkg/src/DynareBison.cc"
    break;

  case 1650: // o_vlist: VLIST EQUAL INT_NUMBER
#line 3194 "pkg/src/lex_yacc/DynareBison.yy"
                                 {driver.option_num("ms.vlist",(yystack_[0].value.string_val)); }
#line 6013 "pkg/src/DynareBison.cc"
    break;

  case 1651: // o_vlistlog: VLISTLOG EQUAL '(' symbol_list ')'
#line 3195 "pkg/src/lex_yacc/DynareBison.yy"
                                                {driver.option_symbol_list("ms.vlistlog"); }
#line 6019 "pkg/src/DynareBison.cc"
    break;

  case 1652: // o_vlistper: VLISTPER EQUAL INT_NUMBER
#line 3196 "pkg/src/lex_yacc/DynareBison.yy"
                                       {driver.option_num("ms.vlistper",(yystack_[0].value.string_val)); }
#line 6025 "pkg/src/DynareBison.cc"
    break;

  case 1653: // o_restriction_fname: RESTRICTION_FNAME EQUAL NAME
#line 3198 "pkg/src/lex_yacc/DynareBison.yy"
                      {
                        driver.warning("restriction_fname is now deprecated, and may be removed in a future version of Dynare. Use svar_identification instead.");
                        driver.option_str("ms.restriction_fname",(yystack_[0].value.string_val));
                      }
#line 6034 "pkg/src/DynareBison.cc"
    break;

  case 1654: // o_restriction_fname: RESTRICTION_FNAME EQUAL UPPER_CHOLESKY
#line 3203 "pkg/src/lex_yacc/DynareBison.yy"
                      {
                        driver.warning("restriction_fname is now deprecated, and may be removed in a future version of Dynare. Use svar_identification instead.");
                        driver.option_str("ms.restriction_fname","upper_cholesky");
                      }
#line 6043 "pkg/src/DynareBison.cc"
    break;

  case 1655: // o_restriction_fname: RESTRICTION_FNAME EQUAL LOWER_CHOLESKY
#line 3208 "pkg/src/lex_yacc/DynareBison.yy"
                      {
                        driver.warning("restriction_fname is now deprecated, and may be removed in a future version of Dynare. Use svar_identification instead.");
                        driver.option_str("ms.restriction_fname","lower_cholesky");
                      }
#line 6052 "pkg/src/DynareBison.cc"
    break;

  case 1656: // o_nlags: NLAGS EQUAL INT_NUMBER
#line 3213 "pkg/src/lex_yacc/DynareBison.yy"
                                 {driver.option_num("ms.nlags",(yystack_[0].value.string_val)); }
#line 6058 "pkg/src/DynareBison.cc"
    break;

  case 1657: // o_cross_restrictions: CROSS_RESTRICTIONS
#line 3214 "pkg/src/lex_yacc/DynareBison.yy"
                                          {driver.option_num("ms.cross_restrictions","1"); }
#line 6064 "pkg/src/DynareBison.cc"
    break;

  case 1658: // o_contemp_reduced_form: CONTEMP_REDUCED_FORM
#line 3215 "pkg/src/lex_yacc/DynareBison.yy"
                                              {driver.option_num("ms.contemp_reduced_form","1"); }
#line 6070 "pkg/src/DynareBison.cc"
    break;

  case 1659: // o_real_pseudo_forecast: REAL_PSEUDO_FORECAST EQUAL INT_NUMBER
#line 3216 "pkg/src/lex_yacc/DynareBison.yy"
                                                               {driver.option_num("ms.real_pseudo_forecast",(yystack_[0].value.string_val)); }
#line 6076 "pkg/src/DynareBison.cc"
    break;

  case 1660: // o_no_bayesian_prior: NO_BAYESIAN_PRIOR
#line 3217 "pkg/src/lex_yacc/DynareBison.yy"
                                        {driver.option_num("ms.bayesian_prior","0"); }
#line 6082 "pkg/src/DynareBison.cc"
    break;

  case 1661: // o_dummy_obs: DUMMY_OBS EQUAL INT_NUMBER
#line 3218 "pkg/src/lex_yacc/DynareBison.yy"
                                         {driver.option_num("ms.dummy_obs",(yystack_[0].value.string_val)); }
#line 6088 "pkg/src/DynareBison.cc"
    break;

  case 1662: // o_nstates: NSTATES EQUAL INT_NUMBER
#line 3219 "pkg/src/lex_yacc/DynareBison.yy"
                                     {driver.option_num("ms.nstates",(yystack_[0].value.string_val)); }
#line 6094 "pkg/src/DynareBison.cc"
    break;

  case 1663: // o_indxscalesstates: INDXSCALESSTATES EQUAL INT_NUMBER
#line 3220 "pkg/src/lex_yacc/DynareBison.yy"
                                                       {driver.option_num("ms.indxscalesstates",(yystack_[0].value.string_val)); }
#line 6100 "pkg/src/DynareBison.cc"
    break;

  case 1664: // o_alpha: ALPHA EQUAL non_negative_number
#line 3221 "pkg/src/lex_yacc/DynareBison.yy"
                                          {driver.option_num("ms.alpha",(yystack_[0].value.string_val)); }
#line 6106 "pkg/src/DynareBison.cc"
    break;

  case 1665: // o_beta: BETA EQUAL non_negative_number
#line 3222 "pkg/src/lex_yacc/DynareBison.yy"
                                        {driver.option_num("ms.beta",(yystack_[0].value.string_val)); }
#line 6112 "pkg/src/DynareBison.cc"
    break;

  case 1666: // o_gsig2_lmdm: GSIG2_LMDM EQUAL INT_NUMBER
#line 3223 "pkg/src/lex_yacc/DynareBison.yy"
                                           {driver.option_num("ms.gsig2_lmdm",(yystack_[0].value.string_val)); }
#line 6118 "pkg/src/DynareBison.cc"
    break;

  case 1667: // o_specification: SPECIFICATION EQUAL SIMS_ZHA
#line 3225 "pkg/src/lex_yacc/DynareBison.yy"
                  {driver.option_num("ms.specification","1"); }
#line 6124 "pkg/src/DynareBison.cc"
    break;

  case 1668: // o_specification: SPECIFICATION EQUAL NONE
#line 3227 "pkg/src/lex_yacc/DynareBison.yy"
                  {driver.option_num("ms.specification","0"); }
#line 6130 "pkg/src/DynareBison.cc"
    break;

  case 1669: // o_q_diag: Q_DIAG EQUAL non_negative_number
#line 3229 "pkg/src/lex_yacc/DynareBison.yy"
                                            {driver.option_num("ms.q_diag",(yystack_[0].value.string_val)); }
#line 6136 "pkg/src/DynareBison.cc"
    break;

  case 1670: // o_flat_prior: FLAT_PRIOR EQUAL INT_NUMBER
#line 3230 "pkg/src/lex_yacc/DynareBison.yy"
                                           {driver.option_num("ms.flat_prior",(yystack_[0].value.string_val)); }
#line 6142 "pkg/src/DynareBison.cc"
    break;

  case 1671: // o_ncsk: NCSK EQUAL INT_NUMBER
#line 3231 "pkg/src/lex_yacc/DynareBison.yy"
                               {driver.option_num("ms.ncsk",(yystack_[0].value.string_val)); }
#line 6148 "pkg/src/DynareBison.cc"
    break;

  case 1672: // o_nstd: NSTD EQUAL INT_NUMBER
#line 3232 "pkg/src/lex_yacc/DynareBison.yy"
                               {driver.option_num("ms.nstd",(yystack_[0].value.string_val)); }
#line 6154 "pkg/src/DynareBison.cc"
    break;

  case 1673: // o_ninv: NINV EQUAL INT_NUMBER
#line 3233 "pkg/src/lex_yacc/DynareBison.yy"
                               {driver.option_num("ms.ninv",(yystack_[0].value.string_val)); }
#line 6160 "pkg/src/DynareBison.cc"
    break;

  case 1674: // o_indxparr: INDXPARR EQUAL INT_NUMBER
#line 3234 "pkg/src/lex_yacc/DynareBison.yy"
                                       {driver.option_num("ms.indxparr",(yystack_[0].value.string_val)); }
#line 6166 "pkg/src/DynareBison.cc"
    break;

  case 1675: // o_indxovr: INDXOVR EQUAL INT_NUMBER
#line 3235 "pkg/src/lex_yacc/DynareBison.yy"
                                     {driver.option_num("ms.indxovr",(yystack_[0].value.string_val)); }
#line 6172 "pkg/src/DynareBison.cc"
    break;

  case 1676: // o_aband: ABAND EQUAL INT_NUMBER
#line 3236 "pkg/src/lex_yacc/DynareBison.yy"
                                 {driver.option_num("ms.aband",(yystack_[0].value.string_val)); }
#line 6178 "pkg/src/DynareBison.cc"
    break;

  case 1677: // o_indxap: INDXAP EQUAL INT_NUMBER
#line 3237 "pkg/src/lex_yacc/DynareBison.yy"
                                   {driver.option_num("ms.indxap",(yystack_[0].value.string_val)); }
#line 6184 "pkg/src/DynareBison.cc"
    break;

  case 1678: // o_apband: APBAND EQUAL INT_NUMBER
#line 3238 "pkg/src/lex_yacc/DynareBison.yy"
                                   {driver.option_num("ms.apband",(yystack_[0].value.string_val)); }
#line 6190 "pkg/src/DynareBison.cc"
    break;

  case 1679: // o_indximf: INDXIMF EQUAL INT_NUMBER
#line 3239 "pkg/src/lex_yacc/DynareBison.yy"
                                     {driver.option_num("ms.indximf",(yystack_[0].value.string_val)); }
#line 6196 "pkg/src/DynareBison.cc"
    break;

  case 1680: // o_indxfore: INDXFORE EQUAL INT_NUMBER
#line 3240 "pkg/src/lex_yacc/DynareBison.yy"
                                       {driver.option_num("ms.indxfore",(yystack_[0].value.string_val)); }
#line 6202 "pkg/src/DynareBison.cc"
    break;

  case 1681: // o_foreband: FOREBAND EQUAL INT_NUMBER
#line 3241 "pkg/src/lex_yacc/DynareBison.yy"
                                       {driver.option_num("ms.foreband",(yystack_[0].value.string_val)); }
#line 6208 "pkg/src/DynareBison.cc"
    break;

  case 1682: // o_indxgforhat: INDXGFOREHAT EQUAL INT_NUMBER
#line 3242 "pkg/src/lex_yacc/DynareBison.yy"
                                              {driver.option_num("ms.indxgforehat",(yystack_[0].value.string_val)); }
#line 6214 "pkg/src/DynareBison.cc"
    break;

  case 1683: // o_indxgimfhat: INDXGIMFHAT EQUAL INT_NUMBER
#line 3243 "pkg/src/lex_yacc/DynareBison.yy"
                                             {driver.option_num("ms.indxgimfhat",(yystack_[0].value.string_val)); }
#line 6220 "pkg/src/DynareBison.cc"
    break;

  case 1684: // o_indxestima: INDXESTIMA EQUAL INT_NUMBER
#line 3244 "pkg/src/lex_yacc/DynareBison.yy"
                                           {driver.option_num("ms.indxestima",(yystack_[0].value.string_val)); }
#line 6226 "pkg/src/DynareBison.cc"
    break;

  case 1685: // o_indxgdls: INDXGDLS EQUAL INT_NUMBER
#line 3245 "pkg/src/lex_yacc/DynareBison.yy"
                                       {driver.option_num("ms.indxgdls",(yystack_[0].value.string_val)); }
#line 6232 "pkg/src/DynareBison.cc"
    break;

  case 1686: // o_eq_ms: EQ_MS EQUAL INT_NUMBER
#line 3246 "pkg/src/lex_yacc/DynareBison.yy"
                                 {driver.option_num("ms.eq_ms",(yystack_[0].value.string_val)); }
#line 6238 "pkg/src/DynareBison.cc"
    break;

  case 1687: // o_cms: CMS EQUAL INT_NUMBER
#line 3247 "pkg/src/lex_yacc/DynareBison.yy"
                             {driver.option_num("ms.cms",(yystack_[0].value.string_val)); }
#line 6244 "pkg/src/DynareBison.cc"
    break;

  case 1688: // o_ncms: NCMS EQUAL INT_NUMBER
#line 3248 "pkg/src/lex_yacc/DynareBison.yy"
                               {driver.option_num("ms.ncms",(yystack_[0].value.string_val)); }
#line 6250 "pkg/src/DynareBison.cc"
    break;

  case 1689: // o_eq_cms: EQ_CMS EQUAL INT_NUMBER
#line 3249 "pkg/src/lex_yacc/DynareBison.yy"
                                   {driver.option_num("ms.eq_cms",(yystack_[0].value.string_val)); }
#line 6256 "pkg/src/DynareBison.cc"
    break;

  case 1690: // o_tlindx: TLINDX EQUAL INT_NUMBER
#line 3250 "pkg/src/lex_yacc/DynareBison.yy"
                                   {driver.option_num("ms.tlindx",(yystack_[0].value.string_val)); }
#line 6262 "pkg/src/DynareBison.cc"
    break;

  case 1691: // o_tlnumber: TLNUMBER EQUAL INT_NUMBER
#line 3251 "pkg/src/lex_yacc/DynareBison.yy"
                                       {driver.option_num("ms.tlnumber",(yystack_[0].value.string_val)); }
#line 6268 "pkg/src/DynareBison.cc"
    break;

  case 1692: // o_cnum: CNUM EQUAL INT_NUMBER
#line 3252 "pkg/src/lex_yacc/DynareBison.yy"
                               {driver.option_num("ms.cnum",(yystack_[0].value.string_val)); }
#line 6274 "pkg/src/DynareBison.cc"
    break;

  case 1693: // o_k_order_solver: K_ORDER_SOLVER
#line 3253 "pkg/src/lex_yacc/DynareBison.yy"
                                  {driver.option_num("k_order_solver","1"); }
#line 6280 "pkg/src/DynareBison.cc"
    break;

  case 1694: // o_pruning: PRUNING
#line 3254 "pkg/src/lex_yacc/DynareBison.yy"
                    { driver.option_num("pruning", "1"); }
#line 6286 "pkg/src/DynareBison.cc"
    break;

  case 1695: // o_chain: CHAIN EQUAL INT_NUMBER
#line 3255 "pkg/src/lex_yacc/DynareBison.yy"
                                 { driver.option_num("ms.chain",(yystack_[0].value.string_val)); }
#line 6292 "pkg/src/DynareBison.cc"
    break;

  case 1696: // o_restrictions: RESTRICTIONS EQUAL vec_of_vec_value
#line 3257 "pkg/src/lex_yacc/DynareBison.yy"
                 { driver.option_num("ms.restrictions",(yystack_[0].value.string_val)); }
#line 6298 "pkg/src/DynareBison.cc"
    break;

  case 1697: // o_duration: DURATION EQUAL non_negative_number
#line 3260 "pkg/src/lex_yacc/DynareBison.yy"
             { driver.option_num("ms.duration",(yystack_[0].value.string_val)); }
#line 6304 "pkg/src/DynareBison.cc"
    break;

  case 1698: // o_duration: DURATION EQUAL vec_value_w_inf
#line 3262 "pkg/src/lex_yacc/DynareBison.yy"
             { driver.option_num("ms.duration",(yystack_[0].value.string_val)); }
#line 6310 "pkg/src/DynareBison.cc"
    break;

  case 1699: // o_number_of_regimes: NUMBER_OF_REGIMES EQUAL INT_NUMBER
#line 3264 "pkg/src/lex_yacc/DynareBison.yy"
                                                         { driver.option_num("ms.number_of_regimes",(yystack_[0].value.string_val)); }
#line 6316 "pkg/src/DynareBison.cc"
    break;

  case 1700: // o_number_of_lags: NUMBER_OF_LAGS EQUAL INT_NUMBER
#line 3265 "pkg/src/lex_yacc/DynareBison.yy"
                                                   { driver.option_num("ms.number_of_lags",(yystack_[0].value.string_val)); }
#line 6322 "pkg/src/DynareBison.cc"
    break;

  case 1701: // o_parameters: PARAMETERS EQUAL '[' symbol_list ']'
#line 3266 "pkg/src/lex_yacc/DynareBison.yy"
                                                    { driver.option_symbol_list("ms.parameters"); }
#line 6328 "pkg/src/DynareBison.cc"
    break;

  case 1702: // o_coefficients: COEFFICIENTS
#line 3267 "pkg/src/lex_yacc/DynareBison.yy"
                              { driver.option_str("ms.coefficients","svar_coefficients"); }
#line 6334 "pkg/src/DynareBison.cc"
    break;

  case 1703: // o_variances: VARIANCES
#line 3268 "pkg/src/lex_yacc/DynareBison.yy"
                        { driver.option_str("ms.variances","svar_variances"); }
#line 6340 "pkg/src/DynareBison.cc"
    break;

  case 1704: // o_equations: EQUATIONS EQUAL vec_int
#line 3270 "pkg/src/lex_yacc/DynareBison.yy"
              { driver.option_vec_int("ms.equations",(yystack_[0].value.vector_int_val)); }
#line 6346 "pkg/src/DynareBison.cc"
    break;

  case 1705: // o_equations: EQUATIONS EQUAL vec_int_number
#line 3272 "pkg/src/lex_yacc/DynareBison.yy"
              { driver.option_vec_int("ms.equations",(yystack_[0].value.vector_int_val)); }
#line 6352 "pkg/src/DynareBison.cc"
    break;

  case 1706: // o_silent_optimizer: SILENT_OPTIMIZER
#line 3274 "pkg/src/lex_yacc/DynareBison.yy"
                                      { driver.option_num("silent_optimizer", "1"); }
#line 6358 "pkg/src/DynareBison.cc"
    break;

  case 1707: // o_instruments: INSTRUMENTS EQUAL '(' symbol_list ')'
#line 3275 "pkg/src/lex_yacc/DynareBison.yy"
                                                      {driver.option_symbol_list("instruments"); }
#line 6364 "pkg/src/DynareBison.cc"
    break;

  case 1708: // o_ext_func_name: EXT_FUNC_NAME EQUAL filename
#line 3277 "pkg/src/lex_yacc/DynareBison.yy"
                                               { driver.external_function_option("name", (yystack_[0].value.string_val)); }
#line 6370 "pkg/src/DynareBison.cc"
    break;

  case 1709: // o_ext_func_nargs: EXT_FUNC_NARGS EQUAL INT_NUMBER
#line 3278 "pkg/src/lex_yacc/DynareBison.yy"
                                                   { driver.external_function_option("nargs",(yystack_[0].value.string_val)); }
#line 6376 "pkg/src/DynareBison.cc"
    break;

  case 1710: // o_first_deriv_provided: FIRST_DERIV_PROVIDED EQUAL filename
#line 3280 "pkg/src/lex_yacc/DynareBison.yy"
                         { driver.external_function_option("first_deriv_provided", (yystack_[0].value.string_val)); }
#line 6382 "pkg/src/DynareBison.cc"
    break;

  case 1711: // o_first_deriv_provided: FIRST_DERIV_PROVIDED
#line 3282 "pkg/src/lex_yacc/DynareBison.yy"
                         { driver.external_function_option("first_deriv_provided", ""); }
#line 6388 "pkg/src/DynareBison.cc"
    break;

  case 1712: // o_second_deriv_provided: SECOND_DERIV_PROVIDED EQUAL filename
#line 3285 "pkg/src/lex_yacc/DynareBison.yy"
                          { driver.external_function_option("second_deriv_provided", (yystack_[0].value.string_val)); }
#line 6394 "pkg/src/DynareBison.cc"
    break;

  case 1713: // o_second_deriv_provided: SECOND_DERIV_PROVIDED
#line 3287 "pkg/src/lex_yacc/DynareBison.yy"
                          { driver.external_function_option("second_deriv_provided", ""); }
#line 6400 "pkg/src/DynareBison.cc"
    break;

  case 1714: // o_filter_covariance: FILTER_COVARIANCE
#line 3290 "pkg/src/lex_yacc/DynareBison.yy"
                        { driver.option_num("filter_covariance","1");}
#line 6406 "pkg/src/DynareBison.cc"
    break;

  case 1715: // o_filter_decomposition: FILTER_DECOMPOSITION
#line 3293 "pkg/src/lex_yacc/DynareBison.yy"
                           { driver.option_num("filter_decomposition","1");}
#line 6412 "pkg/src/DynareBison.cc"
    break;

  case 1716: // o_smoothed_state_uncertainty: SMOOTHED_STATE_UNCERTAINTY
#line 3296 "pkg/src/lex_yacc/DynareBison.yy"
                           { driver.option_num("smoothed_state_uncertainty","1");}
#line 6418 "pkg/src/DynareBison.cc"
    break;

  case 1717: // o_selected_variables_only: SELECTED_VARIABLES_ONLY
#line 3299 "pkg/src/lex_yacc/DynareBison.yy"
                           { driver.option_num("selected_variables_only","1");}
#line 6424 "pkg/src/DynareBison.cc"
    break;

  case 1718: // o_cova_compute: COVA_COMPUTE EQUAL INT_NUMBER
#line 3302 "pkg/src/lex_yacc/DynareBison.yy"
                 { driver.option_num("cova_compute",(yystack_[0].value.string_val));}
#line 6430 "pkg/src/DynareBison.cc"
    break;

  case 1719: // o_output_file_tag: OUTPUT_FILE_TAG EQUAL filename
#line 3304 "pkg/src/lex_yacc/DynareBison.yy"
                                                   {driver.option_str("ms.output_file_tag", (yystack_[0].value.string_val)); }
#line 6436 "pkg/src/DynareBison.cc"
    break;

  case 1720: // o_file_tag: FILE_TAG EQUAL filename
#line 3305 "pkg/src/lex_yacc/DynareBison.yy"
                                     { driver.option_str("ms.file_tag", (yystack_[0].value.string_val)); }
#line 6442 "pkg/src/DynareBison.cc"
    break;

  case 1721: // o_no_create_init: NO_CREATE_INIT
#line 3306 "pkg/src/lex_yacc/DynareBison.yy"
                                  { driver.option_num("ms.create_init", "0"); }
#line 6448 "pkg/src/DynareBison.cc"
    break;

  case 1722: // o_simulation_file_tag: SIMULATION_FILE_TAG EQUAL filename
#line 3307 "pkg/src/lex_yacc/DynareBison.yy"
                                                           { driver.option_str("ms.simulation_file_tag", (yystack_[0].value.string_val)); }
#line 6454 "pkg/src/DynareBison.cc"
    break;

  case 1723: // o_coefficients_prior_hyperparameters: COEFFICIENTS_PRIOR_HYPERPARAMETERS EQUAL vec_value
#line 3309 "pkg/src/lex_yacc/DynareBison.yy"
                                       { driver.option_num("ms.coefficients_prior_hyperparameters",(yystack_[0].value.string_val)); }
#line 6460 "pkg/src/DynareBison.cc"
    break;

  case 1724: // o_convergence_starting_value: CONVERGENCE_STARTING_VALUE EQUAL non_negative_number
#line 3311 "pkg/src/lex_yacc/DynareBison.yy"
                               { driver.option_num("ms.convergence_starting_value",(yystack_[0].value.string_val)); }
#line 6466 "pkg/src/DynareBison.cc"
    break;

  case 1725: // o_convergence_ending_value: CONVERGENCE_ENDING_VALUE EQUAL non_negative_number
#line 3313 "pkg/src/lex_yacc/DynareBison.yy"
                             { driver.option_num("ms.convergence_ending_value",(yystack_[0].value.string_val)); }
#line 6472 "pkg/src/DynareBison.cc"
    break;

  case 1726: // o_convergence_increment_value: CONVERGENCE_INCREMENT_VALUE EQUAL non_negative_number
#line 3315 "pkg/src/lex_yacc/DynareBison.yy"
                                { driver.option_num("ms.convergence_increment_value",(yystack_[0].value.string_val)); }
#line 6478 "pkg/src/DynareBison.cc"
    break;

  case 1727: // o_max_iterations_starting_value: MAX_ITERATIONS_STARTING_VALUE EQUAL INT_NUMBER
#line 3317 "pkg/src/lex_yacc/DynareBison.yy"
                                  { driver.option_num("ms.max_iterations_starting_value",(yystack_[0].value.string_val)); }
#line 6484 "pkg/src/DynareBison.cc"
    break;

  case 1728: // o_max_iterations_increment_value: MAX_ITERATIONS_INCREMENT_VALUE EQUAL non_negative_number
#line 3319 "pkg/src/lex_yacc/DynareBison.yy"
                                   { driver.option_num("ms.max_iterations_increment_value",(yystack_[0].value.string_val)); }
#line 6490 "pkg/src/DynareBison.cc"
    break;

  case 1729: // o_max_block_iterations: MAX_BLOCK_ITERATIONS EQUAL INT_NUMBER
#line 3321 "pkg/src/lex_yacc/DynareBison.yy"
                         { driver.option_num("ms.max_block_iterations",(yystack_[0].value.string_val)); }
#line 6496 "pkg/src/DynareBison.cc"
    break;

  case 1730: // o_max_repeated_optimization_runs: MAX_REPEATED_OPTIMIZATION_RUNS EQUAL INT_NUMBER
#line 3323 "pkg/src/lex_yacc/DynareBison.yy"
                                   { driver.option_num("ms.max_repeated_optimization_runs",(yystack_[0].value.string_val)); }
#line 6502 "pkg/src/DynareBison.cc"
    break;

  case 1731: // o_function_convergence_criterion: FUNCTION_CONVERGENCE_CRITERION EQUAL non_negative_number
#line 3325 "pkg/src/lex_yacc/DynareBison.yy"
                                   { driver.option_num("ms.function_convergence_criterion",(yystack_[0].value.string_val)); }
#line 6508 "pkg/src/DynareBison.cc"
    break;

  case 1732: // o_parameter_convergence_criterion: PARAMETER_CONVERGENCE_CRITERION EQUAL non_negative_number
#line 3327 "pkg/src/lex_yacc/DynareBison.yy"
                                    { driver.option_num("ms.parameter_convergence_criterion",(yystack_[0].value.string_val)); }
#line 6514 "pkg/src/DynareBison.cc"
    break;

  case 1733: // o_number_of_large_perturbations: NUMBER_OF_LARGE_PERTURBATIONS EQUAL INT_NUMBER
#line 3329 "pkg/src/lex_yacc/DynareBison.yy"
                                  { driver.option_num("ms.number_of_large_perturbations",(yystack_[0].value.string_val)); }
#line 6520 "pkg/src/DynareBison.cc"
    break;

  case 1734: // o_number_of_small_perturbations: NUMBER_OF_SMALL_PERTURBATIONS EQUAL INT_NUMBER
#line 3331 "pkg/src/lex_yacc/DynareBison.yy"
                                  { driver.option_num("ms.number_of_small_perturbations",(yystack_[0].value.string_val)); }
#line 6526 "pkg/src/DynareBison.cc"
    break;

  case 1735: // o_number_of_posterior_draws_after_perturbation: NUMBER_OF_POSTERIOR_DRAWS_AFTER_PERTURBATION EQUAL INT_NUMBER
#line 3333 "pkg/src/lex_yacc/DynareBison.yy"
                                                 { driver.option_num("ms.number_of_posterior_draws_after_perturbation",(yystack_[0].value.string_val)); }
#line 6532 "pkg/src/DynareBison.cc"
    break;

  case 1736: // o_max_number_of_stages: MAX_NUMBER_OF_STAGES EQUAL INT_NUMBER
#line 3335 "pkg/src/lex_yacc/DynareBison.yy"
                         { driver.option_num("ms.max_number_of_stages",(yystack_[0].value.string_val)); }
#line 6538 "pkg/src/DynareBison.cc"
    break;

  case 1737: // o_random_function_convergence_criterion: RANDOM_FUNCTION_CONVERGENCE_CRITERION EQUAL non_negative_number
#line 3337 "pkg/src/lex_yacc/DynareBison.yy"
                                          { driver.option_num("ms.random_function_convergence_criterion",(yystack_[0].value.string_val)); }
#line 6544 "pkg/src/DynareBison.cc"
    break;

  case 1738: // o_random_parameter_convergence_criterion: RANDOM_PARAMETER_CONVERGENCE_CRITERION EQUAL non_negative_number
#line 3339 "pkg/src/lex_yacc/DynareBison.yy"
                                           { driver.option_num("ms.random_parameter_convergence_criterion",(yystack_[0].value.string_val)); }
#line 6550 "pkg/src/DynareBison.cc"
    break;

  case 1739: // o_thinning_factor: THINNING_FACTOR EQUAL INT_NUMBER
#line 3340 "pkg/src/lex_yacc/DynareBison.yy"
                                                     { driver.option_num("ms.thinning_factor",(yystack_[0].value.string_val)); }
#line 6556 "pkg/src/DynareBison.cc"
    break;

  case 1740: // o_adaptive_mh_draws: ADAPTIVE_MH_DRAWS EQUAL INT_NUMBER
#line 3341 "pkg/src/lex_yacc/DynareBison.yy"
                                                         { driver.option_num("ms.adaptive_mh_draws",(yystack_[0].value.string_val)); }
#line 6562 "pkg/src/DynareBison.cc"
    break;

  case 1741: // o_save_draws: SAVE_DRAWS
#line 3342 "pkg/src/lex_yacc/DynareBison.yy"
                          { driver.option_num("ms.save_draws","1"); }
#line 6568 "pkg/src/DynareBison.cc"
    break;

  case 1742: // o_proposal_draws: PROPOSAL_DRAWS EQUAL INT_NUMBER
#line 3343 "pkg/src/lex_yacc/DynareBison.yy"
                                                   { driver.option_num("ms.proposal_draws",(yystack_[0].value.string_val)); }
#line 6574 "pkg/src/DynareBison.cc"
    break;

  case 1743: // o_use_mean_center: USE_MEAN_CENTER
#line 3344 "pkg/src/lex_yacc/DynareBison.yy"
                                    { driver.option_num("ms.use_mean_center","1"); }
#line 6580 "pkg/src/DynareBison.cc"
    break;

  case 1744: // o_proposal_type: PROPOSAL_TYPE EQUAL INT_NUMBER
#line 3345 "pkg/src/lex_yacc/DynareBison.yy"
                                                 { driver.option_num("ms.proposal_type",(yystack_[0].value.string_val)); }
#line 6586 "pkg/src/DynareBison.cc"
    break;

  case 1745: // o_proposal_lower_bound: PROPOSAL_LOWER_BOUND EQUAL signed_number
#line 3346 "pkg/src/lex_yacc/DynareBison.yy"
                                                                  { driver.option_num("ms.proposal_lower_bound",(yystack_[0].value.string_val)); }
#line 6592 "pkg/src/DynareBison.cc"
    break;

  case 1746: // o_proposal_upper_bound: PROPOSAL_UPPER_BOUND EQUAL signed_number
#line 3347 "pkg/src/lex_yacc/DynareBison.yy"
                                                                  { driver.option_num("ms.proposal_upper_bound",(yystack_[0].value.string_val)); }
#line 6598 "pkg/src/DynareBison.cc"
    break;

  case 1747: // o_parameter_uncertainty: PARAMETER_UNCERTAINTY
#line 3348 "pkg/src/lex_yacc/DynareBison.yy"
                                                { driver.option_num("ms.parameter_uncertainty","1"); }
#line 6604 "pkg/src/DynareBison.cc"
    break;

  case 1748: // o_horizon: HORIZON EQUAL INT_NUMBER
#line 3349 "pkg/src/lex_yacc/DynareBison.yy"
                                     { driver.option_num("ms.horizon",(yystack_[0].value.string_val)); }
#line 6610 "pkg/src/DynareBison.cc"
    break;

  case 1749: // o_filtered_probabilities: FILTERED_PROBABILITIES
#line 3350 "pkg/src/lex_yacc/DynareBison.yy"
                                                  { driver.option_num("ms.filtered_probabilities","1"); }
#line 6616 "pkg/src/DynareBison.cc"
    break;

  case 1750: // o_real_time_smoothed: REAL_TIME_SMOOTHED
#line 3351 "pkg/src/lex_yacc/DynareBison.yy"
                                          { driver.option_num("ms.real_time_smoothed_probabilities","1"); }
#line 6622 "pkg/src/DynareBison.cc"
    break;

  case 1751: // o_no_error_bands: NO_ERROR_BANDS
#line 3352 "pkg/src/lex_yacc/DynareBison.yy"
                                  { driver.option_num("ms.error_bands","0"); }
#line 6628 "pkg/src/DynareBison.cc"
    break;

  case 1752: // o_error_band_percentiles: ERROR_BAND_PERCENTILES EQUAL vec_value
#line 3353 "pkg/src/lex_yacc/DynareBison.yy"
                                                                  { driver.option_num("ms.percentiles",(yystack_[0].value.string_val)); }
#line 6634 "pkg/src/DynareBison.cc"
    break;

  case 1753: // o_shock_draws: SHOCK_DRAWS EQUAL INT_NUMBER
#line 3354 "pkg/src/lex_yacc/DynareBison.yy"
                                             { driver.option_num("ms.shock_draws",(yystack_[0].value.string_val)); }
#line 6640 "pkg/src/DynareBison.cc"
    break;

  case 1754: // o_shocks_per_parameter: SHOCKS_PER_PARAMETER EQUAL INT_NUMBER
#line 3355 "pkg/src/lex_yacc/DynareBison.yy"
                                                               { driver.option_num("ms.shocks_per_parameter",(yystack_[0].value.string_val)); }
#line 6646 "pkg/src/DynareBison.cc"
    break;

  case 1755: // o_free_parameters: FREE_PARAMETERS EQUAL vec_value
#line 3356 "pkg/src/lex_yacc/DynareBison.yy"
                                                    { driver.option_num("ms.free_parameters",(yystack_[0].value.string_val)); }
#line 6652 "pkg/src/DynareBison.cc"
    break;

  case 1756: // o_median: MEDIAN
#line 3357 "pkg/src/lex_yacc/DynareBison.yy"
                  { driver.option_num("ms.median","1"); }
#line 6658 "pkg/src/DynareBison.cc"
    break;

  case 1757: // o_median: MEDIAN EQUAL signed_number
#line 3358 "pkg/src/lex_yacc/DynareBison.yy"
                                      { driver.option_num("median", (yystack_[0].value.string_val)); }
#line 6664 "pkg/src/DynareBison.cc"
    break;

  case 1758: // o_regimes: REGIMES
#line 3359 "pkg/src/lex_yacc/DynareBison.yy"
                    { driver.option_num("ms.regimes","1"); }
#line 6670 "pkg/src/DynareBison.cc"
    break;

  case 1759: // o_regime: REGIME EQUAL INT_NUMBER
#line 3360 "pkg/src/lex_yacc/DynareBison.yy"
                                   { driver.option_num("ms.regime",(yystack_[0].value.string_val)); }
#line 6676 "pkg/src/DynareBison.cc"
    break;

  case 1760: // o_data_obs_nbr: DATA_OBS_NBR EQUAL INT_NUMBER
#line 3361 "pkg/src/lex_yacc/DynareBison.yy"
                                               { driver.option_num("ms.forecast_data_obs",(yystack_[0].value.string_val)); }
#line 6682 "pkg/src/DynareBison.cc"
    break;

  case 1761: // o_discretionary_tol: DISCRETIONARY_TOL EQUAL non_negative_number
#line 3362 "pkg/src/lex_yacc/DynareBison.yy"
                                                                 { driver.option_num("discretionary_tol",(yystack_[0].value.string_val)); }
#line 6688 "pkg/src/DynareBison.cc"
    break;

  case 1762: // o_analytic_derivation: ANALYTIC_DERIVATION
#line 3363 "pkg/src/lex_yacc/DynareBison.yy"
                                            { driver.option_num("analytic_derivation", "1"); }
#line 6694 "pkg/src/DynareBison.cc"
    break;

  case 1763: // o_analytic_derivation_mode: ANALYTIC_DERIVATION_MODE EQUAL signed_number
#line 3364 "pkg/src/lex_yacc/DynareBison.yy"
                                                                          { driver.option_num("analytic_derivation_mode", (yystack_[0].value.string_val)); }
#line 6700 "pkg/src/DynareBison.cc"
    break;

  case 1764: // o_endogenous_prior: ENDOGENOUS_PRIOR
#line 3365 "pkg/src/lex_yacc/DynareBison.yy"
                                      { driver.option_num("endogenous_prior", "1"); }
#line 6706 "pkg/src/DynareBison.cc"
    break;

  case 1765: // o_use_univariate_filters_if_singularity_is_detected: USE_UNIVARIATE_FILTERS_IF_SINGULARITY_IS_DETECTED EQUAL INT_NUMBER
#line 3366 "pkg/src/lex_yacc/DynareBison.yy"
                                                                                                                         { driver.option_num("use_univariate_filters_if_singularity_is_detected", (yystack_[0].value.string_val)); }
#line 6712 "pkg/src/DynareBison.cc"
    break;

  case 1766: // o_mcmc_jumping_covariance: MCMC_JUMPING_COVARIANCE EQUAL HESSIAN
#line 3368 "pkg/src/lex_yacc/DynareBison.yy"
                            { driver.option_str("MCMC_jumping_covariance", (yystack_[0].value.string_val)); }
#line 6718 "pkg/src/DynareBison.cc"
    break;

  case 1767: // o_mcmc_jumping_covariance: MCMC_JUMPING_COVARIANCE EQUAL PRIOR_VARIANCE
#line 3369 "pkg/src/lex_yacc/DynareBison.yy"
                            { driver.option_str("MCMC_jumping_covariance", (yystack_[0].value.string_val)); }
#line 6724 "pkg/src/DynareBison.cc"
    break;

  case 1768: // o_mcmc_jumping_covariance: MCMC_JUMPING_COVARIANCE EQUAL IDENTITY_MATRIX
#line 3371 "pkg/src/lex_yacc/DynareBison.yy"
                            { driver.option_str("MCMC_jumping_covariance", (yystack_[0].value.string_val)); }
#line 6730 "pkg/src/DynareBison.cc"
    break;

  case 1769: // o_mcmc_jumping_covariance: MCMC_JUMPING_COVARIANCE EQUAL filename
#line 3373 "pkg/src/lex_yacc/DynareBison.yy"
                            { driver.option_str("MCMC_jumping_covariance", (yystack_[0].value.string_val)); }
#line 6736 "pkg/src/DynareBison.cc"
    break;

  case 1770: // o_rescale_prediction_error_covariance: RESCALE_PREDICTION_ERROR_COVARIANCE
#line 3375 "pkg/src/lex_yacc/DynareBison.yy"
                                                                            { driver.option_num("rescale_prediction_error_covariance", "true"); }
#line 6742 "pkg/src/DynareBison.cc"
    break;

  case 1771: // o_use_penalized_objective_for_hessian: USE_PENALIZED_OBJECTIVE_FOR_HESSIAN
#line 3376 "pkg/src/lex_yacc/DynareBison.yy"
                                                                            { driver.option_num("hessian.use_penalized_objective","true"); }
#line 6748 "pkg/src/DynareBison.cc"
    break;

  case 1772: // o_irf_plot_threshold: IRF_PLOT_THRESHOLD EQUAL non_negative_number
#line 3377 "pkg/src/lex_yacc/DynareBison.yy"
                                                                    { driver.option_num("impulse_responses.plot_threshold", (yystack_[0].value.string_val)); }
#line 6754 "pkg/src/DynareBison.cc"
    break;

  case 1773: // o_dr_display_tol: DR_DISPLAY_TOL EQUAL non_negative_number
#line 3378 "pkg/src/lex_yacc/DynareBison.yy"
                                                            { driver.option_num("dr_display_tol", (yystack_[0].value.string_val)); }
#line 6760 "pkg/src/DynareBison.cc"
    break;

  case 1774: // o_consider_all_endogenous: CONSIDER_ALL_ENDOGENOUS
#line 3379 "pkg/src/lex_yacc/DynareBison.yy"
                                                    { driver.option_str("endo_vars_for_moment_computations_in_estimation", "all_endogenous_variables"); }
#line 6766 "pkg/src/DynareBison.cc"
    break;

  case 1775: // o_consider_only_observed: CONSIDER_ONLY_OBSERVED
#line 3380 "pkg/src/lex_yacc/DynareBison.yy"
                                                  { driver.option_str("endo_vars_for_moment_computations_in_estimation", "only_observed_variables"); }
#line 6772 "pkg/src/DynareBison.cc"
    break;

  case 1776: // o_no_homotopy: NO_HOMOTOPY
#line 3381 "pkg/src/lex_yacc/DynareBison.yy"
                            { driver.option_num("no_homotopy", "1"); }
#line 6778 "pkg/src/DynareBison.cc"
    break;

  case 1777: // o_infile: INFILE EQUAL filename
#line 3383 "pkg/src/lex_yacc/DynareBison.yy"
                                 { driver.option_str("infile", (yystack_[0].value.string_val)); }
#line 6784 "pkg/src/DynareBison.cc"
    break;

  case 1778: // o_invars: INVARS EQUAL '(' symbol_list ')'
#line 3384 "pkg/src/lex_yacc/DynareBison.yy"
                                            { driver.option_symbol_list("invars"); }
#line 6790 "pkg/src/DynareBison.cc"
    break;

  case 1779: // o_period: PERIOD EQUAL INT_NUMBER
#line 3385 "pkg/src/lex_yacc/DynareBison.yy"
                                   { driver.option_num("period", (yystack_[0].value.string_val)); }
#line 6796 "pkg/src/DynareBison.cc"
    break;

  case 1780: // o_outfile: OUTFILE EQUAL filename
#line 3386 "pkg/src/lex_yacc/DynareBison.yy"
                                   { driver.option_str("outfile", (yystack_[0].value.string_val)); }
#line 6802 "pkg/src/DynareBison.cc"
    break;

  case 1781: // o_outvars: OUTVARS EQUAL '(' symbol_list ')'
#line 3387 "pkg/src/lex_yacc/DynareBison.yy"
                                              { driver.option_symbol_list("outvars"); }
#line 6808 "pkg/src/DynareBison.cc"
    break;

  case 1782: // o_lmmcp: LMMCP
#line 3388 "pkg/src/lex_yacc/DynareBison.yy"
                {driver.option_num("lmmcp.status", "1"); }
#line 6814 "pkg/src/DynareBison.cc"
    break;

  case 1783: // o_function: FUNCTION EQUAL filename
#line 3389 "pkg/src/lex_yacc/DynareBison.yy"
                                     { driver.option_str("function", (yystack_[0].value.string_val)); }
#line 6820 "pkg/src/DynareBison.cc"
    break;

  case 1784: // o_sampling_draws: SAMPLING_DRAWS EQUAL INT_NUMBER
#line 3390 "pkg/src/lex_yacc/DynareBison.yy"
                                                   { driver.option_num("sampling_draws",(yystack_[0].value.string_val)); }
#line 6826 "pkg/src/DynareBison.cc"
    break;

  case 1785: // o_use_shock_groups: USE_SHOCK_GROUPS
#line 3391 "pkg/src/lex_yacc/DynareBison.yy"
                                      { driver.option_str("plot_shock_decomp.use_shock_groups","default"); }
#line 6832 "pkg/src/DynareBison.cc"
    break;

  case 1786: // o_use_shock_groups: USE_SHOCK_GROUPS EQUAL symbol
#line 3392 "pkg/src/lex_yacc/DynareBison.yy"
                                                   { driver.option_str("plot_shock_decomp.use_shock_groups", (yystack_[0].value.string_val)); }
#line 6838 "pkg/src/DynareBison.cc"
    break;

  case 1787: // o_colormap: COLORMAP EQUAL symbol
#line 3394 "pkg/src/lex_yacc/DynareBison.yy"
                                   { driver.option_num("plot_shock_decomp.colormap",(yystack_[0].value.string_val)); }
#line 6844 "pkg/src/DynareBison.cc"
    break;

  case 1788: // range: symbol ':' symbol
#line 3397 "pkg/src/lex_yacc/DynareBison.yy"
        {
          (yystack_[2].value.string_val)->append(":");
          (yystack_[2].value.string_val)->append(*(yystack_[0].value.string_val));
          delete (yystack_[0].value.string_val);
          (yylhs.value.string_val) = (yystack_[2].value.string_val);
        }
#line 6855 "pkg/src/DynareBison.cc"
    break;

  case 1789: // integer_range: INT_NUMBER ':' INT_NUMBER
#line 3405 "pkg/src/lex_yacc/DynareBison.yy"
                {
                  (yystack_[2].value.string_val)->append(":");
                  (yystack_[2].value.string_val)->append(*(yystack_[0].value.string_val));
                  delete (yystack_[0].value.string_val);
                  (yylhs.value.string_val) = (yystack_[2].value.string_val);
                }
#line 6866 "pkg/src/DynareBison.cc"
    break;

  case 1790: // signed_integer_range: signed_integer ':' signed_integer
#line 3413 "pkg/src/lex_yacc/DynareBison.yy"
                       {
                         (yystack_[2].value.string_val)->append(":");
                         (yystack_[2].value.string_val)->append(*(yystack_[0].value.string_val));
                         delete (yystack_[0].value.string_val);
                         (yylhs.value.string_val) = (yystack_[2].value.string_val);
                       }
#line 6877 "pkg/src/DynareBison.cc"
    break;

  case 1791: // signed_integer_range: MINUS '(' signed_integer ':' signed_integer ')'
#line 3420 "pkg/src/lex_yacc/DynareBison.yy"
                       {
                         (yystack_[3].value.string_val)->insert(0, "-(");
                         (yystack_[3].value.string_val)->append(":");
                         (yystack_[3].value.string_val)->append(*(yystack_[1].value.string_val));
                         delete (yystack_[1].value.string_val);
                         (yystack_[3].value.string_val)->append(")");
                         (yylhs.value.string_val) = (yystack_[3].value.string_val);
                       }
#line 6890 "pkg/src/DynareBison.cc"
    break;

  case 1792: // vec_int_number: INT_NUMBER
#line 3429 "pkg/src/lex_yacc/DynareBison.yy"
                            { (yylhs.value.vector_int_val) = new vector<int>(); (yylhs.value.vector_int_val)->push_back(atoi((*(yystack_[0].value.string_val)).c_str())); delete (yystack_[0].value.string_val); }
#line 6896 "pkg/src/DynareBison.cc"
    break;

  case 1793: // vec_int_elem: vec_int_number
#line 3431 "pkg/src/lex_yacc/DynareBison.yy"
               { (yylhs.value.vector_int_val) = (yystack_[0].value.vector_int_val); }
#line 6902 "pkg/src/DynareBison.cc"
    break;

  case 1794: // vec_int_elem: INT_NUMBER ':' INT_NUMBER
#line 3433 "pkg/src/lex_yacc/DynareBison.yy"
               {
                 (yylhs.value.vector_int_val) = new vector<int>();
                 for(int i=atoi((*(yystack_[2].value.string_val)).c_str()); i<=atoi((*(yystack_[0].value.string_val)).c_str()); i++)
                   (yylhs.value.vector_int_val)->push_back(i);
                 delete (yystack_[2].value.string_val);
                 delete (yystack_[0].value.string_val);
               }
#line 6914 "pkg/src/DynareBison.cc"
    break;

  case 1795: // vec_int_1: '[' vec_int_elem
#line 3443 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.vector_int_val) = (yystack_[0].value.vector_int_val);}
#line 6920 "pkg/src/DynareBison.cc"
    break;

  case 1796: // vec_int_1: '[' COMMA vec_int_elem
#line 3445 "pkg/src/lex_yacc/DynareBison.yy"
            { (yylhs.value.vector_int_val) = (yystack_[0].value.vector_int_val);}
#line 6926 "pkg/src/DynareBison.cc"
    break;

  case 1797: // vec_int_1: vec_int_1 vec_int_elem
#line 3447 "pkg/src/lex_yacc/DynareBison.yy"
            {
              (yylhs.value.vector_int_val) = (yystack_[1].value.vector_int_val);
              for (vector<int>::const_iterator it=(yystack_[0].value.vector_int_val)->begin();
                   it!=(yystack_[0].value.vector_int_val)->end(); it++)
                (yystack_[1].value.vector_int_val)->push_back(*it);
              delete (yystack_[0].value.vector_int_val);
            }
#line 6938 "pkg/src/DynareBison.cc"
    break;

  case 1798: // vec_int_1: vec_int_1 COMMA vec_int_elem
#line 3455 "pkg/src/lex_yacc/DynareBison.yy"
            {
              (yylhs.value.vector_int_val) = (yystack_[2].value.vector_int_val);
              for (vector<int>::const_iterator it=(yystack_[0].value.vector_int_val)->begin();
                   it!=(yystack_[0].value.vector_int_val)->end(); it++)
                (yystack_[2].value.vector_int_val)->push_back(*it);
              delete (yystack_[0].value.vector_int_val);
            }
#line 6950 "pkg/src/DynareBison.cc"
    break;

  case 1799: // vec_int: vec_int_1 ']'
#line 3465 "pkg/src/lex_yacc/DynareBison.yy"
          { (yylhs.value.vector_int_val) = (yystack_[1].value.vector_int_val); }
#line 6956 "pkg/src/DynareBison.cc"
    break;

  case 1800: // vec_int: vec_int_1 COMMA ']'
#line 3467 "pkg/src/lex_yacc/DynareBison.yy"
          { (yylhs.value.vector_int_val) = (yystack_[2].value.vector_int_val); }
#line 6962 "pkg/src/DynareBison.cc"
    break;

  case 1801: // vec_value_1: '[' signed_number
#line 3470 "pkg/src/lex_yacc/DynareBison.yy"
                                { (yystack_[0].value.string_val)->insert(0,"["); (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 6968 "pkg/src/DynareBison.cc"
    break;

  case 1802: // vec_value_1: '[' COMMA signed_number
#line 3471 "pkg/src/lex_yacc/DynareBison.yy"
                                      { (yystack_[0].value.string_val)->insert(0,"["); (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 6974 "pkg/src/DynareBison.cc"
    break;

  case 1803: // vec_value_1: vec_value_1 signed_number
#line 3473 "pkg/src/lex_yacc/DynareBison.yy"
              {
                (yystack_[1].value.string_val)->append(" ");
                (yystack_[1].value.string_val)->append(*(yystack_[0].value.string_val));
                delete (yystack_[0].value.string_val);
                (yylhs.value.string_val) = (yystack_[1].value.string_val);
              }
#line 6985 "pkg/src/DynareBison.cc"
    break;

  case 1804: // vec_value_1: vec_value_1 COMMA signed_number
#line 3480 "pkg/src/lex_yacc/DynareBison.yy"
              {
                (yystack_[2].value.string_val)->append(" ");
                (yystack_[2].value.string_val)->append(*(yystack_[0].value.string_val));
                delete (yystack_[0].value.string_val);
                (yylhs.value.string_val) = (yystack_[2].value.string_val);
              }
#line 6996 "pkg/src/DynareBison.cc"
    break;

  case 1805: // vec_value: vec_value_1 ']'
#line 3488 "pkg/src/lex_yacc/DynareBison.yy"
                            { (yystack_[1].value.string_val)->append("]"); (yylhs.value.string_val) = (yystack_[1].value.string_val); }
#line 7002 "pkg/src/DynareBison.cc"
    break;

  case 1806: // vec_value: vec_value_1 COMMA ']'
#line 3489 "pkg/src/lex_yacc/DynareBison.yy"
                                  { (yystack_[2].value.string_val)->append("]"); (yylhs.value.string_val) = (yystack_[2].value.string_val); }
#line 7008 "pkg/src/DynareBison.cc"
    break;

  case 1807: // vec_value_list: vec_value_list COMMA vec_value
#line 3493 "pkg/src/lex_yacc/DynareBison.yy"
                 {
                   (yystack_[2].value.string_val)->append(",");
                   (yystack_[2].value.string_val)->append(*(yystack_[0].value.string_val));
                   delete (yystack_[0].value.string_val);
                   (yylhs.value.string_val) = (yystack_[2].value.string_val);
                 }
#line 7019 "pkg/src/DynareBison.cc"
    break;

  case 1808: // vec_value_list: vec_value
#line 3500 "pkg/src/lex_yacc/DynareBison.yy"
                 { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 7025 "pkg/src/DynareBison.cc"
    break;

  case 1809: // vec_of_vec_value: '[' vec_value_list ']'
#line 3503 "pkg/src/lex_yacc/DynareBison.yy"
                                          { (yylhs.value.string_val) = (yystack_[1].value.string_val); }
#line 7031 "pkg/src/DynareBison.cc"
    break;

  case 1810: // vec_of_vec_value: vec_value
#line 3504 "pkg/src/lex_yacc/DynareBison.yy"
                              { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 7037 "pkg/src/DynareBison.cc"
    break;

  case 1811: // vec_value_1_w_inf: '[' signed_number_w_inf
#line 3507 "pkg/src/lex_yacc/DynareBison.yy"
                    { (yystack_[0].value.string_val)->insert(0, "["); (yylhs.value.string_val) = (yystack_[0].value.string_val);}
#line 7043 "pkg/src/DynareBison.cc"
    break;

  case 1812: // vec_value_1_w_inf: vec_value_1_w_inf signed_number_w_inf
#line 3509 "pkg/src/lex_yacc/DynareBison.yy"
                    {
                      (yystack_[1].value.string_val)->append(" ");
                      (yystack_[1].value.string_val)->append(*(yystack_[0].value.string_val));
                      delete (yystack_[0].value.string_val);
                      (yylhs.value.string_val) = (yystack_[1].value.string_val);
                    }
#line 7054 "pkg/src/DynareBison.cc"
    break;

  case 1813: // vec_value_w_inf: vec_value_1_w_inf ']'
#line 3517 "pkg/src/lex_yacc/DynareBison.yy"
                                        { (yystack_[1].value.string_val)->append("]"); (yylhs.value.string_val) = (yystack_[1].value.string_val); }
#line 7060 "pkg/src/DynareBison.cc"
    break;

  case 1814: // symbol: NAME
#line 3519 "pkg/src/lex_yacc/DynareBison.yy"
         { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 7066 "pkg/src/DynareBison.cc"
    break;

  case 1815: // symbol: ALPHA
#line 3520 "pkg/src/lex_yacc/DynareBison.yy"
         { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 7072 "pkg/src/DynareBison.cc"
    break;

  case 1816: // symbol: BETA
#line 3521 "pkg/src/lex_yacc/DynareBison.yy"
         { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 7078 "pkg/src/DynareBison.cc"
    break;

  case 1817: // symbol: NINV
#line 3522 "pkg/src/lex_yacc/DynareBison.yy"
         { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 7084 "pkg/src/DynareBison.cc"
    break;

  case 1818: // symbol: ABAND
#line 3523 "pkg/src/lex_yacc/DynareBison.yy"
         { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 7090 "pkg/src/DynareBison.cc"
    break;

  case 1819: // symbol: CMS
#line 3524 "pkg/src/lex_yacc/DynareBison.yy"
         { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 7096 "pkg/src/DynareBison.cc"
    break;

  case 1820: // symbol: NCMS
#line 3525 "pkg/src/lex_yacc/DynareBison.yy"
         { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 7102 "pkg/src/DynareBison.cc"
    break;

  case 1821: // symbol: CNUM
#line 3526 "pkg/src/lex_yacc/DynareBison.yy"
         { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 7108 "pkg/src/DynareBison.cc"
    break;

  case 1822: // symbol: GAMMA
#line 3527 "pkg/src/lex_yacc/DynareBison.yy"
         { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 7114 "pkg/src/DynareBison.cc"
    break;

  case 1823: // symbol: INV_GAMMA
#line 3528 "pkg/src/lex_yacc/DynareBison.yy"
         { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 7120 "pkg/src/DynareBison.cc"
    break;

  case 1824: // symbol: INV_GAMMA1
#line 3529 "pkg/src/lex_yacc/DynareBison.yy"
         { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 7126 "pkg/src/DynareBison.cc"
    break;

  case 1825: // symbol: INV_GAMMA2
#line 3530 "pkg/src/lex_yacc/DynareBison.yy"
         { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 7132 "pkg/src/DynareBison.cc"
    break;

  case 1826: // symbol: NORMAL
#line 3531 "pkg/src/lex_yacc/DynareBison.yy"
         { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 7138 "pkg/src/DynareBison.cc"
    break;

  case 1827: // symbol: UNIFORM
#line 3532 "pkg/src/lex_yacc/DynareBison.yy"
         { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 7144 "pkg/src/DynareBison.cc"
    break;

  case 1828: // symbol: EPS
#line 3533 "pkg/src/lex_yacc/DynareBison.yy"
         { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 7150 "pkg/src/DynareBison.cc"
    break;

  case 1829: // symbol: PDF
#line 3534 "pkg/src/lex_yacc/DynareBison.yy"
         { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 7156 "pkg/src/DynareBison.cc"
    break;

  case 1830: // symbol: FIG
#line 3535 "pkg/src/lex_yacc/DynareBison.yy"
         { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 7162 "pkg/src/DynareBison.cc"
    break;

  case 1831: // symbol: NONE
#line 3536 "pkg/src/lex_yacc/DynareBison.yy"
         { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 7168 "pkg/src/DynareBison.cc"
    break;

  case 1832: // symbol: DR
#line 3537 "pkg/src/lex_yacc/DynareBison.yy"
         { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 7174 "pkg/src/DynareBison.cc"
    break;

  case 1833: // symbol: PRIOR
#line 3538 "pkg/src/lex_yacc/DynareBison.yy"
         { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 7180 "pkg/src/DynareBison.cc"
    break;


#line 7184 "pkg/src/DynareBison.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
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


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
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
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short parser::yypact_ninf_ = -2969;

  const short parser::yytable_ninf_ = -1834;

  const short
  parser::yypact_[] =
  {
    5197,   125,   131,  6559,  -169,   -87,  -149,  -163,  -136,  7303,
     238,  -126,  -122,   320,  7378,   -98,   -76,   386,   390,   -57,
     -45,  7412,   -48,   409,   228,   195,   413,   420,   264,   427,
     280,   283,   509,  7486,   606,   641,   200,   292, -2969,   294,
     299,  7517, 11237, 11237,   273, -2969,  7867,   644,   651, 11237,
     304,   681,  7551,   684,   326,   686,   703,   315,   720,  7570,
    7589,  7625,  7656,   324,  7728, 11237,  7903, 11237, 11237, -2969,
   11237,  7764,   730,   342,   344,   735,   313, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969,   746,   316,  7828,   774,
     776,   779,   826,   920,   929, -2969,   359,   361,   366,   378,
     380,   392,    22,  4672, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,   147, -2969,
   -2969,   351, -2969, -2969,   879, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969,   114,   398,  2074,   400,  3447, -2969,
     426,  7938, -2969,   680, -2969,  1217,   753,   643, 11237, -2969,
    1580,  8153,   152,  6102,  6102, 11237,   953, -2969,  5711,  8177,
     978,  2330,  2677,  1001, -2969,  1074,   933, 11237, -2969,  1994,
    8196, 11237, 11237,  1003,   285, 11237, -2969,  2252, 11237,  1014,
     973, 11237,   765,  6102,   896, -2969,   448, -2969,   914,   482,
    7977, -2969, -2969, -2969,   745,   840, -2969, 11237, 11237, 11237,
   -2969,  6835,  8216,  8263,  8435,     6,  1006,   595,  2369,   850,
    8455, -2969,   267, -2969,  4203,  8474,  6102,   226,   925, -2969,
     743,  8502, 11088,   948,   676, -2969,  2211, -2969,   249, -2969,
   -2969,   863, -2969,  6932,  8521, -2969,   172,  8545, -2969,   211,
    8713, -2969,  7279,  8760,  1045, -2969,  7182,  8784,  8803,   137,
    8823,    29,  8870,    92,  9042,    98, 11237,  9062, -2969, -2969,
    2294,  9081, -2969,  1065, -2969, -2969, -2969,  3683,   328, -2969,
     760,   785, -2969,  1741,  9109, -2969,  2159, -2969,   562, -2969,
     208, -2969,  1414, -2969,   407, -2969,  2603,   723,   362,   436,
   -2969,   397,    12,    12,   870, -2969, -2969,   918, 11237,  2802,
    2930,  6457, 10971, -2969,  1254, -2969,  1263,  1264,  1311,  1314,
    1334, -2969,  1338,  1348,  1371, -2969,  1385,  1421,  1434,  1435,
   -2969,  1155,   931, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
    1441,  1444,  1446, -2969,  1165,   938, -2969, -2969, -2969,  1452,
   -2969,  1453, -2969, -2969, -2969, -2969,   943,  1174, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, 11237, -2969,
   -2969, -2969, -2969, -2969, -2969,   951, -2969,  1460,  1464,  1465,
    1467,  1470,  1472,  1473,  1475, -2969,   -41, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969,  1477,  1479,  1482,
    1483,  1485,    18, -2969, -2969, -2969, -2969, -2969, -2969, 11237,
     224, -2969,  1205, -2969, -2969, -2969,  1488,  1489,  1490,   990,
    1221, -2969, -2969, -2969, -2969, -2969, -2969, -2969,   996, -2969,
     995,   997,  1562, -2969,  1511,  1002, -2969, -2969,  1513,  1515,
   -2969, -2969, -2969,  1519,  1520,  1521, -2969, -2969,  1525,  1526,
    1527, -2969,  1528,  1531, -2969, -2969,  1536,  1538,  1542,  1548,
    1552, -2969,  1556,  1564,  1567,  1570, -2969, -2969, -2969,  1571,
    1573,  1587,  1590,  1591,  1595,  1607,  1609,  1622,  1625, -2969,
    1628, -2969,  1632,  1634,  1635,  1636,  1638, -2969, -2969,  1641,
    1642,  1643,  1644, -2969,  1649,  1650,  1651,  1656,  1657,  1660,
    1662,  1663,  1664,  1665, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969,  1666,  1668, -2969,  1669, -2969,  1670,  1671,  1674, -2969,
   -2969,  1675,  1676, -2969,  1678,  1680, -2969,  1681, -2969,  1684,
      37, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, 11237, -2969, 11237,   892, -2969,    53, -2969,
   11237, 11237,   942, -2969,  1298, 11237, 11237,  1015, -2969,  1403,
    1177, -2969,  1702,  1709, -2969,  1206,  1449, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969,   441,  3428, -2969,  1450,   101, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969,  1223,  3571, -2969,  1230,
    1235,  1786,  3943, -2969,  1509,  1792,  1793,  1795,  1797,  1798,
    1800,  1807,  1809,  1242,  1533, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969,  4131,  1315,  1848,  4189, -2969,
      94,  1340,  1341,  1850,  4112, -2969, -2969,  1854,  1858, -2969,
    1861, -2969,  1863, -2969, -2969,   151, -2969, -2969, -2969,  1864,
    1353,   261,  6102, -2969,  1356,   162, -2969, 11237, -2969,   256,
    1357,  4584, -2969,  1588,  4632, -2969,  1360,  4917,  5224,  1872,
    1873,  1875,  1876, -2969,  1877,  1883,  1884,  1886, -2969, -2969,
   -2969, -2969, -2969, -2969,  1891,  1893, -2969,  1898,  1904, -2969,
     190, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, 11237, -2969,   100,  1394, 11282,  6044, -2969,  1397,
   -2969, -2969, -2969,  1399,  1400,  1405,  1406,  2369,  2369,  1407,
    1408,  1409,  1413,  1417,  1418,  1419,  1420,  1423,  1443,  1445,
    1447,  1448,  1451,  1454,  1455,  1457,  1458,  2369,  3127, -2969,
    1459,  1914, -2969,   234, -2969, -2969, -2969,  1932,  1955, -2969,
    1957,  1960, -2969, -2969,  1961, -2969,   259, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969,  1461, 11237, 11237,   305, -2969, -2969,  1462,  1964, -2969,
    1972,  1976,  1468,  1697, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969,  1981,  3175, -2969,  1982,  1983,   263, -2969,
   -2969,   288, -2969,  1984,  1985,  1989,  1990,  1991,  1480,  1730,
   -2969, -2969, -2969, -2969, -2969,  5021,   314, -2969,  2013,  2014,
   -2969,   317, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
    2015,  2016,  2017,  1506,  1737, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969,  2020,  2021,   330, -2969,
   -2969, -2969, -2969, -2969,   440, -2969, -2969, -2969, -2969,   756,
     255, -2969,  2022,  2034,   453, -2969, -2969, -2969, -2969, -2969,
   -2969,  2035,  2036, 11237, -2969,   123,  1394, -2969, 11237, -2969,
     135,  1394, -2969, 11237, -2969,   140,  1394, -2969,  9128, -2969,
   11237, -2969, -2969,  2037, -2969, -2969, -2969, -2969, -2969,  2038,
    2039,  2041,  2044,  2045,  2047, -2969,  1537,  1769, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969,  1545,  2054,  2061,  2067,  2069,  2070,
    2071,  2072,  2073,  2075,  2076,  2078,  2080,  2081,  2083,  2084,
    2086,  2087,  2088,  2089,  2090,  2091,  2092,  2093,  2096,  2097,
    2102,  2103,  2121,  2122,  2135,  2137,  1639,  1866, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,  2152,
    2153,  2154,  2156,  2157,   456, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969,  2158,  2161,  2162,  2164,  2165,  2167,  2168,
    2171,  2172,  2174, -2969,  2176, -2969,  2177,  2179,  2180,  2181,
   -2969,  2183,  2184,  2188,  2189,  2190,  2191,  2193,  2194,  2196,
    2197,  2198,  2200,  2202,  2203,  2205,  2206,  2213,  2217,  2218,
    2219,  2222,  2224,  2226,  2227,  2228,  2229,  2235,  2245,  1968,
    1734, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,  2253,
   -2969, -2969,  2256,  2258,  2264,  2265,  2266,  2269,  2270,  2271,
    2272,  2273, -2969,  2274,  1970,  1763, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969,  1996,  1767, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,  2280, -2969,
    2281,  2284,  2287,  2288,  2289,  2290,  2292,  2296,  2298,  2300,
    2301,  2302,  2303,  2305,  2308,  2012,  1801, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969,  2309,  2312, -2969,  2314,  2033,  1804, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969,  2320,  2321,  2322,  2324, -2969,
    2043,  1814, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969,  2050,  1815, -2969, -2969, -2969, -2969,  2334,  2053,  1825,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969,    -2,  2338,  2340,  2342,  2343,  2344,
    2345,   463, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969,  2346,   469, -2969, -2969, -2969, -2969, -2969,  2350,  2353,
    2355,  2356,   480, -2969, -2969, -2969, -2969, -2969,  2357,  2360,
     483, -2969, -2969, -2969,   498, -2969,  1563,  1851,  1853,  1844,
     500, -2969,  2364,  1859,  1860,  1865,  1849,  1868,  1869,  1874,
    1852, -2969,  1871,  1878,  1879,  1880, -2969,  6457,  6457,  1882,
    1887,  1889,  1890,  1892,  1896,  1897,  1901,  1903,  1905,  1906,
    1909,  1910,  1911,  1912,  1913,  6457,  1209, -2969,  1916, -2969,
    1918,   133,  1857,   261,   391,   261,  2326,   391,  2329,  6102,
    2331,   117,  2337,  2347, 11237, 11237,  2074,  2352,  2358,   261,
    2368,  3447,  2373,  1920,   261, 10112,   426, -2969, 11237,  2379,
    2380,  2382,   261,   261,  2384,   261,  2386,  1217,  1885,   261,
    1933,   981,  2388,  2394,   753,  1946,  1948,  1950, -2969, 11237,
     558,   933,   933, 10323,  1580, -2969, 10351, 10370,  1951, -2969,
    6457,  1953,  2409,  2178,   261, 11237,   261,   261,   261,  2410,
    6102,   117,   459,   117,  2411,  1958,   261,  2414,   261,  2415,
    2416,   749,   261,   261,   261,   261,   261,   261,  2417,  2421,
    2422,  2423,   308,  2425,  2427,  5863,  6102,  2428,  1920,  1974,
    1974, 11024,  2433,   154,   261,   833,   158,  2435, 11237,   835,
     899,  1988,  2437,  2438,   261,   329,  2443,   376,   261,  2444,
     318,  1993,  2449,  5711, 10433,  2115, -2969,  1997, -2969,   700,
   -2969,  2233,  2234,  1998, -2969,  6457,  2239,  2241,  1999, -2969,
    6457,  2000,  2454,  2467,  2018,  1074,  2468,  2019,  2023, -2969,
    6457,  1994, 10461,  2010,  2024, -2969,   466,  2026,  6102,  2027,
   -2969,  6457,   391,  2473,  2474,   466,  2475,  2481,  4499,  2483,
    2032,  2252,  2048,  2049,  6102,  2051, -2969, 11237,  2486,  2057,
    2064, -2969,  2402, 11237,  3767, -2969,   194, -2969,   261,  2052,
    2503,  2060,   448,  2065,   205,  6102,  2066,  2068,   261, -2969,
    2079,  2082,  2107, -2969,  2108,  2109, -2969, 11237,  2112, -2969,
    6457,  2113,  5844, 11237,  1855,   261,  2519,  2523, 11069,   261,
    2524,   261,  2528,   261,  2531,  2533,  2536,  6835, 10534,   204,
    1394, -2969, -2969, 11237, -2969,  2586,  6316, -2969, -2969, -2969,
    2369,  2369,  2369,  2369,    69,  2336,  2369,  2369,  2369,  2369,
    2369,  2369,  2369,  2369,  2369,  2369,  2369,  2369,  2369,  2369,
    2369,  2369,  2369,   466,  2920,  2369,  2369,  2369,  2369,  2369,
    2369,  2369,  2369,  2369,  2369,  2369,  2114,  2085,  2540,   267,
    2124,   261,   261,  2568,   261,  2579,  4203,  2127,  2128,  2359,
     138,  2132, -2969,  2134,  2589, 11237, 11237, 10609,   743, 11237,
    2138, -2969, 11237, 11237,   261,   261,  6457,  -193,   239, -2969,
   -2969,  2211,  2141,  6102,  2136,  6102,  2143,  2595,  2145,   249,
   11237,   199, -2969,  2656,   863,  2147,   261,  1920,  6932, 10628,
    2604,  2605,  1920, 10647,   172,  2149,  6457,   211, 10672,  7279,
   10700,  6457,  6457,  6457,  6457,  2169, -2969,  2606,   261,  7182,
   10719, -2969, -2969,   206,  1394, -2969, -2969,   210,  1394, -2969,
   -2969,   220,  1394, -2969, -2969, 11237, -2969, -2969, -2969,  6102,
     817,  2607,  2620,   861,   933,   933, 10785,  2294,  2182,  2621,
    2624,  2625,  2632,  2634,  2636,  2638,  2639,  2640,  2642,  2643,
    2676,  2679,   261,  2680,  2221,   261,   261,  2230,  2250,  2251,
    2681,  2683,  2254,   261,  2706,   261,   261,   261,   261,   261,
    2192,  3683,  6102, 11237,   933,   933,  2707,   328,  2257,   148,
    2709,  2711,  2713,  2714,  6102,  2716,  2268,  2723,    68,  2724,
    2725,  2726,  2729,  2730,   261,   261,  2731,  2733,  2734,  2736,
    2737,  2738,   261,  2739,  2740,  2741,  2743,  2744,  2746,  2747,
    2748,  2749,  2750,  2751,  2753,  2765,  2766,  2769,  2770,  2772,
    2774,  1974,   760,  2323, -2969,  2775,  6102,  2777,  6102,  6102,
    1974,  2778,  2779,  1974,   391,  2780,  1741, 10810,  2159,  2333,
     -35,   261,   261,   261,  2783,   261,  2784,  2787,   261,   261,
    2788,  2790,  2794,  2797,   261,   261,   562,  2348,  2798,  2800,
    2803,   208,  2351,  2805,   391,   391,  2806,  1414,  2354,   407,
    2361,  2808,  2603,  2362,  2429,  -171,  2363,  2366,   345, -2969,
    2365,  2370,  2809,   187,  2812,  2822,   362,  2367,   117,   436,
    2371,  6102,  2828,  6102,  6102,   397,  2376,  6102,  2830,    12,
    2378,  2381,  2383, 11237, 11237, -2969,  2821, 11237,  2387,   933,
   11237, 11237, -2969, 11346, 11237, 11237, -2969, 11153,  6457,  6457,
    6457,  6457,  2594,  2594,  6457,  6457,  6457,  6457,  6457,  6457,
    6457,  6457,  6457,  6457,  6457,  6457,  6457,  6457,  6457,  6457,
    2988,  6457,  6457,  6457,  6457,  6457,  6457,  6457,  6457,  6457,
    6457,  6457, -2969,  2389,  1124,  2391,   163, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969,   646, -2969,   110, -2969,
   -2969, -2969, -2969, -2969,  2393, -2969,  2395, -2969, -2969, -2969,
   -2969,  2397, -2969, -2969, -2969,  9152, -2969,  9320, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   11237, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969,  2704, -2969,  2392, -2969, -2969, -2969,  2609,  2609,
   -2969,  9367, -2969, -2969,  9391, -2969,  9410, -2969,  2262, 11237,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969,   561, -2969, -2969, -2969, -2969,
   11237, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969,   365,   368, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969,   451,   157, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,  2690,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969,  2694, -2969, -2969, -2969,  9430, 11237, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,  4411,  2628,
    2401,  2630, 11237,  6457, -2969,  3392, 11237,  6457, -2969,  6697,
    1620, -2969, -2969, -2969, -2969, -2969, -2969, -2969,  4457, -2969,
   -2969,  9477, 10995, -2969, -2969,  2856,  2857,  2403, 11237,  2404,
   -2969,  1091, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, 11237,  2406, -2969,  2641,   -97,  2412,
   11237, -2969,  2369,  2921,   -53, -2969,  2922,  2431, -2969, -2969,
    2369, -2969, -2969, 11237, -2969,  6102, -2969, -2969, -2969, -2969,
    8015, -2969,   261,  2413, -2969, -2969,  2754, -2969,   745, -2969,
     145, -2969,  3150, -2969, 11237,  7837,  6457, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969,  9649,  1394, -2969, -2969, -2969,  2745, -2969,
   -2969,  4544,  4790,  3359,  3423,  3487,  3568,  3681,  3835,   858,
    5919,  3891,  3925,  3964,  4069,  4262,  4443,  4529,  4744,   917,
     937,  4938,  2426, -2969,  1055,  1055,   671,   671,   671,   671,
      69,    69,  2336,  2336,  2644, -2969,  2369,  2436, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, 11237,  6457,
   11237,    28, -2969,   226, -2969, -2969, -2969, -2969,  9669, -2969,
    9688, -2969, -2969,  9716,  2441, -2969, -2969,  4979,   263,  2439,
     266,  6457, -2969, -2969, -2969, -2969, 11237, -2969, 11237, -2969,
   -2969, -2969,  4150,  2446, -2969,  6457, -2969, -2969, -2969, -2969,
   -2969, -2969,  9735, -2969, -2969, -2969, -2969,  9759, -2969, 11237,
    3950, -2969, -2969,  9927, -2969, -2969, 10886, -2969, -2969,  9082,
    9098,  9111,  9368, -2969, -2969, -2969, -2969, -2969,  9974,  2369,
    2369,  1394, -2969, -2969,  1394, -2969, -2969,  1394, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969,   561, -2969,  2609,
    2609, -2969,  9998, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
     308,   169, -2969, -2969, -2969,  3520,  3520,  3520, -2969, -2969,
    3520, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969,  2609,  2609, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, 11237, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969,  2369, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   10017, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,  2886,  2888,
    2447, -2969, -2969,  2450, -2969, 11237,   229, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969,   343,  2665,  2452, -2969, -2969,   -25,  2668,  2453,  2442,
    2445,  2684,  2471, -2969,  2462,  6453,  7700,  5050,  5212,  5269,
    5376,  5801,  5825,  2440,  7887,  5992,  6156,  6283,  6339,  6501,
    6525,  6598,  6741,  2529,  2645, -2969,  1123,  1123,   947,   947,
     947,   947,   589,   589,  2594,  2594,  2644,  6457,  2961,  2980,
    2986,   502, -2969, -2969, -2969, -2969,   375,  2476,  2989,  2479,
    2933, -2969, -2969,   108, -2969, -2969, 11237, -2969, -2969, -2969,
   11237, -2969, -2969,  6154,  2939,  2496, -2969, -2969, -2969, -2969,
    5097, -2969,   506,  6810, -2969, -2969,   391, -2969,   179, -2969,
   -2969,  2752, -2969,   514,  2755, -2969,   516, -2969, -2969,   700,
   -2969,  6457,  2756,  8136,  6457,  2760,  9392, -2969,  2515,  2225,
    6457, -2969, -2969,  2516,   175,  2509, -2969, -2969,  3029,  5380,
    2520,  6457, -2969,  5644,  2522,   593,  2761,  2976,  2762,  5690,
    6945,  2826,  2402,  2369,  2369, -2969,  9431,  7162, -2969,   517,
    4112, -2969,  2535, -2969,  2939,   269,   593,   503,  2526,  6457,
   -2969,  9444, -2969, -2969, -2969,  2369,  2369, -2969, -2969, -2969,
   -2969, -2969, -2969,  2369, -2969,  2369, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969,  2369, -2969,  2369, -2969, -2969,  2534,
    3127,   519, 11237,  3048,  9672,  3069,  6457,   346, -2969, 11237,
   -2969, -2969, -2969,  2562, -2969,   239, -2969,  6457, -2969,  6998,
    7200,  7219,  3075, -2969,  9689, -2969, -2969,  7238, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969,  7043,  7185, -2969, -2969,
   -2969,   521, -2969, -2969, -2969, -2969, -2969, 11327,  2569,  2570,
    2572,  2573,  7272,  7536, -2969,  2807,  2577, -2969, -2969,  4978,
   -2969,    11,  3080,  3091,  3092,  3093,  3095,  3096,  3098,  3113,
    3114,   523, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, 11237,  2601,   933, 11237,  2608,  2732, 11237,
    2610,  3050,  6457,  6457, -2969, -2969, -2969, -2969, -2969, -2969,
    6457, -2969,  6457, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969,  6457, -2969,  6457, -2969,  3950,   524,  2221,   261,   391,
    1124,  2611,  3122,  3124,   528, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969,  1124,  2617,  3072, -2969,
   -2969, -2969, -2969, -2969, -2969,  2614,   115, 11133,  2622,   561,
   -2969, -2969, -2969, -2969, -2969,   325,  2690, -2969,   242,  2694,
   -2969,  3950,  2849,  2851,  2854, -2969,  6457,  6457,  9705,  6457,
   -2969, -2969,  2627,  9718,  1124,  2629,   180,  6457,  2631, -2969,
    9999,  2633, -2969, -2969, -2969,   308,  2635, 11237, -2969, 11237,
    2637, 11237, -2969, -2969,   215, 10038, -2969, -2969,  6102, -2969,
    4077, -2969,   134,  2646,  2648,   132,   -63,  2626, -2969, 10051,
   -2969,  7552,  7783,  7905,  2686,  8327,  8393,  2369,  2369, -2969,
   10037,  6457, -2969,  6457, 10279,  2649, -2969, 11088,  7942, -2969,
   -2969, -2969,  6457, -2969, -2969, 11237, 11237, -2969, -2969, -2969,
   -2969, -2969, -2969, 11237, -2969,  2698, -2969,  1974, -2969,   391,
    1974,   261,  2370,   391,  1974,  1856,  1974,  1974,   343,  2650,
    2652,  3077,  2609,  2653, 11372, -2969,  2655, 11172, -2969,  7978,
    8154,  8178,  2820,  9000,  9608,  6457, -2969, -2969, -2969, -2969,
   -2969, -2969,   391,  6457,   375,  2651,   534,   375, -2969,  3087,
    2654,  3094,  2885, -2969,  2657,   178,  2682, -2969, -2969, -2969,
   -2969, -2969, -2969,  2940, -2969, -2969,  6457,  6457,  6457, 10229,
   10316, -2969, 10601, -2969, -2969,   535,   375,  2658,  3153, 10644,
   -2969, -2969, -2969,   551, -2969,  2868,  2872, -2969, 10084,  2899,
    2369, -2969, -2969, -2969,  2661,  2931, -2969, -2969,   466,  2880,
     466,  2914, -2969, -2969, -2969, -2969,  2369, -2969,  2369,  2369,
    8217,  3127, -2969, 10669, 10929, -2969, -2969,  3248, -2969, 11136,
   10256,   236, 10276, 10295,  2941,  5883,  3143,  2773, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,  2696,
    2700,  2442,  2701,  2702, -2969,  2705, -2969, -2969, -2969,  6457,
   -2969,  6457,  6457,  3950, -2969,  3950, -2969, -2969,  2715,   539,
   -2969,  3164,  2710,   272,  1124,  2717,   201,  2948, -2969,   540,
    2950, -2969,  2952,  6457, -2969, -2969,  2727,   541,  1124,  2728,
   -2969,   308,  2721,   593,   593, 11237, -2969,  2982, -2969, 11347,
   -2969,   272,  2720,   593, -2969,   593,  8456,  8475,  8491, -2969,
   -2969, -2969,  2742, -2969, 11237, -2969,   237,  1394, -2969, -2969,
   11237, -2969,  2984, -2969,  5999,  6296,  2758,  4511,  3241,  5883,
   -2969,  2967,  3186,  3181, 11412,  2860, 11210,  3183,  8504,  8761,
    8785, -2969,  2771, -2969,  3197,  6457,   253, -2969,   580,   375,
    2782,  3255,   588,  2940, -2969,   216,  6457, 11391, -2969,  2776,
     581,   375,  2786, -2969,  2781,  2791,  3001, -2969, -2969,   268,
     466,  2813,  2814, -2969, -2969, -2969, -2969,   241,  1394, -2969,
   -2969,  3002, -2969,  2811,  2815, 11237,  6343, -2969,  4511, -2969,
   11237,  2978,  2442,  2767, -2969, -2969,  2768, -2969, -2969, -2969,
   -2969, -2969, -2969,  8824,   275, -2969,  6457, -2969,  2823,   582,
    1124,  2824, -2969, -2969, -2969,  2981,  2983, -2969, -2969,  2827,
     587, -2969, -2969, -2969, -2969, -2969,  2785, -2969, -2969,  1394,
   -2969, -2969, -2969, 11237, 11237,  3006,  2825,  5883,   111, -2969,
   11237,  2873,  3219, -2969,  6457, -2969,  8837, -2969,  2832,   591,
     375,  6457,  6457, -2969,  2833, -2969, -2969,  3008,  3012,  3268,
   11237,  2834, 11237, -2969,   338, -2969, -2969,  9067, -2969, -2969,
    2841,   592, -2969,  3056, -2969,  3283,  3295,  2842,  3074, -2969,
   -2969, -2969, -2969, -2969,  2847,  6457,  2846,  2848, -2969,  3304,
   -2969,  3950, -2969, -2969,  2850, -2969
  };

  const short
  parser::yydefact_[] =
  {
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1814,     0,
       0,     0,     0,     0,     0,   894,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   823,
       0,     0,     0,     0,     0,     0,     0,  1815,  1816,  1818,
    1817,  1819,  1820,  1821,  1822,  1823,  1824,  1825,  1826,  1827,
    1828,  1829,  1830,  1832,  1831,  1833,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   356,     0,     0,     0,     0,
       0,     0,     0,     0,     2,    39,    40,    79,    80,     5,
       6,     7,     8,     4,     9,    10,    16,    12,    13,    14,
      15,    94,    11,    17,    73,    74,    75,    76,    18,    19,
      20,    21,    48,    95,    96,    97,    98,    22,    77,    23,
      25,    27,    26,    43,    28,    29,    32,    33,     0,    30,
      31,     0,    34,    35,     0,    24,    36,    37,    38,    41,
      42,    44,    45,    46,    60,    61,    62,    47,    49,    50,
      51,    52,    53,    63,    64,    65,    66,    67,    68,    69,
      54,    55,    56,    87,    85,    86,    84,    83,    82,    81,
      57,    58,    59,    70,    72,    71,    78,    88,    89,    90,
      91,    92,    93,    99,     0,     0,     0,     0,     0,  1298,
       0,     0,   541,     0,   433,     0,     0,     0,     0,   949,
       0,     0,     0,     0,     0,     0,     0,   694,     0,     0,
       0,     0,     0,     0,  1314,     0,     0,     0,  1267,     0,
       0,     0,     0,     0,     0,     0,   858,     0,     0,     0,
       0,     0,     0,     0,     0,   283,     0,   885,     0,   888,
       0,   884,   439,   443,     0,     0,  1323,     0,     0,     0,
     848,     0,     0,     0,     0,   185,     0,     0,     0,     0,
       0,   444,     0,   450,     0,     0,     0,     0,     0,   937,
       0,     0,     0,     0,     0,   472,     0,  1341,     0,  1292,
     421,     0,   485,     0,     0,   941,     0,     0,   897,     0,
       0,   901,     0,     0,     0,   915,     0,     0,     0,     0,
       0,   149,     0,   161,     0,   173,     0,     0,   197,   945,
       0,     0,   933,     0,   935,   936,  1160,     0,     0,  1032,
       0,     0,  1086,     0,     0,  1050,     0,  1158,     0,  1119,
       0,  1108,     0,  1096,     0,  1068,     0,     0,     0,     0,
     379,     0,     0,     0,     0,     1,     3,     0,     0,     0,
       0,     0,     0,   972,     0,  1566,     0,     0,     0,     0,
       0,  1516,     0,     0,     0,  1517,     0,     0,     0,     0,
     960,   971,     0,   961,   966,   964,   967,   965,   962,   963,
     968,   969,   953,   954,   955,   956,   957,   958,   959,   980,
       0,     0,     0,   974,   979,     0,   976,   975,   977,     0,
    1499,     0,  1485,  1519,  1715,  1716,     0,  1303,  1306,  1309,
    1307,  1308,  1304,  1311,  1305,  1312,  1310,  1313,     0,  1300,
     539,   199,   200,   201,   202,     0,  1629,     0,     0,     0,
       0,     0,     0,     0,     0,   437,     0,   436,   425,   430,
     432,   429,   438,   426,   427,   428,   431,     0,     0,     0,
       0,     0,     0,  1279,  1282,  1281,  1283,  1284,  1285,     0,
       0,  1289,     0,  1557,  1545,  1541,     0,     0,     0,     0,
    1255,  1257,  1258,  1256,  1260,  1261,  1259,   951,     0,   100,
       0,     0,     0,   263,     0,     0,  1521,  1762,     0,     0,
    1489,  1706,  1638,     0,     0,     0,  1774,  1775,     0,     0,
       0,  1764,     0,     0,  1418,  1439,     0,     0,     0,     0,
       0,  1501,     0,     0,     0,     0,  1483,  1484,  1487,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1518,
       0,  1476,     0,     0,     0,     0,     0,  1497,  1498,     0,
       0,     0,     0,  1514,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1771,  1770,  1447,  1488,  1438,  1440,
    1441,     0,     0,  1522,     0,  1471,     0,  1492,     0,  1500,
    1496,     0,     0,  1494,     0,     0,  1714,     0,  1717,     0,
       0,   699,   751,   757,   778,   737,   766,   781,   700,   800,
     801,   701,   764,   702,   805,   807,   703,   704,   705,   706,
     707,   708,   709,   710,   711,   712,   713,   788,   714,   715,
     716,   806,   803,   804,   717,   718,   719,   720,   721,   723,
     722,   724,   725,   726,   727,   728,   729,   730,   732,   733,
     735,   736,   738,   739,   740,   741,   742,   743,   734,   744,
     745,   746,   747,   748,   749,   750,   782,   783,   785,   784,
     752,   753,   754,   755,   756,   758,   759,   767,   768,   769,
     770,   771,   772,   773,   774,   775,   776,   791,   792,   793,
     794,   797,   795,   796,   798,   799,   731,   802,   760,   761,
     762,   763,   765,   777,   779,   780,   786,   809,   808,   787,
     789,   790,   696,     0,   565,     0,     0,   559,     0,   563,
       0,     0,     0,   585,     0,     0,     0,     0,   579,     0,
       0,  1381,     0,     0,  1782,     0,  1317,  1318,  1319,  1320,
    1321,  1322,   610,   611,     0,     0,   591,     0,     0,  1271,
    1273,  1275,  1276,  1277,  1274,  1269,     0,     0,   268,     0,
       0,     0,     0,  1263,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   861,   870,   862,   869,   873,   875,
     876,   877,   879,   874,   878,   868,   871,   864,   863,   865,
     866,   867,   872,   880,   881,     0,     0,     0,     0,  1336,
       0,     0,     0,     0,     0,   271,   274,     0,   277,  1365,
       0,   276,     0,   275,   282,     0,   279,   272,   273,     0,
       0,     0,     0,   882,   890,     0,   442,     0,   399,     0,
       0,     0,  1329,     0,     0,   830,     0,     0,     0,     0,
       0,     0,     0,  1693,     0,     0,     0,     0,  1370,  1371,
    1372,  1508,  1507,  1694,     0,     0,  1398,     0,     0,   841,
       0,   840,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   501,   502,   506,   507,   509,   510,   511,   842,   843,
     844,   512,   514,   513,   515,   516,   846,   521,   503,   504,
     505,   845,   532,   500,   508,   517,   518,   519,   520,   524,
     525,   526,   527,   528,   529,   522,   523,   847,   530,   531,
     850,   838,     0,   139,   183,   191,     0,     0,   188,     0,
     206,   548,   547,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   895,   301,
     300,     0,  1286,     0,   447,   448,   449,     0,     0,  1486,
       0,     0,  1776,  1364,     0,  1363,     0,   453,   461,   454,
     462,   458,   457,   464,   465,   455,   456,   459,   460,   463,
     102,     0,     0,     0,     0,   349,   350,     0,     0,  1442,
    1785,     0,     0,  1216,  1218,  1223,  1222,  1221,  1224,  1217,
    1219,  1220,   939,     0,     0,  1353,     0,     0,     0,   476,
     477,     0,   475,     0,     0,     0,     0,     0,     0,  1344,
    1345,  1346,  1347,  1348,  1349,     0,     0,   424,     0,  1384,
    1639,     0,   533,   490,   538,   537,   534,   535,   536,   487,
       0,     0,     0,     0,  1226,  1228,  1230,  1229,  1233,  1234,
    1235,  1236,  1227,  1231,  1232,   943,     0,     0,     0,   925,
     926,   927,   899,   930,     0,   929,   931,   932,   903,     0,
       0,   910,     0,     0,     0,   920,   921,   923,   922,   917,
     832,     0,     0,     0,   119,   147,   155,   152,     0,   136,
     159,   167,   164,     0,   137,   171,   179,   176,     0,   827,
       0,   138,   195,     0,  1558,  1542,  1543,  1544,  1540,     0,
       0,     0,     0,     0,     0,  1448,     0,  1238,  1241,  1242,
    1243,  1244,  1245,  1246,  1248,  1247,  1252,  1253,  1249,  1250,
    1251,  1239,  1240,   947,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1163,  1210,  1196,
    1197,  1198,  1199,  1200,  1212,  1201,  1202,  1203,  1204,  1205,
    1207,  1206,  1211,  1164,  1165,  1166,  1167,  1168,  1169,  1170,
    1171,  1172,  1173,  1174,  1175,  1176,  1177,  1178,  1179,  1188,
    1180,  1181,  1189,  1191,  1190,  1182,  1183,  1192,  1184,  1185,
    1186,  1187,  1193,  1194,  1195,  1208,  1209,  1213,  1214,     0,
       0,     0,     0,     0,     0,   616,   617,   618,   619,   620,
     621,   622,   623,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1657,     0,  1658,     0,     0,     0,     0,
    1660,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1031,
       0,   982,  1028,   983,   984,   985,   986,   987,   988,   989,
     990,   991,   992,   993,   994,   995,   996,   997,   998,   999,
    1000,  1001,  1002,  1003,  1004,  1005,  1006,  1007,  1008,  1009,
    1010,  1011,  1012,  1013,  1014,  1015,  1016,  1017,  1018,  1019,
    1020,  1021,  1022,  1023,  1024,  1025,  1026,  1027,  1029,     0,
    1747,  1758,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1756,  1749,     0,  1085,     0,  1070,  1071,  1072,  1079,
    1073,  1074,  1075,  1076,  1077,  1078,  1080,  1081,  1083,  1082,
    1088,  1751,  1049,     0,  1034,  1035,  1036,  1042,  1046,  1047,
    1037,  1038,  1039,  1040,  1041,  1043,  1045,  1044,     0,  1721,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1157,     0,  1127,  1128,  1129,
    1122,  1123,  1124,  1125,  1126,  1130,  1131,  1132,  1133,  1134,
    1135,  1136,  1137,  1138,  1139,  1140,  1121,  1141,  1142,  1143,
    1144,  1145,  1146,  1147,  1148,  1149,  1150,  1151,  1152,  1153,
    1154,  1155,     0,     0,  1741,     0,  1118,     0,  1113,  1112,
    1110,  1111,  1114,  1115,  1116,     0,     0,     0,     0,  1743,
    1107,     0,  1098,  1099,  1100,  1104,  1105,  1101,  1102,  1103,
    1750,  1095,     0,  1090,  1091,  1092,  1093,     0,  1067,     0,
    1052,  1053,  1054,  1059,  1064,  1065,  1056,  1057,  1058,  1060,
    1061,  1063,  1062,  1055,     0,     0,     0,     0,     0,     0,
       0,     0,   382,   383,   385,   384,   386,   387,   388,  1702,
    1703,     0,     0,   391,   395,   392,   393,   394,     0,     0,
    1711,  1713,     0,   480,   481,   482,   483,   484,     0,     0,
       0,   469,   470,   471,     0,   635,     0,     0,     0,     0,
       0,   630,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   252,     0,     0,     0,     0,   251,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   211,   210,   626,
     688,   631,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   540,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1290,     0,
       0,     0,     0,     0,     0,   101,     0,     0,     0,   262,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   562,     0,   558,   255,
     561,     0,     0,     0,   584,     0,     0,     0,     0,   578,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   590,
       0,     0,     0,     0,     0,   267,     0,     0,     0,     0,
    1264,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1337,     0,     0,     0,
       0,   111,     0,     0,     0,   289,     0,   290,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   892,     0,   443,
       0,     0,     0,   398,     0,     0,  1330,     0,     0,   829,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   184,
     189,   186,   194,     0,   141,     0,     0,   145,   143,   207,
       0,     0,     0,     0,   315,   314,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   348,     0,     0,     0,     0,     0,     0,     0,
       0,  1352,     0,     0,     0,     0,     0,     0,   414,   551,
     420,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1295,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   909,     0,     0,     0,
       0,   122,   120,   148,   153,   150,   158,   160,   165,   162,
     170,   172,   177,   174,   182,     0,   824,   825,   196,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   103,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   359,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   625,     0,     0,     0,     0,
       0,     0,   669,     0,     0,     0,   687,     0,     0,     0,
       0,     0,   224,   223,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   208,     0,     0,     0,     0,  1562,  1563,  1564,
    1565,  1561,  1567,  1405,  1415,  1792,     0,  1409,     0,  1408,
    1434,  1435,  1509,  1510,     0,   970,     0,  1568,  1460,  1495,
     978,     0,  1511,  1504,  1299,     0,  1302,     0,   203,  1626,
    1627,  1628,  1391,  1395,  1382,  1402,  1360,   435,   434,  1462,
       0,  1637,  1631,  1632,  1634,  1633,  1635,  1636,  1378,  1367,
    1280,  1278,     0,  1288,     0,  1550,  1551,  1552,  1553,  1554,
     950,     0,  1254,   854,     0,   852,     0,   260,     0,     0,
    1369,  1414,  1407,  1470,  1461,  1537,  1538,  1539,  1406,  1413,
    1412,  1453,  1455,  1454,  1456,     0,  1449,  1411,  1410,  1373,
       0,  1772,  1502,  1503,  1436,  1437,  1529,  1531,  1528,  1530,
    1532,  1533,  1463,  1466,  1472,  1467,  1481,  1482,  1464,  1465,
     554,     0,     0,   556,   555,  1477,  1479,  1478,  1474,  1475,
    1473,  1523,  1512,     0,     0,  1513,  1515,  1767,  1766,  1768,
    1769,  1569,  1570,  1572,  1571,  1573,  1574,  1576,  1575,  1577,
    1578,  1580,  1579,  1581,  1582,  1583,  1584,  1585,  1586,     0,
    1366,  1520,  1480,  1491,  1490,  1493,  1526,  1525,  1527,  1765,
    1534,  1535,  1536,     0,  1718,   698,   695,     0,     0,   557,
     602,   603,   605,   606,   608,   604,   607,   609,   256,     0,
       0,     0,     0,     0,   583,     0,     0,     0,   575,     0,
       0,  1380,  1379,  1315,  1316,   612,   613,   589,     0,  1272,
    1268,     0,     0,   265,   546,     0,     0,     0,     0,     0,
    1262,     0,  1763,  1621,  1625,  1624,  1623,  1622,  1616,  1617,
    1592,   859,   860,   257,     0,     0,  1334,     0,     0,     0,
       0,   856,     0,   298,     0,   296,     0,     0,   287,   288,
       0,   292,  1394,     0,  1397,     0,   281,   285,  1505,  1506,
       0,   889,     0,     0,   441,   440,     0,   396,     0,  1328,
       0,   828,     0,   833,     0,     0,     0,   836,  1773,  1359,
    1368,  1392,  1393,  1375,  1376,  1388,  1387,  1401,  1399,  1361,
    1400,   839,   849,     0,   190,   187,   192,   142,     0,   146,
     144,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   299,   310,   311,   306,   307,   308,   309,
     302,   303,   305,   304,   312,   896,     0,     0,   446,   445,
    1389,  1390,  1383,  1396,  1362,   452,   451,   857,     0,     0,
       0,     0,   346,     0,  1443,  1786,  1787,   938,     0,  1215,
       0,  1358,  1350,     0,     0,   549,   550,     0,     0,     0,
       0,     0,   418,   474,   473,  1777,     0,  1780,     0,  1779,
    1342,  1343,     0,     0,  1294,     0,   423,   422,  1377,  1385,
     489,   486,     0,  1445,  1444,  1446,   942,     0,  1225,     0,
    1524,   924,   898,     0,   928,   902,     0,   906,   907,     0,
       0,     0,     0,   908,  1386,  1761,   919,   916,     0,     0,
       0,   154,   151,   156,   166,   163,   168,   178,   175,   180,
     826,  1546,  1547,  1548,  1549,  1559,  1560,     0,  1451,  1555,
    1556,   946,     0,  1237,   934,  1587,  1588,  1589,  1590,  1591,
    1593,  1594,  1595,  1596,  1597,  1598,  1599,  1600,  1601,  1602,
       0,     0,  1603,  1604,  1605,     0,     0,     0,  1609,  1610,
       0,  1612,  1613,  1614,  1615,  1618,  1619,  1620,  1161,  1162,
    1403,  1404,  1416,  1417,  1419,   615,   614,  1642,  1643,  1644,
    1645,  1646,  1647,  1648,  1649,  1650,     0,  1652,  1653,  1654,
    1655,  1656,  1659,  1661,  1662,  1663,  1664,  1665,  1676,  1673,
    1687,  1688,  1692,  1666,  1669,  1670,  1671,  1672,  1674,  1675,
    1677,  1678,  1679,  1680,  1681,  1682,  1683,  1684,  1685,  1686,
    1689,  1690,  1691,  1723,  1030,  1033,     0,  1759,  1719,  1748,
    1722,  1720,  1752,  1754,  1753,  1755,  1757,  1739,  1084,  1087,
       0,  1048,  1051,  1667,  1668,  1724,  1725,  1726,  1727,  1728,
    1729,  1730,  1731,  1732,  1733,  1734,  1735,  1736,  1737,  1738,
    1156,  1159,  1640,  1641,  1740,  1117,  1120,  1744,  1746,  1745,
    1742,  1106,  1109,  1094,  1097,  1760,  1066,  1069,     0,     0,
       0,   365,   366,     0,   358,     0,     0,  1810,  1696,  1695,
    1697,  1698,  1699,  1700,   381,   380,  1705,  1704,   390,   389,
    1708,  1709,  1710,  1712,   479,   478,  1783,  1784,   468,   466,
     467,     0,     0,     0,   629,   624,     0,     0,     0,   670,
       0,     0,     0,   688,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   209,   221,   222,   217,   218,
     219,   220,   212,   213,   215,   214,   216,     0,     0,     0,
       0,     0,   683,   684,   685,   686,     0,   689,   633,  1792,
       0,  1793,  1795,     0,  1799,  1797,     0,   973,   981,  1301,
       0,   198,   204,     0,     0,     0,   952,   855,   853,   264,
       0,  1457,     0,     0,   552,   553,     0,  1801,     0,  1805,
    1803,     0,   812,     0,     0,   821,     0,   697,   564,   255,
     560,   255,     0,     0,     0,     0,     0,   582,     0,     0,
       0,  1270,   627,   690,   637,     0,   544,   545,     0,     0,
       0,     0,  1266,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   284,     0,     0,   886,     0,
       0,   883,     0,   891,     0,     0,     0,     0,     0,     0,
     834,     0,   851,   193,   140,     0,     0,   327,   328,   316,
     317,   318,   319,     0,   331,     0,   320,   321,   322,   323,
     324,   325,   341,   326,     0,   338,     0,   340,   342,     0,
     343,     0,     0,     0,     0,     0,     0,     0,   940,     0,
    1355,  1357,  1354,     0,   419,   413,   406,     0,   416,     0,
       0,     0,     0,  1293,     0,   488,   944,     0,   900,   904,
     905,   911,   912,   913,   914,   918,     0,     0,   157,   169,
     181,     0,   948,  1811,  1813,  1812,   543,   542,     0,     0,
       0,     0,     0,     0,  1089,     0,     0,   361,   357,     0,
    1808,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   658,   659,   667,   665,   660,   663,   662,   668,
     666,   664,   661,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   236,   237,   225,   226,   227,   228,
       0,   240,     0,   229,   230,   231,   232,   233,   234,   250,
     235,     0,   247,     0,   249,   253,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   646,   647,   655,   653,   648,
     651,   650,   656,   654,   652,   649,     0,     0,     0,  1796,
    1800,  1798,  1788,   205,  1630,   405,     0,     0,     0,     0,
    1450,  1374,  1802,  1806,  1804,     0,     0,  1468,     0,     0,
    1469,   256,     0,     0,     0,   566,     0,     0,     0,     0,
     580,   576,     0,     0,     0,     0,     0,     0,     0,   270,
       0,     0,   259,  1326,  1327,     0,     0,     0,  1789,     0,
       0,     0,   297,   295,     0,     0,   291,   278,     0,   280,
       0,   893,     0,     0,     0,     0,     0,     0,   831,     0,
     837,     0,     0,     0,     0,     0,     0,     0,     0,   336,
       0,     0,   352,     0,     0,     0,  1356,     0,     0,   417,
    1778,  1781,     0,  1296,  1707,     0,     0,  1452,  1606,  1607,
    1608,  1611,  1651,     0,   362,     0,  1701,     0,  1809,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1459,     0,     0,   671,     0,     0,   689,     0,
       0,     0,     0,     0,     0,     0,   245,  1429,  1427,  1428,
     682,   676,     0,     0,     0,     0,     0,     0,  1794,     0,
     401,     0,     0,   628,   692,   641,     0,   261,  1458,   810,
     811,   813,   818,     0,   819,   822,   255,   255,   255,     0,
       0,   588,     0,   577,   592,     0,     0,   691,   639,     0,
     266,  1265,   258,     0,  1338,     0,     0,  1335,     0,   115,
       0,   294,   345,   887,     0,     0,   397,  1331,     0,     0,
       0,     0,   835,   329,   330,   332,     0,   333,     0,     0,
       0,   344,  1287,     0,     0,   351,   347,     0,   415,     0,
       0,   126,     0,     0,   107,     0,     0,   360,  1807,  1420,
    1424,  1426,  1433,  1422,  1431,   593,   594,   596,   597,   599,
     595,   598,   600,   601,  1421,  1430,  1425,   657,   636,     0,
       0,   672,     0,     0,   690,     0,   238,   239,   241,     0,
     242,     0,     0,   254,  1423,  1432,   645,   632,     0,     0,
     404,     0,   400,     0,     0,     0,     0,     0,   816,     0,
     570,   567,   571,     0,   586,   581,     0,     0,     0,     0,
     269,     0,     0,     0,     0,     0,   112,   113,   118,     0,
     286,     0,     0,     0,  1790,     0,     0,     0,     0,   313,
     354,   353,     0,  1297,     0,   123,   124,   132,   129,   121,
       0,   104,   105,   110,     0,     0,     0,   371,     0,   372,
     373,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   677,     0,   403,     0,     0,     0,   412,     0,     0,
     693,   643,     0,     0,   820,     0,   255,     0,   678,     0,
       0,     0,     0,  1324,     0,     0,   114,   116,   293,     0,
       0,     0,     0,   334,   337,   339,  1351,   125,   130,   127,
     135,   106,   108,     0,     0,     0,     0,   363,     0,   374,
       0,     0,   674,     0,   673,   692,     0,   691,   243,   246,
     248,   634,   402,     0,     0,  1291,     0,   411,     0,     0,
       0,     0,   814,   815,   817,     0,   572,   587,   638,     0,
       0,  1325,  1339,  1340,   117,   355,     0,  1332,  1333,   131,
     128,   133,   109,     0,     0,     0,     0,     0,     0,   370,
       0,     0,     0,   409,     0,   410,     0,   680,     0,     0,
       0,   255,   255,   679,     0,  1791,   134,     0,     0,     0,
       0,     0,     0,   368,     0,   675,   693,     0,   408,   642,
       0,     0,   568,   573,   640,     0,     0,     0,     0,   364,
     369,   367,   407,   681,     0,     0,     0,     0,   375,     0,
     644,   574,   376,   377,     0,   378
  };

  const short
  parser::yypgoto_[] =
  {
   -2969, -2969,  3321, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969,   230, -2969, -2969, -2969, -2969,  -766,
   -2969,  -316, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969,   924, -2969, -2969, -1697, -2969, -2969, -2969,  -251,
    -506, -2969,  1047,  -759, -2969,  1667, -2969, -2969, -2969, -2969,
     507, -1637, -2969,   518,   349, -2969, -2969, -1608, -2969,   919,
    -983,  -273, -2969, -2969, -2969,  1343, -2969, -2969, -2969,  -105,
     -96, -2969,     8, -2969, -2969, -2969,  1344, -2969, -2969,  1345,
   -2969,  1018,   525, -2969,    42, -2969,   922, -2969, -2969,  -219,
   -2969, -2969,  1840, -2969, -2969,  1679, -2969, -2969,  -191, -2969,
   -2969,  -197, -2969, -2969,  3088,  1347, -2969, -2969,  1572, -2969,
   -2969,  1349, -2969, -2969,  -158,  1559,   697, -2137, -1676,  1754,
    -989, -2969, -2414, -2969, -2969,  2789, -2969, -2969, -2968, -2969,
    1101,  -733, -2969, -2969,  2792, -2969, -2969,  2718, -2969, -2705,
   -2969, -1409, -2969, -2969, -2969,  1481, -2969, -2969,  3117, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2852,   244,
   -2969,   271, -2969,  3135, -2969, -2720,   411, -2969,  3137, -2969,
   -2969,  1816,   394, -2969,    58, -2969,   396, -2969, -2969, -2969,
   -2969, -2969, -2969,  2687, -2969, -2969, -2969, -2969, -2969,  1716,
   -2969, -2969, -2969, -2969, -2969, -2969,  1775, -2969, -2969,  -134,
   -2969,  1752, -2969, -2969, -2969, -2969, -2969, -2969,   954, -2969,
   -2969,  2455, -2969, -2969,  1604, -2969,  1617, -2969,  -245, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969,   -61,  1942, -2969,
   -2969,  1939, -2969, -2969,  1499, -2969, -2969,  1484, -2969, -2969,
    1456, -2969, -2969,  1491, -2969, -2969,  1463, -2969, -2969,  1469,
   -2969, -2969,  1478, -2969, -2969,  1486, -2969, -2969,  1554, -2969,
    1673, -2969,  1640, -2969,  1589, -2969,  1924, -2969, -2969, -2969,
    2793, -2969, -2969,  1829, -2969, -2969,  1937, -2969, -2969, -2969,
    3073, -2969, -2969, -2969,  1672, -2969,  1962, -2969, -2969,  1839,
   -2969, -2969, -2716, -2969, -2969,  2757, -2969,  1156,  -798, -2969,
    1698, -2969, -2969,   370, -1012,  1687, -2969,    93, -2969, -2969,
   -2969, -2969,  -156,  -116,  -111, -2969,  -206, -2969, -2969, -2969,
    -110,  -100, -2969, -2969, -2969,   235, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
    -175, -2969, -2969, -2969, -2969, -2969, -2969,   -88, -2969, -2969,
    -148, -2969,  -179,  -213,   -73, -2969, -2969,  -196, -2969, -2969,
   -2969, -2969, -2534, -2519, -2516, -2969, -2969, -2500, -2488, -2969,
   -2969, -2969, -2480, -2478, -2969, -2969,  -200,  -207, -2969,  -229,
    -212, -2969,  -259, -2969, -2969, -2969, -2969,  -199, -2969,  -194,
   -2969, -1536,   971,  1487, -2969,  -233, -2969,  -307, -2969, -2969,
   -2969, -2969,  -164, -2969, -2969, -2969, -2969,  -299, -2969, -2969,
   -2969, -2969, -2969,  -150, -2969, -2969, -2969, -2969,  -208, -2969,
   -2969, -2969, -2969, -2969, -2969,   -64,  -225, -2969, -2969,   -55,
     -51,   -93, -2969,  -223, -2969,   -50, -2969, -2969, -2969,  -216,
    -215,   -49, -2969, -2969, -2969, -2969,   -47,   -46, -2969,  -127,
   -2969,   -44,   -43, -2969,  -238,   -40,   -33, -2969, -2969, -2969,
     -32,   -30,   -26,    -9, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969,  -293, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969,  -274,  -272, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969,    49,  -218, -2969, -2969, -2969,  -323,  -311,  -305,  -302,
    -275, -2969, -2969, -2969, -2969, -2969,  -267,  -265,  -262, -2969,
    -252, -2969, -2969, -2969,  -209,  -195,  -192, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969,  -342, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969,  -160,  -230, -2969, -2969, -2969, -2969, -2969,
      -8,    -6, -2969, -2969,  -282,  -185, -2969,  -202,  -165, -2969,
   -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969, -2969,  -184, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969,  -186,  -170,  -270, -2969, -2969,  -166,  -159,  -155,
    -153,  -348,  -142,  -141, -2969, -2969,  -221,  -268, -2969, -2969,
   -2969, -2969, -2969,    -1, -2969, -2969, -2969, -2969, -2969, -2969,
   -2969, -2969, -2969,  -137, -2969, -2969,  -231,  -228, -2969, -2969,
   -2969, -1343, -2010, -2969, -1384, -2969, -1259, -2969,   357, -2969,
   -1944,     0
  };

  const short
  parser::yydefgoto_[] =
  {
       0,   113,   114,   115,   116,   117,  2706,  3333,   118,  2412,
    3298,   119,  2590,  2589,  3330,   120,   121,   122,   123,  1814,
     927,   928,   330,   332,   334,   284,   337,   124,   455,  2207,
     125,   126,  3131,  2173,  3086,  3134,   127,   128,   129,   512,
     513,   130,   767,   768,   131,   824,   825,   132,   814,  2930,
    1764,  1765,  2414,  2415,  1766,  1857,  2971,  1767,   133,   994,
     995,   996,   134,   367,  2098,  2099,  3335,  3547,  3337,  3548,
    3438,  3439,  3440,   135,   136,  1501,  1502,   137,  1512,  1513,
     138,   839,  3116,   139,  3456,  1887,  1888,   140,  1036,   465,
     141,   466,   467,   142,   835,   836,   143,   963,  1019,   144,
     976,  1020,   145,   146,  1530,  1531,   147,  1021,  1022,   148,
    1522,  1523,   149,  1041,  1073,  1043,  3017,  3018,  2387,  1577,
    2293,  2294,  2295,   150,   726,   727,   728,  2360,  3135,   151,
     737,   738,   152,   732,   733,   153,   755,   756,  3354,  2361,
     753,   754,   154,   155,  1234,  1235,   156,   157,   158,  1540,
     159,  2175,  3107,  2122,  3145,  3399,  3385,  3521,  3094,  3095,
    3041,  3042,   160,   161,   162,  2841,  2842,   163,   164,   165,
     610,   611,  2882,  2883,  3388,  3389,  2885,  2886,   166,   336,
    1108,   167,   844,   845,   168,   169,   847,   170,   870,   871,
     171,   172,   173,   174,   175,   176,   783,   784,   177,   269,
    2929,   270,   178,   288,  1856,   179,   180,  2576,  2577,   181,
    1080,  1081,   182,  1084,  1085,  1068,  1069,  1074,  1086,   183,
     184,   185,   186,   187,   188,   189,   400,   401,   402,   190,
     424,   425,   191,  1289,  1290,   192,  1372,  1373,   193,  1478,
    1479,   194,  1354,  1355,   195,  1471,  1472,   196,  1460,  1461,
     197,  1446,  1447,   198,  1405,  1406,   199,   200,  1176,  1177,
    1002,  1003,  1053,  1054,  1126,  1127,   499,   500,   201,   772,
     773,   202,   758,   759,   203,   482,   483,   204,   205,   490,
     491,   206,  1035,  1901,  1902,   207,   436,   437,   208,   745,
     746,   209,  3156,   210,   841,   842,   211,   808,   809,   212,
    1028,  1029,   213,  1014,  1015,  2530,   872,   873,   874,   979,
     980,   981,   875,   876,   877,   878,   879,   880,   881,   882,
     883,   884,   885,   886,  1044,   887,   748,   749,   750,   469,
     982,  1045,  1087,   888,   889,   983,   984,   470,   890,   827,
     471,   986,   828,   891,   892,   893,   894,   895,  1236,  1237,
     403,   619,   620,   404,   897,   623,   624,   405,  1238,  1239,
     625,  1240,  3096,  3097,  3098,  3099,  3046,  3100,  3101,  2843,
    2844,  2845,  3102,  3103,  3104,  3051,   406,   407,   628,   629,
     898,   631,  1007,  1008,  1059,  1060,  1061,   899,  1128,   900,
    1129,  2871,  2872,  1541,   426,   634,   486,   635,   636,   637,
     638,   639,   640,   641,   642,   643,   644,   645,   646,   647,
     648,   649,   650,   651,   652,   653,   654,   655,   441,   987,
     657,   658,   659,   660,   661,   902,   427,   664,   665,   903,
     442,   904,   669,   670,   671,   443,   830,   905,   906,   408,
     409,   444,   676,   677,   678,   679,   410,   411,   682,   445,
     684,   907,   908,   687,  1076,   909,   910,   690,   691,   692,
     911,   912,   913,   914,  1130,   501,  1131,  1132,  1133,   502,
    1134,  1135,   503,   504,   505,  1136,  1137,   506,  1138,  1139,
    1140,   412,   413,   414,   415,   416,   417,   418,   428,   697,
     698,   699,   700,   701,   702,   703,   704,   705,  1193,  1194,
    1195,  1196,  1197,   795,  1199,  1200,  1201,  1202,  1203,  1204,
    1205,  1206,  1207,  1208,  1209,  1210,  1211,  1212,  1213,  1214,
    1215,  1216,  1217,  1218,  1219,  1220,  1221,   796,  1222,  1223,
    1224,   797,   798,   799,   800,   801,   473,   474,   475,   476,
     487,   488,   706,  1048,  1448,  1449,  1293,  1294,  1295,  1296,
    1297,  1298,  1299,  1300,  1301,  1302,  1303,  1304,  1305,  1306,
    1307,  1308,  1309,  1310,  1311,  1312,  1313,  1422,  1314,  1315,
    1316,  1317,  1318,  1319,  1320,  1321,  1322,  1323,  1324,  1325,
    1326,  1327,  1328,  1329,  1330,  1331,  1332,  1333,  1334,  1335,
    1336,  1337,   915,   916,  1503,  1504,  1505,  1506,  1507,  1508,
    1515,  1516,  1517,   707,  1077,  1524,  1525,  1526,  1527,   708,
     446,   447,   711,   712,  1356,  1357,  1425,  1358,  1338,  1427,
    1428,  1429,  1430,  1431,  1432,  1433,  1434,  1435,  1436,  1437,
    1438,  1439,  1440,  1441,  1359,  1453,  1454,  1465,  1466,  1467,
    1468,  1469,  1360,  1361,  1362,  1476,  1381,  1363,  1364,  1365,
    1366,  3105,  1368,  1369,  1493,  1088,   713,   804,   714,   715,
     716,   717,   718,   918,   919,   720,   721,   988,  1030,  1031,
    1032,  1033,  1034,   989,  1532,  1533,  1010,  1011,  2193,  2409,
    3177,  2851,  2852,  2188,  2189,  2304,  2767,  3031,  2768,  2631,
    2632,  1578
  };

  const short
  parser::yytable_[] =
  {
     214,   838,  1881,   222,  1719,  1367,  1639,   805,  1735,   222,
    1756,  1872,  2359,   663,   222,  1097,   764,  1102,  1490,  1107,
     440,   222,   673,   674,   439,   621,   630,  1514,   788,  1890,
     656,   627,   614,   271,   793,  1410,   803,   761,   626,   632,
    1189,   222,   222,   285,   633,   789,   222,  1411,  1190,   222,
     762,   786,   222,  1412,  1198,   763,  1413,  1058,   790,   222,
     222,   222,   222,   791,   222,   222,   331,   333,   335,  2395,
     338,   222,   438,  1225,  1374,  1226,  1423,  1075,  1450,  1228,
    1462,  1070,  1473,  1414,  1480,  1063,  1380,  1005,  1064,  1071,
     618,  1415,  1037,  1416,  1475,  1047,  1417,   977,   222,   510,
     511,   964,   896,  1056,  1006,  1046,  1418,   792,   751,  1141,
     826,   683,  1142,   214,  1188,   484,  2266,   901,  1184,   985,
    1057,   917,   613,   869,  1192,  1292,  1227,  2418,   615,   812,
     794,   985,  1241,  1242,  1180,  1185,   834,   472,   616,  1191,
    1183,  1178,  1408,  1409,   966,   668,   785,  1182,  1186,  1419,
     617,  1181,  1004,  1187,  1376,  1042,  2419,   423,   966,  2771,
    1464,  1818,   991,  1420,  1482,   622,  1421,  2492,  1055,   811,
    1378,  1375,  1377,  1424,   662,  1451,  1452,  1463,  2855,  1474,
    1484,  1481,  1483,   666,  3133,   381,  1379,   667,   672,   675,
    1382,   680,   681,  1426,   685,   686,  1485,  1383,   688,  1179,
    1486,  1384,  1291,  1385,  -670,   689,   693,  1487,   694,  2519,
    1407,  1488,   695,  1489,  1386,  1387,  3013,  3015,   377,  2202,
    3174,   450,  2238,  2239,  1491,  1492,  2350,   392,   492,   696,
     709,   450,   710,   271,   271,   514,  2849,   719,  2849,   450,
     729,   734,   739,  3260,   931,  2185,  -672,   757,  2187,  -674,
     450,   766,   769,   215,   393,   774,   931,  3043,   514,   217,
    2907,   810,  3260,   271,  1050,  2420,   931,  2260,  2553,  2268,
     271,  1442,  3044,   992,   931,  3045,  2657,   843,   846,   848,
     508,  1528,   450,   450,   924,   932,  3300,  2934,   960,  2290,
     450,  3047,  2668,  1627,  2302,   450,   271,   932,  1091,  1639,
    2922,   450,  1016,  3048,  2847,  1066,   802,   932,  2259,  3391,
    2267,  3049,  1617,  3050,   450,   932,   931,   450,   468,  2351,
     450,  3287,   392,   450,  1925,  1782,   931,   450,   450,   931,
    1095,   612,  1100,   925,  1105,  1726,  1109,  1112,  3173,  2976,
     931,   450,  3460,  2759,   286,  2352,  2353,  2354,   931,  1009,
     931,  2428,   992,   931,   450,   931,  1096,   932,  2760,   931,
    2312,  2313,   931,   771,  3217,  1062,   232,   932,  2340,  2341,
     932,  1624,  2319,  2320,  1871,  1023,  1024,  1539,  1542,  1546,
    1550,   932,  1582,  1443,  1229,  1230,  3256,   978,  2538,   932,
    1703,   932,  2539,   992,   932,   931,   932,   304,  2429,   978,
     932,   287,   394,   932,   468,  3379,  1709,  2342,  2723,   999,
    1231,  1232,   931,   223,  2763,  3195,   931,  2608,   227,  1101,
    2305,  2306,   379,    38,  3285,  1106,  2724,  1810,  2290,   479,
    2094,  1853,  1854,   226,  3397,  1855,   932,  1051,  3032,  3033,
    3034,  3035,  3036,  3037,  3038,  3039,   228,  1757,  1607,  2333,
    1934,  1444,   931,   932,  1731,   931,   233,   932,  2355,   815,
     234,   485,  1938,  2853,  3572,  2336,  2337,  1942,  3261,  1000,
    3032,  3092,  3034,  3093,  3036,  3037,  3038,  3039,   931,  1079,
     747,   392,   816,   240,   760,  2874,  2916,  3261,  2875,  1626,
    2917,  2520,   787,   932,   224,   225,   932,   817,  2936,  3019,
    3020,  1025,  1026,  3021,  1772,   241,   429,   430,   393,  1027,
    2878,  2095,   514,  2096,  2097,  1779,   818,  1884,  1885,   932,
    3309,  1001,  3272,  2559,  3310,   246,   480,   965,  2565,  2291,
    2292,  2464,  2923,  2591,   251,  1067,   247,  2594,   931,  1884,
    1885,   965,  1618,  1807,  2356,  2609,  2610,  2597,  1845,  1846,
    1847,  1848,  1849,  1850,  1851,  1852,  1853,  1854,  1233,   489,
    1855,   993,  3055,  3427,  3488,   431,  1783,  1529,  3539,  1845,
    1846,  1847,  1848,  1849,  1850,  1851,  1852,  1853,  1854,   932,
     432,  1855,  2876,  2669,  2670,  2652,  2653,  1859,   926,  1884,
    1885,   837,  2540,  3582,  2384,  2178,  3218,   819,  2181,  1884,
    1885,  1625,  1884,  1885,   837,  3269,  3514,  3519,  1811,  1812,
     374,   926,  1866,  1884,  1885,  2314,   820,   392,  1495,  3530,
    1704,  3514,   433,  1884,  1885,  2848,  1884,  1885,  1884,  1885,
    3040,  2384,  1884,  1885,  1710,  1884,  1885,   958,   931,  1092,
     993,  1891,  3288,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,  3040,  3461,  3458,  2658,  2659,  1904,  2291,  2292,
    1908,  2290,   398,   399,   926,   931,  1758,   821,  3470,   932,
     926,   993,   926,  1917,  1732,  1884,  1885,  3474,  3475,  2357,
     396,  3572,  3573,  3110,  3043,  2854,  3262,  3481,  1777,  3482,
     221,  2186,   382,   822,  1343,   926,   231,   216,  3581,  3044,
    2350,   239,  3045,   218,  3308,  3305,   932,   926,   250,  2521,
    2796, -1833,   926,  1705,  2777,  1706,   729,  2937,  3047,   378,
    1711,  1712,   734,   509,  1773,  1716,  1717,   739,   282,   283,
    3048,  3293,  2879,   290,  1052,  1780,   295,  1346,  3049,   301,
    3050,  1884,  1885,  2392,  3014,   757,   314,   317,   320,   323,
    3525,   327,   328, -1833,  3123,  2776, -1833,   769,   341,  1445,
    1353,  2630,   774,  1808,  2849,  2421,   255,  2094,   823,  1935,
    1936,   276,  2703,  1900,  1939,  1940,   926,   931,   926,  1943,
    1944,  2712,   926,  1919,  2715,   354,  3301,   477,   392,   478,
    3559,  1726,   926,  2351,  2876,   514,  1929,  2276,   810,  1997,
     254,  1884,  1885,  2303,   960,   392,  2106,  1860,   926,   926,
    1551,  2541,  2109,   926,  3273,   393,  2385,  2386,   932,  2352,
    2353,  2354,   271,  2115,  3515,  3516,  2119,  1781,  2277,  2278,
    3109,   843,  1867,  3111,   846,  1886,   260,  1792,  2987,  3535,
    3516,  2119,   422,  2127,  3455,  3090,  1496,  3554,  2095,  3119,
    2096,  2097,   263,  2385,  3175,   264,  1552,  3126,  3522,  3129,
    3168,  1892,  3188,   277,  3119,   278,  3228,  3245,  1553,  3402,
     279,  3254,  1497,  1498,  1499,  1500,   296,  3090,  3090,  1351,
    1554,  1555,  3254,  3463,  3254,   348,   309,  1905,   351,  2542,
    1909,   235,   236,  1343,  3401,   324,   398,   399,  2235,  2236,
    2237,  2291,  2292,  1918,   434,   435,  2261,  2262,  2263,  3591,
    2264,  1351,  1809,   344,    38,   345,  1815,  1815,  1556,  1518,
    1519,  1520,  1521,  3090,  3090,  3254,   451,   960,   960,   723,
    3254,   368,  2355,   369,  3090,  3254,  1346,   370,  1884,  1885,
     380,  2169,  2170,  3153,  3154,  2171,  1497,   960,  1352,  1470,
     371,  1707,   372,  1509,  1510,  1536,  1511,   242,   243,   998,
     456,   244,   245,   394,   373,   457,   458,   459,   489,   383,
     999,   419,  1243,  1244,  1245,  1246,  1247,  3472,   515,   730,
     252,   253,  1869,  1870,   256,   257,  1253,  1254,  1255,  2850,
     479,   258,   259,  1260,  1388,   460,  1261,  1262,   261,   262,
     479,  1713,   480,   740,  1016,   452,   453,   454,  2261,  2262,
    2263,   752,  2264,  1920,  1727,   723,  1537,   461,  2356,  1268,
     462,  1851,  1852,  1853,  1854,  1903,  1930,  1855,   770,  1998,
    1000,  2265,   481,  2316,  2317,  2318,  2107,  2467,  2221,   806,
    2470,   807,  2110,   599,  2279,  2323,  2324,  2325,  1343,   813,
    1557,  1558,   735,  2116,   831,  2716,  2120,  1559,  1560,  1561,
    1562,  1563,  1564,  1565,  1566,  1567,  1568,  1569,  1570,   829,
     837,  2121,  1571,  2128,  1718,  3091,  1572,  1573,  1574,  3120,
     265,   266,  1001,  1933,   840,  2748,  2749,  3127,  1937,  3130,
    3169,  1346,  3189,  1941,  3207,  1389,  3229,  3246,  1947,   961,
    1948,  3255,  1921,  1922,  1923,  1924,    38,  3378,  3396,  2326,
    2327,  2328,  3452,  3464,  3469,  1288,  1390,  1391,  1392,  1393,
    1394,  1395,  1396,  1397,   929,  1398,  1399,  1400,  1401,  1402,
    1403,  1404,    38,  3247,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,  3518,  3529,  3558,    38,  2602,  2603,  2604,
    3564,   464,  1017,  2357,  3580,  3594,   930,  3155,   724,   997,
    1243,  1244,  1245,  1246,  1247,  1248,  1249,   272,   273,  1250,
    1251,   741,  3132,  1252,  1253,  1254,  1255,  1256,  1257,  1258,
    1259,  1260,    38,   725,  1261,  1262,  1263,  1264,  1265,  1266,
    1267,  2953,  1845,  1846,  1847,  1848,  1849,  1850,  1851,  1852,
    1853,  1854,   274,   275,  1855,   291,   292,  1268,  1269,  1270,
    1271,  1272,   293,   294,  1273,  1274,  1275,  1276,  1277,    38,
    1278,  1279,  1280,  1281,  1282,  1283,  1284,  2838,  2839,  2840,
    1285,  1286,  1287,   731,  2222,  2223,  2224,  2225,  2226,  2227,
    1018,  3176,   297,   298,   724,   302,   303,   305,   306,  1079,
    2964,  1845,  1846,  1847,  1848,  1849,  1850,  1851,  1852,  1853,
    1854,  1144,  1575,  1855,   307,   308,  1824,  1825,  1339,   725,
    2966,  1845,  1846,  1847,  1848,  1849,  1850,  1851,  1852,  1853,
    1854,   310,   311,  1855,  1494,  1576,  1844,  2167,  2168,  2169,
    2170,   342,   343,  2171,  2877,  2880,   346,   347,  2261,  2262,
    2263,   742,  2264,  1288,   456,  1583,   736,   349,   350,   457,
     458,   459,  1535,   480,  1584,  1585,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,   355,   356,   357,   358,   460,
     359,   360,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,   461,  1586,   743,   462,  1587,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,  1588,   440,   361,   362,  1589,
     439,  1847,  1848,  1849,  1850,  1851,  1852,  1853,  1854,  1590,
     744,  1855,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,  2954,  1591,  2607,  2911,  2161,  2162,  2163,  2164,  2165,
    2166,  2167,  2168,  2169,  2170,  2183,  1592,  2171,   438,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,   663,  2163,
    2164,  2165,  2166,  2167,  2168,  2169,  2170,   673,   674,  2171,
     621,   630,  1593,  2465,  2466,   656,   627,   614,   764,   463,
    2965,   363,   364,   626,   632,  1594,  1595,  3030,  1596,   633,
     365,   366,  1598,   484,  1597,  1599,  2258,  1600,  1601,   761,
    2967,  1602,   788,  1603,  1604,   464,  1605,  1606,   793,   472,
     803,  1609,   762,  2418,  1608,  1610,  1611,   763,  1612,   789,
     423,  1613,  2300,  1614,  1615,   786,  1616,  2310,  1619,  1890,
    1620,  2988,   790,  1621,  1622,   618,  1623,   791,  1629,  1630,
    1631,  1632,  2419,  2161,  2162,  2163,  2164,  2165,  2166,  2167,
    2168,  2169,  2170,  1633,  1634,  2171,   683,  1635,  1636,  3390,
    1637,  3392,  1640,  3268,  1642,  1641,  1643,   613,   751,   271,
    1644,  1645,  1646,   615,  2192,  2194,  1647,  1648,  1649,  1650,
     493,   792,  1651,   616,  2389,   222,   494,  1652,  2208,  1653,
     668,   495,   496,  1654,  2399,   617,   826,  2592,  2593,  1655,
    2405,  2595,  2596,  1656,   794,  2598,  2599,  1657,   896,  2234,
     622,  1638,  3412,   222,  3414,  1658,   222,   222,  1659,   662,
     785,  1660,  1661,   901,  1662,  2253,  3232,   917,   666,   869,
     271,  1715,   667,   672,   675,  1058,   680,   681,  1663,   685,
     686,  1664,  1665,   688,  2452,  1005,  1666,   735,  2508,  2515,
     689,   693,  2912,   694,  2574,  2299,   271,   695,  1667,  1070,
    1668,   271,  1006,  1063,  1189,  2556,  1064,  1071,  2322,  2898,
    1047,   985,  1190,  1669,   696,   709,  1670,   710,  1198,  1671,
    1046,  1056,   719,  1672,   222,  1673,  1674,  1675,  1367,  1676,
     468,   966,  1677,  1678,  1679,  1680,   985,  1225,  1057,  1226,
    1681,  1682,  1683,  1228,   497,   498,  1141,  1684,  1685,  1142,
    1004,  1686,   222,  1687,  1688,  1689,  1690,  1691,   271,  1692,
    1693,  1694,  1695,   966,  1490,  1696,  1697,  1698,   271,  1699,
    1042,  1700,  1701,  1410,   271,  1702,  1720,  2407,  1188,  2545,
    1721,  2547,  1184,  2416,   960,  1411,  1055,  1514,  1192,  3526,
    1227,  1412,  1794,  1722,  1413,   271,  1374,  2877,  1180,  1185,
    1723,  1241,  1242,  1191,  1183,  1178,    38,  2440,  1380,  1724,
    2172,  1182,  1186,  2446,  1423,  1181,   612,  1187,   271,  1450,
     802,  1414,  1725,  1730,  3536,  1462,  1733,  1473,   222,  1415,
    1480,  1416,  1736,  1815,  1417,  2601,  1815,  1292,  1737,  1475,
     960,   960,   960,   960,  1418,  1750,   960,   960,   960,   960,
     960,   960,   960,   960,   960,   960,   960,   960,   960,   960,
     960,   960,   960,  1179,    38,   960,   960,   960,   960,   960,
     960,   960,   960,   960,   960,   960,  1376,  1738,  2650,   485,
    1408,  1409,  1741,  1742,  1743,  3583,  1744,  1419,  1745,  1746,
    2664,  1747,  1378,  1375,  1377,  2525,  2526,   222,  1748,  2531,
    1749,  1420,  2531,  2534,  1421,  1464,  1751,  3122,  1379,  3124,
    1482,  1424,  1382,   271,  1291,   271,  1451,  1452,  1753,  1383,
     222,  1903,  1463,  1384,  1474,  1385,  1484,  1481,  1483,   222,
    1343,  1426,  2708,   222,  2710,  2711,  1386,  1387,   222,  1754,
    2578,  1761,  1485,  1759,  1760,  1768,  1486,  1009,  1407,  1769,
     222,   736,  1770,  1487,  1771,  1774,  1775,  1488,  1778,  1489,
    1784,  1787,  1790,  1795,  1796,  2600,  1797,  1798,  1799,   271,
    1491,  1492,  1345,  1346,  1800,  1801,   222,  1802,  3338,   978,
     747,  3340,  1803,  1062,  1804,  3344,   760,  3355,  3356,  1805,
    1455,  1456,  1457,  1458,  1459,  1806,   926,  2780,  1819,  2782,
    2783,  1820,  1821,  2786,   978,  1858,   787,  1822,  1823,  1826,
    1827,  1828,   271,  2651,  1872,  1829,  2542,   468,  2870,  1830,
    1831,  1832,  1833,  1861,   271,  1834,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,  1835,  1862,  1836,  1863,  1837,
    1838,  1864,  1865,  1839,  1340,  1874,  1840,  1841,   525,  1842,
    1843,  -335,   959,  1875,  1868,  1873,   271,  1876,   271,   271,
    1878,  1877,  1879,  1882,  1883,  1893,  1894,   222,  1341,  1342,
    1895,  1896,  1897,  1898,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,  1899,  1906,  1907,  1910,  1911,  1912,  1913,
    1914,  1915,  1916,  1927,   965,   384,   385,   386,   535,   536,
    3249,   387,   388,   389,   390,  1928,  1931,  1932,  1949,  1950,
    1951,   271,  1952,   271,   271,  1953,  1954,   271,  1955,   391,
    1956,  1756,  1957,  2792,  2793,  1959,   965,  1542,  1958,   392,
    2797,  2798,  1960,  2800,  2801,  2802,  3270,  2804,  1961,  3274,
    1962,  1963,  1964,  1965,  1966,  2123,  1967,  1968,  2943,  1969,
    1735,  1970,  1971,  2913,  1972,  1973,   393,  1974,  1975,  1976,
    1977,  1978,  1979,  1980,  1981,   838,  1719,  1982,  1983,  2471,
    2472,  2473,  2474,  1984,  1985,  2475,  2476,  2477,  2478,  2479,
    2480,  2481,  2482,  2483,  2484,  2485,  2486,  2487,  2488,  2489,
    2490,  2491,  1986,  1987,  2494,  2495,  2496,  2497,  2498,  2499,
    2500,  2501,  2502,  2503,  2504,   450,  1988,  2862,  1989,  2161,
    2162,  2163,  2164,  2165,  2166,  2167,  2168,  2169,  2170,  1991,
     222,  2171,  1990,  1992,  1993,  1994,   586,  1995,  1996,  1999,
    3339,   588,  2000,  2001,  3343,  2002,  2003,  1343,  2004,  2005,
    1344,   450,  2006,  2007,   450,  2008,   450,  2009,  2010,   514,
    2011,  2012,  2013,   480,  2014,  2015,   517,   775,   518,  2016,
    2017,  2018,  2019,  3374,  2020,  2021,   392,  2022,  2023,  2024,
     222,  2025,   735,  2026,  2027,  3008,  2028,  2029,  3009,  1345,
    1346,  3010,  1347,  1348,  2030,  1349,  1350,  1351,  2031,  2032,
    2033,  2928,  1352,  2034,  3142,  2035,   834,  2036,  2037,  2038,
    2039,  3345,  2205,  1353,   394,   395,  2040,  3346,  3347,  3348,
    3349,  3350,  3351,  1113,  1114,  1881,  2041,  2043,  1115,  1116,
    1117,  2042,  3352,  2056,  2044,  1118,  1119,  2045,  3353,  2046,
    2241,  1120,  1121,  2244,  2246,  2047,  2048,  2049,   396,   397,
    2050,  2051,  2052,  2053,  2054,  2055,  2057,   450,  2888,  2058,
    2059,  2060,  2061,   967,   968,  2062,   535,   536,  2063,  2064,
    2065,  2066,  2892,  2067,  1639,  2076,  2895,  2068,   969,  2069,
     739,  2070,  2071,  2072,  2073,   461,  2074,   730,   970,  2075,
    2078,   450,  2905,  2079,  2077,  2080,  2081,  2082,   769,   542,
     971,  2083,  2084,  2085,  3457,  2086,  2087,  2088,  2090,  1122,
     545,  2347,   776,  2089,   514,  2091,  2092,  1639,  2093,  2100,
     810,  2101,   960,  2102,  2103,  2104,  2105,  2108,   398,   399,
     960,  2111,  3457,   222,  2112,   271,  2113,  2114,  2117,  2381,
     271,  2118,  2126,  2124,  2125,  2129,  2447,  2133,  1123,  1124,
    2137,  2130,  2131,  3052,  2939,  2176,  2132,   972,   433,    38,
    2134,  2135,  1340,  2138,  2180,  2136,   931,  2182,  2251,  2184,
    2139,  2140,  2141,   450,  2144,  2190,  2218,  3517,  2348,  2145,
     480,  2146,  2147,  3523,  2148,  2191,  1341,  1342,  2149,  2150,
    2196,  2142,  2143,  2151,   586,  2152,  2197,  2153,  2154,   588,
    3517,  2155,  2156,  2157,  2158,  2159,  2199,   932,  -244,  2160,
    2174,  2201,   777,   778,  2186,  2463,   960,  2209,  2210,   479,
    2211,   480,  2214,   973,  2216,  2220,  2228,   974,  2973,   464,
    2975,   975,  2229,   779,   596,  3555,  1125,  2231,   450,  2232,
    2981,  2233,  2247,  2981,  2249,   933,   736,  2250,  2257,  2269,
    2270,   481,  2272,  2274,  2275,  2286,   222,   934,   222,  2287,
    2288,  2289,   450,  2296,    38,  2297,  2301,   744,  2303,   935,
     936,  2311,   450,  2321,  2248,  2330,  2331,   450,   959,   222,
    2329,  2335,  2339,   450,  2528,  2343,  2578,  2344,  2349,  2364,
    2368,  2370,  2371,   780,   781,  1776,  2362,  2363,   450,   960,
     960,  1000,  2366,    38,  2367,  2372,  2375,  2552,  2382,  2373,
    2376,  2393,  2394,  2396,  2377,  2383,  2562,  2388,  2390,  2397,
    2567,  2400,   450,  2401,  2408,  2573,  2161,  2162,  2163,  2164,
    2165,  2166,  2167,  2168,  2169,  2170,  2413,  2588,  2171,  2403,
    2404,  2424,  2406,  2358,  2423,   222,   222,   222,  2410,  2365,
     222,   731,  2425,  1001,  2369,  2411,  2427,  2449,   782,  2431,
    2432,  2450,  2454,  2612,  2378,  1343,  2456,  2468,  1344,  2458,
    2435,  2459,  1783,  2436,  2460,  2391,   222,  2506,  2507,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,  2437,  2438,
    2439,   959,   959,  2441,  2443,  2505,  2512,  1345,  1346,  1371,
    1347,  1348,  1855,  1349,  1350,  2509,   960,  2514,  2516,  2517,
    1352,   959,  2518,  2522,  2442,  2523,  2445,  2524,  2546,  2532,
     450,  1353,  2544,  2549,   735,  2548,  2550,  2555,  2557,   937,
     938,  2569,  2563,  2564,  2584,  2605,   939,   940,   941,   942,
     943,   944,   945,   946,   947,   948,   949,   950,  2606,  2615,
    2583,   951,  2616,  2617,  2720,   952,   953,   954,   955,   956,
    2618,  2920,  2619,  2614,  2620,   222,  2621,  2622,  2623,  2926,
    2624,  2625,  1889,  2648,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,  3070,  2161,  2162,  2163,  2164,  2165,  2166,
    2167,  2168,  2169,  2170,  2626,  2630,  2171,  2627,  2629,  2638,
    2537,  2639,  2635,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,  2636,  2637,  2642,  2654,  2640,  2660,  2656,  2661,
    2570,  2662,  2663,  2869,  2665,  2579,  2580,  2581,  2582,  1543,
    2666,  2667,  2671,  2672,  2673,  2970,  3112,  2674,  2675,  2678,
    3113,  2679,  2680,   450,  2681,  2682,  2683,  2685,  2686,  2687,
     514,  2688,  2689,   450,  2690,  2691,  2692,  2693,  2694,  2695,
    3052,  2696,  3081,  2161,  2162,  2163,  2164,  2165,  2166,  2167,
    2168,  2169,  2170,  2697,  2698,  2171,  1340,  2699,  2700,   739,
    2701,    38,  2702,  2707,  2705,  2709,  2713,  2714,  2717,   769,
    1544,  2728,  2730,   514,  2722,  2731,  2734,  2863,  2735,   810,
    1341,  1342,  2736,   960,   960,  2737,  2742,   450,  2743,  2741,
     960,  2744,  2746,  2747,  2750,  2752,  2755,  2769,  3006,  3007,
    2772,  2758,  2754,  2757,  2761,   960,   960,  2762,  2775,  2765,
    2773,   957,  2779,   960,  2766,   960,  2781,  2785,  2787,  2789,
    2171,  1579,  2790,  2864,   960,  2791,   960,  2873,  2795,  1726,
    2881,  2837,   222,  2846,  2884,  2865,  2857,  1547,  2858,  3196,
    2856,  2889,  2890,  2891,  2906,  2907,  2908,  2910,   736,  2914,
     450,   450,  2921,  2924,  2915,  2918,  2933,   450,  3083,  2161,
    2162,  2163,  2164,  2165,  2166,  2167,  2168,  2169,  2170,  2969,
   -1834,  2171,  2925,  2934,  3025,  3428,  3026,   450,  3053,  2972,
    2986,  3056,   450,  3071,  2983,  2944,    38,  2993,  3027,   450,
   -1833,  3028,  3087,  3058,  3303,  3054,  3057,  3059,  1548,  3316,
    1845,  1846,  1847,  1848,  1849,  1850,  1851,  1852,  1853,  1854,
    3061,  3088,  1855,  3230,  3060,  3023,  3233,  3089,  3106,  3236,
    -671,  2849,  2805,  2806,  2807,  2808,  3108,  3115,  2809,  2810,
    2811,  2812,  2813,  2814,  2815,  2816,  2817,  2818,  2819,  2820,
    2821,  2822,  2823,  2824,  3117,  2826,  2827,  2828,  2829,  2830,
    2831,  2832,  2833,  2834,  2835,  2836,  3141,  3146,  3144,  1343,
    3147,  3149,  1344,  3152,  3158,  3125,  3162,  3178,  3128,  3136,
    3489,  3490,  3082,  3139,  3157,  3159,  3187,  3266,  3171,  3191,
    2927,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
    3193,  1345,  1346,  3197,  1347,  1348,  3202,  1349,  1350,  1351,
    1477,  3219,  3208,  3209,    38,  3210,  3211,  3295,  3215,  3296,
    3214,  3299,  3220,  3221,  3222,  1353,  3223,  3224,   271,  3225,
     960,  3540,  3541,  3369,  2161,  2162,  2163,  2164,  2165,  2166,
    2167,  2168,  2169,  2170,  3226,  3227,  2171,   960,   960,  3231,
     450,  3238,  3251,  3252,  3235,  3253,  3234,  1016,  3237,  3257,
    3258,  3259,  3276,  3267,  3277,  3331,  3331,  3278,  3283,  3311,
    3336,  3286,  3290,  3334,  3292,  3380,  3294,  2902,  3297,  3383,
    3387,  3403,  3382,  3566,  -673,  3404,  3408,  3306,  3084,  3307,
    3326,  3358,  3377,  3413,  3362,  3359,  3360,  3365,  3363,  3384,
    3398,  3381,  3410,  2990,  1880,  2991,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,  3411,  2997,  3415,  3433,  3317,
    3386,  3441,  3164,  3165,  1845,  1846,  1847,  1848,  1849,  1850,
    1851,  1852,  1853,  1854,  3443,  3442,  1855,  2893,  3444,  3445,
    3446,  2896,  3453,  3447,  3181,  3182,  3451,  3454,  3407,  3459,
     960,  3462,  3183,  3465,  3184,  3466,  3473,  3480,  3468,  3477,
    3471,  3492,  3497,  3185,  3501,  3186,   960,  3422,   960,   960,
    3500,  3263,  3504,  3486,  3507,  3512,  -675,  1016,  3534,  3542,
    3426,  3550,  3426,  3432,  3561,  3575,  3562,  2177,  1889,  2179,
    3495,  1889,  2161,  2162,  2163,  2164,  2165,  2166,  2167,  2168,
    2169,  2170,  3511,  2198,  2171,  3551,  3552,  3528,  2203,  3569,
    3576,  3585,  3532,  3022,  3520,  3586,  2212,  2213,  3565,  2215,
    2941,  3531,  3533,  2219,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,  3543,  3537,  3538,  3587,  3544,  2252,    38,
    2254,  2255,  2256,  3370,  3557,  3476,  3560,  3570,  3563,  3595,
    2271,  3596,  2273,  3579,  3584,  3589,  2280,  2281,  2282,  2283,
    2284,  2285,  3593,  3597,  3487,  3598,  1889,  3599,  3600,  3602,
    3491,  3603,  3604,  3605,   376,  2909,  3332,  3170,  2315,  2426,
    3163,  2764,  2977,  2974,  3503,  3574,  3506,  3499,  2332,  2334,
    2774,  3571,  2338,  3479,  2778,  1013,  2935,  2217,  2434,  3172,
    2985,  1534,  3029,  2543,  2784,  2989,  2788,  2560,   384,   385,
     386,  2899,    38,  1729,   387,   388,   389,   390,  2655,  2994,
     420,  1845,  1846,  1847,  1848,  1849,  1850,  1851,  1852,  1853,
    1854,   421,   391,  1855,  1538,  3545,  1889,  1728,  3376,  3357,
    3549,  3250,   392,  2493,  2161,  2162,  2163,  2164,  2165,  2166,
    2167,  2168,  2169,  2170,  1545,  1708,  2171,  1549,   959,  2345,
    3271,  3524,  2422,  2461,  1714,  3275,  2402,  2430,  1013,   393,
    3000,  1789,  2433,  2586,  2571,  1926,  3320,  3321,  2195,   422,
    2200,  2704,  2721,  3567,  3568,  2649,  2613,  2718,  2756,  2448,
    3549,  2529,  2753,  2453,  2568,  2455,  2751,  2457,  2242,  2745,
    2379,  2230,  2740,  1628,  2374,  1740,  2919,  3327,  2206,  2533,
    3588,  2825,  3590,  2554,   959,   959,   959,   959,  3011,  3342,
     959,   959,   959,   959,   959,   959,   959,   959,   959,   959,
     959,   959,   959,   959,   959,   959,   959,  2551,  1786,   959,
     959,   959,   959,   959,   959,   959,   959,   959,   959,   959,
       0,     0,     0,     0,  2794,  2510,  2511,     0,  2513,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,  2535,  2536,
    1734,     0,  1889,     0,     0,     0,     0,     0,     0,  3409,
       0,     0,    38,     0,     0,     0,     0,     0,     0,     0,
    2558,     0,     0,     0,     0,  3416,     0,  3417,  3418,  3190,
       0,     0,     0,     0,     0,     0,     0,   394,   395,     0,
       0,     0,  2585,     0,     0,     0,     0,   517,   775,   518,
       0,     0,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,   396,   397,  1845,  1846,  1847,  1848,  1849,  1850,  1851,
    1852,  1853,  1854,     0,     0,  1855,  2628,   525,     0,  2633,
    2634,     0,     0,  2938,     0,     0,     0,  2641,   392,  2643,
    2644,  2645,  2646,  2647,    38,  2894,  2161,  2162,  2163,  2164,
    2165,  2166,  2167,  2168,  2169,  2170,     0,     0,  2171,     0,
       0,  3085,     0,     0,     0,   393,     0,     0,  2676,  2677,
       0,     0,     0,     0,     0,     0,  2684,  1845,  1846,  1847,
    1848,  1849,  1850,  1851,  1852,  1853,  1854,   535,   536,  1855,
       0,   398,   399,     0,     0,    38,     0,     0,     0,     0,
       0,     0,  1145,     0,     0,     0,     0,     0,  1889,     0,
       0,     0,     0,     0,     0,  2725,  2726,  2727,  3138,  2729,
     542,     0,  2732,  2733,  3143,     0,     0,     0,  2738,  2739,
       0,   545,     0,   776,     0,  3150,  2417,   432,  1889,  1889,
       0,  1845,  1846,  1847,  1848,  1849,  1850,  1851,  1852,  1853,
    1854,     0,   552,  1855,   931,     0,     0,  2770,     0,     0,
       0,     0,     0,  3179,     0,     0,     0,     0,   566,     0,
       0,     0,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,     0,     0,     0,     0,   932,     0,     0,     0,     0,
    3194,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3198,     0,   394,     0,   586,     0,     0,     0,     0,
     588,     0,  1845,  1846,  1847,  1848,  1849,  1850,  1851,  1852,
    1853,  1854,     0,   933,  1855,     0,     0,     0,     0,     0,
       0,     0,  2947,     0,     0,   934,     0,   396,   397,     0,
       0,     0,     0,     0,     0,     0,     0,   935,   936,     0,
       0,     0,     0,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,     0,     0,     0,  3239,  3240,     0,     0,
       0,    38,     0,     0,  3241,     0,  3242,     0,     0,     0,
       0,     0,     0,     0,     0,  3243,  2948,  3244,     0,     0,
       0,     0,  1739,     0,   780,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,     0,  1845,  1846,  1847,  1848,  1849,
    1850,  1851,  1852,  1853,  1854,  2535,  2536,  1855,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1889,  1889,     0,
    3279,  3280,     0,  3282,     0,     0,     0,     0,     0,     0,
    2949,  3289,     0,     0,     0,  1146,  1147,  1148,  1149,   782,
    1150,  1151,  1152,  1153,  1154,  1155,  1156,  1157,  1158,  1159,
    1160,  1161,  1162,  1163,  1164,  1165,  1166,  1167,  1168,  1169,
    1170,  1171,  1172,     0,     0,     0,     0,  3016,     0,     0,
       0,     0,     0,     0,     0,  3323,     0,  3324,     0,     0,
       0,     0,     0,     0,     0,     0,  3329,   937,   938,     0,
       0,     0,     0,     0,   939,   940,   941,   942,   943,   944,
     945,   946,   947,   948,   949,   950,  3304,     0,     0,   951,
       0,  2950,     0,   952,   953,   954,   955,   956,     0,     0,
       0,     0,     0,     0,   931,     0,   959,    38,     0,  3373,
       0,     0,     0,     0,   959,     0,     0,  3375,     0,     0,
       0,     0,     0,     0,     0,     0,  2932,     0,     0,  1845,
    1846,  1847,  1848,  1849,  1850,  1851,  1852,  1853,  1854,   931,
    1752,  1855,     0,     0,     0,   932,     0,     0,     0,     0,
       0,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
       0,  1173,  1174,  1175,     0,     0,     0,     0,     0,     0,
     932,     0,     0,   933,     0,  1845,  1846,  1847,  1848,  1849,
    1850,  1851,  1852,  1853,  1854,   934,     0,  1855,  1755,  3437,
     959,     0,     0,     0,  2951,     0,     0,   935,   936,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   933,  1845,
    1846,  1847,  1848,  1849,  1850,  1851,  1852,  1853,  1854,     0,
     934,  1855,  1889,  3448,  1889,  3449,  3450,     0,     0,     0,
       0,    38,   935,   936,  2161,  2162,  2163,  2164,  2165,  2166,
    2167,  2168,  2169,  2170,     0,     0,  2171,  3467,  1845,  1846,
    1847,  1848,  1849,  1850,  1851,  1852,  1853,  1854,     0,     0,
    1855,     0,     0,     0,     0,     0,    38,     0,     0,     0,
       0,     0,     0,   959,   959,   967,   968,     0,     0,   957,
       0,  1762,     0,  1763,     0,    38,     0,     0,  2142,  2143,
     969,     0,     0,  3498,     0,     0,     0,   461,     0,     0,
     970,     0,     0,     0,    38,     0,     0,     0,     0,  3513,
       0,     0,   971,     0,  1889,  1889,     0,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,     0,     0,     0,     0,
       0,     0,     0,    38,     0,     0,     0,     0,  2952,     0,
    2834,     0,     0,  1845,  1846,  1847,  1848,  1849,  1850,  1851,
    1852,  1853,  1854,     0,     0,  1855,     0,   937,   938,   972,
    3556,     0,     0,     0,   939,   940,   941,   942,   943,   944,
     945,   946,   947,   948,   949,   950,     0,     0,     0,   951,
     959,     0,     0,   952,   953,   954,   955,   956,     0,     0,
       0,  3437,   937,   938,  2956,     0,     0,     0,  3577,   939,
     940,   941,   942,   943,   944,   945,   946,   947,   948,   949,
     950,     0,     0,     0,   951,     0,     0,     0,   952,   953,
     954,   955,   956,   448,     0,   973,     0,     0,  2957,   974,
       0,   464,     0,   975,     0,     0,     0,     0,     0,  3601,
    1889,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
       0,     0,     0,     0,     0,     0,     0,  2958,     0,   744,
       0,     0,     0,     0,     0,     0,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,     0,     0,     0,  1845,  1846,  1847,  1848,
    1849,  1850,  1851,  1852,  1853,  1854,     0,  2398,  1855,     0,
    1889,     0,  1889,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,  2959,  1785,     0,     0,     0,     0,     0,   957,
       0,  1762,     0,  1763,     0,     0,     0,     0,     0,     0,
       0,     0,   375,     0,     0,     0,     0,   959,   959,     0,
       0,     0,     0,     0,   959,     0,     1,     2,     0,     0,
       0,     0,     0,     0,   957,     0,  1762,     0,  1763,   959,
     959,  1788,     0,     0,     0,     0,     0,   959,     0,   959,
       0,     3,     4,     5,     6,     7,     0,     0,   959,     8,
     959,     0,     0,    38,     0,     0,     9,     0,     0,     0,
       0,     0,     0,     0,     0,  2992,    10,    11,    12,  1889,
       0,     0,    13,     0,    14,    15,    16,    17,    18,     0,
       0,     0,     0,     0,     0,     0,    19,    20,     0,     0,
       0,     0,     0,     0,    21,  2161,  2162,  2163,  2164,  2165,
    2166,  2167,  2168,  2169,  2170,     0,     0,  2171,     0,   267,
      22,    23,    24,    25,     0,     0,     0,     0,     0,     0,
       0,    26,     0,    27,    28,     0,     0,  1845,  1846,  1847,
    1848,  1849,  1850,  1851,  1852,  1853,  1854,    29,    38,  1855,
    2900,  2161,  2162,  2163,  2164,  2165,  2166,  2167,  2168,  2169,
    2170,     0,     0,  2171,     0,    30,     0,     0,     0,     0,
       0,     0,     0,     0,    31,     0,     0,     0,     0,     0,
       0,     0,  3248,  1889,     0,  2960,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,     0,    32,    33,
      34,    35,     0,     0,    36,  2161,  2162,  2163,  2164,  2165,
    2166,  2167,  2168,  3496,  2170,    37,     0,  2171,     0,  1889,
       0,     0,  1889,  1845,  1846,  1847,  1848,  1849,  1850,  1851,
    1852,  1853,  1854,     0,     0,  1855,    38,  2945,  1845,  1846,
    1847,  1848,  1849,  1850,  1851,  1852,  1853,  1854,     0,  1889,
    1855,     0,     0,     0,     0,     0,    39,     0,    40,     0,
      41,    42,     0,     0,   959,     0,     0,     0,    43,     0,
       0,    44,     0,    45,    46,     0,     0,     0,    47,    48,
       0,   959,   959,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,     0,    49,    50,     0,    51,    52,    53,     0,
      54,    55,     0,  1889,     0,  3341,    56,  1889,     0,    57,
       0,     0,     0,     0,    58,    59,  1791,     0,     0,     0,
       0,    60,  -569,    61,    62,    63,     0,    64,     0,     0,
       0,    65,     0,     0,     0,     0,  1889,    66,    67,    68,
      69,    70,    71,    72,    73,    74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2961,     0,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,  1889,     0,     0,
       0,     0,     0,     0,   959,     0,     0,     0,     0,     0,
       0,     0,     0,    75,     0,     0,     0,     0,     0,     0,
     959,     0,   959,   959,     0,     0,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,     0,     0,    76,  1845,  1846,
    1847,  1848,  1849,  1850,  1851,  1852,  1853,  1854,     0,     0,
    1855,     0,  2962,     0,     0,     0,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,     0,     0,  1889,     0,     0,
       0,    38,     0,  2946,  1845,  1846,  1847,  1848,  1849,  1850,
    1851,  1852,  1853,  1854,     0,  1889,  1855,     0,     0,     0,
       0,     0,     0,     0,     0,  1889,  3118,     0,     0,     0,
       0,     0,    96,    97,     0,     0,    98,    99,   100,   101,
     102,   103,   104,   105,     0,     0,     0,     0,     0,     0,
       0,   106,     0,     0,     0,     0,   107,   108,     0,     0,
       0,     0,    38,   109,     0,     0,     0,     0,     0,     0,
    1889,     1,     2,     0,     0,     0,  1889,     0,     0,     0,
       0,     0,     0,     0,     0,   110,   111,     0,     0,     0,
       0,     0,     0,  1889,     0,     0,     3,     4,     5,     6,
       7,     0,     0,     0,     8,    38,     0,     0,     0,     0,
       0,     9,   112,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,    12,     0,     0,     0,    13,  1889,    14,
      15,    16,    17,    18,     0,     0,     0,     0,     0,     0,
       0,    19,    20,     0,     0,     0,     0,     0,     0,    21,
       0,     0,  1845,  1846,  1847,  1848,  1849,  1850,  1851,  1852,
    1853,  1854,     0,     0,  1855,    22,    23,    24,    25,     0,
       0,   931,     0,     0,     0,     0,    26,     0,    27,    28,
       0,    38,     0,     0,     0,     0,     0,  2963,     0,     0,
       0,   448,    29,  2161,  2162,  2163,  2164,  2165,  2166,  2167,
    2168,  2169,  2170,     0,  1551,  2171,     0,     0,     0,     0,
      30,     0,   932,     0,     0,     0,     0,     0,     0,    31,
       0,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
       0,     0,     0,    32,    33,    34,    35,     0,     0,    36,
    1552,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,     0,  1553,     0,  2161,  2162,  2163,  2164,  2165,  2166,
    2167,  2168,  2169,  2170,  1554,  1555,  2171,     0,     0,     0,
       0,    38,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    39,     0,    40,     0,    41,    42,     0,    38,  3148,
       0,     0,  1556,    43,     0,     0,    44,     0,    45,    46,
       0,     0,     0,    47,    48,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,     0,     0,     0,     0,    49,    50,
       0,    51,    52,    53,     0,    54,    55,     0,     0,     0,
       0,    56,     0,     0,    57,     0,     0,     0,     0,    58,
      59,     0,     0,     0,     0,     0,    60,     0,    61,    62,
      63,  2968,    64,     0,     0,     0,    65,     0,     0,     0,
       0,     0,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
       0,     0,  2984,  3216,     0,     0,  2161,  2162,  2163,  2164,
    2165,  2166,  2167,  2168,  2169,  2170,     0,  1793,  2171,     0,
       0,     0,     0,     0,  1557,  1558,     0,     0,    75,     0,
       0,  1559,  1560,  1561,  1562,  1563,  1564,  1565,  1566,  1567,
    1568,  1569,  1570,     0,    38,  1900,  1571,     0,     0,     0,
    1572,  1573,  1574,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    76,  2161,  2162,  2163,  2164,  2165,  2166,  2167,
    2168,  2169,  2170,  3064,     0,  2171,     0,     0,     0,     0,
       0,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
       0,     0,     0,     0,     0,     0,     0,     0,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    96,    97,     0,
       0,    98,    99,   100,   101,   102,   103,   104,   105,     0,
       0,     0,     0,  3151,   516,   517,   106,   518,     0,   519,
     520,   107,   108,     0,   521,     0,     0,   522,   109,   523,
    2161,  2162,  2163,  2164,  2165,  2166,  2167,  2168,  2169,  2170,
       0,     0,  2171,     0,     0,     0,     0,   524,     0,     0,
     110,   111,     0,     0,     0,   525,   391,     0,     0,  3160,
       0,     0,     0,   526,   527,     0,   392,     0,     0,     0,
     528,   529,   530,     0,     0,     0,     0,   112,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   531,     0,
     532,   429,   430,   533,     0,  3065,     0,   534,     0,     0,
       0,     0,     0,   422,     0,     0,  1575,     0,     0,     0,
       0,     0,     0,     0,     0,   535,   536,   537,     0,     0,
       0,     0,     0,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,   538,   539,   540,     0,   541,   542,   543,
     431,     0,  3066,     0,     0,     0,     0,     0,   544,   545,
       0,     0,   546,   547,     0,   432,   548,   549,    38,   550,
     551,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     552,   553,   554,   555,   556,   557,   558,   559,   560,     0,
       0,   561,   562,   563,   564,   565,   566,     0,     0,     0,
       0,     0,     0,     0,     0,   567,   568,   433,   569,   570,
     571,   572,   573,   574,    38,   575,   576,     0,     0,   577,
     578,     0,     0,     0,   579,     0,     0,     0,   580,   581,
     582,   931,     0,     0,   583,     0,   584,     0,   585,     0,
       0,   394,   395,   586,     0,   587,     0,     0,   588,   589,
     590,     0,     0,     0,     0,     0,   591,     0,   592,  3067,
       0,     0,     0,     0,  1551,     0,     0,     0,     0,   593,
     931,     0,   932,     0,   594,   396,   397,     0,     0,   595,
       0,     0,     0,   596,     0,     0,     0,     0,     0,     0,
       0,  2298,     0,   463,     0,   597,   598,     0,     0,   599,
       0,     0,     0,  1551,     0,     0,     0,     0,     0,     0,
    1552,   932,     0,     0,   600,     0,     0,     0,     0,   464,
       0,     0,  1553,     0,     0,     0,   601,   602,     0,     0,
       0,   603,     0,     0,  1554,  1555,     0,     0,     0,     0,
       0,     0,     0,     0,   604,     0,     0,     0,     0,  1552,
       0,     0,     0,     0,     0,   398,   399,     0,     0,     0,
       0,  1553,     0,     0,     0,     0,     0,     0,    38,     0,
       0,     0,  1556,  1554,  1555,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   931,    38,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    38,     0,     0,
       0,  1556,     0,     0,     0,     0,     0,     0,     0,  1551,
       0,     0,     0,     0,     0,     0,     0,   932,     0,     0,
       0,     0,     0,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,     0,     0,  2161,  2162,  2163,  2164,  2165,
    2166,  2167,  2168,  2169,  2170,  1552,     0,  2171,     0,     0,
       0,   605,     0,     0,     0,     0,     0,  1553,     0,  2161,
    2162,  2163,  2164,  2165,  2166,  2167,  2168,  2169,  2170,  1554,
    1555,  2171,     0,     0,     0,     0,     0,  2444,   606,   434,
     435,     0,     0,     0,  1557,  1558,   607,     0,     0,     0,
       0,  1559,  1560,  1561,  1562,  1563,  1564,  1565,  1566,  1567,
    1568,  1569,  1570,    38,     0,     0,  1571,  1556,     0,     0,
    1572,  1573,  1574,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3434,  3435,     0,     0,   608,   609,     0,
    1559,  1560,  1561,  1562,  1563,  1564,  1565,  1566,  1567,  1568,
    1569,  1570,     0,     0,     0,  1571,     0,     0,    38,  1572,
    1573,  1574,  2955,  1845,  1846,  1847,  1848,  1849,  1850,  1851,
    1852,  1853,  1854,     0,     0,  1855,     0,     0,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    38,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,  2161,  2162,  2163,  2164,
    2165,  2166,  2167,  2168,  2169,  2170,     0,     0,  2171,  1557,
    1558,     0,     0,     0,     0,     0,  1559,  1560,  1561,  1562,
    1563,  1564,  1565,  1566,  1567,  1568,  1569,  1570,    38,     0,
       0,  1571,   267,   931,  3068,  1572,  1573,  1574,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1816,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3069,  3436,
       0,     0,     0,     0,     0,     0,  1551,     0,     0,     0,
       0,     0,     0,     0,   932,     0,  1575,     0,     0,     0,
     931,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,  1552,  1551,     0,  1575,     0,     0,     0,     0,
       0,   932,     0,     0,  1553,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1554,  1555,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,   448,     0,  1552,
    2161,  2162,  2163,  2164,  2165,  2166,  2167,  2168,  2169,  2170,
      38,  1553,  2171,     0,  1556,  3493,     0,     0,     0,     0,
       0,     0,     0,  1554,  1555,     0,     0,     0,     0,     0,
      38,     0,     0,     0,   931,     0,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,     0,     0,    38,     0,     0,
       0,  1556,     0,     0,     0,  3073,     0,  1551,     0,     0,
       0,  1575,     0,     0,     0,   932,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,     0,     0,     0,
       0,     0,     0,  1552,     0,     0,     0,  1817,     0,     0,
       0,     0,     0,     0,     0,  1553,     0,  2161,  2162,  2163,
    2164,  2165,  2166,  2167,  2168,  2169,  2170,  1554,  1555,  2171,
       0,     0,     0,     0,     0,     0,  1557,  1558,     0,     0,
       0,     0,     0,  1559,  1560,  1561,  1562,  1563,  1564,  1565,
    1566,  1567,  1568,  1569,  1570,     0,     0,     0,  1571,     0,
       0,    38,  1572,  1573,  1574,  1556,     0,     0,     0,     0,
       0,     0,     0,  2161,  2162,  2163,  2164,  2165,  2166,  2167,
    2168,  2169,  2170,  1557,  1558,  2171,     0,     0,     0,     0,
    1559,  1560,  1561,  1562,  1563,  1564,  1565,  1566,  1567,  1568,
    1569,  1570,     0,     0,     0,  1571,     0,     0,     0,  1572,
    1573,  1574,     0,     0,     0,     0,     0,  3114,     0,  3074,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,     0,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,     0,
       0,     0,     0,    38,     0,     0,     0,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,  3062,  2161,  2162,  2163,
    2164,  2165,  2166,  2167,  2168,  2169,  2170,  1557,  1558,  2171,
       0,     0,  3494,     0,  1559,  1560,  1561,  1562,  1563,  1564,
    1565,  1566,  1567,  1568,  1569,  1570,     0,     0,   516,  1571,
       0,   518,     0,  1572,  1573,  1574,     0,     0,   521,     0,
       0,     0,   849,   523,     0,  2161,  2162,  2163,  2164,  2165,
    2166,  2167,  2168,  2169,  2170,     0,  3075,  2171,     0,  3546,
       0,     0,     0,     0,     0,     0,     0,     0,  1575,  2161,
    2162,  2163,  2164,  2165,  2166,  2167,  2168,  2169,  2170,     0,
       0,  2171,     0,     0,   528,   529,   530,   850,   851,  2469,
       0,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
       0,     0,  3076,     0,     0,  1575,   852,     0,   853,     0,
       0,     0,     0,     0,     0,   516,     0,     0,   518,   535,
     536,   537,     0,     0,     0,     0,     0,     0,   522,   849,
     854,   855,  2161,  2162,  2163,  2164,  2165,  2166,  2167,  2168,
    2169,  2170,     0,     0,  2171,     0,     0,   538,   539,   540,
       0,     0,     0,     0,     0,     0,     0,   856,     0,     0,
       0,     0,     0,     0,   819,     0,     0,     0,     0,     0,
       0,   528,   529,   530,   850,   851,     0,     0,     0,     0,
       0,     0,   857,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,     0,     0,     0,   853,     0,     0,     0,     0,
     568,     0,     0,     0,    38,     0,   535,   536,   537,  1575,
       0,     0,     0,     0,     0,     0,     0,   854,   855,     0,
    1038,  2161,  2162,  2163,  2164,  2165,  2166,  2167,  2168,  2169,
    2170,     0,     0,  2171,   538,   539,   540,   586,   858,     0,
     859,     0,   588,     0,     0,   860,   861,     0,     0,     0,
     591,   819,   592,     0,  3077,     0,   432,     0,     0,     0,
       0,     0,     0,   593,   480,  2161,  2162,  2163,  2164,  2165,
    2166,  2167,  2168,  2169,  2170,   862,     0,  2171,  3078,     0,
       0,     0,     0,     0,   863,     0,   864,   463,     0,     0,
       0,     0,     0,   599,   481,   865,     0,   568,     0,     0,
       0,     0,     0,     0,   866,   867,   868,     0,     0,     0,
     219,   220,     0,   464,     0,     0,     0,     0,     0,     0,
     601,   602,     0,     0,     0,   603,     0,     0,     0,     0,
       0,     0,     0,   448,   586,   858,     0,   859,     0,   588,
       0,     0,   860,   861,     0,     0,     0,     0,     0,   592,
       0,  3079,     0,     0,     0,   516,     0,     0,   518,     0,
     593,   480,     0,     0,     0,     0,     0,     0,     0,   849,
       0,     0,   862,     0,     0,     0,     0,     0,     0,     0,
       0,   863,     0,   864,   463,     0,     0,     0,     0,     0,
     599,   481,   865,     0,     0,     0,     0,     0,     0,     0,
       0,   866,   867,   868,     0,     0,     0,     0,     0,     0,
     464,   528,   529,   530,   850,   851,     0,   601,   602,     0,
       0,     0,   603,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,     0,     0,   853,  1066,     0,  2897,     0,
    1039,     0,   516,     0,     0,   518,   535,   536,   537,     0,
       0,     0,     0,     0,     0,   605,   849,   854,   855,  1845,
    1846,  1847,  1848,  1849,  1850,  1851,  1852,  1853,  1854,     0,
       0,  1855,     0,     0,   538,   539,   540,     0,     0,     0,
       0,     0,     0,     0,  3080,     0,     0,     0,     0,     0,
       0,   819,     0,     0,     0,     0,     0,     0,   528,   529,
     530,   850,   851,     0,     0,     0,     0,     0,     0,  1082,
       0,     0,  2161,  2162,  2163,  2164,  2165,  2166,  2167,  2168,
    2169,  2170,     0,  1040,  2171,     0,     0,     0,     0,     0,
       0,     0,   853,  1066,     0,     0,     0,   568,     0,     0,
       0,     0,     0,   535,   536,   537,    38,     0,     0,     0,
       0,     0,   605,  3121,   854,   855,     0,  1845,  1846,  1847,
    1848,  1849,  1850,  1851,  1852,  1853,  1854,     0,     0,  1855,
       0,   538,   539,   540,   586,   858,     0,   859,     0,   588,
       0,     0,   860,   861,    38,     0,     0,     0,   819,   592,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     593,   480,     0,    38,     0,     0,     0,     0,     0,     0,
       0,     0,   862,     0,     0,     0,     0,     0,     0,     0,
       0,   863,    38,   864,   463,     0,     0,     0,     0,     0,
     599,   481,   865,     0,   568,     0,     0,     0,     0,     0,
       0,   866,   867,   868,     0,     0,     0,     0,     0,     0,
     464,     0,     0,     0,     0,     0,    38,   601,   602,     0,
       0,     0,   603,     0,     0,     0,  1067,     0,  1083,     0,
       0,   586,   858,     0,   859,   448,   588,     0,     0,   860,
     861,     0,     0,     0,     0,     0,   592,    38,  3161,     0,
       0,     0,     0,     0,     0,     0,     0,   593,   480,  1845,
    1846,  1847,  1848,  1849,  1850,  1851,  1852,  1853,  1854,   862,
       0,  1855,     0,   448,     0,     0,     0,     0,   863,     0,
     864,   463,     0,     0,     0,     0,     0,   599,   481,   865,
       0,     0,   448,     0,     0,     0,     0,     0,   866,   867,
     868,  3199,     0,     0,     0,     0,     0,   464,     0,     0,
       0,   448,     0,     0,   601,   602,     0,     0,     0,   603,
       0,     0,    38,  1067,     0,     0,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,   448,  3205,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,     0,     0,     0,
       0,     0,   605,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,     0,     0,     0,     0,     0,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,     0,     0,     0,     0,   605,
       0,    38,     0,     0,     0,  3167,     0,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,   267,     0,  3206,     0,
       0,     0,     0,     0,     0,    38,     0,     0,     0,     0,
       0,     0,     0,  3200,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    38,     0,     0,     0,     0,     0,
       0,     0,  3201,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,     0,     0,     0,     0,     0,     0,
       0,  3204,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,     0,     0,     0,     0,     0,     0,     0,     0,    38,
       0,     0,     0,     0,     0,  3212,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,     0,     0,     0,     0,     0,
      38,     0,     0,     0,   229,   230,     0,     0,     0,     0,
    1845,  1846,  1847,  1848,  1849,  1850,  1851,  1852,  1853,  1854,
       0,     0,  1855,     0,     0,     0,  1845,  1846,  1847,  1848,
    1849,  1850,  1851,  1852,  1853,  1854,     0,     0,  1855,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,     0,
       0,     0,    38,     0,     0,     0,     0,     0,     0,   237,
     238,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
       0,     0,     0,     0,     0,     0,     0,     0,    38,     0,
       0,     0,     0,   248,   249,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    38,  3063,  2161,  2162,  2163,  2164,  2165,  2166,
    2167,  2168,  2169,  2170,     0,     0,  2171,     0,   268,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,     0,     0,
       0,    38,     0,     0,     0,     0,     0,     0,   280,   281,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,  3213,
       0,     0,     0,     0,     0,     0,     0,    38,     0,     0,
       0,     0,   299,   300,     0,  3313,     0,  1845,  1846,  1847,
    1848,  1849,  1850,  1851,  1852,  1853,  1854,     0,     0,  1855,
       0,   312,   313,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,     0,     0,     0,     0,     0,     0,
     315,   316,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,  2161,  2162,  2163,  2164,  2165,  2166,  2167,  2168,  2169,
    2170,    38,     0,  2171,     0,     0,   318,   319,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   321,   322,    38,
    3072,  2161,  2162,  2163,  2164,  2165,  2166,  2167,  2168,  2169,
    2170,     0,     0,  2171,     0,     0,     0,   267,     0,  1845,
    1846,  1847,  1848,  1849,  1850,  1851,  1852,  1853,  1854,     0,
       0,  1855,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,   448,     0,     0,     0,   267,  2161,  2162,  2163,  2164,
    2165,  2166,  2167,  2168,  2169,  2170,     0,     0,  2171,   325,
     326,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
     832,     0,  2161,  2162,  2163,  2164,  2165,  2166,  2167,  2168,
    2169,  2170,     0,     0,  2171,   339,   340,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,  3314,     0,   832,     0,
       0,     0,     0,     0,     0,     0,     0,    38,     0,     0,
       0,     0,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    38,     0,     0,     0,     0,     0,     0,     0,   352,
     353,     0,     0,     0,     0,     0,     0,     0,  2940,     0,
      38,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      38,     0,     0,     0,     0,     0,     0,     0,     0,   289,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,     0,     0,
       0,     0,     0,     0,     0,   329,     0,    38,  3315,  3137,
    2161,  2162,  2163,  2164,  2165,  2166,  2167,  2168,  2169,  2170,
       0,     0,  2171,     0,     0,     0,   448,     0,  2161,  2162,
    2163,  2164,  2165,  2166,  2167,  2168,  2169,  2170,     0,   449,
    2171,     0,     0,     0,     0,  3328,     0,     0,     0,     0,
     448,     0,  2161,  2162,  2163,  2164,  2165,  2166,  2167,  2168,
    2169,  2170,     0,     0,  2171,     0,     0,     0,     0,   448,
       0,     0,     0,     0,     0,     0,     0,     0,   833,     0,
       0,  3366,     0,     0,     0,     0,     0,     0,     0,   448,
       0,  1845,  1846,  1847,  1848,  1849,  1850,  1851,  1852,  1853,
    1854,     0,     0,  1855,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2931,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,   448,     0,     0,     0,
       0,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    38,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    38,
    3318,  1845,  1846,  1847,  1848,  1849,  1850,  1851,  1852,  1853,
    1854,     0,     0,  1855,     0,     0,     0,     0,    38,     0,
       0,     0,     0,     0,     0,     0,     0,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    38,     0,     0,     0,
       0,     0,     0,     0,   507,     0,     0,  3367,     0,     0,
       0,     0,     0,     0,     0,    38,  3319,  1845,  1846,  1847,
    1848,  1849,  1850,  1851,  1852,  1853,  1854,     0,   722,  1855,
       0,  3368,     0,     0,     0,     0,     0,     0,     0,    38,
       0,     0,     0,     0,     0,     0,     0,   765,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   922,     0,
       0,     0,     0,     0,     0,     0,     0,   920,     0,     0,
    3419,     0,     0,     0,     0,     0,     0,     0,   448,     0,
    1845,  1846,  1847,  1848,  1849,  1850,  1851,  1852,  1853,  1854,
       0,     0,  1855,     0,     0,     0,     0,   448,     0,  1845,
    1846,  1847,  1848,  1849,  1850,  1851,  1852,  1853,  1854,     0,
       0,  1855,     0,     0,   921,  1845,  1846,  1847,  1848,  1849,
    1850,  1851,  1852,  1853,  1854,   448,     0,  1855,  2161,  2162,
    2163,  2164,  2165,  2166,  2167,  2168,  2169,  2170,     0,     0,
    2171,     0,     0,     0,   448,     0,     0,     0,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,   448,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    38,     0,     0,
       0,     0,     0,     0,     0,     0,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    38,     0,     0,     0,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    38,     0,
       0,     0,     0,     0,     0,     0,   923,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,     0,     0,
       0,     0,     0,     0,     0,     0,   962,     0,     0,  3483,
       0,     0,     0,     0,     0,     0,     0,    38,     0,     0,
       0,     0,     0,     0,     0,   990,     0,     0,  3484,     0,
       0,     0,     0,     0,     0,     0,   448,     0,     0,     0,
       0,     0,     0,     0,  3485,     0,     0,     0,     0,     0,
       0,     0,     0,  1012,     0,     0,     0,  3508,     0,     0,
       0,     0,     0,     0,    38,     0,     0,     0,     0,     0,
       0,     0,  1049,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   448,     0,  2161,  2162,  2163,  2164,  2165,
    2166,  2167,  2168,  2169,  2170,     0,  1065,  2171,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   448,     0,  2161,
    2162,  2163,  2164,  2165,  2166,  2167,  2168,  2169,  2170,     0,
       0,  2171,     0,     0,     0,     0,   448,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,  1093,     0,  2161,  2162,
    2163,  2164,  2165,  2166,  2167,  2168,  2169,  2170,     0,     0,
    2171,  2161,  2162,  2163,  2164,  2165,  2166,  2167,  2168,  2169,
    2170,     0,     0,  2171,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,  1098,     0,     0,     0,     0,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    38,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    38,     0,     0,     0,
       0,     0,     0,     0,  1072,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    38,     0,     0,     0,     0,
       0,     0,     0,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    38,     0,     0,     0,     0,     0,     0,
       0,  1078,     0,     0,  3509,     0,     0,     0,     0,     0,
       0,     0,    38,  3371,  2161,  2162,  2163,  2164,  2165,  2166,
    2167,  2168,  2169,  2170,     0,  1089,  2171,     0,  3510,     0,
       0,     0,     0,     0,     0,     0,    38,     0,     0,     0,
       0,     0,     0,     0,  1090,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1103,     0,     0,     0,     0,
       0,     0,     0,     0,  1094,     0,     0,  3553,     0,     0,
       0,     0,     0,     0,     0,  1110,     0,     0,     0,     0,
    3578,  2161,  2162,  2163,  2164,  2165,  2166,  2167,  2168,  2169,
    2170,     0,     0,  2171,   448,     0,  2161,  2162,  2163,  2164,
    2165,  2166,  2167,  2168,  2169,  2170,     0,     0,  2171,     0,
       0,  1099,  2161,  2162,  2163,  2164,  2165,  2166,  2167,  2168,
    2169,  2170,   448,     0,  2171,  2161,  2162,  2163,  2164,  2165,
    2166,  2167,  2168,  2169,  2170,     0,     0,  2171,     0,     0,
       0,  1945,     0,     0,     0,     0,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,   448,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    38,     0,     0,     0,     0,     0,
       0,     0,     0,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    38,     0,     0,     0,     0,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    38,     0,     0,     0,     0,
       0,     0,     0,  1104,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    38,     0,     0,     0,     0,     0,
       0,     0,     0,  1111,     0,     0,     0,     0,     0,     0,
    3592,     0,     0,     0,    38,     0,     0,     0,     0,     0,
       0,     0,  1143,  3001,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2860,     0,     0,     0,     0,     0,  3002,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1370,     0,  3003,     0,     0,     0,     0,     0,     0,     0,
       0,    38,     0,     0,     0,     0,     0,     0,     0,  1946,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     448,     0,  2161,  2162,  2163,  2164,  2165,  2166,  2167,  2168,
    2169,  2170,     0,  2859,  2171,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   448,     0,  2161,  2162,  2163,  2164,
    2165,  2166,  2167,  2168,  2169,  2170,     0,     0,  2171,     0,
       0,     0,     0,   448,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,   448,     0,  1845,  1846,  1847,  1848,  1849,
    1850,  1851,  1852,  1853,  1854,     0,     0,  1855,  2161,  2162,
    2163,  2164,  2165,  2166,  2167,  2168,  2169,  2170,     0,     0,
    2171,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
     448,     0,     0,     0,     0,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    38,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    38,     0,     0,     0,     0,     0,     0,
       0,  2861,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,     0,     0,     0,     0,     0,     0,
       0,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      38,     0,     0,     0,     0,     0,     0,     0,  2866,  3004,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
       0,  3372,  2161,  2162,  2163,  2164,  2165,  2166,  2167,  2168,
    2169,  2170,  2867,  3140,  2171,     0,     0,     0,     0,     0,
       0,     0,     0,    38,     0,     0,     0,     0,     0,     0,
       0,  2868,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   448,     0,     0,     0,     0,     0,     0,     0,
       0,  2887,  3166,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   448,     0,     0,  3180,  2161,  2162,  2163,  2164,
    2165,  2166,  2167,  2168,  2169,  2170,     0,     0,  2171,     0,
       0,  2979,     0,  2161,  2162,  2163,  2164,  2165,  2166,  2167,
    2168,  2169,  2170,     0,     0,  2171,     0,     0,  2901,  2161,
    2162,  2163,  2164,  2165,  2166,  2167,  2168,  2169,  2170,  2979,
       0,  2171,  2161,  2162,  2163,  2164,  2165,  2166,  2167,  2168,
    2169,  2170,     0,     0,  2171,     0,     0,     0,   448,     0,
       0,     0,     0,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,   448,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    38,     0,     0,     0,     0,     0,     0,     0,     0,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    38,     0,
       0,     0,     0,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    38,     0,     0,     0,     0,     0,     0,     0,
    2942,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    38,     0,     0,     0,     0,     0,     0,     0,     0,
    2978,     0,     0,  3192,     0,     0,     0,     0,     0,     0,
       0,    38,     0,     0,     0,     0,     0,     0,     0,  2980,
    3203,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     448,     0,     0,     0,     0,     0,  3281,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2982,     0,  3284,
       0,     0,     0,     0,     0,     0,     0,     0,    38,     0,
       0,     0,     0,     0,     0,     0,  2995,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   448,     0,     0,
       0,     0,     0,     0,     0,     0,    38,     0,     0,     0,
    2996,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   448,     0,  2161,  2162,  2163,  2164,  2165,  2166,  2167,
    2168,  2169,  2170,     0,     0,  2171,     0,     0,     0,     0,
     448,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
     448,     0,  1845,  1846,  1847,  1848,  1849,  1850,  1851,  1852,
    1853,  1854,     0,     0,  1855,  2161,  2162,  2163,  2164,  2165,
    2166,  2167,  2168,  2169,  2170,     0,     0,  2171,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,  3405,     0,     0,
       0,     0,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      38,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      38,     0,     0,     0,     0,     0,     0,     0,  2998,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
       0,     0,     0,     0,     0,     0,     0,     0,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    38,     0,     0,
       0,     0,     0,     0,     0,  3005,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    38,     0,     0,     0,  3012,
    3291,     0,  3393,  2161,  2162,  2163,  2164,  2165,  2166,  2167,
    2168,  2169,  2170,     0,    38,  2171,     0,     0,  3024,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3424,
       0,     0,     0,     0,     0,     0,     0,     0,  3322,  3302,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3424,
       0,     0,  3312,  2161,  2162,  2163,  2164,  2165,  2166,  2167,
    2168,  2169,  2170,     0,     0,  2171,     0,     0,  3430,     0,
       0,     0,     0,     0,     0,     0,     0,    38,     0,     0,
       0,     0,     0,     0,     0,  3406,     0,     0,     0,     0,
    2161,  2162,  2163,  2164,  2165,  2166,  2167,  2168,  2169,  2170,
       0,     0,  2171,     0,     0,    38,     0,     0,     0,     0,
       0,     0,     0,  2204,     0,     0,     0,     0,     0,     0,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,     0,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    38,     0,
       0,     0,     0,     0,     0,     0,     0,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    38,     0,     0,     0,  3425,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,     0,     0,     0,  3429,     0,     0,
    3325,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    38,     0,     0,     0,     0,  3431,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    38,  3394,     0,     0,
       0,     0,     0,     0,  2240,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    38,     0,     0,     0,     0,     0,
       0,     0,  2243,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,     0,     0,     0,     0,     0,     0,
       0,  2245,     0,     0,     0,  2161,  2162,  2163,  2164,  2165,
    2166,  2167,  2168,  2169,  2170,     0,     0,  2171,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,     0,  2161,  2162,
    2163,  2164,  2165,  2166,  2167,  2168,  2169,  2170,     0,    38,
    2171,     0,     0,     0,  2346,     0,     0,     0,     0,     0,
       0,     0,     0,  2161,  2162,  2163,  2164,  2165,  2166,  2167,
    2168,  2169,  2170,     0,    38,  2171,     0,     0,     0,     0,
       0,     0,  2380,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      38,  1579,  1580,     0,     0,  2462,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,  2902,  2903,     0,     0,     0,
       0,     0,     0,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,  3395,     0,     0,     0,     0,     0,     0,     0,
    2527,     0,     0,     0,     0,    38,     0,  2451,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2561,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
       0,     0,     0,     0,     0,  3400,     0,     0,  2566,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    38,     0,
    3420,     0,     0,  2572,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,  3263,  3264,     0,     0,     0,     0,     0,
       0,  2575,     0,  2161,  2162,  2163,  2164,  2165,  2166,  2167,
    2168,  2169,  2170,    38,  2803,  2171,     0,     0,     0,     0,
    2587,     0,     0,     0,   267,     0,     0,     0,     0,     0,
       0,     0,    38,  3364,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,   267,
       0,  3505,     0,     0,     0,     0,     0,    38,     0,     0,
       0,     0,     0,     0,     0,     0,  2611,     0,  1013,     0,
       0,     0,     0,     0,     0,     0,     0,    38,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2719,     0,     0,     0,     0,    38,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,  1581,    38,     0,     0,     0,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,  2904,     0,     0,
       0,    38,     0,     0,     0,     0,     0,  2999,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,  2307,  2308,  2309,
    2161,  2162,  2163,  2164,  2165,  2166,  2167,  2168,  2169,  2170,
       0,     0,  2171,     0,     0,     0,    38,     0,     0,     0,
    3421,     0,     0,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    38,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,     0,     0,     0,     0,     0,     0,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,  3265,    38,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,  1813,    38,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,     0,     0,     0,     0,     0,     0,     0,
     448,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
       0,  1845,  1846,  1847,  1848,  1849,  1850,  1851,  1852,  1853,
    1854,     0,     0,  1855,     0,     0,     0,  3423,     0,     0,
       0,     0,     0,     0,     0,     0,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,  2161,  2162,  2163,  2164,  2165,
    2166,  2167,  2168,  2169,  2170,     0,     0,  2171,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,  2799,     0,
       0,     0,     0,     0,     0,     0,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,  3361,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,  3502,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3478,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  3527
  };

  const short
  parser::yycheck_[] =
  {
       0,   274,  1014,     3,   737,   353,   512,   258,   767,     9,
     808,   994,  1709,   238,    14,   331,   249,   333,   366,   335,
     220,    21,   238,   238,   220,   238,   238,   369,   257,  1018,
     238,   238,   238,    33,   257,   358,   257,   249,   238,   238,
     347,    41,    42,    43,   238,   257,    46,   358,   347,    49,
     249,   257,    52,   358,   347,   249,   358,   316,   257,    59,
      60,    61,    62,   257,    64,    65,    66,    67,    68,  1745,
      70,    71,   220,   347,   356,   347,   358,   322,   360,   347,
     362,   319,   364,   358,   366,   316,   356,   300,   316,   319,
     238,   358,   311,   358,   364,   313,   358,   294,    98,   233,
     234,   292,   281,   316,   300,   313,   358,   257,   245,   340,
     266,   238,   340,   113,   347,   226,  1652,   281,   347,   294,
     316,   281,   238,   281,   347,   350,   347,  1764,   238,   263,
     257,   306,   348,   348,   347,   347,   270,   225,   238,   347,
     347,   347,   358,   358,   292,   238,   257,   347,   347,   358,
     238,   347,   300,   347,   356,   313,  1764,   218,   306,  2103,
     362,   927,   296,   358,   366,   238,   358,  1843,   316,   262,
     356,   356,   356,   358,   238,   360,   360,   362,  2188,   364,
     366,   366,   366,   238,  2889,    71,   356,   238,   238,   238,
     356,   238,   238,   358,   238,   238,   366,   356,   238,   347,
     366,   356,   350,   356,    71,   238,   238,   366,   238,    71,
     358,   366,   238,   366,   356,   356,  2630,  2631,    71,  1603,
    2936,   221,  1631,  1632,   366,   366,    10,    55,   228,   238,
     238,   231,   238,   233,   234,   235,   128,   238,   128,   239,
     240,   241,   242,   128,    87,   128,    71,   247,  1591,    71,
     250,   251,   252,   128,    82,   255,    87,  2791,   258,   128,
     128,   261,   128,   263,    92,    71,    87,  1651,    69,  1653,
     270,    63,  2791,    47,    87,  2791,   128,   277,   278,   279,
     128,   269,   282,   283,   284,   128,    71,   259,   288,   120,
     290,  2791,   224,    69,  1678,   295,   296,   128,   161,   805,
     353,   301,   302,  2791,   141,    94,   257,   128,  1651,  3277,
    1653,  2791,   353,  2791,   314,   128,    87,   317,   225,   103,
     320,   141,    55,   323,    69,    69,    87,   327,   328,    87,
     330,   238,   332,   327,   334,   360,   336,   337,    69,   311,
      87,   341,   141,   514,    71,   129,   130,   131,    87,   300,
      87,   146,    47,    87,   354,    87,   327,   128,   529,    87,
     206,   207,    87,    78,   353,   316,   128,   128,    50,    51,
     128,   353,   214,   215,    69,   126,   127,   377,   378,   379,
     380,   128,   382,   175,    56,    57,  3106,   294,   581,   128,
     353,   128,   585,    47,   128,    87,   128,    71,   193,   306,
     128,   128,   230,   128,   311,  3257,   353,    89,   443,   237,
      82,    83,    87,   582,    69,    69,    87,  1953,   581,   327,
    1679,  1680,    71,   224,  3144,   327,   461,   327,   120,   257,
     432,   362,   363,   582,  3286,   366,   128,   265,    95,    96,
      97,    98,    99,   100,   101,   102,   582,   353,   448,   120,
     327,   243,    87,   128,   353,    87,   582,   128,   242,    11,
     582,   226,   327,   353,   353,    89,    90,   327,   353,   297,
      95,    96,    97,    98,    99,   100,   101,   102,    87,   224,
     245,    55,    34,   581,   249,   120,   583,   353,   120,   489,
     587,   353,   257,   128,   581,   582,   128,    49,   353,  2636,
    2637,   252,   253,  2640,   353,   581,    80,    81,    82,   260,
     353,   513,   512,   515,   516,   353,    68,   360,   361,   128,
     583,   349,   280,  1907,   587,   582,   259,   292,  1912,   360,
     361,   327,   585,   327,   582,   324,   581,   327,    87,   360,
     361,   306,   583,   353,   328,  1954,  1955,   327,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   230,   335,
     366,   335,   587,   327,   327,   139,   839,   555,   327,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   128,
     154,   366,   353,   515,   516,  1994,  1995,   353,   582,   360,
     361,   335,   353,  3561,   128,  1584,   585,   149,  1587,   360,
     361,   583,   360,   361,   335,   280,   353,  3459,   924,   925,
     588,   582,   353,   360,   361,   461,   168,    55,   256,  3471,
     583,   353,   196,   360,   361,   462,   360,   361,   360,   361,
     287,   128,   360,   361,   581,   360,   361,   288,    87,   502,
     335,   353,   462,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   287,   462,  3384,   517,   518,   353,   360,   361,
     353,   120,   344,   345,   582,    87,   582,   229,  3398,   128,
     582,   335,   582,   353,   583,   360,   361,  3403,  3404,   473,
     264,   353,   581,   585,  3228,   585,   581,  3413,   832,  3415,
       3,   584,   588,   255,   496,   582,     9,   582,  3560,  3228,
      10,    14,  3228,   582,   582,   581,   128,   582,    21,   581,
    2129,   588,   582,   723,  2108,   725,   726,   582,  3228,   582,
     730,   731,   732,   581,   583,   735,   736,   737,    41,    42,
    3228,  3155,   585,    46,   572,   583,    49,   539,  3228,    52,
    3228,   360,   361,  1742,   585,   755,    59,    60,    61,    62,
    3465,    64,    65,   588,   585,  2108,   588,   767,    71,   561,
     562,   584,   772,   583,   128,   581,   581,   432,   330,  1095,
    1096,   581,  2041,   584,  1100,  1101,   582,    87,   582,  1105,
    1106,  2050,   582,   353,  2053,    98,   581,    44,    55,    46,
    3520,   360,   582,   103,   353,   805,   353,    58,   808,   353,
     582,   360,   361,   584,   814,    55,   353,   583,   582,   582,
     120,   582,   353,   582,   582,    82,   360,   361,   128,   129,
     130,   131,   832,   353,   581,   582,   353,   837,    89,    90,
    2850,   841,   583,  2853,   844,   582,   582,   847,   582,   581,
     582,   353,    92,   353,   582,   353,   494,   582,   513,   353,
     515,   516,   582,   360,   361,   582,   166,   353,   280,   353,
     353,   583,   353,   581,   353,   581,   353,   353,   178,  3293,
     581,   353,   520,   521,   522,   523,   582,   353,   353,   546,
     190,   191,   353,   353,   353,   582,   581,   583,   582,  1888,
     583,   581,   582,   496,   353,   581,   344,   345,   350,   351,
     352,   360,   361,   583,   488,   489,   457,   458,   459,   581,
     461,   546,   922,   581,   224,   581,   926,   927,   228,   532,
     533,   534,   535,   353,   353,   353,   256,   937,   938,    47,
     353,   582,   242,   582,   353,   353,   539,   581,   360,   361,
      71,   362,   363,   360,   361,   366,   520,   957,   551,   552,
     582,    69,   582,   527,   528,    47,   530,   581,   582,   226,
     107,   581,   582,   230,   582,   112,   113,   114,   335,   581,
     237,   581,   420,   421,   422,   423,   424,  3401,    35,    47,
     581,   582,   992,   993,   581,   582,   434,   435,   436,   353,
     257,   581,   582,   441,   442,   142,   444,   445,   581,   582,
     257,    69,   259,    12,  1014,   335,   336,   337,   457,   458,
     459,    88,   461,   583,   583,    47,   108,   164,   328,   467,
     167,   360,   361,   362,   363,  1035,   583,   366,    35,   583,
     297,   582,   289,   210,   211,   212,   583,  1813,    67,    35,
    1816,    78,   583,   288,   305,   220,   221,   222,   496,   163,
     360,   361,    47,   583,   582,  2054,   583,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,   165,
     335,   583,   382,   583,    69,   583,   386,   387,   388,   583,
     581,   582,   349,  1093,   254,  2084,  2085,   583,  1098,   583,
     583,   539,   583,  1103,   583,   543,   583,   583,  1108,   259,
    1110,   583,   356,   357,   358,   359,   224,   583,   583,   220,
     221,   222,   583,   583,   583,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   128,   573,   574,   575,   576,   577,
     578,   579,   224,  3087,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   583,   583,   583,   224,   350,   351,   352,
     583,   308,   224,   473,   583,   583,   581,   584,   286,   254,
     420,   421,   422,   423,   424,   425,   426,   581,   582,   429,
     430,   117,  2889,   433,   434,   435,   436,   437,   438,   439,
     440,   441,   224,   311,   444,   445,   446,   447,   448,   449,
     450,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   581,   582,   366,   581,   582,   467,   468,   469,
     470,   471,   581,   582,   474,   475,   476,   477,   478,   224,
     480,   481,   482,   483,   484,   485,   486,   123,   124,   125,
     490,   491,   492,   311,   273,   274,   275,   276,   277,   278,
     584,  2937,   581,   582,   286,   581,   582,   581,   582,   224,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   216,   582,   366,   581,   582,   937,   938,   503,   311,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   581,   582,   366,   581,   381,   957,   360,   361,   362,
     363,   581,   582,   366,  2303,  2304,   581,   582,   457,   458,
     459,   247,   461,   563,   107,    71,   311,   581,   582,   112,
     113,   114,   462,   259,    71,    71,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   581,   582,   581,   582,   142,
     581,   582,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   164,    71,   309,   167,    71,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,    71,  1606,   581,   582,    71,
    1606,   356,   357,   358,   359,   360,   361,   362,   363,    71,
     346,   366,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   583,    71,   582,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,  1589,    71,   366,  1606,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,  1703,   356,
     357,   358,   359,   360,   361,   362,   363,  1703,  1703,   366,
    1703,  1703,    71,  1809,  1810,  1703,  1703,  1703,  1731,   282,
     583,   581,   582,  1703,  1703,    71,    71,  2766,   353,  1703,
     581,   582,    71,  1624,   583,    71,  1650,    71,   353,  1731,
     583,   583,  1751,    71,    71,   308,   583,   353,  1751,  1617,
    1751,    71,  1731,  3170,   583,    71,    71,  1731,    71,  1751,
    1601,    71,  1676,    71,    71,  1751,    71,  1681,    71,  2538,
      71,  2540,  1751,    71,    71,  1703,    71,  1751,   353,    71,
      71,    71,  3170,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   583,   353,   366,  1703,   581,   583,  3276,
     583,  3278,    71,  3119,    71,   583,    71,  1703,  1725,  1589,
      71,    71,    71,  1703,  1594,  1595,    71,    71,    71,    71,
      20,  1751,    71,  1703,  1738,  1605,    26,    71,  1608,    71,
    1703,    31,    32,    71,  1748,  1703,  1772,  1933,  1934,    71,
    1754,  1937,  1938,    71,  1751,  1941,  1942,    71,  1807,  1629,
    1703,    69,  3308,  1633,  3310,    71,  1636,  1637,    71,  1703,
    1751,    71,    71,  1807,    71,  1645,  3055,  1807,  1703,  1807,
    1650,   353,  1703,  1703,  1703,  1914,  1703,  1703,    71,  1703,
    1703,    71,    71,  1703,  1798,  1878,    71,    47,  1859,  1866,
    1703,  1703,   581,  1703,  1919,  1675,  1676,  1703,    71,  1917,
      71,  1681,  1878,  1914,  1991,  1904,  1914,  1917,  1688,    69,
    1908,  1866,  1991,    71,  1703,  1703,    71,  1703,  1991,    71,
    1908,  1914,  1703,    71,  1704,    71,    71,    71,  2056,    71,
    1617,  1859,    71,    71,    71,    71,  1891,  1991,  1914,  1991,
      71,    71,    71,  1991,   144,   145,  1957,    71,    71,  1957,
    1878,    71,  1732,    71,    71,    71,    71,    71,  1738,    71,
      71,    71,    71,  1891,  2092,    71,    71,    71,  1748,    71,
    1908,    71,    71,  2076,  1754,    71,   353,  1757,  1991,  1893,
     583,  1895,  1991,  1763,  1764,  2076,  1914,  2109,  1991,  3466,
    1991,  2076,   848,    71,  2076,  1775,  2058,  2766,  1991,  1991,
      71,  1997,  1997,  1991,  1991,  1991,   224,  1787,  2058,   583,
     581,  1991,  1991,  1793,  2076,  1991,  1703,  1991,  1798,  2081,
    1751,  2076,   353,   353,  3480,  2087,   583,  2089,  1808,  2076,
    2092,  2076,   582,  1813,  2076,  1949,  1816,  2042,   583,  2089,
    1820,  1821,  1822,  1823,  2076,   583,  1826,  1827,  1828,  1829,
    1830,  1831,  1832,  1833,  1834,  1835,  1836,  1837,  1838,  1839,
    1840,  1841,  1842,  1991,   224,  1845,  1846,  1847,  1848,  1849,
    1850,  1851,  1852,  1853,  1854,  1855,  2058,    71,  1992,  1624,
    2076,  2076,   353,    71,    71,  3562,    71,  2076,    71,    71,
    2004,    71,  2058,  2058,  2058,  1875,  1876,  1877,    71,  1879,
      71,  2076,  1882,  1883,  2076,  2087,   353,  2876,  2058,  2878,
    2092,  2076,  2058,  1893,  2042,  1895,  2081,  2081,   583,  2058,
    1900,  1901,  2087,  2058,  2089,  2058,  2092,  2092,  2092,  1909,
     496,  2076,  2046,  1913,  2048,  2049,  2058,  2058,  1918,    71,
    1920,    71,  2092,   583,   583,    71,  2092,  1878,  2076,    71,
    1930,   311,    71,  2092,    71,    71,   583,  2092,   582,  2092,
     583,   353,   582,    71,    71,  1945,    71,    71,    71,  1949,
    2092,  2092,   538,   539,    71,    71,  1956,    71,  3217,  1866,
    1725,  3220,    71,  1914,    71,  3224,  1731,  3226,  3227,    71,
     556,   557,   558,   559,   560,    71,   582,  2111,   581,  2113,
    2114,   582,   582,  2117,  1891,    71,  1751,   582,   582,   582,
     582,   582,  1992,  1993,  2977,   582,  2985,  1904,  2249,   582,
     582,   582,   582,    71,  2004,   582,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   582,    71,   582,    71,   582,
     582,    71,    71,   582,   293,    71,   582,   582,    44,   582,
     582,   582,   288,    71,   583,   583,  2046,    71,  2048,  2049,
     353,   583,    71,    71,    71,    71,    71,  2057,   317,   318,
      71,    71,    71,   583,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   353,    71,    71,    71,    71,    71,   583,
     353,    71,    71,    71,  1859,    21,    22,    23,   104,   105,
    3089,    27,    28,    29,    30,    71,    71,    71,    71,    71,
      71,  2111,    71,  2113,  2114,    71,    71,  2117,    71,    45,
     583,  2919,   353,  2123,  2124,    71,  1891,  2127,   583,    55,
    2130,  2131,    71,  2133,  2134,  2135,  3125,  2137,    71,  3128,
      71,    71,    71,    71,    71,   582,    71,    71,  2464,    71,
    2909,    71,    71,  2404,    71,    71,    82,    71,    71,    71,
      71,    71,    71,    71,    71,  2438,  2899,    71,    71,  1820,
    1821,  1822,  1823,    71,    71,  1826,  1827,  1828,  1829,  1830,
    1831,  1832,  1833,  1834,  1835,  1836,  1837,  1838,  1839,  1840,
    1841,  1842,    71,    71,  1845,  1846,  1847,  1848,  1849,  1850,
    1851,  1852,  1853,  1854,  1855,  2205,    71,  2207,    71,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   353,
    2220,   366,   583,    71,    71,    71,   232,    71,    71,    71,
    3219,   237,    71,    71,  3223,    71,    71,   496,    71,    71,
     499,  2241,    71,    71,  2244,    71,  2246,    71,    71,  2249,
      71,    71,    71,   259,    71,    71,     4,     5,     6,    71,
      71,    71,    71,  3252,    71,    71,    55,    71,    71,    71,
    2270,    71,    47,    71,    71,  2591,    71,    71,  2594,   538,
     539,  2597,   541,   542,    71,   544,   545,   546,    71,    71,
      71,  2425,   551,    71,    69,    71,  2430,    71,    71,    71,
      71,   445,  1605,   562,   230,   231,    71,   451,   452,   453,
     454,   455,   456,    19,    20,  3327,    71,   583,    24,    25,
      26,   353,   466,   353,    71,    31,    32,    71,   472,    71,
    1633,    37,    38,  1636,  1637,    71,    71,    71,   264,   265,
      71,    71,    71,    71,    71,    71,   583,  2347,  2348,   353,
     583,    71,    71,   142,   143,    71,   104,   105,    71,    71,
      71,    71,  2362,    71,  2870,   353,  2366,    71,   157,    71,
    2370,    71,    71,    71,    71,   164,    71,    47,   167,    71,
      71,  2381,  2382,    71,   583,    71,   353,   583,  2388,   137,
     179,    71,    71,    71,  3383,    71,   353,   583,   583,   105,
     148,  1704,   150,   353,  2404,    71,   353,  2913,   583,    71,
    2410,    71,  2412,    71,    71,    71,    71,    71,   344,   345,
    2420,    71,  3411,  2423,    71,  2425,    71,    71,    71,  1732,
    2430,    71,   588,   582,   581,    71,   581,   588,   144,   145,
     588,   582,   582,  2791,  2444,   588,   581,   236,   196,   224,
     582,   582,   293,   582,   128,   581,    87,   128,   280,   128,
     582,   582,   582,  2463,   582,   128,   581,  3456,   353,   582,
     259,   582,   582,  3462,   582,   128,   317,   318,   582,   582,
     128,  1557,  1558,   582,   232,   582,   128,   582,   582,   237,
    3479,   582,   582,   582,   582,   582,   128,   128,   582,  1575,
     582,   128,   250,   251,   584,  1808,  2506,   128,   128,   257,
     128,   259,   128,   302,   128,   582,   128,   306,  2518,   308,
    2520,   310,   128,   271,   272,  3514,   232,   581,  2528,   581,
    2530,   581,   581,  2533,   581,   166,   311,   128,   128,   128,
     582,   289,   128,   128,   128,   128,  2546,   178,  2548,   128,
     128,   128,  2552,   128,   224,   128,   128,   346,   584,   190,
     191,   128,  2562,   128,  1640,   128,   128,  2567,   814,  2569,
     582,   128,   128,  2573,  1877,   582,  2576,   128,   581,   581,
     581,   581,   128,   331,   332,   831,   353,   353,  2588,  2589,
    2590,   297,   353,   224,   353,   128,   128,  1900,   588,   581,
     581,   128,   128,   128,   581,   581,  1909,   581,   581,   128,
    1913,   128,  2612,   581,   128,  1918,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   224,  1930,   366,   581,
     581,   128,   581,  1709,   582,  2635,  2636,  2637,   581,  1715,
    2640,   311,   582,   349,  1720,   581,   581,   128,   396,   583,
     582,   128,   128,  1956,  1730,   496,   128,    71,   499,   128,
     581,   128,  2935,   581,   128,  1741,  2666,   582,   128,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   581,   581,
     581,   937,   938,   581,   581,   581,   128,   538,   539,   540,
     541,   542,   366,   544,   545,   581,  2706,   128,   581,   581,
     551,   957,   353,   581,  1790,   581,  1792,   128,   582,   581,
    2720,   562,   581,   128,    47,   582,   581,    71,   581,   360,
     361,   582,   128,   128,   128,   128,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,   128,   128,
     581,   382,   128,   128,  2057,   386,   387,   388,   389,   390,
     128,  2412,   128,   581,   128,  2765,   128,   128,   128,  2420,
     128,   128,  1018,   581,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   128,   584,   366,   128,   128,   128,
    1886,   128,   582,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   582,   582,   128,   128,   582,   128,   581,   128,
    1916,   128,   128,   581,   128,  1921,  1922,  1923,  1924,    47,
     582,   128,   128,   128,   128,  2506,  2856,   128,   128,   128,
    2860,   128,   128,  2863,   128,   128,   128,   128,   128,   128,
    2870,   128,   128,  2873,   128,   128,   128,   128,   128,   128,
    3228,   128,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   128,   128,   366,   293,   128,   128,  2899,
     128,   224,   128,   128,   581,   128,   128,   128,   128,  2909,
     108,   128,   128,  2913,   581,   128,   128,  2220,   128,  2919,
     317,   318,   128,  2923,  2924,   128,   128,  2927,   128,   581,
    2930,   128,   581,   128,   128,   581,   128,   128,  2589,  2590,
     128,   512,   581,   581,   581,  2945,  2946,   581,   581,   584,
     128,   582,   581,  2953,   584,  2955,   128,   581,   128,   581,
     366,   140,   581,   259,  2964,   582,  2966,  2270,   581,   360,
     280,   582,  2972,   582,   280,   583,   581,    47,   581,  2979,
     587,   353,   581,   353,   128,   128,   583,   583,   311,   583,
    2990,  2991,    71,    71,   353,   583,   583,  2997,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   583,
     366,   366,   581,   259,   128,  3331,   128,  3017,   353,   583,
     581,   353,  3022,   583,   583,   280,   224,   581,   581,  3029,
     588,   581,    71,   588,  3168,   583,   583,   353,   108,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     588,    71,   366,  3053,   583,  2706,  3056,    71,   582,  3059,
      71,   128,  2138,  2139,  2140,  2141,   587,   128,  2144,  2145,
    2146,  2147,  2148,  2149,  2150,  2151,  2152,  2153,  2154,  2155,
    2156,  2157,  2158,  2159,   588,  2161,  2162,  2163,  2164,  2165,
    2166,  2167,  2168,  2169,  2170,  2171,   581,   588,   582,   496,
      71,   581,   499,   581,   128,   353,   280,   581,   353,   353,
    3426,  3427,   583,   353,   353,   353,   582,  3117,   583,    71,
    2423,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
      71,   538,   539,   581,   541,   542,    71,   544,   545,   546,
     547,    71,   583,   583,   224,   583,   583,  3157,   581,  3159,
     353,  3161,    71,    71,    71,   562,    71,    71,  3168,    71,
    3170,  3487,  3488,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,    71,    71,   366,  3187,  3188,   588,
    3190,   141,   581,    71,   462,    71,   588,  3197,   588,   582,
     128,   587,   353,   581,   353,  3205,  3206,   353,   581,   583,
     512,   582,   581,  3213,   581,   128,   581,   140,   581,   334,
     280,   353,   128,  3539,    71,   353,   327,   581,   583,   581,
     581,   581,   581,   353,  3234,   583,   583,  3237,   583,   582,
     582,   587,   581,  2546,    69,  2548,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   334,  2569,   353,   327,   583,
     588,   128,  2923,  2924,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   588,   512,   366,  2363,   588,   588,
     588,  2367,   128,   588,  2945,  2946,   581,   587,  3298,   582,
    3300,   353,  2953,   353,  2955,   353,   585,   587,   581,   327,
     582,   327,    71,  2964,   128,  2966,  3316,    69,  3318,  3319,
     353,   140,   462,   581,   141,   128,    71,  3327,   327,   327,
    3330,   353,  3332,  3333,   353,   462,   353,  1583,  1584,  1585,
     582,  1587,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   581,  1599,   366,   588,   588,   581,  1604,   353,
     141,   353,   581,  2666,   582,   353,  1612,  1613,   583,  1615,
    2446,   585,   581,  1619,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   582,   581,   581,   128,   582,  1644,   224,
    1646,  1647,  1648,   583,   581,  3405,   582,   582,   581,   353,
    1656,   128,  1658,   581,   581,   581,  1662,  1663,  1664,  1665,
    1666,  1667,   581,   128,  3424,   583,  1672,   353,   581,   583,
    3430,   583,   128,   583,   113,  2388,  3206,  2930,  1684,  1772,
    2922,  2098,  2523,  2519,  3444,  3550,  3446,  3439,  1694,  1695,
    2106,  3547,  1698,  3411,  2109,   280,  2438,  1617,  1779,  2934,
    2538,   373,  2765,  1891,  2115,  2541,  2119,  1908,    21,    22,
      23,  2370,   224,   755,    27,    28,    29,    30,  1997,  2555,
      33,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,    44,    45,   366,   377,  3495,  1742,    69,  3254,  3228,
    3500,  3090,    55,   583,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   379,   726,   366,   380,  1764,  1703,
    3126,  3463,  1768,  1807,   732,  3129,  1751,  1775,   280,    82,
    2576,   844,  1778,  1929,  1917,  1080,  3187,  3188,  1596,    92,
    1601,  2042,  2058,  3543,  3544,  1991,  1957,  2056,  2092,  1795,
    3550,  1878,  2089,  1799,  1914,  1801,  2087,  1803,  1634,  2081,
    1731,  1624,  2076,   490,  1725,   772,  2410,  3197,  1606,  1882,
    3570,   583,  3572,  1901,  1820,  1821,  1822,  1823,  2607,  3222,
    1826,  1827,  1828,  1829,  1830,  1831,  1832,  1833,  1834,  1835,
    1836,  1837,  1838,  1839,  1840,  1841,  1842,  1899,   841,  1845,
    1846,  1847,  1848,  1849,  1850,  1851,  1852,  1853,  1854,  1855,
      -1,    -1,    -1,    -1,  2127,  1861,  1862,    -1,  1864,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,  1884,  1885,
      69,    -1,  1888,    -1,    -1,    -1,    -1,    -1,    -1,  3300,
      -1,    -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1906,    -1,    -1,    -1,    -1,  3316,    -1,  3318,  3319,  2972,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   230,   231,    -1,
      -1,    -1,  1928,    -1,    -1,    -1,    -1,     4,     5,     6,
      -1,    -1,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   264,   265,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,    -1,    -1,   366,  1972,    44,    -1,  1975,
    1976,    -1,    -1,   583,    -1,    -1,    -1,  1983,    55,  1985,
    1986,  1987,  1988,  1989,   224,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,    -1,    -1,   366,    -1,
      -1,  2837,    -1,    -1,    -1,    82,    -1,    -1,  2014,  2015,
      -1,    -1,    -1,    -1,    -1,    -1,  2022,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   104,   105,   366,
      -1,   344,   345,    -1,    -1,   224,    -1,    -1,    -1,    -1,
      -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,  2054,    -1,
      -1,    -1,    -1,    -1,    -1,  2061,  2062,  2063,  2894,  2065,
     137,    -1,  2068,  2069,  2900,    -1,    -1,    -1,  2074,  2075,
      -1,   148,    -1,   150,    -1,  2911,    69,   154,  2084,  2085,
      -1,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,    -1,   169,   366,    87,    -1,    -1,  2103,    -1,    -1,
      -1,    -1,    -1,  2939,    -1,    -1,    -1,    -1,   185,    -1,
      -1,    -1,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,    -1,    -1,    -1,    -1,   128,    -1,    -1,    -1,    -1,
    2976,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2987,    -1,   230,    -1,   232,    -1,    -1,    -1,    -1,
     237,    -1,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,    -1,   166,   366,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   583,    -1,    -1,   178,    -1,   264,   265,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,   191,    -1,
      -1,    -1,    -1,    -1,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,    -1,    -1,    -1,  3062,  3063,    -1,    -1,
      -1,   224,    -1,    -1,  3070,    -1,  3072,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3081,   583,  3083,    -1,    -1,
      -1,    -1,    69,    -1,   331,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,    -1,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,  2291,  2292,   366,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2303,  2304,    -1,
    3136,  3137,    -1,  3139,    -1,    -1,    -1,    -1,    -1,    -1,
     583,  3147,    -1,    -1,    -1,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,    -1,    -1,    -1,    -1,   587,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3191,    -1,  3193,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3202,   360,   361,    -1,
      -1,    -1,    -1,    -1,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,    69,    -1,    -1,   382,
      -1,   583,    -1,   386,   387,   388,   389,   390,    -1,    -1,
      -1,    -1,    -1,    -1,    87,    -1,  2412,   224,    -1,  3245,
      -1,    -1,    -1,    -1,  2420,    -1,    -1,  3253,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  2432,    -1,    -1,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,    87,
      69,   366,    -1,    -1,    -1,   128,    -1,    -1,    -1,    -1,
      -1,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
      -1,   548,   549,   550,    -1,    -1,    -1,    -1,    -1,    -1,
     128,    -1,    -1,   166,    -1,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   178,    -1,   366,    69,  3335,
    2506,    -1,    -1,    -1,   583,    -1,    -1,   190,   191,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,    -1,
     178,   366,  2538,  3369,  2540,  3371,  3372,    -1,    -1,    -1,
      -1,   224,   190,   191,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,    -1,    -1,   366,  3393,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,    -1,    -1,
     366,    -1,    -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,
      -1,    -1,    -1,  2589,  2590,   142,   143,    -1,    -1,   582,
      -1,   584,    -1,   586,    -1,   224,    -1,    -1,  3434,  3435,
     157,    -1,    -1,  3439,    -1,    -1,    -1,   164,    -1,    -1,
     167,    -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,  3455,
      -1,    -1,   179,    -1,  2630,  2631,    -1,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,   583,    -1,
    3496,    -1,    -1,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,    -1,    -1,   366,    -1,   360,   361,   236,
    3516,    -1,    -1,    -1,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,    -1,    -1,    -1,   382,
    2706,    -1,    -1,   386,   387,   388,   389,   390,    -1,    -1,
      -1,  3547,   360,   361,   583,    -1,    -1,    -1,  3554,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,    -1,    -1,    -1,   382,    -1,    -1,    -1,   386,   387,
     388,   389,   390,   353,    -1,   302,    -1,    -1,   583,   306,
      -1,   308,    -1,   310,    -1,    -1,    -1,    -1,    -1,  3595,
    2766,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   583,    -1,   346,
      -1,    -1,    -1,    -1,    -1,    -1,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,    -1,    -1,    -1,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,    -1,   128,   366,    -1,
    2876,    -1,  2878,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   583,    69,    -1,    -1,    -1,    -1,    -1,   582,
      -1,   584,    -1,   586,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     0,    -1,    -1,    -1,    -1,  2923,  2924,    -1,
      -1,    -1,    -1,    -1,  2930,    -1,    14,    15,    -1,    -1,
      -1,    -1,    -1,    -1,   582,    -1,   584,    -1,   586,  2945,
    2946,    69,    -1,    -1,    -1,    -1,    -1,  2953,    -1,  2955,
      -1,    39,    40,    41,    42,    43,    -1,    -1,  2964,    47,
    2966,    -1,    -1,   224,    -1,    -1,    54,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   585,    64,    65,    66,  2985,
      -1,    -1,    70,    -1,    72,    73,    74,    75,    76,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    -1,    -1,
      -1,    -1,    -1,    -1,    92,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,    -1,    -1,   366,    -1,   280,
     108,   109,   110,   111,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   119,    -1,   121,   122,    -1,    -1,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   135,   224,   366,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,    -1,    -1,   366,    -1,   153,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   162,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3088,  3089,    -1,   583,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   224,    -1,   186,   187,
     188,   189,    -1,    -1,   192,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   203,    -1,   366,    -1,  3125,
      -1,    -1,  3128,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,    -1,    -1,   366,   224,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,    -1,  3155,
     366,    -1,    -1,    -1,    -1,    -1,   244,    -1,   246,    -1,
     248,   249,    -1,    -1,  3170,    -1,    -1,    -1,   256,    -1,
      -1,   259,    -1,   261,   262,    -1,    -1,    -1,   266,   267,
      -1,  3187,  3188,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,    -1,   291,   292,    -1,   294,   295,   296,    -1,
     298,   299,    -1,  3219,    -1,  3221,   304,  3223,    -1,   307,
      -1,    -1,    -1,    -1,   312,   313,    69,    -1,    -1,    -1,
      -1,   319,   581,   321,   322,   323,    -1,   325,    -1,    -1,
      -1,   329,    -1,    -1,    -1,    -1,  3252,   335,   336,   337,
     338,   339,   340,   341,   342,   343,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   583,    -1,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,  3293,    -1,    -1,
      -1,    -1,    -1,    -1,  3300,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   391,    -1,    -1,    -1,    -1,    -1,    -1,
    3316,    -1,  3318,  3319,    -1,    -1,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,    -1,    -1,   425,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,    -1,    -1,
     366,    -1,   583,    -1,    -1,    -1,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,    -1,    -1,  3383,    -1,    -1,
      -1,   224,    -1,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,    -1,  3401,   366,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  3411,    69,    -1,    -1,    -1,
      -1,    -1,   500,   501,    -1,    -1,   504,   505,   506,   507,
     508,   509,   510,   511,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   519,    -1,    -1,    -1,    -1,   524,   525,    -1,    -1,
      -1,    -1,   224,   531,    -1,    -1,    -1,    -1,    -1,    -1,
    3456,    14,    15,    -1,    -1,    -1,  3462,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   553,   554,    -1,    -1,    -1,
      -1,    -1,    -1,  3479,    -1,    -1,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    47,   224,    -1,    -1,    -1,    -1,
      -1,    54,   580,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    64,    65,    66,    -1,    -1,    -1,    70,  3514,    72,
      73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    85,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      -1,    -1,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,    -1,    -1,   366,   108,   109,   110,   111,    -1,
      -1,    87,    -1,    -1,    -1,    -1,   119,    -1,   121,   122,
      -1,   224,    -1,    -1,    -1,    -1,    -1,   583,    -1,    -1,
      -1,   353,   135,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,    -1,   120,   366,    -1,    -1,    -1,    -1,
     153,    -1,   128,    -1,    -1,    -1,    -1,    -1,    -1,   162,
      -1,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
      -1,    -1,    -1,   186,   187,   188,   189,    -1,    -1,   192,
     166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     203,    -1,   178,    -1,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   190,   191,   366,    -1,    -1,    -1,
      -1,   224,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   244,    -1,   246,    -1,   248,   249,    -1,   224,    69,
      -1,    -1,   228,   256,    -1,    -1,   259,    -1,   261,   262,
      -1,    -1,    -1,   266,   267,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,    -1,    -1,    -1,    -1,   291,   292,
      -1,   294,   295,   296,    -1,   298,   299,    -1,    -1,    -1,
      -1,   304,    -1,    -1,   307,    -1,    -1,    -1,    -1,   312,
     313,    -1,    -1,    -1,    -1,    -1,   319,    -1,   321,   322,
     323,   583,   325,    -1,    -1,    -1,   329,    -1,    -1,    -1,
      -1,    -1,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
      -1,    -1,   583,   585,    -1,    -1,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,    -1,   353,   366,    -1,
      -1,    -1,    -1,    -1,   360,   361,    -1,    -1,   391,    -1,
      -1,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,    -1,   224,   584,   382,    -1,    -1,    -1,
     386,   387,   388,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   425,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   583,    -1,   366,    -1,    -1,    -1,    -1,
      -1,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   500,   501,    -1,
      -1,   504,   505,   506,   507,   508,   509,   510,   511,    -1,
      -1,    -1,    -1,    69,     3,     4,   519,     6,    -1,     8,
       9,   524,   525,    -1,    13,    -1,    -1,    16,   531,    18,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
      -1,    -1,   366,    -1,    -1,    -1,    -1,    36,    -1,    -1,
     553,   554,    -1,    -1,    -1,    44,    45,    -1,    -1,    69,
      -1,    -1,    -1,    52,    53,    -1,    55,    -1,    -1,    -1,
      59,    60,    61,    -1,    -1,    -1,    -1,   580,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,
      79,    80,    81,    82,    -1,   583,    -1,    86,    -1,    -1,
      -1,    -1,    -1,    92,    -1,    -1,   582,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   104,   105,   106,    -1,    -1,
      -1,    -1,    -1,    -1,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   132,   133,   134,    -1,   136,   137,   138,
     139,    -1,   583,    -1,    -1,    -1,    -1,    -1,   147,   148,
      -1,    -1,   151,   152,    -1,   154,   155,   156,   224,   158,
     159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     169,   170,   171,   172,   173,   174,   175,   176,   177,    -1,
      -1,   180,   181,   182,   183,   184,   185,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   224,   204,   205,    -1,    -1,   208,
     209,    -1,    -1,    -1,   213,    -1,    -1,    -1,   217,   218,
     219,    87,    -1,    -1,   223,    -1,   225,    -1,   227,    -1,
      -1,   230,   231,   232,    -1,   234,    -1,    -1,   237,   238,
     239,    -1,    -1,    -1,    -1,    -1,   245,    -1,   247,   583,
      -1,    -1,    -1,    -1,   120,    -1,    -1,    -1,    -1,   258,
      87,    -1,   128,    -1,   263,   264,   265,    -1,    -1,   268,
      -1,    -1,    -1,   272,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   128,    -1,   282,    -1,   284,   285,    -1,    -1,   288,
      -1,    -1,    -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,
     166,   128,    -1,    -1,   303,    -1,    -1,    -1,    -1,   308,
      -1,    -1,   178,    -1,    -1,    -1,   315,   316,    -1,    -1,
      -1,   320,    -1,    -1,   190,   191,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   333,    -1,    -1,    -1,    -1,   166,
      -1,    -1,    -1,    -1,    -1,   344,   345,    -1,    -1,    -1,
      -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,   224,    -1,
      -1,    -1,   228,   190,   191,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    87,   224,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   224,    -1,    -1,
      -1,   228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,    -1,    -1,
      -1,    -1,    -1,    -1,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,    -1,    -1,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   166,    -1,   366,    -1,    -1,
      -1,   460,    -1,    -1,    -1,    -1,    -1,   178,    -1,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   190,
     191,   366,    -1,    -1,    -1,    -1,    -1,   353,   487,   488,
     489,    -1,    -1,    -1,   360,   361,   495,    -1,    -1,    -1,
      -1,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   377,   378,   224,    -1,    -1,   382,   228,    -1,    -1,
     386,   387,   388,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   360,   361,    -1,    -1,   536,   537,    -1,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
     377,   378,    -1,    -1,    -1,   382,    -1,    -1,   224,   386,
     387,   388,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,    -1,    -1,   366,    -1,    -1,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   224,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,    -1,    -1,   366,   360,
     361,    -1,    -1,    -1,    -1,    -1,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,   224,    -1,
      -1,   382,   280,    87,   583,   386,   387,   388,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   353,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   583,   526,
      -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   128,    -1,   582,    -1,    -1,    -1,
      87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   166,   120,    -1,   582,    -1,    -1,    -1,    -1,
      -1,   128,    -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   190,   191,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   353,    -1,   166,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     224,   178,   366,    -1,   228,   526,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   190,   191,    -1,    -1,    -1,    -1,    -1,
     224,    -1,    -1,    -1,    87,    -1,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,    -1,    -1,   224,    -1,    -1,
      -1,   228,    -1,    -1,    -1,   583,    -1,   120,    -1,    -1,
      -1,   582,    -1,    -1,    -1,   128,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,    -1,    -1,    -1,
      -1,    -1,    -1,   166,    -1,    -1,    -1,   583,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   178,    -1,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   190,   191,   366,
      -1,    -1,    -1,    -1,    -1,    -1,   360,   361,    -1,    -1,
      -1,    -1,    -1,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,    -1,    -1,    -1,   382,    -1,
      -1,   224,   386,   387,   388,   228,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   360,   361,   366,    -1,    -1,    -1,    -1,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
     377,   378,    -1,    -1,    -1,   382,    -1,    -1,    -1,   386,
     387,   388,    -1,    -1,    -1,    -1,    -1,   583,    -1,   583,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,    -1,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,    -1,
      -1,    -1,    -1,   224,    -1,    -1,    -1,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   360,   361,   366,
      -1,    -1,   526,    -1,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,    -1,    -1,     3,   382,
      -1,     6,    -1,   386,   387,   388,    -1,    -1,    13,    -1,
      -1,    -1,    17,    18,    -1,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,    -1,   583,   366,    -1,   526,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   582,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,    -1,
      -1,   366,    -1,    -1,    59,    60,    61,    62,    63,   583,
      -1,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
      -1,    -1,   583,    -1,    -1,   582,    91,    -1,    93,    -1,
      -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,     6,   104,
     105,   106,    -1,    -1,    -1,    -1,    -1,    -1,    16,    17,
     115,   116,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,    -1,    -1,   366,    -1,    -1,   132,   133,   134,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,    -1,    -1,
      -1,    -1,    -1,    -1,   149,    -1,    -1,    -1,    -1,    -1,
      -1,    59,    60,    61,    62,    63,    -1,    -1,    -1,    -1,
      -1,    -1,   167,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,    -1,    -1,    -1,    93,    -1,    -1,    -1,    -1,
     195,    -1,    -1,    -1,   224,    -1,   104,   105,   106,   582,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   115,   116,    -1,
     118,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,    -1,    -1,   366,   132,   133,   134,   232,   233,    -1,
     235,    -1,   237,    -1,    -1,   240,   241,    -1,    -1,    -1,
     245,   149,   247,    -1,   583,    -1,   154,    -1,    -1,    -1,
      -1,    -1,    -1,   258,   259,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   270,    -1,   366,   583,    -1,
      -1,    -1,    -1,    -1,   279,    -1,   281,   282,    -1,    -1,
      -1,    -1,    -1,   288,   289,   290,    -1,   195,    -1,    -1,
      -1,    -1,    -1,    -1,   299,   300,   301,    -1,    -1,    -1,
     581,   582,    -1,   308,    -1,    -1,    -1,    -1,    -1,    -1,
     315,   316,    -1,    -1,    -1,   320,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   353,   232,   233,    -1,   235,    -1,   237,
      -1,    -1,   240,   241,    -1,    -1,    -1,    -1,    -1,   247,
      -1,   583,    -1,    -1,    -1,     3,    -1,    -1,     6,    -1,
     258,   259,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      -1,    -1,   270,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   279,    -1,   281,   282,    -1,    -1,    -1,    -1,    -1,
     288,   289,   290,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   299,   300,   301,    -1,    -1,    -1,    -1,    -1,    -1,
     308,    59,    60,    61,    62,    63,    -1,   315,   316,    -1,
      -1,    -1,   320,    -1,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,    -1,    -1,    93,    94,    -1,   581,    -1,
     348,    -1,     3,    -1,    -1,     6,   104,   105,   106,    -1,
      -1,    -1,    -1,    -1,    -1,   460,    17,   115,   116,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,    -1,
      -1,   366,    -1,    -1,   132,   133,   134,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   583,    -1,    -1,    -1,    -1,    -1,
      -1,   149,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,    63,    -1,    -1,    -1,    -1,    -1,    -1,   167,
      -1,    -1,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,    -1,   431,   366,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    93,    94,    -1,    -1,    -1,   195,    -1,    -1,
      -1,    -1,    -1,   104,   105,   106,   224,    -1,    -1,    -1,
      -1,    -1,   460,   583,   115,   116,    -1,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,    -1,    -1,   366,
      -1,   132,   133,   134,   232,   233,    -1,   235,    -1,   237,
      -1,    -1,   240,   241,   224,    -1,    -1,    -1,   149,   247,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     258,   259,    -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   270,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   279,   224,   281,   282,    -1,    -1,    -1,    -1,    -1,
     288,   289,   290,    -1,   195,    -1,    -1,    -1,    -1,    -1,
      -1,   299,   300,   301,    -1,    -1,    -1,    -1,    -1,    -1,
     308,    -1,    -1,    -1,    -1,    -1,   224,   315,   316,    -1,
      -1,    -1,   320,    -1,    -1,    -1,   324,    -1,   326,    -1,
      -1,   232,   233,    -1,   235,   353,   237,    -1,    -1,   240,
     241,    -1,    -1,    -1,    -1,    -1,   247,   224,   583,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   258,   259,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   270,
      -1,   366,    -1,   353,    -1,    -1,    -1,    -1,   279,    -1,
     281,   282,    -1,    -1,    -1,    -1,    -1,   288,   289,   290,
      -1,    -1,   353,    -1,    -1,    -1,    -1,    -1,   299,   300,
     301,   583,    -1,    -1,    -1,    -1,    -1,   308,    -1,    -1,
      -1,   353,    -1,    -1,   315,   316,    -1,    -1,    -1,   320,
      -1,    -1,   224,   324,    -1,    -1,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   353,   583,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,
      -1,    -1,   460,    -1,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     224,    -1,    -1,    -1,    -1,    -1,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,    -1,    -1,    -1,    -1,   460,
      -1,   224,    -1,    -1,    -1,   583,    -1,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   280,    -1,   583,    -1,
      -1,    -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   583,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   583,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   583,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,
      -1,    -1,    -1,    -1,    -1,   583,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,    -1,    -1,    -1,    -1,    -1,
     224,    -1,    -1,    -1,   581,   582,    -1,    -1,    -1,    -1,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
      -1,    -1,   366,    -1,    -1,    -1,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,    -1,    -1,   366,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,    -1,
      -1,    -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,   581,
     582,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,    -1,
      -1,    -1,    -1,   581,   582,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   224,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,    -1,    -1,   366,    -1,   582,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,    -1,    -1,
      -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,   581,   582,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   583,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,    -1,    -1,
      -1,    -1,   581,   582,    -1,   583,    -1,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,    -1,    -1,   366,
      -1,   581,   582,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     581,   582,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   224,    -1,   366,    -1,    -1,   581,   582,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   581,   582,   224,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,    -1,    -1,   366,    -1,    -1,    -1,   280,    -1,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,    -1,
      -1,   366,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   353,    -1,    -1,    -1,   280,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,    -1,    -1,   366,   581,
     582,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     353,    -1,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,    -1,    -1,   366,   581,   582,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   583,    -1,   353,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,    -1,    -1,
      -1,    -1,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   581,
     582,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   581,    -1,
     224,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   582,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   582,    -1,   224,   583,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
      -1,    -1,   366,    -1,    -1,    -1,   353,    -1,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,    -1,   581,
     366,    -1,    -1,    -1,    -1,   583,    -1,    -1,    -1,    -1,
     353,    -1,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,    -1,    -1,   366,    -1,    -1,    -1,    -1,   353,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   581,    -1,
      -1,   583,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   353,
      -1,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,    -1,    -1,   366,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   581,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   353,    -1,    -1,    -1,
      -1,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   224,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   224,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,    -1,    -1,   366,    -1,    -1,    -1,    -1,   224,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   224,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   581,    -1,    -1,   583,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   224,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,    -1,   581,   366,
      -1,   583,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   581,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   353,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   581,    -1,    -1,
     583,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   353,    -1,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
      -1,    -1,   366,    -1,    -1,    -1,    -1,   353,    -1,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,    -1,
      -1,   366,    -1,    -1,   581,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   353,    -1,   366,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,    -1,    -1,
     366,    -1,    -1,    -1,   353,    -1,    -1,    -1,    -1,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   353,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   224,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   224,    -1,    -1,    -1,    -1,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   224,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   581,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   581,    -1,    -1,   583,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   581,    -1,    -1,   583,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   353,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   583,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   581,    -1,    -1,    -1,   583,    -1,    -1,
      -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   581,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   353,    -1,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,    -1,   581,   366,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   353,    -1,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,    -1,
      -1,   366,    -1,    -1,    -1,    -1,   353,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   353,    -1,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,    -1,    -1,
     366,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,    -1,    -1,   366,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   353,    -1,    -1,    -1,    -1,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   224,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   224,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   581,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   224,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   581,    -1,    -1,   583,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   224,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,    -1,   581,   366,    -1,   583,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   581,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   353,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   581,    -1,    -1,   583,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   353,    -1,    -1,    -1,    -1,
     583,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,    -1,    -1,   366,   353,    -1,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,    -1,    -1,   366,    -1,
      -1,   581,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   353,    -1,   366,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,    -1,    -1,   366,    -1,    -1,
      -1,   353,    -1,    -1,    -1,    -1,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   353,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   224,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   224,    -1,    -1,    -1,    -1,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   224,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   581,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   581,    -1,    -1,    -1,    -1,    -1,    -1,
     583,    -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   581,   581,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   353,    -1,    -1,    -1,    -1,    -1,   581,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     581,    -1,   581,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   581,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     353,    -1,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,    -1,   581,   366,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   353,    -1,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,    -1,    -1,   366,    -1,
      -1,    -1,    -1,   353,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   353,    -1,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,    -1,    -1,   366,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,    -1,    -1,
     366,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     353,    -1,    -1,    -1,    -1,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   224,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   224,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   581,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   581,   581,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,
      -1,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   581,   581,   366,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   581,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   353,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   581,   581,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   353,    -1,    -1,   581,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,    -1,    -1,   366,    -1,
      -1,   353,    -1,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,    -1,    -1,   366,    -1,    -1,   581,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   353,
      -1,   366,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,    -1,    -1,   366,    -1,    -1,    -1,   353,    -1,
      -1,    -1,    -1,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   353,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   224,    -1,
      -1,    -1,    -1,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     581,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     581,    -1,    -1,   581,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   581,
     581,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     353,    -1,    -1,    -1,    -1,    -1,   581,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   581,    -1,   581,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   581,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   353,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,
     581,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   353,    -1,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,    -1,    -1,   366,    -1,    -1,    -1,    -1,
     353,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     353,    -1,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,    -1,    -1,   366,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,    -1,    -1,   366,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   353,    -1,    -1,
      -1,    -1,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     224,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   581,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   224,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   581,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   224,    -1,    -1,    -1,   581,
     581,    -1,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,    -1,   224,   366,    -1,    -1,   581,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   353,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   581,   581,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   353,
      -1,    -1,   581,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,    -1,    -1,   366,    -1,    -1,   353,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   581,    -1,    -1,    -1,    -1,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
      -1,    -1,   366,    -1,    -1,   224,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   581,    -1,    -1,    -1,    -1,    -1,    -1,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,    -1,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   224,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   224,    -1,    -1,    -1,   581,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   224,    -1,    -1,    -1,    -1,   581,    -1,    -1,
     581,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   224,    -1,    -1,    -1,    -1,   581,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   224,   581,    -1,    -1,
      -1,    -1,    -1,    -1,   581,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   224,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   581,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   581,    -1,    -1,    -1,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,    -1,    -1,   366,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,    -1,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,    -1,   224,
     366,    -1,    -1,    -1,   581,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,    -1,   224,   366,    -1,    -1,    -1,    -1,
      -1,    -1,   581,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     224,   140,   141,    -1,    -1,   581,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   581,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     581,    -1,    -1,    -1,    -1,   224,    -1,   128,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   581,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,
      -1,    -1,    -1,    -1,    -1,   581,    -1,    -1,   581,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   224,    -1,
     581,    -1,    -1,   581,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   140,   141,    -1,    -1,    -1,    -1,    -1,
      -1,   581,    -1,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   224,   141,   366,    -1,    -1,    -1,    -1,
     581,    -1,    -1,    -1,   280,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   224,   141,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   280,
      -1,   141,    -1,    -1,    -1,    -1,    -1,   224,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   581,    -1,   280,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   581,    -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   224,    -1,    -1,    -1,    -1,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,    -1,    -1,
      -1,   224,    -1,    -1,    -1,    -1,    -1,   581,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
      -1,    -1,   366,    -1,    -1,    -1,   224,    -1,    -1,    -1,
     581,    -1,    -1,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     224,    -1,    -1,    -1,    -1,    -1,    -1,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   224,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   353,   224,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     353,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
      -1,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,    -1,    -1,   366,    -1,    -1,    -1,   581,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,    -1,    -1,   366,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   581,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   581
  };

  const short
  parser::yystos_[] =
  {
       0,    14,    15,    39,    40,    41,    42,    43,    47,    54,
      64,    65,    66,    70,    72,    73,    74,    75,    76,    84,
      85,    92,   108,   109,   110,   111,   119,   121,   122,   135,
     153,   162,   186,   187,   188,   189,   192,   203,   224,   244,
     246,   248,   249,   256,   259,   261,   262,   266,   267,   291,
     292,   294,   295,   296,   298,   299,   304,   307,   312,   313,
     319,   321,   322,   323,   325,   329,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   391,   425,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   500,   501,   504,   505,
     506,   507,   508,   509,   510,   511,   519,   524,   525,   531,
     553,   554,   580,   590,   591,   592,   593,   594,   597,   600,
     604,   605,   606,   607,   616,   619,   620,   625,   626,   627,
     630,   633,   636,   647,   651,   662,   663,   666,   669,   672,
     676,   679,   682,   685,   688,   691,   692,   695,   698,   701,
     712,   718,   721,   724,   731,   732,   735,   736,   737,   739,
     751,   752,   753,   756,   757,   758,   767,   770,   773,   774,
     776,   779,   780,   781,   782,   783,   784,   787,   791,   794,
     795,   798,   801,   808,   809,   810,   811,   812,   813,   814,
     818,   821,   824,   827,   830,   833,   836,   839,   842,   845,
     846,   857,   860,   863,   866,   867,   870,   874,   877,   880,
     882,   885,   888,   891,  1280,   128,   582,   128,   582,   581,
     582,   705,  1280,   582,   581,   582,   582,   581,   582,   581,
     582,   705,   128,   582,   582,   581,   582,   581,   582,   705,
     581,   581,   581,   582,   581,   582,   582,   581,   581,   582,
     705,   582,   581,   582,   582,   581,   581,   582,   581,   582,
     582,   581,   582,   582,   582,   581,   582,   280,   582,   788,
     790,  1280,   581,   582,   581,   582,   581,   581,   581,   581,
     581,   582,   705,   705,   614,  1280,    71,   128,   792,   582,
     705,   581,   582,   581,   582,   705,   582,   581,   582,   581,
     582,   705,   581,   582,    71,   581,   582,   581,   582,   581,
     581,   582,   581,   582,   705,   581,   582,   705,   581,   582,
     705,   581,   582,   705,   581,   581,   582,   705,   705,   582,
     611,  1280,   612,  1280,   613,  1280,   768,   615,  1280,   581,
     582,   705,   581,   582,   581,   581,   581,   582,   582,   581,
     582,   582,   581,   582,   705,   581,   582,   581,   582,   581,
     582,   581,   582,   581,   582,   581,   582,   652,   582,   582,
     581,   582,   582,   582,   588,     0,   591,    71,   582,    71,
      71,    71,   588,   581,    21,    22,    23,    27,    28,    29,
      30,    45,    55,    82,   230,   231,   264,   265,   344,   345,
     815,   816,   817,   939,   942,   946,   965,   966,  1028,  1029,
    1035,  1036,  1070,  1071,  1072,  1073,  1074,  1075,  1076,   581,
      33,    44,    92,   816,   819,   820,   983,  1015,  1077,    80,
      81,   139,   154,   196,   488,   489,   875,   876,   939,   946,
     965,  1007,  1019,  1024,  1030,  1038,  1199,  1200,   353,   581,
    1280,   256,   335,   336,   337,   617,   107,   112,   113,   114,
     142,   164,   167,   282,   308,   678,   680,   681,   896,   918,
     926,   929,   936,  1125,  1126,  1127,  1128,    44,    46,   257,
     259,   289,   864,   865,   903,   914,   985,  1129,  1130,   335,
     868,   869,  1280,    20,    26,    31,    32,   144,   145,   855,
     856,  1054,  1058,  1061,  1062,  1063,  1066,   581,   128,   581,
     788,   788,   628,   629,  1280,    35,     3,     4,     6,     8,
       9,    13,    16,    18,    36,    44,    52,    53,    59,    60,
      61,    77,    79,    82,    86,   104,   105,   106,   132,   133,
     134,   136,   137,   138,   147,   148,   151,   152,   155,   156,
     158,   159,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   180,   181,   182,   183,   184,   185,   194,   195,   197,
     198,   199,   200,   201,   202,   204,   205,   208,   209,   213,
     217,   218,   219,   223,   225,   227,   232,   234,   237,   238,
     239,   245,   247,   258,   263,   268,   272,   284,   285,   288,
     303,   315,   316,   320,   333,   460,   487,   495,   536,   537,
     759,   760,   896,   902,   905,   909,   910,   936,   939,   940,
     941,   942,   943,   944,   945,   949,   965,   966,   967,   968,
     969,   970,   976,   978,   984,   986,   987,   988,   989,   990,
     991,   992,   993,   994,   995,   996,   997,   998,   999,  1000,
    1001,  1002,  1003,  1004,  1005,  1006,  1007,  1009,  1010,  1011,
    1012,  1013,  1014,  1015,  1016,  1017,  1018,  1019,  1020,  1021,
    1022,  1023,  1024,  1028,  1029,  1030,  1031,  1032,  1033,  1034,
    1035,  1036,  1037,  1038,  1039,  1040,  1041,  1042,  1044,  1045,
    1046,  1047,  1048,  1049,  1050,  1051,  1052,  1078,  1079,  1080,
    1081,  1082,  1083,  1084,  1085,  1086,  1131,  1192,  1198,  1199,
    1200,  1201,  1202,  1245,  1247,  1248,  1249,  1250,  1251,  1252,
    1254,  1255,   581,    47,   286,   311,   713,   714,   715,  1280,
      47,   311,   722,   723,  1280,    47,   311,   719,   720,  1280,
      12,   117,   247,   309,   346,   878,   879,   914,   915,   916,
     917,  1262,    88,   729,   730,   725,   726,  1280,   861,   862,
     914,   969,   976,   978,   984,   581,  1280,   631,   632,  1280,
      35,    78,   858,   859,  1280,     5,   150,   250,   251,   271,
     331,   332,   396,   785,   786,   903,   905,   914,   968,   969,
     976,   978,  1002,  1022,  1038,  1092,  1116,  1120,  1121,  1122,
    1123,  1124,  1130,  1245,  1246,   628,    35,    78,   886,   887,
    1280,  1020,   788,   163,   637,    11,    34,    49,    68,   149,
     168,   229,   255,   330,   634,   635,   901,   928,   931,   165,
    1025,   582,   353,   581,   788,   683,   684,   335,   650,   670,
     254,   883,   884,  1280,   771,   772,  1280,   775,  1280,    17,
      62,    63,    91,    93,   115,   116,   142,   167,   233,   235,
     240,   241,   270,   279,   281,   290,   299,   300,   301,   703,
     777,   778,   895,   896,   897,   901,   902,   903,   904,   905,
     906,   907,   908,   909,   910,   911,   912,   914,   922,   923,
     927,   932,   933,   934,   935,   936,   941,   943,   969,   976,
     978,   991,  1014,  1018,  1020,  1026,  1027,  1040,  1041,  1044,
    1045,  1049,  1050,  1051,  1052,  1181,  1182,  1192,  1252,  1253,
     581,   581,   353,   581,  1280,   327,   582,   609,   610,   128,
     581,    87,   128,   166,   178,   190,   191,   360,   361,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,   382,   386,   387,   388,   389,   390,   582,   643,   708,
    1280,   259,   581,   686,   687,   914,   939,   142,   143,   157,
     167,   179,   236,   302,   306,   310,   689,   690,   896,   898,
     899,   900,   919,   924,   925,   929,   930,  1008,  1256,  1262,
     581,   788,    47,   335,   648,   649,   650,   254,   226,   237,
     297,   349,   849,   850,   939,   942,   946,   971,   972,  1130,
    1265,  1266,   581,   280,   892,   893,  1280,   224,   584,   687,
     690,   696,   697,   126,   127,   252,   253,   260,   889,   890,
    1257,  1258,  1259,  1260,  1261,   871,   677,   678,   118,   348,
     431,   702,   703,   704,   913,   920,  1007,  1131,  1132,   581,
      92,   265,   572,   851,   852,   939,   942,   946,   971,   973,
     974,   975,  1130,  1265,  1266,   581,    94,   324,   804,   805,
    1043,  1193,   581,   703,   806,   807,  1043,  1193,   581,   224,
     799,   800,   167,   326,   802,   803,   807,   921,  1244,   581,
     581,   161,   502,   353,   581,  1280,   327,   610,   353,   581,
    1280,   327,   610,   353,   581,  1280,   327,   610,   769,  1280,
     353,   581,  1280,    19,    20,    24,    25,    26,    31,    32,
      37,    38,   105,   144,   145,   232,   853,   854,   977,   979,
    1053,  1055,  1056,  1057,  1059,  1060,  1064,  1065,  1067,  1068,
    1069,  1265,  1266,   581,   216,   119,   392,   393,   394,   395,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   419,   548,   549,   550,   847,   848,   905,   939,
     942,   946,   965,   966,   968,   969,   976,   978,   984,   986,
     996,  1007,  1022,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,  1095,  1096,  1097,  1098,  1099,  1100,  1101,  1102,  1103,
    1104,  1105,  1106,  1107,  1108,  1109,  1110,  1111,  1112,  1113,
    1114,  1115,  1117,  1118,  1119,  1120,  1121,  1245,  1246,    56,
      57,    82,    83,   230,   733,   734,   937,   938,   947,   948,
     950,  1028,  1029,   420,   421,   422,   423,   424,   425,   426,
     429,   430,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   444,   445,   446,   447,   448,   449,   450,   467,   468,
     469,   470,   471,   474,   475,   476,   477,   478,   480,   481,
     482,   483,   484,   485,   486,   490,   491,   492,   563,   822,
     823,   939,  1015,  1135,  1136,  1137,  1138,  1139,  1140,  1141,
    1142,  1143,  1144,  1145,  1146,  1147,  1148,  1149,  1150,  1151,
    1152,  1153,  1154,  1155,  1157,  1158,  1159,  1160,  1161,  1162,
    1163,  1164,  1165,  1166,  1167,  1168,  1169,  1170,  1171,  1172,
    1173,  1174,  1175,  1176,  1177,  1178,  1179,  1180,  1207,   503,
     293,   317,   318,   496,   499,   538,   539,   541,   542,   544,
     545,   546,   551,   562,   831,   832,  1203,  1204,  1206,  1223,
    1231,  1232,  1233,  1236,  1237,  1238,  1239,  1240,  1241,  1242,
     581,   540,   825,   826,  1203,  1204,  1206,  1223,  1231,  1232,
    1233,  1235,  1236,  1237,  1238,  1239,  1241,  1242,   442,   543,
     564,   565,   566,   567,   568,   569,   570,   571,   573,   574,
     575,   576,   577,   578,   579,   843,   844,   939,  1028,  1029,
    1135,  1136,  1137,  1138,  1139,  1145,  1146,  1147,  1149,  1153,
    1154,  1155,  1156,  1203,  1204,  1205,  1207,  1208,  1209,  1210,
    1211,  1212,  1213,  1214,  1215,  1216,  1217,  1218,  1219,  1220,
    1221,  1222,    63,   175,   243,   561,   840,   841,  1133,  1134,
    1203,  1204,  1223,  1224,  1225,   556,   557,   558,   559,   560,
     837,   838,  1203,  1204,  1206,  1226,  1227,  1228,  1229,  1230,
     552,   834,   835,  1203,  1204,  1233,  1234,   547,   828,   829,
    1203,  1204,  1206,  1223,  1231,  1232,  1236,  1237,  1238,  1239,
    1240,  1241,  1242,  1243,   581,   256,   494,   520,   521,   522,
     523,   664,   665,  1183,  1184,  1185,  1186,  1187,  1188,   527,
     528,   530,   667,   668,  1183,  1189,  1190,  1191,   532,   533,
     534,   535,   699,   700,  1194,  1195,  1196,  1197,   269,   555,
     693,   694,  1263,  1264,   693,   462,    47,   108,   737,  1280,
     738,   982,  1280,    47,   108,   752,  1280,    47,   108,   757,
    1280,   120,   166,   178,   190,   191,   228,   360,   361,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     378,   382,   386,   387,   388,   582,   621,   708,  1280,   140,
     141,   462,  1280,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,   353,   583,    71,    71,
      71,   353,   583,    71,    71,   583,   353,  1280,   583,    71,
      71,    71,    71,    71,    71,    71,    71,   353,   583,    71,
      71,    71,    71,    71,   353,   583,  1280,    69,   869,   353,
      71,    71,    71,   583,   353,   581,   583,   583,    69,   629,
      71,   583,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,   353,   583,  1280,  1280,    69,   714,   353,
     581,  1280,  1280,    69,   723,   353,  1280,  1280,    69,   720,
     353,   583,    71,    71,   583,   353,   360,   583,    69,   726,
     353,   353,   583,   583,    69,   632,   582,   583,    71,    69,
     859,   353,    71,    71,    71,    71,    71,    71,    71,    71,
     583,   353,    69,   583,    71,    69,   887,   353,   582,   583,
     583,    71,   584,   586,   639,   640,   643,   646,    71,    71,
      71,    71,   353,   583,    71,   583,   708,   788,   582,   353,
     583,  1280,    69,   650,   583,    69,   884,   353,    69,   772,
     582,    69,  1280,   353,   621,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,   353,   583,  1280,
     327,   610,   610,   353,   608,  1280,   353,   583,   608,   581,
     582,   582,   582,   582,   643,   643,   582,   582,   582,   582,
     582,   582,   582,   582,   582,   582,   582,   582,   582,   582,
     582,   582,   582,   582,   643,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   366,   793,   644,    71,   353,
     583,    71,    71,    71,    71,    71,   353,   583,   583,  1280,
    1280,    69,   649,   583,    71,    71,    71,   583,   353,    71,
      69,   893,    71,    71,   360,   361,   582,   674,   675,   708,
     709,   353,   583,    71,    71,    71,    71,    71,   583,   353,
     584,   872,   873,  1280,   353,   583,    71,    71,   353,   583,
      71,    71,    71,   583,   353,    71,    71,   353,   583,   353,
     583,   356,   357,   358,   359,    69,   800,    71,    71,   353,
     583,    71,    71,  1280,   327,   610,   610,  1280,   327,   610,
     610,  1280,   327,   610,   610,   353,   581,  1280,  1280,    71,
      71,    71,    71,    71,    71,    71,   583,   353,   583,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
     583,   353,    71,    71,    71,    71,    71,   353,   583,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,   353,   583,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,   353,   583,   353,   583,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,   353,   583,    71,    71,
      71,   353,   583,    71,    71,    71,    71,   353,   583,   353,
     583,    71,   353,   583,   432,   513,   515,   516,   653,   654,
      71,    71,    71,    71,    71,    71,   353,   583,    71,   353,
     583,    71,    71,    71,    71,   353,   583,    71,    71,   353,
     583,   583,   742,   582,   582,   581,   588,   353,   583,    71,
     582,   582,   581,   588,   582,   582,   581,   588,   582,   582,
     582,   582,   621,   621,   582,   582,   582,   582,   582,   582,
     582,   582,   582,   582,   582,   582,   582,   582,   582,   582,
     621,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   366,   581,   622,   582,   740,   588,   708,   709,   708,
     128,   709,   128,   788,   128,   128,   584,  1270,  1272,  1273,
     128,   128,  1280,  1267,  1280,   817,   128,   128,   708,   128,
     820,   128,  1273,   708,   581,   705,   875,   618,  1280,   128,
     128,   128,   708,   708,   128,   708,   128,   681,   581,   708,
     582,    67,   273,   274,   275,   276,   277,   278,   128,   128,
     865,   581,   581,   581,  1280,   350,   351,   352,   730,   730,
     581,   705,   855,   581,   705,   581,   705,   581,   621,   581,
     128,   280,   708,  1280,   708,   708,   708,   128,   788,  1270,
    1273,   457,   458,   459,   461,   582,   980,  1270,  1273,   128,
     582,   708,   128,   708,   128,   128,    58,    89,    90,   305,
     708,   708,   708,   708,   708,   708,   128,   128,   128,   128,
     120,   360,   361,   709,   710,   711,   128,   128,   128,  1280,
     788,   128,  1273,   584,  1274,  1275,  1275,   463,   464,   465,
     788,   128,   206,   207,   461,   708,   210,   211,   212,   214,
     215,   128,  1280,   220,   221,   222,   220,   221,   222,   582,
     128,   128,   708,   120,   708,   128,    89,    90,   708,   128,
      50,    51,    89,   582,   128,   760,   581,   705,   353,   581,
      10,   103,   129,   130,   131,   242,   328,   473,   621,   624,
     716,   728,   353,   353,   581,   621,   353,   353,   581,   621,
     581,   128,   128,   581,   878,   128,   581,   581,   621,   862,
     581,   705,   588,   581,   128,   360,   361,   707,   581,   788,
     581,   621,   709,   128,   128,   707,   128,   128,   128,   788,
     128,   581,   785,   581,   581,   788,   581,  1280,   128,  1268,
     581,   581,   598,   224,   641,   642,  1280,    69,   640,   646,
      71,   581,   708,   582,   128,   582,   634,   581,   146,   193,
     790,   583,   582,   708,   684,   581,   581,   581,   581,   581,
    1280,   581,   621,   581,   353,   621,  1280,   581,   708,   128,
     128,   128,   788,   708,   128,   708,   128,   708,   128,   128,
     128,   778,   581,   705,   327,   610,   610,   608,    71,   583,
     608,   643,   643,   643,   643,   643,   643,   643,   643,   643,
     643,   643,   643,   643,   643,   643,   643,   643,   643,   643,
     643,   643,   707,   583,   643,   643,   643,   643,   643,   643,
     643,   643,   643,   643,   643,   581,   582,   128,   687,   581,
     708,   708,   128,   708,   128,   690,   581,   581,   353,    71,
     353,   581,   581,   581,   128,  1280,  1280,   581,   705,   849,
     894,  1280,   581,   894,  1280,   708,   708,   621,   581,   585,
     353,   582,   709,   697,   581,   788,   582,   788,   582,   128,
     581,   889,   705,    69,   873,    71,   678,   581,   708,  1273,
     704,   581,   705,   128,   128,  1273,   581,   705,   851,   582,
     621,   805,   581,   705,   807,   581,   796,   797,  1280,   621,
     621,   621,   621,   581,   128,   708,   803,   581,   705,   602,
     601,   327,   610,   610,   327,   610,   610,   327,   610,   610,
    1280,   788,   350,   351,   352,   128,   128,   582,   980,   730,
     730,   581,   705,   853,   581,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   708,   128,
     584,  1278,  1279,   708,   708,   582,   582,   582,   128,   128,
     582,   708,   128,   708,   708,   708,   708,   708,   581,   847,
     788,  1280,   730,   730,   128,   734,   581,   128,   517,   518,
     128,   128,   128,   128,   788,   128,   582,   128,   224,   515,
     516,   128,   128,   128,   128,   128,   708,   708,   128,   128,
     128,   128,   128,   128,   708,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,  1275,   823,   581,   595,   128,   788,   128,
     788,   788,  1275,   128,   128,  1275,   709,   128,   832,   581,
     705,   826,   581,   443,   461,   708,   708,   708,   128,   708,
     128,   128,   708,   708,   128,   128,   128,   128,   708,   708,
     844,   581,   128,   128,   128,   841,   581,   128,   709,   709,
     128,   838,   581,   835,   581,   128,   829,   581,   512,   514,
     529,   581,   581,    69,   654,   584,   584,  1275,  1277,   128,
     708,  1279,   128,   128,   665,   581,  1270,  1273,   668,   581,
     788,   128,   788,   788,   700,   581,   788,   128,   694,   581,
     581,   582,  1280,  1280,   982,   581,   730,  1280,  1280,   462,
    1280,  1280,  1280,   141,  1280,   621,   621,   621,   621,   621,
     621,   621,   621,   621,   621,   621,   621,   621,   621,   621,
     621,   621,   621,   621,   621,   583,   621,   621,   621,   621,
     621,   621,   621,   621,   621,   621,   621,   582,   123,   124,
     125,   754,   755,   958,   959,   960,   582,   141,   462,   128,
     353,  1270,  1271,   353,   585,  1271,   587,   581,   581,   581,
     353,   581,  1280,   705,   259,   583,   581,   581,   581,   581,
     628,   980,   981,   705,   120,   120,   353,   709,   353,   585,
     709,   280,   761,   762,   280,   765,   766,   581,  1280,   353,
     581,   353,  1280,   621,   353,  1280,   621,   581,    69,   719,
     353,   581,   140,   141,   462,  1280,   128,   128,   583,   631,
     583,   353,   581,   628,   583,   353,   583,   587,   583,   886,
     643,    71,   353,   585,    71,   581,   643,   705,   788,   789,
     638,   581,   708,   583,   259,   670,   353,   582,   583,  1280,
     581,   621,   581,   610,   280,   353,   353,   583,   583,   583,
     583,   583,   583,   353,   583,   353,   583,   583,   583,   583,
     583,   583,   583,   583,   353,   583,   353,   583,   583,   583,
     643,   645,   583,  1280,   621,  1280,   311,   648,   581,   353,
     581,  1280,   581,   583,   583,   675,   581,   582,   709,   621,
     705,   705,   585,   581,   621,   581,   581,   705,   581,   581,
     797,   581,   581,   581,   581,   581,   643,   643,   610,   610,
     610,   981,   581,   711,   585,   711,   587,   705,   706,   706,
     706,   706,   705,   643,   581,   128,   128,   581,   581,   705,
    1275,  1276,    95,    96,    97,    98,    99,   100,   101,   102,
     287,   749,   750,   951,   952,   953,   955,   956,   957,   961,
     962,   964,  1240,   353,   583,   587,   353,   583,   588,   353,
     583,   588,   353,   353,   583,   583,   583,   583,   583,   583,
     353,   583,   353,   583,   583,   583,   583,   583,   583,   583,
     583,   353,   583,   353,   583,   621,   623,    71,    71,    71,
     353,   583,    96,    98,   747,   748,   951,   952,   953,   954,
     956,   957,   961,   962,   963,  1240,   582,   741,   587,  1271,
     585,  1271,  1280,  1280,   583,   128,   671,   588,    69,   353,
     583,   583,   709,   585,   709,   353,   353,   583,   353,   353,
     583,   621,   624,   728,   624,   717,   353,   353,   621,   353,
     581,   581,    69,   621,   582,   743,   588,    71,    69,   581,
     621,    69,   581,   360,   361,   584,   881,   353,   128,   353,
      69,   583,   280,   642,   643,   643,   581,   583,   353,   583,
     639,   583,   671,    69,   881,   361,   707,  1269,   581,   621,
     581,   643,   643,   643,   643,   643,   643,   582,   353,   583,
     705,    71,   581,    71,   621,    69,  1280,   581,   621,   583,
     583,   583,    71,   581,   583,   583,   583,   583,   583,   583,
     583,   583,   583,   583,   353,   581,   585,   353,   585,    71,
      71,    71,    71,    71,    71,    71,    71,    71,   353,   583,
    1280,   588,   730,  1280,   588,   462,  1280,   588,   141,   621,
     621,   621,   621,   621,   621,   353,   583,  1279,   708,   709,
     755,   581,    71,    71,   353,   583,   754,   582,   128,   587,
     128,   353,   581,   140,   141,   462,  1280,   581,   980,   280,
     709,   761,   280,   582,   709,   765,   353,   353,   353,   621,
     621,   581,   621,   581,   581,   754,   582,   141,   462,   621,
     581,   581,   581,   711,   581,  1280,  1280,   581,   599,  1280,
      71,   581,   581,   788,    69,   581,   581,   581,   582,   583,
     587,   583,   581,   583,   583,   583,   353,   583,   353,   353,
     643,   643,   581,   621,   621,   581,   581,   892,   583,   621,
     603,  1280,   603,   596,  1280,   655,   512,   657,  1275,   709,
    1275,   708,  1277,   709,  1275,   445,   451,   452,   453,   454,
     455,   456,   466,   472,   727,  1275,  1275,   750,   581,   583,
     583,   462,  1280,   583,   141,  1280,   583,   583,   583,   353,
     583,   353,   353,   621,   709,   621,   748,   581,   583,   747,
     128,   587,   128,   334,   582,   745,   588,   280,   763,   764,
     624,   717,   624,   353,   581,   581,   583,   747,   582,   744,
     581,   353,   711,   353,   353,   353,   581,  1280,   327,   643,
     581,   334,   707,   353,   707,   353,   643,   643,   643,   583,
     581,   581,    69,   581,   353,   581,  1280,   327,   610,   581,
     353,   581,  1280,   327,   360,   361,   526,   621,   659,   660,
     661,   128,   512,   588,   588,   588,   588,   588,   621,   621,
     621,   581,   583,   128,   587,   582,   673,   709,   754,   582,
     141,   462,   353,   353,   583,   353,   353,   621,   581,   583,
     754,   582,   711,   585,   881,   881,  1280,   327,   581,   673,
     587,   881,   881,   583,   583,   583,   581,  1280,   327,   610,
     610,  1280,   327,   526,   526,   582,   362,    71,   621,   661,
     353,   128,   462,  1280,   462,   141,  1280,   141,   583,   583,
     583,   581,   128,   621,   353,   581,   582,   709,   583,   747,
     582,   746,   280,   709,   763,   728,   624,   581,   581,   583,
     747,   585,   581,   581,   327,   581,   707,   581,   581,   327,
     610,   610,   327,   582,   582,  1280,   526,   656,   658,  1280,
     353,   588,   588,   583,   582,   709,   621,   581,   583,   754,
     582,   353,   353,   581,   583,   583,   610,  1280,  1280,   353,
     582,   659,   353,   581,   658,   462,   141,   621,   583,   581,
     583,   747,   717,   624,   581,   353,   353,   128,  1280,   581,
    1280,   581,   583,   581,   583,   353,   128,   128,   583,   353,
     581,   621,   583,   583,   128,   583
  };

  const short
  parser::yyr1_[] =
  {
       0,   589,   590,   590,   591,   591,   591,   591,   591,   591,
     591,   591,   591,   591,   591,   591,   591,   591,   591,   591,
     591,   591,   591,   591,   591,   591,   591,   591,   591,   591,
     591,   591,   591,   591,   591,   591,   591,   591,   591,   591,
     591,   591,   591,   591,   591,   591,   591,   591,   591,   591,
     591,   591,   591,   591,   591,   591,   591,   591,   591,   591,
     591,   591,   591,   591,   591,   591,   591,   591,   591,   591,
     591,   591,   591,   591,   591,   591,   591,   591,   591,   591,
     591,   591,   591,   591,   591,   591,   591,   591,   591,   591,
     591,   591,   591,   591,   591,   591,   591,   591,   591,   591,
     592,   592,   593,   595,   594,   596,   596,   596,   596,   596,
     596,   598,   597,   599,   599,   599,   599,   599,   599,   600,
     601,   600,   602,   600,   603,   603,   603,   603,   603,   603,
     603,   603,   603,   603,   603,   603,   604,   605,   606,   607,
     608,   609,   609,   609,   609,   610,   610,   611,   611,   611,
     611,   611,   611,   611,   611,   611,   611,   611,   611,   612,
     612,   612,   612,   612,   612,   612,   612,   612,   612,   612,
     612,   613,   613,   613,   613,   613,   613,   613,   613,   613,
     613,   613,   613,   614,   614,   614,   614,   614,   614,   614,
     614,   614,   614,   614,   614,   615,   615,   615,   616,   617,
     617,   617,   617,   618,   618,   618,   619,   619,   620,   621,
     621,   621,   621,   621,   621,   621,   621,   621,   621,   621,
     621,   621,   621,   621,   621,   621,   621,   621,   621,   621,
     621,   621,   621,   621,   621,   621,   621,   621,   621,   621,
     621,   621,   621,   621,   622,   621,   621,   621,   621,   621,
     621,   621,   621,   623,   623,   624,   624,   625,   625,   626,
     627,   627,   628,   628,   629,   630,   630,   631,   631,   632,
     633,   634,   634,   634,   634,   634,   634,   634,   634,   634,
     634,   635,   635,   637,   636,   638,   636,   639,   639,   639,
     639,   640,   640,   640,   640,   641,   641,   642,   642,   643,
     643,   643,   643,   643,   643,   643,   643,   643,   643,   643,
     643,   643,   643,   643,   643,   643,   643,   643,   643,   643,
     643,   643,   643,   643,   643,   643,   643,   643,   643,   643,
     643,   643,   643,   643,   643,   644,   643,   643,   643,   643,
     643,   643,   643,   645,   645,   646,   647,   647,   648,   648,
     649,   649,   649,   649,   649,   650,   652,   651,   653,   653,
     654,   654,   655,   656,   654,   654,   654,   657,   657,   658,
     658,   659,   659,   660,   660,   661,   661,   661,   661,   662,
     663,   664,   664,   665,   665,   665,   665,   665,   665,   666,
     667,   667,   668,   668,   668,   668,   669,   669,   670,   670,
     671,   671,   671,   671,   671,   671,   672,   673,   673,   673,
     673,   673,   673,   674,   674,   675,   675,   675,   675,   675,
     675,   676,   676,   677,   677,   678,   678,   678,   678,   678,
     678,   678,   678,   679,   679,   680,   680,   681,   681,   682,
     682,   683,   683,   684,   685,   685,   686,   686,   687,   687,
     688,   688,   689,   689,   690,   690,   690,   690,   690,   690,
     690,   690,   690,   690,   690,   690,   691,   692,   693,   693,
     694,   694,   695,   695,   696,   696,   697,   697,   698,   699,
     699,   700,   700,   700,   700,   701,   701,   701,   701,   702,
     702,   703,   703,   703,   703,   703,   703,   703,   703,   703,
     703,   703,   703,   703,   703,   703,   703,   703,   703,   703,
     703,   703,   703,   703,   703,   703,   703,   703,   703,   703,
     703,   703,   703,   703,   703,   703,   703,   703,   703,   703,
     703,   703,   703,   704,   704,   704,   704,   704,   704,   705,
     705,   705,   706,   706,   707,   707,   707,   708,   708,   709,
     709,   709,   710,   710,   710,   711,   711,   712,   713,   713,
     714,   714,   715,   715,   715,   715,   716,   716,   716,   716,
     716,   717,   717,   717,   717,   718,   718,   718,   719,   719,
     720,   720,   720,   721,   722,   722,   723,   723,   723,   724,
     725,   725,   726,   727,   727,   727,   727,   727,   727,   727,
     727,   727,   728,   728,   728,   728,   728,   728,   728,   728,
     729,   730,   730,   731,   732,   733,   733,   734,   734,   734,
     734,   734,   734,   734,   735,   736,   737,   737,   737,   738,
     738,   740,   739,   741,   739,   742,   739,   743,   739,   744,
     739,   745,   739,   746,   739,   747,   747,   748,   748,   748,
     748,   748,   748,   748,   748,   748,   748,   749,   749,   750,
     750,   750,   750,   750,   750,   750,   750,   750,   750,   751,
     752,   752,   752,   752,   752,   752,   753,   753,   753,   753,
     753,   753,   754,   754,   755,   755,   755,   756,   757,   757,
     757,   757,   757,   757,   758,   758,   758,   758,   759,   759,
     760,   760,   760,   760,   760,   760,   760,   760,   760,   760,
     760,   760,   760,   760,   760,   760,   760,   760,   760,   760,
     760,   760,   760,   760,   760,   760,   760,   760,   760,   760,
     760,   760,   760,   760,   760,   760,   760,   760,   760,   760,
     760,   760,   760,   760,   760,   760,   760,   760,   760,   760,
     760,   760,   760,   760,   760,   760,   760,   760,   760,   760,
     760,   760,   760,   760,   760,   760,   760,   760,   760,   760,
     760,   760,   760,   760,   760,   760,   760,   760,   760,   760,
     760,   760,   760,   760,   760,   760,   760,   760,   760,   760,
     760,   760,   760,   760,   760,   760,   760,   760,   760,   760,
     760,   760,   760,   760,   760,   760,   760,   760,   760,   760,
     761,   761,   762,   762,   763,   763,   764,   764,   765,   765,
     765,   766,   766,   768,   767,   769,   769,   769,   770,   771,
     771,   772,   773,   774,   775,   775,   775,   775,   776,   777,
     777,   778,   778,   778,   778,   778,   778,   778,   779,   779,
     779,   779,   780,   780,   781,   781,   782,   783,   784,   784,
     785,   785,   786,   786,   786,   786,   786,   786,   786,   786,
     786,   786,   786,   786,   786,   786,   786,   786,   786,   786,
     786,   786,   787,   787,   788,   788,   789,   789,   790,   790,
     790,   790,   790,   790,   792,   793,   791,   794,   794,   794,
     794,   795,   795,   795,   795,   796,   796,   797,   798,   799,
     799,   800,   800,   800,   800,   801,   801,   801,   801,   802,
     802,   803,   803,   803,   804,   804,   805,   805,   806,   806,
     807,   807,   807,   808,   808,   809,   810,   811,   811,   811,
     811,   812,   812,   812,   812,   813,   813,   813,   813,   814,
     814,   814,   814,   815,   815,   815,   815,   815,   815,   815,
     816,   816,   816,   816,   816,   816,   816,   816,   816,   816,
     817,   817,   818,   818,   819,   819,   819,   819,   820,   820,
     821,   821,   822,   822,   822,   822,   822,   822,   822,   822,
     822,   822,   822,   822,   822,   822,   822,   822,   822,   822,
     822,   822,   822,   822,   822,   822,   822,   822,   822,   822,
     822,   822,   822,   822,   822,   822,   822,   822,   822,   822,
     822,   822,   822,   822,   822,   822,   822,   822,   822,   822,
     823,   823,   824,   824,   825,   825,   825,   825,   825,   825,
     825,   825,   825,   825,   825,   825,   825,   825,   826,   826,
     827,   827,   828,   828,   828,   828,   828,   828,   828,   828,
     828,   828,   828,   828,   828,   828,   829,   829,   830,   830,
     831,   831,   831,   831,   831,   831,   831,   831,   831,   831,
     831,   831,   831,   831,   832,   832,   833,   833,   833,   833,
     834,   834,   834,   834,   835,   835,   836,   836,   837,   837,
     837,   837,   837,   837,   837,   837,   838,   838,   839,   839,
     840,   840,   840,   840,   840,   840,   840,   841,   841,   842,
     842,   843,   843,   843,   843,   843,   843,   843,   843,   843,
     843,   843,   843,   843,   843,   843,   843,   843,   843,   843,
     843,   843,   843,   843,   843,   843,   843,   843,   843,   843,
     843,   843,   843,   843,   843,   843,   844,   844,   845,   845,
     846,   846,   847,   847,   848,   848,   848,   848,   848,   848,
     848,   848,   848,   848,   848,   848,   848,   848,   848,   848,
     848,   848,   848,   848,   848,   848,   848,   848,   848,   848,
     848,   848,   848,   848,   848,   848,   848,   848,   848,   848,
     848,   848,   848,   848,   848,   848,   848,   848,   848,   848,
     848,   848,   848,   848,   848,   849,   849,   850,   850,   850,
     850,   850,   850,   850,   850,   851,   851,   852,   852,   852,
     852,   852,   852,   852,   852,   852,   852,   853,   853,   854,
     854,   854,   854,   854,   854,   854,   854,   854,   854,   854,
     854,   854,   854,   854,   855,   855,   856,   856,   856,   856,
     856,   856,   857,   858,   858,   859,   859,   860,   860,   860,
     860,   861,   861,   862,   862,   862,   862,   862,   863,   864,
     864,   865,   865,   865,   865,   865,   866,   866,   867,   868,
     868,   869,   871,   870,   872,   872,   873,   873,   874,   874,
     874,   874,   875,   875,   876,   876,   876,   876,   876,   876,
     876,   876,   876,   876,   877,   877,   878,   878,   879,   879,
     879,   879,   879,   880,   881,   881,   881,   881,   882,   883,
     883,   884,   884,   884,   885,   885,   886,   886,   887,   887,
     887,   888,   888,   889,   889,   890,   890,   890,   890,   890,
     891,   891,   892,   892,   893,   893,   894,   894,   894,   895,
     896,   897,   898,   899,   900,   901,   902,   903,   904,   905,
     906,   907,   908,   909,   910,   911,   912,   913,   914,   915,
     916,   917,   918,   919,   920,   920,   921,   922,   923,   924,
     925,   926,   927,   927,   928,   929,   930,   931,   932,   933,
     934,   935,   936,   937,   938,   939,   940,   941,   942,   942,
     943,   943,   944,   944,   945,   946,   947,   948,   949,   950,
     951,   952,   953,   954,   955,   956,   957,   958,   959,   960,
     961,   962,   963,   964,   965,   966,   967,   968,   969,   969,
     970,   970,   971,   972,   973,   974,   975,   976,   977,   978,
     978,   979,   979,   980,   980,   980,   980,   981,   981,   982,
     983,   984,   985,   986,   987,   988,   989,   990,   991,   992,
     993,   994,   995,   996,   997,   997,   998,   999,  1000,  1001,
    1002,  1003,  1004,  1005,  1006,  1007,  1008,  1009,  1010,  1011,
    1012,  1012,  1012,  1013,  1014,  1015,  1016,  1017,  1018,  1019,
    1020,  1021,  1022,  1023,  1024,  1025,  1025,  1026,  1027,  1028,
    1029,  1030,  1031,  1032,  1033,  1034,  1035,  1036,  1037,  1038,
    1039,  1040,  1041,  1042,  1043,  1044,  1044,  1045,  1046,  1046,
    1046,  1046,  1047,  1048,  1049,  1049,  1049,  1050,  1051,  1052,
    1053,  1054,  1055,  1056,  1057,  1058,  1059,  1060,  1060,  1060,
    1061,  1061,  1061,  1062,  1063,  1064,  1065,  1066,  1067,  1068,
    1069,  1070,  1071,  1072,  1073,  1074,  1075,  1076,  1077,  1078,
    1079,  1079,  1079,  1080,  1081,  1081,  1081,  1082,  1082,  1083,
    1084,  1085,  1085,  1085,  1086,  1086,  1086,  1087,  1088,  1089,
    1090,  1091,  1092,  1093,  1094,  1095,  1096,  1097,  1098,  1099,
    1100,  1101,  1102,  1103,  1104,  1105,  1106,  1107,  1108,  1109,
    1110,  1111,  1112,  1113,  1114,  1115,  1116,  1116,  1117,  1118,
    1119,  1120,  1121,  1122,  1123,  1124,  1125,  1126,  1127,  1128,
    1129,  1130,  1130,  1130,  1130,  1130,  1130,  1130,  1131,  1132,
    1133,  1134,  1135,  1135,  1135,  1136,  1137,  1138,  1139,  1140,
    1141,  1142,  1143,  1144,  1144,  1144,  1145,  1146,  1147,  1148,
    1149,  1150,  1151,  1152,  1153,  1154,  1155,  1156,  1156,  1157,
    1158,  1159,  1160,  1161,  1162,  1163,  1164,  1165,  1166,  1167,
    1168,  1169,  1170,  1171,  1172,  1173,  1174,  1175,  1176,  1177,
    1178,  1179,  1180,  1181,  1182,  1183,  1184,  1185,  1185,  1186,
    1187,  1188,  1189,  1190,  1191,  1191,  1192,  1193,  1194,  1195,
    1196,  1196,  1197,  1197,  1198,  1199,  1200,  1201,  1202,  1203,
    1204,  1205,  1206,  1207,  1208,  1209,  1210,  1211,  1212,  1213,
    1214,  1215,  1216,  1217,  1218,  1219,  1220,  1221,  1222,  1223,
    1224,  1225,  1226,  1227,  1228,  1229,  1230,  1231,  1232,  1233,
    1234,  1235,  1236,  1237,  1238,  1239,  1240,  1240,  1241,  1242,
    1243,  1244,  1245,  1246,  1247,  1248,  1249,  1249,  1249,  1249,
    1250,  1251,  1252,  1253,  1254,  1255,  1256,  1257,  1258,  1259,
    1260,  1261,  1262,  1263,  1264,  1265,  1265,  1266,  1267,  1268,
    1269,  1269,  1270,  1271,  1271,  1272,  1272,  1272,  1272,  1273,
    1273,  1274,  1274,  1274,  1274,  1275,  1275,  1276,  1276,  1277,
    1277,  1278,  1278,  1279,  1280,  1280,  1280,  1280,  1280,  1280,
    1280,  1280,  1280,  1280,  1280,  1280,  1280,  1280,  1280,  1280,
    1280,  1280,  1280,  1280
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     4,     3,     0,     9,     2,     3,     1,     3,     4,
       2,     0,     9,     2,     3,     1,     3,     4,     2,     3,
       0,     9,     0,     9,     2,     3,     1,     3,     4,     2,
       3,     4,     2,     4,     5,     3,     3,     3,     3,     3,
       3,     2,     3,     2,     3,     2,     3,     2,     3,     1,
       3,     4,     2,     3,     4,     2,     4,     5,     3,     2,
       3,     1,     3,     4,     2,     3,     4,     2,     4,     5,
       3,     2,     3,     1,     3,     4,     2,     3,     4,     2,
       4,     5,     3,     2,     3,     1,     3,     4,     2,     3,
       4,     2,     4,     5,     3,     2,     3,     1,     6,     1,
       1,     1,     1,     1,     2,     3,     3,     4,     4,     3,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     6,     6,
       4,     6,     6,     8,     0,     5,     8,     4,     8,     4,
       4,     1,     1,     1,     3,     0,     1,     5,     8,     7,
       5,     8,     2,     1,     4,     5,     8,     2,     1,     7,
       7,     1,     1,     1,     1,     1,     1,     1,     5,     1,
       5,     3,     1,     0,     6,     0,     9,     2,     2,     1,
       1,     4,     2,     7,     5,     3,     1,     3,     1,     3,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     7,     2,     2,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     6,
       6,     4,     6,     6,     8,     0,     5,     8,     4,     8,
       4,     4,     4,     1,     3,     5,     5,     8,     2,     1,
       1,     6,     5,     7,     7,     9,     0,     6,     2,     1,
       5,     3,     0,     0,    10,     2,     2,     6,     5,     3,
       1,     1,     1,     1,     2,     6,     7,     7,     8,     2,
       5,     3,     1,     1,     1,     1,     1,     1,     1,     5,
       3,     1,     1,     1,     1,     1,     5,     8,     2,     1,
       3,     2,     5,     4,     3,     1,     6,     5,     4,     3,
       3,     2,     1,     3,     1,     5,     3,     4,     2,     3,
       1,     2,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     5,     3,     1,     1,     1,     2,
       5,     3,     1,     0,     2,     5,     3,     1,     1,     1,
       2,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     5,     3,     1,
       1,     1,     2,     5,     3,     1,     1,     1,     5,     3,
       1,     1,     1,     1,     1,     2,     5,     3,     6,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       3,     1,     1,     1,     2,     2,     1,     1,     1,     2,
       2,     1,     2,     2,     1,     1,     1,     5,     2,     1,
       4,     2,     2,     1,     4,     1,     3,     5,     9,     1,
       5,     3,     5,     7,     9,     5,     7,     8,     2,     1,
       5,     7,     4,     5,     2,     1,     7,     9,     6,     5,
       2,     1,     6,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     5,     5,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     4,     3,     6,     8,     3,
       1,     0,     8,     0,    10,     0,     8,     0,    11,     0,
      13,     0,    13,     0,    15,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       3,     5,     6,     8,     8,    10,     7,     9,    10,    12,
      12,    14,     3,     1,     1,     1,     1,     4,     3,     5,
       6,     8,     8,    10,     2,     5,     3,     6,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     1,     3,     3,     3,     1,     3,     3,     3,
       5,     1,     3,     0,     4,     2,     3,     1,     5,     2,
       1,     5,     3,     5,     4,     6,     3,     5,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     5,
       3,     6,     5,     6,     5,     6,     5,     5,     2,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     6,     1,     1,     1,     3,     1,     4,
       2,     5,     3,     6,     0,     0,     5,     2,     5,     3,
       6,     2,     5,     3,     6,     2,     1,     1,     5,     2,
       1,     4,     4,     4,     4,     2,     5,     3,     6,     3,
       1,     1,     1,     1,     3,     1,     1,     1,     3,     1,
       1,     1,     1,     2,     5,     2,     2,     2,     5,     3,
       6,     2,     5,     3,     6,     2,     5,     3,     6,     2,
       5,     3,     6,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     3,     6,     1,     1,     1,     1,     3,     1,
       3,     6,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     2,     5,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       2,     5,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     2,     5,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     2,     5,     3,     6,
       1,     1,     1,     1,     3,     1,     2,     5,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     2,     5,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     2,
       5,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     2,     5,
       2,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     5,     1,     2,     6,     4,     2,     5,     3,
       6,     1,     3,     1,     1,     1,     1,     1,     5,     1,
       3,     1,     1,     1,     1,     1,     3,     8,     5,     1,
       2,     9,     0,     6,     2,     1,     4,     6,     2,     5,
       3,     6,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     5,     3,     1,     1,     1,
       1,     1,     1,     2,     4,     5,     1,     1,     5,     1,
       2,     6,     9,     9,     5,     8,     1,     2,     6,     9,
       9,     2,     5,     3,     1,     1,     1,     1,     1,     1,
       5,    10,     2,     1,     4,     4,     3,     2,     1,     3,
       3,     3,     3,     1,     1,     1,     3,     3,     3,     3,
       1,     1,     1,     3,     5,     3,     3,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     1,     1,     3,
       5,     3,     5,     1,     1,     1,     1,     1,     3,     5,
       3,     3,     3,     3,     3,     3,     3,     3,     5,     5,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     3,
       3,     3,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     1,     1,     3,
       3,     3,     3,     3,     1,     3,     1,     1,     1,     1,
       3,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     5,     5,     5,     3,
       3,     5,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       5,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     5,     3,     3,     3,     3,     3,     1,     1,     3,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     3,     3,     3,     3,     3,
       3,     5,     1,     1,     3,     3,     1,     5,     3,     3,
       3,     1,     3,     1,     1,     1,     1,     1,     3,     3,
       3,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     3,     1,     3,     3,     3,     1,     3,     1,
       1,     1,     3,     3,     3,     3,     1,     3,     1,     3,
       3,     3,     1,     3,     1,     3,     3,     3,     3,     3,
       1,     1,     3,     3,     1,     1,     1,     3,     5,     3,
       3,     5,     1,     3,     3,     1,     3,     3,     3,     3,
       3,     6,     1,     1,     3,     2,     3,     2,     3,     2,
       3,     2,     3,     2,     3,     2,     3,     3,     1,     3,
       1,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "AIM_SOLVER",
  "ANALYTIC_DERIVATION", "ANALYTIC_DERIVATION_MODE", "AR", "AUTOCORR",
  "POSTERIOR_SAMPLING_METHOD", "BAYESIAN_IRF", "BETA_PDF", "BLOCK",
  "USE_CALIBRATION", "SILENT_OPTIMIZER", "BVAR_DENSITY", "BVAR_FORECAST",
  "NODECOMPOSITION", "DR_DISPLAY_TOL", "HUGE_NUMBER", "FIG_NAME",
  "WRITE_XLS", "BVAR_PRIOR_DECAY", "BVAR_PRIOR_FLAT", "BVAR_PRIOR_LAMBDA",
  "INTERACTIVE", "SCREEN_SHOCKS", "STEADYSTATE", "BVAR_PRIOR_MU",
  "BVAR_PRIOR_OMEGA", "BVAR_PRIOR_TAU", "BVAR_PRIOR_TRAIN", "DETAIL_PLOT",
  "TYPE", "BVAR_REPLIC", "BYTECODE", "ALL_VALUES_REQUIRED",
  "PROPOSAL_DISTRIBUTION", "REALTIME", "VINTAGE", "CALIB_SMOOTHER",
  "CHANGE_TYPE", "CHECK", "CONDITIONAL_FORECAST",
  "CONDITIONAL_FORECAST_PATHS", "CONF_SIG", "CONSTANT",
  "CONTROLLED_VAREXO", "CORR", "COVAR", "CUTOFF", "CYCLE_REDUCTION",
  "LOGARITHMIC_REDUCTION", "CONSIDER_ALL_ENDOGENOUS",
  "CONSIDER_ONLY_OBSERVED", "INITIAL_CONDITION_DECOMPOSITION", "DATAFILE",
  "FILE", "SERIES", "DOUBLING", "DR_CYCLE_REDUCTION_TOL",
  "DR_LOGARITHMIC_REDUCTION_TOL", "DR_LOGARITHMIC_REDUCTION_MAXITER",
  "DR_ALGO", "DROP", "DSAMPLE", "DYNASAVE", "DYNATYPE", "CALIBRATION",
  "DIFFERENTIATE_FORWARD_VARS", "END", "ENDVAL", "EQUAL", "ESTIMATION",
  "ESTIMATED_PARAMS", "ESTIMATED_PARAMS_BOUNDS", "ESTIMATED_PARAMS_INIT",
  "EXTENDED_PATH", "ENDOGENOUS_PRIOR", "FILENAME", "DIRNAME",
  "FILTER_STEP_AHEAD", "FILTERED_VARS", "FIRST_OBS", "LAST_OBS",
  "SET_TIME", "OSR_PARAMS_BOUNDS",
  "KEEP_KALMAN_ALGO_IF_SINGULARITY_IS_DETECTED", "FLOAT_NUMBER", "DATES",
  "DEFAULT", "FIXED_POINT", "OPT_ALGO", "FORECAST", "K_ORDER_SOLVER",
  "INSTRUMENTS", "SHIFT", "MEAN", "STDEV", "VARIANCE", "MODE", "INTERVAL",
  "SHAPE", "DOMAINN", "GAMMA_PDF", "GRAPH", "GRAPH_FORMAT",
  "CONDITIONAL_VARIANCE_DECOMPOSITION", "NOCHECK", "STD", "HISTVAL",
  "HISTVAL_FILE", "HOMOTOPY_SETUP", "HOMOTOPY_MODE", "HOMOTOPY_STEPS",
  "HOMOTOPY_FORCE_CONTINUE", "HP_FILTER", "HP_NGRID", "HYBRID",
  "ONE_SIDED_HP_FILTER", "IDENTIFICATION", "INF_CONSTANT", "INITVAL",
  "INITVAL_FILE", "BOUNDS", "JSCALE", "INIT", "INFILE", "INVARS",
  "INT_NUMBER", "INV_GAMMA_PDF", "INV_GAMMA1_PDF", "INV_GAMMA2_PDF", "IRF",
  "IRF_SHOCKS", "IRF_PLOT_THRESHOLD", "IRF_CALIBRATION",
  "FAST_KALMAN_FILTER", "KALMAN_ALGO", "KALMAN_TOL", "DIFFUSE_KALMAN_TOL",
  "SUBSAMPLES", "OPTIONS", "TOLF", "TOLX", "PLOT_INIT_DATE",
  "PLOT_END_DATE", "LAPLACE", "LIK_ALGO", "LIK_INIT", "LINEAR",
  "LOAD_IDENT_FILES", "LOAD_MH_FILE", "LOAD_RESULTS_AFTER_LOAD_MH",
  "LOAD_PARAMS_AND_STEADY_STATE", "LOGLINEAR", "LOGDATA", "LYAPUNOV",
  "LINEAR_APPROXIMATION", "LYAPUNOV_FIXED_POINT_TOL",
  "LYAPUNOV_DOUBLING_TOL", "LYAPUNOV_SQUARE_ROOT_SOLVER_TOL",
  "LOG_DEFLATOR", "LOG_TREND_VAR", "LOG_GROWTH_FACTOR", "MARKOWITZ",
  "MARGINAL_DENSITY", "MAX", "MAXIT", "MFS", "MH_CONF_SIG", "MH_DROP",
  "MH_INIT_SCALE", "MH_JSCALE", "MH_MODE", "MH_NBLOCKS", "MH_REPLIC",
  "MH_RECOVER", "POSTERIOR_MAX_SUBSAMPLE_DRAWS", "MIN",
  "MINIMAL_SOLVING_PERIODS", "MODE_CHECK", "MODE_CHECK_NEIGHBOURHOOD_SIZE",
  "MODE_CHECK_SYMMETRIC_PLOTS", "MODE_CHECK_NUMBER_OF_POINTS",
  "MODE_COMPUTE", "MODE_FILE", "MODEL", "MODEL_COMPARISON", "MODEL_INFO",
  "MSHOCKS", "ABS", "SIGN", "MODEL_DIAGNOSTICS", "MODIFIEDHARMONICMEAN",
  "MOMENTS_VARENDO", "CONTEMPORANEOUS_CORRELATION", "DIFFUSE_FILTER",
  "SUB_DRAWS", "TAPER_STEPS", "GEWEKE_INTERVAL", "RAFTERY_LEWIS_QRS",
  "RAFTERY_LEWIS_DIAGNOSTICS", "MCMC_JUMPING_COVARIANCE",
  "MOMENT_CALIBRATION", "NUMBER_OF_PARTICLES", "RESAMPLING", "SYSTEMATIC",
  "GENERIC", "RESAMPLING_THRESHOLD", "RESAMPLING_METHOD", "KITAGAWA",
  "STRATIFIED", "SMOOTH", "CPF_WEIGHTS", "AMISANOTRISTANI",
  "MURRAYJONESPARSLOW", "WRITE_EQUATION_TAGS",
  "NONLINEAR_FILTER_INITIALIZATION", "FILTER_ALGORITHM",
  "PROPOSAL_APPROXIMATION", "CUBATURE", "UNSCENTED", "MONTECARLO",
  "DISTRIBUTION_APPROXIMATION", "NAME",
  "USE_PENALIZED_OBJECTIVE_FOR_HESSIAN", "INIT_STATE",
  "RESCALE_PREDICTION_ERROR_COVARIANCE", "NAN_CONSTANT", "NO_STATIC",
  "NOBS", "NOCONSTANT", "NODISPLAY", "NOCORR", "NODIAGNOSTIC",
  "NOFUNCTIONS", "NO_HOMOTOPY", "NOGRAPH", "POSTERIOR_NOGRAPH",
  "POSTERIOR_GRAPH", "NOMOMENTS", "NOPRINT", "NORMAL_PDF", "SAVE_DRAWS",
  "OBSERVATION_TRENDS", "OPTIM", "OPTIM_WEIGHTS", "ORDER", "OSR",
  "OSR_PARAMS", "MAX_DIM_COVA_GROUP", "ADVANCED", "OUTFILE", "OUTVARS",
  "OVERWRITE", "PARALLEL_LOCAL_FILES", "PARAMETERS", "PARAMETER_SET",
  "PARTIAL_INFORMATION", "PERIODS", "PERIOD", "PLANNER_OBJECTIVE",
  "PLOT_CONDITIONAL_FORECAST", "PLOT_PRIORS", "PREFILTER", "PRESAMPLE",
  "PERFECT_FORESIGHT_SETUP", "PERFECT_FORESIGHT_SOLVER",
  "NO_POSTERIOR_KERNEL_DENSITY", "FUNCTION", "PRINT", "PRIOR_MC",
  "PRIOR_TRUNC", "PRIOR_MODE", "PRIOR_MEAN", "POSTERIOR_MODE",
  "POSTERIOR_MEAN", "POSTERIOR_MEDIAN", "MLE_MODE", "PRUNING",
  "QUOTED_STRING", "QZ_CRITERIUM", "QZ_ZERO_THRESHOLD", "FULL", "DSGE_VAR",
  "DSGE_VARLAG", "DSGE_PRIOR_WEIGHT", "TRUNCATE", "RELATIVE_IRF", "REPLIC",
  "SIMUL_REPLIC", "RPLOT", "SAVE_PARAMS_AND_STEADY_STATE",
  "PARAMETER_UNCERTAINTY", "SHOCKS", "SHOCK_DECOMPOSITION", "SHOCK_GROUPS",
  "USE_SHOCK_GROUPS", "SIGMA_E", "SIMUL", "SIMUL_ALGO", "SIMUL_SEED",
  "ENDOGENOUS_TERMINAL_PERIOD", "SMOOTHER", "SMOOTHER2HISTVAL",
  "SQUARE_ROOT_SOLVER", "STACK_SOLVE_ALGO", "STEADY_STATE_MODEL",
  "SOLVE_ALGO", "SOLVER_PERIODS", "ROBUST_LIN_SOLVE", "STDERR", "STEADY",
  "STOCH_SIMUL", "SURPRISE", "SYLVESTER", "SYLVESTER_FIXED_POINT_TOL",
  "REGIMES", "REGIME", "REALTIME_SHOCK_DECOMPOSITION", "TEX",
  "RAMSEY_MODEL", "RAMSEY_POLICY", "RAMSEY_CONSTRAINTS",
  "PLANNER_DISCOUNT", "DISCRETIONARY_POLICY", "DISCRETIONARY_TOL",
  "TEX_NAME", "UNIFORM_PDF", "UNIT_ROOT_VARS", "USE_DLL", "USEAUTOCORR",
  "GSA_SAMPLE_FILE", "USE_UNIVARIATE_FILTERS_IF_SINGULARITY_IS_DETECTED",
  "VALUES", "VAR", "VAREXO", "VAREXO_DET", "VAROBS",
  "PREDETERMINED_VARIABLES", "PLOT_SHOCK_DECOMPOSITION",
  "WRITE_LATEX_DYNAMIC_MODEL", "WRITE_LATEX_STATIC_MODEL",
  "WRITE_LATEX_ORIGINAL_MODEL", "XLS_SHEET", "XLS_RANGE", "LMMCP",
  "OCCBIN", "BANDPASS_FILTER", "COLORMAP", "QOQ", "YOY", "AOA", "COMMA",
  "EQUAL_EQUAL", "EXCLAMATION_EQUAL", "LESS", "GREATER", "LESS_EQUAL",
  "GREATER_EQUAL", "PLUS", "MINUS", "TIMES", "DIVIDE", "UMINUS", "UPLUS",
  "POWER", "EXP", "LOG", "LN", "LOG10", "LINLOG", "LINPOW", "SIN", "COS",
  "TAN", "ASIN", "ACOS", "ATAN", "SINH", "COSH", "TANH", "ERF", "ASINH",
  "ACOSH", "ATANH", "SQRT", "NORMCDF", "NORMPDF", "STEADY_STATE",
  "EXPECTATION", "DYNARE_SENSITIVITY", "MORRIS", "STAB", "REDFORM",
  "PPRIOR", "PRIOR_RANGE", "PPOST", "ILPTAU", "MORRIS_NLIV", "MORRIS_NTRA",
  "NSAM", "LOAD_REDFORM", "LOAD_RMSE", "LOAD_STAB", "ALPHA2_STAB",
  "LOGTRANS_REDFORM", "THRESHOLD_REDFORM", "KSSTAT_REDFORM",
  "ALPHA2_REDFORM", "NAMENDO", "NAMLAGENDO", "NAMEXO", "RMSE", "LIK_ONLY",
  "VAR_RMSE", "PFILT_RMSE", "ISTART_RMSE", "ALPHA_RMSE", "ALPHA2_RMSE",
  "FREQ", "INITIAL_YEAR", "INITIAL_SUBPERIOD", "FINAL_YEAR",
  "FINAL_SUBPERIOD", "DATA", "VLIST", "LOG_VAR", "PERCENT_VAR", "VLISTLOG",
  "VLISTPER", "SPECTRAL_DENSITY", "RESTRICTION", "RESTRICTION_FNAME",
  "CROSS_RESTRICTIONS", "NLAGS", "CONTEMP_REDUCED_FORM",
  "REAL_PSEUDO_FORECAST", "DUMMY_OBS", "NSTATES", "INDXSCALESSTATES",
  "NO_BAYESIAN_PRIOR", "SPECIFICATION", "SIMS_ZHA", "ALPHA", "BETA",
  "ABAND", "NINV", "CMS", "NCMS", "CNUM", "GAMMA", "INV_GAMMA",
  "INV_GAMMA1", "INV_GAMMA2", "NORMAL", "UNIFORM", "EPS", "PDF", "FIG",
  "DR", "NONE", "PRIOR", "PRIOR_VARIANCE", "HESSIAN", "IDENTITY_MATRIX",
  "DIRICHLET", "GSIG2_LMDM", "Q_DIAG", "FLAT_PRIOR", "NCSK", "NSTD",
  "WEIBULL", "WEIBULL_PDF", "INDXPARR", "INDXOVR", "INDXAP", "APBAND",
  "INDXIMF", "IMFBAND", "INDXFORE", "FOREBAND", "INDXGFOREHAT",
  "INDXGIMFHAT", "INDXESTIMA", "INDXGDLS", "EQ_MS", "FILTER_COVARIANCE",
  "FILTER_DECOMPOSITION", "SMOOTHED_STATE_UNCERTAINTY", "EQ_CMS", "TLINDX",
  "TLNUMBER", "BANACT", "RESTRICTIONS", "POSTERIOR_SAMPLER_OPTIONS",
  "OUTPUT_FILE_TAG", "DRAWS_NBR_BURN_IN_1", "DRAWS_NBR_BURN_IN_2",
  "HORIZON", "SBVAR", "TREND_VAR", "DEFLATOR", "GROWTH_FACTOR", "MS_IRF",
  "MS_VARIANCE_DECOMPOSITION", "MS_ESTIMATION", "MS_SIMULATION",
  "MS_COMPUTE_MDD", "MS_COMPUTE_PROBABILITIES", "MS_FORECAST",
  "SVAR_IDENTIFICATION", "EQUATION", "EXCLUSION", "LAG", "UPPER_CHOLESKY",
  "LOWER_CHOLESKY", "MONTHLY", "QUARTERLY", "MARKOV_SWITCHING", "CHAIN",
  "DURATION", "NUMBER_OF_REGIMES", "NUMBER_OF_LAGS", "SVAR",
  "SVAR_GLOBAL_IDENTIFICATION_CHECK", "COEFF", "COEFFICIENTS", "VARIANCES",
  "CONSTANTS", "EQUATIONS", "EXTERNAL_FUNCTION", "EXT_FUNC_NAME",
  "EXT_FUNC_NARGS", "FIRST_DERIV_PROVIDED", "SECOND_DERIV_PROVIDED",
  "SELECTED_VARIABLES_ONLY", "COVA_COMPUTE", "SIMULATION_FILE_TAG",
  "FILE_TAG", "NO_ERROR_BANDS", "ERROR_BAND_PERCENTILES",
  "SHOCKS_PER_PARAMETER", "NO_CREATE_INIT", "SHOCK_DRAWS",
  "FREE_PARAMETERS", "MEDIAN", "DATA_OBS_NBR", "NEIGHBORHOOD_WIDTH",
  "PVALUE_KS", "PVALUE_CORR", "FILTERED_PROBABILITIES",
  "REAL_TIME_SMOOTHED", "PRIOR_FUNCTION", "POSTERIOR_FUNCTION",
  "SAMPLING_DRAWS", "PROPOSAL_TYPE", "PROPOSAL_UPPER_BOUND",
  "PROPOSAL_LOWER_BOUND", "PROPOSAL_DRAWS", "USE_MEAN_CENTER",
  "ADAPTIVE_MH_DRAWS", "THINNING_FACTOR",
  "COEFFICIENTS_PRIOR_HYPERPARAMETERS", "CONVERGENCE_STARTING_VALUE",
  "CONVERGENCE_ENDING_VALUE", "CONVERGENCE_INCREMENT_VALUE",
  "MAX_ITERATIONS_STARTING_VALUE", "MAX_ITERATIONS_INCREMENT_VALUE",
  "MAX_BLOCK_ITERATIONS", "MAX_REPEATED_OPTIMIZATION_RUNS",
  "FUNCTION_CONVERGENCE_CRITERION", "SAVE_REALTIME",
  "PARAMETER_CONVERGENCE_CRITERION", "NUMBER_OF_LARGE_PERTURBATIONS",
  "NUMBER_OF_SMALL_PERTURBATIONS",
  "NUMBER_OF_POSTERIOR_DRAWS_AFTER_PERTURBATION", "MAX_NUMBER_OF_STAGES",
  "RANDOM_FUNCTION_CONVERGENCE_CRITERION",
  "RANDOM_PARAMETER_CONVERGENCE_CRITERION", "SYMBOL_VEC", "';'", "'('",
  "')'", "'['", "']'", "'#'", "':'", "'.'", "$accept", "statement_list",
  "statement", "dsample", "rplot", "trend_var", "$@1", "trend_var_list",
  "log_trend_var", "$@2", "log_trend_var_list", "var", "$@3", "$@4",
  "nonstationary_var_list", "varexo", "varexo_det",
  "predetermined_variables", "parameters", "named_var_elem", "named_var_1",
  "named_var", "var_list", "varexo_list", "varexo_det_list",
  "parameter_list", "predetermined_variables_list", "change_type",
  "change_type_arg", "change_type_var_list", "periods", "init_param",
  "expression", "$@5", "comma_expression", "expression_or_empty",
  "initval", "initval_file", "endval", "initval_list", "initval_elem",
  "histval", "histval_list", "histval_elem", "histval_file",
  "model_options", "model_options_list", "model", "$@6", "$@7",
  "equation_list", "equation", "tags_list", "tag_pair", "hand_side", "$@8",
  "comma_hand_side", "pound_expression", "shocks", "shock_list",
  "shock_elem", "det_shock_elem", "svar_identification", "$@9",
  "svar_identification_list", "svar_identification_elem", "$@10", "$@11",
  "svar_equation_list", "svar_var_list", "restriction_expression",
  "restriction_expression_1", "restriction_elem_expression",
  "svar_global_identification_check", "markov_switching",
  "ms_options_list", "ms_options", "svar", "svar_options_list",
  "svar_options", "mshocks", "mshock_list", "period_list", "sigma_e",
  "value_list", "triangular_matrix", "triangular_row", "steady",
  "steady_options_list", "steady_options", "check", "check_options_list",
  "check_options", "model_info", "model_info_options_list",
  "model_info_options", "perfect_foresight_setup",
  "perfect_foresight_setup_options_list",
  "perfect_foresight_setup_options", "perfect_foresight_solver",
  "perfect_foresight_solver_options_list",
  "perfect_foresight_solver_options", "prior_function",
  "posterior_function", "prior_posterior_function_options_list",
  "prior_posterior_function_options", "simul", "simul_options_list",
  "simul_options", "external_function", "external_function_options_list",
  "external_function_options", "stoch_simul", "stoch_simul_options_list",
  "stoch_simul_primary_options", "stoch_simul_options", "symbol_list",
  "symbol_list_ext", "signed_integer", "non_negative_number",
  "signed_number", "signed_inf", "signed_number_w_inf", "estimated_params",
  "estimated_list", "estimated_elem", "estimated_elem1", "estimated_elem2",
  "estimated_elem3", "estimated_params_init", "estimated_init_list",
  "estimated_init_elem", "estimated_params_bounds",
  "estimated_bounds_list", "estimated_bounds_elem", "osr_params_bounds",
  "osr_bounds_list", "osr_bounds_elem", "prior_distribution", "prior_pdf",
  "date_str", "date_expr", "set_time", "data", "data_options_list",
  "data_options", "subsamples", "subsamples_eq", "subsamples_eq_opt",
  "subsamples_name_list", "prior", "$@12", "$@13", "$@14", "$@15", "$@16",
  "$@17", "$@18", "prior_options_list", "prior_options",
  "joint_prior_options_list", "joint_prior_options", "prior_eq",
  "prior_eq_opt", "options", "options_options_list", "options_options",
  "options_eq", "options_eq_opt", "estimation", "estimation_options_list",
  "estimation_options", "list_optim_option", "optim_options",
  "list_sub_sampling_option", "sub_sampling_options",
  "list_sampling_option", "sampling_options", "varobs", "$@19",
  "varobs_list", "observation_trends", "trend_list", "trend_element",
  "unit_root_vars", "optim_weights", "optim_weights_list", "osr_params",
  "osr_options_list", "osr_options", "osr", "dynatype", "dynasave",
  "load_params_and_steady_state", "save_params_and_steady_state",
  "identification", "identification_options_list", "identification_option",
  "model_comparison", "filename", "parallel_local_filename_list",
  "mc_filename_list", "planner_objective", "$@20", "$@21", "ramsey_model",
  "ramsey_policy", "ramsey_policy_list", "ramsey_policy_element",
  "ramsey_constraints", "ramsey_constraints_list", "ramsey_constraint",
  "discretionary_policy", "discretionary_policy_options_list",
  "discretionary_policy_options", "ramsey_model_options_list",
  "ramsey_model_options", "ramsey_policy_options_list",
  "ramsey_policy_options", "write_latex_dynamic_model",
  "write_latex_static_model", "write_latex_original_model",
  "shock_decomposition", "realtime_shock_decomposition",
  "plot_shock_decomposition", "initial_condition_decomposition",
  "bvar_prior_option", "bvar_common_option", "bvar_density_options_list",
  "bvar_density", "bvar_forecast_option", "bvar_forecast_options_list",
  "bvar_forecast", "sbvar_option", "sbvar_options_list", "sbvar",
  "ms_variance_decomposition_option",
  "ms_variance_decomposition_options_list", "ms_variance_decomposition",
  "ms_forecast_option", "ms_forecast_options_list", "ms_forecast",
  "ms_irf_option", "ms_irf_options_list", "ms_irf",
  "ms_compute_probabilities_option",
  "ms_compute_probabilities_options_list", "ms_compute_probabilities",
  "ms_compute_mdd_option", "ms_compute_mdd_options_list", "ms_compute_mdd",
  "ms_simulation_option", "ms_simulation_options_list", "ms_simulation",
  "ms_estimation_option", "ms_estimation_options_list", "ms_estimation",
  "dynare_sensitivity", "dynare_sensitivity_options_list",
  "dynare_sensitivity_option", "shock_decomposition_options_list",
  "shock_decomposition_option",
  "realtime_shock_decomposition_options_list",
  "realtime_shock_decomposition_option",
  "plot_shock_decomposition_options_list",
  "plot_shock_decomposition_option",
  "initial_condition_decomposition_options_list",
  "initial_condition_decomposition_option", "homotopy_setup",
  "homotopy_list", "homotopy_item", "forecast", "forecast_options",
  "forecast_option", "conditional_forecast",
  "conditional_forecast_options", "conditional_forecast_option",
  "plot_conditional_forecast", "conditional_forecast_paths",
  "conditional_forecast_paths_shock_list",
  "conditional_forecast_paths_shock_elem", "steady_state_model", "$@22",
  "steady_state_equation_list", "steady_state_equation", "calib_smoother",
  "calib_smoother_options_list", "calib_smoother_option", "extended_path",
  "extended_path_options_list", "extended_path_option",
  "model_diagnostics", "calibration_range", "moment_calibration",
  "moment_calibration_list", "moment_calibration_item", "irf_calibration",
  "irf_calibration_list", "irf_calibration_item", "smoother2histval",
  "smoother2histval_options_list", "smoother2histval_option",
  "shock_groups", "shock_group_list", "shock_group_element",
  "shock_name_list", "o_dr_algo", "o_solve_algo", "o_simul_algo",
  "o_stack_solve_algo", "o_robust_lin_solve",
  "o_endogenous_terminal_period", "o_linear", "o_order", "o_replic",
  "o_drop", "o_ar", "o_nocorr", "o_nofunctions", "o_nomoments", "o_irf",
  "o_irf_shocks", "o_hp_filter", "o_hp_ngrid", "o_one_sided_hp_filter",
  "o_periods", "o_solver_periods", "o_extended_path_order", "o_hybrid",
  "o_steady_maxit", "o_simul_maxit", "o_bandpass_filter", "o_dp_maxit",
  "o_osr_maxit", "o_osr_tolf", "o_pf_tolf", "o_pf_tolx", "o_steady_tolf",
  "o_opt_algo", "o_cutoff", "o_markowitz", "o_minimal_solving_periods",
  "o_mfs", "o_simul", "o_simul_replic", "o_simul_seed", "o_qz_criterium",
  "o_qz_zero_threshold", "o_file", "o_series", "o_datafile", "o_dirname",
  "o_huge_number", "o_nobs", "o_conditional_variance_decomposition",
  "o_est_first_obs", "o_posterior_sampling_method", "o_first_obs",
  "o_data_first_obs", "o_data_last_obs",
  "o_keep_kalman_algo_if_singularity_is_detected", "o_data_nobs",
  "o_shift", "o_shape", "o_mode", "o_mean", "o_mean_vec", "o_truncate",
  "o_stdev", "o_jscale", "o_init", "o_bounds", "o_domain", "o_interval",
  "o_variance", "o_variance_mat", "o_prefilter", "o_presample",
  "o_lik_algo", "o_lik_init", "o_nograph", "o_posterior_nograph",
  "o_shock_decomposition_nograph", "o_init_state",
  "o_shock_decomposition_presample", "o_shock_decomposition_forecast",
  "o_save_realtime", "o_nodisplay", "o_psd_nodisplay", "o_graph_format",
  "o_psd_graph_format", "allowed_graph_formats",
  "list_allowed_graph_formats", "o_subsample_name", "o_bvar_conf_sig",
  "o_forecasts_conf_sig", "o_conditional_forecast_conf_sig",
  "o_mh_conf_sig", "o_mh_replic", "o_posterior_max_subsample_draws",
  "o_mh_drop", "o_mh_jscale", "o_optim", "o_posterior_sampler_options",
  "o_proposal_distribution", "o_no_posterior_kernel_density",
  "o_mh_init_scale", "o_mode_file", "o_mode_compute", "o_mode_check",
  "o_mode_check_neighbourhood_size", "o_mode_check_number_of_points",
  "o_mode_check_symmetric_plots", "o_prior_trunc", "o_mh_mode",
  "o_mh_nblocks", "o_load_mh_file", "o_load_results_after_load_mh",
  "o_loglinear", "o_linear_approximation", "o_logdata", "o_nodiagnostic",
  "o_bayesian_irf", "o_dsge_var", "o_dsge_varlag", "o_tex", "o_forecast",
  "o_smoother", "o_moments_varendo", "o_contemporaneous_correlation",
  "o_filtered_vars", "o_relative_irf", "o_fast_kalman_filter",
  "o_kalman_algo", "o_kalman_tol", "o_diffuse_kalman_tol",
  "o_marginal_density", "o_print", "o_noprint", "o_xls_sheet",
  "o_xls_range", "o_filter_step_ahead", "o_taper_steps",
  "o_geweke_interval", "o_raftery_lewis_diagnostics",
  "o_raftery_lewis_qrs", "o_constant", "o_noconstant", "o_mh_recover",
  "o_diffuse_filter", "o_plot_priors", "o_aim_solver",
  "o_partial_information", "o_sub_draws", "o_planner_discount",
  "o_sylvester", "o_sylvester_fixed_point_tol", "o_lyapunov",
  "o_lyapunov_fixed_point_tol", "o_lyapunov_doubling_tol", "o_dr",
  "o_dr_cycle_reduction_tol", "o_dr_logarithmic_reduction_tol",
  "o_dr_logarithmic_reduction_maxiter", "o_psd_detail_plot",
  "o_icd_detail_plot", "o_psd_interactive", "o_psd_screen_shocks",
  "o_psd_steadystate", "o_icd_steadystate", "o_psd_fig_name", "o_psd_type",
  "o_icd_type", "o_icd_plot_init_date", "o_icd_plot_end_date",
  "o_psd_plot_init_date", "o_psd_plot_end_date", "o_icd_write_xls",
  "o_psd_write_xls", "o_psd_realtime", "o_psd_vintage", "o_bvar_prior_tau",
  "o_bvar_prior_decay", "o_bvar_prior_lambda", "o_bvar_prior_mu",
  "o_bvar_prior_omega", "o_bvar_prior_flat", "o_bvar_prior_train",
  "o_bvar_replic", "o_number_of_particles", "o_resampling",
  "o_resampling_threshold", "o_resampling_method", "o_cpf_weights",
  "o_filter_algorithm", "o_nonlinear_filter_initialization",
  "o_proposal_approximation", "o_distribution_approximation",
  "o_gsa_identification", "o_gsa_morris", "o_gsa_stab", "o_gsa_redform",
  "o_gsa_pprior", "o_gsa_prior_range", "o_gsa_ppost", "o_gsa_ilptau",
  "o_gsa_morris_nliv", "o_gsa_morris_ntra", "o_gsa_nsam",
  "o_gsa_load_redform", "o_gsa_load_rmse", "o_gsa_load_stab",
  "o_gsa_alpha2_stab", "o_gsa_logtrans_redform", "o_gsa_threshold_redform",
  "o_gsa_ksstat_redform", "o_gsa_alpha2_redform", "o_gsa_namendo",
  "o_gsa_namlagendo", "o_gsa_namexo", "o_gsa_rmse", "o_gsa_lik_only",
  "o_gsa_var_rmse", "o_gsa_pfilt_rmse", "o_gsa_istart_rmse",
  "o_gsa_alpha_rmse", "o_gsa_alpha2_rmse", "o_gsa_sample_file",
  "o_gsa_neighborhood_width", "o_gsa_pvalue_ks", "o_gsa_pvalue_corr",
  "o_load_ident_files", "o_useautocorr", "o_prior_mc", "o_advanced",
  "o_max_dim_cova_group", "o_homotopy_mode", "o_homotopy_steps",
  "o_homotopy_force_continue", "o_nocheck", "o_controlled_varexo",
  "o_parameter_set", "o_nodecomposition", "o_spectral_density",
  "o_ms_drop", "o_ms_mh_replic", "o_freq", "o_initial_year",
  "o_initial_subperiod", "o_final_year", "o_final_subperiod", "o_data",
  "o_vlist", "o_vlistlog", "o_vlistper", "o_restriction_fname", "o_nlags",
  "o_cross_restrictions", "o_contemp_reduced_form",
  "o_real_pseudo_forecast", "o_no_bayesian_prior", "o_dummy_obs",
  "o_nstates", "o_indxscalesstates", "o_alpha", "o_beta", "o_gsig2_lmdm",
  "o_specification", "o_q_diag", "o_flat_prior", "o_ncsk", "o_nstd",
  "o_ninv", "o_indxparr", "o_indxovr", "o_aband", "o_indxap", "o_apband",
  "o_indximf", "o_indxfore", "o_foreband", "o_indxgforhat",
  "o_indxgimfhat", "o_indxestima", "o_indxgdls", "o_eq_ms", "o_cms",
  "o_ncms", "o_eq_cms", "o_tlindx", "o_tlnumber", "o_cnum",
  "o_k_order_solver", "o_pruning", "o_chain", "o_restrictions",
  "o_duration", "o_number_of_regimes", "o_number_of_lags", "o_parameters",
  "o_coefficients", "o_variances", "o_equations", "o_silent_optimizer",
  "o_instruments", "o_ext_func_name", "o_ext_func_nargs",
  "o_first_deriv_provided", "o_second_deriv_provided",
  "o_filter_covariance", "o_filter_decomposition",
  "o_smoothed_state_uncertainty", "o_selected_variables_only",
  "o_cova_compute", "o_output_file_tag", "o_file_tag", "o_no_create_init",
  "o_simulation_file_tag", "o_coefficients_prior_hyperparameters",
  "o_convergence_starting_value", "o_convergence_ending_value",
  "o_convergence_increment_value", "o_max_iterations_starting_value",
  "o_max_iterations_increment_value", "o_max_block_iterations",
  "o_max_repeated_optimization_runs", "o_function_convergence_criterion",
  "o_parameter_convergence_criterion", "o_number_of_large_perturbations",
  "o_number_of_small_perturbations",
  "o_number_of_posterior_draws_after_perturbation",
  "o_max_number_of_stages", "o_random_function_convergence_criterion",
  "o_random_parameter_convergence_criterion", "o_thinning_factor",
  "o_adaptive_mh_draws", "o_save_draws", "o_proposal_draws",
  "o_use_mean_center", "o_proposal_type", "o_proposal_lower_bound",
  "o_proposal_upper_bound", "o_parameter_uncertainty", "o_horizon",
  "o_filtered_probabilities", "o_real_time_smoothed", "o_no_error_bands",
  "o_error_band_percentiles", "o_shock_draws", "o_shocks_per_parameter",
  "o_free_parameters", "o_median", "o_regimes", "o_regime",
  "o_data_obs_nbr", "o_discretionary_tol", "o_analytic_derivation",
  "o_analytic_derivation_mode", "o_endogenous_prior",
  "o_use_univariate_filters_if_singularity_is_detected",
  "o_mcmc_jumping_covariance", "o_rescale_prediction_error_covariance",
  "o_use_penalized_objective_for_hessian", "o_irf_plot_threshold",
  "o_dr_display_tol", "o_consider_all_endogenous",
  "o_consider_only_observed", "o_no_homotopy", "o_infile", "o_invars",
  "o_period", "o_outfile", "o_outvars", "o_lmmcp", "o_function",
  "o_sampling_draws", "o_use_shock_groups", "o_colormap", "range",
  "integer_range", "signed_integer_range", "vec_int_number",
  "vec_int_elem", "vec_int_1", "vec_int", "vec_value_1", "vec_value",
  "vec_value_list", "vec_of_vec_value", "vec_value_1_w_inf",
  "vec_value_w_inf", "symbol", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   197,   197,   198,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   296,
     299,   301,   305,   307,   307,   311,   313,   315,   317,   319,
     321,   325,   325,   329,   331,   333,   335,   337,   339,   343,
     344,   344,   346,   346,   350,   352,   354,   356,   358,   360,
     362,   364,   366,   368,   370,   372,   376,   378,   380,   382,
     384,   390,   395,   400,   405,   412,   413,   416,   418,   420,
     422,   424,   426,   428,   430,   432,   434,   436,   438,   442,
     444,   446,   448,   450,   452,   454,   456,   458,   460,   462,
     464,   468,   470,   472,   474,   476,   478,   480,   482,   484,
     486,   488,   490,   494,   496,   498,   500,   502,   504,   506,
     508,   510,   512,   514,   516,   520,   522,   524,   528,   532,
     534,   536,   538,   542,   544,   546,   550,   552,   556,   558,
     560,   562,   564,   566,   568,   570,   572,   574,   576,   578,
     580,   582,   584,   586,   588,   590,   592,   594,   596,   598,
     600,   602,   604,   606,   608,   610,   612,   614,   616,   618,
     620,   622,   624,   626,   628,   628,   630,   632,   634,   636,
     638,   640,   642,   646,   648,   652,   653,   656,   658,   662,
     666,   668,   672,   673,   676,   678,   680,   684,   685,   688,
     690,   694,   695,   696,   697,   698,   699,   700,   701,   702,
     703,   706,   707,   710,   710,   712,   712,   716,   717,   718,
     719,   722,   724,   726,   728,   732,   733,   736,   738,   742,
     744,   746,   748,   750,   752,   754,   756,   758,   760,   762,
     764,   766,   768,   770,   772,   774,   776,   778,   780,   782,
     784,   786,   788,   790,   792,   794,   796,   798,   800,   802,
     804,   806,   808,   810,   812,   814,   814,   816,   818,   820,
     822,   824,   826,   830,   832,   836,   839,   840,   843,   844,
     847,   848,   850,   852,   854,   858,   862,   862,   866,   867,
     870,   872,   875,   877,   874,   879,   881,   885,   887,   891,
     893,   897,   898,   901,   902,   905,   907,   909,   911,   915,
     919,   923,   924,   927,   928,   929,   930,   931,   932,   935,
     939,   940,   943,   944,   945,   946,   949,   950,   953,   954,
     957,   959,   961,   963,   965,   967,   971,   973,   975,   977,
     979,   981,   983,   987,   989,   993,   995,   997,   999,  1001,
    1003,  1007,  1009,  1013,  1014,  1017,  1018,  1019,  1020,  1021,
    1022,  1023,  1024,  1027,  1029,  1033,  1034,  1037,  1038,  1041,
    1043,  1047,  1048,  1050,  1052,  1054,  1058,  1059,  1062,  1063,
    1066,  1068,  1072,  1073,  1076,  1077,  1078,  1079,  1080,  1081,
    1082,  1083,  1084,  1085,  1086,  1087,  1090,  1094,  1098,  1099,
    1102,  1103,  1106,  1108,  1112,  1113,  1116,  1117,  1120,  1124,
    1125,  1128,  1129,  1130,  1131,  1134,  1136,  1138,  1140,  1144,
    1145,  1148,  1149,  1150,  1151,  1152,  1153,  1154,  1155,  1156,
    1157,  1158,  1159,  1160,  1161,  1162,  1163,  1164,  1165,  1166,
    1167,  1168,  1169,  1170,  1171,  1172,  1173,  1174,  1175,  1176,
    1177,  1178,  1179,  1180,  1181,  1182,  1183,  1184,  1185,  1186,
    1187,  1188,  1189,  1192,  1193,  1194,  1195,  1196,  1197,  1200,
    1202,  1204,  1208,  1209,  1216,  1218,  1220,  1223,  1224,  1227,
    1229,  1231,  1234,  1236,  1238,  1242,  1243,  1246,  1248,  1250,
    1254,  1255,  1257,  1263,  1269,  1277,  1284,  1288,  1293,  1300,
    1304,  1312,  1317,  1323,  1330,  1340,  1342,  1344,  1348,  1350,
    1354,  1361,  1370,  1379,  1382,  1384,  1388,  1396,  1406,  1416,
    1419,  1421,  1425,  1434,  1436,  1438,  1440,  1442,  1444,  1446,
    1448,  1450,  1454,  1456,  1458,  1460,  1462,  1464,  1466,  1468,
    1472,  1474,  1476,  1480,  1484,  1488,  1489,  1492,  1493,  1494,
    1495,  1496,  1497,  1498,  1501,  1505,  1513,  1519,  1525,  1533,
    1534,  1537,  1537,  1539,  1539,  1541,  1541,  1543,  1543,  1545,
    1545,  1547,  1547,  1549,  1549,  1553,  1554,  1557,  1558,  1559,
    1560,  1561,  1562,  1563,  1564,  1565,  1566,  1569,  1570,  1573,
    1574,  1575,  1576,  1577,  1578,  1579,  1580,  1581,  1582,  1585,
    1594,  1602,  1610,  1618,  1626,  1634,  1644,  1646,  1648,  1650,
    1652,  1654,  1658,  1659,  1662,  1663,  1664,  1667,  1676,  1684,
    1692,  1700,  1708,  1716,  1726,  1728,  1730,  1732,  1736,  1737,
    1740,  1741,  1742,  1743,  1744,  1745,  1746,  1747,  1748,  1749,
    1750,  1751,  1752,  1753,  1754,  1755,  1756,  1757,  1758,  1759,
    1760,  1761,  1762,  1763,  1764,  1765,  1766,  1767,  1768,  1769,
    1770,  1771,  1772,  1773,  1774,  1775,  1776,  1777,  1778,  1779,
    1780,  1781,  1782,  1783,  1784,  1785,  1786,  1787,  1788,  1789,
    1790,  1791,  1792,  1793,  1794,  1795,  1796,  1797,  1798,  1799,
    1800,  1801,  1802,  1803,  1804,  1805,  1806,  1807,  1808,  1809,
    1810,  1811,  1812,  1813,  1814,  1815,  1816,  1817,  1818,  1819,
    1820,  1821,  1822,  1823,  1824,  1825,  1826,  1827,  1828,  1829,
    1830,  1831,  1832,  1833,  1834,  1835,  1836,  1837,  1838,  1839,
    1840,  1841,  1842,  1843,  1844,  1845,  1846,  1847,  1848,  1849,
    1852,  1854,  1858,  1859,  1862,  1870,  1879,  1881,  1889,  1891,
    1893,  1901,  1902,  1905,  1905,  1907,  1909,  1911,  1915,  1917,
    1918,  1921,  1923,  1925,  1927,  1929,  1931,  1933,  1937,  1940,
    1941,  1944,  1945,  1946,  1947,  1948,  1949,  1950,  1953,  1955,
    1957,  1959,  1963,  1965,  1969,  1971,  1975,  1979,  1983,  1985,
    1989,  1990,  1993,  1994,  1995,  1996,  1997,  1998,  1999,  2000,
    2001,  2002,  2003,  2004,  2005,  2006,  2007,  2008,  2009,  2010,
    2011,  2012,  2015,  2017,  2021,  2022,  2025,  2027,  2031,  2033,
    2035,  2037,  2039,  2041,  2045,  2046,  2045,  2048,  2050,  2052,
    2054,  2058,  2060,  2062,  2064,  2068,  2069,  2072,  2075,  2079,
    2080,  2083,  2085,  2087,  2089,  2093,  2095,  2097,  2099,  2103,
    2104,  2107,  2108,  2109,  2112,  2113,  2116,  2117,  2120,  2121,
    2124,  2125,  2126,  2129,  2131,  2135,  2139,  2143,  2145,  2147,
    2149,  2153,  2155,  2157,  2159,  2163,  2165,  2167,  2169,  2173,
    2175,  2177,  2179,  2183,  2184,  2185,  2186,  2187,  2188,  2189,
    2192,  2193,  2194,  2195,  2196,  2197,  2198,  2199,  2200,  2201,
    2204,  2205,  2208,  2210,  2214,  2215,  2216,  2217,  2220,  2221,
    2224,  2226,  2230,  2231,  2232,  2233,  2234,  2235,  2236,  2237,
    2238,  2239,  2240,  2241,  2242,  2243,  2244,  2245,  2246,  2247,
    2248,  2249,  2250,  2251,  2252,  2253,  2254,  2255,  2256,  2257,
    2258,  2259,  2260,  2261,  2262,  2263,  2264,  2265,  2266,  2267,
    2268,  2269,  2270,  2271,  2272,  2273,  2274,  2275,  2276,  2277,
    2280,  2281,  2284,  2286,  2290,  2291,  2292,  2293,  2294,  2295,
    2296,  2297,  2298,  2299,  2300,  2301,  2302,  2303,  2306,  2307,
    2310,  2312,  2316,  2317,  2318,  2319,  2320,  2321,  2322,  2323,
    2324,  2325,  2326,  2327,  2328,  2329,  2332,  2333,  2336,  2338,
    2342,  2343,  2344,  2345,  2346,  2347,  2348,  2349,  2350,  2351,
    2352,  2353,  2354,  2355,  2358,  2359,  2362,  2364,  2366,  2368,
    2372,  2373,  2374,  2375,  2378,  2379,  2382,  2384,  2388,  2389,
    2390,  2391,  2392,  2393,  2394,  2395,  2398,  2399,  2402,  2404,
    2408,  2409,  2410,  2411,  2412,  2413,  2414,  2417,  2418,  2421,
    2423,  2427,  2428,  2429,  2430,  2431,  2432,  2433,  2434,  2435,
    2436,  2437,  2438,  2439,  2440,  2441,  2442,  2443,  2444,  2445,
    2446,  2447,  2448,  2449,  2450,  2451,  2452,  2453,  2454,  2455,
    2456,  2457,  2458,  2459,  2460,  2461,  2464,  2465,  2468,  2470,
    2474,  2476,  2480,  2481,  2484,  2485,  2486,  2487,  2488,  2489,
    2490,  2491,  2492,  2493,  2494,  2495,  2496,  2497,  2498,  2499,
    2500,  2501,  2502,  2503,  2504,  2505,  2506,  2507,  2508,  2509,
    2510,  2511,  2512,  2513,  2514,  2515,  2516,  2517,  2518,  2519,
    2520,  2521,  2522,  2523,  2524,  2525,  2526,  2527,  2528,  2529,
    2530,  2531,  2532,  2533,  2534,  2537,  2538,  2541,  2542,  2543,
    2544,  2545,  2546,  2547,  2548,  2551,  2552,  2555,  2556,  2557,
    2558,  2559,  2560,  2561,  2562,  2563,  2564,  2567,  2568,  2571,
    2572,  2573,  2574,  2575,  2576,  2577,  2578,  2579,  2580,  2581,
    2582,  2583,  2584,  2585,  2588,  2589,  2592,  2593,  2594,  2595,
    2596,  2597,  2600,  2603,  2604,  2607,  2609,  2613,  2614,  2615,
    2616,  2619,  2620,  2623,  2624,  2625,  2626,  2627,  2630,  2634,
    2635,  2638,  2639,  2640,  2641,  2642,  2645,  2647,  2651,  2655,
    2656,  2659,  2663,  2663,  2667,  2668,  2671,  2673,  2677,  2679,
    2681,  2683,  2687,  2688,  2691,  2692,  2693,  2694,  2695,  2696,
    2697,  2698,  2699,  2700,  2703,  2705,  2709,  2710,  2713,  2714,
    2715,  2716,  2717,  2720,  2724,  2730,  2736,  2742,  2750,  2754,
    2755,  2758,  2760,  2762,  2766,  2768,  2772,  2773,  2776,  2778,
    2780,  2784,  2786,  2790,  2791,  2794,  2795,  2796,  2797,  2798,
    2801,  2802,  2806,  2807,  2810,  2811,  2814,  2815,  2816,  2819,
    2825,  2826,  2832,  2833,  2834,  2835,  2836,  2837,  2838,  2839,
    2840,  2841,  2842,  2843,  2844,  2845,  2846,  2847,  2848,  2849,
    2850,  2851,  2852,  2853,  2854,  2855,  2861,  2862,  2863,  2864,
    2865,  2866,  2867,  2868,  2870,  2871,  2872,  2873,  2874,  2875,
    2876,  2877,  2878,  2879,  2880,  2881,  2882,  2883,  2884,  2886,
    2889,  2891,  2894,  2896,  2899,  2901,  2902,  2903,  2904,  2905,
    2906,  2907,  2908,  2909,  2910,  2911,  2912,  2913,  2914,  2915,
    2916,  2917,  2918,  2919,  2920,  2921,  2922,  2923,  2924,  2926,
    2929,  2931,  2934,  2935,  2936,  2937,  2938,  2939,  2940,  2941,
    2943,  2946,  2948,  2951,  2953,  2955,  2957,  2960,  2961,  2964,
    2967,  2968,  2969,  2970,  2971,  2972,  2973,  2974,  2975,  2976,
    2977,  2978,  2981,  2982,  2983,  2984,  2985,  2986,  2987,  2988,
    2989,  2990,  2991,  2992,  2993,  2994,  2995,  2996,  2997,  2998,
    2999,  3001,  3003,  3006,  3007,  3008,  3009,  3010,  3011,  3012,
    3013,  3014,  3015,  3016,  3017,  3018,  3020,  3023,  3024,  3025,
    3026,  3027,  3028,  3029,  3030,  3031,  3032,  3033,  3034,  3035,
    3036,  3037,  3038,  3039,  3040,  3041,  3042,  3043,  3044,  3045,
    3046,  3047,  3048,  3049,  3050,  3051,  3052,  3053,  3054,  3055,
    3056,  3057,  3058,  3059,  3060,  3061,  3062,  3063,  3065,  3067,
    3070,  3072,  3074,  3077,  3078,  3079,  3080,  3081,  3082,  3083,
    3084,  3085,  3086,  3087,  3088,  3089,  3090,  3091,  3092,  3094,
    3095,  3096,  3097,  3098,  3099,  3100,  3101,  3102,  3103,  3104,
    3105,  3106,  3107,  3108,  3109,  3110,  3111,  3114,  3115,  3116,
    3117,  3118,  3119,  3120,  3121,  3122,  3123,  3124,  3125,  3126,
    3127,  3128,  3129,  3130,  3131,  3132,  3133,  3134,  3135,  3136,
    3137,  3138,  3139,  3140,  3141,  3142,  3143,  3145,  3148,  3149,
    3150,  3151,  3152,  3153,  3154,  3155,  3157,  3158,  3159,  3160,
    3162,  3163,  3165,  3167,  3169,  3171,  3173,  3175,  3178,  3179,
    3180,  3181,  3182,  3184,  3186,  3189,  3190,  3191,  3192,  3193,
    3194,  3195,  3196,  3197,  3202,  3207,  3213,  3214,  3215,  3216,
    3217,  3218,  3219,  3220,  3221,  3222,  3223,  3224,  3226,  3229,
    3230,  3231,  3232,  3233,  3234,  3235,  3236,  3237,  3238,  3239,
    3240,  3241,  3242,  3243,  3244,  3245,  3246,  3247,  3248,  3249,
    3250,  3251,  3252,  3253,  3254,  3255,  3256,  3259,  3261,  3264,
    3265,  3266,  3267,  3268,  3269,  3271,  3274,  3275,  3277,  3278,
    3279,  3281,  3284,  3286,  3289,  3292,  3295,  3298,  3301,  3304,
    3305,  3306,  3307,  3308,  3310,  3312,  3314,  3316,  3318,  3320,
    3322,  3324,  3326,  3328,  3330,  3332,  3334,  3336,  3338,  3340,
    3341,  3342,  3343,  3344,  3345,  3346,  3347,  3348,  3349,  3350,
    3351,  3352,  3353,  3354,  3355,  3356,  3357,  3358,  3359,  3360,
    3361,  3362,  3363,  3364,  3365,  3366,  3367,  3368,  3370,  3372,
    3375,  3376,  3377,  3378,  3379,  3380,  3381,  3383,  3384,  3385,
    3386,  3387,  3388,  3389,  3390,  3391,  3392,  3394,  3396,  3404,
    3412,  3419,  3429,  3431,  3432,  3442,  3444,  3446,  3454,  3464,
    3466,  3470,  3471,  3472,  3479,  3488,  3489,  3492,  3499,  3503,
    3504,  3506,  3508,  3517,  3519,  3520,  3521,  3522,  3523,  3524,
    3525,  3526,  3527,  3528,  3529,  3530,  3531,  3532,  3533,  3534,
    3535,  3536,  3537,  3538
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  parser::symbol_kind_type
  parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const short
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,   586,     2,     2,     2,     2,
     582,   583,     2,     2,     2,     2,   588,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   587,   581,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   584,     2,   585,     2,     2,     2,     2,     2,     2,
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
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580
    };
    // Last valid token kind.
    const int code_max = 835;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // Dynare
#line 12275 "pkg/src/DynareBison.cc"

#line 3540 "pkg/src/lex_yacc/DynareBison.yy"


void
Dynare::parser::error(const Dynare::parser::location_type &l,
                      const string &m)
{
  driver.error(l, m);
}
