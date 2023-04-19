#ifndef NT_LSENTENCIAS_H
#define NT_LSENTENCIAS_H
#include "../abstractexpr.h"

class NT_LSentencias : public AbstractExpr
{
public:
    QVector<AbstractExpr*> lista_sentencias;

    NT_LSentencias();
    QString Graficar() override;
    Resultado* Interpretar(Environment* ctx,EnvironmentFunc* ctx2) override;
    void AddSentencia(AbstractExpr *nodo );
};

#endif // NT_LSENTENCIAS_H
