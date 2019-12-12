#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

/*!
 * \brief The Button class allows to create buttons
 */
class Button : public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    /*! 
     * \brief Constructor
     * \param name The name of the button
     * \param parent The pointer on the parent item
     */
    Button(QString name, QGraphicsItem *parent = nullptr);

    /*!
     * \brief Method used to receive left clicks on buttons
     * \param event Pointer on the event received
     */
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    
    /*!
     * \brief Method used to know if the mouse entered a button
     * \param event Pointer on the event received
     */
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    
    /*!
     * \brief Method used to know if the mouse left a button
     * \param event Pointer on the event received
     */
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

    /*!
     * \brief Method used to reset the hover of a button
     */
    void resetHover();

    /*!
     * \brief Method used to change the text of a button and adapt the rect to it
     */
    void setText(QString newText);

    signals:
    		/*!
             * \brief Method used when a button is clicked
             */
            void clicked();

private:
	/*!
     * \brief text Pointer on the text in the button
     */
    QGraphicsTextItem *text;
};

#endif // BUTTON_H
