#ifndef GRAPH_H
#define GRAPH_H

#include <QMainWindow>

namespace Ui {
class graph;
}

class graph : public QMainWindow
{
    Q_OBJECT

public:
    explicit graph(QWidget *parent = 0);
    ~graph();

private:
    Ui::graph *ui;
};

#endif // GRAPH_H
