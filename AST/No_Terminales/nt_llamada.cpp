#include "nt_llamada.h"

Resultado* NT_Llamada::Interpretar(Environment* env, EnvironmentFunc* ctx2) {
    Resultado* idR = this->ID->Interpretar(env,ctx2);
    std::string varName = idR->getValor().toString().toStdString();
    this->nombre = varName;
    AbstractExpr* expr = ctx2->getVariableExpr(varName);
    
    if (expr) {
        // Call the Interpretar method of the retrieved AbstractExpr object
        return expr->Interpretar(env, ctx2);
    } 
    else {
        // Throw an error
        return nullptr;
    }
}

QString NT_Llamada::Graficar() {
    std::stringstream pPosicion;
    pPosicion << (void*)this;
    return QString::fromStdString("n" + pPosicion.str() +
                                  " [ label=\"EXP: Llamada " + this->nombre +
                                  "\"   fillcolor=lightblue];\n");
}

NT_Llamada::NT_Llamada(AbstractExpr *id) : ID(id) {}
