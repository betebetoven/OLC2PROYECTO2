#include "NT_Menor.h"

Resultado *NT_Menor::Interpretar(Environment *ctx,EnvironmentFunc *ctx2) {
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

    // Integer < Integer, Integer < Float, Integer < Boolean, Float < Float, Float < Integer, Float < Boolean, Boolean < Boolean, Boolean < Integer, Boolean < Float
    if ((izqTipo == "Integer" && (derTipo == "Integer" || derTipo == "Float" || derTipo == "Boolean")) || (izqTipo == "Float" && (derTipo == "Float" || derTipo == "Integer" || derTipo == "Boolean")) || (izqTipo == "Boolean" && (derTipo == "Boolean" || derTipo == "Integer" || derTipo == "Float"))) {
        bool less = izqValor.toDouble() < derValor.toDouble();
        resultado = new Resultado(less);
    }
    else {
        // Unsupported operand types
        resultado = nullptr;
    }

    return resultado;
}


QString NT_Menor::Graficar() {
std::stringstream pPosicion, dPosicion, iPosicion ;
pPosicion << (void*)this;
dPosicion << (void*)this->Derecha;
iPosicion << (void*)this->Izquierda;
QString nodo = QString::fromStdString("n" + pPosicion.str() +
        " [ label=\"<\" fillcolor=cornflowerblue];\n");
nodo += QString::fromStdString("n" + pPosicion.str() + " -> n"
+ iPosicion.str()+ ";\n");
nodo += this->Izquierda->Graficar();
nodo += QString::fromStdString("n" + pPosicion.str()+ " -> n"
+ dPosicion.str() + ";\n" );
nodo += this->Derecha->Graficar();
return nodo;
}

NT_Menor::NT_Menor(AbstractExpr* izquierda, AbstractExpr* derecha) : Izquierda(izquierda), Derecha(derecha) {std::cout << "CREA EXPRESION MENOR" << std::endl;}
