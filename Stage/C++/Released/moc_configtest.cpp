/****************************************************************************
** Meta object code from reading C++ file 'configtest.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Ui/configtest.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'configtest.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ConfigTest_t {
    QByteArrayData data[17];
    char stringdata[417];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ConfigTest_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ConfigTest_t qt_meta_stringdata_ConfigTest = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 33),
QT_MOC_LITERAL(2, 45, 0),
QT_MOC_LITERAL(3, 46, 34),
QT_MOC_LITERAL(4, 81, 40),
QT_MOC_LITERAL(5, 122, 4),
QT_MOC_LITERAL(6, 127, 40),
QT_MOC_LITERAL(7, 168, 38),
QT_MOC_LITERAL(8, 207, 28),
QT_MOC_LITERAL(9, 236, 7),
QT_MOC_LITERAL(10, 244, 25),
QT_MOC_LITERAL(11, 270, 27),
QT_MOC_LITERAL(12, 298, 5),
QT_MOC_LITERAL(13, 304, 29),
QT_MOC_LITERAL(14, 334, 35),
QT_MOC_LITERAL(15, 370, 21),
QT_MOC_LITERAL(16, 392, 24)
    },
    "ConfigTest\0on_buttonAjouterParametre_clicked\0"
    "\0on_buttonModifierParametre_clicked\0"
    "on_comboBoxOperation_currentIndexChanged\0"
    "arg1\0on_comboBoxParametre_currentIndexChanged\0"
    "on_doubleSpinBoxValeur_editingFinished\0"
    "on_checkBoxParametre_toggled\0checked\0"
    "on_checkBoxValeur_toggled\0"
    "on_tableValeurstest_clicked\0index\0"
    "on_listViewConfigTest_clicked\0"
    "on_listViewConfigTest_doubleClicked\0"
    "on_buttonBox_accepted\0on_buttonAnnuler_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConfigTest[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    0,   75,    2, 0x08 /* Private */,
       4,    1,   76,    2, 0x08 /* Private */,
       6,    1,   79,    2, 0x08 /* Private */,
       7,    0,   82,    2, 0x08 /* Private */,
       8,    1,   83,    2, 0x08 /* Private */,
      10,    1,   86,    2, 0x08 /* Private */,
      11,    1,   89,    2, 0x08 /* Private */,
      13,    1,   92,    2, 0x08 /* Private */,
      14,    1,   95,    2, 0x08 /* Private */,
      15,    0,   98,    2, 0x08 /* Private */,
      16,    0,   99,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::QModelIndex,   12,
    QMetaType::Void, QMetaType::QModelIndex,   12,
    QMetaType::Void, QMetaType::QModelIndex,   12,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ConfigTest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ConfigTest *_t = static_cast<ConfigTest *>(_o);
        switch (_id) {
        case 0: _t->on_buttonAjouterParametre_clicked(); break;
        case 1: _t->on_buttonModifierParametre_clicked(); break;
        case 2: _t->on_comboBoxOperation_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_comboBoxParametre_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->on_doubleSpinBoxValeur_editingFinished(); break;
        case 5: _t->on_checkBoxParametre_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_checkBoxValeur_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_tableValeurstest_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 8: _t->on_listViewConfigTest_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 9: _t->on_listViewConfigTest_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 10: _t->on_buttonBox_accepted(); break;
        case 11: _t->on_buttonAnnuler_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject ConfigTest::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ConfigTest.data,
      qt_meta_data_ConfigTest,  qt_static_metacall, 0, 0}
};


const QMetaObject *ConfigTest::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConfigTest::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ConfigTest.stringdata))
        return static_cast<void*>(const_cast< ConfigTest*>(this));
    if (!strcmp(_clname, "Vue"))
        return static_cast< Vue*>(const_cast< ConfigTest*>(this));
    return QDialog::qt_metacast(_clname);
}

int ConfigTest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
