#ifndef NT_LLAMADA_H
#define NT_LLAMADA_H

#include "../abstractexpr.h"

class NT_Llamada : public AbstractExpr {
    AbstractExpr* ID;
    std::string nombre;

public:
    Resultado* Interpretar(Environment* env, EnvironmentFunc* ctx2) override;
    QString Graficar() override;

    NT_Llamada(AbstractExpr *id);
};

#endif // NT_LLAMADA_H
