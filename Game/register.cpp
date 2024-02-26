#include "register.h"
#include "ui_register.h"


Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    this->setWindowFlags( (Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowMinMaxButtonsHint) & ~Qt::WindowCloseButtonHint );
}

Register::~Register()
{
    delete ui;
}

void Register::on_pushButton_clicked()
{
    //set the texts in the wedget as values of name,password and confirmation 
    name=ui->username->text();
    password=ui->pass->text();
    confirmpassword=ui->cpass->text();

    int i=0;
    QFile file1("data.txt"); //read the data from the file
    file1.open(QIODevice::ReadOnly);
    QTextStream stream(&file1);
    QString read;
    QString read2;
    while(!file1.atEnd())
    {
        read=file1.readLine();
        read2=file1.readLine();
       if(read==(name+"\n"))
       {
          ui->label_5->setText("this name is already exist"); //If the user name is already exist
          file1.close();
          i=1;
          return;
       }

       //stream>>read;
    }
        file1.close();

        if((name==""||password==""||confirmpassword=="")||i==1||ui->cpass->text()!=ui->pass->text())
        {
            if(ui->cpass->text()!=ui->pass->text()) //Validate the confirmPassword
            {
                ui->label_5->setText("password does not match");
            }
            if(name==""||password==""||confirmpassword=="") //if the user did not enter anything
            {
                ui->label_5->setText("Empty field is not allowed");
            }

        }



   else
    {
        QFile file("data.txt");
        file.open(QIODevice::WriteOnly| QIODevice::Append);
        //enter the new user's data to the file
        QTextStream stream2(&file);
        //user's information:
        stream2 << name << Qt::endl;
        stream2 << password << Qt::endl;
       // stream2 << "100" << Qt::endl; //number of coins
        file.close();
        close();
    }


    }






