#ifndef NT_AND_H
#define NT_AND_H

#include "../../AbstractExpr.h"

class NT_And : public AbstractExpr {
    AbstractExpr* Izquierda;
    AbstractExpr* Derecha;
public:
    Resultado* Interpretar(Environment* ctx,EnvironmentFunc* ctx2) override;
    QString Graficar() override;

    NT_And(AbstractExpr* izquierda, AbstractExpr* derecha);
};

#endif // NT_AND_H
