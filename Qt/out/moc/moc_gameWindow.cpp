/****************************************************************************
** Meta object code from reading C++ file 'gameWindow.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../inc/gameWindow.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gameWindow.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_gameWindow_t {
    QByteArrayData data[17];
    char stringdata0[268];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_gameWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_gameWindow_t qt_meta_stringdata_gameWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "gameWindow"
QT_MOC_LITERAL(1, 11, 15), // "EmitRestartGame"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 15), // "EmitRetranslate"
QT_MOC_LITERAL(4, 44, 16), // "EmitBlockButtons"
QT_MOC_LITERAL(5, 61, 27), // "on_actionSettings_triggered"
QT_MOC_LITERAL(6, 89, 26), // "on_actionConnect_triggered"
QT_MOC_LITERAL(7, 116, 29), // "on_actionDisconnect_triggered"
QT_MOC_LITERAL(8, 146, 10), // "initDevice"
QT_MOC_LITERAL(9, 157, 7), // "devName"
QT_MOC_LITERAL(10, 165, 15), // "ReadTransmision"
QT_MOC_LITERAL(11, 181, 11), // "restartGame"
QT_MOC_LITERAL(12, 193, 7), // "endGame"
QT_MOC_LITERAL(13, 201, 20), // "openStatisticsWidget"
QT_MOC_LITERAL(14, 222, 14), // "openGameWidget"
QT_MOC_LITERAL(15, 237, 16), // "disconnectDevice"
QT_MOC_LITERAL(16, 254, 13) // "checkLanguage"

    },
    "gameWindow\0EmitRestartGame\0\0EmitRetranslate\0"
    "EmitBlockButtons\0on_actionSettings_triggered\0"
    "on_actionConnect_triggered\0"
    "on_actionDisconnect_triggered\0initDevice\0"
    "devName\0ReadTransmision\0restartGame\0"
    "endGame\0openStatisticsWidget\0"
    "openGameWidget\0disconnectDevice\0"
    "checkLanguage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_gameWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    0,   85,    2, 0x06 /* Public */,
       4,    0,   86,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   87,    2, 0x0a /* Public */,
       6,    0,   88,    2, 0x0a /* Public */,
       7,    0,   89,    2, 0x0a /* Public */,
       8,    1,   90,    2, 0x0a /* Public */,
      10,    0,   93,    2, 0x0a /* Public */,
      11,    0,   94,    2, 0x0a /* Public */,
      12,    0,   95,    2, 0x0a /* Public */,
      13,    0,   96,    2, 0x0a /* Public */,
      14,    0,   97,    2, 0x0a /* Public */,
      15,    0,   98,    2, 0x0a /* Public */,
      16,    0,   99,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void gameWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        gameWindow *_t = static_cast<gameWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->EmitRestartGame(); break;
        case 1: _t->EmitRetranslate(); break;
        case 2: _t->EmitBlockButtons(); break;
        case 3: _t->on_actionSettings_triggered(); break;
        case 4: _t->on_actionConnect_triggered(); break;
        case 5: _t->on_actionDisconnect_triggered(); break;
        case 6: _t->initDevice((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->ReadTransmision(); break;
        case 8: _t->restartGame(); break;
        case 9: _t->endGame(); break;
        case 10: _t->openStatisticsWidget(); break;
        case 11: _t->openGameWidget(); break;
        case 12: _t->disconnectDevice(); break;
        case 13: _t->checkLanguage(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (gameWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&gameWindow::EmitRestartGame)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (gameWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&gameWindow::EmitRetranslate)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (gameWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&gameWindow::EmitBlockButtons)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject gameWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_gameWindow.data,
      qt_meta_data_gameWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *gameWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *gameWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_gameWindow.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::gameWindow"))
        return static_cast< Ui::gameWindow*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int gameWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void gameWindow::EmitRestartGame()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void gameWindow::EmitRetranslate()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void gameWindow::EmitBlockButtons()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
