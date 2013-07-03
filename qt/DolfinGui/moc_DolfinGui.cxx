/****************************************************************************
** Meta object code from reading C++ file 'DolfinGui.h'
**
** Created: Wed Jul 3 09:03:31 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "DolfinGui.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DolfinGui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DolfinGui[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      22,   10,   10,   10, 0x08,
      35,   10,   10,   10, 0x08,
      46,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DolfinGui[] = {
    "DolfinGui\0\0plotCube()\0plotSphere()\0"
    "plotCone()\0updatePlot()\0"
};

void DolfinGui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DolfinGui *_t = static_cast<DolfinGui *>(_o);
        switch (_id) {
        case 0: _t->plotCube(); break;
        case 1: _t->plotSphere(); break;
        case 2: _t->plotCone(); break;
        case 3: _t->updatePlot(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData DolfinGui::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DolfinGui::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_DolfinGui,
      qt_meta_data_DolfinGui, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DolfinGui::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DolfinGui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DolfinGui::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DolfinGui))
        return static_cast<void*>(const_cast< DolfinGui*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int DolfinGui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
