#ifndef NT_NOT_H
#define NT_NOT_H

#include "../../AbstractExpr.h"

class NT_Not : public AbstractExpr{
    AbstractExpr* Derecha;
public:
    NT_Not(AbstractExpr *derecha);
    Resultado *Interpretar(Environment *ctx,EnvironmentFunc* ctx2) override;
    QString Graficar() override;
};

#endif // NT_NOT_H
