/****************************************************************************
** Meta object code from reading C++ file 'loginwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../SoundScape/loginwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'loginwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LoginWindow_t {
    QByteArrayData data[20];
    char stringdata0[445];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LoginWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LoginWindow_t qt_meta_stringdata_LoginWindow = {
    {
QT_MOC_LITERAL(0, 0, 11), // "LoginWindow"
QT_MOC_LITERAL(1, 12, 19), // "saveLocationClicked"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 13), // "panToLocation"
QT_MOC_LITERAL(4, 47, 17), // "startWorkerThread"
QT_MOC_LITERAL(5, 65, 16), // "stopWorkerThread"
QT_MOC_LITERAL(6, 82, 12), // "callPlaySong"
QT_MOC_LITERAL(7, 95, 27), // "on_pushButton_login_clicked"
QT_MOC_LITERAL(8, 123, 31), // "on_pushButton_playlists_clicked"
QT_MOC_LITERAL(9, 155, 26), // "on_pushButton_coor_clicked"
QT_MOC_LITERAL(10, 182, 36), // "on_pushButton_createLocation_..."
QT_MOC_LITERAL(11, 219, 34), // "on_pushButton_editLocation_cl..."
QT_MOC_LITERAL(12, 254, 32), // "on_pushButton_createPMap_clicked"
QT_MOC_LITERAL(13, 287, 8), // "setLists"
QT_MOC_LITERAL(14, 296, 34), // "on_pushButton_refreshLists_cl..."
QT_MOC_LITERAL(15, 331, 19), // "handleWorkerMessage"
QT_MOC_LITERAL(16, 351, 1), // "s"
QT_MOC_LITERAL(17, 353, 31), // "on_pushButton_editPMaps_clicked"
QT_MOC_LITERAL(18, 385, 37), // "on_pushButton_refreshLocation..."
QT_MOC_LITERAL(19, 423, 21) // "on_pushButton_clicked"

    },
    "LoginWindow\0saveLocationClicked\0\0"
    "panToLocation\0startWorkerThread\0"
    "stopWorkerThread\0callPlaySong\0"
    "on_pushButton_login_clicked\0"
    "on_pushButton_playlists_clicked\0"
    "on_pushButton_coor_clicked\0"
    "on_pushButton_createLocation_clicked\0"
    "on_pushButton_editLocation_clicked\0"
    "on_pushButton_createPMap_clicked\0"
    "setLists\0on_pushButton_refreshLists_clicked\0"
    "handleWorkerMessage\0s\0"
    "on_pushButton_editPMaps_clicked\0"
    "on_pushButton_refreshLocation_clicked\0"
    "on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LoginWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x06 /* Public */,
       3,    0,  100,    2, 0x06 /* Public */,
       4,    0,  101,    2, 0x06 /* Public */,
       5,    0,  102,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,  103,    2, 0x0a /* Public */,
       7,    0,  104,    2, 0x08 /* Private */,
       8,    0,  105,    2, 0x08 /* Private */,
       9,    0,  106,    2, 0x08 /* Private */,
      10,    0,  107,    2, 0x08 /* Private */,
      11,    0,  108,    2, 0x08 /* Private */,
      12,    0,  109,    2, 0x08 /* Private */,
      13,    0,  110,    2, 0x08 /* Private */,
      14,    0,  111,    2, 0x08 /* Private */,
      15,    1,  112,    2, 0x08 /* Private */,
      17,    0,  115,    2, 0x08 /* Private */,
      18,    0,  116,    2, 0x08 /* Private */,
      19,    0,  117,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

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
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LoginWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LoginWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->saveLocationClicked(); break;
        case 1: _t->panToLocation(); break;
        case 2: _t->startWorkerThread(); break;
        case 3: _t->stopWorkerThread(); break;
        case 4: _t->callPlaySong(); break;
        case 5: _t->on_pushButton_login_clicked(); break;
        case 6: _t->on_pushButton_playlists_clicked(); break;
        case 7: _t->on_pushButton_coor_clicked(); break;
        case 8: _t->on_pushButton_createLocation_clicked(); break;
        case 9: _t->on_pushButton_editLocation_clicked(); break;
        case 10: _t->on_pushButton_createPMap_clicked(); break;
        case 11: _t->setLists(); break;
        case 12: _t->on_pushButton_refreshLists_clicked(); break;
        case 13: _t->handleWorkerMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->on_pushButton_editPMaps_clicked(); break;
        case 15: _t->on_pushButton_refreshLocation_clicked(); break;
        case 16: _t->on_pushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LoginWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LoginWindow::saveLocationClicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (LoginWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LoginWindow::panToLocation)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (LoginWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LoginWindow::startWorkerThread)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (LoginWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LoginWindow::stopWorkerThread)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LoginWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_LoginWindow.data,
    qt_meta_data_LoginWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LoginWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LoginWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LoginWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int LoginWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void LoginWindow::saveLocationClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void LoginWindow::panToLocation()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void LoginWindow::startWorkerThread()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void LoginWindow::stopWorkerThread()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
