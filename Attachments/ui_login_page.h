/********************************************************************************
** Form generated from reading UI file 'login_page.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_PAGE_H
#define UI_LOGIN_PAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Login_page
{
public:
    QLabel *label;
    QLineEdit *username;
    QLineEdit *pass;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *Log_in_button;
    QPushButton *pushButton_2;
    QPushButton *Log_in_button_2;
    QLabel *label_4;

    void setupUi(QDialog *Login_page)
    {
        if (Login_page->objectName().isEmpty())
            Login_page->setObjectName(QString::fromUtf8("Login_page"));
        Login_page->resize(400, 300);
        QFont font;
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(true);
        font.setStrikeOut(false);
        Login_page->setFont(font);
        label = new QLabel(Login_page);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 30, 171, 41));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setUnderline(true);
        font1.setStrikeOut(false);
        label->setFont(font1);
        username = new QLineEdit(Login_page);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(120, 90, 211, 31));
        QFont font2;
        font2.setBold(false);
        font2.setItalic(false);
        font2.setUnderline(false);
        font2.setStrikeOut(false);
        username->setFont(font2);
        pass = new QLineEdit(Login_page);
        pass->setObjectName(QString::fromUtf8("pass"));
        pass->setGeometry(QRect(120, 150, 211, 31));
        pass->setFont(font2);
        label_2 = new QLabel(Login_page);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 90, 101, 21));
        QFont font3;
        font3.setPointSize(15);
        font3.setBold(false);
        font3.setItalic(false);
        font3.setUnderline(false);
        font3.setStrikeOut(false);
        label_2->setFont(font3);
        label_3 = new QLabel(Login_page);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 150, 101, 21));
        label_3->setFont(font3);
        Log_in_button = new QPushButton(Login_page);
        Log_in_button->setObjectName(QString::fromUtf8("Log_in_button"));
        Log_in_button->setGeometry(QRect(140, 200, 81, 31));
        Log_in_button->setFont(font2);
        pushButton_2 = new QPushButton(Login_page);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 200, 81, 31));
        pushButton_2->setFont(font2);
        Log_in_button_2 = new QPushButton(Login_page);
        Log_in_button_2->setObjectName(QString::fromUtf8("Log_in_button_2"));
        Log_in_button_2->setGeometry(QRect(240, 250, 81, 31));
        Log_in_button_2->setFont(font2);
        label_4 = new QLabel(Login_page);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 250, 201, 31));
        label_4->setFont(font2);

        retranslateUi(Login_page);

        QMetaObject::connectSlotsByName(Login_page);
    } // setupUi

    void retranslateUi(QDialog *Login_page)
    {
        Login_page->setWindowTitle(QCoreApplication::translate("Login_page", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Login_page", "LogIn", nullptr));
        label_2->setText(QCoreApplication::translate("Login_page", "User_Name", nullptr));
        label_3->setText(QCoreApplication::translate("Login_page", "Password", nullptr));
        Log_in_button->setText(QCoreApplication::translate("Login_page", "Log_In", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Login_page", "Register", nullptr));
        Log_in_button_2->setText(QCoreApplication::translate("Login_page", "Close", nullptr));
        label_4->setText(QCoreApplication::translate("Login_page", "For only children who cannot log in", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Login_page: public Ui_Login_page {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_PAGE_H
