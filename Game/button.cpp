#include "button.h"
#include <QGraphicsTextItem>
#include <QBrush>

Button::Button(QString Button_name, int SX , int SY,QGraphicsItem *parent): QGraphicsRectItem(parent){
    // draw the rect
    setRect(0,0,SX,SY);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);

    // draw the text
    Button_Text = new QGraphicsTextItem(Button_name,this);
    int x_Position = rect().width()/2 - Button_Text->boundingRect().width()/2;
    int y_Position = rect().height()/2 - Button_Text->boundingRect().height()/2;
    Button_Text->setPos(x_Position,y_Position);

    // allow responding to hover events
    setAcceptHoverEvents(true);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event){
    emit clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    // change color to cyan
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::cyan);
    setBrush(brush);
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    // change color to dark cyan
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);
}
