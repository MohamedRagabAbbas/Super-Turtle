#include "enemy2.h"

Enemy2::Enemy2(int b, int e, int pos_x,int pos_y)
{
    begin=b; // the left boundary
    end=e; // the right boundary

    QPixmap v("monster_left.png"); // to coonect the image of the spider with the emeny1
    v=v.scaled(35,35);
    setPixmap(v);

    //read from the file
    QFile file("table.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);
    QString read;
    for(int i=0;i<18;i++)
    {
        for(int j=0;j<36;j++)
        {
            stream>>read;
            data[i][j]=read.toInt();
        }
    }

    // to avoid creating an enemy above the barriers
    while(true) // loop untle to find empty cell
    {
        row= rand()%7+5;
        column= rand()%e+b;
        if(data[row][column]==-1)
            continue;
        break;
    }

    if(pos_x!=0&&pos_y!=0)
    {
        x=pos_x;
        y=pos_y;
        column=x/35;
        row=(y-50)/35;
    }
    else
    {
        x=column*35;
        y=50+row*35;
    }
    setPos(x,y);

    // inorder to make the enemy move forever
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(350);//its speed



    lose=new Sound; // sound when the player is losing
}

void Enemy2::decline(){number--;}// reduce the number of enemy
int Enemy2::get(){return number;}// return the number of enemy
void Enemy2::increase(){number++;} // increase the number of enemy
void Enemy2::move()
{
    // collision with player
    QList<QGraphicsItem*> collision = collidingItems();
    int size=collision.size();
    for (int i = 0; i < size; i++)
    {
        if (typeid(*(collision[i])) == typeid(Player)&&(Health::get_number()==1))//collision with player and number of hearts is one

        {
                Health::decrease(); // reduce the number of hearts
                collision[i]->clearFocus(); // clear the focus of the player as the number of health is 0
                scene()->removeItem(collision[i]); // remove player
                delete collision[i];
                SLOT(NULL);
                return;
         }

         else if (typeid(*(collision[i])) == typeid(Player)) //collision with player and number of hearts is not one
        {
                collision[i]->setPos(35,85);
                Player::set_row(1);
                Player::set_column(1);
                if(GameManager::getMute_Music()==false)
                    lose->Music_Lose();
                Health::decrease(); // reduce number of hearts
                // remove one heart from the screen
                QList<QGraphicsItem*> heart = scene()->items();
                int size=heart.size();
                for (int i = 0; i < size; i++){
                    if (typeid(*(heart[i])) == typeid(Health))
                    {scene()->removeItem(heart[i]); break;}
                }
                // player is still exist in the scene as the number of health is not 0
                return;
        }
        else if (typeid(*(collision[i])) == typeid(Bullet))
        {
                this->clearFocus();
                delete this;
                Enemy2::decline();
                delete collision[i];
                SLOT(NULL);
                return;
         }
    }



    // it will move until finding any barriers or move five steps then change the direction
    //-1 is a outer brick
    // 5 is gate1
    // 10 is gate 2
    // 15 is gate3

    int static c=0; // changing the direction each five steps
    if(c%5==0)
        ra=rand()%4;
    c++;

//conditions to prevent enemy 2 from moving on gates and outer bricks 
    if(ra==0&&data[row][column+1]>-1&&data[row][column+1]!=5&&data[row][column+1]!=10&&data[row][column+1]!=15)
    {
        x=x+35;
        column++;
        setPos(x,y);
        QPixmap p("monster_right.png");// to change the image to be suitable for the new direction
        p=p.scaled(35,35);
        this->setPixmap(p);
        last_move=0; // store the last move
    }
    else if(ra==1&&data[row+1][column]>-1&&data[row+1][column]!=5&&data[row+1][column]!=10&&data[row+1][column]!=15)
    {
        y=y+35;
        row++;
        setPos(x,y);
        QPixmap p("monster_down.png");
        p=p.scaled(35,35);
        this->setPixmap(p);
        last_move=1;
    }
    else if(ra==2&&data[row-1][column]>-1&&data[row-1][column]!=5&&data[row-1][column]!=10&&data[row-1][column]!=15)
    {
        y=y-35;
        row--;
        setPos(x,y);
        QPixmap p("monster_up.png");
        p=p.scaled(35,35);
        this->setPixmap(p);
        last_move=2;
    }
    else if(ra==3 &&data[row][column-1]>-1&&data[row][column-1]!=5&&data[row][column-1]!=10&&data[row][column-1]!=15)
    {
        x=x-35;
        column--;
        setPos(x,y);
        QPixmap p("monster_left.png");
        p=p.scaled(35,35);
        this->setPixmap(p);
        last_move=3;
    }
    else
        ra=rand()%4;


    // to fire after three momvement
    int static i=0;
    if(i%3==1)
    {
        //create a fire
        Fire * f = new Fire(last_move,1,200);
        f->setPos(x+10,y+10);
        scene()->addItem(f);
    }
    i++;
}
Enemy2::~Enemy2() // when enemy is killed, create a coin 
{


    coins *coin1=new coins();
    scene()->addItem(coin1);
    coin1->setPos(x,y);


    coins *coin2=new coins();
    scene()->addItem(coin2);
    coin2->setPos(x,y);

}
int Enemy2::number=4; // static variable to be shared with all the enemies



