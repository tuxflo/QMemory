#include "memory_card.h"

memory_card::memory_card(const std::string& picture_path, QObject *parent)
{
    QPixmap pix(picture_path.c_str());
    if(pix.isNull())
        qDebug() << "Error picture not found!";
    _size = pix.size();
    _picture = pix;
    setPixmap(_picture);
    setGraphicsItem(this);
    setAcceptsHoverEvents(true);
}

memory_card::~memory_card()
{
    qDebug() << "memory_card Destructor!";
}

QSizeF memory_card::size()
{
    return _size;
}

void memory_card::mirror_picture()
{
    QImage i = _picture.toImage();
    i = i.mirrored(true, false);
    _picture = QPixmap::fromImage(i);
    setPixmap(_picture);
}

QSizeF memory_card::sizeHint(Qt::SizeHint which, const QSizeF &constraint) const
{
    switch (which) {
    case Qt::MinimumSize:
    case Qt::PreferredSize:
        // Do not allow a size smaller than the pixmap with two frames around it.
        return _size + QSize(12, 12);
    case Qt::MaximumSize:
        return QSizeF(1000,1000);
    default:
        break;
    }
    return constraint;
}

void memory_card::setGeometry(const QRectF &rect)
{
    prepareGeometryChange();
     QGraphicsLayoutItem::setGeometry(rect);
     setPos(rect.topLeft());
}

QRectF memory_card::boundingRect()
{
    return QRectF(0, 0, _size.width(), _size.height());
}

void memory_card::setrotationAngleY(qreal angle)
{
    if (_rotationAngleY != angle)
    {
        _rotationAngleY = angle;
        QPointF c = boundingRect().center();
        QTransform t;
        t.translate(c.x(), c.y());
        t.rotate(_rotationAngleY, Qt::YAxis);
        t.translate(-c.x(), -c.y());
        setTransform(t);
    }
}

qreal memory_card::rotationAngle() const
{
    return _rotationAngleY;
}

void memory_card::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
        emit clicked();
}

void memory_card::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    emit hovered(QRectF(this->x(), this->y(), this->size().width(), this->size().height()));
}

void memory_card::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    emit hover_leave();
}
