#include "work.h"
#include "ui_work.h"
#include <QLabel>



Work::Work(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Work)
{
    ui->setupUi(this);
}

Work::Work(int countWork, QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::Work)
{
    ui->setupUi(this);
    QLineEdit *ln;
    for(int i=0;i<countWork;++i)
    {
        ln= new QLineEdit(this);
        ln->setEnabled(false);
        ln->setText("b"+QString::number(i+1));
        ui->verticalLayout->addWidget(ln);
        ln= new QLineEdit(this);
        nameList.append(ln);
        ui->verticalLayout_2->addWidget(ln);
        ln= new QLineEdit(this);
        dependList.append(ln);
        ui->verticalLayout_3->addWidget(ln);
        ln= new QLineEdit(this);
        timeList.append(ln);
        ui->verticalLayout_4->addWidget(ln);
    }
}

Work::~Work()
{
    delete ui;
}

void Work::on_pushButton_clicked()
{
    workData *workDataStructures;
    for (int i=0; i<nameList.count();++i)
    {
        workDataStructures= new workData;
        workDataStructures->name=nameList[i]->text();
        workDataStructures->dependence=dependList[i]->text();
        workDataStructures->time=timeList[1]->text().toInt();
        workList.append(workDataStructures);
    }
}
