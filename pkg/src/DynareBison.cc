// A Bison parser, made by GNU Bison 3.0.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

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
// //                    "%code top" blocks.
#line 24 "lex_yacc/DynareBison.yy" // lalr1.cc:392

class ParsingDriver;

#line 38 "DynareBison.cc" // lalr1.cc:392

// Take the name prefix into account.
#define yylex   Dynarelex

// First part of user declarations.

#line 45 "DynareBison.cc" // lalr1.cc:399

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "DynareBison.hh"

// User implementation prologue.

#line 59 "DynareBison.cc" // lalr1.cc:407
// Unqualified %code blocks.
#line 60 "lex_yacc/DynareBison.yy" // lalr1.cc:408

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

#line 88 "DynareBison.cc" // lalr1.cc:408


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
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

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
      *yycdebug_ << std::endl;                  \
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
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyempty = true)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace Dynare {
#line 174 "DynareBison.cc" // lalr1.cc:474

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
        std::string yyr = "";
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
              // Fall through.
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


  /// Build a parser object.
  parser::parser (ParsingDriver &driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {}

  parser::~parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  parser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
    value = other.value;
  }


  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  inline
  parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  inline
  parser::basic_symbol<Base>::~basic_symbol ()
  {
  }

  template <typename Base>
  inline
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
    value = s.value;
    location = s.location;
  }

  // by_type.
  inline
  parser::by_type::by_type ()
     : type (empty)
  {}

  inline
  parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.type = empty;
  }

  inline
  int
  parser::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  inline
  parser::by_state::by_state ()
    : state (empty)
  {}

  inline
  parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.state = empty;
  }

  inline
  parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  parser::symbol_number_type
  parser::by_state::type_get () const
  {
    return state == empty ? 0 : yystos_[state];
  }

  inline
  parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
    value = that.value;
    // that is emptied.
    that.type = empty;
  }

  inline
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  parser::yypop_ (unsigned int n)
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

  inline parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::parse ()
  {
    /// Whether yyla contains a lookahead.
    bool yyempty = true;

    // State.
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

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    // User initialization code.
    #line 40 "lex_yacc/DynareBison.yy" // lalr1.cc:725
{
  // Initialize the locations' filenames to the filename maintained by the lexer
  yyla.location.begin.filename = yyla.location.end.filename = &(driver.lexer->filename);
}

#line 518 "DynareBison.cc" // lalr1.cc:725

    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyempty)
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location, driver));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
        yyempty = false;
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Discard the token being shifted.
    yyempty = true;

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;

      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 97:
#line 296 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.dsample((yystack_[1].value.string_val)); }
#line 632 "DynareBison.cc" // lalr1.cc:847
    break;

  case 98:
#line 298 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.dsample((yystack_[2].value.string_val), (yystack_[1].value.string_val)); }
#line 638 "DynareBison.cc" // lalr1.cc:847
    break;

  case 99:
#line 301 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.rplot(); }
#line 644 "DynareBison.cc" // lalr1.cc:847
    break;

  case 100:
#line 303 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.begin_trend(); }
#line 650 "DynareBison.cc" // lalr1.cc:847
    break;

  case 101:
#line 304 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.end_trend_var((yystack_[3].value.node_val)); }
#line 656 "DynareBison.cc" // lalr1.cc:847
    break;

  case 102:
#line 308 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_trend_var(false, (yystack_[0].value.string_val)); }
#line 662 "DynareBison.cc" // lalr1.cc:847
    break;

  case 103:
#line 310 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_trend_var(false, (yystack_[0].value.string_val)); }
#line 668 "DynareBison.cc" // lalr1.cc:847
    break;

  case 104:
#line 312 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_trend_var(false, (yystack_[0].value.string_val)); }
#line 674 "DynareBison.cc" // lalr1.cc:847
    break;

  case 105:
#line 314 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_trend_var(false, (yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 680 "DynareBison.cc" // lalr1.cc:847
    break;

  case 106:
#line 316 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_trend_var(false, (yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 686 "DynareBison.cc" // lalr1.cc:847
    break;

  case 107:
#line 318 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_trend_var(false, (yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 692 "DynareBison.cc" // lalr1.cc:847
    break;

  case 108:
#line 321 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.begin_trend(); }
#line 698 "DynareBison.cc" // lalr1.cc:847
    break;

  case 109:
#line 322 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.end_trend_var((yystack_[3].value.node_val)); }
#line 704 "DynareBison.cc" // lalr1.cc:847
    break;

  case 110:
#line 326 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_trend_var(true, (yystack_[0].value.string_val)); }
#line 710 "DynareBison.cc" // lalr1.cc:847
    break;

  case 111:
#line 328 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_trend_var(true, (yystack_[0].value.string_val)); }
#line 716 "DynareBison.cc" // lalr1.cc:847
    break;

  case 112:
#line 330 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_trend_var(true, (yystack_[0].value.string_val)); }
#line 722 "DynareBison.cc" // lalr1.cc:847
    break;

  case 113:
#line 332 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_trend_var(true, (yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 728 "DynareBison.cc" // lalr1.cc:847
    break;

  case 114:
#line 334 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_trend_var(true, (yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 734 "DynareBison.cc" // lalr1.cc:847
    break;

  case 115:
#line 336 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_trend_var(true, (yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 740 "DynareBison.cc" // lalr1.cc:847
    break;

  case 117:
#line 340 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.begin_trend(); }
#line 746 "DynareBison.cc" // lalr1.cc:847
    break;

  case 118:
#line 341 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.end_nonstationary_var(false, (yystack_[3].value.node_val)); }
#line 752 "DynareBison.cc" // lalr1.cc:847
    break;

  case 119:
#line 342 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.begin_trend(); }
#line 758 "DynareBison.cc" // lalr1.cc:847
    break;

  case 120:
#line 343 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.end_nonstationary_var(true, (yystack_[3].value.node_val)); }
#line 764 "DynareBison.cc" // lalr1.cc:847
    break;

  case 121:
#line 347 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_nonstationary_var((yystack_[0].value.string_val)); }
#line 770 "DynareBison.cc" // lalr1.cc:847
    break;

  case 122:
#line 349 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_nonstationary_var((yystack_[0].value.string_val)); }
#line 776 "DynareBison.cc" // lalr1.cc:847
    break;

  case 123:
#line 351 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_nonstationary_var((yystack_[0].value.string_val)); }
#line 782 "DynareBison.cc" // lalr1.cc:847
    break;

  case 124:
#line 353 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_nonstationary_var((yystack_[1].value.string_val), NULL, (yystack_[0].value.vector_string_pair_val)); }
#line 788 "DynareBison.cc" // lalr1.cc:847
    break;

  case 125:
#line 355 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_nonstationary_var((yystack_[1].value.string_val), NULL, (yystack_[0].value.vector_string_pair_val)); }
#line 794 "DynareBison.cc" // lalr1.cc:847
    break;

  case 126:
#line 357 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_nonstationary_var((yystack_[1].value.string_val), NULL, (yystack_[0].value.vector_string_pair_val)); }
#line 800 "DynareBison.cc" // lalr1.cc:847
    break;

  case 127:
#line 359 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_nonstationary_var((yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 806 "DynareBison.cc" // lalr1.cc:847
    break;

  case 128:
#line 361 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_nonstationary_var((yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 812 "DynareBison.cc" // lalr1.cc:847
    break;

  case 129:
#line 363 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_nonstationary_var((yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 818 "DynareBison.cc" // lalr1.cc:847
    break;

  case 130:
#line 365 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_nonstationary_var((yystack_[2].value.string_val), (yystack_[1].value.string_val), (yystack_[0].value.vector_string_pair_val)); }
#line 824 "DynareBison.cc" // lalr1.cc:847
    break;

  case 131:
#line 367 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_nonstationary_var((yystack_[2].value.string_val), (yystack_[1].value.string_val), (yystack_[0].value.vector_string_pair_val)); }
#line 830 "DynareBison.cc" // lalr1.cc:847
    break;

  case 132:
#line 369 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_nonstationary_var((yystack_[2].value.string_val), (yystack_[1].value.string_val), (yystack_[0].value.vector_string_pair_val)); }
#line 836 "DynareBison.cc" // lalr1.cc:847
    break;

  case 137:
#line 381 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                  pair<string *, string *> *pr = new pair<string *, string *>((yystack_[2].value.string_val), (yystack_[0].value.string_val));
                  (yylhs.value.string_pair_val) = pr;
               }
#line 845 "DynareBison.cc" // lalr1.cc:847
    break;

  case 138:
#line 387 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                (yylhs.value.vector_string_pair_val) = new vector<pair<string *, string *> *>();
                (yylhs.value.vector_string_pair_val)->push_back((yystack_[0].value.string_pair_val));
              }
#line 854 "DynareBison.cc" // lalr1.cc:847
    break;

  case 139:
#line 392 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                (yylhs.value.vector_string_pair_val) = new vector<pair<string *, string *> *>();
                (yylhs.value.vector_string_pair_val)->push_back((yystack_[0].value.string_pair_val));
              }
#line 863 "DynareBison.cc" // lalr1.cc:847
    break;

  case 140:
#line 397 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                (yystack_[1].value.vector_string_pair_val)->push_back((yystack_[0].value.string_pair_val));
                (yylhs.value.vector_string_pair_val) = (yystack_[1].value.vector_string_pair_val);
              }
#line 872 "DynareBison.cc" // lalr1.cc:847
    break;

  case 141:
#line 402 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                (yystack_[2].value.vector_string_pair_val)->push_back((yystack_[0].value.string_pair_val));
                (yylhs.value.vector_string_pair_val) = (yystack_[2].value.vector_string_pair_val);
              }
#line 881 "DynareBison.cc" // lalr1.cc:847
    break;

  case 142:
#line 408 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.vector_string_pair_val) = (yystack_[1].value.vector_string_pair_val); }
#line 887 "DynareBison.cc" // lalr1.cc:847
    break;

  case 143:
#line 409 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.vector_string_pair_val) = (yystack_[2].value.vector_string_pair_val); }
#line 893 "DynareBison.cc" // lalr1.cc:847
    break;

  case 144:
#line 413 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_endogenous((yystack_[0].value.string_val)); }
#line 899 "DynareBison.cc" // lalr1.cc:847
    break;

  case 145:
#line 415 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_endogenous((yystack_[0].value.string_val)); }
#line 905 "DynareBison.cc" // lalr1.cc:847
    break;

  case 146:
#line 417 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_endogenous((yystack_[0].value.string_val)); }
#line 911 "DynareBison.cc" // lalr1.cc:847
    break;

  case 147:
#line 419 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_endogenous((yystack_[1].value.string_val), NULL, (yystack_[0].value.vector_string_pair_val)); }
#line 917 "DynareBison.cc" // lalr1.cc:847
    break;

  case 148:
#line 421 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_endogenous((yystack_[1].value.string_val), NULL, (yystack_[0].value.vector_string_pair_val)); }
#line 923 "DynareBison.cc" // lalr1.cc:847
    break;

  case 149:
#line 423 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_endogenous((yystack_[1].value.string_val), NULL, (yystack_[0].value.vector_string_pair_val)); }
#line 929 "DynareBison.cc" // lalr1.cc:847
    break;

  case 150:
#line 425 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_endogenous((yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 935 "DynareBison.cc" // lalr1.cc:847
    break;

  case 151:
#line 427 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_endogenous((yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 941 "DynareBison.cc" // lalr1.cc:847
    break;

  case 152:
#line 429 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_endogenous((yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 947 "DynareBison.cc" // lalr1.cc:847
    break;

  case 153:
#line 431 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_endogenous((yystack_[2].value.string_val), (yystack_[1].value.string_val), (yystack_[0].value.vector_string_pair_val)); }
#line 953 "DynareBison.cc" // lalr1.cc:847
    break;

  case 154:
#line 433 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_endogenous((yystack_[2].value.string_val), (yystack_[1].value.string_val), (yystack_[0].value.vector_string_pair_val)); }
#line 959 "DynareBison.cc" // lalr1.cc:847
    break;

  case 155:
#line 435 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_endogenous((yystack_[2].value.string_val), (yystack_[1].value.string_val), (yystack_[0].value.vector_string_pair_val)); }
#line 965 "DynareBison.cc" // lalr1.cc:847
    break;

  case 156:
#line 439 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_exogenous((yystack_[0].value.string_val)); }
#line 971 "DynareBison.cc" // lalr1.cc:847
    break;

  case 157:
#line 441 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_exogenous((yystack_[0].value.string_val)); }
#line 977 "DynareBison.cc" // lalr1.cc:847
    break;

  case 158:
#line 443 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_exogenous((yystack_[0].value.string_val)); }
#line 983 "DynareBison.cc" // lalr1.cc:847
    break;

  case 159:
#line 445 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_exogenous((yystack_[1].value.string_val), NULL, (yystack_[0].value.vector_string_pair_val)); }
#line 989 "DynareBison.cc" // lalr1.cc:847
    break;

  case 160:
#line 447 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_exogenous((yystack_[1].value.string_val), NULL, (yystack_[0].value.vector_string_pair_val)); }
#line 995 "DynareBison.cc" // lalr1.cc:847
    break;

  case 161:
#line 449 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_exogenous((yystack_[1].value.string_val), NULL, (yystack_[0].value.vector_string_pair_val)); }
#line 1001 "DynareBison.cc" // lalr1.cc:847
    break;

  case 162:
#line 451 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_exogenous((yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 1007 "DynareBison.cc" // lalr1.cc:847
    break;

  case 163:
#line 453 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_exogenous((yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 1013 "DynareBison.cc" // lalr1.cc:847
    break;

  case 164:
#line 455 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_exogenous((yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 1019 "DynareBison.cc" // lalr1.cc:847
    break;

  case 165:
#line 457 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_exogenous((yystack_[2].value.string_val), (yystack_[1].value.string_val), (yystack_[0].value.vector_string_pair_val)); }
#line 1025 "DynareBison.cc" // lalr1.cc:847
    break;

  case 166:
#line 459 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_exogenous((yystack_[2].value.string_val), (yystack_[1].value.string_val), (yystack_[0].value.vector_string_pair_val)); }
#line 1031 "DynareBison.cc" // lalr1.cc:847
    break;

  case 167:
#line 461 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_exogenous((yystack_[2].value.string_val), (yystack_[1].value.string_val), (yystack_[0].value.vector_string_pair_val)); }
#line 1037 "DynareBison.cc" // lalr1.cc:847
    break;

  case 168:
#line 465 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_exogenous_det((yystack_[0].value.string_val)); }
#line 1043 "DynareBison.cc" // lalr1.cc:847
    break;

  case 169:
#line 467 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_exogenous_det((yystack_[0].value.string_val)); }
#line 1049 "DynareBison.cc" // lalr1.cc:847
    break;

  case 170:
#line 469 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_exogenous_det((yystack_[0].value.string_val)); }
#line 1055 "DynareBison.cc" // lalr1.cc:847
    break;

  case 171:
#line 471 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_exogenous_det((yystack_[1].value.string_val), NULL, (yystack_[0].value.vector_string_pair_val)); }
#line 1061 "DynareBison.cc" // lalr1.cc:847
    break;

  case 172:
#line 473 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_exogenous_det((yystack_[1].value.string_val), NULL, (yystack_[0].value.vector_string_pair_val)); }
#line 1067 "DynareBison.cc" // lalr1.cc:847
    break;

  case 173:
#line 475 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_exogenous_det((yystack_[1].value.string_val), NULL, (yystack_[0].value.vector_string_pair_val)); }
#line 1073 "DynareBison.cc" // lalr1.cc:847
    break;

  case 174:
#line 477 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_exogenous_det((yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 1079 "DynareBison.cc" // lalr1.cc:847
    break;

  case 175:
#line 479 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_exogenous_det((yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 1085 "DynareBison.cc" // lalr1.cc:847
    break;

  case 176:
#line 481 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_exogenous_det((yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 1091 "DynareBison.cc" // lalr1.cc:847
    break;

  case 177:
#line 483 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_exogenous_det((yystack_[2].value.string_val), (yystack_[1].value.string_val), (yystack_[0].value.vector_string_pair_val)); }
#line 1097 "DynareBison.cc" // lalr1.cc:847
    break;

  case 178:
#line 485 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_exogenous_det((yystack_[2].value.string_val), (yystack_[1].value.string_val), (yystack_[0].value.vector_string_pair_val)); }
#line 1103 "DynareBison.cc" // lalr1.cc:847
    break;

  case 179:
#line 487 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_exogenous_det((yystack_[2].value.string_val), (yystack_[1].value.string_val), (yystack_[0].value.vector_string_pair_val)); }
#line 1109 "DynareBison.cc" // lalr1.cc:847
    break;

  case 180:
#line 491 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_parameter((yystack_[0].value.string_val)); }
#line 1115 "DynareBison.cc" // lalr1.cc:847
    break;

  case 181:
#line 493 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_parameter((yystack_[0].value.string_val)); }
#line 1121 "DynareBison.cc" // lalr1.cc:847
    break;

  case 182:
#line 495 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_parameter((yystack_[0].value.string_val)); }
#line 1127 "DynareBison.cc" // lalr1.cc:847
    break;

  case 183:
#line 497 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_parameter((yystack_[1].value.string_val), NULL, (yystack_[0].value.vector_string_pair_val)); }
#line 1133 "DynareBison.cc" // lalr1.cc:847
    break;

  case 184:
#line 499 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_parameter((yystack_[1].value.string_val), NULL, (yystack_[0].value.vector_string_pair_val)); }
#line 1139 "DynareBison.cc" // lalr1.cc:847
    break;

  case 185:
#line 501 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_parameter((yystack_[1].value.string_val), NULL, (yystack_[0].value.vector_string_pair_val)); }
#line 1145 "DynareBison.cc" // lalr1.cc:847
    break;

  case 186:
#line 503 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_parameter((yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 1151 "DynareBison.cc" // lalr1.cc:847
    break;

  case 187:
#line 505 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_parameter((yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 1157 "DynareBison.cc" // lalr1.cc:847
    break;

  case 188:
#line 507 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_parameter((yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 1163 "DynareBison.cc" // lalr1.cc:847
    break;

  case 189:
#line 509 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_parameter((yystack_[2].value.string_val), (yystack_[1].value.string_val), (yystack_[0].value.vector_string_pair_val)); }
#line 1169 "DynareBison.cc" // lalr1.cc:847
    break;

  case 190:
#line 511 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_parameter((yystack_[2].value.string_val), (yystack_[1].value.string_val), (yystack_[0].value.vector_string_pair_val)); }
#line 1175 "DynareBison.cc" // lalr1.cc:847
    break;

  case 191:
#line 513 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_parameter((yystack_[2].value.string_val), (yystack_[1].value.string_val), (yystack_[0].value.vector_string_pair_val)); }
#line 1181 "DynareBison.cc" // lalr1.cc:847
    break;

  case 192:
#line 517 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_predetermined_variable((yystack_[0].value.string_val)); }
#line 1187 "DynareBison.cc" // lalr1.cc:847
    break;

  case 193:
#line 519 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_predetermined_variable((yystack_[0].value.string_val)); }
#line 1193 "DynareBison.cc" // lalr1.cc:847
    break;

  case 194:
#line 521 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_predetermined_variable((yystack_[0].value.string_val)); }
#line 1199 "DynareBison.cc" // lalr1.cc:847
    break;

  case 195:
#line 525 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.change_type((yystack_[3].value.symbol_type_val), (yystack_[1].value.vector_string_val)); }
#line 1205 "DynareBison.cc" // lalr1.cc:847
    break;

  case 196:
#line 529 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.symbol_type_val) = eParameter; }
#line 1211 "DynareBison.cc" // lalr1.cc:847
    break;

  case 197:
#line 531 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.symbol_type_val) = eEndogenous; }
#line 1217 "DynareBison.cc" // lalr1.cc:847
    break;

  case 198:
#line 533 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.symbol_type_val) = eExogenous; }
#line 1223 "DynareBison.cc" // lalr1.cc:847
    break;

  case 199:
#line 535 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.symbol_type_val) = eExogenousDet; }
#line 1229 "DynareBison.cc" // lalr1.cc:847
    break;

  case 200:
#line 539 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.vector_string_val) = new vector<string *>(); (yylhs.value.vector_string_val)->push_back((yystack_[0].value.string_val)); }
#line 1235 "DynareBison.cc" // lalr1.cc:847
    break;

  case 201:
#line 541 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.vector_string_val) = (yystack_[1].value.vector_string_val); (yystack_[1].value.vector_string_val)->push_back((yystack_[0].value.string_val)); }
#line 1241 "DynareBison.cc" // lalr1.cc:847
    break;

  case 202:
#line 543 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.vector_string_val) = (yystack_[2].value.vector_string_val); (yystack_[2].value.vector_string_val)->push_back((yystack_[0].value.string_val)); }
#line 1247 "DynareBison.cc" // lalr1.cc:847
    break;

  case 203:
#line 547 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.periods((yystack_[1].value.string_val)); }
#line 1253 "DynareBison.cc" // lalr1.cc:847
    break;

  case 204:
#line 549 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.periods((yystack_[1].value.string_val)); }
#line 1259 "DynareBison.cc" // lalr1.cc:847
    break;

  case 205:
#line 552 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.init_param((yystack_[3].value.string_val), (yystack_[1].value.node_val)); }
#line 1265 "DynareBison.cc" // lalr1.cc:847
    break;

  case 206:
#line 555 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = (yystack_[1].value.node_val);}
#line 1271 "DynareBison.cc" // lalr1.cc:847
    break;

  case 207:
#line 557 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_expression_variable((yystack_[0].value.string_val)); }
#line 1277 "DynareBison.cc" // lalr1.cc:847
    break;

  case 208:
#line 559 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_non_negative_constant((yystack_[0].value.string_val)); }
#line 1283 "DynareBison.cc" // lalr1.cc:847
    break;

  case 209:
#line 561 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_plus((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1289 "DynareBison.cc" // lalr1.cc:847
    break;

  case 210:
#line 563 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_minus((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1295 "DynareBison.cc" // lalr1.cc:847
    break;

  case 211:
#line 565 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_divide((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1301 "DynareBison.cc" // lalr1.cc:847
    break;

  case 212:
#line 567 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_times((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1307 "DynareBison.cc" // lalr1.cc:847
    break;

  case 213:
#line 569 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_power((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1313 "DynareBison.cc" // lalr1.cc:847
    break;

  case 214:
#line 571 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_less((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1319 "DynareBison.cc" // lalr1.cc:847
    break;

  case 215:
#line 573 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_greater((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1325 "DynareBison.cc" // lalr1.cc:847
    break;

  case 216:
#line 575 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_less_equal((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1331 "DynareBison.cc" // lalr1.cc:847
    break;

  case 217:
#line 577 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_greater_equal((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1337 "DynareBison.cc" // lalr1.cc:847
    break;

  case 218:
#line 579 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_equal_equal((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1343 "DynareBison.cc" // lalr1.cc:847
    break;

  case 219:
#line 581 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_different((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1349 "DynareBison.cc" // lalr1.cc:847
    break;

  case 220:
#line 583 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_uminus((yystack_[0].value.node_val)); }
#line 1355 "DynareBison.cc" // lalr1.cc:847
    break;

  case 221:
#line 585 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = (yystack_[0].value.node_val); }
#line 1361 "DynareBison.cc" // lalr1.cc:847
    break;

  case 222:
#line 587 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_exp((yystack_[1].value.node_val)); }
#line 1367 "DynareBison.cc" // lalr1.cc:847
    break;

  case 223:
#line 589 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_log((yystack_[1].value.node_val)); }
#line 1373 "DynareBison.cc" // lalr1.cc:847
    break;

  case 224:
#line 591 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_log((yystack_[1].value.node_val)); }
#line 1379 "DynareBison.cc" // lalr1.cc:847
    break;

  case 225:
#line 593 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_log10((yystack_[1].value.node_val)); }
#line 1385 "DynareBison.cc" // lalr1.cc:847
    break;

  case 226:
#line 595 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_sin((yystack_[1].value.node_val)); }
#line 1391 "DynareBison.cc" // lalr1.cc:847
    break;

  case 227:
#line 597 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_cos((yystack_[1].value.node_val)); }
#line 1397 "DynareBison.cc" // lalr1.cc:847
    break;

  case 228:
#line 599 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_tan((yystack_[1].value.node_val)); }
#line 1403 "DynareBison.cc" // lalr1.cc:847
    break;

  case 229:
#line 601 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_asin((yystack_[1].value.node_val)); }
#line 1409 "DynareBison.cc" // lalr1.cc:847
    break;

  case 230:
#line 603 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_acos((yystack_[1].value.node_val)); }
#line 1415 "DynareBison.cc" // lalr1.cc:847
    break;

  case 231:
#line 605 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_atan((yystack_[1].value.node_val)); }
#line 1421 "DynareBison.cc" // lalr1.cc:847
    break;

  case 232:
#line 607 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_sqrt((yystack_[1].value.node_val)); }
#line 1427 "DynareBison.cc" // lalr1.cc:847
    break;

  case 233:
#line 609 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_abs((yystack_[1].value.node_val)); }
#line 1433 "DynareBison.cc" // lalr1.cc:847
    break;

  case 234:
#line 611 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_sign((yystack_[1].value.node_val)); }
#line 1439 "DynareBison.cc" // lalr1.cc:847
    break;

  case 235:
#line 613 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_max((yystack_[3].value.node_val), (yystack_[1].value.node_val)); }
#line 1445 "DynareBison.cc" // lalr1.cc:847
    break;

  case 236:
#line 615 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_min((yystack_[3].value.node_val), (yystack_[1].value.node_val)); }
#line 1451 "DynareBison.cc" // lalr1.cc:847
    break;

  case 237:
#line 616 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.push_external_function_arg_vector_onto_stack(); }
#line 1457 "DynareBison.cc" // lalr1.cc:847
    break;

  case 238:
#line 617 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_model_var_or_external_function((yystack_[4].value.string_val), false); }
#line 1463 "DynareBison.cc" // lalr1.cc:847
    break;

  case 239:
#line 619 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_normcdf((yystack_[5].value.node_val), (yystack_[3].value.node_val), (yystack_[1].value.node_val)); }
#line 1469 "DynareBison.cc" // lalr1.cc:847
    break;

  case 240:
#line 621 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_normcdf((yystack_[1].value.node_val)); }
#line 1475 "DynareBison.cc" // lalr1.cc:847
    break;

  case 241:
#line 623 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_normpdf((yystack_[5].value.node_val), (yystack_[3].value.node_val), (yystack_[1].value.node_val)); }
#line 1481 "DynareBison.cc" // lalr1.cc:847
    break;

  case 242:
#line 625 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_normpdf((yystack_[1].value.node_val)); }
#line 1487 "DynareBison.cc" // lalr1.cc:847
    break;

  case 243:
#line 627 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_erf((yystack_[1].value.node_val)); }
#line 1493 "DynareBison.cc" // lalr1.cc:847
    break;

  case 244:
#line 629 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_nan_constant(); }
#line 1499 "DynareBison.cc" // lalr1.cc:847
    break;

  case 245:
#line 631 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_inf_constant(); }
#line 1505 "DynareBison.cc" // lalr1.cc:847
    break;

  case 246:
#line 635 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_external_function_arg((yystack_[0].value.node_val)); }
#line 1511 "DynareBison.cc" // lalr1.cc:847
    break;

  case 247:
#line 637 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_external_function_arg((yystack_[0].value.node_val)); }
#line 1517 "DynareBison.cc" // lalr1.cc:847
    break;

  case 248:
#line 640 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {(yylhs.value.node_val) = driver.add_nan_constant();}
#line 1523 "DynareBison.cc" // lalr1.cc:847
    break;

  case 250:
#line 645 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.end_initval(false); }
#line 1529 "DynareBison.cc" // lalr1.cc:847
    break;

  case 251:
#line 647 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.end_initval(true); }
#line 1535 "DynareBison.cc" // lalr1.cc:847
    break;

  case 252:
#line 651 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.initval_file((yystack_[2].value.string_val)); }
#line 1541 "DynareBison.cc" // lalr1.cc:847
    break;

  case 253:
#line 655 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.end_endval(false); }
#line 1547 "DynareBison.cc" // lalr1.cc:847
    break;

  case 254:
#line 657 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.end_endval(true); }
#line 1553 "DynareBison.cc" // lalr1.cc:847
    break;

  case 257:
#line 664 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.init_val((yystack_[3].value.string_val), (yystack_[1].value.node_val)); }
#line 1559 "DynareBison.cc" // lalr1.cc:847
    break;

  case 258:
#line 667 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.end_histval(false); }
#line 1565 "DynareBison.cc" // lalr1.cc:847
    break;

  case 259:
#line 669 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.end_histval(true); }
#line 1571 "DynareBison.cc" // lalr1.cc:847
    break;

  case 262:
#line 676 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.hist_val((yystack_[6].value.string_val), (yystack_[4].value.string_val), (yystack_[1].value.node_val)); }
#line 1577 "DynareBison.cc" // lalr1.cc:847
    break;

  case 263:
#line 679 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.histval_file((yystack_[2].value.string_val)); }
#line 1583 "DynareBison.cc" // lalr1.cc:847
    break;

  case 264:
#line 682 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.block(); }
#line 1589 "DynareBison.cc" // lalr1.cc:847
    break;

  case 267:
#line 685 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.byte_code(); }
#line 1595 "DynareBison.cc" // lalr1.cc:847
    break;

  case 268:
#line 686 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.use_dll(); }
#line 1601 "DynareBison.cc" // lalr1.cc:847
    break;

  case 269:
#line 687 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.no_static();}
#line 1607 "DynareBison.cc" // lalr1.cc:847
    break;

  case 270:
#line 688 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.differentiate_forward_vars_all(); }
#line 1613 "DynareBison.cc" // lalr1.cc:847
    break;

  case 271:
#line 689 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.differentiate_forward_vars_some(); }
#line 1619 "DynareBison.cc" // lalr1.cc:847
    break;

  case 276:
#line 698 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.begin_model(); }
#line 1625 "DynareBison.cc" // lalr1.cc:847
    break;

  case 277:
#line 699 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.reset_data_tree(); }
#line 1631 "DynareBison.cc" // lalr1.cc:847
    break;

  case 278:
#line 700 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.begin_model(); }
#line 1637 "DynareBison.cc" // lalr1.cc:847
    break;

  case 279:
#line 701 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.reset_data_tree(); }
#line 1643 "DynareBison.cc" // lalr1.cc:847
    break;

  case 284:
#line 711 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_model_equal((yystack_[3].value.node_val), (yystack_[1].value.node_val)); }
#line 1649 "DynareBison.cc" // lalr1.cc:847
    break;

  case 285:
#line 713 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_model_equal_with_zero_rhs((yystack_[1].value.node_val)); }
#line 1655 "DynareBison.cc" // lalr1.cc:847
    break;

  case 286:
#line 715 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_model_equal((yystack_[3].value.node_val), (yystack_[1].value.node_val)); }
#line 1661 "DynareBison.cc" // lalr1.cc:847
    break;

  case 287:
#line 717 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_model_equal_with_zero_rhs((yystack_[1].value.node_val)); }
#line 1667 "DynareBison.cc" // lalr1.cc:847
    break;

  case 290:
#line 725 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_equation_tags((yystack_[2].value.string_val), (yystack_[0].value.string_val)); }
#line 1673 "DynareBison.cc" // lalr1.cc:847
    break;

  case 291:
#line 727 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_equation_tags((yystack_[0].value.string_val), new string()); }
#line 1679 "DynareBison.cc" // lalr1.cc:847
    break;

  case 292:
#line 731 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = (yystack_[1].value.node_val);}
#line 1685 "DynareBison.cc" // lalr1.cc:847
    break;

  case 293:
#line 733 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_model_variable((yystack_[0].value.string_val)); }
#line 1691 "DynareBison.cc" // lalr1.cc:847
    break;

  case 294:
#line 735 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_non_negative_constant((yystack_[0].value.string_val)); }
#line 1697 "DynareBison.cc" // lalr1.cc:847
    break;

  case 295:
#line 737 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_plus((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1703 "DynareBison.cc" // lalr1.cc:847
    break;

  case 296:
#line 739 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_minus((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1709 "DynareBison.cc" // lalr1.cc:847
    break;

  case 297:
#line 741 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_divide((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1715 "DynareBison.cc" // lalr1.cc:847
    break;

  case 298:
#line 743 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_times((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1721 "DynareBison.cc" // lalr1.cc:847
    break;

  case 299:
#line 745 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_less((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1727 "DynareBison.cc" // lalr1.cc:847
    break;

  case 300:
#line 747 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_greater((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1733 "DynareBison.cc" // lalr1.cc:847
    break;

  case 301:
#line 749 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_less_equal((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1739 "DynareBison.cc" // lalr1.cc:847
    break;

  case 302:
#line 751 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_greater_equal((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1745 "DynareBison.cc" // lalr1.cc:847
    break;

  case 303:
#line 753 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_equal_equal((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1751 "DynareBison.cc" // lalr1.cc:847
    break;

  case 304:
#line 755 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_different((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1757 "DynareBison.cc" // lalr1.cc:847
    break;

  case 305:
#line 757 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_power((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1763 "DynareBison.cc" // lalr1.cc:847
    break;

  case 306:
#line 759 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_expectation((yystack_[4].value.string_val), (yystack_[1].value.node_val)); }
#line 1769 "DynareBison.cc" // lalr1.cc:847
    break;

  case 307:
#line 761 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_uminus((yystack_[0].value.node_val)); }
#line 1775 "DynareBison.cc" // lalr1.cc:847
    break;

  case 308:
#line 763 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = (yystack_[0].value.node_val); }
#line 1781 "DynareBison.cc" // lalr1.cc:847
    break;

  case 309:
#line 765 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_exp((yystack_[1].value.node_val)); }
#line 1787 "DynareBison.cc" // lalr1.cc:847
    break;

  case 310:
#line 767 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_log((yystack_[1].value.node_val)); }
#line 1793 "DynareBison.cc" // lalr1.cc:847
    break;

  case 311:
#line 769 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_log((yystack_[1].value.node_val)); }
#line 1799 "DynareBison.cc" // lalr1.cc:847
    break;

  case 312:
#line 771 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_log10((yystack_[1].value.node_val)); }
#line 1805 "DynareBison.cc" // lalr1.cc:847
    break;

  case 313:
#line 773 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_sin((yystack_[1].value.node_val)); }
#line 1811 "DynareBison.cc" // lalr1.cc:847
    break;

  case 314:
#line 775 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_cos((yystack_[1].value.node_val)); }
#line 1817 "DynareBison.cc" // lalr1.cc:847
    break;

  case 315:
#line 777 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_tan((yystack_[1].value.node_val)); }
#line 1823 "DynareBison.cc" // lalr1.cc:847
    break;

  case 316:
#line 779 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_asin((yystack_[1].value.node_val)); }
#line 1829 "DynareBison.cc" // lalr1.cc:847
    break;

  case 317:
#line 781 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_acos((yystack_[1].value.node_val)); }
#line 1835 "DynareBison.cc" // lalr1.cc:847
    break;

  case 318:
#line 783 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_atan((yystack_[1].value.node_val)); }
#line 1841 "DynareBison.cc" // lalr1.cc:847
    break;

  case 319:
#line 785 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_sqrt((yystack_[1].value.node_val)); }
#line 1847 "DynareBison.cc" // lalr1.cc:847
    break;

  case 320:
#line 787 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_abs((yystack_[1].value.node_val)); }
#line 1853 "DynareBison.cc" // lalr1.cc:847
    break;

  case 321:
#line 789 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_sign((yystack_[1].value.node_val)); }
#line 1859 "DynareBison.cc" // lalr1.cc:847
    break;

  case 322:
#line 791 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_max((yystack_[3].value.node_val), (yystack_[1].value.node_val)); }
#line 1865 "DynareBison.cc" // lalr1.cc:847
    break;

  case 323:
#line 793 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_min((yystack_[3].value.node_val), (yystack_[1].value.node_val)); }
#line 1871 "DynareBison.cc" // lalr1.cc:847
    break;

  case 324:
#line 794 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.push_external_function_arg_vector_onto_stack(); }
#line 1877 "DynareBison.cc" // lalr1.cc:847
    break;

  case 325:
#line 795 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_model_var_or_external_function((yystack_[4].value.string_val), true); }
#line 1883 "DynareBison.cc" // lalr1.cc:847
    break;

  case 326:
#line 797 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_normcdf((yystack_[5].value.node_val), (yystack_[3].value.node_val), (yystack_[1].value.node_val)); }
#line 1889 "DynareBison.cc" // lalr1.cc:847
    break;

  case 327:
#line 799 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_normcdf((yystack_[1].value.node_val)); }
#line 1895 "DynareBison.cc" // lalr1.cc:847
    break;

  case 328:
#line 801 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_normpdf((yystack_[5].value.node_val), (yystack_[3].value.node_val), (yystack_[1].value.node_val)); }
#line 1901 "DynareBison.cc" // lalr1.cc:847
    break;

  case 329:
#line 803 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_normpdf((yystack_[1].value.node_val)); }
#line 1907 "DynareBison.cc" // lalr1.cc:847
    break;

  case 330:
#line 805 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_erf((yystack_[1].value.node_val)); }
#line 1913 "DynareBison.cc" // lalr1.cc:847
    break;

  case 331:
#line 807 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.node_val) = driver.add_steady_state((yystack_[1].value.node_val)); }
#line 1919 "DynareBison.cc" // lalr1.cc:847
    break;

  case 332:
#line 811 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_external_function_arg((yystack_[0].value.node_val)); }
#line 1925 "DynareBison.cc" // lalr1.cc:847
    break;

  case 333:
#line 813 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_external_function_arg((yystack_[0].value.node_val)); }
#line 1931 "DynareBison.cc" // lalr1.cc:847
    break;

  case 334:
#line 817 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_and_init_model_local_variable((yystack_[3].value.string_val), (yystack_[1].value.node_val)); }
#line 1937 "DynareBison.cc" // lalr1.cc:847
    break;

  case 335:
#line 819 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.end_shocks(false); }
#line 1943 "DynareBison.cc" // lalr1.cc:847
    break;

  case 336:
#line 820 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.end_shocks(true); }
#line 1949 "DynareBison.cc" // lalr1.cc:847
    break;

  case 340:
#line 829 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_stderr_shock((yystack_[4].value.string_val), (yystack_[1].value.node_val)); }
#line 1955 "DynareBison.cc" // lalr1.cc:847
    break;

  case 341:
#line 831 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_var_shock((yystack_[3].value.string_val), (yystack_[1].value.node_val)); }
#line 1961 "DynareBison.cc" // lalr1.cc:847
    break;

  case 342:
#line 833 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_covar_shock((yystack_[5].value.string_val), (yystack_[3].value.string_val), (yystack_[1].value.node_val)); }
#line 1967 "DynareBison.cc" // lalr1.cc:847
    break;

  case 343:
#line 835 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_correl_shock((yystack_[5].value.string_val), (yystack_[3].value.string_val), (yystack_[1].value.node_val)); }
#line 1973 "DynareBison.cc" // lalr1.cc:847
    break;

  case 344:
#line 839 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_det_shock((yystack_[7].value.string_val), false); }
#line 1979 "DynareBison.cc" // lalr1.cc:847
    break;

  case 345:
#line 842 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.begin_svar_identification();}
#line 1985 "DynareBison.cc" // lalr1.cc:847
    break;

  case 346:
#line 843 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.end_svar_identification(); }
#line 1991 "DynareBison.cc" // lalr1.cc:847
    break;

  case 349:
#line 851 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.combine_lag_and_restriction((yystack_[2].value.string_val)); }
#line 1997 "DynareBison.cc" // lalr1.cc:847
    break;

  case 350:
#line 853 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_constants_exclusion(); }
#line 2003 "DynareBison.cc" // lalr1.cc:847
    break;

  case 351:
#line 855 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_restriction_equation_nbr((yystack_[1].value.string_val));}
#line 2009 "DynareBison.cc" // lalr1.cc:847
    break;

  case 352:
#line 857 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.add_restriction_equal();}
#line 2015 "DynareBison.cc" // lalr1.cc:847
    break;

  case 354:
#line 860 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_upper_cholesky(); }
#line 2021 "DynareBison.cc" // lalr1.cc:847
    break;

  case 355:
#line 862 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_lower_cholesky(); }
#line 2027 "DynareBison.cc" // lalr1.cc:847
    break;

  case 356:
#line 866 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_restriction_in_equation((yystack_[3].value.string_val)); }
#line 2033 "DynareBison.cc" // lalr1.cc:847
    break;

  case 357:
#line 868 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_restriction_in_equation((yystack_[3].value.string_val)); }
#line 2039 "DynareBison.cc" // lalr1.cc:847
    break;

  case 358:
#line 872 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_in_svar_restriction_symbols((yystack_[0].value.string_val)); }
#line 2045 "DynareBison.cc" // lalr1.cc:847
    break;

  case 359:
#line 874 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_in_svar_restriction_symbols((yystack_[0].value.string_val)); }
#line 2051 "DynareBison.cc" // lalr1.cc:847
    break;

  case 360:
#line 877 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.check_restriction_expression_constant((yystack_[0].value.node_val));}
#line 2057 "DynareBison.cc" // lalr1.cc:847
    break;

  case 364:
#line 886 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_positive_restriction_element((yystack_[3].value.string_val),(yystack_[1].value.string_val));}
#line 2063 "DynareBison.cc" // lalr1.cc:847
    break;

  case 365:
#line 888 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_positive_restriction_element((yystack_[3].value.string_val),(yystack_[1].value.string_val));}
#line 2069 "DynareBison.cc" // lalr1.cc:847
    break;

  case 366:
#line 890 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_negative_restriction_element((yystack_[3].value.string_val),(yystack_[1].value.string_val));}
#line 2075 "DynareBison.cc" // lalr1.cc:847
    break;

  case 367:
#line 892 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_positive_restriction_element((yystack_[7].value.node_val),(yystack_[3].value.string_val),(yystack_[1].value.string_val));}
#line 2081 "DynareBison.cc" // lalr1.cc:847
    break;

  case 368:
#line 896 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_svar_global_identification_check(); }
#line 2087 "DynareBison.cc" // lalr1.cc:847
    break;

  case 369:
#line 900 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.markov_switching(); }
#line 2093 "DynareBison.cc" // lalr1.cc:847
    break;

  case 378:
#line 916 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.svar(); }
#line 2099 "DynareBison.cc" // lalr1.cc:847
    break;

  case 385:
#line 929 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.end_mshocks(false); }
#line 2105 "DynareBison.cc" // lalr1.cc:847
    break;

  case 386:
#line 930 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.end_mshocks(true); }
#line 2111 "DynareBison.cc" // lalr1.cc:847
    break;

  case 389:
#line 938 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_period((yystack_[0].value.string_val)); }
#line 2117 "DynareBison.cc" // lalr1.cc:847
    break;

  case 390:
#line 940 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_period((yystack_[0].value.string_val)); }
#line 2123 "DynareBison.cc" // lalr1.cc:847
    break;

  case 391:
#line 942 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_period((yystack_[2].value.string_val), (yystack_[0].value.string_val)); }
#line 2129 "DynareBison.cc" // lalr1.cc:847
    break;

  case 392:
#line 944 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_period((yystack_[2].value.string_val), (yystack_[0].value.string_val)); }
#line 2135 "DynareBison.cc" // lalr1.cc:847
    break;

  case 393:
#line 946 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_period((yystack_[2].value.string_val), (yystack_[0].value.string_val)); }
#line 2141 "DynareBison.cc" // lalr1.cc:847
    break;

  case 394:
#line 948 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_period((yystack_[0].value.string_val)); }
#line 2147 "DynareBison.cc" // lalr1.cc:847
    break;

  case 395:
#line 951 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.do_sigma_e(); }
#line 2153 "DynareBison.cc" // lalr1.cc:847
    break;

  case 396:
#line 954 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_value((yystack_[1].value.node_val)); }
#line 2159 "DynareBison.cc" // lalr1.cc:847
    break;

  case 397:
#line 956 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_value((yystack_[1].value.node_val)); }
#line 2165 "DynareBison.cc" // lalr1.cc:847
    break;

  case 398:
#line 958 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_value((yystack_[1].value.node_val)); }
#line 2171 "DynareBison.cc" // lalr1.cc:847
    break;

  case 399:
#line 960 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_value((yystack_[0].value.string_val)); }
#line 2177 "DynareBison.cc" // lalr1.cc:847
    break;

  case 400:
#line 962 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_value((yystack_[0].value.string_val)); }
#line 2183 "DynareBison.cc" // lalr1.cc:847
    break;

  case 401:
#line 964 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_value((yystack_[0].value.string_val)); }
#line 2189 "DynareBison.cc" // lalr1.cc:847
    break;

  case 402:
#line 968 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.end_of_row(); }
#line 2195 "DynareBison.cc" // lalr1.cc:847
    break;

  case 403:
#line 970 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.end_of_row(); }
#line 2201 "DynareBison.cc" // lalr1.cc:847
    break;

  case 404:
#line 974 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_to_row((yystack_[1].value.node_val)); }
#line 2207 "DynareBison.cc" // lalr1.cc:847
    break;

  case 405:
#line 976 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_to_row_const((yystack_[0].value.string_val)); }
#line 2213 "DynareBison.cc" // lalr1.cc:847
    break;

  case 406:
#line 978 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_to_row((yystack_[1].value.node_val)); }
#line 2219 "DynareBison.cc" // lalr1.cc:847
    break;

  case 407:
#line 980 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_to_row_const((yystack_[0].value.string_val)); }
#line 2225 "DynareBison.cc" // lalr1.cc:847
    break;

  case 408:
#line 982 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_to_row((yystack_[1].value.node_val)); }
#line 2231 "DynareBison.cc" // lalr1.cc:847
    break;

  case 409:
#line 984 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_to_row_const((yystack_[0].value.string_val)); }
#line 2237 "DynareBison.cc" // lalr1.cc:847
    break;

  case 410:
#line 988 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.steady(); }
#line 2243 "DynareBison.cc" // lalr1.cc:847
    break;

  case 411:
#line 990 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.steady(); }
#line 2249 "DynareBison.cc" // lalr1.cc:847
    break;

  case 422:
#line 1008 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.check(); }
#line 2255 "DynareBison.cc" // lalr1.cc:847
    break;

  case 423:
#line 1010 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.check(); }
#line 2261 "DynareBison.cc" // lalr1.cc:847
    break;

  case 428:
#line 1022 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.model_info(); }
#line 2267 "DynareBison.cc" // lalr1.cc:847
    break;

  case 429:
#line 1024 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.model_info(); }
#line 2273 "DynareBison.cc" // lalr1.cc:847
    break;

  case 433:
#line 1033 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.perfect_foresight_setup(); }
#line 2279 "DynareBison.cc" // lalr1.cc:847
    break;

  case 434:
#line 1035 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.perfect_foresight_setup(); }
#line 2285 "DynareBison.cc" // lalr1.cc:847
    break;

  case 439:
#line 1047 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.perfect_foresight_solver(); }
#line 2291 "DynareBison.cc" // lalr1.cc:847
    break;

  case 440:
#line 1049 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.perfect_foresight_solver(); }
#line 2297 "DynareBison.cc" // lalr1.cc:847
    break;

  case 455:
#line 1071 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.prior_posterior_function(true); }
#line 2303 "DynareBison.cc" // lalr1.cc:847
    break;

  case 456:
#line 1075 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.prior_posterior_function(false); }
#line 2309 "DynareBison.cc" // lalr1.cc:847
    break;

  case 461:
#line 1087 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.simul(); }
#line 2315 "DynareBison.cc" // lalr1.cc:847
    break;

  case 462:
#line 1089 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.simul(); }
#line 2321 "DynareBison.cc" // lalr1.cc:847
    break;

  case 467:
#line 1101 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.external_function(); }
#line 2327 "DynareBison.cc" // lalr1.cc:847
    break;

  case 474:
#line 1115 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.stoch_simul(); }
#line 2333 "DynareBison.cc" // lalr1.cc:847
    break;

  case 475:
#line 1117 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.stoch_simul(); }
#line 2339 "DynareBison.cc" // lalr1.cc:847
    break;

  case 476:
#line 1119 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.stoch_simul(); }
#line 2345 "DynareBison.cc" // lalr1.cc:847
    break;

  case 477:
#line 1121 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.stoch_simul(); }
#line 2351 "DynareBison.cc" // lalr1.cc:847
    break;

  case 528:
#line 1181 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_in_symbol_list((yystack_[0].value.string_val)); }
#line 2357 "DynareBison.cc" // lalr1.cc:847
    break;

  case 529:
#line 1183 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_in_symbol_list((yystack_[0].value.string_val)); }
#line 2363 "DynareBison.cc" // lalr1.cc:847
    break;

  case 530:
#line 1185 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_in_symbol_list((yystack_[0].value.string_val)); }
#line 2369 "DynareBison.cc" // lalr1.cc:847
    break;

  case 532:
#line 1190 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                    string *colon = new string(":");
                    driver.add_in_symbol_list(colon);
                  }
#line 2378 "DynareBison.cc" // lalr1.cc:847
    break;

  case 533:
#line 1197 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 2384 "DynareBison.cc" // lalr1.cc:847
    break;

  case 534:
#line 1199 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yystack_[0].value.string_val)->insert(0, "-"); (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 2390 "DynareBison.cc" // lalr1.cc:847
    break;

  case 538:
#line 1208 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 2396 "DynareBison.cc" // lalr1.cc:847
    break;

  case 539:
#line 1210 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yystack_[0].value.string_val)->insert(0, "-"); (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 2402 "DynareBison.cc" // lalr1.cc:847
    break;

  case 541:
#line 1215 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.string_val) = new string ("Inf"); }
#line 2408 "DynareBison.cc" // lalr1.cc:847
    break;

  case 542:
#line 1217 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.string_val) = new string ("-Inf"); }
#line 2414 "DynareBison.cc" // lalr1.cc:847
    break;

  case 543:
#line 1219 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.string_val) = new string ("Inf"); }
#line 2420 "DynareBison.cc" // lalr1.cc:847
    break;

  case 546:
#line 1226 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.estimated_params(); }
#line 2426 "DynareBison.cc" // lalr1.cc:847
    break;

  case 547:
#line 1229 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_estimated_params_element(); }
#line 2432 "DynareBison.cc" // lalr1.cc:847
    break;

  case 548:
#line 1231 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_estimated_params_element(); }
#line 2438 "DynareBison.cc" // lalr1.cc:847
    break;

  case 551:
#line 1238 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                    driver.estim_params.type = 1;
                    driver.estim_params.name = *(yystack_[0].value.string_val);
                    delete (yystack_[0].value.string_val);
                  }
#line 2448 "DynareBison.cc" // lalr1.cc:847
    break;

  case 552:
#line 1244 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                    driver.estim_params.type = 2;
                    driver.estim_params.name = *(yystack_[0].value.string_val);
                    delete (yystack_[0].value.string_val);
                  }
#line 2458 "DynareBison.cc" // lalr1.cc:847
    break;

  case 553:
#line 1250 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                    driver.estim_params.type = 3;
                    driver.estim_params.name = *(yystack_[2].value.string_val);
                    driver.estim_params.name2 = *(yystack_[0].value.string_val);
                    delete (yystack_[2].value.string_val);
                    delete (yystack_[0].value.string_val);
                  }
#line 2470 "DynareBison.cc" // lalr1.cc:847
    break;

  case 554:
#line 1258 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                    driver.estim_params.type = 2;
                    driver.estim_params.name = "dsge_prior_weight";
                  }
#line 2479 "DynareBison.cc" // lalr1.cc:847
    break;

  case 555:
#line 1265 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                    driver.estim_params.prior = (yystack_[2].value.prior_distributions_val);
                  }
#line 2487 "DynareBison.cc" // lalr1.cc:847
    break;

  case 556:
#line 1269 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                    driver.estim_params.init_val = (yystack_[4].value.node_val);
                    driver.estim_params.prior = (yystack_[2].value.prior_distributions_val);
                  }
#line 2496 "DynareBison.cc" // lalr1.cc:847
    break;

  case 557:
#line 1274 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                    driver.estim_params.init_val = (yystack_[8].value.node_val);
                    driver.estim_params.low_bound = (yystack_[6].value.node_val);
                    driver.estim_params.up_bound = (yystack_[4].value.node_val);
                    driver.estim_params.prior = (yystack_[2].value.prior_distributions_val);
                  }
#line 2507 "DynareBison.cc" // lalr1.cc:847
    break;

  case 558:
#line 1281 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                    driver.estim_params.init_val = (yystack_[0].value.node_val);
                  }
#line 2515 "DynareBison.cc" // lalr1.cc:847
    break;

  case 559:
#line 1285 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                    driver.estim_params.init_val = (yystack_[4].value.node_val);
                    driver.estim_params.low_bound = (yystack_[2].value.node_val);
                    driver.estim_params.up_bound = (yystack_[0].value.node_val);
                  }
#line 2525 "DynareBison.cc" // lalr1.cc:847
    break;

  case 560:
#line 1293 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                    driver.estim_params.mean = (yystack_[2].value.node_val);
                    driver.estim_params.std = (yystack_[0].value.node_val);
                  }
#line 2534 "DynareBison.cc" // lalr1.cc:847
    break;

  case 561:
#line 1298 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                    driver.estim_params.mean = (yystack_[4].value.node_val);
                    driver.estim_params.std = (yystack_[2].value.node_val);
                    driver.estim_params.p3 = (yystack_[0].value.node_val);
                  }
#line 2544 "DynareBison.cc" // lalr1.cc:847
    break;

  case 562:
#line 1304 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                    driver.estim_params.mean = (yystack_[6].value.node_val);
                    driver.estim_params.std = (yystack_[4].value.node_val);
                    driver.estim_params.p3 = (yystack_[2].value.node_val);
                    driver.estim_params.p4 = (yystack_[0].value.node_val);
                  }
#line 2555 "DynareBison.cc" // lalr1.cc:847
    break;

  case 563:
#line 1311 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                    driver.estim_params.mean = (yystack_[8].value.node_val);
                    driver.estim_params.std = (yystack_[6].value.node_val);
                    driver.estim_params.p3 = (yystack_[4].value.node_val);
                    driver.estim_params.p4 = (yystack_[2].value.node_val);
                    driver.estim_params.jscale = (yystack_[0].value.node_val);
                  }
#line 2567 "DynareBison.cc" // lalr1.cc:847
    break;

  case 564:
#line 1321 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.estimated_params_init(); }
#line 2573 "DynareBison.cc" // lalr1.cc:847
    break;

  case 565:
#line 1323 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.estimated_params_init(true); }
#line 2579 "DynareBison.cc" // lalr1.cc:847
    break;

  case 566:
#line 1325 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.estimated_params_init(true); }
#line 2585 "DynareBison.cc" // lalr1.cc:847
    break;

  case 567:
#line 1329 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_estimated_params_element(); }
#line 2591 "DynareBison.cc" // lalr1.cc:847
    break;

  case 568:
#line 1331 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_estimated_params_element(); }
#line 2597 "DynareBison.cc" // lalr1.cc:847
    break;

  case 569:
#line 1335 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                        driver.estim_params.type = 1;
                        driver.estim_params.name = *(yystack_[3].value.string_val);
                        driver.estim_params.init_val = (yystack_[1].value.node_val);
                        delete (yystack_[3].value.string_val);
                      }
#line 2608 "DynareBison.cc" // lalr1.cc:847
    break;

  case 570:
#line 1342 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                        driver.estim_params.type = 3;
                        driver.estim_params.name = *(yystack_[5].value.string_val);
                        driver.estim_params.name2 = *(yystack_[3].value.string_val);
                        driver.estim_params.init_val = (yystack_[1].value.node_val);
                        delete (yystack_[5].value.string_val);
                        delete (yystack_[3].value.string_val);
                      }
#line 2621 "DynareBison.cc" // lalr1.cc:847
    break;

  case 571:
#line 1351 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                        driver.estim_params.type = 2;
                        driver.estim_params.name = *(yystack_[3].value.string_val);
                        driver.estim_params.init_val = (yystack_[1].value.node_val);
                        delete (yystack_[3].value.string_val);
                      }
#line 2632 "DynareBison.cc" // lalr1.cc:847
    break;

  case 572:
#line 1360 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.estimated_params_bounds(); }
#line 2638 "DynareBison.cc" // lalr1.cc:847
    break;

  case 573:
#line 1363 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_estimated_params_element(); }
#line 2644 "DynareBison.cc" // lalr1.cc:847
    break;

  case 574:
#line 1365 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_estimated_params_element(); }
#line 2650 "DynareBison.cc" // lalr1.cc:847
    break;

  case 575:
#line 1369 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                          driver.estim_params.type = 1;
                          driver.estim_params.name = *(yystack_[5].value.string_val);
                          driver.estim_params.low_bound = (yystack_[3].value.node_val);
                          driver.estim_params.up_bound = (yystack_[1].value.node_val);
                          delete (yystack_[5].value.string_val);
                        }
#line 2662 "DynareBison.cc" // lalr1.cc:847
    break;

  case 576:
#line 1377 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                          driver.estim_params.type = 3;
                          driver.estim_params.name = *(yystack_[7].value.string_val);
                          driver.estim_params.name2 = *(yystack_[5].value.string_val);
                          driver.estim_params.low_bound = (yystack_[3].value.node_val);
                          driver.estim_params.up_bound = (yystack_[1].value.node_val);
                          delete (yystack_[7].value.string_val);
                          delete (yystack_[5].value.string_val);
                        }
#line 2676 "DynareBison.cc" // lalr1.cc:847
    break;

  case 577:
#line 1387 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                          driver.estim_params.type = 2;
                          driver.estim_params.name = *(yystack_[5].value.string_val);
                          driver.estim_params.low_bound = (yystack_[3].value.node_val);
                          driver.estim_params.up_bound = (yystack_[1].value.node_val);
                          delete (yystack_[5].value.string_val);
                        }
#line 2688 "DynareBison.cc" // lalr1.cc:847
    break;

  case 578:
#line 1397 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.osr_params_bounds(); }
#line 2694 "DynareBison.cc" // lalr1.cc:847
    break;

  case 579:
#line 1400 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_osr_params_element(); }
#line 2700 "DynareBison.cc" // lalr1.cc:847
    break;

  case 580:
#line 1402 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_osr_params_element(); }
#line 2706 "DynareBison.cc" // lalr1.cc:847
    break;

  case 581:
#line 1406 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                    driver.osr_params.name = *(yystack_[5].value.string_val);
                    driver.osr_params.low_bound = (yystack_[3].value.node_val);
                    driver.osr_params.up_bound = (yystack_[1].value.node_val);
                    delete (yystack_[5].value.string_val);
                  }
#line 2717 "DynareBison.cc" // lalr1.cc:847
    break;

  case 582:
#line 1415 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.prior_distributions_val) = eBeta; }
#line 2723 "DynareBison.cc" // lalr1.cc:847
    break;

  case 583:
#line 1417 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.prior_distributions_val) = eGamma; }
#line 2729 "DynareBison.cc" // lalr1.cc:847
    break;

  case 584:
#line 1419 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.prior_distributions_val) = eNormal; }
#line 2735 "DynareBison.cc" // lalr1.cc:847
    break;

  case 585:
#line 1421 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.prior_distributions_val) = eInvGamma; }
#line 2741 "DynareBison.cc" // lalr1.cc:847
    break;

  case 586:
#line 1423 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.prior_distributions_val) = eInvGamma1; }
#line 2747 "DynareBison.cc" // lalr1.cc:847
    break;

  case 587:
#line 1425 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.prior_distributions_val) = eUniform; }
#line 2753 "DynareBison.cc" // lalr1.cc:847
    break;

  case 588:
#line 1427 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.prior_distributions_val) = eInvGamma2; }
#line 2759 "DynareBison.cc" // lalr1.cc:847
    break;

  case 589:
#line 1429 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.prior_distributions_val) = eDirichlet; }
#line 2765 "DynareBison.cc" // lalr1.cc:847
    break;

  case 590:
#line 1431 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.prior_distributions_val) = eWeibull; }
#line 2771 "DynareBison.cc" // lalr1.cc:847
    break;

  case 591:
#line 1435 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.prior_distributions_val) = eBeta; }
#line 2777 "DynareBison.cc" // lalr1.cc:847
    break;

  case 592:
#line 1437 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.prior_distributions_val) = eGamma; }
#line 2783 "DynareBison.cc" // lalr1.cc:847
    break;

  case 593:
#line 1439 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.prior_distributions_val) = eNormal; }
#line 2789 "DynareBison.cc" // lalr1.cc:847
    break;

  case 594:
#line 1441 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.prior_distributions_val) = eInvGamma; }
#line 2795 "DynareBison.cc" // lalr1.cc:847
    break;

  case 595:
#line 1443 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.prior_distributions_val) = eInvGamma1; }
#line 2801 "DynareBison.cc" // lalr1.cc:847
    break;

  case 596:
#line 1445 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.prior_distributions_val) = eUniform; }
#line 2807 "DynareBison.cc" // lalr1.cc:847
    break;

  case 597:
#line 1447 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.prior_distributions_val) = eInvGamma2; }
#line 2813 "DynareBison.cc" // lalr1.cc:847
    break;

  case 598:
#line 1449 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.prior_distributions_val) = eWeibull; }
#line 2819 "DynareBison.cc" // lalr1.cc:847
    break;

  case 599:
#line 1452 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 2825 "DynareBison.cc" // lalr1.cc:847
    break;

  case 600:
#line 1455 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 2831 "DynareBison.cc" // lalr1.cc:847
    break;

  case 601:
#line 1457 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.string_val) = (yystack_[2].value.string_val); (yylhs.value.string_val)->append("+").append(*(yystack_[0].value.string_val)); }
#line 2837 "DynareBison.cc" // lalr1.cc:847
    break;

  case 602:
#line 1461 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.set_time((yystack_[2].value.string_val)); }
#line 2843 "DynareBison.cc" // lalr1.cc:847
    break;

  case 603:
#line 1465 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.estimation_data(); }
#line 2849 "DynareBison.cc" // lalr1.cc:847
    break;

  case 613:
#line 1482 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.set_subsamples((yystack_[4].value.vector_string_val)->at(0), (yystack_[4].value.vector_string_val)->at(1)); }
#line 2855 "DynareBison.cc" // lalr1.cc:847
    break;

  case 614:
#line 1486 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                  driver.copy_subsamples((yystack_[3].value.vector_string_val)->at(0), (yystack_[3].value.vector_string_val)->at(1), (yystack_[1].value.vector_string_val)->at(0), (yystack_[1].value.vector_string_val)->at(1));
                  delete (yystack_[3].value.vector_string_val);
                  delete (yystack_[1].value.vector_string_val);
                }
#line 2865 "DynareBison.cc" // lalr1.cc:847
    break;

  case 615:
#line 1494 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                      (yylhs.value.vector_string_val) = new vector<string *>();
                      (yylhs.value.vector_string_val)->push_back((yystack_[2].value.string_val));
                      (yylhs.value.vector_string_val)->push_back(new string (""));
                    }
#line 2875 "DynareBison.cc" // lalr1.cc:847
    break;

  case 616:
#line 1500 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                      (yylhs.value.vector_string_val) = new vector<string *>();
                      (yylhs.value.vector_string_val)->push_back((yystack_[3].value.string_val));
                      (yylhs.value.vector_string_val)->push_back(new string (""));
                    }
#line 2885 "DynareBison.cc" // lalr1.cc:847
    break;

  case 617:
#line 1506 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                      (yylhs.value.vector_string_val) = new vector<string *>();
                      (yylhs.value.vector_string_val)->push_back((yystack_[5].value.string_val));
                      (yylhs.value.vector_string_val)->push_back((yystack_[3].value.string_val));
                    }
#line 2895 "DynareBison.cc" // lalr1.cc:847
    break;

  case 620:
#line 1517 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.set_prior_variance(); driver.prior_shape = eNoShape; }
#line 2901 "DynareBison.cc" // lalr1.cc:847
    break;

  case 621:
#line 1518 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.set_prior((yystack_[7].value.string_val), new string ("")); }
#line 2907 "DynareBison.cc" // lalr1.cc:847
    break;

  case 622:
#line 1519 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.set_prior_variance(); driver.prior_shape = eNoShape; }
#line 2913 "DynareBison.cc" // lalr1.cc:847
    break;

  case 623:
#line 1520 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.set_prior((yystack_[9].value.string_val), (yystack_[7].value.string_val)); }
#line 2919 "DynareBison.cc" // lalr1.cc:847
    break;

  case 624:
#line 1521 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.set_prior_variance(); driver.prior_shape = eNoShape; }
#line 2925 "DynareBison.cc" // lalr1.cc:847
    break;

  case 625:
#line 1522 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.set_joint_prior((yystack_[7].value.vector_string_val)); }
#line 2931 "DynareBison.cc" // lalr1.cc:847
    break;

  case 626:
#line 1523 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.set_prior_variance(); driver.prior_shape = eNoShape; }
#line 2937 "DynareBison.cc" // lalr1.cc:847
    break;

  case 627:
#line 1524 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.set_std_prior((yystack_[8].value.string_val), new string ("")); }
#line 2943 "DynareBison.cc" // lalr1.cc:847
    break;

  case 628:
#line 1525 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.set_prior_variance(); driver.prior_shape = eNoShape; }
#line 2949 "DynareBison.cc" // lalr1.cc:847
    break;

  case 629:
#line 1526 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.set_std_prior((yystack_[10].value.string_val), (yystack_[7].value.string_val)); }
#line 2955 "DynareBison.cc" // lalr1.cc:847
    break;

  case 630:
#line 1527 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.set_prior_variance(); driver.prior_shape = eNoShape; }
#line 2961 "DynareBison.cc" // lalr1.cc:847
    break;

  case 631:
#line 1528 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.set_corr_prior((yystack_[10].value.string_val), (yystack_[8].value.string_val), new string ("")); }
#line 2967 "DynareBison.cc" // lalr1.cc:847
    break;

  case 632:
#line 1529 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.set_prior_variance(); driver.prior_shape = eNoShape; }
#line 2973 "DynareBison.cc" // lalr1.cc:847
    break;

  case 633:
#line 1530 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.set_corr_prior((yystack_[12].value.string_val), (yystack_[10].value.string_val), (yystack_[7].value.string_val)); }
#line 2979 "DynareBison.cc" // lalr1.cc:847
    break;

  case 658:
#line 1566 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
             driver.copy_prior((yystack_[3].value.vector_string_val)->at(0), (yystack_[3].value.vector_string_val)->at(1), (yystack_[3].value.vector_string_val)->at(2), (yystack_[3].value.vector_string_val)->at(3),
                               (yystack_[1].value.vector_string_val)->at(0), (yystack_[1].value.vector_string_val)->at(1), (yystack_[1].value.vector_string_val)->at(2), (yystack_[1].value.vector_string_val)->at(3));
             delete (yystack_[3].value.vector_string_val);
             delete (yystack_[1].value.vector_string_val);
           }
#line 2990 "DynareBison.cc" // lalr1.cc:847
    break;

  case 659:
#line 1575 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                 (yylhs.value.vector_string_val) = new vector<string *>();
                 (yylhs.value.vector_string_val)->push_back(new string ("par"));
                 (yylhs.value.vector_string_val)->push_back((yystack_[2].value.string_val));
                 (yylhs.value.vector_string_val)->push_back(new string (""));
                 (yylhs.value.vector_string_val)->push_back(new string (""));
               }
#line 3002 "DynareBison.cc" // lalr1.cc:847
    break;

  case 660:
#line 1583 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                 (yylhs.value.vector_string_val) = new vector<string *>();
                 (yylhs.value.vector_string_val)->push_back(new string ("par"));
                 (yylhs.value.vector_string_val)->push_back((yystack_[4].value.string_val));
                 (yylhs.value.vector_string_val)->push_back(new string (""));
                 (yylhs.value.vector_string_val)->push_back((yystack_[2].value.string_val));
               }
#line 3014 "DynareBison.cc" // lalr1.cc:847
    break;

  case 661:
#line 1591 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                 (yylhs.value.vector_string_val) = new vector<string *>();
                 (yylhs.value.vector_string_val)->push_back(new string ("std"));
                 (yylhs.value.vector_string_val)->push_back((yystack_[3].value.string_val));
                 (yylhs.value.vector_string_val)->push_back(new string (""));
                 (yylhs.value.vector_string_val)->push_back(new string (""));
               }
#line 3026 "DynareBison.cc" // lalr1.cc:847
    break;

  case 662:
#line 1599 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                 (yylhs.value.vector_string_val) = new vector<string *>();
                 (yylhs.value.vector_string_val)->push_back(new string ("std"));
                 (yylhs.value.vector_string_val)->push_back((yystack_[5].value.string_val));
                 (yylhs.value.vector_string_val)->push_back(new string (""));
                 (yylhs.value.vector_string_val)->push_back((yystack_[2].value.string_val));
               }
#line 3038 "DynareBison.cc" // lalr1.cc:847
    break;

  case 663:
#line 1607 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                 (yylhs.value.vector_string_val) = new vector<string *>();
                 (yylhs.value.vector_string_val)->push_back(new string ("corr"));
                 (yylhs.value.vector_string_val)->push_back((yystack_[5].value.string_val));
                 (yylhs.value.vector_string_val)->push_back((yystack_[3].value.string_val));
                 (yylhs.value.vector_string_val)->push_back(new string (""));
               }
#line 3050 "DynareBison.cc" // lalr1.cc:847
    break;

  case 664:
#line 1615 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                 (yylhs.value.vector_string_val) = new vector<string *>();
                 (yylhs.value.vector_string_val)->push_back(new string ("corr"));
                 (yylhs.value.vector_string_val)->push_back((yystack_[7].value.string_val));
                 (yylhs.value.vector_string_val)->push_back((yystack_[5].value.string_val));
                 (yylhs.value.vector_string_val)->push_back((yystack_[2].value.string_val));
               }
#line 3062 "DynareBison.cc" // lalr1.cc:847
    break;

  case 665:
#line 1625 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.set_options((yystack_[6].value.string_val), new string ("")); }
#line 3068 "DynareBison.cc" // lalr1.cc:847
    break;

  case 666:
#line 1627 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.set_options((yystack_[8].value.string_val), (yystack_[6].value.string_val)); }
#line 3074 "DynareBison.cc" // lalr1.cc:847
    break;

  case 667:
#line 1629 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.set_std_options((yystack_[7].value.string_val), new string ("")); }
#line 3080 "DynareBison.cc" // lalr1.cc:847
    break;

  case 668:
#line 1631 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.set_std_options((yystack_[9].value.string_val), (yystack_[6].value.string_val)); }
#line 3086 "DynareBison.cc" // lalr1.cc:847
    break;

  case 669:
#line 1633 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.set_corr_options((yystack_[9].value.string_val), (yystack_[7].value.string_val), new string ("")); }
#line 3092 "DynareBison.cc" // lalr1.cc:847
    break;

  case 670:
#line 1635 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.set_corr_options((yystack_[11].value.string_val), (yystack_[9].value.string_val), (yystack_[6].value.string_val)); }
#line 3098 "DynareBison.cc" // lalr1.cc:847
    break;

  case 676:
#line 1648 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
               driver.copy_options((yystack_[3].value.vector_string_val)->at(0), (yystack_[3].value.vector_string_val)->at(1), (yystack_[3].value.vector_string_val)->at(2), (yystack_[3].value.vector_string_val)->at(3),
                                   (yystack_[1].value.vector_string_val)->at(0), (yystack_[1].value.vector_string_val)->at(1), (yystack_[1].value.vector_string_val)->at(2), (yystack_[1].value.vector_string_val)->at(3));
               delete (yystack_[3].value.vector_string_val);
               delete (yystack_[1].value.vector_string_val);
             }
#line 3109 "DynareBison.cc" // lalr1.cc:847
    break;

  case 677:
#line 1657 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                   (yylhs.value.vector_string_val) = new vector<string *>();
                   (yylhs.value.vector_string_val)->push_back(new string ("par"));
                   (yylhs.value.vector_string_val)->push_back((yystack_[2].value.string_val));
                   (yylhs.value.vector_string_val)->push_back(new string (""));
                   (yylhs.value.vector_string_val)->push_back(new string (""));
                 }
#line 3121 "DynareBison.cc" // lalr1.cc:847
    break;

  case 678:
#line 1665 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                   (yylhs.value.vector_string_val) = new vector<string *>();
                   (yylhs.value.vector_string_val)->push_back(new string ("par"));
                   (yylhs.value.vector_string_val)->push_back((yystack_[4].value.string_val));
                   (yylhs.value.vector_string_val)->push_back(new string (""));
                   (yylhs.value.vector_string_val)->push_back((yystack_[2].value.string_val));
                 }
#line 3133 "DynareBison.cc" // lalr1.cc:847
    break;

  case 679:
#line 1673 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                   (yylhs.value.vector_string_val) = new vector<string *>();
                   (yylhs.value.vector_string_val)->push_back(new string ("std"));
                   (yylhs.value.vector_string_val)->push_back((yystack_[3].value.string_val));
                   (yylhs.value.vector_string_val)->push_back(new string (""));
                   (yylhs.value.vector_string_val)->push_back(new string (""));
                 }
#line 3145 "DynareBison.cc" // lalr1.cc:847
    break;

  case 680:
#line 1681 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                   (yylhs.value.vector_string_val) = new vector<string *>();
                   (yylhs.value.vector_string_val)->push_back(new string ("std"));
                   (yylhs.value.vector_string_val)->push_back((yystack_[5].value.string_val));
                   (yylhs.value.vector_string_val)->push_back(new string (""));
                   (yylhs.value.vector_string_val)->push_back((yystack_[2].value.string_val));
                 }
#line 3157 "DynareBison.cc" // lalr1.cc:847
    break;

  case 681:
#line 1689 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                   (yylhs.value.vector_string_val) = new vector<string *>();
                   (yylhs.value.vector_string_val)->push_back(new string ("corr"));
                   (yylhs.value.vector_string_val)->push_back((yystack_[5].value.string_val));
                   (yylhs.value.vector_string_val)->push_back((yystack_[3].value.string_val));
                   (yylhs.value.vector_string_val)->push_back(new string (""));
                 }
#line 3169 "DynareBison.cc" // lalr1.cc:847
    break;

  case 682:
#line 1697 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                   (yylhs.value.vector_string_val) = new vector<string *>();
                   (yylhs.value.vector_string_val)->push_back(new string ("corr"));
                   (yylhs.value.vector_string_val)->push_back((yystack_[7].value.string_val));
                   (yylhs.value.vector_string_val)->push_back((yystack_[5].value.string_val));
                   (yylhs.value.vector_string_val)->push_back((yystack_[2].value.string_val));
                 }
#line 3181 "DynareBison.cc" // lalr1.cc:847
    break;

  case 683:
#line 1707 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.run_estimation(); }
#line 3187 "DynareBison.cc" // lalr1.cc:847
    break;

  case 684:
#line 1709 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.run_estimation(); }
#line 3193 "DynareBison.cc" // lalr1.cc:847
    break;

  case 685:
#line 1711 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.run_estimation(); }
#line 3199 "DynareBison.cc" // lalr1.cc:847
    break;

  case 686:
#line 1713 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.run_estimation(); }
#line 3205 "DynareBison.cc" // lalr1.cc:847
    break;

  case 790:
#line 1824 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.optim_options_string((yystack_[2].value.string_val), (yystack_[0].value.string_val)); }
#line 3211 "DynareBison.cc" // lalr1.cc:847
    break;

  case 791:
#line 1826 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.optim_options_num((yystack_[2].value.string_val), (yystack_[0].value.string_val)); }
#line 3217 "DynareBison.cc" // lalr1.cc:847
    break;

  case 794:
#line 1834 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                             (yystack_[2].value.string_val)->insert(0, "''");
                             (yystack_[2].value.string_val)->append("'', ''");
                             (yystack_[2].value.string_val)->append(*(yystack_[0].value.string_val));
                             (yystack_[2].value.string_val)->append("''");
                             (yylhs.value.string_val) = (yystack_[2].value.string_val);
                           }
#line 3229 "DynareBison.cc" // lalr1.cc:847
    break;

  case 795:
#line 1842 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                             (yystack_[2].value.string_val)->insert(0, "''");
                             (yystack_[2].value.string_val)->append("'',");
                             (yystack_[2].value.string_val)->append(*(yystack_[0].value.string_val));
                             (yylhs.value.string_val) = (yystack_[2].value.string_val);
                           }
#line 3240 "DynareBison.cc" // lalr1.cc:847
    break;

  case 796:
#line 1851 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 3246 "DynareBison.cc" // lalr1.cc:847
    break;

  case 797:
#line 1853 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                         (yystack_[2].value.string_val)->append(",");
                         (yystack_[2].value.string_val)->append(*(yystack_[0].value.string_val));
                         (yylhs.value.string_val) = (yystack_[2].value.string_val);
                       }
#line 3256 "DynareBison.cc" // lalr1.cc:847
    break;

  case 798:
#line 1861 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.sampling_options_string((yystack_[2].value.string_val), (yystack_[0].value.string_val)); }
#line 3262 "DynareBison.cc" // lalr1.cc:847
    break;

  case 799:
#line 1863 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.sampling_options_num((yystack_[2].value.string_val), (yystack_[0].value.string_val)); }
#line 3268 "DynareBison.cc" // lalr1.cc:847
    break;

  case 800:
#line 1865 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                         (yystack_[1].value.string_val)->insert(0,"(");
                         (yystack_[1].value.string_val)->append(")");
                         driver.sampling_options_string((yystack_[4].value.string_val), (yystack_[1].value.string_val));
                       }
#line 3278 "DynareBison.cc" // lalr1.cc:847
    break;

  case 803:
#line 1876 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.check_varobs(); }
#line 3284 "DynareBison.cc" // lalr1.cc:847
    break;

  case 805:
#line 1879 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_varobs((yystack_[0].value.string_val)); }
#line 3290 "DynareBison.cc" // lalr1.cc:847
    break;

  case 806:
#line 1881 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_varobs((yystack_[0].value.string_val)); }
#line 3296 "DynareBison.cc" // lalr1.cc:847
    break;

  case 807:
#line 1883 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_varobs((yystack_[0].value.string_val)); }
#line 3302 "DynareBison.cc" // lalr1.cc:847
    break;

  case 808:
#line 1886 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.set_trends(); }
#line 3308 "DynareBison.cc" // lalr1.cc:847
    break;

  case 811:
#line 1892 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.set_trend_element((yystack_[4].value.string_val), (yystack_[2].value.node_val)); }
#line 3314 "DynareBison.cc" // lalr1.cc:847
    break;

  case 812:
#line 1894 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.set_unit_root_vars(); }
#line 3320 "DynareBison.cc" // lalr1.cc:847
    break;

  case 813:
#line 1896 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.optim_weights(); }
#line 3326 "DynareBison.cc" // lalr1.cc:847
    break;

  case 814:
#line 1899 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.set_optim_weights((yystack_[2].value.string_val), (yystack_[1].value.node_val)); }
#line 3332 "DynareBison.cc" // lalr1.cc:847
    break;

  case 815:
#line 1901 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.set_optim_weights((yystack_[4].value.string_val), (yystack_[2].value.string_val), (yystack_[1].value.node_val)); }
#line 3338 "DynareBison.cc" // lalr1.cc:847
    break;

  case 816:
#line 1903 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.set_optim_weights((yystack_[2].value.string_val), (yystack_[1].value.node_val)); }
#line 3344 "DynareBison.cc" // lalr1.cc:847
    break;

  case 817:
#line 1905 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.set_optim_weights((yystack_[4].value.string_val), (yystack_[2].value.string_val), (yystack_[1].value.node_val)); }
#line 3350 "DynareBison.cc" // lalr1.cc:847
    break;

  case 818:
#line 1908 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.set_osr_params(); }
#line 3356 "DynareBison.cc" // lalr1.cc:847
    break;

  case 828:
#line 1925 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.run_osr(); }
#line 3362 "DynareBison.cc" // lalr1.cc:847
    break;

  case 829:
#line 1927 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.run_osr(); }
#line 3368 "DynareBison.cc" // lalr1.cc:847
    break;

  case 830:
#line 1929 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.run_osr(); }
#line 3374 "DynareBison.cc" // lalr1.cc:847
    break;

  case 831:
#line 1931 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.run_osr(); }
#line 3380 "DynareBison.cc" // lalr1.cc:847
    break;

  case 832:
#line 1935 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.run_dynatype((yystack_[2].value.string_val)); }
#line 3386 "DynareBison.cc" // lalr1.cc:847
    break;

  case 833:
#line 1937 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.run_dynatype((yystack_[3].value.string_val)); }
#line 3392 "DynareBison.cc" // lalr1.cc:847
    break;

  case 834:
#line 1941 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.run_dynasave((yystack_[2].value.string_val)); }
#line 3398 "DynareBison.cc" // lalr1.cc:847
    break;

  case 835:
#line 1943 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.run_dynasave((yystack_[3].value.string_val)); }
#line 3404 "DynareBison.cc" // lalr1.cc:847
    break;

  case 836:
#line 1947 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.run_load_params_and_steady_state((yystack_[2].value.string_val)); }
#line 3410 "DynareBison.cc" // lalr1.cc:847
    break;

  case 837:
#line 1951 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.run_save_params_and_steady_state((yystack_[2].value.string_val)); }
#line 3416 "DynareBison.cc" // lalr1.cc:847
    break;

  case 838:
#line 1955 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.run_identification(); }
#line 3422 "DynareBison.cc" // lalr1.cc:847
    break;

  case 839:
#line 1957 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.run_identification(); }
#line 3428 "DynareBison.cc" // lalr1.cc:847
    break;

  case 862:
#line 1987 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.run_model_comparison(); }
#line 3434 "DynareBison.cc" // lalr1.cc:847
    break;

  case 863:
#line 1989 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.run_model_comparison(); }
#line 3440 "DynareBison.cc" // lalr1.cc:847
    break;

  case 866:
#line 1997 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_parallel_local_file((yystack_[0].value.string_val)); }
#line 3446 "DynareBison.cc" // lalr1.cc:847
    break;

  case 867:
#line 1999 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_parallel_local_file((yystack_[0].value.string_val)); }
#line 3452 "DynareBison.cc" // lalr1.cc:847
    break;

  case 868:
#line 2003 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_mc_filename((yystack_[0].value.string_val)); }
#line 3458 "DynareBison.cc" // lalr1.cc:847
    break;

  case 869:
#line 2005 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_mc_filename((yystack_[3].value.string_val), (yystack_[1].value.string_val)); }
#line 3464 "DynareBison.cc" // lalr1.cc:847
    break;

  case 870:
#line 2007 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_mc_filename((yystack_[0].value.string_val)); }
#line 3470 "DynareBison.cc" // lalr1.cc:847
    break;

  case 871:
#line 2009 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_mc_filename((yystack_[3].value.string_val), (yystack_[1].value.string_val)); }
#line 3476 "DynareBison.cc" // lalr1.cc:847
    break;

  case 872:
#line 2011 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_mc_filename((yystack_[0].value.string_val)); }
#line 3482 "DynareBison.cc" // lalr1.cc:847
    break;

  case 873:
#line 2013 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_mc_filename((yystack_[3].value.string_val), (yystack_[1].value.string_val)); }
#line 3488 "DynareBison.cc" // lalr1.cc:847
    break;

  case 874:
#line 2016 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.begin_planner_objective(); }
#line 3494 "DynareBison.cc" // lalr1.cc:847
    break;

  case 875:
#line 2017 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.end_planner_objective((yystack_[0].value.node_val)); }
#line 3500 "DynareBison.cc" // lalr1.cc:847
    break;

  case 877:
#line 2020 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.ramsey_model(); }
#line 3506 "DynareBison.cc" // lalr1.cc:847
    break;

  case 878:
#line 2022 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.ramsey_model(); }
#line 3512 "DynareBison.cc" // lalr1.cc:847
    break;

  case 879:
#line 2024 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.ramsey_model(); }
#line 3518 "DynareBison.cc" // lalr1.cc:847
    break;

  case 880:
#line 2026 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.ramsey_model(); }
#line 3524 "DynareBison.cc" // lalr1.cc:847
    break;

  case 881:
#line 2030 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.ramsey_policy(); }
#line 3530 "DynareBison.cc" // lalr1.cc:847
    break;

  case 882:
#line 2032 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.ramsey_policy(); }
#line 3536 "DynareBison.cc" // lalr1.cc:847
    break;

  case 883:
#line 2034 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.ramsey_policy(); }
#line 3542 "DynareBison.cc" // lalr1.cc:847
    break;

  case 884:
#line 2036 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.ramsey_policy(); }
#line 3548 "DynareBison.cc" // lalr1.cc:847
    break;

  case 885:
#line 2040 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_ramsey_constraints_statement(); }
#line 3554 "DynareBison.cc" // lalr1.cc:847
    break;

  case 888:
#line 2048 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.ramsey_constraint_add_less((yystack_[3].value.string_val),(yystack_[1].value.node_val)); }
#line 3560 "DynareBison.cc" // lalr1.cc:847
    break;

  case 889:
#line 2050 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.ramsey_constraint_add_greater((yystack_[3].value.string_val),(yystack_[1].value.node_val)); }
#line 3566 "DynareBison.cc" // lalr1.cc:847
    break;

  case 890:
#line 2052 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.ramsey_constraint_add_less_equal((yystack_[3].value.string_val),(yystack_[1].value.node_val)); }
#line 3572 "DynareBison.cc" // lalr1.cc:847
    break;

  case 891:
#line 2054 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.ramsey_constraint_add_greater_equal((yystack_[3].value.string_val),(yystack_[1].value.node_val)); }
#line 3578 "DynareBison.cc" // lalr1.cc:847
    break;

  case 892:
#line 2058 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.discretionary_policy(); }
#line 3584 "DynareBison.cc" // lalr1.cc:847
    break;

  case 893:
#line 2060 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.discretionary_policy(); }
#line 3590 "DynareBison.cc" // lalr1.cc:847
    break;

  case 894:
#line 2062 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.discretionary_policy(); }
#line 3596 "DynareBison.cc" // lalr1.cc:847
    break;

  case 895:
#line 2064 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.discretionary_policy(); }
#line 3602 "DynareBison.cc" // lalr1.cc:847
    break;

  case 910:
#line 2094 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.write_latex_dynamic_model(); }
#line 3608 "DynareBison.cc" // lalr1.cc:847
    break;

  case 911:
#line 2098 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.write_latex_static_model(); }
#line 3614 "DynareBison.cc" // lalr1.cc:847
    break;

  case 912:
#line 2102 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.write_latex_original_model(); }
#line 3620 "DynareBison.cc" // lalr1.cc:847
    break;

  case 913:
#line 2106 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.shock_decomposition(); }
#line 3626 "DynareBison.cc" // lalr1.cc:847
    break;

  case 914:
#line 2108 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.shock_decomposition(); }
#line 3632 "DynareBison.cc" // lalr1.cc:847
    break;

  case 915:
#line 2110 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.shock_decomposition(); }
#line 3638 "DynareBison.cc" // lalr1.cc:847
    break;

  case 916:
#line 2112 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.shock_decomposition(); }
#line 3644 "DynareBison.cc" // lalr1.cc:847
    break;

  case 936:
#line 2141 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.bvar_density((yystack_[1].value.string_val)); }
#line 3650 "DynareBison.cc" // lalr1.cc:847
    break;

  case 937:
#line 2143 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.bvar_density((yystack_[1].value.string_val)); }
#line 3656 "DynareBison.cc" // lalr1.cc:847
    break;

  case 944:
#line 2157 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.bvar_forecast((yystack_[1].value.string_val)); }
#line 3662 "DynareBison.cc" // lalr1.cc:847
    break;

  case 945:
#line 2159 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.bvar_forecast((yystack_[1].value.string_val)); }
#line 3668 "DynareBison.cc" // lalr1.cc:847
    break;

  case 996:
#line 2217 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.sbvar(); }
#line 3674 "DynareBison.cc" // lalr1.cc:847
    break;

  case 997:
#line 2219 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.sbvar(); }
#line 3680 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1014:
#line 2243 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.ms_variance_decomposition(); }
#line 3686 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1015:
#line 2245 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.ms_variance_decomposition(); }
#line 3692 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1032:
#line 2269 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.ms_forecast(); }
#line 3698 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1033:
#line 2271 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.ms_forecast(); }
#line 3704 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1050:
#line 2295 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.ms_irf(); }
#line 3710 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1051:
#line 2297 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.ms_irf(); }
#line 3716 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1052:
#line 2299 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.ms_irf(); }
#line 3722 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1053:
#line 2301 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.ms_irf(); }
#line 3728 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1060:
#line 2315 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.ms_compute_probabilities(); }
#line 3734 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1061:
#line 2317 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.ms_compute_probabilities(); }
#line 3740 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1072:
#line 2335 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.ms_compute_mdd(); }
#line 3746 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1073:
#line 2337 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.ms_compute_mdd(); }
#line 3752 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1083:
#line 2354 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.ms_simulation(); }
#line 3758 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1084:
#line 2356 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.ms_simulation(); }
#line 3764 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1122:
#line 2401 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.ms_estimation(); }
#line 3770 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1123:
#line 2403 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.ms_estimation(); }
#line 3776 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1124:
#line 2407 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.dynare_sensitivity(); }
#line 3782 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1125:
#line 2409 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.dynare_sensitivity(); }
#line 3788 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1186:
#line 2481 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.end_homotopy();}
#line 3794 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1189:
#line 2488 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.homotopy_val((yystack_[5].value.string_val), (yystack_[3].value.node_val), (yystack_[1].value.node_val));}
#line 3800 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1190:
#line 2490 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.homotopy_val((yystack_[3].value.string_val), NULL, (yystack_[1].value.node_val));}
#line 3806 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1191:
#line 2493 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.forecast();}
#line 3812 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1192:
#line 2494 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.forecast();}
#line 3818 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1193:
#line 2495 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.forecast();}
#line 3824 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1194:
#line 2496 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.forecast();}
#line 3830 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1202:
#line 2511 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.conditional_forecast(); }
#line 3836 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1210:
#line 2526 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.plot_conditional_forecast(); }
#line 3842 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1211:
#line 2528 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.plot_conditional_forecast((yystack_[3].value.string_val)); }
#line 3848 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1212:
#line 2532 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.conditional_forecast_paths(); }
#line 3854 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1215:
#line 2540 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_det_shock((yystack_[7].value.string_val), true); }
#line 3860 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1216:
#line 2543 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.begin_steady_state_model(); }
#line 3866 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1217:
#line 2544 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.reset_data_tree(); }
#line 3872 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1220:
#line 2552 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_steady_state_model_equal((yystack_[3].value.string_val), (yystack_[1].value.node_val)); }
#line 3878 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1221:
#line 2554 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_steady_state_model_equal_multiple((yystack_[1].value.node_val)); }
#line 3884 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1222:
#line 2558 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.calib_smoother(); }
#line 3890 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1223:
#line 2560 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.calib_smoother(); }
#line 3896 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1224:
#line 2562 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.calib_smoother(); }
#line 3902 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1225:
#line 2564 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.calib_smoother(); }
#line 3908 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1235:
#line 2581 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.extended_path(); }
#line 3914 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1236:
#line 2583 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.extended_path(); }
#line 3920 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1245:
#line 2599 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.model_diagnostics(); }
#line 3926 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1246:
#line 2603 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                      (yylhs.value.vector_string_val) = new vector<string *>();
                      (yylhs.value.vector_string_val)->push_back((yystack_[2].value.string_val));
                      (yylhs.value.vector_string_val)->push_back((yystack_[1].value.string_val));
                    }
#line 3936 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1247:
#line 2609 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                      (yylhs.value.vector_string_val) = new vector<string *>();
                      (yylhs.value.vector_string_val)->push_back((yystack_[3].value.string_val));
                      (yylhs.value.vector_string_val)->push_back((yystack_[1].value.string_val));
                    }
#line 3946 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1248:
#line 2615 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                      (yylhs.value.vector_string_val) = new vector<string *>();
                      (yylhs.value.vector_string_val)->push_back(new string("0"));
                      (yylhs.value.vector_string_val)->push_back(new string("inf"));
                    }
#line 3956 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1249:
#line 2621 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                      (yylhs.value.vector_string_val) = new vector<string *>();
                      (yylhs.value.vector_string_val)->push_back(new string("-inf"));
                      (yylhs.value.vector_string_val)->push_back(new string("0"));
                    }
#line 3966 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1250:
#line 2629 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.end_moment_calibration(); }
#line 3972 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1253:
#line 2637 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_moment_calibration_item((yystack_[5].value.string_val), (yystack_[3].value.string_val), new string("0"), (yystack_[1].value.vector_string_val)); }
#line 3978 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1254:
#line 2639 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_moment_calibration_item((yystack_[8].value.string_val), (yystack_[6].value.string_val), (yystack_[4].value.string_val), (yystack_[1].value.vector_string_val)); }
#line 3984 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1255:
#line 2641 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_moment_calibration_item((yystack_[8].value.string_val), (yystack_[6].value.string_val), (yystack_[4].value.string_val), (yystack_[1].value.vector_string_val)); }
#line 3990 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1256:
#line 2645 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.end_irf_calibration(); }
#line 3996 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1257:
#line 2647 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.end_irf_calibration(); }
#line 4002 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1260:
#line 2655 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_irf_calibration_item((yystack_[5].value.string_val), new string("1"), (yystack_[3].value.string_val), (yystack_[1].value.vector_string_val)); }
#line 4008 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1261:
#line 2657 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_irf_calibration_item((yystack_[8].value.string_val), (yystack_[6].value.string_val), (yystack_[3].value.string_val), (yystack_[1].value.vector_string_val)); }
#line 4014 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1262:
#line 2659 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_irf_calibration_item((yystack_[8].value.string_val), (yystack_[6].value.string_val), (yystack_[3].value.string_val), (yystack_[1].value.vector_string_val)); }
#line 4020 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1263:
#line 2663 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.smoother2histval(); }
#line 4026 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1264:
#line 2665 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.smoother2histval(); }
#line 4032 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1272:
#line 2679 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.end_shock_groups(new string("default"));}
#line 4038 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1273:
#line 2681 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.end_shock_groups((yystack_[5].value.string_val));}
#line 4044 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1276:
#line 2688 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.add_shock_group((yystack_[3].value.string_val));}
#line 4050 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1277:
#line 2691 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.add_shock_group_element((yystack_[0].value.string_val));}
#line 4056 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1278:
#line 2692 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.add_shock_group_element((yystack_[0].value.string_val));}
#line 4062 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1279:
#line 2693 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.add_shock_group_element((yystack_[0].value.string_val));}
#line 4068 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1280:
#line 2696 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                                       if (*(yystack_[0].value.string_val) == string("0"))
                                         driver.warning("dr_algo option is now deprecated, and may be removed in a future version of Dynare");
                                       else
                                         driver.error("dr_algo=1 option is no longer supported");
                                     }
#line 4079 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1281:
#line 2702 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("solve_algo", (yystack_[0].value.string_val)); }
#line 4085 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1282:
#line 2703 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                                             if (*(yystack_[0].value.string_val) == string("0"))
                                               driver.warning("simul_algo option is now deprecated, and may be removed in a future version of Dynare");
                                             else
                                               driver.error("simul_algo=1 option is no longer supported");
                                           }
#line 4096 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1283:
#line 2709 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("stack_solve_algo", (yystack_[0].value.string_val)); }
#line 4102 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1284:
#line 2710 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("endogenous_terminal_period", "1"); }
#line 4108 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1285:
#line 2711 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.linear(); }
#line 4114 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1286:
#line 2712 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("order", (yystack_[0].value.string_val)); }
#line 4120 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1287:
#line 2713 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("replic", (yystack_[0].value.string_val)); }
#line 4126 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1288:
#line 2714 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("drop", (yystack_[0].value.string_val)); }
#line 4132 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1289:
#line 2715 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ar", (yystack_[0].value.string_val)); }
#line 4138 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1290:
#line 2716 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("nocorr", "1"); }
#line 4144 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1291:
#line 2717 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("nofunctions", "1"); }
#line 4150 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1292:
#line 2718 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("nomoments", "1"); }
#line 4156 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1293:
#line 2719 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("irf", (yystack_[0].value.string_val)); }
#line 4162 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1294:
#line 2720 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_symbol_list("irf_shocks"); }
#line 4168 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1295:
#line 2721 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("hp_filter", (yystack_[0].value.string_val)); }
#line 4174 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1296:
#line 2722 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("hp_ngrid", (yystack_[0].value.string_val)); }
#line 4180 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1297:
#line 2723 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("one_sided_hp_filter", (yystack_[0].value.string_val)); }
#line 4186 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1298:
#line 2724 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("periods", (yystack_[0].value.string_val)); }
#line 4192 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1299:
#line 2725 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ep.periods", (yystack_[0].value.string_val)); }
#line 4198 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1300:
#line 2726 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ep.stochastic.order", (yystack_[0].value.string_val)); }
#line 4204 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1301:
#line 2727 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ep.stochastic.hybrid_order", "2"); }
#line 4210 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1302:
#line 2728 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("steady.maxit", (yystack_[0].value.string_val)); }
#line 4216 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1303:
#line 2729 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("simul.maxit", (yystack_[0].value.string_val)); }
#line 4222 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1304:
#line 2730 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("bandpass.indicator", "1"); }
#line 4228 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1305:
#line 2732 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                      driver.option_num("bandpass.indicator", "1");
                      driver.option_vec_int("bandpass.passband", (yystack_[0].value.vector_int_val));
                    }
#line 4237 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1306:
#line 2737 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("dp.maxit", (yystack_[0].value.string_val)); }
#line 4243 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1307:
#line 2738 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("osr.maxit", (yystack_[0].value.string_val)); }
#line 4249 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1308:
#line 2739 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("osr.tolf", (yystack_[0].value.string_val)); }
#line 4255 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1309:
#line 2740 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("dynatol.f", (yystack_[0].value.string_val)); }
#line 4261 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1310:
#line 2741 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("dynatol.x", (yystack_[0].value.string_val)); }
#line 4267 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1311:
#line 2742 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("solve_tolf", (yystack_[0].value.string_val)); }
#line 4273 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1312:
#line 2743 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("osr.opt_algo", (yystack_[0].value.string_val)); }
#line 4279 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1313:
#line 2744 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_str("osr.opt_algo", (yystack_[0].value.string_val)); }
#line 4285 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1314:
#line 2746 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.cutoff((yystack_[0].value.string_val)); }
#line 4291 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1315:
#line 2747 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("markowitz", (yystack_[0].value.string_val)); }
#line 4297 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1316:
#line 2748 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("minimal_solving_periods", (yystack_[0].value.string_val)); }
#line 4303 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1317:
#line 2749 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.mfs((yystack_[0].value.string_val)); }
#line 4309 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1319:
#line 2751 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("simul_replic", (yystack_[0].value.string_val)); }
#line 4315 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1320:
#line 2752 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.error("'simul_seed' option is no longer supported; use 'set_dynare_seed' command instead"); }
#line 4321 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1321:
#line 2753 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("qz_criterium", (yystack_[0].value.string_val)); }
#line 4327 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1322:
#line 2754 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("qz_zero_threshold", (yystack_[0].value.string_val)); }
#line 4333 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1323:
#line 2755 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_str("file", (yystack_[0].value.string_val)); }
#line 4339 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1324:
#line 2756 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_str("series", (yystack_[0].value.string_val)); }
#line 4345 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1325:
#line 2757 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_str("datafile", (yystack_[0].value.string_val)); }
#line 4351 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1326:
#line 2758 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_str("dirname", (yystack_[0].value.string_val)); }
#line 4357 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1327:
#line 2759 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("huge_number", (yystack_[0].value.string_val)); }
#line 4363 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1328:
#line 2761 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_vec_int("nobs", (yystack_[0].value.vector_int_val)); }
#line 4369 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1329:
#line 2763 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_vec_int("nobs", (yystack_[0].value.vector_int_val)); }
#line 4375 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1330:
#line 2766 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_vec_int("conditional_variance_decomposition", (yystack_[0].value.vector_int_val)); }
#line 4381 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1331:
#line 2768 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_vec_int("conditional_variance_decomposition", (yystack_[0].value.vector_int_val)); }
#line 4387 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1332:
#line 2771 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_vec_int("first_obs", (yystack_[0].value.vector_int_val)); }
#line 4393 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1333:
#line 2773 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_vec_int("first_obs", (yystack_[0].value.vector_int_val)); }
#line 4399 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1334:
#line 2776 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_str("posterior_sampler_options.posterior_sampling_method", (yystack_[0].value.string_val)); }
#line 4405 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1335:
#line 2777 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("first_obs", (yystack_[0].value.string_val)); }
#line 4411 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1336:
#line 2778 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_date("firstobs", (yystack_[0].value.string_val)); }
#line 4417 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1337:
#line 2779 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_date("lastobs", (yystack_[0].value.string_val)); }
#line 4423 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1338:
#line 2780 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("nobs", (yystack_[0].value.string_val)); }
#line 4429 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1339:
#line 2781 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("shift", (yystack_[0].value.string_val)); }
#line 4435 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1340:
#line 2782 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.prior_shape = (yystack_[0].value.prior_distributions_val); }
#line 4441 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1341:
#line 2783 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("mode", (yystack_[0].value.string_val)); }
#line 4447 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1342:
#line 2784 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("mean", (yystack_[0].value.string_val)); }
#line 4453 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1343:
#line 2785 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("mean", (yystack_[0].value.string_val)); }
#line 4459 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1344:
#line 2786 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("truncate", (yystack_[0].value.string_val)); }
#line 4465 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1345:
#line 2787 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("stdev", (yystack_[0].value.string_val)); }
#line 4471 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1346:
#line 2788 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("jscale", (yystack_[0].value.string_val)); }
#line 4477 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1347:
#line 2789 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("init", (yystack_[0].value.string_val)); }
#line 4483 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1348:
#line 2790 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("bounds", (yystack_[0].value.string_val)); }
#line 4489 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1349:
#line 2791 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("domain", (yystack_[0].value.string_val)); }
#line 4495 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1350:
#line 2792 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("interval", (yystack_[0].value.string_val)); }
#line 4501 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1351:
#line 2793 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.set_prior_variance((yystack_[0].value.node_val)); }
#line 4507 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1352:
#line 2794 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("variance",(yystack_[0].value.string_val)); }
#line 4513 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1353:
#line 2795 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("prefilter", (yystack_[0].value.string_val)); }
#line 4519 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1354:
#line 2796 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("presample", (yystack_[0].value.string_val)); }
#line 4525 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1355:
#line 2797 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("lik_algo", (yystack_[0].value.string_val)); }
#line 4531 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1356:
#line 2798 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("lik_init", (yystack_[0].value.string_val)); }
#line 4537 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1357:
#line 2800 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("nograph","1"); }
#line 4543 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1358:
#line 2802 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("nograph", "0"); }
#line 4549 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1359:
#line 2804 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("nodisplay","1"); }
#line 4555 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1360:
#line 2806 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.process_graph_format_option(); }
#line 4561 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1361:
#line 2808 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.process_graph_format_option(); }
#line 4567 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1362:
#line 2811 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_graph_format("eps"); }
#line 4573 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1363:
#line 2813 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_graph_format("fig"); }
#line 4579 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1364:
#line 2815 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_graph_format("pdf"); }
#line 4585 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1365:
#line 2817 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.add_graph_format("none"); }
#line 4591 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1368:
#line 2824 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.set_subsample_name_equal_to_date_range((yystack_[4].value.string_val), (yystack_[2].value.string_val), (yystack_[0].value.string_val)); }
#line 4597 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1369:
#line 2826 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("conf_sig", (yystack_[0].value.string_val)); }
#line 4603 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1370:
#line 2827 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("mh_conf_sig", (yystack_[0].value.string_val)); }
#line 4609 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1371:
#line 2828 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("mh_replic", (yystack_[0].value.string_val)); }
#line 4615 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1372:
#line 2829 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("posterior_max_subsample_draws", (yystack_[0].value.string_val)); }
#line 4621 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1373:
#line 2830 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("mh_drop", (yystack_[0].value.string_val)); }
#line 4627 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1374:
#line 2831 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("mh_jscale", (yystack_[0].value.string_val)); }
#line 4633 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1377:
#line 2834 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_str("posterior_sampler_options.posterior_sampling_method.proposal_distribution", (yystack_[0].value.string_val)); }
#line 4639 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1378:
#line 2836 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("moments_posterior_density.indicator", "0"); }
#line 4645 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1379:
#line 2838 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("mh_init_scale", (yystack_[0].value.string_val)); }
#line 4651 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1380:
#line 2839 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_str("mode_file", (yystack_[0].value.string_val)); }
#line 4657 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1381:
#line 2840 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("mode_compute", (yystack_[0].value.string_val)); }
#line 4663 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1382:
#line 2841 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_str("mode_compute", (yystack_[0].value.string_val)); }
#line 4669 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1383:
#line 2842 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("mode_check.status", "1"); }
#line 4675 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1384:
#line 2843 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("mode_check.neighbourhood_size", (yystack_[0].value.string_val)); }
#line 4681 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1385:
#line 2844 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("mode_check.number_of_points", (yystack_[0].value.string_val)); }
#line 4687 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1386:
#line 2845 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("mode_check.symmetric_plots", (yystack_[0].value.string_val)); }
#line 4693 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1387:
#line 2846 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("prior_trunc", (yystack_[0].value.string_val)); }
#line 4699 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1388:
#line 2847 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("mh_mode", (yystack_[0].value.string_val)); }
#line 4705 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1389:
#line 2848 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("mh_nblck", (yystack_[0].value.string_val)); }
#line 4711 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1390:
#line 2849 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("load_mh_file", "1"); }
#line 4717 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1391:
#line 2850 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("loglinear", "1"); }
#line 4723 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1392:
#line 2851 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("linear_approximation", "1"); }
#line 4729 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1393:
#line 2852 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("logdata", "1"); }
#line 4735 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1394:
#line 2853 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("nodiagnostic", "1"); }
#line 4741 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1395:
#line 2854 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("bayesian_irf", "1"); }
#line 4747 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1396:
#line 2856 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("dsge_var", (yystack_[0].value.string_val)); }
#line 4753 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1397:
#line 2858 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("dsge_var", "Inf"); }
#line 4759 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1398:
#line 2860 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_str("dsge_var", "NaN"); }
#line 4765 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1399:
#line 2862 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("dsge_varlag", (yystack_[0].value.string_val)); }
#line 4771 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1400:
#line 2863 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("TeX", "1"); }
#line 4777 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1401:
#line 2864 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("forecast", (yystack_[0].value.string_val)); }
#line 4783 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1402:
#line 2865 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("smoother", "1"); }
#line 4789 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1403:
#line 2866 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("moments_varendo", "1"); }
#line 4795 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1404:
#line 2867 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("contemporaneous_correlation", "1"); }
#line 4801 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1405:
#line 2868 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("filtered_vars", "1"); }
#line 4807 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1406:
#line 2869 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("relative_irf", "1"); }
#line 4813 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1407:
#line 2870 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("fast_kalman_filter", "1"); }
#line 4819 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1408:
#line 2871 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("kalman_algo", (yystack_[0].value.string_val)); }
#line 4825 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1409:
#line 2872 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("kalman_tol", (yystack_[0].value.string_val)); }
#line 4831 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1410:
#line 2873 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("diffuse_kalman_tol", (yystack_[0].value.string_val)); }
#line 4837 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1411:
#line 2875 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_str("mc_marginal_density", "laplace"); }
#line 4843 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1412:
#line 2877 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_str("mc_marginal_density", "modifiedharmonicmean"); }
#line 4849 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1413:
#line 2879 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("noprint", "0"); }
#line 4855 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1414:
#line 2880 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("noprint", "1"); }
#line 4861 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1415:
#line 2881 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_str("xls_sheet", (yystack_[0].value.string_val)); }
#line 4867 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1416:
#line 2882 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_str("xls_range", (yystack_[0].value.string_val)); }
#line 4873 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1417:
#line 2883 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_vec_int("filter_step_ahead", (yystack_[0].value.vector_int_val)); }
#line 4879 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1418:
#line 2884 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_vec_int("taper_steps", (yystack_[0].value.vector_int_val)); }
#line 4885 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1419:
#line 2885 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("geweke_interval",(yystack_[0].value.string_val)); }
#line 4891 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1420:
#line 2886 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("noconstant", "0"); }
#line 4897 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1421:
#line 2887 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("noconstant", "1"); }
#line 4903 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1422:
#line 2888 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("mh_recover", "1"); }
#line 4909 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1423:
#line 2889 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("diffuse_filter", "1"); }
#line 4915 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1424:
#line 2890 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("plot_priors", (yystack_[0].value.string_val)); }
#line 4921 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1425:
#line 2891 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("aim_solver", "1"); }
#line 4927 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1426:
#line 2892 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("partial_information", "1"); }
#line 4933 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1427:
#line 2893 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("sub_draws",(yystack_[0].value.string_val));}
#line 4939 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1428:
#line 2894 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.declare_optimal_policy_discount_factor_parameter((yystack_[0].value.node_val)); }
#line 4945 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1429:
#line 2895 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("sylvester_fp", "1"); }
#line 4951 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1430:
#line 2896 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("sylvester_fp", "0"); }
#line 4957 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1431:
#line 2897 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("sylvester_fixed_point_tol",(yystack_[0].value.string_val));}
#line 4963 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1432:
#line 2898 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("lyapunov_fp", "1"); }
#line 4969 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1433:
#line 2899 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("lyapunov_db", "1"); }
#line 4975 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1434:
#line 2900 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("lyapunov_srs", "1"); }
#line 4981 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1435:
#line 2901 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("lyapunov_fp", "0");driver.option_num("lyapunov_db", "0"); driver.option_num("lyapunov_srs", "0");}
#line 4987 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1436:
#line 2902 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("lyapunov_fixed_point_tol",(yystack_[0].value.string_val));}
#line 4993 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1437:
#line 2903 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("lyapunov_doubling_tol",(yystack_[0].value.string_val));}
#line 4999 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1438:
#line 2904 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("dr_cycle_reduction", "1"); }
#line 5005 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1439:
#line 2905 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("dr_logarithmic_reduction", "1"); }
#line 5011 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1440:
#line 2906 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("dr_cycle_reduction", "0"); driver.option_num("dr_logarithmic_reduction", "0");}
#line 5017 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1441:
#line 2907 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("dr_cycle_reduction_tol",(yystack_[0].value.string_val));}
#line 5023 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1442:
#line 2908 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("dr_logarithmic_reduction_tol",(yystack_[0].value.string_val));}
#line 5029 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1443:
#line 2909 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("dr_logarithmic_reduction_maxiter",(yystack_[0].value.string_val));}
#line 5035 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1444:
#line 2911 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("bvar_prior_tau", (yystack_[0].value.string_val)); }
#line 5041 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1445:
#line 2912 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("bvar_prior_decay", (yystack_[0].value.string_val)); }
#line 5047 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1446:
#line 2913 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("bvar_prior_lambda", (yystack_[0].value.string_val)); }
#line 5053 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1447:
#line 2914 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("bvar_prior_mu", (yystack_[0].value.string_val)); }
#line 5059 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1448:
#line 2915 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("bvar_prior_omega", (yystack_[0].value.string_val)); }
#line 5065 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1449:
#line 2916 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("bvar_prior_flat", "1"); }
#line 5071 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1450:
#line 2917 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("bvar_prior_train", (yystack_[0].value.string_val)); }
#line 5077 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1451:
#line 2918 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("bvar_replic", (yystack_[0].value.string_val)); }
#line 5083 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1452:
#line 2920 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("particle.number_of_particles", (yystack_[0].value.string_val)); }
#line 5089 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1454:
#line 2922 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("particle.resampling.status.systematic", "0"); driver.option_num("particle.resampling.status.none", "1"); }
#line 5095 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1455:
#line 2923 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("particle.resampling.status.systematic", "0"); driver.option_num("particle.resampling.status.generic", "1"); }
#line 5101 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1456:
#line 2924 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("particle.resampling.threshold", (yystack_[0].value.string_val)); }
#line 5107 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1457:
#line 2925 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("particle.resampling.method.kitagawa", "1"); driver.option_num("particle.resampling.method.smooth", "0"); driver.option_num("particle.resampling.smethod.stratified", "0"); }
#line 5113 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1458:
#line 2926 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("particle.resampling.method.kitagawa", "0"); driver.option_num("particle.resampling.method.smooth", "1"); driver.option_num("particle.resampling.smethod.stratified", "0"); }
#line 5119 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1459:
#line 2927 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("particle.resampling.method.kitagawa", "0"); driver.option_num("particle.resampling.method.smooth", "0"); driver.option_num("particle.resampling.method.stratified", "1"); }
#line 5125 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1460:
#line 2928 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("particle.cpf_weights_method.amisanotristani", "1"); driver.option_num("particle.cpf_weights_method.murrayjonesparslow", "0"); }
#line 5131 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1461:
#line 2929 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("particle.cpf_weights_method.amisanotristani", "0"); driver.option_num("particle.cpf_weights_method.murrayjonesparslow", "1"); }
#line 5137 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1462:
#line 2930 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_str("particle.filter_algorithm", (yystack_[0].value.string_val)); }
#line 5143 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1463:
#line 2931 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("particle.proposal_approximation.cubature", "1"); driver.option_num("particle.proposal_approximation.unscented", "0"); driver.option_num("particle.proposal_approximation.montecarlo", "0");}
#line 5149 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1464:
#line 2932 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("particle.proposal_approximation.cubature", "0"); driver.option_num("particle.proposal_approximation.unscented", "1"); driver.option_num("particle.proposal_approximation.montecarlo", "0");}
#line 5155 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1465:
#line 2933 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("particle.proposal_approximation.cubature", "0"); driver.option_num("particle.proposal_approximation.unscented", "0"); driver.option_num("particle.proposal_approximation.montecarlo", "1");}
#line 5161 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1466:
#line 2934 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("particle.distribution_approximation.cubature", "1"); driver.option_num("particle.distribution_approximation.unscented", "0"); driver.option_num("particle.distribution_approximation.montecarlo", "0");}
#line 5167 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1467:
#line 2935 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("particle.distribution_approximation.cubature", "0"); driver.option_num("particle.distribution_approximation.unscented", "1"); driver.option_num("particle.distribution_approximation.montecarlo", "0");}
#line 5173 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1468:
#line 2936 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("particle.distribution_approximation.cubature", "0"); driver.option_num("particle.distribution_approximation.unscented", "0"); driver.option_num("particle.distribution_approximation.montecarlo", "1");}
#line 5179 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1469:
#line 2939 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("identification", (yystack_[0].value.string_val)); }
#line 5185 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1470:
#line 2940 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("morris", (yystack_[0].value.string_val)); }
#line 5191 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1471:
#line 2941 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("stab", (yystack_[0].value.string_val)); }
#line 5197 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1472:
#line 2942 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("redform", (yystack_[0].value.string_val)); }
#line 5203 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1473:
#line 2943 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("pprior", (yystack_[0].value.string_val)); }
#line 5209 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1474:
#line 2944 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("prior_range", (yystack_[0].value.string_val)); }
#line 5215 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1475:
#line 2945 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ppost", (yystack_[0].value.string_val)); }
#line 5221 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1476:
#line 2946 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ilptau", (yystack_[0].value.string_val)); }
#line 5227 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1477:
#line 2947 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("morris_nliv", (yystack_[0].value.string_val)); }
#line 5233 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1478:
#line 2948 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("morris_ntra", (yystack_[0].value.string_val)); }
#line 5239 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1479:
#line 2949 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("Nsam", (yystack_[0].value.string_val)); }
#line 5245 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1480:
#line 2950 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("load_redform", (yystack_[0].value.string_val)); }
#line 5251 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1481:
#line 2951 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("load_rmse", (yystack_[0].value.string_val)); }
#line 5257 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1482:
#line 2952 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("load_stab", (yystack_[0].value.string_val)); }
#line 5263 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1483:
#line 2953 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("alpha2_stab", (yystack_[0].value.string_val)); }
#line 5269 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1484:
#line 2954 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ksstat", (yystack_[0].value.string_val)); }
#line 5275 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1485:
#line 2955 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("logtrans_redform", (yystack_[0].value.string_val)); }
#line 5281 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1486:
#line 2956 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("threshold_redform",(yystack_[0].value.string_val)); }
#line 5287 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1487:
#line 2957 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ksstat_redform", (yystack_[0].value.string_val)); }
#line 5293 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1488:
#line 2958 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("alpha2_redform", (yystack_[0].value.string_val)); }
#line 5299 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1489:
#line 2959 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_symbol_list("namendo"); }
#line 5305 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1490:
#line 2960 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_symbol_list("namlagendo"); }
#line 5311 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1491:
#line 2961 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_symbol_list("namexo"); }
#line 5317 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1492:
#line 2962 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("rmse", (yystack_[0].value.string_val)); }
#line 5323 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1493:
#line 2963 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("lik_only", (yystack_[0].value.string_val)); }
#line 5329 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1494:
#line 2964 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_symbol_list("var_rmse"); }
#line 5335 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1495:
#line 2965 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("pfilt_rmse", (yystack_[0].value.string_val)); }
#line 5341 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1496:
#line 2966 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("istart_rmse", (yystack_[0].value.string_val)); }
#line 5347 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1497:
#line 2967 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("alpha_rmse", (yystack_[0].value.string_val)); }
#line 5353 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1498:
#line 2968 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("alpha2_rmse", (yystack_[0].value.string_val)); }
#line 5359 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1499:
#line 2970 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("gsa_sample_file", (yystack_[0].value.string_val)); }
#line 5365 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1500:
#line 2972 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_str("gsa_sample_file", (yystack_[0].value.string_val)); }
#line 5371 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1501:
#line 2974 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("neighborhood_width", (yystack_[0].value.string_val)); }
#line 5377 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1502:
#line 2975 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("pvalue_ks", (yystack_[0].value.string_val)); }
#line 5383 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1503:
#line 2976 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("pvalue_corr", (yystack_[0].value.string_val)); }
#line 5389 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1504:
#line 2977 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("load_ident_files", (yystack_[0].value.string_val)); }
#line 5395 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1505:
#line 2978 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("useautocorr", (yystack_[0].value.string_val)); }
#line 5401 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1506:
#line 2979 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("prior_mc", (yystack_[0].value.string_val)); }
#line 5407 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1507:
#line 2980 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("advanced", (yystack_[0].value.string_val)); }
#line 5413 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1508:
#line 2981 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("max_dim_cova_group", (yystack_[0].value.string_val)); }
#line 5419 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1509:
#line 2983 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("homotopy_mode",(yystack_[0].value.string_val)); }
#line 5425 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1510:
#line 2984 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("homotopy_steps",(yystack_[0].value.string_val)); }
#line 5431 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1511:
#line 2985 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("homotopy_force_continue",(yystack_[0].value.string_val)); }
#line 5437 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1512:
#line 2986 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("steadystate.nocheck","1"); }
#line 5443 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1513:
#line 2988 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_symbol_list("controlled_varexo"); }
#line 5449 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1514:
#line 2990 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_str("parameter_set", "prior_mode"); }
#line 5455 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1515:
#line 2992 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_str("parameter_set", "prior_mean"); }
#line 5461 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1516:
#line 2994 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_str("parameter_set", "posterior_mean"); }
#line 5467 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1517:
#line 2996 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_str("parameter_set", "posterior_mode"); }
#line 5473 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1518:
#line 2998 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_str("parameter_set", "posterior_median"); }
#line 5479 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1519:
#line 3000 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_str("parameter_set", "mle_mode"); }
#line 5485 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1520:
#line 3002 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_str("parameter_set", "calibration"); }
#line 5491 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1521:
#line 3004 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("nodecomposition", "1"); }
#line 5497 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1522:
#line 3005 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("SpectralDensity.trigger", "1"); }
#line 5503 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1523:
#line 3006 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ms.drop", (yystack_[0].value.string_val)); }
#line 5509 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1524:
#line 3007 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ms.mh_replic", (yystack_[0].value.string_val)); }
#line 5515 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1525:
#line 3009 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ms.freq",(yystack_[0].value.string_val)); }
#line 5521 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1526:
#line 3011 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ms.freq","12"); }
#line 5527 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1527:
#line 3013 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ms.freq","4"); }
#line 5533 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1528:
#line 3015 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("ms.initial_year",(yystack_[0].value.string_val)); }
#line 5539 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1529:
#line 3016 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("ms.initial_subperiod",(yystack_[0].value.string_val)); }
#line 5545 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1530:
#line 3017 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("ms.final_year",(yystack_[0].value.string_val)); }
#line 5551 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1531:
#line 3018 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("ms.final_subperiod",(yystack_[0].value.string_val)); }
#line 5557 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1532:
#line 3019 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_str("ms.data", (yystack_[0].value.string_val)); }
#line 5563 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1533:
#line 3020 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("ms.vlist",(yystack_[0].value.string_val)); }
#line 5569 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1534:
#line 3021 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_symbol_list("ms.vlistlog"); }
#line 5575 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1535:
#line 3022 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("ms.vlistper",(yystack_[0].value.string_val)); }
#line 5581 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1536:
#line 3024 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                        driver.warning("restriction_fname is now deprecated, and may be removed in a future version of Dynare. Use svar_identification instead.");
                        driver.option_str("ms.restriction_fname",(yystack_[0].value.string_val));
                      }
#line 5590 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1537:
#line 3029 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                        driver.warning("restriction_fname is now deprecated, and may be removed in a future version of Dynare. Use svar_identification instead.");
                        driver.option_str("ms.restriction_fname","upper_cholesky");
                      }
#line 5599 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1538:
#line 3034 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                        driver.warning("restriction_fname is now deprecated, and may be removed in a future version of Dynare. Use svar_identification instead.");
                        driver.option_str("ms.restriction_fname","lower_cholesky");
                      }
#line 5608 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1539:
#line 3039 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("ms.nlags",(yystack_[0].value.string_val)); }
#line 5614 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1540:
#line 3040 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("ms.cross_restrictions","1"); }
#line 5620 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1541:
#line 3041 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("ms.contemp_reduced_form","1"); }
#line 5626 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1542:
#line 3042 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("ms.real_pseudo_forecast",(yystack_[0].value.string_val)); }
#line 5632 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1543:
#line 3043 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("ms.bayesian_prior","0"); }
#line 5638 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1544:
#line 3044 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("ms.dummy_obs",(yystack_[0].value.string_val)); }
#line 5644 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1545:
#line 3045 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("ms.nstates",(yystack_[0].value.string_val)); }
#line 5650 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1546:
#line 3046 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("ms.indxscalesstates",(yystack_[0].value.string_val)); }
#line 5656 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1547:
#line 3047 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("ms.alpha",(yystack_[0].value.string_val)); }
#line 5662 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1548:
#line 3048 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("ms.beta",(yystack_[0].value.string_val)); }
#line 5668 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1549:
#line 3049 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("ms.gsig2_lmdm",(yystack_[0].value.string_val)); }
#line 5674 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1550:
#line 3051 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("ms.specification","1"); }
#line 5680 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1551:
#line 3053 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("ms.specification","0"); }
#line 5686 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1552:
#line 3055 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("ms.q_diag",(yystack_[0].value.string_val)); }
#line 5692 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1553:
#line 3056 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("ms.flat_prior",(yystack_[0].value.string_val)); }
#line 5698 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1554:
#line 3057 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("ms.ncsk",(yystack_[0].value.string_val)); }
#line 5704 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1555:
#line 3058 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("ms.nstd",(yystack_[0].value.string_val)); }
#line 5710 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1556:
#line 3059 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("ms.ninv",(yystack_[0].value.string_val)); }
#line 5716 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1557:
#line 3060 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("ms.indxparr",(yystack_[0].value.string_val)); }
#line 5722 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1558:
#line 3061 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("ms.indxovr",(yystack_[0].value.string_val)); }
#line 5728 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1559:
#line 3062 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("ms.aband",(yystack_[0].value.string_val)); }
#line 5734 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1560:
#line 3063 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("ms.indxap",(yystack_[0].value.string_val)); }
#line 5740 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1561:
#line 3064 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("ms.apband",(yystack_[0].value.string_val)); }
#line 5746 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1562:
#line 3065 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("ms.indximf",(yystack_[0].value.string_val)); }
#line 5752 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1563:
#line 3066 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("ms.indxfore",(yystack_[0].value.string_val)); }
#line 5758 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1564:
#line 3067 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("ms.foreband",(yystack_[0].value.string_val)); }
#line 5764 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1565:
#line 3068 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("ms.indxgforehat",(yystack_[0].value.string_val)); }
#line 5770 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1566:
#line 3069 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("ms.indxgimfhat",(yystack_[0].value.string_val)); }
#line 5776 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1567:
#line 3070 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("ms.indxestima",(yystack_[0].value.string_val)); }
#line 5782 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1568:
#line 3071 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("ms.indxgdls",(yystack_[0].value.string_val)); }
#line 5788 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1569:
#line 3072 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("ms.eq_ms",(yystack_[0].value.string_val)); }
#line 5794 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1570:
#line 3073 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("ms.cms",(yystack_[0].value.string_val)); }
#line 5800 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1571:
#line 3074 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("ms.ncms",(yystack_[0].value.string_val)); }
#line 5806 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1572:
#line 3075 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("ms.eq_cms",(yystack_[0].value.string_val)); }
#line 5812 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1573:
#line 3076 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("ms.tlindx",(yystack_[0].value.string_val)); }
#line 5818 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1574:
#line 3077 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("ms.tlnumber",(yystack_[0].value.string_val)); }
#line 5824 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1575:
#line 3078 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("ms.cnum",(yystack_[0].value.string_val)); }
#line 5830 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1576:
#line 3079 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("k_order_solver","1"); }
#line 5836 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1577:
#line 3080 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("pruning", "1"); }
#line 5842 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1578:
#line 3081 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ms.chain",(yystack_[0].value.string_val)); }
#line 5848 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1579:
#line 3083 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ms.restrictions",(yystack_[0].value.string_val)); }
#line 5854 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1580:
#line 3086 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ms.duration",(yystack_[0].value.string_val)); }
#line 5860 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1581:
#line 3088 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ms.duration",(yystack_[0].value.string_val)); }
#line 5866 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1582:
#line 3090 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ms.number_of_regimes",(yystack_[0].value.string_val)); }
#line 5872 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1583:
#line 3091 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ms.number_of_lags",(yystack_[0].value.string_val)); }
#line 5878 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1584:
#line 3092 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_symbol_list("ms.parameters"); }
#line 5884 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1585:
#line 3093 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_str("ms.coefficients","svar_coefficients"); }
#line 5890 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1586:
#line 3094 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_str("ms.variances","svar_variances"); }
#line 5896 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1587:
#line 3096 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_vec_int("ms.equations",(yystack_[0].value.vector_int_val)); }
#line 5902 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1588:
#line 3098 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_vec_int("ms.equations",(yystack_[0].value.vector_int_val)); }
#line 5908 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1589:
#line 3100 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("silent_optimizer", "1"); }
#line 5914 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1590:
#line 3101 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_symbol_list("instruments"); }
#line 5920 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1591:
#line 3103 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.external_function_option("name", (yystack_[0].value.string_val)); }
#line 5926 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1592:
#line 3104 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.external_function_option("nargs",(yystack_[0].value.string_val)); }
#line 5932 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1593:
#line 3106 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.external_function_option("first_deriv_provided", (yystack_[0].value.string_val)); }
#line 5938 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1594:
#line 3108 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.external_function_option("first_deriv_provided", ""); }
#line 5944 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1595:
#line 3111 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.external_function_option("second_deriv_provided", (yystack_[0].value.string_val)); }
#line 5950 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1596:
#line 3113 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.external_function_option("second_deriv_provided", ""); }
#line 5956 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1597:
#line 3116 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("filter_covariance","1");}
#line 5962 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1598:
#line 3119 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("filter_decomposition","1");}
#line 5968 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1599:
#line 3122 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("selected_variables_only","1");}
#line 5974 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1600:
#line 3125 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("cova_compute",(yystack_[0].value.string_val));}
#line 5980 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1601:
#line 3127 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_str("ms.output_file_tag", (yystack_[0].value.string_val)); }
#line 5986 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1602:
#line 3128 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_str("ms.file_tag", (yystack_[0].value.string_val)); }
#line 5992 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1603:
#line 3129 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ms.create_init", "0"); }
#line 5998 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1604:
#line 3130 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_str("ms.simulation_file_tag", (yystack_[0].value.string_val)); }
#line 6004 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1605:
#line 3132 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ms.coefficients_prior_hyperparameters",(yystack_[0].value.string_val)); }
#line 6010 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1606:
#line 3134 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ms.convergence_starting_value",(yystack_[0].value.string_val)); }
#line 6016 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1607:
#line 3136 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ms.convergence_ending_value",(yystack_[0].value.string_val)); }
#line 6022 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1608:
#line 3138 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ms.convergence_increment_value",(yystack_[0].value.string_val)); }
#line 6028 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1609:
#line 3140 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ms.max_iterations_starting_value",(yystack_[0].value.string_val)); }
#line 6034 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1610:
#line 3142 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ms.max_iterations_increment_value",(yystack_[0].value.string_val)); }
#line 6040 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1611:
#line 3144 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ms.max_block_iterations",(yystack_[0].value.string_val)); }
#line 6046 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1612:
#line 3146 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ms.max_repeated_optimization_runs",(yystack_[0].value.string_val)); }
#line 6052 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1613:
#line 3148 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ms.function_convergence_criterion",(yystack_[0].value.string_val)); }
#line 6058 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1614:
#line 3150 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ms.parameter_convergence_criterion",(yystack_[0].value.string_val)); }
#line 6064 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1615:
#line 3152 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ms.number_of_large_perturbations",(yystack_[0].value.string_val)); }
#line 6070 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1616:
#line 3154 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ms.number_of_small_perturbations",(yystack_[0].value.string_val)); }
#line 6076 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1617:
#line 3156 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ms.number_of_posterior_draws_after_perturbation",(yystack_[0].value.string_val)); }
#line 6082 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1618:
#line 3158 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ms.max_number_of_stages",(yystack_[0].value.string_val)); }
#line 6088 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1619:
#line 3160 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ms.random_function_convergence_criterion",(yystack_[0].value.string_val)); }
#line 6094 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1620:
#line 3162 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ms.random_parameter_convergence_criterion",(yystack_[0].value.string_val)); }
#line 6100 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1621:
#line 3163 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ms.thinning_factor",(yystack_[0].value.string_val)); }
#line 6106 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1622:
#line 3164 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ms.adaptive_mh_draws",(yystack_[0].value.string_val)); }
#line 6112 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1623:
#line 3165 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ms.save_draws","1"); }
#line 6118 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1624:
#line 3166 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ms.proposal_draws",(yystack_[0].value.string_val)); }
#line 6124 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1625:
#line 3167 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ms.use_mean_center","1"); }
#line 6130 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1626:
#line 3168 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ms.proposal_type",(yystack_[0].value.string_val)); }
#line 6136 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1627:
#line 3169 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ms.proposal_lower_bound",(yystack_[0].value.string_val)); }
#line 6142 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1628:
#line 3170 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ms.proposal_upper_bound",(yystack_[0].value.string_val)); }
#line 6148 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1629:
#line 3171 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ms.parameter_uncertainty","1"); }
#line 6154 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1630:
#line 3172 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ms.horizon",(yystack_[0].value.string_val)); }
#line 6160 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1631:
#line 3173 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ms.filtered_probabilities","1"); }
#line 6166 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1632:
#line 3174 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ms.real_time_smoothed_probabilities","1"); }
#line 6172 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1633:
#line 3175 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ms.error_bands","0"); }
#line 6178 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1634:
#line 3176 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ms.percentiles",(yystack_[0].value.string_val)); }
#line 6184 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1635:
#line 3177 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ms.shock_draws",(yystack_[0].value.string_val)); }
#line 6190 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1636:
#line 3178 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ms.shocks_per_parameter",(yystack_[0].value.string_val)); }
#line 6196 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1637:
#line 3179 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ms.free_parameters",(yystack_[0].value.string_val)); }
#line 6202 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1638:
#line 3180 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ms.median","1"); }
#line 6208 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1639:
#line 3181 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("median", (yystack_[0].value.string_val)); }
#line 6214 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1640:
#line 3182 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ms.regimes","1"); }
#line 6220 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1641:
#line 3183 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ms.regime",(yystack_[0].value.string_val)); }
#line 6226 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1642:
#line 3184 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("ms.forecast_data_obs",(yystack_[0].value.string_val)); }
#line 6232 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1643:
#line 3185 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("discretionary_tol",(yystack_[0].value.string_val)); }
#line 6238 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1644:
#line 3186 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("analytic_derivation", "1"); }
#line 6244 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1645:
#line 3187 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("analytic_derivation_mode", (yystack_[0].value.string_val)); }
#line 6250 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1646:
#line 3188 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("endogenous_prior", "1"); }
#line 6256 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1647:
#line 3189 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("use_univariate_filters_if_singularity_is_detected", (yystack_[0].value.string_val)); }
#line 6262 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1648:
#line 3191 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_str("MCMC_jumping_covariance", (yystack_[0].value.string_val)); }
#line 6268 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1649:
#line 3192 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_str("MCMC_jumping_covariance", (yystack_[0].value.string_val)); }
#line 6274 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1650:
#line 3194 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_str("MCMC_jumping_covariance", (yystack_[0].value.string_val)); }
#line 6280 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1651:
#line 3196 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_str("MCMC_jumping_covariance", (yystack_[0].value.string_val)); }
#line 6286 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1652:
#line 3198 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("impulse_responses.plot_threshold", (yystack_[0].value.string_val)); }
#line 6292 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1653:
#line 3199 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("dr_display_tol", (yystack_[0].value.string_val)); }
#line 6298 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1654:
#line 3200 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_str("endo_vars_for_moment_computations_in_estimation", "all_endogenous_variables"); }
#line 6304 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1655:
#line 3201 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_str("endo_vars_for_moment_computations_in_estimation", "only_observed_variables"); }
#line 6310 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1656:
#line 3202 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("no_homotopy", "1"); }
#line 6316 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1657:
#line 3204 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_str("infile", (yystack_[0].value.string_val)); }
#line 6322 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1658:
#line 3205 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_symbol_list("invars"); }
#line 6328 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1659:
#line 3206 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("period", (yystack_[0].value.string_val)); }
#line 6334 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1660:
#line 3207 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_str("outfile", (yystack_[0].value.string_val)); }
#line 6340 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1661:
#line 3208 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_symbol_list("outvars"); }
#line 6346 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1662:
#line 3209 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("lmmcp.status", "1"); }
#line 6352 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1663:
#line 3210 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {driver.option_num("occbin", "1"); }
#line 6358 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1664:
#line 3211 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_str("function", (yystack_[0].value.string_val)); }
#line 6364 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1665:
#line 3212 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("sampling_draws",(yystack_[0].value.string_val)); }
#line 6370 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1666:
#line 3213 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_str("use_shock_groups","default"); }
#line 6376 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1667:
#line 3214 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_str("use_shock_groups", (yystack_[0].value.string_val)); }
#line 6382 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1668:
#line 3216 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { driver.option_num("colormap",(yystack_[0].value.string_val)); }
#line 6388 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1669:
#line 3219 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
          (yystack_[2].value.string_val)->append(":");
          (yystack_[2].value.string_val)->append(*(yystack_[0].value.string_val));
          delete (yystack_[0].value.string_val);
          (yylhs.value.string_val) = (yystack_[2].value.string_val);
        }
#line 6399 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1670:
#line 3227 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                  (yystack_[2].value.string_val)->append(":");
                  (yystack_[2].value.string_val)->append(*(yystack_[0].value.string_val));
                  delete (yystack_[0].value.string_val);
                  (yylhs.value.string_val) = (yystack_[2].value.string_val);
                }
#line 6410 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1671:
#line 3235 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                         (yystack_[2].value.string_val)->append(":");
                         (yystack_[2].value.string_val)->append(*(yystack_[0].value.string_val));
                         delete (yystack_[0].value.string_val);
                         (yylhs.value.string_val) = (yystack_[2].value.string_val);
                       }
#line 6421 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1672:
#line 3242 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                         (yystack_[3].value.string_val)->insert(0, "-(");
                         (yystack_[3].value.string_val)->append(":");
                         (yystack_[3].value.string_val)->append(*(yystack_[1].value.string_val));
                         delete (yystack_[1].value.string_val);
                         (yystack_[3].value.string_val)->append(")");
                         (yylhs.value.string_val) = (yystack_[3].value.string_val);
                       }
#line 6434 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1673:
#line 3251 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.vector_int_val) = new vector<int>(); (yylhs.value.vector_int_val)->push_back(atoi((*(yystack_[0].value.string_val)).c_str())); delete (yystack_[0].value.string_val); }
#line 6440 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1675:
#line 3255 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                 (yylhs.value.vector_int_val) = new vector<int>();
                 for(int i=atoi((*(yystack_[2].value.string_val)).c_str()); i<=atoi((*(yystack_[0].value.string_val)).c_str()); i++)
                   (yylhs.value.vector_int_val)->push_back(i);
                 delete (yystack_[2].value.string_val);
                 delete (yystack_[0].value.string_val);
               }
#line 6452 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1676:
#line 3265 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.vector_int_val) = (yystack_[0].value.vector_int_val);}
#line 6458 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1677:
#line 3267 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.vector_int_val) = (yystack_[0].value.vector_int_val);}
#line 6464 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1678:
#line 3269 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
              (yylhs.value.vector_int_val) = (yystack_[1].value.vector_int_val);
              for (vector<int>::const_iterator it=(yystack_[0].value.vector_int_val)->begin();
                   it!=(yystack_[0].value.vector_int_val)->end(); it++)
                (yystack_[1].value.vector_int_val)->push_back(*it);
              delete (yystack_[0].value.vector_int_val);
            }
#line 6476 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1679:
#line 3277 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
              (yylhs.value.vector_int_val) = (yystack_[2].value.vector_int_val);
              for (vector<int>::const_iterator it=(yystack_[0].value.vector_int_val)->begin();
                   it!=(yystack_[0].value.vector_int_val)->end(); it++)
                (yystack_[2].value.vector_int_val)->push_back(*it);
              delete (yystack_[0].value.vector_int_val);
            }
#line 6488 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1680:
#line 3287 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.vector_int_val) = (yystack_[1].value.vector_int_val); }
#line 6494 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1681:
#line 3289 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.vector_int_val) = (yystack_[2].value.vector_int_val); }
#line 6500 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1682:
#line 3292 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yystack_[0].value.string_val)->insert(0,"["); (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 6506 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1683:
#line 3293 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yystack_[0].value.string_val)->insert(0,"["); (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 6512 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1684:
#line 3295 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                (yystack_[1].value.string_val)->append(" ");
                (yystack_[1].value.string_val)->append(*(yystack_[0].value.string_val));
                delete (yystack_[0].value.string_val);
                (yylhs.value.string_val) = (yystack_[1].value.string_val);
              }
#line 6523 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1685:
#line 3302 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                (yystack_[2].value.string_val)->append(" ");
                (yystack_[2].value.string_val)->append(*(yystack_[0].value.string_val));
                delete (yystack_[0].value.string_val);
                (yylhs.value.string_val) = (yystack_[2].value.string_val);
              }
#line 6534 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1686:
#line 3310 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yystack_[1].value.string_val)->append("]"); (yylhs.value.string_val) = (yystack_[1].value.string_val); }
#line 6540 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1687:
#line 3311 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yystack_[2].value.string_val)->append("]"); (yylhs.value.string_val) = (yystack_[2].value.string_val); }
#line 6546 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1688:
#line 3315 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                   (yystack_[2].value.string_val)->append(",");
                   (yystack_[2].value.string_val)->append(*(yystack_[0].value.string_val));
                   delete (yystack_[0].value.string_val);
                   (yylhs.value.string_val) = (yystack_[2].value.string_val);
                 }
#line 6557 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1689:
#line 3322 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 6563 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1690:
#line 3325 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.string_val) = (yystack_[1].value.string_val); }
#line 6569 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1691:
#line 3326 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 6575 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1692:
#line 3329 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yystack_[0].value.string_val)->insert(0, "["); (yylhs.value.string_val) = (yystack_[0].value.string_val);}
#line 6581 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1693:
#line 3331 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    {
                      (yystack_[1].value.string_val)->append(" ");
                      (yystack_[1].value.string_val)->append(*(yystack_[0].value.string_val));
                      delete (yystack_[0].value.string_val);
                      (yylhs.value.string_val) = (yystack_[1].value.string_val);
                    }
#line 6592 "DynareBison.cc" // lalr1.cc:847
    break;

  case 1694:
#line 3339 "lex_yacc/DynareBison.yy" // lalr1.cc:847
    { (yystack_[1].value.string_val)->append("]"); (yylhs.value.string_val) = (yystack_[1].value.string_val); }
#line 6598 "DynareBison.cc" // lalr1.cc:847
    break;


#line 6602 "DynareBison.cc" // lalr1.cc:847
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
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
        error (yyla.location, yysyntax_error_ (yystack_[0].state,
                                           yyempty ? yyempty_ : yyla.type_get ()));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyempty)
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyempty = true;
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
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

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyempty)
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyempty)
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (state_type yystate, symbol_number_type yytoken) const
  {
    std::string yyres;
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yytoken) is
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
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (yytoken != yyempty_)
      {
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short int parser::yypact_ninf_ = -2863;

  const short int parser::yytable_ninf_ = -1715;

  const short int
  parser::yypact_[] =
  {
    4566,    38,   110,  6666,  -139,  -156,  -134,  -131,   -92,   234,
     -81,   -71,   -40,  6693,   -94,   -67,   369,   379,   -44,   -29,
    6752,    -1,   382,   198,   -13,   468,   488,   210,   517,   237,
     247,   564,  6842,   569,   597,   204,   270, -2863,   275,   337,
    6782,  9648,  9648,   273, -2863,  7121,   603,   682,  9648,   262,
     685,  6894,   757,   338,   780,   782,   339,   787,  6920,  6939,
    6958,   349,  6979,  9648,  7185,  9648,  9648, -2863,  9648,   374,
     377,   386,   789,   346, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863,   791,   351,  7031,   793,   818,   823,   825,
     828,   835, -2863,   393,   408,   413,   423,   437,   457,   399,
    3962, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863,   112, -2863, -2863,   913, -2863,
   -2863,   952, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,    85,   483,
    1922,   498,  3729, -2863,   357,  7259, -2863,   132, -2863,  1706,
     294,    50,  9648,   149,  9547,  9547,  9648,   993, -2863,  5049,
    7294,   748,   895,  2640,  1022, -2863,  1109,   965,  9648, -2863,
     859,  7368,  9648,  9648,  1034,   996,  9648, -2863,  3105,  9648,
    1043,  1005,  9648,   815,  9547,   929, -2863,   763, -2863,   934,
     533,  7207, -2863, -2863, -2863,   801,   861, -2863,  9648,  9648,
    9648, -2863,  6173,  7434,  7457,  7521,     1,  1033,   605,  5607,
     947,  7543, -2863,   302, -2863,  2599,  7570,  9547,   256,   985,
   -2863,   299,  7595,  9648,  1012,   713, -2863,  2164, -2863,  1376,
   -2863, -2863,  1830, -2863,  6395,  7630, -2863,   326,  7684, -2863,
    6649,  7706,  1083, -2863,  6522,  7770,  7822,    61,  7857,     2,
    7879,    19,  7911,    46,  9648,  7933, -2863, -2863, -2863, -2863,
   -2863,   875,   686, -2863,  2495,   831, -2863,   541,  7966, -2863,
    1542, -2863,   588, -2863,   135, -2863,  1575, -2863,   -84, -2863,
    1669,   759,   424,   580, -2863,   656,   -39,   -39,   865, -2863,
   -2863,  2722,  9648,  2759,  3291,  5942,  9441, -2863,  1273, -2863,
    1283,  1304,  1308,  1321,  1325, -2863,  1330,  1337,  1353, -2863,
    1357,  1359,  1360,  1361, -2863,  1099,   874, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863,  1375,  1378,  1379, -2863,  1117,   891,
   -2863, -2863, -2863,  1387, -2863, -2863, -2863,   914,  1140, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863,  9648, -2863, -2863, -2863,
   -2863, -2863, -2863,   939, -2863,  1424,  1433,  1434,  1441,  1442,
    1445,  1446,  1453, -2863,   -46, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863,  1460,  1462,  1468,  1476,   -14,
   -2863, -2863, -2863, -2863, -2863, -2863,  9648,   161, -2863,  1206,
     992, -2863,   995,   998,   770, -2863,  1482,  1003, -2863, -2863,
    1483,  1486, -2863, -2863, -2863,  1495,  1515, -2863, -2863,  1521,
    1524,  1526, -2863,  1531,  1534, -2863,  1536,  1537,  1540,  1546,
    1548, -2863,  1550,  1553,  1556,  1560,  1561, -2863, -2863,  1562,
    1563,  1564,  1565,  1566,  1569,  1570,  1571,  1572,  1577, -2863,
    1579, -2863,  1586,  1589,  1593,  1599,  1600, -2863, -2863, -2863,
    1605,  1620,  1623,  1629,  1638,  1673,  1676,  1677,  1681,  1682,
    1690,  1694, -2863, -2863, -2863,  1699,  1700, -2863,  1701, -2863,
    1702,  1703,  1719, -2863, -2863,  1725,  1731, -2863,  1732,  1734,
   -2863,  1736, -2863,  1739,    16, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,  9648, -2863,
    9648,   852, -2863,   396, -2863,  9648,  9648,   932, -2863,  1279,
    9648,  9648,  1728, -2863,  1286,  1085, -2863,  1742,  1744, -2863,
   -2863,  1259,  1487, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863,    -3,  3186, -2863,  1489,    84, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863,  1263,  3310, -2863,  1265,  1266,  1758,  3439,
   -2863,  1496,  1760,  1761,  1762,  1763,  1764,  1765,  1769,  1770,
    1281,  1509, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863,  3498,  1288,  1773,  3697, -2863,     3,  1301,  1306,
    1797,  3208, -2863, -2863,  1801,  1802, -2863,  1803, -2863,  1806,
   -2863, -2863,   123, -2863, -2863, -2863,  1807,  1318,   241,  9547,
   -2863,  1320,   144, -2863,  9648, -2863,   170,  1322,  3793, -2863,
    1547,  3983, -2863,  1327,  4049,  4591,  1811,  1814,  1817,  1818,
   -2863,  1819,  1820,  1842,  1843, -2863, -2863, -2863, -2863, -2863,
   -2863,  1844,  1845, -2863,  1846,  1848, -2863,   180, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,  9648,
   -2863,    47,  1363,  9687,  5646, -2863,  1365, -2863, -2863, -2863,
    1366,  1367,  1368,  1370,  5607,  5607,  1371,  1372,  1373,  1377,
    1380,  1385,  1386,  1388,  1390,  1399,  1400,  1401,  1402,  1403,
    1406,  1407,  5607,  2283, -2863,  1409,  1854, -2863,   200, -2863,
   -2863, -2863,  1864,  1867, -2863,  1876,  1899, -2863, -2863,  1903,
     203, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863,  1419,  9648,  9648,   316, -2863,
   -2863,  1420,  1911,  1913,  1426,  1654, -2863, -2863, -2863, -2863,
   -2863,  4074, -2863,  1920,  1921,   260, -2863, -2863,   211, -2863,
    1927,  1929,  1939,  1940,  1941,  1454,  1680, -2863, -2863, -2863,
   -2863, -2863,  5407,   269, -2863,  1945,  1948, -2863,   389, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863,  1953,  1955,   405,
   -2863, -2863, -2863, -2863, -2863,   406, -2863, -2863, -2863, -2863,
     958,   248, -2863,  1956,  1957,   414, -2863, -2863, -2863, -2863,
   -2863, -2863,  1958,  1960,  9648, -2863,    74,  1363, -2863,  9648,
   -2863,    87,  1363, -2863,  9648, -2863,    96,  1363, -2863,  8020,
   -2863,  9648, -2863, -2863,  1964,  1965,  1966,  1967,  1968,  1969,
    1971,  1974,  1975,  1978,  1980,  1981,  1982,  1984,  1985,  1986,
    1993,  1996,  1997,  1998,  1999,  2000,  2002,  2004,  2007,  2008,
    2009,  2010,  2011,  2013,  2015,  2019,  1530,  1753, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
    2023,  2024,  2025,  2026,  2028,   416, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863,  2029,  2032,  2036,  2037,  2044,  2047,
    2049,  2051,  2052,  2053, -2863,  2055, -2863,  2056,  2057,  2059,
    2060, -2863,  2061,  2062,  2064,  2065,  2067,  2068,  2074,  2075,
    2077,  2078,  2079,  2080,  2100,  2101,  2105,  2106,  2109,  2110,
    2111,  2112,  2113,  2114,  2117,  2125,  2126,  2127,  2128,  2130,
    1787,  1641, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
    2132, -2863, -2863,  2133,  2136,  2137,  2138,  2154,  2155,  2156,
    2158,  2159,  2162, -2863,  2163,  1902,  1684, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863,  1904,  1688, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,  2172,
   -2863,  2181,  2194,  2196,  2200,  2201,  2202,  2206,  2208,  2209,
    2213,  2214,  2215,  2216,  2219,  2220,  1961,  1733, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863,  2221,  2225, -2863,  2226,  1970,  1737, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863,  2228,  2229,  2230,  2232,
   -2863,  1973,  1747, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863,  1976,  1748, -2863, -2863, -2863, -2863,  2240,  1979,
    1754, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863,   -70,  2243,  2245,  2248,  2255,
    2265,  2267,   426, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863,  2269,   465, -2863, -2863, -2863, -2863, -2863,  2271,
    2273,  2274,  2277,   469, -2863, -2863, -2863, -2863, -2863,  2290,
    2293,   471, -2863, -2863, -2863,   472, -2863,  1810,  1812,  1808,
    1800,   475, -2863,  2300,  1813,  1815,  1821,  1816,  1824,  1825,
    1828,  1822, -2863,  1832,  1835,  1836,  1837, -2863,  5942,  5942,
    1838,  1839,  1841,  1847,  1849,  1851,  1852,  1853,  1858,  1859,
    1860,  1862,  1865,  1866,  5942,  4743, -2863,  1868, -2863,  1869,
     102,  1861,   241,   658,   241,  2250,   658,  2251,  9547,  2252,
     134,  2263,  2276,  9648,  9648,  1922,  2278,  2281,   241,  2287,
    3729,  2303,  1870,  8884,   357, -2863,  9648,  2304,  2306,  2310,
     241,   241,  2311,   241,  2312,  1706,  1882,  1889,  1041,  2315,
    2323,   294,  1892,  1893,  1895, -2863,  9648, -2863,  8919,  8938,
    1896, -2863,  5942,  1901,  2329,  2191,   241,  9648,   241,   241,
    2335,  9547,   134,   532,   134,  2336,  1905,   241,  2337,   241,
     241,  2339,  2340,   352,   241,   241,   241,   241,   241,   241,
    2344,  2366,  2371,  2373,   412,  2375,  2376,  9402,  9547,  2388,
    1870,  1959,  9493,  2390,   108,   241,   238,  1198,  9648,   746,
     904,  1962,  2393,  2396,   241,   329,  2398,  1338,   241,  2399,
     362,  1972,  2400,  5049,  8968,  2070, -2863,  1983, -2863,   425,
   -2863,  2195,  2197,  1987, -2863,  5942,  2199,  2203,  1988, -2863,
    5942,  1992,  2401,  2403,  1995,  1109,  2408,  2012,  2020, -2863,
    5942,   859,  9020,  1977,  2021, -2863,   209,  2022,  9547,  2030,
   -2863,  5942,   658,  2411,  2413,   209,  2414,  2417,  5459,  2418,
    2031,  3105,  2033,  2034,  9547,  2035, -2863,  9648,  2425,  2038,
    2069, -2863,  2350,  9648,  2207, -2863,   253, -2863,   241,  2018,
    2440,  2027,   763,  2091,   213,  9547,  2090,  2092,   241, -2863,
    2098,  2099,  2131, -2863,  2134,  2139, -2863,  9648,  2140, -2863,
    5942,  2142,  5179,  9648,  4778,   241,  2443,  2455,  9350,   241,
    2456,   241,  2457,   241,  2458,  2461,  2464,  6173,  9111,   117,
    1363, -2863, -2863,  9648, -2863,  2498,  6644, -2863, -2863, -2863,
    5607,  5607,  5607,  5607,   494,  2249,  5607,  5607,  5607,  5607,
    5607,  5607,  5607,  5607,  5607,  5607,  5607,  5607,  5607,  5607,
    5607,   209,   880,  5607,  5607,  5607,  5607,  5607,  5607,  5607,
    5607,  5607,  5607,  5607,  2143,  2129,  2468,   302,  2145,   241,
     241,  2502,   241,  2546,  2599,  2146,  2147,  2351,   136,  2148,
   -2863,  2149,  9648,  9648,  9165,   299,  2151, -2863,  9648,  9648,
     241,   241,  5942,  -143,   375, -2863, -2863,  2164,  2152,  9547,
    2135,  9547,  2153,  2559,  2157,  1376,  9648,   189, -2863,  2621,
    1830,  2173,   241,  1870,  6395,  9195,  2174,  5942,   326,  9214,
    6649,  9247,  5942,  5942,  5942,  5942,  2176, -2863,  2569,   241,
    6522,  9266, -2863, -2863,   119,  1363, -2863, -2863,   150,  1363,
   -2863, -2863,   155,  1363, -2863, -2863,  9648, -2863, -2863, -2863,
    2570,  2585,  2587,  2588,  2606,  2609,  2610,  2611,  2615,  2617,
    2618,  2619,  2623,   241,   241,  2624,  2193,   241,   241,  2198,
    2204,  2205,  2629,  2634,  2212,   241,  2636,   241,   241,   241,
     241,   241,  2231,   875,  9547,  9648,   965,   965,  2639,   686,
    2233,   225,  2641,  2646,  2660,  2661,  9547,  2667,  2235,  2669,
      91,  2670,  2671,  2673,  2674,  2675,   241,   241,  2676,  2677,
    2678,  2681,  2682,  2683,   241,  2684,  2685,  2686,  2687,  2688,
    2691,  2692,  2693,  2694,  2696,  2698,  2699,  2700,  2701,  2703,
    2704,  2705,  2706,  1959,  2495,  2275, -2863,  2708,  9547,  2710,
    9547,  9547,  1959,  2713,  2714,  1959,   658,  2716,   541,  9301,
    1542,  2286,   391,   241,   241,   241,  2719,   241,  2720,  2721,
     241,   241,  2723,  2725,  2727,  2728,   241,   241,   588,  2299,
    2732,  2733,  2734,   135,  2308,  2735,   658,   658,  2736,  1575,
    2317,   -84,  2318,  2738,  1669,  2320,  2358,   -76,  2321,  2324,
     323, -2863,  2307,  2309,  2743,   145,  2747,  2755,   424,  2325,
     134,   580,  2326,  9547,  2760,  9547,  9547,   656,  2327,  9547,
    2762,   -39,  2331,  2332,  2333,  9648,  9648, -2863,  2763,  9648,
    2347,   965,  9648,  9648, -2863,  9723,  9648,  9648, -2863,  9605,
    5942,  5942,  5942,  5942,  2556,  2556,  5942,  5942,  5942,  5942,
    5942,  5942,  5942,  5942,  5942,  5942,  5942,  5942,  5942,  5942,
    2169,  5942,  5942,  5942,  5942,  5942,  5942,  5942,  5942,  5942,
    5942,  5942, -2863,  2357,  1028,  2367,    81, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863,   154, -2863,    77, -2863,
   -2863, -2863, -2863, -2863,  2342, -2863,  2359, -2863, -2863, -2863,
   -2863,  2369, -2863, -2863,  8106, -2863,  8160, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,  9648, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
    2680, -2863,  2370, -2863,  8193, -2863,  8215, -2863,  5069,  9648,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863,   557, -2863, -2863, -2863, -2863,  9648,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863,   344,   829, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863,   813,   184, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863,  2665, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863,  2672, -2863, -2863, -2863,  8247,  9648, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863,  5715,  2607,  2381,  2614,
    9648,  5942, -2863,  2384,  9648,  5942, -2863,  6892,  2050, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863,  3175, -2863, -2863,  8269,
    9528, -2863, -2863,  2827,  2835,  2402,  9648,  2406, -2863,  3826,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863,  9648,  2407, -2863,  2635,  -138,  2409,  9648, -2863,
    5607,  2900,     6, -2863,  2901,  2415, -2863, -2863,  5607, -2863,
   -2863,  9648, -2863,  9547, -2863, -2863, -2863, -2863,  7230, -2863,
     241,  2412, -2863, -2863,  2731, -2863,   801, -2863,    73, -2863,
    2442, -2863,  9648,  7231,  5942, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863,  8302,  1363, -2863, -2863, -2863,  2712, -2863, -2863,  4190,
    5813,  2830,  2883,  3122,  3194,  3349,  3493,  3512,  3555,  3615,
    3762,  3844,  3957,  3975,  4014,   896,  1078,  4033,  2420, -2863,
    1874,  1874,   756,   756,   756,   756,   494,   494,  2249,  2249,
    2637, -2863,  5607,  2421, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863,  9648,  5942,  9648,   101, -2863,   256,
   -2863, -2863, -2863,  8356, -2863, -2863,  8442, -2863,  2422, -2863,
   -2863,  4091,   260,  2426,   263,  5942, -2863, -2863, -2863, -2863,
    9648, -2863,  9648, -2863, -2863, -2863,  5066,  2427, -2863,  5942,
   -2863, -2863, -2863, -2863, -2863, -2863,  8496,  9648,  5359, -2863,
   -2863,  8529, -2863, -2863,  8551,  8552,  8905,  8940,  9151, -2863,
   -2863, -2863, -2863, -2863,  8583,  5607,  5607,  1363, -2863, -2863,
    1363, -2863, -2863,  1363, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863,   412,   171, -2863, -2863, -2863,  1469,  1469,
    1469, -2863, -2863,  1469, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863,  2647,  2647, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,  9648,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,  5607,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863,  8605, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863,  2863,  2864,  2435, -2863, -2863,  2436, -2863,  9648,   226,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863,   283,  2662,  2437, -2863, -2863,   187,
    2663,  2438,  2434,  2444,  2668,  2445, -2863,  2446,  5917,  6804,
    4281,  4354,  4390,  4448,  4486,  4637,  5089,  5528,  5756,  5770,
    5797,  5835,  5873,  5903,  1516,  2016, -2863,  1917,  1917,   968,
     968,   968,   968,   575,   575,  2556,  2556,  2637,  5942,  2930,
    2937,  2938,   476, -2863, -2863, -2863, -2863,   775,  2451,  2942,
    2450,  2889, -2863, -2863,    89, -2863, -2863,  9648, -2863, -2863,
   -2863,  9648, -2863, -2863,  5915,  2890,  2453, -2863, -2863, -2863,
    4131, -2863,   477,  6169, -2863, -2863,   658, -2863,   224, -2863,
   -2863,  2690, -2863,   485,  2702, -2863,   492, -2863, -2863,   425,
   -2863,  5942,  2707,  6823,  5942,  2715,  9831, -2863,  2462,  2175,
    5942, -2863, -2863,  2460,   105,  2459, -2863, -2863,  2955,  4472,
    2469,  5942, -2863,  4734,  2471,   560,  2717,  2912,  2724,  5022,
    5985,  2773,  2350,  5607,  5607, -2863,  9844,  6417, -2863,   493,
    3208, -2863,  2466, -2863,  2890,   236,   560,   572,  2483,  5942,
   -2863,  9940, -2863, -2863, -2863,  5607,  5607, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863,  5607, -2863,  5607, -2863, -2863,  2484,  2283,   499,  9648,
    2975,  9953,  2977,  5942,   319, -2863,  9648, -2863, -2863,  2496,
   -2863,   375, -2863,  5942, -2863,  6178,  6555,  6576,  2983, -2863,
    9966, -2863,  6595, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
    6215,  6228, -2863, -2863, -2863, -2863, -2863, -2863, -2863,  9804,
    2500,  2522,  2523,  2525,  6614,  6379, -2863,  2729,  2497, -2863,
   -2863,  5380, -2863,     9,  2986,  3018,  3019,  3020,  3021,  3022,
    3023,  3024,  3026,   506, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863,  9648,  2534,   965,  9648,  2535,
    2689,  9648,  2536,  2969,  5942,  5942, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
    5942, -2863,  5942, -2863,  5359,   508,  2193,   241,   658,  1028,
    2551,  3040,  3044,   509, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863,  1028,  2557,  2989, -2863, -2863,
   -2863, -2863, -2863, -2863,  2553,   139,  9577,  2563,   557, -2863,
   -2863, -2863, -2863, -2863,   817,  2665, -2863,   233,  2672, -2863,
    5359,  2789,  2791,  2792, -2863,  5942,  5942,  9979,  5942, -2863,
   -2863,  2568,  9992,  1028,  2572,   129,  5942,  2576, -2863, 10005,
    2577, -2863, -2863, -2863,   412,  2580,  9648, -2863,  9648,  2581,
    9648, -2863, -2863,   322, 10018, -2863, -2863,  9547, -2863,  3239,
   -2863,   159,  2583,  2586,   133,  -110,  2567, -2863, 10031, -2863,
    6950,  6963,  7435,  7501,  5607,  5607, -2863,  8638,  5942, -2863,
    5942, 10044,  2616, -2863,  9648,  7090, -2863, -2863, -2863,  5942,
   -2863, -2863,  9648,  9648, -2863, -2863, -2863, -2863, -2863,  9648,
   -2863,  2711, -2863,  1959, -2863,   658,  1959,   241,  2309,   658,
    1959,  1897,  1959,  1959,   283,  2620,  2643,  3037,  2647,  2644,
    9774, -2863,  2645,  9629, -2863,  7146,  7190,  7571,  7747,  5942,
   -2863, -2863, -2863, -2863, -2863, -2863,   658,  5942,   775,  2651,
     512,   775, -2863,  3051,  2649,  3053,  2892, -2863,  2622,   107,
    2650, -2863, -2863, -2863, -2863, -2863, -2863,  2945, -2863, -2863,
    5942,  5942,  5942,  7837, 10057, -2863, 10070, -2863, -2863,   514,
     775,  2655,  3157, 10083, -2863, -2863, -2863,   709, -2863,  2895,
    2898, -2863,  8692,  2921,  5607, -2863, -2863, -2863,  2695,  2917,
   -2863, -2863,   209,  2905,   209,  2909, -2863, -2863, -2863,  5607,
    5607,  7260,  2283, -2863, 10096, 10109, -2863, -2863,  5042, -2863,
   10122,  8778,   165,  8832,  8865,  2932,  5206,  3118,  2756, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
    2697,  2730,  2434,  2737,  2740, -2863,  2741, -2863, -2863,  5942,
    5942,  5359, -2863,  5359, -2863, -2863,  2745,   543, -2863,  3119,
    2744,   308,  1028,  2742,   142,  2914, -2863,   546,  2915, -2863,
    2922,  5942, -2863, -2863,  2751,   548,  1028,  2752, -2863,   412,
    2718,   560,   560,  9648, -2863,  2946, -2863, 10135, -2863,   308,
    2748,   560, -2863,   560,  7487,  7596, -2863, -2863, -2863,  2757,
   -2863,  9648, -2863,   168,  1363, -2863, -2863,  9648, -2863,  2952,
   -2863,  5228,  5563,  2754,  6561,  3209,  5206, -2863,  2923,  3166,
    3156,  9832,  2873,  9668,  3177,  7823,  7880, -2863,  2765, -2863,
    3191,  5942,   141, -2863,   551,   775,  2761,  3251,   824,  2945,
   -2863,   267,  5942, 10148, -2863,  2768,   552,   775,  2766, -2863,
    2769,  2771,  3025, -2863, -2863,   372,   209,  2774,  2775, -2863,
   -2863, -2863,   173,  1363, -2863, -2863,  3028, -2863,  2772,  2776,
    9648,  5585, -2863,  6561, -2863,  9648,  3004,  2434,  2778, -2863,
   -2863,  2779, -2863, -2863, -2863, -2863, -2863,  8161,   347, -2863,
    5942, -2863,  2787,   553,  1028,  2790, -2863, -2863, -2863,  3027,
    3031, -2863, -2863,  2793,   554, -2863, -2863, -2863, -2863, -2863,
    2794, -2863, -2863,  1363, -2863, -2863, -2863,  9648,  9648,  3034,
    2796,  5206,   415, -2863,  9648,  2911,  3217, -2863,  5942, -2863,
    8216, -2863,  2800,   558,   775,  5942,  5942, -2863,  2801, -2863,
   -2863,  3035,  3038,  3235,  9648,  2812,  9648, -2863,   449, -2863,
   -2863,  8497, -2863, -2863,  2816,   559, -2863,  3043, -2863,  3253,
    3256,  2817,  3052, -2863, -2863, -2863, -2863, -2863,  2826,  5942,
    2828,  2829, -2863,  3260, -2863,  5359, -2863, -2863,  2838, -2863
  };

  const unsigned short int
  parser::yydefact_[] =
  {
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1695,     0,     0,
       0,     0,     0,     0,   874,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   803,     0,     0,
       0,     0,     0,     0,  1696,  1697,  1699,  1698,  1700,  1701,
    1702,  1703,  1704,  1705,  1706,  1707,  1708,  1709,  1710,  1711,
    1713,  1712,  1714,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   345,     0,     0,     0,     0,     0,     0,     0,
       0,     2,    39,    40,    76,    77,     5,     6,     7,     8,
       4,     9,    10,    16,    12,    13,    14,    15,    91,    11,
      17,    70,    71,    72,    73,    18,    19,    20,    21,    48,
      92,    93,    94,    95,    22,    74,    23,    25,    27,    26,
      43,    28,    29,    32,    33,     0,    30,    31,     0,    34,
      35,     0,    24,    36,    37,    38,    41,    42,    44,    45,
      46,    60,    61,    62,    47,    49,    50,    51,    52,    53,
      63,    64,    65,    66,    54,    55,    56,    84,    82,    83,
      81,    80,    79,    78,    57,    58,    59,    67,    69,    68,
      75,    85,    86,    87,    88,    89,    90,    96,     0,     0,
       0,     0,     0,  1222,     0,     0,   530,     0,   422,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   683,     0,
       0,     0,     0,     0,     0,  1235,     0,     0,     0,  1191,
       0,     0,     0,     0,     0,     0,     0,   838,     0,     0,
       0,     0,     0,     0,     0,     0,   276,     0,   865,     0,
     868,     0,   864,   428,   432,     0,     0,  1245,     0,     0,
       0,   828,     0,     0,     0,     0,   182,     0,     0,     0,
       0,     0,   433,     0,   439,     0,     0,     0,     0,     0,
     913,     0,     0,     0,     0,     0,   461,     0,  1263,     0,
    1216,   410,     0,   474,     0,     0,   877,     0,     0,   881,
       0,     0,     0,   892,     0,     0,     0,     0,     0,   146,
       0,   158,     0,   170,     0,     0,   194,   910,   911,   912,
    1124,     0,     0,   996,     0,     0,  1050,     0,     0,  1014,
       0,  1122,     0,  1083,     0,  1072,     0,  1060,     0,  1032,
       0,     0,     0,     0,   368,     0,     0,     0,     0,     1,
       3,     0,     0,     0,     0,     0,     0,   936,     0,  1449,
       0,     0,     0,     0,     0,  1420,     0,     0,     0,  1421,
       0,     0,     0,     0,   924,   935,     0,   925,   930,   928,
     931,   929,   926,   927,   932,   933,   917,   918,   919,   920,
     921,   922,   923,   944,     0,     0,     0,   938,   943,     0,
     940,   939,   941,     0,  1405,  1391,  1598,     0,  1227,  1230,
    1233,  1231,  1232,  1228,  1229,  1234,     0,  1224,   528,   196,
     197,   198,   199,     0,  1512,     0,     0,     0,     0,     0,
       0,     0,     0,   426,     0,   425,   414,   419,   421,   418,
     427,   415,   416,   417,   420,     0,     0,     0,     0,     0,
    1203,  1206,  1205,  1207,  1208,  1209,     0,     0,  1213,     0,
       0,    97,     0,     0,     0,   256,     0,     0,  1425,  1644,
       0,     0,  1395,  1589,  1521,     0,     0,  1654,  1655,     0,
       0,     0,  1646,     0,     0,  1358,     0,     0,     0,     0,
       0,  1407,     0,     0,     0,     0,     0,  1390,  1393,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1422,
       0,  1383,     0,     0,     0,     0,     0,  1403,  1404,  1423,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1359,  1394,  1357,     0,     0,  1426,     0,  1378,
       0,  1398,     0,  1406,  1402,     0,     0,  1400,     0,     0,
    1597,     0,  1599,     0,     0,   688,   738,   744,   764,   724,
     752,   767,   689,   783,   784,   690,   750,   691,   788,   692,
     693,   694,   695,   696,   697,   698,   699,   700,   701,   772,
     702,   703,   704,   789,   786,   787,   705,   706,   707,   708,
     709,   711,   710,   712,   713,   714,   715,   716,   717,   719,
     720,   722,   723,   725,   726,   727,   728,   729,   730,   721,
     731,   732,   733,   734,   735,   736,   737,   768,   769,   739,
     740,   741,   742,   743,   745,   746,   753,   754,   755,   756,
     757,   758,   759,   760,   761,   762,   775,   776,   777,   778,
     780,   779,   781,   782,   718,   785,   747,   748,   749,   751,
     763,   765,   766,   770,   771,   773,   774,   685,     0,   554,
       0,     0,   548,     0,   552,     0,     0,     0,   574,     0,
       0,     0,     0,   568,     0,     0,  1301,     0,     0,  1662,
    1663,     0,  1238,  1239,  1240,  1241,  1242,  1243,  1244,   599,
     600,     0,     0,   580,     0,     0,  1195,  1197,  1199,  1200,
    1201,  1198,  1193,     0,     0,   261,     0,     0,     0,     0,
    1187,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   841,   850,   842,   849,   853,   855,   856,   857,   859,
     854,   858,   848,   851,   844,   843,   845,   846,   847,   852,
     860,   861,     0,     0,     0,     0,  1258,     0,     0,     0,
       0,     0,   264,   267,     0,   270,  1285,     0,   269,     0,
     268,   275,     0,   272,   265,   266,     0,     0,     0,     0,
     862,   870,     0,   431,     0,   388,     0,     0,     0,  1251,
       0,     0,   810,     0,     0,     0,     0,     0,     0,     0,
    1576,     0,     0,     0,     0,  1290,  1291,  1292,  1414,  1413,
    1577,     0,     0,  1318,     0,     0,   821,     0,   820,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   490,   491,
     495,   496,   498,   499,   500,   822,   823,   824,   501,   503,
     502,   504,   505,   826,   510,   492,   493,   494,   825,   521,
     489,   497,   506,   507,   508,   509,   513,   514,   515,   516,
     517,   518,   511,   512,   827,   519,   520,   830,   818,     0,
     136,   180,   188,     0,     0,   185,     0,   203,   537,   536,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   875,   294,   293,     0,  1210,     0,   436,
     437,   438,     0,     0,  1392,     0,     0,  1656,  1284,     0,
       0,   442,   450,   443,   447,   446,   453,   454,   444,   445,
     448,   449,   451,   452,    99,     0,     0,     0,     0,   338,
     339,     0,  1666,     0,     0,  1181,  1183,  1182,  1184,  1185,
     915,     0,  1275,     0,     0,     0,   465,   466,     0,   464,
       0,     0,     0,     0,     0,     0,  1266,  1267,  1268,  1269,
    1270,  1271,     0,     0,   413,     0,  1304,  1522,     0,   522,
     479,   527,   526,   523,   524,   525,   476,     0,     0,     0,
     902,   903,   904,   879,   907,     0,   906,   908,   909,   883,
       0,     0,   887,     0,     0,     0,   897,   898,   900,   899,
     894,   812,     0,     0,     0,   116,   144,   152,   149,     0,
     133,   156,   164,   161,     0,   134,   168,   176,   173,     0,
     807,     0,   135,   192,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1127,  1175,  1161,
    1162,  1163,  1164,  1165,  1177,  1166,  1167,  1168,  1169,  1170,
    1172,  1171,  1176,  1128,  1129,  1130,  1131,  1132,  1133,  1134,
    1135,  1136,  1137,  1138,  1139,  1140,  1141,  1142,  1143,  1144,
    1153,  1145,  1146,  1154,  1156,  1155,  1147,  1148,  1157,  1149,
    1150,  1151,  1152,  1158,  1159,  1160,  1173,  1174,  1178,  1179,
       0,     0,     0,     0,     0,     0,   605,   606,   607,   608,
     609,   610,   611,   612,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1540,     0,  1541,     0,     0,     0,
       0,  1543,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     995,     0,   946,   992,   947,   948,   949,   950,   951,   952,
     953,   954,   955,   956,   957,   958,   959,   960,   961,   962,
     963,   964,   965,   966,   967,   968,   969,   970,   971,   972,
     973,   974,   975,   976,   977,   978,   979,   980,   981,   982,
     983,   984,   985,   986,   987,   988,   989,   990,   991,   993,
       0,  1629,  1640,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1638,  1631,     0,  1049,     0,  1034,  1035,  1036,
    1043,  1037,  1038,  1039,  1040,  1041,  1042,  1044,  1045,  1047,
    1046,  1052,  1633,  1013,     0,   998,   999,  1000,  1006,  1010,
    1011,  1001,  1002,  1003,  1004,  1005,  1007,  1009,  1008,     0,
    1603,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1121,     0,  1091,  1092,
    1093,  1086,  1087,  1088,  1089,  1090,  1094,  1095,  1096,  1097,
    1098,  1099,  1100,  1101,  1102,  1103,  1104,  1085,  1105,  1106,
    1107,  1108,  1109,  1110,  1111,  1112,  1113,  1114,  1115,  1116,
    1117,  1118,  1119,     0,     0,  1623,     0,  1082,     0,  1077,
    1076,  1074,  1075,  1078,  1079,  1080,     0,     0,     0,     0,
    1625,  1071,     0,  1062,  1063,  1064,  1068,  1069,  1065,  1066,
    1067,  1632,  1059,     0,  1054,  1055,  1056,  1057,     0,  1031,
       0,  1016,  1017,  1018,  1023,  1028,  1029,  1020,  1021,  1022,
    1024,  1025,  1027,  1026,  1019,     0,     0,     0,     0,     0,
       0,     0,     0,   371,   372,   374,   373,   375,   376,   377,
    1585,  1586,     0,     0,   380,   384,   381,   382,   383,     0,
       0,  1594,  1596,     0,   469,   470,   471,   472,   473,     0,
       0,     0,   458,   459,   460,     0,   624,     0,     0,     0,
       0,     0,   619,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   245,     0,     0,     0,     0,   244,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   208,   207,   615,   677,
     620,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   529,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1214,     0,    98,     0,     0,
       0,   255,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   551,     0,   547,   248,
     550,     0,     0,     0,   573,     0,     0,     0,     0,   567,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   579,
       0,     0,     0,     0,     0,   260,     0,     0,     0,     0,
    1188,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1259,     0,     0,     0,
       0,   108,     0,     0,     0,   282,     0,   283,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   872,     0,   432,
       0,     0,     0,   387,     0,     0,  1252,     0,     0,   809,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   181,
     186,   183,   191,     0,   138,     0,     0,   142,   140,   204,
       0,     0,     0,     0,   308,   307,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     337,     0,     0,     0,     0,     0,     0,  1274,     0,     0,
       0,     0,     0,     0,   403,   540,   409,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1219,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   886,     0,     0,
       0,     0,   119,   117,   145,   150,   147,   155,   157,   162,
     159,   167,   169,   174,   171,   179,     0,   804,   805,   193,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   100,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   348,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   614,     0,     0,
       0,     0,     0,     0,   658,     0,     0,     0,   676,     0,
       0,     0,     0,     0,   221,   220,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   205,     0,     0,     0,     0,  1445,  1446,  1447,
    1448,  1444,  1450,  1325,  1335,  1673,     0,  1329,     0,  1328,
    1353,  1354,  1415,  1416,     0,   934,     0,  1451,  1369,  1401,
     942,     0,  1417,  1223,     0,  1226,     0,   200,  1509,  1510,
    1511,  1311,  1315,  1302,  1322,  1281,   424,   423,     0,  1520,
    1514,  1515,  1517,  1516,  1518,  1519,  1298,  1287,  1204,  1202,
       0,  1212,     0,   834,     0,   832,     0,   253,     0,     0,
    1289,  1334,  1327,  1377,  1441,  1442,  1443,  1326,  1333,  1332,
    1362,  1364,  1363,  1365,     0,  1360,  1331,  1330,  1293,     0,
    1652,  1408,  1409,  1410,  1355,  1356,  1433,  1435,  1432,  1434,
    1436,  1437,  1370,  1373,  1379,  1374,  1388,  1389,  1371,  1372,
     543,     0,     0,   545,   544,  1384,  1386,  1385,  1381,  1382,
    1380,  1427,  1418,     0,     0,  1419,  1649,  1648,  1650,  1651,
    1452,  1453,  1455,  1454,  1456,  1457,  1459,  1458,  1460,  1461,
    1462,  1463,  1464,  1465,  1466,  1467,  1468,     0,  1286,  1424,
    1387,  1397,  1396,  1399,  1430,  1429,  1431,  1647,  1438,  1439,
    1440,     0,  1600,   687,   684,     0,     0,   546,   591,   592,
     594,   595,   597,   593,   596,   598,   249,     0,     0,     0,
       0,     0,   572,     0,     0,     0,   564,     0,     0,  1300,
    1299,  1236,  1237,   601,   602,   578,     0,  1196,  1192,     0,
       0,   258,   535,     0,     0,     0,     0,     0,  1186,     0,
    1645,  1504,  1508,  1507,  1506,  1505,  1499,  1500,  1474,   839,
     840,   250,     0,     0,  1256,     0,     0,     0,     0,   836,
       0,   291,     0,   289,     0,     0,   280,   281,     0,   285,
    1314,     0,  1317,     0,   274,   278,  1411,  1412,     0,   869,
       0,     0,   430,   429,     0,   385,     0,  1250,     0,   808,
       0,   813,     0,     0,     0,   816,  1653,  1280,  1288,  1312,
    1313,  1295,  1296,  1308,  1307,  1321,  1319,  1282,  1320,   819,
     829,     0,   187,   184,   189,   139,     0,   143,   141,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   292,
     303,   304,   299,   300,   301,   302,   295,   296,   298,   297,
     305,   876,     0,     0,   435,   434,  1309,  1310,  1303,  1316,
    1283,   441,   440,   837,     0,     0,     0,     0,   335,     0,
    1667,  1668,   914,     0,  1180,  1272,     0,  1279,     0,   538,
     539,     0,     0,     0,     0,     0,   407,   463,   462,  1657,
       0,  1660,     0,  1659,  1264,  1265,     0,     0,  1218,     0,
     412,   411,  1297,  1305,   478,   475,     0,     0,  1428,   901,
     878,     0,   905,   882,     0,     0,     0,     0,     0,   885,
    1306,  1643,   896,   893,     0,     0,     0,   151,   148,   153,
     163,   160,   165,   175,   172,   177,   806,  1469,  1470,  1471,
    1472,  1473,  1475,  1476,  1477,  1478,  1479,  1480,  1481,  1482,
    1483,  1484,  1485,     0,     0,  1486,  1487,  1488,     0,     0,
       0,  1492,  1493,     0,  1495,  1496,  1497,  1498,  1501,  1502,
    1503,  1125,  1126,  1323,  1324,  1336,  1337,  1338,   604,   603,
    1525,  1526,  1527,  1528,  1529,  1530,  1531,  1532,  1533,     0,
    1535,  1536,  1537,  1538,  1539,  1542,  1544,  1545,  1546,  1547,
    1548,  1559,  1556,  1570,  1571,  1575,  1549,  1552,  1553,  1554,
    1555,  1557,  1558,  1560,  1561,  1562,  1563,  1564,  1565,  1566,
    1567,  1568,  1569,  1572,  1573,  1574,  1605,   994,   997,     0,
    1641,  1601,  1630,  1604,  1602,  1634,  1636,  1635,  1637,  1639,
    1621,  1048,  1051,     0,  1012,  1015,  1550,  1551,  1606,  1607,
    1608,  1609,  1610,  1611,  1612,  1613,  1614,  1615,  1616,  1617,
    1618,  1619,  1620,  1120,  1123,  1523,  1524,  1622,  1081,  1084,
    1626,  1628,  1627,  1624,  1070,  1073,  1058,  1061,  1642,  1030,
    1033,     0,     0,     0,   354,   355,     0,   347,     0,     0,
    1691,  1579,  1578,  1580,  1581,  1582,  1583,   370,   369,  1588,
    1587,   379,   378,  1591,  1592,  1593,  1595,   468,   467,  1664,
    1665,   457,   455,   456,     0,     0,     0,   618,   613,     0,
       0,     0,   659,     0,     0,     0,   677,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   206,   218,   219,   214,
     215,   216,   217,   209,   210,   212,   211,   213,     0,     0,
       0,     0,     0,   672,   673,   674,   675,     0,   678,   622,
    1673,     0,  1674,  1676,     0,  1680,  1678,     0,   937,   945,
    1225,     0,   195,   201,     0,     0,     0,   835,   833,   257,
       0,  1366,     0,     0,   541,   542,     0,  1682,     0,  1686,
    1684,     0,   792,     0,     0,   801,     0,   686,   553,   248,
     549,   248,     0,     0,     0,     0,     0,   571,     0,     0,
       0,  1194,   616,   679,   626,     0,   533,   534,     0,     0,
       0,     0,  1190,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   277,     0,     0,   866,     0,
       0,   863,     0,   871,     0,     0,     0,     0,     0,     0,
     814,     0,   831,   190,   137,     0,     0,   320,   321,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   330,
     319,     0,   327,     0,   329,   331,     0,   332,     0,     0,
       0,     0,     0,     0,     0,   916,     0,  1276,  1278,     0,
     408,   402,   395,     0,   405,     0,     0,     0,     0,  1217,
       0,   477,     0,   880,   884,   888,   889,   890,   891,   895,
       0,     0,   154,   166,   178,  1692,  1694,  1693,   532,   531,
       0,     0,     0,     0,     0,     0,  1053,     0,     0,   350,
     346,     0,  1689,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   647,   648,   656,   654,   649,   652,
     651,   657,   655,   653,   650,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   233,   234,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   243,   232,
       0,   240,     0,   242,   246,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   635,   636,   644,   642,   637,   640,
     639,   645,   643,   641,   638,     0,     0,     0,  1677,  1681,
    1679,  1669,   202,  1513,   394,     0,     0,     0,     0,  1361,
    1294,  1683,  1687,  1685,     0,     0,  1375,     0,     0,  1376,
     249,     0,     0,     0,   555,     0,     0,     0,     0,   569,
     565,     0,     0,     0,     0,     0,     0,     0,   263,     0,
       0,   252,  1248,  1249,     0,     0,     0,  1670,     0,     0,
       0,   290,   288,     0,     0,   284,   271,     0,   273,     0,
     873,     0,     0,     0,     0,     0,     0,   811,     0,   817,
       0,     0,     0,     0,     0,     0,   325,     0,     0,   341,
       0,     0,     0,  1277,     0,     0,   406,  1658,  1661,     0,
    1220,  1590,     0,     0,  1489,  1490,  1491,  1494,  1534,     0,
     351,     0,  1584,     0,  1690,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1368,     0,
       0,   660,     0,     0,   678,     0,     0,     0,     0,     0,
     238,  1348,  1346,  1347,   671,   665,     0,     0,     0,     0,
       0,     0,  1675,     0,   390,     0,     0,   617,   681,   630,
       0,   254,  1367,   790,   791,   793,   798,     0,   799,   802,
     248,   248,   248,     0,     0,   577,     0,   566,   581,     0,
       0,   680,   628,     0,   259,  1189,   251,     0,  1260,     0,
       0,  1257,     0,   112,     0,   287,   334,   867,     0,     0,
     386,  1253,     0,     0,     0,     0,   815,   322,   323,     0,
       0,     0,   333,  1211,     0,     0,   340,   336,     0,   404,
       0,     0,   123,     0,     0,   104,     0,     0,   349,  1688,
    1339,  1343,  1345,  1352,  1341,  1350,   582,   583,   585,   586,
     588,   584,   587,   589,   590,  1340,  1349,  1344,   646,   625,
       0,     0,   661,     0,     0,   679,     0,   235,   236,     0,
       0,   247,  1342,  1351,   634,   621,     0,     0,   393,     0,
     389,     0,     0,     0,     0,     0,   796,     0,   559,   556,
     560,     0,   575,   570,     0,     0,     0,     0,   262,     0,
       0,     0,     0,     0,   109,   110,   115,     0,   279,     0,
       0,     0,  1671,     0,     0,     0,   306,   343,   342,     0,
    1221,     0,   120,   121,   129,   126,   118,     0,   101,   102,
     107,     0,     0,     0,   360,     0,   361,   362,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   666,     0,   392,
       0,     0,     0,   401,     0,     0,   682,   632,     0,     0,
     800,     0,   248,     0,   667,     0,     0,     0,     0,  1246,
       0,     0,   111,   113,   286,     0,     0,     0,     0,   326,
     328,  1273,   122,   127,   124,   132,   103,   105,     0,     0,
       0,     0,   352,     0,   363,     0,     0,   663,     0,   662,
     681,     0,   680,   239,   241,   623,   391,     0,     0,  1215,
       0,   400,     0,     0,     0,     0,   794,   795,   797,     0,
     561,   576,   627,     0,     0,  1247,  1261,  1262,   114,   344,
       0,  1254,  1255,   128,   125,   130,   106,     0,     0,     0,
       0,     0,     0,   359,     0,     0,     0,   398,     0,   399,
       0,   669,     0,     0,     0,   248,   248,   668,     0,  1672,
     131,     0,     0,     0,     0,     0,     0,   357,     0,   664,
     682,     0,   397,   631,     0,     0,   557,   562,   629,     0,
       0,     0,     0,   353,   358,   356,   396,   670,     0,     0,
       0,     0,   364,     0,   633,   563,   365,   366,     0,   367
  };

  const short int
  parser::yypgoto_[] =
  {
   -2863, -2863,  3268, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863,   380, -2863, -2863, -2863, -2863,  -754,
   -2863,  -300, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863,   643, -2863, -2863, -1558, -2863, -2863, -2863,  -239,
    -468, -2863,  1154,  -706, -2863,  1743, -2863, -2863, -2863, -2863,
     651, -1553, -2863,   662,  -257, -2863, -2863, -1544, -2863,  1036,
    -929,  -264, -2863, -2863, -2863,  1447, -2863, -2863, -2863,    62,
      67, -2863,   174, -2863, -2863, -2863,  1449, -2863, -2863,  1438,
   -2863,  1127,   664, -2863,   212, -2863,  1037, -2863, -2863,  -199,
   -2863, -2863,  1915, -2863, -2863,  1768, -2863, -2863,  -197, -2863,
   -2863,  -205, -2863, -2863,  3065,  1443, -2863, -2863,  1656, -2863,
   -2863,  1451, -2863, -2863,  -198,  1645,   436, -2107, -1614,  1549,
    -950, -2863, -2272, -2863, -2863,  2764, -2863, -2863, -2862, -2863,
    1212,  -675, -2863, -2863,  2767, -2863, -2863,  2739, -2863, -2567,
   -2863, -1706, -2863, -2863, -2863,  1573, -2863, -2863,  3070, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2755,   381,
   -2863,   403, -2863,  3075, -2863, -2390,   544, -2863,  3076, -2863,
   -2863,  1875,   507, -2863,   201, -2863,   519, -2863, -2863, -2863,
   -2863, -2863, -2863,  2746, -2863, -2863, -2863, -2863, -2863,  1774,
   -2863, -2863, -2863, -2863, -2863, -2863,  1831, -2863, -2863,    58,
   -2863,  1809, -2863, -2863, -2863, -2863, -2863, -2863, -2863,  2465,
   -2863, -2863,  1663, -2863,  1679, -2863,  -225, -2863, -2863, -2863,
   -2863, -2863,  -114,  1990, -2863, -2863,  1991, -2863, -2863,  1567,
   -2863, -2863,  1557, -2863, -2863,  1514, -2863, -2863,  1551, -2863,
   -2863,  1527, -2863, -2863,  1533, -2863, -2863,  1541, -2863, -2863,
    1545, -2863, -2863,  1634, -2863,  1735, -2863, -2863, -2863,  2770,
   -2863, -2863,  1877, -2863, -2863,  2045, -2863, -2863, -2863,  3046,
   -2863, -2863, -2863,  1714, -2863,  2017, -2863, -2863,  1887, -2863,
   -2863, -2466, -2863, -2863,  2750, -2863,  1235,  -741, -2863,  1740,
   -2863, -2863,   490,  -947, -2863, -2863,    94, -2863, -2863, -2863,
    -175,  -101,  -130, -2863,  -204, -2863, -2863, -2863,   -73,   -51,
   -2863, -2863, -2863,   271, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,  -193, -2863,
   -2863, -2863, -2863, -2863, -2863,   -72, -2863, -2863,  -159, -2863,
    -170,  -200,   -50, -2863, -2863,  -190, -2863, -2863, -2863, -2398,
   -2396, -2370, -2863, -2863, -2361, -2350, -2863, -2863, -2863, -2347,
   -2325, -2863, -2863,  -196,  -195, -2863,  -218,  -212,   -96,   -86,
   -1984, -2863,  1543,  -183,  -293, -2863, -2863, -2863, -2863,  -167,
   -2863, -2863, -2863, -2863,  -292, -2863, -2863, -2863, -2863, -2863,
    -152, -2863, -2863, -2863,  -182, -2863, -2863, -2863, -2863, -2863,
   -2863,   -49,  -213, -2863, -2863,   -45,   -33,   -95, -2863,  -194,
   -2863, -2863, -2863, -2863, -2863,  -217,  -203,   -31, -2863, -2863,
     -30,   -28, -2863,  -132, -2863,   -24,   -20, -2863,  -246,   -19,
     -17, -2863, -2863, -2863,   -16,     5,     7,     8, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,  -282,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,  -281,  -278,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,  -151,  -215,
   -2863, -2863, -2863,  -290,  -286,  -273,  -270,  -266, -2863, -2863,
   -2863, -2863, -2863,  -259,  -255,  -249, -2863,  -243, -2863, -2863,
   -2863,  -241,  -233,  -216, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
   -2863,  -326, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
    -161,  -240, -2863, -2863, -2863, -2863, -2863,    10, -2863, -2863,
    -269,  -155, -2863,  -181,  -189, -2863, -2863, -2863, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863, -2863,
    -256, -2863, -2863, -2863, -2863, -2863, -2863, -2863,  -180,  -179,
    -305, -2863, -2863,  -176,  -173,  -164,  -150,  -335,  -148,  -136,
   -2863, -2863,  -103,  -253, -2863, -2863, -2863,    11, -2863, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -2863,  -124,  -119, -2863,
   -2863, -2863, -2863, -2863, -2863, -2863, -1277, -1925, -2863, -1269,
   -2863, -1453, -2863,   482, -2863, -1851,     0
  };

  const short int
  parser::yydefgoto_[] =
  {
      -1,   110,   111,   112,   113,   114,  2529,  3134,   115,  2260,
    3102,   116,  2426,  2425,  3131,   117,   118,   119,   120,  1694,
     874,   875,   318,   320,   322,   275,   325,   121,   433,  2066,
     122,   123,  2940,  2033,  2895,  2943,   124,   125,   126,   474,
     475,   127,   714,   715,   128,   771,   772,   129,   761,  2750,
    1644,  1645,  2262,  2263,  1646,  1735,  2788,  1647,   130,   938,
     939,   940,   131,   351,  1960,  1961,  3136,  3341,  3138,  3342,
    3235,  3236,  3237,   132,   133,  1392,  1393,   134,  1403,  1404,
     135,   786,  2925,   136,  3252,  1763,  1764,   137,   973,   443,
     138,   444,   445,   139,   782,   783,   140,   908,   956,   141,
     920,   957,   142,   143,  1421,  1422,   144,   958,   959,   145,
    1413,  1414,   146,   978,   994,   980,  2829,  2830,  2235,  1466,
    2143,  2144,  2145,   147,   671,   672,   673,  2208,  2944,   148,
     682,   683,   149,   677,   678,   150,   702,   703,  3155,  2209,
     700,   701,   151,   152,  1125,  1126,   153,   154,   155,  1431,
     156,  2035,  2916,  1984,  2954,  3197,  3183,  3315,  2903,  2904,
    2853,  2854,   157,   158,   159,  2662,  2663,   160,   161,   162,
     564,   565,  2702,  2703,  3186,  3187,  2705,  2706,   163,   324,
    1029,   164,   791,   792,   165,   166,   794,   167,   817,   818,
     168,   169,   170,   171,   172,   173,   730,   731,   174,   260,
    2749,   261,   175,   279,  1734,   176,   177,   178,  1001,  1002,
     179,  1005,  1006,   989,   990,   995,  1007,   180,   181,   182,
     183,   384,   385,   386,   184,   408,   409,   185,  1180,  1181,
     186,  1263,  1264,   187,  1369,  1370,   188,  1245,  1246,   189,
    1362,  1363,   190,  1351,  1352,   191,  1337,  1338,   192,  1296,
    1297,   193,   194,  1066,  1067,   944,   945,   195,   719,   720,
     196,   705,   706,   197,   459,   460,   198,   199,   467,   468,
     200,   972,  1777,  1778,   201,   417,   418,   202,   691,   692,
     203,  2965,   204,   788,   789,   205,   755,   756,   206,   965,
     966,   207,   951,   952,  2376,   819,   820,   821,   923,   924,
     822,   823,   824,   825,   826,   827,   828,   829,   830,   831,
     832,   833,   981,   834,   694,   695,   696,   447,   925,   982,
    1008,   835,   836,   926,   927,   448,   837,   774,   449,   929,
     775,   838,   839,   840,   841,   842,  1127,  1128,   387,   573,
     574,   388,   844,   577,   578,   389,  1129,  1130,  1131,  2905,
    2906,  2907,  2908,  2858,  2909,  2910,  2664,  2665,  2666,  2911,
    2912,  2913,  2863,   390,   391,   581,   582,   845,   846,   847,
    2115,  2692,  1432,   410,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   600,   601,   602,
     603,   604,   605,   606,   422,   930,   608,   609,   610,   611,
     612,   849,   411,   615,   616,   850,   423,   851,   620,   621,
     622,   623,   777,   852,   853,   392,   393,   424,   627,   628,
     394,   395,   631,   632,   633,   854,   855,   636,   997,   856,
     857,   639,   640,   641,   858,   859,   860,   861,   396,   397,
     398,   399,   400,   401,   402,   412,   646,   647,   648,   649,
     650,   651,   652,   653,  1083,  1084,  1085,  1086,  1087,   742,
    1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,  1097,  1098,
    1099,  1100,  1101,  1102,  1103,  1104,  1105,  1106,  1107,  1108,
    1109,  1110,  1111,  1112,   743,  1113,  1114,  1115,   744,   745,
     746,   747,   748,   451,   452,   453,   454,   464,   465,   654,
     985,  1339,  1340,  1184,  1185,  1186,  1187,  1188,  1189,  1190,
    1191,  1192,  1193,  1194,  1195,  1196,  1197,  1198,  1199,  1200,
    1201,  1202,  1203,  1204,  1313,  1205,  1206,  1207,  1208,  1209,
    1210,  1211,  1212,  1213,  1214,  1215,  1216,  1217,  1218,  1219,
    1220,  1221,  1222,  1223,  1224,  1225,  1226,  1227,  1228,   862,
     863,  1394,  1395,  1396,  1397,  1398,  1399,  1406,  1407,  1408,
     655,   998,  1415,  1416,  1417,  1418,   656,   425,   658,   659,
    1247,  1248,  1316,  1249,  1229,  1318,  1319,  1320,  1321,  1322,
    1323,  1324,  1325,  1326,  1327,  1328,  1329,  1330,  1331,  1332,
    1250,  1344,  1345,  1356,  1357,  1358,  1359,  1360,  1251,  1252,
    1253,  1367,  1272,  1254,  1255,  1256,  1257,  2914,  1259,  1260,
    1384,  1009,   660,   751,   661,   662,   663,   865,   866,   665,
     666,   931,   967,   968,   969,   970,   971,   932,   933,  1423,
    1424,   948,   949,  2053,  2257,  2986,  2672,  2673,  2048,  2049,
    2154,  2590,  2843,  2591,  2454,  2455,  1467
  };

  const short int
  parser::yytable_[] =
  {
     208,   785,  1258,   216,  1757,  1766,  1521,  1599,  1615,  1750,
     752,  2243,   624,   216,  1636,  1381,   614,   583,   421,  1018,
     216,  1023,   903,  1028,   420,   568,   625,  1405,   708,   575,
     735,  2207,   262,   579,   580,  1271,   736,   463,  1079,  1080,
     216,   216,   276,  1366,   733,   216,   586,   607,   216,  1088,
    1116,   216,  1301,  1117,   740,   419,  1302,   711,   216,   216,
     216,   991,   216,   216,   319,   321,   323,   992,   326,  1303,
     572,  1265,  1304,  1314,   816,  1341,  1305,  1353,  1119,  1364,
     921,  1371,   773,  1306,  1268,   996,   909,  1307,  1343,   984,
     461,  2266,   928,  1308,  1374,   216,   739,   749,   407,  1309,
    2267,  1310,   843,   974,   928,   848,   979,  2338,  2155,  1311,
     208,   864,   697,  1074,  2594,  1132,   741,   698,   732,  1075,
    1698,  1183,   983,  2676,   911,  1299,  1312,  1068,   567,  1133,
    2691,  1070,   946,   584,   619,  1072,  1073,  1082,   911,  1300,
     947,  1071,  2942,   585,   709,   750,   365,   450,  1078,  1081,
    2475,  2476,   737,  1317,   710,   209,   569,   571,   758,  1267,
    1269,  1270,   738,  -659,  1273,  1355,  -661,  1274,  -663,  1373,
    1375,  1376,  1069,   361,  1377,  1182,  1275,  1378,   570,   576,
     613,  2825,  2827,  1298,   617,  1266,  1379,  1315,  1333,  1342,
    1276,  1354,  1277,  1365,  2670,  1372,   618,  2365,   626,   629,
    1380,   630,  1382,  2047,  1278,   634,  2670,  1419,  1012,   635,
     637,  2668,   638,   642,  1383,   428,  2855,   878,  2856,  3189,
    1514,   878,   469,  2062,   262,   262,   476,   211,  1118,  1662,
     428,   674,   679,   684,   643,  1076,   644,   645,   704,   657,
     664,   428,   713,   716,  2857,  1077,   721,   878,  2397,   476,
    2727,  2045,   757,  2859,   262,  2108,  3064,  2116,   879,  3091,
     878,   262,   879,  2109,  2860,  2117,   470,  2861,   790,   793,
     795,  2670,  3256,   428,   428,   871,  3064,  2198,  1505,   905,
    2140,   428,   472,   473,  1521,  2619,   428,   262,   879,  2862,
    2983,  2152,   428,   953,   936,  2982,  1334,  2491,  2161,  2162,
     878,   879,   878,   872,  1017,   428,  3177,  1796,   428,   878,
    1511,   428,   759,   446,  2268,   428,   428,   878,  1016,   781,
    1021,  1022,  1026,   566,  1030,  1033,  2232,  1637,  1606,   405,
    2742,   455,  1956,  3023,   277,  3195,   878,  2754,   428,   878,
    1583,   879,  2480,   879,   376,   935,  2276,   376,  1027,  1690,
     879,   223,  2831,  2832,   936,  1335,  2833,   936,   879,  2199,
     466,  1430,  1433,  1437,  1441,   429,  1471,  2844,  2845,  2846,
    2847,  2848,  2849,  2850,  2851,  1749,  1805,   879,  3002,   922,
     879,  1234,  2586,  3104,   878,  2200,  2201,  2202,  2793,  1809,
     278,   922,  2277,   218,   219,    37,   446,  2756,  1813,   295,
    2126,  2674,   376,  2188,  2189,   878,  2382,  2582,  1611,   987,
    2383,   217,  1957,  2736,  1958,  1959,   220,  2737,   221,  2312,
     878,  2427,  2583,   878,  1237,   879,  1495,   413,   414,   377,
    2127,  2128,  2165,  2166,  2167,  2198,  1243,  1361,  2181,   215,
    2190,  3113,   430,   431,   432,  3114,   879,  1652,   878,   230,
    2526,   878,  2430,  2694,  1000,   231,   241,  2433,   222,  2535,
    2366,   879,  2538,  3065,   879,  3308,  1513,  3224,  1659,   224,
    3283,   466,  1760,  1761,   476,  3333,   273,   274,  2671,   225,
     784,   281,   232,  3065,   286,  1420,  2203,   292,   878,   879,
    3076,   462,   879,  3376,   305,   308,   311,   415,   315,   316,
    3313,   878,  2141,  2142,  1687,  1506,   237,   693,  2698,   226,
     227,   707,  3324,  2669,  2403,  1760,  1761,  2199,  1606,   734,
     238,  2140,  1663,  2038,  1737,  3060,  2041,  1744,   456,   879,
     457,   338,  1013,   456,  1442,  1767,   246,  1512,   457,  2163,
    2233,  2234,   879,  2200,  2201,  2202,   784,  2852,  1607,   242,
    2696,   873,   873,  1638,   910,  1760,  1761,  1760,  1761,  2743,
     458,  3092,  3024,  3089,  1760,  1761,   937,  1584,   910,   873,
    2204,  1691,  1692,   942,  3257,  2492,  2493,  1443,  1723,  1724,
    1725,  1726,  1727,  1728,  1729,  1730,  1731,  1732,   210,  1444,
    1733,  1760,  1761,  1780,  1760,  1761,   873,   873,   380,  3375,
    1234,  1445,  1446,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,   943,  2757,   873,   988,   937,  1704,  1705,   937,
    2675,    37,  1447,   376,  2129,  1612,  2855,   873,  2856,  1760,
    1761,   366,  2919,  1237,  2203,  1722,   873,  1723,  1724,  1725,
    1726,  1727,  1728,  1729,  1730,  1731,  1732,  1386, -1714,  1733,
     212, -1714,   362, -1714,  2857,  1336,  1244,   873,  1585,   873,
    1586,   674,  2240,  2859,  1653,  1591,  1592,   679,  1760,  1761,
    1596,  1597,   684,  3112,  2860,  2367,  2046,  2861,  3066,  2232,
    3309,  3310,  3097,  2599,  3319,  1660,  3308,  2453,   471,  2384,
     873,  2600,   704,  1760,  1761,   873,  1760,  1761,  3109,  2862,
    2205,  2481,  2482,  1784,   716,   873,  1806,  1807,   873,   721,
    1589,  1810,  1811,   873,  2826,  1956,  1814,  1815,  2204,  1788,
    1790,  1688,  1120,  1121,   878,  3270,  3271,  2699,  1800,  3366,
    1859,  1776,  2867,  2141,  2142,  3277,  2918,  3278,   245,  2920,
    1968,  1738,   476,   267,  1745,   757,  1448,  1449,  1122,  1123,
     251,   905,  1768,  1450,  1451,  1452,  1453,  1454,  1455,  1456,
    1457,  1458,  1459,  3366,   762,   879,  1460,  2932,  2153,   262,
    1461,  1462,  1463,  3077,  1661,   878,   668,   254,   790,  1971,
     763,   793,  3254,  1977,  1672,  1981,  1981,   255,  1242,  1989,
    2899,  2928,  2269,   764,  2546,  1957,  3266,  1958,  1959,  2935,
    1762,  1231,   287,  2803,  2386,   416,  2938,  2977,  2140,   268,
    1781,   765,  2547,  2995,   269,  3200,   879,  1731,  1732,  1520,
    3034,  1733,  3049,  3058,  1232,  1233,  2899,  1657,  2899,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,  3251,  2844,
    2901,  2846,  2902,  2848,  2849,  2850,  2851,  3058,  2205,  1689,
    3259,  3105,  3058,  1695,  1695,  2899,  2899,  3058,  3058,   479,
     722,   480,  2899,  3058,   905,   905,   270,  1387,   300,   878,
     668,  2962,  2963,   878,   405,  1124,   332,  3348,   312,   766,
     878,   335,   905,  2233,  2984,   878,   382,   383,  2029,  2030,
     405,  1587,  2031,  1388,  1389,  1390,  1391,   767,   233,   234,
     376,  3329,  3310,   327,  3353,  2385,   328,  3268,   235,   236,
     879,   243,   244,   675,   879,   329,  1747,  1748,  2695,  2315,
    1785,   879,  2318,   352,  3072,  1590,   879,   377,  2171,  2172,
    2173,   953,   495,   496,    37,   358,  1789,  1791,   353,  2110,
    2111,  2112,   354,  2113,  3367,  1801,  2539,  1860,   495,   496,
     675,   768,  1779,   355,   363,  1464,    37,  1969,  1134,  1135,
    1136,  1137,  1138,  1034,  2110,  2111,  2112,   356,  2113,  1760,
    1761,  1593,  1144,  1145,  1146,   769,  2571,  2572,  3385,  1151,
    1279,   502,  1152,  1153,   382,   383,  1234,   357,  1465,  1235,
     506,   669,   723,   364,  1804,   415,  1972,   247,   248,  1808,
    1978,   477,  1982,  1983,  1812,  1159,  1990,  2900,  2929,  1818,
     512,  1819,   367,  3199,   685,   670,  2936,   249,   250,  2852,
    2141,  2142,   699,  2939,  2978,  3051,   526,   403,  1236,  1237,
    2996,  1238,  1239,  1234,  1240,  1241,  1242,  3035,    37,  3050,
    3059,  1243,   717,  3176,   718,  3194,   252,   253,   770,  1388,
     542,   753,  1244,   754,  3073,   544,  1400,  1401,   760,  1402,
     553,  3316,  2114,   778,   378,   776,   542,  1729,  1730,  1731,
    1732,   544,   787,  1733,  3248,   457,  1237,  3260,  2079,  3265,
    1280,    37,  3312,  3323,  3352,  3358,  2174,  2175,  2176,  3374,
    3388,   784,  2964,   256,   257,   669,   380,   381,   263,   264,
    1179,  1281,  1282,  1283,  1284,  1285,  1286,  1287,  1288,  1289,
    1290,  1291,  1292,  1293,  1294,  1295,  2842,  2696,    37,   670,
    2659,  2660,  2661,  2985,  1760,  1761,   265,   266,  1760,  1761,
     876,  2941,   282,   283,   877,  1760,  1761,  1409,  1410,  1411,
    1412,  3038,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,   727,   676,   906,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,  2697,  2700,  1723,  1724,  1725,  1726,  1727,
    1728,  1729,  1730,  1731,  1732,   686,   941,  1733,   954,   676,
    2781,  1723,  1724,  1725,  1726,  1727,  1728,  1729,  1730,  1731,
    1732,   284,   285,  1733,   288,   289,  1035,  1036,  1037,  1038,
     729,  1039,  1040,  1041,  1042,  1043,  1044,  1045,  1046,  1047,
    1048,  1049,  1050,  1051,  1052,  1053,  1054,  1055,  1056,  1057,
    1058,  1059,  1060,  1061,  1062,   955,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,  1792,  1793,  1794,  1795,  1000,
    1242,  2080,  2081,  2082,  2083,  2084,  2085,  1426,   421,  2027,
    2028,  2029,  2030,  1230,   420,  2031,   293,   294,  1385,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,   463,   296,
     297,   298,   299,   687,  1472,   419,   301,   302,   330,   331,
     333,   334,   339,   340,  1473,   457,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,  1474,   624,   341,   342,  1475,
     614,   583,   343,   344,   345,   346,   407,   347,   348,   568,
     625,   461,  1476,   575,   349,   350,  1477,   579,   580,  2313,
    2314,  1478,  1063,  1064,  1065,   688,  2168,  2169,  1479,   708,
     586,   607,  2783,  1723,  1724,  1725,  1726,  1727,  1728,  1729,
    1730,  1731,  1732,   735,  1480,  1733,  2184,  2185,  1481,   736,
    1482,  1483,  1484,  1485,   572,  1486,  2266,   733,   711,   689,
     690,  2339,  1766,   450,  2804,  2267,  1487,   740,  1674,  1488,
    1489,  1490,  1491,  2319,  2320,  2321,  2322,  2782,  1492,  2323,
    2324,  2325,  2326,  2327,  2328,  2329,  2330,  2331,  2332,  2333,
    2334,  2335,  2336,  2337,  1494,  1493,  2340,  2341,  2342,  2343,
    2344,  2345,  2346,  2347,  2348,  2349,  2350,   773,   262,   739,
     749,   697,   567,  2052,  2054,  1497,   698,   584,   619,   816,
    1496,   960,   961,   216,  1498,  1499,  2067,   585,  3210,   741,
    3212,   732,  1500,  1501,  2428,  2429,  1502,  1503,  2431,  2432,
     569,   571,  2434,  2435,  1504,   709,  2092,   843,   216,   216,
     848,  1507,  3188,  1508,  3190,   710,   864,  2103,   750,  1509,
    1516,   262,   570,   576,   613,   737,  2043,  1510,   617,  2361,
    2354,  1517,   991,  1522,  1524,   738,  1518,  1525,   992,  1519,
     618,   928,   626,   629,  1523,   630,  1526,  2149,   262,   634,
    1079,  1080,   262,   635,   637,  2412,   638,   642,  2170,   984,
    3139,  1088,  1116,  3141,   928,  1117,  1527,  3145,   911,  3156,
    3157,  2400,  1528,  1258,   216,  1529,   979,  1530,   643,  2107,
     644,   645,  1531,   657,   664,  1532,   946,  1533,  1534,   446,
    1119,  1535,   983,  1595,   947,   962,   963,  1536,   911,  1537,
    1600,  1538,   216,   964,  1539,  1271,  2150,  1540,   262,  1381,
    2159,  1541,  1542,  1543,  1544,  1545,  1546,  1547,   262,  2784,
    1548,  1549,  1550,  1551,   262,  1074,  1601,  2255,  1552,  2697,
    1553,  1075,  1132,  2264,   905,  1405,  1366,  1554,  1301,  1068,
    1555,  1265,  1302,  1070,  1556,   262,  1133,  1072,  1073,  1082,
    1557,  1558,  3330,  1071,  1268,  1303,  1559,  2288,  1304,  1314,
    1078,  1081,  1305,  2294,  1341,    37,  2237,   566,   262,  1306,
    1353,  1560,  1364,  1307,  1561,  1371,  2247,  1343,   216,  1308,
    1562,  1183,  2253,  1695,  1069,  1309,  1695,  1310,  1374,  1563,
     905,   905,   905,   905,  3320,  1311,   905,   905,   905,   905,
     905,   905,   905,   905,   905,   905,   905,   905,   905,   905,
     905,  1299,  1312,   905,   905,   905,   905,   905,   905,   905,
     905,   905,   905,   905,  1564,  1300,  2300,  1565,  1566,  1267,
    1269,  1270,  1567,  1568,  1273,  1182,  2931,  1274,  2933,  1317,
    1118,  1569,  2370,  2371,   216,  1570,  1275,  1076,  2377,  2378,
    1571,  1572,  1573,  1574,  1575,  1266,   680,  1077,  1355,   262,
    1276,   262,  1277,  1373,  1375,  1376,   216,  1779,  1377,  1298,
    1576,  1378,   462,  1315,  1278,   216,  1577,  1598,  1342,   216,
    1379,   216,  1578,  1579,  1354,  1580,  1365,  1581,  3377,  1372,
    1582,   216,   434,  1602,  1380,  1603,  1382,   435,   436,   437,
    1604,  1605,  1231,  1610,  1613,  1616,  2436,  1617,  1383,  1618,
    1621,  1622,  1623,  1624,  1625,  1626,  1627,  2389,   904,  2391,
    1628,  1629,  1630,  1631,  1634,  1232,  1233,   438,   922,  1633,
    2890,  2021,  2022,  2023,  2024,  2025,  2026,  2027,  2028,  2029,
    2030,  2386,  1639,  2031,   262,  2474,   439,  1640,  1641,   440,
    2690,   922,  1648,  1649,  1650,  1750,   262,  1651,  1654,  1655,
    1658,  1667,  1675,  1664,   446,  1676,   693,  1670,  1677,  1678,
    1679,  1680,   707,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,   734,  1681,  1682,  1683,  1684,  1685,   262,  1686,
     262,   262,  2473,   873,  1699,  1736,  1700,  1701,  1702,   216,
    1703,  1706,  1707,  1708,  2487,  1739,   434,  1709,  1740,  2064,
    1710,   435,   436,   437,    37,  1711,  1712,  1741,  1713,  1231,
    1714,   368,   369,   370,   371,   372,   373,   374,  3053,  1715,
    1716,  1717,  1718,  1719,  2094,  2096,  1720,  1721,   375,  -324,
    1742,   438,  1232,  1233,  1743,   441,  2531,   376,  2533,  2534,
    1746,  1751,  1752,   262,  1753,   262,   262,  1754,  1755,   262,
     439,  1758,  1759,   440,  3074,  2615,  2616,  3078,  1769,  1433,
    1770,   442,  2620,  2621,   377,  2623,  2624,  2625,  1636,  2627,
    1771,  1772,  1773,  2740,  1775,  1774,  1782,  1234,   910,  1783,
    1235,  2746,  2763,  2733,  1786,   681,  1787,  1798,  1799,  1802,
    2195,  1803,   785,  1615,  2828,  1820,  1821,  1822,  1823,  1824,
    1825,  2603,  1826,  2605,  2606,  1827,  1828,  2609,   910,  1829,
    1234,  1830,  1831,  1832,  1599,  1833,  1834,  1835,  2229,  1236,
    1237,  1262,  1238,  1239,  1836,  1240,  1241,  1837,  1838,  1839,
    1840,  1841,  1243,  1842,   428,  1843,  2683,  2891,  1844,  1845,
    1846,  1847,  1848,  1244,  1849,  3140,  1850,  1853,   216,  3144,
    1851,  1852,  1236,  1237,  1854,  1855,  1856,  1857,   680,  1858,
    1861,  2004,  2005,  1862,   428,  2787,   428,  1863,  1864,   476,
    1346,  1347,  1348,  1349,  1350,  1865,  3172,  2020,  1866,  2718,
    1867,  1904,  1868,  1869,  1870,   442,  1871,  1872,  1873,   216,
    1874,  1875,  1876,  1877,  2311,  1878,  1879,  2822,  1880,  1881,
    2823,   378,   379,  2824,  1234,  1882,  1883,  1235,  1884,  1885,
    1886,  1887,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,  1888,  1889,   380,   381,  2098,  1890,  1891,  2820,  2821,
    1892,  1893,  1894,  1895,  1896,  1897,  1236,  1237,  1898,  1238,
    1239,  1757,  1240,  1241,  1242,  1368,  1899,  1900,  1901,  1902,
    2373,  1903,  1905,  1906,  1907,   428,  2708,  1908,  1909,  1910,
    1244,  1725,  1726,  1727,  1728,  1729,  1730,  1731,  1732,   376,
    2712,  1733,  2396,   680,  2715,  1911,  1912,  1913,   684,  1914,
    1915,  2406,  1521,  1916,  1917,  2411,  1918,  2414,  1920,   428,
    2725,  3253,  2206,  1922,  2951,  1919,   716,  2424,  2213,  1921,
     382,   383,  1923,  2217,  2023,  2024,  2025,  2026,  2027,  2028,
    2029,  2030,   476,  2226,  2031,  1924,    37,  1925,   757,  3253,
     905,  1926,  1927,  1928,  2239,  1521,  2265,  1929,   905,  1930,
    1931,   216,  2835,   262,  1932,  1933,  1934,  1935,   262,  2864,
    1936,  1937,  1940,   878,  1939,  1938,  1941,  1942,  1944,  1945,
    1946,  1947,  2759,  1948,  1943,   912,   913,  1949,  1950,  1952,
    1951,  1953,  3311,  1954,  1962,  1955,  1963,   914,  3317,  1964,
     904,   428,  3146,  2290,   439,  2293,  1965,   915,  3147,  3148,
    3149,  3150,  3151,  3152,   879,  3311,  1966,  1656,  1967,   916,
    1970,  2748,  1973,  3153,  1974,  1975,   781,   681,  1976,  3154,
    2892,  2021,  2022,  2023,  2024,  2025,  2026,  2027,  2028,  2029,
    2030,  1979,   905,  2031,  1980,  2543,  1988,  1987,  3349,   880,
    1985,  1991,  1986,  1992,  2790,  1993,  2792,  2040,  2042,  2044,
    1994,   881,  1995,   428,  1996,  1997,  2798,  1998,  1999,   917,
    2050,    37,  2000,   882,   883,  2001,  2002,  2003,  2006,  2007,
     216,  2008,   216,  2051,  2196,  2056,   428,  2009,  2057,  2010,
     457,  2011,  2012,  2013,  2059,  2381,   428,   216,  2014,  2015,
    2016,   428,  2017,    37,   428,  2018,  2019,  2036,  -237,  2034,
    2061,  2068,  2046,  2069,   428,   905,   905,  2070,  2073,  2075,
    2408,  2077,  2086,   904,   904,  2415,  2416,  2417,  2418,  2078,
    2087,  2089,  2090,   918,  2091,  2097,  2100,   919,  2101,   442,
    2099,   904,  2106,  2118,  2121,  2119,  2124,  2125,   216,   216,
     216,  2136,   681,   216,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,  2137,   689,   690,  2973,  2974,  2138,   216,
    2139,  1663,  2146,  2147,  2021,  2022,  2023,  2024,  2025,  2026,
    2027,  2028,  2029,  2030,  1765,  2151,  2031,  2160,  2990,  2991,
    2178,  2153,  2177,  2179,  2684,  2183,  2187,  2192,  2219,  2210,
    2220,  2211,  2191,  2214,  2992,  2223,  2993,  2215,  2241,   905,
    2242,  2244,  2197,  2230,  2245,  2248,  2212,  2216,   884,   885,
     376,  2218,  2256,   428,  2221,   886,   887,   888,   889,   890,
     891,   892,   893,   894,   895,  2693,  2261,  2272,   896,  2316,
    2297,  2224,   897,   898,   899,   900,   901,  2893,  2271,  2225,
    2231,  2236,  2298,  2302,  2304,  2306,   406,  2273,  2307,  2238,
    2249,  2308,  2251,  2252,  2254,  2353,  1733,  2258,   216,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,  1723,  1724,
    1725,  1726,  1727,  1728,  1729,  1730,  1731,  1732,  2259,  2358,
    1733,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
    2275,  2279,  2280,  2628,  2629,  2630,  2631,  2283,  2284,  2632,
    2633,  2634,  2635,  2636,  2637,  2638,  2639,  2640,  2641,  2642,
    2643,  2644,  2645,  2360,  2647,  2648,  2649,  2650,  2651,  2652,
    2653,  2654,  2655,  2656,  2657,  2364,  2393,  2921,   680,  2352,
    2285,  2922,  2399,  2286,   428,  2390,  2420,  2437,  2287,  2289,
     476,  2291,  2351,   428,  2355,  2362,  2363,  2368,  2369,  2864,
    2375,  2388,  2438,  2392,  2439,  2440,  2394,  2747,  2714,  2021,
    2022,  2023,  2024,  2025,  2026,  2027,  2028,  2029,  2030,   684,
    2646,  2031,  2401,  2441,  2407,  2419,  2442,  2443,  2444,   716,
     912,   913,  2445,   476,  2446,  2447,  2448,  3121,  3122,   757,
    2449,  2452,   914,   905,   905,  2453,  2461,   428,  2458,   439,
     905,  2462,   915,  2465,  2459,  2460,  2477,   902,  2483,  1642,
    1427,  1643,  2463,  2484,   916,   905,   905,  2021,  2022,  2023,
    2024,  2025,  2026,  2027,  2028,  2029,  2030,  2485,  2486,  2031,
    2471,   905,  2479,   905,  2488,  2489,  2490,  2494,  2495,   216,
    2496,  2497,  2498,  2501,  2502,  2503,  3003,  1434,  2504,  2505,
    2506,  2508,  2509,  2510,  2511,  2512,   428,   428,  2513,  2514,
    2515,  2516,   428,  2517,   917,  2518,  2519,  2520,  2521,  1428,
    2522,  2523,  2524,  2525,  2528,  2530,  2806,  2532,  2807,   428,
    2536,  2537,  3225,  2540,   428,  2545,  2551,  2553,  2554,  2581,
    2557,   428,  2558,  2812,  2559,  2560,    37,  3207,  2564,  2565,
    2566,  2567,  2570,  2573,  2713,  2578,  1435,  2569,  2716,  2588,
    2592,  2589,  3214,  3215,  2595,  3036,  2575,  2577,  3039,  2580,
    2584,  3042,  2596,  2585,  2598,  2602,  2608,  2604,   918,  2610,
    2612,  2613,   919,  2614,   442,  1134,  1135,  1136,  1137,  1138,
    1139,  1140,  1468,  2031,  1141,  1142,  2618,  2677,  1143,  1144,
    1145,  1146,  1147,  1148,  1149,  1150,  1151,  2658,  2678,  1152,
    1153,  1154,  1155,  1156,  1157,  1158,  2685,  2667,  2679,   689,
     690,  2686,  2701,  3284,  3285,  2834,  3070,   681,    37,  2704,
    2710,  2709,  1159,  1160,  1161,  1162,  1163,  2761,  2711,  1164,
    1165,  1166,  1167,  1168,  2726,  1169,  1170,  1171,  1172,  1173,
    1174,  1175,  2727,  2728,  1176,  1177,  1178,  2730,  2734,  2735,
    2738,  2741,  2744,  2753,  2745,    37,  3099,  2754,  3100,  2764,
    3103,  2786,  2789,  2799, -1715,  2802,  2809,   262,  1606,   905,
    2837,  2838,  3334,  3335,  2839,  2840,  2865,  2868,  2866,  2869,
   -1714,  2896,  2871,  2758,   905,   905,  2872,   428,  2897,  2898,
    2870,  2915,  2873,  -660,   953,  2917,  2670,  2924,  2791,  2926,
    2953,  2950,  3132,  3132,  2934,  2955,  2956,  2980,  2958,  3135,
    2961,  2037,  1765,  2039,  2841,  1765,  2937,  1179,  2805,  2967,
    2971,  2945,  2987,  3360,  2994,  3107,  2998,  2058,  3000,  2948,
    3163,  2966,  2810,  3166,  3009,  3004,  3021,  3025,  2968,  2071,
    2072,  3014,  2074,  3020,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,  3015,  3016,  2102,  3017,  2104,  2105,  3026,
    3027,  3028,  3029,  3030,  3031,  3032,  2120,  3033,  2122,  2123,
    3037,  3040,  3043,  2130,  2131,  2132,  2133,  2134,  2135,  3044,
    3055,  3056,  3205,  1765,   905,  3057,  3062,  3061,  3063,   479,
     722,   480,  3071,  3080,  2164,  3081,  3082,  3087,  3115,   905,
     905,  3041,  3090,  2180,  2182,  3094,  3096,  2186,   953,  3098,
    3101,  3223,  3110,  3223,  3229,  3111,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,  1723,  1724,  1725,  1726,  1727,
    1728,  1729,  1730,  1731,  1732,  3127,  2722,  1733,  3178,  3159,
    3180,  1765,  3182,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,  3137,   904,  3160,  3161,  3164,  2270,   495,   496,
    3175,  3181,  3185,  3272,  3179,  3196,  3184,  2281,  1723,  1724,
    1725,  1726,  1727,  1728,  1729,  1730,  1731,  1732,  -662,  3201,
    1733,  3282,  3202,  3206,  2296,  2997,  3209,  3286,  2301,  3211,
    2303,   502,  2305,  3213,  3230,  3238,  3249,  3239,  3258,  3261,
     506,  3298,   723,  3301,  3208,  1608,  3262,  3295,  3273,   904,
     904,   904,   904,  3240,  3287,   904,   904,   904,   904,   904,
     904,   904,   904,   904,   904,   904,   904,   904,   904,   904,
    3292,  3269,   904,   904,   904,   904,   904,   904,   904,   904,
     904,   904,   904,  3296,   878,  3067,  3241,   529,  2356,  2357,
    3339,  2359,  3255,  3242,  3247,  3343,  3243,  3244,  3108,  3250,
    3264,  2894,  3267,  3276,  3290,  3299,  3281,  3302,  3306,  2379,
    2380,  3314,  -664,  1765,  3305,   878,   542,  3322,  3326,  3325,
    3327,   544,  3337,  3331,  3332,   879,  3338,  3328,  3344,  1438,
    3336,  2402,   724,   725,  3345,  3346,  3351,  3361,  3362,   456,
    3354,   457,  3357,  3369,  3343,  3359,  3364,  3370,  2421,  3373,
    3378,  3355,  3381,   726,   550,  3356,   879,  2947,  3363,  3379,
     880,  3383,  3380,  2952,  3382,  3387,  3384,  3389,  3392,  1614,
    3390,   458,   881,  3391,  2959,  3394,  3393,  3398,   360,  3396,
    3397,  2767,  2450,  2451,   882,   883,  2456,  2457,  1439,  3399,
    2729,   880,    37,  3133,  2464,  2274,  2466,  2467,  2468,  2469,
    2470,  2979,  2988,   881,  2972,  2794,  3368,  2587,  3365,  2601,
    3294,   727,   728,  2755,    37,   882,   883,  2597,  2981,  2801,
    2076,  3275,  1425,  2387,  2611,  2499,  2500,  2282,  2607,  2404,
    2719,  1429,  2478,  2507,  2768,  1588,  3001,  3158,  1436,  3174,
    1440,  1609,  3075,  3054,  1594,    37,  3005,  1723,  1724,  1725,
    1726,  1727,  1728,  1729,  1730,  1731,  1732,  3079,  2193,  1733,
    3318,  2309,  2250,  2422,  2278,  1765,  1797,  2409,  2579,  2541,
     729,  2527,  2548,  2549,  2550,  2055,  2552,  2544,  2576,  2555,
    2556,  2060,  2574,  2563,  2568,  2561,  2562,  2472,  2227,  1620,
    2374,  2398,  2222,  2739,  3128,  1765,  1765,    37,  1619,  2720,
    2021,  2022,  2023,  2024,  2025,  2026,  2027,  2028,  2029,  2030,
    3143,  2065,  2031,  1515,  2593,  2395,    37,  3045,  3046,  1723,
    1724,  1725,  1726,  1727,  1728,  1729,  1730,  1731,  1732,     0,
       0,  1733,  2617,  3047,     0,  3048,     0,  1669,  1666,   884,
     885,     0,     0,     0,     0,     0,   886,   887,   888,   889,
     890,   891,   892,   893,   894,   895,  2088,  1632,     0,   896,
       0,     0,     0,   897,   898,   899,   900,   901,     0,     0,
     884,   885,     0,     0,     0,     0,     0,   886,   887,   888,
     889,   890,   891,   892,   893,   894,   895,     0,  3083,  3084,
     896,  3086,     0,     0,   897,   898,   899,   900,   901,  3093,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,     0,
       0,     0,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,  3124,     0,  3125,     0,    37,     0,     0,     0,     0,
       0,     0,  3130,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,     0,  2769,  1723,  1724,  1725,  1726,  1727,  1728,
    1729,  1730,  1731,  1732,     0,     0,  1733,     0,     0,     0,
    2379,  2380,  3171,     0,     0,     0,     0,     0,     0,     0,
    3173,     0,  1765,  1765,    37,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,     0,     0,  2770,     0,     0,   368,   369,
     370,   371,   372,   373,   374,   404,  1635,     0,   902,     0,
    1642,     0,  1643,     0,   405,   375,     0,     0,     0,     0,
       0,     0,     0,     0,   376,     0,     0,     0,     0,  3234,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   902,
       0,  1642,     0,  1643,     0,     0,     0,     0,     0,     0,
       0,   377,     0,     0,     0,     0,     0,     0,     0,   904,
     406,     0,  3245,  3246,     0,     0,     0,   904,  1723,  1724,
    1725,  1726,  1727,  1728,  1729,  1730,  1731,  1732,     0,  2752,
    1733,     0,     0,     0,  3263,     0,     0,  1723,  1724,  1725,
    1726,  1727,  1728,  1729,  1730,  1731,  1732,     0,     0,  1733,
       0,     0,  1665,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,     0,     0,  2004,  2005,     0,     0,     0,  3293,
    1723,  1724,  1725,  1726,  1727,  1728,  1729,  1730,  1731,  1732,
       0,     0,  1733,     0,  3307,     0,     0,     0,     0,     0,
    2771,   904,     0,    37,     0,     0,     0,     0,     0,     0,
       0,     0,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,  1765,     0,  1765,  2655,     0,     0,     0,   378,   379,
    1723,  1724,  1725,  1726,  1727,  1728,  1729,  1730,  1731,  1732,
       0,     0,  1733,  3350,     0,     0,     0,     0,     0,     0,
       0,     0,   359,     0,     0,     0,     0,     0,     0,     0,
     380,   381,     0,     0,   904,   904,     1,     2,     0,     0,
       0,     0,     0,     0,  3234,     0,     0,     0,     0,     0,
       0,  3371,     3,     4,     5,     6,     7,     0,     0,    37,
       8,     0,  1765,  1765,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     9,    10,    11,     0,
       0,     0,    12,     0,    13,    14,    15,    16,    17,     0,
       0,     0,  3395,     0,     0,     0,    18,    19,     0,     0,
       0,     0,  1668,    20,  2772,     0,     0,   382,   383,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
      22,    23,    24,  2773,     0,     0,     0,     0,     0,     0,
      25,     0,    26,    27,     0,     0,     0,     0,   904,     0,
       0,     0,     0,     0,     0,     0,    28,  1723,  1724,  1725,
    1726,  1727,  1728,  1729,  1730,  1731,  1732,     0,     0,  1733,
       0,    29,     0,     0,     0,     0,  2774,     0,  1671,     0,
      30,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
       0,     0,     0,  1756,    31,    32,    33,    34,  1765,     0,
      35,     0,     0,     0,     0,     0,     0,     0,     0,    36,
    2731,  2021,  2022,  2023,  2024,  2025,  2026,  2027,  2028,  2029,
    2030,     0,     0,  2031,     0,     0,  2775,     0,    37,  1723,
    1724,  1725,  1726,  1727,  1728,  1729,  1730,  1731,  1732,     0,
       0,  1733,     0,    38,     0,    39,     0,    40,    41,    37,
    2927,     0,     0,     0,     0,    42,     0,     0,    43,     0,
      44,    45,     0,     0,     0,    46,    47,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,     0,     0,     0,     0,
      48,    49,     0,    50,    51,    52,     0,    53,    54,     0,
       0,     0,     0,    55,     0,  1765,    56,  1765,     0,     0,
      57,    58,     0,     0,     0,    37,     0,     0,    59,    60,
      61,     0,    62,     0,     0,     0,    63,     0,     0,     0,
       0,     0,    64,    65,    66,    67,    68,    69,    70,    71,
      37,     0,  1723,  1724,  1725,  1726,  1727,  1728,  1729,  1730,
    1731,  1732,   904,   904,  1733,     0,     0,     0,     0,   904,
    1723,  1724,  1725,  1726,  1727,  1728,  1729,  1730,  1731,  1732,
       0,     0,  1733,  2776,   904,   904,     0,     0,     0,     0,
       0,     0,    72,     0,     0,     0,     0,     0,     0,     0,
     904,     0,   904,     0,     0,     0,     0,    37,     0,  1723,
    1724,  1725,  1726,  1727,  1728,  1729,  1730,  1731,  1732,     0,
    1765,  1733,     0,     0,     0,     0,     0,    73,  1723,  1724,
    1725,  1726,  1727,  1728,  1729,  1730,  1731,  1732,     0,     0,
    1733,     0,     0,     0,     0,  2732,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,  2777,     0,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,  2021,  2022,  2023,  2024,
    2025,  2026,  2027,  2028,  2029,  2030,     0,     0,  2031,     0,
       0,    93,    94,     0,     0,    95,    96,    97,    98,    99,
     100,   101,   102,     0,     0,     0,  3052,  1765,     0,     0,
     103,     0,     0,     0,     0,   104,   105,     0,     0,     0,
       0,     0,   106,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,     0,  1765,   107,   108,  1765,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,     0,  2778,     0,
     109,     0,     0,  1765,  2765,  1723,  1724,  1725,  1726,  1727,
    1728,  1729,  1730,  1731,  1732,     0,  2779,  1733,   904,     0,
       0,  2957,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   904,   904,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,     0,  2780,     0,     0,     0,     0,
       0,     0,     0,     0,  1765,     0,  3142,     0,  1765,     0,
       1,     2,     0,     0,  2785,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     3,     4,     5,     6,
       7,     0,     0,     0,     8,  1765,  2021,  2022,  2023,  2024,
    2025,  2026,  2027,  2028,  2029,  2030,     0,     0,  2031,     0,
       9,    10,    11,     0,     0,     0,    12,     0,    13,    14,
      15,    16,    17,     0,     0,     0,     0,     0,     0,     0,
      18,    19,  2800,     0,     0,     0,  1765,    20,     0,     0,
       0,     0,     0,   904,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    21,    22,    23,    24,   878,   904,   904,
       0,     0,     0,     0,    25,     0,    26,    27,    37,  2021,
    2022,  2023,  2024,  2025,  2026,  2027,  2028,  2029,  2030,     0,
      28,  2031,     0,     0,     0,     0,     0,     0,     0,     0,
    1442,     0,     0,     0,     0,    29,     0,     0,   879,     0,
       0,     0,     0,     0,    30,  2021,  2022,  2023,  2024,  2025,
    2026,  2027,  2028,  2029,  2030,     0,     0,  2031,     0,     0,
    1765,     0,     0,     0,     0,     0,     0,     0,    31,    32,
      33,    34,     0,  1443,    35,     0,     0,     0,  1765,     0,
       0,     0,     0,    36,     0,  1444,     0,     0,  1765,     0,
       0,     0,     0,     0,     0,     0,     0,  1445,  1446,     0,
       0,     0,    37,  2021,  2022,  2023,  2024,  2025,  2026,  2027,
    2028,  2029,  2030,     0,     0,  2031,     0,    38,     0,    39,
       0,    40,    41,  2960,     0,     0,     0,    37,  1447,    42,
       0,  1765,    43,     0,    44,    45,     0,  1765,     0,    46,
      47,  2021,  2022,  2023,  2024,  2025,  2026,  2027,  2028,  2029,
    2030,     0,     0,  2031,  1765,     0,     0,     0,     0,     0,
       0,     0,  2876,     0,    48,    49,     0,    50,    51,    52,
       0,    53,    54,     0,     0,     0,     0,    55,     0,     0,
      56,     0,     0,     0,    57,    58,     0,  1765,     0,     0,
       0,     0,    59,    60,    61,     0,    62,     0,     0,     0,
      63,     0,     0,     0,     0,     0,    64,    65,    66,    67,
      68,    69,    70,    71,     0,     0,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,  2877,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1673,     0,     0,     0,     0,
       0,     0,  1448,  1449,     0,     0,    72,     0,     0,  1450,
    1451,  1452,  1453,  1454,  1455,  1456,  1457,  1458,  1459,     0,
      37,  2878,  1460,     0,     0,     0,  1461,  1462,  1463,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    73,  2021,  2022,  2023,  2024,  2025,  2026,  2027,  2028,
    2029,  2030,     0,     0,  2031,     0,     0,     0,     0,     0,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,  2879,
       0,     0,     0,     0,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    93,    94,  2880,     0,    95,
      96,    97,    98,    99,   100,   101,   102,     0,     0,     0,
       0,     0,   478,   479,   103,   480,     0,   481,   482,   104,
     105,     0,   483,     0,     0,   484,   106,   485,  2021,  2022,
    2023,  2024,  2025,  2026,  2027,  2028,  2029,  2030,   486,     0,
    2031,  2969,     0,     0,   405,   375,     0,     0,   107,   108,
       0,     0,   487,   488,   376,     0,     0,     0,   489,   490,
     491,  3219,     0,  2021,  2022,  2023,  2024,  2025,  2026,  2027,
    2028,  2029,  2030,     0,   109,  2031,   492,     0,   493,   413,
     414,   494,     0,     0,     0,     0,     0,     0,     0,     0,
     406,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1464,   495,   496,   497,     0,     0,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,     0,     0,     0,
     498,   499,   500,     0,   501,   502,   503,   504,     0,     0,
       0,     0,     0,   505,   506,     0,     0,   507,  2881,   415,
     508,   509,     0,   510,   511,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   512,   513,   514,   515,   516,   517,
     518,   519,   520,     0,     0,   521,   522,   523,   524,   525,
     526,     0,     0,     0,     0,     0,     0,     0,    37,   527,
     528,   529,   530,   531,   532,   533,     0,   534,   535,     0,
       0,   536,   537,     0,     0,     0,   538,     0,    37,   539,
     540,     0,     0,     0,   541,   878,     0,     0,   378,   379,
     542,     0,   543,     0,     0,   544,     0,     0,     0,     0,
       0,   545,    37,   546,     0,     0,     0,     0,     0,     0,
       0,     0,   878,     0,   547,     0,     0,     0,  1442,   548,
     380,   381,  2032,     0,   549,     0,   879,     0,   550,     0,
       0,     0,     0,     0,   878,     0,     0,     0,   441,     0,
     551,   552,     0,     0,   553,  1442,     0,     0,     0,     0,
       0,     0,     0,   879,     0,     0,     0,  2295,     0,   554,
       0,  1443,     0,     0,   442,     0,     0,  1442,     0,     0,
     555,   556,     0,  1444,   557,   879,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1445,  1446,   558,  1443,     0,
       0,     0,     0,     0,     0,     0,     0,   382,   383,     0,
    1444,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1443,     0,  1445,  1446,     0,    37,  1447,     0,     0,     0,
     426,     0,  1444,     0,  2021,  2022,  2023,  2024,  2025,  2026,
    2027,  2028,  2029,  2030,  1445,  1446,  2031,     0,     0,     0,
       0,     0,    37,  1447,  2021,  2022,  2023,  2024,  2025,  2026,
    2027,  2028,  2029,  2030,     0,     0,  2031,     0,     0,     0,
       0,     0,     0,     0,    37,  1447,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,     0,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,     0,     0,     0,     0,   559,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,     0,
       0,     0,     0,  2292,     0,     0,   560,   416,     0,     0,
    1448,  1449,     0,   561,     0,     0,     0,  1450,  1451,  1452,
    1453,  1454,  1455,  1456,  1457,  1458,  1459,     0,     0,     0,
    1460,     0,     0,     0,  1461,  1462,  1463,  3231,  3232,     0,
       0,     0,     0,     0,  1450,  1451,  1452,  1453,  1454,  1455,
    1456,  1457,  1458,  1459,   562,   563,     0,  1460,     0,  1448,
    1449,  1461,  1462,  1463,     0,     0,  1450,  1451,  1452,  1453,
    1454,  1455,  1456,  1457,  1458,  1459,  2246,     0,     0,  1460,
       0,     0,     0,  1461,  1462,  1463,    37,     0,     0,     0,
       0,     0,     0,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,     0,    37,     0,     0,     0,     0,  2689,  2808,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,   878,
    2882,     0,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,   878,     0,     0,     0,    37,     0,     0,     0,     0,
       0,     0,  1442,     0,     0,     0,     0,     0,     0,     0,
     879,     0,     0,   878,  2021,  2022,  2023,  2024,  2025,  2026,
    2027,  2028,  2029,  2030,  1442,     0,  2031,     0,     0,     0,
       0,  3233,   879,     0,   426,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1443,   258,     0,     0,     0,
       0,     0,     0,  3288,   879,     0,     0,  1444,     0,  1464,
       0,     0,     0,     0,     0,     0,     0,  1443,     0,  1445,
    1446,     0,     0,     0,     0,     0,     0,     0,     0,  1444,
       0,     0,     0,     0,     0,     0,  1464,     0,     0,   880,
       0,  1445,  1446,     0,     0,     0,     0,     0,     0,    37,
    1447,   881,     0,     0,     0,     0,     0,     0,  1464,     0,
       0,     0,     0,   882,   883,     0,     0,     0,     0,     0,
       0,    37,  1447,     0,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    37,     0,     0,     0,     0,     0,     0,
       0,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    37,  2021,  2022,  2023,  2024,  2025,  2026,  2027,
    2028,  2029,  2030,     0,     0,  2031,     0,     0,     0,     0,
       0,     0,     0,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,     0,     0,  1448,  1449,     0,     0,     0,     0,
       0,  1450,  1451,  1452,  1453,  1454,  1455,  1456,  1457,  1458,
    1459,     0,     0,     0,  1460,     0,  1448,  1449,  1461,  1462,
    1463,     0,     0,  1450,  1451,  1452,  1453,  1454,  1455,  1456,
    1457,  1458,  1459,  3022,     0,     0,  1460,     0,   884,   885,
    1461,  1462,  1463,     0,     0,   886,   887,   888,   889,   890,
     891,   892,   893,   894,   895,     0,     0,     0,   896,  1776,
       0,     0,   897,   898,   899,   900,   901,     0,     0,     0,
    1696,     0,     0,     0,     0,     0,     0,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,     0,     0,     0,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,   878,     0,
       0,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
    2021,  2022,  2023,  2024,  2025,  2026,  2027,  2028,  2029,  2030,
       0,  1442,  2031,     0,     0,     0,     0,     0,  3289,   879,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,  2883,
    3340,  2021,  2022,  2023,  2024,  2025,  2026,  2027,  2028,  2029,
    2030,     0,     0,  2031,  1443,  2021,  2022,  2023,  2024,  2025,
    2026,  2027,  2028,  2029,  2030,     0,  1444,  2031,     0,     0,
       0,     0,     0,  1464,     0,     0,     0,     0,  1445,  1446,
       0,    37,  2021,  2022,  2023,  2024,  2025,  2026,  2027,  2028,
    2029,  2030,     0,     0,  2031,  1464,     0,  2766,  1723,  1724,
    1725,  1726,  1727,  1728,  1729,  1730,  1731,  1732,    37,  1447,
    1733,     0,     0,     0,     0,     0,     0,   902,     0,     0,
    2021,  2022,  2023,  2024,  2025,  2026,  2027,  2028,  2029,  2030,
       0,     0,  2031,     0,     0,     0,   478,     0,     0,   480,
       0,     0,     0,     0,     0,     0,   483,     0,     0,     0,
     796,   485,     0,     0,     0,     0,     0,  1697,  2021,  2022,
    2023,  2024,  2025,  2026,  2027,  2028,  2029,  2030,     0,     0,
    2031,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   489,   490,   491,   797,   798,     0,  2021,  2022,
    2023,  2024,  2025,  2026,  2027,  2028,  2029,  2030,     0,   426,
    2031,  2874,  2021,  2022,  2023,  2024,  2025,  2026,  2027,  2028,
    2029,  2030,     0,   799,  2031,   800,     0,     0,     0,     0,
       0,     0,     0,     0,  -558,     0,   495,   496,   497,     0,
       0,     0,     0,  1448,  1449,     0,     0,   801,   802,     0,
    1450,  1451,  1452,  1453,  1454,  1455,  1456,  1457,  1458,  1459,
       0,     0,     0,  1460,   498,   499,   500,  1461,  1462,  1463,
       0,     0,     0,     0,   803,     0,     0,  2884,     0,   766,
    1723,  1724,  1725,  1726,  1727,  1728,  1729,  1730,  1731,  1732,
       0,  2885,  1733,     0,     0,     0,   804,     0,     0,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,  2886,     0,
       0,     0,     0,     0,   528,     0,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    37,     0,     0,     0,     0,
       0,     0,     0,     0,   542,   805,  2887,   806,     0,   544,
     807,   808,     0,     0,     0,   545,     0,   546,   478,     0,
       0,   480,     0,     0,     0,     0,     0,     0,   547,   457,
       0,   484,   796,     0,     0,     0,     0,     0,     0,     0,
     809,     0,     0,     0,  2888,     0,     0,     0,     0,   810,
       0,   811,   441,     0,     0,     0,     0,     0,   553,   458,
     812,     0,     0,     0,   489,   490,   491,   797,   798,   813,
     814,   815,     0,     0,  2889,     0,     0,     0,   442,     0,
       0,     0,     0,     0,   555,   556,  2923,     0,   557,     0,
       0,     0,     0,     0,     0,     0,     0,   800,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   495,   496,
     497,     0,  1464,   426,     0,     0,     0,     0,     0,   801,
     802,     0,   975,  2021,  2022,  2023,  2024,  2025,  2026,  2027,
    2028,  2029,  2030,     0,     0,  2031,   498,   499,   500,     0,
       0,     0,     0,     0,     0,   478,     0,     0,   480,     0,
       0,   766,     0,     0,     0,   415,  2970,     0,     0,   796,
    1723,  1724,  1725,  1726,  1727,  1728,  1729,  1730,  1731,  1732,
       0,     0,  1733,  1723,  1724,  1725,  1726,  1727,  1728,  1729,
    1730,  1731,  1732,     0,     0,  1733,     0,     0,     0,     0,
       0,   489,   490,   491,   797,   798,   528,     0,     0,     0,
       0,     0,     0,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,     0,   559,   800,   987,   542,   805,     0,   806,
       0,   544,   807,   808,     0,   495,   496,   497,     0,   546,
       0,     0,     0,    37,     0,     0,   801,   802,     0,     0,
     547,   457,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   809,   498,   499,   500,     0,     0,     0,     0,
       0,   810,   478,   811,   441,   480,     0,     0,   766,     0,
     553,   458,   812,     0,     0,     0,   796,     0,     0,     0,
       0,   813,   814,   815,     0,  1003,     0,     0,     0,     0,
     442,     0,     0,     0,     0,     0,   555,   556,     0,     0,
     557,     0,     0,     0,     0,     0,     0,     0,   489,   490,
     491,   797,   798,   528,  1723,  1724,  1725,  1726,  1727,  1728,
    1729,  1730,  1731,  1732,     0,     0,  1733,   976,     0,     0,
    2930,     0,     0,     0,     0,     0,     0,     0,     0,  3006,
       0,   800,   987,   542,   805,     0,   806,     0,   544,   807,
     808,   426,   495,   496,   497,     0,   546,     0,     0,     0,
       0,     0,     0,   801,   802,     0,     0,   547,   457,     0,
       0,    37,     0,     0,     0,     0,  3012,     0,     0,   809,
     498,   499,   500,     0,     0,     0,     0,     0,   810,  3013,
     811,   441,    37,     0,     0,   766,     0,   553,   458,   812,
       0,     0,     0,     0,     0,     0,   977,     0,   813,   814,
     815,    37,     0,     0,     0,     0,     0,   442,     0,     0,
       0,     0,     0,   555,   556,     0,     0,   557,     0,     0,
      37,   988,     0,  1004,     0,   559,     0,     0,     0,     0,
     528,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      37,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     542,   805,     0,   806,     0,   544,   807,   808,     0,     0,
       0,     0,    37,   546,     0,     0,     0,     0,     0,   426,
       0,     0,     0,     0,   547,   457,  2021,  2022,  2023,  2024,
    2025,  2026,  2027,  2028,  3291,  2030,   809,     0,  2031,    37,
     426,     0,     0,     0,     0,   810,     0,   811,   441,     0,
       0,     0,     0,     0,   553,   458,   812,     0,     0,   426,
       0,     0,     0,     0,     0,   813,   814,   815,     0,     0,
    3019,     0,     0,     0,   442,     0,     0,     0,   426,     0,
     555,   556,     0,     0,   557,     0,     0,     0,   988,     0,
       0,     0,   559,     0,     0,     0,     0,     0,    37,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2976,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    37,     0,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,     0,    37,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,     0,     0,   559,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,   258,
      37,     0,     0,     0,     0,     0,  3007,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    37,  3008,  2875,  2021,
    2022,  2023,  2024,  2025,  2026,  2027,  2028,  2029,  2030,     0,
       0,  2031,     0,     0,     0,    37,  3011,  2946,  2021,  2022,
    2023,  2024,  2025,  2026,  2027,  2028,  2029,  2030,     0,     0,
    2031,     0,     0,     0,    37,  3018,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    37,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2317,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,   213,   214,  2021,  2022,  2023,
    2024,  2025,  2026,  2027,  2028,  2029,  2030,     0,     0,  2031,
       0,     0,     0,     0,     0,     0,     0,    37,     0,     0,
       0,     0,   228,   229,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,  1723,  1724,  1725,  1726,  1727,
    1728,  1729,  1730,  1731,  1732,     0,     0,  1733,  1723,  1724,
    1725,  1726,  1727,  1728,  1729,  1730,  1731,  1732,     0,     0,
    1733,   239,   240,     0,     0,     0,     0,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    37,     0,     0,
       0,   271,   272,     0,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    37,   259,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,     0,    37,     0,  2021,  2022,  2023,  2024,  2025,
    2026,  2027,  2028,  2029,  2030,     0,     0,  2031,     0,     0,
       0,     0,     0,     0,     0,     0,    37,     0,     0,     0,
       0,  2717,     0,   290,   291,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,   258,    37,     0,     0,     0,   303,
     304,  2021,  2022,  2023,  2024,  2025,  2026,  2027,  2028,  2029,
    2030,     0,     0,  2031,     0,     0,     0,   258,   306,   307,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,  3117,     0,     0,     0,     0,     0,   309,   310,     0,
       0,     0,     0,     0,  3118,  2021,  2022,  2023,  2024,  2025,
    2026,  2027,  2028,  2029,  2030,     0,     0,  2031,   313,   314,
       0,   779,     0,     0,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,   779,     0,  2021,  2022,  2023,  2024,
    2025,  2026,  2027,  2028,  2029,  2030,     0,     0,  2031,     0,
       0,     0,     0,     0,    37,     0,     0,     0,     0,     0,
     336,   337,     0,   426,     0,  1723,  1724,  1725,  1726,  1727,
    1728,  1729,  1730,  1731,  1732,     0,     0,  1733,     0,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,   426,     0,
       0,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      37,  3129,     0,     0,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    37,     0,     0,     0,     0,     0,     0,
       0,   280,     0,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,   426,     0,     0,     0,     0,  3167,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    37,     0,     0,
       0,     0,     0,     0,     0,   317,     0,     0,     0,     0,
       0,  3168,     0,     0,     0,     0,     0,     0,     0,    37,
       0,     0,     0,     0,     0,     0,   780,     0,   426,  3119,
    1723,  1724,  1725,  1726,  1727,  1728,  1729,  1730,  1731,  1732,
       0,     0,  1733,     0,     0,     0,    37,     0,     0,  2751,
    2760,   426,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    37,     0,     0,     0,     0,     0,     0,   427,     0,
       0,  3216,  1723,  1724,  1725,  1726,  1727,  1728,  1729,  1730,
    1731,  1732,     0,     0,  1733,  3120,  1723,  1724,  1725,  1726,
    1727,  1728,  1729,  1730,  1731,  1732,    37,     0,  1733,     0,
       0,     0,     0,   667,     0,   869,     0,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,   426,     0,     0,
       0,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      37,     0,     0,     0,   426,  3169,  2021,  2022,  2023,  2024,
    2025,  2026,  2027,  2028,  2029,  2030,     0,     0,  2031,     0,
       0,     0,    37,     0,     0,     0,     0,   712,     0,   426,
       0,  1723,  1724,  1725,  1726,  1727,  1728,  1729,  1730,  1731,
    1732,     0,     0,  1733,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,   426,     0,     0,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    37,     0,     0,     0,
       0,     0,     0,   867,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,     0,     0,     0,   868,     0,   426,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    37,     0,
     426,     0,     0,     0,     0,     0,     0,     0,  3279,     0,
       0,     0,     0,     0,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    37,     0,     0,     0,     0,     0,     0,
     870,  3170,  2021,  2022,  2023,  2024,  2025,  2026,  2027,  2028,
    2029,  2030,     0,     0,  2031,    37,     0,     0,     0,     0,
       0,     0,   907,     0,   426,     0,     0,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    37,     0,   934,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    37,
       0,     0,     0,     0,   950,     0,   426,  3280,  2021,  2022,
    2023,  2024,  2025,  2026,  2027,  2028,  2029,  2030,     0,     0,
    2031,  3191,  2021,  2022,  2023,  2024,  2025,  2026,  2027,  2028,
    2029,  2030,    37,     0,  2031,     0,     0,     0,     0,   986,
       0,  1014,     0,     0,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,  1019,     0,  2021,  2022,  2023,  2024,  2025,
    2026,  2027,  2028,  2029,  2030,     0,     0,  2031,     0,     0,
       0,     0,     0,     0,     0,     0,    37,     0,     0,     0,
       0,     0,     0,   993,     0,  1024,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,   999,     0,  1031,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
     426,     0,     0,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    37,     0,     0,     0,     0,     0,     0,  1010,
       0,     0,     0,     0,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,  1816,     0,     0,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    37,     0,     0,     0,
       0,  1011,     0,     0,  3303,     0,     0,     0,     0,     0,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    37,
       0,     0,     0,     0,     0,     0,  1015,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    37,     0,     0,     0,     0,     0,     0,  1020,     0,
     426,  3304,     0,     0,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    37,     0,     0,     0,     0,     0,     0,
    1025,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    37,     0,     0,     0,     0,
       0,     0,  1032,     0,  2681,     0,  2021,  2022,  2023,  2024,
    2025,  2026,  2027,  2028,  2029,  2030,     0,     0,  2031,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    37,     0,
       0,     0,     0,     0,     0,  1261,     0,   426,     0,     0,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,   426,
       0,  2021,  2022,  2023,  2024,  2025,  2026,  2027,  2028,  2029,
    2030,     0,     0,  2031,     0,     0,     0,     0,     0,     0,
       0,     0,    37,     0,     0,     0,     0,     0,     0,  1817,
       0,   426,     0,     0,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,   426,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,   426,     0,     0,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    37,     0,
       0,     0,     0,     0,     0,  2680,     0,     0,     0,     0,
       0,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
     426,     0,     0,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    37,     0,     0,     0,     0,     0,     0,  2682,
       0,     0,  3347,     0,     0,     0,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    37,     0,     0,     0,     0,
       0,     0,  2687,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    37,     0,     0,
       0,     0,     0,     0,  2688,     0,  2796,  3372,     0,     0,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    37,
       0,     0,     0,     0,     0,     0,  2707,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    37,     0,     0,     0,     0,     0,     0,  2721,     0,
     426,     0,  2021,  2022,  2023,  2024,  2025,  2026,  2027,  2028,
    2029,  2030,     0,     0,  2031,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    37,     0,     0,     0,     0,     0,
       0,  2762,     0,   426,     0,     0,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,   426,     0,  2021,  2022,  2023,
    2024,  2025,  2026,  2027,  2028,  2029,  2030,     0,     0,  2031,
       0,     0,     0,     0,     0,     0,     0,     0,    37,     0,
       0,     0,     0,     0,     0,  2795,     0,   426,     0,     0,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,   426,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,   426,     0,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    37,     0,     0,     0,     0,     0,
       0,  2797,     0,     0,     0,     0,     0,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,  3203,     0,     0,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    37,     0,
       0,     0,     0,     0,     0,  2811,     0,     0,  3386,     0,
       0,     0,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    37,     0,     0,     0,     0,     0,     0,  2813,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2814,  2815,  3221,     0,     0,     0,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    37,     0,     0,     0,     0,
       0,     0,  2819,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    37,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2836,     0,  3221,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    37,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3123,     0,  3227,
       0,     0,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    37,     0,     0,     0,
    2021,  2022,  2023,  2024,  2025,  2026,  2027,  2028,  2029,  2030,
       0,  3204,  2031,     0,     0,     0,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,  2021,  2022,  2023,  2024,  2025,
    2026,  2027,  2028,  2029,  2030,     0,     0,  2031,     0,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    37,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3222,     0,     0,
       0,     0,     0,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    37,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3226,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    37,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  3228,     0,     0,     0,     0,     0,
      37,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2063,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    37,  2816,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2299,  2093,     0,
       0,     0,    37,     0,     0,     0,  2021,  2022,  2023,  2024,
    2025,  2026,  2027,  2028,  2029,  2030,     0,  2095,  2031,  2817,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    37,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2194,     0,  2148,
       0,     0,     0,     0,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    37,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2228,
    1468,  1469,     0,     0,     0,     0,     0,     0,     0,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   258,    37,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    37,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2722,  2723,     0,
    2310,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    37,
    2818,     0,     0,     0,     0,     0,  3067,  3068,     0,     0,
       0,     0,     0,     0,  2372,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    37,  2626,     0,     0,     0,     0,
       0,     0,     0,     0,  2405,     0,     0,     0,     0,     0,
     258,     0,     0,    37,     0,     0,     0,     0,     0,  3165,
       0,     0,     0,  2410,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    37,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2413,     0,  3300,     0,
       0,     0,     0,     0,   258,     0,     0,     0,     0,     0,
       0,    37,     0,     0,     0,  2423,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    37,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2542,     0,     0,     0,    37,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,  1470,    37,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    37,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,  2156,  2157,  2158,    37,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
    2724,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      37,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,  3069,
      37,  1693,     0,     0,     0,     0,     0,     0,     0,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    37,     0,
       0,     0,     0,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,     0,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
       0,     0,     0,     0,     0,     0,     0,     0,   426,     0,
       0,     0,     0,     0,     0,     0,     0,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,  2622,  2021,  2022,  2023,  2024,
    2025,  2026,  2027,  2028,  2029,  2030,     0,     0,  2031,  1723,
    1724,  1725,  1726,  1727,  1728,  1729,  1730,  1731,  1732,     0,
       0,  1733,     0,     0,     0,     0,     0,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,  3162,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,  3297,  2021,  2022,  2023,  2024,  2025,
    2026,  2027,  2028,  2029,  2030,     0,     0,  2031,  2021,  2022,
    2023,  2024,  2025,  2026,  2027,  2028,  2029,  2030,     0,     0,
    2031,  2021,  2022,  2023,  2024,  2025,  2026,  2027,  2028,  2029,
    2030,     0,     0,  2031,  2021,  2022,  2023,  2024,  2025,  2026,
    2027,  2028,  2029,  2030,     0,     0,  2031,  2021,  2022,  2023,
    2024,  2025,  2026,  2027,  2028,  2029,  2030,     0,     0,  2031,
    2021,  2022,  2023,  2024,  2025,  2026,  2027,  2028,  2029,  2030,
       0,     0,  2031,  1723,  1724,  1725,  1726,  1727,  1728,  1729,
    1730,  1731,  1732,     0,     0,  1733,  2021,  2022,  2023,  2024,
    2025,  2026,  2027,  2028,  2029,  2030,     0,     0,  2031,  2021,
    2022,  2023,  2024,  2025,  2026,  2027,  2028,  2029,  2030,     0,
    2949,  2031,  2021,  2022,  2023,  2024,  2025,  2026,  2027,  2028,
    2029,  2030,     0,  2975,  2031,  2021,  2022,  2023,  2024,  2025,
    2026,  2027,  2028,  2029,  2030,     0,     0,  2031,  2021,  2022,
    2023,  2024,  2025,  2026,  2027,  2028,  2029,  2030,     0,     0,
    2031,  2021,  2022,  2023,  2024,  2025,  2026,  2027,  2028,  2029,
    2030,     0,     0,  2031,  2021,  2022,  2023,  2024,  2025,  2026,
    2027,  2028,  2029,  2030,     0,     0,  2031,  2021,  2022,  2023,
    2024,  2025,  2026,  2027,  2028,  2029,  2030,     0,     0,  2031,
    1723,  1724,  1725,  1726,  1727,  1728,  1729,  1730,  1731,  1732,
       0,     0,  1733,  2021,  2022,  2023,  2024,  2025,  2026,  2027,
    2028,  2029,  2030,     0,     0,  2031,     0,     0,     0,  2989,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  2999,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  3010,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3085,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3088,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  3095,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3106,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3116,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3126,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  3192,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3193,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  3198,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  3217,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3218,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3220,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  3274,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3321
  };

  const short int
  parser::yycheck_[] =
  {
       0,   265,   337,     3,   951,   955,   474,   682,   714,   938,
     249,  1625,   229,    13,   755,   350,   229,   229,   214,   319,
      20,   321,   279,   323,   214,   229,   229,   353,   240,   229,
     248,  1589,    32,   229,   229,   340,   248,   220,   331,   331,
      40,    41,    42,   348,   248,    45,   229,   229,    48,   331,
     331,    51,   342,   331,   248,   214,   342,   240,    58,    59,
      60,   307,    62,    63,    64,    65,    66,   307,    68,   342,
     229,   340,   342,   342,   272,   344,   342,   346,   331,   348,
     285,   350,   257,   342,   340,   310,   283,   342,   344,   304,
     220,  1644,   285,   342,   350,    95,   248,   248,   212,   342,
    1644,   342,   272,   302,   297,   272,   304,  1721,  1561,   342,
     110,   272,   236,   331,  1965,   332,   248,   236,   248,   331,
     874,   334,   304,  2048,   283,   342,   342,   331,   229,   332,
    2114,   331,   291,   229,   229,   331,   331,   331,   297,   342,
     291,   331,  2709,   229,   240,   248,    61,   219,   331,   331,
    1856,  1857,   248,   342,   240,   117,   229,   229,   253,   340,
     340,   340,   248,    61,   340,   346,    61,   340,    61,   350,
     350,   350,   331,    61,   350,   334,   340,   350,   229,   229,
     229,  2453,  2454,   342,   229,   340,   350,   342,    53,   344,
     340,   346,   340,   348,   117,   350,   229,    61,   229,   229,
     350,   229,   350,  1480,   340,   229,   117,   246,   147,   229,
     229,   130,   229,   229,   350,   215,  2614,    76,  2614,  3081,
      59,    76,   222,  1492,   224,   225,   226,   117,   331,    59,
     230,   231,   232,   233,   229,   331,   229,   229,   238,   229,
     229,   241,   242,   243,  2614,   331,   246,    76,    59,   249,
     117,   117,   252,  2614,   254,  1532,   117,  1534,   117,   130,
      76,   261,   117,  1532,  2614,  1534,   117,  2614,   268,   269,
     270,   117,   130,   273,   274,   275,   117,    10,   324,   279,
     109,   281,   224,   225,   752,  1991,   286,   287,   117,  2614,
    2756,  1560,   292,   293,    38,    59,   161,   206,   190,   191,
      76,   117,    76,   302,   302,   305,  3061,    59,   308,    76,
     324,   311,   254,   219,    61,   315,   316,    76,   318,   261,
     320,   302,   322,   229,   324,   325,   117,   324,   331,    35,
     324,    37,   402,   324,    61,  3090,    76,   236,   338,    76,
     324,   117,   117,   117,    45,   287,   133,    45,   302,   302,
     117,   117,  2459,  2460,    38,   220,  2463,    38,   117,    92,
     310,   361,   362,   363,   364,   233,   366,    84,    85,    86,
      87,    88,    89,    90,    91,    59,   302,   117,    59,   285,
     117,   465,    59,    61,    76,   118,   119,   120,   287,   302,
     117,   297,   179,   549,   550,   206,   302,   324,   302,    61,
      48,   324,    45,    41,    42,    76,   549,   483,   324,    83,
     553,   550,   482,   551,   484,   485,   550,   555,   549,   302,
      76,   302,   498,    76,   508,   117,   426,    70,    71,    72,
      78,    79,   194,   195,   196,    10,   520,   521,   109,     3,
      78,   551,   310,   311,   312,   555,   117,   324,    76,    13,
    1903,    76,   302,   109,   206,   549,    20,   302,   550,  1912,
     324,   117,  1915,   324,   117,   324,   466,   302,   324,   550,
     302,   310,   331,   332,   474,   302,    40,    41,   324,   550,
     310,    45,   549,   324,    48,   524,   219,    51,    76,   117,
     257,   220,   117,  3355,    58,    59,    60,   140,    62,    63,
    3255,    76,   331,   332,   324,   551,   550,   236,   324,   549,
     550,   240,  3267,   432,  1783,   331,   332,    92,   331,   248,
     549,   109,   786,  1473,   324,  2915,  1476,   324,   234,   117,
     236,    95,   471,   234,   109,   324,   549,   551,   236,   431,
     331,   332,   117,   118,   119,   120,   310,   264,   551,   550,
     324,   550,   550,   550,   283,   331,   332,   331,   332,   553,
     266,   432,   553,  2953,   331,   332,   310,   551,   297,   550,
     303,   871,   872,   274,   432,   484,   485,   152,   325,   326,
     327,   328,   329,   330,   331,   332,   333,   334,   550,   164,
     337,   331,   332,   324,   331,   332,   550,   550,   241,  3354,
     465,   176,   177,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   323,   550,   550,   299,   310,   884,   885,   310,
     553,   206,   207,    45,   282,   551,  3034,   550,  3034,   331,
     332,   556,   553,   508,   219,   902,   550,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   334,   233,   556,   337,
     550,   556,   550,   556,  3034,   530,   531,   550,   668,   550,
     670,   671,  1622,  3034,   551,   675,   676,   677,   331,   332,
     680,   681,   682,   550,  3034,   549,   552,  3034,   549,   117,
     549,   550,  2964,  1970,  3261,   551,   324,   552,   549,   324,
     550,  1970,   702,   331,   332,   550,   331,   332,   549,  3034,
     443,   486,   487,   324,   714,   550,  1016,  1017,   550,   719,
     324,  1021,  1022,   550,   553,   402,  1026,  1027,   303,   324,
     324,   551,    46,    47,    76,  3201,  3202,   553,   324,   324,
     324,   552,   555,   331,   332,  3211,  2671,  3213,   550,  2674,
     324,   551,   752,   549,   551,   755,   331,   332,    72,    73,
     550,   761,   551,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   324,    11,   117,   351,   553,   552,   779,
     355,   356,   357,   550,   784,    76,    38,   550,   788,   324,
      27,   791,  3182,   324,   794,   324,   324,   550,   515,   324,
     324,   324,   549,    40,   413,   482,  3196,   484,   485,   324,
     550,   270,   550,   550,  1764,   458,   324,   324,   109,   549,
     551,    58,   431,   324,   549,  3097,   117,   333,   334,    59,
     324,   337,   324,   324,   293,   294,   324,   779,   324,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   550,    84,
      85,    86,    87,    88,    89,    90,    91,   324,   443,   869,
     324,   549,   324,   873,   874,   324,   324,   324,   324,     4,
       5,     6,   324,   324,   884,   885,   549,   463,   549,    76,
      38,   331,   332,    76,    35,   209,   550,   550,   549,   136,
      76,   550,   902,   331,   332,    76,   318,   319,   333,   334,
      35,    59,   337,   489,   490,   491,   492,   154,   549,   550,
      45,   549,   550,   549,  3314,   550,   549,  3199,   549,   550,
     117,   549,   550,    38,   117,   549,   936,   937,   109,  1693,
     551,   117,  1696,   550,  2928,   549,   117,    72,   202,   203,
     204,   951,    93,    94,   206,   556,   551,   551,   550,   427,
     428,   429,   549,   431,   549,   551,  1916,   551,    93,    94,
      38,   208,   972,   550,    61,   550,   206,   551,   390,   391,
     392,   393,   394,   108,   427,   428,   429,   550,   431,   331,
     332,    59,   404,   405,   406,   232,  1946,  1947,   549,   411,
     412,   126,   414,   415,   318,   319,   465,   550,   365,   468,
     135,   263,   137,    61,  1014,   140,   551,   549,   550,  1019,
     551,    28,   551,   551,  1024,   437,   551,   551,   551,  1029,
     155,  1031,   549,   324,    12,   287,   551,   549,   550,   264,
     331,   332,    77,   551,   551,  2896,   171,   549,   507,   508,
     551,   510,   511,   465,   513,   514,   515,   551,   206,   551,
     551,   520,    28,   551,    68,   551,   549,   550,   305,   489,
     211,    28,   531,    68,   257,   216,   496,   497,   149,   499,
     265,   257,   550,   550,   209,   151,   211,   331,   332,   333,
     334,   216,   231,   337,   551,   236,   508,   551,    57,   551,
     512,   206,   551,   551,   551,   551,   202,   203,   204,   551,
     551,   310,   552,   549,   550,   263,   241,   242,   549,   550,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,  2589,   324,   206,   287,
     112,   113,   114,  2757,   331,   332,   549,   550,   331,   332,
     117,  2709,   549,   550,   549,   331,   332,   501,   502,   503,
     504,  2867,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   306,   287,   236,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,  2153,  2154,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   106,   231,   337,   206,   287,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   549,   550,   337,   549,   550,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   552,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   327,   328,   329,   330,   206,
     515,   250,   251,   252,   253,   254,   255,   432,  1494,   331,
     332,   333,   334,   472,  1494,   337,   549,   550,   549,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,  1511,   549,
     550,   549,   550,   224,    61,  1494,   549,   550,   549,   550,
     549,   550,   549,   550,    61,   236,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,    61,  1583,   549,   550,    61,
    1583,  1583,   549,   550,   549,   550,  1490,   549,   550,  1583,
    1583,  1511,    61,  1583,   549,   550,    61,  1583,  1583,  1689,
    1690,    61,   517,   518,   519,   286,   198,   199,    61,  1611,
    1583,  1583,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,  1631,    61,   337,    78,    79,    61,  1631,
      61,    61,    61,   324,  1583,   551,  2979,  1631,  1611,   320,
     321,   551,  2382,  1505,  2384,  2979,    61,  1631,   795,    61,
      61,   324,   551,  1700,  1701,  1702,  1703,   551,    61,  1706,
    1707,  1708,  1709,  1710,  1711,  1712,  1713,  1714,  1715,  1716,
    1717,  1718,  1719,  1720,   324,   551,  1723,  1724,  1725,  1726,
    1727,  1728,  1729,  1730,  1731,  1732,  1733,  1652,  1478,  1631,
    1631,  1605,  1583,  1483,  1484,    61,  1605,  1583,  1583,  1687,
     551,   115,   116,  1493,    61,    61,  1496,  1583,  3112,  1631,
    3114,  1631,    61,    61,  1804,  1805,    61,    61,  1808,  1809,
    1583,  1583,  1812,  1813,    61,  1611,  1516,  1687,  1518,  1519,
    1687,    61,  3080,    61,  3082,  1611,  1687,  1527,  1631,    61,
     324,  1531,  1583,  1583,  1583,  1631,  1478,    61,  1583,  1744,
    1737,   549,  1788,    61,    61,  1631,   551,    61,  1788,   551,
    1583,  1744,  1583,  1583,   551,  1583,    61,  1557,  1558,  1583,
    1853,  1853,  1562,  1583,  1583,  1790,  1583,  1583,  1568,  1784,
    3023,  1853,  1853,  3026,  1767,  1853,    61,  3030,  1737,  3032,
    3033,  1780,    61,  1918,  1584,    61,  1784,    61,  1583,  1531,
    1583,  1583,    61,  1583,  1583,    61,  1755,    61,    61,  1505,
    1853,    61,  1784,   324,  1755,   229,   230,    61,  1767,    61,
     324,    61,  1612,   237,    61,  1920,  1558,    61,  1618,  1954,
    1562,    61,    61,    61,    61,    61,    61,    61,  1628,   551,
      61,    61,    61,    61,  1634,  1853,   551,  1637,    61,  2589,
      61,  1853,  1859,  1643,  1644,  1971,  1951,    61,  1938,  1853,
      61,  1920,  1938,  1853,    61,  1655,  1859,  1853,  1853,  1853,
      61,    61,  3276,  1853,  1920,  1938,    61,  1667,  1938,  1938,
    1853,  1853,  1938,  1673,  1943,   206,  1618,  1583,  1678,  1938,
    1949,    61,  1951,  1938,    61,  1954,  1628,  1943,  1688,  1938,
      61,  1904,  1634,  1693,  1853,  1938,  1696,  1938,  1954,    61,
    1700,  1701,  1702,  1703,  3262,  1938,  1706,  1707,  1708,  1709,
    1710,  1711,  1712,  1713,  1714,  1715,  1716,  1717,  1718,  1719,
    1720,  1938,  1938,  1723,  1724,  1725,  1726,  1727,  1728,  1729,
    1730,  1731,  1732,  1733,    61,  1938,  1678,    61,    61,  1920,
    1920,  1920,    61,    61,  1920,  1904,  2696,  1920,  2698,  1938,
    1853,    61,  1752,  1753,  1754,    61,  1920,  1853,  1758,  1759,
      61,    61,    61,    61,    61,  1920,    38,  1853,  1949,  1769,
    1920,  1771,  1920,  1954,  1954,  1954,  1776,  1777,  1954,  1938,
      61,  1954,  1511,  1938,  1920,  1785,    61,    59,  1943,  1789,
    1954,  1791,    61,    61,  1949,    61,  1951,    61,  3356,  1954,
      61,  1801,    96,    61,  1954,    61,  1954,   101,   102,   103,
     551,   324,   270,   324,   551,   550,  1816,   551,  1954,    61,
     324,    61,    61,    61,    61,    61,    61,  1769,   279,  1771,
      61,    61,   551,   324,    61,   293,   294,   131,  1744,   551,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,  2801,   551,   337,  1854,  1855,   150,   551,    61,   153,
    2099,  1767,    61,    61,    61,  2794,  1866,    61,    61,   551,
     550,   324,    61,   551,  1780,    61,  1605,   550,    61,    61,
      61,    61,  1611,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,  1631,    61,    61,    61,    61,    61,  1908,    61,
    1910,  1911,  1854,   550,   549,    61,   550,   550,   550,  1919,
     550,   550,   550,   550,  1866,    61,    96,   550,    61,  1493,
     550,   101,   102,   103,   206,   550,   550,    61,   550,   270,
     550,    19,    20,    21,    22,    23,    24,    25,  2898,   550,
     550,   550,   550,   550,  1518,  1519,   550,   550,    36,   550,
      61,   131,   293,   294,    61,   259,  1908,    45,  1910,  1911,
     551,   551,    61,  1973,    61,  1975,  1976,   551,   324,  1979,
     150,    61,    61,   153,  2934,  1985,  1986,  2937,    61,  1989,
      61,   285,  1992,  1993,    72,  1995,  1996,  1997,  2739,  1999,
      61,    61,    61,  2260,   324,   551,    61,   465,  1737,    61,
     468,  2268,  2312,  2252,    61,   287,    61,    61,    61,    61,
    1584,    61,  2286,  2729,   555,    61,    61,    61,    61,    61,
      61,  1973,    61,  1975,  1976,    61,    61,  1979,  1767,    61,
     465,    61,    61,    61,  2719,    61,    61,    61,  1612,   507,
     508,   509,   510,   511,    61,   513,   514,    61,    61,    61,
      61,    61,   520,    61,  2064,    61,  2066,   551,    61,    61,
      61,    61,    61,   531,    61,  3025,    61,   324,  2078,  3029,
      61,   551,   507,   508,    61,    61,    61,    61,    38,    61,
      61,  1448,  1449,    61,  2094,  2352,  2096,    61,    61,  2099,
     525,   526,   527,   528,   529,    61,  3056,  1464,    61,    59,
      61,   324,    61,    61,    61,   285,    61,    61,    61,  2119,
      61,    61,    61,    61,  1688,    61,    61,  2427,    61,    61,
    2430,   209,   210,  2433,   465,    61,    61,   468,    61,    61,
      61,    61,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,    61,    61,   241,   242,  1522,    61,    61,  2425,  2426,
      61,    61,    61,    61,    61,    61,   507,   508,    61,   510,
     511,  3128,   513,   514,   515,   516,    61,    61,    61,    61,
    1754,    61,   551,    61,    61,  2195,  2196,    61,    61,    61,
     531,   327,   328,   329,   330,   331,   332,   333,   334,    45,
    2210,   337,  1776,    38,  2214,    61,    61,    61,  2218,    61,
      61,  1785,  2690,    61,    61,  1789,   324,  1791,   324,  2229,
    2230,  3181,  1589,    61,    59,   551,  2236,  1801,  1595,   551,
     318,   319,    61,  1600,   327,   328,   329,   330,   331,   332,
     333,   334,  2252,  1610,   337,    61,   206,    61,  2258,  3209,
    2260,    61,    61,    61,  1621,  2733,    59,    61,  2268,    61,
      61,  2271,  2529,  2273,    61,    61,    61,    61,  2278,  2614,
      61,    61,    61,    76,   551,   324,    61,    61,   551,    61,
      61,    61,  2292,    61,   324,   131,   132,   324,   551,   551,
     324,    61,  3252,   324,    61,   551,    61,   143,  3258,    61,
     761,  2311,   415,  1670,   150,  1672,    61,   153,   421,   422,
     423,   424,   425,   426,   117,  3275,    61,   778,    61,   165,
      61,  2273,    61,   436,    61,    61,  2278,   287,    61,   442,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,    61,  2352,   337,    61,  1919,   556,   549,  3308,   152,
     550,    61,   550,   550,  2364,   550,  2366,   117,   117,   117,
     549,   164,   556,  2373,   550,   550,  2376,   549,   556,   215,
     117,   206,   550,   176,   177,   550,   550,   550,   550,   550,
    2390,   550,  2392,   117,   324,   117,  2396,   550,   117,   550,
     236,   550,   550,   550,   117,  1762,  2406,  2407,   550,   550,
     550,  2411,   550,   206,  2414,   550,   550,   556,   550,   550,
     117,   117,   552,   117,  2424,  2425,  2426,   117,   117,   117,
    1787,   549,   117,   884,   885,  1792,  1793,  1794,  1795,   550,
     117,   549,   549,   279,   549,   549,   117,   283,   257,   285,
     549,   902,   117,   117,   117,   550,   117,   117,  2458,  2459,
    2460,   117,   287,  2463,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   117,   320,   321,  2743,  2744,   117,  2489,
     117,  2755,   117,   117,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   955,   117,   337,   117,  2765,  2766,
     117,   552,   550,   117,  2078,   117,   117,   117,   117,   324,
     117,   324,   550,   324,  2781,   117,  2783,   324,   117,  2529,
     117,   117,   549,   556,   117,   117,   549,   549,   331,   332,
      45,   549,   117,  2543,   549,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,  2119,   206,   117,   351,    61,
     117,   549,   355,   356,   357,   358,   359,   551,   550,   549,
     549,   549,   117,   117,   117,   117,    81,   550,   117,   549,
     549,   117,   549,   549,   549,   117,   337,   549,  2588,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   325,   326,
     327,   328,   329,   330,   331,   332,   333,   334,   549,   117,
     337,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     549,   551,   550,  2000,  2001,  2002,  2003,   549,   549,  2006,
    2007,  2008,  2009,  2010,  2011,  2012,  2013,  2014,  2015,  2016,
    2017,  2018,  2019,   117,  2021,  2022,  2023,  2024,  2025,  2026,
    2027,  2028,  2029,  2030,  2031,   324,   117,  2677,    38,   550,
     549,  2681,    61,   549,  2684,   550,   117,   117,   549,   549,
    2690,   549,   549,  2693,   549,   549,   549,   549,   549,  3034,
     549,   549,   117,   550,   117,   117,   549,  2271,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,  2719,
     551,   337,   549,   117,   550,   549,   117,   117,   117,  2729,
     131,   132,   117,  2733,   117,   117,   117,  2994,  2995,  2739,
     117,   117,   143,  2743,  2744,   552,   117,  2747,   550,   150,
    2750,   117,   153,   117,   550,   550,   117,   550,   117,   552,
      38,   554,   550,   117,   165,  2765,  2766,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   334,   117,   117,   337,
     549,  2781,   549,  2783,   117,   550,   117,   117,   117,  2789,
     117,   117,   117,   117,   117,   117,  2796,    38,   117,   117,
     117,   117,   117,   117,   117,   117,  2806,  2807,   117,   117,
     117,   117,  2812,   117,   215,   117,   117,   117,   117,    97,
     117,   117,   117,   117,   549,   117,  2390,   117,  2392,  2829,
     117,   117,  3132,   117,  2834,   549,   117,   117,   117,   481,
     117,  2841,   117,  2407,   117,   117,   206,  3104,   549,   117,
     117,   117,   117,   117,  2211,   117,    97,   549,  2215,   552,
     117,   552,  3119,  3120,   117,  2865,   549,   549,  2868,   549,
     549,  2871,   117,   549,   549,   549,   549,   117,   279,   117,
     549,   549,   283,   550,   285,   390,   391,   392,   393,   394,
     395,   396,   129,   337,   399,   400,   549,   555,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   550,   549,   414,
     415,   416,   417,   418,   419,   420,   236,   550,   549,   320,
     321,   551,   257,  3223,  3224,  2489,  2926,   287,   206,   257,
     549,   324,   437,   438,   439,   440,   441,  2294,   324,   444,
     445,   446,   447,   448,   117,   450,   451,   452,   453,   454,
     455,   456,   117,   551,   459,   460,   461,   551,   551,   324,
     551,    61,    61,   551,   549,   206,  2966,   236,  2968,   257,
    2970,   551,   551,   551,   337,   549,   549,  2977,   331,  2979,
     117,   117,  3282,  3283,   549,   549,   324,   324,   551,   551,
     556,    61,   324,   551,  2994,  2995,   551,  2997,    61,    61,
     556,   550,   556,    61,  3004,   555,   117,   117,  2365,   556,
     550,   549,  3012,  3013,   324,   556,    61,   551,   549,  3019,
     549,  1472,  1473,  1474,  2588,  1476,   324,   532,  2385,   117,
     257,   324,   549,  3333,   550,  2977,    61,  1488,    61,   324,
    3040,   324,  2399,  3043,    61,   549,   549,    61,   324,  1500,
    1501,   551,  1503,   324,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   551,   551,  1526,   551,  1528,  1529,    61,
      61,    61,    61,    61,    61,    61,  1537,    61,  1539,  1540,
     556,   556,   556,  1544,  1545,  1546,  1547,  1548,  1549,   130,
     549,    61,  3102,  1554,  3104,    61,   117,   550,   555,     4,
       5,     6,   549,   324,  1565,   324,   324,   549,   551,  3119,
    3120,   432,   550,  1574,  1575,   549,   549,  1578,  3128,   549,
     549,  3131,   549,  3133,  3134,   549,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   549,   129,   337,   117,   549,
     117,  1622,   550,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   481,  1644,   551,   551,   551,  1648,    93,    94,
     549,   309,   257,  3203,   555,   550,   556,  1658,   325,   326,
     327,   328,   329,   330,   331,   332,   333,   334,    61,   324,
     337,  3221,   324,   302,  1675,  2789,   309,  3227,  1679,   324,
    1681,   126,  1683,   324,   302,   117,   117,   481,   324,   324,
     135,  3241,   137,  3243,   549,    59,   324,   324,   302,  1700,
    1701,  1702,  1703,   556,   302,  1706,  1707,  1708,  1709,  1710,
    1711,  1712,  1713,  1714,  1715,  1716,  1717,  1718,  1719,  1720,
      61,   553,  1723,  1724,  1725,  1726,  1727,  1728,  1729,  1730,
    1731,  1732,  1733,   117,    76,   129,   556,   182,  1739,  1740,
    3290,  1742,   550,   556,   549,  3295,   556,   556,    59,   555,
     549,  2658,   550,   555,   550,   432,   549,   130,   117,  1760,
    1761,   550,    61,  1764,   549,    76,   211,   549,   549,   553,
     549,   216,   550,   549,   549,   117,   550,   302,   324,    38,
     302,  1782,   227,   228,   556,   556,   549,  3337,  3338,   234,
     550,   236,   549,   432,  3344,   551,   550,   130,  1799,   549,
     549,   324,   117,   248,   249,   324,   117,  2714,   324,   324,
     152,   549,   324,  2720,  3364,   549,  3366,   324,   551,    59,
     117,   266,   164,   117,  2731,   549,   324,   117,   110,   551,
     551,   551,  1833,  1834,   176,   177,  1837,  1838,    97,   551,
    2236,   152,   206,  3013,  1845,  1652,  1847,  1848,  1849,  1850,
    1851,  2750,  2759,   164,  2742,  2369,  3344,  1960,  3341,  1971,
    3236,   306,   307,  2286,   206,   176,   177,  1968,  2754,  2382,
    1505,  3209,   357,  1767,  1981,  1876,  1877,  1659,  1977,  1784,
    2218,   361,  1859,  1884,   551,   671,  2793,  3034,   363,  3058,
     364,   702,  2935,  2899,   677,   206,  2803,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   334,  2938,  1583,   337,
    3259,  1687,  1631,  1800,  1655,  1916,  1001,  1788,  1954,  1918,
     365,  1904,  1923,  1924,  1925,  1485,  1927,  1920,  1951,  1930,
    1931,  1490,  1949,  1938,  1943,  1936,  1937,  1853,  1611,   719,
    1755,  1777,  1605,  2258,  3004,  1946,  1947,   206,    59,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
    3028,  1494,   337,   467,  1965,  1775,   206,  2874,  2875,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,    -1,
      -1,   337,  1989,  2890,    -1,  2892,    -1,   791,   788,   331,
     332,    -1,    -1,    -1,    -1,    -1,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,  1511,    59,    -1,   351,
      -1,    -1,    -1,   355,   356,   357,   358,   359,    -1,    -1,
     331,   332,    -1,    -1,    -1,    -1,    -1,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,    -1,  2945,  2946,
     351,  2948,    -1,    -1,   355,   356,   357,   358,   359,  2956,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,    -1,
      -1,    -1,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,  2998,    -1,  3000,    -1,   206,    -1,    -1,    -1,    -1,
      -1,    -1,  3009,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,    -1,   551,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,    -1,    -1,   337,    -1,    -1,    -1,
    2141,  2142,  3049,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    3057,    -1,  2153,  2154,   206,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,    -1,    -1,   551,    -1,    -1,    19,    20,
      21,    22,    23,    24,    25,    26,    59,    -1,   550,    -1,
     552,    -1,   554,    -1,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,  3136,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   550,
      -1,   552,    -1,   554,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2260,
      81,    -1,  3169,  3170,    -1,    -1,    -1,  2268,   325,   326,
     327,   328,   329,   330,   331,   332,   333,   334,    -1,  2280,
     337,    -1,    -1,    -1,  3191,    -1,    -1,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   334,    -1,    -1,   337,
      -1,    -1,    59,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,    -1,    -1,  3231,  3232,    -1,    -1,    -1,  3236,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
      -1,    -1,   337,    -1,  3251,    -1,    -1,    -1,    -1,    -1,
     551,  2352,    -1,   206,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,  2382,    -1,  2384,  3291,    -1,    -1,    -1,   209,   210,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
      -1,    -1,   337,  3310,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     0,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     241,   242,    -1,    -1,  2425,  2426,    14,    15,    -1,    -1,
      -1,    -1,    -1,    -1,  3341,    -1,    -1,    -1,    -1,    -1,
      -1,  3348,    30,    31,    32,    33,    34,    -1,    -1,   206,
      38,    -1,  2453,  2454,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    56,    -1,
      -1,    -1,    60,    -1,    62,    63,    64,    65,    66,    -1,
      -1,    -1,  3389,    -1,    -1,    -1,    74,    75,    -1,    -1,
      -1,    -1,    59,    81,   551,    -1,    -1,   318,   319,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    97,
      98,    99,   100,   551,    -1,    -1,    -1,    -1,    -1,    -1,
     108,    -1,   110,   111,    -1,    -1,    -1,    -1,  2529,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   124,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   334,    -1,    -1,   337,
      -1,   139,    -1,    -1,    -1,    -1,   551,    -1,    59,    -1,
     148,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
      -1,    -1,    -1,    59,   172,   173,   174,   175,  2589,    -1,
     178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   187,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,    -1,    -1,   337,    -1,    -1,   551,    -1,   206,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,    -1,
      -1,   337,    -1,   221,    -1,   223,    -1,   225,   226,   206,
      59,    -1,    -1,    -1,    -1,   233,    -1,    -1,   236,    -1,
     238,   239,    -1,    -1,    -1,   243,   244,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,    -1,    -1,    -1,    -1,
     268,   269,    -1,   271,   272,   273,    -1,   275,   276,    -1,
      -1,    -1,    -1,   281,    -1,  2696,   284,  2698,    -1,    -1,
     288,   289,    -1,    -1,    -1,   206,    -1,    -1,   296,   297,
     298,    -1,   300,    -1,    -1,    -1,   304,    -1,    -1,    -1,
      -1,    -1,   310,   311,   312,   313,   314,   315,   316,   317,
     206,    -1,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,  2743,  2744,   337,    -1,    -1,    -1,    -1,  2750,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
      -1,    -1,   337,   551,  2765,  2766,    -1,    -1,    -1,    -1,
      -1,    -1,   360,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2781,    -1,  2783,    -1,    -1,    -1,    -1,   206,    -1,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,    -1,
    2801,   337,    -1,    -1,    -1,    -1,    -1,   395,   325,   326,
     327,   328,   329,   330,   331,   332,   333,   334,    -1,    -1,
     337,    -1,    -1,    -1,    -1,   549,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   551,    -1,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,    -1,    -1,   337,    -1,
      -1,   469,   470,    -1,    -1,   473,   474,   475,   476,   477,
     478,   479,   480,    -1,    -1,    -1,  2897,  2898,    -1,    -1,
     488,    -1,    -1,    -1,    -1,   493,   494,    -1,    -1,    -1,
      -1,    -1,   500,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,    -1,  2934,   522,   523,  2937,    -1,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,    -1,   551,    -1,
     548,    -1,    -1,  2964,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,    -1,   551,   337,  2979,    -1,
      -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2994,  2995,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,    -1,   551,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3025,    -1,  3027,    -1,  3029,    -1,
      14,    15,    -1,    -1,   551,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    38,  3056,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,    -1,    -1,   337,    -1,
      54,    55,    56,    -1,    -1,    -1,    60,    -1,    62,    63,
      64,    65,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      74,    75,   551,    -1,    -1,    -1,  3097,    81,    -1,    -1,
      -1,    -1,    -1,  3104,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    97,    98,    99,   100,    76,  3119,  3120,
      -1,    -1,    -1,    -1,   108,    -1,   110,   111,   206,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,    -1,
     124,   337,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     109,    -1,    -1,    -1,    -1,   139,    -1,    -1,   117,    -1,
      -1,    -1,    -1,    -1,   148,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,    -1,    -1,   337,    -1,    -1,
    3181,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   172,   173,
     174,   175,    -1,   152,   178,    -1,    -1,    -1,  3199,    -1,
      -1,    -1,    -1,   187,    -1,   164,    -1,    -1,  3209,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   176,   177,    -1,
      -1,    -1,   206,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,    -1,    -1,   337,    -1,   221,    -1,   223,
      -1,   225,   226,    59,    -1,    -1,    -1,   206,   207,   233,
      -1,  3252,   236,    -1,   238,   239,    -1,  3258,    -1,   243,
     244,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,    -1,    -1,   337,  3275,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   551,    -1,   268,   269,    -1,   271,   272,   273,
      -1,   275,   276,    -1,    -1,    -1,    -1,   281,    -1,    -1,
     284,    -1,    -1,    -1,   288,   289,    -1,  3308,    -1,    -1,
      -1,    -1,   296,   297,   298,    -1,   300,    -1,    -1,    -1,
     304,    -1,    -1,    -1,    -1,    -1,   310,   311,   312,   313,
     314,   315,   316,   317,    -1,    -1,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   551,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   324,    -1,    -1,    -1,    -1,
      -1,    -1,   331,   332,    -1,    -1,   360,    -1,    -1,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,    -1,
     206,   551,   351,    -1,    -1,    -1,   355,   356,   357,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   395,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,    -1,    -1,   337,    -1,    -1,    -1,    -1,    -1,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   551,
      -1,    -1,    -1,    -1,    -1,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   469,   470,   551,    -1,   473,
     474,   475,   476,   477,   478,   479,   480,    -1,    -1,    -1,
      -1,    -1,     3,     4,   488,     6,    -1,     8,     9,   493,
     494,    -1,    13,    -1,    -1,    16,   500,    18,   325,   326,
     327,   328,   329,   330,   331,   332,   333,   334,    29,    -1,
     337,    59,    -1,    -1,    35,    36,    -1,    -1,   522,   523,
      -1,    -1,    43,    44,    45,    -1,    -1,    -1,    49,    50,
      51,    59,    -1,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,    -1,   548,   337,    67,    -1,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   550,    93,    94,    95,    -1,    -1,    -1,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,    -1,    -1,    -1,
     121,   122,   123,    -1,   125,   126,   127,   128,    -1,    -1,
      -1,    -1,    -1,   134,   135,    -1,    -1,   138,   551,   140,
     141,   142,    -1,   144,   145,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   155,   156,   157,   158,   159,   160,
     161,   162,   163,    -1,    -1,   166,   167,   168,   169,   170,
     171,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   206,   180,
     181,   182,   183,   184,   185,   186,    -1,   188,   189,    -1,
      -1,   192,   193,    -1,    -1,    -1,   197,    -1,   206,   200,
     201,    -1,    -1,    -1,   205,    76,    -1,    -1,   209,   210,
     211,    -1,   213,    -1,    -1,   216,    -1,    -1,    -1,    -1,
      -1,   222,   206,   224,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    -1,   235,    -1,    -1,    -1,   109,   240,
     241,   242,   549,    -1,   245,    -1,   117,    -1,   249,    -1,
      -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,   259,    -1,
     261,   262,    -1,    -1,   265,   109,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   117,    -1,    -1,    -1,   549,    -1,   280,
      -1,   152,    -1,    -1,   285,    -1,    -1,   109,    -1,    -1,
     291,   292,    -1,   164,   295,   117,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   176,   177,   308,   152,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   318,   319,    -1,
     164,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     152,    -1,   176,   177,    -1,   206,   207,    -1,    -1,    -1,
     324,    -1,   164,    -1,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   176,   177,   337,    -1,    -1,    -1,
      -1,    -1,   206,   207,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,    -1,    -1,   337,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   206,   207,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,    -1,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,    -1,    -1,    -1,    -1,   430,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,    -1,
      -1,    -1,    -1,   324,    -1,    -1,   457,   458,    -1,    -1,
     331,   332,    -1,   464,    -1,    -1,    -1,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,    -1,    -1,    -1,
     351,    -1,    -1,    -1,   355,   356,   357,   331,   332,    -1,
      -1,    -1,    -1,    -1,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   505,   506,    -1,   351,    -1,   331,
     332,   355,   356,   357,    -1,    -1,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   117,    -1,    -1,   351,
      -1,    -1,    -1,   355,   356,   357,   206,    -1,    -1,    -1,
      -1,    -1,    -1,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,    -1,   206,    -1,    -1,    -1,    -1,   549,   553,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,    76,
     551,    -1,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,    76,    -1,    -1,    -1,   206,    -1,    -1,    -1,    -1,
      -1,    -1,   109,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     117,    -1,    -1,    76,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   109,    -1,   337,    -1,    -1,    -1,
      -1,   495,   117,    -1,   324,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   152,   257,    -1,    -1,    -1,
      -1,    -1,    -1,   495,   117,    -1,    -1,   164,    -1,   550,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   152,    -1,   176,
     177,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   164,
      -1,    -1,    -1,    -1,    -1,    -1,   550,    -1,    -1,   152,
      -1,   176,   177,    -1,    -1,    -1,    -1,    -1,    -1,   206,
     207,   164,    -1,    -1,    -1,    -1,    -1,    -1,   550,    -1,
      -1,    -1,    -1,   176,   177,    -1,    -1,    -1,    -1,    -1,
      -1,   206,   207,    -1,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   206,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   206,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,    -1,    -1,   337,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,    -1,    -1,   331,   332,    -1,    -1,    -1,    -1,
      -1,   338,   339,   340,   341,   342,   343,   344,   345,   346,
     347,    -1,    -1,    -1,   351,    -1,   331,   332,   355,   356,
     357,    -1,    -1,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   553,    -1,    -1,   351,    -1,   331,   332,
     355,   356,   357,    -1,    -1,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,    -1,    -1,    -1,   351,   552,
      -1,    -1,   355,   356,   357,   358,   359,    -1,    -1,    -1,
     324,    -1,    -1,    -1,    -1,    -1,    -1,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,    -1,    -1,    -1,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,    76,    -1,
      -1,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
      -1,   109,   337,    -1,    -1,    -1,    -1,    -1,   495,   117,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   551,
     495,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,    -1,    -1,   337,   152,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,    -1,   164,   337,    -1,    -1,
      -1,    -1,    -1,   550,    -1,    -1,    -1,    -1,   176,   177,
      -1,   206,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,    -1,    -1,   337,   550,    -1,   324,   325,   326,
     327,   328,   329,   330,   331,   332,   333,   334,   206,   207,
     337,    -1,    -1,    -1,    -1,    -1,    -1,   550,    -1,    -1,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
      -1,    -1,   337,    -1,    -1,    -1,     3,    -1,    -1,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    13,    -1,    -1,    -1,
      17,    18,    -1,    -1,    -1,    -1,    -1,   551,   325,   326,
     327,   328,   329,   330,   331,   332,   333,   334,    -1,    -1,
     337,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    51,    52,    53,    -1,   325,   326,
     327,   328,   329,   330,   331,   332,   333,   334,    -1,   324,
     337,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,    -1,    80,   337,    82,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   549,    -1,    93,    94,    95,    -1,
      -1,    -1,    -1,   331,   332,    -1,    -1,   104,   105,    -1,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
      -1,    -1,    -1,   351,   121,   122,   123,   355,   356,   357,
      -1,    -1,    -1,    -1,   131,    -1,    -1,   551,    -1,   136,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
      -1,   551,   337,    -1,    -1,    -1,   153,    -1,    -1,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   551,    -1,
      -1,    -1,    -1,    -1,   181,    -1,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   206,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   211,   212,   551,   214,    -1,   216,
     217,   218,    -1,    -1,    -1,   222,    -1,   224,     3,    -1,
      -1,     6,    -1,    -1,    -1,    -1,    -1,    -1,   235,   236,
      -1,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     247,    -1,    -1,    -1,   551,    -1,    -1,    -1,    -1,   256,
      -1,   258,   259,    -1,    -1,    -1,    -1,    -1,   265,   266,
     267,    -1,    -1,    -1,    49,    50,    51,    52,    53,   276,
     277,   278,    -1,    -1,   551,    -1,    -1,    -1,   285,    -1,
      -1,    -1,    -1,    -1,   291,   292,   551,    -1,   295,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    93,    94,
      95,    -1,   550,   324,    -1,    -1,    -1,    -1,    -1,   104,
     105,    -1,   107,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,    -1,    -1,   337,   121,   122,   123,    -1,
      -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,     6,    -1,
      -1,   136,    -1,    -1,    -1,   140,   551,    -1,    -1,    17,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
      -1,    -1,   337,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,    -1,    -1,   337,    -1,    -1,    -1,    -1,
      -1,    49,    50,    51,    52,    53,   181,    -1,    -1,    -1,
      -1,    -1,    -1,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,    -1,   430,    82,    83,   211,   212,    -1,   214,
      -1,   216,   217,   218,    -1,    93,    94,    95,    -1,   224,
      -1,    -1,    -1,   206,    -1,    -1,   104,   105,    -1,    -1,
     235,   236,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   247,   121,   122,   123,    -1,    -1,    -1,    -1,
      -1,   256,     3,   258,   259,     6,    -1,    -1,   136,    -1,
     265,   266,   267,    -1,    -1,    -1,    17,    -1,    -1,    -1,
      -1,   276,   277,   278,    -1,   153,    -1,    -1,    -1,    -1,
     285,    -1,    -1,    -1,    -1,    -1,   291,   292,    -1,    -1,
     295,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,
      51,    52,    53,   181,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,    -1,    -1,   337,   322,    -1,    -1,
     551,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   551,
      -1,    82,    83,   211,   212,    -1,   214,    -1,   216,   217,
     218,   324,    93,    94,    95,    -1,   224,    -1,    -1,    -1,
      -1,    -1,    -1,   104,   105,    -1,    -1,   235,   236,    -1,
      -1,   206,    -1,    -1,    -1,    -1,   551,    -1,    -1,   247,
     121,   122,   123,    -1,    -1,    -1,    -1,    -1,   256,   551,
     258,   259,   206,    -1,    -1,   136,    -1,   265,   266,   267,
      -1,    -1,    -1,    -1,    -1,    -1,   401,    -1,   276,   277,
     278,   206,    -1,    -1,    -1,    -1,    -1,   285,    -1,    -1,
      -1,    -1,    -1,   291,   292,    -1,    -1,   295,    -1,    -1,
     206,   299,    -1,   301,    -1,   430,    -1,    -1,    -1,    -1,
     181,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     206,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     211,   212,    -1,   214,    -1,   216,   217,   218,    -1,    -1,
      -1,    -1,   206,   224,    -1,    -1,    -1,    -1,    -1,   324,
      -1,    -1,    -1,    -1,   235,   236,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,   247,    -1,   337,   206,
     324,    -1,    -1,    -1,    -1,   256,    -1,   258,   259,    -1,
      -1,    -1,    -1,    -1,   265,   266,   267,    -1,    -1,   324,
      -1,    -1,    -1,    -1,    -1,   276,   277,   278,    -1,    -1,
     551,    -1,    -1,    -1,   285,    -1,    -1,    -1,   324,    -1,
     291,   292,    -1,    -1,   295,    -1,    -1,    -1,   299,    -1,
      -1,    -1,   430,    -1,    -1,    -1,    -1,    -1,   206,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   551,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   206,    -1,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,    -1,   206,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,    -1,    -1,   430,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   257,
     206,    -1,    -1,    -1,    -1,    -1,   551,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   206,   551,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,    -1,
      -1,   337,    -1,    -1,    -1,   206,   551,   324,   325,   326,
     327,   328,   329,   330,   331,   332,   333,   334,    -1,    -1,
     337,    -1,    -1,    -1,   206,   551,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   206,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   551,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   549,   550,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   334,    -1,    -1,   337,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   206,    -1,    -1,
      -1,    -1,   549,   550,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,    -1,    -1,   337,   325,   326,
     327,   328,   329,   330,   331,   332,   333,   334,    -1,    -1,
     337,   549,   550,    -1,    -1,    -1,    -1,    -1,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   206,    -1,    -1,
      -1,   549,   550,    -1,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   206,   550,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,    -1,   206,    -1,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,    -1,    -1,   337,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   206,    -1,    -1,    -1,
      -1,   549,    -1,   549,   550,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   257,   206,    -1,    -1,    -1,   549,
     550,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,    -1,    -1,   337,    -1,    -1,    -1,   257,   549,   550,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     206,   551,    -1,    -1,    -1,    -1,    -1,   549,   550,    -1,
      -1,    -1,    -1,    -1,   551,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,    -1,    -1,   337,   549,   550,
      -1,   324,    -1,    -1,    -1,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   324,    -1,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,    -1,    -1,   337,    -1,
      -1,    -1,    -1,    -1,   206,    -1,    -1,    -1,    -1,    -1,
     549,   550,    -1,   324,    -1,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,    -1,    -1,   337,    -1,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   324,    -1,
      -1,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     206,   551,    -1,    -1,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   206,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   550,    -1,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   324,    -1,    -1,    -1,    -1,   551,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   206,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   550,    -1,    -1,    -1,    -1,
      -1,   551,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   206,
      -1,    -1,    -1,    -1,    -1,    -1,   549,    -1,   324,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
      -1,    -1,   337,    -1,    -1,    -1,   206,    -1,    -1,   549,
     549,   324,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   206,    -1,    -1,    -1,    -1,    -1,    -1,   549,    -1,
      -1,   551,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,    -1,    -1,   337,   324,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,   206,    -1,   337,    -1,
      -1,    -1,    -1,   549,    -1,   324,    -1,    -1,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   324,    -1,    -1,
      -1,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     206,    -1,    -1,    -1,   324,   324,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,    -1,    -1,   337,    -1,
      -1,    -1,   206,    -1,    -1,    -1,    -1,   549,    -1,   324,
      -1,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,    -1,    -1,   337,    -1,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   324,    -1,    -1,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   206,    -1,    -1,    -1,
      -1,    -1,    -1,   549,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,    -1,    -1,    -1,   549,    -1,   324,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   206,    -1,
     324,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   551,    -1,
      -1,    -1,    -1,    -1,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   206,    -1,    -1,    -1,    -1,    -1,    -1,
     549,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,    -1,    -1,   337,   206,    -1,    -1,    -1,    -1,
      -1,    -1,   549,    -1,   324,    -1,    -1,    -1,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   206,    -1,   549,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   206,
      -1,    -1,    -1,    -1,   549,    -1,   324,   551,   325,   326,
     327,   328,   329,   330,   331,   332,   333,   334,    -1,    -1,
     337,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   206,    -1,   337,    -1,    -1,    -1,    -1,   549,
      -1,   324,    -1,    -1,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   324,    -1,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,    -1,    -1,   337,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   206,    -1,    -1,    -1,
      -1,    -1,    -1,   549,    -1,   324,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   549,    -1,   324,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     324,    -1,    -1,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   206,    -1,    -1,    -1,    -1,    -1,    -1,   549,
      -1,    -1,    -1,    -1,    -1,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   324,    -1,    -1,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   206,    -1,    -1,    -1,
      -1,   549,    -1,    -1,   551,    -1,    -1,    -1,    -1,    -1,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   206,
      -1,    -1,    -1,    -1,    -1,    -1,   549,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   206,    -1,    -1,    -1,    -1,    -1,    -1,   549,    -1,
     324,   551,    -1,    -1,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   206,    -1,    -1,    -1,    -1,    -1,    -1,
     549,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   206,    -1,    -1,    -1,    -1,
      -1,    -1,   549,    -1,   324,    -1,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,    -1,    -1,   337,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   206,    -1,
      -1,    -1,    -1,    -1,    -1,   549,    -1,   324,    -1,    -1,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   324,
      -1,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,    -1,    -1,   337,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   206,    -1,    -1,    -1,    -1,    -1,    -1,   549,
      -1,   324,    -1,    -1,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   324,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   324,    -1,    -1,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   206,    -1,
      -1,    -1,    -1,    -1,    -1,   549,    -1,    -1,    -1,    -1,
      -1,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     324,    -1,    -1,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   206,    -1,    -1,    -1,    -1,    -1,    -1,   549,
      -1,    -1,   551,    -1,    -1,    -1,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   206,    -1,    -1,    -1,    -1,
      -1,    -1,   549,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   206,    -1,    -1,
      -1,    -1,    -1,    -1,   549,    -1,   324,   551,    -1,    -1,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   206,
      -1,    -1,    -1,    -1,    -1,    -1,   549,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   206,    -1,    -1,    -1,    -1,    -1,    -1,   549,    -1,
     324,    -1,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,    -1,    -1,   337,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   206,    -1,    -1,    -1,    -1,    -1,
      -1,   549,    -1,   324,    -1,    -1,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   324,    -1,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   334,    -1,    -1,   337,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   206,    -1,
      -1,    -1,    -1,    -1,    -1,   549,    -1,   324,    -1,    -1,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   324,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   324,    -1,    -1,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   206,    -1,    -1,    -1,    -1,    -1,
      -1,   549,    -1,    -1,    -1,    -1,    -1,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   324,    -1,    -1,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   206,    -1,
      -1,    -1,    -1,    -1,    -1,   549,    -1,    -1,   551,    -1,
      -1,    -1,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   206,    -1,    -1,    -1,    -1,    -1,    -1,   549,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     206,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     549,   549,   324,    -1,    -1,    -1,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   206,    -1,    -1,    -1,    -1,
      -1,    -1,   549,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   206,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   549,    -1,   324,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   206,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   549,    -1,   324,
      -1,    -1,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   206,    -1,    -1,    -1,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
      -1,   549,   337,    -1,    -1,    -1,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,    -1,    -1,   337,    -1,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   206,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   549,    -1,    -1,
      -1,    -1,    -1,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   206,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   549,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   206,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   549,    -1,    -1,    -1,    -1,    -1,
     206,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   549,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   206,   549,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   549,    -1,
      -1,    -1,   206,    -1,    -1,    -1,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,    -1,   549,   337,   549,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   206,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   549,    -1,   117,
      -1,    -1,    -1,    -1,    -1,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   206,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   549,
     129,   130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   257,   206,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   206,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,   130,    -1,
     549,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     414,   415,   416,   417,   418,   419,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   206,
     549,    -1,    -1,    -1,    -1,    -1,   129,   130,    -1,    -1,
      -1,    -1,    -1,    -1,   549,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   206,   130,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   549,    -1,    -1,    -1,    -1,    -1,
     257,    -1,    -1,   206,    -1,    -1,    -1,    -1,    -1,   130,
      -1,    -1,    -1,   549,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   206,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   549,    -1,   130,    -1,
      -1,    -1,    -1,    -1,   257,    -1,    -1,    -1,    -1,    -1,
      -1,   206,    -1,    -1,    -1,   549,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   206,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     549,    -1,    -1,    -1,   206,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   206,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   206,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   206,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     206,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     206,   324,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   206,    -1,
      -1,    -1,    -1,   414,   415,   416,   417,   418,   419,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,    -1,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   414,   415,   416,   417,   418,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   324,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   414,   415,   416,
     417,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,    -1,    -1,   337,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,    -1,
      -1,   337,    -1,    -1,    -1,    -1,    -1,    -1,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   414,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   414,   415,   416,   417,
     418,   419,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,    -1,    -1,   337,   325,   326,
     327,   328,   329,   330,   331,   332,   333,   334,    -1,    -1,
     337,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,    -1,    -1,   337,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,    -1,    -1,   337,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   334,    -1,    -1,   337,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
      -1,    -1,   337,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,    -1,    -1,   337,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,    -1,    -1,   337,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,    -1,
     549,   337,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,    -1,   549,   337,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,    -1,    -1,   337,   325,   326,
     327,   328,   329,   330,   331,   332,   333,   334,    -1,    -1,
     337,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,    -1,    -1,   337,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,    -1,    -1,   337,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   334,    -1,    -1,   337,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
      -1,    -1,   337,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,    -1,    -1,   337,    -1,    -1,    -1,   549,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   549,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   549,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   549,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   549,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   549,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   549,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     549,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   549,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   549,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   549,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   549,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   549,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   549,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   549,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   549,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   549
  };

  const unsigned short int
  parser::yystos_[] =
  {
       0,    14,    15,    30,    31,    32,    33,    34,    38,    54,
      55,    56,    60,    62,    63,    64,    65,    66,    74,    75,
      81,    97,    98,    99,   100,   108,   110,   111,   124,   139,
     148,   172,   173,   174,   175,   178,   187,   206,   221,   223,
     225,   226,   233,   236,   238,   239,   243,   244,   268,   269,
     271,   272,   273,   275,   276,   281,   284,   288,   289,   296,
     297,   298,   300,   304,   310,   311,   312,   313,   314,   315,
     316,   317,   360,   395,   414,   415,   416,   417,   418,   419,
     420,   421,   422,   423,   424,   425,   426,   427,   428,   429,
     430,   431,   432,   469,   470,   473,   474,   475,   476,   477,
     478,   479,   480,   488,   493,   494,   500,   522,   523,   548,
     558,   559,   560,   561,   562,   565,   568,   572,   573,   574,
     575,   584,   587,   588,   593,   594,   595,   598,   601,   604,
     615,   619,   630,   631,   634,   637,   640,   644,   647,   650,
     653,   656,   659,   660,   663,   666,   669,   680,   686,   689,
     692,   699,   700,   703,   704,   705,   707,   719,   720,   721,
     724,   725,   726,   735,   738,   741,   742,   744,   747,   748,
     749,   750,   751,   752,   755,   759,   762,   763,   764,   767,
     774,   775,   776,   777,   781,   784,   787,   790,   793,   796,
     799,   802,   805,   808,   809,   814,   817,   820,   823,   824,
     827,   831,   834,   837,   839,   842,   845,   848,  1203,   117,
     550,   117,   550,   549,   550,   673,  1203,   550,   549,   550,
     550,   549,   550,   117,   550,   550,   549,   550,   549,   550,
     673,   549,   549,   549,   550,   549,   550,   550,   549,   549,
     550,   673,   550,   549,   550,   550,   549,   549,   550,   549,
     550,   550,   549,   550,   550,   550,   549,   550,   257,   550,
     756,   758,  1203,   549,   550,   549,   550,   549,   549,   549,
     549,   549,   550,   673,   673,   582,  1203,    61,   117,   760,
     550,   673,   549,   550,   549,   550,   673,   550,   549,   550,
     549,   550,   673,   549,   550,    61,   549,   550,   549,   550,
     549,   549,   550,   549,   550,   673,   549,   550,   673,   549,
     550,   673,   549,   549,   550,   673,   673,   550,   579,  1203,
     580,  1203,   581,  1203,   736,   583,  1203,   549,   549,   549,
     549,   550,   550,   549,   550,   550,   549,   550,   673,   549,
     550,   549,   550,   549,   550,   549,   550,   549,   550,   549,
     550,   620,   550,   550,   549,   550,   550,   550,   556,     0,
     559,    61,   550,    61,    61,    61,   556,   549,    19,    20,
      21,    22,    23,    24,    25,    36,    45,    72,   209,   210,
     241,   242,   318,   319,   778,   779,   780,   895,   898,   902,
     920,   921,   972,   973,   977,   978,   995,   996,   997,   998,
     999,  1000,  1001,   549,    26,    35,    81,   779,   782,   783,
     930,   959,  1002,    70,    71,   140,   458,   832,   833,   895,
     902,   920,   951,   963,   974,  1124,   324,   549,  1203,   233,
     310,   311,   312,   585,    96,   101,   102,   103,   131,   150,
     153,   259,   285,   646,   648,   649,   853,   874,   882,   885,
     892,  1050,  1051,  1052,  1053,    37,   234,   236,   266,   821,
     822,   859,   870,   930,  1054,  1055,   310,   825,   826,  1203,
     117,   549,   756,   756,   596,   597,  1203,    28,     3,     4,
       6,     8,     9,    13,    16,    18,    29,    43,    44,    49,
      50,    51,    67,    69,    72,    93,    94,    95,   121,   122,
     123,   125,   126,   127,   128,   134,   135,   138,   141,   142,
     144,   145,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   166,   167,   168,   169,   170,   171,   180,   181,   182,
     183,   184,   185,   186,   188,   189,   192,   193,   197,   200,
     201,   205,   211,   213,   216,   222,   224,   235,   240,   245,
     249,   261,   262,   265,   280,   291,   292,   295,   308,   430,
     457,   464,   505,   506,   727,   728,   853,   858,   861,   865,
     866,   892,   895,   896,   897,   898,   899,   900,   901,   920,
     921,   922,   923,   924,   925,   926,   930,   931,   932,   933,
     934,   935,   936,   937,   938,   939,   940,   941,   942,   943,
     944,   945,   946,   947,   948,   949,   950,   951,   953,   954,
     955,   956,   957,   958,   959,   960,   961,   962,   963,   964,
     965,   966,   967,   968,   972,   973,   974,   975,   976,   977,
     978,   979,   980,   981,   982,   983,   984,   986,   987,   988,
     989,   990,   991,   992,   993,   994,  1003,  1004,  1005,  1006,
    1007,  1008,  1009,  1010,  1056,  1117,  1123,  1124,  1125,  1126,
    1169,  1171,  1172,  1173,  1174,  1176,  1177,   549,    38,   263,
     287,   681,   682,   683,  1203,    38,   287,   690,   691,  1203,
      38,   287,   687,   688,  1203,    12,   106,   224,   286,   320,
     321,   835,   836,   870,   871,   872,   873,  1184,  1185,    77,
     697,   698,   693,   694,  1203,   818,   819,   870,   924,   925,
     926,   930,   549,  1203,   599,   600,  1203,    28,    68,   815,
     816,  1203,     5,   137,   227,   228,   248,   306,   307,   365,
     753,   754,   859,   861,   870,   923,   924,   925,   926,   947,
     966,   980,  1016,  1041,  1045,  1046,  1047,  1048,  1049,  1055,
    1169,  1170,   596,    28,    68,   843,   844,  1203,   964,   756,
     149,   605,    11,    27,    40,    58,   136,   154,   208,   232,
     305,   602,   603,   857,   884,   887,   151,   969,   550,   324,
     549,   756,   651,   652,   310,   618,   638,   231,   840,   841,
    1203,   739,   740,  1203,   743,  1203,    17,    52,    53,    80,
      82,   104,   105,   131,   153,   212,   214,   217,   218,   247,
     256,   258,   267,   276,   277,   278,   671,   745,   746,   852,
     853,   854,   857,   858,   859,   860,   861,   862,   863,   864,
     865,   866,   867,   868,   870,   878,   879,   883,   888,   889,
     890,   891,   892,   897,   899,   924,   925,   926,   936,   958,
     962,   964,   970,   971,   982,   983,   986,   987,   991,   992,
     993,   994,  1106,  1107,  1117,  1174,  1175,   549,   549,   324,
     549,  1203,   302,   550,   577,   578,   117,   549,    76,   117,
     152,   164,   176,   177,   331,   332,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   351,   355,   356,   357,
     358,   359,   550,   611,   676,  1203,   236,   549,   654,   655,
     870,   895,   131,   132,   143,   153,   165,   215,   279,   283,
     657,   658,   853,   855,   856,   875,   880,   881,   885,   886,
     952,  1178,  1184,  1185,   549,   756,    38,   310,   616,   617,
     618,   231,   274,   323,   812,   813,   895,  1055,  1188,  1189,
     549,   849,   850,  1203,   206,   552,   655,   658,   664,   665,
     115,   116,   229,   230,   237,   846,   847,  1179,  1180,  1181,
    1182,  1183,   828,   645,   646,   107,   322,   401,   670,   671,
     672,   869,   876,   951,  1056,  1057,   549,    83,   299,   770,
     771,   985,  1118,   549,   671,   772,   773,   985,  1118,   549,
     206,   765,   766,   153,   301,   768,   769,   773,   877,  1168,
     549,   549,   147,   471,   324,   549,  1203,   302,   578,   324,
     549,  1203,   302,   578,   324,   549,  1203,   302,   578,   737,
    1203,   324,   549,  1203,   108,   361,   362,   363,   364,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   517,   518,   519,   810,   811,   861,   895,
     898,   902,   920,   921,   923,   924,   925,   926,   930,   931,
     941,   951,   966,  1011,  1012,  1013,  1014,  1015,  1016,  1017,
    1018,  1019,  1020,  1021,  1022,  1023,  1024,  1025,  1026,  1027,
    1028,  1029,  1030,  1031,  1032,  1033,  1034,  1035,  1036,  1037,
    1038,  1039,  1040,  1042,  1043,  1044,  1045,  1046,  1169,  1170,
      46,    47,    72,    73,   209,   701,   702,   893,   894,   903,
     904,   905,   972,   973,   390,   391,   392,   393,   394,   395,
     396,   399,   400,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   414,   415,   416,   417,   418,   419,   420,   437,
     438,   439,   440,   441,   444,   445,   446,   447,   448,   450,
     451,   452,   453,   454,   455,   456,   459,   460,   461,   532,
     785,   786,   895,   959,  1060,  1061,  1062,  1063,  1064,  1065,
    1066,  1067,  1068,  1069,  1070,  1071,  1072,  1073,  1074,  1075,
    1076,  1077,  1078,  1079,  1080,  1082,  1083,  1084,  1085,  1086,
    1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,
    1097,  1098,  1099,  1100,  1101,  1102,  1103,  1104,  1105,  1131,
     472,   270,   293,   294,   465,   468,   507,   508,   510,   511,
     513,   514,   515,   520,   531,   794,   795,  1127,  1128,  1130,
    1147,  1155,  1156,  1157,  1160,  1161,  1162,  1163,  1164,  1165,
    1166,   549,   509,   788,   789,  1127,  1128,  1130,  1147,  1155,
    1156,  1157,  1159,  1160,  1161,  1162,  1163,  1165,  1166,   412,
     512,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   806,   807,   895,   972,
     973,  1060,  1061,  1062,  1063,  1064,  1070,  1071,  1072,  1074,
    1078,  1079,  1080,  1081,  1127,  1128,  1129,  1131,  1132,  1133,
    1134,  1135,  1136,  1137,  1138,  1139,  1140,  1141,  1142,  1143,
    1144,  1145,  1146,    53,   161,   220,   530,   803,   804,  1058,
    1059,  1127,  1128,  1147,  1148,  1149,   525,   526,   527,   528,
     529,   800,   801,  1127,  1128,  1130,  1150,  1151,  1152,  1153,
    1154,   521,   797,   798,  1127,  1128,  1157,  1158,   516,   791,
     792,  1127,  1128,  1130,  1147,  1155,  1156,  1160,  1161,  1162,
    1163,  1164,  1165,  1166,  1167,   549,   233,   463,   489,   490,
     491,   492,   632,   633,  1108,  1109,  1110,  1111,  1112,  1113,
     496,   497,   499,   635,   636,  1108,  1114,  1115,  1116,   501,
     502,   503,   504,   667,   668,  1119,  1120,  1121,  1122,   246,
     524,   661,   662,  1186,  1187,   661,   432,    38,    97,   705,
    1203,   706,   929,  1203,    38,    97,   720,  1203,    38,    97,
     725,  1203,   109,   152,   164,   176,   177,   207,   331,   332,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     351,   355,   356,   357,   550,   589,   676,  1203,   129,   130,
     432,  1203,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,   324,   551,    61,    61,    61,
     324,   551,    61,   551,   324,  1203,   551,    61,    61,    61,
      61,    61,    61,    61,    61,   324,   551,    61,    61,    61,
      61,   324,   551,  1203,    59,   826,   324,   549,   551,   551,
      59,   597,    61,   551,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,   324,   551,  1203,  1203,    59,   682,   324,
     549,  1203,  1203,    59,   691,   324,  1203,  1203,    59,   688,
     324,   551,    61,    61,   551,   324,   331,   551,    59,   694,
     324,   324,   551,   551,    59,   600,   550,   551,    61,    59,
     816,   324,    61,    61,    61,    61,    61,    61,    61,    61,
     551,   324,    59,   551,    61,    59,   844,   324,   550,   551,
     551,    61,   552,   554,   607,   608,   611,   614,    61,    61,
      61,    61,   324,   551,    61,   551,   676,   756,   550,   324,
     551,  1203,    59,   618,   551,    59,   841,   324,    59,   740,
     550,    59,  1203,   324,   589,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,   324,   551,  1203,
     302,   578,   578,   324,   576,  1203,   324,   551,   576,   549,
     550,   550,   550,   550,   611,   611,   550,   550,   550,   550,
     550,   550,   550,   550,   550,   550,   550,   550,   550,   550,
     550,   550,   611,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   337,   761,   612,    61,   324,   551,    61,
      61,    61,    61,    61,   324,   551,   551,  1203,  1203,    59,
     617,   551,    61,    61,   551,   324,    59,   850,    61,    61,
     331,   332,   550,   642,   643,   676,   677,   324,   551,    61,
      61,    61,    61,    61,   551,   324,   552,   829,   830,  1203,
     324,   551,    61,    61,   324,   551,    61,    61,   324,   551,
     324,   551,   327,   328,   329,   330,    59,   766,    61,    61,
     324,   551,    61,    61,  1203,   302,   578,   578,  1203,   302,
     578,   578,  1203,   302,   578,   578,   324,   549,  1203,  1203,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,   551,   324,    61,    61,    61,    61,    61,   324,
     551,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,   324,   551,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,   324,   551,
     324,   551,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,   324,   551,
      61,    61,    61,   324,   551,    61,    61,    61,    61,   324,
     551,   324,   551,    61,   324,   551,   402,   482,   484,   485,
     621,   622,    61,    61,    61,    61,    61,    61,   324,   551,
      61,   324,   551,    61,    61,    61,    61,   324,   551,    61,
      61,   324,   551,   551,   710,   550,   550,   549,   556,   324,
     551,    61,   550,   550,   549,   556,   550,   550,   549,   556,
     550,   550,   550,   550,   589,   589,   550,   550,   550,   550,
     550,   550,   550,   550,   550,   550,   550,   550,   550,   550,
     589,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   337,   549,   590,   550,   708,   556,   676,   677,   676,
     117,   677,   117,   756,   117,   117,   552,  1193,  1195,  1196,
     117,   117,  1203,  1190,  1203,   780,   117,   117,   676,   117,
     783,   117,  1196,   549,   673,   832,   586,  1203,   117,   117,
     117,   676,   676,   117,   676,   117,   649,   549,   550,    57,
     250,   251,   252,   253,   254,   255,   117,   117,   822,   549,
     549,   549,  1203,   549,   673,   549,   673,   549,   589,   549,
     117,   257,   676,  1203,   676,   676,   117,   756,  1193,  1196,
     427,   428,   429,   431,   550,   927,  1193,  1196,   117,   550,
     676,   117,   676,   676,   117,   117,    48,    78,    79,   282,
     676,   676,   676,   676,   676,   676,   117,   117,   117,   117,
     109,   331,   332,   677,   678,   679,   117,   117,   117,  1203,
     756,   117,  1196,   552,  1197,  1198,   433,   434,   435,   756,
     117,   190,   191,   431,   676,   194,   195,   196,   198,   199,
    1203,   202,   203,   204,   202,   203,   204,   550,   117,   117,
     676,   109,   676,   117,    78,    79,   676,   117,    41,    42,
      78,   550,   117,   728,   549,   673,   324,   549,    10,    92,
     118,   119,   120,   219,   303,   443,   589,   592,   684,   696,
     324,   324,   549,   589,   324,   324,   549,   589,   549,   117,
     117,   549,   835,   117,   549,   549,   589,   819,   549,   673,
     556,   549,   117,   331,   332,   675,   549,   756,   549,   589,
     677,   117,   117,   675,   117,   117,   117,   756,   117,   549,
     753,   549,   549,   756,   549,  1203,   117,  1191,   549,   549,
     566,   206,   609,   610,  1203,    59,   608,   614,    61,   549,
     676,   550,   117,   550,   602,   549,   133,   179,   758,   551,
     550,   676,   652,   549,   549,   549,   549,   549,  1203,   549,
     589,   549,   324,   589,  1203,   549,   676,   117,   117,   117,
     756,   676,   117,   676,   117,   676,   117,   117,   117,   746,
     549,   673,   302,   578,   578,   576,    61,   551,   576,   611,
     611,   611,   611,   611,   611,   611,   611,   611,   611,   611,
     611,   611,   611,   611,   611,   611,   611,   611,   675,   551,
     611,   611,   611,   611,   611,   611,   611,   611,   611,   611,
     611,   549,   550,   117,   655,   549,   676,   676,   117,   676,
     117,   658,   549,   549,   324,    61,   324,   549,   549,   549,
    1203,  1203,   549,   673,   812,   549,   851,  1203,  1203,   676,
     676,   589,   549,   553,   324,   550,   677,   665,   549,   756,
     550,   756,   550,   117,   549,   846,   673,    59,   830,    61,
     646,   549,   676,  1196,   672,   549,   673,   550,   589,   771,
     549,   673,   773,   549,   673,   589,   589,   589,   589,   549,
     117,   676,   769,   549,   673,   570,   569,   302,   578,   578,
     302,   578,   578,   302,   578,   578,  1203,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     676,   676,   117,   552,  1201,  1202,   676,   676,   550,   550,
     550,   117,   117,   550,   676,   117,   676,   676,   676,   676,
     676,   549,   810,   756,  1203,   698,   698,   117,   702,   549,
     117,   486,   487,   117,   117,   117,   117,   756,   117,   550,
     117,   206,   484,   485,   117,   117,   117,   117,   117,   676,
     676,   117,   117,   117,   117,   117,   117,   676,   117,   117,
     117,   117,   117,   117,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,  1198,   786,   549,   563,
     117,   756,   117,   756,   756,  1198,   117,   117,  1198,   677,
     117,   795,   549,   673,   789,   549,   413,   431,   676,   676,
     676,   117,   676,   117,   117,   676,   676,   117,   117,   117,
     117,   676,   676,   807,   549,   117,   117,   117,   804,   549,
     117,   677,   677,   117,   801,   549,   798,   549,   117,   792,
     549,   481,   483,   498,   549,   549,    59,   622,   552,   552,
    1198,  1200,   117,   676,  1202,   117,   117,   633,   549,  1193,
    1196,   636,   549,   756,   117,   756,   756,   668,   549,   756,
     117,   662,   549,   549,   550,  1203,  1203,   929,   549,   698,
    1203,  1203,   432,  1203,  1203,  1203,   130,  1203,   589,   589,
     589,   589,   589,   589,   589,   589,   589,   589,   589,   589,
     589,   589,   589,   589,   589,   589,   551,   589,   589,   589,
     589,   589,   589,   589,   589,   589,   589,   589,   550,   112,
     113,   114,   722,   723,   913,   914,   915,   550,   130,   432,
     117,   324,  1193,  1194,   324,   553,  1194,   555,   549,   549,
     549,   324,   549,  1203,   673,   236,   551,   549,   549,   549,
     596,   927,   928,   673,   109,   109,   324,   677,   324,   553,
     677,   257,   729,   730,   257,   733,   734,   549,  1203,   324,
     549,   324,  1203,   589,   324,  1203,   589,   549,    59,   687,
     324,   549,   129,   130,   432,  1203,   117,   117,   551,   599,
     551,   324,   549,   596,   551,   324,   551,   555,   551,   843,
     611,    61,   324,   553,    61,   549,   611,   673,   756,   757,
     606,   549,   676,   551,   236,   638,   324,   550,   551,  1203,
     549,   589,   549,   578,   257,   324,   324,   551,   551,   551,
     551,   551,   551,   551,   551,   551,   551,   551,   551,   551,
     551,   324,   551,   324,   551,   551,   551,   611,   613,   551,
    1203,   589,  1203,   287,   616,   549,   324,   549,  1203,   551,
     551,   643,   549,   550,   677,   589,   673,   673,   553,   549,
     589,   549,   673,   549,   549,   549,   549,   549,   549,   549,
     611,   611,   578,   578,   578,   679,   553,   679,   555,   673,
     674,   674,   674,   674,   673,   611,   549,   117,   117,   549,
     549,   673,  1198,  1199,    84,    85,    86,    87,    88,    89,
      90,    91,   264,   717,   718,   906,   907,   908,   910,   911,
     912,   916,   917,   919,  1164,   324,   551,   555,   324,   551,
     556,   324,   551,   556,   324,   324,   551,   551,   551,   551,
     551,   551,   551,   551,   551,   551,   551,   551,   551,   551,
     324,   551,   324,   551,   589,   591,    61,    61,    61,   324,
     551,    85,    87,   715,   716,   906,   907,   908,   909,   911,
     912,   916,   917,   918,  1164,   550,   709,   555,  1194,   553,
    1194,  1203,  1203,   551,   117,   639,   556,    59,   324,   551,
     551,   677,   553,   677,   324,   324,   551,   324,   324,   551,
     589,   592,   696,   592,   685,   324,   324,   589,   324,   549,
     549,    59,   589,   550,   711,   556,    61,    59,   549,   589,
      59,   549,   331,   332,   552,   838,   324,   117,   324,    59,
     551,   257,   610,   611,   611,   549,   551,   324,   551,   607,
     551,   639,    59,   838,   332,   675,  1192,   549,   589,   549,
     611,   611,   611,   611,   550,   324,   551,   673,    61,   549,
      61,   589,    59,  1203,   549,   589,   551,   551,   551,    61,
     549,   551,   551,   551,   551,   551,   551,   551,   551,   551,
     324,   549,   553,   324,   553,    61,    61,    61,    61,    61,
      61,    61,    61,    61,   324,   551,  1203,   556,   698,  1203,
     556,   432,  1203,   556,   130,   589,   589,   589,   589,   324,
     551,  1202,   676,   677,   723,   549,    61,    61,   324,   551,
     722,   550,   117,   555,   117,   324,   549,   129,   130,   432,
    1203,   549,   927,   257,   677,   729,   257,   550,   677,   733,
     324,   324,   324,   589,   589,   549,   589,   549,   549,   722,
     550,   130,   432,   589,   549,   549,   549,   679,   549,  1203,
    1203,   549,   567,  1203,    61,   549,   549,   756,    59,   549,
     549,   549,   550,   551,   555,   551,   549,   551,   551,   324,
     324,   611,   611,   549,   589,   589,   549,   549,   849,   551,
     589,   571,  1203,   571,   564,  1203,   623,   481,   625,  1198,
     677,  1198,   676,  1200,   677,  1198,   415,   421,   422,   423,
     424,   425,   426,   436,   442,   695,  1198,  1198,   718,   549,
     551,   551,   432,  1203,   551,   130,  1203,   551,   551,   324,
     324,   589,   677,   589,   716,   549,   551,   715,   117,   555,
     117,   309,   550,   713,   556,   257,   731,   732,   592,   685,
     592,   324,   549,   549,   551,   715,   550,   712,   549,   324,
     679,   324,   324,   324,   549,  1203,   302,   611,   549,   309,
     675,   324,   675,   324,   611,   611,   551,   549,   549,    59,
     549,   324,   549,  1203,   302,   578,   549,   324,   549,  1203,
     302,   331,   332,   495,   589,   627,   628,   629,   117,   481,
     556,   556,   556,   556,   556,   589,   589,   549,   551,   117,
     555,   550,   641,   677,   722,   550,   130,   432,   324,   324,
     551,   324,   324,   589,   549,   551,   722,   550,   679,   553,
     838,   838,  1203,   302,   549,   641,   555,   838,   838,   551,
     551,   549,  1203,   302,   578,   578,  1203,   302,   495,   495,
     550,   333,    61,   589,   629,   324,   117,   432,  1203,   432,
     130,  1203,   130,   551,   551,   549,   117,   589,   324,   549,
     550,   677,   551,   715,   550,   714,   257,   677,   731,   696,
     592,   549,   549,   551,   715,   553,   549,   549,   302,   549,
     675,   549,   549,   302,   578,   578,   302,   550,   550,  1203,
     495,   624,   626,  1203,   324,   556,   556,   551,   550,   677,
     589,   549,   551,   722,   550,   324,   324,   549,   551,   551,
     578,  1203,  1203,   324,   550,   627,   324,   549,   626,   432,
     130,   589,   551,   549,   551,   715,   685,   592,   549,   324,
     324,   117,  1203,   549,  1203,   549,   551,   549,   551,   324,
     117,   117,   551,   324,   549,   589,   551,   551,   117,   551
  };

  const unsigned short int
  parser::yyr1_[] =
  {
       0,   557,   558,   558,   559,   559,   559,   559,   559,   559,
     559,   559,   559,   559,   559,   559,   559,   559,   559,   559,
     559,   559,   559,   559,   559,   559,   559,   559,   559,   559,
     559,   559,   559,   559,   559,   559,   559,   559,   559,   559,
     559,   559,   559,   559,   559,   559,   559,   559,   559,   559,
     559,   559,   559,   559,   559,   559,   559,   559,   559,   559,
     559,   559,   559,   559,   559,   559,   559,   559,   559,   559,
     559,   559,   559,   559,   559,   559,   559,   559,   559,   559,
     559,   559,   559,   559,   559,   559,   559,   559,   559,   559,
     559,   559,   559,   559,   559,   559,   559,   560,   560,   561,
     563,   562,   564,   564,   564,   564,   564,   564,   566,   565,
     567,   567,   567,   567,   567,   567,   568,   569,   568,   570,
     568,   571,   571,   571,   571,   571,   571,   571,   571,   571,
     571,   571,   571,   572,   573,   574,   575,   576,   577,   577,
     577,   577,   578,   578,   579,   579,   579,   579,   579,   579,
     579,   579,   579,   579,   579,   579,   580,   580,   580,   580,
     580,   580,   580,   580,   580,   580,   580,   580,   581,   581,
     581,   581,   581,   581,   581,   581,   581,   581,   581,   581,
     582,   582,   582,   582,   582,   582,   582,   582,   582,   582,
     582,   582,   583,   583,   583,   584,   585,   585,   585,   585,
     586,   586,   586,   587,   587,   588,   589,   589,   589,   589,
     589,   589,   589,   589,   589,   589,   589,   589,   589,   589,
     589,   589,   589,   589,   589,   589,   589,   589,   589,   589,
     589,   589,   589,   589,   589,   589,   589,   590,   589,   589,
     589,   589,   589,   589,   589,   589,   591,   591,   592,   592,
     593,   593,   594,   595,   595,   596,   596,   597,   598,   598,
     599,   599,   600,   601,   602,   602,   602,   602,   602,   602,
     602,   602,   602,   602,   603,   603,   605,   604,   606,   604,
     607,   607,   607,   607,   608,   608,   608,   608,   609,   609,
     610,   610,   611,   611,   611,   611,   611,   611,   611,   611,
     611,   611,   611,   611,   611,   611,   611,   611,   611,   611,
     611,   611,   611,   611,   611,   611,   611,   611,   611,   611,
     611,   611,   611,   611,   612,   611,   611,   611,   611,   611,
     611,   611,   613,   613,   614,   615,   615,   616,   616,   617,
     617,   617,   617,   617,   618,   620,   619,   621,   621,   622,
     622,   623,   624,   622,   622,   622,   625,   625,   626,   626,
     627,   627,   628,   628,   629,   629,   629,   629,   630,   631,
     632,   632,   633,   633,   633,   633,   633,   633,   634,   635,
     635,   636,   636,   636,   636,   637,   637,   638,   638,   639,
     639,   639,   639,   639,   639,   640,   641,   641,   641,   641,
     641,   641,   642,   642,   643,   643,   643,   643,   643,   643,
     644,   644,   645,   645,   646,   646,   646,   646,   646,   646,
     646,   646,   647,   647,   648,   648,   649,   649,   650,   650,
     651,   651,   652,   653,   653,   654,   654,   655,   655,   656,
     656,   657,   657,   658,   658,   658,   658,   658,   658,   658,
     658,   658,   658,   658,   658,   659,   660,   661,   661,   662,
     662,   663,   663,   664,   664,   665,   665,   666,   667,   667,
     668,   668,   668,   668,   669,   669,   669,   669,   670,   670,
     671,   671,   671,   671,   671,   671,   671,   671,   671,   671,
     671,   671,   671,   671,   671,   671,   671,   671,   671,   671,
     671,   671,   671,   671,   671,   671,   671,   671,   671,   671,
     671,   671,   671,   671,   671,   671,   671,   671,   671,   671,
     671,   671,   672,   672,   672,   672,   672,   672,   673,   673,
     673,   674,   674,   675,   675,   675,   676,   676,   677,   677,
     677,   678,   678,   678,   679,   679,   680,   681,   681,   682,
     682,   683,   683,   683,   683,   684,   684,   684,   684,   684,
     685,   685,   685,   685,   686,   686,   686,   687,   687,   688,
     688,   688,   689,   690,   690,   691,   691,   691,   692,   693,
     693,   694,   695,   695,   695,   695,   695,   695,   695,   695,
     695,   696,   696,   696,   696,   696,   696,   696,   696,   697,
     698,   698,   699,   700,   701,   701,   702,   702,   702,   702,
     702,   702,   702,   703,   704,   705,   705,   705,   706,   706,
     708,   707,   709,   707,   710,   707,   711,   707,   712,   707,
     713,   707,   714,   707,   715,   715,   716,   716,   716,   716,
     716,   716,   716,   716,   716,   716,   717,   717,   718,   718,
     718,   718,   718,   718,   718,   718,   718,   718,   719,   720,
     720,   720,   720,   720,   720,   721,   721,   721,   721,   721,
     721,   722,   722,   723,   723,   723,   724,   725,   725,   725,
     725,   725,   725,   726,   726,   726,   726,   727,   727,   728,
     728,   728,   728,   728,   728,   728,   728,   728,   728,   728,
     728,   728,   728,   728,   728,   728,   728,   728,   728,   728,
     728,   728,   728,   728,   728,   728,   728,   728,   728,   728,
     728,   728,   728,   728,   728,   728,   728,   728,   728,   728,
     728,   728,   728,   728,   728,   728,   728,   728,   728,   728,
     728,   728,   728,   728,   728,   728,   728,   728,   728,   728,
     728,   728,   728,   728,   728,   728,   728,   728,   728,   728,
     728,   728,   728,   728,   728,   728,   728,   728,   728,   728,
     728,   728,   728,   728,   728,   728,   728,   728,   728,   728,
     728,   728,   728,   728,   728,   728,   728,   728,   728,   728,
     729,   729,   730,   730,   731,   731,   732,   732,   733,   733,
     733,   734,   734,   736,   735,   737,   737,   737,   738,   739,
     739,   740,   741,   742,   743,   743,   743,   743,   744,   745,
     745,   746,   746,   746,   746,   746,   746,   746,   747,   747,
     747,   747,   748,   748,   749,   749,   750,   751,   752,   752,
     753,   753,   754,   754,   754,   754,   754,   754,   754,   754,
     754,   754,   754,   754,   754,   754,   754,   754,   754,   754,
     754,   754,   755,   755,   756,   756,   757,   757,   758,   758,
     758,   758,   758,   758,   760,   761,   759,   762,   762,   762,
     762,   763,   763,   763,   763,   764,   765,   765,   766,   766,
     766,   766,   767,   767,   767,   767,   768,   768,   769,   769,
     769,   770,   770,   771,   771,   772,   772,   773,   773,   773,
     774,   775,   776,   777,   777,   777,   777,   778,   778,   778,
     778,   778,   778,   778,   779,   779,   779,   779,   779,   779,
     779,   779,   779,   779,   780,   780,   781,   781,   782,   782,
     782,   782,   783,   783,   784,   784,   785,   785,   785,   785,
     785,   785,   785,   785,   785,   785,   785,   785,   785,   785,
     785,   785,   785,   785,   785,   785,   785,   785,   785,   785,
     785,   785,   785,   785,   785,   785,   785,   785,   785,   785,
     785,   785,   785,   785,   785,   785,   785,   785,   785,   785,
     785,   785,   785,   785,   786,   786,   787,   787,   788,   788,
     788,   788,   788,   788,   788,   788,   788,   788,   788,   788,
     788,   788,   789,   789,   790,   790,   791,   791,   791,   791,
     791,   791,   791,   791,   791,   791,   791,   791,   791,   791,
     792,   792,   793,   793,   794,   794,   794,   794,   794,   794,
     794,   794,   794,   794,   794,   794,   794,   794,   795,   795,
     796,   796,   796,   796,   797,   797,   797,   797,   798,   798,
     799,   799,   800,   800,   800,   800,   800,   800,   800,   800,
     801,   801,   802,   802,   803,   803,   803,   803,   803,   803,
     803,   804,   804,   805,   805,   806,   806,   806,   806,   806,
     806,   806,   806,   806,   806,   806,   806,   806,   806,   806,
     806,   806,   806,   806,   806,   806,   806,   806,   806,   806,
     806,   806,   806,   806,   806,   806,   806,   806,   806,   806,
     807,   807,   808,   808,   809,   809,   810,   810,   811,   811,
     811,   811,   811,   811,   811,   811,   811,   811,   811,   811,
     811,   811,   811,   811,   811,   811,   811,   811,   811,   811,
     811,   811,   811,   811,   811,   811,   811,   811,   811,   811,
     811,   811,   811,   811,   811,   811,   811,   811,   811,   811,
     811,   811,   811,   811,   811,   811,   811,   811,   811,   811,
     812,   812,   813,   813,   813,   813,   814,   815,   815,   816,
     816,   817,   817,   817,   817,   818,   818,   819,   819,   819,
     819,   819,   820,   821,   821,   822,   822,   822,   822,   822,
     823,   823,   824,   825,   825,   826,   828,   827,   829,   829,
     830,   830,   831,   831,   831,   831,   832,   832,   833,   833,
     833,   833,   833,   833,   833,   834,   834,   835,   835,   836,
     836,   836,   836,   836,   836,   837,   838,   838,   838,   838,
     839,   840,   840,   841,   841,   841,   842,   842,   843,   843,
     844,   844,   844,   845,   845,   846,   846,   847,   847,   847,
     847,   847,   848,   848,   849,   849,   850,   851,   851,   851,
     852,   853,   854,   855,   856,   857,   858,   859,   860,   861,
     862,   863,   864,   865,   866,   867,   868,   869,   870,   871,
     872,   873,   874,   875,   876,   876,   877,   878,   879,   880,
     881,   882,   883,   883,   884,   885,   886,   887,   888,   889,
     890,   891,   892,   893,   894,   895,   896,   897,   898,   898,
     899,   899,   900,   900,   901,   902,   903,   904,   905,   906,
     907,   908,   909,   910,   911,   912,   913,   914,   915,   916,
     917,   918,   919,   920,   921,   922,   923,   924,   924,   925,
     926,   926,   927,   927,   927,   927,   928,   928,   929,   930,
     931,   932,   933,   934,   935,   936,   937,   938,   939,   940,
     941,   942,   942,   943,   944,   945,   946,   947,   948,   949,
     950,   951,   952,   953,   954,   955,   956,   956,   956,   957,
     958,   959,   960,   961,   962,   963,   964,   965,   966,   967,
     968,   969,   969,   970,   971,   972,   973,   974,   975,   976,
     977,   978,   979,   980,   981,   982,   983,   984,   985,   986,
     986,   987,   988,   988,   988,   988,   989,   990,   991,   991,
     991,   992,   993,   994,   995,   996,   997,   998,   999,  1000,
    1001,  1002,  1003,  1004,  1004,  1004,  1005,  1006,  1006,  1006,
    1007,  1007,  1008,  1009,  1009,  1009,  1010,  1010,  1010,  1011,
    1012,  1013,  1014,  1015,  1016,  1017,  1018,  1019,  1020,  1021,
    1022,  1023,  1024,  1025,  1026,  1027,  1028,  1029,  1030,  1031,
    1032,  1033,  1034,  1035,  1036,  1037,  1038,  1039,  1040,  1041,
    1041,  1042,  1043,  1044,  1045,  1046,  1047,  1048,  1049,  1050,
    1051,  1052,  1053,  1054,  1055,  1055,  1055,  1055,  1055,  1055,
    1055,  1056,  1057,  1058,  1059,  1060,  1060,  1060,  1061,  1062,
    1063,  1064,  1065,  1066,  1067,  1068,  1069,  1069,  1069,  1070,
    1071,  1072,  1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,
    1081,  1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,
    1090,  1091,  1092,  1093,  1094,  1095,  1096,  1097,  1098,  1099,
    1100,  1101,  1102,  1103,  1104,  1105,  1106,  1107,  1108,  1109,
    1110,  1110,  1111,  1112,  1113,  1114,  1115,  1116,  1116,  1117,
    1118,  1119,  1120,  1121,  1121,  1122,  1122,  1123,  1124,  1125,
    1126,  1127,  1128,  1129,  1130,  1131,  1132,  1133,  1134,  1135,
    1136,  1137,  1138,  1139,  1140,  1141,  1142,  1143,  1144,  1145,
    1146,  1147,  1148,  1149,  1150,  1151,  1152,  1153,  1154,  1155,
    1156,  1157,  1158,  1159,  1160,  1161,  1162,  1163,  1164,  1164,
    1165,  1166,  1167,  1168,  1169,  1170,  1171,  1172,  1173,  1173,
    1173,  1173,  1174,  1175,  1176,  1177,  1178,  1179,  1180,  1181,
    1182,  1183,  1184,  1185,  1186,  1187,  1188,  1188,  1189,  1190,
    1191,  1192,  1192,  1193,  1194,  1194,  1195,  1195,  1195,  1195,
    1196,  1196,  1197,  1197,  1197,  1197,  1198,  1198,  1199,  1199,
    1200,  1200,  1201,  1201,  1202,  1203,  1203,  1203,  1203,  1203,
    1203,  1203,  1203,  1203,  1203,  1203,  1203,  1203,  1203,  1203,
    1203,  1203,  1203,  1203,  1203
  };

  const unsigned char
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
       1,     1,     1,     1,     1,     1,     1,     3,     4,     3,
       0,     9,     2,     3,     1,     3,     4,     2,     0,     9,
       2,     3,     1,     3,     4,     2,     3,     0,     9,     0,
       9,     2,     3,     1,     3,     4,     2,     3,     4,     2,
       4,     5,     3,     3,     3,     3,     3,     3,     2,     3,
       2,     3,     2,     3,     2,     3,     1,     3,     4,     2,
       3,     4,     2,     4,     5,     3,     2,     3,     1,     3,
       4,     2,     3,     4,     2,     4,     5,     3,     2,     3,
       1,     3,     4,     2,     3,     4,     2,     4,     5,     3,
       2,     3,     1,     3,     4,     2,     3,     4,     2,     4,
       5,     3,     2,     3,     1,     6,     1,     1,     1,     1,
       1,     2,     3,     3,     4,     4,     3,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     6,     6,     0,     5,     8,
       4,     8,     4,     4,     1,     1,     1,     3,     0,     1,
       5,     8,     7,     5,     8,     2,     1,     4,     5,     8,
       2,     1,     7,     7,     1,     1,     1,     1,     1,     1,
       1,     5,     1,     5,     3,     1,     0,     6,     0,     9,
       2,     2,     1,     1,     4,     2,     7,     5,     3,     1,
       3,     1,     3,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     7,     2,     2,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     6,     6,     0,     5,     8,     4,     8,     4,
       4,     4,     1,     3,     5,     5,     8,     2,     1,     1,
       6,     5,     7,     7,     9,     0,     6,     2,     1,     5,
       3,     0,     0,    10,     2,     2,     6,     5,     3,     1,
       1,     1,     1,     2,     6,     7,     7,     8,     2,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     5,     3,
       1,     1,     1,     1,     1,     5,     8,     2,     1,     3,
       2,     5,     4,     3,     1,     6,     5,     4,     3,     3,
       2,     1,     3,     1,     5,     3,     4,     2,     3,     1,
       2,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     5,     3,     1,     1,     1,     2,     5,
       3,     1,     0,     2,     5,     3,     1,     1,     1,     2,
       5,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     5,     3,     1,     1,
       1,     2,     5,     3,     1,     1,     1,     5,     3,     1,
       1,     1,     1,     1,     2,     5,     3,     6,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     3,
       1,     1,     1,     2,     2,     1,     1,     1,     2,     2,
       1,     2,     2,     1,     1,     1,     5,     2,     1,     4,
       2,     2,     1,     4,     1,     3,     5,     9,     1,     5,
       3,     5,     7,     9,     5,     7,     8,     2,     1,     5,
       7,     4,     5,     2,     1,     7,     9,     6,     5,     2,
       1,     6,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     5,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     4,     3,     6,     8,     3,     1,
       0,     8,     0,    10,     0,     8,     0,    11,     0,    13,
       0,    13,     0,    15,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     3,
       5,     6,     8,     8,    10,     7,     9,    10,    12,    12,
      14,     3,     1,     1,     1,     1,     4,     3,     5,     6,
       8,     8,    10,     2,     5,     3,     6,     3,     1,     1,
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
       6,     2,     5,     3,     6,     5,     2,     1,     4,     4,
       4,     4,     2,     5,     3,     6,     3,     1,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     1,
       2,     2,     2,     2,     5,     3,     6,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     3,     6,     1,     1,
       1,     1,     3,     1,     3,     6,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     2,     5,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     2,     5,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     2,     5,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       2,     5,     3,     6,     1,     1,     1,     1,     3,     1,
       2,     5,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     2,     5,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     2,     5,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     2,     5,     2,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     5,     1,     2,     6,
       4,     2,     5,     3,     6,     1,     3,     1,     1,     1,
       1,     1,     5,     1,     3,     1,     1,     1,     1,     1,
       3,     8,     5,     1,     2,     9,     0,     6,     2,     1,
       4,     6,     2,     5,     3,     6,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     5,     1,     1,
       5,     1,     2,     6,     9,     9,     5,     8,     1,     2,
       6,     9,     9,     2,     5,     3,     1,     1,     1,     1,
       1,     1,     5,    10,     2,     1,     4,     3,     2,     1,
       3,     3,     3,     3,     1,     1,     3,     3,     3,     3,
       1,     1,     1,     3,     5,     3,     3,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       3,     5,     1,     1,     1,     1,     1,     3,     5,     3,
       3,     3,     3,     3,     3,     5,     5,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     3,     3,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     1,     1,     3,     3,     3,     3,     3,
       1,     1,     1,     1,     3,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     5,
       5,     5,     3,     3,     5,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     5,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     5,     3,     3,     3,     3,     3,
       1,     1,     3,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     3,     3,
       3,     3,     3,     3,     5,     1,     1,     3,     3,     1,
       5,     3,     3,     3,     1,     3,     1,     1,     1,     1,
       3,     3,     3,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     1,     3,     3,     3,     1,
       3,     1,     1,     1,     3,     3,     3,     3,     1,     3,
       1,     3,     3,     3,     1,     3,     1,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     3,     5,     3,
       3,     5,     1,     1,     3,     3,     1,     3,     3,     3,
       3,     3,     6,     1,     1,     3,     2,     3,     2,     3,
       2,     3,     2,     3,     2,     3,     2,     3,     3,     1,
       3,     1,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "$end", "error", "$undefined", "AIM_SOLVER", "ANALYTIC_DERIVATION",
  "ANALYTIC_DERIVATION_MODE", "AR", "AUTOCORR",
  "POSTERIOR_SAMPLING_METHOD", "BAYESIAN_IRF", "BETA_PDF", "BLOCK",
  "USE_CALIBRATION", "SILENT_OPTIMIZER", "BVAR_DENSITY", "BVAR_FORECAST",
  "NODECOMPOSITION", "DR_DISPLAY_TOL", "HUGE_NUMBER", "BVAR_PRIOR_DECAY",
  "BVAR_PRIOR_FLAT", "BVAR_PRIOR_LAMBDA", "BVAR_PRIOR_MU",
  "BVAR_PRIOR_OMEGA", "BVAR_PRIOR_TAU", "BVAR_PRIOR_TRAIN", "BVAR_REPLIC",
  "BYTECODE", "ALL_VALUES_REQUIRED", "PROPOSAL_DISTRIBUTION",
  "CALIB_SMOOTHER", "CHANGE_TYPE", "CHECK", "CONDITIONAL_FORECAST",
  "CONDITIONAL_FORECAST_PATHS", "CONF_SIG", "CONSTANT",
  "CONTROLLED_VAREXO", "CORR", "COVAR", "CUTOFF", "CYCLE_REDUCTION",
  "LOGARITHMIC_REDUCTION", "CONSIDER_ALL_ENDOGENOUS",
  "CONSIDER_ONLY_OBSERVED", "DATAFILE", "FILE", "SERIES", "DOUBLING",
  "DR_CYCLE_REDUCTION_TOL", "DR_LOGARITHMIC_REDUCTION_TOL",
  "DR_LOGARITHMIC_REDUCTION_MAXITER", "DR_ALGO", "DROP", "DSAMPLE",
  "DYNASAVE", "DYNATYPE", "CALIBRATION", "DIFFERENTIATE_FORWARD_VARS",
  "END", "ENDVAL", "EQUAL", "ESTIMATION", "ESTIMATED_PARAMS",
  "ESTIMATED_PARAMS_BOUNDS", "ESTIMATED_PARAMS_INIT", "EXTENDED_PATH",
  "ENDOGENOUS_PRIOR", "FILENAME", "DIRNAME", "FILTER_STEP_AHEAD",
  "FILTERED_VARS", "FIRST_OBS", "LAST_OBS", "SET_TIME",
  "OSR_PARAMS_BOUNDS", "FLOAT_NUMBER", "DATES", "DEFAULT", "FIXED_POINT",
  "OPT_ALGO", "FORECAST", "K_ORDER_SOLVER", "INSTRUMENTS", "SHIFT", "MEAN",
  "STDEV", "VARIANCE", "MODE", "INTERVAL", "SHAPE", "DOMAINN", "GAMMA_PDF",
  "GRAPH", "GRAPH_FORMAT", "CONDITIONAL_VARIANCE_DECOMPOSITION", "NOCHECK",
  "STD", "HISTVAL", "HISTVAL_FILE", "HOMOTOPY_SETUP", "HOMOTOPY_MODE",
  "HOMOTOPY_STEPS", "HOMOTOPY_FORCE_CONTINUE", "HP_FILTER", "HP_NGRID",
  "HYBRID", "ONE_SIDED_HP_FILTER", "IDENTIFICATION", "INF_CONSTANT",
  "INITVAL", "INITVAL_FILE", "BOUNDS", "JSCALE", "INIT", "INFILE",
  "INVARS", "INT_NUMBER", "INV_GAMMA_PDF", "INV_GAMMA1_PDF",
  "INV_GAMMA2_PDF", "IRF", "IRF_SHOCKS", "IRF_PLOT_THRESHOLD",
  "IRF_CALIBRATION", "FAST_KALMAN_FILTER", "KALMAN_ALGO", "KALMAN_TOL",
  "DIFFUSE_KALMAN_TOL", "SUBSAMPLES", "OPTIONS", "TOLF", "TOLX", "LAPLACE",
  "LIK_ALGO", "LIK_INIT", "LINEAR", "LOAD_IDENT_FILES", "LOAD_MH_FILE",
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
  "SUB_DRAWS", "TAPER_STEPS", "GEWEKE_INTERVAL", "MCMC_JUMPING_COVARIANCE",
  "MOMENT_CALIBRATION", "NUMBER_OF_PARTICLES", "RESAMPLING", "SYSTEMATIC",
  "GENERIC", "RESAMPLING_THRESHOLD", "RESAMPLING_METHOD", "KITAGAWA",
  "STRATIFIED", "SMOOTH", "CPF_WEIGHTS", "AMISANOTRISTANI",
  "MURRAYJONESPARSLOW", "FILTER_ALGORITHM", "PROPOSAL_APPROXIMATION",
  "CUBATURE", "UNSCENTED", "MONTECARLO", "DISTRIBUTION_APPROXIMATION",
  "NAME", "NAN_CONSTANT", "NO_STATIC", "NOBS", "NOCONSTANT", "NODISPLAY",
  "NOCORR", "NODIAGNOSTIC", "NOFUNCTIONS", "NO_HOMOTOPY", "NOGRAPH",
  "NOMOMENTS", "NOPRINT", "NORMAL_PDF", "SAVE_DRAWS", "OBSERVATION_TRENDS",
  "OPTIM", "OPTIM_WEIGHTS", "ORDER", "OSR", "OSR_PARAMS",
  "MAX_DIM_COVA_GROUP", "ADVANCED", "OUTFILE", "OUTVARS", "OVERWRITE",
  "PARALLEL_LOCAL_FILES", "PARAMETERS", "PARAMETER_SET",
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
  "SOLVE_ALGO", "SOLVER_PERIODS", "STDERR", "STEADY", "STOCH_SIMUL",
  "SURPRISE", "SYLVESTER", "SYLVESTER_FIXED_POINT_TOL", "REGIMES",
  "REGIME", "TEX", "RAMSEY_MODEL", "RAMSEY_POLICY", "RAMSEY_CONSTRAINTS",
  "PLANNER_DISCOUNT", "DISCRETIONARY_POLICY", "DISCRETIONARY_TOL",
  "TEX_NAME", "UNIFORM_PDF", "UNIT_ROOT_VARS", "USE_DLL", "USEAUTOCORR",
  "GSA_SAMPLE_FILE", "USE_UNIVARIATE_FILTERS_IF_SINGULARITY_IS_DETECTED",
  "VALUES", "VAR", "VAREXO", "VAREXO_DET", "VAROBS",
  "PREDETERMINED_VARIABLES", "WRITE_LATEX_DYNAMIC_MODEL",
  "WRITE_LATEX_STATIC_MODEL", "WRITE_LATEX_ORIGINAL_MODEL", "XLS_SHEET",
  "XLS_RANGE", "LMMCP", "OCCBIN", "BANDPASS_FILTER", "COLORMAP", "COMMA",
  "EQUAL_EQUAL", "EXCLAMATION_EQUAL", "LESS", "GREATER", "LESS_EQUAL",
  "GREATER_EQUAL", "PLUS", "MINUS", "TIMES", "DIVIDE", "UMINUS", "UPLUS",
  "POWER", "EXP", "LOG", "LN", "LOG10", "SIN", "COS", "TAN", "ASIN",
  "ACOS", "ATAN", "SINH", "COSH", "TANH", "ERF", "ASINH", "ACOSH", "ATANH",
  "SQRT", "NORMCDF", "NORMPDF", "STEADY_STATE", "EXPECTATION",
  "DYNARE_SENSITIVITY", "MORRIS", "STAB", "REDFORM", "PPRIOR",
  "PRIOR_RANGE", "PPOST", "ILPTAU", "MORRIS_NLIV", "MORRIS_NTRA", "NSAM",
  "LOAD_REDFORM", "LOAD_RMSE", "LOAD_STAB", "ALPHA2_STAB", "KSSTAT",
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
  "FILTER_DECOMPOSITION", "EQ_CMS", "TLINDX", "TLNUMBER", "BANACT",
  "RESTRICTIONS", "POSTERIOR_SAMPLER_OPTIONS", "OUTPUT_FILE_TAG",
  "DRAWS_NBR_BURN_IN_1", "DRAWS_NBR_BURN_IN_2", "HORIZON", "SBVAR",
  "TREND_VAR", "DEFLATOR", "GROWTH_FACTOR", "MS_IRF",
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
  "FUNCTION_CONVERGENCE_CRITERION", "PARAMETER_CONVERGENCE_CRITERION",
  "NUMBER_OF_LARGE_PERTURBATIONS", "NUMBER_OF_SMALL_PERTURBATIONS",
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
  "ramsey_policy", "ramsey_constraints", "ramsey_constraints_list",
  "ramsey_constraint", "discretionary_policy",
  "discretionary_policy_options_list", "discretionary_policy_options",
  "ramsey_model_options_list", "ramsey_model_options",
  "ramsey_policy_options_list", "ramsey_policy_options",
  "write_latex_dynamic_model", "write_latex_static_model",
  "write_latex_original_model", "shock_decomposition", "bvar_prior_option",
  "bvar_common_option", "bvar_density_options_list", "bvar_density",
  "bvar_forecast_option", "bvar_forecast_options_list", "bvar_forecast",
  "sbvar_option", "sbvar_options_list", "sbvar",
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
  "shock_decomposition_option", "homotopy_setup", "homotopy_list",
  "homotopy_item", "forecast", "forecast_options", "forecast_option",
  "conditional_forecast", "conditional_forecast_options",
  "conditional_forecast_option", "plot_conditional_forecast",
  "conditional_forecast_paths", "conditional_forecast_paths_shock_list",
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
  "o_stack_solve_algo", "o_endogenous_terminal_period", "o_linear",
  "o_order", "o_replic", "o_drop", "o_ar", "o_nocorr", "o_nofunctions",
  "o_nomoments", "o_irf", "o_irf_shocks", "o_hp_filter", "o_hp_ngrid",
  "o_one_sided_hp_filter", "o_periods", "o_solver_periods",
  "o_extended_path_order", "o_hybrid", "o_steady_maxit", "o_simul_maxit",
  "o_bandpass_filter", "o_dp_maxit", "o_osr_maxit", "o_osr_tolf",
  "o_pf_tolf", "o_pf_tolx", "o_steady_tolf", "o_opt_algo", "o_cutoff",
  "o_markowitz", "o_minimal_solving_periods", "o_mfs", "o_simul",
  "o_simul_replic", "o_simul_seed", "o_qz_criterium",
  "o_qz_zero_threshold", "o_file", "o_series", "o_datafile", "o_dirname",
  "o_huge_number", "o_nobs", "o_conditional_variance_decomposition",
  "o_est_first_obs", "o_posterior_sampling_method", "o_first_obs",
  "o_data_first_obs", "o_data_last_obs", "o_data_nobs", "o_shift",
  "o_shape", "o_mode", "o_mean", "o_mean_vec", "o_truncate", "o_stdev",
  "o_jscale", "o_init", "o_bounds", "o_domain", "o_interval", "o_variance",
  "o_variance_mat", "o_prefilter", "o_presample", "o_lik_algo",
  "o_lik_init", "o_nograph", "o_nodisplay", "o_graph_format",
  "allowed_graph_formats", "list_allowed_graph_formats",
  "o_subsample_name", "o_conf_sig", "o_mh_conf_sig", "o_mh_replic",
  "o_posterior_max_subsample_draws", "o_mh_drop", "o_mh_jscale", "o_optim",
  "o_posterior_sampler_options", "o_proposal_distribution",
  "o_no_posterior_kernel_density", "o_mh_init_scale", "o_mode_file",
  "o_mode_compute", "o_mode_check", "o_mode_check_neighbourhood_size",
  "o_mode_check_number_of_points", "o_mode_check_symmetric_plots",
  "o_prior_trunc", "o_mh_mode", "o_mh_nblocks", "o_load_mh_file",
  "o_loglinear", "o_linear_approximation", "o_logdata", "o_nodiagnostic",
  "o_bayesian_irf", "o_dsge_var", "o_dsge_varlag", "o_tex", "o_forecast",
  "o_smoother", "o_moments_varendo", "o_contemporaneous_correlation",
  "o_filtered_vars", "o_relative_irf", "o_fast_kalman_filter",
  "o_kalman_algo", "o_kalman_tol", "o_diffuse_kalman_tol",
  "o_marginal_density", "o_print", "o_noprint", "o_xls_sheet",
  "o_xls_range", "o_filter_step_ahead", "o_taper_steps",
  "o_geweke_interval", "o_constant", "o_noconstant", "o_mh_recover",
  "o_diffuse_filter", "o_plot_priors", "o_aim_solver",
  "o_partial_information", "o_sub_draws", "o_planner_discount",
  "o_sylvester", "o_sylvester_fixed_point_tol", "o_lyapunov",
  "o_lyapunov_fixed_point_tol", "o_lyapunov_doubling_tol", "o_dr",
  "o_dr_cycle_reduction_tol", "o_dr_logarithmic_reduction_tol",
  "o_dr_logarithmic_reduction_maxiter", "o_bvar_prior_tau",
  "o_bvar_prior_decay", "o_bvar_prior_lambda", "o_bvar_prior_mu",
  "o_bvar_prior_omega", "o_bvar_prior_flat", "o_bvar_prior_train",
  "o_bvar_replic", "o_number_of_particles", "o_resampling",
  "o_resampling_threshold", "o_resampling_method", "o_cpf_weights",
  "o_filter_algorithm", "o_proposal_approximation",
  "o_distribution_approximation", "o_gsa_identification", "o_gsa_morris",
  "o_gsa_stab", "o_gsa_redform", "o_gsa_pprior", "o_gsa_prior_range",
  "o_gsa_ppost", "o_gsa_ilptau", "o_gsa_morris_nliv", "o_gsa_morris_ntra",
  "o_gsa_nsam", "o_gsa_load_redform", "o_gsa_load_rmse", "o_gsa_load_stab",
  "o_gsa_alpha2_stab", "o_gsa_ksstat", "o_gsa_logtrans_redform",
  "o_gsa_threshold_redform", "o_gsa_ksstat_redform",
  "o_gsa_alpha2_redform", "o_gsa_namendo", "o_gsa_namlagendo",
  "o_gsa_namexo", "o_gsa_rmse", "o_gsa_lik_only", "o_gsa_var_rmse",
  "o_gsa_pfilt_rmse", "o_gsa_istart_rmse", "o_gsa_alpha_rmse",
  "o_gsa_alpha2_rmse", "o_gsa_sample_file", "o_gsa_neighborhood_width",
  "o_gsa_pvalue_ks", "o_gsa_pvalue_corr", "o_load_ident_files",
  "o_useautocorr", "o_prior_mc", "o_advanced", "o_max_dim_cova_group",
  "o_homotopy_mode", "o_homotopy_steps", "o_homotopy_force_continue",
  "o_nocheck", "o_controlled_varexo", "o_parameter_set",
  "o_nodecomposition", "o_spectral_density", "o_ms_drop", "o_ms_mh_replic",
  "o_freq", "o_initial_year", "o_initial_subperiod", "o_final_year",
  "o_final_subperiod", "o_data", "o_vlist", "o_vlistlog", "o_vlistper",
  "o_restriction_fname", "o_nlags", "o_cross_restrictions",
  "o_contemp_reduced_form", "o_real_pseudo_forecast",
  "o_no_bayesian_prior", "o_dummy_obs", "o_nstates", "o_indxscalesstates",
  "o_alpha", "o_beta", "o_gsig2_lmdm", "o_specification", "o_q_diag",
  "o_flat_prior", "o_ncsk", "o_nstd", "o_ninv", "o_indxparr", "o_indxovr",
  "o_aband", "o_indxap", "o_apband", "o_indximf", "o_indxfore",
  "o_foreband", "o_indxgforhat", "o_indxgimfhat", "o_indxestima",
  "o_indxgdls", "o_eq_ms", "o_cms", "o_ncms", "o_eq_cms", "o_tlindx",
  "o_tlnumber", "o_cnum", "o_k_order_solver", "o_pruning", "o_chain",
  "o_restrictions", "o_duration", "o_number_of_regimes",
  "o_number_of_lags", "o_parameters", "o_coefficients", "o_variances",
  "o_equations", "o_silent_optimizer", "o_instruments", "o_ext_func_name",
  "o_ext_func_nargs", "o_first_deriv_provided", "o_second_deriv_provided",
  "o_filter_covariance", "o_filter_decomposition",
  "o_selected_variables_only", "o_cova_compute", "o_output_file_tag",
  "o_file_tag", "o_no_create_init", "o_simulation_file_tag",
  "o_coefficients_prior_hyperparameters", "o_convergence_starting_value",
  "o_convergence_ending_value", "o_convergence_increment_value",
  "o_max_iterations_starting_value", "o_max_iterations_increment_value",
  "o_max_block_iterations", "o_max_repeated_optimization_runs",
  "o_function_convergence_criterion", "o_parameter_convergence_criterion",
  "o_number_of_large_perturbations", "o_number_of_small_perturbations",
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
  "o_mcmc_jumping_covariance", "o_irf_plot_threshold", "o_dr_display_tol",
  "o_consider_all_endogenous", "o_consider_only_observed", "o_no_homotopy",
  "o_infile", "o_invars", "o_period", "o_outfile", "o_outvars", "o_lmmcp",
  "o_occbin", "o_function", "o_sampling_draws", "o_use_shock_groups",
  "o_colormap", "range", "integer_range", "signed_integer_range",
  "vec_int_number", "vec_int_elem", "vec_int_1", "vec_int", "vec_value_1",
  "vec_value", "vec_value_list", "vec_of_vec_value", "vec_value_1_w_inf",
  "vec_value_w_inf", "symbol", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  parser::yyrline_[] =
  {
       0,   196,   196,   197,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   295,   297,   301,
     303,   303,   307,   309,   311,   313,   315,   317,   321,   321,
     325,   327,   329,   331,   333,   335,   339,   340,   340,   342,
     342,   346,   348,   350,   352,   354,   356,   358,   360,   362,
     364,   366,   368,   372,   374,   376,   378,   380,   386,   391,
     396,   401,   408,   409,   412,   414,   416,   418,   420,   422,
     424,   426,   428,   430,   432,   434,   438,   440,   442,   444,
     446,   448,   450,   452,   454,   456,   458,   460,   464,   466,
     468,   470,   472,   474,   476,   478,   480,   482,   484,   486,
     490,   492,   494,   496,   498,   500,   502,   504,   506,   508,
     510,   512,   516,   518,   520,   524,   528,   530,   532,   534,
     538,   540,   542,   546,   548,   552,   554,   556,   558,   560,
     562,   564,   566,   568,   570,   572,   574,   576,   578,   580,
     582,   584,   586,   588,   590,   592,   594,   596,   598,   600,
     602,   604,   606,   608,   610,   612,   614,   616,   616,   618,
     620,   622,   624,   626,   628,   630,   634,   636,   640,   641,
     644,   646,   650,   654,   656,   660,   661,   664,   666,   668,
     672,   673,   676,   678,   682,   683,   684,   685,   686,   687,
     688,   689,   690,   691,   694,   695,   698,   698,   700,   700,
     704,   705,   706,   707,   710,   712,   714,   716,   720,   721,
     724,   726,   730,   732,   734,   736,   738,   740,   742,   744,
     746,   748,   750,   752,   754,   756,   758,   760,   762,   764,
     766,   768,   770,   772,   774,   776,   778,   780,   782,   784,
     786,   788,   790,   792,   794,   794,   796,   798,   800,   802,
     804,   806,   810,   812,   816,   819,   820,   823,   824,   827,
     828,   830,   832,   834,   838,   842,   842,   846,   847,   850,
     852,   855,   857,   854,   859,   861,   865,   867,   871,   873,
     877,   878,   881,   882,   885,   887,   889,   891,   895,   899,
     903,   904,   907,   908,   909,   910,   911,   912,   915,   919,
     920,   923,   924,   925,   926,   929,   930,   933,   934,   937,
     939,   941,   943,   945,   947,   951,   953,   955,   957,   959,
     961,   963,   967,   969,   973,   975,   977,   979,   981,   983,
     987,   989,   993,   994,   997,   998,   999,  1000,  1001,  1002,
    1003,  1004,  1007,  1009,  1013,  1014,  1017,  1018,  1021,  1023,
    1027,  1028,  1030,  1032,  1034,  1038,  1039,  1042,  1043,  1046,
    1048,  1052,  1053,  1056,  1057,  1058,  1059,  1060,  1061,  1062,
    1063,  1064,  1065,  1066,  1067,  1070,  1074,  1078,  1079,  1082,
    1083,  1086,  1088,  1092,  1093,  1096,  1097,  1100,  1104,  1105,
    1108,  1109,  1110,  1111,  1114,  1116,  1118,  1120,  1124,  1125,
    1128,  1129,  1130,  1131,  1132,  1133,  1134,  1135,  1136,  1137,
    1138,  1139,  1140,  1141,  1142,  1143,  1144,  1145,  1146,  1147,
    1148,  1149,  1150,  1151,  1152,  1153,  1154,  1155,  1156,  1157,
    1158,  1159,  1160,  1161,  1162,  1163,  1164,  1165,  1166,  1167,
    1168,  1169,  1172,  1173,  1174,  1175,  1176,  1177,  1180,  1182,
    1184,  1188,  1189,  1196,  1198,  1200,  1203,  1204,  1207,  1209,
    1211,  1214,  1216,  1218,  1222,  1223,  1226,  1228,  1230,  1234,
    1235,  1237,  1243,  1249,  1257,  1264,  1268,  1273,  1280,  1284,
    1292,  1297,  1303,  1310,  1320,  1322,  1324,  1328,  1330,  1334,
    1341,  1350,  1359,  1362,  1364,  1368,  1376,  1386,  1396,  1399,
    1401,  1405,  1414,  1416,  1418,  1420,  1422,  1424,  1426,  1428,
    1430,  1434,  1436,  1438,  1440,  1442,  1444,  1446,  1448,  1452,
    1454,  1456,  1460,  1464,  1468,  1469,  1472,  1473,  1474,  1475,
    1476,  1477,  1478,  1481,  1485,  1493,  1499,  1505,  1513,  1514,
    1517,  1517,  1519,  1519,  1521,  1521,  1523,  1523,  1525,  1525,
    1527,  1527,  1529,  1529,  1533,  1534,  1537,  1538,  1539,  1540,
    1541,  1542,  1543,  1544,  1545,  1546,  1549,  1550,  1553,  1554,
    1555,  1556,  1557,  1558,  1559,  1560,  1561,  1562,  1565,  1574,
    1582,  1590,  1598,  1606,  1614,  1624,  1626,  1628,  1630,  1632,
    1634,  1638,  1639,  1642,  1643,  1644,  1647,  1656,  1664,  1672,
    1680,  1688,  1696,  1706,  1708,  1710,  1712,  1716,  1717,  1720,
    1721,  1722,  1723,  1724,  1725,  1726,  1727,  1728,  1729,  1730,
    1731,  1732,  1733,  1734,  1735,  1736,  1737,  1738,  1739,  1740,
    1741,  1742,  1743,  1744,  1745,  1746,  1747,  1748,  1749,  1750,
    1751,  1752,  1753,  1754,  1755,  1756,  1757,  1758,  1759,  1760,
    1761,  1762,  1763,  1764,  1765,  1766,  1767,  1768,  1769,  1770,
    1771,  1772,  1773,  1774,  1775,  1776,  1777,  1778,  1779,  1780,
    1781,  1782,  1783,  1784,  1785,  1786,  1787,  1788,  1789,  1790,
    1791,  1792,  1793,  1794,  1795,  1796,  1797,  1798,  1799,  1800,
    1801,  1802,  1803,  1804,  1805,  1806,  1807,  1808,  1809,  1810,
    1811,  1812,  1813,  1814,  1815,  1816,  1817,  1818,  1819,  1820,
    1823,  1825,  1829,  1830,  1833,  1841,  1850,  1852,  1860,  1862,
    1864,  1872,  1873,  1876,  1876,  1878,  1880,  1882,  1886,  1888,
    1889,  1892,  1894,  1896,  1898,  1900,  1902,  1904,  1908,  1911,
    1912,  1915,  1916,  1917,  1918,  1919,  1920,  1921,  1924,  1926,
    1928,  1930,  1934,  1936,  1940,  1942,  1946,  1950,  1954,  1956,
    1960,  1961,  1964,  1965,  1966,  1967,  1968,  1969,  1970,  1971,
    1972,  1973,  1974,  1975,  1976,  1977,  1978,  1979,  1980,  1981,
    1982,  1983,  1986,  1988,  1992,  1993,  1996,  1998,  2002,  2004,
    2006,  2008,  2010,  2012,  2016,  2017,  2016,  2019,  2021,  2023,
    2025,  2029,  2031,  2033,  2035,  2039,  2043,  2044,  2047,  2049,
    2051,  2053,  2057,  2059,  2061,  2063,  2067,  2068,  2071,  2072,
    2073,  2076,  2077,  2080,  2081,  2084,  2085,  2088,  2089,  2090,
    2093,  2097,  2101,  2105,  2107,  2109,  2111,  2115,  2116,  2117,
    2118,  2119,  2120,  2121,  2124,  2125,  2126,  2127,  2128,  2129,
    2130,  2131,  2132,  2133,  2136,  2137,  2140,  2142,  2146,  2147,
    2148,  2149,  2152,  2153,  2156,  2158,  2162,  2163,  2164,  2165,
    2166,  2167,  2168,  2169,  2170,  2171,  2172,  2173,  2174,  2175,
    2176,  2177,  2178,  2179,  2180,  2181,  2182,  2183,  2184,  2185,
    2186,  2187,  2188,  2189,  2190,  2191,  2192,  2193,  2194,  2195,
    2196,  2197,  2198,  2199,  2200,  2201,  2202,  2203,  2204,  2205,
    2206,  2207,  2208,  2209,  2212,  2213,  2216,  2218,  2222,  2223,
    2224,  2225,  2226,  2227,  2228,  2229,  2230,  2231,  2232,  2233,
    2234,  2235,  2238,  2239,  2242,  2244,  2248,  2249,  2250,  2251,
    2252,  2253,  2254,  2255,  2256,  2257,  2258,  2259,  2260,  2261,
    2264,  2265,  2268,  2270,  2274,  2275,  2276,  2277,  2278,  2279,
    2280,  2281,  2282,  2283,  2284,  2285,  2286,  2287,  2290,  2291,
    2294,  2296,  2298,  2300,  2304,  2305,  2306,  2307,  2310,  2311,
    2314,  2316,  2320,  2321,  2322,  2323,  2324,  2325,  2326,  2327,
    2330,  2331,  2334,  2336,  2340,  2341,  2342,  2343,  2344,  2345,
    2346,  2349,  2350,  2353,  2355,  2359,  2360,  2361,  2362,  2363,
    2364,  2365,  2366,  2367,  2368,  2369,  2370,  2371,  2372,  2373,
    2374,  2375,  2376,  2377,  2378,  2379,  2380,  2381,  2382,  2383,
    2384,  2385,  2386,  2387,  2388,  2389,  2390,  2391,  2392,  2393,
    2396,  2397,  2400,  2402,  2406,  2408,  2412,  2413,  2416,  2417,
    2418,  2419,  2420,  2421,  2422,  2423,  2424,  2425,  2426,  2427,
    2428,  2429,  2430,  2431,  2432,  2433,  2434,  2435,  2436,  2437,
    2438,  2439,  2440,  2441,  2442,  2443,  2444,  2445,  2446,  2447,
    2448,  2449,  2450,  2451,  2452,  2453,  2454,  2455,  2456,  2457,
    2458,  2459,  2460,  2461,  2462,  2463,  2464,  2465,  2466,  2467,
    2470,  2471,  2474,  2475,  2476,  2477,  2480,  2483,  2484,  2487,
    2489,  2493,  2494,  2495,  2496,  2499,  2500,  2503,  2504,  2505,
    2506,  2507,  2510,  2514,  2515,  2518,  2519,  2520,  2521,  2522,
    2525,  2527,  2531,  2535,  2536,  2539,  2543,  2543,  2547,  2548,
    2551,  2553,  2557,  2559,  2561,  2563,  2567,  2568,  2571,  2572,
    2573,  2574,  2575,  2576,  2577,  2580,  2582,  2586,  2587,  2590,
    2591,  2592,  2593,  2594,  2595,  2598,  2602,  2608,  2614,  2620,
    2628,  2632,  2633,  2636,  2638,  2640,  2644,  2646,  2650,  2651,
    2654,  2656,  2658,  2662,  2664,  2668,  2669,  2672,  2673,  2674,
    2675,  2676,  2679,  2680,  2684,  2685,  2688,  2691,  2692,  2693,
    2696,  2702,  2703,  2709,  2710,  2711,  2712,  2713,  2714,  2715,
    2716,  2717,  2718,  2719,  2720,  2721,  2722,  2723,  2724,  2725,
    2726,  2727,  2728,  2729,  2730,  2731,  2737,  2738,  2739,  2740,
    2741,  2742,  2743,  2744,  2746,  2747,  2748,  2749,  2750,  2751,
    2752,  2753,  2754,  2755,  2756,  2757,  2758,  2759,  2760,  2762,
    2765,  2767,  2770,  2772,  2775,  2777,  2778,  2779,  2780,  2781,
    2782,  2783,  2784,  2785,  2786,  2787,  2788,  2789,  2790,  2791,
    2792,  2793,  2794,  2795,  2796,  2797,  2798,  2799,  2801,  2804,
    2805,  2807,  2810,  2812,  2814,  2816,  2819,  2820,  2823,  2826,
    2827,  2828,  2829,  2830,  2831,  2832,  2833,  2834,  2835,  2838,
    2839,  2840,  2841,  2842,  2843,  2844,  2845,  2846,  2847,  2848,
    2849,  2850,  2851,  2852,  2853,  2854,  2855,  2857,  2859,  2862,
    2863,  2864,  2865,  2866,  2867,  2868,  2869,  2870,  2871,  2872,
    2873,  2874,  2876,  2879,  2880,  2881,  2882,  2883,  2884,  2885,
    2886,  2887,  2888,  2889,  2890,  2891,  2892,  2893,  2894,  2895,
    2896,  2897,  2898,  2899,  2900,  2901,  2902,  2903,  2904,  2905,
    2906,  2907,  2908,  2909,  2911,  2912,  2913,  2914,  2915,  2916,
    2917,  2918,  2920,  2921,  2922,  2923,  2924,  2925,  2926,  2927,
    2928,  2929,  2930,  2931,  2932,  2933,  2934,  2935,  2936,  2939,
    2940,  2941,  2942,  2943,  2944,  2945,  2946,  2947,  2948,  2949,
    2950,  2951,  2952,  2953,  2954,  2955,  2956,  2957,  2958,  2959,
    2960,  2961,  2962,  2963,  2964,  2965,  2966,  2967,  2968,  2969,
    2971,  2974,  2975,  2976,  2977,  2978,  2979,  2980,  2981,  2983,
    2984,  2985,  2986,  2988,  2989,  2991,  2993,  2995,  2997,  2999,
    3001,  3004,  3005,  3006,  3007,  3008,  3010,  3012,  3015,  3016,
    3017,  3018,  3019,  3020,  3021,  3022,  3023,  3028,  3033,  3039,
    3040,  3041,  3042,  3043,  3044,  3045,  3046,  3047,  3048,  3049,
    3050,  3052,  3055,  3056,  3057,  3058,  3059,  3060,  3061,  3062,
    3063,  3064,  3065,  3066,  3067,  3068,  3069,  3070,  3071,  3072,
    3073,  3074,  3075,  3076,  3077,  3078,  3079,  3080,  3081,  3082,
    3085,  3087,  3090,  3091,  3092,  3093,  3094,  3095,  3097,  3100,
    3101,  3103,  3104,  3105,  3107,  3110,  3112,  3115,  3118,  3121,
    3124,  3127,  3128,  3129,  3130,  3131,  3133,  3135,  3137,  3139,
    3141,  3143,  3145,  3147,  3149,  3151,  3153,  3155,  3157,  3159,
    3161,  3163,  3164,  3165,  3166,  3167,  3168,  3169,  3170,  3171,
    3172,  3173,  3174,  3175,  3176,  3177,  3178,  3179,  3180,  3181,
    3182,  3183,  3184,  3185,  3186,  3187,  3188,  3189,  3190,  3191,
    3193,  3195,  3198,  3199,  3200,  3201,  3202,  3204,  3205,  3206,
    3207,  3208,  3209,  3210,  3211,  3212,  3213,  3214,  3216,  3218,
    3226,  3234,  3241,  3251,  3253,  3254,  3264,  3266,  3268,  3276,
    3286,  3288,  3292,  3293,  3294,  3301,  3310,  3311,  3314,  3321,
    3325,  3326,  3328,  3330,  3339,  3341,  3342,  3343,  3344,  3345,
    3346,  3347,  3348,  3349,  3350,  3351,  3352,  3353,  3354,  3355,
    3356,  3357,  3358,  3359,  3360
  };

  // Print the state stack on the debug stream.
  void
  parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
  parser::token_number_type
  parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,   554,     2,     2,     2,     2,
     550,   551,     2,     2,     2,     2,   556,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   555,   549,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   552,     2,   553,     2,     2,     2,     2,     2,     2,
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
     545,   546,   547,   548
    };
    const unsigned int user_token_number_max_ = 803;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // Dynare
#line 11191 "DynareBison.cc" // lalr1.cc:1155
#line 3362 "lex_yacc/DynareBison.yy" // lalr1.cc:1156


void
Dynare::parser::error(const Dynare::parser::location_type &l,
                      const string &m)
{
  driver.error(l, m);
}
