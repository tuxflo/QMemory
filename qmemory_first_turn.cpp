#include "qmemory_first_turn.h"
#include "memory_widget.h"
Qmemory_first_turn::Qmemory_first_turn(Memory_Widget *memory_widget)
    : QMemory_State(memory_widget)
{
}

Qmemory_first_turn::~Qmemory_first_turn()
{
    qDebug() << "Qmemory_first_turn Destructor!";
}

void Qmemory_first_turn::turn(int row, int column)
{
    if(_memory_widget->_game->get_turned(row, column))
        return; //Card is already turned so do nothing
    _memory_widget->turn(row, column);
    _memory_widget->_first_card = _memory_widget->_cards[row][column];
    _memory_widget->_state = &_memory_widget->_second_turn;
}
