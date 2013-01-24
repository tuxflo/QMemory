#ifndef MYGRIDLAYOUT_H
#define MYGRIDLAYOUT_H

#include <QGraphicsGridLayout>
#include "doubleside_card.h"

class MyGridLayout : public QObject, public QGraphicsGridLayout
{
    Q_OBJECT
public:
    explicit MyGridLayout(QObject *parent = 0);
    ~MyGridLayout();
    void addCard(Doubleside_Card *card, int row, int column);
signals:
    
public slots:
    
};

#endif // MYGRIDLAYOUT_H
