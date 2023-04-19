#include "nt_sentencia.h"


Resultado *NT_Sentencia::Interpretar(Environment *ctx,EnvironmentFunc* ctx2) {
    return  this->hijo->Interpretar(ctx,ctx2);
//    return nullptr;
}

QString NT_Sentencia::Graficar() {
    /*std::stringstream  pPosicion, sPosicion;
    pPosicion <<(void*)this;
    sPosicion <<(void*)this->hijo;

    QString nodo = QString::fromStdString("n" + pPosicion.str() +
            " [ label=\"Sent\" fillcolor=yellow];\n");
    nodo += this->hijo->Graficar();
    nodo +=  QString::fromStdString("n" + pPosicion.str() + " -> "
            + sPosicion.str()+ ";\n");*/
    return nullptr;

}

void NT_Sentencia::AddNodo(AbstractExpr *hijo) {
    this->hijo = hijo;
}
