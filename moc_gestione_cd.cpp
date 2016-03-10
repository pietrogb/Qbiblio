/****************************************************************************
** Meta object code from reading C++ file 'gestione_cd.h'
**
** Created: Thu Mar 10 11:40:20 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "View/gestione_cd.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gestione_cd.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Gestione_CD[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,
      30,   12,   12,   12, 0x05,
      47,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      65,   12,   12,   12, 0x0a,
      80,   12,   12,   12, 0x0a,
      95,   12,   12,   12, 0x0a,
     111,   12,   12,   12, 0x0a,
     133,   12,  129,   12, 0x0a,
     145,   12,  129,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Gestione_CD[] = {
    "Gestione_CD\0\0signalInsertCD()\0"
    "signalRemoveCD()\0signalReplaceCD()\0"
    "slotInsertCD()\0slotRemoveCD()\0"
    "slotReplaceCD()\0slotReplaceCD_c()\0CD*\0"
    "slotNewCD()\0slotReplaceCompactDisk()\0"
};

void Gestione_CD::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
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
    }
}

const QMetaObjectExtraData Gestione_CD::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Gestione_CD::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Gestione_CD,
      qt_meta_data_Gestione_CD, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Gestione_CD::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Gestione_CD::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Gestione_CD::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Gestione_CD))
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
