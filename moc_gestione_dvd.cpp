/****************************************************************************
** Meta object code from reading C++ file 'gestione_dvd.h'
**
** Created: Thu Mar 10 11:40:21 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "View/gestione_dvd.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gestione_dvd.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Gestione_DVD[] = {

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

static const char qt_meta_stringdata_Gestione_DVD[] = {
    "Gestione_DVD\0\0signalInsertDVD()\0"
    "signalRemoveDVD()\0signalReplaceDVD()\0"
    "slotInsertDVD()\0slotRemoveDVD()\0"
    "slotReplaceDVD()\0slotReplaceDVD_c()\0"
    "DVD*\0slotNewDVD()\0slotReplaceDigitalVersatileDisk()\0"
};

void Gestione_DVD::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
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
    }
}

const QMetaObjectExtraData Gestione_DVD::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Gestione_DVD::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Gestione_DVD,
      qt_meta_data_Gestione_DVD, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Gestione_DVD::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Gestione_DVD::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Gestione_DVD::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Gestione_DVD))
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
