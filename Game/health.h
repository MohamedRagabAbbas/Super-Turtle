#ifndef HEALTH_H
#define HEALTH_H

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QFile>
#include <QTextStream>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<iostream>
#include <QTimer>
#include <QGraphicsRectItem>
#include <QObject>
#include<QList>


class Health:public QGraphicsPixmapItem
{
    int static number_heart;

public:

    Health(int, int);
    void static increase(); // increase the number of hearts
    void static decrease();// reduce the number of hearts
    int  static get_number(); // return the number of hearts
    void static set_number(int); // change the number of hearts
    Health();

};

#endif // HEALTH_H
