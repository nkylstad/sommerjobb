/****************************************************************************
** Meta object code from reading C++ file 'Plotter.h'
**
** Created: Tue Jul 2 16:25:33 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "Plotter.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Plotter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Plotter[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x05,
      21,    8,    8,    8, 0x05,
      40,   37,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      75,   71,    8,    8, 0x08,
     102,   71,    8,    8, 0x08,
     129,    8,    8,    8, 0x0a,
     142,    8,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Plotter[] = {
    "Plotter\0\0cellId(int)\0cellPicked(int)\0"
    ",,\0worldPos(double,double,double)\0x,y\0"
    "receiveMouseMoved(int,int)\0"
    "receiveMousePress(int,int)\0toggleMesh()\0"
    "update()\0"
};

void Plotter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Plotter *_t = static_cast<Plotter *>(_o);
        switch (_id) {
        case 0: _t->cellId((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->cellPicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->worldPos((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 3: _t->receiveMouseMoved((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->receiveMousePress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->toggleMesh(); break;
        case 6: _t->update(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Plotter::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Plotter::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Plotter,
      qt_meta_data_Plotter, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Plotter::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Plotter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Plotter::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Plotter))
        return static_cast<void*>(const_cast< Plotter*>(this));
    if (!strcmp(_clname, "dolfin::VTKPlotter"))
        return static_cast< dolfin::VTKPlotter*>(const_cast< Plotter*>(this));
    return QObject::qt_metacast(_clname);
}

int Plotter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Plotter::cellId(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Plotter::cellPicked(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Plotter::worldPos(double _t1, double _t2, double _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
static const uint qt_meta_data_PlotterDecorators[] = {

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
      39,   28,   19,   18, 0x0a,
     101,   97,   19,   18, 0x2a,
     156,  150,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_PlotterDecorators[] = {
    "PlotterDecorators\0\0Plotter*\0obj,parent\0"
    "new_Plotter(boost::shared_ptr<dolfin::Variable>,QWidget*)\0"
    "obj\0new_Plotter(boost::shared_ptr<dolfin::Variable>)\0"
    "p,obj\0static_plot(Plotter*,boost::shared_ptr<dolfin::Variable>)\0"
};

void PlotterDecorators::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PlotterDecorators *_t = static_cast<PlotterDecorators *>(_o);
        switch (_id) {
        case 0: { Plotter* _r = _t->new_Plotter((*reinterpret_cast< const boost::shared_ptr<dolfin::Variable>(*)>(_a[1])),(*reinterpret_cast< QWidget*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< Plotter**>(_a[0]) = _r; }  break;
        case 1: { Plotter* _r = _t->new_Plotter((*reinterpret_cast< const boost::shared_ptr<dolfin::Variable>(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< Plotter**>(_a[0]) = _r; }  break;
        case 2: _t->static_plot((*reinterpret_cast< Plotter*(*)>(_a[1])),(*reinterpret_cast< const boost::shared_ptr<dolfin::Variable>(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PlotterDecorators::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PlotterDecorators::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PlotterDecorators,
      qt_meta_data_PlotterDecorators, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PlotterDecorators::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PlotterDecorators::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PlotterDecorators::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PlotterDecorators))
        return static_cast<void*>(const_cast< PlotterDecorators*>(this));
    return QObject::qt_metacast(_clname);
}

int PlotterDecorators::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
