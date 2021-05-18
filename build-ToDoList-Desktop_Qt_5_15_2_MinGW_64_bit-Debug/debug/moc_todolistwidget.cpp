/****************************************************************************
** Meta object code from reading C++ file 'todolistwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../src/todolistwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'todolistwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ToDoListWidget_t {
    QByteArrayData data[10];
    char stringdata0[103];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ToDoListWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ToDoListWidget_t qt_meta_stringdata_ToDoListWidget = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ToDoListWidget"
QT_MOC_LITERAL(1, 15, 10), // "createTask"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 8), // "editTask"
QT_MOC_LITERAL(4, 36, 10), // "deleteTask"
QT_MOC_LITERAL(5, 47, 12), // "compliteTask"
QT_MOC_LITERAL(6, 60, 15), // "setTaskPriority"
QT_MOC_LITERAL(7, 76, 9), // "addedTask"
QT_MOC_LITERAL(8, 86, 4), // "Task"
QT_MOC_LITERAL(9, 91, 11) // "editingTask"

    },
    "ToDoListWidget\0createTask\0\0editTask\0"
    "deleteTask\0compliteTask\0setTaskPriority\0"
    "addedTask\0Task\0editingTask"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ToDoListWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a /* Public */,
       3,    0,   50,    2, 0x0a /* Public */,
       4,    0,   51,    2, 0x0a /* Public */,
       5,    0,   52,    2, 0x0a /* Public */,
       6,    1,   53,    2, 0x0a /* Public */,
       7,    1,   56,    2, 0x08 /* Private */,
       9,    1,   59,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void, 0x80000000 | 8,    2,

       0        // eod
};

void ToDoListWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ToDoListWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->createTask(); break;
        case 1: _t->editTask(); break;
        case 2: _t->deleteTask(); break;
        case 3: _t->compliteTask(); break;
        case 4: _t->setTaskPriority((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->addedTask((*reinterpret_cast< const Task(*)>(_a[1]))); break;
        case 6: _t->editingTask((*reinterpret_cast< const Task(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ToDoListWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ToDoListWidget.data,
    qt_meta_data_ToDoListWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ToDoListWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ToDoListWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ToDoListWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ToDoListWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
