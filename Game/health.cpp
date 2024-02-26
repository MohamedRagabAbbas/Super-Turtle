#include "health.h"

Health::Health(int x, int y)
{

    QPixmap h("heart.png"); // to conncet the image of the heart with the health object
    h=h.scaled(25,25);
    setPixmap(h);
    setPos(x, y);
}
Health::Health(){}
void Health:: increase() // increase the number of hearts
{
    number_heart++;
}
void Health:: decrease()// reduce the number of hearts
{
    number_heart--;
    //control()
}

int Health::get_number()// return the number of hearts
{
    return number_heart;
}
void Health::set_number(int n) // change the number of hearts
{
    number_heart=n;
}


int Health::number_heart=4;
