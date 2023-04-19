#include "interfaz.h"
#include "parser.hpp"
#include "lex.yy.c"

QString Clase3::Interfaz::Analaizar(std::string entrada) {
    yy_scan_string(entrada.c_str(), this->lexer);
    this->Parser->set_debug_level(true);

    this->Parser->parse();
std::cout << "Size of raiz in Analaizar: " << this->raiz.size() << std::endl;

std::cout << "Class name of the first element in raiz: "
                  << typeid(*this->raiz[0]).name() << std::endl;


    Environment *env = new Environment(nullptr);
    EnvironmentFunc *env2 = new EnvironmentFunc(nullptr);
    for (int i = 0; i < this->raiz.size(); i ++){

      Resultado* temp = this->raiz[i]->Interpretar(env, env2);
        /// es un return? es un break, es un continue, etc....
    }

    std::cout << "ACA ESTA LA ENV DEL MAIN: " << this->raiz.size() << std::endl;
    env->report();
    return "salida";

    return 0;
}

QString Clase3::Interfaz::Ejecutar(std::string entrada) {
    yy_scan_string(entrada.c_str(), this->lexer);
    this->Parser->set_debug_level(true);

    this->Parser->parse();


    std::stringstream  pPosicion, lPosicion;
    pPosicion <<(void*)this;
    QString temp = QString::fromStdString("n" + pPosicion.str()  +
                " [ label=\"MAIN\" fillcolor=springgreen];\n");


    for (int i = 0; i < this->raiz.size(); i ++){
        lPosicion.str(std::string());
        lPosicion.clear();
        lPosicion << (void*)this->raiz[i];

        temp +=  QString::fromStdString("n" + pPosicion.str() + " -> n"
                        + lPosicion.str()+ ";\n");
      temp += this->raiz[i]->Graficar();
        /// es un return? es un break, es un continue, etc....
    }
    std::cout << "alv si esta vacio" << std::endl;
    return temp;

}

Clase3::Interfaz::Interfaz() {
    yylex_init(&this->lexer);
    this->loc = new yy::location();
    this->Parser = new yy::Parser(lexer, *loc, *this);
    //this->raiz = QVector<AbstractExpr*>();
}

Clase3::Interfaz::~Interfaz() {
    yylex_destroy(lexer);
    delete loc;
    delete Parser;
}
