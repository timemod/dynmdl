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
#line 24 "MacroBison.yy"

class MacroDriver;

#line 43 "MacroBison.cc"

// Take the name prefix into account.
#define yylex   Macrolex



#include "MacroBison.hh"


// Unqualified %code blocks.
#line 55 "MacroBison.yy"

#include <cstdlib>  // Pour atoi()
#include "MacroDriver.hh"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex

#define TYPERR_CATCH(statement, loc) try        \
    {                                           \
      statement;                                \
    }                                           \
  catch(MacroValue::TypeError &e)               \
    {                                           \
      driver.error(loc, e.message);             \
    }


#line 75 "MacroBison.cc"


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

namespace Macro {
#line 167 "MacroBison.cc"

  /// Build a parser object.
  parser::parser (MacroDriver &driver_yyarg, ostream &out_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      driver (driver_yyarg),
      out (out_yyarg)
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
#line 36 "MacroBison.yy"
{
  // Initialize the location filenames
  yyla.location.begin.filename = yyla.location.end.filename = &driver.file;
}

#line 513 "MacroBison.cc"


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
  case 6: // statement: expr
#line 107 "MacroBison.yy"
            { out << (yystack_[0].value.mv)->toString(); }
#line 651 "MacroBison.cc"
    break;

  case 7: // statement: DEFINE NAME EQUAL expr
#line 109 "MacroBison.yy"
            { driver.set_variable(*(yystack_[2].value.string_val), (yystack_[0].value.mv)); delete (yystack_[2].value.string_val); }
#line 657 "MacroBison.cc"
    break;

  case 8: // statement: FOR NAME IN expr
#line 111 "MacroBison.yy"
            { TYPERR_CATCH(driver.init_loop(*(yystack_[2].value.string_val), (yystack_[0].value.mv)), yylhs.location); delete (yystack_[2].value.string_val); }
#line 663 "MacroBison.cc"
    break;

  case 9: // statement: IF expr
#line 113 "MacroBison.yy"
            { TYPERR_CATCH(driver.begin_if((yystack_[0].value.mv)), yylhs.location); }
#line 669 "MacroBison.cc"
    break;

  case 10: // statement: IFDEF NAME
#line 115 "MacroBison.yy"
            { TYPERR_CATCH(driver.begin_ifdef(*(yystack_[0].value.string_val)), yylhs.location); delete (yystack_[0].value.string_val); }
#line 675 "MacroBison.cc"
    break;

  case 11: // statement: IFNDEF NAME
#line 117 "MacroBison.yy"
            { TYPERR_CATCH(driver.begin_ifndef(*(yystack_[0].value.string_val)), yylhs.location); delete (yystack_[0].value.string_val); }
#line 681 "MacroBison.cc"
    break;

  case 12: // statement: ECHO_DIR expr
#line 119 "MacroBison.yy"
            { TYPERR_CATCH(driver.echo(yylhs.location, (yystack_[0].value.mv)), yylhs.location); }
#line 687 "MacroBison.cc"
    break;

  case 13: // statement: ERROR expr
#line 121 "MacroBison.yy"
            { TYPERR_CATCH(driver.error(yylhs.location, (yystack_[0].value.mv)), yylhs.location); }
#line 693 "MacroBison.cc"
    break;

  case 15: // expr: INTEGER
#line 127 "MacroBison.yy"
       { (yylhs.value.mv) = new IntMV(driver, (yystack_[0].value.int_val)); }
#line 699 "MacroBison.cc"
    break;

  case 16: // expr: STRING
#line 129 "MacroBison.yy"
       { (yylhs.value.mv) = new StringMV(driver, *(yystack_[0].value.string_val)); delete (yystack_[0].value.string_val); }
#line 705 "MacroBison.cc"
    break;

  case 17: // expr: NAME
#line 131 "MacroBison.yy"
       {
         try
           {
             (yylhs.value.mv) = driver.get_variable(*(yystack_[0].value.string_val));
           }
         catch(MacroDriver::UnknownVariable(&e))
           {
             error(yylhs.location, "Unknown variable: " + e.name);
           }
         delete (yystack_[0].value.string_val);
       }
#line 721 "MacroBison.cc"
    break;

  case 18: // expr: LENGTH LPAREN expr RPAREN
#line 143 "MacroBison.yy"
       { TYPERR_CATCH((yylhs.value.mv) = (yystack_[1].value.mv)->length(), yylhs.location); }
#line 727 "MacroBison.cc"
    break;

  case 19: // expr: LPAREN expr RPAREN
#line 145 "MacroBison.yy"
       { (yylhs.value.mv) = (yystack_[1].value.mv); }
#line 733 "MacroBison.cc"
    break;

  case 20: // expr: expr PLUS expr
#line 147 "MacroBison.yy"
       { TYPERR_CATCH((yylhs.value.mv) = *(yystack_[2].value.mv) + *(yystack_[0].value.mv), yylhs.location); }
#line 739 "MacroBison.cc"
    break;

  case 21: // expr: expr MINUS expr
#line 149 "MacroBison.yy"
       { TYPERR_CATCH((yylhs.value.mv) = *(yystack_[2].value.mv) - *(yystack_[0].value.mv), yylhs.location); }
#line 745 "MacroBison.cc"
    break;

  case 22: // expr: expr TIMES expr
#line 151 "MacroBison.yy"
       { TYPERR_CATCH((yylhs.value.mv) = *(yystack_[2].value.mv) * *(yystack_[0].value.mv), yylhs.location); }
#line 751 "MacroBison.cc"
    break;

  case 23: // expr: expr DIVIDE expr
#line 153 "MacroBison.yy"
       {
         if (dynamic_cast<const IntMV *>((yystack_[0].value.mv)) != NULL
             && ((IntMV *)(yystack_[0].value.mv))->get_int_value() == 0)
           driver.error(yylhs.location, "Division by zero");
         TYPERR_CATCH((yylhs.value.mv) = *(yystack_[2].value.mv) / *(yystack_[0].value.mv), yylhs.location);
       }
#line 762 "MacroBison.cc"
    break;

  case 24: // expr: expr LESS expr
#line 160 "MacroBison.yy"
       { TYPERR_CATCH((yylhs.value.mv) = *(yystack_[2].value.mv) < *(yystack_[0].value.mv), yylhs.location); }
#line 768 "MacroBison.cc"
    break;

  case 25: // expr: expr GREATER expr
#line 162 "MacroBison.yy"
       { TYPERR_CATCH((yylhs.value.mv) = *(yystack_[2].value.mv) > *(yystack_[0].value.mv), yylhs.location); }
#line 774 "MacroBison.cc"
    break;

  case 26: // expr: expr LESS_EQUAL expr
#line 164 "MacroBison.yy"
       { TYPERR_CATCH((yylhs.value.mv) = *(yystack_[2].value.mv) <= *(yystack_[0].value.mv), yylhs.location); }
#line 780 "MacroBison.cc"
    break;

  case 27: // expr: expr GREATER_EQUAL expr
#line 166 "MacroBison.yy"
       { TYPERR_CATCH((yylhs.value.mv) = *(yystack_[2].value.mv) >= *(yystack_[0].value.mv), yylhs.location); }
#line 786 "MacroBison.cc"
    break;

  case 28: // expr: expr EQUAL_EQUAL expr
#line 168 "MacroBison.yy"
       { TYPERR_CATCH((yylhs.value.mv) = *(yystack_[2].value.mv) == *(yystack_[0].value.mv), yylhs.location); }
#line 792 "MacroBison.cc"
    break;

  case 29: // expr: expr EXCLAMATION_EQUAL expr
#line 170 "MacroBison.yy"
       { TYPERR_CATCH((yylhs.value.mv) = *(yystack_[2].value.mv) != *(yystack_[0].value.mv), yylhs.location); }
#line 798 "MacroBison.cc"
    break;

  case 30: // expr: expr LOGICAL_OR expr
#line 172 "MacroBison.yy"
       { TYPERR_CATCH((yylhs.value.mv) = *(yystack_[2].value.mv) || *(yystack_[0].value.mv), yylhs.location); }
#line 804 "MacroBison.cc"
    break;

  case 31: // expr: expr LOGICAL_AND expr
#line 174 "MacroBison.yy"
       { TYPERR_CATCH((yylhs.value.mv) = *(yystack_[2].value.mv) && *(yystack_[0].value.mv), yylhs.location); }
#line 810 "MacroBison.cc"
    break;

  case 32: // expr: MINUS expr
#line 176 "MacroBison.yy"
       { TYPERR_CATCH((yylhs.value.mv) = -*(yystack_[0].value.mv), yylhs.location); }
#line 816 "MacroBison.cc"
    break;

  case 33: // expr: PLUS expr
#line 178 "MacroBison.yy"
       { TYPERR_CATCH((yylhs.value.mv) = +(*(yystack_[0].value.mv)), yylhs.location); }
#line 822 "MacroBison.cc"
    break;

  case 34: // expr: EXCLAMATION expr
#line 180 "MacroBison.yy"
       { TYPERR_CATCH((yylhs.value.mv) = !*(yystack_[0].value.mv), yylhs.location); }
#line 828 "MacroBison.cc"
    break;

  case 35: // expr: expr LBRACKET array_expr RBRACKET
#line 182 "MacroBison.yy"
       {
         TYPERR_CATCH((yylhs.value.mv) = (*(yystack_[3].value.mv))[*(yystack_[1].value.mv)], yylhs.location)
         catch(MacroValue::OutOfBoundsError)
           {
             error(yylhs.location, "Index out of bounds");
           }
       }
#line 840 "MacroBison.cc"
    break;

  case 36: // expr: LBRACKET array_expr RBRACKET
#line 190 "MacroBison.yy"
       { (yylhs.value.mv) = (yystack_[1].value.mv); }
#line 846 "MacroBison.cc"
    break;

  case 37: // expr: expr COLON expr
#line 192 "MacroBison.yy"
       { TYPERR_CATCH((yylhs.value.mv) = IntMV::new_range(driver, (yystack_[2].value.mv), (yystack_[0].value.mv)), yylhs.location); }
#line 852 "MacroBison.cc"
    break;

  case 38: // expr: expr IN expr
#line 194 "MacroBison.yy"
       { TYPERR_CATCH((yylhs.value.mv) = (yystack_[2].value.mv)->in((yystack_[0].value.mv)), yylhs.location); }
#line 858 "MacroBison.cc"
    break;

  case 39: // array_expr: expr
#line 198 "MacroBison.yy"
             { (yylhs.value.mv) = (yystack_[0].value.mv)->toArray(); }
#line 864 "MacroBison.cc"
    break;

  case 40: // array_expr: array_expr COMMA expr
#line 200 "MacroBison.yy"
             { TYPERR_CATCH((yylhs.value.mv) = (yystack_[0].value.mv)->append((yystack_[2].value.mv)), yylhs.location); }
#line 870 "MacroBison.cc"
    break;


#line 874 "MacroBison.cc"

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


  const signed char parser::yypact_ninf_ = -15;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
      54,   -14,    -5,    -3,   227,   227,   227,     3,     4,   227,
     227,     1,   -15,   -15,   -15,   227,   227,   227,    30,    54,
      33,   139,    36,    34,    56,   139,   139,   139,   -15,   -15,
      75,   139,    -8,   227,    44,    44,    44,   -15,    50,   -15,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   -15,   227,   -15,   -15,
     227,   107,   -15,    -2,    -7,   171,   203,    81,    81,    81,
      81,    81,    81,   -13,    -9,    -9,    44,    44,   139,   139,
     139,   -15,   -15
  };

