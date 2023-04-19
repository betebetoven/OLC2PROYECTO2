#ifndef BLOQUE_H
#define BLOQUE_H

#include "../../Interprete/Contexto/environment.h"
#include "../../AST/abstractexpr.h"
#include <QVector>

class Bloque: public AbstractExpr {
public:
    Bloque(const QVector<AbstractExpr*>& instrucciones,AbstractExpr *decl,AbstractExpr *expr,AbstractExpr *aumento, bool is_while, AbstractExpr *elsebloque);
    Resultado* Interpretar(Environment* env,EnvironmentFunc* ctx2) override;
    QString Graficar() override;

private:
    QVector<AbstractExpr*> instrucciones;
    AbstractExpr *decl;
    AbstractExpr *expr;
    AbstractExpr *aumento;
    bool is_while;
    AbstractExpr *elsebloque;


};

#endif // BLOQUE_H
