#ifndef WORK_H
#define WORK_H

#include <QMainWindow>
#include <QLineEdit>
#include "structures.h"
#include "multilist.h"

namespace Ui {
class Work;
}

class Work : public QMainWindow
{
    Q_OBJECT

public:
    explicit Work(QWidget *parent = 0);
    explicit Work(int countWork, QWidget *parent = 0);
    ~Work();

    QVector<workData*> workList;
    QVector<QLineEdit*>nameList;
    QVector<MultiListWidget*>dependList;
    QVector<QLineEdit*>timeList;



private slots:
    void on_pushButton_clicked();

private:
    Ui::Work *ui;
};

#endif // WORK_H
