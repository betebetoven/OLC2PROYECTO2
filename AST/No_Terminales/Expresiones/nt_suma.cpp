#include "nt_suma.h"

Resultado *NT_Suma::Interpretar(Environment *ctx,EnvironmentFunc *ctx2) {
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

    // Integer + Integer
    if (izqTipo == "Integer" && derTipo == "Integer") {
        int sum = izqValor.toInt() + derValor.toInt();


        if(izqR->miniResultado.temporales.size()==0 && derR->miniResultado.temporales.size()==0 )
        std::cout<<"t"<<MiniResultado::x<<"= "<<izqValor.toInt() <<"+"<<derValor.toInt()<<std::endl;
        else if(izqR->miniResultado.temporales.size()==0 && derR->miniResultado.temporales.size()!=0 )
        {
            QString temp = derR->miniResultado.temporales[0];
            std::cout<<"t"<<MiniResultado::x<<"= "<<izqValor.toInt() <<"+"<<temp.toStdString()<<std::endl;
        }
        else if(izqR->miniResultado.temporales.size()!=0 && derR->miniResultado.temporales.size()==0 )
        {
            QString temp = izqR->miniResultado.temporales[0];
            std::cout<<"t"<<MiniResultado::x<<"= "<<temp.toStdString()<<"+"<<derValor.toInt()<<std::endl;
        }
        else if(izqR->miniResultado.temporales.size()!=0 && derR->miniResultado.temporales.size()!=0 )
        {
            QString temp = izqR->miniResultado.temporales[0];
            QString temp2 = derR->miniResultado.temporales[0];
            std::cout<<"t"<<MiniResultado::x<<"= "<<temp.toStdString()<<"+"<<temp2.toStdString()<<std::endl;
        }



        resultado = new Resultado(sum);
        QString generado = QString::fromStdString("t"+(std::to_string(MiniResultado::x)));

        resultado->miniResultado.temporales.push_front(generado);
        MiniResultado::x++;
    }
    // Integer + Float, Float + Integer, Float + Float
    else if ((izqTipo == "Integer" && derTipo == "Float") || (izqTipo == "Float" && derTipo == "Integer") || (izqTipo == "Float" && derTipo == "Float")) {
        float sum = izqValor.toFloat() + derValor.toFloat();

        if(izqR->miniResultado.temporales.size()==0 && derR->miniResultado.temporales.size()==0 )
        std::cout<<"t"<<MiniResultado::x<<"= "<<izqValor.toFloat() <<"+"<<derValor.toFloat()<<std::endl;
        else if(izqR->miniResultado.temporales.size()==0 && derR->miniResultado.temporales.size()!=0 )
        {
            QString temp = derR->miniResultado.temporales[0];
            std::cout<<"t"<<MiniResultado::x<<"= "<<izqValor.toFloat() <<"+"<<temp.toStdString()<<std::endl;
        }
        else if(izqR->miniResultado.temporales.size()!=0 && derR->miniResultado.temporales.size()==0 )
        {
            QString temp = izqR->miniResultado.temporales[0];
            std::cout<<"t"<<MiniResultado::x<<"= "<<temp.toStdString()<<"+"<<derValor.toFloat()<<std::endl;
        }
        else if(izqR->miniResultado.temporales.size()!=0 && derR->miniResultado.temporales.size()!=0 )
        {
            QString temp = izqR->miniResultado.temporales[0];
            QString temp2 = derR->miniResultado.temporales[0];
            std::cout<<"t"<<MiniResultado::x<<"= "<<temp.toStdString()<<"+"<<temp2.toStdString()<<std::endl;
        }





        resultado = new Resultado(sum);
        QString generado = QString::fromStdString("t"+(std::to_string(MiniResultado::x)));

        resultado->miniResultado.temporales.push_front(generado);
        MiniResultado::x++;
    }
    // Integer + String, String + Integer, String + String, String + Float, String + Boolean, Float + String, Boolean + String
    else if (izqTipo == "String" || derTipo == "String") {
        QString sum = izqValor.toString() + derValor.toString();

        resultado = new Resultado(sum);
    }
    // Integer + Boolean, Boolean + Integer, Boolean + Float, Float + Boolean, Boolean + Boolean
    else if (izqTipo == "Boolean" || derTipo == "Boolean") {
        int sum = izqValor.toInt() + derValor.toInt();

        resultado = new Resultado(sum);
    }
    else {
        // Unsupported operand types
        resultado = nullptr;
    }

    return resultado;
}


QString NT_Suma::Graficar() {
    std::stringstream  pPosicion, dPosicion, iPosicion ;
    pPosicion <<(void*)this;
    dPosicion <<(void*)this->Derecha;
    iPosicion <<(void*)this->Izquierda;

    QString nodo = QString::fromStdString("n" + pPosicion.str() +
            " [ label=\"+\" fillcolor=cornflowerblue];\n");
    nodo +=  QString::fromStdString("n" + pPosicion.str() + " -> n"
            + iPosicion.str()+ ";\n");
    nodo += this->Izquierda->Graficar();
    nodo +=  QString::fromStdString("n" + pPosicion.str()+ " -> n"
            + dPosicion.str() + ";\n" );
    nodo += this->Derecha->Graficar();
    return nodo;
}

NT_Suma::NT_Suma(AbstractExpr *izquierda, AbstractExpr *derecha) : Izquierda(izquierda), Derecha(derecha) {}
