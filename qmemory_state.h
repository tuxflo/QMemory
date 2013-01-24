#ifndef QMEMORY_STATE_H
#define QMEMORY_STATE_H
#include "./include/view_state.h"

class Memory_Widget;
class QMemory_State : public View_State
{
public:
    QMemory_State(Memory_Widget *memory_widget);
    virtual ~QMemory_State(){}

    virtual void turn(int row, int column)=0;

protected:
    Memory_Widget *_memory_widget;
};

#endif // QMEMORY_STATE_H
