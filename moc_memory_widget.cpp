/****************************************************************************
** Meta object code from reading C++ file 'memory_widget.h'
**
** Created: Thu Jan 24 18:19:28 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "memory_widget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'memory_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Memory_Widget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   15,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
      66,   55,   14,   14, 0x08,
      90,   85,   14,   14, 0x08,
     109,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Memory_Widget[] = {
    "Memory_Widget\0\0string\0"
    "update_StatusBar_points(QString)\0"
    "row,column\0turn_card(int,int)\0rect\0"
    "hover_card(QRectF)\0hover_leave()\0"
};

void Memory_Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Memory_Widget *_t = static_cast<Memory_Widget *>(_o);
        switch (_id) {
        case 0: _t->update_StatusBar_points((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->turn_card((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->hover_card((*reinterpret_cast< QRectF(*)>(_a[1]))); break;
        case 3: _t->hover_leave(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Memory_Widget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Memory_Widget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Memory_Widget,
      qt_meta_data_Memory_Widget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Memory_Widget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Memory_Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Memory_Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Memory_Widget))
        return static_cast<void*>(const_cast< Memory_Widget*>(this));
    if (!strcmp(_clname, "View"))
        return static_cast< View*>(const_cast< Memory_Widget*>(this));
    return QWidget::qt_metacast(_clname);
}

int Memory_Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Memory_Widget::update_StatusBar_points(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
