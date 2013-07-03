/****************************************************************************
** Meta object code from reading C++ file 'guiwindow.h'
**
** Created: Mon Jun 24 16:03:46 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "guiwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'guiwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GuiWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x08,
      20,   10,   10,   10, 0x08,
      27,   10,   10,   10, 0x08,
      34,   10,   10,   10, 0x08,
      49,   10,   10,   10, 0x08,
      66,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_GuiWindow[] = {
    "GuiWindow\0\0sphere()\0cube()\0cone()\0"
    "domainEditor()\0boundaryEditor()\0clear()\0"
};

void GuiWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        GuiWindow *_t = static_cast<GuiWindow *>(_o);
        switch (_id) {
        case 0: _t->sphere(); break;
        case 1: _t->cube(); break;
        case 2: _t->cone(); break;
        case 3: _t->domainEditor(); break;
        case 4: _t->boundaryEditor(); break;
        case 5: _t->clear(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData GuiWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject GuiWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_GuiWindow,
      qt_meta_data_GuiWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GuiWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GuiWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GuiWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GuiWindow))
        return static_cast<void*>(const_cast< GuiWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int GuiWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
