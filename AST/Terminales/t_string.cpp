#include "t_string.h"


Resultado *T_String::Interpretar(Environment *ctx,EnvironmentFunc* ctx2) {
//    auto  StringTipo = ctx->tabla_tipos->getTipo(QString("String"));
     QString trimmedStr = this->str.mid(1, this->str.length() - 2);
     std::cout << "REconocio string: " << trimmedStr.toStdString() << std::endl;
    return new Resultado(trimmedStr);
}

QString T_String::Graficar() {
    std::stringstream  pPosicion;
    pPosicion <<(void*)this;
    return QString::fromStdString("n" + pPosicion.str() +
    " [ label=\"T STR: " + this->str.toStdString().substr(1,this->str.size()-2) +
    "\"   fillcolor=\"#004376\"];\n");
}

T_String::T_String(QString str) {
    this->str = str;
}
