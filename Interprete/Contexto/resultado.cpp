// resultado.cpp
#include "resultado.h"

Resultado::Resultado() : valor(0), tipo("Integer") {}

Resultado::Resultado(int valor) : valor(valor), tipo("Integer") {}

Resultado::Resultado(float valorD) : valor(valorD), tipo("Float") {}

Resultado::Resultado(bool valorB) : valor(valorB), tipo("Boolean") {}

Resultado::Resultado(const QString& valorS) : valor(valorS), tipo("String") {}

QVariant Resultado::getValor() const {
    return valor;
}

QString Resultado::getTipo() const {
    return tipo;
}
