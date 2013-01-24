#ifndef DOUBLESIDE_CARD_H
#define DOUBLESIDE_CARD_H

#include <QGraphicsLayoutItem>
#include <QPropertyAnimation>
#include <QTimer>
#include <QGraphicsSceneMouseEvent>
#include "memory_card.h"

//Class with a picture on "front" and one on the "back"
class Doubleside_Card : public QObject, public QGraphicsLayoutItem
{
    Q_OBJECT
public:
    explicit Doubleside_Card(const std::string& picture_path, const std::string& cover_path, int row, int column, QObject *parent = 0);
    ~Doubleside_Card();
    memory_card *get_picture();
    memory_card *get_cover();
    QSizeF get_size();
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    QSizeF sizeHint(Qt::SizeHint which, const QSizeF &constraint) const;
private:
    memory_card *_picture;
    memory_card *_cover;

    QPropertyAnimation *_picture_ani;
    QPropertyAnimation *_cover_ani;

    QSizeF _size;
    int _row;
    int _column;

    bool _turned;

signals:
    void clicked();
    void card_clicked(int row, int column);
    void cover_animation_finished();
    void hover_event(QRectF rect);
    void hover_leave_event();

public slots:
    void turn_card();
    void set_cover_Zvalue_down();
    void set_cover_Zvalue_up();
    void turn_back();
    void animation_finished();
    void hovered(QRectF rect);
    void hover_left();

};

#endif // DOUBLESIDE_CARD_H
