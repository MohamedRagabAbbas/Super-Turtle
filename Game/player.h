#ifndef PLAYER_H
#define PLAYER_H

#include <QFile>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QKeyEvent>

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
#include <enemy1.h>
#include <enemy2.h>
#include <health.h>
#include <sound.h>
#include <gamemanager.h>



class Player:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    int static row;
    int static column;
    int data[18][36]; // to store the data of the table and

    int static type;
    int block=6;
    int block2=8;
    int block3=4;
    int gate1=5;
    int gate2=10;
    int gate3=15;

    int last_move=3;   // to direct the bullet

    int heart;       // number of health available
    Sound* shooting; // music for shooting
    Sound* lose;
    bool static last_stage; // to know form outside the class with out declaring new object that the player is on the last stage or not
     bool static last_stage2;

     QString static left;
     QString static right;
     QString static up;
     QString static down;


public:


    Player(); // default constructor
    bool static get(); // to know whether the player is in the last stage or not
    bool static set(bool); // to change the state of the player form being in the last stage  or not

    void static set_row(int r);
    void static set_column(int r);
    bool static get_last_stage();
    void static set_last_stage(bool);
    void static player_image(int=0);
    //static functions will be used to pass the player's position to the boss class
    int static get_row();
    int static get_col();


public slots:
    void keyPressEvent(QKeyEvent* event); // for movement


};

#endif // PLAYER_H
