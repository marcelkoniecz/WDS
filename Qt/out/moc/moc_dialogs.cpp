/****************************************************************************
** Meta object code from reading C++ file 'dialogs.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../inc/dialogs.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogs.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_settDialog_t {
    QByteArrayData data[6];
    char stringdata0[88];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_settDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_settDialog_t qt_meta_stringdata_settDialog = {
    {
QT_MOC_LITERAL(0, 0, 10), // "settDialog"
QT_MOC_LITERAL(1, 11, 17), // "EmitSettingsSaved"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 21), // "on_saveButton_clicked"
QT_MOC_LITERAL(4, 52, 23), // "on_returnButton_clicked"
QT_MOC_LITERAL(5, 76, 11) // "retranslate"

    },
    "settDialog\0EmitSettingsSaved\0\0"
    "on_saveButton_clicked\0on_returnButton_clicked\0"
    "retranslate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_settDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   35,    2, 0x0a /* Public */,
       4,    0,   36,    2, 0x0a /* Public */,
       5,    0,   37,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void settDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        settDialog *_t = static_cast<settDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->EmitSettingsSaved(); break;
        case 1: _t->on_saveButton_clicked(); break;
        case 2: _t->on_returnButton_clicked(); break;
        case 3: _t->retranslate(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (settDialog::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&settDialog::EmitSettingsSaved)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject settDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_settDialog.data,
      qt_meta_data_settDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *settDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *settDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_settDialog.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::settDialog"))
        return static_cast< Ui::settDialog*>(this);
    return QDialog::qt_metacast(_clname);
}

int settDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void settDialog::EmitSettingsSaved()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_endDialog_t {
    QByteArrayData data[9];
    char stringdata0[145];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_endDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_endDialog_t qt_meta_stringdata_endDialog = {
    {
QT_MOC_LITERAL(0, 0, 9), // "endDialog"
QT_MOC_LITERAL(1, 10, 11), // "EmitClosing"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 15), // "EmitRestartGame"
QT_MOC_LITERAL(4, 39, 18), // "EmitOpenStatistics"
QT_MOC_LITERAL(5, 58, 27), // "on_statisticsButton_clicked"
QT_MOC_LITERAL(6, 86, 24), // "on_restartButton_clicked"
QT_MOC_LITERAL(7, 111, 21), // "on_exitButton_clicked"
QT_MOC_LITERAL(8, 133, 11) // "retranslate"

    },
    "endDialog\0EmitClosing\0\0EmitRestartGame\0"
    "EmitOpenStatistics\0on_statisticsButton_clicked\0"
    "on_restartButton_clicked\0on_exitButton_clicked\0"
    "retranslate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_endDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    0,   50,    2, 0x06 /* Public */,
       4,    0,   51,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   52,    2, 0x0a /* Public */,
       6,    0,   53,    2, 0x0a /* Public */,
       7,    0,   54,    2, 0x0a /* Public */,
       8,    0,   55,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void endDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        endDialog *_t = static_cast<endDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->EmitClosing(); break;
        case 1: _t->EmitRestartGame(); break;
        case 2: _t->EmitOpenStatistics(); break;
        case 3: _t->on_statisticsButton_clicked(); break;
        case 4: _t->on_restartButton_clicked(); break;
        case 5: _t->on_exitButton_clicked(); break;
        case 6: _t->retranslate(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (endDialog::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&endDialog::EmitClosing)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (endDialog::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&endDialog::EmitRestartGame)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (endDialog::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&endDialog::EmitOpenStatistics)) {
                *result = 2;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject endDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_endDialog.data,
      qt_meta_data_endDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *endDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *endDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_endDialog.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::endGameDialog"))
        return static_cast< Ui::endGameDialog*>(this);
    return QDialog::qt_metacast(_clname);
}

int endDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void endDialog::EmitClosing()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void endDialog::EmitRestartGame()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void endDialog::EmitOpenStatistics()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
struct qt_meta_stringdata_disDialog_t {
    QByteArrayData data[6];
    char stringdata0[96];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_disDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_disDialog_t qt_meta_stringdata_disDialog = {
    {
QT_MOC_LITERAL(0, 0, 9), // "disDialog"
QT_MOC_LITERAL(1, 10, 20), // "EmitDisconnectDevice"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 27), // "on_disconnectButton_clicked"
QT_MOC_LITERAL(4, 60, 23), // "on_cancelButton_clicked"
QT_MOC_LITERAL(5, 84, 11) // "retranslate"

    },
    "disDialog\0EmitDisconnectDevice\0\0"
    "on_disconnectButton_clicked\0"
    "on_cancelButton_clicked\0retranslate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_disDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   35,    2, 0x0a /* Public */,
       4,    0,   36,    2, 0x0a /* Public */,
       5,    0,   37,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void disDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        disDialog *_t = static_cast<disDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->EmitDisconnectDevice(); break;
        case 1: _t->on_disconnectButton_clicked(); break;
        case 2: _t->on_cancelButton_clicked(); break;
        case 3: _t->retranslate(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (disDialog::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&disDialog::EmitDisconnectDevice)) {
                *result = 0;
                return;
            }
        }
    }
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
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void disDialog::EmitDisconnectDevice()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
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
QT_MOC_LITERAL(3, 26, 29), // "on_searchDeviceButton_clicked"
QT_MOC_LITERAL(4, 56, 23), // "on_cancelButton_clicked"
QT_MOC_LITERAL(5, 80, 24), // "on_connectButton_clicked"
QT_MOC_LITERAL(6, 105, 11) // "retranslate"

    },
    "conDialog\0EmitChoosenDev\0\0"
    "on_searchDeviceButton_clicked\0"
    "on_cancelButton_clicked\0"
    "on_connectButton_clicked\0retranslate"
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
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   42,    2, 0x0a /* Public */,
       4,    0,   43,    2, 0x0a /* Public */,
       5,    0,   44,    2, 0x0a /* Public */,
       6,    0,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
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
        case 1: _t->on_searchDeviceButton_clicked(); break;
        case 2: _t->on_cancelButton_clicked(); break;
        case 3: _t->on_connectButton_clicked(); break;
        case 4: _t->retranslate(); break;
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
