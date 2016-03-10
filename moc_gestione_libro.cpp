/****************************************************************************
** Meta object code from reading C++ file 'gestione_libro.h'
**
** Created: Thu Mar 10 11:40:21 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "View/gestione_libro.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gestione_libro.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Gestione_Libro[] = {

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
      16,   15,   15,   15, 0x05,
      36,   15,   15,   15, 0x05,
      56,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      77,   15,   15,   15, 0x0a,
      93,   15,   15,   15, 0x0a,
     109,   15,   15,   15, 0x0a,
     126,   15,   15,   15, 0x0a,
     152,   15,  145,   15, 0x0a,
     167,   15,  145,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Gestione_Libro[] = {
    "Gestione_Libro\0\0signalInsertLibro()\0"
    "signalRemoveLibro()\0signalReplaceLibro()\0"
    "slotInsertLib()\0slotRemoveLib()\0"
    "slotReplaceLib()\0slotReplaceLib_c()\0"
    "Libro*\0slotNewLibro()\0slotReplaceLibro()\0"
};

void Gestione_Libro::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Gestione_Libro *_t = static_cast<Gestione_Libro *>(_o);
        switch (_id) {
        case 0: _t->signalInsertLibro(); break;
        case 1: _t->signalRemoveLibro(); break;
        case 2: _t->signalReplaceLibro(); break;
        case 3: _t->slotInsertLib(); break;
        case 4: _t->slotRemoveLib(); break;
        case 5: _t->slotReplaceLib(); break;
        case 6: _t->slotReplaceLib_c(); break;
        case 7: { Libro* _r = _t->slotNewLibro();
            if (_a[0]) *reinterpret_cast< Libro**>(_a[0]) = _r; }  break;
        case 8: { Libro* _r = _t->slotReplaceLibro();
            if (_a[0]) *reinterpret_cast< Libro**>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Gestione_Libro::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Gestione_Libro::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Gestione_Libro,
      qt_meta_data_Gestione_Libro, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Gestione_Libro::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Gestione_Libro::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Gestione_Libro::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Gestione_Libro))
        return static_cast<void*>(const_cast< Gestione_Libro*>(this));
    return QDialog::qt_metacast(_clname);
}

int Gestione_Libro::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Gestione_Libro::signalInsertLibro()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Gestione_Libro::signalRemoveLibro()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void Gestione_Libro::signalReplaceLibro()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
