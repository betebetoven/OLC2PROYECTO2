#ifndef T_FLOAT_H
#define T_FLOAT_H

#include "../abstractexpr.h"

class T_Float: public AbstractExpr {
QString val;
public:
Resultado *Interpretar(Environment *ctx,EnvironmentFunc* ctx2) override;
QString Graficar() override;

T_Float(QString val);
};

#endif // T_FLOAT_H
