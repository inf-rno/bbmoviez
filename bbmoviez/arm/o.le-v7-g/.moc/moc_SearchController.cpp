/****************************************************************************
** Meta object code from reading C++ file 'SearchController.h'
**
** Created: Sat Apr 13 18:55:00 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/controllers/home/SearchController.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SearchController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SearchController[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      44,   35,   17,   17, 0x0a,
      60,   17,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_SearchController[] = {
    "SearchController\0\0searchResolved()\0"
    "criteria\0search(QString)\0test()\0"
};

void SearchController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SearchController *_t = static_cast<SearchController *>(_o);
        switch (_id) {
        case 0: _t->searchResolved(); break;
        case 1: _t->search((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->test(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SearchController::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SearchController::staticMetaObject = {
    { &Controller::staticMetaObject, qt_meta_stringdata_SearchController,
      qt_meta_data_SearchController, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SearchController::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SearchController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SearchController::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SearchController))
        return static_cast<void*>(const_cast< SearchController*>(this));
    return Controller::qt_metacast(_clname);
}

int SearchController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Controller::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void SearchController::searchResolved()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
