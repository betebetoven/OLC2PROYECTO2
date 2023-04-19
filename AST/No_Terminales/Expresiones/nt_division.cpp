#include "nt_division.h"

Resultado *NT_Division::Interpretar(Environment *ctx,EnvironmentFunc *ctx2) {
    Resultado* izqR = this->izquierda->Interpretar(ctx,ctx2);
    Resultado* derR = this->derecha->Interpretar(ctx,ctx2);

    if (!izqR || !derR) {
        return nullptr; // Return nullptr if either left or right operand is nullptr
    }

    QString izqTipo = izqR->getTipo();
    QString derTipo = derR->getTipo();

    QVariant izqValor = izqR->getValor();
    QVariant derValor = derR->getValor();

    if (derValor == 0) {
        // Division by zero
        std::cerr << "Error: Division by zero" << std::endl;
        return nullptr;
    }

    Resultado *resultado;

    // Integer / Integer
    if (izqTipo == "Integer" && derTipo == "Integer") {
        int quotient = izqValor.toInt() / derValor.toInt();
        resultado = new Resultado(quotient);
    }
    // Integer / Float, Float / Integer, Float / Float
    else if ((izqTipo == "Integer" && derTipo == "Float") || (izqTipo == "Float" && derTipo == "Integer") || (izqTipo == "Float" && derTipo == "Float")) {
        float quotient = izqValor.toFloat() / derValor.toFloat();
        resultado = new Resultado(quotient);
    }
    // Integer / Boolean, Boolean / Integer, Boolean / Float, Float / Boolean, Boolean / Boolean
    else if ((izqTipo == "Integer" && derTipo == "Boolean") || (izqTipo == "Boolean" && derTipo == "Integer") || (izqTipo == "Float" && derTipo == "Boolean") || (izqTipo == "Boolean" && derTipo == "Float") || (izqTipo == "Boolean" && derTipo == "Boolean")) {
        int quotient = izqValor.toInt() / derValor.toInt();
        resultado = new Resultado(quotient);
    }
    else {
        // Unsupported operand types
        resultado = nullptr;
    }

    return resultado;
}


QString NT_Division::Graficar() {
    std::stringstream pPosicion, iPosicion, dPosicion;
    pPosicion << (void*)this;
    iPosicion << (void*)this->izquierda;
    dPosicion << (void*)this->derecha;

    QString nodo = QString::fromStdString("n" + pPosicion.str() +
            " [ label=\"/\" fillcolor=cornflowerblue];\n");
    nodo += QString::fromStdString("n" + pPosicion.str() + " -> n" +
            iPosicion.str() + ";\n");
    nodo += this->izquierda->Graficar();
    nodo += QString::fromStdString("n" + pPosicion.str() + " -> n" +
            dPosicion.str() + ";\n");
    nodo += this->derecha->Graficar();
    return nodo;
}

NT_Division::NT_Division(AbstractExpr* izq, AbstractExpr* der)
    : izquierda(izq), derecha(der) {}
