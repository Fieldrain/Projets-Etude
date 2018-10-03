/****************************************************************************
** Meta object code from reading C++ file 'configstationparametre.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Ui/configstationparametre.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'configstationparametre.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ConfigStationParametre_t {
    QByteArrayData data[7];
    char stringdata[153];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ConfigStationParametre_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ConfigStationParametre_t qt_meta_stringdata_ConfigStationParametre = {
    {
QT_MOC_LITERAL(0, 0, 22),
QT_MOC_LITERAL(1, 23, 27),
QT_MOC_LITERAL(2, 51, 0),
QT_MOC_LITERAL(3, 52, 5),
QT_MOC_LITERAL(4, 58, 33),
QT_MOC_LITERAL(5, 92, 39),
QT_MOC_LITERAL(6, 132, 20)
    },
    "ConfigStationParametre\0"
    "on_listViewNouveaux_clicked\0\0index\0"
    "on_buttonValiderCategorie_clicked\0"
    "on_lineEditNewCategorie_editingFinished\0"
    "on_buttonFin_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ConfigStationParametre[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x08 /* Private */,
       4,    0,   37,    2, 0x08 /* Private */,
       5,    0,   38,    2, 0x08 /* Private */,
       6,    0,   39,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ConfigStationParametre::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ConfigStationParametre *_t = static_cast<ConfigStationParametre *>(_o);
        switch (_id) {
        case 0: _t->on_listViewNouveaux_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 1: _t->on_buttonValiderCategorie_clicked(); break;
        case 2: _t->on_lineEditNewCategorie_editingFinished(); break;
        case 3: _t->on_buttonFin_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject ConfigStationParametre::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ConfigStationParametre.data,
      qt_meta_data_ConfigStationParametre,  qt_static_metacall, 0, 0}
};


const QMetaObject *ConfigStationParametre::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ConfigStationParametre::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ConfigStationParametre.stringdata))
        return static_cast<void*>(const_cast< ConfigStationParametre*>(this));
    if (!strcmp(_clname, "Vue"))
        return static_cast< Vue*>(const_cast< ConfigStationParametre*>(this));
    return QDialog::qt_metacast(_clname);
}

int ConfigStationParametre::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
