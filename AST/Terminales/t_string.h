#ifndef T_STRING_H
#define T_STRING_H


#include "../abstractexpr.h"

class T_String: public AbstractExpr {
    QString str;
public:
    Resultado *Interpretar(Environment *ctx, EnvironmentFunc* ctx2) override;

    QString Graficar() override;

    T_String(QString str);

};


#endif // T_STRING_H
