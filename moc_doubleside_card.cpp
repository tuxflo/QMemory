/****************************************************************************
** Meta object code from reading C++ file 'doubleside_card.h'
**
** Created: Thu Jan 24 15:20:18 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "doubleside_card.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'doubleside_card.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Doubleside_Card[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x05,
      38,   27,   16,   16, 0x05,
      60,   16,   16,   16, 0x05,
      92,   87,   16,   16, 0x05,
     112,   16,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
     132,   16,   16,   16, 0x0a,
     144,   16,   16,   16, 0x0a,
     168,   16,   16,   16, 0x0a,
     190,   16,   16,   16, 0x0a,
     202,   16,   16,   16, 0x0a,
     223,   87,   16,   16, 0x0a,
     239,   16,   16,   16, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Doubleside_Card[] = {
    "Doubleside_Card\0\0clicked()\0row,column\0"
    "card_clicked(int,int)\0cover_animation_finished()\0"
    "rect\0hover_event(QRectF)\0hover_leave_event()\0"
    "turn_card()\0set_cover_Zvalue_down()\0"
    "set_cover_Zvalue_up()\0turn_back()\0"
    "animation_finished()\0hovered(QRectF)\0"
    "hover_left()\0"
};

void Doubleside_Card::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Doubleside_Card *_t = static_cast<Doubleside_Card *>(_o);
        switch (_id) {
        case 0: _t->clicked(); break;
        case 1: _t->card_clicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->cover_animation_finished(); break;
        case 3: _t->hover_event((*reinterpret_cast< QRectF(*)>(_a[1]))); break;
        case 4: _t->hover_leave_event(); break;
        case 5: _t->turn_card(); break;
        case 6: _t->set_cover_Zvalue_down(); break;
        case 7: _t->set_cover_Zvalue_up(); break;
        case 8: _t->turn_back(); break;
        case 9: _t->animation_finished(); break;
        case 10: _t->hovered((*reinterpret_cast< QRectF(*)>(_a[1]))); break;
        case 11: _t->hover_left(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Doubleside_Card::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Doubleside_Card::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Doubleside_Card,
      qt_meta_data_Doubleside_Card, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Doubleside_Card::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Doubleside_Card::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Doubleside_Card::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Doubleside_Card))
        return static_cast<void*>(const_cast< Doubleside_Card*>(this));
    if (!strcmp(_clname, "QGraphicsLayoutItem"))
        return static_cast< QGraphicsLayoutItem*>(const_cast< Doubleside_Card*>(this));
    return QObject::qt_metacast(_clname);
}

int Doubleside_Card::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void Doubleside_Card::clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Doubleside_Card::card_clicked(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Doubleside_Card::cover_animation_finished()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void Doubleside_Card::hover_event(QRectF _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Doubleside_Card::hover_leave_event()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE
