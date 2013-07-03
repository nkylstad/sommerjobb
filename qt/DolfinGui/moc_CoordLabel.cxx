/****************************************************************************
** Meta object code from reading C++ file 'CoordLabel.h'
**
** Created: Tue Jul 2 10:09:26 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "CoordLabel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CoordLabel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CoordLabel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      26,   24,   11,   11, 0x0a,
      45,   42,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CoordLabel[] = {
    "CoordLabel\0\0setNum(int)\0,\0setNum(int,int)\0"
    ",,\0setNum(double,double,double)\0"
};

void CoordLabel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CoordLabel *_t = static_cast<CoordLabel *>(_o);
        switch (_id) {
        case 0: _t->setNum((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->setNum((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->setNum((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CoordLabel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CoordLabel::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_CoordLabel,
      qt_meta_data_CoordLabel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CoordLabel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CoordLabel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CoordLabel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CoordLabel))
        return static_cast<void*>(const_cast< CoordLabel*>(this));
    return QLabel::qt_metacast(_clname);
}

int CoordLabel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
