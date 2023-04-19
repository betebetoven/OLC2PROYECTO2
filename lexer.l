%option reentrant noyywrap nounput batch noinput
%option debug 
/*%option outfile="lexer.cpp" */
/* %option header-file="lexer.hpp"*/
%{
    #include <iostream>
    // definicion del tipo de funcion del retorno de simbolos
    // yy::Parser ¿Por qué?
    // yy es el namespace de parser
    // Parser es el nombre de la clase que lo envuelve (wapper)
    #define YY_DECL yy::Parser::symbol_type yylex(yyscan_t yyscanner, yy::location& loc, class OCL2Calc::ParserCtx & ctx)
    // definición de acciones
    #define YY_USER_ACTION loc.columns(yyleng);
    // defincion de caracter EOF
    #define yyterminate() return Parser::make_END(loc)
    //se incrusta el parser
    #include "parser.hpp"


    using namespace yy;
    //typedefs (abreviaturas DefLarga DefCorta) para definiciones de tokens
    typedef yy::Parser::token token;
    typedef yy::Parser::token_type token_type;
/// código adicinoal aquí

%}


ID    [a-zA-Z][a-zA-Z_0-9]*
NUMERO   [0-9]+


%%
%{
loc.step();

}%

"//"[^\n]*\n            ;
[ \t\r\n]       ;/* Ignore */    
"true"            return Parser::symbol_type(token::VERDADERO, loc);
"false"           return Parser::symbol_type(token::FALSO, loc);
"and"             return Parser::symbol_type(token::AND, loc);
"not"             return Parser::symbol_type(token::NOT, loc);
"="             return Parser::symbol_type(token_type('='), loc);
"<"             return Parser::symbol_type(token_type('<'), loc);
">"             return Parser::symbol_type(token_type('>'), loc);
"+"             return Parser::symbol_type(token_type('+'), loc);
"-"             return Parser::symbol_type(token_type('-'), loc);
"*"             return Parser::symbol_type(token_type('*'), loc);
"/"             return Parser::symbol_type(token_type('/'), loc);
";"             return Parser::symbol_type(token_type(';'), loc);
":="            return Parser::symbol_type(token_type(':='), loc);
"("             return Parser::symbol_type(token_type('()'), loc);
")"             return Parser::symbol_type(token_type(')'), loc);
"skip"            return Parser::symbol_type(token::SKIP, loc);
"if"              return Parser::symbol_type(token::IF, loc);
"then"            return Parser::symbol_type(token::THEN, loc);
"else"            return Parser::symbol_type(token::ELSE, loc);
"while"           return Parser::symbol_type(token::WHILE, loc);
"print"           return Parser::symbol_type(token::PRINT, loc);
{ID}  return Parser::make_ID(yytext, loc);
{NUMERO} return Parser::make_NUMERO(yytext, loc);
\"(\\.|[^"\\])*\" return Parser::make_STRING (yytext, loc);


.  {std::cerr<<loc <<  ":"<< yytext <<": "<<"error token no esperado"<<  std::endl; }





%%

