/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *username;
    QLineEdit *pass;
    QLineEdit *cpass;
    QLabel *label_5;

    void setupUi(QDialog *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QString::fromUtf8("Register"));
        Register->resize(400, 300);
        pushButton = new QPushButton(Register);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(200, 230, 81, 31));
        QFont font;
        font.setPointSize(12);
        pushButton->setFont(font);
        label = new QLabel(Register);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 50, 191, 41));
        QFont font1;
        font1.setPointSize(20);
        label->setFont(font1);
        label_2 = new QLabel(Register);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 100, 191, 41));
        label_2->setFont(font);
        label_3 = new QLabel(Register);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 140, 191, 41));
        label_3->setFont(font);
        label_4 = new QLabel(Register);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 180, 191, 41));
        label_4->setFont(font);
        username = new QLineEdit(Register);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(150, 110, 191, 31));
        pass = new QLineEdit(Register);
        pass->setObjectName(QString::fromUtf8("pass"));
        pass->setGeometry(QRect(150, 150, 191, 31));
        pass->setEchoMode(QLineEdit::Password);
        pass->setDragEnabled(false);
        cpass = new QLineEdit(Register);
        cpass->setObjectName(QString::fromUtf8("cpass"));
        cpass->setGeometry(QRect(150, 190, 191, 31));
        cpass->setEchoMode(QLineEdit::Password);
        label_5 = new QLabel(Register);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(18, 240, 181, 31));
        QFont font2;
        font2.setPointSize(10);
        label_5->setFont(font2);

        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QDialog *Register)
    {
        Register->setWindowTitle(QCoreApplication::translate("Register", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("Register", "Register", nullptr));
        label->setText(QCoreApplication::translate("Register", "Register", nullptr));
        label_2->setText(QCoreApplication::translate("Register", "User_Name", nullptr));
        label_3->setText(QCoreApplication::translate("Register", "Password", nullptr));
        label_4->setText(QCoreApplication::translate("Register", "Confirm_Password", nullptr));
        pass->setText(QString());
        label_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
