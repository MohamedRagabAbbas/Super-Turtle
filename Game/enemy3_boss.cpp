#include "enemy3_boss.h"

enemy3_Boss::enemy3_Boss()
{
    //takes row, col and last move of the player by the static functions 
    playerPosition.first=Player::get_row(); 
    playerPosition.second=Player::get_col();
    player_last_move_row=Player::get_row();
    player_last_move_col=Player::get_col();

    QPixmap v("boss_left.png"); // to conect the image of the boss with the boss
    v=v.scaled(70,70);
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
//initial position of the boss
    bossPosition.first=5;
    bossPosition.second=30;
    setPos(bossPosition.second*35,bossPosition.first*35+50); //

    // inorder to make the enemy move forever
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(200);//its speed*/

    timer2 = new QTimer();
    connect(timer2, SIGNAL(timeout()), this, SLOT(palyer_mover()));
    timer2->start(0);//its speed*/

    lose=new Sound; // sound when the player is losing


    timer3 = new QTimer();
    connect(timer3, SIGNAL(timeout()), this, SLOT(create_small_enemies())); // connect with creating small additional enemies 
    timer3->start(9000);

    AStar ( bossPosition,playerPosition); // A* to find the shortest path 
}




// A_Star Functions
bool enemy3_Boss:: inRange(int r, int col) // in the range of the data
{
    return ((r < ROW) && (col < COL));
}

// if the cell is block +we might use it depends on the enemy lma netfeq
bool enemy3_Boss:: isBlock(int r, int col)
{
    return (data[r][col] <0);
    //||data[r][col]==6||data[r][col]==4||data[r][col]==8
}

bool enemy3_Boss::ReachDestination(int r, int col, Pair dest) // to check whether enemy reached (its destination) the player or not
{
 return (r == dest.first && col == dest.second); // collision
}

int enemy3_Boss::H_Calculation(int r, int col, Pair dest) // return the estimation distance using the rule of difference between two points
{
    return (sqrt((r - dest.first) * (r - dest.first) + (col - dest.second) * (col - dest.second)));
}
 // will be changed and make the boss move according to the sequence of steps
void enemy3_Boss:: tracePath( Pair dest)
{
    int r = dest.first;
    int col = dest.second;
    while(!bossPath.empty())
            bossPath.pop();

    while (!((cellDetails[r][col].parent_i == r && cellDetails[r][col].parent_j == col))) //while the boss hasn't reached the destination 
    {
        bossPath.push(make_pair(r, col)); // pair of row &col to follow the position 
        if(cellDetails[r][col].parent_i==-1||cellDetails[r][col].parent_j==-1)
            break;
        if(cellDetails[cellDetails[r][col].parent_i][cellDetails[r][col].parent_j].parent_i==r&&cellDetails[cellDetails[r][col].parent_i][cellDetails[r][col].parent_j].parent_j==col)//reached the destination 
            break;
        // the following parents of the pair pushed after the cells

        int temp_r = cellDetails[r][col].parent_i; 
        int temp_col = cellDetails[r][col].parent_j;
        r = temp_r; //update r & col 
        col = temp_col;
    }
    bossPath.push(make_pair(r, col)); // last step which is the index of the destination 
 
    return;
}

