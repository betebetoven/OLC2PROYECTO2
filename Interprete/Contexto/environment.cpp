#include "Environment.h"
#include <QMessageBox>

Environment::Environment() {}

Environment::Environment(Environment* father) {
    if (father != nullptr) {
        symbol_table.insert(father->symbol_table.begin(), father->symbol_table.end());
    }
}

void Environment::addVariable(const std::string& name, const std::string& type, const std::variant<std::nullptr_t, int, float, std::string, bool>& content) {
    std::cout << "si llega al addvariable de env" << std::endl;
    if (!variableExists(name)) {
        //AbstractExpr*prueba;
        VariableInfo variable_info{type, content};
        symbol_table[name] = variable_info;
    }
}
//...


void Environment::updateCommonVariables(Environment* other) {
    for (auto& entry : symbol_table) {
        const std::string& name = entry.first;

        if (other->variableExists(name)) {
            symbol_table[name].content = other->getVariableContent(name);
        }
    }
}





void Environment::updateVariable(const std::string& name, const std::variant<std::nullptr_t, int, float, std::string, bool>& newValue, const QString& newValueType) {
    std::cout << "si llega al updateVariable de env" << std::endl;
    if (variableExists(name)) {
        QString varType = QString::fromStdString(getVariableType(name));
        if (varType == newValueType) {
            symbol_table[name].content = newValue;
        } else {
            std::cout << "Type mismatch. Cannot update the variable." << std::endl;
        }
    }
}

//...

std::string Environment::getVariableType(const std::string& name) {
    if (variableExists(name)) {
        return symbol_table[name].type;
    }
    return "";
}

bool Environment::variableExists(const std::string& name) {
    std::cout << "si llega al variableexist de env" << std::endl;
    return symbol_table.find(name) != symbol_table.end();
}

void Environment::report() {
    std::cout << "Symbol table contents:\n";
    for (const auto& entry : symbol_table) {
        std::cout << "Name: " << entry.first
                  << ", Type: " << entry.second.type
                  << ", Content: ";
        print_variant(entry.second.content);
        std::cout << std::endl;
    }
}

void print_variant(const std::variant<std::nullptr_t, int, float, std::string, bool>& var) {
    std::visit(ContentPrinter{}, var);
}

std::variant<std::nullptr_t, int, float, std::string, bool> Environment::getVariableContent(const std::string& name) {
    if (variableExists(name)) {
        return symbol_table[name].content;
    }
    return std::variant<std::nullptr_t, int, float, std::string, bool>{}; // Return
}
