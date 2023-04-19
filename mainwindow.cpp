#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QMessageBox>
#include "Parser/interfaz.h"
#include <fstream>
#include <sstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    Clase3::Interfaz* interfaz = new Clase3::Interfaz();
    QString cabecera = QString("digraph G\n \
                               {label=\"ARBOL SINTACTICO\"\n \
                                       node[shape = hexagon]\n \
                                      node[style = filled]\n \
                                       node[fillcolor = \"#EEEEE\"]\n \
                                       node[color = \"#EEEEE\"]\n \
                                       node[color = \"#31CEF0\"]\n");
    QString dot = interfaz->Analaizar(ui->textEdit->toPlainText().toStdString());
                                std::ifstream inFile("C:\\Users\\alber\\OneDrive\\Documentos\\untitled\\AST\\No_Terminales\\consola.txt");
                                    if (inFile.is_open()) {
                                        std::stringstream buffer;
                                        buffer << inFile.rdbuf();
                                        inFile.close();
                                        QString fileContent = QString::fromStdString(buffer.str());
                                        dot = fileContent;
                                        // Do something with fileContent here

                                    } else {
                                        std::cerr << "Unable to open file 'consola.txt'\n";
                                    }

                                    // Clear the content of "consola.txt"
                                    std::ofstream outFile("C:\\Users\\alber\\OneDrive\\Documentos\\untitled\\AST\\No_Terminales\\consola.txt", std::ios_base::trunc);
                                    if (outFile.is_open()) {
                                        outFile.close();
                                    } else {
                                        std::cerr << "Unable to open file 'consola.txt'\n";
                                    }

                               ui->textEdit_2->setText(dot);
}

void MainWindow::on_pushButton_2_clicked()
{
        Clase3::Interfaz* interfaz = new Clase3::Interfaz();

        QString cabecera = QString("digraph G\n \
                                   {label=\"ARBOL SINTACTICO\"\n \
                                           node[shape = hexagon]\n \
                                          node[style = filled]\n \
                                           node[fillcolor = \"#EEEEE\"]\n \
                                           node[color = \"#EEEEE\"]\n \
                                           node[color = \"#31CEF0\"]\n");
                                   QString dot = interfaz->Ejecutar(ui->textEdit->toPlainText().toStdString());





                                                              ui->textEdit_2->setText( cabecera + dot + "}");

}


void MainWindow::on_textEdit_2_textChanged()
{

}

