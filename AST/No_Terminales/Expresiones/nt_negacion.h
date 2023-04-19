#ifndef NT_NEGACION_H
#define NT_NEGACION_H



#include "../../AbstractExpr.h"

class NT_Negacion : public AbstractExpr{
    AbstractExpr* Derecha;
public:
    NT_Negacion(AbstractExpr *derecha);
    Resultado *Interpretar(Environment *ctx,EnvironmentFunc* ctx2) override;
    QString Graficar() override;
};


#endif // NT_NEGACION_H
