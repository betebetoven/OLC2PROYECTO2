#include "nt_s.h"



Resultado *NT_S::Interpretar(Environment* ctx,EnvironmentFunc* ctx2) {
    /*this->sentencias->Interpretar(ctx);*/

    return nullptr;
}

QString NT_S::Graficar() {
    std::stringstream  pPosicion, lPosicion;
    pPosicion <<(void*)this;
    lPosicion <<(void*)this->sentencias;
    QString nodo = QString::fromStdString("n" + pPosicion.str() +
            " [ label=\"S\" fillcolor=black];\n");
    nodo += this->sentencias->Graficar();
    nodo +=  QString::fromStdString("n" + pPosicion.str()+ " -> n"
            + lPosicion.str()+ "; \n");
    return nodo;
}

NT_S::NT_S(AbstractExpr *sentencias) : sentencias(sentencias) {}
