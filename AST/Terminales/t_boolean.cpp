#include "T_Boolean.h"


T_Boolean::T_Boolean(QString str) : str(str) {}

Resultado *T_Boolean::Interpretar(Environment *ctx,EnvironmentFunc* ctx2) {
    bool value = false;
    if (str.toLower() == "true") {
        value = true;
    } else if (str.toLower() == "false") {
        value = false;
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
