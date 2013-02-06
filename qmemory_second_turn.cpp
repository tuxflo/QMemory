#include "qmemory_second_turn.h"
#include "memory_widget.h"
#include <QTimer>
Qmemory_second_turn::Qmemory_second_turn(Memory_Widget *memory_widget)
    : QMemory_State(memory_widget), _match(false)
{
}

Qmemory_second_turn::~Qmemory_second_turn()
{
    qDebug() << "Qmemory_second_turn Destructor!";
}

void Qmemory_second_turn::turn(int row, int column)
{
    if(_memory_widget->_game->get_turned(row, column))
        return; //Card is already turned so do nothing
    _memory_widget->_second_card = _memory_widget->_cards[row][column];

    _memory_widget->turn(row, column);
    _memory_widget->_turnable = false;
    if(_memory_widget->_game->get_recieved_points() > 0)
    {
        qDebug() << "Cards match!";

        _memory_widget->_first_card->_shadow->setColor(Qt::red);
        _memory_widget->_first_card->_shadow->setEnabled(true);
        _memory_widget->_second_card->_shadow->setColor(Qt::red);
        _memory_widget->_second_card->_shadow->setEnabled(true);
        //QTimer::singleShot(1500, this, SLOT(delete_effect()));
        _memory_widget->_first_card = 0;
        _memory_widget->_second_card = 0;
        if(_memory_widget->_game->get_game_over())
        {
            _memory_widget->game_over();
        }
        _memory_widget->_turnable = true;
        _memory_widget->_state = &_memory_widget->_first_turn;


    }
    else
    {
        //The cards don't match so wait and turn them back
        QTimer::singleShot(1000, this, SLOT(turn_back()));
    }
}

void Qmemory_second_turn::turn_back()
{
    _memory_widget->_first_card->turn_back();
    _memory_widget->_second_card->turn_back();

    _memory_widget->_turnable = true;
    _memory_widget->_first_card = 0;
    _memory_widget->_second_card = 0;
    _memory_widget->_state = &_memory_widget->_first_turn;
}

void Qmemory_second_turn::delete_effect()
{
    _memory_widget->_first_card->_shadow->setEnabled(false);
    _memory_widget->_first_card->_shadow->setColor(Qt::lightGray);
    _memory_widget->_second_card->_shadow->setEnabled(false);
    _memory_widget->_second_card->_shadow->setColor(Qt::lightGray);
    _memory_widget->_first_card = 0;
    _memory_widget->_second_card = 0;

}
