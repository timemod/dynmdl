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
#line 24 "MacroBison.yy" // lalr1.cc:392

class MacroDriver;

#line 38 "MacroBison.cc" // lalr1.cc:392

// Take the name prefix into account.
#define yylex   Macrolex

// First part of user declarations.

#line 45 "MacroBison.cc" // lalr1.cc:399

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "MacroBison.hh"

// User implementation prologue.

#line 59 "MacroBison.cc" // lalr1.cc:407
// Unqualified %code blocks.
#line 55 "MacroBison.yy" // lalr1.cc:408

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


#line 82 "MacroBison.cc" // lalr1.cc:408


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


namespace Macro {
#line 168 "MacroBison.cc" // lalr1.cc:474

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
  parser::parser (MacroDriver &driver_yyarg, ostream &out_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg),
      out (out_yyarg)
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
    #line 36 "MacroBison.yy" // lalr1.cc:725
{
  // Initialize the location filenames
  yyla.location.begin.filename = yyla.location.end.filename = &driver.file;
}

#line 513 "MacroBison.cc" // lalr1.cc:725

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
  case 6:
#line 107 "MacroBison.yy" // lalr1.cc:847
    { out << (yystack_[0].value.mv)->toString(); }
#line 627 "MacroBison.cc" // lalr1.cc:847
    break;

  case 7:
#line 109 "MacroBison.yy" // lalr1.cc:847
    { driver.set_variable(*(yystack_[2].value.string_val), (yystack_[0].value.mv)); delete (yystack_[2].value.string_val); }
#line 633 "MacroBison.cc" // lalr1.cc:847
    break;

  case 8:
#line 111 "MacroBison.yy" // lalr1.cc:847
    { TYPERR_CATCH(driver.init_loop(*(yystack_[2].value.string_val), (yystack_[0].value.mv)), yylhs.location); delete (yystack_[2].value.string_val); }
#line 639 "MacroBison.cc" // lalr1.cc:847
    break;

  case 9:
#line 113 "MacroBison.yy" // lalr1.cc:847
    { TYPERR_CATCH(driver.begin_if((yystack_[0].value.mv)), yylhs.location); }
#line 645 "MacroBison.cc" // lalr1.cc:847
    break;

  case 10:
#line 115 "MacroBison.yy" // lalr1.cc:847
    { TYPERR_CATCH(driver.begin_ifdef(*(yystack_[0].value.string_val)), yylhs.location); delete (yystack_[0].value.string_val); }
#line 651 "MacroBison.cc" // lalr1.cc:847
    break;

  case 11:
#line 117 "MacroBison.yy" // lalr1.cc:847
    { TYPERR_CATCH(driver.begin_ifndef(*(yystack_[0].value.string_val)), yylhs.location); delete (yystack_[0].value.string_val); }
#line 657 "MacroBison.cc" // lalr1.cc:847
    break;

  case 12:
#line 119 "MacroBison.yy" // lalr1.cc:847
    { TYPERR_CATCH(driver.echo(yylhs.location, (yystack_[0].value.mv)), yylhs.location); }
#line 663 "MacroBison.cc" // lalr1.cc:847
    break;

  case 13:
#line 121 "MacroBison.yy" // lalr1.cc:847
    { TYPERR_CATCH(driver.error(yylhs.location, (yystack_[0].value.mv)), yylhs.location); }
#line 669 "MacroBison.cc" // lalr1.cc:847
    break;

  case 15:
#line 127 "MacroBison.yy" // lalr1.cc:847
    { (yylhs.value.mv) = new IntMV(driver, (yystack_[0].value.int_val)); }
#line 675 "MacroBison.cc" // lalr1.cc:847
    break;

  case 16:
#line 129 "MacroBison.yy" // lalr1.cc:847
    { (yylhs.value.mv) = new StringMV(driver, *(yystack_[0].value.string_val)); delete (yystack_[0].value.string_val); }
#line 681 "MacroBison.cc" // lalr1.cc:847
    break;

  case 17:
#line 131 "MacroBison.yy" // lalr1.cc:847
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
#line 697 "MacroBison.cc" // lalr1.cc:847
    break;

