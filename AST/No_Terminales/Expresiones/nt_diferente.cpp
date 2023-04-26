#include "NT_Diferente.h"

Resultado *NT_Diferente::Interpretar(Environment *ctx,EnvironmentFunc *ctx2) {
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

    // Integer != Integer, Integer != Float, Integer != Boolean, Float != Float, Float != Integer, Float != Boolean, Boolean != Boolean, Boolean != Integer, Boolean != Float
    if ((izqTipo == "Integer" && (derTipo == "Integer" || derTipo == "Float" || derTipo == "Boolean")) || (izqTipo == "Float" && (derTipo == "Float" || derTipo == "Integer" || derTipo == "Boolean")) || (izqTipo == "Boolean" && (derTipo == "Boolean" || derTipo == "Integer" || derTipo == "Float"))) {
        bool notEqual = izqValor.toDouble() != derValor.toDouble();
        QString ev = "L" +QString::fromStdString(std::to_string(MiniResultado::L++));
        QString ef = "L" +QString::fromStdString(std::to_string(MiniResultado::L++));
        if(izqR->miniResultado.temporales.size()==0 && derR->miniResultado.temporales.size()==0 )
        {
        std::cout<<"if("<<izqValor.toFloat() <<"!=" <<derValor.toFloat() << ") then goto "<<ev.toStdString() <<";"<<std::endl;
        std::cout<<"goto "<<ef.toStdString() <<";"<<std::endl;
        }
        else if(izqR->miniResultado.temporales.size()==0 && derR->miniResultado.temporales.size()!=0 )
        {
            QString temp = derR->miniResultado.temporales[0];
            std::cout<<"if("<<izqValor.toFloat() <<"!=" <<temp.toStdString() << ") then goto "<<ev.toStdString() <<";"<<std::endl;
            std::cout<<"goto "<<ef.toStdString() <<";"<<std::endl;

        }
        else if(izqR->miniResultado.temporales.size()!=0 && derR->miniResultado.temporales.size()==0 )
        {
            QString temp = izqR->miniResultado.temporales[0];
            std::cout<<"if("<<temp.toStdString() <<"!=" <<derValor.toFloat() << ") then goto "<<ev.toStdString() <<";"<<std::endl;
            std::cout<<"goto "<<ef.toStdString() <<";"<<std::endl;

        }
        else if(izqR->miniResultado.temporales.size()!=0 && derR->miniResultado.temporales.size()!=0 )
        {
            QString temp = izqR->miniResultado.temporales[0];
            QString temp2 = derR->miniResultado.temporales[0];
            std::cout<<"if("<<temp.toStdString() <<"!=" <<temp2.toStdString() << ") then goto "<<ev.toStdString() <<";"<<std::endl;
            std::cout<<"goto "<<ef.toStdString() <<";"<<std::endl;

        }



         resultado = new Resultado(notEqual);
        QString verdadero = QString::fromStdString("t"+(std::to_string(MiniResultado::x)));

        QString falso= QString::fromStdString("t"+(std::to_string(MiniResultado::x)));

        resultado->miniResultado.EV.push_front(ev);
        resultado->miniResultado.EF.push_front(ef);

    }
    // String != String
    else if (izqTipo == "String" && derTipo == "String") {
        bool notEqual = izqValor.toString() != derValor.toString();
        resultado = new Resultado(notEqual);
    }
    else {
        // Unsupported operand types
        resultado = nullptr;
    }

    return resultado;
}


QString NT_Diferente::Graficar() {
    std::stringstream pPosicion, dPosicion, iPosicion ;
    pPosicion << (void*)this;
    dPosicion << (void*)this->Derecha;
    iPosicion << (void*)this->Izquierda;
    QString nodo = QString::fromStdString("n" + pPosicion.str() +
            " [ label=\"!=\" fillcolor=cornflowerblue];\n");
    nodo += QString::fromStdString("n" + pPosicion.str() + " -> n"
            + iPosicion.str()+ ";\n");
    nodo += this->Izquierda->Graficar();
    nodo += QString::fromStdString("n" + pPosicion.str()+ " -> n"
            + dPosicion.str() + ";\n" );
    nodo += this->Derecha->Graficar();
    return nodo;
}

NT_Diferente::NT_Diferente(AbstractExpr* izquierda, AbstractExpr* derecha) : Izquierda(izquierda), Derecha(derecha) {}
