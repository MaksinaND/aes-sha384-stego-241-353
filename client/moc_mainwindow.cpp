/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[19];
    char stringdata0[312];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 21), // "onEmbedMessageClicked"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 23), // "onExtractMessageClicked"
QT_MOC_LITERAL(4, 58, 28), // "onSelectImageForEmbedClicked"
QT_MOC_LITERAL(5, 87, 30), // "onSelectImageForExtractClicked"
QT_MOC_LITERAL(6, 118, 18), // "onSaveImageClicked"
QT_MOC_LITERAL(7, 137, 12), // "onTabChanged"
QT_MOC_LITERAL(8, 150, 5), // "index"
QT_MOC_LITERAL(9, 156, 19), // "onEncryptAesClicked"
QT_MOC_LITERAL(10, 176, 19), // "onDecryptAesClicked"
QT_MOC_LITERAL(11, 196, 19), // "onHashSha384Clicked"
QT_MOC_LITERAL(12, 216, 25), // "onSolveChordMethodClicked"
QT_MOC_LITERAL(13, 242, 25), // "onClearChordMethodClicked"
QT_MOC_LITERAL(14, 268, 13), // "onApiResponse"
QT_MOC_LITERAL(15, 282, 8), // "endpoint"
QT_MOC_LITERAL(16, 291, 7), // "success"
QT_MOC_LITERAL(17, 299, 6), // "result"
QT_MOC_LITERAL(18, 306, 5) // "error"

    },
    "MainWindow\0onEmbedMessageClicked\0\0"
    "onExtractMessageClicked\0"
    "onSelectImageForEmbedClicked\0"
    "onSelectImageForExtractClicked\0"
    "onSaveImageClicked\0onTabChanged\0index\0"
    "onEncryptAesClicked\0onDecryptAesClicked\0"
    "onHashSha384Clicked\0onSolveChordMethodClicked\0"
    "onClearChordMethodClicked\0onApiResponse\0"
    "endpoint\0success\0result\0error"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
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
       4,    0,   76,    2, 0x08 /* Private */,
       5,    0,   77,    2, 0x08 /* Private */,
       6,    0,   78,    2, 0x08 /* Private */,
       7,    1,   79,    2, 0x08 /* Private */,
       9,    0,   82,    2, 0x08 /* Private */,
      10,    0,   83,    2, 0x08 /* Private */,
      11,    0,   84,    2, 0x08 /* Private */,
      12,    0,   85,    2, 0x08 /* Private */,
      13,    0,   86,    2, 0x08 /* Private */,
      14,    4,   87,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool, QMetaType::QJsonObject, QMetaType::QString,   15,   16,   17,   18,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onEmbedMessageClicked(); break;
        case 1: _t->onExtractMessageClicked(); break;
        case 2: _t->onSelectImageForEmbedClicked(); break;
        case 3: _t->onSelectImageForExtractClicked(); break;
        case 4: _t->onSaveImageClicked(); break;
        case 5: _t->onTabChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->onEncryptAesClicked(); break;
        case 7: _t->onDecryptAesClicked(); break;
        case 8: _t->onHashSha384Clicked(); break;
        case 9: _t->onSolveChordMethodClicked(); break;
        case 10: _t->onClearChordMethodClicked(); break;
        case 11: _t->onApiResponse((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< const QJsonObject(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
