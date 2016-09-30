#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "extras.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //borrar
    ui->TraduccionTable->setColumnCount(2);
    ui->TraduccionTable->setRowCount(rowCount);

    QStringList tableHeaders;
    tableHeaders<<"Español"<<"Ingles";
    ui->TraduccionTable->setHorizontalHeaderLabels(tableHeaders);
    ui->TraduccionTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_FileBrowserButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Abrir archivo"), "/home", tr("txt Files (*.txt)"));
    ui->FilePathEdit->setText(filename);
}

void MainWindow::on_EjecutarButton_clicked()
{
    string FilePath = (ui->FilePathEdit->text()).toStdString();
    string palBuscada = (ui->PalabraEdit->text()).toStdString();

    if(FilePath == "" || palBuscada == "")
    {
        ui->statusLabel->setText("Complete todos los campos");
        return;
    }

    if(ejecutarCount != 0)
    {
        LE.limpiar();//limpia la estructura
        rowCount = 0;
        ui->TraduccionTable->setRowCount(rowCount);
    }

    clock_t inicio, fin;
    inicio = clock();
    // inicio

    ifstream archivo (FilePath);
    string linea;

    if(archivo.is_open())
    {
       while(getline(archivo, linea))
       {
          if (!linea.empty())
          {
             istringstream iss(linea);
             vector<string> words {istream_iterator<string>{iss}, istream_iterator<string>{}};
             Palabra tmp(words[0],words[1]);
             LE.pushBack(tmp);
          }
       }
       archivo.close();
    }

    //fin
    fin = clock();
    double tiempo = fin - inicio;
    tiempo = tiempo/CLOCKS_PER_SEC;

    ostringstream strs;
    strs << tiempo;
    string str = strs.str();
    ui->CargaEdit->setText(QString::fromStdString(str));

    clock_t inicio2,fin2;
    inicio2 = clock();
    //inicio
    busqLista(LE,palBuscada);
    //fin
    fin2 = clock();
    tiempo = 0;
    tiempo = fin2-inicio2;
    tiempo = tiempo/CLOCKS_PER_SEC;

    ostringstream strs2;
    strs2 << tiempo;
    string str2 = strs2.str();
    ui->BusquedaEdit->setText(QString::fromStdString(str2));

}

void MainWindow::busqLista(ListaEnlazada L ,string texto)
{
    if(L.isEmpty() || texto == "") return;
    NodoLista *p = L.getHead();
    while(p)
    {
        string a1 = p->m_dato.getString();
        int levi = Levinstein(a1,texto);
        int tmp = (ui->RadioBusquedaSpin->text()).toInt();
        if(levi <= tmp)
        {
            //do someting
            //en este caso imprimir los textos en la q table
            ui->TraduccionTable->setRowCount(rowCount+1);
            ui->TraduccionTable->setItem(rowCount,0,new QTableWidgetItem(QString::fromStdString(p->m_dato.getString())));
            ui->TraduccionTable->setItem(rowCount,1,new QTableWidgetItem(QString::fromStdString(p->m_dato.getString2())));
            rowCount++;
        }
        p = p->m_pSig;
    }
    ejecutarCount++;
}
