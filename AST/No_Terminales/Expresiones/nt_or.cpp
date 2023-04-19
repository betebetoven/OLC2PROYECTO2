#include "NT_Or.h"

Resultado *NT_Or::Interpretar(Environment *ctx,EnvironmentFunc* ctx2) {
    Resultado* izqR = this->Izquierda->Interpretar(ctx,ctx2);
    Resultado* derR = this->Derecha->Interpretar(ctx,ctx2);

    if (!izqR || !derR) {
        return nullptr; // Return nullptr if either left or right operand is nullptr
    }

    QString izqTipo = izqR->getTipo();
    QString derTipo = derR->getTipo();

    QVariant izqValor = izqR->getValor();
    QVariant derValor = derR->getValor();

    Resultado *resultado;

    // Boolean OR Boolean
    if (izqTipo == "Boolean" && derTipo == "Boolean") {
        bool orResult = izqValor.toBool() || derValor.toBool();
        resultado = new Resultado(orResult);
    }
    else {
        // Unsupported operand types
        resultado = nullptr;
    }

    return resultado;
}


QString NT_Or::Graficar() {
    std::stringstream pPosicion, dPosicion, iPosicion ;
    pPosicion << (void*)this;
    dPosicion << (void*)this->Derecha;
    iPosicion << (void*)this->Izquierda;
    QString nodo = QString::fromStdString("n" + pPosicion.str() +
            " [ label=\"OR\" fillcolor=cornflowerblue];\n");
    nodo += QString::fromStdString("n" + pPosicion.str() + " -> n"
            + iPosicion.str()+ ";\n");
    nodo += this->Izquierda->Graficar();
    nodo += QString::fromStdString("n" + pPosicion.str()+ " -> n"
            + dPosicion.str() + ";\n" );
    nodo += this->Derecha->Graficar();
    return nodo;
}

NT_Or::NT_Or(AbstractExpr* izquierda, AbstractExpr* derecha) : Izquierda(izquierda), Derecha(derecha) {}
