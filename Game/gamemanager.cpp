#include "gamemanager.h"

GameManager::GameManager() //constructor
{
    setFixedSize(w,h); // set dimentions
    setWindowTitle("Super Turtle"); // set title
    setScene(&scene); // connect the scene

    arr=new int*[r]; // create 2d array
    for(int i=0;i<r;i++)
        arr[i]=new int[c];


    // music
        background_music=new Sound;
        on_off=new Sound;
        gameOver=new Sound;
        win=new Sound;
        small_win=new Sound;
        background_music->Music_Of_Game();
        sound=new QPushButton(); //initialize sound button


}
void GameManager::log_in() // login window
{
    Login_page l;
    l.setModal(true);
    l.exec(); // display
}
bool GameManager::getMute_Music() // on or off
{
    return Muted_Music;
}

void GameManager::init_table(QString file_name) // read the table whose name is inserted as a parameter and store it into the 2d arry
{
    QFile file(file_name);
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);

    QString read;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            stream>>read;
            arr[i][j]=read.toInt();
        }
    }
    file.close();
}
void GameManager::create_board() //create the 3 rooms
{

     // an array to store the images we used inside
    QPixmap gate("Gate.png");
    QPixmap wall("wall.png");
    QPixmap wall2("wall8");
    QPixmap wall3("wall10.PNG");
    QPixmap blo("Blo.PNG");
    QPixmap pillar("pillar.png");
    QPixmap statue("statue.png");
    QPixmap Background("spacee.png");

    QPixmap pyramids_part1("pyramids_part1.png");
    QPixmap pyramids_part2("pyramids_part2.png");
    QPixmap pyramids_part3("pyramids_part3.png");
    QPixmap pyramids_part4("pyramids_part4.png");

    QPixmap statue_part1("statue_part1.png");
    QPixmap statue_part2("statue_part2.png");
    QPixmap statue_part3("statue_part3.png");
    QPixmap statue_part4("statue_part4.png");

    QPixmap femal_statue_part1("femal_statue_part1.png");
    QPixmap femal_statue_part2("femal_statue_part2.png");
    QPixmap femal_statue_part3("femal_statue_part3.png");
    QPixmap femal_statue_part4("femal_statue_part4.png");

    // to set the width and height for each image(cell)
    gate=gate.scaled(35,35);
    wall=wall.scaled(35,35);
    statue=statue.scaled(35,35);

    Background=Background.scaled(35,35);
    wall2=wall2.scaled(35,35);
    wall3=wall3.scaled(35,35);
    blo=blo.scaled(35,35);
    pillar=pillar.scaled(35,35);

    pyramids_part1=pyramids_part1.scaled(35,35);
    pyramids_part2=pyramids_part2.scaled(35,35);
    pyramids_part3=pyramids_part3.scaled(35,35);
    pyramids_part4=pyramids_part4.scaled(35,35);

    statue_part1=statue_part1.scaled(35,35);
    statue_part2=statue_part2.scaled(35,35);
    statue_part3=statue_part3.scaled(35,35);
    statue_part4=statue_part4.scaled(35,35);

    femal_statue_part1=femal_statue_part1.scaled(35,35);
    femal_statue_part2=femal_statue_part2.scaled(35,35);
    femal_statue_part3=femal_statue_part3.scaled(35,35);
    femal_statue_part4=femal_statue_part4.scaled(35,35);


    for(int i=0;i<r;i++)  // connect each number in the table with the appropriate image
    {
        for(int j=0;j<c;j++)
        {
            if(arr[i][j]==-1)
                pictures[i][j].setPixmap(pillar);
            else if(arr[i][j]==1||arr[i][j]==5||arr[i][j]==10||arr[i][j]==15)
                pictures[i][j].setPixmap(gate);
            else if(arr[i][j]==-2)
                pictures[i][j].setPixmap(statue);


            else if(arr[i][j]==-6)
                pictures[i][j].setPixmap(pyramids_part1);
            else if(arr[i][j]==-7)
                pictures[i][j].setPixmap(pyramids_part2);
            else if(arr[i][j]==-8)
                pictures[i][j].setPixmap(pyramids_part3);
            else if(arr[i][j]==-9)
                pictures[i][j].setPixmap(pyramids_part4);
            else if(arr[i][j]==-11)
                pictures[i][j].setPixmap(statue_part1);
            else if(arr[i][j]==-12)
                pictures[i][j].setPixmap(statue_part2);
            else if(arr[i][j]==-13)
                pictures[i][j].setPixmap(statue_part3);
            else if(arr[i][j]==-14)
                pictures[i][j].setPixmap(statue_part4);
            else if(arr[i][j]==-15)
                pictures[i][j].setPixmap(femal_statue_part1);
            else if(arr[i][j]==-16)
                pictures[i][j].setPixmap(femal_statue_part2);
            else if(arr[i][j]==-17)
                pictures[i][j].setPixmap(femal_statue_part3);
            else if(arr[i][j]==-18)
                pictures[i][j].setPixmap(femal_statue_part4);
            else if(arr[i][j]==6)
                pictures[i][j].setPixmap(wall);
            else if (arr[i][j]==8)
                pictures[i][j].setPixmap(wall2);
            else if (arr[i][j]==4)
                pictures[i][j].setPixmap(wall3);
            else if (arr[i][j]==-3)
                pictures[i][j].setPixmap(blo);

            else
                pictures[i][j].setPixmap(Background);

            pictures[i][j].setPos(j*35,50+i*35);
            scene.addItem(&pictures[i][j]);
        }
    }
}
void GameManager::create_health()// put 4 hearts for player
{
    Health *trial1=new Health(950,25);
    scene.addItem(trial1);

    Health *trial2=new Health(1000,25);
    scene.addItem(trial2);

    Health *trial3=new Health(1050,25);
    scene.addItem(trial3);

    Health *trial4=new Health(1100,25);
    scene.addItem(trial4);

}
void GameManager::draw_enemyhealth() // boss health
{

        Health_enemy *trial1=new Health_enemy(100,25);
        scene.addItem(trial1);

        Health_enemy *trial2=new Health_enemy(150,25);
        scene.addItem(trial2);

        Health_enemy *trial3=new Health_enemy(200,25);
        scene.addItem(trial3);

        Health_enemy *trial4=new Health_enemy(250,25);
        scene.addItem(trial4);

}
void GameManager::create_player()  // the Player
{
    Player* p=new Player();
    scene.addItem(p);

    // focus
    p->setFlag(QGraphicsPixmapItem::ItemIsFocusable);
    p->setFocus();
}
void GameManager::create_enemies()
{
    //room1
    Enemy1 *v1=new Enemy1(0,7);
    Enemy1 *v2=new Enemy1(0,7);
    //room2
    Enemy2 *v3=new Enemy2(9,5);
    Enemy2 *v4=new Enemy2(9,5);
    //room3
    Enemy1 *v5=new Enemy1(20,4);
    Enemy1 *v6=new Enemy1(20,4);
    Enemy2 *v7=new Enemy2(20,4);
    Enemy2 *v8=new Enemy2(20,4);


    // add them to the scene
    scene.addItem(v1);
    scene.addItem(v2);
    scene.addItem(v3);
    scene.addItem(v4);
    scene.addItem(v5);
    scene.addItem(v6);
    scene.addItem(v7);
    scene.addItem(v8);
}
void GameManager::create_menu() //starting menu
{


        // back ground iamge
        q=new QGraphicsPixmapItem;
        QPixmap back_ground("BackGround.jpg");
        back_ground=back_ground.scaled(w,h);
        q->setPixmap(back_ground);
        q->setPos(0,0);
        scene.addItem(q);


        // create the title text
        QGraphicsTextItem* titleText = new QGraphicsTextItem("Super Turtle");
        QFont titleFont("comic sans",35);
        titleText->setFont(titleFont);
        int x = 500;
        int y = 200;
        titleText->setPos(x,y);
        scene.addItem(titleText);

        // create the start button
        Button* start_button = new Button(QString("Start"));
        x = 500;
        y = 300;
        start_button->setPos(x,y);
        connect(start_button,SIGNAL(clicked()),this,SLOT(start()));
        scene.addItem(start_button);

        // create the Music button
        Button* music_button = new Button(QString("Music(ON/OFF)"));
        x = 500;
        y = 400;
        music_button->setPos(x,y);
        connect(music_button,SIGNAL(clicked()),this,SLOT(Sound_Clicked())); //connecting the slot to the button clicked event.
        scene.addItem(music_button);

        // create the Shop button
        Button* shop_button = new Button(QString("Shop"));
        x = 500;
        y = 500;
        shop_button->setPos(x,y);
        connect(shop_button,SIGNAL(clicked()),this,SLOT(Shop_page())); //connecting the slot to the button clicked event.
        scene.addItem(shop_button);


        // create the Exit button
        Button* exit_button = new Button(QString("Quit"));
        x = 500;
        y = 600;
        exit_button->setPos(x,y);
        connect(exit_button,SIGNAL(clicked()),this,SLOT(Delete_All())); // go to the predefined function close()
        scene.addItem(exit_button);

        log_in();



}
void GameManager::Sound_Clicked() // music is on or off
{
        background_music->Toggle_Music();
        Muted_Music=background_music->on_off_music();  //store the state of (ON/OFF Music)

}
void GameManager::start()  // to start the game
{
    int static i=0; // to know whether it is the first time to start the game or button play again is clicked

    QBrush brush(Qt::black);  //back ground collor
    setBackgroundBrush(brush);



    if(i==0) // it is the first time
    {
        scene.clear(); // delete the starting menu

        // coin iamge


        init_table("table.txt"); // table 1
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
                cout<<arr[i][j]<<"  ";
            cout<<endl;
        }
        create_board(); // draw the first board
        i++;

        // game over checker
       timer = new QTimer();
        connect(timer, SIGNAL(timeout()), this, SLOT(game_over()));
        timer->start(350);

        //Monester_Stage checker
        timer2 = new QTimer();
        connect(timer2, SIGNAL(timeout()), this, SLOT(Monester_Stage()));
        timer2->start(350);

        //health checker
        timer4 = new QTimer();
        connect(timer4, SIGNAL(timeout()), this, SLOT(change_health()));
        timer4->start(100);

        //market checker
        timer5 = new QTimer();
        connect(timer5, SIGNAL(timeout()), this, SLOT(shop_display()));
        timer5->start(100);

        //coins checker
        timer6 = new QTimer();
        connect(timer6, SIGNAL(timeout()), this, SLOT(create_coins()));
        timer6->start(100);

        // to delete coins for each 8 second
        timer7 = new QTimer();
        connect(timer7, SIGNAL(timeout()), this, SLOT(delete_coins()));
        timer7->start(8000);

    }
    else // after play again
    {
        while(Enemy1::get()!=4) // number of enemy1 should be 4
        {
            Enemy1::increase();
        }
        while(Enemy2::get()!=4) // number of enemy2 should be 4
        {
            Enemy2::increase();
        }
        while(Health_enemy::get_number()!=4) // number of enemy2 should be 4
        {
            Health_enemy::increase();
        }
        monster_stage_open=0;
        init_table("table.txt"); // store the data of the first table into the 2d array
        create_board(); // draw the first table
    }

    //create player, enemies, and health
    create_player();
    create_enemies();
    create_health();


    // coin iamge
    coin_image=new QGraphicsPixmapItem;
    QPixmap coin("coin_container.png");
    coin=coin.scaled(35,35);
    coin_image->setPixmap(coin);
    coin_image->setPos(700,15);
    scene.addItem(coin_image);

}
void GameManager::game_over() // game over
{
    scene.removeItem(titleText);
    if(Health::get_number()==0)
    {
        Player::set(false);// to force the fire to use the first table

        //number of health should be 4 again
        while(Health::get_number()!=4)
            Health::increase();


        // game over image
        q=new QGraphicsPixmapItem;
        QPixmap back_ground("Game_Over.png");
        if(!getMute_Music())
            gameOver->Music_Game_Over(); // music when health is run out
        back_ground=back_ground.scaled(w,h);
        q->setPixmap(back_ground);
        q->setPos(0,0);
        scene.addItem(q);



        // create the Play again button
        Playagain = new Button(QString("Play Again"));
        int x = 350;
        int y = 500;
        Playagain->setPos(x,y);
        connect(Playagain,SIGNAL(clicked()),this,SLOT(restart()));
        scene.addItem(Playagain);



        // create the Exit button
        exit_button = new Button(QString("Quit"));
        x = 700;
        y = 500;
        exit_button->setPos(x,y);
        connect(exit_button,SIGNAL(clicked()),this,SLOT(Delete_All()));
        scene.addItem(exit_button);



    }

}
void GameManager::restart() // clear the scene
{

    Playagain->clearFocus();
    scene.removeItem(Playagain);
    delete Playagain;

    exit_button->clearFocus();
    scene.removeItem(exit_button);
    delete exit_button;

    q->clearFocus();
    scene.removeItem(q);
    delete q;

    coin_image->clearFocus();
    scene.removeItem(q);
    delete coin_image;


    QList<QGraphicsItem*> all = scene.items(); // remove enemies from the screen
    for (int i = 0; i < all.size(); i++)
    {

        if ((typeid(*(all[i])) == typeid(Enemy1))||(typeid(*(all[i])) == typeid(Enemy2))||(typeid(*(all[i])) == typeid(Health_enemy))||(typeid(*(all[i])) == typeid(Health))||(typeid(*(all[i])) == typeid(enemy3_Boss))||(typeid(*(all[i])) == typeid(Fire))||(typeid(*(all[i])) == typeid(Player))||(typeid(*(all[i])) == typeid(coins)))
        {
            all[i]->clearFocus();
            delete all[i];
        }
    }

    QList<QGraphicsItem*> all2 = scene.items(); // remove coins that will be created after deleting all the enemies( last loop) from the screen
    for (int i = 0; i < all2.size(); i++)
    {

        if ((typeid(*(all2[i])) == typeid(coins)))
        {
            all2[i]->clearFocus();
            delete all2[i];
        }
    }
    // defualt values
    coins::set_number(100);
    Player::player_image(0);
    Bullet::bullet_image(0);
    Bullet::returnspeed();


    start();
}
void GameManager::Win_Game() //need to be modified
{
    if(Health_enemy::get_number()==0&&Enemy1::get()==0&&Enemy2::get()==0&&win_page_open==0)
    {
        win_page_open=1;
        if(!getMute_Music()) //getMute_Music==false
                win->Music_Win_The_Game();

        while(Health_enemy::get_number()!=4) //to return the number of health for the last enemy to 4 again
            Health_enemy::increase();

        while(Health::get_number()!=4)//to return the number of health for the player to 3 again
            Health::increase();


        // game over image
        q=new QGraphicsPixmapItem;
        QPixmap back_ground("win.png");
        back_ground=back_ground.scaled(w,h);
        q->setPixmap(back_ground);
        q->setPos(0,0);
        scene.addItem(q);



        // create the Play again button
        Playagain = new Button(QString("Play Again"));
        int x = 350;
        int y = 500;
        Playagain->setPos(x,y);
        connect(Playagain,SIGNAL(clicked()),this,SLOT(restart()));
        scene.addItem(Playagain);


        // create the Exit button
        exit_button = new Button(QString("Quit"));
        x = 700;
        y = 500;
        exit_button->setPos(x,y);
        connect(exit_button,SIGNAL(clicked()),this,SLOT(Delete_All()));
        scene.addItem(exit_button);

        Player::set(false);// to force the fire to use the first table

    }

}
void GameManager::Monester_Stage() // the last stage
{
    if(Player::get_last_stage()==1&&monster_stage_open==0) // player should be infron of the gate three and number of enemies 1 and 2 is 0
    {
        monster_stage_open=1;
        Player::set_last_stage(0);// to stop the condition
        //Enemy1::increase(); // to stop the conduction (the timer checker of Monester_Stage() that exist in the function start)

        if(!getMute_Music()) // music
                small_win->Music_Win();

        enemy3_Boss *v9=new enemy3_Boss; // create the Monester
        draw_enemyhealth();
        scene.addItem(v9); // add it to the scene

        //win checker
        timer3 = new QTimer();
        connect(timer, SIGNAL(timeout()), this, SLOT(Win_Game()));
        timer->start(350);
    }

}
void GameManager::Delete_All() // return the meemory to the heap
{
    QList<QGraphicsItem*> it = scene.items();
    for (int i = 0; i < it.size(); i++)
    {
        if ((typeid(*(it[i])) == typeid(Enemy1))||(typeid(*(it[i])) == typeid(Enemy2))||(typeid(*(it[i])) == typeid(Health_enemy))||(typeid(*(it[i])) == typeid(enemy3_Boss))||(typeid(*(it[i])) == typeid(Fire))||(typeid(*(it[i])) == typeid(Player))||(typeid(*(it[i])) == typeid(Health))||(typeid(*(it[i])) == typeid(Bullet)))
        {
            it[i]->clearFocus();
            scene.removeItem(it[i]);
            delete it[i];
        }
    }
    close();
}

