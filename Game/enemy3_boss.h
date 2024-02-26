#ifndef ENEMY3_BOSS_H
#define ENEMY3_BOSS_H

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
#include <utility>
#include<bullet.h>
#include<sound.h>
#include<health_enemy.h>
#include <set>
#include <utility>
#include<stack>
#include <stdio.h>
#include <limits.h>
#include <stdint.h>
#include <player.h>
using namespace std;

//pair<int, int> p ;

typedef pair<int, int> Pair;
typedef pair<int, pair<int, int>> pPair;

#define ROW 18
#define COL 36
#define INF 9999

class enemy3_Boss:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

    int data[18][36]; // to store the data of the table// To determine in which room the enemy will be created
    int ra=rand()%4;// to move in a random direction
    int last_move=3; // to direct the fire
    Sound* lose; // sound when the player is losing
    struct  cell  //usied in A_star
    { // 0<=i<r && 0<=j <Col

        int parent_i, parent_j;
        float f, g, h; // f=g+h
    };
    pair<int,int>bossPosition;
    stack<Pair> bossPath;

    static int row;
    static int column;
    Pair playerPosition;
    int player_last_move_row;
    int player_last_move_col;
    QTimer *timer;
    QTimer *timer2;
    QTimer *timer3;
    cell cellDetails[ROW][COL];
    bool closedList[ROW][COL];
    set<pPair> openList;//lesa
public:

    enemy3_Boss();

    bool inRange(int r, int col);
    bool isBlock( int r, int col);
    bool ReachDestination(int r, int col, Pair dest);
    int H_Calculation(int r, int col, Pair dest);
    void tracePath( Pair dest);
    void AStar( Pair src, Pair dest);
    void coll();

public slots:
        void move();
        void palyer_mover();
        void create_small_enemies();

};

#endif // ENEMY3_BOSS_H
