#ifndef NT_DIVISION_H
#define NT_DIVISION_H

#include "../../AbstractExpr.h"

class NT_Division : public AbstractExpr {
    AbstractExpr* izquierda;
    AbstractExpr* derecha;

public:
    Resultado* Interpretar(Environment* ctx,EnvironmentFunc* ctx2) override;
    QString Graficar() override;
    NT_Division(AbstractExpr* izq, AbstractExpr* der);
};

#endif // NT_DIVISION_H
