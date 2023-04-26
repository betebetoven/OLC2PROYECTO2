#include "NT_And.h"

Resultado *NT_And::Interpretar(Environment *ctx,EnvironmentFunc *ctx2) {
    Resultado* izqR = this->Izquierda->Interpretar(ctx,ctx2);
    QString izqTipo = izqR->getTipo();
    QVariant izqValor = izqR->getValor();
    QVector<QString> ev = izqR->miniResultado.EV;
    QVector<QString> ef = izqR->miniResultado.EF;
    for(int i = 0; i <ev.size();i++)
    {
        std::cout<<ev[i].toStdString()<<":"<<std::endl;
    }
    Resultado* derR = this->Derecha->Interpretar(ctx,ctx2);
    QString derTipo = derR->getTipo();
    QVariant derValor = derR->getValor();
    QVector<QString> evd = derR->miniResultado.EV;
    QVector<QString> efd = derR->miniResultado.EF;

    if (!izqR || !derR) {
        return nullptr; // Return nullptr if either left or right operand is nullptr
    }




    Resultado *resultado;

    // Boolean AND Boolean
    if (izqTipo == "Boolean" && derTipo == "Boolean") {
        bool andResult = izqValor.toBool() && derValor.toBool();
        resultado = new Resultado(andResult);
        resultado->miniResultado.EV = evd;
        resultado->miniResultado.EF = ef+efd;
    }
    else {
        // Unsupported operand types
        resultado = nullptr;
    }

    return resultado;
}


QString NT_And::Graficar() {
    std::stringstream pPosicion, dPosicion, iPosicion ;
    pPosicion << (void*)this;
    dPosicion << (void*)this->Derecha;
    iPosicion << (void*)this->Izquierda;
    QString nodo = QString::fromStdString("n" + pPosicion.str() +
            " [ label=\"&&\" fillcolor=cornflowerblue];\n");
    nodo += QString::fromStdString("n" + pPosicion.str() + " -> n"
            + iPosicion.str()+ ";\n");
    nodo += this->Izquierda->Graficar();
    nodo += QString::fromStdString("n" + pPosicion.str()+ " -> n"
            + dPosicion.str() + ";\n" );
    nodo += this->Derecha->Graficar();
    return nodo;
}

NT_And::NT_And(AbstractExpr* izquierda, AbstractExpr* derecha) : Izquierda(izquierda), Derecha(derecha) {}
