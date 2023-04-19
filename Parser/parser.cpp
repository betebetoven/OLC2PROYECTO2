// A Bison parser, made by GNU Bison 3.7.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

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

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.hpp"


// Unqualified %code blocks.
#line 114 "Parser.y"

yy::Parser::symbol_type yylex(void* yyscanner, yy::location& loc, class Clase3::Interfaz & intr);

#line 50 "parser.cpp"


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
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 142 "parser.cpp"

  /// Build a parser object.
  Parser::Parser (void *scanner_yyarg, yy::location& loc_yyarg, class Clase3::Interfaz & intr_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      loc (loc_yyarg),
      intr (intr_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------------.
  | symbol kinds.  |
  `---------------*/



  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_kind_type
  Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_sentencia: // sentencia
      case symbol_kind::S_ciclo_for: // ciclo_for
      case symbol_kind::S_ciclo_while: // ciclo_while
      case symbol_kind::S_ins_if: // ins_if
      case symbol_kind::S_escapa: // escapa
      case symbol_kind::S_llamada: // llamada
      case symbol_kind::S_aumento: // aumento
      case symbol_kind::S_decremento: // decremento
      case symbol_kind::S_lista_Expr: // lista_Expr
      case symbol_kind::S_bloque: // bloque
      case symbol_kind::S_declaracion_void: // declaracion_void
      case symbol_kind::S_declaracion_var: // declaracion_var
      case symbol_kind::S_asignacion_var: // asignacion_var
      case symbol_kind::S_x: // x
      case symbol_kind::S_cond: // cond
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_tipo: // tipo
        value.YY_MOVE_OR_COPY< AbstractExpr* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_imprimir: // imprimir
        value.YY_MOVE_OR_COPY< NT_Imprimir* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_s: // s
      case symbol_kind::S_lSentencia: // lSentencia
        value.YY_MOVE_OR_COPY< QVector<AbstractExpr*>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_STR: // STR
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_FLO: // FLO
      case symbol_kind::S_BOOL: // BOOL
      case symbol_kind::S_oprel: // oprel
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_sentencia: // sentencia
      case symbol_kind::S_ciclo_for: // ciclo_for
      case symbol_kind::S_ciclo_while: // ciclo_while
      case symbol_kind::S_ins_if: // ins_if
      case symbol_kind::S_escapa: // escapa
      case symbol_kind::S_llamada: // llamada
      case symbol_kind::S_aumento: // aumento
      case symbol_kind::S_decremento: // decremento
      case symbol_kind::S_lista_Expr: // lista_Expr
      case symbol_kind::S_bloque: // bloque
      case symbol_kind::S_declaracion_void: // declaracion_void
      case symbol_kind::S_declaracion_var: // declaracion_var
      case symbol_kind::S_asignacion_var: // asignacion_var
      case symbol_kind::S_x: // x
      case symbol_kind::S_cond: // cond
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_tipo: // tipo
        value.move< AbstractExpr* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_imprimir: // imprimir
        value.move< NT_Imprimir* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_s: // s
      case symbol_kind::S_lSentencia: // lSentencia
        value.move< QVector<AbstractExpr*>* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_STR: // STR
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_FLO: // FLO
      case symbol_kind::S_BOOL: // BOOL
      case symbol_kind::S_oprel: // oprel
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_sentencia: // sentencia
      case symbol_kind::S_ciclo_for: // ciclo_for
      case symbol_kind::S_ciclo_while: // ciclo_while
      case symbol_kind::S_ins_if: // ins_if
      case symbol_kind::S_escapa: // escapa
      case symbol_kind::S_llamada: // llamada
      case symbol_kind::S_aumento: // aumento
      case symbol_kind::S_decremento: // decremento
      case symbol_kind::S_lista_Expr: // lista_Expr
      case symbol_kind::S_bloque: // bloque
      case symbol_kind::S_declaracion_void: // declaracion_void
      case symbol_kind::S_declaracion_var: // declaracion_var
      case symbol_kind::S_asignacion_var: // asignacion_var
      case symbol_kind::S_x: // x
      case symbol_kind::S_cond: // cond
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_tipo: // tipo
        value.copy< AbstractExpr* > (that.value);
        break;

      case symbol_kind::S_imprimir: // imprimir
        value.copy< NT_Imprimir* > (that.value);
        break;

      case symbol_kind::S_s: // s
      case symbol_kind::S_lSentencia: // lSentencia
        value.copy< QVector<AbstractExpr*>* > (that.value);
        break;

      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_STR: // STR
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_FLO: // FLO
      case symbol_kind::S_BOOL: // BOOL
      case symbol_kind::S_oprel: // oprel
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_sentencia: // sentencia
      case symbol_kind::S_ciclo_for: // ciclo_for
      case symbol_kind::S_ciclo_while: // ciclo_while
      case symbol_kind::S_ins_if: // ins_if
      case symbol_kind::S_escapa: // escapa
      case symbol_kind::S_llamada: // llamada
      case symbol_kind::S_aumento: // aumento
      case symbol_kind::S_decremento: // decremento
      case symbol_kind::S_lista_Expr: // lista_Expr
      case symbol_kind::S_bloque: // bloque
      case symbol_kind::S_declaracion_void: // declaracion_void
      case symbol_kind::S_declaracion_var: // declaracion_var
      case symbol_kind::S_asignacion_var: // asignacion_var
      case symbol_kind::S_x: // x
      case symbol_kind::S_cond: // cond
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_tipo: // tipo
        value.move< AbstractExpr* > (that.value);
        break;

      case symbol_kind::S_imprimir: // imprimir
        value.move< NT_Imprimir* > (that.value);
        break;

      case symbol_kind::S_s: // s
      case symbol_kind::S_lSentencia: // lSentencia
        value.move< QVector<AbstractExpr*>* > (that.value);
        break;

      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_STR: // STR
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_FLO: // FLO
      case symbol_kind::S_BOOL: // BOOL
      case symbol_kind::S_oprel: // oprel
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        switch (yykind)
    {
      case symbol_kind::S_NUMERO: // NUMERO
#line 174 "Parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 459 "parser.cpp"
        break;

      case symbol_kind::S_ID: // ID
#line 174 "Parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 465 "parser.cpp"
        break;

      case symbol_kind::S_STRING: // STRING
#line 174 "Parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 471 "parser.cpp"
        break;

      case symbol_kind::S_INT: // INT
#line 174 "Parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 477 "parser.cpp"
        break;

      case symbol_kind::S_STR: // STR
#line 174 "Parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 483 "parser.cpp"
        break;

      case symbol_kind::S_FLOAT: // FLOAT
#line 174 "Parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 489 "parser.cpp"
        break;

      case symbol_kind::S_FLO: // FLO
#line 174 "Parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 495 "parser.cpp"
        break;

      case symbol_kind::S_BOOL: // BOOL
#line 174 "Parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 501 "parser.cpp"
        break;

      case symbol_kind::S_s: // s
#line 174 "Parser.y"
                 { yyoutput << yysym.value.template as < QVector<AbstractExpr*>* > (); }
#line 507 "parser.cpp"
        break;

      case symbol_kind::S_lSentencia: // lSentencia
#line 174 "Parser.y"
                 { yyoutput << yysym.value.template as < QVector<AbstractExpr*>* > (); }
#line 513 "parser.cpp"
        break;

      case symbol_kind::S_sentencia: // sentencia
#line 174 "Parser.y"
                 { yyoutput << yysym.value.template as < AbstractExpr* > (); }
#line 519 "parser.cpp"
        break;

      case symbol_kind::S_ciclo_for: // ciclo_for
#line 174 "Parser.y"
                 { yyoutput << yysym.value.template as < AbstractExpr* > (); }
#line 525 "parser.cpp"
        break;

      case symbol_kind::S_ciclo_while: // ciclo_while
#line 174 "Parser.y"
                 { yyoutput << yysym.value.template as < AbstractExpr* > (); }
#line 531 "parser.cpp"
        break;

      case symbol_kind::S_ins_if: // ins_if
#line 174 "Parser.y"
                 { yyoutput << yysym.value.template as < AbstractExpr* > (); }
#line 537 "parser.cpp"
        break;

      case symbol_kind::S_escapa: // escapa
#line 174 "Parser.y"
                 { yyoutput << yysym.value.template as < AbstractExpr* > (); }
#line 543 "parser.cpp"
        break;

      case symbol_kind::S_llamada: // llamada
#line 174 "Parser.y"
                 { yyoutput << yysym.value.template as < AbstractExpr* > (); }
#line 549 "parser.cpp"
        break;

      case symbol_kind::S_aumento: // aumento
#line 174 "Parser.y"
                 { yyoutput << yysym.value.template as < AbstractExpr* > (); }
#line 555 "parser.cpp"
        break;

      case symbol_kind::S_decremento: // decremento
#line 174 "Parser.y"
                 { yyoutput << yysym.value.template as < AbstractExpr* > (); }
#line 561 "parser.cpp"
        break;

      case symbol_kind::S_imprimir: // imprimir
#line 174 "Parser.y"
                 { yyoutput << yysym.value.template as < NT_Imprimir* > (); }
#line 567 "parser.cpp"
        break;

      case symbol_kind::S_lista_Expr: // lista_Expr
#line 174 "Parser.y"
                 { yyoutput << yysym.value.template as < AbstractExpr* > (); }
#line 573 "parser.cpp"
        break;

      case symbol_kind::S_bloque: // bloque
#line 174 "Parser.y"
                 { yyoutput << yysym.value.template as < AbstractExpr* > (); }
#line 579 "parser.cpp"
        break;

      case symbol_kind::S_declaracion_void: // declaracion_void
#line 174 "Parser.y"
                 { yyoutput << yysym.value.template as < AbstractExpr* > (); }
#line 585 "parser.cpp"
        break;

      case symbol_kind::S_declaracion_var: // declaracion_var
#line 174 "Parser.y"
                 { yyoutput << yysym.value.template as < AbstractExpr* > (); }
#line 591 "parser.cpp"
        break;

      case symbol_kind::S_asignacion_var: // asignacion_var
#line 174 "Parser.y"
                 { yyoutput << yysym.value.template as < AbstractExpr* > (); }
#line 597 "parser.cpp"
        break;

      case symbol_kind::S_x: // x
#line 174 "Parser.y"
                 { yyoutput << yysym.value.template as < AbstractExpr* > (); }
#line 603 "parser.cpp"
        break;

      case symbol_kind::S_cond: // cond
#line 174 "Parser.y"
                 { yyoutput << yysym.value.template as < AbstractExpr* > (); }
#line 609 "parser.cpp"
        break;

      case symbol_kind::S_oprel: // oprel
#line 174 "Parser.y"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 615 "parser.cpp"
        break;

      case symbol_kind::S_expr: // expr
#line 174 "Parser.y"
                 { yyoutput << yysym.value.template as < AbstractExpr* > (); }
#line 621 "parser.cpp"
        break;

      case symbol_kind::S_tipo: // tipo
#line 174 "Parser.y"
                 { yyoutput << yysym.value.template as < AbstractExpr* > (); }
#line 627 "parser.cpp"
        break;

      default:
        break;
    }
        yyo << ')';
      }
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
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
            symbol_type yylookahead (yylex (scanner, loc, intr));
            yyla.move (yylookahead);
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
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_sentencia: // sentencia
      case symbol_kind::S_ciclo_for: // ciclo_for
      case symbol_kind::S_ciclo_while: // ciclo_while
      case symbol_kind::S_ins_if: // ins_if
      case symbol_kind::S_escapa: // escapa
      case symbol_kind::S_llamada: // llamada
      case symbol_kind::S_aumento: // aumento
      case symbol_kind::S_decremento: // decremento
      case symbol_kind::S_lista_Expr: // lista_Expr
      case symbol_kind::S_bloque: // bloque
      case symbol_kind::S_declaracion_void: // declaracion_void
      case symbol_kind::S_declaracion_var: // declaracion_var
      case symbol_kind::S_asignacion_var: // asignacion_var
      case symbol_kind::S_x: // x
      case symbol_kind::S_cond: // cond
      case symbol_kind::S_expr: // expr
      case symbol_kind::S_tipo: // tipo
        yylhs.value.emplace< AbstractExpr* > ();
        break;

      case symbol_kind::S_imprimir: // imprimir
        yylhs.value.emplace< NT_Imprimir* > ();
        break;

      case symbol_kind::S_s: // s
      case symbol_kind::S_lSentencia: // lSentencia
        yylhs.value.emplace< QVector<AbstractExpr*>* > ();
        break;

      case symbol_kind::S_NUMERO: // NUMERO
      case symbol_kind::S_ID: // ID
      case symbol_kind::S_STRING: // STRING
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_STR: // STR
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_FLO: // FLO
      case symbol_kind::S_BOOL: // BOOL
      case symbol_kind::S_oprel: // oprel
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }


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
  case 2: // s: lSentencia
#line 183 "Parser.y"
               {std::cout << "LLEGO A S PARA SALIR" << std::endl;
        intr.raiz = *yystack_[0].value.as < QVector<AbstractExpr*>* > ();
                yylhs.value.as < QVector<AbstractExpr*>* > () = yystack_[0].value.as < QVector<AbstractExpr*>* > ();
                if (!yystack_[0].value.as < QVector<AbstractExpr*>* > ()->isEmpty()) {
        AbstractExpr* firstElement = (*yystack_[0].value.as < QVector<AbstractExpr*>* > ())[0]; 
        std::cout << "Class name of the first object in QVector: " << typeid(*firstElement).name() << std::endl;
    } else {
        std::cout << "QVector is empty" << std::endl;
    }
    if (!intr.raiz.isEmpty()) {
        AbstractExpr* firstElement = intr.raiz[0];
        std::cout << "Class name of the first object in intr.raiz: " << typeid(*firstElement).name() << std::endl;
    } else {
        std::cout << "intr.raiz is empty" << std::endl;
    }
    }
#line 936 "parser.cpp"
    break;

  case 3: // lSentencia: lSentencia sentencia z
#line 202 "Parser.y"
                                   {
                           yylhs.value.as < QVector<AbstractExpr*>* > () = yystack_[2].value.as < QVector<AbstractExpr*>* > ();
                            yylhs.value.as < QVector<AbstractExpr*>* > ()->append(yystack_[1].value.as < AbstractExpr* > ());
                        }
#line 945 "parser.cpp"
    break;

  case 4: // lSentencia: sentencia z
#line 206 "Parser.y"
                  {
        QVector<AbstractExpr*>* vec = new QVector<AbstractExpr*>();
        vec->append(yystack_[1].value.as < AbstractExpr* > ());
        yylhs.value.as < QVector<AbstractExpr*>* > () = vec;
    }
#line 955 "parser.cpp"
    break;

  case 5: // sentencia: declaracion_var
#line 214 "Parser.y"
                           {yylhs.value.as < AbstractExpr* > () = yystack_[0].value.as < AbstractExpr* > ();}
#line 961 "parser.cpp"
    break;

  case 6: // sentencia: asignacion_var
#line 215 "Parser.y"
                         {yylhs.value.as < AbstractExpr* > () = yystack_[0].value.as < AbstractExpr* > (); }
#line 967 "parser.cpp"
    break;

  case 7: // sentencia: imprimir
#line 216 "Parser.y"
               {yylhs.value.as < AbstractExpr* > () = yystack_[0].value.as < NT_Imprimir* > (); }
#line 973 "parser.cpp"
    break;

  case 8: // sentencia: bloque
#line 217 "Parser.y"
             {yylhs.value.as < AbstractExpr* > () = yystack_[0].value.as < AbstractExpr* > ();}
#line 979 "parser.cpp"
    break;

  case 9: // sentencia: aumento
#line 218 "Parser.y"
             {yylhs.value.as < AbstractExpr* > () = yystack_[0].value.as < AbstractExpr* > ();}
#line 985 "parser.cpp"
    break;

  case 10: // sentencia: decremento
#line 219 "Parser.y"
                {yylhs.value.as < AbstractExpr* > () = yystack_[0].value.as < AbstractExpr* > ();}
#line 991 "parser.cpp"
    break;

  case 11: // sentencia: ciclo_for
#line 220 "Parser.y"
               {yylhs.value.as < AbstractExpr* > ()=yystack_[0].value.as < AbstractExpr* > ();}
#line 997 "parser.cpp"
    break;

  case 12: // sentencia: ciclo_while
#line 221 "Parser.y"
                {yylhs.value.as < AbstractExpr* > ()=yystack_[0].value.as < AbstractExpr* > ();}
#line 1003 "parser.cpp"
    break;

  case 13: // sentencia: ins_if
#line 222 "Parser.y"
            {yylhs.value.as < AbstractExpr* > ()=yystack_[0].value.as < AbstractExpr* > ();}
#line 1009 "parser.cpp"
    break;

  case 14: // sentencia: escapa
#line 223 "Parser.y"
            {yylhs.value.as < AbstractExpr* > ()=yystack_[0].value.as < AbstractExpr* > ();}
#line 1015 "parser.cpp"
    break;

  case 15: // sentencia: declaracion_void
#line 224 "Parser.y"
                      {yylhs.value.as < AbstractExpr* > ()=yystack_[0].value.as < AbstractExpr* > ();}
#line 1021 "parser.cpp"
    break;

  case 16: // sentencia: llamada
#line 225 "Parser.y"
             {yylhs.value.as < AbstractExpr* > ()=yystack_[0].value.as < AbstractExpr* > ();}
#line 1027 "parser.cpp"
    break;

  case 17: // ciclo_for: FOR '(' declaracion_var z x z aumento ')' '{' lSentencia '}'
#line 228 "Parser.y"
                                                                       {yylhs.value.as < AbstractExpr* > () = new Bloque(*yystack_[1].value.as < QVector<AbstractExpr*>* > (),yystack_[8].value.as < AbstractExpr* > (),yystack_[6].value.as < AbstractExpr* > (),yystack_[4].value.as < AbstractExpr* > (),true,nullptr);}
#line 1033 "parser.cpp"
    break;

  case 18: // ciclo_while: WHILE '(' x ')' '{' lSentencia '}'
#line 231 "Parser.y"
                                                {yylhs.value.as < AbstractExpr* > () = new Bloque(*yystack_[1].value.as < QVector<AbstractExpr*>* > (),nullptr,yystack_[4].value.as < AbstractExpr* > (),nullptr,true,nullptr);}
#line 1039 "parser.cpp"
    break;

  case 19: // ins_if: IF '(' x ')' '{' lSentencia '}'
#line 235 "Parser.y"
                                        {yylhs.value.as < AbstractExpr* > () = new Bloque(*yystack_[1].value.as < QVector<AbstractExpr*>* > (),nullptr,yystack_[4].value.as < AbstractExpr* > (),nullptr,false,nullptr);}
#line 1045 "parser.cpp"
    break;

  case 20: // ins_if: IF '(' x ')' '{' lSentencia '}' ELSE '{' lSentencia '}'
#line 236 "Parser.y"
                                                              {Bloque* elsa = new Bloque(*yystack_[1].value.as < QVector<AbstractExpr*>* > (),nullptr,nullptr,nullptr,false, nullptr);
                                                                yylhs.value.as < AbstractExpr* > () = new Bloque(*yystack_[5].value.as < QVector<AbstractExpr*>* > (),nullptr,yystack_[8].value.as < AbstractExpr* > (),nullptr,false,elsa);}
#line 1052 "parser.cpp"
    break;

  case 21: // ins_if: IF '(' x ')' '{' lSentencia '}' ELSE ins_if
#line 238 "Parser.y"
                                                    {yylhs.value.as < AbstractExpr* > () = new Bloque(*yystack_[3].value.as < QVector<AbstractExpr*>* > (),nullptr,yystack_[6].value.as < AbstractExpr* > (),nullptr,false,yystack_[0].value.as < AbstractExpr* > ());}
#line 1058 "parser.cpp"
    break;

  case 22: // escapa: BREAK
#line 241 "Parser.y"
              { yylhs.value.as < AbstractExpr* > () = new NT_Escape(QString::fromStdString("break"));}
#line 1064 "parser.cpp"
    break;

  case 23: // escapa: CONTINUE
#line 242 "Parser.y"
               { yylhs.value.as < AbstractExpr* > () = new NT_Escape(QString::fromStdString("continue"));}
#line 1070 "parser.cpp"
    break;

  case 24: // escapa: RETORNO
#line 243 "Parser.y"
              { yylhs.value.as < AbstractExpr* > () = new NT_Escape(QString::fromStdString("return"));}
#line 1076 "parser.cpp"
    break;

  case 25: // llamada: ID '(' ')'
#line 249 "Parser.y"
                   { NT_ID* id_av = new NT_ID(QString::fromStdString(yystack_[2].value.as < std::string > ()));
        yylhs.value.as < AbstractExpr* > () = new NT_Llamada(id_av);}
#line 1083 "parser.cpp"
    break;

  case 26: // aumento: INCREMENT ID
#line 256 "Parser.y"
                       {            NT_ID* id_avar2 = new NT_ID(QString::fromStdString(yystack_[0].value.as < std::string > ()));
                                T_ID* id_avar = new T_ID(QString::fromStdString(yystack_[0].value.as < std::string > ()));
                                yylhs.value.as < AbstractExpr* > () = new NT_AsigVar(id_avar2,new NT_Suma(id_avar, new T_Numero( QString::fromStdString("1"))),true ); }
#line 1091 "parser.cpp"
    break;

  case 27: // aumento: ID INCREMENT
#line 259 "Parser.y"
                   {            NT_ID* id_avar2 = new NT_ID(QString::fromStdString(yystack_[1].value.as < std::string > ()));
                                T_ID* id_avar = new T_ID(QString::fromStdString(yystack_[1].value.as < std::string > ()));
                                yylhs.value.as < AbstractExpr* > () = new NT_AsigVar(id_avar2,new NT_Suma(id_avar, new T_Numero( QString::fromStdString("1"))),false ); }
#line 1099 "parser.cpp"
    break;

  case 28: // decremento: DECREMENT ID
#line 263 "Parser.y"
                         {            NT_ID* id_avar2 = new NT_ID(QString::fromStdString(yystack_[0].value.as < std::string > ()));
                                T_ID* id_avar = new T_ID(QString::fromStdString(yystack_[0].value.as < std::string > ()));
                                yylhs.value.as < AbstractExpr* > () = new NT_AsigVar(id_avar2,new NT_Resta(id_avar, new T_Numero( QString::fromStdString("1"))),true ); }
#line 1107 "parser.cpp"
    break;

  case 29: // decremento: ID DECREMENT
#line 266 "Parser.y"
                   {            NT_ID* id_avar2 = new NT_ID(QString::fromStdString(yystack_[1].value.as < std::string > ()));
                                T_ID* id_avar = new T_ID(QString::fromStdString(yystack_[1].value.as < std::string > ()));
                                yylhs.value.as < AbstractExpr* > () = new NT_AsigVar(id_avar2,new NT_Resta(id_avar, new T_Numero( QString::fromStdString("1"))),false ); }
#line 1115 "parser.cpp"
    break;

  case 30: // imprimir: IMPR '(' lista_Expr ')'
#line 270 "Parser.y"
                                  { yylhs.value.as < NT_Imprimir* > () = new NT_Imprimir(yystack_[1].value.as < AbstractExpr* > ()); }
#line 1121 "parser.cpp"
    break;

  case 31: // lista_Expr: lista_Expr ',' x
#line 274 "Parser.y"
                              {   yylhs.value.as < AbstractExpr* > () = new NT_Suma(yystack_[2].value.as < AbstractExpr* > (), yystack_[0].value.as < AbstractExpr* > ());
                                }
#line 1128 "parser.cpp"
    break;

  case 32: // lista_Expr: x
#line 276 "Parser.y"
        { yylhs.value.as < AbstractExpr* > () = yystack_[0].value.as < AbstractExpr* > ();}
#line 1134 "parser.cpp"
    break;

  case 33: // bloque: '{' lSentencia '}'
#line 281 "Parser.y"
                           { yylhs.value.as < AbstractExpr* > () = new Bloque(*yystack_[1].value.as < QVector<AbstractExpr*>* > (),nullptr,nullptr,nullptr,false, nullptr); }
#line 1140 "parser.cpp"
    break;

  case 34: // z: ';'
#line 283 "Parser.y"
       {  }
#line 1146 "parser.cpp"
    break;

  case 35: // z: %empty
#line 284 "Parser.y"
             { }
#line 1152 "parser.cpp"
    break;

  case 36: // declaracion_void: tipo ID '(' ')' bloque
#line 287 "Parser.y"
                                        { 
                                NT_ID* id = new NT_ID(QString::fromStdString(yystack_[3].value.as < std::string > ()));
                                yylhs.value.as < AbstractExpr* > () = new NT_DeclFunc(yystack_[4].value.as < AbstractExpr* > (), id, yystack_[0].value.as < AbstractExpr* > ());
                                }
#line 1161 "parser.cpp"
    break;

  case 37: // declaracion_var: tipo ID
#line 297 "Parser.y"
                          {   NT_ID* id = new NT_ID(QString::fromStdString(yystack_[0].value.as < std::string > ()));
                                    yylhs.value.as < AbstractExpr* > () = new NT_DeclVar(yystack_[1].value.as < AbstractExpr* > (), id); }
#line 1168 "parser.cpp"
    break;

  case 38: // declaracion_var: tipo ID '=' x
#line 299 "Parser.y"
                     {    
                                NT_ID* id = new NT_ID(QString::fromStdString(yystack_[2].value.as < std::string > ()));
                                yylhs.value.as < AbstractExpr* > () = new NT_DeclVar(yystack_[3].value.as < AbstractExpr* > (), id,yystack_[0].value.as < AbstractExpr* > () );  }
#line 1176 "parser.cpp"
    break;

  case 39: // asignacion_var: ID '=' x
#line 304 "Parser.y"
                         {   NT_ID* id_avar = new NT_ID(QString::fromStdString(yystack_[2].value.as < std::string > ()));
                                yylhs.value.as < AbstractExpr* > () = new NT_AsigVar(id_avar, yystack_[0].value.as < AbstractExpr* > (),true);
                                }
#line 1184 "parser.cpp"
    break;

  case 40: // x: cond
#line 310 "Parser.y"
         {yylhs.value.as < AbstractExpr* > () = yystack_[0].value.as < AbstractExpr* > ();}
#line 1190 "parser.cpp"
    break;

  case 41: // cond: cond OR cond
#line 313 "Parser.y"
                   {yylhs.value.as < AbstractExpr* > () = new NT_Or(yystack_[2].value.as < AbstractExpr* > (), yystack_[0].value.as < AbstractExpr* > ());}
#line 1196 "parser.cpp"
    break;

  case 42: // cond: cond AND cond
#line 314 "Parser.y"
                    {yylhs.value.as < AbstractExpr* > () = new NT_And(yystack_[2].value.as < AbstractExpr* > (), yystack_[0].value.as < AbstractExpr* > ());}
#line 1202 "parser.cpp"
    break;

  case 43: // cond: NOT cond
#line 315 "Parser.y"
               { yylhs.value.as < AbstractExpr* > () = new NT_Not(yystack_[0].value.as < AbstractExpr* > ());}
#line 1208 "parser.cpp"
    break;

  case 44: // cond: '(' cond ')'
#line 316 "Parser.y"
                 {yylhs.value.as < AbstractExpr* > () = yystack_[1].value.as < AbstractExpr* > ();}
#line 1214 "parser.cpp"
    break;

  case 45: // cond: expr oprel expr
#line 317 "Parser.y"
                     {if (yystack_[1].value.as < std::string > () == "mayor") {
        yylhs.value.as < AbstractExpr* > () = new NT_Mayor(yystack_[2].value.as < AbstractExpr* > (), yystack_[0].value.as < AbstractExpr* > ());
    } else if (yystack_[1].value.as < std::string > () == "menor") {
        yylhs.value.as < AbstractExpr* > () = new NT_Menor(yystack_[2].value.as < AbstractExpr* > (), yystack_[0].value.as < AbstractExpr* > ());
    } else if (yystack_[1].value.as < std::string > () == "igual") {
        yylhs.value.as < AbstractExpr* > () = new NT_IgualIgual(yystack_[2].value.as < AbstractExpr* > (), yystack_[0].value.as < AbstractExpr* > ());
    } else if (yystack_[1].value.as < std::string > () == "menorigual") {
        yylhs.value.as < AbstractExpr* > () = new NT_MenorIgual(yystack_[2].value.as < AbstractExpr* > (), yystack_[0].value.as < AbstractExpr* > ());
    } else if (yystack_[1].value.as < std::string > () == "mayorigual") {
        yylhs.value.as < AbstractExpr* > () = new NT_MayorIgual(yystack_[2].value.as < AbstractExpr* > (), yystack_[0].value.as < AbstractExpr* > ());
    } else if (yystack_[1].value.as < std::string > () == "diferente") {
        yylhs.value.as < AbstractExpr* > () = new NT_Diferente(yystack_[2].value.as < AbstractExpr* > (), yystack_[0].value.as < AbstractExpr* > ());
    } else {
        yylhs.value.as < AbstractExpr* > () = new NT_Diferente(yystack_[2].value.as < AbstractExpr* > (), yystack_[0].value.as < AbstractExpr* > ());
    }}
#line 1234 "parser.cpp"
    break;

  case 46: // cond: expr
#line 332 "Parser.y"
         {yylhs.value.as < AbstractExpr* > () = yystack_[0].value.as < AbstractExpr* > ();}
#line 1240 "parser.cpp"
    break;

  case 47: // oprel: MAYOR
#line 334 "Parser.y"
            {yylhs.value.as < std::string > () = "mayor";}
#line 1246 "parser.cpp"
    break;

  case 48: // oprel: MENOR
#line 335 "Parser.y"
           {yylhs.value.as < std::string > () = "menor";}
#line 1252 "parser.cpp"
    break;

  case 49: // oprel: IGUAL_IGUAL
#line 336 "Parser.y"
                 {yylhs.value.as < std::string > () = "igual";}
#line 1258 "parser.cpp"
    break;

  case 50: // oprel: MENOR_IGUAL
#line 337 "Parser.y"
                 {yylhs.value.as < std::string > () = "menorigual";}
#line 1264 "parser.cpp"
    break;

  case 51: // oprel: MAYOR_IGUAL
#line 338 "Parser.y"
                 {yylhs.value.as < std::string > () = "mayorigual";}
#line 1270 "parser.cpp"
    break;

  case 52: // oprel: DIFERENTE
#line 339 "Parser.y"
               {yylhs.value.as < std::string > () = "diferente";}
#line 1276 "parser.cpp"
    break;

  case 53: // expr: expr SUMA expr
#line 341 "Parser.y"
                       { yylhs.value.as < AbstractExpr* > () = new NT_Suma(yystack_[2].value.as < AbstractExpr* > (), yystack_[0].value.as < AbstractExpr* > ());  }
#line 1282 "parser.cpp"
    break;

  case 54: // expr: expr MENOS expr
#line 342 "Parser.y"
                      { yylhs.value.as < AbstractExpr* > () = new NT_Resta(yystack_[2].value.as < AbstractExpr* > (), yystack_[0].value.as < AbstractExpr* > ()); }
#line 1288 "parser.cpp"
    break;

  case 55: // expr: expr MULTIPLICACION expr
#line 343 "Parser.y"
                               { yylhs.value.as < AbstractExpr* > () = new NT_Multiplicacion(yystack_[2].value.as < AbstractExpr* > (), yystack_[0].value.as < AbstractExpr* > ()); }
#line 1294 "parser.cpp"
    break;

  case 56: // expr: expr DIVISION expr
#line 344 "Parser.y"
                         { yylhs.value.as < AbstractExpr* > () = new NT_Division(yystack_[2].value.as < AbstractExpr* > (), yystack_[0].value.as < AbstractExpr* > ()); }
#line 1300 "parser.cpp"
    break;

  case 57: // expr: expr MOD expr
#line 345 "Parser.y"
                    { yylhs.value.as < AbstractExpr* > () = new NT_Modulo(yystack_[2].value.as < AbstractExpr* > (), yystack_[0].value.as < AbstractExpr* > ()); }
#line 1306 "parser.cpp"
    break;

  case 58: // expr: expr EXPONENCIAL expr
#line 346 "Parser.y"
                            { yylhs.value.as < AbstractExpr* > () = new NT_Exponencial(yystack_[2].value.as < AbstractExpr* > (), yystack_[0].value.as < AbstractExpr* > ()); }
#line 1312 "parser.cpp"
    break;

  case 59: // expr: '(' expr ')'
#line 347 "Parser.y"
                   { yylhs.value.as < AbstractExpr* > () = yystack_[1].value.as < AbstractExpr* > (); }
#line 1318 "parser.cpp"
    break;

  case 60: // expr: INCREMENT ID
#line 348 "Parser.y"
                   {            NT_ID* id_avar2 = new NT_ID(QString::fromStdString(yystack_[0].value.as < std::string > ()));
                                T_ID* id_avar = new T_ID(QString::fromStdString(yystack_[0].value.as < std::string > ()));
                                yylhs.value.as < AbstractExpr* > () = new NT_AsigVar(id_avar2,new NT_Suma(id_avar, new T_Numero( QString::fromStdString("1"))),true ); }
#line 1326 "parser.cpp"
    break;

  case 61: // expr: ID INCREMENT
#line 351 "Parser.y"
                   {            NT_ID* id_avar2 = new NT_ID(QString::fromStdString(yystack_[1].value.as < std::string > ()));
                                T_ID* id_avar = new T_ID(QString::fromStdString(yystack_[1].value.as < std::string > ()));
                                yylhs.value.as < AbstractExpr* > () = new NT_AsigVar(id_avar2,new NT_Suma(id_avar, new T_Numero( QString::fromStdString("1"))),false ); }
#line 1334 "parser.cpp"
    break;

  case 62: // expr: DECREMENT ID
#line 354 "Parser.y"
                   {            NT_ID* id_avar2 = new NT_ID(QString::fromStdString(yystack_[0].value.as < std::string > ()));
                                T_ID* id_avar = new T_ID(QString::fromStdString(yystack_[0].value.as < std::string > ()));
                                yylhs.value.as < AbstractExpr* > () = new NT_AsigVar(id_avar2,new NT_Resta(id_avar, new T_Numero( QString::fromStdString("1"))),true ); }
#line 1342 "parser.cpp"
    break;

  case 63: // expr: ID DECREMENT
#line 357 "Parser.y"
                   {            NT_ID* id_avar2 = new NT_ID(QString::fromStdString(yystack_[1].value.as < std::string > ()));
                                T_ID* id_avar = new T_ID(QString::fromStdString(yystack_[1].value.as < std::string > ()));
                                yylhs.value.as < AbstractExpr* > () = new NT_AsigVar(id_avar2,new NT_Resta(id_avar, new T_Numero( QString::fromStdString("1"))),false ); }
#line 1350 "parser.cpp"
    break;

  case 64: // expr: MENOS expr
#line 360 "Parser.y"
                            { yylhs.value.as < AbstractExpr* > () = new NT_Negacion(yystack_[0].value.as < AbstractExpr* > ());  }
#line 1356 "parser.cpp"
    break;

  case 65: // expr: NUMERO
#line 361 "Parser.y"
             { yylhs.value.as < AbstractExpr* > () = new T_Numero( QString::fromStdString(yystack_[0].value.as < std::string > ())); }
#line 1362 "parser.cpp"
    break;

  case 66: // expr: ID
#line 362 "Parser.y"
         { yylhs.value.as < AbstractExpr* > () = new T_ID( QString::fromStdString(yystack_[0].value.as < std::string > ())); }
#line 1368 "parser.cpp"
    break;

  case 67: // expr: STRING
#line 363 "Parser.y"
             { yylhs.value.as < AbstractExpr* > () = new T_String( QString::fromStdString(yystack_[0].value.as < std::string > ()));  }
#line 1374 "parser.cpp"
    break;

  case 68: // expr: FLOAT
#line 364 "Parser.y"
            { yylhs.value.as < AbstractExpr* > () = new T_Float( QString::fromStdString(yystack_[0].value.as < std::string > ()));  }
#line 1380 "parser.cpp"
    break;

  case 69: // expr: TRUE
#line 365 "Parser.y"
           { yylhs.value.as < AbstractExpr* > () = new T_Boolean( QString::fromStdString("true"));  }
#line 1386 "parser.cpp"
    break;

  case 70: // expr: FALSE
#line 366 "Parser.y"
            { yylhs.value.as < AbstractExpr* > () = new T_Boolean( QString::fromStdString("false"));  }
#line 1392 "parser.cpp"
    break;

  case 71: // tipo: INT
#line 369 "Parser.y"
           { yylhs.value.as < AbstractExpr* > () = new NT_Tipo( QString::fromStdString("Integer")); }
#line 1398 "parser.cpp"
    break;

  case 72: // tipo: STR
#line 370 "Parser.y"
          { yylhs.value.as < AbstractExpr* > () = new NT_Tipo( QString::fromStdString("String")); }
#line 1404 "parser.cpp"
    break;

  case 73: // tipo: FLO
#line 371 "Parser.y"
          { yylhs.value.as < AbstractExpr* > () = new NT_Tipo( QString::fromStdString("Float")); }
#line 1410 "parser.cpp"
    break;

  case 74: // tipo: BOOL
#line 372 "Parser.y"
           { yylhs.value.as < AbstractExpr* > () = new NT_Tipo( QString::fromStdString("Boolean")); }
#line 1416 "parser.cpp"
    break;

  case 75: // tipo: VOID
#line 373 "Parser.y"
           { yylhs.value.as < AbstractExpr* > () = new NT_Tipo( QString::fromStdString("Void")); }
#line 1422 "parser.cpp"
    break;


#line 1426 "parser.cpp"

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
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
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
  Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // Parser::context.
  Parser::context::context (const Parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  Parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        int yychecklim = yylast_ - yyn + 1;
        int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
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
  Parser::yy_syntax_error_arguments_ (const context& yyctx,
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
  Parser::yysyntax_error_ (const context& yyctx) const
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


  const signed char Parser::yypact_ninf_ = -53;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
  {
     205,   -24,   -53,   -53,   -53,   -53,   -52,   -53,   -41,   -37,
      -6,    44,    51,   -53,   -53,   -53,   205,    56,   205,    -2,
     -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   -53,
     -53,   -53,    54,   -53,   -53,    -1,   213,   213,   213,   213,
      86,   -53,   -53,     5,   -53,    -2,   -53,   -53,   -23,   -53,
     -53,    11,   -53,   -53,   239,   -53,   -53,   213,    55,    60,
     213,   -53,   -10,   296,   -43,   -53,    10,    13,    -2,    68,
     -53,   -53,    19,   213,   -53,   -53,   239,    67,   -10,   -53,
     -53,   -17,   253,   213,   213,   239,   239,   239,   239,   239,
     239,   -53,   -53,   -53,   -53,   -53,   -53,   239,   -53,   213,
      22,    36,   213,    38,    39,   -53,   112,   -53,   -53,   -53,
      81,   133,   133,    67,    67,    67,    67,   100,   -53,   205,
     205,    -2,   -53,    25,    69,     9,    80,   -53,    75,    58,
     -20,    72,   205,   -53,   205,   130,   144,   -53,   -53
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,     0,    71,    72,    73,    74,     0,    75,     0,     0,
       0,     0,     0,    24,    22,    23,     0,     0,     2,    35,
      11,    12,    13,    14,    16,     9,    10,     7,     8,    15,
       5,     6,     0,    27,    29,     0,     0,     0,     0,     0,
       0,    26,    28,     0,     1,    35,    34,     4,    37,    25,
      65,    66,    67,    68,     0,    69,    70,     0,     0,     0,
       0,    39,    40,    46,     0,    32,     0,     0,    35,     0,
      33,     3,     0,     0,    61,    63,     0,    64,    43,    60,
      62,     0,    46,     0,     0,     0,     0,     0,     0,     0,
       0,    50,    51,    49,    52,    48,    47,     0,    30,     0,
       0,     0,     0,    37,     0,    38,     0,    44,    59,    42,
      41,    53,    54,    57,    55,    56,    58,    45,    31,     0,
       0,    35,    36,     0,     0,     0,    19,    18,     0,     0,
       0,     0,     0,    21,     0,     0,     0,    20,    17
  };

  const short
  Parser::yypgoto_[] =
  {
     -53,   -53,   -12,   -18,   -53,   -53,    -9,   -53,   -53,    21,
     -53,   -53,   -53,    34,   -44,   -53,   104,   -53,   -32,    30,
     -53,   216,   116
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    64,    28,    47,    29,    30,    31,    61,    62,
      97,    63,    32
  };

  const unsigned char
  Parser::yytable_[] =
  {
      45,    71,     8,    83,    43,    65,    66,    67,    37,     1,
      83,     2,     3,   128,     4,     5,    33,    34,    98,    38,
       6,    84,     7,    39,   102,    45,    99,     8,    84,     1,
       9,     2,     3,    10,     4,     5,    35,    72,    36,    73,
       6,   105,     7,   132,   107,    11,    12,     8,    41,    11,
       9,    74,    75,    10,    40,    42,    44,    46,    48,    79,
      49,    13,    14,    15,    80,    11,    12,   118,    16,    70,
     121,   100,   103,     1,   101,     2,     3,   125,     4,     5,
     104,    13,    14,    15,     6,   119,     7,    78,    16,   126,
      81,     8,     2,     3,     9,     4,     5,    10,    90,   120,
      73,    83,    16,     7,   130,    45,    45,   123,   124,    11,
      12,    85,    86,   109,   110,    33,    87,    45,    45,   131,
     135,   133,   136,    85,    86,    13,    14,    15,    87,    88,
      89,    90,    16,   127,     1,   134,     2,     3,   122,     4,
       5,    88,    89,    90,    68,     6,   129,     7,     1,    87,
       2,     3,     8,     4,     5,     9,    69,     0,    10,     6,
       0,     7,    88,    89,    90,     0,     8,     0,     0,     9,
      11,    12,    10,   108,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    11,    12,    13,    14,    15,     0,
       0,     0,     0,    16,   137,     0,     0,     0,     0,     0,
      13,    14,    15,     0,     0,     0,     0,    16,   138,     1,
       0,     2,     3,     0,     4,     5,    50,    51,    52,     0,
       6,    53,     7,     0,     0,    54,     0,     8,     0,     0,
       9,    55,    56,    10,    57,     0,     0,     0,     0,     0,
       0,     0,    50,    51,    52,    11,    12,    53,     0,     0,
       0,    54,     0,    58,    59,     0,     0,    55,    56,     0,
       0,    13,    14,    15,    85,    86,     0,     0,    16,    87,
      77,     0,     0,    60,     0,     0,    82,     0,     0,    58,
      59,     0,    88,    89,    90,    91,    92,    93,    94,    95,
      96,     0,   106,     0,     0,     0,     0,     0,     0,    76,
       0,   111,   112,   113,   114,   115,   116,    85,    86,     0,
       0,     0,    87,   117,   108,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    88,    89,    90,    91,    92,
      93,    94,    95,    96
  };

  const short
  Parser::yycheck_[] =
  {
      18,    45,    22,    20,    16,    37,    38,    39,    60,     4,
      20,     6,     7,     4,     9,    10,    40,    41,    61,    60,
      15,    38,    17,    60,    68,    43,    69,    22,    38,     4,
      25,     6,     7,    28,     9,    10,    60,    60,    62,    62,
      15,    73,    17,    63,    61,    40,    41,    22,     4,    40,
      25,    40,    41,    28,    60,     4,     0,    59,     4,     4,
      61,    56,    57,    58,     4,    40,    41,    99,    63,    64,
     102,    61,     4,     4,    61,     6,     7,   121,     9,    10,
      61,    56,    57,    58,    15,    63,    17,    57,    63,    64,
      60,    22,     6,     7,    25,     9,    10,    28,    31,    63,
      62,    20,    63,    17,    24,   123,   124,   119,   120,    40,
      41,    11,    12,    83,    84,    40,    16,   135,   136,    61,
     132,   130,   134,    11,    12,    56,    57,    58,    16,    29,
      30,    31,    63,    64,     4,    63,     6,     7,   104,     9,
      10,    29,    30,    31,    40,    15,   125,    17,     4,    16,
       6,     7,    22,     9,    10,    25,    40,    -1,    28,    15,
      -1,    17,    29,    30,    31,    -1,    22,    -1,    -1,    25,
      40,    41,    28,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    41,    56,    57,    58,    -1,
      -1,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,
      56,    57,    58,    -1,    -1,    -1,    -1,    63,    64,     4,
      -1,     6,     7,    -1,     9,    10,     3,     4,     5,    -1,
      15,     8,    17,    -1,    -1,    12,    -1,    22,    -1,    -1,
      25,    18,    19,    28,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,    40,    41,     8,    -1,    -1,
      -1,    12,    -1,    40,    41,    -1,    -1,    18,    19,    -1,
      -1,    56,    57,    58,    11,    12,    -1,    -1,    63,    16,
      54,    -1,    -1,    60,    -1,    -1,    60,    -1,    -1,    40,
      41,    -1,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      -1,    85,    86,    87,    88,    89,    90,    11,    12,    -1,
      -1,    -1,    16,    97,    61,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,
      34,    35,    36,    37
  };

  const signed char
  Parser::yystos_[] =
  {
       0,     4,     6,     7,     9,    10,    15,    17,    22,    25,
      28,    40,    41,    56,    57,    58,    63,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    83,    85,
      86,    87,    92,    40,    41,    60,    62,    60,    60,    60,
      60,     4,     4,    72,     0,    73,    59,    84,     4,    61,
       3,     4,     5,     8,    12,    18,    19,    21,    40,    41,
      60,    88,    89,    91,    82,    88,    88,    88,    86,    92,
      64,    84,    60,    62,    40,    41,    60,    91,    89,     4,
       4,    89,    91,    20,    38,    11,    12,    16,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    90,    61,    69,
      61,    61,    84,     4,    61,    88,    91,    61,    61,    89,
      89,    91,    91,    91,    91,    91,    91,    91,    88,    63,
      63,    88,    83,    72,    72,    84,    64,    64,     4,    79,
      24,    61,    63,    76,    63,    72,    72,    64,    64
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    70,    71,    72,    72,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    74,    75,    76,
      76,    76,    77,    77,    77,    78,    79,    79,    80,    80,
      81,    82,    82,    83,    84,    84,    85,    86,    86,    87,
      88,    89,    89,    89,    89,    89,    89,    90,    90,    90,
      90,    90,    90,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    92,    92,    92,    92,    92
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,    11,     7,     7,
      11,     9,     1,     1,     1,     3,     2,     2,     2,     2,
       4,     3,     1,     3,     1,     0,     5,     2,     4,     3,
       1,     3,     3,     2,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     2,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "END", "error", "\"invalid token\"", "NUMERO", "ID", "STRING", "INT",
  "STR", "FLOAT", "FLO", "BOOL", "SUMA", "MENOS", "DIM", "AS", "IMPR",
  "MOD", "VOID", "TRUE", "FALSE", "AND", "NOT", "IF", "THEN", "ELSE",
  "WHILE", "PRINT", "PRINTF", "FOR", "MULTIPLICACION", "DIVISION",
  "EXPONENCIAL", "MENOR_IGUAL", "MAYOR_IGUAL", "IGUAL_IGUAL", "DIFERENTE",
  "MENOR", "MAYOR", "OR", "INTERROGACION", "INCREMENT", "DECREMENT", "DOT",
  "LEFT_BRACKET", "RIGHT_BRACKET", "VECTOR", "PUSH_FRONT", "DOT_PUSH_BACK",
  "STRUCT", "REMOVE", "MEDIAN", "IOTA", "MEAN", "SIZE", "ATOI", "GET",
  "RETORNO", "BREAK", "CONTINUE", "';'", "'('", "')'", "'='", "'{'", "'}'",
  "'['", "']'", "'.'", "NEG", "','", "$accept", "s", "lSentencia",
  "sentencia", "ciclo_for", "ciclo_while", "ins_if", "escapa", "llamada",
  "aumento", "decremento", "imprimir", "lista_Expr", "bloque", "z",
  "declaracion_void", "declaracion_var", "asignacion_var", "x", "cond",
  "oprel", "expr", "tipo", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   183,   183,   202,   206,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   228,   231,   235,
     236,   238,   241,   242,   243,   249,   256,   259,   263,   266,
     270,   274,   276,   281,   283,   284,   287,   297,   299,   304,
     310,   313,   314,   315,   316,   317,   332,   334,   335,   336,
     337,   338,   339,   341,   342,   343,   344,   345,   346,   347,
     348,   351,   354,   357,   360,   361,   362,   363,   364,   365,
     366,   369,   370,   371,   372,   373
  };

  void
  Parser::yy_stack_print_ () const
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
  Parser::yy_reduce_print_ (int yyrule) const
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


} // yy
#line 2024 "parser.cpp"

#line 376 "Parser.y"

void yy::Parser::error(const yy::location& l, const std::string& m)
{
    std::cerr << l << ": " << m << std::endl;
}

