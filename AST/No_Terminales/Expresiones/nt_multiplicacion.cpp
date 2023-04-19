#include "nt_multiplicacion.h"

Resultado *NT_Multiplicacion::Interpretar(Environment *ctx,EnvironmentFunc *ctx2) {
    Resultado* izqR = this->izquierda->Interpretar(ctx,ctx2);
    Resultado* derR = this->derecha->Interpretar(ctx,ctx2);

    if (!izqR || !derR) {
        return nullptr; // Return nullptr if either left or right operand is nullptr
    }

    QString izqTipo = izqR->getTipo();
    QString derTipo = derR->getTipo();

    QVariant izqValor = izqR->getValor();
    QVariant derValor = derR->getValor();

    Resultado *resultado;

    // Integer * Integer
    if (izqTipo == "Integer" && derTipo == "Integer") {
        int product = izqValor.toInt() * derValor.toInt();
        resultado = new Resultado(product);
    }
    // Integer * Float, Float * Integer, Float * Float
    else if ((izqTipo == "Integer" && derTipo == "Float") || (izqTipo == "Float" && derTipo == "Integer") || (izqTipo == "Float" && derTipo == "Float")) {
        float product = izqValor.toFloat() * derValor.toFloat();
        resultado = new Resultado(product);
    }
    // Integer * Boolean, Boolean * Integer, Boolean * Float, Float * Boolean, Boolean * Boolean
    else if ((izqTipo == "Integer" && derTipo == "Boolean") || (izqTipo == "Boolean" && derTipo == "Integer") || (izqTipo == "Float" && derTipo == "Boolean") || (izqTipo == "Boolean" && derTipo == "Float") || (izqTipo == "Boolean" && derTipo == "Boolean")) {
        int product = izqValor.toInt() * derValor.toInt();
        resultado = new Resultado(product);
    }
    else {
        // Unsupported operand types
        resultado = nullptr;
    }

    return resultado;
}


QString NT_Multiplicacion::Graficar() {
    std::stringstream  pPosicion, dPosicion, iPosicion ;
    pPosicion <<(void*)this;
    dPosicion <<(void*)this->derecha;
    iPosicion <<(void*)this->izquierda;

    QString nodo = QString::fromStdString("n" + pPosicion.str() +
            " [ label=\"*\" fillcolor=cornflowerblue];\n");
    nodo +=  QString::fromStdString("n" + pPosicion.str() + " -> n"
            + iPosicion.str()+ ";\n");
    nodo += this->izquierda->Graficar();
    nodo +=  QString::fromStdString("n" + pPosicion.str()+ " -> n"
            + dPosicion.str() + ";\n" );
    nodo += this->derecha->Graficar();
    return nodo;
}

NT_Multiplicacion::NT_Multiplicacion(AbstractExpr* izq, AbstractExpr* der)
: izquierda(izq), derecha(der) {}
