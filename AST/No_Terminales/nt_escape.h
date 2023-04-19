#ifndef NT_ESCAPE_H
#define NT_ESCAPE_H

#include "../abstractexpr.h"

class NT_Escape : public AbstractExpr {
    QString valor;

public:
    Resultado* Interpretar(Environment* env,EnvironmentFunc* ctx2) override;
    QString Graficar() override;

    explicit NT_Escape(const QString& valor);
};

#endif // NT_ESCAPE_H
