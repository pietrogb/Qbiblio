/****************************************************************************
** Meta object code from reading C++ file 'trova_elemento.h'
**
** Created: Thu Mar 10 11:40:23 2016
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "View/trova_elemento.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'trova_elemento.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Trova_Elemento[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Trova_Elemento[] = {
    "Trova_Elemento\0\0slot_pushButton_search()\0"
};

void Trova_Elemento::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Trova_Elemento *_t = static_cast<Trova_Elemento *>(_o);
        switch (_id) {
        case 0: _t->slot_pushButton_search(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Trova_Elemento::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Trova_Elemento::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Trova_Elemento,
      qt_meta_data_Trova_Elemento, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Trova_Elemento::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Trova_Elemento::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Trova_Elemento::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Trova_Elemento))
        return static_cast<void*>(const_cast< Trova_Elemento*>(this));
    return QDialog::qt_metacast(_clname);
}

int Trova_Elemento::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
