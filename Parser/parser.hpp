// A Bison parser, made by GNU Bison 3.7.4.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file parser.hpp
 ** Define the yy::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
// "%code requires" blocks.
#line 37 "Parser.y"

    /* código  que se inserta al inicio por lo regular son cabeceras*/
    #include <io.h>
    #include <iostream>
    #include <string>
    #include <QString>
    #include <QVector>

    // nodos No terminales
    #include "../AST/No_Terminales/nt_s.h"
    #include "../AST/No_Terminales/nt_lsentencias.h"
    #include "../AST/No_Terminales/nt_sentencia.h"
    #include "../AST/No_Terminales/nt_imprimir.h"
    #include "../AST/No_Terminales/nt_listaexpr.h"
    #include "../AST/No_Terminales/nt_bloque.h"
    #include "../AST/No_Terminales/nt_declvar.h"
    #include "../AST/No_Terminales/nt_asigvar.h"
    #include "../AST/No_Terminales/Expresiones/nt_suma.h"
    #include "../AST/No_Terminales/Expresiones/nt_multiplicacion.h"
    #include "../AST/No_Terminales/Expresiones/nt_resta.h"
    #include "../AST/No_Terminales/Expresiones/nt_division.h"
    #include "../AST/No_Terminales/Expresiones/nt_exponencial.h"
    #include "../AST/No_Terminales/Expresiones/nt_modulo.h"
    #include "../AST/No_Terminales/nt_declfunc.h"

    #include "../AST/No_Terminales/Expresiones/nt_negacion.h"
    #include "../AST/No_Terminales/Expresiones/nt_id.h"
    #include "../AST/No_Terminales/nt_tipo.h"
    #include "../AST/No_Terminales/nt_escape.h"
    #include "../AST/No_Terminales/nt_llamada.h"

    // nodos terminales
    #include "../AST/Terminales/t_numero.h"
    #include "../AST/Terminales/t_id.h"
    #include "../AST/Terminales/t_string.h"
     #include "../AST/Terminales/t_float.h"
     #include"../AST/Terminales/t_boolean.h"

    #include "../AST/No_Terminales/Expresiones/nt_mayor.h"


    #include "../AST/No_Terminales/Expresiones/nt_menor.h"


    #include "../AST/No_Terminales/Expresiones/nt_menorigual.h"


    #include "../AST/No_Terminales/Expresiones/nt_mayorigual.h"


    #include "../AST/No_Terminales/Expresiones/nt_igualigual.h"


    #include "../AST/No_Terminales/Expresiones/nt_diferente.h"


    #include "../AST/No_Terminales/Expresiones/nt_or.h"


    #include "../AST/No_Terminales/Expresiones/nt_and.h"


    #include "../AST/No_Terminales/Expresiones/nt_not.h"



    //Interfaz
    #include "interfaz.h"


    /*
    Se pueden definir estructuras y tipos para los no terminales
    */


#line 125 "parser.hpp"


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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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

namespace yy {
#line 254 "parser.hpp"




