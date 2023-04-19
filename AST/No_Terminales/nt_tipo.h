#ifndef NT_TIPO_H
#define NT_TIPO_H


#include "../abstractexpr.h"//.h"

class NT_Tipo: public AbstractExpr {
 QString tipo;
public:
    NT_Tipo(QString tipo);

    Resultado *Interpretar(Environment *ctx,EnvironmentFunc* ctx2) override;

    QString Graficar() override;

};


#endif // NT_TIPO_H
