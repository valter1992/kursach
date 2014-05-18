#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "work.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->spinBox->value()>0)
    {
        Work* newWork= new Work(ui->spinBox->value(),this);
        newWork->show();
    }
}
