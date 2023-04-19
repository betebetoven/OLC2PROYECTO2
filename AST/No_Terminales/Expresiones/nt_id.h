#ifndef NT_ID_H
#define NT_ID_H

#include "../../abstractexpr.h"

class NT_ID: public AbstractExpr{
    QString id;

public:
    Resultado *Interpretar(Environment *ctx,EnvironmentFunc* ctx2) override;

    explicit NT_ID(const QString &id);

    QString Graficar() override;
};

#endif // NT_ID_H
