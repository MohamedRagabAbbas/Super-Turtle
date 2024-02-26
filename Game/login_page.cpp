#include "login_page.h"
#include "ui_login_page.h"

#include<iostream>
using namespace std;
Login_page::Login_page(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login_page)
{
    ui->setupUi(this);
    // hide the ("X" close ) from the window to force the user to register first
    this->setWindowFlags( (Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowMinMaxButtonsHint) & ~Qt::WindowCloseButtonHint );
}

Login_page::~Login_page()
{
    delete ui;
}

bool Login_page::on_Log_in_button_clicked()
{
    name=ui->username->text(); // get the user name forn the line edit
    password=ui->pass->text();// get the user password forn the line edit

    QFile file("data.txt"); // file
    file.open(QIODevice::ReadOnly); //read
    QTextStream stream(&file);

    QString read;
    QString read2;

    while(!file.atEnd()) //to validate the user name and password
    {
       read=file.readLine();
       read2=file.readLine();
       qDebug() << read << " " << read2;
       cout<<"77778"<<endl;
       if(read==(name+"\n")&&read2==(password+"\n"))
       {
           close(); // close the loging page to start the game
       }
    }
    file.close(); //close the file
    return false;
}


void Login_page::on_pushButton_2_clicked()// register button
{
    Register r; // display the register window
    r.setModal(true);
    r.exec(); //dispaly
    close(); // close the log in page when the register page is open
}


void Login_page::on_Log_in_button_2_clicked()
// we assumed that there will be many children need to play the game, but they cannot login first
//so, it is logical to give them the chance to close the login page
{
    close();
}