void GameManager::change_health() // to update the health number
{

    scene.removeItem(titleText);
    titleText = new QGraphicsTextItem(QString::number(Health::get_number()*25)+" %");
    QFont titleFont("comic sans",18);
    titleText->setFont(titleFont);
    const QColor titleColor(Qt::white);
    titleText->setDefaultTextColor(titleColor);
    int x = 1200;
    int y = 25;
    titleText->setPos(x,y);
    scene.addItem(titleText);

}

void GameManager::Shop_page()  // display shop
{
    shop_is_open=1;
    // market image
    shop_image=new QGraphicsPixmapItem;
    QPixmap shop_photo("shop.png");
    shop_photo=shop_photo.scaled(800,700);
    shop_image->setPixmap(shop_photo);
    shop_image->setPos(300,50);
    scene.addItem(shop_image);


    close_button = new Button(QString("Close"),150,40);
    close_button->setPos(470,230);
    connect(close_button,SIGNAL(clicked()),this,SLOT(Shop_page_close())); //connecting the slot to the button clicked event.
    scene.addItem(close_button);

    speed_button = new Button(QString("Spead 2X buy for(200 coins)"),150,40);
    speed_button->setPos(470,465);
    connect(speed_button,SIGNAL(clicked()),this,SLOT(bullet_speed())); //connecting the slot to the button clicked event.
    scene.addItem(speed_button);

    player_button = new Button(QString("Player"),150,40);
    player_button->setPos(470,325);
    connect(player_button,SIGNAL(clicked()),this,SLOT(buy_player())); //connecting the slot to the button clicked event.
    scene.addItem(player_button);

    bullet_button = new Button(QString("Power"),150,40);
    bullet_button->setPos(470,395);
    connect(bullet_button,SIGNAL(clicked()),this,SLOT(buy_bullet())); //connecting the slot to the button clicked event.
    scene.addItem(bullet_button);

    health_button = new Button(QString("Health buy for (250 coins)"),150,40);
    health_button->setPos(470,535);
    connect(health_button,SIGNAL(clicked()),this,SLOT(buy_health())); //connecting the slot to the button clicked event.
    scene.addItem(health_button);
}


