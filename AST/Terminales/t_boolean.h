#ifndef T_BOOLEAN_H
#define T_BOOLEAN_H

#include "../abstractexpr.h"
#include <QString>

class T_Boolean : public AbstractExpr {
    QString str;
public:
    Resultado *Interpretar(Environment *ctx,EnvironmentFunc* ctx2) override;
    QString Graficar() override;
    T_Boolean(QString str);
};

#endif // T_BOOLEAN_H
