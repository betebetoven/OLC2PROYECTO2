#ifndef NT_DIFERENTE_H
#define NT_DIFERENTE_H

#include "../../AbstractExpr.h"

class NT_Diferente : public AbstractExpr {
    AbstractExpr* Izquierda;
    AbstractExpr* Derecha;
public:
    Resultado* Interpretar(Environment* ctx,EnvironmentFunc* ctx2) override;
    QString Graficar() override;

    NT_Diferente(AbstractExpr* izquierda, AbstractExpr* derecha);
};

#endif // NT_DIFERENTE_H
