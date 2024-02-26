#include "fire.h"
#include<gamemanager.h>
Fire::Fire(int d, int o, int s)
{
    direction=d;
    option=o;
    spead=s;
    QPixmap v("fireball.png");// to conncet the image of the fire ball  with the fire object
    v=v.scaled(20,20);
    setPixmap(v);
    // read from the file ( table)
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

    // move forever, untill find barriers
    QTimer *timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(spead);

    lose=new Sound; // music when the player is losing

}

void Fire::move()
{
    // collision with the player
    QList<QGraphicsItem*> collision = collidingItems();
    int size=collision.size();
    for (int i = 0; i < size; i++)
    {
        if (typeid(*(collision[i])) == typeid(Player)&&(Health::get_number()==1))//collision with player and number of hearts is one

        {
                Health::decrease();//redyce the number of hearts
                collision[i]->clearFocus(); // clear player's focus
                scene()->removeItem(collision[i]); // remove both player and fire as the number of health is 0
                scene()->removeItem(this);
                delete collision[i];
                delete this;
                SLOT(NULL);
                return;
         }

         else if (typeid(*(collision[i])) == typeid(Player)) //collision with player and number of hearts is not one
        {
            if(GameManager::getMute_Music()==false)
                lose->Music_Lose(); // music to indicate thet the number of health is decreasing
            Health::decrease(); // reduce number of hearts
            collision[i]->setPos(35,85);
            Player::set_row(1);
            Player::set_column(1);
            QList<QGraphicsItem*> heart = scene()->items(); // remove one heart from the screen
            int size=heart.size();
            for (int i = 0; i < size; i++){
                if (typeid(*(heart[i])) == typeid(Health))
                {scene()->removeItem(heart[i]); break;}
            }
            scene()->removeItem(this); // remove only the fire
            delete this;

            // note that player is still exist as the number of health is not 0
            return;
        }
    }

    // to determine whether it should go through the inner bricks or not
    int m=6,m2=4,m3=8; // inner brick is equal to 6,4,8 in the table
    if(option==1)// if the caller is enemy2 change the value of m, in order not to match the value(6) in the table
    {m=9;
     m2=9;
     m3=9;}


    // m=6,4,8 is a inner bricks
    //-1 is a outer brick
    // 5 is gate1
    // 10 is gate 2
    // 15 is gate 3

    if(data[int(y()-26)/35][int(x())/35]<0||data[int(y()-26)/35][int(x())/35]== m||data[int(y()-26)/35][int(x())/35]== m2||data[int(y()-26)/35][int(x())/35]== m3||data[int(y()-26)/35][int(x())/35]== 5||data[int(y()-26)/35][int(x())/35]== 10||data[int(y()-26)/35][int(x())/35]== 15)// if it touch any barriers, remove fire
    {
        delete this;
        //scene()->removeItem(this);
        SLOT(NULL);
        return;
    }
    // move in the same direction of the player
    if(direction==0)
        setPos(x()+35,y());
    else if(direction==1)
        setPos(x(),y()+35);
    else if(direction==2)
        setPos(x(),y()-35);
    else if(direction==3)
        setPos(x()-35,y());
}



