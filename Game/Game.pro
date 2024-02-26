
QT       += core gui
            multimedia
            multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
QT  +=core gui multimedia
QT += multimedia


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bullet.cpp \
    button.cpp \
    coins.cpp \
    enemy1.cpp \
    enemy2.cpp \
    enemy3_boss.cpp \
    fire.cpp \
    gamemanager.cpp \
    health.cpp \
    health_enemy.cpp \
    login_page.cpp \
    main.cpp \
    player.cpp \
    register.cpp \
    sound.cpp

HEADERS += \
    ../../U/Game 1/Game/gamemanager.h \
    bullet.h \
    button.h \
    coins.h \
    enemy1.h \
    enemy2.h \
    enemy3_boss.h \
    fire.h \
    gamemanager.h \
    health.h \
    health_enemy.h \
    login_page.h \
    player.h \
    register.h \
    sound.h

FORMS += \
    login_page.ui \
    player.ui \
    register.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=

