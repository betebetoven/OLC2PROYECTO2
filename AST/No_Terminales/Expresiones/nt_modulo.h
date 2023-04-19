#ifndef NT_MODULO_H
#define NT_MODULO_H


#include "../../AbstractExpr.h"

class NT_Modulo: public AbstractExpr {
    AbstractExpr* Izquierda;
    AbstractExpr* Derecha;
public:
    Resultado *Interpretar(Environment *ctx,EnvironmentFunc* ctx2) override;

    QString Graficar() override;

    NT_Modulo(AbstractExpr *izquierda, AbstractExpr *derecha);

};
#endif // NT_MODULO_H
