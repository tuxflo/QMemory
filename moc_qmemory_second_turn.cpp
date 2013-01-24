/****************************************************************************
** Meta object code from reading C++ file 'qmemory_second_turn.h'
**
** Created: Thu Jan 24 11:07:16 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qmemory_second_turn.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qmemory_second_turn.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Qmemory_second_turn[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Qmemory_second_turn[] = {
    "Qmemory_second_turn\0\0turn_back()\0"
};

void Qmemory_second_turn::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Qmemory_second_turn *_t = static_cast<Qmemory_second_turn *>(_o);
        switch (_id) {
        case 0: _t->turn_back(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Qmemory_second_turn::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Qmemory_second_turn::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Qmemory_second_turn,
      qt_meta_data_Qmemory_second_turn, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Qmemory_second_turn::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Qmemory_second_turn::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Qmemory_second_turn::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Qmemory_second_turn))
        return static_cast<void*>(const_cast< Qmemory_second_turn*>(this));
    if (!strcmp(_clname, "QMemory_State"))
        return static_cast< QMemory_State*>(const_cast< Qmemory_second_turn*>(this));
    return QObject::qt_metacast(_clname);
}

int Qmemory_second_turn::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
