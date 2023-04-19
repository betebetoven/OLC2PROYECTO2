#include "nt_assignvector.h"

NT_AsigVector::NT_AsigVector(AbstractExpr *id, const QVector<AbstractExpr*>& exprList) : ID(id), ExprList(exprList) {}

// Assign vector variables to memory
Resultado *NT_AsigVector::Interpretar(Environment *ctx,EnvironmentFunc* ctx2) {
   /* Resultado* idR = this->ID->Interpretar(ctx);

    QVector<Resultado*> results;
    for (AbstractExpr* expr : this->ExprList) {
        Resultado * exprR = expr->Interpretar(ctx);
        results.append(exprR);
    }

    Simbolo* simbolo = ctx->memoria->getSimbolo(idR->valorS);

    if (simbolo != nullptr) {
        // Simple type handling
        for (Resultado* exp : results) {
            if (simbolo->tipo->Equal(exp->tipo)) {
                //simbolo->resultadoList.append(exp);
            } else {
                ctx->AddError(QString("Incorrect Types"));
            }
        }
    } else {
        ctx->AddError(QString("Could not find the variable: " + idR->valorS));
    }
*/
    return nullptr;
}

QString NT_AsigVector::Graficar() {
    std::stringstream pPosicion, idPosicion;
    pPosicion << (void*)this;
    idPosicion << (void*)this->ID;

    QString nodo = QString::fromStdString("n" + pPosicion.str() +
            " [ label=\"AsigVector\" shape=record, fillcolor=midnightblue];\n");
    nodo += QString::fromStdString("n" + pPosicion.str() + " -> n"
            + idPosicion.str() + ";\n");
    nodo += this->ID->Graficar();

    for (AbstractExpr* expr : this->ExprList) {
        std::stringstream ePosicion;
        ePosicion << (void*)expr;
        nodo += QString::fromStdString("n" + pPosicion.str() + " -> n"
                + ePosicion.str() + ";\n");
        nodo += expr->Graficar();
    }

    return nodo;
}
