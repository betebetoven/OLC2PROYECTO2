// resultado.h
#ifndef RESULTADO_H
#define RESULTADO_H

#include <QString>
#include <QVariant>

class Resultado {
public:
    QVariant valor;
    QString tipo;

    Resultado();
    Resultado(int valor);
    Resultado(float valorD);
    Resultado(bool valorB);
    Resultado(const QString& valorS);

    QVariant getValor() const;
    QString getTipo() const;
};

#endif // RESULTADO_H
