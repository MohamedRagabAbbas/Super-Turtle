#include "bullet.h"

Bullet::Bullet(int d)
{
    direction=d;
    QPixmap v(left); // to conncet the image of the ball with the bullet
    v=v.scaled(size,size);
    setPixmap(v);
    // read for the file(table)
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
    small_win=new Sound; // music is played when the player manage to kill the enemies in each room

    // inorder to make the bullet move until touch any barriers
    QTimer *timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(speed);// its speed



}
void Bullet::move()
{
    // collision with enemies
        QList<QGraphicsItem*> collision = collidingItems(); // all the items in the scene
        int size=collision.size();
        for (int i = 0; i < size; i++){
            if (typeid(*(collision[i])) == typeid(Enemy1)||typeid(*(collision[i])) == typeid(Enemy2)||typeid(*(collision[i])) == typeid(enemy3_Boss))
            {

               if(typeid(*(collision[i])) == typeid(Enemy1)) // is the collision with Enemy1
                    Enemy1::decline(); // reduce its number
               else if(typeid(*(collision[i])) == typeid(Enemy2))// is the collision with Enemy2
                    Enemy2::decline();// reduce its number
               else if(typeid(*(collision[i])) == typeid(enemy3_Boss))// is the collision with Enemy2
                    {

                        if(Health_enemy::get_number()>0)
                        {
                            Health_enemy::decrease();// reduce its number
                            QList<QGraphicsItem*> heart = scene()->items(); // remove one white heart from the screen
                            int size=heart.size();
                            for (int i = 0; i < size; i++){
                                if (typeid(*(heart[i])) == typeid(Health_enemy))
                                {scene()->removeItem(heart[i]); break;}
                            }
                            scene()->removeItem(this);
                            delete this;
                            return;
                        }
                     }

                //scene()->removeItem(collision[i]); // remover the either emeny1 or enemy2
                scene()->removeItem(this); // remove the bullet

                delete collision[i]; // return the memory to the heep
                delete this;

                SLOT(NULL);

                 // to check whether it is the first time or not
                int static i=0;
                int static k=0;
                if(Enemy1::get()==2&&Enemy2::get()==4&&i==0) // i=0 means that it is the first time
                {
                    if(GameManager::getMute_Music()==false)
                        small_win->Music_Win(); // room 1 is finished
                    i++;// change the value of i to stop executing the condition
                    k=0;
                }
               // cout<<"Iam hear number of enemy 2 is"<<Enemy2::get()<<endl;

                if(Enemy2::get()==2&&k==0)// the same
                {
                    if(GameManager::getMute_Music()==false)
                        small_win->Music_Win(); //room 1 is finished
                    k++;
                    i=0;
                }

               if (Enemy1::get()<2||Enemy2::get()<2)// to enter the condition again after playing again
                {
                    i=0;
                    k=0;
                }

                return;
            }
        }
     // if there is no collision
        //-1 is a outer brick
        // 6 is a inner brick in room 1
        // 8 is an inner brick in room 2
        // 4 is an inner brick in room 3

        // 5 is gate1
        // 10 is gate 2
        // 15 is gate 3
    int m=6,m2=4,m3=8; // 3 types of bricks 
        if(type==2){ 
            // different type of bullets that will pass through bricks 
            m=1;
            m2=1;
            m3=1;
        }
        if(type==1)
            size=35;
        else
            size=20;
    if(data[int(y()-26)/35][int(x())/35]<0||data[int(y()-26)/35][int(x())/35]== m||data[int(y()-26)/35][int(x())/35]== m2||data[int(y()-26)/35][int(x())/35]== m3||data[int(y()-26)/35][int(x())/35]== 5||data[int(y()-26)/35][int(x())/35]== 10||data[int(y()-26)/35][int(x())/35]== 15)// if it touch any barriers, remove bullet
    {
        delete this;
        //scene()->removeItem(this);
        SLOT(NULL);
        return;
    }
    // move in the same direction of the player
    if(direction==0) //up
    {
        setPos(x(),y()-35);

        QPixmap p(up);
        p=p.scaled(size,size);
        this->setPixmap(p);
    }
    else if(direction==1)//down
    {

        setPos(x(),y()+35);

        QPixmap p(down);
        p=p.scaled(size,size);
        this->setPixmap(p);
    }
    else if(direction==2)//left
    {
        setPos(x()-35,y());

        QPixmap p(left);
        p=p.scaled(size,size);
        this->setPixmap(p);
    }
    else if(direction==3)//right

    {
        setPos(x()+35,y());

        QPixmap p(right);
        p=p.scaled(size,size);
        this->setPixmap(p);
    }
}
bool Bullet::increase_speed()
{
    if(speed>20)
    {
        speed-=20;
        return true;
    }
    return false;
}
void Bullet::bullet_image(int option) // resect to the ball bullet or others from the market 
{
    type=option;
    if(option==1)
    {
        right="bullet1_right.png";
        left="bullet1_left.png";
        up="bullet1_up.png";
        down="bullet1_down.png";
    }
    else if(option==2)
    {
        right="bullet2_right.png";
        left="bullet2_left.png";
        up="bullet2_up.png";
        down="bullet2_down.png";
    }
    else if(option==3)
    {
        right="bullet3.png";
        left="bullet3.png";
        up="bullet3.png";
        down="bullet3.png";
    }
    else if(option==0) //default shape 
    {
        left="ball.png";
        right="ball.png";
        up="ball.png";
        down="ball.png";
    }
}
int Bullet::speed=100;
QString Bullet::left="ball.png";
QString Bullet::right="ball.png";
QString Bullet::up="ball.png";
QString Bullet::down="ball.png";
int Bullet:: type=0;

int Bullet::get_type() //return bullet type 
{
    return type;
}
void Bullet::returnspeed()// bullet speed
{
    speed=100;
}
