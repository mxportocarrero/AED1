#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //borrar
    coincidencias = 10;
    ui->TraduccionTable->setRowCount(coincidencias);
    ui->TraduccionTable->setColumnCount(2);

    QStringList tableHeaders;
    tableHeaders<<"Español"<<"Ingles";
    ui->TraduccionTable->setHorizontalHeaderLabels(tableHeaders);
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
    string FilePath = (ui->FilePathEdit->text()).toUtf8().constData();

    clock_t inicio, fin;
    inicio = clock();
    // inicio

    ListaEnlazada L1;

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
             L1.pushBack(tmp);
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

}
