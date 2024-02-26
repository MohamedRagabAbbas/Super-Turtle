#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include <QFile>


namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT
    QString name;
    QString password;
    QString confirmpassword;
public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Register *ui;
};

#endif // REGISTER_H
