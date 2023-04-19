#ifndef NT_DECLFUNC_H
#define NT_DECLFUNC_H
#include "../abstractexpr.h"


class NT_DeclFunc: public AbstractExpr {
    AbstractExpr* tipo;
    AbstractExpr* ID;
    AbstractExpr* Expr;

public:
    Resultado *Interpretar(Environment *ctx, EnvironmentFunc *ctx2) override;

    QString Graficar() override;

    NT_DeclFunc(AbstractExpr *tipo, AbstractExpr *id, AbstractExpr *expr);
};

#endif // NT_DECLFUNC_H
