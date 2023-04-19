#ifndef NT_MAYOR_H
#define NT_MAYOR_H

#include "../../AbstractExpr.h"

class NT_Mayor : public AbstractExpr {
AbstractExpr* Izquierda;
AbstractExpr* Derecha;
public:
Resultado* Interpretar(Environment* ctx,EnvironmentFunc* ctx2) override;
QString Graficar() override;

NT_Mayor(AbstractExpr* izquierda, AbstractExpr* derecha);
};

#endif // NT_MAYOR_H
