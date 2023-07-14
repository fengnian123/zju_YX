/****************************************************************************
** Meta object code from reading C++ file 'view.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mota_mvvm/view/view.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'view.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSViewENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSViewENDCLASS = QtMocHelpers::stringData(
    "View",
    "OnNormalTimerTriggered",
    "",
    "OnOpenDoorTimerTriggered",
    "OnCutTimerTriggered",
    "OnFightTimerTriggered",
    "OnGainItemTimerTriggered"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSViewENDCLASS_t {
    uint offsetsAndSizes[14];
    char stringdata0[5];
    char stringdata1[23];
    char stringdata2[1];
    char stringdata3[25];
    char stringdata4[20];
    char stringdata5[22];
    char stringdata6[25];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSViewENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSViewENDCLASS_t qt_meta_stringdata_CLASSViewENDCLASS = {
    {
        QT_MOC_LITERAL(0, 4),  // "View"
        QT_MOC_LITERAL(5, 22),  // "OnNormalTimerTriggered"
        QT_MOC_LITERAL(28, 0),  // ""
        QT_MOC_LITERAL(29, 24),  // "OnOpenDoorTimerTriggered"
        QT_MOC_LITERAL(54, 19),  // "OnCutTimerTriggered"
        QT_MOC_LITERAL(74, 21),  // "OnFightTimerTriggered"
        QT_MOC_LITERAL(96, 24)   // "OnGainItemTimerTriggered"
    },
    "View",
    "OnNormalTimerTriggered",
    "",
    "OnOpenDoorTimerTriggered",
    "OnCutTimerTriggered",
    "OnFightTimerTriggered",
    "OnGainItemTimerTriggered"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSViewENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x0a,    1 /* Public */,
       3,    0,   45,    2, 0x0a,    2 /* Public */,
       4,    0,   46,    2, 0x0a,    3 /* Public */,
       5,    0,   47,    2, 0x0a,    4 /* Public */,
       6,    0,   48,    2, 0x0a,    5 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject View::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSViewENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSViewENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSViewENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<View, std::true_type>,
        // method 'OnNormalTimerTriggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'OnOpenDoorTimerTriggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'OnCutTimerTriggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'OnFightTimerTriggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'OnGainItemTimerTriggered'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void View::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<View *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->OnNormalTimerTriggered(); break;
        case 1: _t->OnOpenDoorTimerTriggered(); break;
        case 2: _t->OnCutTimerTriggered(); break;
        case 3: _t->OnFightTimerTriggered(); break;
        case 4: _t->OnGainItemTimerTriggered(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *View::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *View::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSViewENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int View::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
