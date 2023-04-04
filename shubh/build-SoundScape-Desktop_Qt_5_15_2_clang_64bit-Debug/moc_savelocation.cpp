/****************************************************************************
** Meta object code from reading C++ file 'savelocation.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../SoundScape/savelocation.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'savelocation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_saveLocation_t {
    QByteArrayData data[15];
    char stringdata0[216];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_saveLocation_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_saveLocation_t qt_meta_stringdata_saveLocation = {
    {
QT_MOC_LITERAL(0, 0, 12), // "saveLocation"
QT_MOC_LITERAL(1, 13, 14), // "handleMySignal"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 3), // "lat"
QT_MOC_LITERAL(4, 33, 3), // "lng"
QT_MOC_LITERAL(5, 37, 28), // "on_pushButton_cancel_clicked"
QT_MOC_LITERAL(6, 66, 37), // "on_pushButton_saveNewLocation..."
QT_MOC_LITERAL(7, 104, 12), // "checkOverlap"
QT_MOC_LITERAL(8, 117, 18), // "location::Location"
QT_MOC_LITERAL(9, 136, 14), // "targetLocation"
QT_MOC_LITERAL(10, 151, 9), // "toRadians"
QT_MOC_LITERAL(11, 161, 7), // "degrees"
QT_MOC_LITERAL(12, 169, 13), // "distanceCheck"
QT_MOC_LITERAL(13, 183, 15), // "currentLocation"
QT_MOC_LITERAL(14, 199, 16) // "playlistLocation"

    },
    "saveLocation\0handleMySignal\0\0lat\0lng\0"
    "on_pushButton_cancel_clicked\0"
    "on_pushButton_saveNewLocation_clicked\0"
    "checkOverlap\0location::Location\0"
    "targetLocation\0toRadians\0degrees\0"
    "distanceCheck\0currentLocation\0"
    "playlistLocation"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_saveLocation[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x0a /* Public */,
       5,    0,   49,    2, 0x08 /* Private */,
       6,    0,   50,    2, 0x08 /* Private */,
       7,    1,   51,    2, 0x08 /* Private */,
      10,    1,   54,    2, 0x08 /* Private */,
      12,    2,   57,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, 0x80000000 | 8,    9,
    QMetaType::Double, QMetaType::Double,   11,
    QMetaType::Double, 0x80000000 | 8, 0x80000000 | 8,   13,   14,

       0        // eod
};

void saveLocation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<saveLocation *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->handleMySignal((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 1: _t->on_pushButton_cancel_clicked(); break;
        case 2: _t->on_pushButton_saveNewLocation_clicked(); break;
        case 3: { bool _r = _t->checkOverlap((*reinterpret_cast< location::Location(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: { double _r = _t->toRadians((*reinterpret_cast< double(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 5: { double _r = _t->distanceCheck((*reinterpret_cast< location::Location(*)>(_a[1])),(*reinterpret_cast< location::Location(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject saveLocation::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_saveLocation.data,
    qt_meta_data_saveLocation,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *saveLocation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *saveLocation::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_saveLocation.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int saveLocation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
