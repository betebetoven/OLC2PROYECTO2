#ifndef NT_DECLVAR_H
#define NT_DECLVAR_H
#include "../abstractexpr.h"

class NT_DeclVar: public AbstractExpr {
    AbstractExpr* tipo;
    AbstractExpr* ID;
    AbstractExpr* Expr;


public:
    Resultado *Interpretar(Environment *ctx,EnvironmentFunc* ctx2) override;

    QString Graficar() override;

    NT_DeclVar(AbstractExpr *tipo, AbstractExpr *id, AbstractExpr *expr);

    NT_DeclVar(AbstractExpr *tipo, AbstractExpr *id);



};



#endif // NT_DECLVAR_H
