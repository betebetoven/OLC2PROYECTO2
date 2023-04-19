#include "nt_asigvar.h"

NT_AsigVar::NT_AsigVar(AbstractExpr *id, AbstractExpr *expr, bool si) : ID(id), Expr(expr) {this->si = si;std::cout << "CREA ASIGNACION" << std::endl;}

// asignamos variables a la memoria
Resultado *NT_AsigVar::Interpretar(Environment *ctx,EnvironmentFunc* ctx2) {
    Resultado* idR = this->ID->Interpretar(ctx,ctx2);
    Resultado* expR = this->Expr->Interpretar(ctx,ctx2);

    // Get variable name and value from the Resultado objects
    QString varName = idR->getValor().toString();
    //Resultado*aux = new Resultado(ctx->getVariableContent(idR->getValor().toString().toStdString()));
    std::variant<std::nullptr_t, int, float, std::string, bool> variableContent = ctx->getVariableContent(idR->getValor().toString().toStdString());

    Resultado *aux = std::visit(
        [](auto &&arg) -> Resultado * {
            using T = std::decay_t<decltype(arg)>;
            if constexpr (std::is_same_v<T, int> || std::is_same_v<T, float> || std::is_same_v<T, bool>) {
                return new Resultado(arg);
            } else if constexpr (std::is_same_v<T, std::string>) {
                return new Resultado(QString::fromStdString(arg));
            } else {
                return nullptr;
            }
        },
        variableContent);



    std::string valueType = expR->getTipo().toStdString();
    std::cout << "Entro en asignacion" << expR->getValor().toString().toStdString()<<std::endl;
    // Update the variable in the environment based on the value type
    if (valueType == "Integer") {
        ctx->updateVariable(varName.toStdString(), expR->getValor().toInt(),expR->getTipo());
    } else if (valueType == "Float") {
        ctx->updateVariable(varName.toStdString(), static_cast<float>(expR->getValor().toDouble()),expR->getTipo());
    } else if (valueType == "Boolean") {
        ctx->updateVariable(varName.toStdString(), expR->getValor().toBool(),expR->getTipo());
    } else if (valueType == "String") {
        ctx->updateVariable(varName.toStdString(), expR->getValor().toString().toStdString(),expR->getTipo());
    } else {
        // Handle type mismatch error
        // You can return an error Resultado or throw an exception
        // depending on your error handling strategy
        //qDebug() << "Error: Type mismatch in variable assignment";
        return nullptr;
    }

    ctx->report();
    if(this->si)
    return expR;
    else
        return aux;
}


QString NT_AsigVar::Graficar() {
    std::stringstream  pPosicion, idPosicion, ePosicion ;
    pPosicion <<(void*)this;
    idPosicion <<(void*)this->ID;
    ePosicion <<(void*)this->Expr;


    QString nodo = QString::fromStdString("n" + pPosicion.str() +
            " [ label=\"AsigVar\" , fillcolor=midnightblue];\n");
    nodo +=  QString::fromStdString("n" + pPosicion.str() + " -> n"
            + idPosicion.str()+ ";\n");
    nodo += this->ID->Graficar();
    nodo +=  QString::fromStdString("n" + pPosicion.str() + " -> n"
            + ePosicion.str()+ ";\n");
    nodo += this->Expr->Graficar();
    return nodo;
}
