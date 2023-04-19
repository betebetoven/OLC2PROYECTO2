#include "nt_id.h"

Resultado *NT_ID::Interpretar(Environment *ctx, EnvironmentFunc *ctx2) {
    std::cout << "si llega al Intewrpretar de Nt_ID--    " << this->id.toStdString()<<std::endl;
   return new Resultado(this->id);
}

QString NT_ID::Graficar() {
    std::stringstream pPosicion ;
    pPosicion << (void*)this;
    return QString::fromStdString("n" + pPosicion.str() +
                                  " [ label=\"EXP: ID" + this->id.toStdString() +
                                  "\"   fillcolor=tomato];\n");
}

NT_ID::NT_ID(const QString &id) : id(id) {
}