  const signed char
  parser::yydefact_[] =
  {
       2,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    15,    17,    16,     0,     0,     0,     0,     3,
       0,     6,     0,     0,     0,     9,    12,    13,    10,    11,
       0,    39,     0,     0,    33,    32,    34,     1,     0,     4,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    14,     0,    19,    36,
       0,     0,     5,    38,     0,    30,    31,    24,    25,    26,
      27,    28,    29,    37,    20,    21,    22,    23,     7,     8,
      40,    18,    35
  };

  const signed char
  parser::yypgoto_[] =
  {
     -15,   -15,   -15,    52,    -4,    22
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,    18,    19,    20,    21,    32
  };

  const signed char
  parser::yytable_[] =
  {
      25,    26,    27,    41,    -1,    30,    31,    41,    22,    59,
      82,    34,    35,    36,    41,    33,    60,    60,    23,    24,
      -1,    51,    52,    53,    54,    28,    29,    53,    54,    61,
      37,    50,    51,    52,    53,    54,    63,    31,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    39,    79,    55,    56,    80,     1,     2,     3,
      41,     4,    57,    64,     5,     6,     7,     8,     9,    62,
      10,    38,     0,     0,    11,    12,    13,    14,     0,     0,
       0,    40,     0,     0,     0,     0,     0,    40,    15,    16,
      58,    41,     0,     0,    17,     0,     0,    41,     0,     0,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    40,    50,    51,    52,    53,    54,     0,
       0,     0,    81,    41,     0,     0,     0,     0,     0,     0,
       0,     0,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    40,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    41,     0,     0,     0,     0,
       0,     0,     0,     0,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    40,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    41,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    40,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    41,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,     9,     0,    10,     0,     0,     0,    11,    12,    13,
      14,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    15,    16,     0,     0,     0,     0,    17
  };

