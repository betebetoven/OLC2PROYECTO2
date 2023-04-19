#ifndef NT_MENORIGUAL_H
#define NT_MENORIGUAL_H

#include "../../AbstractExpr.h"

class NT_MenorIgual : public AbstractExpr {
    AbstractExpr* Izquierda;
    AbstractExpr* Derecha;
public:
    Resultado* Interpretar(Environment* ctx,EnvironmentFunc* ctx2) override;
    QString Graficar() override;

    NT_MenorIgual(AbstractExpr* izquierda, AbstractExpr* derecha);
};

#endif // NT_MENORIGUAL_H
