#ifndef LOGIN_PAGE_H
#define LOGIN_PAGE_H

#include <QDialog>
#include <QFile>
#include <register.h>


namespace Ui {
class Login_page;
}

class Login_page : public QDialog
{
    Q_OBJECT

    QString name; //user name
    QString password; // password

public:
    explicit Login_page(QWidget *parent = nullptr);
    ~Login_page();

private slots:
    bool on_Log_in_button_clicked(); // is the user clicked on the login button

    void on_pushButton_2_clicked();// is the user clicked on the regist button

    void on_Log_in_button_2_clicked();// is the user clicked on the close button

private:
    Ui::Login_page *ui;
};

#endif // LOGIN_PAGE_H
