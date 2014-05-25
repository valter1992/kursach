#ifndef GRAPH_H
#define GRAPH_H

#include <QMainWindow>
#include "structures.h"

namespace Ui {
class graph;
}

class graph : public QMainWindow
{
    Q_OBJECT

public:
    explicit graph(QWidget *parent = 0);
    explicit graph(QVector<workData*> workList, QWidget *parent = 0);

    drawWork *drawWorkList;



    ~graph();

private:
    Ui::graph *ui;
};

#endif // GRAPH_H
