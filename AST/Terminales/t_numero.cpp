#include "t_numero.h"



Resultado *T_Numero::Interpretar(Environment *ctx,EnvironmentFunc* ctx2) {
    std::cout << "si llega al Interpretar de num" << std::endl;
    return  new Resultado(this->numero.toInt());
}

QString T_Numero::Graficar() {
    std::stringstream  pPosicion;
    pPosicion <<(void*)this;
    return QString::fromStdString("n" + pPosicion.str()+
    " [ label=\"T_NUM " + this->numero.toStdString() +
    "\"   fillcolor=\"#6D7B8D\"];\n");
}

T_Numero::T_Numero(QString num) {
    this->numero = num;
}

