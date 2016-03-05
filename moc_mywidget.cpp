/****************************************************************************
** Meta object code from reading C++ file 'mywidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "View/mywidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mywidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyWidget_t {
    QByteArrayData data[20];
    char stringdata[317];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MyWidget_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MyWidget_t qt_meta_stringdata_MyWidget = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 21),
QT_MOC_LITERAL(2, 31, 0),
QT_MOC_LITERAL(3, 32, 22),
QT_MOC_LITERAL(4, 55, 22),
QT_MOC_LITERAL(5, 78, 24),
QT_MOC_LITERAL(6, 103, 19),
QT_MOC_LITERAL(7, 123, 12),
QT_MOC_LITERAL(8, 136, 13),
QT_MOC_LITERAL(9, 150, 13),
QT_MOC_LITERAL(10, 164, 15),
QT_MOC_LITERAL(11, 180, 12),
QT_MOC_LITERAL(12, 193, 13),
QT_MOC_LITERAL(13, 207, 13),
QT_MOC_LITERAL(14, 221, 15),
QT_MOC_LITERAL(15, 237, 13),
QT_MOC_LITERAL(16, 251, 14),
QT_MOC_LITERAL(17, 266, 14),
QT_MOC_LITERAL(18, 281, 16),
QT_MOC_LITERAL(19, 298, 17)
    },
    "MyWidget\0slotGestioneCdQDialog\0\0"
    "slotGestioneDvdQDialog\0slotGestioneVhsQDialog\0"
    "slotGestioneLibroQDialog\0slotFindItemQDialog\0"
    "slotInsertCD\0slotInsertDVD\0slotInsertVHS\0"
    "slotInsertLibro\0slotRemoveCD\0slotRemoveDVD\0"
    "slotRemoveVHS\0slotRemoveLibro\0"
    "slotReplaceCD\0slotReplaceDVD\0"
    "slotReplaceVHS\0slotReplaceLibro\0"
    "updateTableResult\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x0a,
       3,    0,  105,    2, 0x0a,
       4,    0,  106,    2, 0x0a,
       5,    0,  107,    2, 0x0a,
       6,    0,  108,    2, 0x0a,
       7,    0,  109,    2, 0x0a,
       8,    0,  110,    2, 0x0a,
       9,    0,  111,    2, 0x0a,
      10,    0,  112,    2, 0x0a,
      11,    0,  113,    2, 0x0a,
      12,    0,  114,    2, 0x0a,
      13,    0,  115,    2, 0x0a,
      14,    0,  116,    2, 0x0a,
      15,    0,  117,    2, 0x0a,
      16,    0,  118,    2, 0x0a,
      17,    0,  119,    2, 0x0a,
      18,    0,  120,    2, 0x0a,
      19,    0,  121,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MyWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
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

const QMetaObject MyWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MyWidget.data,
      qt_meta_data_MyWidget,  qt_static_metacall, 0, 0}
};


const QMetaObject *MyWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyWidget.stringdata))
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
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
