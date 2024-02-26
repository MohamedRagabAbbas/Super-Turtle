#include "health_enemy.h"

Health_enemy::Health_enemy(int x, int y)
{

    QPixmap h("white_heart.png"); // to conncet the image of the heart with the health object
    h=h.scaled(25,25);
    setPixmap(h);
    setPos(x, y);
}
void Health_enemy:: increase() // increase the number of hearts
{
    number_heart++;
}
void Health_enemy:: decrease()// reduce the number of hearts
{
    number_heart--;
    //control()
}

int Health_enemy::get_number()// return the number of hearts
{
    return number_heart;
}
void Health_enemy::set_number(int n) // change the number of hearts
{
    number_heart=n;
}

int Health_enemy::number_heart=4;
