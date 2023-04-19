
%require  "3.0.4"
%skeleton "lalr1.cc"
%defines
%define api.prefix{yy}
%define api.parser.class {Parser}
%locations
%define api.token.constructor
%define api.value.type variant
%define parse.trace
%define parse.error verbose

%code requires 
{
    
    #include<iostream> 
    #include<string> 
    #include <math.h>
    #include <stdio.h>
    int yylex (void);
    void yyerror (char const *);
    #include "parserctx.hpp"

    

}

%code
{
yy::Parser::symbol_type yylex(void* yyscanner, yy::location& loc, class OCL2Calc::ParserCtx & ctx);
}


%token END 0;  
%token <std::string>  NUMERO ID
%token '+' '-' '*' '/' '^' 
%token '(' ')'


%left '-' '+'
%left '*' '/'
%left NEG   /* negation--unary minus */
%right '^'        /* exponentiation */
%lex-param {void *scanner} {yy::location& loc} { class OCL2Calc::ParserCtx & ctx }
%parse-param {void *scanner} {yy::location& loc} { class OCL2Calc::ParserCtx & ctx }
%type<double> e;
%type<std::string>  s;
%printer { yyoutput << $$; } <*>;

%%
/* produccion inicial */

%start s;

s : e z {
    ctx.Salida = std::to_string($1);
    $$ = std::to_string($1);
    }
; 

e : e '+' e                 {$$ = $1 + $3;}
    | e '-' e               {$$ = $1 - $3;} 
    | e '*' e               {$$ = $1 * $3;} 
    | e '/' e               { $$ = $1 / $3;} 
    | '-' e  %prec NEG      { $$ = -$2;          }
    | e '^' e           { $$ = pow ($1, $3); }
    | '(' e ')'           { $$ = $2;           }
    | NUMERO                {  $$ = std::stod($1); }
 ;
z : ';' 
    | %empty { /* epsilum */ }
    ;

%%
void yy::Parser::error(const yy::location& l, const std::string& m)
{
	std::cerr << l << ": " << m << std::endl;
}