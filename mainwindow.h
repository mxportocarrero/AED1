#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>

//includes para lectura de archivos .txt
#include <fstream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <sstream>
using std::ifstream;
using std::istringstream;
using std::vector;
using std::istream_iterator;
using std::ostringstream;

//para calcular el tiempo
#include <time.h>

#include <string>

//Estructuras
#include "listaenlazada.h"
#include "arbolbinario.h"

//funciones adicionales
#include "extras.h"


using std::string;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_FileBrowserButton_clicked();

    void on_EjecutarButton_clicked();

private:
    Ui::MainWindow *ui;

    //numero de filas donde escribira. tb es el numero de resultados
    unsigned int rowCount = 0;

    //Estructuras de datos
    ListaEnlazada LE;
    ArbolBinario<Palabra> AB;

    //otros
    short unsigned int ejecutarCount= 0;

//funciones privadas para la busqueda segun levinstein
private:
    void busqLista(ListaEnlazada, string);
};

#endif // MAINWINDOW_H