  /// A Bison parser.
  class Parser
  {
  public:
#ifndef YYSTYPE
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class semantic_type
  {
  public:
    /// Type of *this.
    typedef semantic_type self_type;

    /// Empty construction.
    semantic_type () YY_NOEXCEPT
      : yybuffer_ ()
    {}

    /// Construct and fill.
    template <typename T>
    semantic_type (YY_RVREF (T) t)
    {
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    semantic_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~semantic_type () YY_NOEXCEPT
    {}

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    semantic_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yybuffer_.yyraw;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yybuffer_.yyraw;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // sentencia
      // ciclo_for
      // ciclo_while
      // ins_if
      // escapa
      // llamada
      // aumento
      // decremento
      // lista_Expr
      // bloque
      // declaracion_void
      // declaracion_var
      // asignacion_var
      // x
      // cond
      // expr
      // tipo
      char dummy1[sizeof (AbstractExpr*)];

      // imprimir
      char dummy2[sizeof (NT_Imprimir*)];

      // s
      // lSentencia
      char dummy3[sizeof (QVector<AbstractExpr*>*)];

      // NUMERO
      // ID
      // STRING
      // INT
      // STR
      // FLOAT
      // FLO
      // BOOL
      // oprel
      char dummy4[sizeof (std::string)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me;
      /// A buffer large enough to store any of the semantic values.
      char yyraw[size];
    } yybuffer_;
  };

#else
    typedef YYSTYPE semantic_type;
#endif
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
    END = 0,                       // END
    YYerror = 256,                 // error
    YYUNDEF = 257,                 // "invalid token"
    NUMERO = 258,                  // NUMERO
    ID = 259,                      // ID
    STRING = 260,                  // STRING
    INT = 261,                     // INT
    STR = 262,                     // STR
    FLOAT = 263,                   // FLOAT
    FLO = 264,                     // FLO
    BOOL = 265,                    // BOOL
    SUMA = 266,                    // SUMA
    MENOS = 267,                   // MENOS
    DIM = 268,                     // DIM
    AS = 269,                      // AS
    IMPR = 270,                    // IMPR
    MOD = 271,                     // MOD
    VOID = 272,                    // VOID
    TRUE = 273,                    // TRUE
    FALSE = 274,                   // FALSE
    AND = 275,                     // AND
    NOT = 276,                     // NOT
    IF = 277,                      // IF
    THEN = 278,                    // THEN
    ELSE = 279,                    // ELSE
    WHILE = 280,                   // WHILE
    PRINT = 281,                   // PRINT
    PRINTF = 282,                  // PRINTF
    FOR = 283,                     // FOR
    MULTIPLICACION = 284,          // MULTIPLICACION
    DIVISION = 285,                // DIVISION
    EXPONENCIAL = 286,             // EXPONENCIAL
    MENOR_IGUAL = 287,             // MENOR_IGUAL
    MAYOR_IGUAL = 288,             // MAYOR_IGUAL
    IGUAL_IGUAL = 289,             // IGUAL_IGUAL
    DIFERENTE = 290,               // DIFERENTE
    MENOR = 291,                   // MENOR
    MAYOR = 292,                   // MAYOR
    OR = 293,                      // OR
    INTERROGACION = 294,           // INTERROGACION
    INCREMENT = 295,               // INCREMENT
    DECREMENT = 296,               // DECREMENT
    DOT = 297,                     // DOT
    LEFT_BRACKET = 298,            // LEFT_BRACKET
    RIGHT_BRACKET = 299,           // RIGHT_BRACKET
    VECTOR = 300,                  // VECTOR
    PUSH_FRONT = 301,              // PUSH_FRONT
    DOT_PUSH_BACK = 302,           // DOT_PUSH_BACK
    STRUCT = 303,                  // STRUCT
    REMOVE = 304,                  // REMOVE
    MEDIAN = 305,                  // MEDIAN
    IOTA = 306,                    // IOTA
    MEAN = 307,                    // MEAN
    SIZE = 308,                    // SIZE
    ATOI = 309,                    // ATOI
    GET = 310,                     // GET
    RETORNO = 311,                 // RETORNO
    BREAK = 312,                   // BREAK
    CONTINUE = 313,                // CONTINUE
    NEG = 314                      // NEG
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::yytokentype token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 70, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // END
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_NUMERO = 3,                            // NUMERO
        S_ID = 4,                                // ID
        S_STRING = 5,                            // STRING
        S_INT = 6,                               // INT
        S_STR = 7,                               // STR
        S_FLOAT = 8,                             // FLOAT
        S_FLO = 9,                               // FLO
        S_BOOL = 10,                             // BOOL
        S_SUMA = 11,                             // SUMA
        S_MENOS = 12,                            // MENOS
        S_DIM = 13,                              // DIM
        S_AS = 14,                               // AS
        S_IMPR = 15,                             // IMPR
        S_MOD = 16,                              // MOD
        S_VOID = 17,                             // VOID
        S_TRUE = 18,                             // TRUE
        S_FALSE = 19,                            // FALSE
        S_AND = 20,                              // AND
        S_NOT = 21,                              // NOT
        S_IF = 22,                               // IF
        S_THEN = 23,                             // THEN
        S_ELSE = 24,                             // ELSE
        S_WHILE = 25,                            // WHILE
        S_PRINT = 26,                            // PRINT
        S_PRINTF = 27,                           // PRINTF
        S_FOR = 28,                              // FOR
        S_MULTIPLICACION = 29,                   // MULTIPLICACION
        S_DIVISION = 30,                         // DIVISION
        S_EXPONENCIAL = 31,                      // EXPONENCIAL
        S_MENOR_IGUAL = 32,                      // MENOR_IGUAL
        S_MAYOR_IGUAL = 33,                      // MAYOR_IGUAL
        S_IGUAL_IGUAL = 34,                      // IGUAL_IGUAL
        S_DIFERENTE = 35,                        // DIFERENTE
        S_MENOR = 36,                            // MENOR
        S_MAYOR = 37,                            // MAYOR
        S_OR = 38,                               // OR
        S_INTERROGACION = 39,                    // INTERROGACION
        S_INCREMENT = 40,                        // INCREMENT
        S_DECREMENT = 41,                        // DECREMENT
        S_DOT = 42,                              // DOT
        S_LEFT_BRACKET = 43,                     // LEFT_BRACKET
        S_RIGHT_BRACKET = 44,                    // RIGHT_BRACKET
        S_VECTOR = 45,                           // VECTOR
        S_PUSH_FRONT = 46,                       // PUSH_FRONT
        S_DOT_PUSH_BACK = 47,                    // DOT_PUSH_BACK
        S_STRUCT = 48,                           // STRUCT
        S_REMOVE = 49,                           // REMOVE
        S_MEDIAN = 50,                           // MEDIAN
        S_IOTA = 51,                             // IOTA
        S_MEAN = 52,                             // MEAN
        S_SIZE = 53,                             // SIZE
        S_ATOI = 54,                             // ATOI
        S_GET = 55,                              // GET
        S_RETORNO = 56,                          // RETORNO
        S_BREAK = 57,                            // BREAK
        S_CONTINUE = 58,                         // CONTINUE
        S_59_ = 59,                              // ';'
        S_60_ = 60,                              // '('
        S_61_ = 61,                              // ')'
        S_62_ = 62,                              // '='
        S_63_ = 63,                              // '{'
        S_64_ = 64,                              // '}'
        S_65_ = 65,                              // '['
        S_66_ = 66,                              // ']'
        S_67_ = 67,                              // '.'
        S_NEG = 68,                              // NEG
        S_69_ = 69,                              // ','
        S_YYACCEPT = 70,                         // $accept
        S_s = 71,                                // s
        S_lSentencia = 72,                       // lSentencia
        S_sentencia = 73,                        // sentencia
        S_ciclo_for = 74,                        // ciclo_for
        S_ciclo_while = 75,                      // ciclo_while
        S_ins_if = 76,                           // ins_if
        S_escapa = 77,                           // escapa
        S_llamada = 78,                          // llamada
        S_aumento = 79,                          // aumento
        S_decremento = 80,                       // decremento
        S_imprimir = 81,                         // imprimir
        S_lista_Expr = 82,                       // lista_Expr
        S_bloque = 83,                           // bloque
        S_z = 84,                                // z
        S_declaracion_void = 85,                 // declaracion_void
        S_declaracion_var = 86,                  // declaracion_var
        S_asignacion_var = 87,                   // asignacion_var
        S_x = 88,                                // x
        S_cond = 89,                             // cond
        S_oprel = 90,                            // oprel
        S_expr = 91,                             // expr
        S_tipo = 92                              // tipo
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
      basic_symbol ()
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
        , location (std::move (that.location))
      {
        switch (this->kind ())
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
        value.move< AbstractExpr* > (std::move (that.value));
        break;

      case symbol_kind::S_imprimir: // imprimir
        value.move< NT_Imprimir* > (std::move (that.value));
        break;

      case symbol_kind::S_s: // s
      case symbol_kind::S_lSentencia: // lSentencia
        value.move< QVector<AbstractExpr*>* > (std::move (that.value));
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
        value.move< std::string > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, AbstractExpr*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const AbstractExpr*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, NT_Imprimir*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const NT_Imprimir*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, QVector<AbstractExpr*>*&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const QVector<AbstractExpr*>*& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }

      /// Destroy contents, and record that is empty.
      void clear ()
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
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
        value.template destroy< AbstractExpr* > ();
        break;

      case symbol_kind::S_imprimir: // imprimir
        value.template destroy< NT_Imprimir* > ();
        break;

      case symbol_kind::S_s: // s
      case symbol_kind::S_lSentencia: // lSentencia
        value.template destroy< QVector<AbstractExpr*>* > ();
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
        value.template destroy< std::string > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// The user-facing name of this symbol.
      std::string name () const YY_NOEXCEPT
      {
        return Parser::symbol_name (this->kind ());
      }

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      semantic_type value;

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
      /// Default constructor.
      by_kind ();

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that);
#endif

