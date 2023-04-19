/*comando   bison --verbose -o parser.cpp  parser.y */

/* Se requiere una versión minima de Bison */
%require  "3.0.4"
/* Se usa el skeleton más recienta para c++ */
%skeleton "lalr1.cc"

/* indica que se deben de crear archivos de cabeceras (.h)
    para las definiciones de tokens
*/
%defines

/* indica el namespace que contiene al parser */
// %name-prefix="yy" ó
%define api.prefix{yy}

/* indica la clase que envuelve al parser */
%define api.parser.class {Parser}

/* indica que se generaran clases de tipo locations que leerá el lexer*/
%locations

/* indica que se deben crear contructores y funciones tipo make_TOKEN para cada token */

%define api.token.constructor

/* indica que se utilizará la notacion $1 -> $$ de los no terminales */
%define api.value.type variant

/* indica que el analizador mostrara un trace cuando haya un error*/
%define parse.trace

/* indica que el analizador mostrará los errores de forma descriptiva */
%define parse.error verbose

%code requires
{
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

}
/* enlace con la función del retorno de simbolos */
%code
{
yy::Parser::symbol_type yylex(void* yyscanner, yy::location& loc, class Clase3::Interfaz & intr);
}


%token END 0;  //token de salida

/// %token<tipo> nombre+
//cuidado con el orden
// %token <std::string> ID NUMERO
%token <std::string>  NUMERO ID STRING INT STR FLOAT FLO BOOL
// token de tipo por defecto
    //token por ID
%token SUMA MENOS DIM AS IMPR MOD VOID;
%token TRUE FALSE AND NOT IF THEN ELSE WHILE PRINT PRINTF FOR
%token MULTIPLICACION DIVISION EXPONENCIAL  MENOR_IGUAL MAYOR_IGUAL IGUAL_IGUAL DIFERENTE MENOR MAYOR OR INTERROGACION INCREMENT DECREMENT
%token DOT LEFT_BRACKET RIGHT_BRACKET VECTOR
%token PUSH_FRONT DOT_PUSH_BACK STRUCT REMOVE MEDIAN IOTA MEAN SIZE ATOI GET RETORNO BREAK CONTINUE
    //token por texto
%token ';' '(' ')' '=' '{' '}' '[' ']'  '.';
// negación unaria
%token NEG

/*
forma alterna
%token SUMA '+'
%token ID 'un_id'


*/
// precedencia menor a mayor
%precedence '='
%left NUMERO
%left SUMA MENOS //menos -
%left MULTIPLICACION DIVISION MOD//más
%left NEG
%right EXPONENCIAL
%left OR
%left AND
/* fin de la definción de tipos*/

/* La clase que envuele al parser se pasa por referencia
del parser al escaner evitando crear variables globales

*/

%lex-param {void *scanner} {yy::location& loc} { class Clase3::Interfaz & intr }
%parse-param {void *scanner} {yy::location& loc} { class Clase3::Interfaz & intr }


%type<AbstractExpr*>   declaracion_var escapa lista_Expr declaracion_void llamada;
%type<QVector<AbstractExpr*>*> s lSentencia;
%type<AbstractExpr*> sentencia asignacion_var aumento decremento;
%type<AbstractExpr*> expr tipo cond x;
%type<AbstractExpr*> bloque  ciclo_for ciclo_while ins_if;
%type<NT_Imprimir*> imprimir;

%type<std::string> oprel;

// printer
%printer { yyoutput << $$; } <*>;

/*
inicio de la grámatica
*/
%%
/* produccion inicial */
%start s;

