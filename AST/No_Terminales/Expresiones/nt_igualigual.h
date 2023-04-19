#ifndef NT_IGUALIGUAL_H
#define NT_IGUALIGUAL_H

#include "../../AbstractExpr.h"

class NT_IgualIgual : public AbstractExpr {
    AbstractExpr* Izquierda;
    AbstractExpr* Derecha;
public:
    Resultado* Interpretar(Environment* ctx,EnvironmentFunc* ctx2) override;
    QString Graficar() override;

    NT_IgualIgual(AbstractExpr* izquierda, AbstractExpr* derecha);
};

#endif // NT_IGUALIGUAL_H
