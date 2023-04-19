#include "NT_Not.h"

NT_Not::NT_Not(AbstractExpr *derecha) : Derecha(derecha) {}

Resultado *NT_Not::Interpretar(Environment *ctx,EnvironmentFunc* ctx2) {
    Resultado* der = this->Derecha->Interpretar(ctx,ctx2);

    if (!der) {
        return nullptr; // Return nullptr if the operand is nullptr
    }

    QString derTipo = der->getTipo();
    QVariant derValor = der->getValor();

    Resultado *resultado;

    // Boolean
    if (derTipo == "Boolean") {
        bool negation = !(derValor.toBool());
        resultado = new Resultado(negation);
    }
    else {
        // Unsupported operand type
        resultado = nullptr;
    }

    return resultado;
}


QString NT_Not::Graficar() {
    std::stringstream  pPosicion ,dPosicion;
    pPosicion <<(void*)this;
    dPosicion <<(void*)this->Derecha;

    QString nodo = QString::fromStdString("n" + pPosicion.str() +
            " [ label=\"!\" fillcolor=yellowgreen];\n");
    nodo += this->Derecha->Graficar();
    nodo +=  QString::fromStdString("n" + pPosicion.str() + " -> n"
            + dPosicion.str() + ";\n");
    return nodo;
}
