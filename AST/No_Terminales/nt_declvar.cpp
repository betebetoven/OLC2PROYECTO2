#include "nt_declvar.h"

Resultado *NT_DeclVar::Interpretar(Environment *ctx,EnvironmentFunc* ctx2) {
    std::cout << "si llega al Interpretar de declvaar" << std::endl;
    Resultado* idR = this->ID->Interpretar(ctx,ctx2);
    Resultado* tipoR = this->tipo->Interpretar(ctx,ctx2);
    std::cout << "si llega al declvar idR--    " << idR->getValor().toString().toStdString() <<std::endl;
    std::cout << "si llega al declvar tipoR--    " << tipoR->getValor().toString().toStdString() <<std::endl;
    // Check if Expr is not nullptr and evaluate it
    if (this->Expr) {
        Resultado* exprR = this->Expr->Interpretar(ctx,ctx2);
        std::cout << "si llega al declvar ExpR--    " << exprR->getValor().toString().toStdString() <<std::endl;
        // Check if Expr is not nullptr and evaluate it
        // Check if the types match before adding the variable
        std::cout << "tipo de ExpR--    " << exprR->getTipo().toStdString() <<std::endl;
        std::cout << "tipo de tipoR--    " << tipoR->getTipo().toStdString() <<std::endl;
        if (exprR->getTipo() == tipoR->getTipo()) {
            QString varName = idR->getValor().toString();
            std::string valueType = tipoR->getTipo().toStdString();

            if (valueType == "Integer") {
                std::cout << "si llega al If numero de declvaar" << std::endl;
                            ctx->addVariable(varName.toStdString(), valueType, exprR->getValor().toInt());
                        } else if (valueType == "Float") {
                            ctx->addVariable(varName.toStdString(), valueType, static_cast<float>(exprR->getValor().toDouble()));
                        } else if (valueType == "Boolean") {
                            ctx->addVariable(varName.toStdString(), valueType, exprR->getValor().toBool());
                        } else if (valueType == "String") {
                            ctx->addVariable(varName.toStdString(), valueType, exprR->getValor().toString().toStdString());
                        }
        } else {
            // Handle type mismatch error
            // You can return an error Resultado or throw an exception
            // depending on your error handling strategy
            //qDebug() << "Error: Type mismatch in variable declaration";
            return nullptr;
        }
    } else {
        // If Expr is nullptr, add the variable with an empty content
        QString varName = idR->getValor().toString();
        ctx->addVariable(varName.toStdString(), tipoR->getTipo().toStdString(), nullptr);
    }
    ctx->report();
    return nullptr;
}
QString NT_DeclVar::Graficar() {
    std::stringstream  pPosicion, idPosicion, ePosicion, tPosicion ;
    pPosicion <<(void*)this;
    idPosicion <<(void*)this->ID;
    ePosicion <<(void*)this->Expr;
    tPosicion <<(void*)this->tipo;

    QString nodo = QString::fromStdString("n" + pPosicion.str() +
            " [ label=\"Decl Var\" , fillcolor=red];\n");
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


// constructor resumido c++-style
NT_DeclVar::NT_DeclVar(AbstractExpr *tipo, AbstractExpr *id, AbstractExpr *expr) : tipo(tipo), ID(id), Expr(expr) {std::cout << "CREA DECLARACION" << std::endl;}

//constructor tipo "java"
NT_DeclVar::NT_DeclVar(AbstractExpr *tipo, AbstractExpr *id) {
    this->Expr = nullptr;
    this->ID = id;
    this->tipo = tipo;
}
