#ifndef MEMORY_CARD_H
#define MEMORY_CARD_H

#include <QGraphicsPixmapItem>
#include <QGraphicsLayoutItem>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QDebug>
#include <string>


//Class for a single Picture
class memory_card : public QObject, public QGraphicsPixmapItem, public QGraphicsLayoutItem
{
    Q_OBJECT
    Q_PROPERTY(qreal rotatingAngleY READ rotationAngle WRITE setrotationAngleY)

public:
    explicit memory_card(const std::string& picture_path, QObject *parent=0);
    ~memory_card();
    QSizeF size();
    void mirror_picture();

protected:
    QSizeF sizeHint(Qt::SizeHint which, const QSizeF &constraint) const;
    void setGeometry(const QRectF &rect);
    QRectF boundingRect();
    void setrotationAngleY(qreal angle);
    qreal rotationAngle() const;
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

private:
    QSizeF _size;
    QPixmap _picture;
    qreal _rotationAngleY;

    
signals:
    void clicked();
    void hovered(QRectF);
    void hover_leave();
    
public slots:
    
};

#endif // MEMORY_CARD_H
