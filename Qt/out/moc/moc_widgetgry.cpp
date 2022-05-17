/****************************************************************************
** Meta object code from reading C++ file 'widgetgry.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../inc/widgetgry.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widgetgry.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_disDialog_t {
    QByteArrayData data[1];
    char stringdata0[10];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_disDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_disDialog_t qt_meta_stringdata_disDialog = {
    {
QT_MOC_LITERAL(0, 0, 9) // "disDialog"

    },
    "disDialog"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_disDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void disDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject disDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_disDialog.data,
      qt_meta_data_disDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *disDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *disDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_disDialog.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::disDialog"))
        return static_cast< Ui::disDialog*>(this);
    return QDialog::qt_metacast(_clname);
}

int disDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_conDialog_t {
    QByteArrayData data[7];
    char stringdata0[117];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_conDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_conDialog_t qt_meta_stringdata_conDialog = {
    {
QT_MOC_LITERAL(0, 0, 9), // "conDialog"
QT_MOC_LITERAL(1, 10, 14), // "EmitChoosenDev"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 11), // "EmitClosing"
QT_MOC_LITERAL(4, 38, 29), // "on_searchDeviceButton_clicked"
QT_MOC_LITERAL(5, 68, 23), // "on_cancelButton_clicked"
QT_MOC_LITERAL(6, 92, 24) // "on_connectButton_clicked"

    },
    "conDialog\0EmitChoosenDev\0\0EmitClosing\0"
    "on_searchDeviceButton_clicked\0"
    "on_cancelButton_clicked\0"
    "on_connectButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_conDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       3,    0,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   43,    2, 0x0a /* Public */,
       5,    0,   44,    2, 0x0a /* Public */,
       6,    0,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void conDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        conDialog *_t = static_cast<conDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->EmitChoosenDev((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->EmitClosing(); break;
        case 2: _t->on_searchDeviceButton_clicked(); break;
        case 3: _t->on_cancelButton_clicked(); break;
        case 4: _t->on_connectButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (conDialog::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&conDialog::EmitChoosenDev)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (conDialog::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&conDialog::EmitClosing)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject conDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_conDialog.data,
      qt_meta_data_conDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *conDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *conDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_conDialog.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::conDialog"))
        return static_cast< Ui::conDialog*>(this);
    return QDialog::qt_metacast(_clname);
}

int conDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void conDialog::EmitChoosenDev(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void conDialog::EmitClosing()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
struct qt_meta_stringdata_mainGameWidget_t {
    QByteArrayData data[3];
    char stringdata0[20];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mainGameWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mainGameWidget_t qt_meta_stringdata_mainGameWidget = {
    {
QT_MOC_LITERAL(0, 0, 14), // "mainGameWidget"
QT_MOC_LITERAL(1, 15, 3), // "tak"
QT_MOC_LITERAL(2, 19, 0) // ""

    },
    "mainGameWidget\0tak\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mainGameWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void mainGameWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        mainGameWidget *_t = static_cast<mainGameWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->tak(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject mainGameWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_mainGameWidget.data,
      qt_meta_data_mainGameWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *mainGameWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mainGameWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_mainGameWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int mainGameWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_gameWidget_t {
    QByteArrayData data[7];
    char stringdata0[64];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_gameWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_gameWidget_t qt_meta_stringdata_gameWidget = {
    {
QT_MOC_LITERAL(0, 0, 10), // "gameWidget"
QT_MOC_LITERAL(1, 11, 11), // "EmitClosing"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 10), // "EndProgram"
QT_MOC_LITERAL(4, 35, 10), // "updateTime"
QT_MOC_LITERAL(5, 46, 9), // "writeTime"
QT_MOC_LITERAL(6, 56, 7) // "EndGame"

    },
    "gameWidget\0EmitClosing\0\0EndProgram\0"
    "updateTime\0writeTime\0EndGame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_gameWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   40,    2, 0x0a /* Public */,
       4,    0,   41,    2, 0x0a /* Public */,
       5,    0,   42,    2, 0x0a /* Public */,
       6,    0,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void gameWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        gameWidget *_t = static_cast<gameWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->EmitClosing(); break;
        case 1: _t->EndProgram(); break;
        case 2: _t->updateTime(); break;
        case 3: _t->writeTime(); break;
        case 4: _t->EndGame(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (gameWidget::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&gameWidget::EmitClosing)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject gameWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_gameWidget.data,
      qt_meta_data_gameWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *gameWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *gameWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_gameWidget.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::gameWidget"))
        return static_cast< Ui::gameWidget*>(this);
    return QWidget::qt_metacast(_clname);
}

int gameWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void gameWidget::EmitClosing()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_mainWidget_t {
    QByteArrayData data[1];
    char stringdata0[11];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mainWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mainWidget_t qt_meta_stringdata_mainWidget = {
    {
QT_MOC_LITERAL(0, 0, 10) // "mainWidget"

    },
    "mainWidget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mainWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void mainWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject mainWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_mainWidget.data,
      qt_meta_data_mainWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *mainWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mainWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_mainWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int mainWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_gameWindow_t {
    QByteArrayData data[8];
    char stringdata0[132];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_gameWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_gameWindow_t qt_meta_stringdata_gameWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "gameWindow"
QT_MOC_LITERAL(1, 11, 27), // "on_actionSettings_triggered"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 26), // "on_actionConnect_triggered"
QT_MOC_LITERAL(4, 67, 29), // "on_actionDisconnect_triggered"
QT_MOC_LITERAL(5, 97, 10), // "initDevice"
QT_MOC_LITERAL(6, 108, 7), // "devName"
QT_MOC_LITERAL(7, 116, 15) // "ReadTransmision"

    },
    "gameWindow\0on_actionSettings_triggered\0"
    "\0on_actionConnect_triggered\0"
    "on_actionDisconnect_triggered\0initDevice\0"
    "devName\0ReadTransmision"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_gameWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x0a /* Public */,
       3,    0,   40,    2, 0x0a /* Public */,
       4,    0,   41,    2, 0x0a /* Public */,
       5,    1,   42,    2, 0x0a /* Public */,
       7,    0,   45,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,

       0        // eod
};

void gameWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        gameWindow *_t = static_cast<gameWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actionSettings_triggered(); break;
        case 1: _t->on_actionConnect_triggered(); break;
        case 2: _t->on_actionDisconnect_triggered(); break;
        case 3: _t->initDevice((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->ReadTransmision(); break;
        default: ;
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
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
