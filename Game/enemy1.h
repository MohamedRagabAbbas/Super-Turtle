 #ifndef ENEMY1_H
#define ENEMY1_H

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
#include<bullet.h>
#include<fire.h>
#include<sound.h>
#include<coins.h>

class Enemy1:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    int row;
    int column;
    int data[18][36]; // to store the data of the table
    int x,y;
    int begin,end; // To determine in which room the enemy will be created
    int ra=rand()%4; // to move in a random direction
    int static number; // to know the number of enemies alive from outside of the class without creating a new object
    int last_move=3; // to direct the fire initialized to 3 to solve the problem of static fire
    Sound* lose; // sound when the player is losing
public:

    Enemy1(int,int,int=0,int=0);
    void static decline(); // to reduce the number of enemies
    int static get(); // to return the number of enemies alive
    void static increase();// to increase the number of enemeies
    ~Enemy1();
public slots:
    void move();

};

#endif // ENEMY1_H
