#ifndef NT_RESTA_H
#define NT_RESTA_H

#include "../../AbstractExpr.h"

class NT_Resta : public AbstractExpr {
    AbstractExpr* izquierda;
    AbstractExpr* derecha;

public:
    Resultado* Interpretar(Environment* ctx,EnvironmentFunc* ctx2) override;
    QString Graficar() override;
    NT_Resta(AbstractExpr* izq, AbstractExpr* der);
};

#endif // NT_RESTA_H
