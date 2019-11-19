#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class Button : public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    // constructor
    Button(QString name, QGraphicsItem *parent = NULL);

    // methods
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);

    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

    void setText(QString newText);

    signals:
            void clicked();

private:
    QGraphicsTextItem *text;
};

#endif // BUTTON_H
