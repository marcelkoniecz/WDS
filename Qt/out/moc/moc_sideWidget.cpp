/****************************************************************************
** Meta object code from reading C++ file 'sideWidget.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../inc/sideWidget.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sideWidget.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SidePanelWidget_t {
    QByteArrayData data[11];
    char stringdata0[129];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SidePanelWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SidePanelWidget_t qt_meta_stringdata_SidePanelWidget = {
    {
QT_MOC_LITERAL(0, 0, 15), // "SidePanelWidget"
QT_MOC_LITERAL(1, 16, 11), // "EmitClosing"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 11), // "EmitEndGame"
QT_MOC_LITERAL(4, 41, 10), // "EndProgram"
QT_MOC_LITERAL(5, 52, 10), // "updateTime"
QT_MOC_LITERAL(6, 63, 9), // "writeTime"
QT_MOC_LITERAL(7, 73, 7), // "EndGame"
QT_MOC_LITERAL(8, 81, 12), // "setTimerNull"
QT_MOC_LITERAL(9, 94, 16), // "retranslatePanel"
QT_MOC_LITERAL(10, 111, 17) // "checkBlockButtons"

    },
    "SidePanelWidget\0EmitClosing\0\0EmitEndGame\0"
    "EndProgram\0updateTime\0writeTime\0EndGame\0"
    "setTimerNull\0retranslatePanel\0"
    "checkBlockButtons"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SidePanelWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   61,    2, 0x0a /* Public */,
       5,    0,   62,    2, 0x0a /* Public */,
       6,    0,   63,    2, 0x0a /* Public */,
       7,    0,   64,    2, 0x0a /* Public */,
       8,    0,   65,    2, 0x0a /* Public */,
       9,    0,   66,    2, 0x0a /* Public */,
      10,    0,   67,    2, 0x0a /* Public */,

 // signals: parameters
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

       0        // eod
};

void SidePanelWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SidePanelWidget *_t = static_cast<SidePanelWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->EmitClosing(); break;
        case 1: _t->EmitEndGame(); break;
        case 2: _t->EndProgram(); break;
        case 3: _t->updateTime(); break;
        case 4: _t->writeTime(); break;
        case 5: _t->EndGame(); break;
        case 6: _t->setTimerNull(); break;
        case 7: _t->retranslatePanel(); break;
        case 8: _t->checkBlockButtons(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (SidePanelWidget::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SidePanelWidget::EmitClosing)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (SidePanelWidget::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SidePanelWidget::EmitEndGame)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject SidePanelWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_SidePanelWidget.data,
      qt_meta_data_SidePanelWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SidePanelWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SidePanelWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SidePanelWidget.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::sidePanelWidget"))
        return static_cast< Ui::sidePanelWidget*>(this);
    return QWidget::qt_metacast(_clname);
}

int SidePanelWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void SidePanelWidget::EmitClosing()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void SidePanelWidget::EmitEndGame()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
