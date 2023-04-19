/* se convierte con: flex --verbose Lexer.l*/
/* opcciones para encapsulamiento */

/*%option reentrant noyywrap nounput batch noinput*/
%option reentrant noyywrap nounput batch noinput
%option debug
%option case-insensitive

/*%option outfile="lex.yy.cpp"*/
/*%option outfile="lexer.cpp" */
/*%option header-file="lexer.hpp"*/
%{

    // definicion del tipo de funcion del retorno de simbolos
    // yy::Parser ¿Por qué?
    // yy es el namespace de parser
    // Parser es el nombre de la clase que lo envuelve (wapper)
    #define YY_DECL yy::Parser::symbol_type yylex(yyscan_t yyscanner, yy::location& loc, class Clase3::Interfaz & intr)
    // definición de acciones
    #define YY_USER_ACTION loc.columns(yyleng);
    // defincion de caracter EOF
    #define yyterminate() return Parser::make_END(loc)
    //se incrusta el parser
    #include "parser.hpp"
    #include <io.h>
    #include <iostream>


    using namespace yy;
    //typedefs (abreviaturas DefLarga DefCorta) para definiciones de tokens
    typedef yy::Parser::token token;
    typedef yy::Parser::token_type token_type;
/// código adicinoal aquí


%}

/* ============== INICIO DE SCANNER ==========  */


/* expresiones regulares */

DIGITO [0-9]
LETRAS [a-zA-ZñÑ]
NUMERO {DIGITO}+
FLOAT {NUMERO}"."{NUMERO}
ID  {LETRAS}({DIGITO}|{LETRAS}|"_")*
%%

%{
    #include <stdio.h>
    loc.step();


%}

"/*"[^"\*"]*"*/"   ;
"//"[^\n]*\n            ;

[ \t\v\r\n\f]+             ;

"++"     return Parser::symbol_type( token::INCREMENT, loc );
"--"     return Parser::symbol_type( token::DECREMENT, loc );
"return"     return Parser::symbol_type( token::RETORNO, loc );
"break"     return Parser::symbol_type( token::BREAK, loc );
"continue"     return Parser::symbol_type( token::CONTINUE, loc );
"+"     return Parser::symbol_type( token::SUMA, loc );
"%"     return Parser::symbol_type( token::MOD, loc );
"-"     return Parser::symbol_type( token::MENOS, loc );
"*" return Parser::symbol_type(token::MULTIPLICACION, loc);
"/" return Parser::symbol_type(token::DIVISION, loc);
"^" return Parser::symbol_type(token::EXPONENCIAL, loc);
"Dim"   return Parser::symbol_type( token::DIM, loc);
"as"    return Parser::symbol_type( token::AS, loc);
"Printf"  return Parser::symbol_type( token::IMPR, loc);
"void"    return Parser::symbol_type( token::VOID, loc);
"Int"    return Parser::symbol_type( token::INT, loc);
"String"   return Parser::symbol_type( token::STR , loc);
"Float"   return Parser::symbol_type( token::FLO , loc);
"Bool" return Parser::symbol_type( token::BOOL , loc);
"true" return Parser::symbol_type(token::TRUE, loc);
"false" return Parser::symbol_type(token::FALSE, loc);
"and" return Parser::symbol_type(token::AND, loc);
"not" return Parser::symbol_type(token::NOT, loc);
"if" return Parser::symbol_type(token::IF, loc);
"then" return Parser::symbol_type(token::THEN, loc);
"else" return Parser::symbol_type(token::ELSE, loc);
"while" return Parser::symbol_type(token::WHILE, loc);
"for" return Parser::symbol_type(token::FOR, loc);
"print" return Parser::symbol_type(token::PRINT, loc);
"printf" return Parser::symbol_type(token::PRINTF, loc);
"vector" return Parser::symbol_type(token::VECTOR, loc);
"push_front" return Parser::symbol_type(token::PUSH_FRONT, loc);
"push_back" return Parser::symbol_type(token::DOT_PUSH_BACK, loc);
"struct" return Parser::symbol_type(token::STRUCT, loc);
"remove" return Parser::symbol_type(token::REMOVE, loc);
"median" return Parser::symbol_type(token::MEDIAN, loc);
"iota" return Parser::symbol_type(token::IOTA, loc);
"mean" return Parser::symbol_type(token::MEAN, loc);
"size" return Parser::symbol_type(token::SIZE, loc);
"atoi" return Parser::symbol_type(token::ATOI, loc);
"get" return Parser::symbol_type(token::GET, loc);
"."     return Parser::symbol_type(token_type('.'), loc);
"["     return Parser::symbol_type(token_type('['), loc);
"]"     return Parser::symbol_type(token_type(']'), loc);


    /* defincion clásica / para caracteres especiales */
";"     return Parser::symbol_type( token_type(';'), loc );
","     return Parser::symbol_type( token_type(','), loc );
"("     return Parser::symbol_type( token_type('('), loc );
")"     return Parser::symbol_type( token_type(')'), loc );
"="     return Parser::symbol_type( token_type('='), loc );
"{"     return Parser::symbol_type( token_type('{'), loc );
"}"     return Parser::symbol_type( token_type('}'), loc );

"<=" return Parser::symbol_type(token::MENOR_IGUAL, loc);
">=" return Parser::symbol_type(token::MAYOR_IGUAL, loc);
"==" return Parser::symbol_type(token::IGUAL_IGUAL, loc);
"!=" return Parser::symbol_type(token::DIFERENTE, loc);
"<" return Parser::symbol_type(token::MENOR, loc);
">" return Parser::symbol_type(token::MAYOR, loc);
"||" return Parser::symbol_type(token::OR, loc);
"?" return Parser::symbol_type(token::INTERROGACION, loc);
"&&" return Parser::symbol_type(token::AND, loc);


    /* TOKENS   if */
{ID}  return Parser::make_ID(yytext, loc);
{NUMERO} return Parser::make_NUMERO(yytext, loc);
{FLOAT}   return Parser::make_FLOAT(yytext,loc);
\"(\\.|[^"\\])*\" return Parser::make_STRING (yytext, loc);

.  {std::cerr<<loc <<  ":"<< yytext <<": "<<"error token no esperado"<<  std::endl; }

    /*si no se usa yyterminate() se agrega lo siguiente*/
    /* <<EOF>> {return Parser::make_END(loc);} */



%%


 // más código - normalmente para manejo de errores

