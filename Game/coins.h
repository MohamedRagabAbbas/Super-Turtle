#ifndef COINS_H
#define COINS_H
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
#include<enemy1.h>
#include<enemy2.h>
#include<enemy3_boss.h>
#include<sound.h>
#include<health_enemy.h>

class coins: public QGraphicsPixmapItem
{
    int static number_coins; // static to be viewed anywhere outside the class


public:

    coins();
    void static increase(); // increase the number of coins
    void static decrease(int);// reduce the number of coins
    int  static get_number(); // return the number of coins
    void static set_number(int); // change the number of coins
};

#endif // COINS_H