      /// Copy constructor.
      by_kind (const by_kind& that);

      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t);

      /// Record that this symbol is empty.
      void clear ();

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
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type(token_type (tok), std::move (l))
#else
      symbol_type (int tok, const location_type& l)
        : super_type(token_type (tok), l)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v, location_type l)
        : super_type(token_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type(token_type (tok), v, l)
#endif
      {}
    };

    /// Build a parser object.
    Parser (void *scanner_yyarg, yy::location& loc_yyarg, class Clase3::Interfaz & intr_yyarg);
    virtual ~Parser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    Parser (const Parser&) = delete;
    /// Non copyable.
    Parser& operator= (const Parser&) = delete;
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

    // Implementation of make_symbol for each symbol type.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END (location_type l)
      {
        return symbol_type (token::END, std::move (l));
      }
#else
      static
      symbol_type
      make_END (const location_type& l)
      {
        return symbol_type (token::END, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYerror (location_type l)
      {
        return symbol_type (token::YYerror, std::move (l));
      }
#else
      static
      symbol_type
      make_YYerror (const location_type& l)
      {
        return symbol_type (token::YYerror, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF (location_type l)
      {
        return symbol_type (token::YYUNDEF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYUNDEF (const location_type& l)
      {
        return symbol_type (token::YYUNDEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NUMERO (std::string v, location_type l)
      {
        return symbol_type (token::NUMERO, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NUMERO (const std::string& v, const location_type& l)
      {
        return symbol_type (token::NUMERO, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ID (std::string v, location_type l)
      {
        return symbol_type (token::ID, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ID (const std::string& v, const location_type& l)
      {
        return symbol_type (token::ID, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRING (std::string v, location_type l)
      {
        return symbol_type (token::STRING, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_STRING (const std::string& v, const location_type& l)
      {
        return symbol_type (token::STRING, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INT (std::string v, location_type l)
      {
        return symbol_type (token::INT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_INT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::INT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STR (std::string v, location_type l)
      {
        return symbol_type (token::STR, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_STR (const std::string& v, const location_type& l)
      {
        return symbol_type (token::STR, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FLOAT (std::string v, location_type l)
      {
        return symbol_type (token::FLOAT, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FLOAT (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FLOAT, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FLO (std::string v, location_type l)
      {
        return symbol_type (token::FLO, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_FLO (const std::string& v, const location_type& l)
      {
        return symbol_type (token::FLO, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BOOL (std::string v, location_type l)
      {
        return symbol_type (token::BOOL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_BOOL (const std::string& v, const location_type& l)
      {
        return symbol_type (token::BOOL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUMA (location_type l)
      {
        return symbol_type (token::SUMA, std::move (l));
      }
#else
      static
      symbol_type
      make_SUMA (const location_type& l)
      {
        return symbol_type (token::SUMA, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MENOS (location_type l)
      {
        return symbol_type (token::MENOS, std::move (l));
      }
#else
      static
      symbol_type
      make_MENOS (const location_type& l)
      {
        return symbol_type (token::MENOS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIM (location_type l)
      {
        return symbol_type (token::DIM, std::move (l));
      }
#else
      static
      symbol_type
      make_DIM (const location_type& l)
      {
        return symbol_type (token::DIM, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AS (location_type l)
      {
        return symbol_type (token::AS, std::move (l));
      }
#else
      static
      symbol_type
      make_AS (const location_type& l)
      {
        return symbol_type (token::AS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IMPR (location_type l)
      {
        return symbol_type (token::IMPR, std::move (l));
      }
#else
      static
      symbol_type
      make_IMPR (const location_type& l)
      {
        return symbol_type (token::IMPR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MOD (location_type l)
      {
        return symbol_type (token::MOD, std::move (l));
      }
#else
      static
      symbol_type
      make_MOD (const location_type& l)
      {
        return symbol_type (token::MOD, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VOID (location_type l)
      {
        return symbol_type (token::VOID, std::move (l));
      }
#else
      static
      symbol_type
      make_VOID (const location_type& l)
      {
        return symbol_type (token::VOID, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TRUE (location_type l)
      {
        return symbol_type (token::TRUE, std::move (l));
      }
#else
      static
      symbol_type
      make_TRUE (const location_type& l)
      {
        return symbol_type (token::TRUE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FALSE (location_type l)
      {
        return symbol_type (token::FALSE, std::move (l));
      }
#else
      static
      symbol_type
      make_FALSE (const location_type& l)
      {
        return symbol_type (token::FALSE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AND (location_type l)
      {
        return symbol_type (token::AND, std::move (l));
      }
#else
      static
      symbol_type
      make_AND (const location_type& l)
      {
        return symbol_type (token::AND, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NOT (location_type l)
      {
        return symbol_type (token::NOT, std::move (l));
      }
#else
      static
      symbol_type
      make_NOT (const location_type& l)
      {
        return symbol_type (token::NOT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IF (location_type l)
      {
        return symbol_type (token::IF, std::move (l));
      }
#else
      static
      symbol_type
      make_IF (const location_type& l)
      {
        return symbol_type (token::IF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_THEN (location_type l)
      {
        return symbol_type (token::THEN, std::move (l));
      }
#else
      static
      symbol_type
      make_THEN (const location_type& l)
      {
        return symbol_type (token::THEN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ELSE (location_type l)
      {
        return symbol_type (token::ELSE, std::move (l));
      }
#else
      static
      symbol_type
      make_ELSE (const location_type& l)
      {
        return symbol_type (token::ELSE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WHILE (location_type l)
      {
        return symbol_type (token::WHILE, std::move (l));
      }
#else
      static
      symbol_type
      make_WHILE (const location_type& l)
      {
        return symbol_type (token::WHILE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PRINT (location_type l)
      {
        return symbol_type (token::PRINT, std::move (l));
      }
#else
      static
      symbol_type
      make_PRINT (const location_type& l)
      {
        return symbol_type (token::PRINT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PRINTF (location_type l)
      {
        return symbol_type (token::PRINTF, std::move (l));
      }
#else
      static
      symbol_type
      make_PRINTF (const location_type& l)
      {
        return symbol_type (token::PRINTF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FOR (location_type l)
      {
        return symbol_type (token::FOR, std::move (l));
      }
#else
      static
      symbol_type
      make_FOR (const location_type& l)
      {
        return symbol_type (token::FOR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MULTIPLICACION (location_type l)
      {
        return symbol_type (token::MULTIPLICACION, std::move (l));
      }
#else
      static
      symbol_type
      make_MULTIPLICACION (const location_type& l)
      {
        return symbol_type (token::MULTIPLICACION, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIVISION (location_type l)
      {
        return symbol_type (token::DIVISION, std::move (l));
      }
#else
      static
      symbol_type
      make_DIVISION (const location_type& l)
      {
        return symbol_type (token::DIVISION, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXPONENCIAL (location_type l)
      {
        return symbol_type (token::EXPONENCIAL, std::move (l));
      }
#else
      static
      symbol_type
      make_EXPONENCIAL (const location_type& l)
      {
        return symbol_type (token::EXPONENCIAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MENOR_IGUAL (location_type l)
      {
        return symbol_type (token::MENOR_IGUAL, std::move (l));
      }
#else
      static
      symbol_type
      make_MENOR_IGUAL (const location_type& l)
      {
        return symbol_type (token::MENOR_IGUAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAYOR_IGUAL (location_type l)
      {
        return symbol_type (token::MAYOR_IGUAL, std::move (l));
      }
#else
      static
      symbol_type
      make_MAYOR_IGUAL (const location_type& l)
      {
        return symbol_type (token::MAYOR_IGUAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IGUAL_IGUAL (location_type l)
      {
        return symbol_type (token::IGUAL_IGUAL, std::move (l));
      }
#else
      static
      symbol_type
      make_IGUAL_IGUAL (const location_type& l)
      {
        return symbol_type (token::IGUAL_IGUAL, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIFERENTE (location_type l)
      {
        return symbol_type (token::DIFERENTE, std::move (l));
      }
#else
      static
      symbol_type
      make_DIFERENTE (const location_type& l)
      {
        return symbol_type (token::DIFERENTE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MENOR (location_type l)
      {
        return symbol_type (token::MENOR, std::move (l));
      }
#else
      static
      symbol_type
      make_MENOR (const location_type& l)
      {
        return symbol_type (token::MENOR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAYOR (location_type l)
      {
        return symbol_type (token::MAYOR, std::move (l));
      }
#else
      static
      symbol_type
      make_MAYOR (const location_type& l)
      {
        return symbol_type (token::MAYOR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OR (location_type l)
      {
        return symbol_type (token::OR, std::move (l));
      }
#else
      static
      symbol_type
      make_OR (const location_type& l)
      {
        return symbol_type (token::OR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INTERROGACION (location_type l)
      {
        return symbol_type (token::INTERROGACION, std::move (l));
      }
#else
      static
      symbol_type
      make_INTERROGACION (const location_type& l)
      {
        return symbol_type (token::INTERROGACION, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INCREMENT (location_type l)
      {
        return symbol_type (token::INCREMENT, std::move (l));
      }
#else
      static
      symbol_type
      make_INCREMENT (const location_type& l)
      {
        return symbol_type (token::INCREMENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DECREMENT (location_type l)
      {
        return symbol_type (token::DECREMENT, std::move (l));
      }
#else
      static
      symbol_type
      make_DECREMENT (const location_type& l)
      {
        return symbol_type (token::DECREMENT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOT (location_type l)
      {
        return symbol_type (token::DOT, std::move (l));
      }
#else
      static
      symbol_type
      make_DOT (const location_type& l)
      {
        return symbol_type (token::DOT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LEFT_BRACKET (location_type l)
      {
        return symbol_type (token::LEFT_BRACKET, std::move (l));
      }
#else
      static
      symbol_type
      make_LEFT_BRACKET (const location_type& l)
      {
        return symbol_type (token::LEFT_BRACKET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RIGHT_BRACKET (location_type l)
      {
        return symbol_type (token::RIGHT_BRACKET, std::move (l));
      }
#else
      static
      symbol_type
      make_RIGHT_BRACKET (const location_type& l)
      {
        return symbol_type (token::RIGHT_BRACKET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VECTOR (location_type l)
      {
        return symbol_type (token::VECTOR, std::move (l));
      }
#else
      static
      symbol_type
      make_VECTOR (const location_type& l)
      {
        return symbol_type (token::VECTOR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PUSH_FRONT (location_type l)
      {
        return symbol_type (token::PUSH_FRONT, std::move (l));
      }
#else
      static
      symbol_type
      make_PUSH_FRONT (const location_type& l)
      {
        return symbol_type (token::PUSH_FRONT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOT_PUSH_BACK (location_type l)
      {
        return symbol_type (token::DOT_PUSH_BACK, std::move (l));
      }
#else
      static
      symbol_type
      make_DOT_PUSH_BACK (const location_type& l)
      {
        return symbol_type (token::DOT_PUSH_BACK, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_STRUCT (location_type l)
      {
        return symbol_type (token::STRUCT, std::move (l));
      }
#else
      static
      symbol_type
      make_STRUCT (const location_type& l)
      {
        return symbol_type (token::STRUCT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REMOVE (location_type l)
      {
        return symbol_type (token::REMOVE, std::move (l));
      }
#else
      static
      symbol_type
      make_REMOVE (const location_type& l)
      {
        return symbol_type (token::REMOVE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MEDIAN (location_type l)
      {
        return symbol_type (token::MEDIAN, std::move (l));
      }
#else
      static
      symbol_type
      make_MEDIAN (const location_type& l)
      {
        return symbol_type (token::MEDIAN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IOTA (location_type l)
      {
        return symbol_type (token::IOTA, std::move (l));
      }
#else
      static
      symbol_type
      make_IOTA (const location_type& l)
      {
        return symbol_type (token::IOTA, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MEAN (location_type l)
      {
        return symbol_type (token::MEAN, std::move (l));
      }
#else
      static
      symbol_type
      make_MEAN (const location_type& l)
      {
        return symbol_type (token::MEAN, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SIZE (location_type l)
      {
        return symbol_type (token::SIZE, std::move (l));
      }
#else
      static
      symbol_type
      make_SIZE (const location_type& l)
      {
        return symbol_type (token::SIZE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ATOI (location_type l)
      {
        return symbol_type (token::ATOI, std::move (l));
      }
#else
      static
      symbol_type
      make_ATOI (const location_type& l)
      {
        return symbol_type (token::ATOI, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_GET (location_type l)
      {
        return symbol_type (token::GET, std::move (l));
      }
#else
      static
      symbol_type
      make_GET (const location_type& l)
      {
        return symbol_type (token::GET, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RETORNO (location_type l)
      {
        return symbol_type (token::RETORNO, std::move (l));
      }
#else
      static
      symbol_type
      make_RETORNO (const location_type& l)
      {
        return symbol_type (token::RETORNO, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BREAK (location_type l)
      {
        return symbol_type (token::BREAK, std::move (l));
      }
#else
      static
      symbol_type
      make_BREAK (const location_type& l)
      {
        return symbol_type (token::BREAK, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CONTINUE (location_type l)
      {
        return symbol_type (token::CONTINUE, std::move (l));
      }
#else
      static
      symbol_type
      make_CONTINUE (const location_type& l)
      {
        return symbol_type (token::CONTINUE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NEG (location_type l)
      {
        return symbol_type (token::NEG, std::move (l));
      }
#else
      static
      symbol_type
      make_NEG (const location_type& l)
      {
        return symbol_type (token::NEG, l);
      }
#endif


    class context
    {
    public:
      context (const Parser& yyparser, const symbol_type& yyla);
      const symbol_type& lookahead () const { return yyla_; }
      symbol_kind_type token () const { return yyla_.kind (); }
      const location_type& location () const { return yyla_.location; }

      /// Put in YYARG at most YYARGN of the expected tokens, and return the
      /// number of tokens stored in YYARG.  If YYARG is null, return the
      /// number of expected tokens (guaranteed to be less than YYNTOKENS).
      int expected_tokens (symbol_kind_type yyarg[], int yyargn) const;

    private:
      const Parser& yyparser_;
      const symbol_type& yyla_;
    };

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    Parser (const Parser&);
    /// Non copyable.
    Parser& operator= (const Parser&);
#endif


    /// Stored state numbers (used for stacks).
    typedef unsigned char state_type;

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
    static bool yy_pact_value_is_default_ (int yyvalue);

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue);

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_type enum.
    static symbol_kind_type yytranslate_ (int t);

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
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const short yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const signed char yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const unsigned char yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    // symbol of state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[YYN] -- Symbol number of symbol that rule YYN derives.
    static const signed char yyr1_[];

    // YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.
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

      stack (size_type n = 200)
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
        slice (const stack& stack, index_type range)
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
    void yypop_ (int n = 1);

    /// Constants.
    enum
    {
      yylast_ = 333,     ///< Last index in yytable_.
      yynnts_ = 23,  ///< Number of nonterminal symbols.
      yyfinal_ = 44 ///< Termination state number.
    };


    // User arguments.
    void *scanner;
    yy::location& loc;
    class Clase3::Interfaz & intr;

  };

  inline
  Parser::symbol_kind_type
  Parser::yytranslate_ (int t)
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
      60,    61,     2,     2,    69,     2,    67,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    59,
       2,    62,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    65,     2,    66,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    63,     2,    64,     2,     2,     2,     2,
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
      55,    56,    57,    58,    68
    };
    // Last valid token kind.
    const int code_max = 314;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return YY_CAST (symbol_kind_type, translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

  // basic_symbol.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
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
        value.copy< AbstractExpr* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_imprimir: // imprimir
        value.copy< NT_Imprimir* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_s: // s
      case symbol_kind::S_lSentencia: // lSentencia
        value.copy< QVector<AbstractExpr*>* > (YY_MOVE (that.value));
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
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  Parser::symbol_kind_type
  Parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
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
        value.move< AbstractExpr* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_imprimir: // imprimir
        value.move< NT_Imprimir* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_s: // s
      case symbol_kind::S_lSentencia: // lSentencia
        value.move< QVector<AbstractExpr*>* > (YY_MOVE (s.value));
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
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  inline
  Parser::by_kind::by_kind ()
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  Parser::by_kind::by_kind (by_kind&& that)
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  inline
  Parser::by_kind::by_kind (const by_kind& that)
    : kind_ (that.kind_)
  {}

  inline
  Parser::by_kind::by_kind (token_kind_type t)
    : kind_ (yytranslate_ (t))
  {}

  inline
  void
  Parser::by_kind::clear ()
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  inline
  void
  Parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  inline
  Parser::symbol_kind_type
  Parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }

  inline
  Parser::symbol_kind_type
  Parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }

} // yy
#line 2545 "parser.hpp"




#endif // !YY_YY_PARSER_HPP_INCLUDED