void enemy3_Boss::AStar ( Pair src, Pair dest) // pass boss's and player's positions to to the function 
{
 // initialize closed list (2D array)
    for(int i=0;i<ROW;i++)
    {
        for(int j=0;j<COL;j++)
        {
            closedList[i][j]=0;
        }
    }

    // Declare a 2D array of structure to hold the details

    int i, j;

    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            //initite the the value of f, g and h to be infinity 
            cellDetails[i][j].f = INF;
            cellDetails[i][j].g = INF;
            cellDetails[i][j].h = INF;
            cellDetails[i][j].parent_i = -1; //initiate parent by -1
            cellDetails[i][j].parent_j = -1;
        }
    }
    //boss=source
    //player= destination 
    i = src.first, j = src.second; // i and j took the values of the boss's position 
    // starting from the enemy position to get the pass 
    cellDetails[i][j].f = 0;
    cellDetails[i][j].g = 0;
    cellDetails[i][j].h = 0;
    cellDetails[i][j].parent_i = i;
    cellDetails[i][j].parent_j = j;

    //  This open list is implemented as a set of pair of pair


    // Put the starting cell on the open list and set its'f' as 0
    openList.insert(make_pair(0, make_pair(i, j)));
    bool foundDest = false; // the destination is not reached.
    while (!openList.empty())
    {
        pPair p = *openList.begin(); // Remove this vertex from the open list
        openList.erase(openList.begin());
        i = p.second.first;
        j = p.second.second;
        closedList[i][j] = true; // Add this vertex to the closed list

        // Cell-->Popped Cell (i, j)
        //(4 directions ) N -->  North (i-1, j) S -->  South (i+1, j) E -->  East (i, j+1) W -->  West (i, j-1)
        int gNew, hNew, fNew; // To store the 'g', 'h' and 'f' of the 4 successors

        if (inRange(i - 1, j) == true) // north
        {
            if (ReachDestination(i - 1, j, dest) == true)
            {
                cellDetails[i - 1][j].parent_i = i; // Set the Parent of the destination cell
                cellDetails[i - 1][j].parent_j = j;
                tracePath( dest);
                foundDest = true; 
                return;
            }
            else if (!(closedList[i - 1][j]) && !(isBlock( i - 1, j)))
            {
                gNew = cellDetails[i][j].g + 1;
                hNew = H_Calculation(i - 1, j, dest);
                fNew = gNew + hNew;
                if (cellDetails[i - 1][j].f == INF || cellDetails[i - 1][j].f > fNew)
                {
                    openList.insert(make_pair(fNew, make_pair(i - 1, j)));

                    // Update the details of this cell
                    cellDetails[i - 1][j].f = fNew;
                    cellDetails[i - 1][j].g = gNew;
                    cellDetails[i - 1][j].h = hNew;
                    cellDetails[i - 1][j].parent_i = i;
                    cellDetails[i - 1][j].parent_j = j;
                }
            }
        }
        if (inRange(i + 1, j) == true) //(South)
        {
            // If the destination cell is the same as the  current successor
            if (ReachDestination(i + 1, j, dest) == true)
            {
                // Set the Parent of the destination cell
                cellDetails[i + 1][j].parent_i = i;
                cellDetails[i + 1][j].parent_j = j;
                tracePath(dest);
                foundDest = true;
                return;
            }

            else if (!closedList[i + 1][j] && !isBlock( i + 1, j))
            {
                gNew = cellDetails[i][j].g + 1;
                hNew = H_Calculation(i + 1, j, dest);
                fNew = gNew + hNew;

                if (cellDetails[i + 1][j].f == INF || cellDetails[i + 1][j].f > fNew)
                {
                    openList.insert(make_pair(
                        fNew, make_pair(i + 1, j)));
                    // Update the details of this cell
                    cellDetails[i + 1][j].f = fNew;
                    cellDetails[i + 1][j].g = gNew;
                    cellDetails[i + 1][j].h = hNew;
                    cellDetails[i + 1][j].parent_i = i;
                    cellDetails[i + 1][j].parent_j = j;
                }
            }
        }

        if (inRange(i, j + 1) == true) // east
        {
            if (ReachDestination(i, j + 1, dest) == true) // Set the Parent of the destination cell

            {
                cellDetails[i][j + 1].parent_i = i;
                cellDetails[i][j + 1].parent_j = j;
                tracePath(dest);
                foundDest = true;
                return;
            }

            else if (!closedList[i][j + 1] && !isBlock(i, j + 1))
            {
                gNew = cellDetails[i][j].g + 1;
                hNew = H_Calculation(i, j + 1, dest);
                fNew = gNew + hNew;
                if (cellDetails[i][j + 1].f == INF || cellDetails[i][j + 1].f > fNew)
                {
                    openList.insert(make_pair(
                        fNew, make_pair(i, j + 1)));
                    // Update the details of this cell
                    cellDetails[i][j + 1].f = fNew;
                    cellDetails[i][j + 1].g = gNew;
                    cellDetails[i][j + 1].h = hNew;
                    cellDetails[i][j + 1].parent_i = i;
                    cellDetails[i][j + 1].parent_j = j;
                }
            }
        }

        if (inRange(i, j - 1) == true) // west
        {
            if (ReachDestination(i, j - 1, dest) == true)
            {
                // Set the Parent of the destination cell
                cellDetails[i][j - 1].parent_i = i;
                cellDetails[i][j - 1].parent_j = j;
                tracePath( dest);
                foundDest = true;
                return;
            }
            else if (!closedList[i][j - 1] && !isBlock( i, j - 1) == true)
            {
                gNew = cellDetails[i][j].g + 1;
                hNew = H_Calculation(i, j - 1, dest);
                fNew = gNew + hNew;
                if (cellDetails[i][j - 1].f == INF || cellDetails[i][j - 1].f > fNew)
                {
                    openList.insert(make_pair(
                        fNew, make_pair(i, j - 1)));

                    cellDetails[i][j - 1].f = fNew;
                    cellDetails[i][j - 1].g = gNew;
                    cellDetails[i][j - 1].h = hNew;
                    cellDetails[i][j - 1].parent_i = i;
                    cellDetails[i][j - 1].parent_j = j;
                }
            }
        }
    }
    return;
}


    void enemy3_Boss::move()
    {
        while(!bossPath.empty())
        {
          coll(); //collision between boss and bullets  
          if(Player::get_row()==bossPosition.first&&Player::get_col()==bossPosition.second)
          {
              cout<<"\n ? \n";
              while(!bossPath.empty())
              {cout<<"kkk\n";
                  bossPath.pop();}
              break;
          }
          if( bossPosition.first==bossPath.top().first&&bossPosition.second+1==bossPath.top().second)
          {
             QPixmap p("boss_right.png");// to change the image to be suitable for the new direction
             p=p.scaled(70,70);
             this->setPixmap(p);
             last_move=0;
          }
          else if( bossPosition.first==bossPath.top().first&&bossPosition.second-1==bossPath.top().second)
          {
             QPixmap p("boss_left.png");// to change the image to be suitable for the new direction
             p=p.scaled(70,70);
             this->setPixmap(p);
             last_move=3;
          }
          else if( bossPosition.first-1==bossPath.top().first&&bossPosition.second==bossPath.top().second)
          {
             QPixmap p("boss_up.png");// to change the image to be suitable for the new direction
             p=p.scaled(70,70);
             this->setPixmap(p);
             last_move=2;
          }
          else if( bossPosition.first+1==bossPath.top().first&&bossPosition.second==bossPath.top().second)
          {
             QPixmap p("boss_down.png");// to change the image to be suitable for the new direction
             p=p.scaled(70,70);
             this->setPixmap(p);
             last_move=1;
          }
          cout<<"HIII  222";
          cout<<" ( "<<bossPosition.first<<"  "<<bossPosition.second<<" )"<<endl;
          Pair p = bossPath.top();
          bossPosition.first=bossPath.top().first;
          bossPosition.second=bossPath.top().second;
          bossPath.pop();
          setPos(bossPosition.second*35,50+bossPosition.first*35);

          int static counter=0;
          if(counter%3==1)
          {
              //create a fire
              Fire * f = new Fire(last_move,0,100);
              f->setPos(x()+10,y()+10);
              scene()->addItem(f);
          }
          counter++;

          return;
        }


        //AStar (bossPosition,{Player::get_row(),Player::get_col()});
        return;
    }

    int enemy3_Boss:: row;
    int enemy3_Boss:: column;

