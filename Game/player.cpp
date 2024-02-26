#include "player.h"
#include "bullet.h"


Player::Player()
{


    row=1;        // the default row
    column=1;        // the default column

    QPixmap p(right);  // connect the turtle image with the player
    p=p.scaled(35,35);
    setPixmap(p);
    setPos(0,85);
    //setPos(row*35,35+column*35);    // set  postion

    // read the data of the table
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



    file.close();
    shooting=new Sound;
    lose=new Sound;


}

 void Player::keyPressEvent(QKeyEvent* event)
    {


    //collision bewteen player and enemies
     QList<QGraphicsItem*> collision = collidingItems(); // all the items in the scene
     int size=collision.size(); // their number
     for (int i = 0; i < size; i++)
     {
         if((typeid(*(collision[i])) == typeid(coins)))
                  {
                          coins::increase();
                          scene()->removeItem(collision[i]);
                          delete collision[i];
                          return;
                  }
         else if ((typeid(*(collision[i])) == typeid(Enemy1)||typeid(*(collision[i])) == typeid(Enemy2)||typeid(*(collision[i])) == typeid(enemy3_Boss)||typeid(*(collision[i])) == typeid(Fire))&&(Health::get_number()==1))//collision with enemies and number of hearts is one

         {
                 Health::decrease(); // reduce the number of hearts
                 this->clearFocus(); // remove the player' focus as the number of health now is 0
                 scene()->removeItem(this); // remove it from the scene
                 delete this; // return the memory to the heap
                 SLOT(NULL);
                 return;
          }

          else if (typeid(*(collision[i])) == typeid(Enemy1)||typeid(*(collision[i])) == typeid(Enemy2)||typeid(*(collision[i])) == typeid(enemy3_Boss)||typeid(*(collision[i])) == typeid(Fire)) //collision with enemies and number of hearts is not one
         {
                 setPos(35,85);
                 row=1;
                 column=1;
                 if(GameManager::getMute_Music()==false)
                     lose->Music_Lose();
                 Health::decrease(); // reduce number of hearts
                 QList<QGraphicsItem*> heart = scene()->items(); // remove one heart from the screen
                 int size=heart.size();
                 for (int i = 0; i < size; i++){
                     if (typeid(*(heart[i])) == typeid(Health)) // remove a heard from the scene
                     {scene()->removeItem(heart[i]); break;}
                 }
                 // the player is still exists
                 return;
         }
     }


     // if the number of enemies of the first type are two, this means that all enemies of the first room are killed
     if(Enemy1::get()==2) // to allow moving above the gate1
     {
         gate1=1;// change the cell number(gate1)
     }

     if(Enemy2::get()==2)// to allow moving above the gate2
     {
         gate2=1;
     }
     if(Enemy2::get()==0&&Enemy1::get()==0)// to allow moving above the gate2
     {
         gate3=1;
     }
     if(type==1)
     {
         block=1;
         block2=1;
         block3=1;

     }
     else
     {
         block=6;
         block2=8;
         block3=4;
     }

     // -1 is a outer brick
     // 6 is a inner brick

          // movement is up
        if(event->key()==Qt::Key_Up&&data[row-1][column]>-1&&data[row-1][column]!=gate1&&data[row-1][column]!=gate2&&data[row-1][column]!=gate3&&data[row-1][column]!=block&&data[row-1][column]!=block2&&data[row-1][column]!=block3)
        {
            row--; //go to the above row
            setPos(35*column,50+35*row);
            QPixmap p(up); // inorder to change the image of the player to be rotated_up
            p=p.scaled(35,35);
            this->setPixmap(p);
            last_move=0; // store the last movemen

        }
        // movement is down
        else if(event->key()==Qt::Key_Down&&data[row+1][column]>-1&&data[row+1][column]!=gate1&&data[row+1][column]!=gate2&&data[row+1][column]!=gate3&&data[row+1][column]!=block&&data[row+1][column]!=block2&&data[row+1][column]!=block3)
        {
            row++;
            setPos(35*column,50+35*row);
            QPixmap p(down);
            p=p.scaled(35,35);
            this->setPixmap(p);
            last_move=1;
        }
        // movement is left
        else if(event->key()==Qt::Key_Left&&data[row][column-1]>-1&&data[row][column-1]!=gate1&&data[row][column-1]!=gate2&&data[row][column-1]!=gate3&&data[row][column-1]!=block&&data[row][column-1]!=block2&&data[row][column-1]!=block3)
        {
            column--;
            setPos(35*column,50+35*row);
            QPixmap p(left);
            p=p.scaled(35,35);
            this->setPixmap(p);
            last_move=2;
        }
        // movement is right
        else if(event->key()==Qt::Key_Right&&data[row][column+1]>-1&&data[row][column+1]!=gate1&&data[row][column+1]!=gate2&&data[row][column+1]!=gate3&&data[row][column+1]!=block&&data[row][column+1]!=block2&&data[row][column+1]!=block3)
        {

            column++;
            setPos(35*column,50+35*row);
            QPixmap p(right);
            p=p.scaled(35,35);
            this->setPixmap(p);
            last_move=3;
           if(Enemy1::get()==0&&Enemy2::get()==0&&data[row][column]==15)
               last_stage2= true;

        }
        // fire a bullet
        else if (event->key() == Qt::Key_Space)
        {

            // create a bullet
            Bullet * b = new Bullet(last_move); //"last_move" to direct it
            if(GameManager::getMute_Music()==false)
                 shooting->Music_Shooting();
            b->setPos(x()+5,y()+5);
            scene()->addItem(b);
            if(Bullet::get_type()==1)
            {
                Bullet * b = new Bullet(last_move); //"last_move" to direct it
                if(GameManager::getMute_Music()==false)
                     shooting->Music_Shooting();
                b->setPos(x()+5,y()+5);
                scene()->addItem(b);
            }
        }
        else if(event->key()==Qt::Key_Shift)
            GameManager::set_open(1);

    }


bool Player::get()
{
    return last_stage;
}
bool Player::set(bool c)
{
    last_stage=c;
}


bool Player::last_stage= false; // player is not in the last stage
bool Player::last_stage2= false;

void Player::set_row(int r){row =r;}
void Player::set_column(int r){column =r;}
int Player::row=1;
int Player::column=1;

bool Player::get_last_stage()
{
    return last_stage2;
}
void Player::set_last_stage(bool s)
{
    last_stage2=s;
}

void Player::player_image(int option)
{

    if(option==1)
    {
        type=1;
        right="player1_right.png";
        left="player1_left.png";
        up="player1_up.png";
        down="player1_down.png";
    }
    else if(option==2)
    {
        type=2;
        right="player2_right.png";
        left="player2_left.png";
        up="player2_up.png";
        down="player2_down.png";
    }
    else if(option==3)
    {
        type=3;
        right="player3_right.png";
        left="player3_left.png";
        up="player3_up.png";
        down="player3_down.png";
    }
    if(option==0)
    {
        type=0;
        left="turtle_left.png";
        right="turtle_right.png";
        up="turtle_up.png";
        down="turtle_down.png";
    }
}
int Player::get_row()
{
    return row;
}
int Player::get_col()
{
    return column;
}
int Player:: type;
QString Player::left="turtle_left.png";
QString Player::right="turtle_right.png";
QString Player::up="turtle_up.png";
QString Player::down="turtle_down.png";






