#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "player.h"
#include "enemy1.h"
#include "enemy2.h"
#include "bullet.h"
#include "sound.h"
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
#include<QWidget>
#include<QPushButton>
#include<button.h>
#include<QGraphicsTextItem>
#include<fstream>
#include<sound.h>
#include<enemy3_boss.h>
#include<QLineEdit>
#include <login_page.h>

using namespace std;



class GameManager:public QGraphicsView
{
    Q_OBJECT
    // dimentions
    const int w=1300;
    const int h=700;
    const int r=18;
    const int c=36;
    // array to store the data
    int **arr;
    // timers
    QTimer *timer; // game over checker
    QTimer *timer2; // the last stage checker
    QTimer *timer3; //win checker
    QTimer *timer4; //health checker
    QTimer *timer5; //market checker
    QTimer *timer6;// coins checker
    QTimer *timer7;// delete coins

    QGraphicsPixmapItem pictures[18][36]; // 2d array to display boards
    QGraphicsPixmapItem *q; // to display images ( win and game over)
    QGraphicsPixmapItem *shop_image; // image for shop
    QGraphicsPixmapItem *players_image; // image for the player shop
    QGraphicsPixmapItem *bullet_image; // bullet shop
    QGraphicsPixmapItem *coin_image; // for display coin at the top
    QGraphicsScene scene; // it is the scene
    Button* Playagain; // button to play again
    Button* exit_button; //button to exit
    Sound* background_music; // the back grpund music
    Sound* gameOver;// music
    Sound* win;// music
    Sound* small_win; // when finsh any room
    Sound* on_off; // music off and on
    QPushButton *sound;
    QGraphicsTextItem* titleText; //for dispaly the player's health
    QGraphicsTextItem* coinText; // for display number of coins
    bool static Muted_Music; // to mute all the music used

    Button* close_button; // to close
    Button* speed_button;// to increas the speed of the bullet (shop)
    Button* player_button; // to open players' shop
    Button* bullet_button; // to open bullet' shop
    Button* health_button; // to increase player's health

    Button* buy_button1; // buy the first player( can walk on bricks)
    Button* buy_button2;// buy the second player ( it is just another image for player)
    Button* buy_button3; //buy the third player ( it is just another image for player)

    Button* buy_bullet1; // buy the first bullet ( the player fire 2 bullets)
    Button* buy_bullet2; // buy the second bullet ( can move on bricks)
    Button* buy_bullet3;// buy the third bullet ( it is just another image for bullet fire)
    bool shop_is_open=0; // now the shop is not open

    bool monster_stage_open=0; // now the boss is not created yet
    bool win_page_open=0; // now the player dose not win or lose the game is on


    bool static open;

    bool is_player_shop_open=0; // palyer's shop is not open
    bool is_bullet_shop_open=0; // bullet's shop is not open


public:

    GameManager();

    void create_player(); // create and dispaly players
    void create_enemies(); // to create and dispaly enemies
    void create_health(); // to create and dispaly helath
    void create_board(); // to create and display the board
    //void create_board2();
    void create_menu(); // to create and display the startint menu
    void init_table(QString); // initialize the array with the table
    void draw_enemyhealth(); // dispaly and create the health of the last boss
    static bool getMute_Music();    //store the value of on/off to be used in the whole game
    void static set_open(bool); //to know whether the shop of open or not from anywhere outside the class
    void player_focus(); // to return the focus on the player again after colsing the shop as we will click on the other items
    void log_in();// log in window to validate the users



    public slots:
        void start();// start the game
        void game_over(); // dispaly the game over page
        void restart(); // to delete all the items from the scene and return all the values to thier default
        //, coins to 100, player to type 0 and bullet to type 0, enemy1 and enemy2 to 4, health of boss to 4, palyer health to 4 and...
        void Sound_Clicked(); // to make the music on or off
        void Win_Game(); // to dispaly the win page after the number of enemies one and two become 0 and the last boss' health become 0
        void Monester_Stage(); // display the boss and delete
        void Delete_All(); // to return all the memories to the heap
        void change_health(); // to change the number of player's health  after death
        void Shop_page(); // display the shop page
        void Shop_page_close(); // close the shop page
        void Shop_page_players_close(); // close the players' shop page
        void Shop_page_bullets_close();// close the bullets' shop page
        //void keyPressEvent(QKeyEvent* event);
        void buy_player(); // open players' shop page
        void player1(); // buy player 1
        void player2();// buy player 2
        void player3();// buy player 3
        void shop_display();
        void bullet_speed();// increase bullet speed
        void buy_health(); // increase player's health
        void buy_bullet(); // open bullet's page
        void bullet1();  // buy bullet1
        void bullet2();// buy bullet 2
        void bullet3();// buy bullet 3
        void create_coins(); // dispaly the number of the coins at the top of the page
        void delete_coins();
};

#endif // GAMEMANAGER_H
