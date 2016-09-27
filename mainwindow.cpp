#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->TraduccionTable->setRowCount(10);
    ui->TraduccionTable->setColumnCount(10);

    QStringList tableHeaders;
    tableHeaders<<"#"<<"Español"<<"Ingles";
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

}