void GameManager::buy_player() // display players' shop
{
    is_player_shop_open=1;
    players_image=new QGraphicsPixmapItem;
    QPixmap shop_photo("players.png");
    shop_photo=shop_photo.scaled(400,300);
    players_image->setPixmap(shop_photo);
    players_image->setPos(470,325);;
    scene.addItem(players_image);

    buy_button1 = new Button(QString("Buy (500 Coin)"),80,25);
    buy_button1->setPos(525,520);
    connect(buy_button1,SIGNAL(clicked()),this,SLOT(player1())); //connecting the slot to the button clicked event.
    scene.addItem(buy_button1);

    buy_button2 = new Button(QString("Buy (250 Coin)"),80,25);
    buy_button2->setPos(625,520);
    connect(buy_button2,SIGNAL(clicked()),this,SLOT(player2())); //connecting the slot to the button clicked event.
    scene.addItem(buy_button2);

    buy_button3 = new Button(QString("Buy (250 Coin)"),80,25);
    buy_button3->setPos(725,520);
    connect(buy_button3,SIGNAL(clicked()),this,SLOT(player3())); //connecting the slot to the button clicked event.
    scene.addItem(buy_button3);
}
void GameManager::shop_display() // shop is open or not
{
    if(open&&shop_is_open==0)
    {
        Shop_page();
        open=0;   
    }
}
void GameManager::player1() // buy player1
{
    if(coins::get_number()<500)
        return;
    coins::decrease(500);
    Player::player_image(1);
    Shop_page_players_close();
    Shop_page_close();
}
void GameManager::player2()// buy player2
{
    if(coins::get_number()<250)
        return;
    coins::decrease(250);
    Player::player_image(2);
    Shop_page_players_close();
    Shop_page_close();
}
void GameManager::player3()// buy player3
{
    if(coins::get_number()<250)
        return;
    coins::decrease(250);
    Player::player_image(3);
    Shop_page_players_close();
    Shop_page_close();
}

