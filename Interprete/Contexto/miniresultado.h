// miniresultado.h
#ifndef MINIRESULTADO_H
#define MINIRESULTADO_H

#include <QString>
#include <QVector>

class MiniResultado {

public:
    static int x;

    QVector<QString>temporales = {};
    QVector<QString>EV = {};
    QVector<QString>EF = {};
    QVector<QString>LI = {};
    QVector<QString>LS = {};
    QString dir = "";
    QString tipodato = "";
    QString manejo = "";
};

#endif // MINIRESULTADO_H
