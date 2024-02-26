#include "player.h"
#include "enemy1.h"
#include "enemy2.h"
#include "bullet.h"
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
#include<QScrollBar>
#include<health.h>
#include<QBrush>
//#include <QMediaPlayer>
#include<QWidget>
#include<QPushButton>
#include<button.h>
#include<QGraphicsTextItem>
#include<gamemanager.h>



GameManager* game;
using namespace std;

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    srand(time(NULL));


    game =new GameManager;
    game->show();
    game->create_menu();


    return a.exec();
}
