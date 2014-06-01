#include "work.h"
#include "ui_work.h"
#include <QLabel>
#include <QStringList>
#include "graph.h"



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
    QStringList lst;
    for(int i=1; i<=countWork; ++i)
    {
        lst<<"b"+QString::number(i);
    }

    MultiListWidget *ml;

    for(int i=0;i<countWork;++i)
    {
        ln= new QLineEdit(this);
        ln->setEnabled(false);
        ln->setText("b"+QString::number(i+1));
        ui->verticalLayout->addWidget(ln);
        ln= new QLineEdit(this);
        nameList.append(ln);
        ui->verticalLayout_2->addWidget(ln);
        ml= new MultiListWidget();
        ml->addItems(lst);
        ml->removeItem(i);
        dependList.append(ml);
        ui->verticalLayout_3->addWidget(ml);
        ln= new QLineEdit(this);
        ln->setInputMask("900");
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
    workList.clear();
    workData *workDataStructures;
    for (int i=0; i<nameList.count();++i)
    {
        workDataStructures= new workData;
        workDataStructures->name=nameList[i]->text();
        workDataStructures->dependence=dependList[i]->getDisplayText();
        workDataStructures->time=timeList[i]->text().toInt();
        workList.append(workDataStructures);
    }

    graph* graph_= new graph(workList, this);
    graph_->show();

}
