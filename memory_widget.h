#ifndef MEMORY_WIDGET_H
#define MEMORY_WIDGET_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QHBoxLayout>
#include <QGraphicsWidget>
#include <QDialog>
#include <QDebug>
#include <QGraphicsGridLayout>
#include <QTimer>
#include "qmemory_first_turn.h"

#include "./include/view.h"
#include "./include/game_interface.h"
#include "qmemory_first_turn.h"
#include "qmemory_second_turn.h"
#include "memory_card.h"

class Memory_Widget : public QWidget, public View
{
    friend class Qmemory_first_turn;
    friend class Qmemory_second_turn;
    Q_OBJECT
public:
    explicit Memory_Widget(Game_Interface *game);
    ~Memory_Widget();
    virtual void update();
    virtual void turn(int row, int column);
    virtual bool set_cards();
    virtual void view_board();
    virtual void play();
    virtual void game_over();
    bool eventFilter(QObject *object, QEvent *event);

protected:

private:
    void set_players();
    QHBoxLayout *_layout;
    QGraphicsView *_view;
    QGraphicsScene *_scene;

    MemoryCard ***_cards;

    //The Graphicswidget is needed for the gridlayout
    QGraphicsWidget *_graphics_widget;

    Game_Interface *_game;

    QGraphicsGridLayout _grid;


    //States
    Qmemory_first_turn _first_turn;
    Qmemory_second_turn _second_turn;

    MemoryCard *_first_card;
    MemoryCard *_second_card;
    bool _turnable;

    QGraphicsRectItem *_hover;

signals:
    void update_StatusBar_points(QString string);
private slots:
    void turn_card(int row, int column);
    void hover_card(QRectF rect);
    void hover_leave();

    void selection_change(int row, int column, bool selected);

    void game_over_animation();
    
};

#endif // MEMORY_WIDGET_H
