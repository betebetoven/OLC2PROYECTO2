#ifndef NT_LISTAEXPR_H
#define NT_LISTAEXPR_H

#include "../abstractexpr.h"//.h"

class NT_ListaExpr: public  AbstractExpr{
public:
    NT_ListaExpr(AbstractExpr* expr);
    QVector<AbstractExpr*>lista_expresiones;
    Resultado *Interpretar(Environment *ctx,EnvironmentFunc* ctx2) override;
    QString Graficar() override;
    void AddNodo(AbstractExpr* nodo);
};


#endif // NT_LISTAEXPR_H
