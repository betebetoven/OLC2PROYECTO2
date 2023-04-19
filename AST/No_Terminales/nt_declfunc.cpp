#include "nt_declfunc.h"

Resultado *NT_DeclFunc::Interpretar(Environment *ctx, EnvironmentFunc* ctx2) {

    Resultado* idR = this->ID->Interpretar(ctx, ctx2);
    Resultado* tipoR = this->tipo->Interpretar(ctx, ctx2);
    if (this->Expr) {
        //Resultado* exprR = this->Expr->Interpretar(ctx, ctx2);
        QString varName = idR->getValor().toString();
        std::string valueType = tipoR->getTipo().toStdString();

        ctx2->addVariable(varName.toStdString(), valueType, Expr);
    }

    return nullptr;
}
QString NT_DeclFunc::Graficar() {
    std::stringstream  pPosicion, idPosicion, ePosicion, tPosicion ;
    pPosicion <<(void*)this;
    idPosicion <<(void*)this->ID;
    ePosicion <<(void*)this->Expr;
    tPosicion <<(void*)this->tipo;

    QString nodo = QString::fromStdString("n" + pPosicion.str() +
            " [ label=\"Decl FUNCION\" , fillcolor=red];\n");
    nodo +=  QString::fromStdString("n" + pPosicion.str() + " -> n"
            + idPosicion.str()+ ";\n");
    nodo += this->ID->Graficar();
    nodo +=  QString::fromStdString("n" + pPosicion.str() + " -> n"
            + tPosicion.str()+ ";\n");
    nodo += this->tipo->Graficar();

    if (this->Expr != nullptr){
        nodo +=  QString::fromStdString("n" + pPosicion.str() + " -> n"
                + ePosicion.str()+ ";\n");
        nodo += this->Expr->Graficar();
    }
    return nodo;
}


NT_DeclFunc::NT_DeclFunc(AbstractExpr *tipo, AbstractExpr *id, AbstractExpr *expr) : tipo(tipo), ID(id), Expr(expr) {}