  case 18:
#line 143 "MacroBison.yy" // lalr1.cc:847
    { TYPERR_CATCH((yylhs.value.mv) = (yystack_[1].value.mv)->length(), yylhs.location); }
#line 703 "MacroBison.cc" // lalr1.cc:847
    break;

  case 19:
#line 145 "MacroBison.yy" // lalr1.cc:847
    { (yylhs.value.mv) = (yystack_[1].value.mv); }
#line 709 "MacroBison.cc" // lalr1.cc:847
    break;

  case 20:
#line 147 "MacroBison.yy" // lalr1.cc:847
    { TYPERR_CATCH((yylhs.value.mv) = *(yystack_[2].value.mv) + *(yystack_[0].value.mv), yylhs.location); }
#line 715 "MacroBison.cc" // lalr1.cc:847
    break;

  case 21:
#line 149 "MacroBison.yy" // lalr1.cc:847
    { TYPERR_CATCH((yylhs.value.mv) = *(yystack_[2].value.mv) - *(yystack_[0].value.mv), yylhs.location); }
#line 721 "MacroBison.cc" // lalr1.cc:847
    break;

  case 22:
#line 151 "MacroBison.yy" // lalr1.cc:847
    { TYPERR_CATCH((yylhs.value.mv) = *(yystack_[2].value.mv) * *(yystack_[0].value.mv), yylhs.location); }
#line 727 "MacroBison.cc" // lalr1.cc:847
    break;

  case 23:
#line 153 "MacroBison.yy" // lalr1.cc:847
    { TYPERR_CATCH((yylhs.value.mv) = *(yystack_[2].value.mv) / *(yystack_[0].value.mv), yylhs.location); }
#line 733 "MacroBison.cc" // lalr1.cc:847
    break;

  case 24:
#line 155 "MacroBison.yy" // lalr1.cc:847
    { TYPERR_CATCH((yylhs.value.mv) = *(yystack_[2].value.mv) < *(yystack_[0].value.mv), yylhs.location); }
#line 739 "MacroBison.cc" // lalr1.cc:847
    break;

  case 25:
#line 157 "MacroBison.yy" // lalr1.cc:847
    { TYPERR_CATCH((yylhs.value.mv) = *(yystack_[2].value.mv) > *(yystack_[0].value.mv), yylhs.location); }
#line 745 "MacroBison.cc" // lalr1.cc:847
    break;

  case 26:
#line 159 "MacroBison.yy" // lalr1.cc:847
    { TYPERR_CATCH((yylhs.value.mv) = *(yystack_[2].value.mv) <= *(yystack_[0].value.mv), yylhs.location); }
#line 751 "MacroBison.cc" // lalr1.cc:847
    break;

  case 27:
#line 161 "MacroBison.yy" // lalr1.cc:847
    { TYPERR_CATCH((yylhs.value.mv) = *(yystack_[2].value.mv) >= *(yystack_[0].value.mv), yylhs.location); }
#line 757 "MacroBison.cc" // lalr1.cc:847
    break;

  case 28:
#line 163 "MacroBison.yy" // lalr1.cc:847
    { TYPERR_CATCH((yylhs.value.mv) = *(yystack_[2].value.mv) == *(yystack_[0].value.mv), yylhs.location); }
#line 763 "MacroBison.cc" // lalr1.cc:847
    break;

  case 29:
#line 165 "MacroBison.yy" // lalr1.cc:847
    { TYPERR_CATCH((yylhs.value.mv) = *(yystack_[2].value.mv) != *(yystack_[0].value.mv), yylhs.location); }
#line 769 "MacroBison.cc" // lalr1.cc:847
    break;

  case 30:
#line 167 "MacroBison.yy" // lalr1.cc:847
    { TYPERR_CATCH((yylhs.value.mv) = *(yystack_[2].value.mv) || *(yystack_[0].value.mv), yylhs.location); }
#line 775 "MacroBison.cc" // lalr1.cc:847
    break;

  case 31:
#line 169 "MacroBison.yy" // lalr1.cc:847
    { TYPERR_CATCH((yylhs.value.mv) = *(yystack_[2].value.mv) && *(yystack_[0].value.mv), yylhs.location); }
#line 781 "MacroBison.cc" // lalr1.cc:847
    break;

