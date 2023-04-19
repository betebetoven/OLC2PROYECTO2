#ifndef NT_MENOR_H
#define NT_MENOR_H

#include "../../AbstractExpr.h"

class NT_Menor : public AbstractExpr {
AbstractExpr* Izquierda;
AbstractExpr* Derecha;
public:
Resultado* Interpretar(Environment* ctx,EnvironmentFunc* ctx2) override;
QString Graficar() override;
NT_Menor(AbstractExpr* izquierda, AbstractExpr* derecha);
};

#endif // NT_MENOR_H
