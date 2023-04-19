#ifndef NT_DECLVECTOR_H
#define NT_DECLVECTOR_H
#include "../abstractexpr.h"

class NT_DeclVector: public AbstractExpr {
    AbstractExpr* tipo;
    AbstractExpr* ID;
    AbstractExpr* Expr;
    QVector<AbstractExpr*> instrucciones;

public:
    Resultado *Interpretar(Environment *ctx,EnvironmentFunc* ctx2) override;

    QString Graficar() override;

    NT_DeclVector(AbstractExpr *tipo, AbstractExpr *id, AbstractExpr *expr);

    NT_DeclVector(AbstractExpr *tipo, AbstractExpr *id);



};



#endif // NT_DECLVECTOR_H
