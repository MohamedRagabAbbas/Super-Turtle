#include "coins.h"

coins::coins()
{

    QPixmap h("coin.png"); // to conncet the image of the coins with the coin object
    h=h.scaled(20,20);
    setPixmap(h);
    setPos(x(), y());



}
void coins:: increase() // increase the number of coins
{
    number_coins += 50;
}
void coins:: decrease(int x = 50)// reduce the number of coins
{
    number_coins -= x;
    //control()
}


int coins::get_number()// return the number of coins
{
    return number_coins;
}
void coins::set_number(int n) // change the number of coins
{
    number_coins=n;
}

/*void coins::show_the_coin()
{
    int x,y; //for storing the random place that the coin will be put in

    if(Enemy1::get() > 2)
    {
        int x = rand()%1300;
        int y = rand()%700;
        coins(x,y);
    }
    else if (Enemy1::get() == 2)
    {
        int x = rand()%1300;
        int y = rand()%700;
        coins(x,y);
    }
    else if(Enemy2::get() == 2)
    {
        int x = rand()%1300;
        int y = rand()%700;
        coins(x,y);
    }
}*/


int coins::number_coins= 100 ;
