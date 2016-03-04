/****************************************************************************
** Meta object code from reading C++ file 'gestione_dvd.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "View/gestione_dvd.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gestione_dvd.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Gestione_DVD_t {
    QByteArrayData data[12];
    char stringdata[172];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Gestione_DVD_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Gestione_DVD_t qt_meta_stringdata_Gestione_DVD = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 15),
QT_MOC_LITERAL(2, 29, 0),
QT_MOC_LITERAL(3, 30, 15),
QT_MOC_LITERAL(4, 46, 16),
QT_MOC_LITERAL(5, 63, 13),
QT_MOC_LITERAL(6, 77, 13),
QT_MOC_LITERAL(7, 91, 14),
QT_MOC_LITERAL(8, 106, 16),
QT_MOC_LITERAL(9, 123, 10),
QT_MOC_LITERAL(10, 134, 4),
QT_MOC_LITERAL(11, 139, 31)
    },
    "Gestione_DVD\0signalInsertDVD\0\0"
    "signalRemoveDVD\0signalReplaceDVD\0"
    "slotInsertDVD\0slotRemoveDVD\0slotReplaceDVD\0"
    "slotReplaceDVD_c\0slotNewDVD\0DVD*\0"
    "slotReplaceDigitalVersatileDisk\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Gestione_DVD[] = {

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

void Gestione_DVD::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Gestione_DVD *_t = static_cast<Gestione_DVD *>(_o);
        switch (_id) {
        case 0: _t->signalInsertDVD(); break;
        case 1: _t->signalRemoveDVD(); break;
        case 2: _t->signalReplaceDVD(); break;
        case 3: _t->slotInsertDVD(); break;
        case 4: _t->slotRemoveDVD(); break;
        case 5: _t->slotReplaceDVD(); break;
        case 6: _t->slotReplaceDVD_c(); break;
        case 7: { DVD* _r = _t->slotNewDVD();
            if (_a[0]) *reinterpret_cast< DVD**>(_a[0]) = _r; }  break;
        case 8: { DVD* _r = _t->slotReplaceDigitalVersatileDisk();
            if (_a[0]) *reinterpret_cast< DVD**>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Gestione_DVD::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Gestione_DVD::signalInsertDVD)) {
                *result = 0;
            }
        }
        {
            typedef void (Gestione_DVD::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Gestione_DVD::signalRemoveDVD)) {
                *result = 1;
            }
        }
        {
            typedef void (Gestione_DVD::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Gestione_DVD::signalReplaceDVD)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject Gestione_DVD::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Gestione_DVD.data,
      qt_meta_data_Gestione_DVD,  qt_static_metacall, 0, 0}
};


const QMetaObject *Gestione_DVD::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Gestione_DVD::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Gestione_DVD.stringdata))
        return static_cast<void*>(const_cast< Gestione_DVD*>(this));
    return QDialog::qt_metacast(_clname);
}

int Gestione_DVD::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Gestione_DVD::signalInsertDVD()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Gestione_DVD::signalRemoveDVD()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Gestione_DVD::signalReplaceDVD()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
