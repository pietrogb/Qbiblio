/****************************************************************************
** Meta object code from reading C++ file 'gestione_cd.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "View/gestione_cd.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gestione_cd.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Gestione_CD_t {
    QByteArrayData data[12];
    char stringdata[153];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Gestione_CD_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Gestione_CD_t qt_meta_stringdata_Gestione_CD = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 14),
QT_MOC_LITERAL(2, 27, 0),
QT_MOC_LITERAL(3, 28, 14),
QT_MOC_LITERAL(4, 43, 15),
QT_MOC_LITERAL(5, 59, 12),
QT_MOC_LITERAL(6, 72, 12),
QT_MOC_LITERAL(7, 85, 13),
QT_MOC_LITERAL(8, 99, 15),
QT_MOC_LITERAL(9, 115, 9),
QT_MOC_LITERAL(10, 125, 3),
QT_MOC_LITERAL(11, 129, 22)
    },
    "Gestione_CD\0signalInsertCD\0\0signalRemoveCD\0"
    "signalReplaceCD\0slotInsertCD\0slotRemoveCD\0"
    "slotReplaceCD\0slotReplaceCD_c\0slotNewCD\0"
    "CD*\0slotReplaceCompactDisk\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Gestione_CD[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06,
       3,    0,   60,    2, 0x06,
       4,    0,   61,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       5,    0,   62,    2, 0x0a,
       6,    0,   63,    2, 0x0a,
       7,    0,   64,    2, 0x0a,
       8,    0,   65,    2, 0x0a,
       9,    0,   66,    2, 0x0a,
      11,    0,   67,    2, 0x0a,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 10,
    0x80000000 | 10,

       0        // eod
};

void Gestione_CD::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Gestione_CD *_t = static_cast<Gestione_CD *>(_o);
        switch (_id) {
        case 0: _t->signalInsertCD(); break;
        case 1: _t->signalRemoveCD(); break;
        case 2: _t->signalReplaceCD(); break;
        case 3: _t->slotInsertCD(); break;
        case 4: _t->slotRemoveCD(); break;
        case 5: _t->slotReplaceCD(); break;
        case 6: _t->slotReplaceCD_c(); break;
        case 7: { CD* _r = _t->slotNewCD();
            if (_a[0]) *reinterpret_cast< CD**>(_a[0]) = _r; }  break;
        case 8: { CD* _r = _t->slotReplaceCompactDisk();
            if (_a[0]) *reinterpret_cast< CD**>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Gestione_CD::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Gestione_CD::signalInsertCD)) {
                *result = 0;
            }
        }
        {
            typedef void (Gestione_CD::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Gestione_CD::signalRemoveCD)) {
                *result = 1;
            }
        }
        {
            typedef void (Gestione_CD::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Gestione_CD::signalReplaceCD)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject Gestione_CD::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Gestione_CD.data,
      qt_meta_data_Gestione_CD,  qt_static_metacall, 0, 0}
};


const QMetaObject *Gestione_CD::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Gestione_CD::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Gestione_CD.stringdata))
        return static_cast<void*>(const_cast< Gestione_CD*>(this));
    return QDialog::qt_metacast(_clname);
}

int Gestione_CD::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Gestione_CD::signalInsertCD()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Gestione_CD::signalRemoveCD()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Gestione_CD::signalReplaceCD()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
