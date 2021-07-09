/****************************************************************************
** Meta object code from reading C++ file 'MainWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../src/MainWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MainWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[60];
    char stringdata0[840];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 9), // "NewAction"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 10), // "OpenAction"
QT_MOC_LITERAL(4, 33, 10), // "SaveAction"
QT_MOC_LITERAL(5, 44, 12), // "SaveAsAction"
QT_MOC_LITERAL(6, 57, 11), // "CloseAction"
QT_MOC_LITERAL(7, 69, 10), // "ExitAction"
QT_MOC_LITERAL(8, 80, 10), // "UndoAction"
QT_MOC_LITERAL(9, 91, 10), // "RedoAction"
QT_MOC_LITERAL(10, 102, 15), // "GotoPreviousSub"
QT_MOC_LITERAL(11, 118, 11), // "GotoNextSub"
QT_MOC_LITERAL(12, 130, 14), // "DelaySubtitles"
QT_MOC_LITERAL(13, 145, 15), // "OpenMediaAction"
QT_MOC_LITERAL(14, 161, 16), // "CloseMediaAction"
QT_MOC_LITERAL(15, 178, 15), // "AboutHelpAction"
QT_MOC_LITERAL(16, 194, 17), // "AboutQtHelpAction"
QT_MOC_LITERAL(17, 212, 13), // "OpenMediaFile"
QT_MOC_LITERAL(18, 226, 4), // "Path"
QT_MOC_LITERAL(19, 231, 20), // "VideoSeekableChanged"
QT_MOC_LITERAL(20, 252, 5), // "value"
QT_MOC_LITERAL(21, 258, 20), // "VideoDurationChanged"
QT_MOC_LITERAL(22, 279, 20), // "VideoPositionChanged"
QT_MOC_LITERAL(23, 300, 21), // "TimelineSliderChanged"
QT_MOC_LITERAL(24, 322, 15), // "TogglePlayVideo"
QT_MOC_LITERAL(25, 338, 9), // "StopVideo"
QT_MOC_LITERAL(26, 348, 12), // "SeekForwards"
QT_MOC_LITERAL(27, 361, 13), // "SeekBackwards"
QT_MOC_LITERAL(28, 375, 8), // "VolumeUp"
QT_MOC_LITERAL(29, 384, 10), // "VolumeDown"
QT_MOC_LITERAL(30, 395, 15), // "ToggleMuteAudio"
QT_MOC_LITERAL(31, 411, 19), // "VolumeSliderChanged"
QT_MOC_LITERAL(32, 431, 16), // "OpenSubtitleFile"
QT_MOC_LITERAL(33, 448, 15), // "DisplaySubtitle"
QT_MOC_LITERAL(34, 464, 12), // "SubtitleItem"
QT_MOC_LITERAL(35, 477, 7), // "subItem"
QT_MOC_LITERAL(36, 485, 13), // "ClearSubtitle"
QT_MOC_LITERAL(37, 499, 18), // "SelectSubFromTable"
QT_MOC_LITERAL(38, 518, 3), // "row"
QT_MOC_LITERAL(39, 522, 18), // "SubTableRowClicked"
QT_MOC_LITERAL(40, 541, 11), // "QModelIndex"
QT_MOC_LITERAL(41, 553, 5), // "index"
QT_MOC_LITERAL(42, 559, 18), // "SubShowTimeChanged"
QT_MOC_LITERAL(43, 578, 18), // "SubHideTimeChanged"
QT_MOC_LITERAL(44, 597, 18), // "SubDurationChanged"
QT_MOC_LITERAL(45, 616, 14), // "SubTextChanged"
QT_MOC_LITERAL(46, 631, 19), // "SubCursorPosChanged"
QT_MOC_LITERAL(47, 651, 14), // "SubBoldClicked"
QT_MOC_LITERAL(48, 666, 16), // "SubItalicClicked"
QT_MOC_LITERAL(49, 683, 19), // "SubUnderlineClicked"
QT_MOC_LITERAL(50, 703, 19), // "SubStrikeoutClicked"
QT_MOC_LITERAL(51, 723, 16), // "SubTextToggleTag"
QT_MOC_LITERAL(52, 740, 3), // "tag"
QT_MOC_LITERAL(53, 744, 20), // "ApplySubtitlePressed"
QT_MOC_LITERAL(54, 765, 14), // "RemoveSubtitle"
QT_MOC_LITERAL(55, 780, 13), // "ApplySubtitle"
QT_MOC_LITERAL(56, 794, 4), // "item"
QT_MOC_LITERAL(57, 799, 14), // "ApplySubtitles"
QT_MOC_LITERAL(58, 814, 19), // "QList<SubtitleItem>"
QT_MOC_LITERAL(59, 834, 5) // "items"

    },
    "MainWindow\0NewAction\0\0OpenAction\0"
    "SaveAction\0SaveAsAction\0CloseAction\0"
    "ExitAction\0UndoAction\0RedoAction\0"
    "GotoPreviousSub\0GotoNextSub\0DelaySubtitles\0"
    "OpenMediaAction\0CloseMediaAction\0"
    "AboutHelpAction\0AboutQtHelpAction\0"
    "OpenMediaFile\0Path\0VideoSeekableChanged\0"
    "value\0VideoDurationChanged\0"
    "VideoPositionChanged\0TimelineSliderChanged\0"
    "TogglePlayVideo\0StopVideo\0SeekForwards\0"
    "SeekBackwards\0VolumeUp\0VolumeDown\0"
    "ToggleMuteAudio\0VolumeSliderChanged\0"
    "OpenSubtitleFile\0DisplaySubtitle\0"
    "SubtitleItem\0subItem\0ClearSubtitle\0"
    "SelectSubFromTable\0row\0SubTableRowClicked\0"
    "QModelIndex\0index\0SubShowTimeChanged\0"
    "SubHideTimeChanged\0SubDurationChanged\0"
    "SubTextChanged\0SubCursorPosChanged\0"
    "SubBoldClicked\0SubItalicClicked\0"
    "SubUnderlineClicked\0SubStrikeoutClicked\0"
    "SubTextToggleTag\0tag\0ApplySubtitlePressed\0"
    "RemoveSubtitle\0ApplySubtitle\0item\0"
    "ApplySubtitles\0QList<SubtitleItem>\0"
    "items"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      47,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  249,    2, 0x08 /* Private */,
       3,    0,  250,    2, 0x08 /* Private */,
       4,    0,  251,    2, 0x08 /* Private */,
       5,    0,  252,    2, 0x08 /* Private */,
       6,    0,  253,    2, 0x08 /* Private */,
       7,    0,  254,    2, 0x08 /* Private */,
       8,    0,  255,    2, 0x08 /* Private */,
       9,    0,  256,    2, 0x08 /* Private */,
      10,    0,  257,    2, 0x08 /* Private */,
      11,    0,  258,    2, 0x08 /* Private */,
      12,    0,  259,    2, 0x08 /* Private */,
      13,    0,  260,    2, 0x08 /* Private */,
      14,    0,  261,    2, 0x08 /* Private */,
      15,    0,  262,    2, 0x08 /* Private */,
      16,    0,  263,    2, 0x08 /* Private */,
      17,    1,  264,    2, 0x08 /* Private */,
      19,    1,  267,    2, 0x08 /* Private */,
      21,    1,  270,    2, 0x08 /* Private */,
      22,    1,  273,    2, 0x08 /* Private */,
      23,    1,  276,    2, 0x08 /* Private */,
      24,    0,  279,    2, 0x08 /* Private */,
      25,    0,  280,    2, 0x08 /* Private */,
      26,    0,  281,    2, 0x08 /* Private */,
      27,    0,  282,    2, 0x08 /* Private */,
      28,    0,  283,    2, 0x08 /* Private */,
      29,    0,  284,    2, 0x08 /* Private */,
      30,    0,  285,    2, 0x08 /* Private */,
      31,    1,  286,    2, 0x08 /* Private */,
      32,    1,  289,    2, 0x08 /* Private */,
      33,    1,  292,    2, 0x08 /* Private */,
      36,    0,  295,    2, 0x08 /* Private */,
      37,    1,  296,    2, 0x08 /* Private */,
      39,    1,  299,    2, 0x08 /* Private */,
      42,    0,  302,    2, 0x08 /* Private */,
      43,    0,  303,    2, 0x08 /* Private */,
      44,    0,  304,    2, 0x08 /* Private */,
      45,    0,  305,    2, 0x08 /* Private */,
      46,    0,  306,    2, 0x08 /* Private */,
      47,    0,  307,    2, 0x08 /* Private */,
      48,    0,  308,    2, 0x08 /* Private */,
      49,    0,  309,    2, 0x08 /* Private */,
      50,    0,  310,    2, 0x08 /* Private */,
      51,    1,  311,    2, 0x08 /* Private */,
      53,    0,  314,    2, 0x08 /* Private */,
      54,    0,  315,    2, 0x08 /* Private */,
      55,    2,  316,    2, 0x08 /* Private */,
      57,    1,  321,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void, QMetaType::Bool,   20,
    QMetaType::Void, QMetaType::LongLong,   20,
    QMetaType::Void, QMetaType::LongLong,   20,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void, 0x80000000 | 34,   35,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   38,
    QMetaType::Void, 0x80000000 | 40,   41,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   52,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, 0x80000000 | 34, QMetaType::Int,   56,   41,
    QMetaType::Bool, 0x80000000 | 58,   59,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->NewAction(); break;
        case 1: _t->OpenAction(); break;
        case 2: _t->SaveAction(); break;
        case 3: _t->SaveAsAction(); break;
        case 4: _t->CloseAction(); break;
        case 5: _t->ExitAction(); break;
        case 6: _t->UndoAction(); break;
        case 7: _t->RedoAction(); break;
        case 8: _t->GotoPreviousSub(); break;
        case 9: _t->GotoNextSub(); break;
        case 10: _t->DelaySubtitles(); break;
        case 11: _t->OpenMediaAction(); break;
        case 12: _t->CloseMediaAction(); break;
        case 13: _t->AboutHelpAction(); break;
        case 14: _t->AboutQtHelpAction(); break;
        case 15: _t->OpenMediaFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: _t->VideoSeekableChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->VideoDurationChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 18: _t->VideoPositionChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 19: _t->TimelineSliderChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->TogglePlayVideo(); break;
        case 21: _t->StopVideo(); break;
        case 22: _t->SeekForwards(); break;
        case 23: _t->SeekBackwards(); break;
        case 24: _t->VolumeUp(); break;
        case 25: _t->VolumeDown(); break;
        case 26: _t->ToggleMuteAudio(); break;
        case 27: _t->VolumeSliderChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->OpenSubtitleFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 29: _t->DisplaySubtitle((*reinterpret_cast< const SubtitleItem(*)>(_a[1]))); break;
        case 30: _t->ClearSubtitle(); break;
        case 31: _t->SelectSubFromTable((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 32: _t->SubTableRowClicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 33: _t->SubShowTimeChanged(); break;
        case 34: _t->SubHideTimeChanged(); break;
        case 35: _t->SubDurationChanged(); break;
        case 36: _t->SubTextChanged(); break;
        case 37: _t->SubCursorPosChanged(); break;
        case 38: _t->SubBoldClicked(); break;
        case 39: _t->SubItalicClicked(); break;
        case 40: _t->SubUnderlineClicked(); break;
        case 41: _t->SubStrikeoutClicked(); break;
        case 42: _t->SubTextToggleTag((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 43: _t->ApplySubtitlePressed(); break;
        case 44: _t->RemoveSubtitle(); break;
        case 45: { bool _r = _t->ApplySubtitle((*reinterpret_cast< const SubtitleItem(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 46: { bool _r = _t->ApplySubtitles((*reinterpret_cast< const QList<SubtitleItem>(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
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
        if (_id < 47)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 47;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 47)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 47;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
