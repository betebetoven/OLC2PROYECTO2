#ifndef INTERFAZ_H
#define INTERFAZ_H

#include <string>
#include "../AST/abstractexpr.h"
#include "../AST/No_Terminales/nt_s.h"
#include "../Interprete/Contexto/environment.h"
#include "../Interprete/Contexto/environmentfunc.h"
namespace yy {
    class Parser;
    class location;
}




namespace Clase3 {
class Interfaz {
    public:
        Interfaz();
        ~Interfaz();
        void* lexer;
        yy::location *loc;
        yy::Parser* Parser;

        QString Analaizar( std::string  entrada );
        QString Ejecutar( std::string  entrada );
        QVector<AbstractExpr*> raiz;

    };

}


#endif // INTERFAZ_H