  case 32:
#line 171 "MacroBison.yy" // lalr1.cc:847
    { TYPERR_CATCH((yylhs.value.mv) = -*(yystack_[0].value.mv), yylhs.location); }
#line 787 "MacroBison.cc" // lalr1.cc:847
    break;

  case 33:
#line 173 "MacroBison.yy" // lalr1.cc:847
    { TYPERR_CATCH((yylhs.value.mv) = +(*(yystack_[0].value.mv)), yylhs.location); }
#line 793 "MacroBison.cc" // lalr1.cc:847
    break;

  case 34:
#line 175 "MacroBison.yy" // lalr1.cc:847
    { TYPERR_CATCH((yylhs.value.mv) = !*(yystack_[0].value.mv), yylhs.location); }
#line 799 "MacroBison.cc" // lalr1.cc:847
    break;

  case 35:
#line 177 "MacroBison.yy" // lalr1.cc:847
    {
         TYPERR_CATCH((yylhs.value.mv) = (*(yystack_[3].value.mv))[*(yystack_[1].value.mv)], yylhs.location)
         catch(MacroValue::OutOfBoundsError)
           {
             error(yylhs.location, "Index out of bounds");
           }
       }
#line 811 "MacroBison.cc" // lalr1.cc:847
    break;

  case 36:
#line 185 "MacroBison.yy" // lalr1.cc:847
    { (yylhs.value.mv) = (yystack_[1].value.mv); }
#line 817 "MacroBison.cc" // lalr1.cc:847
    break;

  case 37:
#line 187 "MacroBison.yy" // lalr1.cc:847
    { TYPERR_CATCH((yylhs.value.mv) = IntMV::new_range(driver, (yystack_[2].value.mv), (yystack_[0].value.mv)), yylhs.location); }
#line 823 "MacroBison.cc" // lalr1.cc:847
    break;

  case 38:
#line 189 "MacroBison.yy" // lalr1.cc:847
    { TYPERR_CATCH((yylhs.value.mv) = (yystack_[2].value.mv)->in((yystack_[0].value.mv)), yylhs.location); }
#line 829 "MacroBison.cc" // lalr1.cc:847
    break;

  case 39:
#line 193 "MacroBison.yy" // lalr1.cc:847
    { (yylhs.value.mv) = (yystack_[0].value.mv)->toArray(); }
#line 835 "MacroBison.cc" // lalr1.cc:847
    break;

  case 40:
#line 195 "MacroBison.yy" // lalr1.cc:847
    { TYPERR_CATCH((yylhs.value.mv) = (yystack_[0].value.mv)->append((yystack_[2].value.mv)), yylhs.location); }
#line 841 "MacroBison.cc" // lalr1.cc:847
    break;


#line 845 "MacroBison.cc" // lalr1.cc:847
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


  const signed char parser::yypact_ninf_ = -21;

  const signed char parser::yytable_ninf_ = -1;

  const short int
  parser::yypact_[] =
  {
      58,   -20,    18,    36,   166,   166,   166,    45,    51,   166,
     166,    61,   -21,   -21,   -21,   166,   166,   166,    76,    58,
      63,    78,    59,    62,    79,    78,    78,    78,   -21,   -21,
      -5,    78,   -10,   166,    70,    70,    70,   -21,    68,   -21,
     166,   166,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,   166,   -21,   166,   -21,   -21,
     166,   -12,   -21,     2,    42,   110,   142,    84,    84,    84,
      84,    84,    84,   116,    -3,    -3,    70,    70,    78,    78,
      78,   -21,   -21
  };

