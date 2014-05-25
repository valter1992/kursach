#include "graph.h"
#include "ui_graph.h"
#include <qwt_plot_grid.h>
#include <qwt_plot_magnifier.h>
#include <qwt_plot_panner.h>
#include <qwt_plot_curve.h>
#include <qwt_symbol.h>
#include <qwt_legend.h>
#include <QDebug>

graph::graph(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::graph)
{
    ui->setupUi(this);
    //сетка
    QwtPlotGrid *grid = new QwtPlotGrid(); //
    grid->setMajorPen(QPen( Qt::gray, 2 )); // цвет линий и толщина
    grid->attach( ui->qwtPlot ); // добавить сетку к полю графика
}

graph::graph(QVector<workData *> workList, QWidget *parent)
    :
      QMainWindow(parent),
      ui(new Ui::graph)
{
    ui->setupUi(this);

    QwtPlotGrid *grid = new QwtPlotGrid(); //
    grid->setMajorPen(QPen( Qt::gray, 2 )); // цвет линий и толщина
    grid->attach( ui->qwtPlot ); // добавить сетку к полю графика

    // Включить возможность приближения/удаления графика
    // #include <qwt_plot_magnifier.h>
    QwtPlotMagnifier *magnifier = new QwtPlotMagnifier(ui->qwtPlot->canvas());
    // клавиша, активирующая приближение/удаление
    magnifier->setMouseButton(Qt::MidButton);

    // Включить возможность перемещения по графику
    // #include <qwt_plot_panner.h>
    QwtPlotPanner *d_panner = new QwtPlotPanner( ui->qwtPlot->canvas() );
    // клавиша, активирующая перемещение
    d_panner->setMouseButton( Qt::RightButton );

    // Кривая
    //#include <qwt_plot_curve.h>
    QwtPlotCurve *curve;


    QwtLegend *legend = new QwtLegend();
//       legend->setItemMode(QwtLegend::ReadOnlyItem);
    legend->setDefaultItemMode(QwtLegendData::Checkable);
//       ui->qwtPlot->insertLegend(legend, QwtPlot::TopLegend);

    drawWorkList= new drawWork[workList.count()];

    QPolygonF points;


    QwtSymbol *symbol;

    int count=0;
    for(int i=0; i< workList.count(); ++i)
    {
        drawWorkList[i].work=workList[i];
        drawWorkList[i].point=QPoint(0,0);
        if (workList[i]->dependence=="")
        {
            curve = new QwtPlotCurve(QString("U1(t)"));
            curve->setPen( Qt::black, 2 ); // цвет и толщина кривой
            curve->setRenderHint
                    ( QwtPlotItem::RenderAntialiased, true ); // сглаживание

            points << QPointF( 0,0) // координаты x, y
                   << QPointF( (double)workList[i]->time,20*count);
            drawWorkList[i].point=QPoint(workList[i]->time,20*count);
            curve->setSamples( points ); // ассоциировать набор точек с кривой
            curve->attach( ui->qwtPlot ); // отобразить кривую на графике

            symbol = new QwtSymbol( QwtSymbol::Ellipse,
                                    QBrush( Qt::yellow ), QPen( Qt::red, 2 ), QSize( 8, 8 ) );
            curve->setSymbol( symbol );

            ++count;
        }

    }
    QStringList tmpList;
    QPoint tmpPoint;
    bool accept=false;
    bool check=true;
    while(check)
    {
        count=0;
        check=false;
        for(int i=0; i< workList.count(); ++i)
        {
            if(drawWorkList[i].point==QPoint(0,0))
            {
                qDebug()<<"zavisit"<<drawWorkList[i].work->name;
                tmpList= drawWorkList[i].work->dependence.split(",");
                accept=true;
                tmpPoint=drawWorkList[i].point;
                foreach (QString tmpString, tmpList) {
//                    qDebug()<<"digValue"<<tmpString[1].digitValue();
                    if(drawWorkList[tmpString[1].digitValue()-1].point==QPoint(0,0))
                    {
                        accept=false;
                    }
                    else
                    {
//                        qDebug()<<"point se"<<drawWorkList[tmpString[1].digitValue()].point;
                        if(drawWorkList[tmpString[1].digitValue()-1].point.x()>tmpPoint.x() )
                            tmpPoint=drawWorkList[tmpString[1].digitValue()-1].point;
                        ++count;

                    }

                }
                if(accept)
                {
                    curve = new QwtPlotCurve(QString("U1(t)"));
                    curve->setPen( Qt::black, 2 ); // цвет и толщина кривой
                    curve->setRenderHint
                            ( QwtPlotItem::RenderAntialiased, true ); // сглаживание
                    points.clear();
                    points << QPointF( tmpPoint) // координаты x, y
                           << QPointF( (double) (tmpPoint.x() + workList[i]->time),20*count);
                    drawWorkList[i].point=QPoint(( tmpPoint.x() + workList[i]->time),20*count);
                    curve->setSamples( points ); // ассоциировать набор точек с кривой
                    curve->attach( ui->qwtPlot ); // отобразить кривую на графике

                    symbol = new QwtSymbol( QwtSymbol::Ellipse,
                                            QBrush( Qt::yellow ), QPen( Qt::red, 2 ), QSize( 8, 8 ) );
                    curve->setSymbol( symbol );

                    check=true;

                }
            }
        }
    }




}

graph::~graph()
{   ui->qwtPlot->deleteLater();
    delete ui;
}
