#include "nt_tipo.h"


NT_Tipo::NT_Tipo(QString tipo) {
 this->tipo = tipo;
}

Resultado *NT_Tipo::Interpretar(Environment *ctx,EnvironmentFunc* ctx2) {
    if (this->tipo == "Integer") {
        return new Resultado(0);
    } else if (this->tipo == "String") {
        return new Resultado(QString(""));
    } else if (this->tipo == "Float") {
        float x = 0.0;
        return new Resultado(x);
    } else if (this->tipo == "Boolean") {
        return new Resultado(false);
    }  else if (this->tipo == "Void") {
        return new Resultado(false);
    } else {
        return new Resultado(this->tipo);
    }
}


QString NT_Tipo::Graficar() {
    std::stringstream  pPosicion;
    pPosicion <<(void*)this;

    return QString::fromStdString("n" +pPosicion.str()+
    " [ label=\"Tipo " + this->tipo.toStdString() +
    "\"   fillcolor=grey];\n");
}
