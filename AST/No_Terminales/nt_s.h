#ifndef NT_S_H
#define NT_S_H


#include "../abstractexpr.h"//.h"
#include "../../Interprete/Contexto/environment.h"

class NT_S : public AbstractExpr  {
    AbstractExpr* sentencias;

public:
    NT_S(AbstractExpr *sentencias);

    Resultado *Interpretar(Environment* ctx,EnvironmentFunc* ctx2) override;
    QString Graficar() override;
};

#endif // NT_S_H
