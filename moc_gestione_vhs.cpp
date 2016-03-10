/****************************************************************************
** Meta object code from reading C++ file 'gestione_vhs.h'
**
** Created: Thu Mar 10 11:40:22 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "View/gestione_vhs.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gestione_vhs.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Gestione_VHS[] = {

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
      14,   13,   13,   13, 0x05,
      32,   13,   13,   13, 0x05,
      50,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      69,   13,   13,   13, 0x0a,
      85,   13,   13,   13, 0x0a,
     101,   13,   13,   13, 0x0a,
     118,   13,   13,   13, 0x0a,
     142,   13,  137,   13, 0x0a,
     155,   13,  137,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Gestione_VHS[] = {
    "Gestione_VHS\0\0signalInsertVHS()\0"
    "signalRemoveVHS()\0signalReplaceVHS()\0"
    "slotInsertVHS()\0slotRemoveVHS()\0"
    "slotReplaceVHS()\0slotReplaceVHS_c()\0"
    "VHS*\0slotNewVHS()\0slotReplaceVideoCassetta()\0"
};

void Gestione_VHS::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Gestione_VHS *_t = static_cast<Gestione_VHS *>(_o);
        switch (_id) {
        case 0: _t->signalInsertVHS(); break;
        case 1: _t->signalRemoveVHS(); break;
        case 2: _t->signalReplaceVHS(); break;
        case 3: _t->slotInsertVHS(); break;
        case 4: _t->slotRemoveVHS(); break;
        case 5: _t->slotReplaceVHS(); break;
        case 6: _t->slotReplaceVHS_c(); break;
        case 7: { VHS* _r = _t->slotNewVHS();
            if (_a[0]) *reinterpret_cast< VHS**>(_a[0]) = _r; }  break;
        case 8: { VHS* _r = _t->slotReplaceVideoCassetta();
            if (_a[0]) *reinterpret_cast< VHS**>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Gestione_VHS::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Gestione_VHS::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Gestione_VHS,
      qt_meta_data_Gestione_VHS, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Gestione_VHS::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Gestione_VHS::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Gestione_VHS::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Gestione_VHS))
        return static_cast<void*>(const_cast< Gestione_VHS*>(this));
    return QDialog::qt_metacast(_clname);
}

int Gestione_VHS::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Gestione_VHS::signalInsertVHS()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Gestione_VHS::signalRemoveVHS()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Gestione_VHS::signalReplaceVHS()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