s: lSentencia  {std::cout << "LLEGO A S PARA SALIR" << std::endl;
        intr.raiz = *$1;
                $$ = $1;
                if (!$1->isEmpty()) {
        AbstractExpr* firstElement = (*$1)[0]; 
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
;


lSentencia: lSentencia sentencia z {
                           $$ = $1;
                            $$->append($2);
                        }
    | sentencia z {
        QVector<AbstractExpr*>* vec = new QVector<AbstractExpr*>();
        vec->append($1);
        $$ = vec;
    }

    ;
    /*sentencias*/
sentencia: declaracion_var {$$ = $1;}
        | asignacion_var {$$ = $1; }
    | imprimir {$$ = $1; }
    | bloque {$$ = $1;}
    | aumento{$$ = $1;}
    |decremento {$$ = $1;}
    | ciclo_for{$$=$1;}
    |ciclo_while{$$=$1;}
    | ins_if{$$=$1;}
    |escapa {$$=$1;}
    |declaracion_void {$$=$1;}
    |llamada {$$=$1;}
    ;

ciclo_for:FOR '(' declaracion_var z x z aumento ')' '{' lSentencia '}' {$$ = new Bloque(*$10,$3,$5,$7,true,nullptr);}

 ;   
 ciclo_while:WHILE '(' x ')' '{' lSentencia '}' {$$ = new Bloque(*$6,nullptr,$3,nullptr,true,nullptr);}

 ; 

ins_if: IF '(' x ')' '{' lSentencia '}' {$$ = new Bloque(*$6,nullptr,$3,nullptr,false,nullptr);}
    | IF '(' x ')' '{' lSentencia '}' ELSE '{' lSentencia '}' {Bloque* elsa = new Bloque(*$10,nullptr,nullptr,nullptr,false, nullptr);
                                                                $$ = new Bloque(*$6,nullptr,$3,nullptr,false,elsa);}
    |   IF '(' x ')' '{' lSentencia '}' ELSE ins_if {$$ = new Bloque(*$6,nullptr,$3,nullptr,false,$9);}
    ;

escapa: BREAK { $$ = new NT_Escape(QString::fromStdString("break"));}
    | CONTINUE { $$ = new NT_Escape(QString::fromStdString("continue"));}
    | RETORNO { $$ = new NT_Escape(QString::fromStdString("return"));}           
    ;


 ;
llamada: /*ID '(' lista_Expr ')' { $$ = new NT_Llamada(QString::fromStdString($1),*$3);}
    | */ID '(' ')' { NT_ID* id_av = new NT_ID(QString::fromStdString($1));
        $$ = new NT_Llamada(id_av);}
    ;




aumento : INCREMENT ID {            NT_ID* id_avar2 = new NT_ID(QString::fromStdString($2));
                                T_ID* id_avar = new T_ID(QString::fromStdString($2));
                                $$ = new NT_AsigVar(id_avar2,new NT_Suma(id_avar, new T_Numero( QString::fromStdString("1"))),true ); }
    | ID INCREMENT {            NT_ID* id_avar2 = new NT_ID(QString::fromStdString($1));
                                T_ID* id_avar = new T_ID(QString::fromStdString($1));
                                $$ = new NT_AsigVar(id_avar2,new NT_Suma(id_avar, new T_Numero( QString::fromStdString("1"))),false ); }
;                                
decremento: DECREMENT ID {            NT_ID* id_avar2 = new NT_ID(QString::fromStdString($2));
                                T_ID* id_avar = new T_ID(QString::fromStdString($2));
                                $$ = new NT_AsigVar(id_avar2,new NT_Resta(id_avar, new T_Numero( QString::fromStdString("1"))),true ); }
    | ID DECREMENT {            NT_ID* id_avar2 = new NT_ID(QString::fromStdString($1));
                                T_ID* id_avar = new T_ID(QString::fromStdString($1));
                                $$ = new NT_AsigVar(id_avar2,new NT_Resta(id_avar, new T_Numero( QString::fromStdString("1"))),false ); }
;
imprimir: IMPR '(' lista_Expr ')' { $$ = new NT_Imprimir($3); }
    ;


lista_Expr: lista_Expr ','  x {   $$ = new NT_Suma($1, $3);
                                }
    | x { $$ = $1;}
    ;



bloque: '{' lSentencia '}' { $$ = new Bloque(*$2,nullptr,nullptr,nullptr,false, nullptr); }
;
z: ';' {  }
    | %empty { }
    ;

declaracion_void: tipo ID '('')' bloque { 
                                NT_ID* id = new NT_ID(QString::fromStdString($2));
                                $$ = new NT_DeclFunc($1, id, $5);
                                }
    ;





declaracion_var: tipo ID  {   NT_ID* id = new NT_ID(QString::fromStdString($2));
                                    $$ = new NT_DeclVar($1, id); }
    | tipo ID  '=' x {    
                                NT_ID* id = new NT_ID(QString::fromStdString($2));
                                $$ = new NT_DeclVar($1, id,$4 );  }
    ;

asignacion_var: ID '=' x {   NT_ID* id_avar = new NT_ID(QString::fromStdString($1));
                                $$ = new NT_AsigVar(id_avar, $3,true);
                                }
    ;

x: 
     cond{$$ = $1;}
;

cond: cond OR cond {$$ = new NT_Or($1, $3);}
    | cond AND cond {$$ = new NT_And($1, $3);}
    | NOT cond { $$ = new NT_Not($2);}
    |'(' cond ')'{$$ = $2;}
    | expr oprel expr{if ($2 == "mayor") {
        $$ = new NT_Mayor($1, $3);
    } else if ($2 == "menor") {
        $$ = new NT_Menor($1, $3);
    } else if ($2 == "igual") {
        $$ = new NT_IgualIgual($1, $3);
    } else if ($2 == "menorigual") {
        $$ = new NT_MenorIgual($1, $3);
    } else if ($2 == "mayorigual") {
        $$ = new NT_MayorIgual($1, $3);
    } else if ($2 == "diferente") {
        $$ = new NT_Diferente($1, $3);
    } else {
        $$ = new NT_Diferente($1, $3);
    }}
    |expr{$$ = $1;}
;
oprel: MAYOR{$$ = "mayor";}
    | MENOR{$$ = "menor";}
    | IGUAL_IGUAL{$$ = "igual";}
    | MENOR_IGUAL{$$ = "menorigual";}
    | MAYOR_IGUAL{$$ = "mayorigual";}
    | DIFERENTE{$$ = "diferente";}
;
expr: expr SUMA expr   { $$ = new NT_Suma($1, $3);  }
    | expr MENOS expr { $$ = new NT_Resta($1, $3); }
    | expr MULTIPLICACION expr { $$ = new NT_Multiplicacion($1, $3); }
    | expr DIVISION expr { $$ = new NT_Division($1, $3); }/*pendiente de implementar*/
    | expr MOD expr { $$ = new NT_Modulo($1, $3); }/*pendiente de implementar*/
    | expr EXPONENCIAL expr { $$ = new NT_Exponencial($1, $3); }/*pendiente de implementar*/
    | '(' expr ')' { $$ = $2; }
    | INCREMENT ID {            NT_ID* id_avar2 = new NT_ID(QString::fromStdString($2));
                                T_ID* id_avar = new T_ID(QString::fromStdString($2));
                                $$ = new NT_AsigVar(id_avar2,new NT_Suma(id_avar, new T_Numero( QString::fromStdString("1"))),true ); }
    | ID INCREMENT {            NT_ID* id_avar2 = new NT_ID(QString::fromStdString($1));
                                T_ID* id_avar = new T_ID(QString::fromStdString($1));
                                $$ = new NT_AsigVar(id_avar2,new NT_Suma(id_avar, new T_Numero( QString::fromStdString("1"))),false ); }
    | DECREMENT ID {            NT_ID* id_avar2 = new NT_ID(QString::fromStdString($2));
                                T_ID* id_avar = new T_ID(QString::fromStdString($2));
                                $$ = new NT_AsigVar(id_avar2,new NT_Resta(id_avar, new T_Numero( QString::fromStdString("1"))),true ); }
    | ID DECREMENT {            NT_ID* id_avar2 = new NT_ID(QString::fromStdString($1));
                                T_ID* id_avar = new T_ID(QString::fromStdString($1));
                                $$ = new NT_AsigVar(id_avar2,new NT_Resta(id_avar, new T_Numero( QString::fromStdString("1"))),false ); }                                                        
    | MENOS expr %prec NEG  { $$ = new NT_Negacion($2);  }
    | NUMERO { $$ = new T_Numero( QString::fromStdString($1)); }
    | ID { $$ = new T_ID( QString::fromStdString($1)); }
    | STRING { $$ = new T_String( QString::fromStdString($1));  }
    | FLOAT { $$ = new T_Float( QString::fromStdString($1));  }
    | TRUE { $$ = new T_Boolean( QString::fromStdString("true"));  }
    | FALSE { $$ = new T_Boolean( QString::fromStdString("false"));  }
    ;

tipo:  INT { $$ = new NT_Tipo( QString::fromStdString("Integer")); }
    | STR { $$ = new NT_Tipo( QString::fromStdString("String")); }
    | FLO { $$ = new NT_Tipo( QString::fromStdString("Float")); }
    | BOOL { $$ = new NT_Tipo( QString::fromStdString("Boolean")); }
    | VOID { $$ = new NT_Tipo( QString::fromStdString("Void")); }
    ;

%%
void yy::Parser::error(const yy::location& l, const std::string& m)
{
    std::cerr << l << ": " << m << std::endl;
}

