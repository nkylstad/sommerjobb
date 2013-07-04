/****************************************************************************
** Meta object code from reading C++ file 'GeometryInfo.h'
**
** Created: Wed Jul 3 15:58:48 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "GeometryInfo.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GeometryInfo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GeometryInfo[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_GeometryInfo[] = {
    "GeometryInfo\0"
};

void GeometryInfo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData GeometryInfo::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GeometryInfo::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GeometryInfo,
      qt_meta_data_GeometryInfo, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GeometryInfo::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GeometryInfo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GeometryInfo::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GeometryInfo))
        return static_cast<void*>(const_cast< GeometryInfo*>(this));
    return QObject::qt_metacast(_clname);
}

int GeometryInfo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_GeometryInfoDecorator[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      43,   37,   23,   22, 0x0a,
      75,   65,   22,   22, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GeometryInfoDecorator[] = {
    "GeometryInfoDecorator\0\0GeometryInfo*\0"
    "count\0new_GeometryInfo(int)\0info,list\0"
    "setDataList(GeometryInfo*,double*)\0"
};

void GeometryInfoDecorator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GeometryInfoDecorator *_t = static_cast<GeometryInfoDecorator *>(_o);
        switch (_id) {
        case 0: { GeometryInfo* _r = _t->new_GeometryInfo((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< GeometryInfo**>(_a[0]) = _r; }  break;
        case 1: _t->setDataList((*reinterpret_cast< GeometryInfo*(*)>(_a[1])),(*reinterpret_cast< double*(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData GeometryInfoDecorator::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GeometryInfoDecorator::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GeometryInfoDecorator,
      qt_meta_data_GeometryInfoDecorator, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GeometryInfoDecorator::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GeometryInfoDecorator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GeometryInfoDecorator::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GeometryInfoDecorator))
        return static_cast<void*>(const_cast< GeometryInfoDecorator*>(this));
    return QObject::qt_metacast(_clname);
}

int GeometryInfoDecorator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
