#include "t_float.h"

Resultado *T_Float::Interpretar(Environment *ctx,EnvironmentFunc* ctx2) {
return new Resultado(this->val.toFloat());
}

QString T_Float::Graficar() {
std::stringstream pPosicion;
pPosicion <<(void*)this;
return QString::fromStdString("n" + pPosicion.str() +
" [ label=\"T_FLOAT " + this->val.toStdString() +
"\"  fillcolor=\"#004376\"];\n");
}

T_Float::T_Float(QString val) {
this->val = val;
}
