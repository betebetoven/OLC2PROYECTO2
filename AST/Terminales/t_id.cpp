#include "t_id.h"
#include <sstream>

struct ResultadoVisitor {
    template<typename T>
    Resultado* operator()(const T& value) const {
        return new Resultado(value);
    }

    Resultado* operator()(const std::string& value) const {
        return new Resultado(QString::fromStdString(value));
    }
};

Resultado* T_ID::Interpretar(Environment* ctx,EnvironmentFunc* ctx2) {
    std::string id_str = this->id.toStdString();

    // Retrieve the variable content from the environment
    auto content = ctx->getVariableContent(id_str);
    int placer = ctx->getvariableplacer(id_str);
    // Create a new Resultado object with the content of the variable
    Resultado* resultado = std::visit(ResultadoVisitor{}, content);
    std::cout<<"t"<<MiniResultado::x<<" =P + "<<placer<<std::endl;
    MiniResultado::x++;
    std::cout<<"t"<<MiniResultado::x<<" = stack[t"<<MiniResultado::x-1<<"];"<<std::endl;
    QString generado = "t"+QString::fromStdString(std::to_string(MiniResultado::x));
    resultado->miniResultado.temporales.push_front(generado);
    MiniResultado::x++;
    return resultado;
}

QString T_ID::Graficar() {
    std::stringstream pPosicion;
    pPosicion << (void*)this;

    return QString::fromStdString("n" + pPosicion.str() +
                                   " [ label=\"T ID" + this->id.toStdString() +
                                   "\"   fillcolor=\"#12342c\"];\n");
}

T_ID::T_ID(QString id) {
    std::cout << "crea el T ID" << std::endl;
    this->id = id;
}
