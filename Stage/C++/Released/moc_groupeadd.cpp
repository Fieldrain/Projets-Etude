/****************************************************************************
** Meta object code from reading C++ file 'groupeadd.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Ui/groupeadd.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'groupeadd.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_GroupeAdd_t {
    QByteArrayData data[10];
    char stringdata[182];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GroupeAdd_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GroupeAdd_t qt_meta_stringdata_GroupeAdd = {
    {
QT_MOC_LITERAL(0, 0, 9),
QT_MOC_LITERAL(1, 10, 27),
QT_MOC_LITERAL(2, 38, 0),
QT_MOC_LITERAL(3, 39, 4),
QT_MOC_LITERAL(4, 44, 30),
QT_MOC_LITERAL(5, 75, 25),
QT_MOC_LITERAL(6, 101, 5),
QT_MOC_LITERAL(7, 107, 22),
QT_MOC_LITERAL(8, 130, 26),
QT_MOC_LITERAL(9, 157, 24)
    },
    "GroupeAdd\0on_checkBoxNom_stateChanged\0"
    "\0arg1\0on_checkBoxGroupe_stateChanged\0"
    "on_listViewGroupe_clicked\0index\0"
    "on_buttonCreer_clicked\0"
    "listViewSelections_clicked\0"
    "on_buttonAnnuler_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GroupeAdd[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x08 /* Private */,
       4,    1,   47,    2, 0x08 /* Private */,
       5,    1,   50,    2, 0x08 /* Private */,
       7,    0,   53,    2, 0x08 /* Private */,
       8,    1,   54,    2, 0x08 /* Private */,
       9,    0,   57,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::QModelIndex,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    6,
    QMetaType::Void,

       0        // eod
};

void GroupeAdd::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GroupeAdd *_t = static_cast<GroupeAdd *>(_o);
        switch (_id) {
        case 0: _t->on_checkBoxNom_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_checkBoxGroupe_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_listViewGroupe_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 3: _t->on_buttonCreer_clicked(); break;
        case 4: _t->listViewSelections_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 5: _t->on_buttonAnnuler_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject GroupeAdd::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GroupeAdd.data,
      qt_meta_data_GroupeAdd,  qt_static_metacall, 0, 0}
};


const QMetaObject *GroupeAdd::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GroupeAdd::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GroupeAdd.stringdata))
        return static_cast<void*>(const_cast< GroupeAdd*>(this));
    if (!strcmp(_clname, "Vue"))
        return static_cast< Vue*>(const_cast< GroupeAdd*>(this));
    return QWidget::qt_metacast(_clname);
}

int GroupeAdd::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
