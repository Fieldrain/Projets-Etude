/****************************************************************************
** Meta object code from reading C++ file 'parametretest.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Ui/parametretest.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'parametretest.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ParametreTest_t {
    QByteArrayData data[20];
    char stringdata[534];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ParametreTest_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ParametreTest_t qt_meta_stringdata_ParametreTest = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 33),
QT_MOC_LITERAL(2, 48, 0),
QT_MOC_LITERAL(3, 49, 34),
QT_MOC_LITERAL(4, 84, 31),
QT_MOC_LITERAL(5, 116, 7),
QT_MOC_LITERAL(6, 124, 28),
QT_MOC_LITERAL(7, 153, 26),
QT_MOC_LITERAL(8, 180, 40),
QT_MOC_LITERAL(9, 221, 4),
QT_MOC_LITERAL(10, 226, 44),
QT_MOC_LITERAL(11, 271, 40),
QT_MOC_LITERAL(12, 312, 31),
QT_MOC_LITERAL(13, 344, 8),
QT_MOC_LITERAL(14, 353, 41),
QT_MOC_LITERAL(15, 395, 35),
QT_MOC_LITERAL(16, 431, 32),
QT_MOC_LITERAL(17, 464, 5),
QT_MOC_LITERAL(18, 470, 38),
QT_MOC_LITERAL(19, 509, 24)
    },
    "ParametreTest\0on_buttonAjouterParametre_clicked\0"
    "\0on_buttonModifierParametre_clicked\0"
    "on_radioButtonParametre_clicked\0checked\0"
    "on_radioButtonValeur_clicked\0"
    "on_radioButtonDate_clicked\0"
    "on_comboBoxOperation_currentIndexChanged\0"
    "arg1\0on_comboBoxFirstOperande_currentIndexChanged\0"
    "on_comboBoxParametre_currentIndexChanged\0"
    "on_dateTimeEdit_dateTimeChanged\0"
    "dateTime\0on_dateTimeEditIntervalle_dateTimeChanged\0"
    "on_doubleSpinBoxValeur_valueChanged\0"
    "on_listViewParametreTest_clicked\0index\0"
    "on_listViewParametreTest_doubleClicked\0"
    "on_buttonValider_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ParametreTest[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    1,   86,    2, 0x08 /* Private */,
       6,    1,   89,    2, 0x08 /* Private */,
       7,    1,   92,    2, 0x08 /* Private */,
       8,    1,   95,    2, 0x08 /* Private */,
      10,    1,   98,    2, 0x08 /* Private */,
      11,    1,  101,    2, 0x08 /* Private */,
      12,    1,  104,    2, 0x08 /* Private */,
      14,    1,  107,    2, 0x08 /* Private */,
      15,    1,  110,    2, 0x08 /* Private */,
      16,    1,  113,    2, 0x08 /* Private */,
      18,    1,  116,    2, 0x08 /* Private */,
      19,    0,  119,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QDateTime,   13,
    QMetaType::Void, QMetaType::QDateTime,   13,
    QMetaType::Void, QMetaType::Double,    9,
    QMetaType::Void, QMetaType::QModelIndex,   17,
    QMetaType::Void, QMetaType::QModelIndex,   17,
    QMetaType::Void,

       0        // eod
};

void ParametreTest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ParametreTest *_t = static_cast<ParametreTest *>(_o);
        switch (_id) {
        case 0: _t->on_buttonAjouterParametre_clicked(); break;
        case 1: _t->on_buttonModifierParametre_clicked(); break;
        case 2: _t->on_radioButtonParametre_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_radioButtonValeur_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_radioButtonDate_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_comboBoxOperation_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_comboBoxFirstOperande_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_comboBoxParametre_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->on_dateTimeEdit_dateTimeChanged((*reinterpret_cast< const QDateTime(*)>(_a[1]))); break;
        case 9: _t->on_dateTimeEditIntervalle_dateTimeChanged((*reinterpret_cast< const QDateTime(*)>(_a[1]))); break;
        case 10: _t->on_doubleSpinBoxValeur_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->on_listViewParametreTest_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 12: _t->on_listViewParametreTest_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 13: _t->on_buttonValider_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject ParametreTest::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ParametreTest.data,
      qt_meta_data_ParametreTest,  qt_static_metacall, 0, 0}
};


const QMetaObject *ParametreTest::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ParametreTest::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ParametreTest.stringdata))
        return static_cast<void*>(const_cast< ParametreTest*>(this));
    if (!strcmp(_clname, "Vue"))
        return static_cast< Vue*>(const_cast< ParametreTest*>(this));
    return QWidget::qt_metacast(_clname);
}

int ParametreTest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
