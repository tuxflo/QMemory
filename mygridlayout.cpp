#include "mygridlayout.h"

MyGridLayout::MyGridLayout(QObject *parent) :
    QGraphicsGridLayout()
{
}

MyGridLayout::~MyGridLayout()
{
    qDebug() << "MyGrid Destructor!";
    while(itemAt(0) != 0)
        delete itemAt(0);
    qDebug() << "after Deletion";
}

void MyGridLayout::addCard(Doubleside_Card *card, int row, int column)
{
    addItem(card->get_picture(), row, column);
    addItem(card->get_cover(), row, column);
}
