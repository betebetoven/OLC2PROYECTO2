#ifndef NT_MAYORIGUAL_H
#define NT_MAYORIGUAL_H

#include "../../AbstractExpr.h"

class NT_MayorIgual : public AbstractExpr {
    AbstractExpr* Izquierda;
    AbstractExpr* Derecha;
public:
    Resultado* Interpretar(Environment* ctx,EnvironmentFunc* ctx2) override;
    QString Graficar() override;

    NT_MayorIgual(AbstractExpr* izquierda, AbstractExpr* derecha);
};

#endif // NT_MAYORIGUAL_H
