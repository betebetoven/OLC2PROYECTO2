#include "environmentfunc.h"

EnvironmentFunc::EnvironmentFunc(EnvironmentFunc* father) {
    if (father != nullptr) {
        func_table.insert(father->func_table.begin(), father->func_table.end());
    }
}

void EnvironmentFunc::addVariable(const std::string& name, const std::string& type, AbstractExpr* expr) {
    FuncInfo func_info{type, expr};
    func_table[name] = func_info;
}

AbstractExpr* EnvironmentFunc::getVariableExpr(const std::string& name) {
    auto it = func_table.find(name);
    if (it != func_table.end()) {
        return it->second.expr;
    }
    return nullptr; // Return nullptr if the variable does not exist
}
