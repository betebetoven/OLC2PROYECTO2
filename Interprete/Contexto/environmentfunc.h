#ifndef ENVIRONMENTFUNC_H
#define ENVIRONMENTFUNC_H

#include <iostream>
#include <string>
#include <map>
#include <variant>
#include "../../AST/abstractexpr.h"
class AbstractExpr;
struct FuncInfo {
    std::string type;
    AbstractExpr* expr;
};

class EnvironmentFunc {
public:
    EnvironmentFunc();
    EnvironmentFunc(EnvironmentFunc* father);
    void addVariable(const std::string& name, const std::string& type, AbstractExpr* expr);
    AbstractExpr* getVariableExpr(const std::string& name);
    std::map<std::string, FuncInfo> func_table;
};

#endif // ENVIRONMENTFUNC_H
