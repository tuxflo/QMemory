#include "memory_card.h"

MemoryCard::MemoryCard(int row, int column, const std::string& picture_path, const std::string& cover_path, QObject *parent) :
    _row(row),
    _column(column),
    _cover(cover_path.c_str()),
    _turned(false),
    _duration(200)

{
    //Mirror the image for displaying right after turning
    QImage mirrored_image(picture_path.c_str());
    mirrored_image = mirrored_image.mirrored(true, false);
    _picture = QPixmap::fromImage(mirrored_image);


    setFlag(QGraphicsItem::ItemIsSelectable);
    setAcceptHoverEvents(true);
    _picture_animation = new QPropertyAnimation(this, "rotationAngle");
    _cover_animation = new QPropertyAnimation(this, "rotationAngle");
    _pix = &_cover;

    _shadow = new QGraphicsDropShadowEffect();
    _shadow->setOffset(0, 0);
    _shadow->setBlurRadius(45);
    _shadow->setEnabled(false);
    _shadow->setColor(Qt::yellow);

    setGraphicsEffect(_shadow);
    setGraphicsItem(this);
}

MemoryCard::MemoryCard(QObject *parent)
{
}

MemoryCard::~MemoryCard()
{
    delete _picture_animation;
    delete _cover_animation;
}

int MemoryCard::get_row()
{
    return _row;
}

int MemoryCard::get_column()
{
    return _column;
}

void MemoryCard::turn()
{
    if(!_turned)
    {
    //Turning Animation
    _picture_animation->setDuration(_duration);
    _picture_animation->setStartValue(0);
    _picture_animation->setEndValue(90);

    _cover_animation->setDuration(_duration);
    _cover_animation->setStartValue(90);
    _cover_animation->setEndValue(180);
    connect(_picture_animation, SIGNAL(finished()), this, SLOT(paint_cover()));
    connect(_picture_animation, SIGNAL(finished()), _cover_animation, SLOT(start()));
    _picture_animation->start();
    _turned = true;
    }
}

void MemoryCard::turn_back()
{
    _turned = false;
    _picture_animation->setStartValue(180);
    _picture_animation->setEndValue(90);

    _cover_animation->setStartValue(90);
    _cover_animation->setEndValue(0);
    _picture_animation->start();

}

QSize MemoryCard::get_size()
{
    return _cover.size();
}

void MemoryCard::set_duration(int duration)
{
    _duration = duration/2;
}

void MemoryCard::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    emit selected_change(_row, _column, true);
    event->setAccepted(true);
}

void MemoryCard::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    emit selected_change(_row, _column, false);
    event->setAccepted(true);
}

void MemoryCard::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit selected_change(_row, _column, true);
    emit clicked(_row, _column);
    event->setAccepted(true);
}

void MemoryCard::setRotationAngle(qreal angle)
{
    if (_rotationAngle != angle)
    {
        _rotationAngle = angle;
        QPointF c = boundingRect().center();
        QTransform t;
        t.translate(c.x(), c.y());
        t.rotate(_rotationAngle, Qt::YAxis);
        t.translate(-c.x(), -c.y());
        setTransform(t);
    }
}

qreal MemoryCard::rotationAngle() const
{
    return _rotationAngle;
}

QSizeF MemoryCard::sizeHint(Qt::SizeHint which, const QSizeF &constraint) const
{
    switch (which) {
    case Qt::MinimumSize:
    case Qt::PreferredSize:
        // Do not allow a size smaller than the pixmap with two frames around it.
        return _cover.size() + QSize(12, 12);
    case Qt::MaximumSize:
        return QSizeF(1000,1000);
    default:
        break;
    }
    return constraint;
}

void MemoryCard::setGeometry(const QRectF &rect)
{
    prepareGeometryChange();
    QGraphicsLayoutItem::setGeometry(rect);
    setPos(rect.topLeft());
}

QRectF MemoryCard::boundingRect() const
{
    return _cover.rect();
}


void MemoryCard::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->drawPixmap(0, 0, *_pix);
}


void MemoryCard::paint_cover()
{
    if(_turned)
        _pix = &_picture;
    else
        _pix = &_cover;
}

void MemoryCard::set_selected(bool selected)
{
    setSelected(selected);
    _shadow->setEnabled(selected);
}
