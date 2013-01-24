#include "doubleside_card.h"

Doubleside_Card::Doubleside_Card(const std::string& picture_path, const std::string& cover_path, int row, int column, QObject *parent)
{
    _picture = new memory_card(picture_path, this);
    _cover = new memory_card(cover_path, this);
    _picture->mirror_picture();
    _size = _picture->size();

    _picture_ani = new QPropertyAnimation(_picture, "rotatingAngleY");
    _picture_ani->setDuration(400);
    _picture_ani->setStartValue(0);
    _picture_ani->setEndValue(180);

    _cover_ani = new QPropertyAnimation(_cover, "rotatingAngleY");
    _cover_ani->setDuration(400);
    _cover_ani->setStartValue(0);
    _cover_ani->setEndValue(180);

    connect(_cover, SIGNAL(clicked()), this, SLOT(animation_finished()));

    connect(_cover, SIGNAL(hovered(QRectF)), this, SLOT(hovered(QRectF)));
    connect(_picture, SIGNAL(hovered(QRectF)), this, SLOT(hovered(QRectF)));
    connect(_cover, SIGNAL(hover_leave()), this, SLOT(hover_left()));
    connect(_picture, SIGNAL(hover_leave()), this, SLOT(hover_left()));
    _row = row;
    _column = column;
    _turned = false;
}

Doubleside_Card::~Doubleside_Card()
{
    qDebug() << "Doubleside_Card Destructor!";
    delete _cover;
    delete _picture;
    delete _picture_ani;
    delete _cover_ani;
}

memory_card *Doubleside_Card::get_picture()
{
    return _picture;
}

memory_card *Doubleside_Card::get_cover()
{
    return _cover;
}

QSizeF Doubleside_Card::get_size()
{
    return _size;
}

void Doubleside_Card::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
        emit clicked();
}

QSizeF Doubleside_Card::sizeHint(Qt::SizeHint which, const QSizeF &constraint) const
{
    switch (which) {
    case Qt::MinimumSize:
    case Qt::PreferredSize:
        // Do not allow a size smaller than the pixmap with two frames around it.
        return _cover->size() + QSize(12, 12);
    case Qt::MaximumSize:
        return QSizeF(1000,1000);
    default:
        break;
    }
    return constraint;
}

void Doubleside_Card::turn_card()
{
    _picture_ani->setDuration(400);
    _picture_ani->setStartValue(0);
    _picture_ani->setEndValue(180);

    _cover_ani->setDuration(400);
    _cover_ani->setStartValue(0);
    _cover_ani->setEndValue(180);

    _picture_ani->start();
    _cover_ani->start();

    QTimer::singleShot(200, this, SLOT(set_cover_Zvalue_down()));
    connect(_cover_ani, SIGNAL(finished()), this, SLOT(animation_finished()));
}

void Doubleside_Card::set_cover_Zvalue_down()
{
    _cover->setZValue(-1);
}

void Doubleside_Card::set_cover_Zvalue_up()
{

    _cover->setZValue(0);
}

void Doubleside_Card::turn_back()
{
    _picture_ani->setStartValue(180);
    _picture_ani->setEndValue(0);

    _cover_ani->setStartValue(180);
    _cover_ani->setEndValue(0);

    _picture_ani->start();
    _cover_ani->start();

    _turned = false;
    QTimer::singleShot(200, this, SLOT(set_cover_Zvalue_up()));

}

void Doubleside_Card::animation_finished()
{
    emit card_clicked(_row, _column);
    _turned = true;
    _cover_ani->disconnect();
}

void Doubleside_Card::hovered(QRectF rect)
{
    if(!_turned)
        emit hover_event(rect);
}

void Doubleside_Card::hover_left()
{
     emit hover_leave_event();
}


