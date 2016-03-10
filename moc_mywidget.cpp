/****************************************************************************
** Meta object code from reading C++ file 'mywidget.h'
**
** Created: Thu Mar 10 11:40:22 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "View/mywidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mywidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MyWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x0a,
      34,    9,    9,    9, 0x0a,
      59,    9,    9,    9, 0x0a,
      84,    9,    9,    9, 0x0a,
     111,    9,    9,    9, 0x0a,
     133,    9,    9,    9, 0x0a,
     148,    9,    9,    9, 0x0a,
     164,    9,    9,    9, 0x0a,
     180,    9,    9,    9, 0x0a,
     198,    9,    9,    9, 0x0a,
     213,    9,    9,    9, 0x0a,
     229,    9,    9,    9, 0x0a,
     245,    9,    9,    9, 0x0a,
     263,    9,    9,    9, 0x0a,
     279,    9,    9,    9, 0x0a,
     296,    9,    9,    9, 0x0a,
     313,    9,    9,    9, 0x0a,
     332,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MyWidget[] = {
    "MyWidget\0\0slotGestioneCdQDialog()\0"
    "slotGestioneDvdQDialog()\0"
    "slotGestioneVhsQDialog()\0"
    "slotGestioneLibroQDialog()\0"
    "slotFindItemQDialog()\0slotInsertCD()\0"
    "slotInsertDVD()\0slotInsertVHS()\0"
    "slotInsertLibro()\0slotRemoveCD()\0"
    "slotRemoveDVD()\0slotRemoveVHS()\0"
    "slotRemoveLibro()\0slotReplaceCD()\0"
    "slotReplaceDVD()\0slotReplaceVHS()\0"
    "slotReplaceLibro()\0updateTableResult()\0"
};

void MyWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MyWidget *_t = static_cast<MyWidget *>(_o);
        switch (_id) {
        case 0: _t->slotGestioneCdQDialog(); break;
        case 1: _t->slotGestioneDvdQDialog(); break;
        case 2: _t->slotGestioneVhsQDialog(); break;
        case 3: _t->slotGestioneLibroQDialog(); break;
        case 4: _t->slotFindItemQDialog(); break;
        case 5: _t->slotInsertCD(); break;
        case 6: _t->slotInsertDVD(); break;
        case 7: _t->slotInsertVHS(); break;
        case 8: _t->slotInsertLibro(); break;
        case 9: _t->slotRemoveCD(); break;
        case 10: _t->slotRemoveDVD(); break;
        case 11: _t->slotRemoveVHS(); break;
        case 12: _t->slotRemoveLibro(); break;
        case 13: _t->slotReplaceCD(); break;
        case 14: _t->slotReplaceDVD(); break;
        case 15: _t->slotReplaceVHS(); break;
        case 16: _t->slotReplaceLibro(); break;
        case 17: _t->updateTableResult(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MyWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MyWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MyWidget,
      qt_meta_data_MyWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MyWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MyWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MyWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyWidget))
        return static_cast<void*>(const_cast< MyWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int MyWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
