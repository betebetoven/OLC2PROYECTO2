#include "T_Boolean.h"


T_Boolean::T_Boolean(QString str) : str(str) {}

Resultado *T_Boolean::Interpretar(Environment *ctx,EnvironmentFunc* ctx2) {
    int value = 0;
    if (str.toLower() == "true") {
        value = 1;
    } else if (str.toLower() == "false") {
        value = 0;
    }
    return new Resultado(value);
}

QString T_Boolean::Graficar() {
    std::stringstream  pPosicion;
    pPosicion <<(void*)this;
    return QString::fromStdString("n" + pPosicion.str() +
    " [ label=\" VALOR BOOLEAN:" +
    "\"   fillcolor=\"#004376\"];\n");
}
