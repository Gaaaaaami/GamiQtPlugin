/****************************************************************************
** Meta object code from reading C++ file 'GamiInternetTelport.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../GamiInternetTelport.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GamiInternetTelport.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GamiInternetTelportThread_t {
    QByteArrayData data[3];
    char stringdata0[45];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GamiInternetTelportThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GamiInternetTelportThread_t qt_meta_stringdata_GamiInternetTelportThread = {
    {
QT_MOC_LITERAL(0, 0, 25), // "GamiInternetTelportThread"
QT_MOC_LITERAL(1, 26, 17), // "signal_thread_run"
QT_MOC_LITERAL(2, 44, 0) // ""

    },
    "GamiInternetTelportThread\0signal_thread_run\0"
    ""
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GamiInternetTelportThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void GamiInternetTelportThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GamiInternetTelportThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_thread_run(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GamiInternetTelportThread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GamiInternetTelportThread::signal_thread_run)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject GamiInternetTelportThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_GamiInternetTelportThread.data,
    qt_meta_data_GamiInternetTelportThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GamiInternetTelportThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GamiInternetTelportThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GamiInternetTelportThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int GamiInternetTelportThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void GamiInternetTelportThread::signal_thread_run()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_GamiInternetTelport_t {
    QByteArrayData data[9];
    char stringdata0[95];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GamiInternetTelport_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GamiInternetTelport_t qt_meta_stringdata_GamiInternetTelport = {
    {
QT_MOC_LITERAL(0, 0, 19), // "GamiInternetTelport"
QT_MOC_LITERAL(1, 20, 19), // "signal_frame_update"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 16), // "signal_frame_key"
QT_MOC_LITERAL(4, 58, 6), // "stKey*"
QT_MOC_LITERAL(5, 65, 1), // "e"
QT_MOC_LITERAL(6, 67, 6), // "thread"
QT_MOC_LITERAL(7, 74, 14), // "defaultTimeout"
QT_MOC_LITERAL(8, 89, 5) // "OnKey"

    },
    "GamiInternetTelport\0signal_frame_update\0"
    "\0signal_frame_key\0stKey*\0e\0thread\0"
    "defaultTimeout\0OnKey"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GamiInternetTelport[] = {

 // content:
       8,       // revision
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
       3,    1,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   45,    2, 0x09 /* Protected */,
       7,    0,   46,    2, 0x09 /* Protected */,
       8,    1,   47,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, 0x80000000 | 4,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,

       0        // eod
};

void GamiInternetTelport::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GamiInternetTelport *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_frame_update((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->signal_frame_key((*reinterpret_cast< stKey*(*)>(_a[1]))); break;
        case 2: _t->thread(); break;
        case 3: _t->defaultTimeout(); break;
        case 4: _t->OnKey((*reinterpret_cast< stKey*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (GamiInternetTelport::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GamiInternetTelport::signal_frame_update)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (GamiInternetTelport::*)(stKey * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GamiInternetTelport::signal_frame_key)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GamiInternetTelport::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_GamiInternetTelport.data,
    qt_meta_data_GamiInternetTelport,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GamiInternetTelport::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GamiInternetTelport::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GamiInternetTelport.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int GamiInternetTelport::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void GamiInternetTelport::signal_frame_update(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void GamiInternetTelport::signal_frame_key(stKey * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
