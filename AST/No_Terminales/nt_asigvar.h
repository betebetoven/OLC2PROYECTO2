#ifndef NT_ASIGVAR_H
#define NT_ASIGVAR_H

#include "../abstractexpr.h"
#include <QString>

class NT_AsigVar: public AbstractExpr{
    AbstractExpr* ID;
    AbstractExpr* Expr;
    bool si;
public:
    NT_AsigVar(AbstractExpr *id, AbstractExpr *expr, bool si);

    Resultado *Interpretar(Environment *ctx,EnvironmentFunc* ctx2) override;
    QString Graficar() override;
};



#endif // NT_ASIGVAR_H
