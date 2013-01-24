#ifndef QMEMORY_FIRST_TURN_H
#define QMEMORY_FIRST_TURN_H

#include "qmemory_state.h"

class Memory_Widget;
class Qmemory_first_turn : public QMemory_State
{
public:
    explicit Qmemory_first_turn(Memory_Widget *memory_widget);

    ~Qmemory_first_turn();
    void turn(int row, int column);

};

#endif // QMEMORY_FIRST_TURN_H
