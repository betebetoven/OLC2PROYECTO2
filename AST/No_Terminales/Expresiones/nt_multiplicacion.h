#ifndef NT_MULTIPLICACION_H
#define NT_MULTIPLICACION_H

#include "../../AbstractExpr.h"

class NT_Multiplicacion : public AbstractExpr {
AbstractExpr* izquierda;
AbstractExpr* derecha;

public:
Resultado* Interpretar(Environment* ctx,EnvironmentFunc* ctx2) override;
QString Graficar() override;
NT_Multiplicacion(AbstractExpr* izq, AbstractExpr* der);
};

#endif // NT_MULTIPLICACION_H
