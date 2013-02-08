#ifndef MEMORY_CARD_H
#define MEMORY_CARD_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsSceneMouseEvent>
#include <QPropertyAnimation>
#include <QGraphicsDropShadowEffect>
#include <QGraphicsLayoutItem>
#include <QGraphicsSvgItem>
#include <QSvgRenderer>
#include <QPainter>

class MemoryCard : public QGraphicsObject, public QGraphicsLayoutItem
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsLayoutItem)
    Q_PROPERTY(qreal rotationAngle READ rotationAngle WRITE setRotationAngle)
public:
    explicit MemoryCard(int row, int column, const std::string& picture_path, const std::string& cover_path , QObject *parent);
    MemoryCard(QObject *parent=0);
    ~MemoryCard();
    int get_row();
    int get_column();
    void turn();
    void turn_back();
    QSize get_size();
    void set_duration(int duration);
    qreal rotationAngle() const;
    QGraphicsDropShadowEffect *_shadow;
    QSize _size;



protected:
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);


    QSizeF sizeHint(Qt::SizeHint which, const QSizeF &constraint) const;
    void setGeometry(const QRectF &rect);

private:
    int _row;
    int _column;
    QGraphicsSvgItem _picture;
    QGraphicsSvgItem _cover;
    QGraphicsSvgItem *_pix;
    QSvgRenderer *_renderer;
    QSvgRenderer *_renderer2;
    QSvgRenderer *_p_renderer;
    QRectF boundingRect()const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    qreal _rotationAngle;
    QPropertyAnimation *_picture_animation;
    QPropertyAnimation *_cover_animation;

    bool _turned;

    int _duration;

signals:
    //Tells which card is selected
    void selected_change(int, int, bool);
    void clicked(int, int);

public slots:
    void paint_cover();
    void set_selected(bool selected);
    void setRotationAngle(qreal angle);


};

#endif // MEMORY_CARD_H