void GameManager::bullet_speed() // increase bullet speed
{
    if(Bullet::increase_speed())
    {
        if(coins::get_number()<200)
            return;
        coins::decrease(200);
    }
    Shop_page_close();
}
void GameManager::buy_health() // increase health ( not that 100)
{
    if(Health::get_number()==4)
    {
        Shop_page_close();
        return;
    }
    if(coins::get_number()<250)
        return;
    coins::decrease(250);

    if(Health::get_number()==3)
    {
        Health::increase();
        Health *trial4=new Health(1100,25);
        scene.addItem(trial4);
        Shop_page_close();

    }
    else if(Health::get_number()==2)
    {
        Health::increase();
        Health *trial3=new Health(1050,25);
        scene.addItem(trial3);
        Shop_page_close();
    }
    else if(Health::get_number()==1)
    {
        Health::increase();
        Health *trial2=new Health(1000,25);
        scene.addItem(trial2);
        Shop_page_close();
    }
}
void GameManager::buy_bullet() // open the shop of bullets
{
    is_bullet_shop_open=1;
    bullet_image=new QGraphicsPixmapItem;
    QPixmap bullet_photos("bullet_shop.png");
    bullet_photos=bullet_photos.scaled(400,300);
    bullet_image->setPixmap(bullet_photos);
    bullet_image->setPos(470,325);;
    scene.addItem(bullet_image);

    buy_bullet1 = new Button(QString("Buy (300 Coins )"),80,25);
    buy_bullet1->setPos(525,520);
    connect(buy_bullet1,SIGNAL(clicked()),this,SLOT(bullet1())); //connecting the slot to the button clicked event.
    scene.addItem(buy_bullet1);

    buy_bullet2 = new Button(QString("Buy (400 Coins )"),80,25);
    buy_bullet2->setPos(625,520);
    connect(buy_bullet2,SIGNAL(clicked()),this,SLOT(bullet2())); //connecting the slot to the button clicked event.
    scene.addItem(buy_bullet2);

    buy_bullet3 = new Button(QString("Buy (100 Coins)"),80,25);
    buy_bullet3->setPos(725,520);
    connect(buy_bullet3,SIGNAL(clicked()),this,SLOT(bullet3())); //connecting the slot to the button clicked event.
    scene.addItem(buy_bullet3);
}
void GameManager::bullet1() // buy bullet1
{
    if(coins::get_number()<300)
        return;
    coins::decrease(300);
    Bullet::bullet_image(1);
    Shop_page_close();
}
void GameManager::bullet2() // buy bullet2
{
    if(coins::get_number()<400)
        return;
    coins::decrease(400);
    Bullet::bullet_image(2);
    Shop_page_close();
}
void GameManager::bullet3() // buy bullet3
{
    if(coins::get_number()<100)
        return;
    coins::decrease(100);
   Bullet::bullet_image(3);
   Shop_page_close();
}
void GameManager::player_focus() // return the focus to the player after closing the shop
{
    QList<QGraphicsItem*> it = scene.items();
    for (int i = 0; i < it.size(); i++)
    {
        if (typeid(*(it[i])) == typeid(Player))
        {
            it[i]->setFlag(QGraphicsPixmapItem::ItemIsFocusable);
            it[i]->setFocus();
            return;
        }
    }
}