  const unsigned char
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
     -21,   -21,   -21,    69,     0,    23
  };

  const signed char
  parser::yydefgoto_[] =
  {
      -1,    18,    19,    20,    31,    32
  };

  const signed char
  parser::yytable_[] =
  {
      21,    40,    22,    81,    25,    26,    27,    59,    -1,    30,
      58,    41,    60,    41,    60,    34,    35,    36,    41,    21,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    53,    54,    50,    51,    52,    53,    54,
      63,    23,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    61,    79,    24,    82,
      80,     1,     2,     3,    64,     4,    60,    28,     5,     6,
       7,     8,     9,    29,    10,    33,    37,    55,    11,    12,
      13,    14,    39,    56,    40,    57,    41,    62,    38,     0,
      40,     0,    15,    16,    41,     0,     0,     0,    17,     0,
      41,     0,     0,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    40,    50,    51,    52,
      53,    54,     0,     0,     0,     0,    41,     0,     0,     0,
       0,     0,    41,     0,     0,     0,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    40,    -1,
      51,    52,    53,    54,     0,     0,     0,     0,    41,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
       9,     0,    10,     0,     0,     0,    11,    12,    13,    14,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      15,    16,     0,     0,     0,     0,    17
  };

  const signed char
  parser::yycheck_[] =
  {
       0,     6,    22,    15,     4,     5,     6,    17,     6,     9,
      15,    16,    24,    16,    24,    15,    16,    17,    16,    19,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    36,    37,    33,    34,    35,    36,    37,
      40,    23,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    33,    57,    22,    17,
      60,     3,     4,     5,    41,     7,    24,    22,    10,    11,
      12,    13,    14,    22,    16,    14,     0,    18,    20,    21,
      22,    23,    19,    21,     6,     6,    16,    19,    19,    -1,
       6,    -1,    34,    35,    16,    -1,    -1,    -1,    40,    -1,
      16,    -1,    -1,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,     6,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    -1,    16,    -1,    -1,    -1,
      -1,    -1,    16,    -1,    -1,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,     6,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      14,    -1,    16,    -1,    -1,    -1,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    -1,    -1,    -1,    -1,    40
  };

  const unsigned char
  parser::yystos_[] =
  {
       0,     3,     4,     5,     7,    10,    11,    12,    13,    14,
      16,    20,    21,    22,    23,    34,    35,    40,    42,    43,
      44,    45,    22,    23,    22,    45,    45,    45,    22,    22,
      45,    45,    46,    14,    45,    45,    45,     0,    44,    19,
       6,    16,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    18,    21,     6,    15,    17,
      24,    46,    19,    45,    46,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    15,    17
  };

  const unsigned char
  parser::yyr1_[] =
  {
       0,    41,    42,    42,    43,    43,    44,    44,    44,    44,
      44,    44,    44,    44,    44,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    46,
      46
  };

  const unsigned char
  parser::yyr2_[] =
  {
       0,     2,     0,     1,     2,     3,     1,     4,     4,     2,
       2,     2,     2,     2,     3,     1,     1,     1,     4,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     2,     4,     3,     3,     3,     1,
       3
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "$end", "error", "$undefined", "DEFINE", "LINE", "FOR", "IN", "IF",
  "ELSE", "ENDIF", "ECHO_DIR", "ERROR", "IFDEF", "IFNDEF", "LPAREN",
  "RPAREN", "LBRACKET", "RBRACKET", "EQUAL", "EOL", "LENGTH", "INTEGER",
  "NAME", "STRING", "COMMA", "LOGICAL_OR", "LOGICAL_AND", "LESS",
  "GREATER", "LESS_EQUAL", "GREATER_EQUAL", "EQUAL_EQUAL",
  "EXCLAMATION_EQUAL", "COLON", "PLUS", "MINUS", "TIMES", "DIVIDE",
  "UMINUS", "UPLUS", "EXCLAMATION", "$accept", "statement_list_or_nothing",
  "statement_list", "statement", "expr", "array_expr", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,    98,    98,    99,   102,   103,   106,   108,   110,   112,
     114,   116,   118,   120,   122,   126,   128,   130,   142,   144,
     146,   148,   150,   152,   154,   156,   158,   160,   162,   164,
     166,   168,   170,   172,   174,   176,   184,   186,   188,   192,
     194
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
    const unsigned int user_token_number_max_ = 295;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // Macro
#line 1340 "MacroBison.cc" // lalr1.cc:1155
#line 198 "MacroBison.yy" // lalr1.cc:1156


void
Macro::parser::error(const Macro::parser::location_type &l,
                     const string &m)
{
  driver.error(l, m);
}