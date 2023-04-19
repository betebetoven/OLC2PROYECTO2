#include "nt_negacion.h"

NT_Negacion::NT_Negacion(AbstractExpr *derecha) : Derecha(derecha) {}

Resultado *NT_Negacion::Interpretar(Environment *ctx, EnvironmentFunc *ctx2) {
    Resultado* izqR = new Resultado(0);
    Resultado* derR = this->Derecha->Interpretar(ctx,ctx2);

    if (!izqR || !derR) {
        return nullptr; // Return nullptr if either left or right operand is nullptr
    }

    QString izqTipo = izqR->getTipo();
    QString derTipo = derR->getTipo();

    QVariant izqValor = izqR->getValor();
    QVariant derValor = derR->getValor();

    Resultado *resultado;

    // Integer - Integer
    if (izqTipo == "Integer" && derTipo == "Integer") {
        int diff = izqValor.toInt() - derValor.toInt();
        resultado = new Resultado(diff);
    }
    // Integer - Float, Float - Integer, Float - Float
    else if ((izqTipo == "Integer" && derTipo == "Float") || (izqTipo == "Float" && derTipo == "Integer") || (izqTipo == "Float" && derTipo == "Float")) {
        float diff = izqValor.toFloat() - derValor.toFloat();
        resultado = new Resultado(diff);
    }
    // Integer - Boolean, Boolean - Integer, Boolean - Float, Float - Boolean, Boolean - Boolean
    else if ((izqTipo == "Integer" && derTipo == "Boolean") || (izqTipo == "Boolean" && derTipo == "Integer") || (izqTipo == "Float" && derTipo == "Boolean") || (izqTipo == "Boolean" && derTipo == "Float") || (izqTipo == "Boolean" && derTipo == "Boolean")) {
        int diff = izqValor.toInt() - derValor.toInt();
        resultado = new Resultado(diff);
    }
    else {
        // Unsupported operand types
        resultado = nullptr;
    }

    return resultado;
}


QString NT_Negacion::Graficar() {
    std::stringstream  pPosicion ,dPosicion;
    pPosicion <<(void*)this;
    dPosicion <<(void*)this->Derecha;

    QString nodo = QString::fromStdString("n" + pPosicion.str() +
            " [ label=\"-\" fillcolor=yellowgreen];\n");
    nodo += this->Derecha->Graficar();
    nodo +=  QString::fromStdString("n" + pPosicion.str() + " -> n"
            + dPosicion.str() + ";\n");
    return nodo;

}
