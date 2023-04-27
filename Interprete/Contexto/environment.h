#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <iostream>
#include <string>
#include <map>
#include <variant>
#include<QString>
#include<Qvector>
#include <sstream>
//#include"../../AST/abstractexpr.h"
//class AbstracExpr;
struct VariableInfo {
    std::string type;
    std::variant<std::nullptr_t, int, float, std::string, bool> content; // Added float
    int placer;
};

class ContentPrinter {
public:
    template<typename T>
    void operator()(const T& value) const {
        std::cout << value;
    }
};

void print_variant(const std::variant<std::nullptr_t, int, float, std::string, bool>& var);

class Environment {

public:
    int placer;
    Environment();
    Environment(Environment* father);
    void addVariable(const std::string& name, const std::string& type, const std::variant<std::nullptr_t, int, float, std::string, bool>& content);
    void updateVariable(const std::string& name, const std::variant<std::nullptr_t, int, float, std::string, bool>& newValue, const QString& newValueType);
    void updateCommonVariables(Environment* other);
    std::string getVariableType(const std::string& name);
    bool variableExists(const std::string& name);
    void report();
    std::variant<std::nullptr_t, int, float, std::string, bool> getVariableContent(const std::string& name);
    int getvariableplacer(const std::string& name);
    std::map<std::string, VariableInfo> symbol_table;
};

#endif // ENVIRONMENT_H
