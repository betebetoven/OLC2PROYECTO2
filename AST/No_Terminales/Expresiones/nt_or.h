#ifndef NT_OR_H
#define NT_OR_H

#include "../../AbstractExpr.h"

class NT_Or : public AbstractExpr {
    AbstractExpr* Izquierda;
    AbstractExpr* Derecha;
public:
    Resultado* Interpretar(Environment* ctx,EnvironmentFunc* ctx2) override;
    QString Graficar() override;

    NT_Or(AbstractExpr* izquierda, AbstractExpr* derecha);
};

#endif // NT_OR_H
