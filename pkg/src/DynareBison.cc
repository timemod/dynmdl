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
#line 621 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_linlog((yystack_[1].value.node_val)); }
#line 1488 "DynareBison.cc" // lalr1.cc:859
    break;

  case 241:
#line 623 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_linlog((yystack_[3].value.node_val), (yystack_[1].value.node_val)); }
#line 1494 "DynareBison.cc" // lalr1.cc:859
    break;

  case 242:
#line 624 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.push_external_function_arg_vector_onto_stack(); }
#line 1500 "DynareBison.cc" // lalr1.cc:859
    break;

  case 243:
#line 625 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_model_var_or_external_function((yystack_[4].value.string_val), false); }
#line 1506 "DynareBison.cc" // lalr1.cc:859
    break;

  case 244:
#line 627 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_normcdf((yystack_[5].value.node_val), (yystack_[3].value.node_val), (yystack_[1].value.node_val)); }
#line 1512 "DynareBison.cc" // lalr1.cc:859
    break;

  case 245:
#line 629 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_normcdf((yystack_[1].value.node_val)); }
#line 1518 "DynareBison.cc" // lalr1.cc:859
    break;

  case 246:
#line 631 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_normpdf((yystack_[5].value.node_val), (yystack_[3].value.node_val), (yystack_[1].value.node_val)); }
#line 1524 "DynareBison.cc" // lalr1.cc:859
    break;

  case 247:
#line 633 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_normpdf((yystack_[1].value.node_val)); }
#line 1530 "DynareBison.cc" // lalr1.cc:859
    break;

  case 248:
#line 635 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_erf((yystack_[1].value.node_val)); }
#line 1536 "DynareBison.cc" // lalr1.cc:859
    break;

  case 249:
#line 637 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_nan_constant(); }
#line 1542 "DynareBison.cc" // lalr1.cc:859
    break;

  case 250:
#line 639 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_inf_constant(); }
#line 1548 "DynareBison.cc" // lalr1.cc:859
    break;

  case 251:
#line 643 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_external_function_arg((yystack_[0].value.node_val)); }
#line 1554 "DynareBison.cc" // lalr1.cc:859
    break;

  case 252:
#line 645 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_external_function_arg((yystack_[0].value.node_val)); }
#line 1560 "DynareBison.cc" // lalr1.cc:859
    break;

  case 253:
#line 648 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {(yylhs.value.node_val) = driver.add_nan_constant();}
#line 1566 "DynareBison.cc" // lalr1.cc:859
    break;

  case 255:
#line 653 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.end_initval(false); }
#line 1572 "DynareBison.cc" // lalr1.cc:859
    break;

  case 256:
#line 655 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.end_initval(true); }
#line 1578 "DynareBison.cc" // lalr1.cc:859
    break;

  case 257:
#line 659 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.initval_file((yystack_[2].value.string_val)); }
#line 1584 "DynareBison.cc" // lalr1.cc:859
    break;

  case 258:
#line 663 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.end_endval(false); }
#line 1590 "DynareBison.cc" // lalr1.cc:859
    break;

  case 259:
#line 665 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.end_endval(true); }
#line 1596 "DynareBison.cc" // lalr1.cc:859
    break;

  case 262:
#line 672 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.init_val((yystack_[3].value.string_val), (yystack_[1].value.node_val)); }
#line 1602 "DynareBison.cc" // lalr1.cc:859
    break;

  case 263:
#line 675 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.end_histval(false); }
#line 1608 "DynareBison.cc" // lalr1.cc:859
    break;

  case 264:
#line 677 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.end_histval(true); }
#line 1614 "DynareBison.cc" // lalr1.cc:859
    break;

  case 267:
#line 684 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.hist_val((yystack_[6].value.string_val), (yystack_[4].value.string_val), (yystack_[1].value.node_val)); }
#line 1620 "DynareBison.cc" // lalr1.cc:859
    break;

  case 268:
#line 687 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.histval_file((yystack_[2].value.string_val)); }
#line 1626 "DynareBison.cc" // lalr1.cc:859
    break;

  case 269:
#line 690 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.block(); }
#line 1632 "DynareBison.cc" // lalr1.cc:859
    break;

  case 272:
#line 693 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.byte_code(); }
#line 1638 "DynareBison.cc" // lalr1.cc:859
    break;

  case 273:
#line 694 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.use_dll(); }
#line 1644 "DynareBison.cc" // lalr1.cc:859
    break;

  case 274:
#line 695 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.no_static();}
#line 1650 "DynareBison.cc" // lalr1.cc:859
    break;

  case 275:
#line 696 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.differentiate_forward_vars_all(); }
#line 1656 "DynareBison.cc" // lalr1.cc:859
    break;

  case 276:
#line 697 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.differentiate_forward_vars_some(); }
#line 1662 "DynareBison.cc" // lalr1.cc:859
    break;

  case 281:
#line 706 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.begin_model(); }
#line 1668 "DynareBison.cc" // lalr1.cc:859
    break;

  case 282:
#line 707 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.end_model(); }
#line 1674 "DynareBison.cc" // lalr1.cc:859
    break;

  case 283:
#line 708 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.begin_model(); }
#line 1680 "DynareBison.cc" // lalr1.cc:859
    break;

  case 284:
#line 709 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.end_model(); }
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

  case 291:
#line 723 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_model_equal((yystack_[3].value.node_val), (yystack_[1].value.node_val)); }
#line 1704 "DynareBison.cc" // lalr1.cc:859
    break;

  case 292:
#line 725 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_model_equal_with_zero_rhs((yystack_[1].value.node_val)); }
#line 1710 "DynareBison.cc" // lalr1.cc:859
    break;

  case 295:
#line 733 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_equation_tags((yystack_[2].value.string_val), (yystack_[0].value.string_val)); }
#line 1716 "DynareBison.cc" // lalr1.cc:859
    break;

  case 296:
#line 735 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_equation_tags((yystack_[0].value.string_val), new string()); }
#line 1722 "DynareBison.cc" // lalr1.cc:859
    break;

  case 297:
#line 739 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = (yystack_[1].value.node_val);}
#line 1728 "DynareBison.cc" // lalr1.cc:859
    break;

  case 298:
#line 741 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_model_variable((yystack_[0].value.string_val)); }
#line 1734 "DynareBison.cc" // lalr1.cc:859
    break;

  case 299:
#line 743 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_non_negative_constant((yystack_[0].value.string_val)); }
#line 1740 "DynareBison.cc" // lalr1.cc:859
    break;

  case 300:
#line 745 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_plus((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1746 "DynareBison.cc" // lalr1.cc:859
    break;

  case 301:
#line 747 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_minus((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1752 "DynareBison.cc" // lalr1.cc:859
    break;

  case 302:
#line 749 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_divide((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1758 "DynareBison.cc" // lalr1.cc:859
    break;

  case 303:
#line 751 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_times((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1764 "DynareBison.cc" // lalr1.cc:859
    break;

  case 304:
#line 753 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_less((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1770 "DynareBison.cc" // lalr1.cc:859
    break;

  case 305:
#line 755 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_greater((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1776 "DynareBison.cc" // lalr1.cc:859
    break;

  case 306:
#line 757 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_less_equal((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1782 "DynareBison.cc" // lalr1.cc:859
    break;

  case 307:
#line 759 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_greater_equal((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1788 "DynareBison.cc" // lalr1.cc:859
    break;

  case 308:
#line 761 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_equal_equal((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1794 "DynareBison.cc" // lalr1.cc:859
    break;

  case 309:
#line 763 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_different((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1800 "DynareBison.cc" // lalr1.cc:859
    break;

  case 310:
#line 765 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_power((yystack_[2].value.node_val), (yystack_[0].value.node_val)); }
#line 1806 "DynareBison.cc" // lalr1.cc:859
    break;

  case 311:
#line 767 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_expectation((yystack_[4].value.string_val), (yystack_[1].value.node_val)); }
#line 1812 "DynareBison.cc" // lalr1.cc:859
    break;

  case 312:
#line 769 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_uminus((yystack_[0].value.node_val)); }
#line 1818 "DynareBison.cc" // lalr1.cc:859
    break;

  case 313:
#line 771 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = (yystack_[0].value.node_val); }
#line 1824 "DynareBison.cc" // lalr1.cc:859
    break;

  case 314:
#line 773 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_exp((yystack_[1].value.node_val)); }
#line 1830 "DynareBison.cc" // lalr1.cc:859
    break;

  case 315:
#line 775 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_log((yystack_[1].value.node_val)); }
#line 1836 "DynareBison.cc" // lalr1.cc:859
    break;

  case 316:
#line 777 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_log((yystack_[1].value.node_val)); }
#line 1842 "DynareBison.cc" // lalr1.cc:859
    break;

  case 317:
#line 779 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_log10((yystack_[1].value.node_val)); }
#line 1848 "DynareBison.cc" // lalr1.cc:859
    break;

  case 318:
#line 781 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_sin((yystack_[1].value.node_val)); }
#line 1854 "DynareBison.cc" // lalr1.cc:859
    break;

  case 319:
#line 783 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_cos((yystack_[1].value.node_val)); }
#line 1860 "DynareBison.cc" // lalr1.cc:859
    break;

  case 320:
#line 785 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_tan((yystack_[1].value.node_val)); }
#line 1866 "DynareBison.cc" // lalr1.cc:859
    break;

  case 321:
#line 787 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_asin((yystack_[1].value.node_val)); }
#line 1872 "DynareBison.cc" // lalr1.cc:859
    break;

  case 322:
#line 789 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_acos((yystack_[1].value.node_val)); }
#line 1878 "DynareBison.cc" // lalr1.cc:859
    break;

  case 323:
#line 791 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_atan((yystack_[1].value.node_val)); }
#line 1884 "DynareBison.cc" // lalr1.cc:859
    break;

  case 324:
#line 793 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_sqrt((yystack_[1].value.node_val)); }
#line 1890 "DynareBison.cc" // lalr1.cc:859
    break;

  case 325:
#line 795 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_abs((yystack_[1].value.node_val)); }
#line 1896 "DynareBison.cc" // lalr1.cc:859
    break;

  case 326:
#line 797 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_sign((yystack_[1].value.node_val)); }
#line 1902 "DynareBison.cc" // lalr1.cc:859
    break;

  case 327:
#line 799 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_max((yystack_[3].value.node_val), (yystack_[1].value.node_val)); }
#line 1908 "DynareBison.cc" // lalr1.cc:859
    break;

  case 328:
#line 801 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_min((yystack_[3].value.node_val), (yystack_[1].value.node_val)); }
#line 1914 "DynareBison.cc" // lalr1.cc:859
    break;

  case 329:
#line 803 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_linlog((yystack_[1].value.node_val)); }
#line 1920 "DynareBison.cc" // lalr1.cc:859
    break;

  case 330:
#line 805 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_linlog((yystack_[3].value.node_val), (yystack_[1].value.node_val)); }
#line 1926 "DynareBison.cc" // lalr1.cc:859
    break;

  case 331:
#line 806 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.push_external_function_arg_vector_onto_stack(); }
#line 1932 "DynareBison.cc" // lalr1.cc:859
    break;

  case 332:
#line 807 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_model_var_or_external_function((yystack_[4].value.string_val), true); }
#line 1938 "DynareBison.cc" // lalr1.cc:859
    break;

  case 333:
#line 809 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_normcdf((yystack_[5].value.node_val), (yystack_[3].value.node_val), (yystack_[1].value.node_val)); }
#line 1944 "DynareBison.cc" // lalr1.cc:859
    break;

  case 334:
#line 811 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_normcdf((yystack_[1].value.node_val)); }
#line 1950 "DynareBison.cc" // lalr1.cc:859
    break;

  case 335:
#line 813 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_normpdf((yystack_[5].value.node_val), (yystack_[3].value.node_val), (yystack_[1].value.node_val)); }
#line 1956 "DynareBison.cc" // lalr1.cc:859
    break;

  case 336:
#line 815 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_normpdf((yystack_[1].value.node_val)); }
#line 1962 "DynareBison.cc" // lalr1.cc:859
    break;

  case 337:
#line 817 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_erf((yystack_[1].value.node_val)); }
#line 1968 "DynareBison.cc" // lalr1.cc:859
    break;

  case 338:
#line 819 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.node_val) = driver.add_steady_state((yystack_[1].value.node_val)); }
#line 1974 "DynareBison.cc" // lalr1.cc:859
    break;

  case 339:
#line 823 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_external_function_arg((yystack_[0].value.node_val)); }
#line 1980 "DynareBison.cc" // lalr1.cc:859
    break;

  case 340:
#line 825 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_external_function_arg((yystack_[0].value.node_val)); }
#line 1986 "DynareBison.cc" // lalr1.cc:859
    break;

  case 341:
#line 829 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_and_init_model_local_variable((yystack_[3].value.string_val), (yystack_[1].value.node_val)); }
#line 1992 "DynareBison.cc" // lalr1.cc:859
    break;

  case 342:
#line 831 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.end_shocks(false); }
#line 1998 "DynareBison.cc" // lalr1.cc:859
    break;

  case 343:
#line 832 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.end_shocks(true); }
#line 2004 "DynareBison.cc" // lalr1.cc:859
    break;

  case 347:
#line 841 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_stderr_shock((yystack_[4].value.string_val), (yystack_[1].value.node_val)); }
#line 2010 "DynareBison.cc" // lalr1.cc:859
    break;

  case 348:
#line 843 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_var_shock((yystack_[3].value.string_val), (yystack_[1].value.node_val)); }
#line 2016 "DynareBison.cc" // lalr1.cc:859
    break;

  case 349:
#line 845 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_covar_shock((yystack_[5].value.string_val), (yystack_[3].value.string_val), (yystack_[1].value.node_val)); }
#line 2022 "DynareBison.cc" // lalr1.cc:859
    break;

  case 350:
#line 847 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_correl_shock((yystack_[5].value.string_val), (yystack_[3].value.string_val), (yystack_[1].value.node_val)); }
#line 2028 "DynareBison.cc" // lalr1.cc:859
    break;

  case 351:
#line 851 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_det_shock((yystack_[7].value.string_val), false); }
#line 2034 "DynareBison.cc" // lalr1.cc:859
    break;

  case 352:
#line 854 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.begin_svar_identification();}
#line 2040 "DynareBison.cc" // lalr1.cc:859
    break;

  case 353:
#line 855 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.end_svar_identification(); }
#line 2046 "DynareBison.cc" // lalr1.cc:859
    break;

  case 356:
#line 863 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.combine_lag_and_restriction((yystack_[2].value.string_val)); }
#line 2052 "DynareBison.cc" // lalr1.cc:859
    break;

  case 357:
#line 865 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_constants_exclusion(); }
#line 2058 "DynareBison.cc" // lalr1.cc:859
    break;

  case 358:
#line 867 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_restriction_equation_nbr((yystack_[1].value.string_val));}
#line 2064 "DynareBison.cc" // lalr1.cc:859
    break;

  case 359:
#line 869 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.add_restriction_equal();}
#line 2070 "DynareBison.cc" // lalr1.cc:859
    break;

  case 361:
#line 872 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_upper_cholesky(); }
#line 2076 "DynareBison.cc" // lalr1.cc:859
    break;

  case 362:
#line 874 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_lower_cholesky(); }
#line 2082 "DynareBison.cc" // lalr1.cc:859
    break;

  case 363:
#line 878 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_restriction_in_equation((yystack_[3].value.string_val)); }
#line 2088 "DynareBison.cc" // lalr1.cc:859
    break;

  case 364:
#line 880 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_restriction_in_equation((yystack_[3].value.string_val)); }
#line 2094 "DynareBison.cc" // lalr1.cc:859
    break;

  case 365:
#line 884 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_in_svar_restriction_symbols((yystack_[0].value.string_val)); }
#line 2100 "DynareBison.cc" // lalr1.cc:859
    break;

  case 366:
#line 886 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_in_svar_restriction_symbols((yystack_[0].value.string_val)); }
#line 2106 "DynareBison.cc" // lalr1.cc:859
    break;

  case 367:
#line 889 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.check_restriction_expression_constant((yystack_[0].value.node_val));}
#line 2112 "DynareBison.cc" // lalr1.cc:859
    break;

  case 371:
#line 898 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_positive_restriction_element((yystack_[3].value.string_val),(yystack_[1].value.string_val));}
#line 2118 "DynareBison.cc" // lalr1.cc:859
    break;

  case 372:
#line 900 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_positive_restriction_element((yystack_[3].value.string_val),(yystack_[1].value.string_val));}
#line 2124 "DynareBison.cc" // lalr1.cc:859
    break;

  case 373:
#line 902 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_negative_restriction_element((yystack_[3].value.string_val),(yystack_[1].value.string_val));}
#line 2130 "DynareBison.cc" // lalr1.cc:859
    break;

  case 374:
#line 904 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_positive_restriction_element((yystack_[7].value.node_val),(yystack_[3].value.string_val),(yystack_[1].value.string_val));}
#line 2136 "DynareBison.cc" // lalr1.cc:859
    break;

  case 375:
#line 908 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_svar_global_identification_check(); }
#line 2142 "DynareBison.cc" // lalr1.cc:859
    break;

  case 376:
#line 912 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.markov_switching(); }
#line 2148 "DynareBison.cc" // lalr1.cc:859
    break;

  case 385:
#line 928 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.svar(); }
#line 2154 "DynareBison.cc" // lalr1.cc:859
    break;

  case 392:
#line 941 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.end_mshocks(false); }
#line 2160 "DynareBison.cc" // lalr1.cc:859
    break;

  case 393:
#line 942 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.end_mshocks(true); }
#line 2166 "DynareBison.cc" // lalr1.cc:859
    break;

  case 396:
#line 950 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_period((yystack_[0].value.string_val)); }
#line 2172 "DynareBison.cc" // lalr1.cc:859
    break;

  case 397:
#line 952 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_period((yystack_[0].value.string_val)); }
#line 2178 "DynareBison.cc" // lalr1.cc:859
    break;

  case 398:
#line 954 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_period((yystack_[2].value.string_val), (yystack_[0].value.string_val)); }
#line 2184 "DynareBison.cc" // lalr1.cc:859
    break;

  case 399:
#line 956 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_period((yystack_[2].value.string_val), (yystack_[0].value.string_val)); }
#line 2190 "DynareBison.cc" // lalr1.cc:859
    break;

  case 400:
#line 958 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_period((yystack_[2].value.string_val), (yystack_[0].value.string_val)); }
#line 2196 "DynareBison.cc" // lalr1.cc:859
    break;

  case 401:
#line 960 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_period((yystack_[0].value.string_val)); }
#line 2202 "DynareBison.cc" // lalr1.cc:859
    break;

  case 402:
#line 963 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.do_sigma_e(); }
#line 2208 "DynareBison.cc" // lalr1.cc:859
    break;

  case 403:
#line 966 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_value((yystack_[1].value.node_val)); }
#line 2214 "DynareBison.cc" // lalr1.cc:859
    break;

  case 404:
#line 968 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_value((yystack_[1].value.node_val)); }
#line 2220 "DynareBison.cc" // lalr1.cc:859
    break;

  case 405:
#line 970 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_value((yystack_[1].value.node_val)); }
#line 2226 "DynareBison.cc" // lalr1.cc:859
    break;

  case 406:
#line 972 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_value((yystack_[0].value.string_val)); }
#line 2232 "DynareBison.cc" // lalr1.cc:859
    break;

  case 407:
#line 974 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_value((yystack_[0].value.string_val)); }
#line 2238 "DynareBison.cc" // lalr1.cc:859
    break;

  case 408:
#line 976 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_value((yystack_[0].value.string_val)); }
#line 2244 "DynareBison.cc" // lalr1.cc:859
    break;

  case 409:
#line 980 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.end_of_row(); }
#line 2250 "DynareBison.cc" // lalr1.cc:859
    break;

  case 410:
#line 982 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.end_of_row(); }
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
#line 990 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_to_row((yystack_[1].value.node_val)); }
#line 2274 "DynareBison.cc" // lalr1.cc:859
    break;

  case 414:
#line 992 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_to_row_const((yystack_[0].value.string_val)); }
#line 2280 "DynareBison.cc" // lalr1.cc:859
    break;

  case 415:
#line 994 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_to_row((yystack_[1].value.node_val)); }
#line 2286 "DynareBison.cc" // lalr1.cc:859
    break;

  case 416:
#line 996 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_to_row_const((yystack_[0].value.string_val)); }
#line 2292 "DynareBison.cc" // lalr1.cc:859
    break;

  case 417:
#line 1000 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.steady(); }
#line 2298 "DynareBison.cc" // lalr1.cc:859
    break;

  case 418:
#line 1002 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.steady(); }
#line 2304 "DynareBison.cc" // lalr1.cc:859
    break;

  case 429:
#line 1020 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.check(); }
#line 2310 "DynareBison.cc" // lalr1.cc:859
    break;

  case 430:
#line 1022 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.check(); }
#line 2316 "DynareBison.cc" // lalr1.cc:859
    break;

  case 435:
#line 1034 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.model_info(); }
#line 2322 "DynareBison.cc" // lalr1.cc:859
    break;

  case 436:
#line 1036 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.model_info(); }
#line 2328 "DynareBison.cc" // lalr1.cc:859
    break;

  case 440:
#line 1045 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.perfect_foresight_setup(); }
#line 2334 "DynareBison.cc" // lalr1.cc:859
    break;

  case 441:
#line 1047 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.perfect_foresight_setup(); }
#line 2340 "DynareBison.cc" // lalr1.cc:859
    break;

  case 446:
#line 1059 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.perfect_foresight_solver(); }
#line 2346 "DynareBison.cc" // lalr1.cc:859
    break;

  case 447:
#line 1061 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.perfect_foresight_solver(); }
#line 2352 "DynareBison.cc" // lalr1.cc:859
    break;

  case 462:
#line 1083 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.prior_posterior_function(true); }
#line 2358 "DynareBison.cc" // lalr1.cc:859
    break;

  case 463:
#line 1087 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.prior_posterior_function(false); }
#line 2364 "DynareBison.cc" // lalr1.cc:859
    break;

  case 468:
#line 1099 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.simul(); }
#line 2370 "DynareBison.cc" // lalr1.cc:859
    break;

  case 469:
#line 1101 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.simul(); }
#line 2376 "DynareBison.cc" // lalr1.cc:859
    break;

  case 474:
#line 1113 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.external_function(); }
#line 2382 "DynareBison.cc" // lalr1.cc:859
    break;

  case 481:
#line 1127 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.stoch_simul(); }
#line 2388 "DynareBison.cc" // lalr1.cc:859
    break;

  case 482:
#line 1129 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.stoch_simul(); }
#line 2394 "DynareBison.cc" // lalr1.cc:859
    break;

  case 483:
#line 1131 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.stoch_simul(); }
#line 2400 "DynareBison.cc" // lalr1.cc:859
    break;

  case 484:
#line 1133 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.stoch_simul(); }
#line 2406 "DynareBison.cc" // lalr1.cc:859
    break;

  case 535:
#line 1193 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_in_symbol_list((yystack_[0].value.string_val)); }
#line 2412 "DynareBison.cc" // lalr1.cc:859
    break;

  case 536:
#line 1195 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_in_symbol_list((yystack_[0].value.string_val)); }
#line 2418 "DynareBison.cc" // lalr1.cc:859
    break;

  case 537:
#line 1197 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_in_symbol_list((yystack_[0].value.string_val)); }
#line 2424 "DynareBison.cc" // lalr1.cc:859
    break;

  case 539:
#line 1202 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                    string *colon = new string(":");
                    driver.add_in_symbol_list(colon);
                  }
#line 2433 "DynareBison.cc" // lalr1.cc:859
    break;

  case 540:
#line 1209 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 2439 "DynareBison.cc" // lalr1.cc:859
    break;

  case 541:
#line 1211 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yystack_[0].value.string_val)->insert(0, "-"); (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 2445 "DynareBison.cc" // lalr1.cc:859
    break;

  case 545:
#line 1220 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 2451 "DynareBison.cc" // lalr1.cc:859
    break;

  case 546:
#line 1222 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yystack_[0].value.string_val)->insert(0, "-"); (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 2457 "DynareBison.cc" // lalr1.cc:859
    break;

  case 548:
#line 1227 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.string_val) = new string ("Inf"); }
#line 2463 "DynareBison.cc" // lalr1.cc:859
    break;

  case 549:
#line 1229 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.string_val) = new string ("-Inf"); }
#line 2469 "DynareBison.cc" // lalr1.cc:859
    break;

  case 550:
#line 1231 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.string_val) = new string ("Inf"); }
#line 2475 "DynareBison.cc" // lalr1.cc:859
    break;

  case 553:
#line 1238 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.estimated_params(); }
#line 2481 "DynareBison.cc" // lalr1.cc:859
    break;

  case 554:
#line 1241 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_estimated_params_element(); }
#line 2487 "DynareBison.cc" // lalr1.cc:859
    break;

  case 555:
#line 1243 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_estimated_params_element(); }
#line 2493 "DynareBison.cc" // lalr1.cc:859
    break;

  case 558:
#line 1250 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                    driver.estim_params.type = 1;
                    driver.estim_params.name = *(yystack_[0].value.string_val);
                    delete (yystack_[0].value.string_val);
                  }
#line 2503 "DynareBison.cc" // lalr1.cc:859
    break;

  case 559:
#line 1256 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                    driver.estim_params.type = 2;
                    driver.estim_params.name = *(yystack_[0].value.string_val);
                    delete (yystack_[0].value.string_val);
                  }
#line 2513 "DynareBison.cc" // lalr1.cc:859
    break;

  case 560:
#line 1262 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                    driver.estim_params.type = 3;
                    driver.estim_params.name = *(yystack_[2].value.string_val);
                    driver.estim_params.name2 = *(yystack_[0].value.string_val);
                    delete (yystack_[2].value.string_val);
                    delete (yystack_[0].value.string_val);
                  }
#line 2525 "DynareBison.cc" // lalr1.cc:859
    break;

  case 561:
#line 1270 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                    driver.estim_params.type = 2;
                    driver.estim_params.name = "dsge_prior_weight";
                  }
#line 2534 "DynareBison.cc" // lalr1.cc:859
    break;

  case 562:
#line 1277 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                    driver.estim_params.prior = (yystack_[2].value.prior_distributions_val);
                  }
#line 2542 "DynareBison.cc" // lalr1.cc:859
    break;

  case 563:
#line 1281 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                    driver.estim_params.init_val = (yystack_[4].value.node_val);
                    driver.estim_params.prior = (yystack_[2].value.prior_distributions_val);
                  }
#line 2551 "DynareBison.cc" // lalr1.cc:859
    break;

  case 564:
#line 1286 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                    driver.estim_params.init_val = (yystack_[8].value.node_val);
                    driver.estim_params.low_bound = (yystack_[6].value.node_val);
                    driver.estim_params.up_bound = (yystack_[4].value.node_val);
                    driver.estim_params.prior = (yystack_[2].value.prior_distributions_val);
                  }
#line 2562 "DynareBison.cc" // lalr1.cc:859
    break;

  case 565:
#line 1293 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                    driver.estim_params.init_val = (yystack_[0].value.node_val);
                  }
#line 2570 "DynareBison.cc" // lalr1.cc:859
    break;

  case 566:
#line 1297 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                    driver.estim_params.init_val = (yystack_[4].value.node_val);
                    driver.estim_params.low_bound = (yystack_[2].value.node_val);
                    driver.estim_params.up_bound = (yystack_[0].value.node_val);
                  }
#line 2580 "DynareBison.cc" // lalr1.cc:859
    break;

  case 567:
#line 1305 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                    driver.estim_params.mean = (yystack_[2].value.node_val);
                    driver.estim_params.std = (yystack_[0].value.node_val);
                  }
#line 2589 "DynareBison.cc" // lalr1.cc:859
    break;

  case 568:
#line 1310 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                    driver.estim_params.mean = (yystack_[4].value.node_val);
                    driver.estim_params.std = (yystack_[2].value.node_val);
                    driver.estim_params.p3 = (yystack_[0].value.node_val);
                  }
#line 2599 "DynareBison.cc" // lalr1.cc:859
    break;

  case 569:
#line 1316 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                    driver.estim_params.mean = (yystack_[6].value.node_val);
                    driver.estim_params.std = (yystack_[4].value.node_val);
                    driver.estim_params.p3 = (yystack_[2].value.node_val);
                    driver.estim_params.p4 = (yystack_[0].value.node_val);
                  }
#line 2610 "DynareBison.cc" // lalr1.cc:859
    break;

  case 570:
#line 1323 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                    driver.estim_params.mean = (yystack_[8].value.node_val);
                    driver.estim_params.std = (yystack_[6].value.node_val);
                    driver.estim_params.p3 = (yystack_[4].value.node_val);
                    driver.estim_params.p4 = (yystack_[2].value.node_val);
                    driver.estim_params.jscale = (yystack_[0].value.node_val);
                  }
#line 2622 "DynareBison.cc" // lalr1.cc:859
    break;

  case 571:
#line 1333 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.estimated_params_init(); }
#line 2628 "DynareBison.cc" // lalr1.cc:859
    break;

  case 572:
#line 1335 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.estimated_params_init(true); }
#line 2634 "DynareBison.cc" // lalr1.cc:859
    break;

  case 573:
#line 1337 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.estimated_params_init(true); }
#line 2640 "DynareBison.cc" // lalr1.cc:859
    break;

  case 574:
#line 1341 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_estimated_params_element(); }
#line 2646 "DynareBison.cc" // lalr1.cc:859
    break;

  case 575:
#line 1343 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_estimated_params_element(); }
#line 2652 "DynareBison.cc" // lalr1.cc:859
    break;

  case 576:
#line 1347 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                        driver.estim_params.type = 1;
                        driver.estim_params.name = *(yystack_[3].value.string_val);
                        driver.estim_params.init_val = (yystack_[1].value.node_val);
                        delete (yystack_[3].value.string_val);
                      }
#line 2663 "DynareBison.cc" // lalr1.cc:859
    break;

  case 577:
#line 1354 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                        driver.estim_params.type = 3;
                        driver.estim_params.name = *(yystack_[5].value.string_val);
                        driver.estim_params.name2 = *(yystack_[3].value.string_val);
                        driver.estim_params.init_val = (yystack_[1].value.node_val);
                        delete (yystack_[5].value.string_val);
                        delete (yystack_[3].value.string_val);
                      }
#line 2676 "DynareBison.cc" // lalr1.cc:859
    break;

  case 578:
#line 1363 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                        driver.estim_params.type = 2;
                        driver.estim_params.name = *(yystack_[3].value.string_val);
                        driver.estim_params.init_val = (yystack_[1].value.node_val);
                        delete (yystack_[3].value.string_val);
                      }
#line 2687 "DynareBison.cc" // lalr1.cc:859
    break;

  case 579:
#line 1372 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.estimated_params_bounds(); }
#line 2693 "DynareBison.cc" // lalr1.cc:859
    break;

  case 580:
#line 1375 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_estimated_params_element(); }
#line 2699 "DynareBison.cc" // lalr1.cc:859
    break;

  case 581:
#line 1377 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_estimated_params_element(); }
#line 2705 "DynareBison.cc" // lalr1.cc:859
    break;

  case 582:
#line 1381 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                          driver.estim_params.type = 1;
                          driver.estim_params.name = *(yystack_[5].value.string_val);
                          driver.estim_params.low_bound = (yystack_[3].value.node_val);
                          driver.estim_params.up_bound = (yystack_[1].value.node_val);
                          delete (yystack_[5].value.string_val);
                        }
#line 2717 "DynareBison.cc" // lalr1.cc:859
    break;

  case 583:
#line 1389 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                          driver.estim_params.type = 3;
                          driver.estim_params.name = *(yystack_[7].value.string_val);
                          driver.estim_params.name2 = *(yystack_[5].value.string_val);
                          driver.estim_params.low_bound = (yystack_[3].value.node_val);
                          driver.estim_params.up_bound = (yystack_[1].value.node_val);
                          delete (yystack_[7].value.string_val);
                          delete (yystack_[5].value.string_val);
                        }
#line 2731 "DynareBison.cc" // lalr1.cc:859
    break;

  case 584:
#line 1399 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                          driver.estim_params.type = 2;
                          driver.estim_params.name = *(yystack_[5].value.string_val);
                          driver.estim_params.low_bound = (yystack_[3].value.node_val);
                          driver.estim_params.up_bound = (yystack_[1].value.node_val);
                          delete (yystack_[5].value.string_val);
                        }
#line 2743 "DynareBison.cc" // lalr1.cc:859
    break;

  case 585:
#line 1409 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.osr_params_bounds(); }
#line 2749 "DynareBison.cc" // lalr1.cc:859
    break;

  case 586:
#line 1412 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_osr_params_element(); }
#line 2755 "DynareBison.cc" // lalr1.cc:859
    break;

  case 587:
#line 1414 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_osr_params_element(); }
#line 2761 "DynareBison.cc" // lalr1.cc:859
    break;

  case 588:
#line 1418 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                    driver.osr_params.name = *(yystack_[5].value.string_val);
                    driver.osr_params.low_bound = (yystack_[3].value.node_val);
                    driver.osr_params.up_bound = (yystack_[1].value.node_val);
                    delete (yystack_[5].value.string_val);
                  }
#line 2772 "DynareBison.cc" // lalr1.cc:859
    break;

  case 589:
#line 1427 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.prior_distributions_val) = eBeta; }
#line 2778 "DynareBison.cc" // lalr1.cc:859
    break;

  case 590:
#line 1429 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.prior_distributions_val) = eGamma; }
#line 2784 "DynareBison.cc" // lalr1.cc:859
    break;

  case 591:
#line 1431 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.prior_distributions_val) = eNormal; }
#line 2790 "DynareBison.cc" // lalr1.cc:859
    break;

  case 592:
#line 1433 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.prior_distributions_val) = eInvGamma; }
#line 2796 "DynareBison.cc" // lalr1.cc:859
    break;

  case 593:
#line 1435 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.prior_distributions_val) = eInvGamma1; }
#line 2802 "DynareBison.cc" // lalr1.cc:859
    break;

  case 594:
#line 1437 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.prior_distributions_val) = eUniform; }
#line 2808 "DynareBison.cc" // lalr1.cc:859
    break;

  case 595:
#line 1439 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.prior_distributions_val) = eInvGamma2; }
#line 2814 "DynareBison.cc" // lalr1.cc:859
    break;

  case 596:
#line 1441 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.prior_distributions_val) = eDirichlet; }
#line 2820 "DynareBison.cc" // lalr1.cc:859
    break;

  case 597:
#line 1443 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.prior_distributions_val) = eWeibull; }
#line 2826 "DynareBison.cc" // lalr1.cc:859
    break;

  case 598:
#line 1447 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.prior_distributions_val) = eBeta; }
#line 2832 "DynareBison.cc" // lalr1.cc:859
    break;

  case 599:
#line 1449 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.prior_distributions_val) = eGamma; }
#line 2838 "DynareBison.cc" // lalr1.cc:859
    break;

  case 600:
#line 1451 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.prior_distributions_val) = eNormal; }
#line 2844 "DynareBison.cc" // lalr1.cc:859
    break;

  case 601:
#line 1453 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.prior_distributions_val) = eInvGamma; }
#line 2850 "DynareBison.cc" // lalr1.cc:859
    break;

  case 602:
#line 1455 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.prior_distributions_val) = eInvGamma1; }
#line 2856 "DynareBison.cc" // lalr1.cc:859
    break;

  case 603:
#line 1457 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.prior_distributions_val) = eUniform; }
#line 2862 "DynareBison.cc" // lalr1.cc:859
    break;

  case 604:
#line 1459 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.prior_distributions_val) = eInvGamma2; }
#line 2868 "DynareBison.cc" // lalr1.cc:859
    break;

  case 605:
#line 1461 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.prior_distributions_val) = eWeibull; }
#line 2874 "DynareBison.cc" // lalr1.cc:859
    break;

  case 606:
#line 1464 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 2880 "DynareBison.cc" // lalr1.cc:859
    break;

  case 607:
#line 1467 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 2886 "DynareBison.cc" // lalr1.cc:859
    break;

  case 608:
#line 1469 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.string_val) = (yystack_[2].value.string_val); (yylhs.value.string_val)->append("+").append(*(yystack_[0].value.string_val)); }
#line 2892 "DynareBison.cc" // lalr1.cc:859
    break;

  case 609:
#line 1473 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_time((yystack_[2].value.string_val)); }
#line 2898 "DynareBison.cc" // lalr1.cc:859
    break;

  case 610:
#line 1477 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.estimation_data(); }
#line 2904 "DynareBison.cc" // lalr1.cc:859
    break;

  case 620:
#line 1494 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_subsamples((yystack_[4].value.vector_string_val)->at(0), (yystack_[4].value.vector_string_val)->at(1)); }
#line 2910 "DynareBison.cc" // lalr1.cc:859
    break;

  case 621:
#line 1498 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                  driver.copy_subsamples((yystack_[3].value.vector_string_val)->at(0), (yystack_[3].value.vector_string_val)->at(1), (yystack_[1].value.vector_string_val)->at(0), (yystack_[1].value.vector_string_val)->at(1));
                  delete (yystack_[3].value.vector_string_val);
                  delete (yystack_[1].value.vector_string_val);
                }
#line 2920 "DynareBison.cc" // lalr1.cc:859
    break;

  case 622:
#line 1506 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                      (yylhs.value.vector_string_val) = new vector<string *>();
                      (yylhs.value.vector_string_val)->push_back((yystack_[2].value.string_val));
                      (yylhs.value.vector_string_val)->push_back(new string (""));
                    }
#line 2930 "DynareBison.cc" // lalr1.cc:859
    break;

  case 623:
#line 1512 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                      (yylhs.value.vector_string_val) = new vector<string *>();
                      (yylhs.value.vector_string_val)->push_back((yystack_[3].value.string_val));
                      (yylhs.value.vector_string_val)->push_back(new string (""));
                    }
#line 2940 "DynareBison.cc" // lalr1.cc:859
    break;

  case 624:
#line 1518 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                      (yylhs.value.vector_string_val) = new vector<string *>();
                      (yylhs.value.vector_string_val)->push_back((yystack_[5].value.string_val));
                      (yylhs.value.vector_string_val)->push_back((yystack_[3].value.string_val));
                    }
#line 2950 "DynareBison.cc" // lalr1.cc:859
    break;

  case 627:
#line 1529 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_prior_variance(); driver.prior_shape = eNoShape; }
#line 2956 "DynareBison.cc" // lalr1.cc:859
    break;

  case 628:
#line 1530 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_prior((yystack_[7].value.string_val), new string ("")); }
#line 2962 "DynareBison.cc" // lalr1.cc:859
    break;

  case 629:
#line 1531 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_prior_variance(); driver.prior_shape = eNoShape; }
#line 2968 "DynareBison.cc" // lalr1.cc:859
    break;

  case 630:
#line 1532 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_prior((yystack_[9].value.string_val), (yystack_[7].value.string_val)); }
#line 2974 "DynareBison.cc" // lalr1.cc:859
    break;

  case 631:
#line 1533 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_prior_variance(); driver.prior_shape = eNoShape; }
#line 2980 "DynareBison.cc" // lalr1.cc:859
    break;

  case 632:
#line 1534 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_joint_prior((yystack_[7].value.vector_string_val)); }
#line 2986 "DynareBison.cc" // lalr1.cc:859
    break;

  case 633:
#line 1535 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_prior_variance(); driver.prior_shape = eNoShape; }
#line 2992 "DynareBison.cc" // lalr1.cc:859
    break;

  case 634:
#line 1536 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_std_prior((yystack_[8].value.string_val), new string ("")); }
#line 2998 "DynareBison.cc" // lalr1.cc:859
    break;

  case 635:
#line 1537 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_prior_variance(); driver.prior_shape = eNoShape; }
#line 3004 "DynareBison.cc" // lalr1.cc:859
    break;

  case 636:
#line 1538 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_std_prior((yystack_[10].value.string_val), (yystack_[7].value.string_val)); }
#line 3010 "DynareBison.cc" // lalr1.cc:859
    break;

  case 637:
#line 1539 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_prior_variance(); driver.prior_shape = eNoShape; }
#line 3016 "DynareBison.cc" // lalr1.cc:859
    break;

  case 638:
#line 1540 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_corr_prior((yystack_[10].value.string_val), (yystack_[8].value.string_val), new string ("")); }
#line 3022 "DynareBison.cc" // lalr1.cc:859
    break;

  case 639:
#line 1541 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_prior_variance(); driver.prior_shape = eNoShape; }
#line 3028 "DynareBison.cc" // lalr1.cc:859
    break;

  case 640:
#line 1542 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_corr_prior((yystack_[12].value.string_val), (yystack_[10].value.string_val), (yystack_[7].value.string_val)); }
#line 3034 "DynareBison.cc" // lalr1.cc:859
    break;

  case 665:
#line 1578 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
             driver.copy_prior((yystack_[3].value.vector_string_val)->at(0), (yystack_[3].value.vector_string_val)->at(1), (yystack_[3].value.vector_string_val)->at(2), (yystack_[3].value.vector_string_val)->at(3),
                               (yystack_[1].value.vector_string_val)->at(0), (yystack_[1].value.vector_string_val)->at(1), (yystack_[1].value.vector_string_val)->at(2), (yystack_[1].value.vector_string_val)->at(3));
             delete (yystack_[3].value.vector_string_val);
             delete (yystack_[1].value.vector_string_val);
           }
#line 3045 "DynareBison.cc" // lalr1.cc:859
    break;

  case 666:
#line 1587 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                 (yylhs.value.vector_string_val) = new vector<string *>();
                 (yylhs.value.vector_string_val)->push_back(new string ("par"));
                 (yylhs.value.vector_string_val)->push_back((yystack_[2].value.string_val));
                 (yylhs.value.vector_string_val)->push_back(new string (""));
                 (yylhs.value.vector_string_val)->push_back(new string (""));
               }
#line 3057 "DynareBison.cc" // lalr1.cc:859
    break;

  case 667:
#line 1595 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                 (yylhs.value.vector_string_val) = new vector<string *>();
                 (yylhs.value.vector_string_val)->push_back(new string ("par"));
                 (yylhs.value.vector_string_val)->push_back((yystack_[4].value.string_val));
                 (yylhs.value.vector_string_val)->push_back(new string (""));
                 (yylhs.value.vector_string_val)->push_back((yystack_[2].value.string_val));
               }
#line 3069 "DynareBison.cc" // lalr1.cc:859
    break;

  case 668:
#line 1603 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                 (yylhs.value.vector_string_val) = new vector<string *>();
                 (yylhs.value.vector_string_val)->push_back(new string ("std"));
                 (yylhs.value.vector_string_val)->push_back((yystack_[3].value.string_val));
                 (yylhs.value.vector_string_val)->push_back(new string (""));
                 (yylhs.value.vector_string_val)->push_back(new string (""));
               }
#line 3081 "DynareBison.cc" // lalr1.cc:859
    break;

  case 669:
#line 1611 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                 (yylhs.value.vector_string_val) = new vector<string *>();
                 (yylhs.value.vector_string_val)->push_back(new string ("std"));
                 (yylhs.value.vector_string_val)->push_back((yystack_[5].value.string_val));
                 (yylhs.value.vector_string_val)->push_back(new string (""));
                 (yylhs.value.vector_string_val)->push_back((yystack_[2].value.string_val));
               }
#line 3093 "DynareBison.cc" // lalr1.cc:859
    break;

  case 670:
#line 1619 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                 (yylhs.value.vector_string_val) = new vector<string *>();
                 (yylhs.value.vector_string_val)->push_back(new string ("corr"));
                 (yylhs.value.vector_string_val)->push_back((yystack_[5].value.string_val));
                 (yylhs.value.vector_string_val)->push_back((yystack_[3].value.string_val));
                 (yylhs.value.vector_string_val)->push_back(new string (""));
               }
#line 3105 "DynareBison.cc" // lalr1.cc:859
    break;

  case 671:
#line 1627 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                 (yylhs.value.vector_string_val) = new vector<string *>();
                 (yylhs.value.vector_string_val)->push_back(new string ("corr"));
                 (yylhs.value.vector_string_val)->push_back((yystack_[7].value.string_val));
                 (yylhs.value.vector_string_val)->push_back((yystack_[5].value.string_val));
                 (yylhs.value.vector_string_val)->push_back((yystack_[2].value.string_val));
               }
#line 3117 "DynareBison.cc" // lalr1.cc:859
    break;

  case 672:
#line 1637 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_options((yystack_[6].value.string_val), new string ("")); }
#line 3123 "DynareBison.cc" // lalr1.cc:859
    break;

  case 673:
#line 1639 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_options((yystack_[8].value.string_val), (yystack_[6].value.string_val)); }
#line 3129 "DynareBison.cc" // lalr1.cc:859
    break;

  case 674:
#line 1641 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_std_options((yystack_[7].value.string_val), new string ("")); }
#line 3135 "DynareBison.cc" // lalr1.cc:859
    break;

  case 675:
#line 1643 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_std_options((yystack_[9].value.string_val), (yystack_[6].value.string_val)); }
#line 3141 "DynareBison.cc" // lalr1.cc:859
    break;

  case 676:
#line 1645 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_corr_options((yystack_[9].value.string_val), (yystack_[7].value.string_val), new string ("")); }
#line 3147 "DynareBison.cc" // lalr1.cc:859
    break;

  case 677:
#line 1647 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_corr_options((yystack_[11].value.string_val), (yystack_[9].value.string_val), (yystack_[6].value.string_val)); }
#line 3153 "DynareBison.cc" // lalr1.cc:859
    break;

  case 683:
#line 1660 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
               driver.copy_options((yystack_[3].value.vector_string_val)->at(0), (yystack_[3].value.vector_string_val)->at(1), (yystack_[3].value.vector_string_val)->at(2), (yystack_[3].value.vector_string_val)->at(3),
                                   (yystack_[1].value.vector_string_val)->at(0), (yystack_[1].value.vector_string_val)->at(1), (yystack_[1].value.vector_string_val)->at(2), (yystack_[1].value.vector_string_val)->at(3));
               delete (yystack_[3].value.vector_string_val);
               delete (yystack_[1].value.vector_string_val);
             }
#line 3164 "DynareBison.cc" // lalr1.cc:859
    break;

  case 684:
#line 1669 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                   (yylhs.value.vector_string_val) = new vector<string *>();
                   (yylhs.value.vector_string_val)->push_back(new string ("par"));
                   (yylhs.value.vector_string_val)->push_back((yystack_[2].value.string_val));
                   (yylhs.value.vector_string_val)->push_back(new string (""));
                   (yylhs.value.vector_string_val)->push_back(new string (""));
                 }
#line 3176 "DynareBison.cc" // lalr1.cc:859
    break;

  case 685:
#line 1677 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                   (yylhs.value.vector_string_val) = new vector<string *>();
                   (yylhs.value.vector_string_val)->push_back(new string ("par"));
                   (yylhs.value.vector_string_val)->push_back((yystack_[4].value.string_val));
                   (yylhs.value.vector_string_val)->push_back(new string (""));
                   (yylhs.value.vector_string_val)->push_back((yystack_[2].value.string_val));
                 }
#line 3188 "DynareBison.cc" // lalr1.cc:859
    break;

  case 686:
#line 1685 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                   (yylhs.value.vector_string_val) = new vector<string *>();
                   (yylhs.value.vector_string_val)->push_back(new string ("std"));
                   (yylhs.value.vector_string_val)->push_back((yystack_[3].value.string_val));
                   (yylhs.value.vector_string_val)->push_back(new string (""));
                   (yylhs.value.vector_string_val)->push_back(new string (""));
                 }
#line 3200 "DynareBison.cc" // lalr1.cc:859
    break;

  case 687:
#line 1693 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                   (yylhs.value.vector_string_val) = new vector<string *>();
                   (yylhs.value.vector_string_val)->push_back(new string ("std"));
                   (yylhs.value.vector_string_val)->push_back((yystack_[5].value.string_val));
                   (yylhs.value.vector_string_val)->push_back(new string (""));
                   (yylhs.value.vector_string_val)->push_back((yystack_[2].value.string_val));
                 }
#line 3212 "DynareBison.cc" // lalr1.cc:859
    break;

  case 688:
#line 1701 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                   (yylhs.value.vector_string_val) = new vector<string *>();
                   (yylhs.value.vector_string_val)->push_back(new string ("corr"));
                   (yylhs.value.vector_string_val)->push_back((yystack_[5].value.string_val));
                   (yylhs.value.vector_string_val)->push_back((yystack_[3].value.string_val));
                   (yylhs.value.vector_string_val)->push_back(new string (""));
                 }
#line 3224 "DynareBison.cc" // lalr1.cc:859
    break;

  case 689:
#line 1709 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                   (yylhs.value.vector_string_val) = new vector<string *>();
                   (yylhs.value.vector_string_val)->push_back(new string ("corr"));
                   (yylhs.value.vector_string_val)->push_back((yystack_[7].value.string_val));
                   (yylhs.value.vector_string_val)->push_back((yystack_[5].value.string_val));
                   (yylhs.value.vector_string_val)->push_back((yystack_[2].value.string_val));
                 }
#line 3236 "DynareBison.cc" // lalr1.cc:859
    break;

  case 690:
#line 1719 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.run_estimation(); }
#line 3242 "DynareBison.cc" // lalr1.cc:859
    break;

  case 691:
#line 1721 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.run_estimation(); }
#line 3248 "DynareBison.cc" // lalr1.cc:859
    break;

  case 692:
#line 1723 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.run_estimation(); }
#line 3254 "DynareBison.cc" // lalr1.cc:859
    break;

  case 693:
#line 1725 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.run_estimation(); }
#line 3260 "DynareBison.cc" // lalr1.cc:859
    break;

  case 806:
#line 1845 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.optim_options_string((yystack_[2].value.string_val), (yystack_[0].value.string_val)); }
#line 3266 "DynareBison.cc" // lalr1.cc:859
    break;

  case 807:
#line 1847 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.optim_options_num((yystack_[2].value.string_val), (yystack_[0].value.string_val)); }
#line 3272 "DynareBison.cc" // lalr1.cc:859
    break;

  case 810:
#line 1855 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                             (yystack_[2].value.string_val)->insert(0, "''");
                             (yystack_[2].value.string_val)->append("'', ''");
                             (yystack_[2].value.string_val)->append(*(yystack_[0].value.string_val));
                             (yystack_[2].value.string_val)->append("''");
                             (yylhs.value.string_val) = (yystack_[2].value.string_val);
                           }
#line 3284 "DynareBison.cc" // lalr1.cc:859
    break;

  case 811:
#line 1863 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                             (yystack_[2].value.string_val)->insert(0, "''");
                             (yystack_[2].value.string_val)->append("'',");
                             (yystack_[2].value.string_val)->append(*(yystack_[0].value.string_val));
                             (yylhs.value.string_val) = (yystack_[2].value.string_val);
                           }
#line 3295 "DynareBison.cc" // lalr1.cc:859
    break;

  case 812:
#line 1872 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 3301 "DynareBison.cc" // lalr1.cc:859
    break;

  case 813:
#line 1874 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                         (yystack_[2].value.string_val)->append(",");
                         (yystack_[2].value.string_val)->append(*(yystack_[0].value.string_val));
                         (yylhs.value.string_val) = (yystack_[2].value.string_val);
                       }
#line 3311 "DynareBison.cc" // lalr1.cc:859
    break;

  case 814:
#line 1882 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.sampling_options_string((yystack_[2].value.string_val), (yystack_[0].value.string_val)); }
#line 3317 "DynareBison.cc" // lalr1.cc:859
    break;

  case 815:
#line 1884 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.sampling_options_num((yystack_[2].value.string_val), (yystack_[0].value.string_val)); }
#line 3323 "DynareBison.cc" // lalr1.cc:859
    break;

  case 816:
#line 1886 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                         (yystack_[1].value.string_val)->insert(0,"(");
                         (yystack_[1].value.string_val)->append(")");
                         driver.sampling_options_string((yystack_[4].value.string_val), (yystack_[1].value.string_val));
                       }
#line 3333 "DynareBison.cc" // lalr1.cc:859
    break;

  case 819:
#line 1897 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.check_varobs(); }
#line 3339 "DynareBison.cc" // lalr1.cc:859
    break;

  case 821:
#line 1900 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_varobs((yystack_[0].value.string_val)); }
#line 3345 "DynareBison.cc" // lalr1.cc:859
    break;

  case 822:
#line 1902 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_varobs((yystack_[0].value.string_val)); }
#line 3351 "DynareBison.cc" // lalr1.cc:859
    break;

  case 823:
#line 1904 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_varobs((yystack_[0].value.string_val)); }
#line 3357 "DynareBison.cc" // lalr1.cc:859
    break;

  case 824:
#line 1907 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_trends(); }
#line 3363 "DynareBison.cc" // lalr1.cc:859
    break;

  case 827:
#line 1913 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_trend_element((yystack_[4].value.string_val), (yystack_[2].value.node_val)); }
#line 3369 "DynareBison.cc" // lalr1.cc:859
    break;

  case 828:
#line 1915 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_unit_root_vars(); }
#line 3375 "DynareBison.cc" // lalr1.cc:859
    break;

  case 829:
#line 1917 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.optim_weights(); }
#line 3381 "DynareBison.cc" // lalr1.cc:859
    break;

  case 830:
#line 1920 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_optim_weights((yystack_[2].value.string_val), (yystack_[1].value.node_val)); }
#line 3387 "DynareBison.cc" // lalr1.cc:859
    break;

  case 831:
#line 1922 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_optim_weights((yystack_[4].value.string_val), (yystack_[2].value.string_val), (yystack_[1].value.node_val)); }
#line 3393 "DynareBison.cc" // lalr1.cc:859
    break;

  case 832:
#line 1924 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_optim_weights((yystack_[2].value.string_val), (yystack_[1].value.node_val)); }
#line 3399 "DynareBison.cc" // lalr1.cc:859
    break;

  case 833:
#line 1926 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_optim_weights((yystack_[4].value.string_val), (yystack_[2].value.string_val), (yystack_[1].value.node_val)); }
#line 3405 "DynareBison.cc" // lalr1.cc:859
    break;

  case 834:
#line 1929 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_osr_params(); }
#line 3411 "DynareBison.cc" // lalr1.cc:859
    break;

  case 844:
#line 1946 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.run_osr(); }
#line 3417 "DynareBison.cc" // lalr1.cc:859
    break;

  case 845:
#line 1948 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.run_osr(); }
#line 3423 "DynareBison.cc" // lalr1.cc:859
    break;

  case 846:
#line 1950 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.run_osr(); }
#line 3429 "DynareBison.cc" // lalr1.cc:859
    break;

  case 847:
#line 1952 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.run_osr(); }
#line 3435 "DynareBison.cc" // lalr1.cc:859
    break;

  case 848:
#line 1956 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.run_dynatype((yystack_[2].value.string_val)); }
#line 3441 "DynareBison.cc" // lalr1.cc:859
    break;

  case 849:
#line 1958 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.run_dynatype((yystack_[3].value.string_val)); }
#line 3447 "DynareBison.cc" // lalr1.cc:859
    break;

  case 850:
#line 1962 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.run_dynasave((yystack_[2].value.string_val)); }
#line 3453 "DynareBison.cc" // lalr1.cc:859
    break;

  case 851:
#line 1964 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.run_dynasave((yystack_[3].value.string_val)); }
#line 3459 "DynareBison.cc" // lalr1.cc:859
    break;

  case 852:
#line 1968 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.run_load_params_and_steady_state((yystack_[2].value.string_val)); }
#line 3465 "DynareBison.cc" // lalr1.cc:859
    break;

  case 853:
#line 1972 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.run_save_params_and_steady_state((yystack_[2].value.string_val)); }
#line 3471 "DynareBison.cc" // lalr1.cc:859
    break;

  case 854:
#line 1976 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.run_identification(); }
#line 3477 "DynareBison.cc" // lalr1.cc:859
    break;

  case 855:
#line 1978 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.run_identification(); }
#line 3483 "DynareBison.cc" // lalr1.cc:859
    break;

  case 878:
#line 2008 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.run_model_comparison(); }
#line 3489 "DynareBison.cc" // lalr1.cc:859
    break;

  case 879:
#line 2010 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.run_model_comparison(); }
#line 3495 "DynareBison.cc" // lalr1.cc:859
    break;

  case 882:
#line 2018 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_parallel_local_file((yystack_[0].value.string_val)); }
#line 3501 "DynareBison.cc" // lalr1.cc:859
    break;

  case 883:
#line 2020 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_parallel_local_file((yystack_[0].value.string_val)); }
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
#line 2028 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_mc_filename((yystack_[0].value.string_val)); }
#line 3525 "DynareBison.cc" // lalr1.cc:859
    break;

  case 887:
#line 2030 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_mc_filename((yystack_[3].value.string_val), (yystack_[1].value.string_val)); }
#line 3531 "DynareBison.cc" // lalr1.cc:859
    break;

  case 888:
#line 2032 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_mc_filename((yystack_[0].value.string_val)); }
#line 3537 "DynareBison.cc" // lalr1.cc:859
    break;

  case 889:
#line 2034 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_mc_filename((yystack_[3].value.string_val), (yystack_[1].value.string_val)); }
#line 3543 "DynareBison.cc" // lalr1.cc:859
    break;

  case 890:
#line 2037 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.begin_planner_objective(); }
#line 3549 "DynareBison.cc" // lalr1.cc:859
    break;

  case 891:
#line 2038 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.end_planner_objective((yystack_[0].value.node_val)); }
#line 3555 "DynareBison.cc" // lalr1.cc:859
    break;

  case 893:
#line 2041 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ramsey_model(); }
#line 3561 "DynareBison.cc" // lalr1.cc:859
    break;

  case 894:
#line 2043 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ramsey_model(); }
#line 3567 "DynareBison.cc" // lalr1.cc:859
    break;

  case 895:
#line 2045 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ramsey_model(); }
#line 3573 "DynareBison.cc" // lalr1.cc:859
    break;

  case 896:
#line 2047 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ramsey_model(); }
#line 3579 "DynareBison.cc" // lalr1.cc:859
    break;

  case 897:
#line 2051 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ramsey_policy(); }
#line 3585 "DynareBison.cc" // lalr1.cc:859
    break;

  case 898:
#line 2053 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ramsey_policy(); }
#line 3591 "DynareBison.cc" // lalr1.cc:859
    break;

  case 899:
#line 2055 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ramsey_policy(); }
#line 3597 "DynareBison.cc" // lalr1.cc:859
    break;

  case 900:
#line 2057 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ramsey_policy(); }
#line 3603 "DynareBison.cc" // lalr1.cc:859
    break;

  case 903:
#line 2064 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_to_ramsey_policy_list((yystack_[0].value.string_val)); }
#line 3609 "DynareBison.cc" // lalr1.cc:859
    break;

  case 904:
#line 2068 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_ramsey_constraints_statement(); }
#line 3615 "DynareBison.cc" // lalr1.cc:859
    break;

  case 907:
#line 2076 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ramsey_constraint_add_less((yystack_[3].value.string_val),(yystack_[1].value.node_val)); }
#line 3621 "DynareBison.cc" // lalr1.cc:859
    break;

  case 908:
#line 2078 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ramsey_constraint_add_greater((yystack_[3].value.string_val),(yystack_[1].value.node_val)); }
#line 3627 "DynareBison.cc" // lalr1.cc:859
    break;

  case 909:
#line 2080 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ramsey_constraint_add_less_equal((yystack_[3].value.string_val),(yystack_[1].value.node_val)); }
#line 3633 "DynareBison.cc" // lalr1.cc:859
    break;

  case 910:
#line 2082 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ramsey_constraint_add_greater_equal((yystack_[3].value.string_val),(yystack_[1].value.node_val)); }
#line 3639 "DynareBison.cc" // lalr1.cc:859
    break;

  case 911:
#line 2086 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.discretionary_policy(); }
#line 3645 "DynareBison.cc" // lalr1.cc:859
    break;

  case 912:
#line 2088 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.discretionary_policy(); }
#line 3651 "DynareBison.cc" // lalr1.cc:859
    break;

  case 913:
#line 2090 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.discretionary_policy(); }
#line 3657 "DynareBison.cc" // lalr1.cc:859
    break;

  case 914:
#line 2092 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.discretionary_policy(); }
#line 3663 "DynareBison.cc" // lalr1.cc:859
    break;

  case 929:
#line 2122 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.write_latex_dynamic_model(false); }
#line 3669 "DynareBison.cc" // lalr1.cc:859
    break;

  case 930:
#line 2124 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.write_latex_dynamic_model(true); }
#line 3675 "DynareBison.cc" // lalr1.cc:859
    break;

  case 931:
#line 2128 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.write_latex_static_model(); }
#line 3681 "DynareBison.cc" // lalr1.cc:859
    break;

  case 932:
#line 2132 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.write_latex_original_model(); }
#line 3687 "DynareBison.cc" // lalr1.cc:859
    break;

  case 933:
#line 2136 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.shock_decomposition(); }
#line 3693 "DynareBison.cc" // lalr1.cc:859
    break;

  case 934:
#line 2138 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.shock_decomposition(); }
#line 3699 "DynareBison.cc" // lalr1.cc:859
    break;

  case 935:
#line 2140 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.shock_decomposition(); }
#line 3705 "DynareBison.cc" // lalr1.cc:859
    break;

  case 936:
#line 2142 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.shock_decomposition(); }
#line 3711 "DynareBison.cc" // lalr1.cc:859
    break;

  case 937:
#line 2146 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.realtime_shock_decomposition(); }
#line 3717 "DynareBison.cc" // lalr1.cc:859
    break;

  case 938:
#line 2148 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.realtime_shock_decomposition(); }
#line 3723 "DynareBison.cc" // lalr1.cc:859
    break;

  case 939:
#line 2150 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.realtime_shock_decomposition(); }
#line 3729 "DynareBison.cc" // lalr1.cc:859
    break;

  case 940:
#line 2152 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.realtime_shock_decomposition(); }
#line 3735 "DynareBison.cc" // lalr1.cc:859
    break;

  case 941:
#line 2156 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.plot_shock_decomposition(); }
#line 3741 "DynareBison.cc" // lalr1.cc:859
    break;

  case 942:
#line 2158 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.plot_shock_decomposition(); }
#line 3747 "DynareBison.cc" // lalr1.cc:859
    break;

  case 943:
#line 2160 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.plot_shock_decomposition(); }
#line 3753 "DynareBison.cc" // lalr1.cc:859
    break;

  case 944:
#line 2162 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.plot_shock_decomposition(); }
#line 3759 "DynareBison.cc" // lalr1.cc:859
    break;

  case 945:
#line 2166 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.initial_condition_decomposition(); }
#line 3765 "DynareBison.cc" // lalr1.cc:859
    break;

  case 946:
#line 2168 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.initial_condition_decomposition(); }
#line 3771 "DynareBison.cc" // lalr1.cc:859
    break;

  case 947:
#line 2170 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.initial_condition_decomposition(); }
#line 3777 "DynareBison.cc" // lalr1.cc:859
    break;

  case 948:
#line 2172 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.initial_condition_decomposition(); }
#line 3783 "DynareBison.cc" // lalr1.cc:859
    break;

  case 968:
#line 2201 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.bvar_density((yystack_[1].value.string_val)); }
#line 3789 "DynareBison.cc" // lalr1.cc:859
    break;

  case 969:
#line 2203 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.bvar_density((yystack_[1].value.string_val)); }
#line 3795 "DynareBison.cc" // lalr1.cc:859
    break;

  case 976:
#line 2217 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.bvar_forecast((yystack_[1].value.string_val)); }
#line 3801 "DynareBison.cc" // lalr1.cc:859
    break;

  case 977:
#line 2219 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.bvar_forecast((yystack_[1].value.string_val)); }
#line 3807 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1028:
#line 2277 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.sbvar(); }
#line 3813 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1029:
#line 2279 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.sbvar(); }
#line 3819 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1046:
#line 2303 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ms_variance_decomposition(); }
#line 3825 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1047:
#line 2305 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ms_variance_decomposition(); }
#line 3831 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1064:
#line 2329 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ms_forecast(); }
#line 3837 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1065:
#line 2331 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ms_forecast(); }
#line 3843 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1082:
#line 2355 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ms_irf(); }
#line 3849 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1083:
#line 2357 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ms_irf(); }
#line 3855 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1084:
#line 2359 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ms_irf(); }
#line 3861 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1085:
#line 2361 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ms_irf(); }
#line 3867 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1092:
#line 2375 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ms_compute_probabilities(); }
#line 3873 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1093:
#line 2377 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ms_compute_probabilities(); }
#line 3879 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1104:
#line 2395 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ms_compute_mdd(); }
#line 3885 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1105:
#line 2397 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ms_compute_mdd(); }
#line 3891 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1115:
#line 2414 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ms_simulation(); }
#line 3897 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1116:
#line 2416 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ms_simulation(); }
#line 3903 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1154:
#line 2461 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ms_estimation(); }
#line 3909 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1155:
#line 2463 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.ms_estimation(); }
#line 3915 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1156:
#line 2467 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.dynare_sensitivity(); }
#line 3921 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1157:
#line 2469 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.dynare_sensitivity(); }
#line 3927 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1258:
#line 2593 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.end_homotopy();}
#line 3933 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1261:
#line 2600 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.homotopy_val((yystack_[5].value.string_val), (yystack_[3].value.node_val), (yystack_[1].value.node_val));}
#line 3939 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1262:
#line 2602 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.homotopy_val((yystack_[3].value.string_val), NULL, (yystack_[1].value.node_val));}
#line 3945 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1263:
#line 2605 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.forecast();}
#line 3951 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1264:
#line 2606 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.forecast();}
#line 3957 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1265:
#line 2607 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.forecast();}
#line 3963 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1266:
#line 2608 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.forecast();}
#line 3969 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1274:
#line 2623 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.conditional_forecast(); }
#line 3975 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1282:
#line 2638 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.plot_conditional_forecast(); }
#line 3981 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1283:
#line 2640 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.plot_conditional_forecast((yystack_[3].value.string_val)); }
#line 3987 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1284:
#line 2644 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.conditional_forecast_paths(); }
#line 3993 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1287:
#line 2652 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_det_shock((yystack_[7].value.string_val), true); }
#line 3999 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1288:
#line 2655 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.begin_steady_state_model(); }
#line 4005 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1289:
#line 2656 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.reset_data_tree(); }
#line 4011 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1292:
#line 2664 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_steady_state_model_equal((yystack_[3].value.string_val), (yystack_[1].value.node_val)); }
#line 4017 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1293:
#line 2666 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_steady_state_model_equal_multiple((yystack_[1].value.node_val)); }
#line 4023 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1294:
#line 2670 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.calib_smoother(); }
#line 4029 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1295:
#line 2672 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.calib_smoother(); }
#line 4035 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1296:
#line 2674 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.calib_smoother(); }
#line 4041 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1297:
#line 2676 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.calib_smoother(); }
#line 4047 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1310:
#line 2696 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.extended_path(); }
#line 4053 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1311:
#line 2698 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.extended_path(); }
#line 4059 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1319:
#line 2713 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.model_diagnostics(); }
#line 4065 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1320:
#line 2717 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                      (yylhs.value.vector_string_val) = new vector<string *>();
                      (yylhs.value.vector_string_val)->push_back((yystack_[2].value.string_val));
                      (yylhs.value.vector_string_val)->push_back((yystack_[1].value.string_val));
                    }
#line 4075 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1321:
#line 2723 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                      (yylhs.value.vector_string_val) = new vector<string *>();
                      (yylhs.value.vector_string_val)->push_back((yystack_[3].value.string_val));
                      (yylhs.value.vector_string_val)->push_back((yystack_[1].value.string_val));
                    }
#line 4085 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1322:
#line 2729 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                      (yylhs.value.vector_string_val) = new vector<string *>();
                      (yylhs.value.vector_string_val)->push_back(new string("0"));
                      (yylhs.value.vector_string_val)->push_back(new string("inf"));
                    }
#line 4095 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1323:
#line 2735 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                      (yylhs.value.vector_string_val) = new vector<string *>();
                      (yylhs.value.vector_string_val)->push_back(new string("-inf"));
                      (yylhs.value.vector_string_val)->push_back(new string("0"));
                    }
#line 4105 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1324:
#line 2743 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.end_moment_calibration(); }
#line 4111 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1327:
#line 2751 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_moment_calibration_item((yystack_[5].value.string_val), (yystack_[3].value.string_val), new string("0"), (yystack_[1].value.vector_string_val)); }
#line 4117 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1328:
#line 2753 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_moment_calibration_item((yystack_[8].value.string_val), (yystack_[6].value.string_val), (yystack_[4].value.string_val), (yystack_[1].value.vector_string_val)); }
#line 4123 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1329:
#line 2755 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_moment_calibration_item((yystack_[8].value.string_val), (yystack_[6].value.string_val), (yystack_[4].value.string_val), (yystack_[1].value.vector_string_val)); }
#line 4129 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1330:
#line 2759 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.end_irf_calibration(); }
#line 4135 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1331:
#line 2761 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.end_irf_calibration(); }
#line 4141 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1334:
#line 2769 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_irf_calibration_item((yystack_[5].value.string_val), new string("1"), (yystack_[3].value.string_val), (yystack_[1].value.vector_string_val)); }
#line 4147 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1335:
#line 2771 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_irf_calibration_item((yystack_[8].value.string_val), (yystack_[6].value.string_val), (yystack_[3].value.string_val), (yystack_[1].value.vector_string_val)); }
#line 4153 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1336:
#line 2773 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_irf_calibration_item((yystack_[8].value.string_val), (yystack_[6].value.string_val), (yystack_[3].value.string_val), (yystack_[1].value.vector_string_val)); }
#line 4159 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1337:
#line 2777 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.smoother2histval(); }
#line 4165 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1338:
#line 2779 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.smoother2histval(); }
#line 4171 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1346:
#line 2793 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.end_shock_groups(new string("default"));}
#line 4177 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1347:
#line 2795 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.end_shock_groups((yystack_[5].value.string_val));}
#line 4183 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1350:
#line 2802 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_shock_group((yystack_[3].value.string_val)); }
#line 4189 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1351:
#line 2803 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_shock_group((yystack_[3].value.string_val)); }
#line 4195 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1352:
#line 2806 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.add_shock_group_element((yystack_[0].value.string_val));}
#line 4201 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1353:
#line 2807 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.add_shock_group_element((yystack_[0].value.string_val));}
#line 4207 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1354:
#line 2808 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.add_shock_group_element((yystack_[0].value.string_val));}
#line 4213 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1355:
#line 2811 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                                       if (*(yystack_[0].value.string_val) == string("0"))
                                         driver.warning("dr_algo option is now deprecated, and may be removed in a future version of Dynare");
                                       else
                                         driver.error("dr_algo=1 option is no longer supported");
                                     }
#line 4224 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1356:
#line 2817 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("solve_algo", (yystack_[0].value.string_val)); }
#line 4230 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1357:
#line 2818 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                                             if (*(yystack_[0].value.string_val) == string("0"))
                                               driver.warning("simul_algo option is now deprecated, and may be removed in a future version of Dynare");
                                             else
                                               driver.error("simul_algo=1 option is no longer supported");
                                           }
#line 4241 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1358:
#line 2824 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("stack_solve_algo", (yystack_[0].value.string_val)); }
#line 4247 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1359:
#line 2825 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("simul.robust_lin_solve", "1"); }
#line 4253 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1360:
#line 2826 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("endogenous_terminal_period", "1"); }
#line 4259 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1361:
#line 2827 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.linear(); }
#line 4265 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1362:
#line 2828 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("order", (yystack_[0].value.string_val)); }
#line 4271 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1363:
#line 2829 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("replic", (yystack_[0].value.string_val)); }
#line 4277 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1364:
#line 2830 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("drop", (yystack_[0].value.string_val)); }
#line 4283 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1365:
#line 2831 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ar", (yystack_[0].value.string_val)); }
#line 4289 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1366:
#line 2832 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("nocorr", "1"); }
#line 4295 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1367:
#line 2833 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("nofunctions", "1"); }
#line 4301 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1368:
#line 2834 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("nomoments", "1"); }
#line 4307 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1369:
#line 2835 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("irf", (yystack_[0].value.string_val)); }
#line 4313 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1370:
#line 2836 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_symbol_list("irf_shocks"); }
#line 4319 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1371:
#line 2837 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("hp_filter", (yystack_[0].value.string_val)); }
#line 4325 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1372:
#line 2838 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("hp_ngrid", (yystack_[0].value.string_val)); }
#line 4331 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1373:
#line 2839 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("one_sided_hp_filter", (yystack_[0].value.string_val)); }
#line 4337 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1374:
#line 2840 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("periods", (yystack_[0].value.string_val)); }
#line 4343 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1375:
#line 2841 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ep.periods", (yystack_[0].value.string_val)); }
#line 4349 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1376:
#line 2842 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ep.stochastic.order", (yystack_[0].value.string_val)); }
#line 4355 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1377:
#line 2843 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ep.stochastic.hybrid_order", "2"); }
#line 4361 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1378:
#line 2844 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("steady.maxit", (yystack_[0].value.string_val)); }
#line 4367 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1379:
#line 2845 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("simul.maxit", (yystack_[0].value.string_val)); }
#line 4373 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1380:
#line 2846 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("bandpass.indicator", "1"); }
#line 4379 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1381:
#line 2848 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                      driver.option_num("bandpass.indicator", "1");
                      driver.option_vec_int("bandpass.passband", (yystack_[0].value.vector_int_val));
                    }
#line 4388 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1382:
#line 2853 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("dp.maxit", (yystack_[0].value.string_val)); }
#line 4394 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1383:
#line 2854 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("osr.maxit", (yystack_[0].value.string_val)); }
#line 4400 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1384:
#line 2855 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("osr.tolf", (yystack_[0].value.string_val)); }
#line 4406 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1385:
#line 2856 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("dynatol.f", (yystack_[0].value.string_val)); }
#line 4412 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1386:
#line 2857 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("dynatol.x", (yystack_[0].value.string_val)); }
#line 4418 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1387:
#line 2858 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("solve_tolf", (yystack_[0].value.string_val)); }
#line 4424 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1388:
#line 2859 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("osr.opt_algo", (yystack_[0].value.string_val)); }
#line 4430 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1389:
#line 2860 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("osr.opt_algo", (yystack_[0].value.string_val)); }
#line 4436 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1390:
#line 2862 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.cutoff((yystack_[0].value.string_val)); }
#line 4442 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1391:
#line 2863 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("markowitz", (yystack_[0].value.string_val)); }
#line 4448 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1392:
#line 2864 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("minimal_solving_periods", (yystack_[0].value.string_val)); }
#line 4454 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1393:
#line 2865 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.mfs((yystack_[0].value.string_val)); }
#line 4460 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1395:
#line 2867 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("simul_replic", (yystack_[0].value.string_val)); }
#line 4466 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1396:
#line 2868 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.error("'simul_seed' option is no longer supported; use 'set_dynare_seed' command instead"); }
#line 4472 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1397:
#line 2869 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("qz_criterium", (yystack_[0].value.string_val)); }
#line 4478 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1398:
#line 2870 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("qz_zero_threshold", (yystack_[0].value.string_val)); }
#line 4484 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1399:
#line 2871 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("file", (yystack_[0].value.string_val)); }
#line 4490 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1400:
#line 2872 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("series", (yystack_[0].value.string_val)); }
#line 4496 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1401:
#line 2873 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("datafile", (yystack_[0].value.string_val)); }
#line 4502 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1402:
#line 2874 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("dirname", (yystack_[0].value.string_val)); }
#line 4508 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1403:
#line 2875 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("huge_number", (yystack_[0].value.string_val)); }
#line 4514 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1404:
#line 2877 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_vec_int("nobs", (yystack_[0].value.vector_int_val)); }
#line 4520 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1405:
#line 2879 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_vec_int("nobs", (yystack_[0].value.vector_int_val)); }
#line 4526 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1406:
#line 2882 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_vec_int("conditional_variance_decomposition", (yystack_[0].value.vector_int_val)); }
#line 4532 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1407:
#line 2884 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_vec_int("conditional_variance_decomposition", (yystack_[0].value.vector_int_val)); }
#line 4538 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1408:
#line 2887 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_vec_int("first_obs", (yystack_[0].value.vector_int_val)); }
#line 4544 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1409:
#line 2889 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_vec_int("first_obs", (yystack_[0].value.vector_int_val)); }
#line 4550 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1410:
#line 2892 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("posterior_sampler_options.posterior_sampling_method", (yystack_[0].value.string_val)); }
#line 4556 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1411:
#line 2893 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("first_obs", (yystack_[0].value.string_val)); }
#line 4562 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1412:
#line 2894 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_date("firstobs", (yystack_[0].value.string_val)); }
#line 4568 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1413:
#line 2895 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_date("lastobs", (yystack_[0].value.string_val)); }
#line 4574 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1414:
#line 2896 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("kalman.keep_kalman_algo_if_singularity_is_detected", "1"); }
#line 4580 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1415:
#line 2897 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("nobs", (yystack_[0].value.string_val)); }
#line 4586 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1416:
#line 2898 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("shift", (yystack_[0].value.string_val)); }
#line 4592 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1417:
#line 2899 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.prior_shape = (yystack_[0].value.prior_distributions_val); }
#line 4598 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1418:
#line 2900 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("mode", (yystack_[0].value.string_val)); }
#line 4604 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1419:
#line 2901 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("mean", (yystack_[0].value.string_val)); }
#line 4610 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1420:
#line 2902 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("mean", (yystack_[0].value.string_val)); }
#line 4616 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1421:
#line 2903 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("truncate", (yystack_[0].value.string_val)); }
#line 4622 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1422:
#line 2904 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("stdev", (yystack_[0].value.string_val)); }
#line 4628 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1423:
#line 2905 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("jscale", (yystack_[0].value.string_val)); }
#line 4634 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1424:
#line 2906 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("init", (yystack_[0].value.string_val)); }
#line 4640 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1425:
#line 2907 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("bounds", (yystack_[0].value.string_val)); }
#line 4646 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1426:
#line 2908 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("domain", (yystack_[0].value.string_val)); }
#line 4652 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1427:
#line 2909 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("interval", (yystack_[0].value.string_val)); }
#line 4658 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1428:
#line 2910 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_prior_variance((yystack_[0].value.node_val)); }
#line 4664 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1429:
#line 2911 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("variance",(yystack_[0].value.string_val)); }
#line 4670 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1430:
#line 2912 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("prefilter", (yystack_[0].value.string_val)); }
#line 4676 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1431:
#line 2913 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("presample", (yystack_[0].value.string_val)); }
#line 4682 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1432:
#line 2914 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("lik_algo", (yystack_[0].value.string_val)); }
#line 4688 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1433:
#line 2915 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("lik_init", (yystack_[0].value.string_val)); }
#line 4694 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1434:
#line 2917 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("nograph","1"); }
#line 4700 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1435:
#line 2919 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("nograph", "0"); }
#line 4706 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1436:
#line 2922 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("no_graph.posterior","1"); }
#line 4712 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1437:
#line 2924 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("no_graph.posterior", "0"); }
#line 4718 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1438:
#line 2926 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("no_graph.shock_decomposition", "1"); }
#line 4724 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1439:
#line 2927 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("shock_decomp.init_state", (yystack_[0].value.string_val)); }
#line 4730 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1440:
#line 2928 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("shock_decomp.presample", (yystack_[0].value.string_val)); }
#line 4736 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1441:
#line 2929 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("shock_decomp.forecast", (yystack_[0].value.string_val)); }
#line 4742 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1442:
#line 2930 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_vec_int("shock_decomp.save_realtime", (yystack_[0].value.vector_int_val)); }
#line 4748 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1443:
#line 2931 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("nodisplay","1"); }
#line 4754 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1444:
#line 2932 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("plot_shock_decomp.nodisplay","1"); }
#line 4760 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1445:
#line 2934 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.process_graph_format_option(); }
#line 4766 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1446:
#line 2936 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.process_graph_format_option(); }
#line 4772 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1447:
#line 2939 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.plot_shock_decomp_process_graph_format_option(); }
#line 4778 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1448:
#line 2941 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.plot_shock_decomp_process_graph_format_option(); }
#line 4784 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1449:
#line 2944 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_graph_format("eps"); }
#line 4790 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1450:
#line 2946 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_graph_format("fig"); }
#line 4796 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1451:
#line 2948 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_graph_format("pdf"); }
#line 4802 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1452:
#line 2950 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.add_graph_format("none"); }
#line 4808 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1455:
#line 2957 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.set_subsample_name_equal_to_date_range((yystack_[4].value.string_val), (yystack_[2].value.string_val), (yystack_[0].value.string_val)); }
#line 4814 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1456:
#line 2959 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("bvar.conf_sig", (yystack_[0].value.string_val)); }
#line 4820 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1457:
#line 2960 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("forecasts.conf_sig", (yystack_[0].value.string_val)); }
#line 4826 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1458:
#line 2961 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("conditional_forecast.conf_sig", (yystack_[0].value.string_val)); }
#line 4832 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1459:
#line 2962 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("mh_conf_sig", (yystack_[0].value.string_val)); }
#line 4838 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1460:
#line 2963 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("mh_replic", (yystack_[0].value.string_val)); }
#line 4844 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1461:
#line 2964 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("posterior_max_subsample_draws", (yystack_[0].value.string_val)); }
#line 4850 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1462:
#line 2965 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("mh_drop", (yystack_[0].value.string_val)); }
#line 4856 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1463:
#line 2966 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("mh_jscale", (yystack_[0].value.string_val)); }
#line 4862 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1466:
#line 2969 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("posterior_sampler_options.posterior_sampling_method.proposal_distribution", (yystack_[0].value.string_val)); }
#line 4868 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1467:
#line 2971 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("estimation.moments_posterior_density.indicator", "0"); }
#line 4874 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1468:
#line 2973 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("mh_init_scale", (yystack_[0].value.string_val)); }
#line 4880 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1469:
#line 2974 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("mode_file", (yystack_[0].value.string_val)); }
#line 4886 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1470:
#line 2975 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("mode_compute", (yystack_[0].value.string_val)); }
#line 4892 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1471:
#line 2976 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("mode_compute", (yystack_[0].value.string_val)); }
#line 4898 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1472:
#line 2977 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("mode_check.status", "1"); }
#line 4904 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1473:
#line 2978 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("mode_check.neighbourhood_size", (yystack_[0].value.string_val)); }
#line 4910 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1474:
#line 2979 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("mode_check.number_of_points", (yystack_[0].value.string_val)); }
#line 4916 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1475:
#line 2980 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("mode_check.symmetric_plots", (yystack_[0].value.string_val)); }
#line 4922 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1476:
#line 2981 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("prior_trunc", (yystack_[0].value.string_val)); }
#line 4928 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1477:
#line 2982 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("mh_mode", (yystack_[0].value.string_val)); }
#line 4934 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1478:
#line 2983 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("mh_nblck", (yystack_[0].value.string_val)); }
#line 4940 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1479:
#line 2984 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("load_mh_file", "1"); }
#line 4946 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1480:
#line 2985 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("load_results_after_load_mh", "1"); }
#line 4952 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1481:
#line 2986 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("loglinear", "1"); }
#line 4958 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1482:
#line 2987 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("linear_approximation", "1"); }
#line 4964 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1483:
#line 2988 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("logdata", "1"); }
#line 4970 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1484:
#line 2989 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("nodiagnostic", "1"); }
#line 4976 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1485:
#line 2990 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("bayesian_irf", "1"); }
#line 4982 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1486:
#line 2992 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("dsge_var", (yystack_[0].value.string_val)); }
#line 4988 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1487:
#line 2994 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("dsge_var", "Inf"); }
#line 4994 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1488:
#line 2996 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("dsge_var", "NaN"); }
#line 5000 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1489:
#line 2998 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("dsge_varlag", (yystack_[0].value.string_val)); }
#line 5006 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1490:
#line 2999 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("TeX", "1"); }
#line 5012 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1491:
#line 3000 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("forecast", (yystack_[0].value.string_val)); }
#line 5018 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1492:
#line 3001 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("smoother", "1"); }
#line 5024 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1493:
#line 3002 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("moments_varendo", "1"); }
#line 5030 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1494:
#line 3003 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("contemporaneous_correlation", "1"); }
#line 5036 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1495:
#line 3004 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("filtered_vars", "1"); }
#line 5042 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1496:
#line 3005 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("relative_irf", "1"); }
#line 5048 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1497:
#line 3006 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("fast_kalman_filter", "1"); }
#line 5054 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1498:
#line 3007 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("kalman_algo", (yystack_[0].value.string_val)); }
#line 5060 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1499:
#line 3008 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("kalman_tol", (yystack_[0].value.string_val)); }
#line 5066 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1500:
#line 3009 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("diffuse_kalman_tol", (yystack_[0].value.string_val)); }
#line 5072 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1501:
#line 3011 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("mc_marginal_density", "laplace"); }
#line 5078 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1502:
#line 3013 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("mc_marginal_density", "modifiedharmonicmean"); }
#line 5084 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1503:
#line 3015 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("noprint", "0"); }
#line 5090 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1504:
#line 3016 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("noprint", "1"); }
#line 5096 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1505:
#line 3017 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("xls_sheet", (yystack_[0].value.string_val)); }
#line 5102 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1506:
#line 3018 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("xls_range", (yystack_[0].value.string_val)); }
#line 5108 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1507:
#line 3019 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_vec_int("filter_step_ahead", (yystack_[0].value.vector_int_val)); }
#line 5114 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1508:
#line 3020 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_vec_int("convergence.geweke.taper_steps", (yystack_[0].value.vector_int_val)); }
#line 5120 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1509:
#line 3021 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("convergence.geweke.geweke_interval",(yystack_[0].value.string_val)); }
#line 5126 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1510:
#line 3022 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("convergence.rafterylewis.indicator", "1"); }
#line 5132 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1511:
#line 3023 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("convergence.rafterylewis.qrs",(yystack_[0].value.string_val)); }
#line 5138 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1512:
#line 3024 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("noconstant", "0"); }
#line 5144 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1513:
#line 3025 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("noconstant", "1"); }
#line 5150 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1514:
#line 3026 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("mh_recover", "1"); }
#line 5156 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1515:
#line 3027 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("diffuse_filter", "1"); }
#line 5162 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1516:
#line 3028 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("plot_priors", (yystack_[0].value.string_val)); }
#line 5168 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1517:
#line 3029 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("aim_solver", "1"); }
#line 5174 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1518:
#line 3030 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("partial_information", "1"); }
#line 5180 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1519:
#line 3031 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("sub_draws",(yystack_[0].value.string_val));}
#line 5186 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1520:
#line 3032 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.declare_optimal_policy_discount_factor_parameter((yystack_[0].value.node_val)); }
#line 5192 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1521:
#line 3033 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("sylvester_fp", "1"); }
#line 5198 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1522:
#line 3034 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("sylvester_fp", "0"); }
#line 5204 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1523:
#line 3035 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("sylvester_fixed_point_tol",(yystack_[0].value.string_val));}
#line 5210 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1524:
#line 3036 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("lyapunov_fp", "1"); }
#line 5216 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1525:
#line 3037 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("lyapunov_db", "1"); }
#line 5222 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1526:
#line 3038 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("lyapunov_srs", "1"); }
#line 5228 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1527:
#line 3039 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("lyapunov_fp", "0");driver.option_num("lyapunov_db", "0"); driver.option_num("lyapunov_srs", "0");}
#line 5234 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1528:
#line 3040 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("lyapunov_fixed_point_tol",(yystack_[0].value.string_val));}
#line 5240 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1529:
#line 3041 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("lyapunov_doubling_tol",(yystack_[0].value.string_val));}
#line 5246 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1530:
#line 3042 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("dr_cycle_reduction", "1"); }
#line 5252 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1531:
#line 3043 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("dr_logarithmic_reduction", "1"); }
#line 5258 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1532:
#line 3044 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("dr_cycle_reduction", "0"); driver.option_num("dr_logarithmic_reduction", "0");}
#line 5264 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1533:
#line 3045 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("dr_cycle_reduction_tol",(yystack_[0].value.string_val));}
#line 5270 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1534:
#line 3046 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("dr_logarithmic_reduction_tol",(yystack_[0].value.string_val));}
#line 5276 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1535:
#line 3047 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("dr_logarithmic_reduction_maxiter",(yystack_[0].value.string_val));}
#line 5282 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1536:
#line 3048 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("plot_shock_decomp.detail_plot", "1"); }
#line 5288 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1537:
#line 3049 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("initial_condition_decomp.detail_plot", "1"); }
#line 5294 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1538:
#line 3050 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("plot_shock_decomp.interactive", "1"); }
#line 5300 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1539:
#line 3051 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("plot_shock_decomp.screen_shocks", "1"); }
#line 5306 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1540:
#line 3052 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("plot_shock_decomp.steadystate", "1"); }
#line 5312 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1541:
#line 3053 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("initial_condition_decomp.steadystate", "1"); }
#line 5318 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1542:
#line 3054 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("plot_shock_decomp.fig_name", (yystack_[0].value.string_val)); }
#line 5324 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1543:
#line 3056 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("plot_shock_decomp.type", "qoq"); }
#line 5330 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1544:
#line 3058 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("plot_shock_decomp.type", "yoy"); }
#line 5336 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1545:
#line 3060 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("plot_shock_decomp.type", "aoa"); }
#line 5342 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1546:
#line 3063 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("initial_condition_decomp.type", "qoq"); }
#line 5348 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1547:
#line 3065 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("initial_condition_decomp.type", "yoy"); }
#line 5354 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1548:
#line 3067 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("initial_condition_decomp.type", "aoa"); }
#line 5360 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1549:
#line 3069 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_date("initial_condition_decomp.plot_init_date", (yystack_[0].value.string_val)); }
#line 5366 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1550:
#line 3070 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_date("initial_condition_decomp.plot_end_date", (yystack_[0].value.string_val)); }
#line 5372 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1551:
#line 3071 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_date("plot_shock_decomp.plot_init_date", (yystack_[0].value.string_val)); }
#line 5378 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1552:
#line 3072 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_date("plot_shock_decomp.plot_end_date", (yystack_[0].value.string_val)); }
#line 5384 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1553:
#line 3073 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("initial_condition_decomp.write_xls", "1"); }
#line 5390 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1554:
#line 3074 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("plot_shock_decomp.write_xls", "1"); }
#line 5396 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1555:
#line 3075 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("plot_shock_decomp.realtime", (yystack_[0].value.string_val)); }
#line 5402 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1556:
#line 3076 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("plot_shock_decomp.vintage", (yystack_[0].value.string_val)); }
#line 5408 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1557:
#line 3077 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("bvar_prior_tau", (yystack_[0].value.string_val)); }
#line 5414 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1558:
#line 3078 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("bvar_prior_decay", (yystack_[0].value.string_val)); }
#line 5420 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1559:
#line 3079 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("bvar_prior_lambda", (yystack_[0].value.string_val)); }
#line 5426 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1560:
#line 3080 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("bvar_prior_mu", (yystack_[0].value.string_val)); }
#line 5432 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1561:
#line 3081 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("bvar_prior_omega", (yystack_[0].value.string_val)); }
#line 5438 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1562:
#line 3082 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("bvar_prior_flat", "1"); }
#line 5444 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1563:
#line 3083 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("bvar_prior_train", (yystack_[0].value.string_val)); }
#line 5450 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1564:
#line 3084 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("bvar_replic", (yystack_[0].value.string_val)); }
#line 5456 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1565:
#line 3086 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("particle.number_of_particles", (yystack_[0].value.string_val)); }
#line 5462 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1567:
#line 3088 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("particle.resampling.status.systematic", "0"); driver.option_num("particle.resampling.status.none", "1"); }
#line 5468 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1568:
#line 3089 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("particle.resampling.status.systematic", "0"); driver.option_num("particle.resampling.status.generic", "1"); }
#line 5474 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1569:
#line 3090 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("particle.resampling.threshold", (yystack_[0].value.string_val)); }
#line 5480 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1570:
#line 3091 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("particle.resampling.method.kitagawa", "1"); driver.option_num("particle.resampling.method.smooth", "0"); driver.option_num("particle.resampling.smethod.stratified", "0"); }
#line 5486 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1571:
#line 3092 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("particle.resampling.method.kitagawa", "0"); driver.option_num("particle.resampling.method.smooth", "1"); driver.option_num("particle.resampling.smethod.stratified", "0"); }
#line 5492 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1572:
#line 3093 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("particle.resampling.method.kitagawa", "0"); driver.option_num("particle.resampling.method.smooth", "0"); driver.option_num("particle.resampling.method.stratified", "1"); }
#line 5498 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1573:
#line 3094 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("particle.cpf_weights_method.amisanotristani", "1"); driver.option_num("particle.cpf_weights_method.murrayjonesparslow", "0"); }
#line 5504 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1574:
#line 3095 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("particle.cpf_weights_method.amisanotristani", "0"); driver.option_num("particle.cpf_weights_method.murrayjonesparslow", "1"); }
#line 5510 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1575:
#line 3096 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("particle.filter_algorithm", (yystack_[0].value.string_val)); }
#line 5516 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1576:
#line 3097 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("particle.initialization", (yystack_[0].value.string_val)); }
#line 5522 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1577:
#line 3098 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("particle.proposal_approximation.cubature", "1"); driver.option_num("particle.proposal_approximation.unscented", "0"); driver.option_num("particle.proposal_approximation.montecarlo", "0");}
#line 5528 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1578:
#line 3099 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("particle.proposal_approximation.cubature", "0"); driver.option_num("particle.proposal_approximation.unscented", "1"); driver.option_num("particle.proposal_approximation.montecarlo", "0");}
#line 5534 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1579:
#line 3100 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("particle.proposal_approximation.cubature", "0"); driver.option_num("particle.proposal_approximation.unscented", "0"); driver.option_num("particle.proposal_approximation.montecarlo", "1");}
#line 5540 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1580:
#line 3101 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("particle.distribution_approximation.cubature", "1"); driver.option_num("particle.distribution_approximation.unscented", "0"); driver.option_num("particle.distribution_approximation.montecarlo", "0");}
#line 5546 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1581:
#line 3102 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("particle.distribution_approximation.cubature", "0"); driver.option_num("particle.distribution_approximation.unscented", "1"); driver.option_num("particle.distribution_approximation.montecarlo", "0");}
#line 5552 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1582:
#line 3103 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("particle.distribution_approximation.cubature", "0"); driver.option_num("particle.distribution_approximation.unscented", "0"); driver.option_num("particle.distribution_approximation.montecarlo", "1");}
#line 5558 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1583:
#line 3106 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("identification", (yystack_[0].value.string_val)); }
#line 5564 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1584:
#line 3107 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("morris", (yystack_[0].value.string_val)); }
#line 5570 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1585:
#line 3108 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("stab", (yystack_[0].value.string_val)); }
#line 5576 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1586:
#line 3109 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("redform", (yystack_[0].value.string_val)); }
#line 5582 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1587:
#line 3110 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("pprior", (yystack_[0].value.string_val)); }
#line 5588 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1588:
#line 3111 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("prior_range", (yystack_[0].value.string_val)); }
#line 5594 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1589:
#line 3112 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ppost", (yystack_[0].value.string_val)); }
#line 5600 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1590:
#line 3113 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ilptau", (yystack_[0].value.string_val)); }
#line 5606 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1591:
#line 3114 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("morris_nliv", (yystack_[0].value.string_val)); }
#line 5612 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1592:
#line 3115 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("morris_ntra", (yystack_[0].value.string_val)); }
#line 5618 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1593:
#line 3116 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("Nsam", (yystack_[0].value.string_val)); }
#line 5624 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1594:
#line 3117 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("load_redform", (yystack_[0].value.string_val)); }
#line 5630 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1595:
#line 3118 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("load_rmse", (yystack_[0].value.string_val)); }
#line 5636 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1596:
#line 3119 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("load_stab", (yystack_[0].value.string_val)); }
#line 5642 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1597:
#line 3120 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("alpha2_stab", (yystack_[0].value.string_val)); }
#line 5648 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1598:
#line 3121 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("logtrans_redform", (yystack_[0].value.string_val)); }
#line 5654 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1599:
#line 3122 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("threshold_redform",(yystack_[0].value.string_val)); }
#line 5660 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1600:
#line 3123 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ksstat_redform", (yystack_[0].value.string_val)); }
#line 5666 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1601:
#line 3124 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("alpha2_redform", (yystack_[0].value.string_val)); }
#line 5672 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1602:
#line 3125 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_symbol_list("namendo"); }
#line 5678 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1603:
#line 3126 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_symbol_list("namlagendo"); }
#line 5684 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1604:
#line 3127 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_symbol_list("namexo"); }
#line 5690 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1605:
#line 3128 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("rmse", (yystack_[0].value.string_val)); }
#line 5696 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1606:
#line 3129 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("lik_only", (yystack_[0].value.string_val)); }
#line 5702 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1607:
#line 3130 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_symbol_list("var_rmse"); }
#line 5708 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1608:
#line 3131 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("pfilt_rmse", (yystack_[0].value.string_val)); }
#line 5714 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1609:
#line 3132 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("istart_rmse", (yystack_[0].value.string_val)); }
#line 5720 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1610:
#line 3133 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("alpha_rmse", (yystack_[0].value.string_val)); }
#line 5726 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1611:
#line 3134 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("alpha2_rmse", (yystack_[0].value.string_val)); }
#line 5732 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1612:
#line 3136 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("gsa_sample_file", (yystack_[0].value.string_val)); }
#line 5738 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1613:
#line 3138 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("gsa_sample_file", (yystack_[0].value.string_val)); }
#line 5744 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1614:
#line 3140 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("neighborhood_width", (yystack_[0].value.string_val)); }
#line 5750 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1615:
#line 3141 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("pvalue_ks", (yystack_[0].value.string_val)); }
#line 5756 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1616:
#line 3142 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("pvalue_corr", (yystack_[0].value.string_val)); }
#line 5762 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1617:
#line 3143 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("load_ident_files", (yystack_[0].value.string_val)); }
#line 5768 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1618:
#line 3144 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("useautocorr", (yystack_[0].value.string_val)); }
#line 5774 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1619:
#line 3145 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("prior_mc", (yystack_[0].value.string_val)); }
#line 5780 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1620:
#line 3146 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("advanced", (yystack_[0].value.string_val)); }
#line 5786 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1621:
#line 3147 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("max_dim_cova_group", (yystack_[0].value.string_val)); }
#line 5792 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1622:
#line 3149 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("homotopy_mode",(yystack_[0].value.string_val)); }
#line 5798 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1623:
#line 3150 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("homotopy_steps",(yystack_[0].value.string_val)); }
#line 5804 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1624:
#line 3151 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("homotopy_force_continue",(yystack_[0].value.string_val)); }
#line 5810 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1625:
#line 3152 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("steadystate.nocheck","1"); }
#line 5816 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1626:
#line 3154 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_symbol_list("controlled_varexo"); }
#line 5822 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1627:
#line 3156 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("parameter_set", "prior_mode"); }
#line 5828 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1628:
#line 3158 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("parameter_set", "prior_mean"); }
#line 5834 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1629:
#line 3160 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("parameter_set", "posterior_mean"); }
#line 5840 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1630:
#line 3162 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("parameter_set", "posterior_mode"); }
#line 5846 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1631:
#line 3164 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("parameter_set", "posterior_median"); }
#line 5852 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1632:
#line 3166 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("parameter_set", "mle_mode"); }
#line 5858 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1633:
#line 3168 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("parameter_set", "calibration"); }
#line 5864 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1634:
#line 3170 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("nodecomposition", "1"); }
#line 5870 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1635:
#line 3171 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("SpectralDensity.trigger", "1"); }
#line 5876 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1636:
#line 3172 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.drop", (yystack_[0].value.string_val)); }
#line 5882 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1637:
#line 3173 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.mh_replic", (yystack_[0].value.string_val)); }
#line 5888 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1638:
#line 3175 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.freq",(yystack_[0].value.string_val)); }
#line 5894 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1639:
#line 3177 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.freq","12"); }
#line 5900 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1640:
#line 3179 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.freq","4"); }
#line 5906 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1641:
#line 3181 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.initial_year",(yystack_[0].value.string_val)); }
#line 5912 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1642:
#line 3182 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.initial_subperiod",(yystack_[0].value.string_val)); }
#line 5918 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1643:
#line 3183 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.final_year",(yystack_[0].value.string_val)); }
#line 5924 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1644:
#line 3184 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.final_subperiod",(yystack_[0].value.string_val)); }
#line 5930 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1645:
#line 3185 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("ms.data", (yystack_[0].value.string_val)); }
#line 5936 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1646:
#line 3186 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.vlist",(yystack_[0].value.string_val)); }
#line 5942 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1647:
#line 3187 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_symbol_list("ms.vlistlog"); }
#line 5948 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1648:
#line 3188 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.vlistper",(yystack_[0].value.string_val)); }
#line 5954 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1649:
#line 3190 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                        driver.warning("restriction_fname is now deprecated, and may be removed in a future version of Dynare. Use svar_identification instead.");
                        driver.option_str("ms.restriction_fname",(yystack_[0].value.string_val));
                      }
#line 5963 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1650:
#line 3195 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                        driver.warning("restriction_fname is now deprecated, and may be removed in a future version of Dynare. Use svar_identification instead.");
                        driver.option_str("ms.restriction_fname","upper_cholesky");
                      }
#line 5972 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1651:
#line 3200 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                        driver.warning("restriction_fname is now deprecated, and may be removed in a future version of Dynare. Use svar_identification instead.");
                        driver.option_str("ms.restriction_fname","lower_cholesky");
                      }
#line 5981 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1652:
#line 3205 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.nlags",(yystack_[0].value.string_val)); }
#line 5987 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1653:
#line 3206 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.cross_restrictions","1"); }
#line 5993 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1654:
#line 3207 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.contemp_reduced_form","1"); }
#line 5999 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1655:
#line 3208 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.real_pseudo_forecast",(yystack_[0].value.string_val)); }
#line 6005 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1656:
#line 3209 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.bayesian_prior","0"); }
#line 6011 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1657:
#line 3210 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.dummy_obs",(yystack_[0].value.string_val)); }
#line 6017 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1658:
#line 3211 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.nstates",(yystack_[0].value.string_val)); }
#line 6023 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1659:
#line 3212 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.indxscalesstates",(yystack_[0].value.string_val)); }
#line 6029 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1660:
#line 3213 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.alpha",(yystack_[0].value.string_val)); }
#line 6035 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1661:
#line 3214 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.beta",(yystack_[0].value.string_val)); }
#line 6041 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1662:
#line 3215 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.gsig2_lmdm",(yystack_[0].value.string_val)); }
#line 6047 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1663:
#line 3217 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.specification","1"); }
#line 6053 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1664:
#line 3219 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.specification","0"); }
#line 6059 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1665:
#line 3221 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.q_diag",(yystack_[0].value.string_val)); }
#line 6065 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1666:
#line 3222 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.flat_prior",(yystack_[0].value.string_val)); }
#line 6071 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1667:
#line 3223 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.ncsk",(yystack_[0].value.string_val)); }
#line 6077 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1668:
#line 3224 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.nstd",(yystack_[0].value.string_val)); }
#line 6083 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1669:
#line 3225 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.ninv",(yystack_[0].value.string_val)); }
#line 6089 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1670:
#line 3226 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.indxparr",(yystack_[0].value.string_val)); }
#line 6095 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1671:
#line 3227 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.indxovr",(yystack_[0].value.string_val)); }
#line 6101 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1672:
#line 3228 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.aband",(yystack_[0].value.string_val)); }
#line 6107 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1673:
#line 3229 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.indxap",(yystack_[0].value.string_val)); }
#line 6113 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1674:
#line 3230 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.apband",(yystack_[0].value.string_val)); }
#line 6119 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1675:
#line 3231 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.indximf",(yystack_[0].value.string_val)); }
#line 6125 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1676:
#line 3232 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.indxfore",(yystack_[0].value.string_val)); }
#line 6131 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1677:
#line 3233 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.foreband",(yystack_[0].value.string_val)); }
#line 6137 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1678:
#line 3234 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.indxgforehat",(yystack_[0].value.string_val)); }
#line 6143 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1679:
#line 3235 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.indxgimfhat",(yystack_[0].value.string_val)); }
#line 6149 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1680:
#line 3236 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.indxestima",(yystack_[0].value.string_val)); }
#line 6155 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1681:
#line 3237 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.indxgdls",(yystack_[0].value.string_val)); }
#line 6161 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1682:
#line 3238 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.eq_ms",(yystack_[0].value.string_val)); }
#line 6167 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1683:
#line 3239 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.cms",(yystack_[0].value.string_val)); }
#line 6173 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1684:
#line 3240 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.ncms",(yystack_[0].value.string_val)); }
#line 6179 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1685:
#line 3241 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.eq_cms",(yystack_[0].value.string_val)); }
#line 6185 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1686:
#line 3242 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.tlindx",(yystack_[0].value.string_val)); }
#line 6191 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1687:
#line 3243 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.tlnumber",(yystack_[0].value.string_val)); }
#line 6197 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1688:
#line 3244 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("ms.cnum",(yystack_[0].value.string_val)); }
#line 6203 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1689:
#line 3245 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("k_order_solver","1"); }
#line 6209 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1690:
#line 3246 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("pruning", "1"); }
#line 6215 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1691:
#line 3247 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.chain",(yystack_[0].value.string_val)); }
#line 6221 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1692:
#line 3249 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.restrictions",(yystack_[0].value.string_val)); }
#line 6227 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1693:
#line 3252 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.duration",(yystack_[0].value.string_val)); }
#line 6233 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1694:
#line 3254 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.duration",(yystack_[0].value.string_val)); }
#line 6239 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1695:
#line 3256 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.number_of_regimes",(yystack_[0].value.string_val)); }
#line 6245 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1696:
#line 3257 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.number_of_lags",(yystack_[0].value.string_val)); }
#line 6251 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1697:
#line 3258 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_symbol_list("ms.parameters"); }
#line 6257 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1698:
#line 3259 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("ms.coefficients","svar_coefficients"); }
#line 6263 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1699:
#line 3260 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("ms.variances","svar_variances"); }
#line 6269 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1700:
#line 3262 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_vec_int("ms.equations",(yystack_[0].value.vector_int_val)); }
#line 6275 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1701:
#line 3264 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_vec_int("ms.equations",(yystack_[0].value.vector_int_val)); }
#line 6281 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1702:
#line 3266 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("silent_optimizer", "1"); }
#line 6287 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1703:
#line 3267 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_symbol_list("instruments"); }
#line 6293 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1704:
#line 3269 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.external_function_option("name", (yystack_[0].value.string_val)); }
#line 6299 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1705:
#line 3270 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.external_function_option("nargs",(yystack_[0].value.string_val)); }
#line 6305 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1706:
#line 3272 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.external_function_option("first_deriv_provided", (yystack_[0].value.string_val)); }
#line 6311 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1707:
#line 3274 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.external_function_option("first_deriv_provided", ""); }
#line 6317 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1708:
#line 3277 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.external_function_option("second_deriv_provided", (yystack_[0].value.string_val)); }
#line 6323 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1709:
#line 3279 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.external_function_option("second_deriv_provided", ""); }
#line 6329 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1710:
#line 3282 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("filter_covariance","1");}
#line 6335 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1711:
#line 3285 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("filter_decomposition","1");}
#line 6341 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1712:
#line 3288 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("smoothed_state_uncertainty","1");}
#line 6347 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1713:
#line 3291 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("selected_variables_only","1");}
#line 6353 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1714:
#line 3294 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("cova_compute",(yystack_[0].value.string_val));}
#line 6359 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1715:
#line 3296 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_str("ms.output_file_tag", (yystack_[0].value.string_val)); }
#line 6365 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1716:
#line 3297 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("ms.file_tag", (yystack_[0].value.string_val)); }
#line 6371 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1717:
#line 3298 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.create_init", "0"); }
#line 6377 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1718:
#line 3299 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("ms.simulation_file_tag", (yystack_[0].value.string_val)); }
#line 6383 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1719:
#line 3301 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.coefficients_prior_hyperparameters",(yystack_[0].value.string_val)); }
#line 6389 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1720:
#line 3303 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.convergence_starting_value",(yystack_[0].value.string_val)); }
#line 6395 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1721:
#line 3305 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.convergence_ending_value",(yystack_[0].value.string_val)); }
#line 6401 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1722:
#line 3307 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.convergence_increment_value",(yystack_[0].value.string_val)); }
#line 6407 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1723:
#line 3309 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.max_iterations_starting_value",(yystack_[0].value.string_val)); }
#line 6413 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1724:
#line 3311 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.max_iterations_increment_value",(yystack_[0].value.string_val)); }
#line 6419 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1725:
#line 3313 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.max_block_iterations",(yystack_[0].value.string_val)); }
#line 6425 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1726:
#line 3315 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.max_repeated_optimization_runs",(yystack_[0].value.string_val)); }
#line 6431 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1727:
#line 3317 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.function_convergence_criterion",(yystack_[0].value.string_val)); }
#line 6437 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1728:
#line 3319 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.parameter_convergence_criterion",(yystack_[0].value.string_val)); }
#line 6443 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1729:
#line 3321 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.number_of_large_perturbations",(yystack_[0].value.string_val)); }
#line 6449 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1730:
#line 3323 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.number_of_small_perturbations",(yystack_[0].value.string_val)); }
#line 6455 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1731:
#line 3325 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.number_of_posterior_draws_after_perturbation",(yystack_[0].value.string_val)); }
#line 6461 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1732:
#line 3327 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.max_number_of_stages",(yystack_[0].value.string_val)); }
#line 6467 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1733:
#line 3329 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.random_function_convergence_criterion",(yystack_[0].value.string_val)); }
#line 6473 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1734:
#line 3331 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.random_parameter_convergence_criterion",(yystack_[0].value.string_val)); }
#line 6479 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1735:
#line 3332 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.thinning_factor",(yystack_[0].value.string_val)); }
#line 6485 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1736:
#line 3333 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.adaptive_mh_draws",(yystack_[0].value.string_val)); }
#line 6491 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1737:
#line 3334 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.save_draws","1"); }
#line 6497 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1738:
#line 3335 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.proposal_draws",(yystack_[0].value.string_val)); }
#line 6503 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1739:
#line 3336 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.use_mean_center","1"); }
#line 6509 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1740:
#line 3337 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.proposal_type",(yystack_[0].value.string_val)); }
#line 6515 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1741:
#line 3338 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.proposal_lower_bound",(yystack_[0].value.string_val)); }
#line 6521 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1742:
#line 3339 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.proposal_upper_bound",(yystack_[0].value.string_val)); }
#line 6527 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1743:
#line 3340 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.parameter_uncertainty","1"); }
#line 6533 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1744:
#line 3341 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.horizon",(yystack_[0].value.string_val)); }
#line 6539 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1745:
#line 3342 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.filtered_probabilities","1"); }
#line 6545 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1746:
#line 3343 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.real_time_smoothed_probabilities","1"); }
#line 6551 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1747:
#line 3344 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.error_bands","0"); }
#line 6557 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1748:
#line 3345 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.percentiles",(yystack_[0].value.string_val)); }
#line 6563 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1749:
#line 3346 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.shock_draws",(yystack_[0].value.string_val)); }
#line 6569 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1750:
#line 3347 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.shocks_per_parameter",(yystack_[0].value.string_val)); }
#line 6575 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1751:
#line 3348 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.free_parameters",(yystack_[0].value.string_val)); }
#line 6581 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1752:
#line 3349 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.median","1"); }
#line 6587 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1753:
#line 3350 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("median", (yystack_[0].value.string_val)); }
#line 6593 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1754:
#line 3351 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.regimes","1"); }
#line 6599 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1755:
#line 3352 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.regime",(yystack_[0].value.string_val)); }
#line 6605 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1756:
#line 3353 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("ms.forecast_data_obs",(yystack_[0].value.string_val)); }
#line 6611 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1757:
#line 3354 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("discretionary_tol",(yystack_[0].value.string_val)); }
#line 6617 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1758:
#line 3355 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("analytic_derivation", "1"); }
#line 6623 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1759:
#line 3356 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("analytic_derivation_mode", (yystack_[0].value.string_val)); }
#line 6629 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1760:
#line 3357 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("endogenous_prior", "1"); }
#line 6635 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1761:
#line 3358 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("use_univariate_filters_if_singularity_is_detected", (yystack_[0].value.string_val)); }
#line 6641 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1762:
#line 3360 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("MCMC_jumping_covariance", (yystack_[0].value.string_val)); }
#line 6647 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1763:
#line 3361 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("MCMC_jumping_covariance", (yystack_[0].value.string_val)); }
#line 6653 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1764:
#line 3363 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("MCMC_jumping_covariance", (yystack_[0].value.string_val)); }
#line 6659 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1765:
#line 3365 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("MCMC_jumping_covariance", (yystack_[0].value.string_val)); }
#line 6665 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1766:
#line 3367 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("rescale_prediction_error_covariance", "true"); }
#line 6671 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1767:
#line 3368 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("hessian.use_penalized_objective","true"); }
#line 6677 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1768:
#line 3369 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("impulse_responses.plot_threshold", (yystack_[0].value.string_val)); }
#line 6683 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1769:
#line 3370 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("dr_display_tol", (yystack_[0].value.string_val)); }
#line 6689 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1770:
#line 3371 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("endo_vars_for_moment_computations_in_estimation", "all_endogenous_variables"); }
#line 6695 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1771:
#line 3372 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("endo_vars_for_moment_computations_in_estimation", "only_observed_variables"); }
#line 6701 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1772:
#line 3373 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("no_homotopy", "1"); }
#line 6707 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1773:
#line 3375 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("infile", (yystack_[0].value.string_val)); }
#line 6713 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1774:
#line 3376 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_symbol_list("invars"); }
#line 6719 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1775:
#line 3377 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("period", (yystack_[0].value.string_val)); }
#line 6725 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1776:
#line 3378 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("outfile", (yystack_[0].value.string_val)); }
#line 6731 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1777:
#line 3379 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_symbol_list("outvars"); }
#line 6737 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1778:
#line 3380 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {driver.option_num("lmmcp.status", "1"); }
#line 6743 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1779:
#line 3381 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("function", (yystack_[0].value.string_val)); }
#line 6749 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1780:
#line 3382 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("sampling_draws",(yystack_[0].value.string_val)); }
#line 6755 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1781:
#line 3383 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("plot_shock_decomp.use_shock_groups","default"); }
#line 6761 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1782:
#line 3384 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_str("plot_shock_decomp.use_shock_groups", (yystack_[0].value.string_val)); }
#line 6767 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1783:
#line 3386 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { driver.option_num("plot_shock_decomp.colormap",(yystack_[0].value.string_val)); }
#line 6773 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1784:
#line 3389 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
          (yystack_[2].value.string_val)->append(":");
          (yystack_[2].value.string_val)->append(*(yystack_[0].value.string_val));
          delete (yystack_[0].value.string_val);
          (yylhs.value.string_val) = (yystack_[2].value.string_val);
        }
#line 6784 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1785:
#line 3397 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                  (yystack_[2].value.string_val)->append(":");
                  (yystack_[2].value.string_val)->append(*(yystack_[0].value.string_val));
                  delete (yystack_[0].value.string_val);
                  (yylhs.value.string_val) = (yystack_[2].value.string_val);
                }
#line 6795 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1786:
#line 3405 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                         (yystack_[2].value.string_val)->append(":");
                         (yystack_[2].value.string_val)->append(*(yystack_[0].value.string_val));
                         delete (yystack_[0].value.string_val);
                         (yylhs.value.string_val) = (yystack_[2].value.string_val);
                       }
#line 6806 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1787:
#line 3412 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                         (yystack_[3].value.string_val)->insert(0, "-(");
                         (yystack_[3].value.string_val)->append(":");
                         (yystack_[3].value.string_val)->append(*(yystack_[1].value.string_val));
                         delete (yystack_[1].value.string_val);
                         (yystack_[3].value.string_val)->append(")");
                         (yylhs.value.string_val) = (yystack_[3].value.string_val);
                       }
#line 6819 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1788:
#line 3421 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.vector_int_val) = new vector<int>(); (yylhs.value.vector_int_val)->push_back(atoi((*(yystack_[0].value.string_val)).c_str())); delete (yystack_[0].value.string_val); }
#line 6825 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1790:
#line 3425 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                 (yylhs.value.vector_int_val) = new vector<int>();
                 for(int i=atoi((*(yystack_[2].value.string_val)).c_str()); i<=atoi((*(yystack_[0].value.string_val)).c_str()); i++)
                   (yylhs.value.vector_int_val)->push_back(i);
                 delete (yystack_[2].value.string_val);
                 delete (yystack_[0].value.string_val);
               }
#line 6837 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1791:
#line 3435 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.vector_int_val) = (yystack_[0].value.vector_int_val);}
#line 6843 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1792:
#line 3437 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.vector_int_val) = (yystack_[0].value.vector_int_val);}
#line 6849 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1793:
#line 3439 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
              (yylhs.value.vector_int_val) = (yystack_[1].value.vector_int_val);
              for (vector<int>::const_iterator it=(yystack_[0].value.vector_int_val)->begin();
                   it!=(yystack_[0].value.vector_int_val)->end(); it++)
                (yystack_[1].value.vector_int_val)->push_back(*it);
              delete (yystack_[0].value.vector_int_val);
            }
#line 6861 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1794:
#line 3447 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
              (yylhs.value.vector_int_val) = (yystack_[2].value.vector_int_val);
              for (vector<int>::const_iterator it=(yystack_[0].value.vector_int_val)->begin();
                   it!=(yystack_[0].value.vector_int_val)->end(); it++)
                (yystack_[2].value.vector_int_val)->push_back(*it);
              delete (yystack_[0].value.vector_int_val);
            }
#line 6873 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1795:
#line 3457 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.vector_int_val) = (yystack_[1].value.vector_int_val); }
#line 6879 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1796:
#line 3459 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.vector_int_val) = (yystack_[2].value.vector_int_val); }
#line 6885 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1797:
#line 3462 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yystack_[0].value.string_val)->insert(0,"["); (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 6891 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1798:
#line 3463 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yystack_[0].value.string_val)->insert(0,"["); (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 6897 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1799:
#line 3465 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                (yystack_[1].value.string_val)->append(" ");
                (yystack_[1].value.string_val)->append(*(yystack_[0].value.string_val));
                delete (yystack_[0].value.string_val);
                (yylhs.value.string_val) = (yystack_[1].value.string_val);
              }
#line 6908 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1800:
#line 3472 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                (yystack_[2].value.string_val)->append(" ");
                (yystack_[2].value.string_val)->append(*(yystack_[0].value.string_val));
                delete (yystack_[0].value.string_val);
                (yylhs.value.string_val) = (yystack_[2].value.string_val);
              }
#line 6919 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1801:
#line 3480 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yystack_[1].value.string_val)->append("]"); (yylhs.value.string_val) = (yystack_[1].value.string_val); }
#line 6925 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1802:
#line 3481 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yystack_[2].value.string_val)->append("]"); (yylhs.value.string_val) = (yystack_[2].value.string_val); }
#line 6931 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1803:
#line 3485 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                   (yystack_[2].value.string_val)->append(",");
                   (yystack_[2].value.string_val)->append(*(yystack_[0].value.string_val));
                   delete (yystack_[0].value.string_val);
                   (yylhs.value.string_val) = (yystack_[2].value.string_val);
                 }
#line 6942 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1804:
#line 3492 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 6948 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1805:
#line 3495 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.string_val) = (yystack_[1].value.string_val); }
#line 6954 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1806:
#line 3496 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yylhs.value.string_val) = (yystack_[0].value.string_val); }
#line 6960 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1807:
#line 3499 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yystack_[0].value.string_val)->insert(0, "["); (yylhs.value.string_val) = (yystack_[0].value.string_val);}
#line 6966 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1808:
#line 3501 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    {
                      (yystack_[1].value.string_val)->append(" ");
                      (yystack_[1].value.string_val)->append(*(yystack_[0].value.string_val));
                      delete (yystack_[0].value.string_val);
                      (yylhs.value.string_val) = (yystack_[1].value.string_val);
                    }
#line 6977 "DynareBison.cc" // lalr1.cc:859
    break;

  case 1809:
#line 3509 "lex_yacc/DynareBison.yy" // lalr1.cc:859
    { (yystack_[1].value.string_val)->append("]"); (yylhs.value.string_val) = (yystack_[1].value.string_val); }
#line 6983 "DynareBison.cc" // lalr1.cc:859
    break;


#line 6987 "DynareBison.cc" // lalr1.cc:859
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


  const short int parser::yypact_ninf_ = -2964;

  const short int parser::yytable_ninf_ = -1830;

  const short int
  parser::yypact_[] =
  {
    5329,    99,   108,  6677,  -259,  -196,  -234,  -185,  -220,  7607,
     236,  -139,  -129,   231,  7642,  -182,  -126,   317,   351,  -124,
    -120,  7662,  -105,   374,   -97,  -102,   382,   390,   -87,   405,
     -85,   -60,   471,  7686,   485,   498,   -99,   -89, -2964,   -56,
     227,  7746,  6578,  6578,   282, -2964,  8058,   515,   569,  6578,
     -15,   629,  7801,   689,   745,   691,   720,   249,   723,  7845,
    7900,  7940,  7959,   283,  7984,  6578,  8098,  6578,  6578, -2964,
    6578,  8003,   744,   290,   293,   751,   257, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964,   765,   280,  8039,   781,
     827,   832,   840,   842,   887, -2964,   287,   295,   298,   312,
     327,   334,   325,  4857, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,   143, -2964,
   -2964,   833, -2964, -2964,   852, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964,   140,   345,   954,   349,  2037, -2964,
     626,  8351, -2964,   138, -2964,  1283,   746,   607,  6578, -2964,
    1307,  8380,   141, 11012, 11012,  6578,   909, -2964,  5842,  8408,
     862,  1736,  3516,   937, -2964,   644,   864,  6578, -2964,   780,
    8437,  6578,  6578,   922,   902,  6578, -2964,   791,  6578,   930,
     916,  6578,   701, 11012,   834, -2964,   896, -2964,   839,   426,
    8242, -2964, -2964, -2964,   676,   762, -2964,  6578,  6578,  6578,
   -2964,  7192,  8460,  8489,  8546,    31,   891,   457,  6785,   784,
    8698, -2964,   269, -2964,  2661,  8727, 11012,   212,   786, -2964,
     597,  8746, 11134,   879,   522, -2964,   831, -2964,   281, -2964,
   -2964,  1827, -2964,  7289,  8784, -2964,   182,  8807, -2964,   323,
    8893, -2964,  7693,  8945,   886, -2964,  7480,  9002,  9055,   126,
    9084,    39,  9111,    95,  9141,   109,  6578,  9193, -2964, -2964,
    1310,  9250, -2964,   845, -2964, -2964, -2964,  3500,   306, -2964,
    4060,   545, -2964,   921,  9302, -2964,  1680, -2964,   802, -2964,
     190, -2964,   675, -2964,   -82, -2964,  1941,   476,   447,   -95,
   -2964,   586,     7,     7,   627, -2964, -2964,  2763,  6578,  3980,
    4109,  6816,  6199, -2964,  1044, -2964,  1053,  1061,  1065,  1067,
    1071, -2964,  1084,  1086,  1100, -2964,  1105,  1149,  1169,  1173,
   -2964,   894,   685, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
    1255,  1257,  1266, -2964,   990,   767, -2964, -2964, -2964,  1302,
   -2964,  1313, -2964, -2964, -2964, -2964,   807,  1033, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,  6578, -2964,
   -2964, -2964, -2964, -2964, -2964,   809, -2964,  1316,  1323,  1332,
    1334,  1338,  1343,  1347,  1353, -2964,   119, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964,  1355,  1375,  1377,
    1382,  1385,   130, -2964, -2964, -2964, -2964, -2964, -2964,  6578,
     204, -2964,  1107, -2964, -2964, -2964,  1392,  1398,  1399,   890,
    1120, -2964, -2964, -2964, -2964, -2964, -2964, -2964,   897, -2964,
     892,   899,  3850, -2964,  1405,   903, -2964, -2964,  1407,  1408,
   -2964, -2964, -2964,  1413,  1416,  1418, -2964, -2964,  1423,  1425,
    1426, -2964,  1427,  1430, -2964, -2964,  1433,  1434,  1436,  1438,
    1451, -2964,  1453,  1454,  1455,  1458, -2964, -2964, -2964,  1460,
    1461,  1462,  1463,  1465,  1466,  1467,  1468,  1469,  1470, -2964,
    1473, -2964,  1474,  1475,  1476,  1480,  1482, -2964, -2964,  1483,
    1484,  1486,  1487, -2964,  1488,  1489,  1490,  1491,  1495,  1496,
    1497,  1499,  1500,  1501, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964,  1503,  1505, -2964,  1509, -2964,  1510,  1511,  1513, -2964,
   -2964,  1514,  1515, -2964,  1517,  1524, -2964,  1525, -2964,  1526,
     193, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964,  6578, -2964,  6578,   805, -2964,   -55, -2964,
    6578,  6578,   984, -2964,  1246,  6578,  6578,  2624, -2964,  1249,
    1023, -2964,  1538,  1540, -2964,  1030,  1260, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964,   -66,  4193, -2964,  1263,   209, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964,  1035,  4277, -2964,  1039,
    1042,  1558,  4296, -2964,  1277,  1561,  1568,  1574,  1575,  1579,
    1585,  1589,  1590,  1082,  1336, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964,  4324,  1111,  1623,  4347, -2964,
     112,  1113,  1118,  1630,  5356, -2964, -2964,  1632,  1635, -2964,
    1636, -2964,  1638, -2964, -2964,   220, -2964, -2964, -2964,  1639,
    1130,   268, 11012, -2964,  1133,   420, -2964,  6578, -2964,   270,
    1134,  4380, -2964,  1362,  4618, -2964,  1137,  4639,  5981,  1660,
    1662,  1663,  1672, -2964,  1674,  1677,  1683,  1685, -2964, -2964,
   -2964, -2964, -2964, -2964,  1686,  1687, -2964,  1692,  1693, -2964,
     424, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964,  6578, -2964,   110,  1184, 10972,  5861, -2964,  1190,
   -2964, -2964, -2964,  1203,  1217,  1220,  1226,  6785,  6785,  1228,
    1235,  1236,  1259,  1275,  1280,  1281,  1282,  1287,  1296,  1300,
    1312,  1314,  1315,  1321,  1322,  1327,  6785,  3853, -2964,  1328,
    1700, -2964,   432, -2964, -2964, -2964,  1793,  1841, -2964,  1851,
    1852, -2964, -2964,  1855, -2964,   433, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
    1346,  6578,  6578,   246, -2964, -2964,  1350,  1858, -2964,  1862,
    1864,  1361,  1584, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964,  1873,  1867, -2964,  1874,  1878,   229, -2964, -2964,
     440, -2964,  1880,  1881,  1883,  1884,  1885,  1376,  1604, -2964,
   -2964, -2964, -2964, -2964,  5830,   445, -2964,  1888,  1890, -2964,
     448, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,  1891,
    1893,  1895,  1386,  1617, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964,  1900,  1901,   450, -2964, -2964,
   -2964, -2964, -2964,   456, -2964, -2964, -2964, -2964,   837,   256,
   -2964,  1913,  1916,   462, -2964, -2964, -2964, -2964, -2964, -2964,
    1921,  1922,  6578, -2964,   116,  1184, -2964,  6578, -2964,   163,
    1184, -2964,  6578, -2964,   168,  1184, -2964,  9359, -2964,  6578,
   -2964, -2964,  1925, -2964, -2964, -2964, -2964, -2964,  1928,  1929,
    1931,  1932,  1933,  1934, -2964,  1424,  1642, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964,  1429,  1959,  1973,  1984,  1985,  1990,  1991,
    1997,  2001,  2013,  2014,  2015,  2016,  2017,  2019,  2033,  2034,
    2036,  2038,  2042,  2044,  2045,  2046,  2047,  2051,  2052,  2054,
    2062,  2065,  2066,  2067,  2068,  1559,  1659, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,  2069,  2071,
    2074,  2077,  2078,   464, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964,  2079,  2080,  2081,  2082,  2084,  2085,  2088,  2089,
    2106,  2127, -2964,  2128, -2964,  2129,  2134,  2135,  2136, -2964,
    2138,  2140,  2141,  2143,  2144,  2151,  2155,  2156,  2157,  2158,
    2160,  2161,  2162,  2164,  2165,  2167,  2168,  2172,  2173,  2175,
    2176,  2177,  2178,  2179,  2180,  2181,  2183,  2184,  1903,  1626,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,  2186, -2964,
   -2964,  2189,  2190,  2192,  2198,  2200,  2201,  2203,  2204,  2217,
    2218, -2964,  2221,  1911,  1711, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964,  1942,  1712, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964,  2226, -2964,  2227,
    2228,  2229,  2233,  2234,  2235,  2238,  2259,  2260,  2261,  2262,
    2263,  2265,  2266,  2267,  1986,  1758, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964,  2270,  2271, -2964,  2283,  2004,  1777, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964,  2289,  2290,  2293,  2294, -2964,  2018,
    1785, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
    2020,  1786, -2964, -2964, -2964, -2964,  2299,  2021,  1790, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964,   404,  2304,  2305,  2308,  2309,  2312,  2314,
     467, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
    2315,   473, -2964, -2964, -2964, -2964, -2964,  2316,  2317,  2318,
    2319,   475, -2964, -2964, -2964, -2964, -2964,  2320,  2322,   477,
   -2964, -2964, -2964,   478, -2964,  1813,  1814,  1816,  1811,   493,
   -2964,  2330,  1821,  1822,  1824,  1818,  1826,  1828,  1830,  1825,
   -2964,  1833,  1834,  1837,  1842, -2964,  6816,  6816,  1843,  1844,
    1846,  1847,  1849,  1850,  1853,  1854,  1856,  1860,  1861,  1865,
    1866,  1868,  1870,  6816,  5069, -2964,  1871, -2964,  1872,   142,
    1835,   268,   339,   268,  2327,   339,  2328, 11012,  2329,   101,
    2332,  2333,  6578,  6578,   954,  2346,  2349,   268,  2352,  2037,
    2355,  1875,   268,  6225,   626, -2964,  6578,  2360,  2361,  2376,
     268,   268,  2377,   268,  2380,  1283,  1831,   268,  1930,   905,
    2382,  2384,   746,  1863,  1936,  1937, -2964,  6578,   584,   864,
     864, 10340,  1307, -2964, 10360, 10401,  1938, -2964,  6816,  1939,
    2392,  2152,   268,  6578,   268,   268,   268,  2393, 11012,   101,
     836,   101,  2394,  1943,   268,  2398,   268,  2399,  2401,   397,
     268,   268,   268,   268,   268,   268,  2402,  2403,  2404,  2406,
     310,  2407,  2408,  5254, 11012,  2410,  1875,  1954,  1954, 11093,
    2412,    85,   268,   291,   328,  2414,  6578,   804,   861,  1963,
    2417,  2418,   268,   300,  2420,   911,   268,  2421,   364,  1969,
    2423,  5842, 10501,  2092, -2964,  1972, -2964,   830, -2964,  2095,
    2101,  1974, -2964,  6816,  2205,  2206,  1980, -2964,  6816,  1981,
    2425,  2437,  1987,   644,  2438,  1993,  1994, -2964,  6816,   780,
   10548,  1927,  1995, -2964,   458,  1996, 11012,  1998, -2964,  6816,
     339,  2441,  2442,   458,  2451,  2452, 10952,  2453,  2002,   791,
    2006,  2007, 11012,  2008, -2964,  6578,  2462,  2011,  2012, -2964,
    2369,  6578,  3565, -2964,   194, -2964,   268,  2022,  2466,  2023,
     896,  2039,   183, 11012,  2040,  2043,   268, -2964,  2041,  2048,
    2049, -2964,  2053,  2086, -2964,  6578,  2087, -2964,  6816,  2090,
    6012,  6578,  7195,   268,  2467,  2468, 10993,   268,  2470,   268,
    2471,   268,  2472,  2473,  2474,  7192, 10598,   177,  1184, -2964,
   -2964,  6578, -2964,  2552,  6471, -2964, -2964, -2964,  6785,  6785,
    6785,  6785,     5,  2268,  6785,  6785,  6785,  6785,  6785,  6785,
    6785,  6785,  6785,  6785,  6785,  6785,  6785,  6785,  6785,  6785,
     458,   806,  6785,  6785,  6785,  6785,  6785,  6785,  6785,  6785,
    6785,  6785,  6785,  2093,  2083,  2497,   269,  2094,   268,   268,
    2498,   268,  2499,  2661,  2096,  2097,  2306,   167,  2114, -2964,
    2115,  2530,  6578,  6578, 10617,   597,  6578,  2116, -2964,  6578,
    6578,   268,   268,  6816,  -135,   264, -2964, -2964,   831,  2118,
   11012,  2119, 11012,  2121,  2537,  2142,   281,  6578,   185, -2964,
    2597,  1827,  2146,   268,  1875,  7289, 10639,  2541,  2547,  1875,
   10658,   182,  2133,  6816,   323, 10687,  7693, 10706,  6816,  6816,
    6816,  6816,  2149, -2964,  2571,   268,  7480, 10755, -2964, -2964,
     178,  1184, -2964, -2964,   179,  1184, -2964, -2964,   181,  1184,
   -2964, -2964,  6578, -2964, -2964, -2964, 11012,   877,  2589,  2590,
     925,   864,   864, 10796,  1310,  2150,  2592,  2593,  2595,  2596,
    2604,  2605,  2606,  2607,  2608,  2610,  2622,  2623,  2625,   268,
    2626,  2174,   268,   268,  2209,  2210,  2211,  2627,  2628,  2230,
     268,  2631,   268,   268,   268,   268,   268,  2182,  3500, 11012,
    6578,   864,   864,  2633,   306,  2207,   171,  2658,  2679,  2680,
    2681, 11012,  2685,  2239,  2686,     8,  2687,  2688,  2691,  2693,
    2694,   268,   268,  2695,  2696,  2698,  2701,  2702,  2703,   268,
    2704,  2705,  2706,  2707,  2709,  2711,  2713,  2714,  2715,  2716,
    2717,  2718,  2719,  2721,  2723,  2724,  2725,  2727,  1954,  4060,
    2276, -2964,  2730, 11012,  2731, 11012, 11012,  1954,  2732,  2733,
    1954,   339,  2734,   921, 10855,  1680,  2285,   -90,   268,   268,
     268,  2735,   268,  2738,  2740,   268,   268,  2741,  2742,  2744,
    2745,   268,   268,   802,  2295,  2746,  2748,  2750,   190,  2300,
    2751,   339,   339,  2753,   675,  2302,   -82,  2303,  2756,  1941,
    2311,  2374,   -88,  2321,  2324,   242, -2964,  2313,  2323,  2758,
     128,  2760,  2764,   447,  2325,   101,   -95,  2331, 11012,  2766,
   11012, 11012,   586,  2334, 11012,  2767,     7,  2335,  2336,  2338,
    6578,  6578, -2964,  2759,  6578,  2340,   864,  6578,  6578, -2964,
   11073,  6578,  6578, -2964,  6253,  6816,  6816,  6816,  6816,  2532,
    2532,  6816,  6816,  6816,  6816,  6816,  6816,  6816,  6816,  6816,
    6816,  6816,  6816,  6816,  6816,  6816,  1620,  6816,  6816,  6816,
    6816,  6816,  6816,  6816,  6816,  6816,  6816,  6816, -2964,  2341,
    1064,  2342,   165, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964,   161, -2964,    88, -2964, -2964, -2964, -2964, -2964,
    2339, -2964,  2347, -2964, -2964, -2964, -2964,  2348, -2964, -2964,
   -2964,  9388, -2964,  9441, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964,  6578, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,  2641, -2964,
    2344, -2964, -2964, -2964,  2542,  2542, -2964,  9468, -2964, -2964,
    9498, -2964,  9550, -2964,  7799,  6578, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964,   696, -2964, -2964, -2964, -2964,  6578, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964,   331,   823, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,   357,
     158, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964,  2629, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,  2630,
   -2964, -2964, -2964,  9636,  6578, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964,  8267,  2559,  2351,  2576,  6578,  6816,
   -2964,  1740,  6578,  6816, -2964,  8667,  3400, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964,  2639, -2964, -2964,  9659,  6274, -2964,
   -2964,  2802,  2805,  2354,  6578,  2356, -2964,  4524, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
    6578,  2359, -2964,  2581,  -116,  2362,  6578, -2964,  6785,  2866,
      70, -2964,  2872,  2365, -2964, -2964,  6785, -2964, -2964,  6578,
   -2964, 11012, -2964, -2964, -2964, -2964,  8299, -2964,   268,  2364,
   -2964, -2964,  2689, -2964,   676, -2964,   135, -2964,  2109, -2964,
    6578,  8700,  6816, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,  9706,
    1184, -2964, -2964, -2964,  2669, -2964, -2964,  3302,  4493,  2137,
    2254,  2326,  2386,  2409,  2422,   997,  2439,  2673,  2699,  2757,
    2810,  2916,  2937,  2974,  1157,  1366,  3015,  2368, -2964,  1717,
    1717,   708,   708,   708,   708,     5,     5,  2268,  2268,  2585,
   -2964,  6785,  2370, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964,  6578,  6816,  6578,   100, -2964,   212, -2964,
   -2964, -2964, -2964,  9745, -2964,  9815, -2964, -2964,  9897,  2371,
   -2964, -2964,  3094,   229,  2375,   232,  6816, -2964, -2964, -2964,
   -2964,  6578, -2964,  6578, -2964, -2964, -2964,  5234,  2378, -2964,
    6816, -2964, -2964, -2964, -2964, -2964, -2964,  9924, -2964, -2964,
   -2964, -2964,  9953, -2964,  6578,  7478, -2964, -2964,  9983, -2964,
   -2964, 10896, -2964, -2964,  8716,  8729,  8747,  8854, -2964, -2964,
   -2964, -2964, -2964, 10006,  6785,  6785,  1184, -2964, -2964,  1184,
   -2964, -2964,  1184, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964,   696, -2964,  2542,  2542, -2964, 10063, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964,   310,   198, -2964, -2964, -2964,
    5154,  5154,  5154, -2964, -2964,  5154, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964,  2542,  2542, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964,  6578, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964,  6785, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, 10092, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964,  2826,  2828,  2381, -2964, -2964,  2390, -2964,
    6578,   253, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964,   304,  2609,  2391, -2964,
   -2964,   -51,  2611,  2395,  2373,  2379,  2621,  2396, -2964,  2388,
    4646,  5201,  3340,  3412,  3425,  3696,  3735,  3750,  1810,  3763,
    3776,  3828,  3895,  3909,  3993,  4227,  4312,  1924,  2350, -2964,
    1989,  1989,  1038,  1038,  1038,  1038,   147,   147,  2532,  2532,
    2585,  6816,  2905,  2908,  2909,   495, -2964, -2964, -2964, -2964,
     566,  2400,  2914,  2427,  2858, -2964, -2964,   102, -2964, -2964,
    6578, -2964, -2964, -2964,  6578, -2964, -2964,  6625,  2860,  2419,
   -2964, -2964, -2964, -2964,  4774, -2964,   502,  7210, -2964, -2964,
     339, -2964,   216, -2964, -2964,  2636, -2964,   503,  2655, -2964,
     505, -2964, -2964,   830, -2964,  6816,  2656,  6265,  6816,  2663,
    9324, -2964,  2431,  3423,  6816, -2964, -2964,  2433,   151,  2436,
   -2964, -2964,  2953,  4805,  2445,  6816, -2964,  4878,  2446,   521,
    2684,  2912,  2692,  5051,  4931,  2761,  2369,  6785,  6785, -2964,
    9668,  7234, -2964,   507,  5356, -2964,  2460, -2964,  2860,   324,
     521,   528,  2464,  6816, -2964,  9708, -2964, -2964, -2964,  6785,
    6785, -2964, -2964, -2964, -2964, -2964, -2964,  6785, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964,  6785, -2964,  6785,
   -2964, -2964,  2469,  3853,   511,  6578,  2976,  9780,  2977,  6816,
     322, -2964,  6578, -2964, -2964, -2964,  2483, -2964,   264, -2964,
    6816, -2964,  4992,  7404,  7424,  2980, -2964,  9866, -2964, -2964,
    7448, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,  5114,
    5182, -2964, -2964, -2964,   512, -2964, -2964, -2964, -2964, -2964,
   11162,  2504,  2506,  2507,  2508,  7588,  5400, -2964,  2739,  2511,
   -2964, -2964,  5510, -2964,   111,  3022,  3023,  3026,  3027,  3028,
    3029,  3030,  3031,  3032,   518, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964,  6578,  2517,   864,  6578,
    2518,  2647,  6578,  2523,  2981,  6816,  6816, -2964, -2964, -2964,
   -2964, -2964, -2964,  6816, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964,  6816, -2964,  6816, -2964,  7478,   519,  2174,
     268,   339,  1064,  2544,  3050,  3054,   524, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,  1064,  2545,
    2999, -2964, -2964, -2964, -2964, -2964, -2964,  2546,   118,  6649,
    2550,   696, -2964, -2964, -2964, -2964, -2964,   587,  2629, -2964,
     218,  2630, -2964,  7478,  2778,  2780,  2781, -2964,  6816,  6816,
   10245,  6816, -2964, -2964,  2555, 10383,  1064,  2556,   192,  6816,
    2558, -2964, 10610,  2560, -2964, -2964, -2964,   310,  2561,  6578,
   -2964,  6578,  2562,  6578, -2964, -2964,   241, 11204, -2964, -2964,
   11012, -2964,  4015, -2964,   129,  2563,  2564,   115,   166,  2557,
   -2964, 11270, -2964,  5511,  5894,  6162,  7558,  7717,  6785,  6785,
   -2964, 10201,  6816, -2964,  6816, 11283,  2565, -2964, 11134,  6185,
   -2964, -2964, -2964,  6816, -2964, -2964,  6578,  6578, -2964, -2964,
   -2964, -2964, -2964, -2964,  6578, -2964,  2645, -2964,  1954, -2964,
     339,  1954,   268,  2323,   339,  1954,  1598,  1954,  1954,   304,
    2567,  2568,  3012,  2542,  2575, 11210, -2964,  2577, 11034, -2964,
    6599,  6642,  6700,  7818,  7858,  6816, -2964, -2964, -2964, -2964,
   -2964, -2964,   339,  6816,   566,  2578,   526,   566, -2964,  3033,
    2588,  3035,  2841, -2964,  2599,   154,  2598, -2964, -2964, -2964,
   -2964, -2964, -2964,  2897, -2964, -2964,  6816,  6816,  6816,  7875,
   11318, -2964, 11358, -2964, -2964,   530,   566,  2601,  3112, 11371,
   -2964, -2964, -2964,   410, -2964,  2833,  2834, -2964, 10244,  2862,
    6785, -2964, -2964, -2964,  2612,  2856, -2964, -2964,   458,  2838,
     458,  2840, -2964, -2964, -2964, -2964,  6785,  6785,  6859,  3853,
   -2964, 11384, 11397, -2964, -2964,  2193, -2964, 11410, 10263,   188,
   10310, 10449,  2867,  6035,  3067,  2690, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964,  2613,  2615,  2373,
    2616,  2640, -2964,  2642, -2964, -2964, -2964,  6816,  6816,  7478,
   -2964,  7478, -2964, -2964,  2618,   539, -2964,  3071,  2644,   258,
    1064,  2650,   197,  2873, -2964,   546,  2879, -2964,  2880,  6816,
   -2964, -2964,  2659,   547,  1064,  2657, -2964,   310,  2683,   521,
     521,  6578, -2964,  2941, -2964, 11431, -2964,   258,  2700,   521,
   -2964,   521,  6955,  7017, -2964, -2964, -2964,  2722, -2964,  6578,
   -2964,   200,  1184, -2964, -2964,  6578, -2964,  2942, -2964,  6387,
    6410,  2708,  7914,  3209,  6035, -2964,  2931,  3157,  3147, 11250,
    2843, 11053,  3160,  7054,  7261, -2964,  2728, -2964,  3177,  6816,
     139, -2964,   548,   566,  2729,  3238,   738,  2897, -2964,   332,
    6816, 11444, -2964,  2736,   549,   566,  2743, -2964,  2737,  2762,
    2984, -2964, -2964,   262,   458,  2765,  2768, -2964, -2964, -2964,
     213,  1184, -2964, -2964,  2985, -2964,  2769,  2772,  6578,  6439,
   -2964,  7914, -2964,  6578,  2960,  2373,  2754, -2964, -2964,  2770,
   -2964, -2964, -2964, -2964, -2964,  7374,   288, -2964,  6816, -2964,
    2775,   552,  1064,  2779, -2964, -2964, -2964,  2961,  2966, -2964,
   -2964,  2776,   553, -2964, -2964, -2964, -2964, -2964,  2777, -2964,
   -2964,  1184, -2964, -2964, -2964,  6578,  6578,  2972,  2782,  6035,
     413, -2964,  6578,  2883,  3205, -2964,  6816, -2964,  7953, -2964,
    2784,   558,   566,  6816,  6816, -2964,  2785, -2964, -2964,  2994,
    2996,  3233,  6578,  2786,  6578, -2964,   453, -2964, -2964,  8008,
   -2964, -2964,  2799,   561, -2964,  3009, -2964,  3252,  3254,  2806,
    3036, -2964, -2964, -2964, -2964, -2964,  2804,  6816,  2808,  2811,
   -2964,  3266, -2964,  7478, -2964, -2964,  2814, -2964
  };

  const unsigned short int
  parser::yydefact_[] =
  {
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1810,     0,
       0,     0,     0,     0,     0,   890,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   819,
       0,     0,     0,     0,     0,     0,     0,  1811,  1812,  1814,
    1813,  1815,  1816,  1817,  1818,  1819,  1820,  1821,  1822,  1823,
    1824,  1825,  1826,  1828,  1827,  1829,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   352,     0,     0,     0,     0,
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
      91,    92,    93,    99,     0,     0,     0,     0,     0,  1294,
       0,     0,   537,     0,   429,     0,     0,     0,     0,   945,
       0,     0,     0,     0,     0,     0,     0,   690,     0,     0,
       0,     0,     0,     0,  1310,     0,     0,     0,  1263,     0,
       0,     0,     0,     0,     0,     0,   854,     0,     0,     0,
       0,     0,     0,     0,     0,   281,     0,   881,     0,   884,
       0,   880,   435,   439,     0,     0,  1319,     0,     0,     0,
     844,     0,     0,     0,     0,   185,     0,     0,     0,     0,
       0,   440,     0,   446,     0,     0,     0,     0,     0,   933,
       0,     0,     0,     0,     0,   468,     0,  1337,     0,  1288,
     417,     0,   481,     0,     0,   937,     0,     0,   893,     0,
       0,   897,     0,     0,     0,   911,     0,     0,     0,     0,
       0,   149,     0,   161,     0,   173,     0,     0,   197,   941,
       0,     0,   929,     0,   931,   932,  1156,     0,     0,  1028,
       0,     0,  1082,     0,     0,  1046,     0,  1154,     0,  1115,
       0,  1104,     0,  1092,     0,  1064,     0,     0,     0,     0,
     375,     0,     0,     0,     0,     1,     3,     0,     0,     0,
       0,     0,     0,   968,     0,  1562,     0,     0,     0,     0,
       0,  1512,     0,     0,     0,  1513,     0,     0,     0,     0,
     956,   967,     0,   957,   962,   960,   963,   961,   958,   959,
     964,   965,   949,   950,   951,   952,   953,   954,   955,   976,
       0,     0,     0,   970,   975,     0,   972,   971,   973,     0,
    1495,     0,  1481,  1515,  1711,  1712,     0,  1299,  1302,  1305,
    1303,  1304,  1300,  1307,  1301,  1308,  1306,  1309,     0,  1296,
     535,   199,   200,   201,   202,     0,  1625,     0,     0,     0,
       0,     0,     0,     0,     0,   433,     0,   432,   421,   426,
     428,   425,   434,   422,   423,   424,   427,     0,     0,     0,
       0,     0,     0,  1275,  1278,  1277,  1279,  1280,  1281,     0,
       0,  1285,     0,  1553,  1541,  1537,     0,     0,     0,     0,
    1251,  1253,  1254,  1252,  1256,  1257,  1255,   947,     0,   100,
       0,     0,     0,   261,     0,     0,  1517,  1758,     0,     0,
    1485,  1702,  1634,     0,     0,     0,  1770,  1771,     0,     0,
       0,  1760,     0,     0,  1414,  1435,     0,     0,     0,     0,
       0,  1497,     0,     0,     0,     0,  1479,  1480,  1483,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1514,
       0,  1472,     0,     0,     0,     0,     0,  1493,  1494,     0,
       0,     0,     0,  1510,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1767,  1766,  1443,  1484,  1434,  1436,
    1437,     0,     0,  1518,     0,  1467,     0,  1488,     0,  1496,
    1492,     0,     0,  1490,     0,     0,  1710,     0,  1713,     0,
       0,   695,   747,   753,   774,   733,   762,   777,   696,   796,
     797,   697,   760,   698,   801,   803,   699,   700,   701,   702,
     703,   704,   705,   706,   707,   708,   709,   784,   710,   711,
     712,   802,   799,   800,   713,   714,   715,   716,   717,   719,
     718,   720,   721,   722,   723,   724,   725,   726,   728,   729,
     731,   732,   734,   735,   736,   737,   738,   739,   730,   740,
     741,   742,   743,   744,   745,   746,   778,   779,   781,   780,
     748,   749,   750,   751,   752,   754,   755,   763,   764,   765,
     766,   767,   768,   769,   770,   771,   772,   787,   788,   789,
     790,   793,   791,   792,   794,   795,   727,   798,   756,   757,
     758,   759,   761,   773,   775,   776,   782,   805,   804,   783,
     785,   786,   692,     0,   561,     0,     0,   555,     0,   559,
       0,     0,     0,   581,     0,     0,     0,     0,   575,     0,
       0,  1377,     0,     0,  1778,     0,  1313,  1314,  1315,  1316,
    1317,  1318,   606,   607,     0,     0,   587,     0,     0,  1267,
    1269,  1271,  1272,  1273,  1270,  1265,     0,     0,   266,     0,
       0,     0,     0,  1259,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   857,   866,   858,   865,   869,   871,
     872,   873,   875,   870,   874,   864,   867,   860,   859,   861,
     862,   863,   868,   876,   877,     0,     0,     0,     0,  1332,
       0,     0,     0,     0,     0,   269,   272,     0,   275,  1361,
       0,   274,     0,   273,   280,     0,   277,   270,   271,     0,
       0,     0,     0,   878,   886,     0,   438,     0,   395,     0,
       0,     0,  1325,     0,     0,   826,     0,     0,     0,     0,
       0,     0,     0,  1689,     0,     0,     0,     0,  1366,  1367,
    1368,  1504,  1503,  1690,     0,     0,  1394,     0,     0,   837,
       0,   836,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   497,   498,   502,   503,   505,   506,   507,   838,   839,
     840,   508,   510,   509,   511,   512,   842,   517,   499,   500,
     501,   841,   528,   496,   504,   513,   514,   515,   516,   520,
     521,   522,   523,   524,   525,   518,   519,   843,   526,   527,
     846,   834,     0,   139,   183,   191,     0,     0,   188,     0,
     206,   544,   543,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   891,   299,   298,
       0,  1282,     0,   443,   444,   445,     0,     0,  1482,     0,
       0,  1772,  1360,     0,  1359,     0,   449,   457,   450,   458,
     454,   453,   460,   461,   451,   452,   455,   456,   459,   102,
       0,     0,     0,     0,   345,   346,     0,     0,  1438,  1781,
       0,     0,  1212,  1214,  1219,  1218,  1217,  1220,  1213,  1215,
    1216,   935,     0,     0,  1349,     0,     0,     0,   472,   473,
       0,   471,     0,     0,     0,     0,     0,     0,  1340,  1341,
    1342,  1343,  1344,  1345,     0,     0,   420,     0,  1380,  1635,
       0,   529,   486,   534,   533,   530,   531,   532,   483,     0,
       0,     0,     0,  1222,  1224,  1226,  1225,  1229,  1230,  1231,
    1232,  1223,  1227,  1228,   939,     0,     0,     0,   921,   922,
     923,   895,   926,     0,   925,   927,   928,   899,     0,     0,
     906,     0,     0,     0,   916,   917,   919,   918,   913,   828,
       0,     0,     0,   119,   147,   155,   152,     0,   136,   159,
     167,   164,     0,   137,   171,   179,   176,     0,   823,     0,
     138,   195,     0,  1554,  1538,  1539,  1540,  1536,     0,     0,
       0,     0,     0,     0,  1444,     0,  1234,  1237,  1238,  1239,
    1240,  1241,  1242,  1244,  1243,  1248,  1249,  1245,  1246,  1247,
    1235,  1236,   943,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1159,  1206,  1192,  1193,
    1194,  1195,  1196,  1208,  1197,  1198,  1199,  1200,  1201,  1203,
    1202,  1207,  1160,  1161,  1162,  1163,  1164,  1165,  1166,  1167,
    1168,  1169,  1170,  1171,  1172,  1173,  1174,  1175,  1184,  1176,
    1177,  1185,  1187,  1186,  1178,  1179,  1188,  1180,  1181,  1182,
    1183,  1189,  1190,  1191,  1204,  1205,  1209,  1210,     0,     0,
       0,     0,     0,     0,   612,   613,   614,   615,   616,   617,
     618,   619,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1653,     0,  1654,     0,     0,     0,     0,  1656,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1027,     0,
     978,  1024,   979,   980,   981,   982,   983,   984,   985,   986,
     987,   988,   989,   990,   991,   992,   993,   994,   995,   996,
     997,   998,   999,  1000,  1001,  1002,  1003,  1004,  1005,  1006,
    1007,  1008,  1009,  1010,  1011,  1012,  1013,  1014,  1015,  1016,
    1017,  1018,  1019,  1020,  1021,  1022,  1023,  1025,     0,  1743,
    1754,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1752,  1745,     0,  1081,     0,  1066,  1067,  1068,  1075,  1069,
    1070,  1071,  1072,  1073,  1074,  1076,  1077,  1079,  1078,  1084,
    1747,  1045,     0,  1030,  1031,  1032,  1038,  1042,  1043,  1033,
    1034,  1035,  1036,  1037,  1039,  1041,  1040,     0,  1717,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1153,     0,  1123,  1124,  1125,  1118,
    1119,  1120,  1121,  1122,  1126,  1127,  1128,  1129,  1130,  1131,
    1132,  1133,  1134,  1135,  1136,  1117,  1137,  1138,  1139,  1140,
    1141,  1142,  1143,  1144,  1145,  1146,  1147,  1148,  1149,  1150,
    1151,     0,     0,  1737,     0,  1114,     0,  1109,  1108,  1106,
    1107,  1110,  1111,  1112,     0,     0,     0,     0,  1739,  1103,
       0,  1094,  1095,  1096,  1100,  1101,  1097,  1098,  1099,  1746,
    1091,     0,  1086,  1087,  1088,  1089,     0,  1063,     0,  1048,
    1049,  1050,  1055,  1060,  1061,  1052,  1053,  1054,  1056,  1057,
    1059,  1058,  1051,     0,     0,     0,     0,     0,     0,     0,
       0,   378,   379,   381,   380,   382,   383,   384,  1698,  1699,
       0,     0,   387,   391,   388,   389,   390,     0,     0,  1707,
    1709,     0,   476,   477,   478,   479,   480,     0,     0,     0,
     465,   466,   467,     0,   631,     0,     0,     0,     0,     0,
     626,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     250,     0,     0,     0,     0,   249,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   211,   210,   622,   684,   627,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   536,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1286,     0,     0,     0,
       0,     0,     0,   101,     0,     0,     0,   260,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   558,     0,   554,   253,   557,     0,
       0,     0,   580,     0,     0,     0,     0,   574,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   586,     0,     0,
       0,     0,     0,   265,     0,     0,     0,     0,  1260,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1333,     0,     0,     0,     0,   111,
       0,     0,     0,   287,     0,   288,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   888,     0,   439,     0,     0,
       0,   394,     0,     0,  1326,     0,     0,   825,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   184,   189,   186,
     194,     0,   141,     0,     0,   145,   143,   207,     0,     0,
       0,     0,   313,   312,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   344,
       0,     0,     0,     0,     0,     0,     0,     0,  1348,     0,
       0,     0,     0,     0,     0,   410,   547,   416,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1291,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   905,     0,     0,     0,     0,   122,   120,
     148,   153,   150,   158,   160,   165,   162,   170,   172,   177,
     174,   182,     0,   820,   821,   196,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   103,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   355,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   621,     0,     0,     0,     0,     0,     0,   665,
       0,     0,     0,   683,     0,     0,     0,     0,     0,   224,
     223,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   208,     0,
       0,     0,     0,  1558,  1559,  1560,  1561,  1557,  1563,  1401,
    1411,  1788,     0,  1405,     0,  1404,  1430,  1431,  1505,  1506,
       0,   966,     0,  1564,  1456,  1491,   974,     0,  1507,  1500,
    1295,     0,  1298,     0,   203,  1622,  1623,  1624,  1387,  1391,
    1378,  1398,  1356,   431,   430,  1458,     0,  1633,  1627,  1628,
    1630,  1629,  1631,  1632,  1374,  1363,  1276,  1274,     0,  1284,
       0,  1546,  1547,  1548,  1549,  1550,   946,     0,  1250,   850,
       0,   848,     0,   258,     0,     0,  1365,  1410,  1403,  1466,
    1457,  1533,  1534,  1535,  1402,  1409,  1408,  1449,  1451,  1450,
    1452,     0,  1445,  1407,  1406,  1369,     0,  1768,  1498,  1499,
    1432,  1433,  1525,  1527,  1524,  1526,  1528,  1529,  1459,  1462,
    1468,  1463,  1477,  1478,  1460,  1461,   550,     0,     0,   552,
     551,  1473,  1475,  1474,  1470,  1471,  1469,  1519,  1508,     0,
       0,  1509,  1511,  1763,  1762,  1764,  1765,  1565,  1566,  1568,
    1567,  1569,  1570,  1572,  1571,  1573,  1574,  1576,  1575,  1577,
    1578,  1579,  1580,  1581,  1582,     0,  1362,  1516,  1476,  1487,
    1486,  1489,  1522,  1521,  1523,  1761,  1530,  1531,  1532,     0,
    1714,   694,   691,     0,     0,   553,   598,   599,   601,   602,
     604,   600,   603,   605,   254,     0,     0,     0,     0,     0,
     579,     0,     0,     0,   571,     0,     0,  1376,  1375,  1311,
    1312,   608,   609,   585,     0,  1268,  1264,     0,     0,   263,
     542,     0,     0,     0,     0,     0,  1258,     0,  1759,  1617,
    1621,  1620,  1619,  1618,  1612,  1613,  1588,   855,   856,   255,
       0,     0,  1330,     0,     0,     0,     0,   852,     0,   296,
       0,   294,     0,     0,   285,   286,     0,   290,  1390,     0,
    1393,     0,   279,   283,  1501,  1502,     0,   885,     0,     0,
     437,   436,     0,   392,     0,  1324,     0,   824,     0,   829,
       0,     0,     0,   832,  1769,  1355,  1364,  1388,  1389,  1371,
    1372,  1384,  1383,  1397,  1395,  1357,  1396,   835,   845,     0,
     190,   187,   192,   142,     0,   146,   144,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   297,   308,
     309,   304,   305,   306,   307,   300,   301,   303,   302,   310,
     892,     0,     0,   442,   441,  1385,  1386,  1379,  1392,  1358,
     448,   447,   853,     0,     0,     0,     0,   342,     0,  1439,
    1782,  1783,   934,     0,  1211,     0,  1354,  1346,     0,     0,
     545,   546,     0,     0,     0,     0,     0,   414,   470,   469,
    1773,     0,  1776,     0,  1775,  1338,  1339,     0,     0,  1290,
       0,   419,   418,  1373,  1381,   485,   482,     0,  1441,  1440,
    1442,   938,     0,  1221,     0,  1520,   920,   894,     0,   924,
     898,     0,   902,   903,     0,     0,     0,     0,   904,  1382,
    1757,   915,   912,     0,     0,     0,   154,   151,   156,   166,
     163,   168,   178,   175,   180,   822,  1542,  1543,  1544,  1545,
    1555,  1556,     0,  1447,  1551,  1552,   942,     0,  1233,   930,
    1583,  1584,  1585,  1586,  1587,  1589,  1590,  1591,  1592,  1593,
    1594,  1595,  1596,  1597,  1598,     0,     0,  1599,  1600,  1601,
       0,     0,     0,  1605,  1606,     0,  1608,  1609,  1610,  1611,
    1614,  1615,  1616,  1157,  1158,  1399,  1400,  1412,  1413,  1415,
     611,   610,  1638,  1639,  1640,  1641,  1642,  1643,  1644,  1645,
    1646,     0,  1648,  1649,  1650,  1651,  1652,  1655,  1657,  1658,
    1659,  1660,  1661,  1672,  1669,  1683,  1684,  1688,  1662,  1665,
    1666,  1667,  1668,  1670,  1671,  1673,  1674,  1675,  1676,  1677,
    1678,  1679,  1680,  1681,  1682,  1685,  1686,  1687,  1719,  1026,
    1029,     0,  1755,  1715,  1744,  1718,  1716,  1748,  1750,  1749,
    1751,  1753,  1735,  1080,  1083,     0,  1044,  1047,  1663,  1664,
    1720,  1721,  1722,  1723,  1724,  1725,  1726,  1727,  1728,  1729,
    1730,  1731,  1732,  1733,  1734,  1152,  1155,  1636,  1637,  1736,
    1113,  1116,  1740,  1742,  1741,  1738,  1102,  1105,  1090,  1093,
    1756,  1062,  1065,     0,     0,     0,   361,   362,     0,   354,
       0,     0,  1806,  1692,  1691,  1693,  1694,  1695,  1696,   377,
     376,  1701,  1700,   386,   385,  1704,  1705,  1706,  1708,   475,
     474,  1779,  1780,   464,   462,   463,     0,     0,     0,   625,
     620,     0,     0,     0,   666,     0,     0,     0,   684,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   209,
     221,   222,   217,   218,   219,   220,   212,   213,   215,   214,
     216,     0,     0,     0,     0,     0,   679,   680,   681,   682,
       0,   685,   629,  1788,     0,  1789,  1791,     0,  1795,  1793,
       0,   969,   977,  1297,     0,   198,   204,     0,     0,     0,
     948,   851,   849,   262,     0,  1453,     0,     0,   548,   549,
       0,  1797,     0,  1801,  1799,     0,   808,     0,     0,   817,
       0,   693,   560,   253,   556,   253,     0,     0,     0,     0,
       0,   578,     0,     0,     0,  1266,   623,   686,   633,     0,
     540,   541,     0,     0,     0,     0,  1262,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   282,
       0,     0,   882,     0,     0,   879,     0,   887,     0,     0,
       0,     0,     0,     0,   830,     0,   847,   193,   140,     0,
       0,   325,   326,   314,   315,   316,   317,     0,   329,   318,
     319,   320,   321,   322,   323,   337,   324,     0,   334,     0,
     336,   338,     0,   339,     0,     0,     0,     0,     0,     0,
       0,   936,     0,  1351,  1353,  1350,     0,   415,   409,   402,
       0,   412,     0,     0,     0,     0,  1289,     0,   484,   940,
       0,   896,   900,   901,   907,   908,   909,   910,   914,     0,
       0,   157,   169,   181,     0,   944,  1807,  1809,  1808,   539,
     538,     0,     0,     0,     0,     0,     0,  1085,     0,     0,
     357,   353,     0,  1804,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   654,   655,   663,   661,   656,
     659,   658,   664,   662,   660,   657,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   236,   237,   225,
     226,   227,   228,     0,   240,   229,   230,   231,   232,   233,
     234,   248,   235,     0,   245,     0,   247,   251,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   642,   643,   651,
     649,   644,   647,   646,   652,   650,   648,   645,     0,     0,
       0,  1792,  1796,  1794,  1784,   205,  1626,   401,     0,     0,
       0,     0,  1446,  1370,  1798,  1802,  1800,     0,     0,  1464,
       0,     0,  1465,   254,     0,     0,     0,   562,     0,     0,
       0,     0,   576,   572,     0,     0,     0,     0,     0,     0,
       0,   268,     0,     0,   257,  1322,  1323,     0,     0,     0,
    1785,     0,     0,     0,   295,   293,     0,     0,   289,   276,
       0,   278,     0,   889,     0,     0,     0,     0,     0,     0,
     827,     0,   833,     0,     0,     0,     0,     0,     0,     0,
     332,     0,     0,   348,     0,     0,     0,  1352,     0,     0,
     413,  1774,  1777,     0,  1292,  1703,     0,     0,  1448,  1602,
    1603,  1604,  1607,  1647,     0,   358,     0,  1697,     0,  1805,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1455,     0,     0,   667,     0,     0,   685,
       0,     0,     0,     0,     0,     0,   243,  1425,  1423,  1424,
     678,   672,     0,     0,     0,     0,     0,     0,  1790,     0,
     397,     0,     0,   624,   688,   637,     0,   259,  1454,   806,
     807,   809,   814,     0,   815,   818,   253,   253,   253,     0,
       0,   584,     0,   573,   588,     0,     0,   687,   635,     0,
     264,  1261,   256,     0,  1334,     0,     0,  1331,     0,   115,
       0,   292,   341,   883,     0,     0,   393,  1327,     0,     0,
       0,     0,   831,   327,   328,   330,     0,     0,     0,   340,
    1283,     0,     0,   347,   343,     0,   411,     0,     0,   126,
       0,     0,   107,     0,     0,   356,  1803,  1416,  1420,  1422,
    1429,  1418,  1427,   589,   590,   592,   593,   595,   591,   594,
     596,   597,  1417,  1426,  1421,   653,   632,     0,     0,   668,
       0,     0,   686,     0,   238,   239,   241,     0,     0,   252,
    1419,  1428,   641,   628,     0,     0,   400,     0,   396,     0,
       0,     0,     0,     0,   812,     0,   566,   563,   567,     0,
     582,   577,     0,     0,     0,     0,   267,     0,     0,     0,
       0,     0,   112,   113,   118,     0,   284,     0,     0,     0,
    1786,     0,     0,     0,   311,   350,   349,     0,  1293,     0,
     123,   124,   132,   129,   121,     0,   104,   105,   110,     0,
       0,     0,   367,     0,   368,   369,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   673,     0,   399,     0,     0,
       0,   408,     0,     0,   689,   639,     0,     0,   816,     0,
     253,     0,   674,     0,     0,     0,     0,  1320,     0,     0,
     114,   116,   291,     0,     0,     0,     0,   333,   335,  1347,
     125,   130,   127,   135,   106,   108,     0,     0,     0,     0,
     359,     0,   370,     0,     0,   670,     0,   669,   688,     0,
     687,   244,   246,   630,   398,     0,     0,  1287,     0,   407,
       0,     0,     0,     0,   810,   811,   813,     0,   568,   583,
     634,     0,     0,  1321,  1335,  1336,   117,   351,     0,  1328,
    1329,   131,   128,   133,   109,     0,     0,     0,     0,     0,
       0,   366,     0,     0,     0,   405,     0,   406,     0,   676,
       0,     0,     0,   253,   253,   675,     0,  1787,   134,     0,
       0,     0,     0,     0,     0,   364,     0,   671,   689,     0,
     404,   638,     0,     0,   564,   569,   636,     0,     0,     0,
       0,   360,   365,   363,   403,   677,     0,     0,     0,     0,
     371,     0,   640,   570,   372,   373,     0,   374
  };

  const short int
  parser::yypgoto_[] =
  {
   -2964, -2964,  3285, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964,   202, -2964, -2964, -2964, -2964,  -738,
   -2964,  -316, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964,  1099, -2964, -2964, -1691, -2964, -2964, -2964,  -257,
    -508, -2964,  1016,  -757, -2964,  1637, -2964, -2964, -2964, -2964,
     484, -1606, -2964,   494,   189, -2964, -2964, -1598, -2964,   895,
    -985,  -272, -2964, -2964, -2964,  1317, -2964, -2964, -2964,  -118,
    -113, -2964,    -7, -2964, -2964, -2964,  1318, -2964, -2964,  1319,
   -2964,   985,   490, -2964,    23, -2964,   889, -2964, -2964,  -210,
   -2964, -2964,  1809, -2964, -2964,  1649, -2964, -2964,  -178, -2964,
   -2964,  -187, -2964, -2964,  3055,  1311, -2964, -2964,  1542, -2964,
   -2964,  1320, -2964, -2964,  -154,  1530,   523, -1711, -1690,  1741,
    -907, -2964, -2408, -2964, -2964,  2710, -2964, -2964, -2963, -2964,
    1072,  -732, -2964, -2964,  2712, -2964, -2964,  2720, -2964, -2673,
   -2964, -1381, -2964, -2964, -2964,  1445, -2964, -2964,  3063, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2926,   199,
   -2964,   222, -2964,  3066, -2964, -2715,   360, -2964,  3079, -2964,
   -2964,  1745,   343, -2964,    16, -2964,   344, -2964, -2964, -2964,
   -2964, -2964, -2964,  2620, -2964, -2964, -2964, -2964, -2964,  1661,
   -2964, -2964, -2964, -2964, -2964, -2964,  1718, -2964, -2964,   617,
   -2964,  1695, -2964, -2964, -2964, -2964, -2964, -2964,   900, -2964,
   -2964,  2397, -2964, -2964,  1546, -2964,  1560, -2964,  -291, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964,   -10,  1879, -2964,
   -2964,  1886, -2964, -2964,  1441, -2964, -2964,  1422, -2964, -2964,
    1393, -2964, -2964,  1431, -2964, -2964,  1400, -2964, -2964,  1403,
   -2964, -2964,  1411, -2964, -2964,  1417, -2964, -2964,  1506, -2964,
    1616, -2964,  1582, -2964,  1543, -2964,  1869, -2964, -2964, -2964,
    2749, -2964, -2964,  1770, -2964, -2964,  1887, -2964, -2964, -2964,
    3010, -2964, -2964, -2964,  1610, -2964,  1898, -2964, -2964,  1787,
   -2964, -2964, -2707, -2964, -2964,  2670, -2964,  1106,  -801, -2964,
    1618, -2964, -2964,   330, -1007,  1634, -2964,    37, -2964, -2964,
   -2964, -2964,  -134,  -123,   -53, -2964,  -206, -2964, -2964, -2964,
    -107,  -103, -2964, -2964, -2964,   201, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
    -183, -2964, -2964, -2964, -2964, -2964, -2964,   -63, -2964, -2964,
    -198, -2964,  -172,  -213,  -101, -2964, -2964,  -194, -2964, -2964,
   -2964, -2964, -2542, -2515, -2514, -2964, -2964, -2506, -2505, -2964,
   -2964, -2964, -2486, -2479, -2964, -2964,  -202,  -211, -2964,  -228,
    -201, -2964,  -242, -2964, -2964, -2964, -2964,  -199, -2964,  -166,
   -2964, -1521,   913,  1396, -2964,  -221, -2964,  -303, -2964, -2964,
   -2964, -2964,  -164, -2964, -2964, -2964, -2964,  -300, -2964, -2964,
   -2964, -2964, -2964,  -145, -2964, -2964, -2964, -2964,  -208, -2964,
   -2964, -2964, -2964, -2964, -2964,   -80,  -226, -2964, -2964,   -64,
     -59,   -61, -2964,  -222, -2964,   -54, -2964, -2964, -2964,  -218,
    -215,   -48, -2964, -2964, -2964, -2964,   -47,   -46, -2964,  -100,
   -2964,   -44,   -38, -2964,  -243,   -36,   -35, -2964, -2964, -2964,
     -33,   -31,   -29,   -26, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964,  -284, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964,  -251,  -248, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964,    56,  -197, -2964, -2964, -2964,  -324,  -320,  -304,  -281,
    -280, -2964, -2964, -2964, -2964, -2964,  -278,  -273,  -265, -2964,
    -216, -2964, -2964, -2964,  -214,  -207,  -204, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964,  -356, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964,  -161,  -230, -2964, -2964, -2964, -2964, -2964,
     -19,   -18, -2964, -2964,  -274,  -195, -2964,  -287,  -203, -2964,
   -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964, -2964,  -190, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964,  -311,  -188,  -283, -2964, -2964,  -184,  -173,  -171,
    -170,  -342,  -169,  -168, -2964, -2964,  -200,  -247, -2964, -2964,
   -2964, -2964, -2964,   -14, -2964, -2964, -2964, -2964, -2964, -2964,
   -2964, -2964, -2964,  -150, -2964, -2964,  -219,  -212, -2964, -2964,
   -2964, -1383, -1985, -2964, -1341, -2964, -1304, -2964,   303, -2964,
   -1920,     0
  };

  const short int
  parser::yydefgoto_[] =
  {
      -1,   113,   114,   115,   116,   117,  2701,  3321,   118,  2408,
    3288,   119,  2585,  2584,  3318,   120,   121,   122,   123,  1812,
     927,   928,   330,   332,   334,   284,   337,   124,   455,  2203,
     125,   126,  3123,  2169,  3078,  3126,   127,   128,   129,   512,
     513,   130,   767,   768,   131,   824,   825,   132,   814,  2924,
    1762,  1763,  2410,  2411,  1764,  1854,  2964,  1765,   133,   993,
     994,   995,   134,   367,  2095,  2096,  3323,  3529,  3325,  3530,
    3423,  3424,  3425,   135,   136,  1500,  1501,   137,  1511,  1512,
     138,   839,  3108,   139,  3440,  1884,  1885,   140,  1035,   465,
     141,   466,   467,   142,   835,   836,   143,   962,  1018,   144,
     975,  1019,   145,   146,  1529,  1530,   147,  1020,  1021,   148,
    1521,  1522,   149,  1040,  1072,  1042,  3010,  3011,  2383,  1575,
    2289,  2290,  2291,   150,   726,   727,   728,  2356,  3127,   151,
     737,   738,   152,   732,   733,   153,   755,   756,  3342,  2357,
     753,   754,   154,   155,  1233,  1234,   156,   157,   158,  1539,
     159,  2171,  3099,  2119,  3137,  3385,  3371,  3503,  3086,  3087,
    3034,  3035,   160,   161,   162,  2835,  2836,   163,   164,   165,
     610,   611,  2876,  2877,  3374,  3375,  2879,  2880,   166,   336,
    1107,   167,   844,   845,   168,   169,   847,   170,   870,   871,
     171,   172,   173,   174,   175,   176,   783,   784,   177,   269,
    2923,   270,   178,   288,  1853,   179,   180,  2571,  2572,   181,
    1079,  1080,   182,  1083,  1084,  1067,  1068,  1073,  1085,   183,
     184,   185,   186,   187,   188,   189,   400,   401,   402,   190,
     424,   425,   191,  1288,  1289,   192,  1371,  1372,   193,  1477,
    1478,   194,  1353,  1354,   195,  1470,  1471,   196,  1459,  1460,
     197,  1445,  1446,   198,  1404,  1405,   199,   200,  1175,  1176,
    1001,  1002,  1052,  1053,  1125,  1126,   499,   500,   201,   772,
     773,   202,   758,   759,   203,   482,   483,   204,   205,   490,
     491,   206,  1034,  1898,  1899,   207,   436,   437,   208,   745,
     746,   209,  3148,   210,   841,   842,   211,   808,   809,   212,
    1027,  1028,   213,  1013,  1014,  2525,   872,   873,   874,   978,
     979,   980,   875,   876,   877,   878,   879,   880,   881,   882,
     883,   884,   885,   886,  1043,   887,   748,   749,   750,   469,
     981,  1044,  1086,   888,   889,   982,   983,   470,   890,   827,
     471,   985,   828,   891,   892,   893,   894,   895,  1235,  1236,
     403,   619,   620,   404,   897,   623,   624,   405,  1237,  1238,
     625,  1239,  3088,  3089,  3090,  3091,  3039,  3092,  3093,  2837,
    2838,  2839,  3094,  3095,  3096,  3044,   406,   407,   628,   629,
     898,   631,  1006,  1007,  1058,  1059,  1060,   899,  1127,   900,
    1128,  2865,  2866,  1540,   426,   634,   486,   635,   636,   637,
     638,   639,   640,   641,   642,   643,   644,   645,   646,   647,
     648,   649,   650,   651,   652,   653,   654,   655,   441,   986,
     657,   658,   659,   660,   661,   902,   427,   664,   665,   903,
     442,   904,   669,   670,   671,   443,   830,   905,   906,   408,
     409,   444,   676,   677,   678,   679,   410,   411,   682,   445,
     684,   907,   908,   687,  1075,   909,   910,   690,   691,   692,
     911,   912,   913,   914,  1129,   501,  1130,  1131,  1132,   502,
    1133,  1134,   503,   504,   505,  1135,  1136,   506,  1137,  1138,
    1139,   412,   413,   414,   415,   416,   417,   418,   428,   697,
     698,   699,   700,   701,   702,   703,   704,   705,  1192,  1193,
    1194,  1195,  1196,   795,  1198,  1199,  1200,  1201,  1202,  1203,
    1204,  1205,  1206,  1207,  1208,  1209,  1210,  1211,  1212,  1213,
    1214,  1215,  1216,  1217,  1218,  1219,  1220,   796,  1221,  1222,
    1223,   797,   798,   799,   800,   801,   473,   474,   475,   476,
     487,   488,   706,  1047,  1447,  1448,  1292,  1293,  1294,  1295,
    1296,  1297,  1298,  1299,  1300,  1301,  1302,  1303,  1304,  1305,
    1306,  1307,  1308,  1309,  1310,  1311,  1312,  1421,  1313,  1314,
    1315,  1316,  1317,  1318,  1319,  1320,  1321,  1322,  1323,  1324,
    1325,  1326,  1327,  1328,  1329,  1330,  1331,  1332,  1333,  1334,
    1335,  1336,   915,   916,  1502,  1503,  1504,  1505,  1506,  1507,
    1514,  1515,  1516,   707,  1076,  1523,  1524,  1525,  1526,   708,
     446,   447,   711,   712,  1355,  1356,  1424,  1357,  1337,  1426,
    1427,  1428,  1429,  1430,  1431,  1432,  1433,  1434,  1435,  1436,
    1437,  1438,  1439,  1440,  1358,  1452,  1453,  1464,  1465,  1466,
    1467,  1468,  1359,  1360,  1361,  1475,  1380,  1362,  1363,  1364,
    1365,  3097,  1367,  1368,  1492,  1087,   713,   804,   714,   715,
     716,   717,   718,   918,   919,   720,   721,   987,  1029,  1030,
    1031,  1032,  1033,   988,  1531,  1532,  1009,  1010,  2189,  2405,
    3169,  2845,  2846,  2184,  2185,  2300,  2762,  3024,  2763,  2626,
    2627,  1576
  };

  const short int
  parser::yytable_[] =
  {
     214,   805,   838,   222,  1637,  1717,  1878,  1754,  1869,   222,
    1733,  1366,   663,  1513,   222,  1096,  2355,  1101,   440,  1106,
     673,   222,   438,   674,  1489,   621,   439,   627,   764,   788,
     656,  1074,   614,   271,  1409,   793,   626,   630,  1410,   632,
     618,   222,   222,   285,  1188,  1377,   222,  1189,   761,   222,
     762,   786,   222,  2391,  1411,  1483,   789,   803,   790,   222,
     222,   222,   222,  1197,   222,   222,   331,   333,   335,  1375,
     338,   222,   633,  1379,  1057,  1463,  1069,  1412,  1413,  1481,
    1414,  1474,  1373,   763,  1422,  1415,  1449,  1004,  1461,  1070,
    1472,   791,  1479,  1416,   965,   751,  1224,  1062,   222,  1225,
    1227,  1036,  1003,  1055,  1063,  1045,  1005,   976,   965,   896,
    1887,   984,   792,   214,   963,   613,  1046,   901,  1054,  1183,
     917,  1140,  1056,   984,  1291,  1191,  1187,   869,  1141,  2262,
    1240,   615,   826,  1241,  1179,   616,  1182,   622,   683,  1190,
    1407,  1177,  1417,  1408,  1418,  1181,  1184,  1226,  1185,  1178,
    2487,  1419,  1290,  1180,  1420,  1425,  2414,   794,   662,  1041,
    1406,  1374,   472,  1423,  2415,  1450,  1376,  1462,  1378,  1473,
    1451,  1480,  1381,   484,   666,   617,  1482,   668,  1484,   667,
    2766,  1186,  1485,  1382,   672,  1383,  1384,  1385,  1386,  1816,
     675,   680,   681,  1486,   685,  1487,  1488,  1490,  1491,  2849,
     686,   811,   688,   689,   785,   693,  2183,   694,   423,   695,
    3125,   381,   696,  -666,   377,   931,  2843,  3006,  3008,   709,
     710,   450,  -668,  3166,   719,  -670,   931,   215,   492,  2181,
    2843,   450,  2663,   271,   271,   514,   217,   392,  2514,   450,
     729,   734,   739,  2901,  3036,   931,  3250,   757,  2234,  2235,
     450,   766,   769,  1441,  2548,   774,   932,  3250,   514,   991,
    2198,   810,   468,   271,   393,  2416,  2255,   932,  2263,   508,
     271,  3037,  3038,  1625,  1049,   612,  1527,   843,   846,   848,
    3040,  3041,   450,   450,   924,   931,   932,  1090,   959,  2843,
     450,  2308,  2309,   991,  1724,   450,   271,  1637,  1707,  2652,
    3042,   450,  1015,   931,  3377,   931,  2841,  3043,  2256,  1724,
    2264,  2758,  3290,   802,   450,  1868,   931,   450,  2286,   931,
     450,  3365,   223,   450,   392,  1922,   932,   450,   450,  2424,
    1094,   977,  1099,  3277,  1104,  2298,  1108,  1111,  3444,  1780,
     931,   450,  2346,   977,   932,   931,   932,   226,   468,   931,
    3383,   931,  2718,   286,   450,   931,  1008,   932,   925,  2928,
     932,   228,  1228,  1229,   232,  1442,  1095,  1850,  1851,   991,
    2719,  1852,  1061,  2301,  2302,   931,  2425,  1538,  1541,  1545,
    1549,   932,  1580,  3246,   224,   225,   932,   931,  1230,  1231,
     932,  3186,   932,  3165,   451,   227,   932,   931,   240,  3025,
    3026,  3027,  3028,  3029,  3030,  3031,  3032,  1022,  1023,    38,
     287,  2969,   394,  1342,  2336,  2337,   932,  1065,   931,   998,
    2329,  3275,  1100,  2916,  1496,  2754,   931,   485,   932,  2603,
    2286,  1508,  1509,  1443,  1510,  2347,  1105,  1808,   932,   479,
    2755,  2847,   233,  1931,   931,  2533,   747,  1050,  1605,  2534,
     760,  2868,   234,  2338,   241,  2272,  1345,   246,   787,   932,
     247,  2348,  2349,  2350,  3208,  1755,  2910,   932,  1351,  1469,
    2911,  3251,  1615,   452,   453,   454,   251,   957,   255,   999,
    1078,   276,  3251,  1622,   254,   932,  2273,  2274,  2930,  1624,
    1935,   277,  3496,   964,   260,  1939,   263,   931,  3262,  1881,
    1882,  2312,  2313,  2314,  2460,  2586,  2589,   964,  2592,  2165,
    2166,  2872,   514,  2167,  2844,  3412,  1725,  3501,  1881,  1882,
    2515,   264,  2664,  2665,   278,  1708,   221,  3471,   480,  3512,
    2286,  1000,   231,  1024,  1025,  3048,  1232,   239,   932,   489,
    3521,  1026,  2315,  2316,   250,  2310,  1701,   992,  1842,  1843,
    1844,  1845,  1846,  1847,  1848,  1849,  1850,  1851,  2287,  2288,
    1852,  1528,  1729,  2554,   282,   283,   296,  1781,  2560,   290,
    2604,  2605,   295,  1770,  2351,   301,  1881,  1882,  1881,  1882,
    3564,   992,   314,   317,   320,   323,  2380,   327,   328,  1881,
    1882,  3033,  1881,  1882,   341,  1842,  1843,  1844,  1845,  1846,
    1847,  1848,  1849,  1850,  1851,   837,  2870,  1852,  1809,  1810,
    2647,  2648,   926,  1881,  1882,  3496,  3563,  2535,  1881,  1882,
     926,   354,  1881,  1882,  1881,  1882,  2842,  1091,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,  1066,  1881,  1882,
     398,   399,   392,  3278,  2917,  3442,  2380,   992,  3445,   837,
    2352,  3025,  3084,  3027,  3085,  3029,  3030,  3031,  3032,  3454,
    2287,  2288,  2848,  2091,   931,  2174,   926,  3036,  2177,   393,
     216,   392,  3458,  3459,  2182,  1342,  3102,  2653,  2654,   218,
     926,   926,  3465,  1756,  3466,  3209,  3298,   926,  3252,  1881,
    1882,  1616,  2275,  1494,  3037,  3038,   429,   430,   393,  3295,
    2870,  2625,  1623,  3040,  3041,   932,  2931,  1881,  1882,  3497,
    3498,   509,  2771,  1703,   378,  1704,   729,   382,  1345, -1829,
    1709,  1710,   734,  3042,  2698,  1714,  1715,   739, -1829,  3283,
    3043, -1829,  2873,  2707,   926,  2791,  2710,  2516,  3299,   926,
    1444,  1352,  3300,  1051,  2092,   757,  2093,  2094,   926,   926,
     926,   741,   926,  3387,  2772,   431,  3554,   769,  1897,   926,
    2287,  2288,   774,  1777,  2417,  1702,  3507,  1805,  1932,  1933,
     432,   926,  3007,  1936,  1937,  1856,  1863,  3541,  1940,  1941,
     477,  1730,   478,  1888,   926,   517,   775,   518,  1901,  3263,
    3115,  1905,  1771,  1914,  2353,   514,  3554,   279,   810,  1916,
    1883,   235,   236,  2980,   959,  1926,   304,  1994,  2381,  2382,
    2103,  3291,   433,   997,   525,   931,  2106,   394,  2112,   309,
    2116,  2116,   271,  2388,   998,  2091,  2299,  1779,   348,  3439,
    2346,   843,  3517,  3498,   846,  2536,  2124,  1790,  3082,  1350,
     510,   511,   723,  3033,   479,  3111,  3118,   392,  3121,  3101,
    3160,   351,  3103,   324,  3179,  3111,   932,  3259,   368,  3536,
     344,  3219,  3235,   345,  1705,  3388,   369,  3244,   370,  3082,
     812,  3145,  3146,  3082,   535,   536,   392,   834,  2381,  3167,
     396,   742,  3244,   371,   999,   535,   536,   242,   243,  3447,
    3244,  3082,  3082,   480,   379,  3244,  3244,   815,   372,   723,
     931,  3082,   374,   990,  3244,   373,  2092,   931,  2093,  2094,
    3012,  3013,  1807,   380,  3014,   383,  1813,  1813,   542,   419,
     816,   244,   245,  2347,  2231,  2232,  2233,   959,   959,   545,
    1495,   776,   489,  2869,   515,   817,  1000,  1881,  1882,   740,
    1550,   932,   752,   743,   252,   253,   959,   770,   932,  2348,
    2349,  2350,   256,   257,   818,   806,  1496,  1497,  1498,  1499,
     258,   259,  2217,   966,   967,   384,   385,   386,  2537,  3456,
     771,   387,   388,   389,   390,   261,   262,   433,   968,   599,
     744,  1866,  1867,  3555,   807,   461,  1551,   813,   969,   391,
    2332,  2333,  1778,   479,   829,   480,  1806,   831,  1552,   392,
     970,   837,   586,  1015,  1857,  1864,   840,   588,  3504,   929,
    1553,  1554,  1889,   586,  2319,  2320,  2321,  1902,   588,    38,
    1906,   730,  1915,  3573,  1900,   481,   393,   930,  1917,   480,
     996,   777,   778,   960,  1927,   819,  1995,  1338,   479,  2104,
     480,   265,   266,  1711,    38,  2107,  1493,  2113,  1555,  2117,
    2118,  1143,   779,   596,   820,   272,   273,   971,  1848,  1849,
    1850,  1851,  2351,  2463,  1852,  2125,  2466,  3083,   274,   275,
     481,  2322,  2323,  2324,  3112,  3119,    38,  3122,  1534,  3161,
     480,   724,  1930,  3180,  3198,   291,   292,  1934,  1881,  1882,
    3220,  3236,  1938,  1016,  3147,  1017,  3245,  1944,  3364,  1945,
    1078,  1350,  3382,   434,   435,  1581,   725,  1517,  1518,  1519,
    1520,  3436,   780,   781,  1582,   821,  1822,  1823,  3448,  3453,
    3500,  3511,  1583,   972,  3540,  3546,  1584,   973,  1585,   464,
    3562,   974,  1586,  3576,  2711,  1841,   398,   399,   724,   293,
     294,   822,  2257,  2258,  2259,  1587,  2260,  1588,  2352,  3237,
    1842,  1843,  1844,  1845,  1846,  1847,  1848,  1849,  1850,  1851,
    1342,  1589,  1852,   725,  2743,  2744,  1590,   744,  2218,  2219,
    2220,  2221,  2222,  2223,   394,   395,   782,  2832,  2833,  2834,
    1556,  1557,  3124,  1918,  1919,  1920,  1921,  1558,  1559,  1560,
    1561,  1562,  1563,  1564,  1565,  1566,  1567,  1568,    38,   297,
     298,  1569,  1344,  1345,  1339,  1570,  1571,  1572,   396,   397,
    1591,  1242,  1243,  1244,  1245,  1246,   823,  2597,  2598,  2599,
    1454,  1455,  1456,  1457,  1458,  1252,  1253,  1254,  1340,  1341,
    1592,  3168,  1259,  1387,  1593,  1260,  1261,  1594,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,  1595,  1267,   302,
     303,   305,   306,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,  2257,  2258,  2259,   731,  2260,  1342,   398,   399,
     307,   308,  2353,   310,   311,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,   342,   343,  1596,   493,  1597,  1112,
    1113,   346,   347,   494,  1114,  1115,  1116,  1598,   495,   496,
    1345,  1117,  1118,  1599,  1388,   349,   350,  1119,  1120,  1600,
    2947,  1842,  1843,  1844,  1845,  1846,  1847,  1848,  1849,  1850,
    1851,   355,   356,  1852,  1287,  1389,  1390,  1391,  1392,  1393,
    1394,  1395,  1396,  1601,  1397,  1398,  1399,  1400,  1401,  1402,
    1403,  2257,  2258,  2259,  1602,  2260,  1604,  1607,  2488,  1603,
     456,  1606,  2871,  2874,  1608,   457,   458,   459,  2163,  2164,
    2165,  2166,   440,  1609,  2167,  1610,   438,   357,   358,  1611,
     439,  1573,   359,   360,  1612,  1121,  1342,  2261,  1613,  1343,
     361,   362,   363,   364,  1614,   460,  1617,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,  1618,   461,  1619,  1775,
     462,   497,   498,  1620,  1122,  1123,  1621,  3023,  1344,  1345,
    1627,  1346,  1347,  1628,  1348,  1349,  1350,   365,   366,  1629,
    1630,  1351,  1631,  1632,  1634,   663,  1638,  1633,  1640,  1641,
    1574,  1635,  1352,   673,  1642,  1639,   674,  1643,   621,  1644,
     627,  2461,  2462,   656,  1645,   614,  1646,  1647,  1648,   626,
     630,  1649,   632,   618,  1650,  1651,  2602,  1652,   764,  1653,
    2957,  1842,  1843,  1844,  1845,  1846,  1847,  1848,  1849,  1850,
    1851,   788,  1654,  1852,  1655,  1656,  1657,   793,   761,  1658,
     762,  1659,  1660,  1661,  1662,   633,  1663,  1664,  1665,  1666,
    1667,  1668,  1124,   786,  1669,  1670,  1671,  1672,   789,   803,
     790,  1673,   472,  1674,  1675,  1676,  2414,  1677,  1678,  1679,
    1680,  1681,  1682,   763,  2415,   463,  1683,  1684,  1685,   484,
    1686,  1687,  1688,   751,  1689,  3376,  1690,  3378,   613,  2948,
    1691,  1692,  1693,   791,  1694,  1695,  1696,   271,  1697,   423,
    3258,   464,  2188,  2190,   615,  1698,  1699,  1700,   616,  1713,
     622,   683,  1718,   222,   792,  1719,  2204,   999,  3398,  1720,
    3400,  1721,  1722,  1723,  2587,  2588,  1728,  1731,  2590,  2591,
    1734,   662,  2593,  2594,  1735,  2569,  1887,  2230,  2981,  1736,
    1739,   222,  1740,   896,   222,   222,   826,   666,   617,  1741,
     668,   901,   667,  2249,   917,  1742,  1743,   672,   271,   794,
    1744,   869,   468,   675,   680,   681,  1745,   685,   965,  1000,
    1746,  1747,  1004,   686,  1748,   688,   689,  3223,   693,  1057,
     694,  1069,   695,  2295,   271,   696,  2510,  1003,  2503,   271,
     984,  1005,   709,   710,  1070,  1188,  2318,   719,  1189,  1749,
     965,  2551,  1062,  1751,  1752,  1757,   785,  1045,  1055,  1063,
    1758,  1759,   222,  1766,  1197,   984,  1767,  1768,  1046,  1769,
    1772,  1366,  1773,  1054,  1776,  1785,  1782,  1056,  1788,  2959,
    1842,  1843,  1844,  1845,  1846,  1847,  1848,  1849,  1850,  1851,
     222,  1793,  1852,  1794,  1795,  1140,   271,  1224,   612,  2958,
    1225,  1227,  1141,  1796,  1377,  1797,   271,  1489,  1798,  1409,
    1513,  1041,   271,  1410,  1799,  2403,  1800,  1801,  1802,  3508,
    1183,  2412,   959,  1803,  1804,   926,  1191,  1187,  1375,  1411,
    1817,  1855,  1379,   271,  3518,  1179,  1240,  1182,  1483,  1241,
    1190,  1373,  1177,   730,  1818,  2436,  1181,  1184,  1226,  1185,
    1178,  2442,  1412,  1413,  1180,  1414,   271,  1463,  1819,  1422,
    1415,  1820,  1481,  1474,  1449,   802,   222,  1821,  1416,  1824,
    1461,  1813,  1472,  1291,  1813,  1479,  1825,  1826,   959,   959,
     959,   959,  1186,   485,   959,   959,   959,   959,   959,   959,
     959,   959,   959,   959,   959,   959,   959,   959,   959,   959,
    1827,  1290,   959,   959,   959,   959,   959,   959,   959,   959,
     959,   959,   959,  3565,  2871,  1407,  1828,  1417,  1408,  1418,
    1374,  1829,  1830,  1831,  1858,  1376,  1419,  1378,  1832,  1420,
    1425,  1381,  2520,  2521,   222,  1406,  2526,  1833,  1423,  2526,
    2529,  1834,  1382,  1450,  1383,  1384,  1385,  1386,  1451,  1462,
     271,  1473,   271,  1835,  1480,  1836,  1837,   222,  1900,  1482,
     977,  1484,  1838,  1839,  3326,  1485,   222,  3328,  1840,  -331,
     222,  3332,  1859,  3343,  3344,   222,  1486,  2573,  1487,  1488,
    1490,  1491,  1860,  1861,   747,   977,  1862,   222,  1865,  1871,
     760,  1008,  1870,  1872,   456,  1873,  1877,  1875,   468,   457,
     458,   459,  2595,  1874,  1876,  1879,   271,  1792,  2960,  1880,
     787,  1890,  1891,   222,  1892,  1893,  1894,  1896,  1895,  1903,
      38,  1904,  1907,  3114,  1908,  3116,  1909,  1061,  1910,   460,
    1911,  1912,  1913,  1339,  2157,  2158,  2159,  2160,  2161,  2162,
    2163,  2164,  2165,  2166,  1924,  1869,  2167,  1925,  2864,   271,
    2646,   461,  1928,  1929,   462,  1954,  1946,  1340,  1341,  1947,
    1948,   271,  1949,  1950,  1951,  1952,  1953,  2467,  2468,  2469,
    2470,  1955,  1988,  2471,  2472,  2473,  2474,  2475,  2476,  2477,
    2478,  2479,  2480,  2481,  2482,  2483,  2484,  2485,  2486,   958,
    1956,  2489,  2490,  2491,  2492,  2493,  2494,  2495,  2496,  2497,
    2498,  2499,  3333,   271,  1957,   271,   271,   731,  3334,  3335,
    3336,  3337,  3338,  3339,   222,  1958,  1959,   964,   384,   385,
     386,  1960,  1961,  3340,   387,   388,   389,   390,  1962,  3341,
     420,  2537,  1963,  1844,  1845,  1846,  1847,  1848,  1849,  1850,
    1851,   421,   391,  1852,  1964,  1965,  1966,  1967,  1968,   964,
    1969,    38,   392,  2888,  2157,  2158,  2159,  2160,  2161,  2162,
    2163,  2164,  2165,  2166,  1970,  1971,  2167,  1972,   271,  1973,
     271,   271,  1754,  1974,   271,  1975,  1976,  1977,  1978,   393,
    2787,  2788,  1979,  1980,  1541,  1981,  2201,  2792,  2793,   422,
    2795,  2796,  2797,  1982,  2799,   464,  1983,  1984,  1985,  1986,
    1989,  1987,  1990,  2907,  2937,  1991,  1733,  1012,  1992,  1993,
    1996,  1997,  1998,  1999,  2237,  2000,  2001,  2240,  2242,  2002,
    2003,  1717,   838,  3063,  2157,  2158,  2159,  2160,  2161,  2162,
    2163,  2164,  2165,  2166,  3239,  1342,  2167,  2004,  1343,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,  2005,  2006,
    2007,   450,  2819,  2856,  2179,  2008,  2009,  2010,  2040,  2011,
    3260,  2012,  2013,  3264,  2014,  2015,   222,  1344,  1345,  1370,
    1346,  1347,  2016,  1348,  1349,  2343,  2017,  2018,  2019,  2020,
    1351,  2021,  2022,  2023,  1339,  2024,  2025,   450,  2026,  2027,
     450,  1352,   450,  2028,  2029,   514,  2030,  2031,  2032,  2033,
    2034,  2035,  2036,  2377,  2037,  2038,  2039,  2041,  1340,  1341,
    2042,  2043,  3407,  2044,  2053,  2254,   222,   394,   395,  2045,
    3001,  2046,  2047,  3002,  2048,  2049,  3003,  3073,  2157,  2158,
    2159,  2160,  2161,  2162,  2163,  2164,  2165,  2166,  2050,  2051,
    2167,  2296,  2052,  2054,  2056,  2055,  2306,  2057,  2058,  2059,
    2060,   396,   397,  3327,  2061,  2062,  2063,  3331,  1878,  2064,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,  2459,
    2065,  2066,  2067,  2068,  2069,  3360,  2070,  2071,  2072,  2073,
    2074,  2075,  2076,   450,  2882,  2159,  2160,  2161,  2162,  2163,
    2164,  2165,  2166,  2385,  2077,  2167,  1637,  2078,  2886,  2079,
    2080,  2081,  2889,  2395,  2082,  2083,   739,  2085,  2087,  2401,
    2088,  2084,  2090,  2086,  2089,  2097,  2098,   450,  2899,  2099,
    2100,   398,   399,  2101,   769,  2102,  2105,  2108,  2109,  2110,
    2111,  2114,  3064,  2115,  2120,  2121,  2122,  2523,  2123,  1637,
     514,  2126,  2127,  2128,  2129,  2130,   810,  2131,   959,  2132,
    2133,  2214,  2134,  2448,  2135,  2136,   959,    38,  2137,   222,
    2547,   271,  2172,  2138,  2141,  2142,   271,  2143,  2144,  2557,
    2145,  2146,  2247,  2562,  2147,  2148,  1342,  2149,  2568,  1343,
    2933,  2150,  2151,  2227,  3045,  2344,  2152,  2153,  2358,  2154,
    2583,  2155,  -242,  2170,  2359,  2176,  2178,  2180,  2182,   450,
    2186,  2187,  3441,  2157,  2158,  2159,  2160,  2161,  2162,  2163,
    2164,  2165,  2166,  1012,  2192,  2167,  2607,  2193,  1344,  1345,
    2195,  1346,  1347,  2197,  1348,  1349,  1350,  1476,  2205,  2206,
    3441,  1842,  1843,  1844,  1845,  1846,  1847,  1848,  1849,  1850,
    1851,   959,  1352,  1852,  2207,  2210,  3074,  2540,  2212,  2542,
    2224,  2216,  2225,  2966,  2378,  2968,  2228,  2229,  2243,  2245,
    2246,  2253,  2265,   450,  2266,  2974,  2268,  2270,  2974,  2271,
    2282,  2283,  2284,  3499,  2285,  2292,  2293,  2299,  2297,  3505,
    2307,   222,  2317,   222,  2325,  2326,  2327,   450,  2331,  2335,
    2339,  2340,  2345,  2367,  2360,   958,  3499,   450,  2362,  2363,
    2364,  2366,   450,  2596,   222,  2368,  2371,  2369,   450,  2389,
    2390,  2573,  1774,  2372,  2373,  2379,  2384,  2715,  2386,  2392,
    2393,  2396,  2397,   450,   959,   959,  2399,  2400,  2402,  3537,
    2404,  2406,  2407,  2409,  2420,  2445,  2446,  2914,  2450,  2452,
    2454,  2455,  2456,  2419,  2421,  2920,  2645,   450,  1842,  1843,
    1844,  1845,  1846,  1847,  1848,  1849,  1850,  1851,  2659,  2423,
    1852,  2431,  2427,  2464,  2428,  2502,  2507,  2509,  2432,  2433,
     222,   222,   222,  2434,  1852,   222,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,  2139,  2140,  1781,  2519,  2513,
    2703,   222,  2705,  2706,  2501,  2544,  2435,  2437,  2550,  2558,
    2439,   735,  2156,  2500,  2504,  2559,  2511,  2512,   958,   958,
    1842,  1843,  1844,  1845,  1846,  1847,  1848,  1849,  1850,  1851,
    2963,  2932,  1852,  1716,  2517,  2518,  2527,   958,  2539,  2579,
    2541,   959,  2543,  3075,  2157,  2158,  2159,  2160,  2161,  2162,
    2163,  2164,  2165,  2166,  2564,   450,  2167,  2600,  2601,  2941,
    2610,  2611,  2545,  2612,  2613,  2775,  2552,  2777,  2778,  2578,
    2609,  2781,  2614,  2615,  2616,  2617,  2618,  2244,  2619,  2857,
    1842,  1843,  1844,  1845,  1846,  1847,  1848,  1849,  1850,  1851,
    2620,  2621,  1852,  2622,  2624,  2633,  2634,  2625,  1886,  2637,
     222,  2649,  2643,  1842,  1843,  1844,  1845,  1846,  1847,  1848,
    1849,  1850,  1851,  2999,  3000,  1852,  1842,  1843,  1844,  1845,
    1846,  1847,  1848,  1849,  1850,  1851,  2655,  2651,  1852,  2867,
    2630,  2631,  2632,  1842,  1843,  1844,  1845,  1846,  1847,  1848,
    1849,  1850,  1851,   966,   967,  1852,  2354,  2656,  2657,  2658,
    1535,  2635,  2361,  2660,  2662,  2666,  2667,  2365,   968,  2668,
    2661,  2669,  2670,  2673,  2674,   461,  2675,  2374,   969,  2676,
    2677,  2678,  2680,  2681,  2682,  2683,  2942,  2684,  2387,  2685,
     970,  2686,  2687,  2688,  2689,  2690,  2691,  2692,    38,  2693,
    3104,  2694,  2695,  2696,  3105,  2697,  2700,   450,  2702,  2704,
    2708,  2709,  2712,  2723,   514,  2717,  2725,   450,  2726,  2729,
    2730,  1536,  2731,  2732,  2737,  2736,  2738,  3045,  2739,  2742,
    2741,  2745,  2747,  2749,  2750,  2753,  2764,  2438,  2767,  2441,
    3016,  2752,  2768,   739,  2776,  2782,  2760,   971,  2167,  1577,
    2858,  2756,  1724,   769,  2757,  2770,  2761,   514,  2943,  2875,
    2878,  2774,  2883,   810,  2780,  2784,  2785,   959,   959,  2786,
    2790,   450,  2831,  2840,   959,  2850,  2859,  2851,  2852,  2885,
    2900,  2884,  3076,  2901,  2909,   736,  2902,  2915,  2904,   959,
     959,  2908,  2921,  2918,  2912,  2919,  2927,   959,  2928,  2938,
    2962, -1830,  2965,  2976,  3018,  2979,  3019,   959,  2986,   959,
   -1829,  3020,  3046,   972,  3049,   222,  3051,   973,  2944,   464,
    3021,   974,  3187,  3047,  3052,  3054,  3079,  3050,  3053,  3080,
    3081,  3098,  2532,   450,   450,  -667,  2843,    38,  3107,  3117,
     450,  2945,  2894,  2157,  2158,  2159,  2160,  2161,  2162,  2163,
    2164,  2165,  2166,  3413,  2946,  2167,  3109,   744,  3120,  3128,
     450,  3133,  2565,  3100,  3136,   450,  3131,  2574,  2575,  2576,
    2577,  2949,   450,  3138,  3139,  3141,  3144,  1842,  1843,  1844,
    1845,  1846,  1847,  1848,  1849,  1850,  1851,  3149,  2922,  1852,
    3150,  3154,  3163,   834,  3170,  3151,  3221,  3182,  3184,  3224,
    3178,  3193,  3227,  1842,  1843,  1844,  1845,  1846,  1847,  1848,
    1849,  1850,  1851,  3188,  2983,  1852,  2984,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,  3199,  2990,  3200,  3201,
    3202,  3206,  3205,  3210,  3211,  3472,  3473,  3212,  3213,  3214,
    3215,  3216,  3217,  3218,  3222,  3225,  3156,  3157,  3226,  3256,
    3228,  1842,  1843,  1844,  1845,  1846,  1847,  1848,  1849,  1850,
    1851,  3242,  3229,  1852,  3241,  3243,  3247,  3248,  3173,  3174,
    3257,  3266,  3249,  3267,  3268,  3273,  3175,  3276,  3280,  3301,
    3282,  3284,  3287,  3296,  3297,  3314,  3176,  3346,  3177,  3285,
    3347,  3286,  2896,  3289,  3522,  3523,  3324,  3348,  3363,  3351,
     271,  3366,   959,  3368,  1842,  1843,  1844,  1845,  1846,  1847,
    1848,  1849,  1850,  1851,  3367,  3369,  1852,  3373,   959,   959,
    3370,   450,  3384,  -669,  3015,  3372,  3389,  3390,  1015,  3394,
    3397,  3399,  3396,  3401,  3418,  3426,  3319,  3319,  3435,  3437,
    3428,  3427,  3429,  3430,  3322,  3548,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,  3350,  3446,  3431,  3353,  3432,
    3438,  3443,  3449,  3450,  2800,  2801,  2802,  2803,  3455,  3452,
    2804,  2805,  2806,  2807,  2808,  2809,  2810,  2811,  2812,  2813,
    2814,  2815,  2816,  2817,  2818,  2950,  2820,  2821,  2822,  2823,
    2824,  2825,  2826,  2827,  2828,  2829,  2830,  3457,  3461,  3475,
    1842,  1843,  1844,  1845,  1846,  1847,  1848,  1849,  1850,  1851,
    3480,  2951,  1852,  3022,  3483,  3484,  3464,  3253,  3393,  3478,
     959,  1842,  1843,  1844,  1845,  1846,  1847,  1848,  1849,  1850,
    1851,  3490,  3469,  1852,  3487,  3494,   959,   959,  3493,  -671,
    3502,  3516,  3524,  3532,  3543,  1015,  3510,  3514,  3411,  3544,
    3411,  3417,  2173,  1886,  2175,  3551,  1886,  3513,  1842,  1843,
    1844,  1845,  1846,  1847,  1848,  1849,  1850,  1851,  2194,  2952,
    1852,  3533,  3515,  2199,  3557,  3519,  3558,  3567,  3520,  3568,
    3525,  2208,  2209,  3526,  2211,  3539,  3545,  3534,  2215,  3547,
    3542,  3569,  3577,  3552,  3561,  3566,  3571,  3308,  3309,  1842,
    1843,  1844,  1845,  1846,  1847,  1848,  1849,  1850,  1851,  3575,
    3578,  1852,  3579,  2248,  3582,  2250,  2251,  2252,  3580,  3581,
    3584,  3460,  2953,  3585,  3586,  2267,  3587,  2269,   376,  3320,
    2903,  2276,  2277,  2278,  2279,  2280,  2281,  2422,  3162,  3470,
    3155,  1886,  2759,  2970,  3556,  3474,  3553,  3482,  3164,  2929,
    3463,  2769,  2978,  2311,  2213,  2773,  2430,  2783,  1533,  3486,
    2538,  3489,  2779,  2328,  2330,  2555,  1706,  2334,  2893,  2650,
    1537,  3345,  3240,  3362,  1712,  1544,  2341,   735,  2157,  2158,
    2159,  2160,  2161,  2162,  2163,  2164,  2165,  2166,  2887,  1548,
    2167,  3261,  2890,  3506,  1787,  3265,  2457,  2398,  2426,  2892,
     735,  2993,  2581,  2191,  2566,  1727,  1923,  2716,  3527,  3395,
    2699,  1886,  2751,  3531,  2713,  2196,  2748,  2746,  3181,  2740,
    2735,  2524,  3134,  2563,  2644,  3402,  3403,  2608,  2954,  2375,
    1626,  2238,  2202,   958,   517,   775,   518,  2418,  2549,  2226,
    2370,  1784,  2913,  2528,  2546,  3004,  3330,  2429,  3315,  2955,
    2789,  1738,     0,     0,     0,  3549,  3550,     0,     0,     0,
       0,     0,  3531,     0,  2444,     0,     0,     0,  2449,     0,
    2451,  2935,  2453,     0,   525,     0,     0,     0,     0,     0,
       0,     0,  3570,     0,  3572,   392,  2956,     0,     0,   958,
     958,   958,   958,   735,     0,   958,   958,   958,   958,   958,
     958,   958,   958,   958,   958,   958,   958,   958,   958,   958,
     958,     0,   393,   958,   958,   958,   958,   958,   958,   958,
     958,   958,   958,   958,     0,     0,     0,  2961,     0,  2505,
    2506,     0,  2508,     0,   535,   536,     0,     0,     0,     0,
       0,     0,     0,  2967,     0,     0,     0,     0,     0,  1144,
       0,     0,  2530,  2531,    38,     0,  1886,     0,     0,     0,
       0,     0,     0,     0,  2413,  2982,     0,   542,     0,     0,
       0,     0,     0,     0,  2553,     0,     0,    38,   545,  2987,
     776,     0,   931,     0,   432,  2939,  1842,  1843,  1844,  1845,
    1846,  1847,  1848,  1849,  1850,  1851,  2580,     0,  1852,   552,
       0,     0,     0,     0,     0,     0,  2977,     0,     0,     0,
       0,     0,     0,     0,     0,   566,     0,     0,     0,     0,
       0,     0,     0,   932,  2157,  2158,  2159,  2160,  2161,  2162,
    2163,  2164,  2165,  2166,     0,     0,  2167,     0,     0,     0,
    2623,   736,     0,  2628,  2629,     0,     0,     0,     0,     0,
       0,  2636,     0,  2638,  2639,  2640,  2641,  2642,     0,     0,
     394,   933,   586,     0,   736,     0,     0,   588,     0,     0,
      38,     0,     0,   934,     0,     0,     0,     0,     0,     0,
       0,     0,  2671,  2672,     0,   935,   936,     0,     0,     0,
    2679,     0,     0,     0,   396,   397,  2157,  2158,  2159,  2160,
    2161,  2162,  2163,  2164,  2165,  2166,     0,  3293,  2167,  2157,
    2158,  2159,  2160,  2161,  2162,  2163,  2164,  2165,  2166,    38,
       0,  2167,  1886,     0,     0,     0,     0,     0,     0,  2720,
    2721,  2722,     0,  2724,     0,     0,  2727,  2728,     0,     0,
       0,     0,  2733,  2734,     0,     0,     0,     0,     0,     0,
       0,     0,  1886,  1886,     0,     0,     0,   736,     0,     0,
       0,   780,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  2765,     0,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,     0,     0,     0,     0,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,     0,     0,     0,     0,     0,
       0,  1145,  1146,  1147,  1148,   782,  1149,  1150,  1151,  1152,
    1153,  1154,  1155,  1156,  1157,  1158,  1159,  1160,  1161,  1162,
    1163,  1164,  1165,  1166,  1167,  1168,  1169,  1170,  1171,  1636,
       0,     0,  3057,     0,     0,   937,   938,     0,     0,     0,
    3077,     0,   939,   940,   941,   942,   943,   944,   945,   946,
     947,   948,   949,     0,     0,     0,   950,     0,     0,     0,
     951,   952,   953,   954,   955,     0,     0,     0,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3130,     0,     0,
       0,     0,     0,  3135,  3058,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  3142,     0,     0,  3059,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,  1542,  2530,  2531,
       0,     0,  3171,     0,     0,     0,     0,     0,     0,     0,
    1886,  1886,     0,     0,     0,     0,     0,  1172,  1173,  1174,
    2157,  2158,  2159,  2160,  2161,  2162,  2163,  2164,  2165,  2166,
       0,     0,  2167,     0,     0,     0,     0,     0,  3185,     0,
       0,     0,     0,     0,    38,     0,     0,     0,     0,  3189,
       0,     0,     0,     0,  3294,     0,     0,     0,  1543,  2157,
    2158,  2159,  2160,  2161,  2162,  2163,  2164,  2165,  2166,     0,
       0,  2167,   931,     0,  2157,  2158,  2159,  2160,  2161,  2162,
    2163,  2164,  2165,  2166,     0,   392,  2167,  2157,  2158,  2159,
    2160,  2161,  2162,  2163,  2164,  2165,  2166,     0,     0,  2167,
    2157,  2158,  2159,  2160,  2161,  2162,  2163,  2164,  2165,  2166,
       0,     0,  2167,   932,     0,     0,   956,     0,  1760,   958,
    1761,     0,   422,     0,  3230,  3231,  1546,   958,     0,     0,
       0,     0,  3232,     0,     0,     0,     0,     0,     0,  2926,
       0,     0,  3233,     0,  3234,     0,     0,     0,     0,     0,
       0,   933,  2157,  2158,  2159,  2160,  2161,  2162,  2163,  2164,
    2165,  2166,     0,   934,  2167,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    38,   935,   936,  1842,  1843,  1844,
    1845,  1846,  1847,  1848,  1849,  1850,  1851,  1547,     0,  1852,
       0,     0,     0,     0,     0,     0,     0,  3269,  3270,     0,
    3272,     0,     0,     0,     0,     0,     0,     0,  3279,    38,
       0,     0,   958,     0,     0,     0,     0,     0,     0,  2157,
    2158,  2159,  2160,  2161,  2162,  2163,  2164,  2165,  2166,     0,
       0,  2167,  1726,  2157,  2158,  2159,  2160,  2161,  2162,  2163,
    2164,  2165,  2166,     0,  1886,  2167,  1886,     0,  3060,     0,
       0,  3311,     0,  3312,     0,     0,     0,     0,     0,     0,
       0,     0,  3317,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,     0,     0,     0,     0,     0,  3061,     0,     0,
       0,     0,     0,     0,     0,   958,   958,     0,     0,     0,
       0,     0,  3062,    38,  3359,     0,     0,     0,     0,     0,
       0,     0,  3361,     0,     0,  3065,  1732,  2157,  2158,  2159,
    2160,  2161,  2162,  2163,  2164,  2165,  2166,     0,  3066,  2167,
       0,     0,     0,     0,     0,  1737,  1886,  1886,     0,     0,
       0,     0,     0,     0,     0,   937,   938,     0,     0,     0,
       0,     0,   939,   940,   941,   942,   943,   944,   945,   946,
     947,   948,   949,  1750,     0,     0,   950,     0,     0,     0,
     951,   952,   953,   954,   955,     0,     0,     0,     0,     0,
    3067,     0,     0,     0,     0,     0,  1753,    38,     0,     0,
       0,     0,  3422,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,   958,     0,     0,     0,     0,     0,     0,  1783,
       0,     0,     0,     0,     0,     0,  3433,  3434,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,  3068,  3451,  1242,
    1243,  1244,  1245,  1246,  1247,  1248,     0,     0,  1249,  1250,
       0,  3069,  1251,  1252,  1253,  1254,  1255,  1256,  1257,  1258,
    1259,    38,  1886,  1260,  1261,  1262,  1263,  1264,  1265,  1266,
       0,     0,     0,     0,     0,     0,     0,     0,  2139,  2140,
      38,     0,     0,  3481,     0,     0,  1267,  1268,  1269,  1270,
    1271,     0,     0,  1272,  1273,  1274,  1275,  1276,  3495,  1277,
    1278,  1279,  1280,  1281,  1282,  1283,     0,     0,    38,  1284,
    1285,  1286,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    38,     0,     0,     0,  3070,     0,     0,  2828,     0,
       0,  2157,  2158,  2159,  2160,  2161,  2162,  2163,  2164,  2165,
    2166,     0,     0,  2167,     0,     0,   956,  3538,  1760,     0,
    1761,     0,     0,     0,    38,     0,     0,     0,     0,     0,
       0,  1886,     0,  1886,     0,     0,     0,     0,     0,     0,
       0,     0,  1287,     0,     0,     0,     0,     0,  3422,     0,
       0,     0,     0,     0,     0,  3559,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,     0,     0,     0,   958,   958,
       0,     0,     0,     0,     0,   958,  2157,  2158,  2159,  2160,
    2161,  2162,  2163,  2164,  2165,  2166,  3583,     0,  2167,     0,
     958,   958,     0,     0,     0,     0,     0,  1786,   958,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   958,     0,
     958,     0,     0,     0,     0,     0,     0,     0,  1789,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  1886,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,     0,     0,     0,     0,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,  3071,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3238,  1886,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    38,  3110,     0,     0,  2940,  1842,  1843,  1844,
    1845,  1846,  1847,  1848,  1849,  1850,  1851,   375,  1886,  1852,
       0,  1886,     0,    38,     0,     0,     0,     0,     0,     0,
       0,     1,     2,     0,  3140,     0,     0,  2905,  2157,  2158,
    2159,  2160,  2161,  2162,  2163,  2164,  2165,  2166,  1886,     0,
    2167,     0,     0,     0,  3072,     0,     3,     4,     5,     6,
       7,     0,     0,   958,     8,     0,     0,     0,     0,     0,
       0,     9,     0,     0,     0,     0,     0,     0,     0,   958,
     958,    10,    11,    12,     0,     0,     0,    13,     0,    14,
      15,    16,    17,    18,     0,     0,     0,     0,     0,     0,
       0,    19,    20,     0,     0,     0,     0,  3143,     0,    21,
       0,  1886,     0,  3329,     0,  1886,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    22,    23,    24,    25,     0,
       0,     0,     0,     0,     0,     0,    26,     0,    27,    28,
       0,     0,     0,  1886,     0,     0,     0,     0,     0,     0,
       0,     0,    29,     0,     0,     0,     0,     0,    38,  3055,
    2157,  2158,  2159,  2160,  2161,  2162,  2163,  2164,  2165,  2166,
      30,     0,  2167,     0,     0,     0,     0,     0,     0,    31,
       0,     0,     0,     0,  1886,     0,     0,     0,     0,    38,
       0,   958,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    32,    33,    34,    35,   958,   958,    36,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
       0,    38,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    39,    38,    40,  2906,    41,    42,     0,     0,     0,
    1886,     0,     0,    43,     0,     0,    44,     0,    45,    46,
    3152,     0,     0,    47,    48,     0,     0,     0,  1886,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1886,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    49,    50,
       0,    51,    52,    53,     0,    54,    55,     0,     0,     0,
       0,    56,     0,     0,    57,     0,     0,     0,     0,    58,
      59,     0,     0,     0,     0,     0,    60,     0,    61,    62,
      63,  1886,    64,     0,     0,     0,    65,  1886,     0,     0,
       0,     0,    66,    67,    68,    69,    70,    71,    72,    73,
      74,     0,     0,     0,  1886,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,     0,  1886,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    75,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,     0,     0,     0,
       0,     0,     0,     0,     0,    38,     0,     0,     0,     0,
       0,    76,     0,     0,     0,  1842,  1843,  1844,  1845,  1846,
    1847,  1848,  1849,  1850,  1851,     0,     0,  1852,     0,     0,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,     0,
       0,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
       0,     0,     0,     1,     2,     0,  2157,  2158,  2159,  2160,
    2161,  2162,  2163,  2164,  2165,  2166,    96,    97,  2167,     0,
      98,    99,   100,   101,   102,   103,   104,   105,     3,     4,
       5,     6,     7,     0,     0,   106,     8,     0,    38,     0,
     107,   108,  2294,     9,     0,     0,     0,   109,     0,     0,
       0,     0,     0,    10,    11,    12,     0,     0,     0,    13,
       0,    14,    15,    16,    17,    18,     0,     0,     0,   110,
     111,     0,     0,    19,    20,     0,     0,     0,     0,     0,
       0,    21,     0,  2157,  2158,  2159,  2160,  2161,  2162,  2163,
    2164,  2165,  2166,     0,     0,  2167,   112,    22,    23,    24,
      25,     0,     0,   931,     0,     0,     0,     0,    26,     0,
      27,    28,     0,     0,     0,     0,     0,     0,    38,     0,
       0,     0,     0,     0,    29,     0,     0,     0,  1842,  1843,
    1844,  1845,  1846,  1847,  1848,  1849,  1850,  1851,    38,     0,
    1852,     0,    30,     0,   932,     0,     0,     0,     0,     0,
       0,    31,     0,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,  3153,     0,    32,    33,    34,    35,     0,
       0,    36,   933,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    37,     0,   934,     0,  1842,  1843,  1844,  1845,
    1846,  1847,  1848,  1849,  1850,  1851,   935,   936,  1852,     0,
       0,     0,     0,    38,  3056,  2157,  2158,  2159,  2160,  2161,
    2162,  2163,  2164,  2165,  2166,     0,     0,  2167,     0,     0,
       0,     0,     0,    39,  3190,    40,     0,    41,    42,     0,
      38,     0,     0,     0,     0,    43,     0,   448,    44,     0,
      45,    46,     0,     0,     0,    47,    48,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,     0,     0,     0,     0,
      49,    50,     0,    51,    52,    53,     0,    54,    55,     0,
       0,     0,     0,    56,     0,     0,    57,     0,     0,     0,
       0,    58,    59,     0,     0,     0,     0,     0,    60,  2168,
      61,    62,    63,     0,    64,     0,     0,     0,    65,     0,
       0,     0,     0,     0,    66,    67,    68,    69,    70,    71,
      72,    73,    74,     0,     0,     0,     0,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,  3196,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,   937,   938,     0,    75,
       0,     0,     0,   939,   940,   941,   942,   943,   944,   945,
     946,   947,   948,   949,    38,     0,     0,   950,     0,     0,
    3009,   951,   952,   953,   954,   955,     0,     0,     0,     0,
       0,     0,     0,    76,  1842,  1843,  1844,  1845,  1846,  1847,
    1848,  1849,  1850,  1851,  3197,     0,  1852,     0,     0,     0,
       0,     0,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,     0,     0,     0,     0,     0,     0,     0,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,  2985,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    96,    97,
       0,     0,    98,    99,   100,   101,   102,   103,   104,   105,
       0,     0,     0,     0,     0,   516,   517,   106,   518,     0,
     519,   520,   107,   108,     0,   521,     0,     0,   522,   109,
     523,     0,     0,   448,     0,  1842,  1843,  1844,  1845,  1846,
    1847,  1848,  1849,  1850,  1851,     0,     0,  1852,   524,     0,
       0,   110,   111,     0,     0,     0,   525,   391,     0,     0,
       0,     0,     0,     0,   526,   527,     0,   392,     0,     0,
       0,   528,   529,   530,     0,     0,     0,     0,   112,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   531,
       0,   532,   429,   430,   533,     0,     0,     0,   534,     0,
       0,     0,     0,     0,   422,     0,     0,   956,     0,  1760,
       0,  1761,     0,     0,     0,     0,   535,   536,   537,     0,
       0,     0,     0,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,     0,     0,   538,   539,   540,     0,   541,   542,
     543,   431,  3204,     0,     0,     0,     0,     0,     0,   544,
     545,     0,     0,   546,   547,     0,   432,   548,   549,     0,
     550,   551,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   552,   553,   554,   555,   556,   557,   558,   559,   560,
       0,     0,   561,   562,   563,   564,   565,   566,     0,     0,
       0,     0,     0,     0,     0,     0,   567,   568,   433,   569,
     570,   571,   572,   573,   574,     0,   575,   576,     0,     0,
     577,   578,     0,     0,    38,   579,     0,     0,     0,   580,
     581,   582,     0,     0,     0,   583,     0,   584,   931,   585,
       0,     0,   394,   395,   586,     0,   587,     0,     0,   588,
     589,   590,     0,     0,     0,    38,     0,   591,     0,   592,
       0,     0,     0,  3303,  3207,     0,     0,     0,     0,   931,
     593,  1550,     0,     0,     0,   594,   396,   397,     0,   932,
     595,     0,     0,     0,   596,     0,     0,     0,     0,     0,
       0,     0,   931,     0,   463,     0,   597,   598,     0,     0,
     599,     0,  1550,     0,     0,     0,     0,     0,     0,     0,
     932,     0,     0,     0,     0,   600,     0,  1551,     0,     0,
     464,     0,     0,     0,     0,  1550,     0,   601,   602,  1552,
       0,     0,   603,   932,     0,     0,     0,     0,     0,     0,
       0,  1553,  1554,     0,     0,   604,     0,     0,  1551,     0,
       0,     0,     0,     0,     0,     0,   398,   399,     0,     0,
    1552,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1551,  1553,  1554,     0,    38,     0,     0,     0,  1555,
       0,     0,     0,  1552,  1814,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1553,  1554,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,     0,     0,     0,
    1555,     0,     0,     0,     0,     0,     0,     0,  1842,  1843,
    1844,  1845,  1846,  1847,  1848,  1849,  1850,  1851,     0,    38,
    1852,     0,     0,  1555,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   605,     0,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,     0,     0,     0,     0,     0,   606,   434,
     435,     0,     0,     0,  1791,     0,   607,     0,     0,  1577,
    1578,  1556,  1557,     0,     0,     0,     0,     0,  1558,  1559,
    1560,  1561,  1562,  1563,  1564,  1565,  1566,  1567,  1568,     0,
       0,     0,  1569,     0,     0,  2440,  1570,  1571,  1572,     0,
       0,     0,  1556,  1557,     0,     0,     0,   608,   609,  1558,
    1559,  1560,  1561,  1562,  1563,  1564,  1565,  1566,  1567,  1568,
       0,     0,     0,  1569,  2798,  3419,  3420,  1570,  1571,  1572,
       0,     0,  1558,  1559,  1560,  1561,  1562,  1563,  1564,  1565,
    1566,  1567,  1568,  1897,  2896,  2897,  1569,     0,     0,     0,
    1570,  1571,  1572,    38,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,  1815,     0,     0,     0,     0,     0,    38,
       0,     0,     0,     0,     0,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,   931,     0,  3304,    38,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,   931,    38,     0,
       0,     0,     0,     0,     0,     0,     0,  1550,     0,     0,
       0,     0,     0,     0,     0,   932,  1842,  1843,  1844,  1845,
    1846,  1847,  1848,  1849,  1850,  1851,   931,     0,  1852,     0,
    1550,     0,     0,     0,     0,     0,     0,     0,   932,  2157,
    2158,  2159,  2160,  2161,  2162,  2163,  2164,  2165,  2166,     0,
       0,  2167,     0,  1551,     0,     0,     0,     0,     0,  1550,
    3421,     0,  1573,     0,     0,  1552,     0,   932,     0,     0,
       0,     0,     0,     0,     0,     0,  1551,  1553,  1554,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1552,     0,
       0,     0,     0,  1573,     0,     0,     0,     0,     0,     0,
    1553,  1554,     0,     0,     0,  1551,     0,     0,     0,     0,
       0,    38,     0,     0,     0,  1555,  1573,  1552,  3129,  2157,
    2158,  2159,  2160,  2161,  2162,  2163,  2164,  2165,  2166,  1553,
    1554,  2167,     0,     0,    38,     0,     0,     0,  1555,     0,
       0,     0,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
    1579,     0,     0,    38,     0,     0,     0,  1555,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,     0,     0,     0,
       0,     0,     0,     0,     0,    38,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,     0,     0,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,  2898,     0,     0,     0,     0,
       0,     0,     0,     0,  3305,     0,     0,  1556,  1557,     0,
       0,     0,     0,     0,  1558,  1559,  1560,  1561,  1562,  1563,
    1564,  1565,  1566,  1567,  1568,     0,     0,  3316,  1569,     0,
    1556,  1557,  1570,  1571,  1572,     0,     0,  1558,  1559,  1560,
    1561,  1562,  1563,  1564,  1565,  1566,  1567,  1568,     0,  3253,
    3254,  1569,     0,     0,     0,  1570,  1571,  1572,     0,  1556,
    1557,     0,    38,     0,     0,  2200,  1558,  1559,  1560,  1561,
    1562,  1563,  1564,  1565,  1566,  1567,  1568,     0,     0,     0,
    1569,     0,     0,     0,  1570,  1571,  1572,     0,     0,     0,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    38,
       0,     0,     0,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,   931,    38,     0,     0,     0,     0,     0,     0,
       0,     0,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    38,     0,   931,     0,     0,     0,     0,     0,     0,
       0,     0,  3476,   932,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,     0,     0,  3477,  1550,     0,     0,     0,
       0,     0,     0,     0,   932,     0,     0,     0,     0,     0,
       0,   933,     0,  2157,  2158,  2159,  2160,  2161,  2162,  2163,
    2164,  2165,  2166,   934,  3528,  2167,     0,     0,  1573,     0,
       0,     0,     0,     0,     0,   935,   936,     0,   448,     0,
       0,     0,  1551,     0,     0,     0,     0,     0,     0,     0,
       0,  1573,     0,     0,  1552,     0,  2157,  2158,  2159,  2160,
    2161,  2162,  2163,  2164,  2165,  2166,  1553,  1554,  2167,    38,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1573,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      38,     0,     0,     0,  1555,     0,     0,     0,     0,     0,
       0,     0,     0,  2465,  2157,  2158,  2159,  2160,  2161,  2162,
    2163,  2164,  2165,  2166,     0,     0,  2167,     0,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,     0,     0,     0,
       0,     0,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
    3255,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,     0,
       0,     0,     0,     0,     0,   937,   938,     0,     0,     0,
       0,     0,   939,   940,   941,   942,   943,   944,   945,   946,
     947,   948,   949,     0,     0,     0,   950,     0,     0,     0,
     951,   952,   953,   954,   955,     0,  1556,  1557,     0,     0,
       0,  3354,     0,  1558,  1559,  1560,  1561,  1562,  1563,  1564,
    1565,  1566,  1567,  1568,     0,   516,     0,  1569,   518,     0,
       0,  1570,  1571,  1572,     0,   521,     0,  3106,     0,   849,
     523,     0,     0,  1842,  1843,  1844,  1845,  1846,  1847,  1848,
    1849,  1850,  1851,     0,  3355,  1852,     0,     0,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,     0,     0,     0,
       0,   528,   529,   530,   850,   851,     0,   219,   220,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,     0,     0,
       0,     0,  3356,   852,     0,   853,     0,     0,     0,     0,
       0,     0,   516,     0,     0,   518,   535,   536,   537,     0,
       0,     0,     0,     0,     0,   522,   849,   854,   855,  1842,
    1843,  1844,  1845,  1846,  1847,  1848,  1849,  1850,  1851,     0,
       0,  1852,     0,     0,   538,   539,   540,     0,     0,     0,
       0,     0,     0,     0,   856,     0,     0,     0,     0,     0,
       0,   819,     0,     0,     0,     0,     0,     0,   528,   529,
     530,   850,   851,     0,     0,     0,     0,     0,     0,   857,
       0,     0,     0,     0,     0,     0,   956,     0,     0,     0,
       0,  1842,  1843,  1844,  1845,  1846,  1847,  1848,  1849,  1850,
    1851,     0,   853,  1852,     0,     0,     0,   568,     0,     0,
       0,     0,     0,   535,   536,   537,     0,  1573,     0,     0,
       0,     0,     0,     0,   854,   855,     0,  1037,  2157,  2158,
    2159,  2160,  2161,  2162,  2163,  2164,  2165,  2166,     0,     0,
    2167,   538,   539,   540,   586,   858,     0,   859,     0,   588,
       0,     0,   860,   861,    38,     0,     0,   591,   819,   592,
       0,  3404,     0,   432,     0,     0,     0,     0,     0,     0,
     593,   480,     0,     0,     0,     0,     0,     0,    38,     0,
       0,     0,   862,     0,     0,     0,     0,     0,     0,     0,
       0,   863,     0,   864,   463,     0,     0,     0,     0,     0,
     599,   481,   865,   516,   568,     0,   518,     0,     0,     0,
       0,   866,   867,   868,     0,     0,     0,   849,     0,     0,
     464,     0,     0,     0,     0,     0,     0,   601,   602,     0,
       0,     0,   603,     0,     0,     0,     0,     0,     0,     0,
       0,   586,   858,     0,   859,     0,   588,     0,     0,   860,
     861,     0,     0,     0,     0,     0,   592,  3467,     0,   528,
     529,   530,   850,   851,     0,     0,     0,   593,   480,  2157,
    2158,  2159,  2160,  2161,  2162,  2163,  2164,  2165,  2166,   862,
       0,  2167,     0,   448,     0,     0,     0,     0,   863,     0,
     864,   463,     0,   853,  1065,     0,     0,   599,   481,   865,
       0,     0,     0,     0,   535,   536,   537,   448,   866,   867,
     868,     0,     0,     0,     0,   854,   855,   464,     0,  3468,
       0,     0,     0,     0,   601,   602,     0,     0,     0,   603,
       0,     0,   538,   539,   540,  2157,  2158,  2159,  2160,  2161,
    2162,  2163,  2164,  2165,  2166,     0,     0,  2167,    38,   819,
       0,     0,     0,     0,     0,     0,  3491,  1038,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1081,    38,     0,
       0,   605,     0,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    38,     0,     0,   568,     0,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,   516,     0,     0,   518,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     849,     0,   586,   858,     0,   859,     0,   588,     0,  1039,
     860,   861,     0,     0,     0,     0,     0,   592,  2157,  2158,
    2159,  2160,  2161,  2162,  2163,  2164,  2165,  2166,   593,   480,
    2167,     0,     0,     0,     0,     0,     0,     0,   605,     0,
     862,     0,   528,   529,   530,   850,   851,   448,     0,   863,
       0,   864,   463,     0,     0,     0,     0,     0,   599,   481,
     865,     0,     0,     0,     0,  2443,     0,   448,     0,   866,
     867,   868,     0,     0,     0,     0,   853,  1065,   464,     0,
       0,     0,  3113,     0,     0,   601,   602,   535,   536,   537,
     603,   448,     0,     0,  1066,     0,  1082,     0,   854,   855,
       0,     0,    38,     0,     0,     0,  3159,     0,     0,     0,
       0,     0,     0,     0,     0,   538,   539,   540,     0,     0,
       0,    38,  2157,  2158,  2159,  2160,  2161,  2162,  2163,  2164,
    2165,  2166,   819,  3492,  2167,     0,     0,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    38,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    38,     0,   568,     0,
       0,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      38,  3306,  1842,  1843,  1844,  1845,  1846,  1847,  1848,  1849,
    1850,  1851,     0,     0,  1852,   586,   858,     0,   859,     0,
     588,     0,     0,   860,   861,     0,     0,     0,     0,   605,
     592,   448,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   593,   480,     0,     0,     0,  3535,     0,     0,     0,
       0,     0,     0,   862,     0,     0,   267,     0,     0,     0,
      38,     0,   863,     0,   864,   463,     0,     0,     0,     0,
       0,   599,   481,   865,     0,     0,  3191,     0,     0,     0,
       0,     0,   866,   867,   868,     0,     0,     0,     0,     0,
       0,   464,     0,     0,     0,     0,  3192,     0,   601,   602,
       0,     0,     0,   603,     0,     0,     0,  1066,     0,     0,
       0,     0,     0,     0,     0,    38,     0,     0,     0,     0,
    3195,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    38,
    3307,  1842,  1843,  1844,  1845,  1846,  1847,  1848,  1849,  1850,
    1851,     0,     0,  1852,     0,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,     0,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    38,     0,     0,     0,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,     0,     0,
       0,     0,   605,  2157,  2158,  2159,  2160,  2161,  2162,  2163,
    2164,  2165,  2166,     0,    38,  2167,     0,     0,     0,     0,
    3203,  3357,  2157,  2158,  2159,  2160,  2161,  2162,  2163,  2164,
    2165,  2166,     0,    38,  2167,     0,     0,   229,   230,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    38,     0,
       0,  3358,  2157,  2158,  2159,  2160,  2161,  2162,  2163,  2164,
    2165,  2166,   237,   238,  2167,     0,     0,    38,  3379,  2157,
    2158,  2159,  2160,  2161,  2162,  2163,  2164,  2165,  2166,     0,
       0,  2167,   248,   249,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    38,     0,     0,     0,   268,  2157,  2158,
    2159,  2160,  2161,  2162,  2163,  2164,  3479,  2166,     0,     0,
    2167,     0,    38,     0,     0,     0,     0,     0,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,  2157,  2158,  2159,
    2160,  2161,  2162,  2163,  2164,  2165,  2166,     0,     0,  2167,
       0,     0,    38,     0,     0,     0,   280,   281,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,  2157,  2158,  2159,  2160,  2161,  2162,  2163,  2164,
    2165,  2166,     0,     0,  2167,     0,     0,     0,     0,  2863,
       0,   299,   300,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,     0,     0,     0,     0,   312,   313,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,     0,    38,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     315,   316,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
     318,   319,   267,    38,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  3560,     0,     0,     0,   321,
     322,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
       0,     0,     0,     0,   325,   326,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    38,     0,     0,     0,   267,
       0,     0,     0,   339,   340,     0,     0,     0,     0,     0,
    3574,     0,     0,     0,     0,   832,     0,     0,     0,     0,
       0,     0,     0,     0,    38,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   352,
     353,  2157,  2158,  2159,  2160,  2161,  2162,  2163,  2164,  2165,
    2166,     0,    38,  2167,     0,     0,     0,     0,     0,   289,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   832,     0,     0,     0,     0,     0,     0,     0,
       0,    38,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   329,
       0,     0,     0,     0,    38,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,   448,     0,     0,     0,     0,     0,
       0,     0,     0,    38,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   448,     0,     0,     0,     0,     0,     0,
       0,     0,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,   448,     0,     0,     0,     0,     0,     0,     0,     0,
      38,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     448,     0,     0,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,   448,     0,     0,     0,     0,     0,     0,
       0,     0,   833,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,   448,     0,     0,     0,     0,  -565,     0,     0,
       0,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  2925,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,   922,
       0,     0,     0,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    38,     0,     0,     0,     0,     0,     0,     0,
       0,   449,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    38,     0,     0,     0,     0,     0,     0,     0,     0,
     507,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   722,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    38,     0,
       0,     0,     0,     0,     0,     0,     0,   765,     0,     0,
       0,  2157,  2158,  2159,  2160,  2161,  2162,  2163,  2164,  2165,
    2166,    38,     0,  2167,     0,     0,     0,     0,     0,     0,
     920,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   448,     0,     0,  2157,  2158,  2159,  2160,  2161,  2162,
    2163,  2164,  2165,  2166,     0,     0,  2167,     0,     0,   921,
    2157,  2158,  2159,  2160,  2161,  2162,  2163,  2164,  2165,  2166,
     448,     0,  2167,  2157,  2158,  2159,  2160,  2161,  2162,  2163,
    2164,  2165,  2166,     0,     0,  2167,     0,     0,     0,   448,
       0,  2157,  2158,  2159,  2160,  2161,  2162,  2163,  2164,  2165,
    2166,     0,     0,  2167,     0,     0,     0,    38,     0,     0,
       0,     0,     0,     0,     0,     0,   923,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   448,     0,     0,
       0,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
     448,     0,     0,     0,     0,     0,     0,     0,     0,    38,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,  2157,  2158,
    2159,  2160,  2161,  2162,  2163,  2164,  2165,  2166,     0,     0,
    2167,     0,     0,     0,     0,     0,    38,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,   448,  2891,     0,     0,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   961,    38,
    2934,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  2994,     0,   448,     0,
       0,     0,     0,     0,     0,     0,     0,   989,    38,  2995,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1011,  2996,     0,     0,
       0,     0,     0,     0,     0,    38,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,   448,     0,     0,     0,     0,
       0,     0,     0,     0,  1048,    38,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  1064,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,     0,   448,     0,
       0,     0,     0,     0,     0,     0,     0,    38,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2997,     0,     0,  1092,     0,     0,
       0,     0,     0,     0,     0,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,  1097,     0,     0,     0,     0,     0,
       0,     0,     0,  1071,    38,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1102,     0,     0,     0,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,     0,     0,     0,
       0,     0,     0,     0,     0,  1077,    38,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,  1109,     0,     0,     0,
       0,     0,     0,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1088,    38,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,   448,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1089,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,   448,     0,     0,     0,     0,
       0,     0,     0,     0,  1093,    38,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  2157,  2158,
    2159,  2160,  2161,  2162,  2163,  2164,  2165,  2166,     0,     0,
    2167,  1098,    38,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,  1942,     0,     0,     0,     0,     0,     0,     0,
       0,  1103,    38,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   448,     0,     0,     0,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1110,    38,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2854,     0,     0,     0,     0,     0,
       0,     0,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,   448,     0,     0,     0,     0,     0,     0,     0,     0,
    1142,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
       0,   448,     0,     0,     0,     0,     0,     0,     0,     0,
      38,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1369,    38,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,   448,  3132,     0,     0,     0,     0,     0,
       0,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      38,     0,     0,     0,     0,     0,     0,     0,     0,  1943,
       0,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
       0,     0,     0,     0,     0,     0,     0,     0,  2853,    38,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   448,
       0,     0,     0,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,   448,     0,     0,     0,     0,     0,     0,     0,
       0,  2855,  1842,  1843,  1844,  1845,  1846,  1847,  1848,  1849,
    1850,  1851,     0,     0,  1852,     0,     0,     0,     0,    38,
       0,     0,     0,     0,     0,     0,     0,     0,  2860,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   448,
       0,     0,  2157,  2158,  2159,  2160,  2161,  2162,  2163,  2164,
    2165,  2166,     0,     0,  2167,     0,     0,     0,  2861,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,   448,     0,
       0,     0,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    38,     0,     0,     0,     0,     0,     0,     0,     0,
    2862,     0,     0,     0,  2157,  2158,  2159,  2160,  2161,  2162,
    2163,  2164,  2165,  2166,     0,     0,  2167,     0,    38,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,  2972,     0,
       0,     0,     0,     0,     0,     0,     0,    38,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    38,     0,     0,
       0,     0,     0,     0,     0,     0,  2881,     0,     0,     0,
    2157,  2158,  2159,  2160,  2161,  2162,  2163,  2164,  2165,  2166,
      38,     0,  2167,     0,     0,     0,     0,     0,     0,  2895,
       0,     0,     0,     0,     0,     0,     0,     0,  3158,     0,
    2972,     0,     0,     0,     0,     0,     0,     0,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,   448,     0,     0,
       0,     0,     0,     0,     0,     0,  2936,    38,  3172,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   448,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,     0,     0,     0,
       0,     0,     0,     0,     0,  2971,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   448,     0,     0,     0,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,   448,
    3183,     0,     0,     0,     0,     0,     0,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2973,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,     0,   448,     0,     0,     0,
       0,     0,     0,     0,     0,    38,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,   448,  3194,     0,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    38,     0,
       0,     0,     0,     0,     0,     0,     0,  2975,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  2988,     0,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,     0,     0,     0,     0,     0,
       0,     0,     0,  2989,    38,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,   448,     0,     0,     0,     0,     0,
       0,     0,     0,  2991,    38,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    38,     0,  2998,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3391,     0,  2157,
    2158,  2159,  2160,  2161,  2162,  2163,  2164,  2165,  2166,     0,
       0,  2167,     0,     0,     0,     0,  3409,     0,     0,     0,
       0,     0,     0,     0,     0,    38,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3005,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,  3409,     0,     0,     0,     0,     0,     0,
       0,     0,  3017,    38,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    38,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  2157,  2158,  2159,
    2160,  2161,  2162,  2163,  2164,  2165,  2166,     0,     0,  2167,
       0,     0,     0,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    38,     0,     0,     0,     0,     0,     0,     0,
       0,  3310,     0,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,  3415,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    38,     0,  3392,  3271,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    38,     0,  3410,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    38,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,     0,     0,     0,     0,     0,     0,
    3414,     0,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    38,     0,     0,     0,     0,     0,     0,     0,     0,
    2236,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    2239,     0,     0,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,  3274,  2157,  2158,  2159,  2160,  2161,  2162,
    2163,  2164,  2165,  2166,     0,     0,  2167,     0,     0,    38,
       0,  2241,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,     0,     0,     0,     0,     0,     0,     0,     0,  3416,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    38,
    2394,  2342,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      38,  2447,     0,     0,     0,     0,     0,     0,  2376,     0,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,     0,     0,
       0,     0,     0,     0,     0,  3352,    38,     0,  2458,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3281,     0,     0,     0,  3488,     0,    38,  2522,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    38,     0,  2556,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   267,     0,     0,     0,    38,     0,  2561,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    38,     0,
       0,     0,     0,     0,     0,     0,     0,  2567,     0,     0,
       0,     0,     0,   267,     0,     0,     0,    38,     0,     0,
       0,     0,     0,     0,     0,     0,  2570,     0,     0,     0,
       0,     0,   267,     0,     0,     0,     0,    38,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    38,     0,     0,
       0,     0,     0,     0,     0,  1811,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  2582,     0,     0,     0,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    38,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   267,     0,     0,  2606,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,     0,     0,     0,
       0,     0,     0,     0,     0,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,  1012,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    38,  2714,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    38,     0,  2992,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,   448,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,  2794,     0,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,  2303,  2304,  2305,  1842,  1843,
    1844,  1845,  1846,  1847,  1848,  1849,  1850,  1851,     0,     0,
    1852,     0,     0,     0,     0,     0,     0,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,  2157,  2158,  2159,  2160,  2161,  2162,
    2163,  2164,  2165,  2166,     0,     0,  2167,  2157,  2158,  2159,
    2160,  2161,  2162,  2163,  2164,  2165,  2166,     0,     0,  2167,
       0,     0,     0,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,  3349,  2157,  2158,  2159,  2160,  2161,  2162,  2163,  2164,
    2165,  2166,     0,     0,  2167,     0,     0,     0,     0,     0,
       0,     0,     0,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,  3485,  2157,  2158,  2159,  2160,  2161,  2162,  2163,  2164,
    2165,  2166,     0,     0,  2167,  2157,  2158,  2159,  2160,  2161,
    2162,  2163,  2164,  2165,  2166,     0,     0,  2167,  2157,  2158,
    2159,  2160,  2161,  2162,  2163,  2164,  2165,  2166,     0,     0,
    2167,  2157,  2158,  2159,  2160,  2161,  2162,  2163,  2164,  2165,
    2166,     0,     0,  2167,  2157,  2158,  2159,  2160,  2161,  2162,
    2163,  2164,  2165,  2166,     0,     0,  2167,     0,     0,     0,
       0,     0,     0,     0,  3292,  1842,  1843,  1844,  1845,  1846,
    1847,  1848,  1849,  1850,  1851,     0,     0,  1852,  2157,  2158,
    2159,  2160,  2161,  2162,  2163,  2164,  2165,  2166,     0,     0,
    2167,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3302,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  3313,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3380,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  3381,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3386,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  3405,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  3406,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    3408,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  3462,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  3509
  };

  const short int
  parser::yycheck_[] =
  {
       0,   258,   274,     3,   512,   737,  1013,   808,   993,     9,
     767,   353,   238,   369,    14,   331,  1707,   333,   220,   335,
     238,    21,   220,   238,   366,   238,   220,   238,   249,   257,
     238,   322,   238,    33,   358,   257,   238,   238,   358,   238,
     238,    41,    42,    43,   347,   356,    46,   347,   249,    49,
     249,   257,    52,  1743,   358,   366,   257,   257,   257,    59,
      60,    61,    62,   347,    64,    65,    66,    67,    68,   356,
      70,    71,   238,   356,   316,   362,   319,   358,   358,   366,
     358,   364,   356,   249,   358,   358,   360,   300,   362,   319,
     364,   257,   366,   358,   292,   245,   347,   316,    98,   347,
     347,   311,   300,   316,   316,   313,   300,   294,   306,   281,
    1017,   294,   257,   113,   292,   238,   313,   281,   316,   347,
     281,   340,   316,   306,   350,   347,   347,   281,   340,  1650,
     348,   238,   266,   348,   347,   238,   347,   238,   238,   347,
     358,   347,   358,   358,   358,   347,   347,   347,   347,   347,
    1840,   358,   350,   347,   358,   358,  1762,   257,   238,   313,
     358,   356,   225,   358,  1762,   360,   356,   362,   356,   364,
     360,   366,   356,   226,   238,   238,   366,   238,   366,   238,
    2100,   347,   366,   356,   238,   356,   356,   356,   356,   927,
     238,   238,   238,   366,   238,   366,   366,   366,   366,  2184,
     238,   262,   238,   238,   257,   238,  1589,   238,   218,   238,
    2883,    71,   238,    71,    71,    87,   128,  2625,  2626,   238,
     238,   221,    71,  2930,   238,    71,    87,   128,   228,   128,
     128,   231,   224,   233,   234,   235,   128,    55,    71,   239,
     240,   241,   242,   128,  2786,    87,   128,   247,  1629,  1630,
     250,   251,   252,    63,    69,   255,   128,   128,   258,    47,
    1601,   261,   225,   263,    82,    71,  1649,   128,  1651,   128,
     270,  2786,  2786,    69,    92,   238,   269,   277,   278,   279,
    2786,  2786,   282,   283,   284,    87,   128,   161,   288,   128,
     290,   206,   207,    47,   360,   295,   296,   805,   353,   128,
    2786,   301,   302,    87,  3267,    87,   141,  2786,  1649,   360,
    1651,    69,    71,   257,   314,    69,    87,   317,   120,    87,
     320,  3247,   581,   323,    55,    69,   128,   327,   328,   146,
     330,   294,   332,   141,   334,  1676,   336,   337,   141,    69,
      87,   341,    10,   306,   128,    87,   128,   581,   311,    87,
    3276,    87,   442,    71,   354,    87,   300,   128,   327,   259,
     128,   581,    56,    57,   128,   175,   327,   362,   363,    47,
     460,   366,   316,  1677,  1678,    87,   193,   377,   378,   379,
     380,   128,   382,  3098,   580,   581,   128,    87,    82,    83,
     128,    69,   128,    69,   256,   580,   128,    87,   580,    95,
      96,    97,    98,    99,   100,   101,   102,   126,   127,   224,
     128,   311,   230,   495,    50,    51,   128,    94,    87,   237,
     120,  3136,   327,   353,   519,   513,    87,   226,   128,  1950,
     120,   526,   527,   243,   529,   103,   327,   327,   128,   257,
     528,   353,   581,   327,    87,   580,   245,   265,   448,   584,
     249,   120,   581,    89,   580,    58,   538,   581,   257,   128,
     580,   129,   130,   131,   353,   353,   582,   128,   550,   551,
     586,   353,   353,   335,   336,   337,   581,   288,   580,   297,
     224,   580,   353,   353,   581,   128,    89,    90,   353,   489,
     327,   580,   353,   292,   581,   327,   581,    87,   280,   360,
     361,   210,   211,   212,   327,   327,   327,   306,   327,   362,
     363,   353,   512,   366,   353,   327,   582,  3443,   360,   361,
     353,   581,   514,   515,   580,   580,     3,   327,   259,  3455,
     120,   349,     9,   252,   253,   586,   230,    14,   128,   335,
     327,   260,   214,   215,    21,   460,   353,   335,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   360,   361,
     366,   554,   353,  1904,    41,    42,   581,   839,  1909,    46,
    1951,  1952,    49,   353,   242,    52,   360,   361,   360,   361,
    3543,   335,    59,    60,    61,    62,   128,    64,    65,   360,
     361,   287,   360,   361,    71,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   335,   353,   366,   924,   925,
    1991,  1992,   581,   360,   361,   353,  3542,   353,   360,   361,
     581,    98,   360,   361,   360,   361,   461,   501,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   324,   360,   361,
     344,   345,    55,   461,   584,  3370,   128,   335,   461,   335,
     328,    95,    96,    97,    98,    99,   100,   101,   102,  3384,
     360,   361,   584,   431,    87,  1582,   581,  3219,  1585,    82,
     581,    55,  3389,  3390,   583,   495,   584,   516,   517,   581,
     581,   581,  3399,   581,  3401,   584,   581,   581,   580,   360,
     361,   582,   305,   256,  3219,  3219,    80,    81,    82,   580,
     353,   583,   582,  3219,  3219,   128,   581,   360,   361,   580,
     581,   580,  2105,   723,   581,   725,   726,   587,   538,   587,
     730,   731,   732,  3219,  2038,   735,   736,   737,   587,  3147,
    3219,   587,   584,  2047,   581,  2126,  2050,   580,   582,   581,
     560,   561,   586,   571,   512,   755,   514,   515,   581,   581,
     581,   117,   581,   353,  2105,   139,   353,   767,   583,   581,
     360,   361,   772,   353,   580,   582,  3449,   353,  1094,  1095,
     154,   581,   584,  1099,  1100,   353,   353,  3502,  1104,  1105,
      44,   582,    46,   353,   581,     4,     5,     6,   353,   581,
     584,   353,   582,   353,   472,   805,   353,   580,   808,   353,
     581,   580,   581,   581,   814,   353,    71,   353,   360,   361,
     353,   580,   196,   226,    44,    87,   353,   230,   353,   580,
     353,   353,   832,  1740,   237,   431,   583,   837,   581,   581,
      10,   841,   580,   581,   844,   581,   353,   847,   353,   545,
     233,   234,    47,   287,   257,   353,   353,    55,   353,  2844,
     353,   581,  2847,   580,   353,   353,   128,   280,   581,   581,
     580,   353,   353,   580,    69,  3283,   581,   353,   580,   353,
     263,   360,   361,   353,   104,   105,    55,   270,   360,   361,
     264,   247,   353,   581,   297,   104,   105,   580,   581,   353,
     353,   353,   353,   259,    71,   353,   353,    11,   581,    47,
      87,   353,   587,   296,   353,   581,   512,    87,   514,   515,
    2631,  2632,   922,    71,  2635,   580,   926,   927,   137,   580,
      34,   580,   581,   103,   350,   351,   352,   937,   938,   148,
     493,   150,   335,   120,    35,    49,   349,   360,   361,    12,
     120,   128,    88,   309,   580,   581,   956,    35,   128,   129,
     130,   131,   580,   581,    68,    35,   519,   520,   521,   522,
     580,   581,    67,   142,   143,    21,    22,    23,  1885,  3387,
      78,    27,    28,    29,    30,   580,   581,   196,   157,   288,
     346,   991,   992,   580,    78,   164,   166,   163,   167,    45,
      89,    90,   582,   257,   165,   259,   582,   581,   178,    55,
     179,   335,   232,  1013,   582,   582,   254,   237,   280,   128,
     190,   191,   582,   232,   220,   221,   222,   582,   237,   224,
     582,    47,   582,   580,  1034,   289,    82,   580,   582,   259,
     254,   250,   251,   259,   582,   149,   582,   502,   257,   582,
     259,   580,   581,    69,   224,   582,   580,   582,   228,   582,
     582,   216,   271,   272,   168,   580,   581,   236,   360,   361,
     362,   363,   242,  1811,   366,   582,  1814,   582,   580,   581,
     289,   220,   221,   222,   582,   582,   224,   582,   461,   582,
     259,   286,  1092,   582,   582,   580,   581,  1097,   360,   361,
     582,   582,  1102,   224,   583,   583,   582,  1107,   582,  1109,
     224,   545,   582,   487,   488,    71,   311,   531,   532,   533,
     534,   582,   331,   332,    71,   229,   937,   938,   582,   582,
     582,   582,    71,   302,   582,   582,    71,   306,    71,   308,
     582,   310,    71,   582,  2051,   956,   344,   345,   286,   580,
     581,   255,   456,   457,   458,    71,   460,    71,   328,  3079,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     495,    71,   366,   311,  2081,  2082,    71,   346,   273,   274,
     275,   276,   277,   278,   230,   231,   395,   123,   124,   125,
     360,   361,  2883,   356,   357,   358,   359,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   224,   580,
     581,   381,   537,   538,   293,   385,   386,   387,   264,   265,
      71,   419,   420,   421,   422,   423,   330,   350,   351,   352,
     555,   556,   557,   558,   559,   433,   434,   435,   317,   318,
      71,  2931,   440,   441,    71,   443,   444,   353,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   582,   466,   580,
     581,   580,   581,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   456,   457,   458,   311,   460,   495,   344,   345,
     580,   581,   472,   580,   581,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   580,   581,    71,    20,    71,    19,
      20,   580,   581,    26,    24,    25,    26,    71,    31,    32,
     538,    31,    32,   353,   542,   580,   581,    37,    38,   582,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   580,   581,   366,   562,   563,   564,   565,   566,   567,
     568,   569,   570,    71,   572,   573,   574,   575,   576,   577,
     578,   456,   457,   458,    71,   460,   353,    71,   582,   582,
     107,   582,  2299,  2300,    71,   112,   113,   114,   360,   361,
     362,   363,  1604,    71,   366,    71,  1604,   580,   581,    71,
    1604,   581,   580,   581,    71,   105,   495,   581,    71,   498,
     580,   581,   580,   581,    71,   142,    71,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,    71,   164,    71,   832,
     167,   144,   145,    71,   144,   145,    71,  2761,   537,   538,
     353,   540,   541,    71,   543,   544,   545,   580,   581,    71,
      71,   550,   582,   353,   582,  1701,    71,   580,    71,    71,
     381,   582,   561,  1701,    71,   582,  1701,    71,  1701,    71,
    1701,  1807,  1808,  1701,    71,  1701,    71,    71,    71,  1701,
    1701,    71,  1701,  1701,    71,    71,   581,    71,  1729,    71,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,  1749,    71,   366,    71,    71,    71,  1749,  1729,    71,
    1729,    71,    71,    71,    71,  1701,    71,    71,    71,    71,
      71,    71,   232,  1749,    71,    71,    71,    71,  1749,  1749,
    1749,    71,  1615,    71,    71,    71,  3162,    71,    71,    71,
      71,    71,    71,  1729,  3162,   282,    71,    71,    71,  1622,
      71,    71,    71,  1723,    71,  3266,    71,  3268,  1701,   582,
      71,    71,    71,  1749,    71,    71,    71,  1587,    71,  1599,
    3111,   308,  1592,  1593,  1701,    71,    71,    71,  1701,   353,
    1701,  1701,   353,  1603,  1749,   582,  1606,   297,  3298,    71,
    3300,    71,   582,   353,  1930,  1931,   353,   582,  1934,  1935,
     581,  1701,  1938,  1939,   582,  1916,  2533,  1627,  2535,    71,
     353,  1631,    71,  1805,  1634,  1635,  1770,  1701,  1701,    71,
    1701,  1805,  1701,  1643,  1805,    71,    71,  1701,  1648,  1749,
      71,  1805,  1615,  1701,  1701,  1701,    71,  1701,  1856,   349,
      71,    71,  1875,  1701,   582,  1701,  1701,  3048,  1701,  1911,
    1701,  1914,  1701,  1673,  1674,  1701,  1863,  1875,  1856,  1679,
    1863,  1875,  1701,  1701,  1914,  1988,  1686,  1701,  1988,   353,
    1888,  1901,  1911,   582,    71,   582,  1749,  1905,  1911,  1911,
     582,    71,  1702,    71,  1988,  1888,    71,    71,  1905,    71,
      71,  2053,   582,  1911,   581,   353,   582,  1911,   581,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
    1730,    71,   366,    71,    71,  1954,  1736,  1988,  1701,   582,
    1988,  1988,  1954,    71,  2055,    71,  1746,  2089,    71,  2073,
    2106,  1905,  1752,  2073,    71,  1755,    71,    71,    71,  3450,
    1988,  1761,  1762,    71,    71,   581,  1988,  1988,  2055,  2073,
     580,    71,  2055,  1773,  3464,  1988,  1994,  1988,  2089,  1994,
    1988,  2055,  1988,    47,   581,  1785,  1988,  1988,  1988,  1988,
    1988,  1791,  2073,  2073,  1988,  2073,  1796,  2084,   581,  2073,
    2073,   581,  2089,  2086,  2078,  1749,  1806,   581,  2073,   581,
    2084,  1811,  2086,  2039,  1814,  2089,   581,   581,  1818,  1819,
    1820,  1821,  1988,  1622,  1824,  1825,  1826,  1827,  1828,  1829,
    1830,  1831,  1832,  1833,  1834,  1835,  1836,  1837,  1838,  1839,
     581,  2039,  1842,  1843,  1844,  1845,  1846,  1847,  1848,  1849,
    1850,  1851,  1852,  3544,  2761,  2073,   581,  2073,  2073,  2073,
    2055,   581,   581,   581,    71,  2055,  2073,  2055,   581,  2073,
    2073,  2055,  1872,  1873,  1874,  2073,  1876,   581,  2073,  1879,
    1880,   581,  2055,  2078,  2055,  2055,  2055,  2055,  2078,  2084,
    1890,  2086,  1892,   581,  2089,   581,   581,  1897,  1898,  2089,
    1863,  2089,   581,   581,  3208,  2089,  1906,  3211,   581,   581,
    1910,  3215,    71,  3217,  3218,  1915,  2089,  1917,  2089,  2089,
    2089,  2089,    71,    71,  1723,  1888,    71,  1927,   582,    71,
    1729,  1875,   582,    71,   107,    71,    69,   353,  1901,   112,
     113,   114,  1942,   582,    71,    71,  1946,   848,   582,    71,
    1749,    71,    71,  1953,    71,    71,    71,   353,   582,    71,
     224,    71,    71,  2870,    71,  2872,    71,  1911,   582,   142,
     353,    71,    71,   293,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,    71,  2970,   366,    71,  2245,  1989,
    1990,   164,    71,    71,   167,   353,    71,   317,   318,    71,
      71,  2001,    71,    71,    71,    71,   582,  1818,  1819,  1820,
    1821,   582,   353,  1824,  1825,  1826,  1827,  1828,  1829,  1830,
    1831,  1832,  1833,  1834,  1835,  1836,  1837,  1838,  1839,   288,
      71,  1842,  1843,  1844,  1845,  1846,  1847,  1848,  1849,  1850,
    1851,  1852,   444,  2043,    71,  2045,  2046,   311,   450,   451,
     452,   453,   454,   455,  2054,    71,    71,  1856,    21,    22,
      23,    71,    71,   465,    27,    28,    29,    30,    71,   471,
      33,  2978,    71,   356,   357,   358,   359,   360,   361,   362,
     363,    44,    45,   366,    71,    71,    71,    71,    71,  1888,
      71,   224,    55,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,    71,    71,   366,    71,  2108,    71,
    2110,  2111,  2913,    71,  2114,    71,    71,    71,    71,    82,
    2120,  2121,    71,    71,  2124,    71,  1603,  2127,  2128,    92,
    2130,  2131,  2132,    71,  2134,   308,    71,    71,    71,    71,
      71,   582,    71,  2400,  2460,    71,  2903,   280,    71,    71,
      71,    71,    71,    71,  1631,    71,    71,  1634,  1635,    71,
      71,  2893,  2434,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,  3081,   495,   366,    71,   498,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,    71,    71,
      71,  2201,   582,  2203,  1587,    71,    71,    71,   582,    71,
    3117,    71,    71,  3120,    71,    71,  2216,   537,   538,   539,
     540,   541,    71,   543,   544,  1702,    71,    71,    71,    71,
     550,    71,    71,    71,   293,    71,    71,  2237,    71,    71,
    2240,   561,  2242,    71,    71,  2245,    71,    71,    71,    71,
      71,    71,    71,  1730,    71,    71,   353,    71,   317,   318,
      71,    71,    69,    71,   353,  1648,  2266,   230,   231,    71,
    2586,    71,    71,  2589,    71,    71,  2592,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,    71,    71,
     366,  1674,    71,   582,   582,   353,  1679,    71,    71,    71,
      71,   264,   265,  3210,    71,    71,    71,  3214,  3315,    71,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,  1806,
      71,    71,    71,    71,    71,  3242,    71,    71,    71,   353,
     582,    71,    71,  2343,  2344,   356,   357,   358,   359,   360,
     361,   362,   363,  1736,    71,   366,  2864,   353,  2358,   582,
      71,    71,  2362,  1746,    71,    71,  2366,   582,   582,  1752,
      71,   353,   582,   353,   353,    71,    71,  2377,  2378,    71,
      71,   344,   345,    71,  2384,    71,    71,    71,    71,    71,
      71,    71,   582,    71,   581,   581,   580,  1874,   587,  2907,
    2400,    71,   581,   581,   580,   587,  2406,   581,  2408,   581,
     580,   580,   587,  1796,   581,   581,  2416,   224,   581,  2419,
    1897,  2421,   587,   581,   581,   581,  2426,   581,   581,  1906,
     581,   581,   280,  1910,   581,   581,   495,   581,  1915,   498,
    2440,   581,   581,   580,  2786,   353,   581,   581,   353,   581,
    1927,   581,   581,   581,   353,   128,   128,   128,   583,  2459,
     128,   128,  3369,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   280,   128,   366,  1953,   128,   537,   538,
     128,   540,   541,   128,   543,   544,   545,   546,   128,   128,
    3397,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,  2501,   561,   366,   128,   128,   582,  1890,   128,  1892,
     128,   581,   128,  2513,   587,  2515,   580,   580,   580,   580,
     128,   128,   128,  2523,   581,  2525,   128,   128,  2528,   128,
     128,   128,   128,  3440,   128,   128,   128,   583,   128,  3446,
     128,  2541,   128,  2543,   581,   128,   128,  2547,   128,   128,
     581,   128,   580,   128,   580,   814,  3463,  2557,   353,   353,
     580,   580,  2562,  1946,  2564,   128,   128,   580,  2568,   128,
     128,  2571,   831,   580,   580,   580,   580,  2054,   580,   128,
     128,   128,   580,  2583,  2584,  2585,   580,   580,   580,  3496,
     128,   580,   580,   224,   128,   128,   128,  2408,   128,   128,
     128,   128,   128,   581,   581,  2416,  1989,  2607,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,  2001,   580,
     366,   580,   582,    71,   581,   128,   128,   128,   580,   580,
    2630,  2631,  2632,   580,   366,  2635,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,  1556,  1557,  2929,   128,   353,
    2043,  2661,  2045,  2046,   581,   128,   580,   580,    71,   128,
     580,    47,  1573,   580,   580,   128,   580,   580,   937,   938,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
    2501,   582,   366,    69,   580,   580,   580,   956,   580,   128,
     581,  2701,   581,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   581,  2715,   366,   128,   128,   582,
     128,   128,   580,   128,   128,  2108,   580,  2110,  2111,   580,
     580,  2114,   128,   128,   128,   128,   128,  1638,   128,  2216,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     128,   128,   366,   128,   128,   128,   128,   583,  1017,   128,
    2760,   128,   580,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,  2584,  2585,   366,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   128,   580,   366,  2266,
     581,   581,   581,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   142,   143,   366,  1707,   128,   128,   128,
      47,   581,  1713,   128,   128,   128,   128,  1718,   157,   128,
     581,   128,   128,   128,   128,   164,   128,  1728,   167,   128,
     128,   128,   128,   128,   128,   128,   582,   128,  1739,   128,
     179,   128,   128,   128,   128,   128,   128,   128,   224,   128,
    2850,   128,   128,   128,  2854,   128,   580,  2857,   128,   128,
     128,   128,   128,   128,  2864,   580,   128,  2867,   128,   128,
     128,   108,   128,   128,   128,   580,   128,  3219,   128,   128,
     580,   128,   580,   580,   128,   511,   128,  1788,   128,  1790,
    2701,   580,   128,  2893,   128,   128,   583,   236,   366,   140,
     259,   580,   360,  2903,   580,   580,   583,  2907,   582,   280,
     280,   580,   353,  2913,   580,   580,   580,  2917,  2918,   581,
     580,  2921,   581,   581,  2924,   586,   582,   580,   580,   353,
     128,   580,   582,   128,   353,   311,   582,    71,   582,  2939,
    2940,   582,  2419,    71,   582,   580,   582,  2947,   259,   280,
     582,   366,   582,   582,   128,   580,   128,  2957,   580,  2959,
     587,   580,   353,   302,   353,  2965,   587,   306,   582,   308,
     580,   310,  2972,   582,   353,   587,    71,   582,   582,    71,
      71,   581,  1883,  2983,  2984,    71,   128,   224,   128,   353,
    2990,   582,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,  3319,   582,   366,   587,   346,   353,   353,
    3010,   580,  1913,   586,   581,  3015,   353,  1918,  1919,  1920,
    1921,   582,  3022,   587,    71,   580,   580,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   353,  2421,   366,
     128,   280,   582,  2426,   580,   353,  3046,    71,    71,  3049,
     581,    71,  3052,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   580,  2541,   366,  2543,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   582,  2564,   582,   582,
     582,   580,   353,    71,    71,  3411,  3412,    71,    71,    71,
      71,    71,    71,    71,   587,   587,  2917,  2918,   461,  3109,
     587,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,    71,   141,   366,   580,    71,   581,   128,  2939,  2940,
     580,   353,   586,   353,   353,   580,  2947,   581,   580,   582,
     580,   580,   580,   580,   580,   580,  2957,   580,  2959,  3149,
     582,  3151,   140,  3153,  3470,  3471,   511,   582,   580,   582,
    3160,   128,  3162,   128,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   586,   334,   366,   280,  3178,  3179,
     581,  3181,   581,    71,  2661,   587,   353,   353,  3188,   327,
     334,   353,   580,   353,   327,   128,  3196,  3197,   580,   128,
     587,   511,   587,   587,  3204,  3521,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,  3225,   353,   587,  3228,   587,
     586,   581,   353,   353,  2135,  2136,  2137,  2138,   581,   580,
    2141,  2142,  2143,  2144,  2145,  2146,  2147,  2148,  2149,  2150,
    2151,  2152,  2153,  2154,  2155,   582,  2157,  2158,  2159,  2160,
    2161,  2162,  2163,  2164,  2165,  2166,  2167,   584,   327,   327,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
      71,   582,   366,  2760,   353,   128,   586,   140,  3288,   581,
    3290,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   141,   580,   366,   461,   128,  3306,  3307,   580,    71,
     581,   327,   327,   353,   353,  3315,   580,   580,  3318,   353,
    3320,  3321,  1581,  1582,  1583,   353,  1585,   584,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,  1597,   582,
     366,   587,   580,  1602,   461,   580,   141,   353,   580,   353,
     581,  1610,  1611,   581,  1613,   580,   580,   587,  1617,   582,
     581,   128,   353,   581,   580,   580,   580,  3178,  3179,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   580,
     128,   366,   128,  1642,   580,  1644,  1645,  1646,   582,   353,
     582,  3391,   582,   582,   128,  1654,   582,  1656,   113,  3197,
    2384,  1660,  1661,  1662,  1663,  1664,  1665,  1770,  2924,  3409,
    2916,  1670,  2095,  2518,  3532,  3415,  3529,  3424,  2928,  2434,
    3397,  2103,  2533,  1682,  1615,  2106,  1777,  2116,   373,  3429,
    1888,  3431,  2112,  1692,  1693,  1905,   726,  1696,  2366,  1994,
     377,  3219,  3082,  3244,   732,   379,  1701,    47,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,  2359,   380,
     366,  3118,  2363,  3447,   844,  3121,  1805,  1749,  1773,    69,
      47,  2571,  1926,  1594,  1914,   755,  1079,  2055,  3478,  3290,
    2039,  1740,  2089,  3483,  2053,  1599,  2086,  2084,  2965,  2078,
    2073,  1875,    69,  1911,  1988,  3306,  3307,  1954,   582,  1729,
     490,  1632,  1604,  1762,     4,     5,     6,  1766,  1898,  1622,
    1723,   841,  2406,  1879,  1896,  2602,  3213,  1776,  3188,   582,
    2124,   772,    -1,    -1,    -1,  3525,  3526,    -1,    -1,    -1,
      -1,    -1,  3532,    -1,  1793,    -1,    -1,    -1,  1797,    -1,
    1799,  2442,  1801,    -1,    44,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3552,    -1,  3554,    55,   582,    -1,    -1,  1818,
    1819,  1820,  1821,    47,    -1,  1824,  1825,  1826,  1827,  1828,
    1829,  1830,  1831,  1832,  1833,  1834,  1835,  1836,  1837,  1838,
    1839,    -1,    82,  1842,  1843,  1844,  1845,  1846,  1847,  1848,
    1849,  1850,  1851,  1852,    -1,    -1,    -1,   582,    -1,  1858,
    1859,    -1,  1861,    -1,   104,   105,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  2514,    -1,    -1,    -1,    -1,    -1,   119,
      -1,    -1,  1881,  1882,   224,    -1,  1885,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,  2536,    -1,   137,    -1,    -1,
      -1,    -1,    -1,    -1,  1903,    -1,    -1,   224,   148,  2550,
     150,    -1,    87,    -1,   154,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,  1925,    -1,   366,   169,
      -1,    -1,    -1,    -1,    -1,    -1,   582,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   185,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   128,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,    -1,    -1,   366,    -1,    -1,    -1,
    1969,   311,    -1,  1972,  1973,    -1,    -1,    -1,    -1,    -1,
      -1,  1980,    -1,  1982,  1983,  1984,  1985,  1986,    -1,    -1,
     230,   166,   232,    -1,   311,    -1,    -1,   237,    -1,    -1,
     224,    -1,    -1,   178,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2011,  2012,    -1,   190,   191,    -1,    -1,    -1,
    2019,    -1,    -1,    -1,   264,   265,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,    -1,  3160,   366,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   224,
      -1,   366,  2051,    -1,    -1,    -1,    -1,    -1,    -1,  2058,
    2059,  2060,    -1,  2062,    -1,    -1,  2065,  2066,    -1,    -1,
      -1,    -1,  2071,  2072,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  2081,  2082,    -1,    -1,    -1,   311,    -1,    -1,
      -1,   331,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  2100,    -1,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,    -1,    -1,    -1,    -1,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,    -1,    -1,    -1,    -1,    -1,
      -1,   391,   392,   393,   394,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   418,    69,
      -1,    -1,   582,    -1,    -1,   360,   361,    -1,    -1,    -1,
    2831,    -1,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,    -1,    -1,    -1,   381,    -1,    -1,    -1,
     385,   386,   387,   388,   389,    -1,    -1,    -1,    -1,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  2888,    -1,    -1,
      -1,    -1,    -1,  2894,   582,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  2905,    -1,    -1,   582,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,    47,  2287,  2288,
      -1,    -1,  2933,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    2299,  2300,    -1,    -1,    -1,    -1,    -1,   547,   548,   549,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
      -1,    -1,   366,    -1,    -1,    -1,    -1,    -1,  2969,    -1,
      -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,  2980,
      -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,   108,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,    -1,
      -1,   366,    87,    -1,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,    -1,    55,   366,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,    -1,    -1,   366,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
      -1,    -1,   366,   128,    -1,    -1,   581,    -1,   583,  2408,
     585,    -1,    92,    -1,  3055,  3056,    47,  2416,    -1,    -1,
      -1,    -1,  3063,    -1,    -1,    -1,    -1,    -1,    -1,  2428,
      -1,    -1,  3073,    -1,  3075,    -1,    -1,    -1,    -1,    -1,
      -1,   166,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,    -1,   178,   366,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   224,   190,   191,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   108,    -1,   366,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  3128,  3129,    -1,
    3131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3139,   224,
      -1,    -1,  2501,    -1,    -1,    -1,    -1,    -1,    -1,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,    -1,
      -1,   366,    69,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,    -1,  2533,   366,  2535,    -1,   582,    -1,
      -1,  3182,    -1,  3184,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3193,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,    -1,    -1,    -1,    -1,    -1,   582,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  2584,  2585,    -1,    -1,    -1,
      -1,    -1,   582,   224,  3235,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  3243,    -1,    -1,   582,    69,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,    -1,   582,   366,
      -1,    -1,    -1,    -1,    -1,    69,  2625,  2626,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   360,   361,    -1,    -1,    -1,
      -1,    -1,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,    69,    -1,    -1,   381,    -1,    -1,    -1,
     385,   386,   387,   388,   389,    -1,    -1,    -1,    -1,    -1,
     582,    -1,    -1,    -1,    -1,    -1,    69,   224,    -1,    -1,
      -1,    -1,  3323,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,  2701,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    -1,    -1,    -1,    -1,    -1,  3357,  3358,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   582,  3379,   419,
     420,   421,   422,   423,   424,   425,    -1,    -1,   428,   429,
      -1,   582,   432,   433,   434,   435,   436,   437,   438,   439,
     440,   224,  2761,   443,   444,   445,   446,   447,   448,   449,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3419,  3420,
     224,    -1,    -1,  3424,    -1,    -1,   466,   467,   468,   469,
     470,    -1,    -1,   473,   474,   475,   476,   477,  3439,   479,
     480,   481,   482,   483,   484,   485,    -1,    -1,   224,   489,
     490,   491,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   224,    -1,    -1,    -1,   582,    -1,    -1,  3479,    -1,
      -1,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,    -1,    -1,   366,    -1,    -1,   581,  3498,   583,    -1,
     585,    -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,    -1,
      -1,  2870,    -1,  2872,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   562,    -1,    -1,    -1,    -1,    -1,  3529,    -1,
      -1,    -1,    -1,    -1,    -1,  3536,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,    -1,    -1,    -1,  2917,  2918,
      -1,    -1,    -1,    -1,    -1,  2924,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,  3577,    -1,   366,    -1,
    2939,  2940,    -1,    -1,    -1,    -1,    -1,    69,  2947,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2957,    -1,
    2959,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  2978,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,    -1,    -1,    -1,    -1,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   582,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  3080,  3081,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   224,    69,    -1,    -1,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,     0,  3117,   366,
      -1,  3120,    -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    14,    15,    -1,    69,    -1,    -1,   353,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,  3147,    -1,
     366,    -1,    -1,    -1,   582,    -1,    39,    40,    41,    42,
      43,    -1,    -1,  3162,    47,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3178,
    3179,    64,    65,    66,    -1,    -1,    -1,    70,    -1,    72,
      73,    74,    75,    76,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    85,    -1,    -1,    -1,    -1,    69,    -1,    92,
      -1,  3210,    -1,  3212,    -1,  3214,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,   109,   110,   111,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,   121,   122,
      -1,    -1,    -1,  3242,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   135,    -1,    -1,    -1,    -1,    -1,   224,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     153,    -1,   366,    -1,    -1,    -1,    -1,    -1,    -1,   162,
      -1,    -1,    -1,    -1,  3283,    -1,    -1,    -1,    -1,   224,
      -1,  3290,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   186,   187,   188,   189,  3306,  3307,   192,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     203,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
      -1,   224,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   244,   224,   246,   580,   248,   249,    -1,    -1,    -1,
    3369,    -1,    -1,   256,    -1,    -1,   259,    -1,   261,   262,
      69,    -1,    -1,   266,   267,    -1,    -1,    -1,  3387,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  3397,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   291,   292,
      -1,   294,   295,   296,    -1,   298,   299,    -1,    -1,    -1,
      -1,   304,    -1,    -1,   307,    -1,    -1,    -1,    -1,   312,
     313,    -1,    -1,    -1,    -1,    -1,   319,    -1,   321,   322,
     323,  3440,   325,    -1,    -1,    -1,   329,  3446,    -1,    -1,
      -1,    -1,   335,   336,   337,   338,   339,   340,   341,   342,
     343,    -1,    -1,    -1,  3463,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,    -1,  3496,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   390,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,
      -1,   424,    -1,    -1,    -1,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,    -1,    -1,   366,    -1,    -1,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,    -1,
      -1,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
      -1,    -1,    -1,    14,    15,    -1,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   499,   500,   366,    -1,
     503,   504,   505,   506,   507,   508,   509,   510,    39,    40,
      41,    42,    43,    -1,    -1,   518,    47,    -1,   224,    -1,
     523,   524,   128,    54,    -1,    -1,    -1,   530,    -1,    -1,
      -1,    -1,    -1,    64,    65,    66,    -1,    -1,    -1,    70,
      -1,    72,    73,    74,    75,    76,    -1,    -1,    -1,   552,
     553,    -1,    -1,    84,    85,    -1,    -1,    -1,    -1,    -1,
      -1,    92,    -1,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,    -1,    -1,   366,   579,   108,   109,   110,
     111,    -1,    -1,    87,    -1,    -1,    -1,    -1,   119,    -1,
     121,   122,    -1,    -1,    -1,    -1,    -1,    -1,   224,    -1,
      -1,    -1,    -1,    -1,   135,    -1,    -1,    -1,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   224,    -1,
     366,    -1,   153,    -1,   128,    -1,    -1,    -1,    -1,    -1,
      -1,   162,    -1,    -1,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   582,    -1,   186,   187,   188,   189,    -1,
      -1,   192,   166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   203,    -1,   178,    -1,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   190,   191,   366,    -1,
      -1,    -1,    -1,   224,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,    -1,    -1,   366,    -1,    -1,
      -1,    -1,    -1,   244,   582,   246,    -1,   248,   249,    -1,
     224,    -1,    -1,    -1,    -1,   256,    -1,   353,   259,    -1,
     261,   262,    -1,    -1,    -1,   266,   267,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,    -1,    -1,    -1,    -1,
     291,   292,    -1,   294,   295,   296,    -1,   298,   299,    -1,
      -1,    -1,    -1,   304,    -1,    -1,   307,    -1,    -1,    -1,
      -1,   312,   313,    -1,    -1,    -1,    -1,    -1,   319,   580,
     321,   322,   323,    -1,   325,    -1,    -1,    -1,   329,    -1,
      -1,    -1,    -1,    -1,   335,   336,   337,   338,   339,   340,
     341,   342,   343,    -1,    -1,    -1,    -1,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   582,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   360,   361,    -1,   390,
      -1,    -1,    -1,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   224,    -1,    -1,   381,    -1,    -1,
     586,   385,   386,   387,   388,   389,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   424,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   582,    -1,   366,    -1,    -1,    -1,
      -1,    -1,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   584,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   499,   500,
      -1,    -1,   503,   504,   505,   506,   507,   508,   509,   510,
      -1,    -1,    -1,    -1,    -1,     3,     4,   518,     6,    -1,
       8,     9,   523,   524,    -1,    13,    -1,    -1,    16,   530,
      18,    -1,    -1,   353,    -1,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,    -1,    -1,   366,    36,    -1,
      -1,   552,   553,    -1,    -1,    -1,    44,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    52,    53,    -1,    55,    -1,    -1,
      -1,    59,    60,    61,    -1,    -1,    -1,    -1,   579,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,
      -1,    79,    80,    81,    82,    -1,    -1,    -1,    86,    -1,
      -1,    -1,    -1,    -1,    92,    -1,    -1,   581,    -1,   583,
      -1,   585,    -1,    -1,    -1,    -1,   104,   105,   106,    -1,
      -1,    -1,    -1,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,    -1,    -1,   132,   133,   134,    -1,   136,   137,
     138,   139,   582,    -1,    -1,    -1,    -1,    -1,    -1,   147,
     148,    -1,    -1,   151,   152,    -1,   154,   155,   156,    -1,
     158,   159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   169,   170,   171,   172,   173,   174,   175,   176,   177,
      -1,    -1,   180,   181,   182,   183,   184,   185,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   194,   195,   196,   197,
     198,   199,   200,   201,   202,    -1,   204,   205,    -1,    -1,
     208,   209,    -1,    -1,   224,   213,    -1,    -1,    -1,   217,
     218,   219,    -1,    -1,    -1,   223,    -1,   225,    87,   227,
      -1,    -1,   230,   231,   232,    -1,   234,    -1,    -1,   237,
     238,   239,    -1,    -1,    -1,   224,    -1,   245,    -1,   247,
      -1,    -1,    -1,   582,   584,    -1,    -1,    -1,    -1,    87,
     258,   120,    -1,    -1,    -1,   263,   264,   265,    -1,   128,
     268,    -1,    -1,    -1,   272,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    87,    -1,   282,    -1,   284,   285,    -1,    -1,
     288,    -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     128,    -1,    -1,    -1,    -1,   303,    -1,   166,    -1,    -1,
     308,    -1,    -1,    -1,    -1,   120,    -1,   315,   316,   178,
      -1,    -1,   320,   128,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   190,   191,    -1,    -1,   333,    -1,    -1,   166,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   344,   345,    -1,    -1,
     178,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   166,   190,   191,    -1,   224,    -1,    -1,    -1,   228,
      -1,    -1,    -1,   178,   353,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   190,   191,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,
     228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,    -1,   224,
     366,    -1,    -1,   228,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   459,    -1,    -1,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,    -1,    -1,    -1,    -1,    -1,   486,   487,
     488,    -1,    -1,    -1,   353,    -1,   494,    -1,    -1,   140,
     141,   360,   361,    -1,    -1,    -1,    -1,    -1,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,    -1,
      -1,    -1,   381,    -1,    -1,   353,   385,   386,   387,    -1,
      -1,    -1,   360,   361,    -1,    -1,    -1,   535,   536,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
      -1,    -1,    -1,   381,   141,   360,   361,   385,   386,   387,
      -1,    -1,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   583,   140,   141,   381,    -1,    -1,    -1,
     385,   386,   387,   224,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   582,    -1,    -1,    -1,    -1,    -1,   224,
      -1,    -1,    -1,    -1,    -1,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,    87,    -1,   582,   224,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,    87,   224,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   128,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,    87,    -1,   366,    -1,
     120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,    -1,
      -1,   366,    -1,   166,    -1,    -1,    -1,    -1,    -1,   120,
     525,    -1,   581,    -1,    -1,   178,    -1,   128,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   166,   190,   191,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   178,    -1,
      -1,    -1,    -1,   581,    -1,    -1,    -1,    -1,    -1,    -1,
     190,   191,    -1,    -1,    -1,   166,    -1,    -1,    -1,    -1,
      -1,   224,    -1,    -1,    -1,   228,   581,   178,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   190,
     191,   366,    -1,    -1,   224,    -1,    -1,    -1,   228,    -1,
      -1,    -1,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,    -1,    -1,   224,    -1,    -1,    -1,   228,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   224,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,    -1,    -1,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   582,    -1,    -1,   360,   361,    -1,
      -1,    -1,    -1,    -1,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,    -1,    -1,   582,   381,    -1,
     360,   361,   385,   386,   387,    -1,    -1,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,    -1,   140,
     141,   381,    -1,    -1,    -1,   385,   386,   387,    -1,   360,
     361,    -1,   224,    -1,    -1,   580,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   377,    -1,    -1,    -1,
     381,    -1,    -1,    -1,   385,   386,   387,    -1,    -1,    -1,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   224,
      -1,    -1,    -1,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,    87,   224,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   224,    -1,    87,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   525,   128,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,    -1,    -1,   525,   120,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   128,    -1,    -1,    -1,    -1,    -1,
      -1,   166,    -1,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   178,   525,   366,    -1,    -1,   581,    -1,
      -1,    -1,    -1,    -1,    -1,   190,   191,    -1,   353,    -1,
      -1,    -1,   166,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   581,    -1,    -1,   178,    -1,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   190,   191,   366,   224,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     581,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     224,    -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   582,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,    -1,    -1,   366,    -1,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,    -1,    -1,    -1,
      -1,    -1,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,    -1,
      -1,    -1,    -1,    -1,    -1,   360,   361,    -1,    -1,    -1,
      -1,    -1,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,    -1,    -1,    -1,   381,    -1,    -1,    -1,
     385,   386,   387,   388,   389,    -1,   360,   361,    -1,    -1,
      -1,   582,    -1,   367,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,    -1,     3,    -1,   381,     6,    -1,
      -1,   385,   386,   387,    -1,    13,    -1,   582,    -1,    17,
      18,    -1,    -1,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,    -1,   582,   366,    -1,    -1,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,    -1,    -1,    -1,
      -1,    59,    60,    61,    62,    63,    -1,   580,   581,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,    -1,    -1,
      -1,    -1,   582,    91,    -1,    93,    -1,    -1,    -1,    -1,
      -1,    -1,     3,    -1,    -1,     6,   104,   105,   106,    -1,
      -1,    -1,    -1,    -1,    -1,    16,    17,   115,   116,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,    -1,
      -1,   366,    -1,    -1,   132,   133,   134,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,
      -1,   149,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,    63,    -1,    -1,    -1,    -1,    -1,    -1,   167,
      -1,    -1,    -1,    -1,    -1,    -1,   581,    -1,    -1,    -1,
      -1,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,    -1,    93,   366,    -1,    -1,    -1,   195,    -1,    -1,
      -1,    -1,    -1,   104,   105,   106,    -1,   581,    -1,    -1,
      -1,    -1,    -1,    -1,   115,   116,    -1,   118,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,    -1,    -1,
     366,   132,   133,   134,   232,   233,    -1,   235,    -1,   237,
      -1,    -1,   240,   241,   224,    -1,    -1,   245,   149,   247,
      -1,   582,    -1,   154,    -1,    -1,    -1,    -1,    -1,    -1,
     258,   259,    -1,    -1,    -1,    -1,    -1,    -1,   224,    -1,
      -1,    -1,   270,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   279,    -1,   281,   282,    -1,    -1,    -1,    -1,    -1,
     288,   289,   290,     3,   195,    -1,     6,    -1,    -1,    -1,
      -1,   299,   300,   301,    -1,    -1,    -1,    17,    -1,    -1,
     308,    -1,    -1,    -1,    -1,    -1,    -1,   315,   316,    -1,
      -1,    -1,   320,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   232,   233,    -1,   235,    -1,   237,    -1,    -1,   240,
     241,    -1,    -1,    -1,    -1,    -1,   247,   582,    -1,    59,
      60,    61,    62,    63,    -1,    -1,    -1,   258,   259,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   270,
      -1,   366,    -1,   353,    -1,    -1,    -1,    -1,   279,    -1,
     281,   282,    -1,    93,    94,    -1,    -1,   288,   289,   290,
      -1,    -1,    -1,    -1,   104,   105,   106,   353,   299,   300,
     301,    -1,    -1,    -1,    -1,   115,   116,   308,    -1,   582,
      -1,    -1,    -1,    -1,   315,   316,    -1,    -1,    -1,   320,
      -1,    -1,   132,   133,   134,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,    -1,    -1,   366,   224,   149,
      -1,    -1,    -1,    -1,    -1,    -1,   582,   348,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,   224,    -1,
      -1,   459,    -1,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   224,    -1,    -1,   195,    -1,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,     3,    -1,    -1,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    -1,   232,   233,    -1,   235,    -1,   237,    -1,   430,
     240,   241,    -1,    -1,    -1,    -1,    -1,   247,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,   258,   259,
     366,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   459,    -1,
     270,    -1,    59,    60,    61,    62,    63,   353,    -1,   279,
      -1,   281,   282,    -1,    -1,    -1,    -1,    -1,   288,   289,
     290,    -1,    -1,    -1,    -1,   580,    -1,   353,    -1,   299,
     300,   301,    -1,    -1,    -1,    -1,    93,    94,   308,    -1,
      -1,    -1,   582,    -1,    -1,   315,   316,   104,   105,   106,
     320,   353,    -1,    -1,   324,    -1,   326,    -1,   115,   116,
      -1,    -1,   224,    -1,    -1,    -1,   582,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   132,   133,   134,    -1,    -1,
      -1,   224,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   149,   582,   366,    -1,    -1,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   224,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   224,    -1,   195,    -1,
      -1,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     224,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,    -1,    -1,   366,   232,   233,    -1,   235,    -1,
     237,    -1,    -1,   240,   241,    -1,    -1,    -1,    -1,   459,
     247,   353,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   258,   259,    -1,    -1,    -1,   582,    -1,    -1,    -1,
      -1,    -1,    -1,   270,    -1,    -1,   280,    -1,    -1,    -1,
     224,    -1,   279,    -1,   281,   282,    -1,    -1,    -1,    -1,
      -1,   288,   289,   290,    -1,    -1,   582,    -1,    -1,    -1,
      -1,    -1,   299,   300,   301,    -1,    -1,    -1,    -1,    -1,
      -1,   308,    -1,    -1,    -1,    -1,   582,    -1,   315,   316,
      -1,    -1,    -1,   320,    -1,    -1,    -1,   324,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,
     582,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   224,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,    -1,    -1,   366,    -1,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,    -1,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   224,    -1,    -1,    -1,    -1,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,    -1,    -1,
      -1,    -1,   459,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,    -1,   224,   366,    -1,    -1,    -1,    -1,
     582,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,    -1,   224,   366,    -1,    -1,   580,   581,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   224,    -1,
      -1,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   580,   581,   366,    -1,    -1,   224,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,    -1,
      -1,   366,   580,   581,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   224,    -1,    -1,    -1,   581,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,    -1,    -1,
     366,    -1,   224,    -1,    -1,    -1,    -1,    -1,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,    -1,    -1,   366,
      -1,    -1,   224,    -1,    -1,    -1,   580,   581,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,    -1,    -1,   366,    -1,    -1,    -1,    -1,   580,
      -1,   580,   581,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,    -1,    -1,    -1,    -1,   580,   581,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,    -1,   224,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     580,   581,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     580,   581,   280,   224,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   582,    -1,    -1,    -1,   580,
     581,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
      -1,    -1,    -1,    -1,   580,   581,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,   280,
      -1,    -1,    -1,   580,   581,    -1,    -1,    -1,    -1,    -1,
     582,    -1,    -1,    -1,    -1,   353,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   580,
     581,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,    -1,   224,   366,    -1,    -1,    -1,    -1,    -1,   581,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   353,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   581,
      -1,    -1,    -1,    -1,   224,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   353,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   353,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   353,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     353,    -1,    -1,    -1,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   353,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   580,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   353,    -1,    -1,    -1,    -1,   580,    -1,    -1,
      -1,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   580,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   353,
      -1,    -1,    -1,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   580,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     580,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   580,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   224,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   580,    -1,    -1,
      -1,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   224,    -1,   366,    -1,    -1,    -1,    -1,    -1,    -1,
     580,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   353,    -1,    -1,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,    -1,    -1,   366,    -1,    -1,   580,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     353,    -1,   366,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,    -1,    -1,   366,    -1,    -1,    -1,   353,
      -1,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,    -1,    -1,   366,    -1,    -1,    -1,   224,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   580,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   353,    -1,    -1,
      -1,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     353,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,    -1,    -1,
     366,    -1,    -1,    -1,    -1,    -1,   224,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   353,   580,    -1,    -1,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   580,   224,
     580,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   580,    -1,   353,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   580,   224,   580,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   580,   580,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   224,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   353,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   580,   224,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   580,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,    -1,   353,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   580,    -1,    -1,   353,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   353,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   580,   224,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   353,    -1,    -1,    -1,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   580,   224,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   353,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   580,   224,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   353,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   580,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   353,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   580,   224,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,    -1,    -1,
     366,   580,   224,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   353,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   580,   224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   353,    -1,    -1,    -1,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   580,   224,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   353,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   353,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     580,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
      -1,   353,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   580,   224,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   353,   580,    -1,    -1,    -1,    -1,    -1,
      -1,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   580,
      -1,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   580,   224,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   353,
      -1,    -1,    -1,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   353,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   580,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,    -1,    -1,   366,    -1,    -1,    -1,    -1,   224,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   580,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   353,
      -1,    -1,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,    -1,    -1,   366,    -1,    -1,    -1,   580,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   353,    -1,
      -1,    -1,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     580,    -1,    -1,    -1,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,    -1,    -1,   366,    -1,   224,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   353,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   224,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   580,    -1,    -1,    -1,
     354,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     224,    -1,   366,    -1,    -1,    -1,    -1,    -1,    -1,   580,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   580,    -1,
     353,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   353,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   580,   224,   580,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   353,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   580,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   353,    -1,    -1,    -1,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   353,
     580,    -1,    -1,    -1,    -1,    -1,    -1,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   580,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,    -1,   353,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   224,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   353,   580,    -1,    -1,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   224,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   580,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   224,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   580,    -1,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   580,   224,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   353,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   580,   224,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   224,    -1,   580,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   353,    -1,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,    -1,
      -1,   366,    -1,    -1,    -1,    -1,   353,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   580,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   353,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   580,   224,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   224,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,    -1,    -1,   366,
      -1,    -1,    -1,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   580,    -1,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   353,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   224,    -1,   580,   580,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   224,    -1,   580,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   224,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     580,    -1,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     580,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     580,    -1,    -1,    -1,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   580,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,    -1,    -1,   366,    -1,    -1,   224,
      -1,   580,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   580,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   224,
     128,   580,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     224,   128,    -1,    -1,    -1,    -1,    -1,    -1,   580,    -1,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   141,   224,    -1,   580,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     580,    -1,    -1,    -1,   141,    -1,   224,   580,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   224,    -1,   580,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   280,    -1,    -1,    -1,   224,    -1,   580,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   224,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   580,    -1,    -1,
      -1,    -1,    -1,   280,    -1,    -1,    -1,   224,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   580,    -1,    -1,    -1,
      -1,    -1,   280,    -1,    -1,    -1,    -1,   224,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   224,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   353,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   580,    -1,    -1,    -1,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   224,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   280,    -1,    -1,   580,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   280,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   224,   580,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   224,    -1,   580,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   353,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,    -1,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,    -1,    -1,
     366,    -1,    -1,    -1,    -1,    -1,    -1,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,    -1,    -1,   366,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,    -1,    -1,   366,
      -1,    -1,    -1,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,    -1,    -1,   366,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,    -1,    -1,   366,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,    -1,    -1,   366,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,    -1,    -1,
     366,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,    -1,    -1,   366,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,    -1,    -1,   366,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   580,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,    -1,    -1,   366,   354,   355,
     356,   357,   358,   359,   360,   361,   362,   363,    -1,    -1,
     366,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     580,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   580,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   580,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   580,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   580,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   580,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   580,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     580,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   580,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   580
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
     339,   340,   341,   342,   343,   390,   424,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   499,   500,   503,   504,
     505,   506,   507,   508,   509,   510,   518,   523,   524,   530,
     552,   553,   579,   589,   590,   591,   592,   593,   596,   599,
     603,   604,   605,   606,   615,   618,   619,   624,   625,   626,
     629,   632,   635,   646,   650,   661,   662,   665,   668,   671,
     675,   678,   681,   684,   687,   690,   691,   694,   697,   700,
     711,   717,   720,   723,   730,   731,   734,   735,   736,   738,
     750,   751,   752,   755,   756,   757,   766,   769,   772,   773,
     775,   778,   779,   780,   781,   782,   783,   786,   790,   793,
     794,   797,   800,   807,   808,   809,   810,   811,   812,   813,
     817,   820,   823,   826,   829,   832,   835,   838,   841,   844,
     845,   856,   859,   862,   865,   866,   869,   873,   876,   879,
     881,   884,   887,   890,  1279,   128,   581,   128,   581,   580,
     581,   704,  1279,   581,   580,   581,   581,   580,   581,   580,
     581,   704,   128,   581,   581,   580,   581,   580,   581,   704,
     580,   580,   580,   581,   580,   581,   581,   580,   580,   581,
     704,   581,   580,   581,   581,   580,   580,   581,   580,   581,
     581,   580,   581,   581,   581,   580,   581,   280,   581,   787,
     789,  1279,   580,   581,   580,   581,   580,   580,   580,   580,
     580,   581,   704,   704,   613,  1279,    71,   128,   791,   581,
     704,   580,   581,   580,   581,   704,   581,   580,   581,   580,
     581,   704,   580,   581,    71,   580,   581,   580,   581,   580,
     580,   581,   580,   581,   704,   580,   581,   704,   580,   581,
     704,   580,   581,   704,   580,   580,   581,   704,   704,   581,
     610,  1279,   611,  1279,   612,  1279,   767,   614,  1279,   580,
     581,   704,   580,   581,   580,   580,   580,   581,   581,   580,
     581,   581,   580,   581,   704,   580,   581,   580,   581,   580,
     581,   580,   581,   580,   581,   580,   581,   651,   581,   581,
     580,   581,   581,   581,   587,     0,   590,    71,   581,    71,
      71,    71,   587,   580,    21,    22,    23,    27,    28,    29,
      30,    45,    55,    82,   230,   231,   264,   265,   344,   345,
     814,   815,   816,   938,   941,   945,   964,   965,  1027,  1028,
    1034,  1035,  1069,  1070,  1071,  1072,  1073,  1074,  1075,   580,
      33,    44,    92,   815,   818,   819,   982,  1014,  1076,    80,
      81,   139,   154,   196,   487,   488,   874,   875,   938,   945,
     964,  1006,  1018,  1023,  1029,  1037,  1198,  1199,   353,   580,
    1279,   256,   335,   336,   337,   616,   107,   112,   113,   114,
     142,   164,   167,   282,   308,   677,   679,   680,   895,   917,
     925,   928,   935,  1124,  1125,  1126,  1127,    44,    46,   257,
     259,   289,   863,   864,   902,   913,   984,  1128,  1129,   335,
     867,   868,  1279,    20,    26,    31,    32,   144,   145,   854,
     855,  1053,  1057,  1060,  1061,  1062,  1065,   580,   128,   580,
     787,   787,   627,   628,  1279,    35,     3,     4,     6,     8,
       9,    13,    16,    18,    36,    44,    52,    53,    59,    60,
      61,    77,    79,    82,    86,   104,   105,   106,   132,   133,
     134,   136,   137,   138,   147,   148,   151,   152,   155,   156,
     158,   159,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   180,   181,   182,   183,   184,   185,   194,   195,   197,
     198,   199,   200,   201,   202,   204,   205,   208,   209,   213,
     217,   218,   219,   223,   225,   227,   232,   234,   237,   238,
     239,   245,   247,   258,   263,   268,   272,   284,   285,   288,
     303,   315,   316,   320,   333,   459,   486,   494,   535,   536,
     758,   759,   895,   901,   904,   908,   909,   935,   938,   939,
     940,   941,   942,   943,   944,   948,   964,   965,   966,   967,
     968,   969,   975,   977,   983,   985,   986,   987,   988,   989,
     990,   991,   992,   993,   994,   995,   996,   997,   998,   999,
    1000,  1001,  1002,  1003,  1004,  1005,  1006,  1008,  1009,  1010,
    1011,  1012,  1013,  1014,  1015,  1016,  1017,  1018,  1019,  1020,
    1021,  1022,  1023,  1027,  1028,  1029,  1030,  1031,  1032,  1033,
    1034,  1035,  1036,  1037,  1038,  1039,  1040,  1041,  1043,  1044,
    1045,  1046,  1047,  1048,  1049,  1050,  1051,  1077,  1078,  1079,
    1080,  1081,  1082,  1083,  1084,  1085,  1130,  1191,  1197,  1198,
    1199,  1200,  1201,  1244,  1246,  1247,  1248,  1249,  1250,  1251,
    1253,  1254,   580,    47,   286,   311,   712,   713,   714,  1279,
      47,   311,   721,   722,  1279,    47,   311,   718,   719,  1279,
      12,   117,   247,   309,   346,   877,   878,   913,   914,   915,
     916,  1261,    88,   728,   729,   724,   725,  1279,   860,   861,
     913,   968,   975,   977,   983,   580,  1279,   630,   631,  1279,
      35,    78,   857,   858,  1279,     5,   150,   250,   251,   271,
     331,   332,   395,   784,   785,   902,   904,   913,   967,   968,
     975,   977,  1001,  1021,  1037,  1091,  1115,  1119,  1120,  1121,
    1122,  1123,  1129,  1244,  1245,   627,    35,    78,   885,   886,
    1279,  1019,   787,   163,   636,    11,    34,    49,    68,   149,
     168,   229,   255,   330,   633,   634,   900,   927,   930,   165,
    1024,   581,   353,   580,   787,   682,   683,   335,   649,   669,
     254,   882,   883,  1279,   770,   771,  1279,   774,  1279,    17,
      62,    63,    91,    93,   115,   116,   142,   167,   233,   235,
     240,   241,   270,   279,   281,   290,   299,   300,   301,   702,
     776,   777,   894,   895,   896,   900,   901,   902,   903,   904,
     905,   906,   907,   908,   909,   910,   911,   913,   921,   922,
     926,   931,   932,   933,   934,   935,   940,   942,   968,   975,
     977,   990,  1013,  1017,  1019,  1025,  1026,  1039,  1040,  1043,
    1044,  1048,  1049,  1050,  1051,  1180,  1181,  1191,  1251,  1252,
     580,   580,   353,   580,  1279,   327,   581,   608,   609,   128,
     580,    87,   128,   166,   178,   190,   191,   360,   361,   367,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     381,   385,   386,   387,   388,   389,   581,   642,   707,  1279,
     259,   580,   685,   686,   913,   938,   142,   143,   157,   167,
     179,   236,   302,   306,   310,   688,   689,   895,   897,   898,
     899,   918,   923,   924,   928,   929,  1007,  1255,  1261,   580,
     787,    47,   335,   647,   648,   649,   254,   226,   237,   297,
     349,   848,   849,   938,   941,   945,   970,   971,  1129,  1264,
    1265,   580,   280,   891,   892,  1279,   224,   583,   686,   689,
     695,   696,   126,   127,   252,   253,   260,   888,   889,  1256,
    1257,  1258,  1259,  1260,   870,   676,   677,   118,   348,   430,
     701,   702,   703,   912,   919,  1006,  1130,  1131,   580,    92,
     265,   571,   850,   851,   938,   941,   945,   970,   972,   973,
     974,  1129,  1264,  1265,   580,    94,   324,   803,   804,  1042,
    1192,   580,   702,   805,   806,  1042,  1192,   580,   224,   798,
     799,   167,   326,   801,   802,   806,   920,  1243,   580,   580,
     161,   501,   353,   580,  1279,   327,   609,   353,   580,  1279,
     327,   609,   353,   580,  1279,   327,   609,   768,  1279,   353,
     580,  1279,    19,    20,    24,    25,    26,    31,    32,    37,
      38,   105,   144,   145,   232,   852,   853,   976,   978,  1052,
    1054,  1055,  1056,  1058,  1059,  1063,  1064,  1066,  1067,  1068,
    1264,  1265,   580,   216,   119,   391,   392,   393,   394,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   418,   547,   548,   549,   846,   847,   904,   938,   941,
     945,   964,   965,   967,   968,   975,   977,   983,   985,   995,
    1006,  1021,  1086,  1087,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,  1095,  1096,  1097,  1098,  1099,  1100,  1101,  1102,  1103,
    1104,  1105,  1106,  1107,  1108,  1109,  1110,  1111,  1112,  1113,
    1114,  1116,  1117,  1118,  1119,  1120,  1244,  1245,    56,    57,
      82,    83,   230,   732,   733,   936,   937,   946,   947,   949,
    1027,  1028,   419,   420,   421,   422,   423,   424,   425,   428,
     429,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     443,   444,   445,   446,   447,   448,   449,   466,   467,   468,
     469,   470,   473,   474,   475,   476,   477,   479,   480,   481,
     482,   483,   484,   485,   489,   490,   491,   562,   821,   822,
     938,  1014,  1134,  1135,  1136,  1137,  1138,  1139,  1140,  1141,
    1142,  1143,  1144,  1145,  1146,  1147,  1148,  1149,  1150,  1151,
    1152,  1153,  1154,  1156,  1157,  1158,  1159,  1160,  1161,  1162,
    1163,  1164,  1165,  1166,  1167,  1168,  1169,  1170,  1171,  1172,
    1173,  1174,  1175,  1176,  1177,  1178,  1179,  1206,   502,   293,
     317,   318,   495,   498,   537,   538,   540,   541,   543,   544,
     545,   550,   561,   830,   831,  1202,  1203,  1205,  1222,  1230,
    1231,  1232,  1235,  1236,  1237,  1238,  1239,  1240,  1241,   580,
     539,   824,   825,  1202,  1203,  1205,  1222,  1230,  1231,  1232,
    1234,  1235,  1236,  1237,  1238,  1240,  1241,   441,   542,   563,
     564,   565,   566,   567,   568,   569,   570,   572,   573,   574,
     575,   576,   577,   578,   842,   843,   938,  1027,  1028,  1134,
    1135,  1136,  1137,  1138,  1144,  1145,  1146,  1148,  1152,  1153,
    1154,  1155,  1202,  1203,  1204,  1206,  1207,  1208,  1209,  1210,
    1211,  1212,  1213,  1214,  1215,  1216,  1217,  1218,  1219,  1220,
    1221,    63,   175,   243,   560,   839,   840,  1132,  1133,  1202,
    1203,  1222,  1223,  1224,   555,   556,   557,   558,   559,   836,
     837,  1202,  1203,  1205,  1225,  1226,  1227,  1228,  1229,   551,
     833,   834,  1202,  1203,  1232,  1233,   546,   827,   828,  1202,
    1203,  1205,  1222,  1230,  1231,  1235,  1236,  1237,  1238,  1239,
    1240,  1241,  1242,   580,   256,   493,   519,   520,   521,   522,
     663,   664,  1182,  1183,  1184,  1185,  1186,  1187,   526,   527,
     529,   666,   667,  1182,  1188,  1189,  1190,   531,   532,   533,
     534,   698,   699,  1193,  1194,  1195,  1196,   269,   554,   692,
     693,  1262,  1263,   692,   461,    47,   108,   736,  1279,   737,
     981,  1279,    47,   108,   751,  1279,    47,   108,   756,  1279,
     120,   166,   178,   190,   191,   228,   360,   361,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   381,
     385,   386,   387,   581,   620,   707,  1279,   140,   141,   461,
    1279,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,   353,   582,    71,    71,    71,   353,
     582,    71,    71,   582,   353,  1279,   582,    71,    71,    71,
      71,    71,    71,    71,    71,   353,   582,    71,    71,    71,
      71,    71,   353,   582,  1279,    69,   868,   353,    71,    71,
      71,   582,   353,   580,   582,   582,    69,   628,    71,   582,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,   353,   582,  1279,  1279,    69,   713,   353,   580,  1279,
    1279,    69,   722,   353,  1279,  1279,    69,   719,   353,   582,
      71,    71,   582,   353,   360,   582,    69,   725,   353,   353,
     582,   582,    69,   631,   581,   582,    71,    69,   858,   353,
      71,    71,    71,    71,    71,    71,    71,    71,   582,   353,
      69,   582,    71,    69,   886,   353,   581,   582,   582,    71,
     583,   585,   638,   639,   642,   645,    71,    71,    71,    71,
     353,   582,    71,   582,   707,   787,   581,   353,   582,  1279,
      69,   649,   582,    69,   883,   353,    69,   771,   581,    69,
    1279,   353,   620,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,   353,   582,  1279,   327,   609,
     609,   353,   607,  1279,   353,   582,   607,   580,   581,   581,
     581,   581,   642,   642,   581,   581,   581,   581,   581,   581,
     581,   581,   581,   581,   581,   581,   581,   581,   581,   581,
     581,   642,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   366,   792,   643,    71,   353,   582,    71,    71,
      71,    71,    71,   353,   582,   582,  1279,  1279,    69,   648,
     582,    71,    71,    71,   582,   353,    71,    69,   892,    71,
      71,   360,   361,   581,   673,   674,   707,   708,   353,   582,
      71,    71,    71,    71,    71,   582,   353,   583,   871,   872,
    1279,   353,   582,    71,    71,   353,   582,    71,    71,    71,
     582,   353,    71,    71,   353,   582,   353,   582,   356,   357,
     358,   359,    69,   799,    71,    71,   353,   582,    71,    71,
    1279,   327,   609,   609,  1279,   327,   609,   609,  1279,   327,
     609,   609,   353,   580,  1279,  1279,    71,    71,    71,    71,
      71,    71,    71,   582,   353,   582,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,   582,   353,    71,
      71,    71,    71,    71,   353,   582,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,   353,
     582,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,   353,   582,   353,   582,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,   353,   582,    71,    71,    71,   353,   582,
      71,    71,    71,    71,   353,   582,   353,   582,    71,   353,
     582,   431,   512,   514,   515,   652,   653,    71,    71,    71,
      71,    71,    71,   353,   582,    71,   353,   582,    71,    71,
      71,    71,   353,   582,    71,    71,   353,   582,   582,   741,
     581,   581,   580,   587,   353,   582,    71,   581,   581,   580,
     587,   581,   581,   580,   587,   581,   581,   581,   581,   620,
     620,   581,   581,   581,   581,   581,   581,   581,   581,   581,
     581,   581,   581,   581,   581,   581,   620,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   366,   580,   621,
     581,   739,   587,   707,   708,   707,   128,   708,   128,   787,
     128,   128,   583,  1269,  1271,  1272,   128,   128,  1279,  1266,
    1279,   816,   128,   128,   707,   128,   819,   128,  1272,   707,
     580,   704,   874,   617,  1279,   128,   128,   128,   707,   707,
     128,   707,   128,   680,   580,   707,   581,    67,   273,   274,
     275,   276,   277,   278,   128,   128,   864,   580,   580,   580,
    1279,   350,   351,   352,   729,   729,   580,   704,   854,   580,
     704,   580,   704,   580,   620,   580,   128,   280,   707,  1279,
     707,   707,   707,   128,   787,  1269,  1272,   456,   457,   458,
     460,   581,   979,  1269,  1272,   128,   581,   707,   128,   707,
     128,   128,    58,    89,    90,   305,   707,   707,   707,   707,
     707,   707,   128,   128,   128,   128,   120,   360,   361,   708,
     709,   710,   128,   128,   128,  1279,   787,   128,  1272,   583,
    1273,  1274,  1274,   462,   463,   464,   787,   128,   206,   207,
     460,   707,   210,   211,   212,   214,   215,   128,  1279,   220,
     221,   222,   220,   221,   222,   581,   128,   128,   707,   120,
     707,   128,    89,    90,   707,   128,    50,    51,    89,   581,
     128,   759,   580,   704,   353,   580,    10,   103,   129,   130,
     131,   242,   328,   472,   620,   623,   715,   727,   353,   353,
     580,   620,   353,   353,   580,   620,   580,   128,   128,   580,
     877,   128,   580,   580,   620,   861,   580,   704,   587,   580,
     128,   360,   361,   706,   580,   787,   580,   620,   708,   128,
     128,   706,   128,   128,   128,   787,   128,   580,   784,   580,
     580,   787,   580,  1279,   128,  1267,   580,   580,   597,   224,
     640,   641,  1279,    69,   639,   645,    71,   580,   707,   581,
     128,   581,   633,   580,   146,   193,   789,   582,   581,   707,
     683,   580,   580,   580,   580,   580,  1279,   580,   620,   580,
     353,   620,  1279,   580,   707,   128,   128,   128,   787,   707,
     128,   707,   128,   707,   128,   128,   128,   777,   580,   704,
     327,   609,   609,   607,    71,   582,   607,   642,   642,   642,
     642,   642,   642,   642,   642,   642,   642,   642,   642,   642,
     642,   642,   642,   642,   642,   642,   642,   706,   582,   642,
     642,   642,   642,   642,   642,   642,   642,   642,   642,   642,
     580,   581,   128,   686,   580,   707,   707,   128,   707,   128,
     689,   580,   580,   353,    71,   353,   580,   580,   580,   128,
    1279,  1279,   580,   704,   848,   893,  1279,   580,   893,  1279,
     707,   707,   620,   580,   584,   353,   581,   708,   696,   580,
     787,   581,   787,   581,   128,   580,   888,   704,    69,   872,
      71,   677,   580,   707,  1272,   703,   580,   704,   128,   128,
    1272,   580,   704,   850,   581,   620,   804,   580,   704,   806,
     580,   795,   796,  1279,   620,   620,   620,   620,   580,   128,
     707,   802,   580,   704,   601,   600,   327,   609,   609,   327,
     609,   609,   327,   609,   609,  1279,   787,   350,   351,   352,
     128,   128,   581,   979,   729,   729,   580,   704,   852,   580,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   707,   128,   583,  1277,  1278,   707,   707,
     581,   581,   581,   128,   128,   581,   707,   128,   707,   707,
     707,   707,   707,   580,   846,   787,  1279,   729,   729,   128,
     733,   580,   128,   516,   517,   128,   128,   128,   128,   787,
     128,   581,   128,   224,   514,   515,   128,   128,   128,   128,
     128,   707,   707,   128,   128,   128,   128,   128,   128,   707,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,  1274,   822,
     580,   594,   128,   787,   128,   787,   787,  1274,   128,   128,
    1274,   708,   128,   831,   580,   704,   825,   580,   442,   460,
     707,   707,   707,   128,   707,   128,   128,   707,   707,   128,
     128,   128,   128,   707,   707,   843,   580,   128,   128,   128,
     840,   580,   128,   708,   708,   128,   837,   580,   834,   580,
     128,   828,   580,   511,   513,   528,   580,   580,    69,   653,
     583,   583,  1274,  1276,   128,   707,  1278,   128,   128,   664,
     580,  1269,  1272,   667,   580,   787,   128,   787,   787,   699,
     580,   787,   128,   693,   580,   580,   581,  1279,  1279,   981,
     580,   729,  1279,  1279,   461,  1279,  1279,  1279,   141,  1279,
     620,   620,   620,   620,   620,   620,   620,   620,   620,   620,
     620,   620,   620,   620,   620,   620,   620,   620,   620,   582,
     620,   620,   620,   620,   620,   620,   620,   620,   620,   620,
     620,   581,   123,   124,   125,   753,   754,   957,   958,   959,
     581,   141,   461,   128,   353,  1269,  1270,   353,   584,  1270,
     586,   580,   580,   580,   353,   580,  1279,   704,   259,   582,
     580,   580,   580,   580,   627,   979,   980,   704,   120,   120,
     353,   708,   353,   584,   708,   280,   760,   761,   280,   764,
     765,   580,  1279,   353,   580,   353,  1279,   620,   353,  1279,
     620,   580,    69,   718,   353,   580,   140,   141,   461,  1279,
     128,   128,   582,   630,   582,   353,   580,   627,   582,   353,
     582,   586,   582,   885,   642,    71,   353,   584,    71,   580,
     642,   704,   787,   788,   637,   580,   707,   582,   259,   669,
     353,   581,   582,  1279,   580,   620,   580,   609,   280,   353,
     353,   582,   582,   582,   582,   582,   582,   353,   582,   582,
     582,   582,   582,   582,   582,   582,   582,   353,   582,   353,
     582,   582,   582,   642,   644,   582,  1279,   620,  1279,   311,
     647,   580,   353,   580,  1279,   580,   582,   582,   674,   580,
     581,   708,   620,   704,   704,   584,   580,   620,   580,   580,
     704,   580,   580,   796,   580,   580,   580,   580,   580,   642,
     642,   609,   609,   609,   980,   580,   710,   584,   710,   586,
     704,   705,   705,   705,   705,   704,   642,   580,   128,   128,
     580,   580,   704,  1274,  1275,    95,    96,    97,    98,    99,
     100,   101,   102,   287,   748,   749,   950,   951,   952,   954,
     955,   956,   960,   961,   963,  1239,   353,   582,   586,   353,
     582,   587,   353,   582,   587,   353,   353,   582,   582,   582,
     582,   582,   582,   353,   582,   582,   582,   582,   582,   582,
     582,   582,   582,   353,   582,   353,   582,   620,   622,    71,
      71,    71,   353,   582,    96,    98,   746,   747,   950,   951,
     952,   953,   955,   956,   960,   961,   962,  1239,   581,   740,
     586,  1270,   584,  1270,  1279,  1279,   582,   128,   670,   587,
      69,   353,   582,   582,   708,   584,   708,   353,   353,   582,
     353,   353,   582,   620,   623,   727,   623,   716,   353,   353,
     620,   353,   580,   580,    69,   620,   581,   742,   587,    71,
      69,   580,   620,    69,   580,   360,   361,   583,   880,   353,
     128,   353,    69,   582,   280,   641,   642,   642,   580,   582,
     353,   582,   638,   582,   670,    69,   880,   361,   706,  1268,
     580,   620,   580,   642,   642,   642,   642,   642,   581,   353,
     582,   704,    71,   580,    71,   620,    69,  1279,   580,   620,
     582,   582,   582,    71,   580,   582,   582,   582,   582,   582,
     582,   582,   582,   582,   582,   353,   580,   584,   353,   584,
      71,    71,    71,    71,    71,    71,    71,    71,    71,   353,
     582,  1279,   587,   729,  1279,   587,   461,  1279,   587,   141,
     620,   620,   620,   620,   620,   353,   582,  1278,   707,   708,
     754,   580,    71,    71,   353,   582,   753,   581,   128,   586,
     128,   353,   580,   140,   141,   461,  1279,   580,   979,   280,
     708,   760,   280,   581,   708,   764,   353,   353,   353,   620,
     620,   580,   620,   580,   580,   753,   581,   141,   461,   620,
     580,   580,   580,   710,   580,  1279,  1279,   580,   598,  1279,
      71,   580,   580,   787,    69,   580,   580,   580,   581,   582,
     586,   582,   580,   582,   582,   582,   353,   353,   642,   642,
     580,   620,   620,   580,   580,   891,   582,   620,   602,  1279,
     602,   595,  1279,   654,   511,   656,  1274,   708,  1274,   707,
    1276,   708,  1274,   444,   450,   451,   452,   453,   454,   455,
     465,   471,   726,  1274,  1274,   749,   580,   582,   582,   461,
    1279,   582,   141,  1279,   582,   582,   582,   353,   353,   620,
     708,   620,   747,   580,   582,   746,   128,   586,   128,   334,
     581,   744,   587,   280,   762,   763,   623,   716,   623,   353,
     580,   580,   582,   746,   581,   743,   580,   353,   710,   353,
     353,   353,   580,  1279,   327,   642,   580,   334,   706,   353,
     706,   353,   642,   642,   582,   580,   580,    69,   580,   353,
     580,  1279,   327,   609,   580,   353,   580,  1279,   327,   360,
     361,   525,   620,   658,   659,   660,   128,   511,   587,   587,
     587,   587,   587,   620,   620,   580,   582,   128,   586,   581,
     672,   708,   753,   581,   141,   461,   353,   353,   582,   353,
     353,   620,   580,   582,   753,   581,   710,   584,   880,   880,
    1279,   327,   580,   672,   586,   880,   880,   582,   582,   580,
    1279,   327,   609,   609,  1279,   327,   525,   525,   581,   362,
      71,   620,   660,   353,   128,   461,  1279,   461,   141,  1279,
     141,   582,   582,   580,   128,   620,   353,   580,   581,   708,
     582,   746,   581,   745,   280,   708,   762,   727,   623,   580,
     580,   582,   746,   584,   580,   580,   327,   580,   706,   580,
     580,   327,   609,   609,   327,   581,   581,  1279,   525,   655,
     657,  1279,   353,   587,   587,   582,   581,   708,   620,   580,
     582,   753,   581,   353,   353,   580,   582,   582,   609,  1279,
    1279,   353,   581,   658,   353,   580,   657,   461,   141,   620,
     582,   580,   582,   746,   716,   623,   580,   353,   353,   128,
    1279,   580,  1279,   580,   582,   580,   582,   353,   128,   128,
     582,   353,   580,   620,   582,   582,   128,   582
  };

  const unsigned short int
  parser::yyr1_[] =
  {
       0,   588,   589,   589,   590,   590,   590,   590,   590,   590,
     590,   590,   590,   590,   590,   590,   590,   590,   590,   590,
     590,   590,   590,   590,   590,   590,   590,   590,   590,   590,
     590,   590,   590,   590,   590,   590,   590,   590,   590,   590,
     590,   590,   590,   590,   590,   590,   590,   590,   590,   590,
     590,   590,   590,   590,   590,   590,   590,   590,   590,   590,
     590,   590,   590,   590,   590,   590,   590,   590,   590,   590,
     590,   590,   590,   590,   590,   590,   590,   590,   590,   590,
     590,   590,   590,   590,   590,   590,   590,   590,   590,   590,
     590,   590,   590,   590,   590,   590,   590,   590,   590,   590,
     591,   591,   592,   594,   593,   595,   595,   595,   595,   595,
     595,   597,   596,   598,   598,   598,   598,   598,   598,   599,
     600,   599,   601,   599,   602,   602,   602,   602,   602,   602,
     602,   602,   602,   602,   602,   602,   603,   604,   605,   606,
     607,   608,   608,   608,   608,   609,   609,   610,   610,   610,
     610,   610,   610,   610,   610,   610,   610,   610,   610,   611,
     611,   611,   611,   611,   611,   611,   611,   611,   611,   611,
     611,   612,   612,   612,   612,   612,   612,   612,   612,   612,
     612,   612,   612,   613,   613,   613,   613,   613,   613,   613,
     613,   613,   613,   613,   613,   614,   614,   614,   615,   616,
     616,   616,   616,   617,   617,   617,   618,   618,   619,   620,
     620,   620,   620,   620,   620,   620,   620,   620,   620,   620,
     620,   620,   620,   620,   620,   620,   620,   620,   620,   620,
     620,   620,   620,   620,   620,   620,   620,   620,   620,   620,
     620,   620,   621,   620,   620,   620,   620,   620,   620,   620,
     620,   622,   622,   623,   623,   624,   624,   625,   626,   626,
     627,   627,   628,   629,   629,   630,   630,   631,   632,   633,
     633,   633,   633,   633,   633,   633,   633,   633,   633,   634,
     634,   636,   635,   637,   635,   638,   638,   638,   638,   639,
     639,   639,   639,   640,   640,   641,   641,   642,   642,   642,
     642,   642,   642,   642,   642,   642,   642,   642,   642,   642,
     642,   642,   642,   642,   642,   642,   642,   642,   642,   642,
     642,   642,   642,   642,   642,   642,   642,   642,   642,   642,
     642,   643,   642,   642,   642,   642,   642,   642,   642,   644,
     644,   645,   646,   646,   647,   647,   648,   648,   648,   648,
     648,   649,   651,   650,   652,   652,   653,   653,   654,   655,
     653,   653,   653,   656,   656,   657,   657,   658,   658,   659,
     659,   660,   660,   660,   660,   661,   662,   663,   663,   664,
     664,   664,   664,   664,   664,   665,   666,   666,   667,   667,
     667,   667,   668,   668,   669,   669,   670,   670,   670,   670,
     670,   670,   671,   672,   672,   672,   672,   672,   672,   673,
     673,   674,   674,   674,   674,   674,   674,   675,   675,   676,
     676,   677,   677,   677,   677,   677,   677,   677,   677,   678,
     678,   679,   679,   680,   680,   681,   681,   682,   682,   683,
     684,   684,   685,   685,   686,   686,   687,   687,   688,   688,
     689,   689,   689,   689,   689,   689,   689,   689,   689,   689,
     689,   689,   690,   691,   692,   692,   693,   693,   694,   694,
     695,   695,   696,   696,   697,   698,   698,   699,   699,   699,
     699,   700,   700,   700,   700,   701,   701,   702,   702,   702,
     702,   702,   702,   702,   702,   702,   702,   702,   702,   702,
     702,   702,   702,   702,   702,   702,   702,   702,   702,   702,
     702,   702,   702,   702,   702,   702,   702,   702,   702,   702,
     702,   702,   702,   702,   702,   702,   702,   702,   702,   703,
     703,   703,   703,   703,   703,   704,   704,   704,   705,   705,
     706,   706,   706,   707,   707,   708,   708,   708,   709,   709,
     709,   710,   710,   711,   712,   712,   713,   713,   714,   714,
     714,   714,   715,   715,   715,   715,   715,   716,   716,   716,
     716,   717,   717,   717,   718,   718,   719,   719,   719,   720,
     721,   721,   722,   722,   722,   723,   724,   724,   725,   726,
     726,   726,   726,   726,   726,   726,   726,   726,   727,   727,
     727,   727,   727,   727,   727,   727,   728,   729,   729,   730,
     731,   732,   732,   733,   733,   733,   733,   733,   733,   733,
     734,   735,   736,   736,   736,   737,   737,   739,   738,   740,
     738,   741,   738,   742,   738,   743,   738,   744,   738,   745,
     738,   746,   746,   747,   747,   747,   747,   747,   747,   747,
     747,   747,   747,   748,   748,   749,   749,   749,   749,   749,
     749,   749,   749,   749,   749,   750,   751,   751,   751,   751,
     751,   751,   752,   752,   752,   752,   752,   752,   753,   753,
     754,   754,   754,   755,   756,   756,   756,   756,   756,   756,
     757,   757,   757,   757,   758,   758,   759,   759,   759,   759,
     759,   759,   759,   759,   759,   759,   759,   759,   759,   759,
     759,   759,   759,   759,   759,   759,   759,   759,   759,   759,
     759,   759,   759,   759,   759,   759,   759,   759,   759,   759,
     759,   759,   759,   759,   759,   759,   759,   759,   759,   759,
     759,   759,   759,   759,   759,   759,   759,   759,   759,   759,
     759,   759,   759,   759,   759,   759,   759,   759,   759,   759,
     759,   759,   759,   759,   759,   759,   759,   759,   759,   759,
     759,   759,   759,   759,   759,   759,   759,   759,   759,   759,
     759,   759,   759,   759,   759,   759,   759,   759,   759,   759,
     759,   759,   759,   759,   759,   759,   759,   759,   759,   759,
     759,   759,   759,   759,   759,   759,   760,   760,   761,   761,
     762,   762,   763,   763,   764,   764,   764,   765,   765,   767,
     766,   768,   768,   768,   769,   770,   770,   771,   772,   773,
     774,   774,   774,   774,   775,   776,   776,   777,   777,   777,
     777,   777,   777,   777,   778,   778,   778,   778,   779,   779,
     780,   780,   781,   782,   783,   783,   784,   784,   785,   785,
     785,   785,   785,   785,   785,   785,   785,   785,   785,   785,
     785,   785,   785,   785,   785,   785,   785,   785,   786,   786,
     787,   787,   788,   788,   789,   789,   789,   789,   789,   789,
     791,   792,   790,   793,   793,   793,   793,   794,   794,   794,
     794,   795,   795,   796,   797,   798,   798,   799,   799,   799,
     799,   800,   800,   800,   800,   801,   801,   802,   802,   802,
     803,   803,   804,   804,   805,   805,   806,   806,   806,   807,
     807,   808,   809,   810,   810,   810,   810,   811,   811,   811,
     811,   812,   812,   812,   812,   813,   813,   813,   813,   814,
     814,   814,   814,   814,   814,   814,   815,   815,   815,   815,
     815,   815,   815,   815,   815,   815,   816,   816,   817,   817,
     818,   818,   818,   818,   819,   819,   820,   820,   821,   821,
     821,   821,   821,   821,   821,   821,   821,   821,   821,   821,
     821,   821,   821,   821,   821,   821,   821,   821,   821,   821,
     821,   821,   821,   821,   821,   821,   821,   821,   821,   821,
     821,   821,   821,   821,   821,   821,   821,   821,   821,   821,
     821,   821,   821,   821,   821,   821,   822,   822,   823,   823,
     824,   824,   824,   824,   824,   824,   824,   824,   824,   824,
     824,   824,   824,   824,   825,   825,   826,   826,   827,   827,
     827,   827,   827,   827,   827,   827,   827,   827,   827,   827,
     827,   827,   828,   828,   829,   829,   830,   830,   830,   830,
     830,   830,   830,   830,   830,   830,   830,   830,   830,   830,
     831,   831,   832,   832,   832,   832,   833,   833,   833,   833,
     834,   834,   835,   835,   836,   836,   836,   836,   836,   836,
     836,   836,   837,   837,   838,   838,   839,   839,   839,   839,
     839,   839,   839,   840,   840,   841,   841,   842,   842,   842,
     842,   842,   842,   842,   842,   842,   842,   842,   842,   842,
     842,   842,   842,   842,   842,   842,   842,   842,   842,   842,
     842,   842,   842,   842,   842,   842,   842,   842,   842,   842,
     842,   842,   843,   843,   844,   844,   845,   845,   846,   846,
     847,   847,   847,   847,   847,   847,   847,   847,   847,   847,
     847,   847,   847,   847,   847,   847,   847,   847,   847,   847,
     847,   847,   847,   847,   847,   847,   847,   847,   847,   847,
     847,   847,   847,   847,   847,   847,   847,   847,   847,   847,
     847,   847,   847,   847,   847,   847,   847,   847,   847,   847,
     847,   848,   848,   849,   849,   849,   849,   849,   849,   849,
     849,   850,   850,   851,   851,   851,   851,   851,   851,   851,
     851,   851,   851,   852,   852,   853,   853,   853,   853,   853,
     853,   853,   853,   853,   853,   853,   853,   853,   853,   853,
     854,   854,   855,   855,   855,   855,   855,   855,   856,   857,
     857,   858,   858,   859,   859,   859,   859,   860,   860,   861,
     861,   861,   861,   861,   862,   863,   863,   864,   864,   864,
     864,   864,   865,   865,   866,   867,   867,   868,   870,   869,
     871,   871,   872,   872,   873,   873,   873,   873,   874,   874,
     875,   875,   875,   875,   875,   875,   875,   875,   875,   875,
     876,   876,   877,   877,   878,   878,   878,   878,   878,   879,
     880,   880,   880,   880,   881,   882,   882,   883,   883,   883,
     884,   884,   885,   885,   886,   886,   886,   887,   887,   888,
     888,   889,   889,   889,   889,   889,   890,   890,   891,   891,
     892,   892,   893,   893,   893,   894,   895,   896,   897,   898,
     899,   900,   901,   902,   903,   904,   905,   906,   907,   908,
     909,   910,   911,   912,   913,   914,   915,   916,   917,   918,
     919,   919,   920,   921,   922,   923,   924,   925,   926,   926,
     927,   928,   929,   930,   931,   932,   933,   934,   935,   936,
     937,   938,   939,   940,   941,   941,   942,   942,   943,   943,
     944,   945,   946,   947,   948,   949,   950,   951,   952,   953,
     954,   955,   956,   957,   958,   959,   960,   961,   962,   963,
     964,   965,   966,   967,   968,   968,   969,   969,   970,   971,
     972,   973,   974,   975,   976,   977,   977,   978,   978,   979,
     979,   979,   979,   980,   980,   981,   982,   983,   984,   985,
     986,   987,   988,   989,   990,   991,   992,   993,   994,   995,
     996,   996,   997,   998,   999,  1000,  1001,  1002,  1003,  1004,
    1005,  1006,  1007,  1008,  1009,  1010,  1011,  1011,  1011,  1012,
    1013,  1014,  1015,  1016,  1017,  1018,  1019,  1020,  1021,  1022,
    1023,  1024,  1024,  1025,  1026,  1027,  1028,  1029,  1030,  1031,
    1032,  1033,  1034,  1035,  1036,  1037,  1038,  1039,  1040,  1041,
    1042,  1043,  1043,  1044,  1045,  1045,  1045,  1045,  1046,  1047,
    1048,  1048,  1048,  1049,  1050,  1051,  1052,  1053,  1054,  1055,
    1056,  1057,  1058,  1059,  1059,  1059,  1060,  1060,  1060,  1061,
    1062,  1063,  1064,  1065,  1066,  1067,  1068,  1069,  1070,  1071,
    1072,  1073,  1074,  1075,  1076,  1077,  1078,  1078,  1078,  1079,
    1080,  1080,  1080,  1081,  1081,  1082,  1083,  1084,  1084,  1084,
    1085,  1085,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1092,
    1093,  1094,  1095,  1096,  1097,  1098,  1099,  1100,  1101,  1102,
    1103,  1104,  1105,  1106,  1107,  1108,  1109,  1110,  1111,  1112,
    1113,  1114,  1115,  1115,  1116,  1117,  1118,  1119,  1120,  1121,
    1122,  1123,  1124,  1125,  1126,  1127,  1128,  1129,  1129,  1129,
    1129,  1129,  1129,  1129,  1130,  1131,  1132,  1133,  1134,  1134,
    1134,  1135,  1136,  1137,  1138,  1139,  1140,  1141,  1142,  1143,
    1143,  1143,  1144,  1145,  1146,  1147,  1148,  1149,  1150,  1151,
    1152,  1153,  1154,  1155,  1155,  1156,  1157,  1158,  1159,  1160,
    1161,  1162,  1163,  1164,  1165,  1166,  1167,  1168,  1169,  1170,
    1171,  1172,  1173,  1174,  1175,  1176,  1177,  1178,  1179,  1180,
    1181,  1182,  1183,  1184,  1184,  1185,  1186,  1187,  1188,  1189,
    1190,  1190,  1191,  1192,  1193,  1194,  1195,  1195,  1196,  1196,
    1197,  1198,  1199,  1200,  1201,  1202,  1203,  1204,  1205,  1206,
    1207,  1208,  1209,  1210,  1211,  1212,  1213,  1214,  1215,  1216,
    1217,  1218,  1219,  1220,  1221,  1222,  1223,  1224,  1225,  1226,
    1227,  1228,  1229,  1230,  1231,  1232,  1233,  1234,  1235,  1236,
    1237,  1238,  1239,  1239,  1240,  1241,  1242,  1243,  1244,  1245,
    1246,  1247,  1248,  1248,  1248,  1248,  1249,  1250,  1251,  1252,
    1253,  1254,  1255,  1256,  1257,  1258,  1259,  1260,  1261,  1262,
    1263,  1264,  1264,  1265,  1266,  1267,  1268,  1268,  1269,  1270,
    1270,  1271,  1271,  1271,  1271,  1272,  1272,  1273,  1273,  1273,
    1273,  1274,  1274,  1275,  1275,  1276,  1276,  1277,  1277,  1278,
    1279,  1279,  1279,  1279,  1279,  1279,  1279,  1279,  1279,  1279,
    1279,  1279,  1279,  1279,  1279,  1279,  1279,  1279,  1279,  1279
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
       4,     6,     0,     5,     8,     4,     8,     4,     4,     1,
       1,     1,     3,     0,     1,     5,     8,     7,     5,     8,
       2,     1,     4,     5,     8,     2,     1,     7,     7,     1,
       1,     1,     1,     1,     1,     1,     5,     1,     5,     3,
       1,     0,     6,     0,     9,     2,     2,     1,     1,     4,
       2,     7,     5,     3,     1,     3,     1,     3,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     7,     2,     2,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     6,     6,     4,
       6,     0,     5,     8,     4,     8,     4,     4,     4,     1,
       3,     5,     5,     8,     2,     1,     1,     6,     5,     7,
       7,     9,     0,     6,     2,     1,     5,     3,     0,     0,
      10,     2,     2,     6,     5,     3,     1,     1,     1,     1,
       2,     6,     7,     7,     8,     2,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     5,     3,     1,     1,     1,
       1,     1,     5,     8,     2,     1,     3,     2,     5,     4,
       3,     1,     6,     5,     4,     3,     3,     2,     1,     3,
       1,     5,     3,     4,     2,     3,     1,     2,     5,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       5,     3,     1,     1,     1,     2,     5,     3,     1,     0,
       2,     5,     3,     1,     1,     1,     2,     5,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     5,     3,     1,     1,     1,     2,     5,
       3,     1,     1,     1,     5,     3,     1,     1,     1,     1,
       1,     2,     5,     3,     6,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     1,     1,     1,
       2,     2,     1,     1,     1,     2,     2,     1,     2,     2,
       1,     1,     1,     5,     2,     1,     4,     2,     2,     1,
       4,     1,     3,     5,     9,     1,     5,     3,     5,     7,
       9,     5,     7,     8,     2,     1,     5,     7,     4,     5,
       2,     1,     7,     9,     6,     5,     2,     1,     6,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     5,
       5,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     4,     3,     6,     8,     3,     1,     0,     8,     0,
      10,     0,     8,     0,    11,     0,    13,     0,    13,     0,
      15,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     3,     5,     6,     8,
       8,    10,     7,     9,    10,    12,    12,    14,     3,     1,
       1,     1,     1,     4,     3,     5,     6,     8,     8,    10,
       2,     5,     3,     6,     3,     1,     1,     1,     1,     1,
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
       1,     1,     1,     1,     1,     1,     3,     3,     1,     3,
       3,     3,     1,     3,     3,     3,     5,     1,     3,     0,
       4,     2,     3,     1,     5,     2,     1,     5,     3,     5,
       4,     6,     3,     5,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     5,     3,     6,     5,     6,
       5,     6,     5,     5,     2,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     6,
       1,     1,     1,     3,     1,     4,     2,     5,     3,     6,
       0,     0,     5,     2,     5,     3,     6,     2,     5,     3,
       6,     2,     1,     1,     5,     2,     1,     4,     4,     4,
       4,     2,     5,     3,     6,     3,     1,     1,     1,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     1,     2,
       5,     2,     2,     2,     5,     3,     6,     2,     5,     3,
       6,     2,     5,     3,     6,     2,     5,     3,     6,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     3,     6,
       1,     1,     1,     1,     3,     1,     3,     6,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     2,     5,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     2,     5,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     2,     5,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     2,     5,     3,     6,     1,     1,     1,     1,
       3,     1,     2,     5,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     2,     5,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     2,     5,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     2,     5,     2,     5,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     5,     1,
       2,     6,     4,     2,     5,     3,     6,     1,     3,     1,
       1,     1,     1,     1,     5,     1,     3,     1,     1,     1,
       1,     1,     3,     8,     5,     1,     2,     9,     0,     6,
       2,     1,     4,     6,     2,     5,     3,     6,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     5,     3,     1,     1,     1,     1,     1,     1,     2,
       4,     5,     1,     1,     5,     1,     2,     6,     9,     9,
       5,     8,     1,     2,     6,     9,     9,     2,     5,     3,
       1,     1,     1,     1,     1,     1,     5,    10,     2,     1,
       4,     4,     3,     2,     1,     3,     3,     3,     3,     1,
       1,     1,     3,     3,     3,     3,     1,     1,     1,     3,
       5,     3,     3,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     1,     1,     3,     5,     3,     5,     1,
       1,     1,     1,     1,     3,     5,     3,     3,     3,     3,
       3,     3,     3,     3,     5,     5,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     1,     1,     3,     3,     3,     3,     3,
       1,     3,     1,     1,     1,     1,     3,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     5,     5,     5,     3,     3,     5,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     5,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     5,     3,     3,
       3,     3,     3,     1,     1,     3,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     3,     3,     3,     3,     3,     3,     5,     1,     1,
       3,     3,     1,     5,     3,     3,     3,     1,     3,     1,
       1,     1,     1,     1,     3,     3,     3,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     3,     1,
       3,     3,     3,     1,     3,     1,     1,     1,     3,     3,
       3,     3,     1,     3,     1,     3,     3,     3,     1,     3,
       1,     3,     3,     3,     3,     3,     1,     1,     3,     3,
       1,     1,     1,     3,     5,     3,     3,     5,     1,     3,
       3,     1,     3,     3,     3,     3,     3,     6,     1,     1,
       3,     2,     3,     2,     3,     2,     3,     2,     3,     2,
       3,     2,     3,     3,     1,     3,     1,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
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
  "POWER", "EXP", "LOG", "LN", "LOG10", "LINLOG", "SIN", "COS", "TAN",
  "ASIN", "ACOS", "ATAN", "SINH", "COSH", "TANH", "ERF", "ASINH", "ACOSH",
  "ATANH", "SQRT", "NORMCDF", "NORMPDF", "STEADY_STATE", "EXPECTATION",
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
     620,   622,   624,   624,   626,   628,   630,   632,   634,   636,
     638,   642,   644,   648,   649,   652,   654,   658,   662,   664,
     668,   669,   672,   674,   676,   680,   681,   684,   686,   690,
     691,   692,   693,   694,   695,   696,   697,   698,   699,   702,
     703,   706,   706,   708,   708,   712,   713,   714,   715,   718,
     720,   722,   724,   728,   729,   732,   734,   738,   740,   742,
     744,   746,   748,   750,   752,   754,   756,   758,   760,   762,
     764,   766,   768,   770,   772,   774,   776,   778,   780,   782,
     784,   786,   788,   790,   792,   794,   796,   798,   800,   802,
     804,   806,   806,   808,   810,   812,   814,   816,   818,   822,
     824,   828,   831,   832,   835,   836,   839,   840,   842,   844,
     846,   850,   854,   854,   858,   859,   862,   864,   867,   869,
     866,   871,   873,   877,   879,   883,   885,   889,   890,   893,
     894,   897,   899,   901,   903,   907,   911,   915,   916,   919,
     920,   921,   922,   923,   924,   927,   931,   932,   935,   936,
     937,   938,   941,   942,   945,   946,   949,   951,   953,   955,
     957,   959,   963,   965,   967,   969,   971,   973,   975,   979,
     981,   985,   987,   989,   991,   993,   995,   999,  1001,  1005,
    1006,  1009,  1010,  1011,  1012,  1013,  1014,  1015,  1016,  1019,
    1021,  1025,  1026,  1029,  1030,  1033,  1035,  1039,  1040,  1042,
    1044,  1046,  1050,  1051,  1054,  1055,  1058,  1060,  1064,  1065,
    1068,  1069,  1070,  1071,  1072,  1073,  1074,  1075,  1076,  1077,
    1078,  1079,  1082,  1086,  1090,  1091,  1094,  1095,  1098,  1100,
    1104,  1105,  1108,  1109,  1112,  1116,  1117,  1120,  1121,  1122,
    1123,  1126,  1128,  1130,  1132,  1136,  1137,  1140,  1141,  1142,
    1143,  1144,  1145,  1146,  1147,  1148,  1149,  1150,  1151,  1152,
    1153,  1154,  1155,  1156,  1157,  1158,  1159,  1160,  1161,  1162,
    1163,  1164,  1165,  1166,  1167,  1168,  1169,  1170,  1171,  1172,
    1173,  1174,  1175,  1176,  1177,  1178,  1179,  1180,  1181,  1184,
    1185,  1186,  1187,  1188,  1189,  1192,  1194,  1196,  1200,  1201,
    1208,  1210,  1212,  1215,  1216,  1219,  1221,  1223,  1226,  1228,
    1230,  1234,  1235,  1238,  1240,  1242,  1246,  1247,  1249,  1255,
    1261,  1269,  1276,  1280,  1285,  1292,  1296,  1304,  1309,  1315,
    1322,  1332,  1334,  1336,  1340,  1342,  1346,  1353,  1362,  1371,
    1374,  1376,  1380,  1388,  1398,  1408,  1411,  1413,  1417,  1426,
    1428,  1430,  1432,  1434,  1436,  1438,  1440,  1442,  1446,  1448,
    1450,  1452,  1454,  1456,  1458,  1460,  1464,  1466,  1468,  1472,
    1476,  1480,  1481,  1484,  1485,  1486,  1487,  1488,  1489,  1490,
    1493,  1497,  1505,  1511,  1517,  1525,  1526,  1529,  1529,  1531,
    1531,  1533,  1533,  1535,  1535,  1537,  1537,  1539,  1539,  1541,
    1541,  1545,  1546,  1549,  1550,  1551,  1552,  1553,  1554,  1555,
    1556,  1557,  1558,  1561,  1562,  1565,  1566,  1567,  1568,  1569,
    1570,  1571,  1572,  1573,  1574,  1577,  1586,  1594,  1602,  1610,
    1618,  1626,  1636,  1638,  1640,  1642,  1644,  1646,  1650,  1651,
    1654,  1655,  1656,  1659,  1668,  1676,  1684,  1692,  1700,  1708,
    1718,  1720,  1722,  1724,  1728,  1729,  1732,  1733,  1734,  1735,
    1736,  1737,  1738,  1739,  1740,  1741,  1742,  1743,  1744,  1745,
    1746,  1747,  1748,  1749,  1750,  1751,  1752,  1753,  1754,  1755,
    1756,  1757,  1758,  1759,  1760,  1761,  1762,  1763,  1764,  1765,
    1766,  1767,  1768,  1769,  1770,  1771,  1772,  1773,  1774,  1775,
    1776,  1777,  1778,  1779,  1780,  1781,  1782,  1783,  1784,  1785,
    1786,  1787,  1788,  1789,  1790,  1791,  1792,  1793,  1794,  1795,
    1796,  1797,  1798,  1799,  1800,  1801,  1802,  1803,  1804,  1805,
    1806,  1807,  1808,  1809,  1810,  1811,  1812,  1813,  1814,  1815,
    1816,  1817,  1818,  1819,  1820,  1821,  1822,  1823,  1824,  1825,
    1826,  1827,  1828,  1829,  1830,  1831,  1832,  1833,  1834,  1835,
    1836,  1837,  1838,  1839,  1840,  1841,  1844,  1846,  1850,  1851,
    1854,  1862,  1871,  1873,  1881,  1883,  1885,  1893,  1894,  1897,
    1897,  1899,  1901,  1903,  1907,  1909,  1910,  1913,  1915,  1917,
    1919,  1921,  1923,  1925,  1929,  1932,  1933,  1936,  1937,  1938,
    1939,  1940,  1941,  1942,  1945,  1947,  1949,  1951,  1955,  1957,
    1961,  1963,  1967,  1971,  1975,  1977,  1981,  1982,  1985,  1986,
    1987,  1988,  1989,  1990,  1991,  1992,  1993,  1994,  1995,  1996,
    1997,  1998,  1999,  2000,  2001,  2002,  2003,  2004,  2007,  2009,
    2013,  2014,  2017,  2019,  2023,  2025,  2027,  2029,  2031,  2033,
    2037,  2038,  2037,  2040,  2042,  2044,  2046,  2050,  2052,  2054,
    2056,  2060,  2061,  2064,  2067,  2071,  2072,  2075,  2077,  2079,
    2081,  2085,  2087,  2089,  2091,  2095,  2096,  2099,  2100,  2101,
    2104,  2105,  2108,  2109,  2112,  2113,  2116,  2117,  2118,  2121,
    2123,  2127,  2131,  2135,  2137,  2139,  2141,  2145,  2147,  2149,
    2151,  2155,  2157,  2159,  2161,  2165,  2167,  2169,  2171,  2175,
    2176,  2177,  2178,  2179,  2180,  2181,  2184,  2185,  2186,  2187,
    2188,  2189,  2190,  2191,  2192,  2193,  2196,  2197,  2200,  2202,
    2206,  2207,  2208,  2209,  2212,  2213,  2216,  2218,  2222,  2223,
    2224,  2225,  2226,  2227,  2228,  2229,  2230,  2231,  2232,  2233,
    2234,  2235,  2236,  2237,  2238,  2239,  2240,  2241,  2242,  2243,
    2244,  2245,  2246,  2247,  2248,  2249,  2250,  2251,  2252,  2253,
    2254,  2255,  2256,  2257,  2258,  2259,  2260,  2261,  2262,  2263,
    2264,  2265,  2266,  2267,  2268,  2269,  2272,  2273,  2276,  2278,
    2282,  2283,  2284,  2285,  2286,  2287,  2288,  2289,  2290,  2291,
    2292,  2293,  2294,  2295,  2298,  2299,  2302,  2304,  2308,  2309,
    2310,  2311,  2312,  2313,  2314,  2315,  2316,  2317,  2318,  2319,
    2320,  2321,  2324,  2325,  2328,  2330,  2334,  2335,  2336,  2337,
    2338,  2339,  2340,  2341,  2342,  2343,  2344,  2345,  2346,  2347,
    2350,  2351,  2354,  2356,  2358,  2360,  2364,  2365,  2366,  2367,
    2370,  2371,  2374,  2376,  2380,  2381,  2382,  2383,  2384,  2385,
    2386,  2387,  2390,  2391,  2394,  2396,  2400,  2401,  2402,  2403,
    2404,  2405,  2406,  2409,  2410,  2413,  2415,  2419,  2420,  2421,
    2422,  2423,  2424,  2425,  2426,  2427,  2428,  2429,  2430,  2431,
    2432,  2433,  2434,  2435,  2436,  2437,  2438,  2439,  2440,  2441,
    2442,  2443,  2444,  2445,  2446,  2447,  2448,  2449,  2450,  2451,
    2452,  2453,  2456,  2457,  2460,  2462,  2466,  2468,  2472,  2473,
    2476,  2477,  2478,  2479,  2480,  2481,  2482,  2483,  2484,  2485,
    2486,  2487,  2488,  2489,  2490,  2491,  2492,  2493,  2494,  2495,
    2496,  2497,  2498,  2499,  2500,  2501,  2502,  2503,  2504,  2505,
    2506,  2507,  2508,  2509,  2510,  2511,  2512,  2513,  2514,  2515,
    2516,  2517,  2518,  2519,  2520,  2521,  2522,  2523,  2524,  2525,
    2526,  2529,  2530,  2533,  2534,  2535,  2536,  2537,  2538,  2539,
    2540,  2543,  2544,  2547,  2548,  2549,  2550,  2551,  2552,  2553,
    2554,  2555,  2556,  2559,  2560,  2563,  2564,  2565,  2566,  2567,
    2568,  2569,  2570,  2571,  2572,  2573,  2574,  2575,  2576,  2577,
    2580,  2581,  2584,  2585,  2586,  2587,  2588,  2589,  2592,  2595,
    2596,  2599,  2601,  2605,  2606,  2607,  2608,  2611,  2612,  2615,
    2616,  2617,  2618,  2619,  2622,  2626,  2627,  2630,  2631,  2632,
    2633,  2634,  2637,  2639,  2643,  2647,  2648,  2651,  2655,  2655,
    2659,  2660,  2663,  2665,  2669,  2671,  2673,  2675,  2679,  2680,
    2683,  2684,  2685,  2686,  2687,  2688,  2689,  2690,  2691,  2692,
    2695,  2697,  2701,  2702,  2705,  2706,  2707,  2708,  2709,  2712,
    2716,  2722,  2728,  2734,  2742,  2746,  2747,  2750,  2752,  2754,
    2758,  2760,  2764,  2765,  2768,  2770,  2772,  2776,  2778,  2782,
    2783,  2786,  2787,  2788,  2789,  2790,  2793,  2794,  2798,  2799,
    2802,  2803,  2806,  2807,  2808,  2811,  2817,  2818,  2824,  2825,
    2826,  2827,  2828,  2829,  2830,  2831,  2832,  2833,  2834,  2835,
    2836,  2837,  2838,  2839,  2840,  2841,  2842,  2843,  2844,  2845,
    2846,  2847,  2853,  2854,  2855,  2856,  2857,  2858,  2859,  2860,
    2862,  2863,  2864,  2865,  2866,  2867,  2868,  2869,  2870,  2871,
    2872,  2873,  2874,  2875,  2876,  2878,  2881,  2883,  2886,  2888,
    2891,  2893,  2894,  2895,  2896,  2897,  2898,  2899,  2900,  2901,
    2902,  2903,  2904,  2905,  2906,  2907,  2908,  2909,  2910,  2911,
    2912,  2913,  2914,  2915,  2916,  2918,  2921,  2923,  2926,  2927,
    2928,  2929,  2930,  2931,  2932,  2933,  2935,  2938,  2940,  2943,
    2945,  2947,  2949,  2952,  2953,  2956,  2959,  2960,  2961,  2962,
    2963,  2964,  2965,  2966,  2967,  2968,  2969,  2970,  2973,  2974,
    2975,  2976,  2977,  2978,  2979,  2980,  2981,  2982,  2983,  2984,
    2985,  2986,  2987,  2988,  2989,  2990,  2991,  2993,  2995,  2998,
    2999,  3000,  3001,  3002,  3003,  3004,  3005,  3006,  3007,  3008,
    3009,  3010,  3012,  3015,  3016,  3017,  3018,  3019,  3020,  3021,
    3022,  3023,  3024,  3025,  3026,  3027,  3028,  3029,  3030,  3031,
    3032,  3033,  3034,  3035,  3036,  3037,  3038,  3039,  3040,  3041,
    3042,  3043,  3044,  3045,  3046,  3047,  3048,  3049,  3050,  3051,
    3052,  3053,  3054,  3055,  3057,  3059,  3062,  3064,  3066,  3069,
    3070,  3071,  3072,  3073,  3074,  3075,  3076,  3077,  3078,  3079,
    3080,  3081,  3082,  3083,  3084,  3086,  3087,  3088,  3089,  3090,
    3091,  3092,  3093,  3094,  3095,  3096,  3097,  3098,  3099,  3100,
    3101,  3102,  3103,  3106,  3107,  3108,  3109,  3110,  3111,  3112,
    3113,  3114,  3115,  3116,  3117,  3118,  3119,  3120,  3121,  3122,
    3123,  3124,  3125,  3126,  3127,  3128,  3129,  3130,  3131,  3132,
    3133,  3134,  3135,  3137,  3140,  3141,  3142,  3143,  3144,  3145,
    3146,  3147,  3149,  3150,  3151,  3152,  3154,  3155,  3157,  3159,
    3161,  3163,  3165,  3167,  3170,  3171,  3172,  3173,  3174,  3176,
    3178,  3181,  3182,  3183,  3184,  3185,  3186,  3187,  3188,  3189,
    3194,  3199,  3205,  3206,  3207,  3208,  3209,  3210,  3211,  3212,
    3213,  3214,  3215,  3216,  3218,  3221,  3222,  3223,  3224,  3225,
    3226,  3227,  3228,  3229,  3230,  3231,  3232,  3233,  3234,  3235,
    3236,  3237,  3238,  3239,  3240,  3241,  3242,  3243,  3244,  3245,
    3246,  3247,  3248,  3251,  3253,  3256,  3257,  3258,  3259,  3260,
    3261,  3263,  3266,  3267,  3269,  3270,  3271,  3273,  3276,  3278,
    3281,  3284,  3287,  3290,  3293,  3296,  3297,  3298,  3299,  3300,
    3302,  3304,  3306,  3308,  3310,  3312,  3314,  3316,  3318,  3320,
    3322,  3324,  3326,  3328,  3330,  3332,  3333,  3334,  3335,  3336,
    3337,  3338,  3339,  3340,  3341,  3342,  3343,  3344,  3345,  3346,
    3347,  3348,  3349,  3350,  3351,  3352,  3353,  3354,  3355,  3356,
    3357,  3358,  3359,  3360,  3362,  3364,  3367,  3368,  3369,  3370,
    3371,  3372,  3373,  3375,  3376,  3377,  3378,  3379,  3380,  3381,
    3382,  3383,  3384,  3386,  3388,  3396,  3404,  3411,  3421,  3423,
    3424,  3434,  3436,  3438,  3446,  3456,  3458,  3462,  3463,  3464,
    3471,  3480,  3481,  3484,  3491,  3495,  3496,  3498,  3500,  3509,
    3511,  3512,  3513,  3514,  3515,  3516,  3517,  3518,  3519,  3520,
    3521,  3522,  3523,  3524,  3525,  3526,  3527,  3528,  3529,  3530
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
       2,     2,     2,     2,     2,   585,     2,     2,     2,     2,
     581,   582,     2,     2,     2,     2,   587,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   586,   580,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   583,     2,   584,     2,     2,     2,     2,     2,     2,
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
     575,   576,   577,   578,   579
    };
    const unsigned int user_token_number_max_ = 834;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // Dynare
#line 11983 "DynareBison.cc" // lalr1.cc:1167
#line 3532 "lex_yacc/DynareBison.yy" // lalr1.cc:1168


void
Dynare::parser::error(const Dynare::parser::location_type &l,
                      const string &m)
{
  driver.error(l, m);
}
