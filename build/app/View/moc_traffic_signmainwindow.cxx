/****************************************************************************
** Meta object code from reading C++ file 'traffic_signmainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../app/View/traffic_signmainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'traffic_signmainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Traffic_signMainWindow[] = {

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
      24,   23,   23,   23, 0x08,
      49,   23,   23,   23, 0x08,
      73,   23,   23,   23, 0x08,
      96,   23,   23,   23, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Traffic_signMainWindow[] = {
    "Traffic_signMainWindow\0\0"
    "on_VideoButton_clicked()\0"
    "on_ExitButton_clicked()\0on_RunButton_clicked()\0"
    "run()\0"
};

void Traffic_signMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Traffic_signMainWindow *_t = static_cast<Traffic_signMainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_VideoButton_clicked(); break;
        case 1: _t->on_ExitButton_clicked(); break;
        case 2: _t->on_RunButton_clicked(); break;
        case 3: _t->run(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Traffic_signMainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Traffic_signMainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Traffic_signMainWindow,
      qt_meta_data_Traffic_signMainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Traffic_signMainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Traffic_signMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Traffic_signMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Traffic_signMainWindow))
        return static_cast<void*>(const_cast< Traffic_signMainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Traffic_signMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
