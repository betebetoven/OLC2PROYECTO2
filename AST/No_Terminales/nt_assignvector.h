#ifndef NT_ASIGVECTOR_H
#define NT_ASIGVECTOR_H

#include "../abstractexpr.h"
#include <QVector>

class NT_AsigVector: public AbstractExpr {
    AbstractExpr* ID;
    QVector<AbstractExpr*> ExprList;

public:
    NT_AsigVector(AbstractExpr *id, const QVector<AbstractExpr*>& exprList);

    Resultado *Interpretar(Environment *ctx,EnvironmentFunc* ctx2) override;
    QString Graficar() override;
};

#endif // NT_ASIGVECTOR_H
