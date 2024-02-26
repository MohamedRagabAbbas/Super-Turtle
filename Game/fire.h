#ifndef FIRE_H
#define FIRE_H

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
#include<player.h>
#include <QGraphicsItem>
#include <gamemanager.h>
#include "sound.h"

class Fire:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    int row;
    int column;
    int data[18][36]; // store the data of the table to be able to delete the bullet when touching any barriers
    int direction;
    int option; // to determine whether it should be deleted after touching the inner bricks or not
    int spead; // the fire's spead

    Sound* lose; // music when the fire hit the player
public:
    Fire(int,int,int);
public slots:
    void move();
};

#endif // FIRE_H