void GameManager::Shop_page_close() //close the shop
{
    close_button->clearFocus();
    scene.removeItem(close_button);
    delete close_button;

    speed_button->clearFocus();
    scene.removeItem(speed_button);
    delete speed_button;

    player_button->clearFocus();
    scene.removeItem(player_button);
    delete player_button;

    bullet_button->clearFocus();
    scene.removeItem(bullet_button);
    delete bullet_button;

    health_button->clearFocus();
    scene.removeItem(health_button);
    delete health_button;


    shop_image->clearFocus();
    scene.removeItem(shop_image);
    delete shop_image;
    if(is_player_shop_open)
        Shop_page_players_close();
     if(is_bullet_shop_open)
         Shop_page_bullets_close();
    shop_is_open=0;
    player_focus();
}

void GameManager::Shop_page_players_close() // close the shop of players
{
    is_player_shop_open=0;
    players_image->clearFocus();
    scene.removeItem(players_image);
    delete players_image;
    shop_is_open=0;

    buy_button1->clearFocus();
    scene.removeItem(buy_button1);
    delete buy_button1;

    buy_button2->clearFocus();
    scene.removeItem(buy_button2);
    delete buy_button2;

    buy_button3->clearFocus();
    scene.removeItem(buy_button3);
    delete buy_button3;
    //Shop_page_close();
}

