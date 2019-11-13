#include "Button.h"
#include <QGraphicsTextItem>
#include <QBrush>
#include <QFont>
#include <QFontDatabase>

Button::Button(QString name, QGraphicsItem *parent): QGraphicsRectItem(parent) {
    // draw the button
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::transparent);
    setBrush(brush);

    // draw the text
    text = new QGraphicsTextItem(name,this);
    text->setDefaultTextColor(QColor(255,255,255,255));
    QFont font("Planet N Compact",30);
    text->setFont(font);
    int textWidth = text->boundingRect().width();
    int textHeight = text->boundingRect().height();
    setRect(0,0,textWidth+8,textHeight+8);
    text->setPos(4,4);

    setAcceptHoverEvents(true);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if(event->button() == Qt::LeftButton) {
        emit clicked();
    }
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    text->setDefaultTextColor(QColor(125,125,125,255));
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {
    text->setDefaultTextColor(QColor(255,255,255,255));
}