void enemy3_Boss::palyer_mover() //to update the player's position everytime 
{
    if((player_last_move_row==Player::get_row()&&player_last_move_col==Player::get_col())||(Player::get_row()==1&&Player::get_col()==1))
        return;

    player_last_move_row=Player::get_row();
    player_last_move_col=Player::get_col();

    playerPosition.first=Player::get_row();
    playerPosition.second=Player::get_col();

    while(!bossPath.empty())
        bossPath.pop(); 
        //pop content of the stack then call the A* to trace the path 

    AStar (bossPosition,playerPosition);
}
void enemy3_Boss::coll() //collision 
{
    QList<QGraphicsItem*> collision = collidingItems();
    int size=collision.size();
    for (int i = 0; i < size; i++)
    {
        if (typeid(*(collision[i])) == typeid(Player)&&(Health::get_number()==1))//collision with player and number of hearts is one

        { 
                Health::decrease(); // reduce the number of hearts
                collision[i]->clearFocus(); // clear the focus of the player as the number of health is 0
                //scene()->removeItem(collision[i]); // remove player
                delete collision[i];
                SLOT(NULL);
                return;
         }

         else if (typeid(*(collision[i])) == typeid(Player)) //collision with player and number of hearts is not one
        {
            int rand_row=rand()%10+2;
            int rand_col=rand()%20+3;
            Player::set_row(rand_row);
            Player::set_column(rand_col);
            collision[i]->setPos(35*rand_col,50+35*rand_row);

            if(GameManager::getMute_Music()==false)
                lose->Music_Lose();
            Health::decrease(); // reduce number of hearts
            // remove one heart from the screen
            QList<QGraphicsItem*> heart = scene()->items();
            int size=heart.size();
            for (int i = 0; i < size; i++) {
                if (typeid(*(heart[i])) == typeid(Health)) {
                    scene()->removeItem(heart[i]);
                    break;
                }
            }
        }
            else if (typeid(*(collision[i])) == typeid(Bullet)) //collision with bullet or the player 
            {
            Health_enemy::decrease();// reduce its number
            if(Health_enemy::get_number()>0)
            {
                QList<QGraphicsItem*> heart = scene()->items(); // remove one white heart from the screen
                int size=heart.size();
                for (int i = 0; i < size; i++){
                    if (typeid(*(heart[i])) == typeid(Health_enemy))
                    {scene()->removeItem(heart[i]); break;}
                }
                break;
            }
            this->clearFocus();
            delete this;
            delete collision[i];
            SLOT(NULL);
            return;
             }
            // player is still exist in the scene as the number of health is not 0
            return;
        }
    }


void enemy3_Boss::create_small_enemies() 
{
    int static i=0;
    if(i%2==0)
    {
        Enemy1 *v1=new Enemy1(0,7,bossPosition.second*35,bossPosition.first*35+50);
        scene()->addItem(v1);
        Enemy1::increase();
        i++;
    }
    else
    {
        Enemy2 *v2=new Enemy2(0,7,bossPosition.second*35,bossPosition.first*35+50);
        scene()->addItem(v2);
        Enemy2::increase();
        i++;
    }
}


