// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

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
// //                    "%code top" blocks.
#line 24 "lex_yacc/DynareBison.yy" // lalr1.cc:397

class ParsingDriver;

#line 38 "DynareBison.cc" // lalr1.cc:397

// Take the name prefix into account.
#define yylex   Dynarelex

// First part of user declarations.

#line 45 "DynareBison.cc" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "DynareBison.hh"

// User implementation prologue.

#line 59 "DynareBison.cc" // lalr1.cc:412
// Unqualified %code blocks.
#line 60 "lex_yacc/DynareBison.yy" // lalr1.cc:413

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

#line 88 "DynareBison.cc" // lalr1.cc:413


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
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace Dynare {
#line 174 "DynareBison.cc" // lalr1.cc:479

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
    clear ();
  }

  template <typename Base>
  inline
  void
  parser::basic_symbol<Base>::clear ()
  {
    Base::clear ();
  }

  template <typename Base>
  inline
  bool
  parser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
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
    : type (empty_symbol)
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
  parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
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
    : state (empty_state)
  {}

  inline
  parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  parser::symbol_number_type
  parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
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
    that.type = empty_symbol;
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
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
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
    #line 40 "lex_yacc/DynareBison.yy" // lalr1.cc:741
{
  // Initialize the locations' filenames to the filename maintained by the lexer
  yyla.location.begin.filename = yyla.location.end.filename = &(driver.lexer->filename);
}

#line 553 "DynareBison.cc" // lalr1.cc:741

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
    if (yyla.empty ())
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
  case 100:
#line 300 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.dsample((yystack_[1].value.string_val)); }
#line 663 "DynareBison.cc" // lalr1.cc:859
    break;

  case 101:
#line 302 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.dsample((yystack_[2].value.string_val), (yystack_[1].value.string_val)); }
#line 669 "DynareBison.cc" // lalr1.cc:859
    break;

  case 102:
#line 305 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.rplot(); }
#line 675 "DynareBison.cc" // lalr1.cc:859
    break;

  case 103:
#line 307 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.begin_trend(); }
#line 681 "DynareBison.cc" // lalr1.cc:859
    break;

  case 104:
#line 308 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.end_trend_var((yystack_[3].value.node_val)); }
#line 687 "DynareBison.cc" // lalr1.cc:859
    break;

  case 105:
#line 312 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_trend_var(false, (yystack_[0].value.string_val)); }
#line 693 "DynareBison.cc" // lalr1.cc:859
    break;

  case 106:
#line 314 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_trend_var(false, (yystack_[0].value.string_val)); }
#line 699 "DynareBison.cc" // lalr1.cc:859
    break;

  case 107:
#line 316 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_trend_var(false, (yystack_[0].value.string_val)); }
#line 705 "DynareBison.cc" // lalr1.cc:859
    break;

  case 108:
#line 318 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_trend_var(false, (yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 711 "DynareBison.cc" // lalr1.cc:859
    break;

  case 109:
#line 320 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_trend_var(false, (yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 717 "DynareBison.cc" // lalr1.cc:859
    break;

  case 110:
#line 322 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_trend_var(false, (yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 723 "DynareBison.cc" // lalr1.cc:859
    break;

  case 111:
#line 325 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.begin_trend(); }
#line 729 "DynareBison.cc" // lalr1.cc:859
    break;

  case 112:
#line 326 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.end_trend_var((yystack_[3].value.node_val)); }
#line 735 "DynareBison.cc" // lalr1.cc:859
    break;

  case 113:
#line 330 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_trend_var(true, (yystack_[0].value.string_val)); }
#line 741 "DynareBison.cc" // lalr1.cc:859
    break;

  case 114:
#line 332 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_trend_var(true, (yystack_[0].value.string_val)); }
#line 747 "DynareBison.cc" // lalr1.cc:859
    break;

  case 115:
#line 334 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_trend_var(true, (yystack_[0].value.string_val)); }
#line 753 "DynareBison.cc" // lalr1.cc:859
    break;

  case 116:
#line 336 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_trend_var(true, (yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 759 "DynareBison.cc" // lalr1.cc:859
    break;

  case 117:
#line 338 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_trend_var(true, (yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 765 "DynareBison.cc" // lalr1.cc:859
    break;

  case 118:
#line 340 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_trend_var(true, (yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 771 "DynareBison.cc" // lalr1.cc:859
    break;

  case 120:
#line 344 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.begin_trend(); }
#line 777 "DynareBison.cc" // lalr1.cc:859
    break;

  case 121:
#line 345 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.end_nonstationary_var(false, (yystack_[3].value.node_val)); }
#line 783 "DynareBison.cc" // lalr1.cc:859
    break;

  case 122:
#line 346 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.begin_trend(); }
#line 789 "DynareBison.cc" // lalr1.cc:859
    break;

  case 123:
#line 347 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.end_nonstationary_var(true, (yystack_[3].value.node_val)); }
#line 795 "DynareBison.cc" // lalr1.cc:859
    break;

  case 124:
#line 351 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_nonstationary_var((yystack_[0].value.string_val)); }
#line 801 "DynareBison.cc" // lalr1.cc:859
    break;

  case 125:
#line 353 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_nonstationary_var((yystack_[0].value.string_val)); }
#line 807 "DynareBison.cc" // lalr1.cc:859
    break;

  case 126:
#line 355 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_nonstationary_var((yystack_[0].value.string_val)); }
#line 813 "DynareBison.cc" // lalr1.cc:859
    break;

  case 127:
#line 357 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_nonstationary_var((yystack_[1].value.string_val), NULL, (yystack_[0].value.vector_string_pair_val)); }
#line 819 "DynareBison.cc" // lalr1.cc:859
    break;

  case 128:
#line 359 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_nonstationary_var((yystack_[1].value.string_val), NULL, (yystack_[0].value.vector_string_pair_val)); }
#line 825 "DynareBison.cc" // lalr1.cc:859
    break;

  case 129:
#line 361 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_nonstationary_var((yystack_[1].value.string_val), NULL, (yystack_[0].value.vector_string_pair_val)); }
#line 831 "DynareBison.cc" // lalr1.cc:859
    break;

  case 130:
#line 363 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_nonstationary_var((yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 837 "DynareBison.cc" // lalr1.cc:859
    break;

  case 131:
#line 365 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_nonstationary_var((yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 843 "DynareBison.cc" // lalr1.cc:859
    break;

  case 132:
#line 367 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_nonstationary_var((yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 849 "DynareBison.cc" // lalr1.cc:859
    break;

  case 133:
#line 369 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_nonstationary_var((yystack_[2].value.string_val), (yystack_[1].value.string_val), (yystack_[0].value.vector_string_pair_val)); }
#line 855 "DynareBison.cc" // lalr1.cc:859
    break;

  case 134:
#line 371 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_nonstationary_var((yystack_[2].value.string_val), (yystack_[1].value.string_val), (yystack_[0].value.vector_string_pair_val)); }
#line 861 "DynareBison.cc" // lalr1.cc:859
    break;

  case 135:
#line 373 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_nonstationary_var((yystack_[2].value.string_val), (yystack_[1].value.string_val), (yystack_[0].value.vector_string_pair_val)); }
#line 867 "DynareBison.cc" // lalr1.cc:859
    break;

  case 140:
#line 385 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                  pair<string *, string *> *pr = new pair<string *, string *>((yystack_[2].value.string_val), (yystack_[0].value.string_val));
                  (yylhs.value.string_pair_val) = pr;
               }
#line 876 "DynareBison.cc" // lalr1.cc:859
    break;

  case 141:
#line 391 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                (yylhs.value.vector_string_pair_val) = new vector<pair<string *, string *> *>();
                (yylhs.value.vector_string_pair_val)->push_back((yystack_[0].value.string_pair_val));
              }
#line 885 "DynareBison.cc" // lalr1.cc:859
    break;

  case 142:
#line 396 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                (yylhs.value.vector_string_pair_val) = new vector<pair<string *, string *> *>();
                (yylhs.value.vector_string_pair_val)->push_back((yystack_[0].value.string_pair_val));
              }
#line 894 "DynareBison.cc" // lalr1.cc:859
    break;

  case 143:
#line 401 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                (yystack_[1].value.vector_string_pair_val)->push_back((yystack_[0].value.string_pair_val));
                (yylhs.value.vector_string_pair_val) = (yystack_[1].value.vector_string_pair_val);
              }
#line 903 "DynareBison.cc" // lalr1.cc:859
    break;

  case 144:
#line 406 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                (yystack_[2].value.vector_string_pair_val)->push_back((yystack_[0].value.string_pair_val));
                (yylhs.value.vector_string_pair_val) = (yystack_[2].value.vector_string_pair_val);
              }
#line 912 "DynareBison.cc" // lalr1.cc:859
    break;

  case 145:
#line 412 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.vector_string_pair_val) = (yystack_[1].value.vector_string_pair_val); }
#line 918 "DynareBison.cc" // lalr1.cc:859
    break;

  case 146:
#line 413 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.vector_string_pair_val) = (yystack_[2].value.vector_string_pair_val); }
#line 924 "DynareBison.cc" // lalr1.cc:859
    break;

  case 147:
#line 417 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_endogenous((yystack_[0].value.string_val)); }
#line 930 "DynareBison.cc" // lalr1.cc:859
    break;

  case 148:
#line 419 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_endogenous((yystack_[0].value.string_val)); }
#line 936 "DynareBison.cc" // lalr1.cc:859
    break;

  case 149:
#line 421 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_endogenous((yystack_[0].value.string_val)); }
#line 942 "DynareBison.cc" // lalr1.cc:859
    break;

  case 150:
#line 423 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_endogenous((yystack_[1].value.string_val), NULL, (yystack_[0].value.vector_string_pair_val)); }
#line 948 "DynareBison.cc" // lalr1.cc:859
    break;

  case 151:
#line 425 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_endogenous((yystack_[1].value.string_val), NULL, (yystack_[0].value.vector_string_pair_val)); }
#line 954 "DynareBison.cc" // lalr1.cc:859
    break;

  case 152:
#line 427 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_endogenous((yystack_[1].value.string_val), NULL, (yystack_[0].value.vector_string_pair_val)); }
#line 960 "DynareBison.cc" // lalr1.cc:859
    break;

  case 153:
#line 429 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_endogenous((yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 966 "DynareBison.cc" // lalr1.cc:859
    break;

  case 154:
#line 431 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_endogenous((yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 972 "DynareBison.cc" // lalr1.cc:859
    break;

  case 155:
#line 433 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_endogenous((yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 978 "DynareBison.cc" // lalr1.cc:859
    break;

  case 156:
#line 435 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_endogenous((yystack_[2].value.string_val), (yystack_[1].value.string_val), (yystack_[0].value.vector_string_pair_val)); }
#line 984 "DynareBison.cc" // lalr1.cc:859
    break;

  case 157:
#line 437 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_endogenous((yystack_[2].value.string_val), (yystack_[1].value.string_val), (yystack_[0].value.vector_string_pair_val)); }
#line 990 "DynareBison.cc" // lalr1.cc:859
    break;

  case 158:
#line 439 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_endogenous((yystack_[2].value.string_val), (yystack_[1].value.string_val), (yystack_[0].value.vector_string_pair_val)); }
#line 996 "DynareBison.cc" // lalr1.cc:859
    break;

  case 159:
#line 443 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_exogenous((yystack_[0].value.string_val)); }
#line 1002 "DynareBison.cc" // lalr1.cc:859
    break;

  case 160:
#line 445 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_exogenous((yystack_[0].value.string_val)); }
#line 1008 "DynareBison.cc" // lalr1.cc:859
    break;

  case 161:
#line 447 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_exogenous((yystack_[0].value.string_val)); }
#line 1014 "DynareBison.cc" // lalr1.cc:859
    break;

  case 162:
#line 449 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_exogenous((yystack_[1].value.string_val), NULL, (yystack_[0].value.vector_string_pair_val)); }
#line 1020 "DynareBison.cc" // lalr1.cc:859
    break;

  case 163:
#line 451 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_exogenous((yystack_[1].value.string_val), NULL, (yystack_[0].value.vector_string_pair_val)); }
#line 1026 "DynareBison.cc" // lalr1.cc:859
    break;

  case 164:
#line 453 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_exogenous((yystack_[1].value.string_val), NULL, (yystack_[0].value.vector_string_pair_val)); }
#line 1032 "DynareBison.cc" // lalr1.cc:859
    break;

  case 165:
#line 455 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_exogenous((yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 1038 "DynareBison.cc" // lalr1.cc:859
    break;

  case 166:
#line 457 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_exogenous((yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 1044 "DynareBison.cc" // lalr1.cc:859
    break;

  case 167:
#line 459 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_exogenous((yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 1050 "DynareBison.cc" // lalr1.cc:859
    break;

  case 168:
#line 461 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_exogenous((yystack_[2].value.string_val), (yystack_[1].value.string_val), (yystack_[0].value.vector_string_pair_val)); }
#line 1056 "DynareBison.cc" // lalr1.cc:859
    break;

  case 169:
#line 463 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_exogenous((yystack_[2].value.string_val), (yystack_[1].value.string_val), (yystack_[0].value.vector_string_pair_val)); }
#line 1062 "DynareBison.cc" // lalr1.cc:859
    break;

  case 170:
#line 465 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_exogenous((yystack_[2].value.string_val), (yystack_[1].value.string_val), (yystack_[0].value.vector_string_pair_val)); }
#line 1068 "DynareBison.cc" // lalr1.cc:859
    break;

  case 171:
#line 469 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_exogenous_det((yystack_[0].value.string_val)); }
#line 1074 "DynareBison.cc" // lalr1.cc:859
    break;

  case 172:
#line 471 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_exogenous_det((yystack_[0].value.string_val)); }
#line 1080 "DynareBison.cc" // lalr1.cc:859
    break;

  case 173:
#line 473 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_exogenous_det((yystack_[0].value.string_val)); }
#line 1086 "DynareBison.cc" // lalr1.cc:859
    break;

  case 174:
#line 475 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_exogenous_det((yystack_[1].value.string_val), NULL, (yystack_[0].value.vector_string_pair_val)); }
#line 1092 "DynareBison.cc" // lalr1.cc:859
    break;

  case 175:
#line 477 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_exogenous_det((yystack_[1].value.string_val), NULL, (yystack_[0].value.vector_string_pair_val)); }
#line 1098 "DynareBison.cc" // lalr1.cc:859
    break;

  case 176:
#line 479 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_exogenous_det((yystack_[1].value.string_val), NULL, (yystack_[0].value.vector_string_pair_val)); }
#line 1104 "DynareBison.cc" // lalr1.cc:859
    break;

  case 177:
#line 481 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_exogenous_det((yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 1110 "DynareBison.cc" // lalr1.cc:859
    break;

  case 178:
#line 483 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_exogenous_det((yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 1116 "DynareBison.cc" // lalr1.cc:859
    break;

  case 179:
#line 485 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_exogenous_det((yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 1122 "DynareBison.cc" // lalr1.cc:859
    break;

  case 180:
#line 487 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_exogenous_det((yystack_[2].value.string_val), (yystack_[1].value.string_val), (yystack_[0].value.vector_string_pair_val)); }
#line 1128 "DynareBison.cc" // lalr1.cc:859
    break;

  case 181:
#line 489 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_exogenous_det((yystack_[2].value.string_val), (yystack_[1].value.string_val), (yystack_[0].value.vector_string_pair_val)); }
#line 1134 "DynareBison.cc" // lalr1.cc:859
    break;

  case 182:
#line 491 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_exogenous_det((yystack_[2].value.string_val), (yystack_[1].value.string_val), (yystack_[0].value.vector_string_pair_val)); }
#line 1140 "DynareBison.cc" // lalr1.cc:859
    break;

  case 183:
#line 495 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_parameter((yystack_[0].value.string_val)); }
#line 1146 "DynareBison.cc" // lalr1.cc:859
    break;

  case 184:
#line 497 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_parameter((yystack_[0].value.string_val)); }
#line 1152 "DynareBison.cc" // lalr1.cc:859
    break;

  case 185:
#line 499 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_parameter((yystack_[0].value.string_val)); }
#line 1158 "DynareBison.cc" // lalr1.cc:859
    break;

  case 186:
#line 501 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_parameter((yystack_[1].value.string_val), NULL, (yystack_[0].value.vector_string_pair_val)); }
#line 1164 "DynareBison.cc" // lalr1.cc:859
    break;

  case 187:
#line 503 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_parameter((yystack_[1].value.string_val), NULL, (yystack_[0].value.vector_string_pair_val)); }
#line 1170 "DynareBison.cc" // lalr1.cc:859
    break;

  case 188:
#line 505 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_parameter((yystack_[1].value.string_val), NULL, (yystack_[0].value.vector_string_pair_val)); }
#line 1176 "DynareBison.cc" // lalr1.cc:859
    break;

  case 189:
#line 507 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_parameter((yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 1182 "DynareBison.cc" // lalr1.cc:859
    break;

  case 190:
#line 509 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_parameter((yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 1188 "DynareBison.cc" // lalr1.cc:859
    break;

  case 191:
#line 511 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_parameter((yystack_[1].value.string_val), (yystack_[0].value.string_val)); }
#line 1194 "DynareBison.cc" // lalr1.cc:859
    break;

  case 192:
#line 513 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_parameter((yystack_[2].value.string_val), (yystack_[1].value.string_val), (yystack_[0].value.vector_string_pair_val)); }
#line 1200 "DynareBison.cc" // lalr1.cc:859
    break;

  case 193:
#line 515 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_parameter((yystack_[2].value.string_val), (yystack_[1].value.string_val), (yystack_[0].value.vector_string_pair_val)); }
#line 1206 "DynareBison.cc" // lalr1.cc:859
    break;

  case 194:
#line 517 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_parameter((yystack_[2].value.string_val), (yystack_[1].value.string_val), (yystack_[0].value.vector_string_pair_val)); }
#line 1212 "DynareBison.cc" // lalr1.cc:859
    break;

  case 195:
#line 521 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_predetermined_variable((yystack_[0].value.string_val)); }
#line 1218 "DynareBison.cc" // lalr1.cc:859
    break;

  case 196:
#line 523 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_predetermined_variable((yystack_[0].value.string_val)); }
#line 1224 "DynareBison.cc" // lalr1.cc:859
    break;

  case 197:
#line 525 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_predetermined_variable((yystack_[0].value.string_val)); }
#line 1230 "DynareBison.cc" // lalr1.cc:859
    break;

  case 198:
#line 529 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.change_type((yystack_[3].value.symbol_type_val), (yystack_[1].value.vector_string_val)); }
#line 1236 "DynareBison.cc" // lalr1.cc:859
    break;

  case 199:
#line 533 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.symbol_type_val) = eParameter; }
#line 1242 "DynareBison.cc" // lalr1.cc:859
    break;

  case 200:
#line 535 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.symbol_type_val) = eEndogenous; }
#line 1248 "DynareBison.cc" // lalr1.cc:859
    break;

  case 201:
#line 537 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.symbol_type_val) = eExogenous; }
#line 1254 "DynareBison.cc" // lalr1.cc:859
    break;

  case 202:
#line 539 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.symbol_type_val) = eExogenousDet; }
#line 1260 "DynareBison.cc" // lalr1.cc:859
    break;

  case 203:
#line 543 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.vector_string_val) = new vector<string *>(); (yylhs.value.vector_string_val)->push_back((yystack_[0].value.string_val)); }
#line 1266 "DynareBison.cc" // lalr1.cc:859
    break;

  case 204:
#line 545 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.vector_string_val) = (yystack_[1].value.vector_string_val); (yystack_[1].value.vector_string_val)->push_back((yystack_[0].value.string_val)); }
#line 1272 "DynareBison.cc" // lalr1.cc:859
    break;

  case 205:
#line 547 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.vector_string_val) = (yystack_[2].value.vector_string_val); (yystack_[2].value.vector_string_val)->push_back((yystack_[0].value.string_val)); }
#line 1278 "DynareBison.cc" // lalr1.cc:859
    break;

  case 206:
#line 551 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.periods((yystack_[1].value.string_val)); }
#line 1284 "DynareBison.cc" // lalr1.cc:859
    break;

  case 207:
#line 553 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.periods((yystack_[1].value.string_val)); }
#line 1290 "DynareBison.cc" // lalr1.cc:859
    break;

  case 208:
#line 556 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.init_param((yystack_[3].value.string_val), (yystack_[1].value.node_val)); }
#line 1296 "DynareBison.cc" // lalr1.cc:859
    break;

  case 209:
#line 559 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = (yystack_[1].value.node_val);}
#line 1302 "DynareBison.cc" // lalr1.cc:859
    break;

  case 210:
#line 561 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_expression_variable((yystack_[0].value.string_val)); }
#line 1308 "DynareBison.cc" // lalr1.cc:859
    break;

  case 211:
#line 563 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_non_negative_constant((yystack_[0].value.string_val)); }
#line 1314 "DynareBison.cc" // lalr1.cc:859
    break;

  case 212:
#line 565 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_plus((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1320 "DynareBison.cc" // lalr1.cc:859
    break;

  case 213:
#line 567 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_minus((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1326 "DynareBison.cc" // lalr1.cc:859
    break;

  case 214:
#line 569 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_divide((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1332 "DynareBison.cc" // lalr1.cc:859
    break;

  case 215:
#line 571 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_times((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1338 "DynareBison.cc" // lalr1.cc:859
    break;

  case 216:
#line 573 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_power((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1344 "DynareBison.cc" // lalr1.cc:859
    break;

  case 217:
#line 575 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_less((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1350 "DynareBison.cc" // lalr1.cc:859
    break;

  case 218:
#line 577 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_greater((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1356 "DynareBison.cc" // lalr1.cc:859
    break;

  case 219:
#line 579 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_less_equal((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1362 "DynareBison.cc" // lalr1.cc:859
    break;

  case 220:
#line 581 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_greater_equal((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1368 "DynareBison.cc" // lalr1.cc:859
    break;

  case 221:
#line 583 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_equal_equal((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1374 "DynareBison.cc" // lalr1.cc:859
    break;

  case 222:
#line 585 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_different((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1380 "DynareBison.cc" // lalr1.cc:859
    break;

  case 223:
#line 587 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_uminus((yystack_[0].value.node_val)); }
#line 1386 "DynareBison.cc" // lalr1.cc:859
    break;

  case 224:
#line 589 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = (yystack_[0].value.node_val); }
#line 1392 "DynareBison.cc" // lalr1.cc:859
    break;

  case 225:
#line 591 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_exp((yystack_[1].value.node_val)); }
#line 1398 "DynareBison.cc" // lalr1.cc:859
    break;

  case 226:
#line 593 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_log((yystack_[1].value.node_val)); }
#line 1404 "DynareBison.cc" // lalr1.cc:859
    break;

  case 227:
#line 595 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_log((yystack_[1].value.node_val)); }
#line 1410 "DynareBison.cc" // lalr1.cc:859
    break;

  case 228:
#line 597 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_log10((yystack_[1].value.node_val)); }
#line 1416 "DynareBison.cc" // lalr1.cc:859
    break;

  case 229:
#line 599 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_sin((yystack_[1].value.node_val)); }
#line 1422 "DynareBison.cc" // lalr1.cc:859
    break;

  case 230:
#line 601 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_cos((yystack_[1].value.node_val)); }
#line 1428 "DynareBison.cc" // lalr1.cc:859
    break;

  case 231:
#line 603 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_tan((yystack_[1].value.node_val)); }
#line 1434 "DynareBison.cc" // lalr1.cc:859
    break;

  case 232:
#line 605 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_asin((yystack_[1].value.node_val)); }
#line 1440 "DynareBison.cc" // lalr1.cc:859
    break;

  case 233:
#line 607 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_acos((yystack_[1].value.node_val)); }
#line 1446 "DynareBison.cc" // lalr1.cc:859
    break;

  case 234:
#line 609 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_atan((yystack_[1].value.node_val)); }
#line 1452 "DynareBison.cc" // lalr1.cc:859
    break;

  case 235:
#line 611 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_sqrt((yystack_[1].value.node_val)); }
#line 1458 "DynareBison.cc" // lalr1.cc:859
    break;

  case 236:
#line 613 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_abs((yystack_[1].value.node_val)); }
#line 1464 "DynareBison.cc" // lalr1.cc:859
    break;

  case 237:
#line 615 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_sign((yystack_[1].value.node_val)); }
#line 1470 "DynareBison.cc" // lalr1.cc:859
    break;

  case 238:
#line 617 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_max((yystack_[3].value.node_val), (yystack_[1].value.node_val)); }
#line 1476 "DynareBison.cc" // lalr1.cc:859
    break;

  case 239:
#line 619 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_min((yystack_[3].value.node_val), (yystack_[1].value.node_val)); }
#line 1482 "DynareBison.cc" // lalr1.cc:859
    break;

  case 240:
#line 620 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.push_external_function_arg_vector_onto_stack(); }
#line 1488 "DynareBison.cc" // lalr1.cc:859
    break;

  case 241:
#line 621 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_model_var_or_external_function((yystack_[4].value.string_val), false); }
#line 1494 "DynareBison.cc" // lalr1.cc:859
    break;

  case 242:
#line 623 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_normcdf((yystack_[5].value.node_val), (yystack_[3].value.node_val), (yystack_[1].value.node_val)); }
#line 1500 "DynareBison.cc" // lalr1.cc:859
    break;

  case 243:
#line 625 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_normcdf((yystack_[1].value.node_val)); }
#line 1506 "DynareBison.cc" // lalr1.cc:859
    break;

  case 244:
#line 627 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_normpdf((yystack_[5].value.node_val), (yystack_[3].value.node_val), (yystack_[1].value.node_val)); }
#line 1512 "DynareBison.cc" // lalr1.cc:859
    break;

  case 245:
#line 629 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_normpdf((yystack_[1].value.node_val)); }
#line 1518 "DynareBison.cc" // lalr1.cc:859
    break;

  case 246:
#line 631 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_erf((yystack_[1].value.node_val)); }
#line 1524 "DynareBison.cc" // lalr1.cc:859
    break;

  case 247:
#line 633 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_nan_constant(); }
#line 1530 "DynareBison.cc" // lalr1.cc:859
    break;

  case 248:
#line 635 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_inf_constant(); }
#line 1536 "DynareBison.cc" // lalr1.cc:859
    break;

  case 249:
#line 639 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_external_function_arg((yystack_[0].value.node_val)); }
#line 1542 "DynareBison.cc" // lalr1.cc:859
    break;

  case 250:
#line 641 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_external_function_arg((yystack_[0].value.node_val)); }
#line 1548 "DynareBison.cc" // lalr1.cc:859
    break;

  case 251:
#line 644 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {(yylhs.value.node_val) = driver.add_nan_constant();}
#line 1554 "DynareBison.cc" // lalr1.cc:859
    break;

  case 253:
#line 649 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.end_initval(false); }
#line 1560 "DynareBison.cc" // lalr1.cc:859
    break;

  case 254:
#line 651 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.end_initval(true); }
#line 1566 "DynareBison.cc" // lalr1.cc:859
    break;

  case 255:
#line 655 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.initval_file((yystack_[2].value.string_val)); }
#line 1572 "DynareBison.cc" // lalr1.cc:859
    break;

  case 256:
#line 659 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.end_endval(false); }
#line 1578 "DynareBison.cc" // lalr1.cc:859
    break;

  case 257:
#line 661 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.end_endval(true); }
#line 1584 "DynareBison.cc" // lalr1.cc:859
    break;

  case 260:
#line 668 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.init_val((yystack_[3].value.string_val), (yystack_[1].value.node_val)); }
#line 1590 "DynareBison.cc" // lalr1.cc:859
    break;

  case 261:
#line 671 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.end_histval(false); }
#line 1596 "DynareBison.cc" // lalr1.cc:859
    break;

  case 262:
#line 673 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.end_histval(true); }
#line 1602 "DynareBison.cc" // lalr1.cc:859
    break;

  case 265:
#line 680 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.hist_val((yystack_[6].value.string_val), (yystack_[4].value.string_val), (yystack_[1].value.node_val)); }
#line 1608 "DynareBison.cc" // lalr1.cc:859
    break;

  case 266:
#line 683 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.histval_file((yystack_[2].value.string_val)); }
#line 1614 "DynareBison.cc" // lalr1.cc:859
    break;

  case 267:
#line 686 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.block(); }
#line 1620 "DynareBison.cc" // lalr1.cc:859
    break;

  case 270:
#line 689 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.byte_code(); }
#line 1626 "DynareBison.cc" // lalr1.cc:859
    break;

  case 271:
#line 690 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.use_dll(); }
#line 1632 "DynareBison.cc" // lalr1.cc:859
    break;

  case 272:
#line 691 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.no_static();}
#line 1638 "DynareBison.cc" // lalr1.cc:859
    break;

  case 273:
#line 692 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.differentiate_forward_vars_all(); }
#line 1644 "DynareBison.cc" // lalr1.cc:859
    break;

  case 274:
#line 693 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.differentiate_forward_vars_some(); }
#line 1650 "DynareBison.cc" // lalr1.cc:859
    break;

  case 279:
#line 702 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.begin_model(); }
#line 1656 "DynareBison.cc" // lalr1.cc:859
    break;

  case 280:
#line 703 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.end_model(); }
#line 1662 "DynareBison.cc" // lalr1.cc:859
    break;

  case 281:
#line 704 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.begin_model(); }
#line 1668 "DynareBison.cc" // lalr1.cc:859
    break;

  case 282:
#line 705 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.end_model(); }
#line 1674 "DynareBison.cc" // lalr1.cc:859
    break;

  case 287:
#line 715 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_model_equal((yystack_[3].value.node_val), (yystack_[1].value.node_val)); }
#line 1680 "DynareBison.cc" // lalr1.cc:859
    break;

  case 288:
#line 717 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_model_equal_with_zero_rhs((yystack_[1].value.node_val)); }
#line 1686 "DynareBison.cc" // lalr1.cc:859
    break;

  case 289:
#line 719 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_model_equal((yystack_[3].value.node_val), (yystack_[1].value.node_val)); }
#line 1692 "DynareBison.cc" // lalr1.cc:859
    break;

  case 290:
#line 721 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_model_equal_with_zero_rhs((yystack_[1].value.node_val)); }
#line 1698 "DynareBison.cc" // lalr1.cc:859
    break;

  case 293:
#line 729 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_equation_tags((yystack_[2].value.string_val), (yystack_[0].value.string_val)); }
#line 1704 "DynareBison.cc" // lalr1.cc:859
    break;

  case 294:
#line 731 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_equation_tags((yystack_[0].value.string_val), new string()); }
#line 1710 "DynareBison.cc" // lalr1.cc:859
    break;

  case 295:
#line 735 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = (yystack_[1].value.node_val);}
#line 1716 "DynareBison.cc" // lalr1.cc:859
    break;

  case 296:
#line 737 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_model_variable((yystack_[0].value.string_val)); }
#line 1722 "DynareBison.cc" // lalr1.cc:859
    break;

  case 297:
#line 739 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_non_negative_constant((yystack_[0].value.string_val)); }
#line 1728 "DynareBison.cc" // lalr1.cc:859
    break;

  case 298:
#line 741 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_plus((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1734 "DynareBison.cc" // lalr1.cc:859
    break;

  case 299:
#line 743 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_minus((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1740 "DynareBison.cc" // lalr1.cc:859
    break;

  case 300:
#line 745 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_divide((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1746 "DynareBison.cc" // lalr1.cc:859
    break;

  case 301:
#line 747 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_times((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1752 "DynareBison.cc" // lalr1.cc:859
    break;

  case 302:
#line 749 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_less((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1758 "DynareBison.cc" // lalr1.cc:859
    break;

  case 303:
#line 751 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_greater((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1764 "DynareBison.cc" // lalr1.cc:859
    break;

  case 304:
#line 753 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_less_equal((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1770 "DynareBison.cc" // lalr1.cc:859
    break;

  case 305:
#line 755 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_greater_equal((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1776 "DynareBison.cc" // lalr1.cc:859
    break;

  case 306:
#line 757 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_equal_equal((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1782 "DynareBison.cc" // lalr1.cc:859
    break;

  case 307:
#line 759 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_different((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1788 "DynareBison.cc" // lalr1.cc:859
    break;

  case 308:
#line 761 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_power((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1794 "DynareBison.cc" // lalr1.cc:859
    break;

  case 309:
#line 763 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_expectation((yystack_[4].value.string_val), (yystack_[1].value.node_val)); }
#line 1800 "DynareBison.cc" // lalr1.cc:859
    break;

  case 310:
#line 765 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_uminus((yystack_[0].value.node_val)); }
#line 1806 "DynareBison.cc" // lalr1.cc:859
    break;

  case 311:
#line 767 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = (yystack_[0].value.node_val); }
#line 1812 "DynareBison.cc" // lalr1.cc:859
    break;

  case 312:
#line 769 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_exp((yystack_[1].value.node_val)); }
#line 1818 "DynareBison.cc" // lalr1.cc:859
    break;

  case 313:
#line 771 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_log((yystack_[1].value.node_val)); }
#line 1824 "DynareBison.cc" // lalr1.cc:859
    break;

  case 314:
#line 773 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_log((yystack_[1].value.node_val)); }
#line 1830 "DynareBison.cc" // lalr1.cc:859
    break;

  case 315:
#line 775 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_log10((yystack_[1].value.node_val)); }
#line 1836 "DynareBison.cc" // lalr1.cc:859
    break;

  case 316:
#line 777 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_sin((yystack_[1].value.node_val)); }
#line 1842 "DynareBison.cc" // lalr1.cc:859
    break;

  case 317:
#line 779 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_cos((yystack_[1].value.node_val)); }
#line 1848 "DynareBison.cc" // lalr1.cc:859
    break;

  case 318:
#line 781 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_tan((yystack_[1].value.node_val)); }
#line 1854 "DynareBison.cc" // lalr1.cc:859
    break;

  case 319:
#line 783 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_asin((yystack_[1].value.node_val)); }
#line 1860 "DynareBison.cc" // lalr1.cc:859
    break;

  case 320:
#line 785 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_acos((yystack_[1].value.node_val)); }
#line 1866 "DynareBison.cc" // lalr1.cc:859
    break;

  case 321:
#line 787 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_atan((yystack_[1].value.node_val)); }
#line 1872 "DynareBison.cc" // lalr1.cc:859
    break;

  case 322:
#line 789 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_sqrt((yystack_[1].value.node_val)); }
#line 1878 "DynareBison.cc" // lalr1.cc:859
    break;

  case 323:
#line 791 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_abs((yystack_[1].value.node_val)); }
#line 1884 "DynareBison.cc" // lalr1.cc:859
    break;

  case 324:
#line 793 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_sign((yystack_[1].value.node_val)); }
#line 1890 "DynareBison.cc" // lalr1.cc:859
    break;

  case 325:
#line 795 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_max((yystack_[3].value.node_val), (yystack_[1].value.node_val)); }
#line 1896 "DynareBison.cc" // lalr1.cc:859
    break;

  case 326:
#line 797 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_min((yystack_[3].value.node_val), (yystack_[1].value.node_val)); }
#line 1902 "DynareBison.cc" // lalr1.cc:859
    break;

  case 327:
#line 798 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.push_external_function_arg_vector_onto_stack(); }
#line 1908 "DynareBison.cc" // lalr1.cc:859
    break;

  case 328:
#line 799 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_model_var_or_external_function((yystack_[4].value.string_val), true); }
#line 1914 "DynareBison.cc" // lalr1.cc:859
    break;

  case 329:
#line 801 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_normcdf((yystack_[5].value.node_val), (yystack_[3].value.node_val), (yystack_[1].value.node_val)); }
#line 1920 "DynareBison.cc" // lalr1.cc:859
    break;

  case 330:
#line 803 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_normcdf((yystack_[1].value.node_val)); }
#line 1926 "DynareBison.cc" // lalr1.cc:859
    break;

  case 331:
#line 805 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_normpdf((yystack_[5].value.node_val), (yystack_[3].value.node_val), (yystack_[1].value.node_val)); }
#line 1932 "DynareBison.cc" // lalr1.cc:859
    break;

  case 332:
#line 807 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_normpdf((yystack_[1].value.node_val)); }
#line 1938 "DynareBison.cc" // lalr1.cc:859
    break;

  case 333:
#line 809 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_erf((yystack_[1].value.node_val)); }
#line 1944 "DynareBison.cc" // lalr1.cc:859
    break;

  case 334:
#line 811 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_steady_state((yystack_[1].value.node_val)); }
#line 1950 "DynareBison.cc" // lalr1.cc:859
    break;

  case 335:
#line 815 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_external_function_arg((yystack_[0].value.node_val)); }
#line 1956 "DynareBison.cc" // lalr1.cc:859
    break;

  case 336:
#line 817 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_external_function_arg((yystack_[0].value.node_val)); }
#line 1962 "DynareBison.cc" // lalr1.cc:859
    break;

  case 337:
#line 821 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_and_init_model_local_variable((yystack_[3].value.string_val), (yystack_[1].value.node_val)); }
#line 1968 "DynareBison.cc" // lalr1.cc:859
    break;

  case 338:
#line 823 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.end_shocks(false); }
#line 1974 "DynareBison.cc" // lalr1.cc:859
    break;

  case 339:
#line 824 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.end_shocks(true); }
#line 1980 "DynareBison.cc" // lalr1.cc:859
    break;

  case 343:
#line 833 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_stderr_shock((yystack_[4].value.string_val), (yystack_[1].value.node_val)); }
#line 1986 "DynareBison.cc" // lalr1.cc:859
    break;

  case 344:
#line 835 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_var_shock((yystack_[3].value.string_val), (yystack_[1].value.node_val)); }
#line 1992 "DynareBison.cc" // lalr1.cc:859
    break;

  case 345:
#line 837 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_covar_shock((yystack_[5].value.string_val), (yystack_[3].value.string_val), (yystack_[1].value.node_val)); }
#line 1998 "DynareBison.cc" // lalr1.cc:859
    break;

  case 346:
#line 839 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_correl_shock((yystack_[5].value.string_val), (yystack_[3].value.string_val), (yystack_[1].value.node_val)); }
#line 2004 "DynareBison.cc" // lalr1.cc:859
    break;

  case 347:
#line 843 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_det_shock((yystack_[7].value.string_val), false); }
#line 2010 "DynareBison.cc" // lalr1.cc:859
    break;

  case 348:
#line 846 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.begin_svar_identification();}
#line 2016 "DynareBison.cc" // lalr1.cc:859
    break;

  case 349:
#line 847 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.end_svar_identification(); }
#line 2022 "DynareBison.cc" // lalr1.cc:859
    break;

  case 352:
#line 855 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.combine_lag_and_restriction((yystack_[2].value.string_val)); }
#line 2028 "DynareBison.cc" // lalr1.cc:859
    break;

  case 353:
#line 857 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_constants_exclusion(); }
#line 2034 "DynareBison.cc" // lalr1.cc:859
    break;

  case 354:
#line 859 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_restriction_equation_nbr((yystack_[1].value.string_val));}
#line 2040 "DynareBison.cc" // lalr1.cc:859
    break;

  case 355:
#line 861 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.add_restriction_equal();}
#line 2046 "DynareBison.cc" // lalr1.cc:859
    break;

  case 357:
#line 864 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_upper_cholesky(); }
#line 2052 "DynareBison.cc" // lalr1.cc:859
    break;

  case 358:
#line 866 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_lower_cholesky(); }
#line 2058 "DynareBison.cc" // lalr1.cc:859
    break;

  case 359:
#line 870 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_restriction_in_equation((yystack_[3].value.string_val)); }
#line 2064 "DynareBison.cc" // lalr1.cc:859
    break;

  case 360:
#line 872 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_restriction_in_equation((yystack_[3].value.string_val)); }
#line 2070 "DynareBison.cc" // lalr1.cc:859
    break;

  case 361:
#line 876 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_in_svar_restriction_symbols((yystack_[0].value.string_val)); }
#line 2076 "DynareBison.cc" // lalr1.cc:859
    break;

  case 362:
#line 878 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_in_svar_restriction_symbols((yystack_[0].value.string_val)); }
#line 2082 "DynareBison.cc" // lalr1.cc:859
    break;

  case 363:
#line 881 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.check_restriction_expression_constant((yystack_[0].value.node_val));}
#line 2088 "DynareBison.cc" // lalr1.cc:859
    break;

  case 367:
#line 890 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_positive_restriction_element((yystack_[3].value.string_val),(yystack_[1].value.string_val));}
#line 2094 "DynareBison.cc" // lalr1.cc:859
    break;

  case 368:
#line 892 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_positive_restriction_element((yystack_[3].value.string_val),(yystack_[1].value.string_val));}
#line 2100 "DynareBison.cc" // lalr1.cc:859
    break;

  case 369:
#line 894 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_negative_restriction_element((yystack_[3].value.string_val),(yystack_[1].value.string_val));}
#line 2106 "DynareBison.cc" // lalr1.cc:859
    break;

  case 370:
#line 896 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_positive_restriction_element((yystack_[7].value.node_val),(yystack_[3].value.string_val),(yystack_[1].value.string_val));}
#line 2112 "DynareBison.cc" // lalr1.cc:859
    break;

  case 371:
#line 900 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_svar_global_identification_check(); }
#line 2118 "DynareBison.cc" // lalr1.cc:859
    break;

  case 372:
#line 904 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.markov_switching(); }
#line 2124 "DynareBison.cc" // lalr1.cc:859
    break;

  case 381:
#line 920 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.svar(); }
#line 2130 "DynareBison.cc" // lalr1.cc:859
    break;

  case 388:
#line 933 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.end_mshocks(false); }
#line 2136 "DynareBison.cc" // lalr1.cc:859
    break;

  case 389:
#line 934 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.end_mshocks(true); }
#line 2142 "DynareBison.cc" // lalr1.cc:859
    break;

  case 392:
#line 942 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_period((yystack_[0].value.string_val)); }
#line 2148 "DynareBison.cc" // lalr1.cc:859
    break;

  case 393:
#line 944 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_period((yystack_[0].value.string_val)); }
#line 2154 "DynareBison.cc" // lalr1.cc:859
    break;

  case 394:
#line 946 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_period((yystack_[2].value.string_val), (yystack_[0].value.string_val)); }
#line 2160 "DynareBison.cc" // lalr1.cc:859
    break;

  case 395:
#line 948 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_period((yystack_[2].value.string_val), (yystack_[0].value.string_val)); }
#line 2166 "DynareBison.cc" // lalr1.cc:859
    break;

  case 396:
#line 950 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_period((yystack_[2].value.string_val), (yystack_[0].value.string_val)); }
#line 2172 "DynareBison.cc" // lalr1.cc:859
    break;

  case 397:
#line 952 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_period((yystack_[0].value.string_val)); }
#line 2178 "DynareBison.cc" // lalr1.cc:859
    break;

  case 398:
#line 955 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.do_sigma_e(); }
#line 2184 "DynareBison.cc" // lalr1.cc:859
    break;

  case 399:
#line 958 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_value((yystack_[1].value.node_val)); }
#line 2190 "DynareBison.cc" // lalr1.cc:859
    break;

  case 400:
#line 960 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_value((yystack_[1].value.node_val)); }
#line 2196 "DynareBison.cc" // lalr1.cc:859
    break;

  case 401:
#line 962 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_value((yystack_[1].value.node_val)); }
#line 2202 "DynareBison.cc" // lalr1.cc:859
    break;

  case 402:
#line 964 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_value((yystack_[0].value.string_val)); }
#line 2208 "DynareBison.cc" // lalr1.cc:859
    break;

  case 403:
#line 966 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_value((yystack_[0].value.string_val)); }
#line 2214 "DynareBison.cc" // lalr1.cc:859
    break;

  case 404:
#line 968 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_value((yystack_[0].value.string_val)); }
#line 2220 "DynareBison.cc" // lalr1.cc:859
    break;

  case 405:
#line 972 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.end_of_row(); }
#line 2226 "DynareBison.cc" // lalr1.cc:859
    break;

  case 406:
#line 974 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.end_of_row(); }
#line 2232 "DynareBison.cc" // lalr1.cc:859
    break;

  case 407:
#line 978 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_to_row((yystack_[1].value.node_val)); }
#line 2238 "DynareBison.cc" // lalr1.cc:859
    break;

  case 408:
#line 980 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_to_row_const((yystack_[0].value.string_val)); }
#line 2244 "DynareBison.cc" // lalr1.cc:859
    break;

  case 409:
#line 982 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_to_row((yystack_[1].value.node_val)); }
#line 2250 "DynareBison.cc" // lalr1.cc:859
    break;

  case 410:
#line 984 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_to_row_const((yystack_[0].value.string_val)); }
#line 2256 "DynareBison.cc" // lalr1.cc:859
    break;

  case 411:
#line 986 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_to_row((yystack_[1].value.node_val)); }
#line 2262 "DynareBison.cc" // lalr1.cc:859
    break;

  case 412:
#line 988 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_to_row_const((yystack_[0].value.string_val)); }
#line 2268 "DynareBison.cc" // lalr1.cc:859
    break;

  case 413:
#line 992 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.steady(); }
#line 2274 "DynareBison.cc" // lalr1.cc:859
    break;

  case 414:
#line 994 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.steady(); }
#line 2280 "DynareBison.cc" // lalr1.cc:859
    break;

  case 425:
#line 1012 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.check(); }
#line 2286 "DynareBison.cc" // lalr1.cc:859
    break;

  case 426:
#line 1014 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.check(); }
#line 2292 "DynareBison.cc" // lalr1.cc:859
    break;

  case 431:
#line 1026 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.model_info(); }
#line 2298 "DynareBison.cc" // lalr1.cc:859
    break;

  case 432:
#line 1028 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.model_info(); }
#line 2304 "DynareBison.cc" // lalr1.cc:859
    break;

  case 436:
#line 1037 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.perfect_foresight_setup(); }
#line 2310 "DynareBison.cc" // lalr1.cc:859
    break;

  case 437:
#line 1039 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.perfect_foresight_setup(); }
#line 2316 "DynareBison.cc" // lalr1.cc:859
    break;

  case 442:
#line 1051 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.perfect_foresight_solver(); }
#line 2322 "DynareBison.cc" // lalr1.cc:859
    break;

  case 443:
#line 1053 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.perfect_foresight_solver(); }
#line 2328 "DynareBison.cc" // lalr1.cc:859
    break;

  case 458:
#line 1075 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.prior_posterior_function(true); }
#line 2334 "DynareBison.cc" // lalr1.cc:859
    break;

  case 459:
#line 1079 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.prior_posterior_function(false); }
#line 2340 "DynareBison.cc" // lalr1.cc:859
    break;

  case 464:
#line 1091 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.simul(); }
#line 2346 "DynareBison.cc" // lalr1.cc:859
    break;

  case 465:
#line 1093 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.simul(); }
#line 2352 "DynareBison.cc" // lalr1.cc:859
    break;

  case 470:
#line 1105 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.external_function(); }
#line 2358 "DynareBison.cc" // lalr1.cc:859
    break;

  case 477:
#line 1119 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.stoch_simul(); }
#line 2364 "DynareBison.cc" // lalr1.cc:859
    break;

  case 478:
#line 1121 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.stoch_simul(); }
#line 2370 "DynareBison.cc" // lalr1.cc:859
    break;

  case 479:
#line 1123 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.stoch_simul(); }
#line 2376 "DynareBison.cc" // lalr1.cc:859
    break;

  case 480:
#line 1125 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.stoch_simul(); }
#line 2382 "DynareBison.cc" // lalr1.cc:859
    break;

  case 531:
#line 1185 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_in_symbol_list((yystack_[0].value.string_val)); }
#line 2388 "DynareBison.cc" // lalr1.cc:859
    break;

  case 532:
#line 1187 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_in_symbol_list((yystack_[0].value.string_val)); }
#line 2394 "DynareBison.cc" // lalr1.cc:859
    break;

  case 533:
#line 1189 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_in_symbol_list((yystack_[0].value.string_val)); }
#line 2400 "DynareBison.cc" // lalr1.cc:859
    break;

  case 535:
#line 1194 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                    string *colon = new string(":");
                    driver.add_in_symbol_list(colon);
                  }
#line 2409 "DynareBison.cc" // lalr1.cc:859
    break;

  case 536:
#line 1201 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 2415 "DynareBison.cc" // lalr1.cc:859
    break;

  case 537:
#line 1203 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yystack_[0].value.string_val)->insert(0, "-"); (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 2421 "DynareBison.cc" // lalr1.cc:859
    break;

  case 541:
#line 1212 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 2427 "DynareBison.cc" // lalr1.cc:859
    break;

  case 542:
#line 1214 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yystack_[0].value.string_val)->insert(0, "-"); (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 2433 "DynareBison.cc" // lalr1.cc:859
    break;

  case 544:
#line 1219 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.string_val) = new string ("Inf"); }
#line 2439 "DynareBison.cc" // lalr1.cc:859
    break;

  case 545:
#line 1221 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.string_val) = new string ("-Inf"); }
#line 2445 "DynareBison.cc" // lalr1.cc:859
    break;

  case 546:
#line 1223 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.string_val) = new string ("Inf"); }
#line 2451 "DynareBison.cc" // lalr1.cc:859
    break;

  case 549:
#line 1230 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.estimated_params(); }
#line 2457 "DynareBison.cc" // lalr1.cc:859
    break;

  case 550:
#line 1233 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_estimated_params_element(); }
#line 2463 "DynareBison.cc" // lalr1.cc:859
    break;

  case 551:
#line 1235 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_estimated_params_element(); }
#line 2469 "DynareBison.cc" // lalr1.cc:859
    break;

  case 554:
#line 1242 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                    driver.estim_params.type = 1;
                    driver.estim_params.name = *(yystack_[0].value.string_val);
                    delete (yystack_[0].value.string_val);
                  }
#line 2479 "DynareBison.cc" // lalr1.cc:859
    break;

  case 555:
#line 1248 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                    driver.estim_params.type = 2;
                    driver.estim_params.name = *(yystack_[0].value.string_val);
                    delete (yystack_[0].value.string_val);
                  }
#line 2489 "DynareBison.cc" // lalr1.cc:859
    break;

  case 556:
#line 1254 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                    driver.estim_params.type = 3;
                    driver.estim_params.name = *(yystack_[2].value.string_val);
                    driver.estim_params.name2 = *(yystack_[0].value.string_val);
                    delete (yystack_[2].value.string_val);
                    delete (yystack_[0].value.string_val);
                  }
#line 2501 "DynareBison.cc" // lalr1.cc:859
    break;

  case 557:
#line 1262 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                    driver.estim_params.type = 2;
                    driver.estim_params.name = "dsge_prior_weight";
                  }
#line 2510 "DynareBison.cc" // lalr1.cc:859
    break;

  case 558:
#line 1269 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                    driver.estim_params.prior = (yystack_[2].value.prior_distributions_val);
                  }
#line 2518 "DynareBison.cc" // lalr1.cc:859
    break;

  case 559:
#line 1273 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                    driver.estim_params.init_val = (yystack_[4].value.node_val);
                    driver.estim_params.prior = (yystack_[2].value.prior_distributions_val);
                  }
#line 2527 "DynareBison.cc" // lalr1.cc:859
    break;

  case 560:
#line 1278 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                    driver.estim_params.init_val = (yystack_[8].value.node_val);
                    driver.estim_params.low_bound = (yystack_[6].value.node_val);
                    driver.estim_params.up_bound = (yystack_[4].value.node_val);
                    driver.estim_params.prior = (yystack_[2].value.prior_distributions_val);
                  }
#line 2538 "DynareBison.cc" // lalr1.cc:859
    break;

  case 561:
#line 1285 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                    driver.estim_params.init_val = (yystack_[0].value.node_val);
                  }
#line 2546 "DynareBison.cc" // lalr1.cc:859
    break;

  case 562:
#line 1289 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                    driver.estim_params.init_val = (yystack_[4].value.node_val);
                    driver.estim_params.low_bound = (yystack_[2].value.node_val);
                    driver.estim_params.up_bound = (yystack_[0].value.node_val);
                  }
#line 2556 "DynareBison.cc" // lalr1.cc:859
    break;

  case 563:
#line 1297 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                    driver.estim_params.mean = (yystack_[2].value.node_val);
                    driver.estim_params.std = (yystack_[0].value.node_val);
                  }
#line 2565 "DynareBison.cc" // lalr1.cc:859
    break;

  case 564:
#line 1302 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                    driver.estim_params.mean = (yystack_[4].value.node_val);
                    driver.estim_params.std = (yystack_[2].value.node_val);
                    driver.estim_params.p3 = (yystack_[0].value.node_val);
                  }
#line 2575 "DynareBison.cc" // lalr1.cc:859
    break;

  case 565:
#line 1308 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                    driver.estim_params.mean = (yystack_[6].value.node_val);
                    driver.estim_params.std = (yystack_[4].value.node_val);
                    driver.estim_params.p3 = (yystack_[2].value.node_val);
                    driver.estim_params.p4 = (yystack_[0].value.node_val);
                  }
#line 2586 "DynareBison.cc" // lalr1.cc:859
    break;

  case 566:
#line 1315 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                    driver.estim_params.mean = (yystack_[8].value.node_val);
                    driver.estim_params.std = (yystack_[6].value.node_val);
                    driver.estim_params.p3 = (yystack_[4].value.node_val);
                    driver.estim_params.p4 = (yystack_[2].value.node_val);
                    driver.estim_params.jscale = (yystack_[0].value.node_val);
                  }
#line 2598 "DynareBison.cc" // lalr1.cc:859
    break;

  case 567:
#line 1325 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.estimated_params_init(); }
#line 2604 "DynareBison.cc" // lalr1.cc:859
    break;

  case 568:
#line 1327 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.estimated_params_init(true); }
#line 2610 "DynareBison.cc" // lalr1.cc:859
    break;

  case 569:
#line 1329 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.estimated_params_init(true); }
#line 2616 "DynareBison.cc" // lalr1.cc:859
    break;

  case 570:
#line 1333 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_estimated_params_element(); }
#line 2622 "DynareBison.cc" // lalr1.cc:859
    break;

  case 571:
#line 1335 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_estimated_params_element(); }
#line 2628 "DynareBison.cc" // lalr1.cc:859
    break;

  case 572:
#line 1339 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                        driver.estim_params.type = 1;
                        driver.estim_params.name = *(yystack_[3].value.string_val);
                        driver.estim_params.init_val = (yystack_[1].value.node_val);
                        delete (yystack_[3].value.string_val);
                      }
#line 2639 "DynareBison.cc" // lalr1.cc:859
    break;

  case 573:
#line 1346 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                        driver.estim_params.type = 3;
                        driver.estim_params.name = *(yystack_[5].value.string_val);
                        driver.estim_params.name2 = *(yystack_[3].value.string_val);
                        driver.estim_params.init_val = (yystack_[1].value.node_val);
                        delete (yystack_[5].value.string_val);
                        delete (yystack_[3].value.string_val);
                      }
#line 2652 "DynareBison.cc" // lalr1.cc:859
    break;

  case 574:
#line 1355 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                        driver.estim_params.type = 2;
                        driver.estim_params.name = *(yystack_[3].value.string_val);
                        driver.estim_params.init_val = (yystack_[1].value.node_val);
                        delete (yystack_[3].value.string_val);
                      }
#line 2663 "DynareBison.cc" // lalr1.cc:859
    break;

  case 575:
#line 1364 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.estimated_params_bounds(); }
#line 2669 "DynareBison.cc" // lalr1.cc:859
    break;

  case 576:
#line 1367 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_estimated_params_element(); }
#line 2675 "DynareBison.cc" // lalr1.cc:859
    break;

  case 577:
#line 1369 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_estimated_params_element(); }
#line 2681 "DynareBison.cc" // lalr1.cc:859
    break;

  case 578:
#line 1373 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                          driver.estim_params.type = 1;
                          driver.estim_params.name = *(yystack_[5].value.string_val);
                          driver.estim_params.low_bound = (yystack_[3].value.node_val);
                          driver.estim_params.up_bound = (yystack_[1].value.node_val);
                          delete (yystack_[5].value.string_val);
                        }
#line 2693 "DynareBison.cc" // lalr1.cc:859
    break;

  case 579:
#line 1381 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                          driver.estim_params.type = 3;
                          driver.estim_params.name = *(yystack_[7].value.string_val);
                          driver.estim_params.name2 = *(yystack_[5].value.string_val);
                          driver.estim_params.low_bound = (yystack_[3].value.node_val);
                          driver.estim_params.up_bound = (yystack_[1].value.node_val);
                          delete (yystack_[7].value.string_val);
                          delete (yystack_[5].value.string_val);
                        }
#line 2707 "DynareBison.cc" // lalr1.cc:859
    break;

  case 580:
#line 1391 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                          driver.estim_params.type = 2;
                          driver.estim_params.name = *(yystack_[5].value.string_val);
                          driver.estim_params.low_bound = (yystack_[3].value.node_val);
                          driver.estim_params.up_bound = (yystack_[1].value.node_val);
                          delete (yystack_[5].value.string_val);
                        }
#line 2719 "DynareBison.cc" // lalr1.cc:859
    break;

  case 581:
#line 1401 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.osr_params_bounds(); }
#line 2725 "DynareBison.cc" // lalr1.cc:859
    break;

  case 582:
#line 1404 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_osr_params_element(); }
#line 2731 "DynareBison.cc" // lalr1.cc:859
    break;

  case 583:
#line 1406 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_osr_params_element(); }
#line 2737 "DynareBison.cc" // lalr1.cc:859
    break;

  case 584:
#line 1410 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                    driver.osr_params.name = *(yystack_[5].value.string_val);
                    driver.osr_params.low_bound = (yystack_[3].value.node_val);
                    driver.osr_params.up_bound = (yystack_[1].value.node_val);
                    delete (yystack_[5].value.string_val);
                  }
#line 2748 "DynareBison.cc" // lalr1.cc:859
    break;

  case 585:
#line 1419 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.prior_distributions_val) = eBeta; }
#line 2754 "DynareBison.cc" // lalr1.cc:859
    break;

  case 586:
#line 1421 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.prior_distributions_val) = eGamma; }
#line 2760 "DynareBison.cc" // lalr1.cc:859
    break;

  case 587:
#line 1423 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.prior_distributions_val) = eNormal; }
#line 2766 "DynareBison.cc" // lalr1.cc:859
    break;

  case 588:
#line 1425 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.prior_distributions_val) = eInvGamma; }
#line 2772 "DynareBison.cc" // lalr1.cc:859
    break;

  case 589:
#line 1427 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.prior_distributions_val) = eInvGamma1; }
#line 2778 "DynareBison.cc" // lalr1.cc:859
    break;

  case 590:
#line 1429 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.prior_distributions_val) = eUniform; }
#line 2784 "DynareBison.cc" // lalr1.cc:859
    break;

  case 591:
#line 1431 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.prior_distributions_val) = eInvGamma2; }
#line 2790 "DynareBison.cc" // lalr1.cc:859
    break;

  case 592:
#line 1433 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.prior_distributions_val) = eDirichlet; }
#line 2796 "DynareBison.cc" // lalr1.cc:859
    break;

  case 593:
#line 1435 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.prior_distributions_val) = eWeibull; }
#line 2802 "DynareBison.cc" // lalr1.cc:859
    break;

  case 594:
#line 1439 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.prior_distributions_val) = eBeta; }
#line 2808 "DynareBison.cc" // lalr1.cc:859
    break;

  case 595:
#line 1441 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.prior_distributions_val) = eGamma; }
#line 2814 "DynareBison.cc" // lalr1.cc:859
    break;

  case 596:
#line 1443 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.prior_distributions_val) = eNormal; }
#line 2820 "DynareBison.cc" // lalr1.cc:859
    break;

  case 597:
#line 1445 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.prior_distributions_val) = eInvGamma; }
#line 2826 "DynareBison.cc" // lalr1.cc:859
    break;

  case 598:
#line 1447 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.prior_distributions_val) = eInvGamma1; }
#line 2832 "DynareBison.cc" // lalr1.cc:859
    break;

  case 599:
#line 1449 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.prior_distributions_val) = eUniform; }
#line 2838 "DynareBison.cc" // lalr1.cc:859
    break;

  case 600:
#line 1451 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.prior_distributions_val) = eInvGamma2; }
#line 2844 "DynareBison.cc" // lalr1.cc:859
    break;

  case 601:
#line 1453 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.prior_distributions_val) = eWeibull; }
#line 2850 "DynareBison.cc" // lalr1.cc:859
    break;

  case 602:
#line 1456 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 2856 "DynareBison.cc" // lalr1.cc:859
    break;

  case 603:
#line 1459 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 2862 "DynareBison.cc" // lalr1.cc:859
    break;

  case 604:
#line 1461 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.string_val) = (yystack_[2].value.string_val); (yylhs.value.string_val)->append("+").append(*(yystack_[0].value.string_val)); }
#line 2868 "DynareBison.cc" // lalr1.cc:859
    break;

  case 605:
#line 1465 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_time((yystack_[2].value.string_val)); }
#line 2874 "DynareBison.cc" // lalr1.cc:859
    break;

  case 606:
#line 1469 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.estimation_data(); }
#line 2880 "DynareBison.cc" // lalr1.cc:859
    break;

  case 616:
#line 1486 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_subsamples((yystack_[4].value.vector_string_val)->at(0), (yystack_[4].value.vector_string_val)->at(1)); }
#line 2886 "DynareBison.cc" // lalr1.cc:859
    break;

  case 617:
#line 1490 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                  driver.copy_subsamples((yystack_[3].value.vector_string_val)->at(0), (yystack_[3].value.vector_string_val)->at(1), (yystack_[1].value.vector_string_val)->at(0), (yystack_[1].value.vector_string_val)->at(1));
                  delete (yystack_[3].value.vector_string_val);
                  delete (yystack_[1].value.vector_string_val);
                }
#line 2896 "DynareBison.cc" // lalr1.cc:859
    break;

  case 618:
#line 1498 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                      (yylhs.value.vector_string_val) = new vector<string *>();
                      (yylhs.value.vector_string_val)->push_back((yystack_[2].value.string_val));
                      (yylhs.value.vector_string_val)->push_back(new string (""));
                    }
#line 2906 "DynareBison.cc" // lalr1.cc:859
    break;

  case 619:
#line 1504 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                      (yylhs.value.vector_string_val) = new vector<string *>();
                      (yylhs.value.vector_string_val)->push_back((yystack_[3].value.string_val));
                      (yylhs.value.vector_string_val)->push_back(new string (""));
                    }
#line 2916 "DynareBison.cc" // lalr1.cc:859
    break;

  case 620:
#line 1510 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                      (yylhs.value.vector_string_val) = new vector<string *>();
                      (yylhs.value.vector_string_val)->push_back((yystack_[5].value.string_val));
                      (yylhs.value.vector_string_val)->push_back((yystack_[3].value.string_val));
                    }
#line 2926 "DynareBison.cc" // lalr1.cc:859
    break;

  case 623:
#line 1521 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_prior_variance(); driver.prior_shape = eNoShape; }
#line 2932 "DynareBison.cc" // lalr1.cc:859
    break;

  case 624:
#line 1522 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_prior((yystack_[7].value.string_val), new string ("")); }
#line 2938 "DynareBison.cc" // lalr1.cc:859
    break;

  case 625:
#line 1523 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_prior_variance(); driver.prior_shape = eNoShape; }
#line 2944 "DynareBison.cc" // lalr1.cc:859
    break;

  case 626:
#line 1524 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_prior((yystack_[9].value.string_val), (yystack_[7].value.string_val)); }
#line 2950 "DynareBison.cc" // lalr1.cc:859
    break;

  case 627:
#line 1525 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_prior_variance(); driver.prior_shape = eNoShape; }
#line 2956 "DynareBison.cc" // lalr1.cc:859
    break;

  case 628:
#line 1526 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_joint_prior((yystack_[7].value.vector_string_val)); }
#line 2962 "DynareBison.cc" // lalr1.cc:859
    break;

  case 629:
#line 1527 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_prior_variance(); driver.prior_shape = eNoShape; }
#line 2968 "DynareBison.cc" // lalr1.cc:859
    break;

  case 630:
#line 1528 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_std_prior((yystack_[8].value.string_val), new string ("")); }
#line 2974 "DynareBison.cc" // lalr1.cc:859
    break;

  case 631:
#line 1529 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_prior_variance(); driver.prior_shape = eNoShape; }
#line 2980 "DynareBison.cc" // lalr1.cc:859
    break;

  case 632:
#line 1530 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_std_prior((yystack_[10].value.string_val), (yystack_[7].value.string_val)); }
#line 2986 "DynareBison.cc" // lalr1.cc:859
    break;

  case 633:
#line 1531 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_prior_variance(); driver.prior_shape = eNoShape; }
#line 2992 "DynareBison.cc" // lalr1.cc:859
    break;

  case 634:
#line 1532 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_corr_prior((yystack_[10].value.string_val), (yystack_[8].value.string_val), new string ("")); }
#line 2998 "DynareBison.cc" // lalr1.cc:859
    break;

  case 635:
#line 1533 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_prior_variance(); driver.prior_shape = eNoShape; }
#line 3004 "DynareBison.cc" // lalr1.cc:859
    break;

  case 636:
#line 1534 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_corr_prior((yystack_[12].value.string_val), (yystack_[10].value.string_val), (yystack_[7].value.string_val)); }
#line 3010 "DynareBison.cc" // lalr1.cc:859
    break;

  case 661:
#line 1570 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
             driver.copy_prior((yystack_[3].value.vector_string_val)->at(0), (yystack_[3].value.vector_string_val)->at(1), (yystack_[3].value.vector_string_val)->at(2), (yystack_[3].value.vector_string_val)->at(3),
                               (yystack_[1].value.vector_string_val)->at(0), (yystack_[1].value.vector_string_val)->at(1), (yystack_[1].value.vector_string_val)->at(2), (yystack_[1].value.vector_string_val)->at(3));
             delete (yystack_[3].value.vector_string_val);
             delete (yystack_[1].value.vector_string_val);
           }
#line 3021 "DynareBison.cc" // lalr1.cc:859
    break;

  case 662:
#line 1579 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                 (yylhs.value.vector_string_val) = new vector<string *>();
                 (yylhs.value.vector_string_val)->push_back(new string ("par"));
                 (yylhs.value.vector_string_val)->push_back((yystack_[2].value.string_val));
                 (yylhs.value.vector_string_val)->push_back(new string (""));
                 (yylhs.value.vector_string_val)->push_back(new string (""));
               }
#line 3033 "DynareBison.cc" // lalr1.cc:859
    break;

  case 663:
#line 1587 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                 (yylhs.value.vector_string_val) = new vector<string *>();
                 (yylhs.value.vector_string_val)->push_back(new string ("par"));
                 (yylhs.value.vector_string_val)->push_back((yystack_[4].value.string_val));
                 (yylhs.value.vector_string_val)->push_back(new string (""));
                 (yylhs.value.vector_string_val)->push_back((yystack_[2].value.string_val));
               }
#line 3045 "DynareBison.cc" // lalr1.cc:859
    break;

  case 664:
#line 1595 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                 (yylhs.value.vector_string_val) = new vector<string *>();
                 (yylhs.value.vector_string_val)->push_back(new string ("std"));
                 (yylhs.value.vector_string_val)->push_back((yystack_[3].value.string_val));
                 (yylhs.value.vector_string_val)->push_back(new string (""));
                 (yylhs.value.vector_string_val)->push_back(new string (""));
               }
#line 3057 "DynareBison.cc" // lalr1.cc:859
    break;

  case 665:
#line 1603 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                 (yylhs.value.vector_string_val) = new vector<string *>();
                 (yylhs.value.vector_string_val)->push_back(new string ("std"));
                 (yylhs.value.vector_string_val)->push_back((yystack_[5].value.string_val));
                 (yylhs.value.vector_string_val)->push_back(new string (""));
                 (yylhs.value.vector_string_val)->push_back((yystack_[2].value.string_val));
               }
#line 3069 "DynareBison.cc" // lalr1.cc:859
    break;

  case 666:
#line 1611 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                 (yylhs.value.vector_string_val) = new vector<string *>();
                 (yylhs.value.vector_string_val)->push_back(new string ("corr"));
                 (yylhs.value.vector_string_val)->push_back((yystack_[5].value.string_val));
                 (yylhs.value.vector_string_val)->push_back((yystack_[3].value.string_val));
                 (yylhs.value.vector_string_val)->push_back(new string (""));
               }
#line 3081 "DynareBison.cc" // lalr1.cc:859
    break;

  case 667:
#line 1619 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                 (yylhs.value.vector_string_val) = new vector<string *>();
                 (yylhs.value.vector_string_val)->push_back(new string ("corr"));
                 (yylhs.value.vector_string_val)->push_back((yystack_[7].value.string_val));
                 (yylhs.value.vector_string_val)->push_back((yystack_[5].value.string_val));
                 (yylhs.value.vector_string_val)->push_back((yystack_[2].value.string_val));
               }
#line 3093 "DynareBison.cc" // lalr1.cc:859
    break;

  case 668:
#line 1629 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_options((yystack_[6].value.string_val), new string ("")); }
#line 3099 "DynareBison.cc" // lalr1.cc:859
    break;

  case 669:
#line 1631 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_options((yystack_[8].value.string_val), (yystack_[6].value.string_val)); }
#line 3105 "DynareBison.cc" // lalr1.cc:859
    break;

  case 670:
#line 1633 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_std_options((yystack_[7].value.string_val), new string ("")); }
#line 3111 "DynareBison.cc" // lalr1.cc:859
    break;

  case 671:
#line 1635 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_std_options((yystack_[9].value.string_val), (yystack_[6].value.string_val)); }
#line 3117 "DynareBison.cc" // lalr1.cc:859
    break;

  case 672:
#line 1637 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_corr_options((yystack_[9].value.string_val), (yystack_[7].value.string_val), new string ("")); }
#line 3123 "DynareBison.cc" // lalr1.cc:859
    break;

  case 673:
#line 1639 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_corr_options((yystack_[11].value.string_val), (yystack_[9].value.string_val), (yystack_[6].value.string_val)); }
#line 3129 "DynareBison.cc" // lalr1.cc:859
    break;

  case 679:
#line 1652 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
               driver.copy_options((yystack_[3].value.vector_string_val)->at(0), (yystack_[3].value.vector_string_val)->at(1), (yystack_[3].value.vector_string_val)->at(2), (yystack_[3].value.vector_string_val)->at(3),
                                   (yystack_[1].value.vector_string_val)->at(0), (yystack_[1].value.vector_string_val)->at(1), (yystack_[1].value.vector_string_val)->at(2), (yystack_[1].value.vector_string_val)->at(3));
               delete (yystack_[3].value.vector_string_val);
               delete (yystack_[1].value.vector_string_val);
             }
#line 3140 "DynareBison.cc" // lalr1.cc:859
    break;

  case 680:
#line 1661 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                   (yylhs.value.vector_string_val) = new vector<string *>();
                   (yylhs.value.vector_string_val)->push_back(new string ("par"));
                   (yylhs.value.vector_string_val)->push_back((yystack_[2].value.string_val));
                   (yylhs.value.vector_string_val)->push_back(new string (""));
                   (yylhs.value.vector_string_val)->push_back(new string (""));
                 }
#line 3152 "DynareBison.cc" // lalr1.cc:859
    break;

  case 681:
#line 1669 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                   (yylhs.value.vector_string_val) = new vector<string *>();
                   (yylhs.value.vector_string_val)->push_back(new string ("par"));
                   (yylhs.value.vector_string_val)->push_back((yystack_[4].value.string_val));
                   (yylhs.value.vector_string_val)->push_back(new string (""));
                   (yylhs.value.vector_string_val)->push_back((yystack_[2].value.string_val));
                 }
#line 3164 "DynareBison.cc" // lalr1.cc:859
    break;

  case 682:
#line 1677 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                   (yylhs.value.vector_string_val) = new vector<string *>();
                   (yylhs.value.vector_string_val)->push_back(new string ("std"));
                   (yylhs.value.vector_string_val)->push_back((yystack_[3].value.string_val));
                   (yylhs.value.vector_string_val)->push_back(new string (""));
                   (yylhs.value.vector_string_val)->push_back(new string (""));
                 }
#line 3176 "DynareBison.cc" // lalr1.cc:859
    break;

  case 683:
#line 1685 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                   (yylhs.value.vector_string_val) = new vector<string *>();
                   (yylhs.value.vector_string_val)->push_back(new string ("std"));
                   (yylhs.value.vector_string_val)->push_back((yystack_[5].value.string_val));
                   (yylhs.value.vector_string_val)->push_back(new string (""));
                   (yylhs.value.vector_string_val)->push_back((yystack_[2].value.string_val));
                 }
#line 3188 "DynareBison.cc" // lalr1.cc:859
    break;

  case 684:
#line 1693 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                   (yylhs.value.vector_string_val) = new vector<string *>();
                   (yylhs.value.vector_string_val)->push_back(new string ("corr"));
                   (yylhs.value.vector_string_val)->push_back((yystack_[5].value.string_val));
                   (yylhs.value.vector_string_val)->push_back((yystack_[3].value.string_val));
                   (yylhs.value.vector_string_val)->push_back(new string (""));
                 }
#line 3200 "DynareBison.cc" // lalr1.cc:859
    break;

  case 685:
#line 1701 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                   (yylhs.value.vector_string_val) = new vector<string *>();
                   (yylhs.value.vector_string_val)->push_back(new string ("corr"));
                   (yylhs.value.vector_string_val)->push_back((yystack_[7].value.string_val));
                   (yylhs.value.vector_string_val)->push_back((yystack_[5].value.string_val));
                   (yylhs.value.vector_string_val)->push_back((yystack_[2].value.string_val));
                 }
#line 3212 "DynareBison.cc" // lalr1.cc:859
    break;

  case 686:
#line 1711 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.run_estimation(); }
#line 3218 "DynareBison.cc" // lalr1.cc:859
    break;

  case 687:
#line 1713 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.run_estimation(); }
#line 3224 "DynareBison.cc" // lalr1.cc:859
    break;

  case 688:
#line 1715 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.run_estimation(); }
#line 3230 "DynareBison.cc" // lalr1.cc:859
    break;

  case 689:
#line 1717 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.run_estimation(); }
#line 3236 "DynareBison.cc" // lalr1.cc:859
    break;

  case 802:
#line 1837 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.optim_options_string((yystack_[2].value.string_val), (yystack_[0].value.string_val)); }
#line 3242 "DynareBison.cc" // lalr1.cc:859
    break;

  case 803:
#line 1839 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.optim_options_num((yystack_[2].value.string_val), (yystack_[0].value.string_val)); }
#line 3248 "DynareBison.cc" // lalr1.cc:859
    break;

  case 806:
#line 1847 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                             (yystack_[2].value.string_val)->insert(0, "''");
                             (yystack_[2].value.string_val)->append("'', ''");
                             (yystack_[2].value.string_val)->append(*(yystack_[0].value.string_val));
                             (yystack_[2].value.string_val)->append("''");
                             (yylhs.value.string_val) = (yystack_[2].value.string_val);
                           }
#line 3260 "DynareBison.cc" // lalr1.cc:859
    break;

  case 807:
#line 1855 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                             (yystack_[2].value.string_val)->insert(0, "''");
                             (yystack_[2].value.string_val)->append("'',");
                             (yystack_[2].value.string_val)->append(*(yystack_[0].value.string_val));
                             (yylhs.value.string_val) = (yystack_[2].value.string_val);
                           }
#line 3271 "DynareBison.cc" // lalr1.cc:859
    break;

  case 808:
#line 1864 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 3277 "DynareBison.cc" // lalr1.cc:859
    break;

  case 809:
#line 1866 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                         (yystack_[2].value.string_val)->append(",");
                         (yystack_[2].value.string_val)->append(*(yystack_[0].value.string_val));
                         (yylhs.value.string_val) = (yystack_[2].value.string_val);
                       }
#line 3287 "DynareBison.cc" // lalr1.cc:859
    break;

  case 810:
#line 1874 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.sampling_options_string((yystack_[2].value.string_val), (yystack_[0].value.string_val)); }
#line 3293 "DynareBison.cc" // lalr1.cc:859
    break;

  case 811:
#line 1876 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.sampling_options_num((yystack_[2].value.string_val), (yystack_[0].value.string_val)); }
#line 3299 "DynareBison.cc" // lalr1.cc:859
    break;

  case 812:
#line 1878 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                         (yystack_[1].value.string_val)->insert(0,"(");
                         (yystack_[1].value.string_val)->append(")");
                         driver.sampling_options_string((yystack_[4].value.string_val), (yystack_[1].value.string_val));
                       }
#line 3309 "DynareBison.cc" // lalr1.cc:859
    break;

  case 815:
#line 1889 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.check_varobs(); }
#line 3315 "DynareBison.cc" // lalr1.cc:859
    break;

  case 817:
#line 1892 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_varobs((yystack_[0].value.string_val)); }
#line 3321 "DynareBison.cc" // lalr1.cc:859
    break;

  case 818:
#line 1894 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_varobs((yystack_[0].value.string_val)); }
#line 3327 "DynareBison.cc" // lalr1.cc:859
    break;

  case 819:
#line 1896 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_varobs((yystack_[0].value.string_val)); }
#line 3333 "DynareBison.cc" // lalr1.cc:859
    break;

  case 820:
#line 1899 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_trends(); }
#line 3339 "DynareBison.cc" // lalr1.cc:859
    break;

  case 823:
#line 1905 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_trend_element((yystack_[4].value.string_val), (yystack_[2].value.node_val)); }
#line 3345 "DynareBison.cc" // lalr1.cc:859
    break;

  case 824:
#line 1907 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_unit_root_vars(); }
#line 3351 "DynareBison.cc" // lalr1.cc:859
    break;

  case 825:
#line 1909 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.optim_weights(); }
#line 3357 "DynareBison.cc" // lalr1.cc:859
    break;

  case 826:
#line 1912 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_optim_weights((yystack_[2].value.string_val), (yystack_[1].value.node_val)); }
#line 3363 "DynareBison.cc" // lalr1.cc:859
    break;

  case 827:
#line 1914 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_optim_weights((yystack_[4].value.string_val), (yystack_[2].value.string_val), (yystack_[1].value.node_val)); }
#line 3369 "DynareBison.cc" // lalr1.cc:859
    break;

  case 828:
#line 1916 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_optim_weights((yystack_[2].value.string_val), (yystack_[1].value.node_val)); }
#line 3375 "DynareBison.cc" // lalr1.cc:859
    break;

  case 829:
#line 1918 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_optim_weights((yystack_[4].value.string_val), (yystack_[2].value.string_val), (yystack_[1].value.node_val)); }
#line 3381 "DynareBison.cc" // lalr1.cc:859
    break;

  case 830:
#line 1921 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_osr_params(); }
#line 3387 "DynareBison.cc" // lalr1.cc:859
    break;

  case 840:
#line 1938 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.run_osr(); }
#line 3393 "DynareBison.cc" // lalr1.cc:859
    break;

  case 841:
#line 1940 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.run_osr(); }
#line 3399 "DynareBison.cc" // lalr1.cc:859
    break;

  case 842:
#line 1942 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.run_osr(); }
#line 3405 "DynareBison.cc" // lalr1.cc:859
    break;

  case 843:
#line 1944 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.run_osr(); }
#line 3411 "DynareBison.cc" // lalr1.cc:859
    break;

  case 844:
#line 1948 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.run_dynatype((yystack_[2].value.string_val)); }
#line 3417 "DynareBison.cc" // lalr1.cc:859
    break;

  case 845:
#line 1950 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.run_dynatype((yystack_[3].value.string_val)); }
#line 3423 "DynareBison.cc" // lalr1.cc:859
    break;

  case 846:
#line 1954 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.run_dynasave((yystack_[2].value.string_val)); }
#line 3429 "DynareBison.cc" // lalr1.cc:859
    break;

  case 847:
#line 1956 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.run_dynasave((yystack_[3].value.string_val)); }
#line 3435 "DynareBison.cc" // lalr1.cc:859
    break;

  case 848:
#line 1960 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.run_load_params_and_steady_state((yystack_[2].value.string_val)); }
#line 3441 "DynareBison.cc" // lalr1.cc:859
    break;

  case 849:
#line 1964 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.run_save_params_and_steady_state((yystack_[2].value.string_val)); }
#line 3447 "DynareBison.cc" // lalr1.cc:859
    break;

  case 850:
#line 1968 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.run_identification(); }
#line 3453 "DynareBison.cc" // lalr1.cc:859
    break;

  case 851:
#line 1970 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.run_identification(); }
#line 3459 "DynareBison.cc" // lalr1.cc:859
    break;

  case 874:
#line 2000 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.run_model_comparison(); }
#line 3465 "DynareBison.cc" // lalr1.cc:859
    break;

  case 875:
#line 2002 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.run_model_comparison(); }
#line 3471 "DynareBison.cc" // lalr1.cc:859
    break;

  case 878:
#line 2010 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_parallel_local_file((yystack_[0].value.string_val)); }
#line 3477 "DynareBison.cc" // lalr1.cc:859
    break;

  case 879:
#line 2012 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_parallel_local_file((yystack_[0].value.string_val)); }
#line 3483 "DynareBison.cc" // lalr1.cc:859
    break;

  case 880:
#line 2016 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_mc_filename((yystack_[0].value.string_val)); }
#line 3489 "DynareBison.cc" // lalr1.cc:859
    break;

  case 881:
#line 2018 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_mc_filename((yystack_[3].value.string_val), (yystack_[1].value.string_val)); }
#line 3495 "DynareBison.cc" // lalr1.cc:859
    break;

  case 882:
#line 2020 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_mc_filename((yystack_[0].value.string_val)); }
#line 3501 "DynareBison.cc" // lalr1.cc:859
    break;

  case 883:
#line 2022 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_mc_filename((yystack_[3].value.string_val), (yystack_[1].value.string_val)); }
#line 3507 "DynareBison.cc" // lalr1.cc:859
    break;

  case 884:
#line 2024 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_mc_filename((yystack_[0].value.string_val)); }
#line 3513 "DynareBison.cc" // lalr1.cc:859
    break;

  case 885:
#line 2026 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_mc_filename((yystack_[3].value.string_val), (yystack_[1].value.string_val)); }
#line 3519 "DynareBison.cc" // lalr1.cc:859
    break;

  case 886:
#line 2029 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.begin_planner_objective(); }
#line 3525 "DynareBison.cc" // lalr1.cc:859
    break;

  case 887:
#line 2030 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.end_planner_objective((yystack_[0].value.node_val)); }
#line 3531 "DynareBison.cc" // lalr1.cc:859
    break;

  case 889:
#line 2033 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ramsey_model(); }
#line 3537 "DynareBison.cc" // lalr1.cc:859
    break;

  case 890:
#line 2035 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ramsey_model(); }
#line 3543 "DynareBison.cc" // lalr1.cc:859
    break;

  case 891:
#line 2037 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ramsey_model(); }
#line 3549 "DynareBison.cc" // lalr1.cc:859
    break;

  case 892:
#line 2039 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ramsey_model(); }
#line 3555 "DynareBison.cc" // lalr1.cc:859
    break;

  case 893:
#line 2043 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ramsey_policy(); }
#line 3561 "DynareBison.cc" // lalr1.cc:859
    break;

  case 894:
#line 2045 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ramsey_policy(); }
#line 3567 "DynareBison.cc" // lalr1.cc:859
    break;

  case 895:
#line 2047 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ramsey_policy(); }
#line 3573 "DynareBison.cc" // lalr1.cc:859
    break;

  case 896:
#line 2049 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ramsey_policy(); }
#line 3579 "DynareBison.cc" // lalr1.cc:859
    break;

  case 899:
#line 2056 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_to_ramsey_policy_list((yystack_[0].value.string_val)); }
#line 3585 "DynareBison.cc" // lalr1.cc:859
    break;

  case 900:
#line 2060 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_ramsey_constraints_statement(); }
#line 3591 "DynareBison.cc" // lalr1.cc:859
    break;

  case 903:
#line 2068 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ramsey_constraint_add_less((yystack_[3].value.string_val),(yystack_[1].value.node_val)); }
#line 3597 "DynareBison.cc" // lalr1.cc:859
    break;

  case 904:
#line 2070 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ramsey_constraint_add_greater((yystack_[3].value.string_val),(yystack_[1].value.node_val)); }
#line 3603 "DynareBison.cc" // lalr1.cc:859
    break;

  case 905:
#line 2072 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ramsey_constraint_add_less_equal((yystack_[3].value.string_val),(yystack_[1].value.node_val)); }
#line 3609 "DynareBison.cc" // lalr1.cc:859
    break;

  case 906:
#line 2074 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ramsey_constraint_add_greater_equal((yystack_[3].value.string_val),(yystack_[1].value.node_val)); }
#line 3615 "DynareBison.cc" // lalr1.cc:859
    break;

  case 907:
#line 2078 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.discretionary_policy(); }
#line 3621 "DynareBison.cc" // lalr1.cc:859
    break;

  case 908:
#line 2080 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.discretionary_policy(); }
#line 3627 "DynareBison.cc" // lalr1.cc:859
    break;

  case 909:
#line 2082 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.discretionary_policy(); }
#line 3633 "DynareBison.cc" // lalr1.cc:859
    break;

  case 910:
#line 2084 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.discretionary_policy(); }
#line 3639 "DynareBison.cc" // lalr1.cc:859
    break;

  case 925:
#line 2114 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.write_latex_dynamic_model(false); }
#line 3645 "DynareBison.cc" // lalr1.cc:859
    break;

  case 926:
#line 2116 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.write_latex_dynamic_model(true); }
#line 3651 "DynareBison.cc" // lalr1.cc:859
    break;

  case 927:
#line 2120 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.write_latex_static_model(); }
#line 3657 "DynareBison.cc" // lalr1.cc:859
    break;

  case 928:
#line 2124 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.write_latex_original_model(); }
#line 3663 "DynareBison.cc" // lalr1.cc:859
    break;

  case 929:
#line 2128 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.shock_decomposition(); }
#line 3669 "DynareBison.cc" // lalr1.cc:859
    break;

  case 930:
#line 2130 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.shock_decomposition(); }
#line 3675 "DynareBison.cc" // lalr1.cc:859
    break;

  case 931:
#line 2132 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.shock_decomposition(); }
#line 3681 "DynareBison.cc" // lalr1.cc:859
    break;

  case 932:
#line 2134 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.shock_decomposition(); }
#line 3687 "DynareBison.cc" // lalr1.cc:859
    break;

  case 933:
#line 2138 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.realtime_shock_decomposition(); }
#line 3693 "DynareBison.cc" // lalr1.cc:859
    break;

  case 934:
#line 2140 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.realtime_shock_decomposition(); }
#line 3699 "DynareBison.cc" // lalr1.cc:859
    break;

  case 935:
#line 2142 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.realtime_shock_decomposition(); }
#line 3705 "DynareBison.cc" // lalr1.cc:859
    break;

  case 936:
#line 2144 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.realtime_shock_decomposition(); }
#line 3711 "DynareBison.cc" // lalr1.cc:859
    break;

  case 937:
#line 2148 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.plot_shock_decomposition(); }
#line 3717 "DynareBison.cc" // lalr1.cc:859
    break;

  case 938:
#line 2150 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.plot_shock_decomposition(); }
#line 3723 "DynareBison.cc" // lalr1.cc:859
    break;

  case 939:
#line 2152 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.plot_shock_decomposition(); }
#line 3729 "DynareBison.cc" // lalr1.cc:859
    break;

  case 940:
#line 2154 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.plot_shock_decomposition(); }
#line 3735 "DynareBison.cc" // lalr1.cc:859
    break;

  case 941:
#line 2158 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.initial_condition_decomposition(); }
#line 3741 "DynareBison.cc" // lalr1.cc:859
    break;

  case 942:
#line 2160 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.initial_condition_decomposition(); }
#line 3747 "DynareBison.cc" // lalr1.cc:859
    break;

  case 943:
#line 2162 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.initial_condition_decomposition(); }
#line 3753 "DynareBison.cc" // lalr1.cc:859
    break;

  case 944:
#line 2164 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.initial_condition_decomposition(); }
#line 3759 "DynareBison.cc" // lalr1.cc:859
    break;

  case 964:
#line 2193 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.bvar_density((yystack_[1].value.string_val)); }
#line 3765 "DynareBison.cc" // lalr1.cc:859
    break;

  case 965:
#line 2195 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.bvar_density((yystack_[1].value.string_val)); }
#line 3771 "DynareBison.cc" // lalr1.cc:859
    break;

  case 972:
#line 2209 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.bvar_forecast((yystack_[1].value.string_val)); }
#line 3777 "DynareBison.cc" // lalr1.cc:859
    break;

  case 973:
#line 2211 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.bvar_forecast((yystack_[1].value.string_val)); }
#line 3783 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1024:
#line 2269 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.sbvar(); }
#line 3789 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1025:
#line 2271 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.sbvar(); }
#line 3795 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1042:
#line 2295 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ms_variance_decomposition(); }
#line 3801 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1043:
#line 2297 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ms_variance_decomposition(); }
#line 3807 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1060:
#line 2321 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ms_forecast(); }
#line 3813 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1061:
#line 2323 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ms_forecast(); }
#line 3819 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1078:
#line 2347 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ms_irf(); }
#line 3825 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1079:
#line 2349 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ms_irf(); }
#line 3831 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1080:
#line 2351 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ms_irf(); }
#line 3837 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1081:
#line 2353 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ms_irf(); }
#line 3843 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1088:
#line 2367 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ms_compute_probabilities(); }
#line 3849 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1089:
#line 2369 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ms_compute_probabilities(); }
#line 3855 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1100:
#line 2387 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ms_compute_mdd(); }
#line 3861 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1101:
#line 2389 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ms_compute_mdd(); }
#line 3867 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1111:
#line 2406 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ms_simulation(); }
#line 3873 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1112:
#line 2408 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ms_simulation(); }
#line 3879 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1150:
#line 2453 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ms_estimation(); }
#line 3885 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1151:
#line 2455 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ms_estimation(); }
#line 3891 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1152:
#line 2459 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.dynare_sensitivity(); }
#line 3897 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1153:
#line 2461 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.dynare_sensitivity(); }
#line 3903 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1254:
#line 2585 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.end_homotopy();}
#line 3909 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1257:
#line 2592 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.homotopy_val((yystack_[5].value.string_val), (yystack_[3].value.node_val), (yystack_[1].value.node_val));}
#line 3915 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1258:
#line 2594 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.homotopy_val((yystack_[3].value.string_val), NULL, (yystack_[1].value.node_val));}
#line 3921 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1259:
#line 2597 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.forecast();}
#line 3927 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1260:
#line 2598 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.forecast();}
#line 3933 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1261:
#line 2599 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.forecast();}
#line 3939 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1262:
#line 2600 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.forecast();}
#line 3945 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1270:
#line 2615 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.conditional_forecast(); }
#line 3951 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1278:
#line 2630 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.plot_conditional_forecast(); }
#line 3957 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1279:
#line 2632 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.plot_conditional_forecast((yystack_[3].value.string_val)); }
#line 3963 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1280:
#line 2636 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.conditional_forecast_paths(); }
#line 3969 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1283:
#line 2644 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_det_shock((yystack_[7].value.string_val), true); }
#line 3975 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1284:
#line 2647 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.begin_steady_state_model(); }
#line 3981 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1285:
#line 2648 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.reset_data_tree(); }
#line 3987 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1288:
#line 2656 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_steady_state_model_equal((yystack_[3].value.string_val), (yystack_[1].value.node_val)); }
#line 3993 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1289:
#line 2658 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_steady_state_model_equal_multiple((yystack_[1].value.node_val)); }
#line 3999 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1290:
#line 2662 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.calib_smoother(); }
#line 4005 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1291:
#line 2664 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.calib_smoother(); }
#line 4011 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1292:
#line 2666 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.calib_smoother(); }
#line 4017 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1293:
#line 2668 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.calib_smoother(); }
#line 4023 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1306:
#line 2688 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.extended_path(); }
#line 4029 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1307:
#line 2690 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.extended_path(); }
#line 4035 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1315:
#line 2705 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.model_diagnostics(); }
#line 4041 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1316:
#line 2709 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                      (yylhs.value.vector_string_val) = new vector<string *>();
                      (yylhs.value.vector_string_val)->push_back((yystack_[2].value.string_val));
                      (yylhs.value.vector_string_val)->push_back((yystack_[1].value.string_val));
                    }
#line 4051 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1317:
#line 2715 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                      (yylhs.value.vector_string_val) = new vector<string *>();
                      (yylhs.value.vector_string_val)->push_back((yystack_[3].value.string_val));
                      (yylhs.value.vector_string_val)->push_back((yystack_[1].value.string_val));
                    }
#line 4061 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1318:
#line 2721 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                      (yylhs.value.vector_string_val) = new vector<string *>();
                      (yylhs.value.vector_string_val)->push_back(new string("0"));
                      (yylhs.value.vector_string_val)->push_back(new string("inf"));
                    }
#line 4071 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1319:
#line 2727 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                      (yylhs.value.vector_string_val) = new vector<string *>();
                      (yylhs.value.vector_string_val)->push_back(new string("-inf"));
                      (yylhs.value.vector_string_val)->push_back(new string("0"));
                    }
#line 4081 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1320:
#line 2735 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.end_moment_calibration(); }
#line 4087 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1323:
#line 2743 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_moment_calibration_item((yystack_[5].value.string_val), (yystack_[3].value.string_val), new string("0"), (yystack_[1].value.vector_string_val)); }
#line 4093 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1324:
#line 2745 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_moment_calibration_item((yystack_[8].value.string_val), (yystack_[6].value.string_val), (yystack_[4].value.string_val), (yystack_[1].value.vector_string_val)); }
#line 4099 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1325:
#line 2747 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_moment_calibration_item((yystack_[8].value.string_val), (yystack_[6].value.string_val), (yystack_[4].value.string_val), (yystack_[1].value.vector_string_val)); }
#line 4105 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1326:
#line 2751 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.end_irf_calibration(); }
#line 4111 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1327:
#line 2753 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.end_irf_calibration(); }
#line 4117 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1330:
#line 2761 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_irf_calibration_item((yystack_[5].value.string_val), new string("1"), (yystack_[3].value.string_val), (yystack_[1].value.vector_string_val)); }
#line 4123 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1331:
#line 2763 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_irf_calibration_item((yystack_[8].value.string_val), (yystack_[6].value.string_val), (yystack_[3].value.string_val), (yystack_[1].value.vector_string_val)); }
#line 4129 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1332:
#line 2765 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_irf_calibration_item((yystack_[8].value.string_val), (yystack_[6].value.string_val), (yystack_[3].value.string_val), (yystack_[1].value.vector_string_val)); }
#line 4135 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1333:
#line 2769 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.smoother2histval(); }
#line 4141 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1334:
#line 2771 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.smoother2histval(); }
#line 4147 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1342:
#line 2785 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.end_shock_groups(new string("default"));}
#line 4153 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1343:
#line 2787 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.end_shock_groups((yystack_[5].value.string_val));}
#line 4159 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1346:
#line 2794 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_shock_group((yystack_[3].value.string_val)); }
#line 4165 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1347:
#line 2795 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_shock_group((yystack_[3].value.string_val)); }
#line 4171 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1348:
#line 2798 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.add_shock_group_element((yystack_[0].value.string_val));}
#line 4177 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1349:
#line 2799 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.add_shock_group_element((yystack_[0].value.string_val));}
#line 4183 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1350:
#line 2800 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.add_shock_group_element((yystack_[0].value.string_val));}
#line 4189 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1351:
#line 2803 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                                       if (*(yystack_[0].value.string_val) == string("0"))
                                         driver.warning("dr_algo option is now deprecated, and may be removed in a future version of Dynare");
                                       else
                                         driver.error("dr_algo=1 option is no longer supported");
                                     }
#line 4200 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1352:
#line 2809 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("solve_algo", (yystack_[0].value.string_val)); }
#line 4206 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1353:
#line 2810 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                                             if (*(yystack_[0].value.string_val) == string("0"))
                                               driver.warning("simul_algo option is now deprecated, and may be removed in a future version of Dynare");
                                             else
                                               driver.error("simul_algo=1 option is no longer supported");
                                           }
#line 4217 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1354:
#line 2816 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("stack_solve_algo", (yystack_[0].value.string_val)); }
#line 4223 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1355:
#line 2817 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("simul.robust_lin_solve", "1"); }
#line 4229 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1356:
#line 2818 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("endogenous_terminal_period", "1"); }
#line 4235 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1357:
#line 2819 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.linear(); }
#line 4241 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1358:
#line 2820 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("order", (yystack_[0].value.string_val)); }
#line 4247 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1359:
#line 2821 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("replic", (yystack_[0].value.string_val)); }
#line 4253 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1360:
#line 2822 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("drop", (yystack_[0].value.string_val)); }
#line 4259 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1361:
#line 2823 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ar", (yystack_[0].value.string_val)); }
#line 4265 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1362:
#line 2824 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("nocorr", "1"); }
#line 4271 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1363:
#line 2825 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("nofunctions", "1"); }
#line 4277 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1364:
#line 2826 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("nomoments", "1"); }
#line 4283 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1365:
#line 2827 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("irf", (yystack_[0].value.string_val)); }
#line 4289 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1366:
#line 2828 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_symbol_list("irf_shocks"); }
#line 4295 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1367:
#line 2829 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("hp_filter", (yystack_[0].value.string_val)); }
#line 4301 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1368:
#line 2830 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("hp_ngrid", (yystack_[0].value.string_val)); }
#line 4307 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1369:
#line 2831 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("one_sided_hp_filter", (yystack_[0].value.string_val)); }
#line 4313 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1370:
#line 2832 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("periods", (yystack_[0].value.string_val)); }
#line 4319 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1371:
#line 2833 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ep.periods", (yystack_[0].value.string_val)); }
#line 4325 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1372:
#line 2834 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ep.stochastic.order", (yystack_[0].value.string_val)); }
#line 4331 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1373:
#line 2835 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ep.stochastic.hybrid_order", "2"); }
#line 4337 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1374:
#line 2836 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("steady.maxit", (yystack_[0].value.string_val)); }
#line 4343 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1375:
#line 2837 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("simul.maxit", (yystack_[0].value.string_val)); }
#line 4349 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1376:
#line 2838 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("bandpass.indicator", "1"); }
#line 4355 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1377:
#line 2840 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                      driver.option_num("bandpass.indicator", "1");
                      driver.option_vec_int("bandpass.passband", (yystack_[0].value.vector_int_val));
                    }
#line 4364 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1378:
#line 2845 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("dp.maxit", (yystack_[0].value.string_val)); }
#line 4370 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1379:
#line 2846 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("osr.maxit", (yystack_[0].value.string_val)); }
#line 4376 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1380:
#line 2847 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("osr.tolf", (yystack_[0].value.string_val)); }
#line 4382 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1381:
#line 2848 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("dynatol.f", (yystack_[0].value.string_val)); }
#line 4388 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1382:
#line 2849 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("dynatol.x", (yystack_[0].value.string_val)); }
#line 4394 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1383:
#line 2850 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("solve_tolf", (yystack_[0].value.string_val)); }
#line 4400 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1384:
#line 2851 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("osr.opt_algo", (yystack_[0].value.string_val)); }
#line 4406 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1385:
#line 2852 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("osr.opt_algo", (yystack_[0].value.string_val)); }
#line 4412 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1386:
#line 2854 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.cutoff((yystack_[0].value.string_val)); }
#line 4418 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1387:
#line 2855 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("markowitz", (yystack_[0].value.string_val)); }
#line 4424 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1388:
#line 2856 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("minimal_solving_periods", (yystack_[0].value.string_val)); }
#line 4430 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1389:
#line 2857 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.mfs((yystack_[0].value.string_val)); }
#line 4436 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1391:
#line 2859 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("simul_replic", (yystack_[0].value.string_val)); }
#line 4442 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1392:
#line 2860 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.error("'simul_seed' option is no longer supported; use 'set_dynare_seed' command instead"); }
#line 4448 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1393:
#line 2861 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("qz_criterium", (yystack_[0].value.string_val)); }
#line 4454 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1394:
#line 2862 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("qz_zero_threshold", (yystack_[0].value.string_val)); }
#line 4460 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1395:
#line 2863 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("file", (yystack_[0].value.string_val)); }
#line 4466 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1396:
#line 2864 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("series", (yystack_[0].value.string_val)); }
#line 4472 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1397:
#line 2865 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("datafile", (yystack_[0].value.string_val)); }
#line 4478 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1398:
#line 2866 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("dirname", (yystack_[0].value.string_val)); }
#line 4484 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1399:
#line 2867 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("huge_number", (yystack_[0].value.string_val)); }
#line 4490 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1400:
#line 2869 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_vec_int("nobs", (yystack_[0].value.vector_int_val)); }
#line 4496 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1401:
#line 2871 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_vec_int("nobs", (yystack_[0].value.vector_int_val)); }
#line 4502 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1402:
#line 2874 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_vec_int("conditional_variance_decomposition", (yystack_[0].value.vector_int_val)); }
#line 4508 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1403:
#line 2876 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_vec_int("conditional_variance_decomposition", (yystack_[0].value.vector_int_val)); }
#line 4514 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1404:
#line 2879 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_vec_int("first_obs", (yystack_[0].value.vector_int_val)); }
#line 4520 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1405:
#line 2881 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_vec_int("first_obs", (yystack_[0].value.vector_int_val)); }
#line 4526 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1406:
#line 2884 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("posterior_sampler_options.posterior_sampling_method", (yystack_[0].value.string_val)); }
#line 4532 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1407:
#line 2885 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("first_obs", (yystack_[0].value.string_val)); }
#line 4538 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1408:
#line 2886 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_date("firstobs", (yystack_[0].value.string_val)); }
#line 4544 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1409:
#line 2887 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_date("lastobs", (yystack_[0].value.string_val)); }
#line 4550 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1410:
#line 2888 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("kalman.keep_kalman_algo_if_singularity_is_detected", "1"); }
#line 4556 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1411:
#line 2889 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("nobs", (yystack_[0].value.string_val)); }
#line 4562 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1412:
#line 2890 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("shift", (yystack_[0].value.string_val)); }
#line 4568 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1413:
#line 2891 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.prior_shape = (yystack_[0].value.prior_distributions_val); }
#line 4574 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1414:
#line 2892 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("mode", (yystack_[0].value.string_val)); }
#line 4580 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1415:
#line 2893 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("mean", (yystack_[0].value.string_val)); }
#line 4586 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1416:
#line 2894 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("mean", (yystack_[0].value.string_val)); }
#line 4592 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1417:
#line 2895 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("truncate", (yystack_[0].value.string_val)); }
#line 4598 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1418:
#line 2896 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("stdev", (yystack_[0].value.string_val)); }
#line 4604 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1419:
#line 2897 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("jscale", (yystack_[0].value.string_val)); }
#line 4610 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1420:
#line 2898 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("init", (yystack_[0].value.string_val)); }
#line 4616 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1421:
#line 2899 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("bounds", (yystack_[0].value.string_val)); }
#line 4622 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1422:
#line 2900 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("domain", (yystack_[0].value.string_val)); }
#line 4628 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1423:
#line 2901 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("interval", (yystack_[0].value.string_val)); }
#line 4634 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1424:
#line 2902 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_prior_variance((yystack_[0].value.node_val)); }
#line 4640 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1425:
#line 2903 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("variance",(yystack_[0].value.string_val)); }
#line 4646 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1426:
#line 2904 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("prefilter", (yystack_[0].value.string_val)); }
#line 4652 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1427:
#line 2905 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("presample", (yystack_[0].value.string_val)); }
#line 4658 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1428:
#line 2906 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("lik_algo", (yystack_[0].value.string_val)); }
#line 4664 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1429:
#line 2907 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("lik_init", (yystack_[0].value.string_val)); }
#line 4670 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1430:
#line 2909 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("nograph","1"); }
#line 4676 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1431:
#line 2911 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("nograph", "0"); }
#line 4682 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1432:
#line 2914 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("no_graph.posterior","1"); }
#line 4688 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1433:
#line 2916 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("no_graph.posterior", "0"); }
#line 4694 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1434:
#line 2918 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("no_graph.shock_decomposition", "1"); }
#line 4700 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1435:
#line 2919 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("shock_decomp.init_state", (yystack_[0].value.string_val)); }
#line 4706 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1436:
#line 2920 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("shock_decomp.presample", (yystack_[0].value.string_val)); }
#line 4712 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1437:
#line 2921 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("shock_decomp.forecast", (yystack_[0].value.string_val)); }
#line 4718 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1438:
#line 2922 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_vec_int("shock_decomp.save_realtime", (yystack_[0].value.vector_int_val)); }
#line 4724 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1439:
#line 2923 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("nodisplay","1"); }
#line 4730 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1440:
#line 2924 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("plot_shock_decomp.nodisplay","1"); }
#line 4736 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1441:
#line 2926 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.process_graph_format_option(); }
#line 4742 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1442:
#line 2928 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.process_graph_format_option(); }
#line 4748 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1443:
#line 2931 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.plot_shock_decomp_process_graph_format_option(); }
#line 4754 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1444:
#line 2933 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.plot_shock_decomp_process_graph_format_option(); }
#line 4760 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1445:
#line 2936 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_graph_format("eps"); }
#line 4766 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1446:
#line 2938 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_graph_format("fig"); }
#line 4772 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1447:
#line 2940 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_graph_format("pdf"); }
#line 4778 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1448:
#line 2942 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_graph_format("none"); }
#line 4784 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1451:
#line 2949 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_subsample_name_equal_to_date_range((yystack_[4].value.string_val), (yystack_[2].value.string_val), (yystack_[0].value.string_val)); }
#line 4790 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1452:
#line 2951 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("bvar.conf_sig", (yystack_[0].value.string_val)); }
#line 4796 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1453:
#line 2952 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("forecasts.conf_sig", (yystack_[0].value.string_val)); }
#line 4802 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1454:
#line 2953 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("conditional_forecast.conf_sig", (yystack_[0].value.string_val)); }
#line 4808 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1455:
#line 2954 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("mh_conf_sig", (yystack_[0].value.string_val)); }
#line 4814 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1456:
#line 2955 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("mh_replic", (yystack_[0].value.string_val)); }
#line 4820 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1457:
#line 2956 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("posterior_max_subsample_draws", (yystack_[0].value.string_val)); }
#line 4826 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1458:
#line 2957 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("mh_drop", (yystack_[0].value.string_val)); }
#line 4832 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1459:
#line 2958 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("mh_jscale", (yystack_[0].value.string_val)); }
#line 4838 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1462:
#line 2961 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("posterior_sampler_options.posterior_sampling_method.proposal_distribution", (yystack_[0].value.string_val)); }
#line 4844 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1463:
#line 2963 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("estimation.moments_posterior_density.indicator", "0"); }
#line 4850 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1464:
#line 2965 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("mh_init_scale", (yystack_[0].value.string_val)); }
#line 4856 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1465:
#line 2966 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("mode_file", (yystack_[0].value.string_val)); }
#line 4862 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1466:
#line 2967 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("mode_compute", (yystack_[0].value.string_val)); }
#line 4868 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1467:
#line 2968 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("mode_compute", (yystack_[0].value.string_val)); }
#line 4874 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1468:
#line 2969 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("mode_check.status", "1"); }
#line 4880 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1469:
#line 2970 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("mode_check.neighbourhood_size", (yystack_[0].value.string_val)); }
#line 4886 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1470:
#line 2971 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("mode_check.number_of_points", (yystack_[0].value.string_val)); }
#line 4892 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1471:
#line 2972 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("mode_check.symmetric_plots", (yystack_[0].value.string_val)); }
#line 4898 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1472:
#line 2973 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("prior_trunc", (yystack_[0].value.string_val)); }
#line 4904 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1473:
#line 2974 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("mh_mode", (yystack_[0].value.string_val)); }
#line 4910 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1474:
#line 2975 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("mh_nblck", (yystack_[0].value.string_val)); }
#line 4916 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1475:
#line 2976 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("load_mh_file", "1"); }
#line 4922 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1476:
#line 2977 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("load_results_after_load_mh", "1"); }
#line 4928 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1477:
#line 2978 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("loglinear", "1"); }
#line 4934 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1478:
#line 2979 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("linear_approximation", "1"); }
#line 4940 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1479:
#line 2980 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("logdata", "1"); }
#line 4946 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1480:
#line 2981 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("nodiagnostic", "1"); }
#line 4952 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1481:
#line 2982 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("bayesian_irf", "1"); }
#line 4958 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1482:
#line 2984 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("dsge_var", (yystack_[0].value.string_val)); }
#line 4964 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1483:
#line 2986 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("dsge_var", "Inf"); }
#line 4970 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1484:
#line 2988 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("dsge_var", "NaN"); }
#line 4976 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1485:
#line 2990 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("dsge_varlag", (yystack_[0].value.string_val)); }
#line 4982 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1486:
#line 2991 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("TeX", "1"); }
#line 4988 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1487:
#line 2992 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("forecast", (yystack_[0].value.string_val)); }
#line 4994 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1488:
#line 2993 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("smoother", "1"); }
#line 5000 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1489:
#line 2994 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("moments_varendo", "1"); }
#line 5006 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1490:
#line 2995 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("contemporaneous_correlation", "1"); }
#line 5012 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1491:
#line 2996 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("filtered_vars", "1"); }
#line 5018 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1492:
#line 2997 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("relative_irf", "1"); }
#line 5024 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1493:
#line 2998 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("fast_kalman_filter", "1"); }
#line 5030 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1494:
#line 2999 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("kalman_algo", (yystack_[0].value.string_val)); }
#line 5036 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1495:
#line 3000 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("kalman_tol", (yystack_[0].value.string_val)); }
#line 5042 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1496:
#line 3001 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("diffuse_kalman_tol", (yystack_[0].value.string_val)); }
#line 5048 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1497:
#line 3003 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("mc_marginal_density", "laplace"); }
#line 5054 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1498:
#line 3005 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("mc_marginal_density", "modifiedharmonicmean"); }
#line 5060 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1499:
#line 3007 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("noprint", "0"); }
#line 5066 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1500:
#line 3008 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("noprint", "1"); }
#line 5072 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1501:
#line 3009 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("xls_sheet", (yystack_[0].value.string_val)); }
#line 5078 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1502:
#line 3010 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("xls_range", (yystack_[0].value.string_val)); }
#line 5084 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1503:
#line 3011 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_vec_int("filter_step_ahead", (yystack_[0].value.vector_int_val)); }
#line 5090 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1504:
#line 3012 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_vec_int("convergence.geweke.taper_steps", (yystack_[0].value.vector_int_val)); }
#line 5096 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1505:
#line 3013 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("convergence.geweke.geweke_interval",(yystack_[0].value.string_val)); }
#line 5102 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1506:
#line 3014 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("convergence.rafterylewis.indicator", "1"); }
#line 5108 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1507:
#line 3015 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("convergence.rafterylewis.qrs",(yystack_[0].value.string_val)); }
#line 5114 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1508:
#line 3016 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("noconstant", "0"); }
#line 5120 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1509:
#line 3017 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("noconstant", "1"); }
#line 5126 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1510:
#line 3018 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("mh_recover", "1"); }
#line 5132 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1511:
#line 3019 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("diffuse_filter", "1"); }
#line 5138 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1512:
#line 3020 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("plot_priors", (yystack_[0].value.string_val)); }
#line 5144 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1513:
#line 3021 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("aim_solver", "1"); }
#line 5150 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1514:
#line 3022 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("partial_information", "1"); }
#line 5156 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1515:
#line 3023 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("sub_draws",(yystack_[0].value.string_val));}
#line 5162 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1516:
#line 3024 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_optimal_policy_discount_factor_parameter((yystack_[0].value.node_val)); }
#line 5168 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1517:
#line 3025 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("sylvester_fp", "1"); }
#line 5174 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1518:
#line 3026 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("sylvester_fp", "0"); }
#line 5180 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1519:
#line 3027 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("sylvester_fixed_point_tol",(yystack_[0].value.string_val));}
#line 5186 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1520:
#line 3028 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("lyapunov_fp", "1"); }
#line 5192 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1521:
#line 3029 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("lyapunov_db", "1"); }
#line 5198 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1522:
#line 3030 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("lyapunov_srs", "1"); }
#line 5204 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1523:
#line 3031 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("lyapunov_fp", "0");driver.option_num("lyapunov_db", "0"); driver.option_num("lyapunov_srs", "0");}
#line 5210 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1524:
#line 3032 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("lyapunov_fixed_point_tol",(yystack_[0].value.string_val));}
#line 5216 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1525:
#line 3033 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("lyapunov_doubling_tol",(yystack_[0].value.string_val));}
#line 5222 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1526:
#line 3034 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("dr_cycle_reduction", "1"); }
#line 5228 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1527:
#line 3035 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("dr_logarithmic_reduction", "1"); }
#line 5234 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1528:
#line 3036 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("dr_cycle_reduction", "0"); driver.option_num("dr_logarithmic_reduction", "0");}
#line 5240 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1529:
#line 3037 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("dr_cycle_reduction_tol",(yystack_[0].value.string_val));}
#line 5246 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1530:
#line 3038 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("dr_logarithmic_reduction_tol",(yystack_[0].value.string_val));}
#line 5252 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1531:
#line 3039 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("dr_logarithmic_reduction_maxiter",(yystack_[0].value.string_val));}
#line 5258 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1532:
#line 3040 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("plot_shock_decomp.detail_plot", "1"); }
#line 5264 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1533:
#line 3041 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("initial_condition_decomp.detail_plot", "1"); }
#line 5270 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1534:
#line 3042 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("plot_shock_decomp.interactive", "1"); }
#line 5276 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1535:
#line 3043 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("plot_shock_decomp.screen_shocks", "1"); }
#line 5282 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1536:
#line 3044 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("plot_shock_decomp.steadystate", "1"); }
#line 5288 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1537:
#line 3045 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("initial_condition_decomp.steadystate", "1"); }
#line 5294 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1538:
#line 3046 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("plot_shock_decomp.fig_name", (yystack_[0].value.string_val)); }
#line 5300 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1539:
#line 3048 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("plot_shock_decomp.type", "qoq"); }
#line 5306 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1540:
#line 3050 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("plot_shock_decomp.type", "yoy"); }
#line 5312 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1541:
#line 3052 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("plot_shock_decomp.type", "aoa"); }
#line 5318 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1542:
#line 3055 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("initial_condition_decomp.type", "qoq"); }
#line 5324 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1543:
#line 3057 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("initial_condition_decomp.type", "yoy"); }
#line 5330 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1544:
#line 3059 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("initial_condition_decomp.type", "aoa"); }
#line 5336 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1545:
#line 3061 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_date("initial_condition_decomp.plot_init_date", (yystack_[0].value.string_val)); }
#line 5342 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1546:
#line 3062 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_date("initial_condition_decomp.plot_end_date", (yystack_[0].value.string_val)); }
#line 5348 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1547:
#line 3063 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_date("plot_shock_decomp.plot_init_date", (yystack_[0].value.string_val)); }
#line 5354 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1548:
#line 3064 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_date("plot_shock_decomp.plot_end_date", (yystack_[0].value.string_val)); }
#line 5360 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1549:
#line 3065 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("initial_condition_decomp.write_xls", "1"); }
#line 5366 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1550:
#line 3066 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("plot_shock_decomp.write_xls", "1"); }
#line 5372 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1551:
#line 3067 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("plot_shock_decomp.realtime", (yystack_[0].value.string_val)); }
#line 5378 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1552:
#line 3068 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("plot_shock_decomp.vintage", (yystack_[0].value.string_val)); }
#line 5384 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1553:
#line 3069 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("bvar_prior_tau", (yystack_[0].value.string_val)); }
#line 5390 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1554:
#line 3070 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("bvar_prior_decay", (yystack_[0].value.string_val)); }
#line 5396 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1555:
#line 3071 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("bvar_prior_lambda", (yystack_[0].value.string_val)); }
#line 5402 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1556:
#line 3072 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("bvar_prior_mu", (yystack_[0].value.string_val)); }
#line 5408 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1557:
#line 3073 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("bvar_prior_omega", (yystack_[0].value.string_val)); }
#line 5414 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1558:
#line 3074 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("bvar_prior_flat", "1"); }
#line 5420 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1559:
#line 3075 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("bvar_prior_train", (yystack_[0].value.string_val)); }
#line 5426 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1560:
#line 3076 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("bvar_replic", (yystack_[0].value.string_val)); }
#line 5432 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1561:
#line 3078 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("particle.number_of_particles", (yystack_[0].value.string_val)); }
#line 5438 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1563:
#line 3080 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("particle.resampling.status.systematic", "0"); driver.option_num("particle.resampling.status.none", "1"); }
#line 5444 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1564:
#line 3081 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("particle.resampling.status.systematic", "0"); driver.option_num("particle.resampling.status.generic", "1"); }
#line 5450 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1565:
#line 3082 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("particle.resampling.threshold", (yystack_[0].value.string_val)); }
#line 5456 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1566:
#line 3083 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("particle.resampling.method.kitagawa", "1"); driver.option_num("particle.resampling.method.smooth", "0"); driver.option_num("particle.resampling.smethod.stratified", "0"); }
#line 5462 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1567:
#line 3084 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("particle.resampling.method.kitagawa", "0"); driver.option_num("particle.resampling.method.smooth", "1"); driver.option_num("particle.resampling.smethod.stratified", "0"); }
#line 5468 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1568:
#line 3085 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("particle.resampling.method.kitagawa", "0"); driver.option_num("particle.resampling.method.smooth", "0"); driver.option_num("particle.resampling.method.stratified", "1"); }
#line 5474 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1569:
#line 3086 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("particle.cpf_weights_method.amisanotristani", "1"); driver.option_num("particle.cpf_weights_method.murrayjonesparslow", "0"); }
#line 5480 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1570:
#line 3087 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("particle.cpf_weights_method.amisanotristani", "0"); driver.option_num("particle.cpf_weights_method.murrayjonesparslow", "1"); }
#line 5486 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1571:
#line 3088 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("particle.filter_algorithm", (yystack_[0].value.string_val)); }
#line 5492 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1572:
#line 3089 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("particle.initialization", (yystack_[0].value.string_val)); }
#line 5498 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1573:
#line 3090 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("particle.proposal_approximation.cubature", "1"); driver.option_num("particle.proposal_approximation.unscented", "0"); driver.option_num("particle.proposal_approximation.montecarlo", "0");}
#line 5504 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1574:
#line 3091 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("particle.proposal_approximation.cubature", "0"); driver.option_num("particle.proposal_approximation.unscented", "1"); driver.option_num("particle.proposal_approximation.montecarlo", "0");}
#line 5510 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1575:
#line 3092 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("particle.proposal_approximation.cubature", "0"); driver.option_num("particle.proposal_approximation.unscented", "0"); driver.option_num("particle.proposal_approximation.montecarlo", "1");}
#line 5516 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1576:
#line 3093 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("particle.distribution_approximation.cubature", "1"); driver.option_num("particle.distribution_approximation.unscented", "0"); driver.option_num("particle.distribution_approximation.montecarlo", "0");}
#line 5522 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1577:
#line 3094 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("particle.distribution_approximation.cubature", "0"); driver.option_num("particle.distribution_approximation.unscented", "1"); driver.option_num("particle.distribution_approximation.montecarlo", "0");}
#line 5528 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1578:
#line 3095 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("particle.distribution_approximation.cubature", "0"); driver.option_num("particle.distribution_approximation.unscented", "0"); driver.option_num("particle.distribution_approximation.montecarlo", "1");}
#line 5534 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1579:
#line 3098 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("identification", (yystack_[0].value.string_val)); }
#line 5540 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1580:
#line 3099 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("morris", (yystack_[0].value.string_val)); }
#line 5546 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1581:
#line 3100 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("stab", (yystack_[0].value.string_val)); }
#line 5552 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1582:
#line 3101 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("redform", (yystack_[0].value.string_val)); }
#line 5558 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1583:
#line 3102 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("pprior", (yystack_[0].value.string_val)); }
#line 5564 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1584:
#line 3103 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("prior_range", (yystack_[0].value.string_val)); }
#line 5570 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1585:
#line 3104 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ppost", (yystack_[0].value.string_val)); }
#line 5576 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1586:
#line 3105 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ilptau", (yystack_[0].value.string_val)); }
#line 5582 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1587:
#line 3106 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("morris_nliv", (yystack_[0].value.string_val)); }
#line 5588 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1588:
#line 3107 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("morris_ntra", (yystack_[0].value.string_val)); }
#line 5594 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1589:
#line 3108 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("Nsam", (yystack_[0].value.string_val)); }
#line 5600 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1590:
#line 3109 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("load_redform", (yystack_[0].value.string_val)); }
#line 5606 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1591:
#line 3110 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("load_rmse", (yystack_[0].value.string_val)); }
#line 5612 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1592:
#line 3111 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("load_stab", (yystack_[0].value.string_val)); }
#line 5618 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1593:
#line 3112 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("alpha2_stab", (yystack_[0].value.string_val)); }
#line 5624 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1594:
#line 3113 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("logtrans_redform", (yystack_[0].value.string_val)); }
#line 5630 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1595:
#line 3114 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("threshold_redform",(yystack_[0].value.string_val)); }
#line 5636 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1596:
#line 3115 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ksstat_redform", (yystack_[0].value.string_val)); }
#line 5642 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1597:
#line 3116 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("alpha2_redform", (yystack_[0].value.string_val)); }
#line 5648 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1598:
#line 3117 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_symbol_list("namendo"); }
#line 5654 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1599:
#line 3118 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_symbol_list("namlagendo"); }
#line 5660 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1600:
#line 3119 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_symbol_list("namexo"); }
#line 5666 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1601:
#line 3120 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("rmse", (yystack_[0].value.string_val)); }
#line 5672 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1602:
#line 3121 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("lik_only", (yystack_[0].value.string_val)); }
#line 5678 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1603:
#line 3122 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_symbol_list("var_rmse"); }
#line 5684 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1604:
#line 3123 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("pfilt_rmse", (yystack_[0].value.string_val)); }
#line 5690 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1605:
#line 3124 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("istart_rmse", (yystack_[0].value.string_val)); }
#line 5696 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1606:
#line 3125 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("alpha_rmse", (yystack_[0].value.string_val)); }
#line 5702 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1607:
#line 3126 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("alpha2_rmse", (yystack_[0].value.string_val)); }
#line 5708 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1608:
#line 3128 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("gsa_sample_file", (yystack_[0].value.string_val)); }
#line 5714 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1609:
#line 3130 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("gsa_sample_file", (yystack_[0].value.string_val)); }
#line 5720 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1610:
#line 3132 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("neighborhood_width", (yystack_[0].value.string_val)); }
#line 5726 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1611:
#line 3133 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("pvalue_ks", (yystack_[0].value.string_val)); }
#line 5732 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1612:
#line 3134 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("pvalue_corr", (yystack_[0].value.string_val)); }
#line 5738 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1613:
#line 3135 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("load_ident_files", (yystack_[0].value.string_val)); }
#line 5744 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1614:
#line 3136 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("useautocorr", (yystack_[0].value.string_val)); }
#line 5750 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1615:
#line 3137 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("prior_mc", (yystack_[0].value.string_val)); }
#line 5756 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1616:
#line 3138 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("advanced", (yystack_[0].value.string_val)); }
#line 5762 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1617:
#line 3139 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("max_dim_cova_group", (yystack_[0].value.string_val)); }
#line 5768 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1618:
#line 3141 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("homotopy_mode",(yystack_[0].value.string_val)); }
#line 5774 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1619:
#line 3142 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("homotopy_steps",(yystack_[0].value.string_val)); }
#line 5780 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1620:
#line 3143 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("homotopy_force_continue",(yystack_[0].value.string_val)); }
#line 5786 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1621:
#line 3144 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("steadystate.nocheck","1"); }
#line 5792 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1622:
#line 3146 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_symbol_list("controlled_varexo"); }
#line 5798 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1623:
#line 3148 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("parameter_set", "prior_mode"); }
#line 5804 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1624:
#line 3150 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("parameter_set", "prior_mean"); }
#line 5810 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1625:
#line 3152 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("parameter_set", "posterior_mean"); }
#line 5816 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1626:
#line 3154 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("parameter_set", "posterior_mode"); }
#line 5822 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1627:
#line 3156 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("parameter_set", "posterior_median"); }
#line 5828 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1628:
#line 3158 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("parameter_set", "mle_mode"); }
#line 5834 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1629:
#line 3160 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("parameter_set", "calibration"); }
#line 5840 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1630:
#line 3162 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("nodecomposition", "1"); }
#line 5846 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1631:
#line 3163 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("SpectralDensity.trigger", "1"); }
#line 5852 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1632:
#line 3164 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.drop", (yystack_[0].value.string_val)); }
#line 5858 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1633:
#line 3165 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.mh_replic", (yystack_[0].value.string_val)); }
#line 5864 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1634:
#line 3167 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.freq",(yystack_[0].value.string_val)); }
#line 5870 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1635:
#line 3169 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.freq","12"); }
#line 5876 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1636:
#line 3171 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.freq","4"); }
#line 5882 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1637:
#line 3173 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.initial_year",(yystack_[0].value.string_val)); }
#line 5888 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1638:
#line 3174 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.initial_subperiod",(yystack_[0].value.string_val)); }
#line 5894 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1639:
#line 3175 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.final_year",(yystack_[0].value.string_val)); }
#line 5900 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1640:
#line 3176 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.final_subperiod",(yystack_[0].value.string_val)); }
#line 5906 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1641:
#line 3177 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("ms.data", (yystack_[0].value.string_val)); }
#line 5912 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1642:
#line 3178 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.vlist",(yystack_[0].value.string_val)); }
#line 5918 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1643:
#line 3179 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_symbol_list("ms.vlistlog"); }
#line 5924 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1644:
#line 3180 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.vlistper",(yystack_[0].value.string_val)); }
#line 5930 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1645:
#line 3182 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                        driver.warning("restriction_fname is now deprecated, and may be removed in a future version of Dynare. Use svar_identification instead.");
                        driver.option_str("ms.restriction_fname",(yystack_[0].value.string_val));
                      }
#line 5939 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1646:
#line 3187 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                        driver.warning("restriction_fname is now deprecated, and may be removed in a future version of Dynare. Use svar_identification instead.");
                        driver.option_str("ms.restriction_fname","upper_cholesky");
                      }
#line 5948 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1647:
#line 3192 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                        driver.warning("restriction_fname is now deprecated, and may be removed in a future version of Dynare. Use svar_identification instead.");
                        driver.option_str("ms.restriction_fname","lower_cholesky");
                      }
#line 5957 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1648:
#line 3197 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.nlags",(yystack_[0].value.string_val)); }
#line 5963 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1649:
#line 3198 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.cross_restrictions","1"); }
#line 5969 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1650:
#line 3199 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.contemp_reduced_form","1"); }
#line 5975 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1651:
#line 3200 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.real_pseudo_forecast",(yystack_[0].value.string_val)); }
#line 5981 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1652:
#line 3201 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.bayesian_prior","0"); }
#line 5987 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1653:
#line 3202 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.dummy_obs",(yystack_[0].value.string_val)); }
#line 5993 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1654:
#line 3203 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.nstates",(yystack_[0].value.string_val)); }
#line 5999 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1655:
#line 3204 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.indxscalesstates",(yystack_[0].value.string_val)); }
#line 6005 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1656:
#line 3205 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.alpha",(yystack_[0].value.string_val)); }
#line 6011 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1657:
#line 3206 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.beta",(yystack_[0].value.string_val)); }
#line 6017 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1658:
#line 3207 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.gsig2_lmdm",(yystack_[0].value.string_val)); }
#line 6023 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1659:
#line 3209 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.specification","1"); }
#line 6029 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1660:
#line 3211 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.specification","0"); }
#line 6035 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1661:
#line 3213 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.q_diag",(yystack_[0].value.string_val)); }
#line 6041 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1662:
#line 3214 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.flat_prior",(yystack_[0].value.string_val)); }
#line 6047 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1663:
#line 3215 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.ncsk",(yystack_[0].value.string_val)); }
#line 6053 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1664:
#line 3216 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.nstd",(yystack_[0].value.string_val)); }
#line 6059 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1665:
#line 3217 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.ninv",(yystack_[0].value.string_val)); }
#line 6065 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1666:
#line 3218 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.indxparr",(yystack_[0].value.string_val)); }
#line 6071 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1667:
#line 3219 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.indxovr",(yystack_[0].value.string_val)); }
#line 6077 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1668:
#line 3220 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.aband",(yystack_[0].value.string_val)); }
#line 6083 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1669:
#line 3221 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.indxap",(yystack_[0].value.string_val)); }
#line 6089 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1670:
#line 3222 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.apband",(yystack_[0].value.string_val)); }
#line 6095 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1671:
#line 3223 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.indximf",(yystack_[0].value.string_val)); }
#line 6101 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1672:
#line 3224 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.indxfore",(yystack_[0].value.string_val)); }
#line 6107 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1673:
#line 3225 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.foreband",(yystack_[0].value.string_val)); }
#line 6113 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1674:
#line 3226 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.indxgforehat",(yystack_[0].value.string_val)); }
#line 6119 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1675:
#line 3227 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.indxgimfhat",(yystack_[0].value.string_val)); }
#line 6125 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1676:
#line 3228 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.indxestima",(yystack_[0].value.string_val)); }
#line 6131 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1677:
#line 3229 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.indxgdls",(yystack_[0].value.string_val)); }
#line 6137 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1678:
#line 3230 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.eq_ms",(yystack_[0].value.string_val)); }
#line 6143 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1679:
#line 3231 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.cms",(yystack_[0].value.string_val)); }
#line 6149 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1680:
#line 3232 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.ncms",(yystack_[0].value.string_val)); }
#line 6155 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1681:
#line 3233 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.eq_cms",(yystack_[0].value.string_val)); }
#line 6161 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1682:
#line 3234 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.tlindx",(yystack_[0].value.string_val)); }
#line 6167 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1683:
#line 3235 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.tlnumber",(yystack_[0].value.string_val)); }
#line 6173 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1684:
#line 3236 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.cnum",(yystack_[0].value.string_val)); }
#line 6179 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1685:
#line 3237 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("k_order_solver","1"); }
#line 6185 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1686:
#line 3238 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("pruning", "1"); }
#line 6191 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1687:
#line 3239 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.chain",(yystack_[0].value.string_val)); }
#line 6197 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1688:
#line 3241 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.restrictions",(yystack_[0].value.string_val)); }
#line 6203 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1689:
#line 3244 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.duration",(yystack_[0].value.string_val)); }
#line 6209 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1690:
#line 3246 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.duration",(yystack_[0].value.string_val)); }
#line 6215 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1691:
#line 3248 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.number_of_regimes",(yystack_[0].value.string_val)); }
#line 6221 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1692:
#line 3249 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.number_of_lags",(yystack_[0].value.string_val)); }
#line 6227 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1693:
#line 3250 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_symbol_list("ms.parameters"); }
#line 6233 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1694:
#line 3251 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("ms.coefficients","svar_coefficients"); }
#line 6239 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1695:
#line 3252 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("ms.variances","svar_variances"); }
#line 6245 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1696:
#line 3254 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_vec_int("ms.equations",(yystack_[0].value.vector_int_val)); }
#line 6251 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1697:
#line 3256 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_vec_int("ms.equations",(yystack_[0].value.vector_int_val)); }
#line 6257 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1698:
#line 3258 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("silent_optimizer", "1"); }
#line 6263 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1699:
#line 3259 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_symbol_list("instruments"); }
#line 6269 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1700:
#line 3261 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.external_function_option("name", (yystack_[0].value.string_val)); }
#line 6275 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1701:
#line 3262 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.external_function_option("nargs",(yystack_[0].value.string_val)); }
#line 6281 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1702:
#line 3264 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.external_function_option("first_deriv_provided", (yystack_[0].value.string_val)); }
#line 6287 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1703:
#line 3266 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.external_function_option("first_deriv_provided", ""); }
#line 6293 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1704:
#line 3269 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.external_function_option("second_deriv_provided", (yystack_[0].value.string_val)); }
#line 6299 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1705:
#line 3271 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.external_function_option("second_deriv_provided", ""); }
#line 6305 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1706:
#line 3274 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("filter_covariance","1");}
#line 6311 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1707:
#line 3277 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("filter_decomposition","1");}
#line 6317 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1708:
#line 3280 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("smoothed_state_uncertainty","1");}
#line 6323 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1709:
#line 3283 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("selected_variables_only","1");}
#line 6329 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1710:
#line 3286 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("cova_compute",(yystack_[0].value.string_val));}
#line 6335 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1711:
#line 3288 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_str("ms.output_file_tag", (yystack_[0].value.string_val)); }
#line 6341 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1712:
#line 3289 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("ms.file_tag", (yystack_[0].value.string_val)); }
#line 6347 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1713:
#line 3290 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.create_init", "0"); }
#line 6353 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1714:
#line 3291 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("ms.simulation_file_tag", (yystack_[0].value.string_val)); }
#line 6359 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1715:
#line 3293 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.coefficients_prior_hyperparameters",(yystack_[0].value.string_val)); }
#line 6365 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1716:
#line 3295 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.convergence_starting_value",(yystack_[0].value.string_val)); }
#line 6371 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1717:
#line 3297 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.convergence_ending_value",(yystack_[0].value.string_val)); }
#line 6377 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1718:
#line 3299 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.convergence_increment_value",(yystack_[0].value.string_val)); }
#line 6383 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1719:
#line 3301 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.max_iterations_starting_value",(yystack_[0].value.string_val)); }
#line 6389 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1720:
#line 3303 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.max_iterations_increment_value",(yystack_[0].value.string_val)); }
#line 6395 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1721:
#line 3305 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.max_block_iterations",(yystack_[0].value.string_val)); }
#line 6401 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1722:
#line 3307 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.max_repeated_optimization_runs",(yystack_[0].value.string_val)); }
#line 6407 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1723:
#line 3309 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.function_convergence_criterion",(yystack_[0].value.string_val)); }
#line 6413 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1724:
#line 3311 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.parameter_convergence_criterion",(yystack_[0].value.string_val)); }
#line 6419 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1725:
#line 3313 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.number_of_large_perturbations",(yystack_[0].value.string_val)); }
#line 6425 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1726:
#line 3315 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.number_of_small_perturbations",(yystack_[0].value.string_val)); }
#line 6431 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1727:
#line 3317 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.number_of_posterior_draws_after_perturbation",(yystack_[0].value.string_val)); }
#line 6437 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1728:
#line 3319 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.max_number_of_stages",(yystack_[0].value.string_val)); }
#line 6443 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1729:
#line 3321 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.random_function_convergence_criterion",(yystack_[0].value.string_val)); }
#line 6449 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1730:
#line 3323 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.random_parameter_convergence_criterion",(yystack_[0].value.string_val)); }
#line 6455 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1731:
#line 3324 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.thinning_factor",(yystack_[0].value.string_val)); }
#line 6461 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1732:
#line 3325 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.adaptive_mh_draws",(yystack_[0].value.string_val)); }
#line 6467 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1733:
#line 3326 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.save_draws","1"); }
#line 6473 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1734:
#line 3327 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.proposal_draws",(yystack_[0].value.string_val)); }
#line 6479 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1735:
#line 3328 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.use_mean_center","1"); }
#line 6485 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1736:
#line 3329 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.proposal_type",(yystack_[0].value.string_val)); }
#line 6491 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1737:
#line 3330 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.proposal_lower_bound",(yystack_[0].value.string_val)); }
#line 6497 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1738:
#line 3331 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.proposal_upper_bound",(yystack_[0].value.string_val)); }
#line 6503 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1739:
#line 3332 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.parameter_uncertainty","1"); }
#line 6509 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1740:
#line 3333 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.horizon",(yystack_[0].value.string_val)); }
#line 6515 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1741:
#line 3334 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.filtered_probabilities","1"); }
#line 6521 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1742:
#line 3335 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.real_time_smoothed_probabilities","1"); }
#line 6527 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1743:
#line 3336 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.error_bands","0"); }
#line 6533 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1744:
#line 3337 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.percentiles",(yystack_[0].value.string_val)); }
#line 6539 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1745:
#line 3338 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.shock_draws",(yystack_[0].value.string_val)); }
#line 6545 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1746:
#line 3339 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.shocks_per_parameter",(yystack_[0].value.string_val)); }
#line 6551 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1747:
#line 3340 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.free_parameters",(yystack_[0].value.string_val)); }
#line 6557 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1748:
#line 3341 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.median","1"); }
#line 6563 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1749:
#line 3342 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("median", (yystack_[0].value.string_val)); }
#line 6569 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1750:
#line 3343 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.regimes","1"); }
#line 6575 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1751:
#line 3344 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.regime",(yystack_[0].value.string_val)); }
#line 6581 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1752:
#line 3345 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.forecast_data_obs",(yystack_[0].value.string_val)); }
#line 6587 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1753:
#line 3346 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("discretionary_tol",(yystack_[0].value.string_val)); }
#line 6593 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1754:
#line 3347 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("analytic_derivation", "1"); }
#line 6599 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1755:
#line 3348 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("analytic_derivation_mode", (yystack_[0].value.string_val)); }
#line 6605 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1756:
#line 3349 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("endogenous_prior", "1"); }
#line 6611 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1757:
#line 3350 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("use_univariate_filters_if_singularity_is_detected", (yystack_[0].value.string_val)); }
#line 6617 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1758:
#line 3352 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("MCMC_jumping_covariance", (yystack_[0].value.string_val)); }
#line 6623 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1759:
#line 3353 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("MCMC_jumping_covariance", (yystack_[0].value.string_val)); }
#line 6629 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1760:
#line 3355 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("MCMC_jumping_covariance", (yystack_[0].value.string_val)); }
#line 6635 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1761:
#line 3357 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("MCMC_jumping_covariance", (yystack_[0].value.string_val)); }
#line 6641 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1762:
#line 3359 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("rescale_prediction_error_covariance", "true"); }
#line 6647 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1763:
#line 3360 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("hessian.use_penalized_objective","true"); }
#line 6653 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1764:
#line 3361 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("impulse_responses.plot_threshold", (yystack_[0].value.string_val)); }
#line 6659 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1765:
#line 3362 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("dr_display_tol", (yystack_[0].value.string_val)); }
#line 6665 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1766:
#line 3363 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("endo_vars_for_moment_computations_in_estimation", "all_endogenous_variables"); }
#line 6671 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1767:
#line 3364 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("endo_vars_for_moment_computations_in_estimation", "only_observed_variables"); }
#line 6677 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1768:
#line 3365 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("no_homotopy", "1"); }
#line 6683 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1769:
#line 3367 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("infile", (yystack_[0].value.string_val)); }
#line 6689 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1770:
#line 3368 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_symbol_list("invars"); }
#line 6695 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1771:
#line 3369 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("period", (yystack_[0].value.string_val)); }
#line 6701 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1772:
#line 3370 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("outfile", (yystack_[0].value.string_val)); }
#line 6707 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1773:
#line 3371 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_symbol_list("outvars"); }
#line 6713 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1774:
#line 3372 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("lmmcp.status", "1"); }
#line 6719 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1775:
#line 3373 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("function", (yystack_[0].value.string_val)); }
#line 6725 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1776:
#line 3374 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("sampling_draws",(yystack_[0].value.string_val)); }
#line 6731 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1777:
#line 3375 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("plot_shock_decomp.use_shock_groups","default"); }
#line 6737 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1778:
#line 3376 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("plot_shock_decomp.use_shock_groups", (yystack_[0].value.string_val)); }
#line 6743 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1779:
#line 3378 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("plot_shock_decomp.colormap",(yystack_[0].value.string_val)); }
#line 6749 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1780:
#line 3381 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
          (yystack_[2].value.string_val)->append(":");
          (yystack_[2].value.string_val)->append(*(yystack_[0].value.string_val));
          delete (yystack_[0].value.string_val);
          (yylhs.value.string_val) = (yystack_[2].value.string_val);
        }
#line 6760 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1781:
#line 3389 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                  (yystack_[2].value.string_val)->append(":");
                  (yystack_[2].value.string_val)->append(*(yystack_[0].value.string_val));
                  delete (yystack_[0].value.string_val);
                  (yylhs.value.string_val) = (yystack_[2].value.string_val);
                }
#line 6771 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1782:
#line 3397 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                         (yystack_[2].value.string_val)->append(":");
                         (yystack_[2].value.string_val)->append(*(yystack_[0].value.string_val));
                         delete (yystack_[0].value.string_val);
                         (yylhs.value.string_val) = (yystack_[2].value.string_val);
                       }
#line 6782 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1783:
#line 3404 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                         (yystack_[3].value.string_val)->insert(0, "-(");
                         (yystack_[3].value.string_val)->append(":");
                         (yystack_[3].value.string_val)->append(*(yystack_[1].value.string_val));
                         delete (yystack_[1].value.string_val);
                         (yystack_[3].value.string_val)->append(")");
                         (yylhs.value.string_val) = (yystack_[3].value.string_val);
                       }
#line 6795 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1784:
#line 3413 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.vector_int_val) = new vector<int>(); (yylhs.value.vector_int_val)->push_back(atoi((*(yystack_[0].value.string_val)).c_str())); delete (yystack_[0].value.string_val); }
#line 6801 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1786:
#line 3417 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                 (yylhs.value.vector_int_val) = new vector<int>();
                 for(int i=atoi((*(yystack_[2].value.string_val)).c_str()); i<=atoi((*(yystack_[0].value.string_val)).c_str()); i++)
                   (yylhs.value.vector_int_val)->push_back(i);
                 delete (yystack_[2].value.string_val);
                 delete (yystack_[0].value.string_val);
               }
#line 6813 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1787:
#line 3427 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.vector_int_val) = (yystack_[0].value.vector_int_val);}
#line 6819 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1788:
#line 3429 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.vector_int_val) = (yystack_[0].value.vector_int_val);}
#line 6825 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1789:
#line 3431 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
              (yylhs.value.vector_int_val) = (yystack_[1].value.vector_int_val);
              for (vector<int>::const_iterator it=(yystack_[0].value.vector_int_val)->begin();
                   it!=(yystack_[0].value.vector_int_val)->end(); it++)
                (yystack_[1].value.vector_int_val)->push_back(*it);
              delete (yystack_[0].value.vector_int_val);
            }
#line 6837 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1790:
#line 3439 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
              (yylhs.value.vector_int_val) = (yystack_[2].value.vector_int_val);
              for (vector<int>::const_iterator it=(yystack_[0].value.vector_int_val)->begin();
                   it!=(yystack_[0].value.vector_int_val)->end(); it++)
                (yystack_[2].value.vector_int_val)->push_back(*it);
              delete (yystack_[0].value.vector_int_val);
            }
#line 6849 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1791:
#line 3449 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.vector_int_val) = (yystack_[1].value.vector_int_val); }
#line 6855 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1792:
#line 3451 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.vector_int_val) = (yystack_[2].value.vector_int_val); }
#line 6861 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1793:
#line 3454 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yystack_[0].value.string_val)->insert(0,"["); (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 6867 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1794:
#line 3455 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yystack_[0].value.string_val)->insert(0,"["); (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 6873 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1795:
#line 3457 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                (yystack_[1].value.string_val)->append(" ");
                (yystack_[1].value.string_val)->append(*(yystack_[0].value.string_val));
                delete (yystack_[0].value.string_val);
                (yylhs.value.string_val) = (yystack_[1].value.string_val);
              }
#line 6884 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1796:
#line 3464 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                (yystack_[2].value.string_val)->append(" ");
                (yystack_[2].value.string_val)->append(*(yystack_[0].value.string_val));
                delete (yystack_[0].value.string_val);
                (yylhs.value.string_val) = (yystack_[2].value.string_val);
              }
#line 6895 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1797:
#line 3472 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yystack_[1].value.string_val)->append("]"); (yylhs.value.string_val) = (yystack_[1].value.string_val); }
#line 6901 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1798:
#line 3473 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yystack_[2].value.string_val)->append("]"); (yylhs.value.string_val) = (yystack_[2].value.string_val); }
#line 6907 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1799:
#line 3477 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                   (yystack_[2].value.string_val)->append(",");
                   (yystack_[2].value.string_val)->append(*(yystack_[0].value.string_val));
                   delete (yystack_[0].value.string_val);
                   (yylhs.value.string_val) = (yystack_[2].value.string_val);
                 }
#line 6918 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1800:
#line 3484 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 6924 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1801:
#line 3487 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.string_val) = (yystack_[1].value.string_val); }
#line 6930 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1802:
#line 3488 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 6936 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1803:
#line 3491 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yystack_[0].value.string_val)->insert(0, "["); (yylhs.value.string_val) = (yystack_[0].value.string_val);}
#line 6942 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1804:
#line 3493 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                      (yystack_[1].value.string_val)->append(" ");
                      (yystack_[1].value.string_val)->append(*(yystack_[0].value.string_val));
                      delete (yystack_[0].value.string_val);
                      (yylhs.value.string_val) = (yystack_[1].value.string_val);
                    }
#line 6953 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1805:
#line 3501 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yystack_[1].value.string_val)->append("]"); (yylhs.value.string_val) = (yystack_[1].value.string_val); }
#line 6959 "DynareBison.cc" // lalr1.cc:859
    break;


#line 6963 "DynareBison.cc" // lalr1.cc:859
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
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
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
    if (!yyla.empty ())
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
        if (!yyla.empty ())
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
  parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
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
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
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

    std::string yyres;
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


  const short int parser::yypact_ninf_ = -2945;

  const short int parser::yytable_ninf_ = -1826;

  const short int
  parser::yypact_[] =
  {
    4468,   158,   161,  7103,  -217,   -57,  -190,  -224,  -182,  7126,
     246,  -179,  -172,   230,  7205,  -168,  -161,   237,   302,  -155,
    -152,  7302,  -150,   344,  -142,  -136,   385,   416,  -120,   431,
    -107,   -97,   497,  7363,   541,   567,  -128,  -101, -2945,   -73,
     -59,  7382, 10641, 10641,   301, -2945,  7736,   604,   609, 10641,
     -92,   723,  7401,   733,   420,   783,   785,   -48,   809,  7420,
    7442,  7461,  7480,   -43,  7559, 10641,  7755, 10641, 10641, -2945,
   10641,  7659,   819,   -40,   -19,   823,   -72, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945,   825,   -29,  7717,   831,
     833,   837,   855,   873,   892, -2945,   -15,   -11,   -16,    -5,
     148,   256,   -42,   878, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,    97, -2945,
   -2945,   750, -2945, -2945,   782, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945,   105,   271,  3450,   281,  2690, -2945,
     807,  7912, -2945,   193, -2945,  1984,   821,   531, 10641, -2945,
    1161,  8050,   171, 10732, 10732, 10641,   842, -2945,  5055,  8069,
    2421,  3542,  3606,   894, -2945,   779,   828, 10641, -2945,   836,
    8088, 10641, 10641,   898,   835, 10641, -2945,  2149, 10641,   910,
     851, 10641,   661, 10732,   795, -2945,   808, -2945,   802,   380,
    7774, -2945, -2945, -2945,   634,   724, -2945, 10641, 10641, 10641,
   -2945,  6628,  8107,  8126,  8264,   110,   870,   427,  6208,   768,
    8372, -2945,   707, -2945,  3541,  8402, 10732,   277,   754, -2945,
     633,  8421, 10764,   812,   457, -2945,  1131, -2945,   991, -2945,
   -2945,  2097, -2945,  6788,  8440, -2945,   175,  8459, -2945,   235,
    8480, -2945,  7108,  8618,   845, -2945,  6948,  8696,  8726,   131,
    8756,   123,  8775,   125,  8804,   130, 10641,  8834, -2945, -2945,
    2340,  8913, -2945,   844, -2945, -2945, -2945,  3537,   459, -2945,
    2342,   571, -2945,  1740,  8942, -2945,  1709, -2945,  1750, -2945,
     210, -2945,   760, -2945,   485, -2945,  2660,   500,   306,   476,
   -2945,   679,    35,    35,   625, -2945, -2945,  2800, 10641,  3795,
    3847,  6253, 10404, -2945,  1016, -2945,  1019,  1022,  1027,  1033,
    1036, -2945,  1058,  1087,  1089, -2945,  1091,  1097,  1100,  1107,
   -2945,   822,   641, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
    1109,  1171,  1182, -2945,   913,   699, -2945, -2945, -2945,  1216,
   -2945,  1221, -2945, -2945, -2945, -2945,   719,   951, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, 10641, -2945,
   -2945, -2945, -2945, -2945, -2945,   758, -2945,  1269,  1289,  1295,
    1308,  1325,  1335,  1337,  1343, -2945,   -13, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945,  1347,  1349,  1365,
    1367,  1369,    51, -2945, -2945, -2945, -2945, -2945, -2945, 10641,
     287, -2945,  1102, -2945, -2945, -2945,  1398,  1402,  1404,   895,
    1127, -2945, -2945, -2945, -2945, -2945, -2945, -2945,   903, -2945,
     904,   906,  1629, -2945,  1413,   907, -2945, -2945,  1420,  1422,
   -2945, -2945, -2945,  1423,  1424,  1427, -2945, -2945,  1429,  1430,
    1431, -2945,  1432,  1433, -2945, -2945,  1434,  1439,  1440,  1441,
    1443, -2945,  1445,  1454,  1455,  1456, -2945, -2945, -2945,  1458,
    1459,  1460,  1461,  1462,  1465,  1468,  1470,  1471,  1472, -2945,
    1477, -2945,  1478,  1495,  1507,  1513,  1515, -2945, -2945,  1517,
    1518,  1521,  1527, -2945,  1528,  1531,  1532,  1534,  1535,  1536,
    1542,  1544,  1549,  1560, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945,  1565,  1567, -2945,  1569, -2945,  1573,  1576,  1578, -2945,
   -2945,  1581,  1582, -2945,  1584,  1585, -2945,  1586, -2945,  1591,
     113, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, 10641, -2945, 10641,  2139, -2945,   179, -2945,
   10641, 10641,  2658, -2945,  1329, 10641, 10641,  2678, -2945,  1344,
    1115, -2945,  1631,  1632, -2945,  1125,  1355, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945,   254,  3911, -2945,  1359,   137, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945,  1132,  4000, -2945,  1136,
    1141,  1653,  4494, -2945,  1373,  1660,  1662,  1665,  1666,  1668,
    1669,  1671,  1674,  1167,  1396, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945,  4974,  1173,  1681,  5009, -2945,
       7,  1174,  1175,  1687,  5224, -2945, -2945,  1691,  1708, -2945,
    1714, -2945,  1716, -2945, -2945,   168, -2945, -2945, -2945,  1720,
    1199,   308, 10732, -2945,  1215,   173, -2945, 10641, -2945,   340,
    1217,  5073, -2945,  1444,  5172, -2945,  1227,  5320,  4045,  1737,
    1744,  1766,  1779, -2945,  1783,  1785,  1788,  1789, -2945, -2945,
   -2945, -2945, -2945, -2945,  1790,  1791, -2945,  1793,  1794, -2945,
     226, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, 10641, -2945,   134,  1286, 10794,  6067, -2945,  1293,
   -2945, -2945, -2945,  1298,  1299,  1300,  1304,  6208,  6208,  1311,
    1312,  1313,  1319,  1339,  1340,  1341,  1345,  1346,  1348,  1350,
    1351,  1352,  1353,  1357,  1361,  6208,  2992, -2945,  1362,  1804,
   -2945,   333, -2945, -2945, -2945,  1817,  1838, -2945,  1846,  1864,
   -2945, -2945,  1873, -2945,   353, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,  1364,
   10641, 10641,   350, -2945, -2945,  1366,  1875, -2945,  1877,  1878,
    1370,  1599, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945,  1883,   599, -2945,  1884,  1888,   248, -2945, -2945,   358,
   -2945,  1889,  1892,  1893,  1894,  1895,  1386,  1616, -2945, -2945,
   -2945, -2945, -2945,  6015,   404, -2945,  1899,  1900, -2945,   433,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,  1901,  1902,
    1903,  1394,  1624, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945,  1907,  1909,   434, -2945, -2945, -2945,
   -2945, -2945,   435, -2945, -2945, -2945, -2945,   756,   293, -2945,
    1912,  1913,   439, -2945, -2945, -2945, -2945, -2945, -2945,  1917,
    1920, 10641, -2945,   136,  1286, -2945, 10641, -2945,   141,  1286,
   -2945, 10641, -2945,   142,  1286, -2945,  8972, -2945, 10641, -2945,
   -2945,  1922, -2945, -2945, -2945, -2945, -2945,  1926,  1928,  1929,
    1930,  1932,  1933, -2945,  1426,  1652, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945,  1435,  1937,  1939,  1941,  1943,  1946,  1948,  1949,
    1950,  1951,  1952,  1954,  1957,  1958,  1959,  1960,  1963,  1965,
    1966,  1967,  1968,  1970,  1973,  1974,  1976,  1977,  1979,  1981,
    1982,  1983,  1985,  1988,  1474,  1693, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945,  1989,  1990,  1992,
    1993,  1994,   444, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945,  1995,  1997,  1998,  1999,  2019,  2021,  2022,  2028,  2029,
    2030, -2945,  2031, -2945,  2032,  2033,  2035,  2041, -2945,  2042,
    2043,  2044,  2045,  2048,  2049,  2052,  2059,  2063,  2064,  2065,
    2068,  2071,  2072,  2073,  2075,  2078,  2079,  2081,  2087,  2088,
    2089,  2090,  2091,  2092,  2094,  2104,  2105,  1821,  1596, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945,  2107, -2945, -2945,
    2108,  2109,  2110,  2114,  2116,  2117,  2120,  2123,  2124,  2125,
   -2945,  2127,  1847,  1620, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
    1849,  1626, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945,  2134, -2945,  2142,  2143,
    2145,  2146,  2147,  2148,  2150,  2151,  2152,  2154,  2155,  2156,
    2157,  2159,  2169,  1867,  1661, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
    2172,  2179, -2945,  2184,  1904,  1675, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945,  2188,  2189,  2192,  2194, -2945,  1914,  1689,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,  1915,
    1690, -2945, -2945, -2945, -2945,  2202,  1921,  1704, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945,   -27,  2217,  2219,  2222,  2225,  2227,  2230,   449,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,  2231,
     480, -2945, -2945, -2945, -2945, -2945,  2232,  2233,  2234,  2235,
     481, -2945, -2945, -2945, -2945, -2945,  2238,  2239,   493, -2945,
   -2945, -2945,   501, -2945,  1762,  1763,  1741,  1760,   502, -2945,
    2276,  1768,  1769,  1772,  1767,  1775,  1776,  1773,  1771, -2945,
    1781,  1787,  1795,  1796, -2945,  6253,  6253,  1799,  1802,  1803,
    1805,  1807,  1808,  1809,  1810,  1811,  1812,  1814,  1815,  1818,
    1823,  6253,  2960, -2945,  1827, -2945,  1829,   107,  1782,   308,
     620,   308,  2241,   620,  2242, 10732,  2256,    87,  2273,  2282,
   10641, 10641,  3450,  2283,  2285,   308,  2286,  2690,  2288,  1836,
     308,  8155,   807, -2945, 10641,  2291,  2295,  2298,   308,   308,
    2299,   308,  2300,  1984,  1850,   308,  1851,  1008,  2304,  2305,
     821,  1856,  1858,  1860, -2945, 10641,   479,   828,   828,  8864,
    1161, -2945,  9867,  9886,  1861, -2945,  6253,  1862,  2314,  2163,
     308, 10641,   308,   308,   308,  2316, 10732,    87,   739,    87,
    2318,  1868,   308,  2321,   308,  2323,  2324,   623,   308,   308,
     308,   308,   308,   308,  2325,  2326,  2339,  2343,   313,  2344,
    2347, 10428, 10732,  2348,  1836,  1897,  1897, 10548,  2354,   239,
     308,   687,   769,  2355, 10641,   797,  1028,  1890,  2358,  2359,
     308,   286,  2360,  1156,   308,  2362,   366,  1911,  2364,  5055,
    9915,  2140, -2945,  1916, -2945,   781, -2945,  2141,  2153,  1919,
   -2945,  6253,  2158,  2160,  1923, -2945,  6253,  1924,  2371,  2372,
    1925,   779,  2373,  1935,  1936, -2945,  6253,   836,  9945,  1931,
    1940, -2945,   525,  1942, 10732,  1945, -2945,  6253,   620,  2377,
    2379,   525,  2381,  2384, 10333,  2388,  1956,  2149,  1961,  1969,
   10732,  1971, -2945, 10641,  2394,  1972,  1986, -2945,  2315, 10641,
    3734, -2945,   138, -2945,   308,  1978,  2417,  1980,   808,  1991,
     238, 10732,  1987,  1996,   308, -2945,  2036,  2038,  2040, -2945,
    2053,  2054, -2945, 10641,  2056, -2945,  6253,  2057,  5520, 10641,
    3005,   308,  2419,  2425, 10527,   308,  2427,   308,  2434,   308,
    2436,  2439,  2441,  6628,  9975,   144,  1286, -2945, -2945, 10641,
   -2945,  2478,  5270, -2945, -2945, -2945,  6208,  6208,  6208,  6208,
     611,  2205,  6208,  6208,  6208,  6208,  6208,  6208,  6208,  6208,
    6208,  6208,  6208,  6208,  6208,  6208,  6208,   525,  1088,  6208,
    6208,  6208,  6208,  6208,  6208,  6208,  6208,  6208,  6208,  6208,
    2067,  2020,  2445,   707,  2069,   308,   308,  2446,   308,  2447,
    3541,  2070,  2074,  2224,   182,  2080, -2945,  2084,  2473, 10641,
   10641, 10053,   633, 10641,  2085, -2945, 10641, 10641,   308,   308,
    6253,  -144,   258, -2945, -2945,  1131,  2086, 10732,  2034, 10732,
    2051,  2493,  2093,   991, 10641,   191, -2945,  2551,  2097,  2095,
     308,  1836,  6788, 10083,  2496,  2500,  1836, 10123,   175,  2058,
    6253,   235, 10152,  7108, 10191,  6253,  6253,  6253,  6253,  2096,
   -2945,  2514,   308,  6948, 10221, -2945, -2945,   147,  1286, -2945,
   -2945,   149,  1286, -2945, -2945,   176,  1286, -2945, -2945, 10641,
   -2945, -2945, -2945, 10732,   926,  2515,  2519,   852,   828,   828,
   10240,  2340,  2099,  2523,  2524,  2526,  2529,  2530,  2532,  2538,
    2541,  2542,  2543,  2545,  2548,  2552,   308,  2553,  2100,   308,
     308,  2106,  2111,  2112,  2555,  2559,  2113,   308,  2560,   308,
     308,   308,   308,   308,  2118,  3537, 10732, 10641,   828,   828,
    2562,   459,  2119,   181,  2571,  2572,  2573,  2574, 10732,  2575,
    2128,  2586,   114,  2587,  2588,  2593,  2594,  2596,   308,   308,
    2598,  2600,  2601,  2602,  2603,  2605,   308,  2608,  2609,  2611,
    2612,  2613,  2614,  2615,  2616,  2620,  2621,  2622,  2623,  2625,
    2626,  2628,  2629,  2630,  2631,  1897,  2342,  2130, -2945,  2639,
   10732,  2640, 10732, 10732,  1897,  2643,  2655,  1897,   620,  2663,
    1740, 10261,  1709,  2213,   -17,   308,   308,   308,  2665,   308,
    2666,  2667,   308,   308,  2668,  2669,  2671,  2672,   308,   308,
    1750,  2223,  2673,  2675,  2676,   210,  2226,  2684,   620,   620,
    2685,   760,  2240,   485,  2259,  2711,  2660,  2261,  2296,   -65,
    2262,  2263,   338, -2945,  2264,  2268,  2715,   177,  2717,  2724,
     306,  2274,    87,   476,  2275, 10732,  2727, 10732, 10732,   679,
    2277, 10732,  2731,    35,  2281,  2306,  2303, 10641, 10641, -2945,
    2722, 10641,  2307,   828, 10641, 10641, -2945, 10848, 10641, 10641,
   -2945, 10611,  6253,  6253,  6253,  6253,  2518,  2518,  6253,  6253,
    6253,  6253,  6253,  6253,  6253,  6253,  6253,  6253,  6253,  6253,
    6253,  6253,  2171,  6253,  6253,  6253,  6253,  6253,  6253,  6253,
    6253,  6253,  6253,  6253, -2945,  2308,  1166,  2309,   192, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,   264, -2945,
     126, -2945, -2945, -2945, -2945, -2945,  2313, -2945,  2311, -2945,
   -2945, -2945, -2945,  2312, -2945, -2945, -2945,  9021, -2945,  9080,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, 10641, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945,  2633, -2945,  2319, -2945, -2945, -2945,
    2533,  2533, -2945,  9129, -2945, -2945,  9188, -2945,  9237, -2945,
    3859, 10641, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945,   749, -2945, -2945,
   -2945, -2945, 10641, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945,   336,   357, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945,   418,   194, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945,  2619, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945,  2624, -2945, -2945, -2945,  9267,
   10641, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
    4655,  2556,  2327,  2557, 10641,  6253, -2945,  3370, 10641,  6253,
   -2945,  4679,  2780, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
    3402, -2945, -2945,  9296, 10477, -2945, -2945,  2766,  2777,  2332,
   10641,  2333, -2945,  2250, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, 10641,  2335, -2945,  2564,
     -47,  2338, 10641, -2945,  6208,  2851,   -22, -2945,  2852,  2345,
   -2945, -2945,  6208, -2945, -2945, 10641, -2945, 10732, -2945, -2945,
   -2945, -2945,  7799, -2945,   308,  2349, -2945, -2945,  2686, -2945,
     634, -2945,    30, -2945,  2581, -2945, 10641,  5379,  6253, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945,  9345,  1286, -2945, -2945, -2945,
    2645, -2945, -2945,  5793,  5830,  2926,  3096,  3277,  3303,  3616,
    3649,  3801,  3846,  3975,  4018,  4031,  4107,  4277,  4488,   902,
    1104,  4514,  2350, -2945,  1012,  1012,   909,   909,   909,   909,
     611,   611,  2205,  2205,  2566, -2945,  6208,  2365, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, 10641,  6253,
   10641,   154, -2945,   277, -2945, -2945, -2945, -2945,  9375, -2945,
    9405, -2945, -2945,  9453,  2367, -2945, -2945,  4694,   248,  2380,
     263,  6253, -2945, -2945, -2945, -2945, 10641, -2945, 10641, -2945,
   -2945, -2945,  4373,  2382, -2945,  6253, -2945, -2945, -2945, -2945,
   -2945, -2945,  9483, -2945, -2945, -2945, -2945,  9513, -2945, 10641,
    3478, -2945, -2945,  9561, -2945, -2945, 10290, -2945, -2945,  5987,
    8403,  8422,  8441, -2945, -2945, -2945, -2945, -2945,  9591,  6208,
    6208,  1286, -2945, -2945,  1286, -2945, -2945,  1286, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945,   749, -2945,  2533,
    2533, -2945,  9621, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
     313,   223, -2945, -2945, -2945,  4294,  4294,  4294, -2945, -2945,
    4294, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945,  2533,  2533, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, 10641, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945,  6208, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
    9669, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,  2798,  2822,
    2383, -2945, -2945,  2386, -2945, 10641,   211, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945,   269,  2599,  2375, -2945, -2945,   180,  2607,  2385,  2387,
    2393,  2610,  2389, -2945,  2395,  5946,  6938,  4763,  4810,  5081,
    5487,  5500,  5554,  5629,  5845,  5908,  6139,  6193,  6244,  6316,
    6391,  1975,  2103, -2945,  1065,  1065,  1031,  1031,  1031,  1031,
     666,   666,  2518,  2518,  2566,  6253,  2857,  2887,  2896,   503,
   -2945, -2945, -2945, -2945,   561,  2391,  2897,  2398,  2844, -2945,
   -2945,   101, -2945, -2945, 10641, -2945, -2945, -2945, 10641, -2945,
   -2945,  6542,  2846,  2399, -2945, -2945, -2945, -2945,  5377, -2945,
     505,  6702, -2945, -2945,   620, -2945,   216, -2945, -2945,  2627,
   -2945,   508,  2634, -2945,   511, -2945, -2945,   781, -2945,  6253,
    2635,  6976,  6253,  2637,  8757, -2945,  2405,  2986,  6253, -2945,
   -2945,  2406,   122,  2407, -2945, -2945,  2920,  5718,  2413,  6253,
   -2945,  5770,  2415,   534,  2642,  2868,  2646,  5958,  6424,  2718,
    2315,  6208,  6208, -2945,  8983,  6866, -2945,   516,  5224, -2945,
    2420, -2945,  2846,   341,   534,   632,  2424,  6253, -2945,  9090,
   -2945, -2945, -2945,  6208,  6208, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,  6208,
   -2945,  6208, -2945, -2945,  2428,  2992,   518, 10641,  2929,  9150,
    2934,  6253,   352, -2945, 10641, -2945, -2945, -2945,  2430, -2945,
     258, -2945,  6253, -2945,  6452,  7007,  7026,  2939, -2945,  9198,
   -2945, -2945,  7046, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945,  6480,  6601, -2945, -2945, -2945,   519, -2945, -2945, -2945,
   -2945, -2945, 10819,  2431,  2432,  2435,  2437,  7065,  6772, -2945,
    2662,  2438, -2945, -2945,  6086, -2945,    22,  2940,  2948,  2949,
    2952,  2954,  2955,  2956,  2957,  2958,   522, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, 10641,  2444,
     828, 10641,  2450,  2577, 10641,  2454,  2890,  6253,  6253, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945,  6253, -2945,  6253, -2945,  3478,   530,  2100,
     308,   620,  1166,  2453,  2971,  2972,   538, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,  1166,  2465,
    2918, -2945, -2945, -2945, -2945, -2945, -2945,  2462,   165, 10582,
    2469,   749, -2945, -2945, -2945, -2945, -2945,   415,  2619, -2945,
     231,  2624, -2945,  3478,  2696,  2701,  2729, -2945,  6253,  6253,
    9522,  6253, -2945, -2945,  2491,  9631,  1166,  2503,   207,  6253,
    2505, -2945, 10584,  2506, -2945, -2945, -2945,   313,  2507, 10641,
   -2945, 10641,  2508, 10641, -2945, -2945,   241, 10839, -2945, -2945,
   10732, -2945,  5117, -2945,   172,  2511,  2513,   166,   -28,  2512,
   -2945, 10985, -2945,  7014,  7361,  7080,  7174,  6208,  6208, -2945,
    9699,  6253, -2945,  6253, 10998,  2516, -2945, 10764,  7374, -2945,
   -2945, -2945,  6253, -2945, -2945, 10641, 10641, -2945, -2945, -2945,
   -2945, -2945, -2945, 10641, -2945,  2584, -2945,  1897, -2945,   620,
    1897,   308,  2268,   620,  1897,  1070,  1897,  1897,   269,  2517,
    2561,  2979,  2533,  2563, 10878, -2945,  2565, 10667, -2945,  7409,
    7689,  7255,  7275,  6253, -2945, -2945, -2945, -2945, -2945, -2945,
     620,  6253,   561,  2570,   547,   561, -2945,  2969,  2568,  2970,
    2806, -2945,  2576,   133,  2578, -2945, -2945, -2945, -2945, -2945,
   -2945,  2865, -2945, -2945,  6253,  6253,  6253,  7314, 11031, -2945,
   11044, -2945, -2945,   549,   561,  2579,  3080, 11065, -2945, -2945,
   -2945,   339, -2945,  2805,  2807, -2945,  9729,  2834,  6208, -2945,
   -2945, -2945,  2590,  2829, -2945, -2945,   525,  2812,   525,  2813,
   -2945, -2945, -2945,  6208,  6208,  7707,  2992, -2945, 11078, 11091,
   -2945, -2945,   899, -2945, 11104,  9777,   183,  9807,  9837,  2845,
    5565,  3043,  2664, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945,  2589,  2592,  2387,  2595,  2597, -2945,
    2604, -2945, -2945,  6253,  6253,  3478, -2945,  3478, -2945, -2945,
    2632,   550, -2945,  3045,  2591,   265,  1166,  2636,   212,  2826,
   -2945,   551,  2827, -2945,  2831,  6253, -2945, -2945,  2682,   552,
    1166,  2638, -2945,   313,  2606,   534,   534, 10641, -2945,  2855,
   -2945, 11117, -2945,   265,  2656,   534, -2945,   534,  7726,  8035,
   -2945, -2945, -2945,  2683, -2945, 10641, -2945,   186,  1286, -2945,
   -2945, 10641, -2945,  2860, -2945,  5674,  5873,  2641,  4347,  3117,
    5565, -2945,  2838,  3064,  3054, 10924,  2735, 10686,  3060,  8051,
    8070, -2945,  2687, -2945,  3078,  6253,   221, -2945,   554,   561,
    2688,  3136,   422,  2865, -2945,   351,  6253, 11130, -2945,  2691,
     555,   561,  2681, -2945,  2692,  2693,  2881, -2945, -2945,   260,
     525,  2700,  2712, -2945, -2945, -2945,   200,  1286, -2945, -2945,
    2882, -2945,  2689,  2695, 10641,  5912, -2945,  4347, -2945, 10641,
    2859,  2387,  2704, -2945, -2945,  2709, -2945, -2945, -2945, -2945,
   -2945,  8089,   294, -2945,  6253, -2945,  2719,   562,  1166,  2716,
   -2945, -2945, -2945,  2862,  2866, -2945, -2945,  2720,   578, -2945,
   -2945, -2945, -2945, -2945,  2723, -2945, -2945,  1286, -2945, -2945,
   -2945, 10641, 10641,  2914,  2721,  5565,   233, -2945, 10641,  2753,
    3159, -2945,  6253, -2945,  8108, -2945,  2733,   582,   561,  6253,
    6253, -2945,  2745, -2945, -2945,  2950,  2953,  3199, 10641,  2749,
   10641, -2945,   428, -2945, -2945,  8381, -2945, -2945,  2750,   583,
   -2945,  2978, -2945,  3204,  3205,  2754,  2981, -2945, -2945, -2945,
   -2945, -2945,  2757,  6253,  2756,  2759, -2945,  3214, -2945,  3478,
   -2945, -2945,  2762, -2945
  };

  const unsigned short int
  parser::yydefact_[] =
  {
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1806,     0,
       0,     0,     0,     0,     0,   886,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   815,
       0,     0,     0,     0,     0,     0,     0,  1807,  1808,  1810,
    1809,  1811,  1812,  1813,  1814,  1815,  1816,  1817,  1818,  1819,
    1820,  1821,  1822,  1824,  1823,  1825,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   348,     0,     0,     0,     0,
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
      91,    92,    93,    99,     0,     0,     0,     0,     0,  1290,
       0,     0,   533,     0,   425,     0,     0,     0,     0,   941,
       0,     0,     0,     0,     0,     0,     0,   686,     0,     0,
       0,     0,     0,     0,  1306,     0,     0,     0,  1259,     0,
       0,     0,     0,     0,     0,     0,   850,     0,     0,     0,
       0,     0,     0,     0,     0,   279,     0,   877,     0,   880,
       0,   876,   431,   435,     0,     0,  1315,     0,     0,     0,
     840,     0,     0,     0,     0,   185,     0,     0,     0,     0,
       0,   436,     0,   442,     0,     0,     0,     0,     0,   929,
       0,     0,     0,     0,     0,   464,     0,  1333,     0,  1284,
     413,     0,   477,     0,     0,   933,     0,     0,   889,     0,
       0,   893,     0,     0,     0,   907,     0,     0,     0,     0,
       0,   149,     0,   161,     0,   173,     0,     0,   197,   937,
       0,     0,   925,     0,   927,   928,  1152,     0,     0,  1024,
       0,     0,  1078,     0,     0,  1042,     0,  1150,     0,  1111,
       0,  1100,     0,  1088,     0,  1060,     0,     0,     0,     0,
     371,     0,     0,     0,     0,     1,     3,     0,     0,     0,
       0,     0,     0,   964,     0,  1558,     0,     0,     0,     0,
       0,  1508,     0,     0,     0,  1509,     0,     0,     0,     0,
     952,   963,     0,   953,   958,   956,   959,   957,   954,   955,
     960,   961,   945,   946,   947,   948,   949,   950,   951,   972,
       0,     0,     0,   966,   971,     0,   968,   967,   969,     0,
    1491,     0,  1477,  1511,  1707,  1708,     0,  1295,  1298,  1301,
    1299,  1300,  1296,  1303,  1297,  1304,  1302,  1305,     0,  1292,
     531,   199,   200,   201,   202,     0,  1621,     0,     0,     0,
       0,     0,     0,     0,     0,   429,     0,   428,   417,   422,
     424,   421,   430,   418,   419,   420,   423,     0,     0,     0,
       0,     0,     0,  1271,  1274,  1273,  1275,  1276,  1277,     0,
       0,  1281,     0,  1549,  1537,  1533,     0,     0,     0,     0,
    1247,  1249,  1250,  1248,  1252,  1253,  1251,   943,     0,   100,
       0,     0,     0,   259,     0,     0,  1513,  1754,     0,     0,
    1481,  1698,  1630,     0,     0,     0,  1766,  1767,     0,     0,
       0,  1756,     0,     0,  1410,  1431,     0,     0,     0,     0,
       0,  1493,     0,     0,     0,     0,  1475,  1476,  1479,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1510,
       0,  1468,     0,     0,     0,     0,     0,  1489,  1490,     0,
       0,     0,     0,  1506,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1763,  1762,  1439,  1480,  1430,  1432,
    1433,     0,     0,  1514,     0,  1463,     0,  1484,     0,  1492,
    1488,     0,     0,  1486,     0,     0,  1706,     0,  1709,     0,
       0,   691,   743,   749,   770,   729,   758,   773,   692,   792,
     793,   693,   756,   694,   797,   799,   695,   696,   697,   698,
     699,   700,   701,   702,   703,   704,   705,   780,   706,   707,
     708,   798,   795,   796,   709,   710,   711,   712,   713,   715,
     714,   716,   717,   718,   719,   720,   721,   722,   724,   725,
     727,   728,   730,   731,   732,   733,   734,   735,   726,   736,
     737,   738,   739,   740,   741,   742,   774,   775,   777,   776,
     744,   745,   746,   747,   748,   750,   751,   759,   760,   761,
     762,   763,   764,   765,   766,   767,   768,   783,   784,   785,
     786,   789,   787,   788,   790,   791,   723,   794,   752,   753,
     754,   755,   757,   769,   771,   772,   778,   801,   800,   779,
     781,   782,   688,     0,   557,     0,     0,   551,     0,   555,
       0,     0,     0,   577,     0,     0,     0,     0,   571,     0,
       0,  1373,     0,     0,  1774,     0,  1309,  1310,  1311,  1312,
    1313,  1314,   602,   603,     0,     0,   583,     0,     0,  1263,
    1265,  1267,  1268,  1269,  1266,  1261,     0,     0,   264,     0,
       0,     0,     0,  1255,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   853,   862,   854,   861,   865,   867,
     868,   869,   871,   866,   870,   860,   863,   856,   855,   857,
     858,   859,   864,   872,   873,     0,     0,     0,     0,  1328,
       0,     0,     0,     0,     0,   267,   270,     0,   273,  1357,
       0,   272,     0,   271,   278,     0,   275,   268,   269,     0,
       0,     0,     0,   874,   882,     0,   434,     0,   391,     0,
       0,     0,  1321,     0,     0,   822,     0,     0,     0,     0,
       0,     0,     0,  1685,     0,     0,     0,     0,  1362,  1363,
    1364,  1500,  1499,  1686,     0,     0,  1390,     0,     0,   833,
       0,   832,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   493,   494,   498,   499,   501,   502,   503,   834,   835,
     836,   504,   506,   505,   507,   508,   838,   513,   495,   496,
     497,   837,   524,   492,   500,   509,   510,   511,   512,   516,
     517,   518,   519,   520,   521,   514,   515,   839,   522,   523,
     842,   830,     0,   139,   183,   191,     0,     0,   188,     0,
     206,   540,   539,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   887,   297,   296,     0,
    1278,     0,   439,   440,   441,     0,     0,  1478,     0,     0,
    1768,  1356,     0,  1355,     0,   445,   453,   446,   454,   450,
     449,   456,   457,   447,   448,   451,   452,   455,   102,     0,
       0,     0,     0,   341,   342,     0,     0,  1434,  1777,     0,
       0,  1208,  1210,  1215,  1214,  1213,  1216,  1209,  1211,  1212,
     931,     0,     0,  1345,     0,     0,     0,   468,   469,     0,
     467,     0,     0,     0,     0,     0,     0,  1336,  1337,  1338,
    1339,  1340,  1341,     0,     0,   416,     0,  1376,  1631,     0,
     525,   482,   530,   529,   526,   527,   528,   479,     0,     0,
       0,     0,  1218,  1220,  1222,  1221,  1225,  1226,  1227,  1228,
    1219,  1223,  1224,   935,     0,     0,     0,   917,   918,   919,
     891,   922,     0,   921,   923,   924,   895,     0,     0,   902,
       0,     0,     0,   912,   913,   915,   914,   909,   824,     0,
       0,     0,   119,   147,   155,   152,     0,   136,   159,   167,
     164,     0,   137,   171,   179,   176,     0,   819,     0,   138,
     195,     0,  1550,  1534,  1535,  1536,  1532,     0,     0,     0,
       0,     0,     0,  1440,     0,  1230,  1233,  1234,  1235,  1236,
    1237,  1238,  1240,  1239,  1244,  1245,  1241,  1242,  1243,  1231,
    1232,   939,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1155,  1202,  1188,  1189,  1190,
    1191,  1192,  1204,  1193,  1194,  1195,  1196,  1197,  1199,  1198,
    1203,  1156,  1157,  1158,  1159,  1160,  1161,  1162,  1163,  1164,
    1165,  1166,  1167,  1168,  1169,  1170,  1171,  1180,  1172,  1173,
    1181,  1183,  1182,  1174,  1175,  1184,  1176,  1177,  1178,  1179,
    1185,  1186,  1187,  1200,  1201,  1205,  1206,     0,     0,     0,
       0,     0,     0,   608,   609,   610,   611,   612,   613,   614,
     615,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1649,     0,  1650,     0,     0,     0,     0,  1652,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1023,     0,   974,
    1020,   975,   976,   977,   978,   979,   980,   981,   982,   983,
     984,   985,   986,   987,   988,   989,   990,   991,   992,   993,
     994,   995,   996,   997,   998,   999,  1000,  1001,  1002,  1003,
    1004,  1005,  1006,  1007,  1008,  1009,  1010,  1011,  1012,  1013,
    1014,  1015,  1016,  1017,  1018,  1019,  1021,     0,  1739,  1750,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1748,
    1741,     0,  1077,     0,  1062,  1063,  1064,  1071,  1065,  1066,
    1067,  1068,  1069,  1070,  1072,  1073,  1075,  1074,  1080,  1743,
    1041,     0,  1026,  1027,  1028,  1034,  1038,  1039,  1029,  1030,
    1031,  1032,  1033,  1035,  1037,  1036,     0,  1713,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1149,     0,  1119,  1120,  1121,  1114,  1115,
    1116,  1117,  1118,  1122,  1123,  1124,  1125,  1126,  1127,  1128,
    1129,  1130,  1131,  1132,  1113,  1133,  1134,  1135,  1136,  1137,
    1138,  1139,  1140,  1141,  1142,  1143,  1144,  1145,  1146,  1147,
       0,     0,  1733,     0,  1110,     0,  1105,  1104,  1102,  1103,
    1106,  1107,  1108,     0,     0,     0,     0,  1735,  1099,     0,
    1090,  1091,  1092,  1096,  1097,  1093,  1094,  1095,  1742,  1087,
       0,  1082,  1083,  1084,  1085,     0,  1059,     0,  1044,  1045,
    1046,  1051,  1056,  1057,  1048,  1049,  1050,  1052,  1053,  1055,
    1054,  1047,     0,     0,     0,     0,     0,     0,     0,     0,
     374,   375,   377,   376,   378,   379,   380,  1694,  1695,     0,
       0,   383,   387,   384,   385,   386,     0,     0,  1703,  1705,
       0,   472,   473,   474,   475,   476,     0,     0,     0,   461,
     462,   463,     0,   627,     0,     0,     0,     0,     0,   622,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   248,
       0,     0,     0,     0,   247,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   211,   210,   618,   680,   623,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   532,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1282,     0,     0,     0,     0,     0,
       0,   101,     0,     0,     0,   258,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   554,     0,   550,   251,   553,     0,     0,     0,
     576,     0,     0,     0,     0,   570,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   582,     0,     0,     0,     0,
       0,   263,     0,     0,     0,     0,  1256,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1329,     0,     0,     0,     0,   111,     0,     0,
       0,   285,     0,   286,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   884,     0,   435,     0,     0,     0,   390,
       0,     0,  1322,     0,     0,   821,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   184,   189,   186,   194,     0,
     141,     0,     0,   145,   143,   207,     0,     0,     0,     0,
     311,   310,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   340,     0,     0,     0,
       0,     0,     0,     0,     0,  1344,     0,     0,     0,     0,
       0,     0,   406,   543,   412,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1287,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     901,     0,     0,     0,     0,   122,   120,   148,   153,   150,
     158,   160,   165,   162,   170,   172,   177,   174,   182,     0,
     816,   817,   196,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   103,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   351,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   617,
       0,     0,     0,     0,     0,     0,   661,     0,     0,     0,
     679,     0,     0,     0,     0,     0,   224,   223,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   208,     0,     0,     0,     0,  1554,
    1555,  1556,  1557,  1553,  1559,  1397,  1407,  1784,     0,  1401,
       0,  1400,  1426,  1427,  1501,  1502,     0,   962,     0,  1560,
    1452,  1487,   970,     0,  1503,  1496,  1291,     0,  1294,     0,
     203,  1618,  1619,  1620,  1383,  1387,  1374,  1394,  1352,   427,
     426,  1454,     0,  1629,  1623,  1624,  1626,  1625,  1627,  1628,
    1370,  1359,  1272,  1270,     0,  1280,     0,  1542,  1543,  1544,
    1545,  1546,   942,     0,  1246,   846,     0,   844,     0,   256,
       0,     0,  1361,  1406,  1399,  1462,  1453,  1529,  1530,  1531,
    1398,  1405,  1404,  1445,  1447,  1446,  1448,     0,  1441,  1403,
    1402,  1365,     0,  1764,  1494,  1495,  1428,  1429,  1521,  1523,
    1520,  1522,  1524,  1525,  1455,  1458,  1464,  1459,  1473,  1474,
    1456,  1457,   546,     0,     0,   548,   547,  1469,  1471,  1470,
    1466,  1467,  1465,  1515,  1504,     0,     0,  1505,  1507,  1759,
    1758,  1760,  1761,  1561,  1562,  1564,  1563,  1565,  1566,  1568,
    1567,  1569,  1570,  1572,  1571,  1573,  1574,  1575,  1576,  1577,
    1578,     0,  1358,  1512,  1472,  1483,  1482,  1485,  1518,  1517,
    1519,  1757,  1526,  1527,  1528,     0,  1710,   690,   687,     0,
       0,   549,   594,   595,   597,   598,   600,   596,   599,   601,
     252,     0,     0,     0,     0,     0,   575,     0,     0,     0,
     567,     0,     0,  1372,  1371,  1307,  1308,   604,   605,   581,
       0,  1264,  1260,     0,     0,   261,   538,     0,     0,     0,
       0,     0,  1254,     0,  1755,  1613,  1617,  1616,  1615,  1614,
    1608,  1609,  1584,   851,   852,   253,     0,     0,  1326,     0,
       0,     0,     0,   848,     0,   294,     0,   292,     0,     0,
     283,   284,     0,   288,  1386,     0,  1389,     0,   277,   281,
    1497,  1498,     0,   881,     0,     0,   433,   432,     0,   388,
       0,  1320,     0,   820,     0,   825,     0,     0,     0,   828,
    1765,  1351,  1360,  1384,  1385,  1367,  1368,  1380,  1379,  1393,
    1391,  1353,  1392,   831,   841,     0,   190,   187,   192,   142,
       0,   146,   144,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   295,   306,   307,   302,   303,   304,   305,
     298,   299,   301,   300,   308,   888,     0,     0,   438,   437,
    1381,  1382,  1375,  1388,  1354,   444,   443,   849,     0,     0,
       0,     0,   338,     0,  1435,  1778,  1779,   930,     0,  1207,
       0,  1350,  1342,     0,     0,   541,   542,     0,     0,     0,
       0,     0,   410,   466,   465,  1769,     0,  1772,     0,  1771,
    1334,  1335,     0,     0,  1286,     0,   415,   414,  1369,  1377,
     481,   478,     0,  1437,  1436,  1438,   934,     0,  1217,     0,
    1516,   916,   890,     0,   920,   894,     0,   898,   899,     0,
       0,     0,     0,   900,  1378,  1753,   911,   908,     0,     0,
       0,   154,   151,   156,   166,   163,   168,   178,   175,   180,
     818,  1538,  1539,  1540,  1541,  1551,  1552,     0,  1443,  1547,
    1548,   938,     0,  1229,   926,  1579,  1580,  1581,  1582,  1583,
    1585,  1586,  1587,  1588,  1589,  1590,  1591,  1592,  1593,  1594,
       0,     0,  1595,  1596,  1597,     0,     0,     0,  1601,  1602,
       0,  1604,  1605,  1606,  1607,  1610,  1611,  1612,  1153,  1154,
    1395,  1396,  1408,  1409,  1411,   607,   606,  1634,  1635,  1636,
    1637,  1638,  1639,  1640,  1641,  1642,     0,  1644,  1645,  1646,
    1647,  1648,  1651,  1653,  1654,  1655,  1656,  1657,  1668,  1665,
    1679,  1680,  1684,  1658,  1661,  1662,  1663,  1664,  1666,  1667,
    1669,  1670,  1671,  1672,  1673,  1674,  1675,  1676,  1677,  1678,
    1681,  1682,  1683,  1715,  1022,  1025,     0,  1751,  1711,  1740,
    1714,  1712,  1744,  1746,  1745,  1747,  1749,  1731,  1076,  1079,
       0,  1040,  1043,  1659,  1660,  1716,  1717,  1718,  1719,  1720,
    1721,  1722,  1723,  1724,  1725,  1726,  1727,  1728,  1729,  1730,
    1148,  1151,  1632,  1633,  1732,  1109,  1112,  1736,  1738,  1737,
    1734,  1098,  1101,  1086,  1089,  1752,  1058,  1061,     0,     0,
       0,   357,   358,     0,   350,     0,     0,  1802,  1688,  1687,
    1689,  1690,  1691,  1692,   373,   372,  1697,  1696,   382,   381,
    1700,  1701,  1702,  1704,   471,   470,  1775,  1776,   460,   458,
     459,     0,     0,     0,   621,   616,     0,     0,     0,   662,
       0,     0,     0,   680,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   209,   221,   222,   217,   218,   219,   220,
     212,   213,   215,   214,   216,     0,     0,     0,     0,     0,
     675,   676,   677,   678,     0,   681,   625,  1784,     0,  1785,
    1787,     0,  1791,  1789,     0,   965,   973,  1293,     0,   198,
     204,     0,     0,     0,   944,   847,   845,   260,     0,  1449,
       0,     0,   544,   545,     0,  1793,     0,  1797,  1795,     0,
     804,     0,     0,   813,     0,   689,   556,   251,   552,   251,
       0,     0,     0,     0,     0,   574,     0,     0,     0,  1262,
     619,   682,   629,     0,   536,   537,     0,     0,     0,     0,
    1258,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   280,     0,     0,   878,     0,     0,   875,
       0,   883,     0,     0,     0,     0,     0,     0,   826,     0,
     843,   193,   140,     0,     0,   323,   324,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   333,   322,     0,
     330,     0,   332,   334,     0,   335,     0,     0,     0,     0,
       0,     0,     0,   932,     0,  1347,  1349,  1346,     0,   411,
     405,   398,     0,   408,     0,     0,     0,     0,  1285,     0,
     480,   936,     0,   892,   896,   897,   903,   904,   905,   906,
     910,     0,     0,   157,   169,   181,     0,   940,  1803,  1805,
    1804,   535,   534,     0,     0,     0,     0,     0,     0,  1081,
       0,     0,   353,   349,     0,  1800,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   650,   651,   659,
     657,   652,   655,   654,   660,   658,   656,   653,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   236,
     237,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   246,   235,     0,   243,     0,   245,   249,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   638,   639,   647,
     645,   640,   643,   642,   648,   646,   644,   641,     0,     0,
       0,  1788,  1792,  1790,  1780,   205,  1622,   397,     0,     0,
       0,     0,  1442,  1366,  1794,  1798,  1796,     0,     0,  1460,
       0,     0,  1461,   252,     0,     0,     0,   558,     0,     0,
       0,     0,   572,   568,     0,     0,     0,     0,     0,     0,
       0,   266,     0,     0,   255,  1318,  1319,     0,     0,     0,
    1781,     0,     0,     0,   293,   291,     0,     0,   287,   274,
       0,   276,     0,   885,     0,     0,     0,     0,     0,     0,
     823,     0,   829,     0,     0,     0,     0,     0,     0,   328,
       0,     0,   344,     0,     0,     0,  1348,     0,     0,   409,
    1770,  1773,     0,  1288,  1699,     0,     0,  1444,  1598,  1599,
    1600,  1603,  1643,     0,   354,     0,  1693,     0,  1801,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1451,     0,     0,   663,     0,     0,   681,     0,
       0,     0,     0,     0,   241,  1421,  1419,  1420,   674,   668,
       0,     0,     0,     0,     0,     0,  1786,     0,   393,     0,
       0,   620,   684,   633,     0,   257,  1450,   802,   803,   805,
     810,     0,   811,   814,   251,   251,   251,     0,     0,   580,
       0,   569,   584,     0,     0,   683,   631,     0,   262,  1257,
     254,     0,  1330,     0,     0,  1327,     0,   115,     0,   290,
     337,   879,     0,     0,   389,  1323,     0,     0,     0,     0,
     827,   325,   326,     0,     0,     0,   336,  1279,     0,     0,
     343,   339,     0,   407,     0,     0,   126,     0,     0,   107,
       0,     0,   352,  1799,  1412,  1416,  1418,  1425,  1414,  1423,
     585,   586,   588,   589,   591,   587,   590,   592,   593,  1413,
    1422,  1417,   649,   628,     0,     0,   664,     0,     0,   682,
       0,   238,   239,     0,     0,   250,  1415,  1424,   637,   624,
       0,     0,   396,     0,   392,     0,     0,     0,     0,     0,
     808,     0,   562,   559,   563,     0,   578,   573,     0,     0,
       0,     0,   265,     0,     0,     0,     0,     0,   112,   113,
     118,     0,   282,     0,     0,     0,  1782,     0,     0,     0,
     309,   346,   345,     0,  1289,     0,   123,   124,   132,   129,
     121,     0,   104,   105,   110,     0,     0,     0,   363,     0,
     364,   365,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   669,     0,   395,     0,     0,     0,   404,     0,     0,
     685,   635,     0,     0,   812,     0,   251,     0,   670,     0,
       0,     0,     0,  1316,     0,     0,   114,   116,   289,     0,
       0,     0,     0,   329,   331,  1343,   125,   130,   127,   135,
     106,   108,     0,     0,     0,     0,   355,     0,   366,     0,
       0,   666,     0,   665,   684,     0,   683,   242,   244,   626,
     394,     0,     0,  1283,     0,   403,     0,     0,     0,     0,
     806,   807,   809,     0,   564,   579,   630,     0,     0,  1317,
    1331,  1332,   117,   347,     0,  1324,  1325,   131,   128,   133,
     109,     0,     0,     0,     0,     0,     0,   362,     0,     0,
       0,   401,     0,   402,     0,   672,     0,     0,     0,   251,
     251,   671,     0,  1783,   134,     0,     0,     0,     0,     0,
       0,   360,     0,   667,   685,     0,   400,   634,     0,     0,
     560,   565,   632,     0,     0,     0,     0,   356,   361,   359,
     399,   673,     0,     0,     0,     0,   367,     0,   636,   566,
     368,   369,     0,   370
  };

  const short int
  parser::yypgoto_[] =
  {
   -2945, -2945,  3231, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945,   189, -2945, -2945, -2945, -2945,  -788,
   -2945,  -309, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945,   918, -2945, -2945, -1675, -2945, -2945, -2945,  -251,
    -508, -2945,   977,  -759, -2945,  1608, -2945, -2945, -2945, -2945,
     460, -1660, -2945,   469,  -272, -2945, -2945, -1644, -2945,   867,
    -981,  -273, -2945, -2945, -2945,  1291, -2945, -2945, -2945,  -137,
    -121, -2945,   -25, -2945, -2945, -2945,  1287, -2945, -2945,  1283,
   -2945,   966,   475, -2945,    16, -2945,   872, -2945, -2945,  -197,
   -2945, -2945,  1792, -2945, -2945,  1627, -2945, -2945,  -258, -2945,
   -2945,  -206, -2945, -2945,  3030,  1294, -2945, -2945,  1519, -2945,
   -2945,  1297, -2945, -2945,  -223,  1506,    82, -2078, -1678,  1730,
     399, -2945, -2398, -2945, -2945,  2697, -2945, -2945, -2944, -2945,
    1047,  -731, -2945, -2945,  2679, -2945, -2945,  2657, -2945, -2715,
   -2945, -1359, -2945, -2945, -2945,  1425, -2945, -2945,  3036, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2922,   187,
   -2945,   206, -2945,  3039, -2945, -2692,   354, -2945,  3042, -2945,
   -2945,  1726,   359, -2945,    14, -2945,   337, -2945, -2945, -2945,
   -2945, -2945, -2945,  2617, -2945, -2945, -2945, -2945, -2945,  1657,
   -2945, -2945, -2945, -2945, -2945, -2945,  1718, -2945, -2945,   124,
   -2945,  1695, -2945, -2945, -2945, -2945, -2945, -2945,   908, -2945,
   -2945,  2397, -2945, -2945,  1553, -2945,  1570, -2945,  -233, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945,   -98,  1891, -2945,
   -2945,  1885, -2945, -2945,  1448, -2945, -2945,  1436, -2945, -2945,
    1399, -2945, -2945,  1437, -2945, -2945,  1403, -2945, -2945,  1408,
   -2945, -2945,  1416, -2945, -2945,  1428, -2945, -2945,  1508, -2945,
    1625, -2945,  1588, -2945,  1541, -2945,  1869, -2945, -2945, -2945,
    2728, -2945, -2945,  1774, -2945, -2945,  1882, -2945, -2945, -2945,
    3013, -2945, -2945, -2945,  1613, -2945,  1908, -2945, -2945,  1798,
   -2945, -2945, -2705, -2945, -2945,  2674, -2945,  1111,  -798, -2945,
    1621, -2945, -2945,   343, -1007,  1640, -2945,   164, -2945, -2945,
   -2945, -2945,  -159,   -83,  -105, -2945,  -164, -2945, -2945, -2945,
     -82,   -75, -2945, -2945, -2945,   288, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
    -195, -2945, -2945, -2945, -2945, -2945, -2945,  -106, -2945, -2945,
    -134, -2945,  -189,  -221,   -71, -2945, -2945,  -183, -2945, -2945,
   -2945, -2945, -2507, -2475, -2474, -2945, -2945, -2466, -2465, -2945,
   -2945, -2945, -2456, -2455, -2945, -2945,  -193,  -220, -2945,  -238,
    -210, -2945,  -278, -2945, -2945, -2945, -2945,  -209, -2945,   -88,
   -2945, -1519,   920,  1401, -2945,  -199, -2945,  -324, -2945, -2945,
   -2945, -2945,  -169, -2945, -2945, -2945, -2945,  -315, -2945, -2945,
   -2945, -2945, -2945,  -160, -2945, -2945, -2945, -2945,  -102, -2945,
   -2945, -2945, -2945, -2945, -2945,   -64,  -225, -2945, -2945,   -51,
     -49,   -78, -2945,  -147, -2945,   -41, -2945, -2945, -2945,  -218,
    -213,   -36, -2945, -2945, -2945, -2945,   -35,   -33, -2945,   -87,
   -2945,   -32,   -31, -2945,  -237,   -24,   -21, -2945, -2945, -2945,
      -6,     5,     6,     8, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945,  -312, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945,  -293,  -290, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945,  -151,  -208, -2945, -2945, -2945,  -327,  -303,  -302,  -289,
    -286, -2945, -2945, -2945, -2945, -2945,  -282,  -280,  -277, -2945,
    -271, -2945, -2945, -2945,  -264,  -257,  -256, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945,  -357, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945,  -166,  -235, -2945, -2945, -2945, -2945, -2945,
      11,    18, -2945, -2945,  -185,  -170, -2945,  -171,  -250, -2945,
   -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945, -2945,  -148, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945,  -283,  -146,  -320, -2945, -2945,  -130,  -129,  -118,
     -94,  -351,   -91,   -90, -2945, -2945,   -56,  -267, -2945, -2945,
   -2945, -2945, -2945,    42, -2945, -2945, -2945, -2945, -2945, -2945,
   -2945, -2945, -2945,  -127, -2945, -2945,  -265,  -263, -2945, -2945,
   -2945, -1362, -2023, -2945, -1328, -2945, -1477, -2945,   321, -2945,
   -1975,     0
  };

  const short int
  parser::yydefgoto_[] =
  {
      -1,   113,   114,   115,   116,   117,  2696,  3308,   118,  2404,
    3276,   119,  2580,  2579,  3305,   120,   121,   122,   123,  1810,
     927,   928,   330,   332,   334,   284,   337,   124,   455,  2199,
     125,   126,  3113,  2165,  3068,  3116,   127,   128,   129,   512,
     513,   130,   767,   768,   131,   824,   825,   132,   814,  2918,
    1760,  1761,  2406,  2407,  1762,  1851,  2956,  1763,   133,   992,
     993,   994,   134,   367,  2092,  2093,  3310,  3515,  3312,  3516,
    3409,  3410,  3411,   135,   136,  1499,  1500,   137,  1510,  1511,
     138,   839,  3098,   139,  3426,  1881,  1882,   140,  1034,   465,
     141,   466,   467,   142,   835,   836,   143,   961,  1017,   144,
     974,  1018,   145,   146,  1528,  1529,   147,  1019,  1020,   148,
    1520,  1521,   149,  1039,  1071,  1041,  3002,  3003,  2379,  1573,
    2285,  2286,  2287,   150,   726,   727,   728,  2352,  3117,   151,
     737,   738,   152,   732,   733,   153,   755,   756,  3329,  2353,
     753,   754,   154,   155,  1232,  1233,   156,   157,   158,  1538,
     159,  2167,  3089,  2116,  3127,  3371,  3357,  3489,  3076,  3077,
    3026,  3027,   160,   161,   162,  2829,  2830,   163,   164,   165,
     610,   611,  2870,  2871,  3360,  3361,  2873,  2874,   166,   336,
    1106,   167,   844,   845,   168,   169,   847,   170,   870,   871,
     171,   172,   173,   174,   175,   176,   783,   784,   177,   269,
    2917,   270,   178,   288,  1850,   179,   180,  2566,  2567,   181,
    1078,  1079,   182,  1082,  1083,  1066,  1067,  1072,  1084,   183,
     184,   185,   186,   187,   188,   189,   400,   401,   402,   190,
     424,   425,   191,  1287,  1288,   192,  1370,  1371,   193,  1476,
    1477,   194,  1352,  1353,   195,  1469,  1470,   196,  1458,  1459,
     197,  1444,  1445,   198,  1403,  1404,   199,   200,  1174,  1175,
    1000,  1001,  1051,  1052,  1124,  1125,   499,   500,   201,   772,
     773,   202,   758,   759,   203,   482,   483,   204,   205,   490,
     491,   206,  1033,  1895,  1896,   207,   436,   437,   208,   745,
     746,   209,  3138,   210,   841,   842,   211,   808,   809,   212,
    1026,  1027,   213,  1012,  1013,  2520,   872,   873,   874,   977,
     978,   979,   875,   876,   877,   878,   879,   880,   881,   882,
     883,   884,   885,   886,  1042,   887,   748,   749,   750,   469,
     980,  1043,  1085,   888,   889,   981,   982,   470,   890,   827,
     471,   984,   828,   891,   892,   893,   894,   895,  1234,  1235,
     403,   619,   620,   404,   897,   623,   624,   405,  1236,  1237,
     625,  1238,  3078,  3079,  3080,  3081,  3031,  3082,  3083,  2831,
    2832,  2833,  3084,  3085,  3086,  3036,   406,   407,   628,   629,
     898,   631,  1005,  1006,  1057,  1058,  1059,   899,  1126,   900,
    1127,  2859,  2860,  1539,   426,   634,   486,   635,   636,   637,
     638,   639,   640,   641,   642,   643,   644,   645,   646,   647,
     648,   649,   650,   651,   652,   653,   654,   655,   441,   985,
     657,   658,   659,   660,   661,   902,   427,   664,   665,   903,
     442,   904,   669,   670,   671,   443,   830,   905,   906,   408,
     409,   444,   676,   677,   678,   679,   410,   411,   682,   445,
     684,   907,   908,   687,  1074,   909,   910,   690,   691,   692,
     911,   912,   913,   914,  1128,   501,  1129,  1130,  1131,   502,
    1132,  1133,   503,   504,   505,  1134,  1135,   506,  1136,  1137,
    1138,   412,   413,   414,   415,   416,   417,   418,   428,   697,
     698,   699,   700,   701,   702,   703,   704,   705,  1191,  1192,
    1193,  1194,  1195,   795,  1197,  1198,  1199,  1200,  1201,  1202,
    1203,  1204,  1205,  1206,  1207,  1208,  1209,  1210,  1211,  1212,
    1213,  1214,  1215,  1216,  1217,  1218,  1219,   796,  1220,  1221,
    1222,   797,   798,   799,   800,   801,   473,   474,   475,   476,
     487,   488,   706,  1046,  1446,  1447,  1291,  1292,  1293,  1294,
    1295,  1296,  1297,  1298,  1299,  1300,  1301,  1302,  1303,  1304,
    1305,  1306,  1307,  1308,  1309,  1310,  1311,  1420,  1312,  1313,
    1314,  1315,  1316,  1317,  1318,  1319,  1320,  1321,  1322,  1323,
    1324,  1325,  1326,  1327,  1328,  1329,  1330,  1331,  1332,  1333,
    1334,  1335,   915,   916,  1501,  1502,  1503,  1504,  1505,  1506,
    1513,  1514,  1515,   707,  1075,  1522,  1523,  1524,  1525,   708,
     446,   447,   711,   712,  1354,  1355,  1423,  1356,  1336,  1425,
    1426,  1427,  1428,  1429,  1430,  1431,  1432,  1433,  1434,  1435,
    1436,  1437,  1438,  1439,  1357,  1451,  1452,  1463,  1464,  1465,
    1466,  1467,  1358,  1359,  1360,  1474,  1379,  1361,  1362,  1363,
    1364,  3087,  1366,  1367,  1491,  1086,   713,   804,   714,   715,
     716,   717,   718,   918,   919,   720,   721,   986,  1028,  1029,
    1030,  1031,  1032,   987,  1530,  1531,  1008,  1009,  2185,  2401,
    3159,  2839,  2840,  2180,  2181,  2296,  2757,  3016,  2758,  2621,
    2622,  1574
  };

  const short int
  parser::yytable_[] =
  {
     214,   838,  1365,   222,  1635,  1875,  1715,   805,  1731,   222,
    1752,  1866,  1512,   663,   222,  1488,   956,   621,   627,   788,
     673,   222,  1095,  1187,  1100,   674,  1105,   440,   630,   632,
    2351,  1408,  1188,   271,   962,  1196,  1378,   439,  1056,   761,
     762,   222,   222,   285,  1473,   626,   222,   789,   790,   222,
     764,  1061,   222,  1062,  1223,  1409,  1410,  1224,   869,   222,
     222,   222,   222,  2387,   222,   222,   331,   333,   335,  1411,
     338,   222,  1412,  1376,   614,  1139,  1413,  1140,  1414,  1003,
    1226,  1415,  1068,  1482,  1069,   221,   438,  1416,   975,  1073,
    1040,   231,   896,   786,  1417,  1054,   239,   792,   222,   983,
    2410,  1418,  1419,   250,   618,  1045,   802,   826,  1424,  1182,
     793,   983,   901,   214,  1035,   917,  2411,  1004,   751,   472,
     423,   484,  2761,   282,   283,  1290,  1178,  1181,   290,  2258,
    1239,   295,   617,  1055,   301,  1240,   656,  1183,  1184,  1814,
    1406,   314,   317,   320,   323,  1407,   327,   328,  1186,  1007,
     633,   683,   785,   341,  1180,   613,   615,  2843,   964,  2482,
     668,   763,  3115,   616,  1179,  1060,  1002,   622,   377,   791,
     794,  1372,   964,  1421,   662,  1448,   381,  1460,  -662,  1471,
     354,  1478,  1053,  1176,   811,  1374,  1373,   666,  1422,   667,
    1449,  1462,  1461,  -664,  1472,  1480,  1479,   672,  2297,  2298,
    1190,   803,   675,   680,  -666,   681,   685,   686,  1375,  2412,
    1377,  1044,  1450,  1177,   688,  2177,  1289,   689,  1481,  3156,
    1483,   450,  2998,  3000,  1405,  2179,  1380,  1381,   492,  2837,
     392,   450,   693,   271,   271,   514,  1484,  1485,  1382,   450,
     729,   734,   739,   694,   695,  1189,   696,   757,  1486,   709,
     450,   766,   769,  2509,  2837,   774,   710,   393,   514,  1185,
    2543,   810,  1383,   271,   931,  1384,  1385,  1048,  2230,  2231,
     271,  2194,  1487,  1440,  3028,  1489,  1490,   843,   846,   848,
     719,   931,   450,   450,   924,  2251,   215,  2259,   958,   217,
     450,  1225,  1089,  3238,  2895,   450,   271,  1635,   931,   508,
    3238,   450,  1014,   931,  1526,   932,  3029,  3030,   931,  2647,
     931,  3363,  3278,  3351,   450,  3032,  3033,   450,   931,  2252,
     450,  2260,   932,   450,   990,  3034,  3035,   450,   450,  1064,
    1093,  2910,  1098,  2835,  1103,   931,  1107,  1110,  2658,   932,
    1613,   450,  3369,  2282,   932,   931,  2294,   931,  3265,   932,
     931,   932,   931,  3430,   450,   227,  1623,   510,   511,   932,
    1753,  2342,  1919,   223,  3017,  3018,  3019,  3020,  3021,  3022,
    3023,  3024,   286,   931,   232,  3197,   932,  1537,  1540,  1544,
    1548,   931,  1578,  2924,  2420,  1441,   932,   812,   932,   468,
     226,   932,  2837,   932,   834,   931,  3234,   990,   228,   990,
     931,   233,   612,  2088,  1620,   394,  2325,  2753,   234,  1778,
    3155,   240,   997,  2922,   932,    38,  2332,  2333,   241,  1865,
     989,  3175,   932,   931,  2713,   246,   931,   247,  2598,   287,
     251,  2421,   479,  2282,  3263,  2528,   932,   925,   254,  2529,
    1049,   932,  2714,   255,   931,  2304,  2305,  2749,  1603,   451,
    1094,   276,  1099,  1442,  2343,  2334,  2862,  1104,   976,  2282,
     260,  1806,  2750,  1928,   932,  2961,  1699,   932,  1932,  1936,
     976,  2456,   998,   263,  2581,   468,  2584,  2863,   277,  2841,
    2344,  2345,  2346,   264,  2089,   932,  2090,  2091,   296,  1622,
    1727,   304,  1839,  1840,  1841,  1842,  1843,  1844,  1845,  1846,
    1847,  1848,   931,  2587,  1849,   931,   278,  3487,   348,   931,
    3398,  3250,   514,  3457,   485,  1227,  1228,  1077,  3239,  3498,
     279,  1768,   224,   225,   999,  3239,  1775,  3507,   452,   453,
     454,   309,  1705,   747,  2904,  2510,   324,   760,  2905,   344,
    1722,  1229,  1230,   932,   374,   787,   932,  2866,  3004,  3005,
     932,   351,  3006,  3287,  1878,  1879,  3025,  3288,  2693,  1065,
     345,  2911,  1493,   370,  2864,   368,  1779,  2702,  1614,   369,
    2705,  1878,  1879,  2549,  3482,   371,  1878,  1879,  2555,  1803,
     963,  1878,  1879,  2283,  2284,  3550,  3540,  1754,  1527,  2599,
    2600,  1878,  1879,  2347,   963,  1839,  1840,  1841,  1842,  1843,
    1844,  1845,  1846,  1847,  1848,  3198,  3549,  1849,  1878,  1879,
    2925,  2530,   991,  3482,  1722,  1807,  1808,  2838,  1878,  1879,
    1878,  1879,   489,  1878,  1879,  1878,  1879,  2659,  2660,  2642,
    2643,  1090,  1621,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,  2836,  2376,  1878,  1879,  3017,  3074,  3019,  3075,
    3021,  3022,  3023,  3024,  3428,  1820,  1821,  3266,  1874,  2178,
    3444,  3445,  3431,  2283,  2284,   837,   837,   378,  3440,  2348,
    3451,  2268,  3452,  1838,  3092,   991,  1853,   991,   392,  1231,
     926,   382,  3373, -1825,  1700,  3247,  2648,  2649,  2306,  2283,
    2284,  3028,  3490,   926,  1341,   926,  1860,   931, -1825,  2842,
     926,  1885,  2269,  2270,   926,   393,   926,  2413,  1728, -1825,
    3493,   926,   926,  1701,   926,  1702,   729,   926,   372,   926,
    1707,  1708,   734,  3029,  3030,  1712,  1713,   739,   216,  3271,
    2766,   218,  3032,  3033,  3240,  1050,  3286,  1344,   932,  1769,
     509,  3283,  3034,  3035,  1776,   757,   926,  1898,  1706,  2620,
    2376,  2511,   392,   926,  2786,  3040,   926,   769,  2088,  1443,
    1351,  2864,   774,  1894,  2767,  1878,  1879,  2867,  1878,  1879,
     926,  3540,  1878,  1879,  1929,  1930,  1902,  1911,  1913,  1933,
    1934,  2342,  1923,  2295,  1937,  1938,  3527,  1991,  1494,  3105,
    3483,  3484,  2100,   398,   399,   514,  2999,  1804,   810,   235,
     236,  3251,  3541,  1349,   958,  3091,   242,   243,  3093,   815,
    3279,   379,  2349,    38,  1495,  1496,  1497,  1498,  1880,  2227,
    2228,  2229,   271,  2103,  2109,  1723,   373,  1777,  2531,  3503,
    3484,   843,   816,  2972,   846,  3425,  2113,  1788,  3025,  2089,
     383,  2090,  2091,   380,  2113,  2121,  3072,   817,  3101,   996,
     419,  3108,   392,   394,  3111,   477,   489,   478,   931,  3150,
     997,  3168,  3101,  3374,  3522,  3208,   818,   515,   375,  1011,
     525,   244,   245,  3223,  2343,  2377,  2378,   429,   430,   393,
     479,  3232,     1,     2,  3135,  3136,   741,  2308,  2309,  2310,
    3072,  1549,  3072,  3232,  3433,  3232,   740,  3072,  3072,   932,
    2344,  2345,  2346,   771,  1854,  3232,   752,     3,     4,     5,
       6,     7,  1805,   252,   253,     8,  1811,  1811,  2271,   807,
     998,  3232,     9,   770,  1861,  3072,  3232,   958,   958,  1886,
     535,   536,    10,    11,    12,   806,   431,  1550,    13,   599,
      14,    15,    16,    17,    18,   958,  1773,   819,   813,  1551,
     831,   432,    19,    20,   256,   257,   480,   829,  3393,   837,
      21,  1552,  1553,  1847,  1848,  3442,   820,  1849,   840,  1341,
    1878,  1879,   999,  2311,  2312,  1899,    22,    23,    24,    25,
    1863,  1864,  2377,  3157,  1495,   258,   259,    26,   929,    27,
      28,  1507,  1508,   433,  1509,    38,   930,  3559,   995,  1554,
     261,   262,  1014,    29,  1903,  1912,  1914,  2315,  2316,  2317,
    1924,  2459,  1344,  2347,  2462,  1992,   742,   959,  2161,  2162,
    2101,    30,  2163,  1897,  1350,  1468,  1015,   821,   480,  1016,
      31,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
    1142,  2104,  2110,   822,    32,    33,    34,    35,   586,  1077,
      36,   396,  1337,   588,  2114,  2213,   265,   266,   479,  1492,
     480,    37,  2115,  2122,  3073,  1533,  3102,  1579,   743,  3109,
    1580,  1927,  3112,  1581,  3225,   480,  1931,  3151,  1582,  3169,
    3187,  1935,    38,  3209,  1583,  1349,  1941,  1584,  1942,  2348,
     481,  3224,  1915,  1916,  1917,  1918,  3137,  1021,  1022,  3233,
     272,   273,    39,    38,    40,   744,    41,    42,  3350,  1585,
    3368,  3422,  3434,  3439,    43,  3486,  3497,    44,   823,    45,
      46,  1555,  1556,  3526,    47,    48,   274,   275,  1557,  1558,
    1559,  1560,  1561,  1562,  1563,  1564,  1565,  1566,  1586,  3532,
    1587,  1567,  1588,  3548,  3562,  1568,  1569,  1570,  1589,    49,
      50,  1590,    51,    52,    53,  1592,    54,    55,  1591,  1011,
    1594,   493,    56,   291,   292,    57,   392,   494,   293,   294,
      58,    59,   495,   496,  2253,  2254,  2255,    60,  2256,    61,
      62,    63,  3114,    64,  2253,  2254,  2255,    65,  2256,  1516,
    1517,  1518,  1519,    66,    67,    68,    69,    70,    71,    72,
      73,    74,  1593,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,  1595,  1023,  1024,  2328,  2329,  3158,  2318,  2319,
    2320,  1025,  2349,  1596,  1341,  2949,  1839,  1840,  1841,  1842,
    1843,  1844,  1845,  1846,  1847,  1848,  1597,    75,  1849,  1845,
    1846,  1847,  1848,   965,   966,  1849,  2592,  2593,  2594,  3015,
    1598,  2214,  2215,  2216,  2217,  2218,  2219,  1599,   967,  2826,
    2827,  2828,  1600,   434,   435,   461,  1343,  1344,   968,  1572,
    1601,    76,   297,   298,  1602,   497,   498,  2253,  2254,  2255,
     969,  2256,   302,   303,  1453,  1454,  1455,  1456,  1457,  2257,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,  1604,
    1605,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
    1606,  1571,   305,   306,   307,   308,  1607,   970,  1841,  1842,
    1843,  1844,  1845,  1846,  1847,  1848,    96,    97,  1849,  1608,
      98,    99,   100,   101,   102,   103,   104,   105,   310,   311,
     480,  2159,  2160,  2161,  2162,   106,  1609,  2163,   342,   343,
     107,   108,   346,   347,   349,   350,  1610,   109,  1611,   440,
     355,   356,   357,   358,  1612,  1884,   359,   360,  1615,   439,
    1616,  2155,  2156,  2157,  2158,  2159,  2160,  2161,  2162,   110,
     111,  2163,  2597,   971,   361,   362,  1617,   972,  1618,   464,
    1619,   973,  1839,  1840,  1841,  1842,  1843,  1844,  1845,  1846,
    1847,  1848,   363,   364,  1849,  1625,   112,  2951,  1839,  1840,
    1841,  1842,  1843,  1844,  1845,  1846,  1847,  1848,   438,  1626,
    1849,   365,   366,  1627,   663,  1628,  1629,   744,   621,   627,
    1630,   673,  1631,  2950,  1636,  1632,   674,  1633,  1637,   630,
     632,  1638,  2410,  1639,  1640,  1641,  2457,  2458,  1642,   423,
    1643,  1644,  1645,  1646,  1647,  1648,   626,   472,  2411,   788,
    1649,  1650,  1651,  3320,  1652,   484,  1653,   761,   762,  3321,
    3322,  3323,  3324,  3325,  3326,  1654,  1655,  1656,   764,  1657,
    1658,  1659,  1660,  1661,  3327,   614,  1662,   789,   790,  1663,
    3328,  1664,  1665,  1666,  2463,  2464,  2465,  2466,  1667,  1668,
    2467,  2468,  2469,  2470,  2471,  2472,  2473,  2474,  2475,  2476,
    2477,  2478,  2479,  2480,  2481,   618,  1669,  2484,  2485,  2486,
    2487,  2488,  2489,  2490,  2491,  2492,  2493,  2494,  1670,  3362,
     869,  3364,  3246,   786,  1671,   271,  1672,   792,  1673,  1674,
    2184,  2186,  1675,   617,   751,  2498,   802,   656,  1676,  1677,
     793,   222,  1678,  1679,  2200,  1680,  1681,  1682,  3384,   826,
    3386,   633,   683,  1683,   896,  1684,   613,   615,  2582,  2583,
    1685,   668,  2585,  2586,   616,  2226,  2588,  2589,   622,   222,
    1056,  1686,   222,   222,   901,   662,  1687,   917,  1688,   763,
    1689,  2245,   785,  1061,  1690,  1062,   271,  1691,   666,  1692,
     667,  1003,  1693,  1694,  2505,  1695,  1696,  1697,   672,   791,
     794,  1187,  1698,   675,   680,   983,   681,   685,   686,  2483,
    1188,  2291,   271,  1196,  1068,   688,  1069,   271,   689,  1040,
    2564,  3212,  1711,  2197,  2314,  2952,  1139,  1054,  1140,  1004,
     983,   803,  1223,   693,  1045,  1224,  1717,  1716,  1634,  1365,
     222,  2546,  1718,  1719,   694,   695,  1720,   696,  1721,  2175,
     709,  2233,  1726,  1729,  2236,  2238,  1732,   710,  1226,   964,
    3313,  1007,  1733,  3315,  1734,  1055,  1737,  3319,   222,  3330,
    3331,  1738,  1378,  1739,   271,  1488,  1740,  1741,  1002,  1742,
    1743,   719,  1744,  1408,   271,  1745,  1512,  1182,  1746,  1747,
     271,   964,  1750,  2399,  1749,  1755,  1756,  1060,  1757,  2408,
     958,  3494,  1764,  1473,  1178,  1181,  1790,  1409,  1410,  1376,
    2250,   271,  3504,  1239,  1053,  1183,  1184,   468,  1240,  1765,
    1771,  1411,  2339,  2432,  1412,  1766,  1186,  1767,  1413,  2438,
    1414,  1770,  1180,  1415,   271,  1774,  2292,  1783,  1780,  1416,
    1044,  2302,  1179,  1482,   222,   392,  1417,  1786,  1791,  1811,
    2373,  1290,  1811,  1418,  1419,  1792,   958,   958,   958,   958,
    1424,  1176,   958,   958,   958,   958,   958,   958,   958,   958,
     958,   958,   958,   958,   958,   958,   958,  1793,  1190,   958,
     958,   958,   958,   958,   958,   958,   958,   958,   958,   958,
    1794,  1177,  1406,    38,  1795,  3551,  1796,  1407,  2381,  1797,
    1798,  1799,  1800,   612,  1801,  1802,   926,  1372,  2391,  2515,
    2516,   222,  1815,  2521,  2397,  1852,  2521,  2524,  1816,  1817,
    1818,  1374,  1373,  1189,  1819,  1421,  2455,   271,  1855,   271,
    1448,  1822,  1823,  1824,   222,  1897,  1460,  1185,  1471,  1825,
    1422,  1478,  1289,   222,  1375,  1449,  1377,   222,   485,  1856,
    1462,  1461,   222,  1472,  2568,  1480,  1479,  1857,  2444,  1826,
    1827,  1828,  1380,  1381,   222,  1829,  1830,  1450,  1831,  1225,
    1832,  1833,  1834,  1835,  1382,  1858,  1405,  1836,  1481,  2590,
    1483,  1837,  -327,   271,  1859,  1862,  1868,  1867,  1869,  1870,
     222,  1871,  1872,  2518,  1873,  1876,  1484,  1485,  1383,  1877,
    1887,  1384,  1385,  1888,  1889,  1890,  1891,  1892,  1486,  1893,
    1900,  1901,  1904,  1905,  1906,  1907,  2542,  1908,  1909,  2170,
    1910,  1866,  2173,  1921,  1922,  2552,   271,  2641,  1925,  2557,
    2858,  1926,  1487,  1943,  2563,  1489,  1490,  1944,   271,  1945,
    1946,  1947,  1338,  1948,  1949,  1951,  2578,  1950,  1953,   747,
    1954,  2535,  1955,  2537,  1956,   760,  1952,  1957,   957,  1958,
    1959,  1960,  1961,  1962,   976,  1963,  1339,  1340,  1964,  1965,
    1966,  1967,  2602,  1338,  1968,   787,  1969,  1970,  1971,  1972,
     271,  1973,   271,   271,  1974,  1975,  1985,  1976,  1977,   976,
    1978,   222,  1979,  1980,  1981,  1984,  1982,  1339,  1340,  1983,
    1986,  1987,   468,  1988,  1989,  1990,  1993,  2591,  1994,  1995,
    1996,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
    1997,   456,  1998,  1999,   398,   399,   457,   458,   459,  2000,
    2001,  2002,  2003,  2004,  2005,   271,  2006,   271,   271,  1752,
    2640,   271,  2007,  2008,  2009,  2010,  2011,  2782,  2783,  2012,
    2013,  1540,  2654,  2014,  2787,  2788,   460,  2790,  2791,  2792,
    2015,  2794,  2908,  2710,  2016,  2017,  2018,  2384,  1731,  2019,
    2914,   963,  2020,  2021,  2022,  2901,  2023,  2931,   461,  2024,
    2025,   462,  2026,   517,   775,   518,  1715,   838,  2027,  2028,
    2029,  2030,  2031,  2032,  2698,  2033,  2700,  2701,  1241,  1242,
    1243,  1244,  1245,   963,  2036,  2034,  2035,  2037,  2038,  2039,
    2040,  2041,  1251,  1252,  1253,  2042,   723,  2043,  2044,  1258,
    1386,  2045,  1259,  1260,  2046,  2047,  2048,   450,  2049,  2850,
    2050,  2051,  2052,  1341,   456,  2054,  1342,  2053,  1703,   457,
     458,   459,   222,  2055,  2056,  1266,  2057,  2058,  2059,  2060,
    2070,  2061,  2062,  2063,  2955,  2064,  2065,  2066,  2067,  2770,
    2068,  2772,  2773,   450,  1341,  2776,   450,  1342,   450,   460,
    2069,   514,  2071,  2072,  1341,  1343,  1344,  1369,  1345,  1346,
    2073,  1347,  1348,   535,   536,  2074,  2076,  2075,  1350,  2077,
    2078,   461,   222,  2079,   462,  2080,   463,  2081,  2083,  1351,
    2082,  2084,  2993,  2085,  2086,  2994,  1343,  1344,  2995,  1345,
    1346,  2532,  1347,  1348,  1349,  2087,   542,  1344,  2094,  1350,
    2095,  1387,   464,  2096,  2851,  1875,  2097,   545,  2098,   776,
    1351,  2099,  2102,  2105,  2106,  2107,  2108,  2991,  2992,  2111,
    2112,  1286,  1388,  1389,  1390,  1391,  1392,  1393,  1394,  1395,
    2119,  1396,  1397,  1398,  1399,  1400,  1401,  1402,  3063,  2153,
    2154,  2155,  2156,  2157,  2158,  2159,  2160,  2161,  2162,   450,
    2876,  2163,  2117,  2118,  2861,   433,  2120,  2123,  2124,  2125,
    1635,  2126,  2130,  2127,  2880,  2128,  2129,  2131,  2883,  1111,
    1112,  2132,   739,    38,  1113,  1114,  1115,  2133,  2168,  2172,
    2174,  1116,  1117,   450,  2893,  2134,  2135,  1118,  1119,  2138,
     769,   586,  2139,  2140,  2176,  2141,   588,  2142,  2143,  2144,
    2145,  2146,  2147,  1635,  2148,  2149,   514,   392,  2150,   777,
     778,  2182,   810,  2151,   958,   464,   479,  -240,   480,  2166,
    2183,  2188,   958,  2189,  2191,   222,  2193,   271,  2178,  2201,
     779,   596,   271,  2202,  3008,   724,  2203,  2206,  2208,  2210,
    3037,  2212,  2220,  2221,   422,  2223,  2927,  2224,   481,  2225,
    2239,  2241,  2242,  2243,  2249,  1120,  2261,  2706,  2262,  2264,
     725,  2266,  2267,  2278,  2279,   450,  3065,  2153,  2154,  2155,
    2156,  2157,  2158,  2159,  2160,  2161,  2162,  2280,   723,  2163,
    2321,  2281,  2288,  2136,  2137,  2289,  2293,  2738,  2739,  2295,
     780,   781,  2303,  2313,  1121,  1122,  2322,  2323,  2327,  2152,
    2331,  2335,  2336,  2340,  2354,  2341,   958,  2915,  2356,  2363,
    2364,  2367,  2360,  2362,  2365,  2385,  2355,  2386,  2958,  2388,
    2960,  2358,  2389,  2359,  2368,  2369,  2392,  2374,   450,  2375,
    2966,  2380,  2400,  2966,  2382,  2153,  2154,  2155,  2156,  2157,
    2158,  2159,  2160,  2161,  2162,  2393,   222,  2163,   222,  2405,
    2395,  2916,   450,   782,   957,  2416,   834,  2441,  2396,  2460,
    2398,  2402,   450,  2442,  2240,  2446,  3064,   450,  2415,   222,
    2417,  1772,  2448,   450,  2450,  2403,  2568,  2451,  2423,  2452,
    2419,  1849,  1123,  2497,  2502,  2504,  2424,  2508,   450,   958,
     958,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
    2496,  2514,   450,  2899,  2153,  2154,  2155,  2156,  2157,  2158,
    2159,  2160,  2161,  2162,  2536,  2427,  2163,  2428,  2975,  2429,
    2976,  2539,  2545,  2350,  2553,   222,   222,   222,  2554,  2357,
     222,  2538,  2430,  2431,  2361,  2433,  2435,   998,  2559,  3146,
    3147,  2982,  2574,  2595,  2370,    38,  2495,  2596,  2499,  2506,
    1779,  2605,  2606,  2507,  2607,  2383,   222,  2608,  2609,  2512,
    2610,  3163,  3164,  2513,  2522,  2534,  2611,   957,   957,  2612,
    2613,  2614,  2540,  2615,  2547,  2573,  2616,  3165,  2604,  3166,
    2617,  2619,  2620,  2628,  3066,   957,  2625,  2629,  2632,   999,
    2644,  2626,  2627,  2630,  2865,  2868,   958,  2638,  2646,  2650,
    2651,  2652,  2653,  2655,  2434,   730,  2437,   724,  2656,  2695,
     450,   384,   385,   386,  2657,  2661,  2662,   387,   388,   389,
     390,  2663,  2664,   420,  2665,   735,  2668,  1709,  2669,  2670,
    2671,  2672,   725,  2673,   421,   391,  2675,  2676,  3007,  2677,
    2678,  2679,  2680,  2681,  2682,   392,  1883,  1714,  2683,  2684,
    2685,  2686,  2813,  2687,  2688,   222,  2689,  2690,  2691,  2692,
    1241,  1242,  1243,  1244,  1245,  1246,  1247,  2697,  2699,  1248,
    1249,  2703,   393,  1250,  1251,  1252,  1253,  1254,  1255,  1256,
    1257,  1258,   422,  2704,  1259,  1260,  1261,  1262,  1263,  1264,
    1265,  2707,  2712,  2718,  2720,  2721,  2724,  2725,  2527,  2726,
    2727,  2732,  2731,  2733,  2734,  2736,  2748,  1266,  1267,  1268,
    1269,  1270,  2737,  2740,  1271,  1272,  1273,  1274,  1275,  2742,
    1276,  1277,  1278,  1279,  1280,  1281,  1282,   735,  2560,  2900,
    1283,  1284,  1285,  2569,  2570,  2571,  2572,  3014,  2744,  2745,
    2747,  2751,  2752,  2759,  3094,  2762,  2755,  1534,  3095,  2886,
    2756,   450,  2763,  2765,  2769,  2771,  2775,  3037,   514,  2777,
    2779,   450,  1575,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    38,  2781,  2163,  2780,  2785,   739,  2825,  2834,
    2845,  2846,  2852,  1722,  2894,  3295,  3296,   769,  2844,  2869,
    2853,   514,    38,  1286,  2872,  2895,  2878,   810,  1535,  2877,
    2879,   958,   958,  2896,  2898,   450,  2902,  2903,   958,  2906,
     394,   395,  2909,  2912,  2913,  2932,  3010,  1884,  3069,  2973,
    2921,  2954, -1826,   958,   958,  2153,  2154,  2155,  2156,  2157,
    2158,  2159,  2160,  2161,  2162,  2922,  2957,  2163,  2968,   958,
    3011,   958,  3038,  1338,   396,   397,  3039,   222,  3070,  2971,
    3041,  2978,  3012,  3044,  3176,  3013,  3042,  3071,  -663,   731,
    3045,  3088,  2837, -1825,  3097,   450,   450,  1339,  1340,  3043,
    3107,  3046,   450,  3090,  3123,  3099,  3126,  3110,  3118,   736,
    3121,  3129,  3131,  3128,  3134,  3139,  3140,  3399,  3144,  3141,
    3171,  3153,   450,  3160,    38,  3173,  3381,   450,  3167,  3177,
    3182,  3199,  3188,  3189,   450,  3194,  3190,  3195,  3191,  3200,
    3201,  3388,  3389,  3202,    38,  3203,  3204,  3205,  3206,  3207,
    3211,  3218,  3229,   735,   398,   399,  3214,  3215,  3210,  3170,
    3217,  3213,  3230,  3231,  3216,  3235,  3236,  3237,  3245,  3254,
    2795,  2796,  2797,  2798,  3255,  3124,  2799,  2800,  2801,  2802,
    2803,  2804,  2805,  2806,  2807,  2808,  2809,  2810,  2811,  2812,
    3261,  2814,  2815,  2816,  2817,  2818,  2819,  2820,  2821,  2822,
    2823,  2824,  3256,  3264,  3268,  3270,  3272,  3275,  3458,  3459,
    3284,   736,  3285,  3289,  3311,  3301,  3333,  3352,  3354,  3244,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,  2890,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,  3273,
    3355,  3274,  3334,  3277,  3335,  3359,  3338,  3508,  3509,  3349,
     271,  -665,   958,  3353,  1341,  2865,  3356,  1342,  3375,  3370,
    3376,  3380,  2926,  3383,  3358,  3385,  3387,   958,   958,  3382,
     450,  3412,  3404,  3423,  3413,  3414,  3424,  1014,  3415,  3432,
    3435,  3416,  3447,  3417,  3436,  3306,  3306,  3461,  3466,  3443,
    3418,  3469,  3470,  3309,  3241,  3473,  1343,  1344,  3534,  1345,
    1346,  3476,  1347,  1348,  1349,  1475,  3480,  -667,  3502,  3510,
      38,  3421,  3518,  3543,  3337,  3529,  3429,  3340,  3441,  3530,
    1351,  3464,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,  3450,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,  3438,  3455,  3104,  3499,  3106,  3479,  3537,  3488,  3511,
    3496,  3500,  3501,  2881,  3281,  3512,  3379,  2884,   958,  3505,
    1839,  1840,  1841,  1842,  1843,  1844,  1845,  1846,  1847,  1848,
    3519,  3506,  1849,   958,   958,  3520,  3528,   736,  3525,  3531,
    3544,  3538,  1014,  3553,  3533,  3397,  3554,  3397,  3403,  2169,
    1883,  2171,  3547,  1883,  2153,  2154,  2155,  2156,  2157,  2158,
    2159,  2160,  2161,  2162,  3552,  2190,  2163,  3555,  3557,  3561,
    2195,  3563,  3564,  3565,  3567,  3566,  3568,  3570,  2204,  2205,
    3571,  2207,  3572,  3573,   376,  2211,  1839,  1840,  1841,  1842,
    1843,  1844,  1845,  1846,  1847,  1848,  2929,  2897,  1849,  2153,
    2154,  2155,  2156,  2157,  2158,  2159,  2160,  2161,  2162,  2532,
    2244,  2163,  2246,  2247,  2248,  3307,  2418,  3446,  3152,  3145,
    2962,  3542,  2263,  2754,  2265,  3468,  2768,  2764,  2272,  2273,
    2274,  2275,  2276,  2277,  3539,  3456,  2923,  3154,  1883,  3449,
    2970,  3460,  2426,  1532,  2533,  2209,  2774,  2778,  2550,  2887,
    2307,  1710,  1725,  1536,  3332,  3472,  2645,  3475,  1543,  3348,
    2324,  2326,  1547,  1704,  2330,  2337,  3228,  2959,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,  3492,  3253,  2974,
    1839,  1840,  1841,  1842,  1843,  1844,  1845,  1846,  1847,  1848,
    2453,  1785,  1849,  2979,  3513,  2394,  2422,  3249,  1883,  3517,
    3227,   384,   385,   386,  2985,  1920,  2576,   387,   388,   389,
     390,  2561,  2192,  2187,  2694,  2746,  2743,  2708,  2711,  2741,
     957,  2735,  2603,  2639,  2414,   391,  2558,  2519,  2730,  2234,
    1736,  2371,  2222,  1624,  2425,   392,  3248,  2935,  2544,  3252,
    2198,  3535,  3536,  2907,  2541,  1782,  2523,  2996,  3517,  2366,
    3302,  2440,  2784,  3317,     0,  2445,     0,  2447,     0,  2449,
       0,     0,   393,     0,     0,     0,     0,     0,  3556,  2164,
    3558,   517,   775,   518,     0,     0,   957,   957,   957,   957,
       0,     0,   957,   957,   957,   957,   957,   957,   957,   957,
     957,   957,   957,   957,   957,   957,   957,     0,     0,   957,
     957,   957,   957,   957,   957,   957,   957,   957,   957,   957,
       0,   525,     0,     0,  2439,  2500,  2501,     0,  2503,   730,
       0,     0,   392,     0,     0,     0,     0,     0,  3314,     0,
       0,     0,  3318,     0,     0,     0,     0,     0,  2525,  2526,
       0,     0,  1883,     0,     0,     0,     0,     0,     0,   393,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3346,
    2548,  1839,  1840,  1841,  1842,  1843,  1844,  1845,  1846,  1847,
    1848,   535,   536,  1849,     0,     0,     0,     0,     0,     0,
       0,     0,  2575,   735,     0,     0,  1143,  1839,  1840,  1841,
    1842,  1843,  1844,  1845,  1846,  1847,  1848,     0,     0,  1849,
       0,     0,     0,     0,   542,     0,     0,  2936,     0,     0,
     394,   395,     0,   965,   966,   545,     0,   776,     0,     0,
       0,   432,     0,     0,     0,     0,  2618,     0,   967,  2623,
    2624,     0,     0,     0,     0,   461,   552,  2631,   968,  2633,
    2634,  2635,  2636,  2637,   396,   397,     0,     0,     0,     0,
     969,     0,   566,  2882,  2153,  2154,  2155,  2156,  2157,  2158,
    2159,  2160,  2161,  2162,     0,     0,  2163,     0,  2666,  2667,
       0,     0,     0,  3067,     0,     0,  2674,     0,     0,     0,
       0,     0,     0,     0,  3427,  2888,  2153,  2154,  2155,  2156,
    2157,  2158,  2159,  2160,  2161,  2162,    38,   394,  2163,   586,
       0,     0,     0,     0,   588,     0,     0,   970,  1883,     0,
       0,     0,  3427,     0,     0,  2715,  2716,  2717,     0,  2719,
       0,     0,  2722,  2723,   398,   399,     0,     0,  2728,  2729,
    3120,   396,   397,  2409,     0,     0,  3125,     0,  1883,  1883,
       0,     0,     0,     0,     0,     0,     0,  3132,     0,     0,
       0,   931,     0,     0,     0,  3485,     0,  2760,     0,     0,
      38,  3491,  2153,  2154,  2155,  2156,  2157,  2158,  2159,  2160,
    2161,  2162,  1541,   971,  2163,  3161,     0,   972,  3485,   464,
       0,   973,     0,   731,     0,     0,     0,     0,  2937,     0,
       0,     0,   932,     0,     0,     0,     0,     0,   780,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3174,
       0,  3523,     0,     0,  2938,     0,     0,   744,     0,     0,
    3178,     0,     0,     0,  1545,     0,     0,     0,     0,     0,
     933,     0,     0,  1542,     0,     0,     0,     0,     0,     0,
       0,     0,   934,     0,     0,     0,     0,   736,     0,     0,
       0,     0,     0,     0,   935,   936,     0,  1144,  1145,  1146,
    1147,   782,  1148,  1149,  1150,  1151,  1152,  1153,  1154,  1155,
    1156,  1157,  1158,  1159,  1160,  1161,  1162,  1163,  1164,  1165,
    1166,  1167,  1168,  1169,  1170,  1546,     0,     0,    38,     0,
       0,     0,     0,     0,     0,  3219,  3220,     0,     0,     0,
    1839,  1840,  1841,  1842,  1843,  1844,  1845,  1846,  1847,  1848,
    1724,  3221,  1849,  3222,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,  1839,  1840,  1841,  1842,  1843,  1844,  1845,
    1846,  1847,  1848,  2525,  2526,  1849,     0,     0,     0,    38,
       0,     0,     0,     0,     0,  1883,  1883,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  3257,  3258,     0,  3260,
       0,     0,     0,     0,     0,     0,     0,  3267,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,     0,     0,  1730,
       0,    38,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1171,  1172,  1173,     0,     0,     0,  3298,
       0,  3299,     0,     0,   937,   938,     0,     0,     0,     0,
    3304,   939,   940,   941,   942,   943,   944,   945,   946,   947,
     948,     0,     0,     0,   949,     0,     0,     0,   950,   951,
     952,   953,   954,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   931,     0,   957,    38,     0,     0,     0,     0,
       0,  3345,   957,     0,     0,     0,     0,     0,     0,  3347,
       0,     0,     0,     0,  2920,  1839,  1840,  1841,  1842,  1843,
    1844,  1845,  1846,  1847,  1848,  1549,     0,  1849,     0,     0,
       0,     0,     0,   932,     0,     0,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,     0,     0,  2939,     0,     0,
    1839,  1840,  1841,  1842,  1843,  1844,  1845,  1846,  1847,  1848,
       0,  1550,  1849,  2153,  2154,  2155,  2156,  2157,  2158,  2159,
    2160,  2161,  2162,  1551,    38,  2163,   957,     0,  3408,     0,
    2940,     0,     0,     0,     0,  1552,  1553,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,     0,     0,  1883,     0,
    1883,  3419,  3420,     0,     0,     0,     0,     0,     0,    38,
       0,     0,     0,  1554,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3437,     0,     0,     0,     0,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,     0,   957,
     957,     0,     0,     0,   955,     0,  1758,     0,  1759,     0,
       0,     0,     0,  2136,  2137,     0,     0,     0,  3467,  1839,
    1840,  1841,  1842,  1843,  1844,  1845,  1846,  1847,  1848,     0,
       0,  1849,     0,  3481,     0,     0,     0,     0,     0,     0,
    1883,  1883,     0,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,  1839,  1840,  1841,  1842,  1843,  1844,  1845,  1846,
    1847,  1848,  2941,  2822,  1849,  1839,  1840,  1841,  1842,  1843,
    1844,  1845,  1846,  1847,  1848,     0,     0,  1849,  1789,     0,
       0,     0,  3524,     0,     0,  1555,  1556,     0,     0,     0,
       0,     0,  1557,  1558,  1559,  1560,  1561,  1562,  1563,  1564,
    1565,  1566,     0,     0,     0,  1567,   957,  2942,     0,  1568,
    1569,  1570,     0,  3408,     0,     0,     0,     0,  2857,     0,
    3545,     0,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,  1839,  1840,  1841,  1842,  1843,  1844,  1845,  1846,  1847,
    1848,     0,     0,  1849,     0,     0,     0,     0,     0,     0,
       0,  3569,     1,     2,     0,     0,  1883,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,     0,     3,     4,     5,
       6,     7,     0,     0,     0,     8,     0,     0,    38,     0,
       0,     0,     9,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,    11,    12,     0,     0,     0,    13,     0,
      14,    15,    16,    17,    18,     0,     0,     0,     0,     0,
       0,     0,    19,    20,     0,     0,  2943,     0,     0,     0,
      21,     0,     0,  1735,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    22,    23,    24,    25,
       0,     0,     0,     0,     0,     0,     0,    26,     0,    27,
      28,     0,     0,     0,  1883,     0,  1883,    38,     0,  2944,
       0,     0,     0,    29,     0,     0,     0,     0,     0,     0,
       0,     0,  2945,     0,     0,     0,     0,     0,     0,     0,
       0,    30,     0,     0,     0,  1571,     0,     0,     0,     0,
      31,  1839,  1840,  1841,  1842,  1843,  1844,  1845,  1846,  1847,
    1848,   957,   957,  1849,     0,     0,     0,     0,   957,     0,
       0,     0,     0,     0,    32,    33,    34,    35,     0,     0,
      36,     0,     0,   957,   957,     0,     0,     0,     0,     0,
       0,    37,     0,     0,     0,     0,     0,     0,     0,   957,
       0,   957,     0,     0,     0,     0,     0,     0,  2946,     0,
       0,     0,    38,     0,     0,     0,     0,     0,     0,     0,
    1883,  2153,  2154,  2155,  2156,  2157,  2158,  2159,  2160,  3465,
    2162,     0,    39,  2163,    40,     0,    41,    42,    38,     0,
       0,     0,     0,     0,    43,     0,   448,    44,     0,    45,
      46,     0,     0,     0,    47,    48,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,     0,     0,     0,     0,    49,
      50,     0,    51,    52,    53,     0,    54,    55,     0,     0,
       0,     0,    56,     0,     0,    57,     0,     0,     0,     0,
      58,    59,     0,     0,     0,     0,     0,    60,     0,    61,
      62,    63,     0,    64,     0,     0,     0,    65,     0,     0,
    3226,  1883,     0,    66,    67,    68,    69,    70,    71,    72,
      73,    74,     0,     0,     0,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,     0,     0,     0,  1883,     0,     0,
    1883,     0,  1839,  1840,  1841,  1842,  1843,  1844,  1845,  1846,
    1847,  1848,     0,     0,  1849,     0,     0,    75,  2947,     0,
       0,     0,     0,     0,     0,     0,     0,  1883,  1839,  1840,
    1841,  1842,  1843,  1844,  1845,  1846,  1847,  1848,     0,  3001,
    1849,     0,   957,     0,     0,     0,     0,     0,     0,     0,
       0,    76,     0,     0,     0,     0,     0,   957,   957,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,  1883,
       0,  3316,     0,  1883,     0,     0,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,     0,  2977,     0,     0,     0,
    1883,     0,     0,     0,     0,     0,    96,    97,     0,     0,
      98,    99,   100,   101,   102,   103,   104,   105,     0,     0,
       0,     0,     0,     0,     0,   106,     0,     0,     0,     0,
     107,   108,     0,     0,     0,     0,     0,   109,     0,     0,
       0,  1883,     0,     0,     0,     0,     0,     0,   957,  2153,
    2154,  2155,  2156,  2157,  2158,  2159,  2160,  2161,  2162,   110,
     111,  2163,     0,   957,   957,     0,     0,     0,     0,     0,
       0,     0,     0,  2153,  2154,  2155,  2156,  2157,  2158,  2159,
    2160,  2161,  2162,  1748,     0,  2163,   112,     0,  2153,  2154,
    2155,  2156,  2157,  2158,  2159,  2160,  2161,  2162,   516,   517,
    2163,   518,     0,   519,   520,     0,     0,     0,   521,  2948,
       0,   522,     0,   523,     0,     0,     0,     0,  1751,     0,
       0,     0,     0,     0,     0,  1883,     0,     0,     0,     0,
       0,   524,     0,     0,     0,  2953,     0,     0,     0,   525,
     391,     0,     0,  1883,     0,     0,     0,   526,   527,     0,
     392,     0,     0,  1883,   528,   529,   530,  2153,  2154,  2155,
    2156,  2157,  2158,  2159,  2160,  2161,  2162,     0,     0,  2163,
       0,     0,   531,     0,   532,   429,   430,   533,     0,     0,
       0,   534,  1781,     0,     0,     0,     0,   422,     0,     0,
       0,     0,     0,     0,     0,     0,  1883,     0,     0,   535,
     536,   537,  1883,     0,  2153,  2154,  2155,  2156,  2157,  2158,
    2159,  2160,  2161,  2162,     0,     0,  2163,     0,     0,  1883,
       0,     0,     0,     0,     0,     0,  3282,   538,   539,   540,
       0,   541,   542,   543,   431,     0,     0,     0,    38,     0,
       0,     0,   544,   545,   931,     0,   546,   547,     0,   432,
     548,   549,  1883,   550,   551,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   552,   553,   554,   555,   556,   557,
     558,   559,   560,    38,  -561,   561,   562,   563,   564,   565,
     566,  1784,     0,     0,     0,   932,     0,     0,     0,   567,
     568,   433,   569,   570,   571,   572,   573,   574,  2885,   575,
     576,     0,     0,   577,   578,     0,     0,     0,   579,     0,
       0,     0,   580,   581,   582,  2969,     0,     0,   583,     0,
     584,     0,   585,   933,     0,   394,   395,   586,     0,   587,
       0,     0,   588,   589,   590,   934,     0,    38,     0,     0,
     591,     0,   592,     0,     0,     0,     0,   935,   936,     0,
       0,   931,     0,   593,     0,     0,     0,     0,   594,   396,
     397,     0,     0,   595,     0,     0,     0,   596,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   463,     0,   597,
     598,    38,     0,   599,  3049,     0,     0,     0,     0,     0,
       0,     0,   932,     0,     0,     0,     0,     0,   600,     0,
       0,     0,     0,   464,     0,     0,     0,     0,     0,     0,
     601,   602,     0,     0,     0,   603,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   604,  1787,
     933,  3050,     0,     0,     0,     0,    38,     0,     0,   398,
     399,     0,   934,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   935,   936,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,  2153,  2154,  2155,  2156,  2157,
    2158,  2159,  2160,  2161,  2162,     0,  3100,  2163,    38,     0,
       0,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
       0,     0,     0,     0,     0,     0,     0,   937,   938,     0,
       0,     0,     0,     0,   939,   940,   941,   942,   943,   944,
     945,   946,   947,   948,    38,     0,     0,   949,     0,     0,
       0,   950,   951,   952,   953,   954,     0,     0,     0,     0,
       0,     0,     0,   605,     0,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,     0,     0,     0,     0,     0,     0,
     606,   434,   435,     0,    38,     0,     0,     0,   607,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,     0,     0,
       0,     0,     0,     0,   937,   938,     0,     0,     0,   608,
     609,   939,   940,   941,   942,   943,   944,   945,   946,   947,
     948,    38,     0,     0,   949,     0,     0,   931,   950,   951,
     952,   953,   954,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,     0,     0,     0,     0,     0,     0,     0,
    1549,     0,     0,     0,     0,     0,     0,     0,   932,     0,
       0,     0,   931,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  3051,     0,     0,     0,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,  1549,  1550,     0,     0,     0,
       0,     0,     0,   932,     0,     0,     0,   955,  1551,  1758,
       0,  1759,     0,     0,     0,     0,     0,     0,     0,     0,
    1552,  1553,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,  1550,     0,  2153,  2154,  2155,  2156,  2157,  2158,  2159,
    2160,  2161,  2162,  1551,    38,  2163,     0,     0,  1554,     0,
       0,     0,     0,     0,     0,  1552,  1553,     0,     0,     0,
       0,   931,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,     0,     0,     0,     0,     0,     0,  3130,     0,    38,
       0,     0,     0,  1554,  1549,     0,     0,     0,     0,     0,
       0,     0,   932,     0,   955,     0,  1758,     0,  1759,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,     0,  3133,
    1550,  2153,  2154,  2155,  2156,  2157,  2158,  2159,  2160,  2161,
    2162,  2461,  1551,  2163,  2153,  2154,  2155,  2156,  2157,  2158,
    2159,  2160,  2161,  2162,  1552,  1553,  2163,     0,     0,     0,
       0,     0,     0,  2436,     0,     0,     0,     0,     0,     0,
    1555,  1556,     0,     0,     0,     0,     0,  1557,  1558,  1559,
    1560,  1561,  1562,  1563,  1564,  1565,  1566,     0,    38,     0,
    1567,     0,  1554,     0,  1568,  1569,  1570,     0,  2153,  2154,
    2155,  2156,  2157,  2158,  2159,  2160,  2161,  2162,     0,     0,
    2163,     0,     0,     0,     0,  3405,  3406,     0,     0,     0,
       0,     0,  1557,  1558,  1559,  1560,  1561,  1562,  1563,  1564,
    1565,  1566,    38,     0,     0,  1567,     0,     0,     0,  1568,
    1569,  1570,     0,     0,     0,     0,     0,     0,  2928,     0,
     931,     0,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,     0,     0,  2153,  2154,  2155,  2156,  2157,  2158,  2159,
    2160,  2161,  2162,  1549,    38,  2163,     0,     0,     0,   931,
       0,   932,     0,     0,     0,     0,     0,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,     0,  3142,     0,     0,
       0,     0,  1549,     0,  1555,  1556,     0,     0,     0,  1550,
     932,  1557,  1558,  1559,  1560,  1561,  1562,  1563,  1564,  1565,
    1566,  1551,     0,     0,  1567,     0,     0,     0,  1568,  1569,
    1570,     0,     0,  1552,  1553,     0,     0,     0,  3052,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1550,     0,
       0,  3053,     0,     0,     0,     0,     0,     0,     0,  3407,
    1551,     0,     0,     0,     0,     0,     0,    38,     0,     0,
    1571,  1554,  1552,  1553,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,  3054,    38,     0,     0,     0,
    1554,     0,     0,     0,     0,  1571,  2933,  1839,  1840,  1841,
    1842,  1843,  1844,  1845,  1846,  1847,  1848,     0,     0,  1849,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,     0,
       0,     0,    38,  2934,  1839,  1840,  1841,  1842,  1843,  1844,
    1845,  1846,  1847,  1848,     0,     0,  1849,     0,  3462,  2153,
    2154,  2155,  2156,  2157,  2158,  2159,  2160,  2161,  2162,     0,
    3055,  2163,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,     0,     0,  1555,  1556,     0,     0,     0,     0,    38,
    1557,  1558,  1559,  1560,  1561,  1562,  1563,  1564,  1565,  1566,
       0,     0,     0,  1567,  1571,     0,     0,  1568,  1569,  1570,
       0,     0,  2153,  2154,  2155,  2156,  2157,  2158,  2159,  2160,
    2161,  2162,  1555,  1556,  2163,     0,     0,     0,     0,  1557,
    1558,  1559,  1560,  1561,  1562,  1563,  1564,  1565,  1566,     0,
       0,    38,  1567,     0,     0,   931,  1568,  1569,  1570,  3047,
    2153,  2154,  2155,  2156,  2157,  2158,  2159,  2160,  2161,  2162,
      38,     0,  2163,     0,     0,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,     0,     0,   932,     0,     0,     0,
     931,  2153,  2154,  2155,  2156,  2157,  2158,  2159,  2160,  2161,
    2162,     0,     0,  2163,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,  1549,   933,     0,     0,     0,     0,     0,
       0,   932,     0,     0,     0,     0,   934,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3463,   935,   936,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,  1550,
    1812,     0,     0,     0,     0,     0,  3056,     0,     0,     0,
       0,  1551,    38,     0,     0,     0,  3514,     0,     0,   448,
       0,     0,     0,  1552,  1553,     0,     0,     0,     0,     0,
       0,     0,     0,  1571,     0,     0,     0,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,     0,    38,     0,     0,
       0,  1554,     0,     0,     0,     0,     0,     0,     0,  3057,
       0,     0,  1571,  2153,  2154,  2155,  2156,  2157,  2158,  2159,
    2160,  2161,  2162,     0,     0,  2163,     0,     0,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,  2153,  2154,  2155,
    2156,  2157,  2158,  2159,  2160,  2161,  2162,     0,     0,  2163,
       0,     0,     0,     0,     0,     0,  2986,     0,   937,   938,
       0,     0,     0,     0,     0,   939,   940,   941,   942,   943,
     944,   945,   946,   947,   948,     0,     0,     0,   949,     0,
       0,     0,   950,   951,   952,   953,   954,  1894,  2153,  2154,
    2155,  2156,  2157,  2158,  2159,  2160,  2161,  2162,     0,     0,
    2163,     0,     0,  1555,  1556,     0,     0,     0,     0,     0,
    1557,  1558,  1559,  1560,  1561,  1562,  1563,  1564,  1565,  1566,
       0,   516,     0,  1567,   518,     0,     0,  1568,  1569,  1570,
       0,   521,     0,     0,     0,   849,   523,     0,  1813,     0,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,  3196,
    2153,  2154,  2155,  2156,  2157,  2158,  2159,  2160,  2161,  2162,
       0,     0,  2163,     0,     0,     0,     0,   528,   529,   530,
     850,   851,     0,     0,     0,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,     0,     0,     0,     0,     0,   852,
    3058,   853,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   535,   536,   537,     0,     0,     0,     0,     0,
       0,     0,     0,   854,   855,  2153,  2154,  2155,  2156,  2157,
    2158,  2159,  2160,  2161,  2162,     0,     0,  2163,     0,     0,
     538,   539,   540,     0,     0,     0,    38,     0,     0,     0,
     856,     0,     0,     0,  3059,     0,     0,   819,  1839,  1840,
    1841,  1842,  1843,  1844,  1845,  1846,  1847,  1848,   955,     0,
    1849,   516,     0,     0,   518,   857,     0,     0,     0,     0,
       0,     0,     0,     0,   522,   849,  2153,  2154,  2155,  2156,
    2157,  2158,  2159,  2160,  2161,  2162,     0,     0,  2163,     0,
       0,     0,     0,   568,     0,  3060,     0,     0,     0,     0,
       0,     0,     0,  1571,  1839,  1840,  1841,  1842,  1843,  1844,
    1845,  1846,  1847,  1848,     0,     0,  1849,   528,   529,   530,
     850,   851,     0,     0,     0,     0,     0,     0,     0,     0,
     586,   858,     0,   859,     0,   588,     0,     0,   860,   861,
       0,     0,     0,   591,     0,   592,     0,     0,     0,     0,
       0,   853,     0,     0,     0,     0,   593,   480,     0,     0,
       0,     0,   535,   536,   537,   448,     0,  3061,   862,     0,
       0,     0,     0,   854,   855,     0,  1036,   863,     0,   864,
     463,     0,     0,     0,     0,     0,   599,   481,   865,     0,
     538,   539,   540,     0,     0,     0,    38,   866,   867,   868,
       0,     0,     0,     0,     0,     0,   464,   819,     0,     0,
       0,     0,   432,   601,   602,     0,     0,     0,   603,     0,
       0,   516,     0,     0,   518,  1839,  1840,  1841,  1842,  1843,
    1844,  1845,  1846,  1847,  1848,   849,     0,  1849,     0,     0,
       0,     0,  3062,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   568,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,     0,     0,  3143,     0,   528,   529,   530,
     850,   851,     0,     0,     0,     0,     0,     0,     0,     0,
     586,   858,     0,   859,     0,   588,     0,     0,   860,   861,
       0,     0,     0,  3179,     0,   592,     0,     0,     0,     0,
       0,   853,  1064,     0,     0,     0,   593,   480,     0,     0,
       0,     0,   535,   536,   537,   448,     0,     0,   862,     0,
       0,  3185,     0,   854,   855,     0,     0,   863,     0,   864,
     463,     0,     0,     0,     0,     0,   599,   481,   865,     0,
     538,   539,   540,     0,     0,     0,   605,   866,   867,   868,
      38,     0,     0,     0,     0,     0,   464,   819,     0,     0,
       0,     0,     0,   601,   602,     0,     0,     0,   603,     0,
       0,   516,     0,     0,   518,  1080,     0,     0,     0,     0,
       0,     0,     0,  3096,     0,   849,  1839,  1840,  1841,  1842,
    1843,  1844,  1845,  1846,  1847,  1848,  1037,     0,  1849,     0,
       0,     0,     0,   568,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,     0,     0,     0,     0,   528,   529,   530,
     850,   851,     0,     0,     0,     0,     0,     0,     0,     0,
     586,   858,  3186,   859,     0,   588,     0,     0,   860,   861,
       0,     0,     0,     0,     0,   592,     0,     0,     0,     0,
       0,   853,  1064,     0,     0,     0,   593,   480,     0,     0,
       0,     0,   535,   536,   537,     0,     0,  1038,   862,   448,
       0,     0,     0,   854,   855,     0,     0,   863,     0,   864,
     463,    38,     0,     0,     0,     0,   599,   481,   865,     0,
     538,   539,   540,     0,     0,     0,   605,   866,   867,   868,
      38,     0,     0,     0,     0,     0,   464,   819,     0,     0,
       0,     0,     0,   601,   602,     0,     0,     0,   603,     0,
      38,     0,  1065,     0,  1081,     0,     0,     0,     0,     0,
       0,     0,     0,  3103,     0,     0,     0,     0,     0,    38,
       0,  3048,  2153,  2154,  2155,  2156,  2157,  2158,  2159,  2160,
    2161,  2162,     0,   568,  2163,     0,     0,     0,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    38,     0,  3119,
    2153,  2154,  2155,  2156,  2157,  2158,  2159,  2160,  2161,  2162,
     586,   858,  2163,   859,     0,   588,     0,     0,   860,   861,
      38,     0,     0,  3193,     0,   592,     0,     0,     0,     0,
     448,     0,     0,     0,     0,     0,   593,   480,  1839,  1840,
    1841,  1842,  1843,  1844,  1845,  1846,  1847,  1848,   862,   448,
    1849,     0,     0,     0,     0,     0,     0,   863,     0,   864,
     463,     0,     0,     0,     0,     0,   599,   481,   865,   448,
       0,     0,     0,     0,     0,     0,   605,   866,   867,   868,
       0,     0,     0,     0,     0,     0,   464,     0,   448,     0,
       0,     0,     0,   601,   602,     0,     0,     0,   603,    38,
       0,     0,  1065,  3293,  1839,  1840,  1841,  1842,  1843,  1844,
    1845,  1846,  1847,  1848,     0,     0,  1849,  3149,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,     0,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    38,  3294,  1839,  1840,
    1841,  1842,  1843,  1844,  1845,  1846,  1847,  1848,     0,     0,
    1849,     0,     0,     0,     0,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,     0,     0,   605,     0,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    38,  3180,     0,
       0,     0,     0,     0,     0,  3291,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,  3181,  3343,  2153,
    2154,  2155,  2156,  2157,  2158,  2159,  2160,  2161,  2162,     0,
       0,  2163,     0,     0,     0,    38,     0,  3184,  3344,  2153,
    2154,  2155,  2156,  2157,  2158,  2159,  2160,  2161,  2162,     0,
       0,  2163,     0,   267,    38,     0,  3192,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    38,  3365,  2153,  2154,
    2155,  2156,  2157,  2158,  2159,  2160,  2161,  2162,     0,     0,
    2163,     0,   219,   220,     0,    38,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    38,   229,   230,     0,     0,     0,
       0,     0,     0,     0,     0,  1839,  1840,  1841,  1842,  1843,
    1844,  1845,  1846,  1847,  1848,     0,     0,  1849,  2153,  2154,
    2155,  2156,  2157,  2158,  2159,  2160,  2161,  2162,     0,     0,
    2163,     0,     0,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,  2153,  2154,  2155,  2156,  2157,  2158,  2159,
    2160,  2161,  2162,     0,     0,  2163,     0,     0,     0,     0,
       0,     0,     0,    38,   237,   238,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,   248,   249,    38,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    38,  3292,   268,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  3303,     0,     0,     0,     0,
      38,   280,   281,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
     299,   300,     0,     0,     0,     0,     0,     0,     0,     0,
    3341,     0,     0,     0,     0,     0,     0,     0,    38,   312,
     313,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
       0,   315,   316,    38,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     318,   319,     0,  2153,  2154,  2155,  2156,  2157,  2158,  2159,
    2160,  2161,  2162,     0,   267,  2163,     0,     0,     0,   321,
     322,  1839,  1840,  1841,  1842,  1843,  1844,  1845,  1846,  1847,
    1848,     0,     0,  1849,     0,     0,     0,     0,     0,   267,
    1839,  1840,  1841,  1842,  1843,  1844,  1845,  1846,  1847,  1848,
       0,     0,  1849,     0,     0,     0,     0,     0,     0,     0,
       0,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
       0,     0,     0,     0,     0,     0,     0,   832,     0,     0,
       0,     0,     0,     0,     0,     0,    38,     0,   325,   326,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   832,     0,     0,     0,     0,     0,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,     0,     0,     0,   339,   340,
       0,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
       0,     0,     0,     0,     0,   448,     0,     0,     0,     0,
    3342,     0,     0,     0,    38,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3390,     0,
       0,     0,     0,    38,     0,     0,   352,   353,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3453,     0,     0,
       0,     0,    38,     0,     0,     0,   289,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    38,     0,     0,     0,   329,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,     0,     0,   833,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,     0,     0,     0,     0,     0,  2919,    38,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1839,
    1840,  1841,  1842,  1843,  1844,  1845,  1846,  1847,  1848,     0,
       0,  1849,     0,   448,     0,  2153,  2154,  2155,  2156,  2157,
    2158,  2159,  2160,  2161,  2162,     0,     0,  2163,     0,     0,
       0,     0,   448,     0,  2153,  2154,  2155,  2156,  2157,  2158,
    2159,  2160,  2161,  2162,     0,     0,  2163,     0,     0,     0,
       0,   448,     0,  2153,  2154,  2155,  2156,  2157,  2158,  2159,
    2160,  2161,  2162,     0,     0,  2163,     0,     0,     0,     0,
     448,     0,  2153,  2154,  2155,  2156,  2157,  2158,  2159,  2160,
    2161,  2162,     0,     0,  2163,     0,     0,     0,     0,   448,
       0,     0,     0,     0,     0,     0,     0,     0,    38,     0,
       0,   449,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,  3454,   922,     0,     0,
       0,     0,     0,     0,     0,     0,    38,     0,     0,   507,
       0,     0,  3477,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    38,     0,     0,   722,     0,
       0,  3478,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    38,     0,     0,   765,     0,     0,
    3521,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,     0,     0,   920,     0,     0,  3546,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    38,   921,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,   448,     0,     0,     0,     0,
       0,     0,     0,     0,  2196,  2153,  2154,  2155,  2156,  2157,
    2158,  2159,  2160,  2161,  2162,     0,     0,  2163,     0,     0,
       0,     0,     0,     0,     0,   448,     0,  2153,  2154,  2155,
    2156,  2157,  2158,  2159,  2160,  2161,  2162,     0,     0,  2163,
       0,     0,     0,     0,   448,     0,  2153,  2154,  2155,  2156,
    2157,  2158,  2159,  2160,  2161,  2162,     0,     0,  2163,     0,
       0,     0,     0,   448,     0,  2153,  2154,  2155,  2156,  2157,
    2158,  2159,  2160,  2161,  2162,     0,     0,  2163,     0,     0,
       0,     0,   448,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,   448,     0,     0,     0,     0,     0,     0,
       0,     0,    38,   923,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      38,     0,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,   960,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  3560,     0,     0,     0,     0,     0,     0,     0,
       0,   448,     0,     0,     0,     0,     0,     0,     0,     0,
      38,   988,  2987,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
    1010,  2988,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1047,
    2989,     0,     0,     0,     0,     0,     0,     0,    38,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1063,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   448,
       0,     0,     0,     0,     0,     0,     0,     0,    38,  1070,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,   448,
       0,     0,     0,     0,     0,     0,     0,     0,    38,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1091,
       0,  2153,  2154,  2155,  2156,  2157,  2158,  2159,  2160,  2161,
    2162,     0,     0,  2163,     0,     0,     0,     0,  1096,     0,
       0,     0,     0,     0,     0,     0,     0,    38,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,  1101,     0,     0,
       0,     0,     0,     0,     0,     0,    38,     0,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,  1108,     0,     0,
       0,     0,     0,     0,     0,     0,    38,  1076,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    38,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,     0,   448,     0,     0,     0,
       0,     0,     0,     0,     0,  1087,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,   448,     0,     0,     0,     0,
       0,     0,     0,     0,    38,  1088,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,  1939,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1092,  3122,  1839,  1840,  1841,
    1842,  1843,  1844,  1845,  1846,  1847,  1848,     0,     0,  1849,
       0,     0,     0,    38,  1097,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,   448,     0,     0,     0,     0,     0,
       0,     0,     0,  1102,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,  1109,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,  2848,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  2232,  2153,  2154,  2155,  2156,  2157,  2158,
    2159,  2160,  2161,  2162,     0,     0,  2163,     0,     0,     0,
       0,    38,     0,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,   448,     0,     0,     0,     0,     0,     0,     0,
       0,    38,  1141,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2153,  2154,  2155,  2156,  2157,  2158,
    2159,  2160,  2161,  2162,     0,     0,  2163,     0,     0,     0,
      38,  1368,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,   448,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1940,  2153,  2154,  2155,  2156,  2157,  2158,  2159,  2160,
    2161,  2162,  3148,     0,  2163,     0,     0,     0,     0,    38,
       0,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
     448,     0,     0,     0,     0,     0,     0,     0,     0,    38,
    2847,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     448,     0,     0,     0,     0,     0,     0,     0,     0,    38,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,   448,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2849,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3162,
       0,     0,     0,     0,     0,     0,     0,    38,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,   448,     0,
       0,     0,     0,     0,     0,     0,     0,    38,  2854,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,   448,  3172,
       0,     0,     0,     0,     0,     0,     0,    38,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,     0,  2964,     0,
       0,     0,     0,     0,     0,     0,     0,  2855,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3183,     0,     0,
       0,     0,     0,     0,     0,    38,     0,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,  2964,     0,     0,     0,
       0,     0,     0,     0,     0,    38,  2856,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,   448,     0,     0,     0,
       0,     0,     0,     0,     0,    38,  2875,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,   448,     0,     0,     0,
       0,     0,     0,     0,     0,  2889,  2153,  2154,  2155,  2156,
    2157,  2158,  2159,  2160,  2161,  2162,     0,     0,  2163,     0,
       0,     0,     0,    38,     0,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,   448,     0,     0,     0,     0,     0,
       0,     0,     0,    38,  2930,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,   448,     0,     0,     0,     0,     0,
       0,     0,     0,    38,  2963,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,   448,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2965,  2153,  2154,  2155,  2156,  2157,
    2158,  2159,  2160,  2161,  2162,     0,     0,  2163,     0,     0,
       0,    38,     0,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,   448,     0,     0,     0,     0,     0,     0,     0,
       0,    38,  2967,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,   448,     0,     0,     0,     0,     0,     0,     0,
       0,    38,  2980,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,  3377,     0,     0,     0,     0,     0,     0,     0,
       0,    38,  2981,     0,     0,     0,     0,     0,     0,     0,
       0,  3259,     0,     0,     0,     0,     0,     0,     0,     0,
      38,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
    3395,     0,     0,     0,     0,     0,     0,     0,     0,    38,
    2983,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
    3395,     0,     0,     0,     0,     0,     0,     0,     0,    38,
    2990,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
    3401,     0,     0,     0,     0,     0,     0,     0,     0,    38,
    2997,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3262,     0,     0,     0,     0,     0,     0,     0,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3009,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,  3297,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,  3378,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    38,     0,     0,
       0,     0,     0,     0,     0,     0,  3396,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    38,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  3400,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    38,  3402,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    38,  2235,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2390,     0,     0,    38,  2237,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    38,     0,     0,     0,     0,
       0,     0,     0,     0,  2338,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    38,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2372,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,  1575,  1576,     0,     0,     0,     0,
       0,     0,     0,     0,  2454,     0,  2290,    38,     0,     0,
       0,     0,     0,     0,     0,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,   267,     0,     0,     0,  2890,  2891,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,     0,
       0,     0,  2517,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    38,     0,     0,  2443,     0,     0,     0,     0,
       0,     0,  2551,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    38,  2556,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,  3241,  3242,     0,     0,     0,     0,     0,     0,
       0,  2562,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    38,  2793,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2565,     0,    38,     0,     0,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,     0,     0,     0,     0,     0,     0,
    2577,     0,     0,     0,     0,     0,    38,   267,  3339,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2601,
       0,     0,     0,     0,     0,     0,     0,  3474,   267,     0,
       0,     0,     0,     0,     0,    38,     0,     0,     0,     0,
    2709,     0,     0,     0,     0,     0,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,  1577,    38,     0,     0,     0,  2984,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,     0,
       0,    38,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,     0,     0,     0,     0,     0,     0,     0,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,  2892,  2153,  2154,
    2155,  2156,  2157,  2158,  2159,  2160,  2161,  2162,     0,     0,
    2163,     0,     0,     0,     0,     0,    38,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    38,     0,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,  2299,
    2300,  2301,   267,     0,     0,     0,     0,     0,    38,     0,
       0,     0,     0,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,  3243,    38,  1011,     0,     0,     0,     0,     0,
       0,     0,     0,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    38,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    38,     0,     0,     0,     0,     0,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,  1809,    38,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3269,     0,     0,     0,     0,     0,     0,
       0,     0,   448,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,  1839,  1840,  1841,  1842,  1843,  1844,  1845,
    1846,  1847,  1848,     0,     0,  1849,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,     0,     0,     0,     0,     0,
       0,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,  2789,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,  3336,  2153,
    2154,  2155,  2156,  2157,  2158,  2159,  2160,  2161,  2162,     0,
       0,  2163,  2153,  2154,  2155,  2156,  2157,  2158,  2159,  2160,
    2161,  2162,     0,     0,  2163,     0,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,  3471,  2153,  2154,  2155,  2156,  2157,
    2158,  2159,  2160,  2161,  2162,     0,     0,  2163,  2153,  2154,
    2155,  2156,  2157,  2158,  2159,  2160,  2161,  2162,     0,     0,
    2163,     0,     0,     0,     0,     0,     0,     0,  3280,  2153,
    2154,  2155,  2156,  2157,  2158,  2159,  2160,  2161,  2162,     0,
       0,  2163,  2153,  2154,  2155,  2156,  2157,  2158,  2159,  2160,
    2161,  2162,     0,     0,  2163,  2153,  2154,  2155,  2156,  2157,
    2158,  2159,  2160,  2161,  2162,     0,     0,  2163,  2153,  2154,
    2155,  2156,  2157,  2158,  2159,  2160,  2161,  2162,     0,     0,
    2163,  1839,  1840,  1841,  1842,  1843,  1844,  1845,  1846,  1847,
    1848,     0,     0,  1849,  2153,  2154,  2155,  2156,  2157,  2158,
    2159,  2160,  2161,  2162,     0,     0,  2163,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  3290,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3300,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3366,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3367,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  3372,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3391,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3392,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3394,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  3448,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  3495
  };

  const short int
  parser::yycheck_[] =
  {
       0,   274,   353,     3,   512,  1012,   737,   258,   767,     9,
     808,   992,   369,   238,    14,   366,   288,   238,   238,   257,
     238,    21,   331,   347,   333,   238,   335,   220,   238,   238,
    1705,   358,   347,    33,   292,   347,   356,   220,   316,   249,
     249,    41,    42,    43,   364,   238,    46,   257,   257,    49,
     249,   316,    52,   316,   347,   358,   358,   347,   281,    59,
      60,    61,    62,  1741,    64,    65,    66,    67,    68,   358,
      70,    71,   358,   356,   238,   340,   358,   340,   358,   300,
     347,   358,   319,   366,   319,     3,   220,   358,   294,   322,
     313,     9,   281,   257,   358,   316,    14,   257,    98,   294,
    1760,   358,   358,    21,   238,   313,   257,   266,   358,   347,
     257,   306,   281,   113,   311,   281,  1760,   300,   245,   225,
     218,   226,  2097,    41,    42,   350,   347,   347,    46,  1648,
     348,    49,   238,   316,    52,   348,   238,   347,   347,   927,
     358,    59,    60,    61,    62,   358,    64,    65,   347,   300,
     238,   238,   257,    71,   347,   238,   238,  2180,   292,  1837,
     238,   249,  2877,   238,   347,   316,   300,   238,    71,   257,
     257,   356,   306,   358,   238,   360,    71,   362,    71,   364,
      98,   366,   316,   347,   262,   356,   356,   238,   358,   238,
     360,   362,   362,    71,   364,   366,   366,   238,  1675,  1676,
     347,   257,   238,   238,    71,   238,   238,   238,   356,    71,
     356,   313,   360,   347,   238,   128,   350,   238,   366,  2924,
     366,   221,  2620,  2621,   358,  1587,   356,   356,   228,   128,
      55,   231,   238,   233,   234,   235,   366,   366,   356,   239,
     240,   241,   242,   238,   238,   347,   238,   247,   366,   238,
     250,   251,   252,    71,   128,   255,   238,    82,   258,   347,
      69,   261,   356,   263,    87,   356,   356,    92,  1627,  1628,
     270,  1599,   366,    63,  2781,   366,   366,   277,   278,   279,
     238,    87,   282,   283,   284,  1647,   128,  1649,   288,   128,
     290,   347,   161,   128,   128,   295,   296,   805,    87,   128,
     128,   301,   302,    87,   269,   128,  2781,  2781,    87,   128,
      87,  3255,    71,  3235,   314,  2781,  2781,   317,    87,  1647,
     320,  1649,   128,   323,    47,  2781,  2781,   327,   328,    94,
     330,   353,   332,   141,   334,    87,   336,   337,   224,   128,
     353,   341,  3264,   120,   128,    87,  1674,    87,   141,   128,
      87,   128,    87,   141,   354,   579,    69,   233,   234,   128,
     353,    10,    69,   580,    95,    96,    97,    98,    99,   100,
     101,   102,    71,    87,   128,   353,   128,   377,   378,   379,
     380,    87,   382,   353,   146,   175,   128,   263,   128,   225,
     580,   128,   128,   128,   270,    87,  3088,    47,   580,    47,
      87,   580,   238,   430,   353,   230,   120,    69,   580,    69,
      69,   579,   237,   259,   128,   224,    50,    51,   579,    69,
     296,    69,   128,    87,   441,   580,    87,   579,  1947,   128,
     580,   193,   257,   120,  3126,   579,   128,   327,   580,   583,
     265,   128,   459,   579,    87,   206,   207,   512,   448,   256,
     327,   579,   327,   243,   103,    89,   120,   327,   294,   120,
     580,   327,   527,   327,   128,   311,   353,   128,   327,   327,
     306,   327,   297,   580,   327,   311,   327,   120,   579,   353,
     129,   130,   131,   580,   511,   128,   513,   514,   580,   489,
     353,    71,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,    87,   327,   366,    87,   579,  3429,   580,    87,
     327,   280,   512,   327,   226,    56,    57,   224,   353,  3441,
     579,   353,   579,   580,   349,   353,   353,   327,   335,   336,
     337,   579,   353,   245,   581,   353,   579,   249,   585,   579,
     360,    82,    83,   128,   586,   257,   128,   353,  2626,  2627,
     128,   580,  2630,   581,   360,   361,   287,   585,  2035,   324,
     579,   583,   256,   579,   353,   580,   839,  2044,   581,   580,
    2047,   360,   361,  1901,   353,   580,   360,   361,  1906,   353,
     292,   360,   361,   360,   361,  3529,   353,   580,   553,  1948,
    1949,   360,   361,   242,   306,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   583,  3528,   366,   360,   361,
     580,   353,   335,   353,   360,   924,   925,   353,   360,   361,
     360,   361,   335,   360,   361,   360,   361,   513,   514,  1988,
    1989,   500,   581,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   460,   128,   360,   361,    95,    96,    97,    98,
      99,   100,   101,   102,  3356,   937,   938,   460,    69,   582,
    3375,  3376,   460,   360,   361,   335,   335,   580,  3370,   328,
    3385,    58,  3387,   955,   583,   335,   353,   335,    55,   230,
     580,   586,   353,   586,   581,   280,   515,   516,   459,   360,
     361,  3208,   280,   580,   494,   580,   353,    87,   586,   583,
     580,   353,    89,    90,   580,    82,   580,   579,   581,   586,
    3435,   580,   580,   723,   580,   725,   726,   580,   580,   580,
     730,   731,   732,  3208,  3208,   735,   736,   737,   580,  3137,
    2102,   580,  3208,  3208,   579,   570,   580,   537,   128,   581,
     579,   579,  3208,  3208,   581,   755,   580,   353,   579,   582,
     128,   579,    55,   580,  2123,   585,   580,   767,   430,   559,
     560,   353,   772,   582,  2102,   360,   361,   583,   360,   361,
     580,   353,   360,   361,  1093,  1094,   353,   353,   353,  1098,
    1099,    10,   353,   582,  1103,  1104,  3488,   353,   492,   583,
     579,   580,   353,   344,   345,   805,   583,   581,   808,   579,
     580,   580,   579,   544,   814,  2838,   579,   580,  2841,    11,
     579,    71,   471,   224,   518,   519,   520,   521,   580,   350,
     351,   352,   832,   353,   353,   581,   580,   837,   580,   579,
     580,   841,    34,   580,   844,   580,   353,   847,   287,   511,
     579,   513,   514,    71,   353,   353,   353,    49,   353,   226,
     579,   353,    55,   230,   353,    44,   335,    46,    87,   353,
     237,   353,   353,  3271,   580,   353,    68,    35,     0,   280,
      44,   579,   580,   353,   103,   360,   361,    80,    81,    82,
     257,   353,    14,    15,   360,   361,   117,   210,   211,   212,
     353,   120,   353,   353,   353,   353,    12,   353,   353,   128,
     129,   130,   131,    78,   581,   353,    88,    39,    40,    41,
      42,    43,   922,   579,   580,    47,   926,   927,   305,    78,
     297,   353,    54,    35,   581,   353,   353,   937,   938,   581,
     104,   105,    64,    65,    66,    35,   139,   166,    70,   288,
      72,    73,    74,    75,    76,   955,   832,   149,   163,   178,
     580,   154,    84,    85,   579,   580,   259,   165,    69,   335,
      92,   190,   191,   362,   363,  3373,   168,   366,   254,   494,
     360,   361,   349,   214,   215,   581,   108,   109,   110,   111,
     990,   991,   360,   361,   518,   579,   580,   119,   128,   121,
     122,   525,   526,   196,   528,   224,   579,   579,   254,   228,
     579,   580,  1012,   135,   581,   581,   581,   220,   221,   222,
     581,  1809,   537,   242,  1812,   581,   247,   259,   362,   363,
     581,   153,   366,  1033,   549,   550,   224,   229,   259,   582,
     162,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     216,   581,   581,   255,   186,   187,   188,   189,   232,   224,
     192,   264,   501,   237,   581,    67,   579,   580,   257,   579,
     259,   203,   581,   581,   581,   460,   581,    71,   309,   581,
      71,  1091,   581,    71,  3069,   259,  1096,   581,    71,   581,
     581,  1101,   224,   581,    71,   544,  1106,    71,  1108,   328,
     289,   581,   356,   357,   358,   359,   582,   126,   127,   581,
     579,   580,   244,   224,   246,   346,   248,   249,   581,    71,
     581,   581,   581,   581,   256,   581,   581,   259,   330,   261,
     262,   360,   361,   581,   266,   267,   579,   580,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,    71,   581,
      71,   380,    71,   581,   581,   384,   385,   386,    71,   291,
     292,    71,   294,   295,   296,   353,   298,   299,    71,   280,
      71,    20,   304,   579,   580,   307,    55,    26,   579,   580,
     312,   313,    31,    32,   455,   456,   457,   319,   459,   321,
     322,   323,  2877,   325,   455,   456,   457,   329,   459,   530,
     531,   532,   533,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   581,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,    71,   252,   253,    89,    90,  2925,   220,   221,
     222,   260,   471,    71,   494,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   353,   389,   366,   360,
     361,   362,   363,   142,   143,   366,   350,   351,   352,  2756,
     581,   273,   274,   275,   276,   277,   278,    71,   157,   123,
     124,   125,    71,   486,   487,   164,   536,   537,   167,   381,
     581,   423,   579,   580,   353,   144,   145,   455,   456,   457,
     179,   459,   579,   580,   554,   555,   556,   557,   558,   580,
     442,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   581,
      71,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
      71,   580,   579,   580,   579,   580,    71,   236,   356,   357,
     358,   359,   360,   361,   362,   363,   498,   499,   366,    71,
     502,   503,   504,   505,   506,   507,   508,   509,   579,   580,
     259,   360,   361,   362,   363,   517,    71,   366,   579,   580,
     522,   523,   579,   580,   579,   580,    71,   529,    71,  1602,
     579,   580,   579,   580,    71,  1016,   579,   580,    71,  1602,
      71,   356,   357,   358,   359,   360,   361,   362,   363,   551,
     552,   366,   580,   302,   579,   580,    71,   306,    71,   308,
      71,   310,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   579,   580,   366,   353,   578,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,  1602,    71,
     366,   579,   580,    71,  1699,    71,   581,   346,  1699,  1699,
     353,  1699,   579,   581,    71,   581,  1699,   581,   581,  1699,
    1699,    71,  3152,    71,    71,    71,  1805,  1806,    71,  1597,
      71,    71,    71,    71,    71,    71,  1699,  1613,  3152,  1747,
      71,    71,    71,   443,    71,  1620,    71,  1727,  1727,   449,
     450,   451,   452,   453,   454,    71,    71,    71,  1727,    71,
      71,    71,    71,    71,   464,  1699,    71,  1747,  1747,    71,
     470,    71,    71,    71,  1816,  1817,  1818,  1819,    71,    71,
    1822,  1823,  1824,  1825,  1826,  1827,  1828,  1829,  1830,  1831,
    1832,  1833,  1834,  1835,  1836,  1699,    71,  1839,  1840,  1841,
    1842,  1843,  1844,  1845,  1846,  1847,  1848,  1849,    71,  3254,
    1803,  3256,  3101,  1747,    71,  1585,    71,  1747,    71,    71,
    1590,  1591,    71,  1699,  1721,  1853,  1747,  1699,    71,    71,
    1747,  1601,    71,    71,  1604,    71,    71,    71,  3286,  1768,
    3288,  1699,  1699,    71,  1803,    71,  1699,  1699,  1927,  1928,
      71,  1699,  1931,  1932,  1699,  1625,  1935,  1936,  1699,  1629,
    1908,    71,  1632,  1633,  1803,  1699,    71,  1803,    71,  1727,
      71,  1641,  1747,  1908,    71,  1908,  1646,    71,  1699,    71,
    1699,  1872,    71,    71,  1860,    71,    71,    71,  1699,  1747,
    1747,  1985,    71,  1699,  1699,  1860,  1699,  1699,  1699,   581,
    1985,  1671,  1672,  1985,  1911,  1699,  1911,  1677,  1699,  1902,
    1913,  3040,   353,  1601,  1684,   581,  1951,  1908,  1951,  1872,
    1885,  1747,  1985,  1699,  1902,  1985,   581,   353,    69,  2050,
    1700,  1898,    71,    71,  1699,  1699,   581,  1699,   353,  1585,
    1699,  1629,   353,   581,  1632,  1633,   580,  1699,  1985,  1853,
    3197,  1872,   581,  3200,    71,  1908,   353,  3204,  1728,  3206,
    3207,    71,  2052,    71,  1734,  2086,    71,    71,  1872,    71,
      71,  1699,    71,  2070,  1744,    71,  2103,  1985,   581,   353,
    1750,  1885,    71,  1753,   581,   581,   581,  1908,    71,  1759,
    1760,  3436,    71,  2083,  1985,  1985,   848,  2070,  2070,  2052,
    1646,  1771,  3450,  1991,  1908,  1985,  1985,  1613,  1991,    71,
     581,  2070,  1700,  1783,  2070,    71,  1985,    71,  2070,  1789,
    2070,    71,  1985,  2070,  1794,   580,  1672,   353,   581,  2070,
    1902,  1677,  1985,  2086,  1804,    55,  2070,   580,    71,  1809,
    1728,  2036,  1812,  2070,  2070,    71,  1816,  1817,  1818,  1819,
    2070,  1985,  1822,  1823,  1824,  1825,  1826,  1827,  1828,  1829,
    1830,  1831,  1832,  1833,  1834,  1835,  1836,    71,  1985,  1839,
    1840,  1841,  1842,  1843,  1844,  1845,  1846,  1847,  1848,  1849,
      71,  1985,  2070,   224,    71,  3530,    71,  2070,  1734,    71,
      71,    71,    71,  1699,    71,    71,   580,  2052,  1744,  1869,
    1870,  1871,   579,  1873,  1750,    71,  1876,  1877,   580,   580,
     580,  2052,  2052,  1985,   580,  2070,  1804,  1887,    71,  1889,
    2075,   580,   580,   580,  1894,  1895,  2081,  1985,  2083,   580,
    2070,  2086,  2036,  1903,  2052,  2075,  2052,  1907,  1620,    71,
    2081,  2081,  1912,  2083,  1914,  2086,  2086,    71,  1794,   580,
     580,   580,  2052,  2052,  1924,   580,   580,  2075,   580,  1985,
     580,   580,   580,   580,  2052,    71,  2070,   580,  2086,  1939,
    2086,   580,   580,  1943,    71,   581,    71,   581,    71,    71,
    1950,   581,   353,  1871,    71,    71,  2086,  2086,  2052,    71,
      71,  2052,  2052,    71,    71,    71,    71,   581,  2086,   353,
      71,    71,    71,    71,    71,   581,  1894,   353,    71,  1580,
      71,  2962,  1583,    71,    71,  1903,  1986,  1987,    71,  1907,
    2241,    71,  2086,    71,  1912,  2086,  2086,    71,  1998,    71,
      71,    71,   293,    71,    71,   353,  1924,   581,    71,  1721,
      71,  1887,    71,  1889,    71,  1727,   581,    71,   288,    71,
      71,    71,    71,    71,  1860,    71,   317,   318,    71,    71,
      71,    71,  1950,   293,    71,  1747,    71,    71,    71,    71,
    2040,    71,  2042,  2043,    71,    71,   353,    71,    71,  1885,
      71,  2051,    71,    71,    71,   581,    71,   317,   318,    71,
      71,    71,  1898,    71,    71,    71,    71,  1943,    71,    71,
      71,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
      71,   107,    71,    71,   344,   345,   112,   113,   114,    71,
      71,    71,    71,    71,    71,  2105,    71,  2107,  2108,  2907,
    1986,  2111,    71,    71,    71,    71,    71,  2117,  2118,    71,
      71,  2121,  1998,    71,  2124,  2125,   142,  2127,  2128,  2129,
      71,  2131,  2404,  2051,    71,    71,    71,  1738,  2897,    71,
    2412,  1853,    71,    71,    71,  2396,    71,  2456,   164,    71,
      71,   167,    71,     4,     5,     6,  2887,  2430,    71,    71,
      71,    71,    71,    71,  2040,    71,  2042,  2043,   418,   419,
     420,   421,   422,  1885,   353,    71,    71,   581,    71,    71,
      71,    71,   432,   433,   434,    71,    47,    71,    71,   439,
     440,    71,   442,   443,    71,    71,    71,  2197,    71,  2199,
     353,   581,   353,   494,   107,    71,   497,   581,    69,   112,
     113,   114,  2212,    71,    71,   465,    71,    71,    71,    71,
     353,    71,    71,    71,  2496,    71,    71,    71,    71,  2105,
      71,  2107,  2108,  2233,   494,  2111,  2236,   497,  2238,   142,
      71,  2241,   581,    71,   494,   536,   537,   538,   539,   540,
      71,   542,   543,   104,   105,    71,   581,   353,   549,    71,
      71,   164,  2262,    71,   167,    71,   282,   353,   353,   560,
     581,   581,  2581,    71,   353,  2584,   536,   537,  2587,   539,
     540,  1882,   542,   543,   544,   581,   137,   537,    71,   549,
      71,   541,   308,    71,  2212,  3302,    71,   148,    71,   150,
     560,    71,    71,    71,    71,    71,    71,  2579,  2580,    71,
      71,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     579,   571,   572,   573,   574,   575,   576,   577,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,  2339,
    2340,   366,   580,   580,  2262,   196,   586,    71,   580,   580,
    2858,   579,   579,   586,  2354,   580,   580,   586,  2358,    19,
      20,   580,  2362,   224,    24,    25,    26,   580,   586,   128,
     128,    31,    32,  2373,  2374,   580,   580,    37,    38,   580,
    2380,   232,   580,   580,   128,   580,   237,   580,   580,   580,
     580,   580,   580,  2901,   580,   580,  2396,    55,   580,   250,
     251,   128,  2402,   580,  2404,   308,   257,   580,   259,   580,
     128,   128,  2412,   128,   128,  2415,   128,  2417,   582,   128,
     271,   272,  2422,   128,  2696,   286,   128,   128,   128,   579,
    2781,   580,   128,   128,    92,   579,  2436,   579,   289,   579,
     579,   579,   128,   280,   128,   105,   128,  2048,   580,   128,
     311,   128,   128,   128,   128,  2455,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   128,    47,   366,
     580,   128,   128,  1555,  1556,   128,   128,  2078,  2079,   582,
     331,   332,   128,   128,   144,   145,   128,   128,   128,  1571,
     128,   580,   128,   353,   353,   579,  2496,  2415,   579,   128,
     128,   128,   579,   579,   579,   128,   353,   128,  2508,   128,
    2510,   353,   128,   353,   579,   579,   128,   586,  2518,   579,
    2520,   579,   128,  2523,   579,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   579,  2536,   366,  2538,   224,
     579,  2417,  2542,   394,   814,   128,  2422,   128,   579,    71,
     579,   579,  2552,   128,  1636,   128,   581,  2557,   580,  2559,
     580,   831,   128,  2563,   128,   579,  2566,   128,   581,   128,
     579,   366,   232,   128,   128,   128,   580,   353,  2578,  2579,
    2580,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     580,   128,  2602,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   580,   579,   366,   579,  2536,   579,
    2538,   128,    71,  1705,   128,  2625,  2626,  2627,   128,  1711,
    2630,   580,   579,   579,  1716,   579,   579,   297,   580,  2911,
    2912,  2559,   128,   128,  1726,   224,   579,   128,   579,   579,
    2923,   128,   128,   579,   128,  1737,  2656,   128,   128,   579,
     128,  2933,  2934,   579,   579,   579,   128,   937,   938,   128,
     128,   128,   579,   128,   579,   579,   128,  2949,   579,  2951,
     128,   128,   582,   128,   581,   955,   580,   128,   128,   349,
     128,   580,   580,   580,  2295,  2296,  2696,   579,   579,   128,
     128,   128,   128,   128,  1786,    47,  1788,   286,   580,   579,
    2710,    21,    22,    23,   128,   128,   128,    27,    28,    29,
      30,   128,   128,    33,   128,    47,   128,    69,   128,   128,
     128,   128,   311,   128,    44,    45,   128,   128,  2656,   128,
     128,   128,   128,   128,   128,    55,  1016,    69,   128,   128,
     128,   128,   581,   128,   128,  2755,   128,   128,   128,   128,
     418,   419,   420,   421,   422,   423,   424,   128,   128,   427,
     428,   128,    82,   431,   432,   433,   434,   435,   436,   437,
     438,   439,    92,   128,   442,   443,   444,   445,   446,   447,
     448,   128,   579,   128,   128,   128,   128,   128,  1880,   128,
     128,   128,   579,   128,   128,   579,   510,   465,   466,   467,
     468,   469,   128,   128,   472,   473,   474,   475,   476,   579,
     478,   479,   480,   481,   482,   483,   484,    47,  1910,   579,
     488,   489,   490,  1915,  1916,  1917,  1918,  2755,   579,   128,
     579,   579,   579,   128,  2844,   128,   582,    47,  2848,    69,
     582,  2851,   128,   579,   579,   128,   579,  3208,  2858,   128,
     579,  2861,   140,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   224,   580,   366,   579,   579,  2887,   580,   580,
     579,   579,   259,   360,   128,  3167,  3168,  2897,   585,   280,
     581,  2901,   224,   561,   280,   128,   579,  2907,   108,   353,
     353,  2911,  2912,   581,   581,  2915,   581,   353,  2918,   581,
     230,   231,    71,    71,   579,   280,   128,  2528,    71,  2530,
     581,   581,   366,  2933,  2934,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   259,   581,   366,   581,  2949,
     128,  2951,   353,   293,   264,   265,   581,  2957,    71,   579,
     353,   579,   579,   353,  2964,   579,   581,    71,    71,   311,
     581,   580,   128,   586,   128,  2975,  2976,   317,   318,   586,
     353,   586,  2982,   585,   579,   586,   580,   353,   353,   311,
     353,    71,   579,   586,   579,   353,   128,  3306,   280,   353,
      71,   581,  3002,   579,   224,    71,  3278,  3007,   580,   579,
      71,    71,   581,   581,  3014,   353,   581,   579,   581,    71,
      71,  3293,  3294,    71,   224,    71,    71,    71,    71,    71,
     586,   141,   579,    47,   344,   345,   586,   460,  3038,  2957,
     586,  3041,    71,    71,  3044,   580,   128,   585,   579,   353,
    2132,  2133,  2134,  2135,   353,    69,  2138,  2139,  2140,  2141,
    2142,  2143,  2144,  2145,  2146,  2147,  2148,  2149,  2150,  2151,
     579,  2153,  2154,  2155,  2156,  2157,  2158,  2159,  2160,  2161,
    2162,  2163,   353,   580,   579,   579,   579,   579,  3397,  3398,
     579,   311,   579,   581,   510,   579,   579,   128,   128,  3099,
     442,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   140,
     442,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,  3139,
     334,  3141,   581,  3143,   581,   280,   581,  3456,  3457,   579,
    3150,    71,  3152,   585,   494,  2756,   580,   497,   353,   580,
     353,   327,   581,   334,   586,   353,   353,  3167,  3168,   579,
    3170,   128,   327,   128,   510,   586,   585,  3177,   586,   353,
     353,   586,   327,   586,   353,  3185,  3186,   327,    71,   583,
     586,   353,   128,  3193,   140,   460,   536,   537,  3507,   539,
     540,   141,   542,   543,   544,   545,   128,    71,   327,   327,
     224,   579,   353,   460,  3214,   353,   580,  3217,   580,   353,
     560,   580,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   585,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   579,   579,  2864,   583,  2866,   579,   353,   580,   580,
     579,   579,   579,  2355,  3150,   580,  3276,  2359,  3278,   579,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     586,   579,   366,  3293,  3294,   586,   580,   311,   579,   579,
     141,   580,  3302,   353,   581,  3305,   353,  3307,  3308,  1579,
    1580,  1581,   579,  1583,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   579,  1595,   366,   128,   579,   579,
    1600,   353,   128,   128,   353,   581,   579,   581,  1608,  1609,
     581,  1611,   128,   581,   113,  1615,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,  2438,  2380,   366,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,  2970,
    1640,   366,  1642,  1643,  1644,  3186,  1768,  3377,  2918,  2910,
    2513,  3518,  1652,  2092,  1654,  3410,  2103,  2100,  1658,  1659,
    1660,  1661,  1662,  1663,  3515,  3395,  2430,  2922,  1668,  3383,
    2528,  3401,  1775,   373,  1885,  1613,  2109,  2113,  1902,  2362,
    1680,   732,   755,   377,  3208,  3415,  1991,  3417,   379,  3232,
    1690,  1691,   380,   726,  1694,  1699,  3072,  2509,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,  3433,  3111,  2531,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
    1803,   844,   366,  2545,  3464,  1747,  1771,  3108,  1738,  3469,
    3071,    21,    22,    23,  2566,  1078,  1923,    27,    28,    29,
      30,  1911,  1597,  1592,  2036,  2086,  2083,  2050,  2052,  2081,
    1760,  2075,  1951,  1985,  1764,    45,  1908,  1872,  2070,  1630,
     772,  1727,  1620,   490,  1774,    55,  3107,   581,  1895,  3110,
    1602,  3511,  3512,  2402,  1893,   841,  1876,  2597,  3518,  1721,
    3177,  1791,  2121,  3202,    -1,  1795,    -1,  1797,    -1,  1799,
      -1,    -1,    82,    -1,    -1,    -1,    -1,    -1,  3538,   579,
    3540,     4,     5,     6,    -1,    -1,  1816,  1817,  1818,  1819,
      -1,    -1,  1822,  1823,  1824,  1825,  1826,  1827,  1828,  1829,
    1830,  1831,  1832,  1833,  1834,  1835,  1836,    -1,    -1,  1839,
    1840,  1841,  1842,  1843,  1844,  1845,  1846,  1847,  1848,  1849,
      -1,    44,    -1,    -1,   579,  1855,  1856,    -1,  1858,    47,
      -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,  3199,    -1,
      -1,    -1,  3203,    -1,    -1,    -1,    -1,    -1,  1878,  1879,
      -1,    -1,  1882,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3230,
    1900,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   104,   105,   366,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1922,    47,    -1,    -1,   119,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,    -1,    -1,   366,
      -1,    -1,    -1,    -1,   137,    -1,    -1,   581,    -1,    -1,
     230,   231,    -1,   142,   143,   148,    -1,   150,    -1,    -1,
      -1,   154,    -1,    -1,    -1,    -1,  1966,    -1,   157,  1969,
    1970,    -1,    -1,    -1,    -1,   164,   169,  1977,   167,  1979,
    1980,  1981,  1982,  1983,   264,   265,    -1,    -1,    -1,    -1,
     179,    -1,   185,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,    -1,    -1,   366,    -1,  2008,  2009,
      -1,    -1,    -1,  2825,    -1,    -1,  2016,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  3355,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   224,   230,   366,   232,
      -1,    -1,    -1,    -1,   237,    -1,    -1,   236,  2048,    -1,
      -1,    -1,  3383,    -1,    -1,  2055,  2056,  2057,    -1,  2059,
      -1,    -1,  2062,  2063,   344,   345,    -1,    -1,  2068,  2069,
    2882,   264,   265,    69,    -1,    -1,  2888,    -1,  2078,  2079,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2899,    -1,    -1,
      -1,    87,    -1,    -1,    -1,  3426,    -1,  2097,    -1,    -1,
     224,  3432,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,    47,   302,   366,  2927,    -1,   306,  3449,   308,
      -1,   310,    -1,   311,    -1,    -1,    -1,    -1,   581,    -1,
      -1,    -1,   128,    -1,    -1,    -1,    -1,    -1,   331,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2961,
      -1,  3482,    -1,    -1,   581,    -1,    -1,   346,    -1,    -1,
    2972,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,
     166,    -1,    -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   178,    -1,    -1,    -1,    -1,   311,    -1,    -1,
      -1,    -1,    -1,    -1,   190,   191,    -1,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   108,    -1,    -1,   224,    -1,
      -1,    -1,    -1,    -1,    -1,  3047,  3048,    -1,    -1,    -1,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
      69,  3063,   366,  3065,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,  2283,  2284,   366,    -1,    -1,    -1,   224,
      -1,    -1,    -1,    -1,    -1,  2295,  2296,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3118,  3119,    -1,  3121,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3129,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,    -1,    -1,    69,
      -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   546,   547,   548,    -1,    -1,    -1,  3171,
      -1,  3173,    -1,    -1,   360,   361,    -1,    -1,    -1,    -1,
    3182,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,    -1,    -1,    -1,   380,    -1,    -1,    -1,   384,   385,
     386,   387,   388,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    -1,  2404,   224,    -1,    -1,    -1,    -1,
      -1,  3223,  2412,    -1,    -1,    -1,    -1,    -1,    -1,  3231,
      -1,    -1,    -1,    -1,  2424,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   120,    -1,   366,    -1,    -1,
      -1,    -1,    -1,   128,    -1,    -1,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,    -1,    -1,   581,    -1,    -1,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
      -1,   166,   366,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   178,   224,   366,  2496,    -1,  3310,    -1,
     581,    -1,    -1,    -1,    -1,   190,   191,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,    -1,    -1,  2528,    -1,
    2530,  3343,  3344,    -1,    -1,    -1,    -1,    -1,    -1,   224,
      -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  3365,    -1,    -1,    -1,    -1,    -1,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,    -1,  2579,
    2580,    -1,    -1,    -1,   580,    -1,   582,    -1,   584,    -1,
      -1,    -1,    -1,  3405,  3406,    -1,    -1,    -1,  3410,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,    -1,
      -1,   366,    -1,  3425,    -1,    -1,    -1,    -1,    -1,    -1,
    2620,  2621,    -1,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   581,  3465,   366,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,    -1,    -1,   366,   353,    -1,
      -1,    -1,  3484,    -1,    -1,   360,   361,    -1,    -1,    -1,
      -1,    -1,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,    -1,    -1,    -1,   380,  2696,   581,    -1,   384,
     385,   386,    -1,  3515,    -1,    -1,    -1,    -1,   579,    -1,
    3522,    -1,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,    -1,    -1,   366,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3563,    14,    15,    -1,    -1,  2756,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,    -1,    39,    40,    41,
      42,    43,    -1,    -1,    -1,    47,    -1,    -1,   224,    -1,
      -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    65,    66,    -1,    -1,    -1,    70,    -1,
      72,    73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    84,    85,    -1,    -1,   581,    -1,    -1,    -1,
      92,    -1,    -1,    69,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,   111,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,   121,
     122,    -1,    -1,    -1,  2864,    -1,  2866,   224,    -1,   581,
      -1,    -1,    -1,   135,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   581,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   153,    -1,    -1,    -1,   580,    -1,    -1,    -1,    -1,
     162,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,  2911,  2912,   366,    -1,    -1,    -1,    -1,  2918,    -1,
      -1,    -1,    -1,    -1,   186,   187,   188,   189,    -1,    -1,
     192,    -1,    -1,  2933,  2934,    -1,    -1,    -1,    -1,    -1,
      -1,   203,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2949,
      -1,  2951,    -1,    -1,    -1,    -1,    -1,    -1,   581,    -1,
      -1,    -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2970,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,    -1,   244,   366,   246,    -1,   248,   249,   224,    -1,
      -1,    -1,    -1,    -1,   256,    -1,   353,   259,    -1,   261,
     262,    -1,    -1,    -1,   266,   267,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,    -1,    -1,    -1,    -1,   291,
     292,    -1,   294,   295,   296,    -1,   298,   299,    -1,    -1,
      -1,    -1,   304,    -1,    -1,   307,    -1,    -1,    -1,    -1,
     312,   313,    -1,    -1,    -1,    -1,    -1,   319,    -1,   321,
     322,   323,    -1,   325,    -1,    -1,    -1,   329,    -1,    -1,
    3070,  3071,    -1,   335,   336,   337,   338,   339,   340,   341,
     342,   343,    -1,    -1,    -1,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,    -1,    -1,    -1,  3107,    -1,    -1,
    3110,    -1,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,    -1,    -1,   366,    -1,    -1,   389,   581,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3137,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,    -1,   585,
     366,    -1,  3152,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   423,    -1,    -1,    -1,    -1,    -1,  3167,  3168,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     442,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,  3199,
      -1,  3201,    -1,  3203,    -1,    -1,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,    -1,   583,    -1,    -1,    -1,
    3230,    -1,    -1,    -1,    -1,    -1,   498,   499,    -1,    -1,
     502,   503,   504,   505,   506,   507,   508,   509,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   517,    -1,    -1,    -1,    -1,
     522,   523,    -1,    -1,    -1,    -1,    -1,   529,    -1,    -1,
      -1,  3271,    -1,    -1,    -1,    -1,    -1,    -1,  3278,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   551,
     552,   366,    -1,  3293,  3294,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,    69,    -1,   366,   578,    -1,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,     3,     4,
     366,     6,    -1,     8,     9,    -1,    -1,    -1,    13,   581,
      -1,    16,    -1,    18,    -1,    -1,    -1,    -1,    69,    -1,
      -1,    -1,    -1,    -1,    -1,  3355,    -1,    -1,    -1,    -1,
      -1,    36,    -1,    -1,    -1,   581,    -1,    -1,    -1,    44,
      45,    -1,    -1,  3373,    -1,    -1,    -1,    52,    53,    -1,
      55,    -1,    -1,  3383,    59,    60,    61,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,    -1,    -1,   366,
      -1,    -1,    77,    -1,    79,    80,    81,    82,    -1,    -1,
      -1,    86,    69,    -1,    -1,    -1,    -1,    92,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  3426,    -1,    -1,   104,
     105,   106,  3432,    -1,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,    -1,    -1,   366,    -1,    -1,  3449,
      -1,    -1,    -1,    -1,    -1,    -1,    69,   132,   133,   134,
      -1,   136,   137,   138,   139,    -1,    -1,    -1,   224,    -1,
      -1,    -1,   147,   148,    87,    -1,   151,   152,    -1,   154,
     155,   156,  3482,   158,   159,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   224,   579,   180,   181,   182,   183,   184,
     185,    69,    -1,    -1,    -1,   128,    -1,    -1,    -1,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   579,   204,
     205,    -1,    -1,   208,   209,    -1,    -1,    -1,   213,    -1,
      -1,    -1,   217,   218,   219,   581,    -1,    -1,   223,    -1,
     225,    -1,   227,   166,    -1,   230,   231,   232,    -1,   234,
      -1,    -1,   237,   238,   239,   178,    -1,   224,    -1,    -1,
     245,    -1,   247,    -1,    -1,    -1,    -1,   190,   191,    -1,
      -1,    87,    -1,   258,    -1,    -1,    -1,    -1,   263,   264,
     265,    -1,    -1,   268,    -1,    -1,    -1,   272,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   282,    -1,   284,
     285,   224,    -1,   288,   581,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   128,    -1,    -1,    -1,    -1,    -1,   303,    -1,
      -1,    -1,    -1,   308,    -1,    -1,    -1,    -1,    -1,    -1,
     315,   316,    -1,    -1,    -1,   320,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   333,    69,
     166,   581,    -1,    -1,    -1,    -1,   224,    -1,    -1,   344,
     345,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   190,   191,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,    -1,    69,   366,   224,    -1,
      -1,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   360,   361,    -1,
      -1,    -1,    -1,    -1,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   224,    -1,    -1,   380,    -1,    -1,
      -1,   384,   385,   386,   387,   388,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   458,    -1,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,    -1,    -1,    -1,    -1,    -1,    -1,
     485,   486,   487,    -1,   224,    -1,    -1,    -1,   493,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,    -1,    -1,
      -1,    -1,    -1,    -1,   360,   361,    -1,    -1,    -1,   534,
     535,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   224,    -1,    -1,   380,    -1,    -1,    87,   384,   385,
     386,   387,   388,    -1,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,    -1,
      -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   581,    -1,    -1,    -1,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   120,   166,    -1,    -1,    -1,
      -1,    -1,    -1,   128,    -1,    -1,    -1,   580,   178,   582,
      -1,   584,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     190,   191,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   166,    -1,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   178,   224,   366,    -1,    -1,   228,    -1,
      -1,    -1,    -1,    -1,    -1,   190,   191,    -1,    -1,    -1,
      -1,    87,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,   224,
      -1,    -1,    -1,   228,   120,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   128,    -1,   580,    -1,   582,    -1,   584,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,    -1,    69,
     166,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   581,   178,   366,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   190,   191,   366,    -1,    -1,    -1,
      -1,    -1,    -1,   353,    -1,    -1,    -1,    -1,    -1,    -1,
     360,   361,    -1,    -1,    -1,    -1,    -1,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,    -1,   224,    -1,
     380,    -1,   228,    -1,   384,   385,   386,    -1,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,    -1,    -1,
     366,    -1,    -1,    -1,    -1,   360,   361,    -1,    -1,    -1,
      -1,    -1,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   224,    -1,    -1,   380,    -1,    -1,    -1,   384,
     385,   386,    -1,    -1,    -1,    -1,    -1,    -1,   579,    -1,
      87,    -1,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,    -1,    -1,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   120,   224,   366,    -1,    -1,    -1,    87,
      -1,   128,    -1,    -1,    -1,    -1,    -1,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,    -1,    69,    -1,    -1,
      -1,    -1,   120,    -1,   360,   361,    -1,    -1,    -1,   166,
     128,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     376,   178,    -1,    -1,   380,    -1,    -1,    -1,   384,   385,
     386,    -1,    -1,   190,   191,    -1,    -1,    -1,   581,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,    -1,
      -1,   581,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   524,
     178,    -1,    -1,    -1,    -1,    -1,    -1,   224,    -1,    -1,
     580,   228,   190,   191,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   581,   224,    -1,    -1,    -1,
     228,    -1,    -1,    -1,    -1,   580,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,    -1,    -1,   366,
     442,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,    -1,
      -1,    -1,   224,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,    -1,    -1,   366,    -1,   524,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,    -1,
     581,   366,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,    -1,    -1,   360,   361,    -1,    -1,    -1,    -1,   224,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
      -1,    -1,    -1,   380,   580,    -1,    -1,   384,   385,   386,
      -1,    -1,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   360,   361,   366,    -1,    -1,    -1,    -1,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,    -1,
      -1,   224,   380,    -1,    -1,    87,   384,   385,   386,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     224,    -1,   366,    -1,    -1,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,    -1,    -1,   128,    -1,    -1,    -1,
      87,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,    -1,    -1,   366,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   120,   166,    -1,    -1,    -1,    -1,    -1,
      -1,   128,    -1,    -1,    -1,    -1,   178,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   524,   190,   191,
     442,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   166,
     353,    -1,    -1,    -1,    -1,    -1,   581,    -1,    -1,    -1,
      -1,   178,   224,    -1,    -1,    -1,   524,    -1,    -1,   353,
      -1,    -1,    -1,   190,   191,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   580,    -1,    -1,    -1,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,    -1,   224,    -1,    -1,
      -1,   228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   581,
      -1,    -1,   580,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,    -1,    -1,   366,    -1,    -1,    -1,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,    -1,    -1,   366,
      -1,    -1,    -1,    -1,    -1,    -1,   579,    -1,   360,   361,
      -1,    -1,    -1,    -1,    -1,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,    -1,    -1,    -1,   380,    -1,
      -1,    -1,   384,   385,   386,   387,   388,   582,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,    -1,    -1,
     366,    -1,    -1,   360,   361,    -1,    -1,    -1,    -1,    -1,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
      -1,     3,    -1,   380,     6,    -1,    -1,   384,   385,   386,
      -1,    13,    -1,    -1,    -1,    17,    18,    -1,   581,    -1,
     442,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   583,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
      -1,    -1,   366,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    63,    -1,    -1,    -1,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,    -1,    -1,    -1,    -1,    -1,    91,
     581,    93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   104,   105,   106,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   115,   116,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,    -1,    -1,   366,    -1,    -1,
     132,   133,   134,    -1,    -1,    -1,   224,    -1,    -1,    -1,
     142,    -1,    -1,    -1,   581,    -1,    -1,   149,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   580,    -1,
     366,     3,    -1,    -1,     6,   167,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    16,    17,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,    -1,    -1,   366,    -1,
      -1,    -1,    -1,   195,    -1,   581,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   580,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,    -1,    -1,   366,    59,    60,    61,
      62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     232,   233,    -1,   235,    -1,   237,    -1,    -1,   240,   241,
      -1,    -1,    -1,   245,    -1,   247,    -1,    -1,    -1,    -1,
      -1,    93,    -1,    -1,    -1,    -1,   258,   259,    -1,    -1,
      -1,    -1,   104,   105,   106,   353,    -1,   581,   270,    -1,
      -1,    -1,    -1,   115,   116,    -1,   118,   279,    -1,   281,
     282,    -1,    -1,    -1,    -1,    -1,   288,   289,   290,    -1,
     132,   133,   134,    -1,    -1,    -1,   224,   299,   300,   301,
      -1,    -1,    -1,    -1,    -1,    -1,   308,   149,    -1,    -1,
      -1,    -1,   154,   315,   316,    -1,    -1,    -1,   320,    -1,
      -1,     3,    -1,    -1,     6,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,    17,    -1,   366,    -1,    -1,
      -1,    -1,   581,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   195,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,    -1,    -1,   581,    -1,    59,    60,    61,
      62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     232,   233,    -1,   235,    -1,   237,    -1,    -1,   240,   241,
      -1,    -1,    -1,   581,    -1,   247,    -1,    -1,    -1,    -1,
      -1,    93,    94,    -1,    -1,    -1,   258,   259,    -1,    -1,
      -1,    -1,   104,   105,   106,   353,    -1,    -1,   270,    -1,
      -1,   581,    -1,   115,   116,    -1,    -1,   279,    -1,   281,
     282,    -1,    -1,    -1,    -1,    -1,   288,   289,   290,    -1,
     132,   133,   134,    -1,    -1,    -1,   458,   299,   300,   301,
     224,    -1,    -1,    -1,    -1,    -1,   308,   149,    -1,    -1,
      -1,    -1,    -1,   315,   316,    -1,    -1,    -1,   320,    -1,
      -1,     3,    -1,    -1,     6,   167,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   581,    -1,    17,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   348,    -1,   366,    -1,
      -1,    -1,    -1,   195,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     232,   233,   581,   235,    -1,   237,    -1,    -1,   240,   241,
      -1,    -1,    -1,    -1,    -1,   247,    -1,    -1,    -1,    -1,
      -1,    93,    94,    -1,    -1,    -1,   258,   259,    -1,    -1,
      -1,    -1,   104,   105,   106,    -1,    -1,   429,   270,   353,
      -1,    -1,    -1,   115,   116,    -1,    -1,   279,    -1,   281,
     282,   224,    -1,    -1,    -1,    -1,   288,   289,   290,    -1,
     132,   133,   134,    -1,    -1,    -1,   458,   299,   300,   301,
     224,    -1,    -1,    -1,    -1,    -1,   308,   149,    -1,    -1,
      -1,    -1,    -1,   315,   316,    -1,    -1,    -1,   320,    -1,
     224,    -1,   324,    -1,   326,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   581,    -1,    -1,    -1,    -1,    -1,   224,
      -1,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,    -1,   195,   366,    -1,    -1,    -1,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   224,    -1,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     232,   233,   366,   235,    -1,   237,    -1,    -1,   240,   241,
     224,    -1,    -1,   581,    -1,   247,    -1,    -1,    -1,    -1,
     353,    -1,    -1,    -1,    -1,    -1,   258,   259,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   270,   353,
     366,    -1,    -1,    -1,    -1,    -1,    -1,   279,    -1,   281,
     282,    -1,    -1,    -1,    -1,    -1,   288,   289,   290,   353,
      -1,    -1,    -1,    -1,    -1,    -1,   458,   299,   300,   301,
      -1,    -1,    -1,    -1,    -1,    -1,   308,    -1,   353,    -1,
      -1,    -1,    -1,   315,   316,    -1,    -1,    -1,   320,   224,
      -1,    -1,   324,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,    -1,    -1,   366,   581,    -1,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,    -1,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   224,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,    -1,    -1,
     366,    -1,    -1,    -1,    -1,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,    -1,    -1,   458,    -1,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   224,   581,    -1,
      -1,    -1,    -1,    -1,    -1,   581,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   224,   581,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,    -1,
      -1,   366,    -1,    -1,    -1,   224,    -1,   581,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,    -1,
      -1,   366,    -1,   280,   224,    -1,   581,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   224,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,    -1,    -1,
     366,    -1,   579,   580,    -1,   224,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   224,   579,   580,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,    -1,    -1,   366,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,    -1,    -1,
     366,    -1,    -1,    -1,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,    -1,    -1,   366,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   224,   579,   580,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   579,   580,   224,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   224,   581,   580,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   581,    -1,    -1,    -1,    -1,
     224,   579,   580,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,
     579,   580,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     581,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,   579,
     580,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
      -1,   579,   580,   224,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     579,   580,    -1,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,    -1,   280,   366,    -1,    -1,    -1,   579,
     580,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,    -1,    -1,   366,    -1,    -1,    -1,    -1,    -1,   280,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
      -1,    -1,   366,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   353,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   224,    -1,   579,   580,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   353,    -1,    -1,    -1,    -1,    -1,    -1,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,    -1,    -1,    -1,   579,   580,
      -1,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
      -1,    -1,    -1,    -1,    -1,   353,    -1,    -1,    -1,    -1,
     581,    -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   581,    -1,
      -1,    -1,    -1,   224,    -1,    -1,   579,   580,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   581,    -1,    -1,
      -1,    -1,   224,    -1,    -1,    -1,   580,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   224,    -1,    -1,    -1,   580,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     224,    -1,    -1,   579,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,    -1,    -1,    -1,    -1,    -1,   579,   224,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,    -1,
      -1,   366,    -1,   353,    -1,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,    -1,    -1,   366,    -1,    -1,
      -1,    -1,   353,    -1,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,    -1,    -1,   366,    -1,    -1,    -1,
      -1,   353,    -1,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,    -1,    -1,   366,    -1,    -1,    -1,    -1,
     353,    -1,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,    -1,    -1,   366,    -1,    -1,    -1,    -1,   353,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,    -1,
      -1,   579,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     442,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   224,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   581,   353,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   224,    -1,    -1,   579,
      -1,    -1,   581,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   224,    -1,    -1,   579,    -1,
      -1,   581,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   224,    -1,    -1,   579,    -1,    -1,
     581,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   224,    -1,    -1,   579,    -1,    -1,   581,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   224,   579,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   353,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   579,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,    -1,    -1,   366,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   353,    -1,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,    -1,    -1,   366,
      -1,    -1,    -1,    -1,   353,    -1,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,    -1,    -1,   366,    -1,
      -1,    -1,    -1,   353,    -1,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,    -1,    -1,   366,    -1,    -1,
      -1,    -1,   353,    -1,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   353,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   224,   579,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     224,    -1,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     224,   579,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   581,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   353,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     224,   579,   579,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,
     579,   579,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   579,
     579,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   579,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   353,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,   579,
     442,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   353,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   353,
      -1,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,    -1,    -1,   366,    -1,    -1,    -1,    -1,   353,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   353,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   224,    -1,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   353,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   224,   579,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   224,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,    -1,   353,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   579,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   353,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   224,   579,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   353,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   579,   579,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,    -1,    -1,   366,
      -1,    -1,    -1,   224,   579,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   353,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   579,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   224,   579,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   353,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   579,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,    -1,    -1,   366,    -1,    -1,    -1,
      -1,   224,    -1,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   353,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   224,   579,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,    -1,    -1,   366,    -1,    -1,    -1,
     224,   579,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   353,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   579,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   579,    -1,   366,    -1,    -1,    -1,    -1,   224,
      -1,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     353,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,
     579,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     353,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,
     442,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   353,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   579,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   579,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,    -1,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   353,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,   579,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   353,   579,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,    -1,   353,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   579,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   579,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   224,    -1,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   353,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   224,   579,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   353,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   224,   579,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   353,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   579,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,    -1,    -1,   366,    -1,
      -1,    -1,    -1,   224,    -1,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   353,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   224,   579,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   353,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   224,   579,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   353,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   579,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,    -1,    -1,   366,    -1,    -1,
      -1,   224,    -1,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   353,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   224,   579,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   353,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   224,   579,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   353,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   224,   579,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   579,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     224,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     353,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,
     579,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     353,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,
     579,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     353,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,
     579,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     579,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   579,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,   579,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,   579,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   224,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   579,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   224,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   579,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   224,   579,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   224,   579,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   128,    -1,    -1,   224,   579,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   579,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   224,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   579,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   140,   141,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   579,    -1,   128,   224,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   280,    -1,    -1,    -1,   140,   141,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,    -1,
      -1,    -1,   579,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   224,    -1,    -1,   128,    -1,    -1,    -1,    -1,
      -1,    -1,   579,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   224,   579,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   140,   141,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   579,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   224,   141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     579,    -1,   224,    -1,    -1,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,    -1,    -1,    -1,    -1,    -1,    -1,
     579,    -1,    -1,    -1,    -1,    -1,   224,   280,   141,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   579,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   141,   280,    -1,
      -1,    -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,
     579,    -1,    -1,    -1,    -1,    -1,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   224,    -1,    -1,    -1,   579,
     442,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,    -1,
      -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,    -1,    -1,
     366,    -1,    -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   224,    -1,
     442,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   463,   280,    -1,    -1,    -1,    -1,    -1,   224,    -1,
      -1,    -1,    -1,    -1,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   224,   280,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   224,    -1,    -1,    -1,    -1,    -1,    -1,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   353,   224,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   579,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   353,    -1,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,    -1,    -1,   366,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,    -1,    -1,    -1,    -1,    -1,
      -1,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     442,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     442,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,    -1,
      -1,   366,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,    -1,    -1,   366,    -1,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,    -1,    -1,   366,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,    -1,    -1,
     366,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   579,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,    -1,
      -1,   366,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,    -1,    -1,   366,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,    -1,    -1,   366,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,    -1,    -1,
     366,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,    -1,    -1,   366,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,    -1,    -1,   366,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   579,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   579,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     579,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   579,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   579,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   579,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     579,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   579,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   579,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   579
  };

  const unsigned short int
  parser::yystos_[] =
  {
       0,    14,    15,    39,    40,    41,    42,    43,    47,    54,
      64,    65,    66,    70,    72,    73,    74,    75,    76,    84,
      85,    92,   108,   109,   110,   111,   119,   121,   122,   135,
     153,   162,   186,   187,   188,   189,   192,   203,   224,   244,
     246,   248,   249,   256,   259,   261,   262,   266,   267,   291,
     292,   294,   295,   296,   298,   299,   304,   307,   312,   313,
     319,   321,   322,   323,   325,   329,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   389,   423,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   498,   499,   502,   503,
     504,   505,   506,   507,   508,   509,   517,   522,   523,   529,
     551,   552,   578,   588,   589,   590,   591,   592,   595,   598,
     602,   603,   604,   605,   614,   617,   618,   623,   624,   625,
     628,   631,   634,   645,   649,   660,   661,   664,   667,   670,
     674,   677,   680,   683,   686,   689,   690,   693,   696,   699,
     710,   716,   719,   722,   729,   730,   733,   734,   735,   737,
     749,   750,   751,   754,   755,   756,   765,   768,   771,   772,
     774,   777,   778,   779,   780,   781,   782,   785,   789,   792,
     793,   796,   799,   806,   807,   808,   809,   810,   811,   812,
     816,   819,   822,   825,   828,   831,   834,   837,   840,   843,
     844,   855,   858,   861,   864,   865,   868,   872,   875,   878,
     880,   883,   886,   889,  1278,   128,   580,   128,   580,   579,
     580,   703,  1278,   580,   579,   580,   580,   579,   580,   579,
     580,   703,   128,   580,   580,   579,   580,   579,   580,   703,
     579,   579,   579,   580,   579,   580,   580,   579,   579,   580,
     703,   580,   579,   580,   580,   579,   579,   580,   579,   580,
     580,   579,   580,   580,   580,   579,   580,   280,   580,   786,
     788,  1278,   579,   580,   579,   580,   579,   579,   579,   579,
     579,   580,   703,   703,   612,  1278,    71,   128,   790,   580,
     703,   579,   580,   579,   580,   703,   580,   579,   580,   579,
     580,   703,   579,   580,    71,   579,   580,   579,   580,   579,
     579,   580,   579,   580,   703,   579,   580,   703,   579,   580,
     703,   579,   580,   703,   579,   579,   580,   703,   703,   580,
     609,  1278,   610,  1278,   611,  1278,   766,   613,  1278,   579,
     580,   703,   579,   580,   579,   579,   579,   580,   580,   579,
     580,   580,   579,   580,   703,   579,   580,   579,   580,   579,
     580,   579,   580,   579,   580,   579,   580,   650,   580,   580,
     579,   580,   580,   580,   586,     0,   589,    71,   580,    71,
      71,    71,   586,   579,    21,    22,    23,    27,    28,    29,
      30,    45,    55,    82,   230,   231,   264,   265,   344,   345,
     813,   814,   815,   937,   940,   944,   963,   964,  1026,  1027,
    1033,  1034,  1068,  1069,  1070,  1071,  1072,  1073,  1074,   579,
      33,    44,    92,   814,   817,   818,   981,  1013,  1075,    80,
      81,   139,   154,   196,   486,   487,   873,   874,   937,   944,
     963,  1005,  1017,  1022,  1028,  1036,  1197,  1198,   353,   579,
    1278,   256,   335,   336,   337,   615,   107,   112,   113,   114,
     142,   164,   167,   282,   308,   676,   678,   679,   894,   916,
     924,   927,   934,  1123,  1124,  1125,  1126,    44,    46,   257,
     259,   289,   862,   863,   901,   912,   983,  1127,  1128,   335,
     866,   867,  1278,    20,    26,    31,    32,   144,   145,   853,
     854,  1052,  1056,  1059,  1060,  1061,  1064,   579,   128,   579,
     786,   786,   626,   627,  1278,    35,     3,     4,     6,     8,
       9,    13,    16,    18,    36,    44,    52,    53,    59,    60,
      61,    77,    79,    82,    86,   104,   105,   106,   132,   133,
     134,   136,   137,   138,   147,   148,   151,   152,   155,   156,
     158,   159,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   180,   181,   182,   183,   184,   185,   194,   195,   197,
     198,   199,   200,   201,   202,   204,   205,   208,   209,   213,
     217,   218,   219,   223,   225,   227,   232,   234,   237,   238,
     239,   245,   247,   258,   263,   268,   272,   284,   285,   288,
     303,   315,   316,   320,   333,   458,   485,   493,   534,   535,
     757,   758,   894,   900,   903,   907,   908,   934,   937,   938,
     939,   940,   941,   942,   943,   947,   963,   964,   965,   966,
     967,   968,   974,   976,   982,   984,   985,   986,   987,   988,
     989,   990,   991,   992,   993,   994,   995,   996,   997,   998,
     999,  1000,  1001,  1002,  1003,  1004,  1005,  1007,  1008,  1009,
    1010,  1011,  1012,  1013,  1014,  1015,  1016,  1017,  1018,  1019,
    1020,  1021,  1022,  1026,  1027,  1028,  1029,  1030,  1031,  1032,
    1033,  1034,  1035,  1036,  1037,  1038,  1039,  1040,  1042,  1043,
    1044,  1045,  1046,  1047,  1048,  1049,  1050,  1076,  1077,  1078,
    1079,  1080,  1081,  1082,  1083,  1084,  1129,  1190,  1196,  1197,
    1198,  1199,  1200,  1243,  1245,  1246,  1247,  1248,  1249,  1250,
    1252,  1253,   579,    47,   286,   311,   711,   712,   713,  1278,
      47,   311,   720,   721,  1278,    47,   311,   717,   718,  1278,
      12,   117,   247,   309,   346,   876,   877,   912,   913,   914,
     915,  1260,    88,   727,   728,   723,   724,  1278,   859,   860,
     912,   967,   974,   976,   982,   579,  1278,   629,   630,  1278,
      35,    78,   856,   857,  1278,     5,   150,   250,   251,   271,
     331,   332,   394,   783,   784,   901,   903,   912,   966,   967,
     974,   976,  1000,  1020,  1036,  1090,  1114,  1118,  1119,  1120,
    1121,  1122,  1128,  1243,  1244,   626,    35,    78,   884,   885,
    1278,  1018,   786,   163,   635,    11,    34,    49,    68,   149,
     168,   229,   255,   330,   632,   633,   899,   926,   929,   165,
    1023,   580,   353,   579,   786,   681,   682,   335,   648,   668,
     254,   881,   882,  1278,   769,   770,  1278,   773,  1278,    17,
      62,    63,    91,    93,   115,   116,   142,   167,   233,   235,
     240,   241,   270,   279,   281,   290,   299,   300,   301,   701,
     775,   776,   893,   894,   895,   899,   900,   901,   902,   903,
     904,   905,   906,   907,   908,   909,   910,   912,   920,   921,
     925,   930,   931,   932,   933,   934,   939,   941,   967,   974,
     976,   989,  1012,  1016,  1018,  1024,  1025,  1038,  1039,  1042,
    1043,  1047,  1048,  1049,  1050,  1179,  1180,  1190,  1250,  1251,
     579,   579,   353,   579,  1278,   327,   580,   607,   608,   128,
     579,    87,   128,   166,   178,   190,   191,   360,   361,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   380,
     384,   385,   386,   387,   388,   580,   641,   706,  1278,   259,
     579,   684,   685,   912,   937,   142,   143,   157,   167,   179,
     236,   302,   306,   310,   687,   688,   894,   896,   897,   898,
     917,   922,   923,   927,   928,  1006,  1254,  1260,   579,   786,
      47,   335,   646,   647,   648,   254,   226,   237,   297,   349,
     847,   848,   937,   940,   944,   969,   970,  1128,  1263,  1264,
     579,   280,   890,   891,  1278,   224,   582,   685,   688,   694,
     695,   126,   127,   252,   253,   260,   887,   888,  1255,  1256,
    1257,  1258,  1259,   869,   675,   676,   118,   348,   429,   700,
     701,   702,   911,   918,  1005,  1129,  1130,   579,    92,   265,
     570,   849,   850,   937,   940,   944,   969,   971,   972,   973,
    1128,  1263,  1264,   579,    94,   324,   802,   803,  1041,  1191,
     579,   701,   804,   805,  1041,  1191,   579,   224,   797,   798,
     167,   326,   800,   801,   805,   919,  1242,   579,   579,   161,
     500,   353,   579,  1278,   327,   608,   353,   579,  1278,   327,
     608,   353,   579,  1278,   327,   608,   767,  1278,   353,   579,
    1278,    19,    20,    24,    25,    26,    31,    32,    37,    38,
     105,   144,   145,   232,   851,   852,   975,   977,  1051,  1053,
    1054,  1055,  1057,  1058,  1062,  1063,  1065,  1066,  1067,  1263,
    1264,   579,   216,   119,   390,   391,   392,   393,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   546,   547,   548,   845,   846,   903,   937,   940,   944,
     963,   964,   966,   967,   974,   976,   982,   984,   994,  1005,
    1020,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,  1095,  1096,  1097,  1098,  1099,  1100,  1101,  1102,  1103,
    1104,  1105,  1106,  1107,  1108,  1109,  1110,  1111,  1112,  1113,
    1115,  1116,  1117,  1118,  1119,  1243,  1244,    56,    57,    82,
      83,   230,   731,   732,   935,   936,   945,   946,   948,  1026,
    1027,   418,   419,   420,   421,   422,   423,   424,   427,   428,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   442,
     443,   444,   445,   446,   447,   448,   465,   466,   467,   468,
     469,   472,   473,   474,   475,   476,   478,   479,   480,   481,
     482,   483,   484,   488,   489,   490,   561,   820,   821,   937,
    1013,  1133,  1134,  1135,  1136,  1137,  1138,  1139,  1140,  1141,
    1142,  1143,  1144,  1145,  1146,  1147,  1148,  1149,  1150,  1151,
    1152,  1153,  1155,  1156,  1157,  1158,  1159,  1160,  1161,  1162,
    1163,  1164,  1165,  1166,  1167,  1168,  1169,  1170,  1171,  1172,
    1173,  1174,  1175,  1176,  1177,  1178,  1205,   501,   293,   317,
     318,   494,   497,   536,   537,   539,   540,   542,   543,   544,
     549,   560,   829,   830,  1201,  1202,  1204,  1221,  1229,  1230,
    1231,  1234,  1235,  1236,  1237,  1238,  1239,  1240,   579,   538,
     823,   824,  1201,  1202,  1204,  1221,  1229,  1230,  1231,  1233,
    1234,  1235,  1236,  1237,  1239,  1240,   440,   541,   562,   563,
     564,   565,   566,   567,   568,   569,   571,   572,   573,   574,
     575,   576,   577,   841,   842,   937,  1026,  1027,  1133,  1134,
    1135,  1136,  1137,  1143,  1144,  1145,  1147,  1151,  1152,  1153,
    1154,  1201,  1202,  1203,  1205,  1206,  1207,  1208,  1209,  1210,
    1211,  1212,  1213,  1214,  1215,  1216,  1217,  1218,  1219,  1220,
      63,   175,   243,   559,   838,   839,  1131,  1132,  1201,  1202,
    1221,  1222,  1223,   554,   555,   556,   557,   558,   835,   836,
    1201,  1202,  1204,  1224,  1225,  1226,  1227,  1228,   550,   832,
     833,  1201,  1202,  1231,  1232,   545,   826,   827,  1201,  1202,
    1204,  1221,  1229,  1230,  1234,  1235,  1236,  1237,  1238,  1239,
    1240,  1241,   579,   256,   492,   518,   519,   520,   521,   662,
     663,  1181,  1182,  1183,  1184,  1185,  1186,   525,   526,   528,
     665,   666,  1181,  1187,  1188,  1189,   530,   531,   532,   533,
     697,   698,  1192,  1193,  1194,  1195,   269,   553,   691,   692,
    1261,  1262,   691,   460,    47,   108,   735,  1278,   736,   980,
    1278,    47,   108,   750,  1278,    47,   108,   755,  1278,   120,
     166,   178,   190,   191,   228,   360,   361,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   380,   384,   385,
     386,   580,   619,   706,  1278,   140,   141,   460,  1278,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,   353,   581,    71,    71,    71,   353,   581,    71,
      71,   581,   353,  1278,   581,    71,    71,    71,    71,    71,
      71,    71,    71,   353,   581,    71,    71,    71,    71,    71,
     353,   581,  1278,    69,   867,   353,    71,    71,    71,   581,
     353,   579,   581,   581,    69,   627,    71,   581,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,   353,
     581,  1278,  1278,    69,   712,   353,   579,  1278,  1278,    69,
     721,   353,  1278,  1278,    69,   718,   353,   581,    71,    71,
     581,   353,   360,   581,    69,   724,   353,   353,   581,   581,
      69,   630,   580,   581,    71,    69,   857,   353,    71,    71,
      71,    71,    71,    71,    71,    71,   581,   353,    69,   581,
      71,    69,   885,   353,   580,   581,   581,    71,   582,   584,
     637,   638,   641,   644,    71,    71,    71,    71,   353,   581,
      71,   581,   706,   786,   580,   353,   581,  1278,    69,   648,
     581,    69,   882,   353,    69,   770,   580,    69,  1278,   353,
     619,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,   353,   581,  1278,   327,   608,   608,   353,
     606,  1278,   353,   581,   606,   579,   580,   580,   580,   580,
     641,   641,   580,   580,   580,   580,   580,   580,   580,   580,
     580,   580,   580,   580,   580,   580,   580,   580,   641,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   366,
     791,   642,    71,   353,   581,    71,    71,    71,    71,    71,
     353,   581,   581,  1278,  1278,    69,   647,   581,    71,    71,
      71,   581,   353,    71,    69,   891,    71,    71,   360,   361,
     580,   672,   673,   706,   707,   353,   581,    71,    71,    71,
      71,    71,   581,   353,   582,   870,   871,  1278,   353,   581,
      71,    71,   353,   581,    71,    71,    71,   581,   353,    71,
      71,   353,   581,   353,   581,   356,   357,   358,   359,    69,
     798,    71,    71,   353,   581,    71,    71,  1278,   327,   608,
     608,  1278,   327,   608,   608,  1278,   327,   608,   608,   353,
     579,  1278,  1278,    71,    71,    71,    71,    71,    71,    71,
     581,   353,   581,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,   581,   353,    71,    71,    71,    71,
      71,   353,   581,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,   353,   581,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
     353,   581,   353,   581,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
     353,   581,    71,    71,    71,   353,   581,    71,    71,    71,
      71,   353,   581,   353,   581,    71,   353,   581,   430,   511,
     513,   514,   651,   652,    71,    71,    71,    71,    71,    71,
     353,   581,    71,   353,   581,    71,    71,    71,    71,   353,
     581,    71,    71,   353,   581,   581,   740,   580,   580,   579,
     586,   353,   581,    71,   580,   580,   579,   586,   580,   580,
     579,   586,   580,   580,   580,   580,   619,   619,   580,   580,
     580,   580,   580,   580,   580,   580,   580,   580,   580,   580,
     580,   580,   619,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   366,   579,   620,   580,   738,   586,   706,
     707,   706,   128,   707,   128,   786,   128,   128,   582,  1268,
    1270,  1271,   128,   128,  1278,  1265,  1278,   815,   128,   128,
     706,   128,   818,   128,  1271,   706,   579,   703,   873,   616,
    1278,   128,   128,   128,   706,   706,   128,   706,   128,   679,
     579,   706,   580,    67,   273,   274,   275,   276,   277,   278,
     128,   128,   863,   579,   579,   579,  1278,   350,   351,   352,
     728,   728,   579,   703,   853,   579,   703,   579,   703,   579,
     619,   579,   128,   280,   706,  1278,   706,   706,   706,   128,
     786,  1268,  1271,   455,   456,   457,   459,   580,   978,  1268,
    1271,   128,   580,   706,   128,   706,   128,   128,    58,    89,
      90,   305,   706,   706,   706,   706,   706,   706,   128,   128,
     128,   128,   120,   360,   361,   707,   708,   709,   128,   128,
     128,  1278,   786,   128,  1271,   582,  1272,  1273,  1273,   461,
     462,   463,   786,   128,   206,   207,   459,   706,   210,   211,
     212,   214,   215,   128,  1278,   220,   221,   222,   220,   221,
     222,   580,   128,   128,   706,   120,   706,   128,    89,    90,
     706,   128,    50,    51,    89,   580,   128,   758,   579,   703,
     353,   579,    10,   103,   129,   130,   131,   242,   328,   471,
     619,   622,   714,   726,   353,   353,   579,   619,   353,   353,
     579,   619,   579,   128,   128,   579,   876,   128,   579,   579,
     619,   860,   579,   703,   586,   579,   128,   360,   361,   705,
     579,   786,   579,   619,   707,   128,   128,   705,   128,   128,
     128,   786,   128,   579,   783,   579,   579,   786,   579,  1278,
     128,  1266,   579,   579,   596,   224,   639,   640,  1278,    69,
     638,   644,    71,   579,   706,   580,   128,   580,   632,   579,
     146,   193,   788,   581,   580,   706,   682,   579,   579,   579,
     579,   579,  1278,   579,   619,   579,   353,   619,  1278,   579,
     706,   128,   128,   128,   786,   706,   128,   706,   128,   706,
     128,   128,   128,   776,   579,   703,   327,   608,   608,   606,
      71,   581,   606,   641,   641,   641,   641,   641,   641,   641,
     641,   641,   641,   641,   641,   641,   641,   641,   641,   641,
     641,   641,   705,   581,   641,   641,   641,   641,   641,   641,
     641,   641,   641,   641,   641,   579,   580,   128,   685,   579,
     706,   706,   128,   706,   128,   688,   579,   579,   353,    71,
     353,   579,   579,   579,   128,  1278,  1278,   579,   703,   847,
     892,  1278,   579,   892,  1278,   706,   706,   619,   579,   583,
     353,   580,   707,   695,   579,   786,   580,   786,   580,   128,
     579,   887,   703,    69,   871,    71,   676,   579,   706,  1271,
     702,   579,   703,   128,   128,  1271,   579,   703,   849,   580,
     619,   803,   579,   703,   805,   579,   794,   795,  1278,   619,
     619,   619,   619,   579,   128,   706,   801,   579,   703,   600,
     599,   327,   608,   608,   327,   608,   608,   327,   608,   608,
    1278,   786,   350,   351,   352,   128,   128,   580,   978,   728,
     728,   579,   703,   851,   579,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   706,   128,
     582,  1276,  1277,   706,   706,   580,   580,   580,   128,   128,
     580,   706,   128,   706,   706,   706,   706,   706,   579,   845,
     786,  1278,   728,   728,   128,   732,   579,   128,   515,   516,
     128,   128,   128,   128,   786,   128,   580,   128,   224,   513,
     514,   128,   128,   128,   128,   128,   706,   706,   128,   128,
     128,   128,   128,   128,   706,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,  1273,   821,   579,   593,   128,   786,   128,
     786,   786,  1273,   128,   128,  1273,   707,   128,   830,   579,
     703,   824,   579,   441,   459,   706,   706,   706,   128,   706,
     128,   128,   706,   706,   128,   128,   128,   128,   706,   706,
     842,   579,   128,   128,   128,   839,   579,   128,   707,   707,
     128,   836,   579,   833,   579,   128,   827,   579,   510,   512,
     527,   579,   579,    69,   652,   582,   582,  1273,  1275,   128,
     706,  1277,   128,   128,   663,   579,  1268,  1271,   666,   579,
     786,   128,   786,   786,   698,   579,   786,   128,   692,   579,
     579,   580,  1278,  1278,   980,   579,   728,  1278,  1278,   460,
    1278,  1278,  1278,   141,  1278,   619,   619,   619,   619,   619,
     619,   619,   619,   619,   619,   619,   619,   619,   619,   619,
     619,   619,   619,   581,   619,   619,   619,   619,   619,   619,
     619,   619,   619,   619,   619,   580,   123,   124,   125,   752,
     753,   956,   957,   958,   580,   141,   460,   128,   353,  1268,
    1269,   353,   583,  1269,   585,   579,   579,   579,   353,   579,
    1278,   703,   259,   581,   579,   579,   579,   579,   626,   978,
     979,   703,   120,   120,   353,   707,   353,   583,   707,   280,
     759,   760,   280,   763,   764,   579,  1278,   353,   579,   353,
    1278,   619,   353,  1278,   619,   579,    69,   717,   353,   579,
     140,   141,   460,  1278,   128,   128,   581,   629,   581,   353,
     579,   626,   581,   353,   581,   585,   581,   884,   641,    71,
     353,   583,    71,   579,   641,   703,   786,   787,   636,   579,
     706,   581,   259,   668,   353,   580,   581,  1278,   579,   619,
     579,   608,   280,   353,   353,   581,   581,   581,   581,   581,
     581,   581,   581,   581,   581,   581,   581,   581,   581,   353,
     581,   353,   581,   581,   581,   641,   643,   581,  1278,   619,
    1278,   311,   646,   579,   353,   579,  1278,   579,   581,   581,
     673,   579,   580,   707,   619,   703,   703,   583,   579,   619,
     579,   579,   703,   579,   579,   795,   579,   579,   579,   579,
     579,   641,   641,   608,   608,   608,   979,   579,   709,   583,
     709,   585,   703,   704,   704,   704,   704,   703,   641,   579,
     128,   128,   579,   579,   703,  1273,  1274,    95,    96,    97,
      98,    99,   100,   101,   102,   287,   747,   748,   949,   950,
     951,   953,   954,   955,   959,   960,   962,  1238,   353,   581,
     585,   353,   581,   586,   353,   581,   586,   353,   353,   581,
     581,   581,   581,   581,   581,   581,   581,   581,   581,   581,
     581,   581,   581,   353,   581,   353,   581,   619,   621,    71,
      71,    71,   353,   581,    96,    98,   745,   746,   949,   950,
     951,   952,   954,   955,   959,   960,   961,  1238,   580,   739,
     585,  1269,   583,  1269,  1278,  1278,   581,   128,   669,   586,
      69,   353,   581,   581,   707,   583,   707,   353,   353,   581,
     353,   353,   581,   619,   622,   726,   622,   715,   353,   353,
     619,   353,   579,   579,    69,   619,   580,   741,   586,    71,
      69,   579,   619,    69,   579,   360,   361,   582,   879,   353,
     128,   353,    69,   581,   280,   640,   641,   641,   579,   581,
     353,   581,   637,   581,   669,    69,   879,   361,   705,  1267,
     579,   619,   579,   641,   641,   641,   641,   580,   353,   581,
     703,    71,   579,    71,   619,    69,  1278,   579,   619,   581,
     581,   581,    71,   579,   581,   581,   581,   581,   581,   581,
     581,   581,   581,   581,   353,   579,   583,   353,   583,    71,
      71,    71,    71,    71,    71,    71,    71,    71,   353,   581,
    1278,   586,   728,  1278,   586,   460,  1278,   586,   141,   619,
     619,   619,   619,   353,   581,  1277,   706,   707,   753,   579,
      71,    71,   353,   581,   752,   580,   128,   585,   128,   353,
     579,   140,   141,   460,  1278,   579,   978,   280,   707,   759,
     280,   580,   707,   763,   353,   353,   353,   619,   619,   579,
     619,   579,   579,   752,   580,   141,   460,   619,   579,   579,
     579,   709,   579,  1278,  1278,   579,   597,  1278,    71,   579,
     579,   786,    69,   579,   579,   579,   580,   581,   585,   581,
     579,   581,   581,   353,   353,   641,   641,   579,   619,   619,
     579,   579,   890,   581,   619,   601,  1278,   601,   594,  1278,
     653,   510,   655,  1273,   707,  1273,   706,  1275,   707,  1273,
     443,   449,   450,   451,   452,   453,   454,   464,   470,   725,
    1273,  1273,   748,   579,   581,   581,   460,  1278,   581,   141,
    1278,   581,   581,   353,   353,   619,   707,   619,   746,   579,
     581,   745,   128,   585,   128,   334,   580,   743,   586,   280,
     761,   762,   622,   715,   622,   353,   579,   579,   581,   745,
     580,   742,   579,   353,   709,   353,   353,   353,   579,  1278,
     327,   641,   579,   334,   705,   353,   705,   353,   641,   641,
     581,   579,   579,    69,   579,   353,   579,  1278,   327,   608,
     579,   353,   579,  1278,   327,   360,   361,   524,   619,   657,
     658,   659,   128,   510,   586,   586,   586,   586,   586,   619,
     619,   579,   581,   128,   585,   580,   671,   707,   752,   580,
     141,   460,   353,   353,   581,   353,   353,   619,   579,   581,
     752,   580,   709,   583,   879,   879,  1278,   327,   579,   671,
     585,   879,   879,   581,   581,   579,  1278,   327,   608,   608,
    1278,   327,   524,   524,   580,   362,    71,   619,   659,   353,
     128,   460,  1278,   460,   141,  1278,   141,   581,   581,   579,
     128,   619,   353,   579,   580,   707,   581,   745,   580,   744,
     280,   707,   761,   726,   622,   579,   579,   581,   745,   583,
     579,   579,   327,   579,   705,   579,   579,   327,   608,   608,
     327,   580,   580,  1278,   524,   654,   656,  1278,   353,   586,
     586,   581,   580,   707,   619,   579,   581,   752,   580,   353,
     353,   579,   581,   581,   608,  1278,  1278,   353,   580,   657,
     353,   579,   656,   460,   141,   619,   581,   579,   581,   745,
     715,   622,   579,   353,   353,   128,  1278,   579,  1278,   579,
     581,   579,   581,   353,   128,   128,   581,   353,   579,   619,
     581,   581,   128,   581
  };

  const unsigned short int
  parser::yyr1_[] =
  {
       0,   587,   588,   588,   589,   589,   589,   589,   589,   589,
     589,   589,   589,   589,   589,   589,   589,   589,   589,   589,
     589,   589,   589,   589,   589,   589,   589,   589,   589,   589,
     589,   589,   589,   589,   589,   589,   589,   589,   589,   589,
     589,   589,   589,   589,   589,   589,   589,   589,   589,   589,
     589,   589,   589,   589,   589,   589,   589,   589,   589,   589,
     589,   589,   589,   589,   589,   589,   589,   589,   589,   589,
     589,   589,   589,   589,   589,   589,   589,   589,   589,   589,
     589,   589,   589,   589,   589,   589,   589,   589,   589,   589,
     589,   589,   589,   589,   589,   589,   589,   589,   589,   589,
     590,   590,   591,   593,   592,   594,   594,   594,   594,   594,
     594,   596,   595,   597,   597,   597,   597,   597,   597,   598,
     599,   598,   600,   598,   601,   601,   601,   601,   601,   601,
     601,   601,   601,   601,   601,   601,   602,   603,   604,   605,
     606,   607,   607,   607,   607,   608,   608,   609,   609,   609,
     609,   609,   609,   609,   609,   609,   609,   609,   609,   610,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   610,
     610,   611,   611,   611,   611,   611,   611,   611,   611,   611,
     611,   611,   611,   612,   612,   612,   612,   612,   612,   612,
     612,   612,   612,   612,   612,   613,   613,   613,   614,   615,
     615,   615,   615,   616,   616,   616,   617,   617,   618,   619,
     619,   619,   619,   619,   619,   619,   619,   619,   619,   619,
     619,   619,   619,   619,   619,   619,   619,   619,   619,   619,
     619,   619,   619,   619,   619,   619,   619,   619,   619,   619,
     620,   619,   619,   619,   619,   619,   619,   619,   619,   621,
     621,   622,   622,   623,   623,   624,   625,   625,   626,   626,
     627,   628,   628,   629,   629,   630,   631,   632,   632,   632,
     632,   632,   632,   632,   632,   632,   632,   633,   633,   635,
     634,   636,   634,   637,   637,   637,   637,   638,   638,   638,
     638,   639,   639,   640,   640,   641,   641,   641,   641,   641,
     641,   641,   641,   641,   641,   641,   641,   641,   641,   641,
     641,   641,   641,   641,   641,   641,   641,   641,   641,   641,
     641,   641,   641,   641,   641,   641,   641,   642,   641,   641,
     641,   641,   641,   641,   641,   643,   643,   644,   645,   645,
     646,   646,   647,   647,   647,   647,   647,   648,   650,   649,
     651,   651,   652,   652,   653,   654,   652,   652,   652,   655,
     655,   656,   656,   657,   657,   658,   658,   659,   659,   659,
     659,   660,   661,   662,   662,   663,   663,   663,   663,   663,
     663,   664,   665,   665,   666,   666,   666,   666,   667,   667,
     668,   668,   669,   669,   669,   669,   669,   669,   670,   671,
     671,   671,   671,   671,   671,   672,   672,   673,   673,   673,
     673,   673,   673,   674,   674,   675,   675,   676,   676,   676,
     676,   676,   676,   676,   676,   677,   677,   678,   678,   679,
     679,   680,   680,   681,   681,   682,   683,   683,   684,   684,
     685,   685,   686,   686,   687,   687,   688,   688,   688,   688,
     688,   688,   688,   688,   688,   688,   688,   688,   689,   690,
     691,   691,   692,   692,   693,   693,   694,   694,   695,   695,
     696,   697,   697,   698,   698,   698,   698,   699,   699,   699,
     699,   700,   700,   701,   701,   701,   701,   701,   701,   701,
     701,   701,   701,   701,   701,   701,   701,   701,   701,   701,
     701,   701,   701,   701,   701,   701,   701,   701,   701,   701,
     701,   701,   701,   701,   701,   701,   701,   701,   701,   701,
     701,   701,   701,   701,   701,   702,   702,   702,   702,   702,
     702,   703,   703,   703,   704,   704,   705,   705,   705,   706,
     706,   707,   707,   707,   708,   708,   708,   709,   709,   710,
     711,   711,   712,   712,   713,   713,   713,   713,   714,   714,
     714,   714,   714,   715,   715,   715,   715,   716,   716,   716,
     717,   717,   718,   718,   718,   719,   720,   720,   721,   721,
     721,   722,   723,   723,   724,   725,   725,   725,   725,   725,
     725,   725,   725,   725,   726,   726,   726,   726,   726,   726,
     726,   726,   727,   728,   728,   729,   730,   731,   731,   732,
     732,   732,   732,   732,   732,   732,   733,   734,   735,   735,
     735,   736,   736,   738,   737,   739,   737,   740,   737,   741,
     737,   742,   737,   743,   737,   744,   737,   745,   745,   746,
     746,   746,   746,   746,   746,   746,   746,   746,   746,   747,
     747,   748,   748,   748,   748,   748,   748,   748,   748,   748,
     748,   749,   750,   750,   750,   750,   750,   750,   751,   751,
     751,   751,   751,   751,   752,   752,   753,   753,   753,   754,
     755,   755,   755,   755,   755,   755,   756,   756,   756,   756,
     757,   757,   758,   758,   758,   758,   758,   758,   758,   758,
     758,   758,   758,   758,   758,   758,   758,   758,   758,   758,
     758,   758,   758,   758,   758,   758,   758,   758,   758,   758,
     758,   758,   758,   758,   758,   758,   758,   758,   758,   758,
     758,   758,   758,   758,   758,   758,   758,   758,   758,   758,
     758,   758,   758,   758,   758,   758,   758,   758,   758,   758,
     758,   758,   758,   758,   758,   758,   758,   758,   758,   758,
     758,   758,   758,   758,   758,   758,   758,   758,   758,   758,
     758,   758,   758,   758,   758,   758,   758,   758,   758,   758,
     758,   758,   758,   758,   758,   758,   758,   758,   758,   758,
     758,   758,   758,   758,   758,   758,   758,   758,   758,   758,
     758,   758,   759,   759,   760,   760,   761,   761,   762,   762,
     763,   763,   763,   764,   764,   766,   765,   767,   767,   767,
     768,   769,   769,   770,   771,   772,   773,   773,   773,   773,
     774,   775,   775,   776,   776,   776,   776,   776,   776,   776,
     777,   777,   777,   777,   778,   778,   779,   779,   780,   781,
     782,   782,   783,   783,   784,   784,   784,   784,   784,   784,
     784,   784,   784,   784,   784,   784,   784,   784,   784,   784,
     784,   784,   784,   784,   785,   785,   786,   786,   787,   787,
     788,   788,   788,   788,   788,   788,   790,   791,   789,   792,
     792,   792,   792,   793,   793,   793,   793,   794,   794,   795,
     796,   797,   797,   798,   798,   798,   798,   799,   799,   799,
     799,   800,   800,   801,   801,   801,   802,   802,   803,   803,
     804,   804,   805,   805,   805,   806,   806,   807,   808,   809,
     809,   809,   809,   810,   810,   810,   810,   811,   811,   811,
     811,   812,   812,   812,   812,   813,   813,   813,   813,   813,
     813,   813,   814,   814,   814,   814,   814,   814,   814,   814,
     814,   814,   815,   815,   816,   816,   817,   817,   817,   817,
     818,   818,   819,   819,   820,   820,   820,   820,   820,   820,
     820,   820,   820,   820,   820,   820,   820,   820,   820,   820,
     820,   820,   820,   820,   820,   820,   820,   820,   820,   820,
     820,   820,   820,   820,   820,   820,   820,   820,   820,   820,
     820,   820,   820,   820,   820,   820,   820,   820,   820,   820,
     820,   820,   821,   821,   822,   822,   823,   823,   823,   823,
     823,   823,   823,   823,   823,   823,   823,   823,   823,   823,
     824,   824,   825,   825,   826,   826,   826,   826,   826,   826,
     826,   826,   826,   826,   826,   826,   826,   826,   827,   827,
     828,   828,   829,   829,   829,   829,   829,   829,   829,   829,
     829,   829,   829,   829,   829,   829,   830,   830,   831,   831,
     831,   831,   832,   832,   832,   832,   833,   833,   834,   834,
     835,   835,   835,   835,   835,   835,   835,   835,   836,   836,
     837,   837,   838,   838,   838,   838,   838,   838,   838,   839,
     839,   840,   840,   841,   841,   841,   841,   841,   841,   841,
     841,   841,   841,   841,   841,   841,   841,   841,   841,   841,
     841,   841,   841,   841,   841,   841,   841,   841,   841,   841,
     841,   841,   841,   841,   841,   841,   841,   841,   842,   842,
     843,   843,   844,   844,   845,   845,   846,   846,   846,   846,
     846,   846,   846,   846,   846,   846,   846,   846,   846,   846,
     846,   846,   846,   846,   846,   846,   846,   846,   846,   846,
     846,   846,   846,   846,   846,   846,   846,   846,   846,   846,
     846,   846,   846,   846,   846,   846,   846,   846,   846,   846,
     846,   846,   846,   846,   846,   846,   846,   847,   847,   848,
     848,   848,   848,   848,   848,   848,   848,   849,   849,   850,
     850,   850,   850,   850,   850,   850,   850,   850,   850,   851,
     851,   852,   852,   852,   852,   852,   852,   852,   852,   852,
     852,   852,   852,   852,   852,   852,   853,   853,   854,   854,
     854,   854,   854,   854,   855,   856,   856,   857,   857,   858,
     858,   858,   858,   859,   859,   860,   860,   860,   860,   860,
     861,   862,   862,   863,   863,   863,   863,   863,   864,   864,
     865,   866,   866,   867,   869,   868,   870,   870,   871,   871,
     872,   872,   872,   872,   873,   873,   874,   874,   874,   874,
     874,   874,   874,   874,   874,   874,   875,   875,   876,   876,
     877,   877,   877,   877,   877,   878,   879,   879,   879,   879,
     880,   881,   881,   882,   882,   882,   883,   883,   884,   884,
     885,   885,   885,   886,   886,   887,   887,   888,   888,   888,
     888,   888,   889,   889,   890,   890,   891,   891,   892,   892,
     892,   893,   894,   895,   896,   897,   898,   899,   900,   901,
     902,   903,   904,   905,   906,   907,   908,   909,   910,   911,
     912,   913,   914,   915,   916,   917,   918,   918,   919,   920,
     921,   922,   923,   924,   925,   925,   926,   927,   928,   929,
     930,   931,   932,   933,   934,   935,   936,   937,   938,   939,
     940,   940,   941,   941,   942,   942,   943,   944,   945,   946,
     947,   948,   949,   950,   951,   952,   953,   954,   955,   956,
     957,   958,   959,   960,   961,   962,   963,   964,   965,   966,
     967,   967,   968,   968,   969,   970,   971,   972,   973,   974,
     975,   976,   976,   977,   977,   978,   978,   978,   978,   979,
     979,   980,   981,   982,   983,   984,   985,   986,   987,   988,
     989,   990,   991,   992,   993,   994,   995,   995,   996,   997,
     998,   999,  1000,  1001,  1002,  1003,  1004,  1005,  1006,  1007,
    1008,  1009,  1010,  1010,  1010,  1011,  1012,  1013,  1014,  1015,
    1016,  1017,  1018,  1019,  1020,  1021,  1022,  1023,  1023,  1024,
    1025,  1026,  1027,  1028,  1029,  1030,  1031,  1032,  1033,  1034,
    1035,  1036,  1037,  1038,  1039,  1040,  1041,  1042,  1042,  1043,
    1044,  1044,  1044,  1044,  1045,  1046,  1047,  1047,  1047,  1048,
    1049,  1050,  1051,  1052,  1053,  1054,  1055,  1056,  1057,  1058,
    1058,  1058,  1059,  1059,  1059,  1060,  1061,  1062,  1063,  1064,
    1065,  1066,  1067,  1068,  1069,  1070,  1071,  1072,  1073,  1074,
    1075,  1076,  1077,  1077,  1077,  1078,  1079,  1079,  1079,  1080,
    1080,  1081,  1082,  1083,  1083,  1083,  1084,  1084,  1084,  1085,
    1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,
    1096,  1097,  1098,  1099,  1100,  1101,  1102,  1103,  1104,  1105,
    1106,  1107,  1108,  1109,  1110,  1111,  1112,  1113,  1114,  1114,
    1115,  1116,  1117,  1118,  1119,  1120,  1121,  1122,  1123,  1124,
    1125,  1126,  1127,  1128,  1128,  1128,  1128,  1128,  1128,  1128,
    1129,  1130,  1131,  1132,  1133,  1133,  1133,  1134,  1135,  1136,
    1137,  1138,  1139,  1140,  1141,  1142,  1142,  1142,  1143,  1144,
    1145,  1146,  1147,  1148,  1149,  1150,  1151,  1152,  1153,  1154,
    1154,  1155,  1156,  1157,  1158,  1159,  1160,  1161,  1162,  1163,
    1164,  1165,  1166,  1167,  1168,  1169,  1170,  1171,  1172,  1173,
    1174,  1175,  1176,  1177,  1178,  1179,  1180,  1181,  1182,  1183,
    1183,  1184,  1185,  1186,  1187,  1188,  1189,  1189,  1190,  1191,
    1192,  1193,  1194,  1194,  1195,  1195,  1196,  1197,  1198,  1199,
    1200,  1201,  1202,  1203,  1204,  1205,  1206,  1207,  1208,  1209,
    1210,  1211,  1212,  1213,  1214,  1215,  1216,  1217,  1218,  1219,
    1220,  1221,  1222,  1223,  1224,  1225,  1226,  1227,  1228,  1229,
    1230,  1231,  1232,  1233,  1234,  1235,  1236,  1237,  1238,  1238,
    1239,  1240,  1241,  1242,  1243,  1244,  1245,  1246,  1247,  1247,
    1247,  1247,  1248,  1249,  1250,  1251,  1252,  1253,  1254,  1255,
    1256,  1257,  1258,  1259,  1260,  1261,  1262,  1263,  1263,  1264,
    1265,  1266,  1267,  1267,  1268,  1269,  1269,  1270,  1270,  1270,
    1270,  1271,  1271,  1272,  1272,  1272,  1272,  1273,  1273,  1274,
    1274,  1275,  1275,  1276,  1276,  1277,  1278,  1278,  1278,  1278,
    1278,  1278,  1278,  1278,  1278,  1278,  1278,  1278,  1278,  1278,
    1278,  1278,  1278,  1278,  1278,  1278
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
       0,     5,     8,     4,     8,     4,     4,     1,     1,     1,
       3,     0,     1,     5,     8,     7,     5,     8,     2,     1,
       4,     5,     8,     2,     1,     7,     7,     1,     1,     1,
       1,     1,     1,     1,     5,     1,     5,     3,     1,     0,
       6,     0,     9,     2,     2,     1,     1,     4,     2,     7,
       5,     3,     1,     3,     1,     3,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     7,
       2,     2,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     6,     6,     0,     5,     8,
       4,     8,     4,     4,     4,     1,     3,     5,     5,     8,
       2,     1,     1,     6,     5,     7,     7,     9,     0,     6,
       2,     1,     5,     3,     0,     0,    10,     2,     2,     6,
       5,     3,     1,     1,     1,     1,     2,     6,     7,     7,
       8,     2,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     5,     3,     1,     1,     1,     1,     1,     5,     8,
       2,     1,     3,     2,     5,     4,     3,     1,     6,     5,
       4,     3,     3,     2,     1,     3,     1,     5,     3,     4,
       2,     3,     1,     2,     5,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     5,     3,     1,     1,
       1,     2,     5,     3,     1,     0,     2,     5,     3,     1,
       1,     1,     2,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     5,
       3,     1,     1,     1,     2,     5,     3,     1,     1,     1,
       5,     3,     1,     1,     1,     1,     1,     2,     5,     3,
       6,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     3,     1,     1,     1,     2,     2,     1,     1,
       1,     2,     2,     1,     2,     2,     1,     1,     1,     5,
       2,     1,     4,     2,     2,     1,     4,     1,     3,     5,
       9,     1,     5,     3,     5,     7,     9,     5,     7,     8,
       2,     1,     5,     7,     4,     5,     2,     1,     7,     9,
       6,     5,     2,     1,     6,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     5,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     4,     3,     6,
       8,     3,     1,     0,     8,     0,    10,     0,     8,     0,
      11,     0,    13,     0,    13,     0,    15,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     3,     5,     6,     8,     8,    10,     7,     9,
      10,    12,    12,    14,     3,     1,     1,     1,     1,     4,
       3,     5,     6,     8,     8,    10,     2,     5,     3,     6,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
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
       1,     1,     3,     3,     1,     3,     3,     3,     1,     3,
       3,     3,     5,     1,     3,     0,     4,     2,     3,     1,
       5,     2,     1,     5,     3,     5,     4,     6,     3,     5,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     5,     3,     6,     5,     6,     5,     6,     5,     5,
       2,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     6,     1,     1,     1,     3,
       1,     4,     2,     5,     3,     6,     0,     0,     5,     2,
       5,     3,     6,     2,     5,     3,     6,     2,     1,     1,
       5,     2,     1,     4,     4,     4,     4,     2,     5,     3,
       6,     3,     1,     1,     1,     1,     3,     1,     1,     1,
       3,     1,     1,     1,     1,     2,     5,     2,     2,     2,
       5,     3,     6,     2,     5,     3,     6,     2,     5,     3,
       6,     2,     5,     3,     6,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     3,     6,     1,     1,     1,     1,
       3,     1,     3,     6,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     2,     5,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     2,     5,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       2,     5,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     2,     5,
       3,     6,     1,     1,     1,     1,     3,     1,     2,     5,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       2,     5,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     2,     5,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       2,     5,     2,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     5,     1,     2,     6,     4,     2,
       5,     3,     6,     1,     3,     1,     1,     1,     1,     1,
       5,     1,     3,     1,     1,     1,     1,     1,     3,     8,
       5,     1,     2,     9,     0,     6,     2,     1,     4,     6,
       2,     5,     3,     6,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     5,     3,     1,
       1,     1,     1,     1,     1,     2,     4,     5,     1,     1,
       5,     1,     2,     6,     9,     9,     5,     8,     1,     2,
       6,     9,     9,     2,     5,     3,     1,     1,     1,     1,
       1,     1,     5,    10,     2,     1,     4,     4,     3,     2,
       1,     3,     3,     3,     3,     1,     1,     1,     3,     3,
       3,     3,     1,     1,     1,     3,     5,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     1,
       1,     3,     5,     3,     5,     1,     1,     1,     1,     1,
       3,     5,     3,     3,     3,     3,     3,     3,     3,     3,
       5,     5,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     3,     3,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     1,     3,     1,     3,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     1,
       1,     3,     3,     3,     3,     3,     1,     3,     1,     1,
       1,     1,     3,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     5,     5,
       5,     3,     3,     5,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     5,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     5,     3,     3,     3,     3,     3,     1,
       1,     3,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     1,     3,     3,     3,
       3,     3,     3,     5,     1,     1,     3,     3,     1,     5,
       3,     3,     3,     1,     3,     1,     1,     1,     1,     1,
       3,     3,     3,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     1,     3,     3,     3,     1,
       3,     1,     1,     1,     3,     3,     3,     3,     1,     3,
       1,     3,     3,     3,     1,     3,     1,     3,     3,     3,
       3,     3,     1,     1,     3,     3,     1,     1,     1,     3,
       5,     3,     3,     5,     1,     3,     3,     1,     3,     3,
       3,     3,     3,     6,     1,     1,     3,     2,     3,     2,
       3,     2,     3,     2,     3,     2,     3,     2,     3,     3,
       1,     3,     1,     2,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
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
  "POWER", "EXP", "LOG", "LN", "LOG10", "SIN", "COS", "TAN", "ASIN",
  "ACOS", "ATAN", "SINH", "COSH", "TANH", "ERF", "ASINH", "ACOSH", "ATANH",
  "SQRT", "NORMCDF", "NORMPDF", "STEADY_STATE", "EXPECTATION",
  "DYNARE_SENSITIVITY", "MORRIS", "STAB", "REDFORM", "PPRIOR",
  "PRIOR_RANGE", "PPOST", "ILPTAU", "MORRIS_NLIV", "MORRIS_NTRA", "NSAM",
  "LOAD_REDFORM", "LOAD_RMSE", "LOAD_STAB", "ALPHA2_STAB",
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

#if YYDEBUG
  const unsigned short int
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
     620,   620,   622,   624,   626,   628,   630,   632,   634,   638,
     640,   644,   645,   648,   650,   654,   658,   660,   664,   665,
     668,   670,   672,   676,   677,   680,   682,   686,   687,   688,
     689,   690,   691,   692,   693,   694,   695,   698,   699,   702,
     702,   704,   704,   708,   709,   710,   711,   714,   716,   718,
     720,   724,   725,   728,   730,   734,   736,   738,   740,   742,
     744,   746,   748,   750,   752,   754,   756,   758,   760,   762,
     764,   766,   768,   770,   772,   774,   776,   778,   780,   782,
     784,   786,   788,   790,   792,   794,   796,   798,   798,   800,
     802,   804,   806,   808,   810,   814,   816,   820,   823,   824,
     827,   828,   831,   832,   834,   836,   838,   842,   846,   846,
     850,   851,   854,   856,   859,   861,   858,   863,   865,   869,
     871,   875,   877,   881,   882,   885,   886,   889,   891,   893,
     895,   899,   903,   907,   908,   911,   912,   913,   914,   915,
     916,   919,   923,   924,   927,   928,   929,   930,   933,   934,
     937,   938,   941,   943,   945,   947,   949,   951,   955,   957,
     959,   961,   963,   965,   967,   971,   973,   977,   979,   981,
     983,   985,   987,   991,   993,   997,   998,  1001,  1002,  1003,
    1004,  1005,  1006,  1007,  1008,  1011,  1013,  1017,  1018,  1021,
    1022,  1025,  1027,  1031,  1032,  1034,  1036,  1038,  1042,  1043,
    1046,  1047,  1050,  1052,  1056,  1057,  1060,  1061,  1062,  1063,
    1064,  1065,  1066,  1067,  1068,  1069,  1070,  1071,  1074,  1078,
    1082,  1083,  1086,  1087,  1090,  1092,  1096,  1097,  1100,  1101,
    1104,  1108,  1109,  1112,  1113,  1114,  1115,  1118,  1120,  1122,
    1124,  1128,  1129,  1132,  1133,  1134,  1135,  1136,  1137,  1138,
    1139,  1140,  1141,  1142,  1143,  1144,  1145,  1146,  1147,  1148,
    1149,  1150,  1151,  1152,  1153,  1154,  1155,  1156,  1157,  1158,
    1159,  1160,  1161,  1162,  1163,  1164,  1165,  1166,  1167,  1168,
    1169,  1170,  1171,  1172,  1173,  1176,  1177,  1178,  1179,  1180,
    1181,  1184,  1186,  1188,  1192,  1193,  1200,  1202,  1204,  1207,
    1208,  1211,  1213,  1215,  1218,  1220,  1222,  1226,  1227,  1230,
    1232,  1234,  1238,  1239,  1241,  1247,  1253,  1261,  1268,  1272,
    1277,  1284,  1288,  1296,  1301,  1307,  1314,  1324,  1326,  1328,
    1332,  1334,  1338,  1345,  1354,  1363,  1366,  1368,  1372,  1380,
    1390,  1400,  1403,  1405,  1409,  1418,  1420,  1422,  1424,  1426,
    1428,  1430,  1432,  1434,  1438,  1440,  1442,  1444,  1446,  1448,
    1450,  1452,  1456,  1458,  1460,  1464,  1468,  1472,  1473,  1476,
    1477,  1478,  1479,  1480,  1481,  1482,  1485,  1489,  1497,  1503,
    1509,  1517,  1518,  1521,  1521,  1523,  1523,  1525,  1525,  1527,
    1527,  1529,  1529,  1531,  1531,  1533,  1533,  1537,  1538,  1541,
    1542,  1543,  1544,  1545,  1546,  1547,  1548,  1549,  1550,  1553,
    1554,  1557,  1558,  1559,  1560,  1561,  1562,  1563,  1564,  1565,
    1566,  1569,  1578,  1586,  1594,  1602,  1610,  1618,  1628,  1630,
    1632,  1634,  1636,  1638,  1642,  1643,  1646,  1647,  1648,  1651,
    1660,  1668,  1676,  1684,  1692,  1700,  1710,  1712,  1714,  1716,
    1720,  1721,  1724,  1725,  1726,  1727,  1728,  1729,  1730,  1731,
    1732,  1733,  1734,  1735,  1736,  1737,  1738,  1739,  1740,  1741,
    1742,  1743,  1744,  1745,  1746,  1747,  1748,  1749,  1750,  1751,
    1752,  1753,  1754,  1755,  1756,  1757,  1758,  1759,  1760,  1761,
    1762,  1763,  1764,  1765,  1766,  1767,  1768,  1769,  1770,  1771,
    1772,  1773,  1774,  1775,  1776,  1777,  1778,  1779,  1780,  1781,
    1782,  1783,  1784,  1785,  1786,  1787,  1788,  1789,  1790,  1791,
    1792,  1793,  1794,  1795,  1796,  1797,  1798,  1799,  1800,  1801,
    1802,  1803,  1804,  1805,  1806,  1807,  1808,  1809,  1810,  1811,
    1812,  1813,  1814,  1815,  1816,  1817,  1818,  1819,  1820,  1821,
    1822,  1823,  1824,  1825,  1826,  1827,  1828,  1829,  1830,  1831,
    1832,  1833,  1836,  1838,  1842,  1843,  1846,  1854,  1863,  1865,
    1873,  1875,  1877,  1885,  1886,  1889,  1889,  1891,  1893,  1895,
    1899,  1901,  1902,  1905,  1907,  1909,  1911,  1913,  1915,  1917,
    1921,  1924,  1925,  1928,  1929,  1930,  1931,  1932,  1933,  1934,
    1937,  1939,  1941,  1943,  1947,  1949,  1953,  1955,  1959,  1963,
    1967,  1969,  1973,  1974,  1977,  1978,  1979,  1980,  1981,  1982,
    1983,  1984,  1985,  1986,  1987,  1988,  1989,  1990,  1991,  1992,
    1993,  1994,  1995,  1996,  1999,  2001,  2005,  2006,  2009,  2011,
    2015,  2017,  2019,  2021,  2023,  2025,  2029,  2030,  2029,  2032,
    2034,  2036,  2038,  2042,  2044,  2046,  2048,  2052,  2053,  2056,
    2059,  2063,  2064,  2067,  2069,  2071,  2073,  2077,  2079,  2081,
    2083,  2087,  2088,  2091,  2092,  2093,  2096,  2097,  2100,  2101,
    2104,  2105,  2108,  2109,  2110,  2113,  2115,  2119,  2123,  2127,
    2129,  2131,  2133,  2137,  2139,  2141,  2143,  2147,  2149,  2151,
    2153,  2157,  2159,  2161,  2163,  2167,  2168,  2169,  2170,  2171,
    2172,  2173,  2176,  2177,  2178,  2179,  2180,  2181,  2182,  2183,
    2184,  2185,  2188,  2189,  2192,  2194,  2198,  2199,  2200,  2201,
    2204,  2205,  2208,  2210,  2214,  2215,  2216,  2217,  2218,  2219,
    2220,  2221,  2222,  2223,  2224,  2225,  2226,  2227,  2228,  2229,
    2230,  2231,  2232,  2233,  2234,  2235,  2236,  2237,  2238,  2239,
    2240,  2241,  2242,  2243,  2244,  2245,  2246,  2247,  2248,  2249,
    2250,  2251,  2252,  2253,  2254,  2255,  2256,  2257,  2258,  2259,
    2260,  2261,  2264,  2265,  2268,  2270,  2274,  2275,  2276,  2277,
    2278,  2279,  2280,  2281,  2282,  2283,  2284,  2285,  2286,  2287,
    2290,  2291,  2294,  2296,  2300,  2301,  2302,  2303,  2304,  2305,
    2306,  2307,  2308,  2309,  2310,  2311,  2312,  2313,  2316,  2317,
    2320,  2322,  2326,  2327,  2328,  2329,  2330,  2331,  2332,  2333,
    2334,  2335,  2336,  2337,  2338,  2339,  2342,  2343,  2346,  2348,
    2350,  2352,  2356,  2357,  2358,  2359,  2362,  2363,  2366,  2368,
    2372,  2373,  2374,  2375,  2376,  2377,  2378,  2379,  2382,  2383,
    2386,  2388,  2392,  2393,  2394,  2395,  2396,  2397,  2398,  2401,
    2402,  2405,  2407,  2411,  2412,  2413,  2414,  2415,  2416,  2417,
    2418,  2419,  2420,  2421,  2422,  2423,  2424,  2425,  2426,  2427,
    2428,  2429,  2430,  2431,  2432,  2433,  2434,  2435,  2436,  2437,
    2438,  2439,  2440,  2441,  2442,  2443,  2444,  2445,  2448,  2449,
    2452,  2454,  2458,  2460,  2464,  2465,  2468,  2469,  2470,  2471,
    2472,  2473,  2474,  2475,  2476,  2477,  2478,  2479,  2480,  2481,
    2482,  2483,  2484,  2485,  2486,  2487,  2488,  2489,  2490,  2491,
    2492,  2493,  2494,  2495,  2496,  2497,  2498,  2499,  2500,  2501,
    2502,  2503,  2504,  2505,  2506,  2507,  2508,  2509,  2510,  2511,
    2512,  2513,  2514,  2515,  2516,  2517,  2518,  2521,  2522,  2525,
    2526,  2527,  2528,  2529,  2530,  2531,  2532,  2535,  2536,  2539,
    2540,  2541,  2542,  2543,  2544,  2545,  2546,  2547,  2548,  2551,
    2552,  2555,  2556,  2557,  2558,  2559,  2560,  2561,  2562,  2563,
    2564,  2565,  2566,  2567,  2568,  2569,  2572,  2573,  2576,  2577,
    2578,  2579,  2580,  2581,  2584,  2587,  2588,  2591,  2593,  2597,
    2598,  2599,  2600,  2603,  2604,  2607,  2608,  2609,  2610,  2611,
    2614,  2618,  2619,  2622,  2623,  2624,  2625,  2626,  2629,  2631,
    2635,  2639,  2640,  2643,  2647,  2647,  2651,  2652,  2655,  2657,
    2661,  2663,  2665,  2667,  2671,  2672,  2675,  2676,  2677,  2678,
    2679,  2680,  2681,  2682,  2683,  2684,  2687,  2689,  2693,  2694,
    2697,  2698,  2699,  2700,  2701,  2704,  2708,  2714,  2720,  2726,
    2734,  2738,  2739,  2742,  2744,  2746,  2750,  2752,  2756,  2757,
    2760,  2762,  2764,  2768,  2770,  2774,  2775,  2778,  2779,  2780,
    2781,  2782,  2785,  2786,  2790,  2791,  2794,  2795,  2798,  2799,
    2800,  2803,  2809,  2810,  2816,  2817,  2818,  2819,  2820,  2821,
    2822,  2823,  2824,  2825,  2826,  2827,  2828,  2829,  2830,  2831,
    2832,  2833,  2834,  2835,  2836,  2837,  2838,  2839,  2845,  2846,
    2847,  2848,  2849,  2850,  2851,  2852,  2854,  2855,  2856,  2857,
    2858,  2859,  2860,  2861,  2862,  2863,  2864,  2865,  2866,  2867,
    2868,  2870,  2873,  2875,  2878,  2880,  2883,  2885,  2886,  2887,
    2888,  2889,  2890,  2891,  2892,  2893,  2894,  2895,  2896,  2897,
    2898,  2899,  2900,  2901,  2902,  2903,  2904,  2905,  2906,  2907,
    2908,  2910,  2913,  2915,  2918,  2919,  2920,  2921,  2922,  2923,
    2924,  2925,  2927,  2930,  2932,  2935,  2937,  2939,  2941,  2944,
    2945,  2948,  2951,  2952,  2953,  2954,  2955,  2956,  2957,  2958,
    2959,  2960,  2961,  2962,  2965,  2966,  2967,  2968,  2969,  2970,
    2971,  2972,  2973,  2974,  2975,  2976,  2977,  2978,  2979,  2980,
    2981,  2982,  2983,  2985,  2987,  2990,  2991,  2992,  2993,  2994,
    2995,  2996,  2997,  2998,  2999,  3000,  3001,  3002,  3004,  3007,
    3008,  3009,  3010,  3011,  3012,  3013,  3014,  3015,  3016,  3017,
    3018,  3019,  3020,  3021,  3022,  3023,  3024,  3025,  3026,  3027,
    3028,  3029,  3030,  3031,  3032,  3033,  3034,  3035,  3036,  3037,
    3038,  3039,  3040,  3041,  3042,  3043,  3044,  3045,  3046,  3047,
    3049,  3051,  3054,  3056,  3058,  3061,  3062,  3063,  3064,  3065,
    3066,  3067,  3068,  3069,  3070,  3071,  3072,  3073,  3074,  3075,
    3076,  3078,  3079,  3080,  3081,  3082,  3083,  3084,  3085,  3086,
    3087,  3088,  3089,  3090,  3091,  3092,  3093,  3094,  3095,  3098,
    3099,  3100,  3101,  3102,  3103,  3104,  3105,  3106,  3107,  3108,
    3109,  3110,  3111,  3112,  3113,  3114,  3115,  3116,  3117,  3118,
    3119,  3120,  3121,  3122,  3123,  3124,  3125,  3126,  3127,  3129,
    3132,  3133,  3134,  3135,  3136,  3137,  3138,  3139,  3141,  3142,
    3143,  3144,  3146,  3147,  3149,  3151,  3153,  3155,  3157,  3159,
    3162,  3163,  3164,  3165,  3166,  3168,  3170,  3173,  3174,  3175,
    3176,  3177,  3178,  3179,  3180,  3181,  3186,  3191,  3197,  3198,
    3199,  3200,  3201,  3202,  3203,  3204,  3205,  3206,  3207,  3208,
    3210,  3213,  3214,  3215,  3216,  3217,  3218,  3219,  3220,  3221,
    3222,  3223,  3224,  3225,  3226,  3227,  3228,  3229,  3230,  3231,
    3232,  3233,  3234,  3235,  3236,  3237,  3238,  3239,  3240,  3243,
    3245,  3248,  3249,  3250,  3251,  3252,  3253,  3255,  3258,  3259,
    3261,  3262,  3263,  3265,  3268,  3270,  3273,  3276,  3279,  3282,
    3285,  3288,  3289,  3290,  3291,  3292,  3294,  3296,  3298,  3300,
    3302,  3304,  3306,  3308,  3310,  3312,  3314,  3316,  3318,  3320,
    3322,  3324,  3325,  3326,  3327,  3328,  3329,  3330,  3331,  3332,
    3333,  3334,  3335,  3336,  3337,  3338,  3339,  3340,  3341,  3342,
    3343,  3344,  3345,  3346,  3347,  3348,  3349,  3350,  3351,  3352,
    3354,  3356,  3359,  3360,  3361,  3362,  3363,  3364,  3365,  3367,
    3368,  3369,  3370,  3371,  3372,  3373,  3374,  3375,  3376,  3378,
    3380,  3388,  3396,  3403,  3413,  3415,  3416,  3426,  3428,  3430,
    3438,  3448,  3450,  3454,  3455,  3456,  3463,  3472,  3473,  3476,
    3483,  3487,  3488,  3490,  3492,  3501,  3503,  3504,  3505,  3506,
    3507,  3508,  3509,  3510,  3511,  3512,  3513,  3514,  3515,  3516,
    3517,  3518,  3519,  3520,  3521,  3522
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
       2,     2,     2,     2,     2,   584,     2,     2,     2,     2,
     580,   581,     2,     2,     2,     2,   586,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   585,   579,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   582,     2,   583,     2,     2,     2,     2,     2,     2,
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
     575,   576,   577,   578
    };
    const unsigned int user_token_number_max_ = 833;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // Dynare
#line 11892 "DynareBison.cc" // lalr1.cc:1167
#line 3524 "lex_yacc/DynareBison.yy" // lalr1.cc:1168


void
Dynare::parser::error(const Dynare::parser::location_type &l,
                      const string &m)
{
  driver.error(l, m);
}
