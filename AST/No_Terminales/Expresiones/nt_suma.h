#ifndef NT_SUMA_H
#define NT_SUMA_H


#include "../../AbstractExpr.h"

class NT_Suma: public AbstractExpr {
    AbstractExpr* Izquierda;
    AbstractExpr* Derecha;
public:
    Resultado *Interpretar(Environment *ctx,EnvironmentFunc *ctx2) override;

    QString Graficar() override;

    NT_Suma(AbstractExpr *izquierda, AbstractExpr *derecha);

};


#endif // NT_SUMA_H
