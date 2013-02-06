#ifndef QMEMORY_SECOND_TURN_H
#define QMEMORY_SECOND_TURN_H

#include "qmemory_state.h"
#include <QObject>


class Memory_Widget;
class Qmemory_second_turn : public QObject, public QMemory_State
{
    Q_OBJECT
public:
    Qmemory_second_turn(Memory_Widget *memory_widget);
    ~Qmemory_second_turn();
    void turn(int row, int column);
private:
    bool _match;
signals:

public slots:
    void turn_back();
    void delete_effect();
};

#endif // QMEMORY_SECOND_TURN_H