void GameManager::Shop_page_bullets_close() // close the shop of bullets
{
    is_bullet_shop_open=0;
    bullet_image->clearFocus();
    scene.removeItem(bullet_image);
    delete bullet_image;
    shop_is_open=0;

    buy_bullet1->clearFocus();
    scene.removeItem(buy_bullet1);
    delete buy_bullet1;

    buy_bullet2->clearFocus();
    scene.removeItem(buy_bullet2);
    delete buy_bullet2;

    buy_bullet3->clearFocus();
    scene.removeItem(buy_bullet3);
    delete buy_bullet3;
    //Shop_page_close();
}
void GameManager::create_coins()// create and update the number of coins
{

    scene.removeItem(coinText);
    coinText = new QGraphicsTextItem( QString:: number(coins::get_number()) + "X ");
    QFont titleFont("comic sans",18);
    coinText->setFont(titleFont);
    const QColor titleColor(Qt::white);
    coinText->setDefaultTextColor(titleColor);
    int x = 640;
    int y = 20;
    coinText->setPos(x,y);
    scene.addItem(coinText);
}
void GameManager::delete_coins() // delete coins after each 9 second
{
    int static i=0;
    if(i==0)
    {
        i=1;
        return;
    }
    QList<QGraphicsItem*> it = scene.items();
    for (int i = 0; i < it.size(); i++)
    {
        if (typeid(*(it[i])) == typeid(coins))
        {
            scene.removeItem(it[i]);
            it[i]->clearFocus();
            delete it[i];
            return;
        }
    }
}
void GameManager::set_open( bool b){open =b;}
bool GameManager::Muted_Music; //static boolian variable
bool GameManager::open=0;
