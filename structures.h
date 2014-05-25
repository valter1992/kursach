#ifndef STRUCTURES_H
#define STRUCTURES_H
#include <QString>

struct workData
{

    QString name;
    QString dependence;
    int time;

};

struct drawWork
{

    workData* work;
    QPoint point;

};


#endif // STRUCTURES_H
