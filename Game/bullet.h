#ifndef BULLET_H
#define BULLET_H

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
#include<sound.h>
#include<health_enemy.h>

class Bullet:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    int row;
    int column;
    int data[18][36]; // store the data of the table to be able to delete the bullet when touching any barriers
    int direction;
    Sound* small_win; // music is played when the player manage to kill the enemies in each room
    int condition=0;
    int static speed;

    QString static left;
    QString static right;
    QString static up;
    QString static down;

    int static type;
    int block=6;
    int size=20;

public:
    Bullet(int);
    bool static increase_speed();
    void static bullet_image(int=0);
    int static get_type();
    void static returnspeed();
public slots:
    void move();
};

#endif // BULLET_H