  const signed char
  parser::yycheck_[] =
  {
       4,     5,     6,    16,     6,     9,    10,    16,    22,    17,
      17,    15,    16,    17,    16,    14,    24,    24,    23,    22,
      33,    34,    35,    36,    37,    22,    22,    36,    37,    33,
       0,    33,    34,    35,    36,    37,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    19,    57,    18,    21,    60,     3,     4,     5,
      16,     7,     6,    41,    10,    11,    12,    13,    14,    19,
      16,    19,    -1,    -1,    20,    21,    22,    23,    -1,    -1,
      -1,     6,    -1,    -1,    -1,    -1,    -1,     6,    34,    35,
      15,    16,    -1,    -1,    40,    -1,    -1,    16,    -1,    -1,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,     6,    33,    34,    35,    36,    37,    -1,
      -1,    -1,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    16,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    14,    -1,    16,    -1,    -1,    -1,    20,    21,    22,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    35,    -1,    -1,    -1,    -1,    40
  };

  const signed char
  parser::yystos_[] =
  {
       0,     3,     4,     5,     7,    10,    11,    12,    13,    14,
      16,    20,    21,    22,    23,    34,    35,    40,    42,    43,
      44,    45,    22,    23,    22,    45,    45,    45,    22,    22,
      45,    45,    46,    14,    45,    45,    45,     0,    44,    19,
       6,    16,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    18,    21,     6,    15,    17,
      24,    45,    19,    45,    46,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    15,    17
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    41,    42,    42,    43,    43,    44,    44,    44,    44,
      44,    44,    44,    44,    44,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    46,
      46
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     0,     1,     2,     3,     1,     4,     4,     2,
       2,     2,     2,     2,     3,     1,     1,     1,     4,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     2,     4,     3,     3,     3,     1,
       3
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "DEFINE", "LINE",
  "FOR", "IN", "IF", "ELSE", "ENDIF", "ECHO_DIR", "ERROR", "IFDEF",
  "IFNDEF", "LPAREN", "RPAREN", "LBRACKET", "RBRACKET", "EQUAL", "EOL",
  "LENGTH", "INTEGER", "NAME", "STRING", "COMMA", "LOGICAL_OR",
  "LOGICAL_AND", "LESS", "GREATER", "LESS_EQUAL", "GREATER_EQUAL",
  "EQUAL_EQUAL", "EXCLAMATION_EQUAL", "COLON", "PLUS", "MINUS", "TIMES",
  "DIVIDE", "UMINUS", "UPLUS", "EXCLAMATION", "$accept",
  "statement_list_or_nothing", "statement_list", "statement", "expr",
  "array_expr", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,    98,    98,    99,   102,   103,   106,   108,   110,   112,
     114,   116,   118,   120,   122,   126,   128,   130,   142,   144,
     146,   148,   150,   152,   159,   161,   163,   165,   167,   169,
     171,   173,   175,   177,   179,   181,   189,   191,   193,   197,
     199
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
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40
    };
    // Last valid token kind.
    const int code_max = 295;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

} // Macro
#line 1478 "MacroBison.cc"

#line 203 "MacroBison.yy"


void
Macro::parser::error(const Macro::parser::location_type &l,
                     const string &m)
{
  driver.error(l, m);
}
