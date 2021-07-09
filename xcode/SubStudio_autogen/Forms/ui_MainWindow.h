/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *ActionNew;
    QAction *ActionOpen;
    QAction *ActionSave;
    QAction *ActionSaveAs;
    QAction *ActionMediaOpen;
    QAction *ActionMediaClose;
    QAction *ActionExit;
    QAction *ActionClose;
    QAction *ActionMediaPlayPause;
    QAction *ActionMediaStop;
    QAction *ActionMediaSeekForward;
    QAction *ActionMediaSeekBackward;
    QAction *ActionMediaAudioToggleMute;
    QAction *ActionMediaAudioVolumeUp;
    QAction *ActionMediaAudioVolumeDown;
    QAction *ActionEditGotoPrevious;
    QAction *ActionEditGotoNext;
    QAction *ActionEditUndo;
    QAction *ActionEditRedo;
    QAction *ActionHelpAbout;
    QAction *ActionEditDelay;
    QAction *ActionHelpAboutQt;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *MediaControls;
    QToolButton *TogglePlayButton;
    QSpacerItem *horizontalSpacer_4;
    QToolButton *BackwardSeekButton;
    QToolButton *StopButton;
    QToolButton *ForwardSeekButton;
    QSpacerItem *horizontalSpacer_3;
    QToolButton *ToggleMuteButton;
    QSlider *VolumeSlider;
    QGraphicsView *GraphicsView;
    QGroupBox *SubtitleGroupBox;
    QGridLayout *gridLayout_2;
    QPlainTextEdit *SubtitleTextEdit;
    QHBoxLayout *SubActionButtonsBox;
    QToolButton *ApplySubButton;
    QToolButton *RemoveSubButton;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *SubBoldButton;
    QToolButton *SubItalicButton;
    QToolButton *SubUnderlineButton;
    QToolButton *SubStrikeoutButton;
    QSpacerItem *horizontalSpacer;
    QToolButton *PrevSubButton;
    QToolButton *NextSubButton;
    QGridLayout *SubTimeEditsGrid;
    QTimeEdit *DurationSubTimeEdit;
    QLabel *label_5;
    QTimeEdit *HideSubTimeEdit;
    QLabel *label_4;
    QTimeEdit *ShowSubTimeEdit;
    QLabel *label_3;
    QTableView *SubTableView;
    QSpacerItem *verticalSpacer;
    QLabel *TimelineLabel;
    QSlider *TimelineSlider;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuMedia;
    QMenu *menuAudio;
    QMenu *menuEdit;
    QMenu *menuHelp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 650);
        MainWindow->setAcceptDrops(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/assets/colored-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setTabShape(QTabWidget::Rounded);
        ActionNew = new QAction(MainWindow);
        ActionNew->setObjectName(QString::fromUtf8("ActionNew"));
        ActionOpen = new QAction(MainWindow);
        ActionOpen->setObjectName(QString::fromUtf8("ActionOpen"));
        ActionSave = new QAction(MainWindow);
        ActionSave->setObjectName(QString::fromUtf8("ActionSave"));
        ActionSaveAs = new QAction(MainWindow);
        ActionSaveAs->setObjectName(QString::fromUtf8("ActionSaveAs"));
        ActionMediaOpen = new QAction(MainWindow);
        ActionMediaOpen->setObjectName(QString::fromUtf8("ActionMediaOpen"));
        ActionMediaClose = new QAction(MainWindow);
        ActionMediaClose->setObjectName(QString::fromUtf8("ActionMediaClose"));
        ActionExit = new QAction(MainWindow);
        ActionExit->setObjectName(QString::fromUtf8("ActionExit"));
        ActionClose = new QAction(MainWindow);
        ActionClose->setObjectName(QString::fromUtf8("ActionClose"));
        ActionMediaPlayPause = new QAction(MainWindow);
        ActionMediaPlayPause->setObjectName(QString::fromUtf8("ActionMediaPlayPause"));
        ActionMediaStop = new QAction(MainWindow);
        ActionMediaStop->setObjectName(QString::fromUtf8("ActionMediaStop"));
        ActionMediaSeekForward = new QAction(MainWindow);
        ActionMediaSeekForward->setObjectName(QString::fromUtf8("ActionMediaSeekForward"));
        ActionMediaSeekBackward = new QAction(MainWindow);
        ActionMediaSeekBackward->setObjectName(QString::fromUtf8("ActionMediaSeekBackward"));
        ActionMediaAudioToggleMute = new QAction(MainWindow);
        ActionMediaAudioToggleMute->setObjectName(QString::fromUtf8("ActionMediaAudioToggleMute"));
        ActionMediaAudioVolumeUp = new QAction(MainWindow);
        ActionMediaAudioVolumeUp->setObjectName(QString::fromUtf8("ActionMediaAudioVolumeUp"));
        ActionMediaAudioVolumeDown = new QAction(MainWindow);
        ActionMediaAudioVolumeDown->setObjectName(QString::fromUtf8("ActionMediaAudioVolumeDown"));
        ActionEditGotoPrevious = new QAction(MainWindow);
        ActionEditGotoPrevious->setObjectName(QString::fromUtf8("ActionEditGotoPrevious"));
        ActionEditGotoNext = new QAction(MainWindow);
        ActionEditGotoNext->setObjectName(QString::fromUtf8("ActionEditGotoNext"));
        ActionEditUndo = new QAction(MainWindow);
        ActionEditUndo->setObjectName(QString::fromUtf8("ActionEditUndo"));
        ActionEditRedo = new QAction(MainWindow);
        ActionEditRedo->setObjectName(QString::fromUtf8("ActionEditRedo"));
        ActionHelpAbout = new QAction(MainWindow);
        ActionHelpAbout->setObjectName(QString::fromUtf8("ActionHelpAbout"));
        ActionEditDelay = new QAction(MainWindow);
        ActionEditDelay->setObjectName(QString::fromUtf8("ActionEditDelay"));
        ActionHelpAboutQt = new QAction(MainWindow);
        ActionHelpAboutQt->setObjectName(QString::fromUtf8("ActionHelpAboutQt"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        MediaControls = new QHBoxLayout();
        MediaControls->setObjectName(QString::fromUtf8("MediaControls"));
        TogglePlayButton = new QToolButton(centralwidget);
        TogglePlayButton->setObjectName(QString::fromUtf8("TogglePlayButton"));
        TogglePlayButton->setEnabled(false);

        MediaControls->addWidget(TogglePlayButton);

        horizontalSpacer_4 = new QSpacerItem(6, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        MediaControls->addItem(horizontalSpacer_4);

        BackwardSeekButton = new QToolButton(centralwidget);
        BackwardSeekButton->setObjectName(QString::fromUtf8("BackwardSeekButton"));
        BackwardSeekButton->setEnabled(false);

        MediaControls->addWidget(BackwardSeekButton);

        StopButton = new QToolButton(centralwidget);
        StopButton->setObjectName(QString::fromUtf8("StopButton"));
        StopButton->setEnabled(false);

        MediaControls->addWidget(StopButton);

        ForwardSeekButton = new QToolButton(centralwidget);
        ForwardSeekButton->setObjectName(QString::fromUtf8("ForwardSeekButton"));
        ForwardSeekButton->setEnabled(false);

        MediaControls->addWidget(ForwardSeekButton);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        MediaControls->addItem(horizontalSpacer_3);

        ToggleMuteButton = new QToolButton(centralwidget);
        ToggleMuteButton->setObjectName(QString::fromUtf8("ToggleMuteButton"));
        ToggleMuteButton->setChecked(false);

        MediaControls->addWidget(ToggleMuteButton);

        VolumeSlider = new QSlider(centralwidget);
        VolumeSlider->setObjectName(QString::fromUtf8("VolumeSlider"));
        VolumeSlider->setMaximumSize(QSize(125, 16777215));
        VolumeSlider->setMaximum(100);
        VolumeSlider->setPageStep(0);
        VolumeSlider->setValue(80);
        VolumeSlider->setOrientation(Qt::Horizontal);

        MediaControls->addWidget(VolumeSlider);


        gridLayout->addLayout(MediaControls, 2, 0, 1, 7);

        GraphicsView = new QGraphicsView(centralwidget);
        GraphicsView->setObjectName(QString::fromUtf8("GraphicsView"));
        GraphicsView->setEnabled(false);
        GraphicsView->setAcceptDrops(false);
        GraphicsView->setFrameShape(QFrame::NoFrame);
        GraphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        GraphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        GraphicsView->setBackgroundBrush(brush);

        gridLayout->addWidget(GraphicsView, 0, 0, 1, 7);

        SubtitleGroupBox = new QGroupBox(centralwidget);
        SubtitleGroupBox->setObjectName(QString::fromUtf8("SubtitleGroupBox"));
        SubtitleGroupBox->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SubtitleGroupBox->sizePolicy().hasHeightForWidth());
        SubtitleGroupBox->setSizePolicy(sizePolicy);
        SubtitleGroupBox->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_2 = new QGridLayout(SubtitleGroupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        SubtitleTextEdit = new QPlainTextEdit(SubtitleGroupBox);
        SubtitleTextEdit->setObjectName(QString::fromUtf8("SubtitleTextEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(SubtitleTextEdit->sizePolicy().hasHeightForWidth());
        SubtitleTextEdit->setSizePolicy(sizePolicy1);
        SubtitleTextEdit->setMaximumSize(QSize(16777215, 90));
        QFont font;
        font.setFamily(QString::fromUtf8("Courier"));
        font.setPointSize(14);
        SubtitleTextEdit->setFont(font);

        gridLayout_2->addWidget(SubtitleTextEdit, 4, 2, 1, 2);

        SubActionButtonsBox = new QHBoxLayout();
        SubActionButtonsBox->setSpacing(3);
        SubActionButtonsBox->setObjectName(QString::fromUtf8("SubActionButtonsBox"));
        ApplySubButton = new QToolButton(SubtitleGroupBox);
        ApplySubButton->setObjectName(QString::fromUtf8("ApplySubButton"));

        SubActionButtonsBox->addWidget(ApplySubButton);

        RemoveSubButton = new QToolButton(SubtitleGroupBox);
        RemoveSubButton->setObjectName(QString::fromUtf8("RemoveSubButton"));

        SubActionButtonsBox->addWidget(RemoveSubButton);

        horizontalSpacer_2 = new QSpacerItem(9, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        SubActionButtonsBox->addItem(horizontalSpacer_2);

        SubBoldButton = new QToolButton(SubtitleGroupBox);
        SubBoldButton->setObjectName(QString::fromUtf8("SubBoldButton"));
        QFont font1;
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        SubBoldButton->setFont(font1);
        SubBoldButton->setCheckable(true);

        SubActionButtonsBox->addWidget(SubBoldButton);

        SubItalicButton = new QToolButton(SubtitleGroupBox);
        SubItalicButton->setObjectName(QString::fromUtf8("SubItalicButton"));
        QFont font2;
        font2.setPointSize(13);
        font2.setItalic(true);
        SubItalicButton->setFont(font2);
        SubItalicButton->setCheckable(true);

        SubActionButtonsBox->addWidget(SubItalicButton);

        SubUnderlineButton = new QToolButton(SubtitleGroupBox);
        SubUnderlineButton->setObjectName(QString::fromUtf8("SubUnderlineButton"));
        QFont font3;
        font3.setPointSize(13);
        font3.setUnderline(true);
        SubUnderlineButton->setFont(font3);
        SubUnderlineButton->setCheckable(true);

        SubActionButtonsBox->addWidget(SubUnderlineButton);

        SubStrikeoutButton = new QToolButton(SubtitleGroupBox);
        SubStrikeoutButton->setObjectName(QString::fromUtf8("SubStrikeoutButton"));
        QFont font4;
        font4.setPointSize(13);
        font4.setStrikeOut(true);
        SubStrikeoutButton->setFont(font4);
        SubStrikeoutButton->setCheckable(true);

        SubActionButtonsBox->addWidget(SubStrikeoutButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        SubActionButtonsBox->addItem(horizontalSpacer);

        PrevSubButton = new QToolButton(SubtitleGroupBox);
        PrevSubButton->setObjectName(QString::fromUtf8("PrevSubButton"));
        QFont font5;
        font5.setPointSize(10);
        font5.setBold(false);
        font5.setWeight(50);
        PrevSubButton->setFont(font5);

        SubActionButtonsBox->addWidget(PrevSubButton);

        NextSubButton = new QToolButton(SubtitleGroupBox);
        NextSubButton->setObjectName(QString::fromUtf8("NextSubButton"));
        NextSubButton->setFont(font5);

        SubActionButtonsBox->addWidget(NextSubButton);


        gridLayout_2->addLayout(SubActionButtonsBox, 3, 2, 1, 2);

        SubTimeEditsGrid = new QGridLayout();
        SubTimeEditsGrid->setObjectName(QString::fromUtf8("SubTimeEditsGrid"));
        DurationSubTimeEdit = new QTimeEdit(SubtitleGroupBox);
        DurationSubTimeEdit->setObjectName(QString::fromUtf8("DurationSubTimeEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(DurationSubTimeEdit->sizePolicy().hasHeightForWidth());
        DurationSubTimeEdit->setSizePolicy(sizePolicy2);
        DurationSubTimeEdit->setMinimumSize(QSize(100, 0));

        SubTimeEditsGrid->addWidget(DurationSubTimeEdit, 3, 1, 1, 1);

        label_5 = new QLabel(SubtitleGroupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy2.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy2);
        label_5->setMaximumSize(QSize(16777215, 10));

        SubTimeEditsGrid->addWidget(label_5, 3, 0, 1, 1);

        HideSubTimeEdit = new QTimeEdit(SubtitleGroupBox);
        HideSubTimeEdit->setObjectName(QString::fromUtf8("HideSubTimeEdit"));
        sizePolicy2.setHeightForWidth(HideSubTimeEdit->sizePolicy().hasHeightForWidth());
        HideSubTimeEdit->setSizePolicy(sizePolicy2);
        HideSubTimeEdit->setMinimumSize(QSize(100, 0));

        SubTimeEditsGrid->addWidget(HideSubTimeEdit, 2, 1, 1, 1);

        label_4 = new QLabel(SubtitleGroupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);
        label_4->setMaximumSize(QSize(16777215, 10));

        SubTimeEditsGrid->addWidget(label_4, 2, 0, 1, 1);

        ShowSubTimeEdit = new QTimeEdit(SubtitleGroupBox);
        ShowSubTimeEdit->setObjectName(QString::fromUtf8("ShowSubTimeEdit"));
        sizePolicy2.setHeightForWidth(ShowSubTimeEdit->sizePolicy().hasHeightForWidth());
        ShowSubTimeEdit->setSizePolicy(sizePolicy2);
        ShowSubTimeEdit->setMinimumSize(QSize(100, 0));

        SubTimeEditsGrid->addWidget(ShowSubTimeEdit, 1, 1, 1, 1);

        label_3 = new QLabel(SubtitleGroupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);
        label_3->setMaximumSize(QSize(16777215, 10));

        SubTimeEditsGrid->addWidget(label_3, 1, 0, 1, 1);


        gridLayout_2->addLayout(SubTimeEditsGrid, 4, 1, 1, 1);

        SubTableView = new QTableView(SubtitleGroupBox);
        SubTableView->setObjectName(QString::fromUtf8("SubTableView"));
        sizePolicy.setHeightForWidth(SubTableView->sizePolicy().hasHeightForWidth());
        SubTableView->setSizePolicy(sizePolicy);
        SubTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        SubTableView->horizontalHeader()->setStretchLastSection(true);

        gridLayout_2->addWidget(SubTableView, 1, 1, 1, 3);

        verticalSpacer = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_2->addItem(verticalSpacer, 2, 1, 1, 3);


        gridLayout->addWidget(SubtitleGroupBox, 5, 0, 1, 7);

        TimelineLabel = new QLabel(centralwidget);
        TimelineLabel->setObjectName(QString::fromUtf8("TimelineLabel"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(TimelineLabel->sizePolicy().hasHeightForWidth());
        TimelineLabel->setSizePolicy(sizePolicy3);
        TimelineLabel->setMinimumSize(QSize(155, 0));
        TimelineLabel->setMaximumSize(QSize(155, 16777215));
        QFont font6;
        font6.setPointSize(10);
        TimelineLabel->setFont(font6);
        TimelineLabel->setTextFormat(Qt::PlainText);
        TimelineLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(TimelineLabel, 1, 6, 1, 1);

        TimelineSlider = new QSlider(centralwidget);
        TimelineSlider->setObjectName(QString::fromUtf8("TimelineSlider"));
        TimelineSlider->setEnabled(false);
        TimelineSlider->setMaximum(1);
        TimelineSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(TimelineSlider, 1, 0, 1, 6);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 3, 6, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 24));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuMedia = new QMenu(menubar);
        menuMedia->setObjectName(QString::fromUtf8("menuMedia"));
        menuAudio = new QMenu(menuMedia);
        menuAudio->setObjectName(QString::fromUtf8("menuAudio"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuMedia->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(ActionNew);
        menuFile->addAction(ActionOpen);
        menuFile->addSeparator();
        menuFile->addAction(ActionSave);
        menuFile->addAction(ActionSaveAs);
        menuFile->addSeparator();
        menuFile->addAction(ActionClose);
        menuFile->addSeparator();
        menuFile->addAction(ActionExit);
        menuMedia->addAction(ActionMediaOpen);
        menuMedia->addAction(ActionMediaClose);
        menuMedia->addSeparator();
        menuMedia->addAction(ActionMediaPlayPause);
        menuMedia->addAction(ActionMediaStop);
        menuMedia->addSeparator();
        menuMedia->addAction(ActionMediaSeekBackward);
        menuMedia->addAction(ActionMediaSeekForward);
        menuMedia->addSeparator();
        menuMedia->addAction(menuAudio->menuAction());
        menuAudio->addAction(ActionMediaAudioVolumeUp);
        menuAudio->addAction(ActionMediaAudioVolumeDown);
        menuAudio->addSeparator();
        menuAudio->addAction(ActionMediaAudioToggleMute);
        menuEdit->addAction(ActionEditUndo);
        menuEdit->addAction(ActionEditRedo);
        menuEdit->addSeparator();
        menuEdit->addAction(ActionEditGotoPrevious);
        menuEdit->addAction(ActionEditGotoNext);
        menuEdit->addSeparator();
        menuEdit->addAction(ActionEditDelay);
        menuHelp->addAction(ActionHelpAbout);
        menuHelp->addAction(ActionHelpAboutQt);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        ActionNew->setText(QCoreApplication::translate("MainWindow", "New", nullptr));
#if QT_CONFIG(shortcut)
        ActionNew->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        ActionOpen->setText(QCoreApplication::translate("MainWindow", "Open...", nullptr));
#if QT_CONFIG(shortcut)
        ActionOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        ActionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
#if QT_CONFIG(shortcut)
        ActionSave->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        ActionSaveAs->setText(QCoreApplication::translate("MainWindow", "Save As...", nullptr));
#if QT_CONFIG(shortcut)
        ActionSaveAs->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        ActionMediaOpen->setText(QCoreApplication::translate("MainWindow", "Open...", nullptr));
#if QT_CONFIG(shortcut)
        ActionMediaOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+O", nullptr));
#endif // QT_CONFIG(shortcut)
        ActionMediaClose->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
        ActionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
#if QT_CONFIG(shortcut)
        ActionExit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        ActionClose->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
        ActionMediaPlayPause->setText(QCoreApplication::translate("MainWindow", "Play/Pause", nullptr));
#if QT_CONFIG(shortcut)
        ActionMediaPlayPause->setShortcut(QCoreApplication::translate("MainWindow", "Space", nullptr));
#endif // QT_CONFIG(shortcut)
        ActionMediaStop->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        ActionMediaSeekForward->setText(QCoreApplication::translate("MainWindow", "Seek Forward", nullptr));
#if QT_CONFIG(shortcut)
        ActionMediaSeekForward->setShortcut(QCoreApplication::translate("MainWindow", "Right", nullptr));
#endif // QT_CONFIG(shortcut)
        ActionMediaSeekBackward->setText(QCoreApplication::translate("MainWindow", "Seek Backward", nullptr));
#if QT_CONFIG(shortcut)
        ActionMediaSeekBackward->setShortcut(QCoreApplication::translate("MainWindow", "Left", nullptr));
#endif // QT_CONFIG(shortcut)
        ActionMediaAudioToggleMute->setText(QCoreApplication::translate("MainWindow", "Toggle Mute", nullptr));
#if QT_CONFIG(shortcut)
        ActionMediaAudioToggleMute->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+M", nullptr));
#endif // QT_CONFIG(shortcut)
        ActionMediaAudioVolumeUp->setText(QCoreApplication::translate("MainWindow", "Volume Up", nullptr));
#if QT_CONFIG(shortcut)
        ActionMediaAudioVolumeUp->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Up", nullptr));
#endif // QT_CONFIG(shortcut)
        ActionMediaAudioVolumeDown->setText(QCoreApplication::translate("MainWindow", "Volume Down", nullptr));
#if QT_CONFIG(shortcut)
        ActionMediaAudioVolumeDown->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Down", nullptr));
#endif // QT_CONFIG(shortcut)
        ActionEditGotoPrevious->setText(QCoreApplication::translate("MainWindow", "Goto Previous", nullptr));
#if QT_CONFIG(tooltip)
        ActionEditGotoPrevious->setToolTip(QCoreApplication::translate("MainWindow", "Goto Previous", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        ActionEditGotoPrevious->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Left", nullptr));
#endif // QT_CONFIG(shortcut)
        ActionEditGotoNext->setText(QCoreApplication::translate("MainWindow", "Goto Next", nullptr));
#if QT_CONFIG(tooltip)
        ActionEditGotoNext->setToolTip(QCoreApplication::translate("MainWindow", "Goto Next", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        ActionEditGotoNext->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Right", nullptr));
#endif // QT_CONFIG(shortcut)
        ActionEditUndo->setText(QCoreApplication::translate("MainWindow", "Undo", nullptr));
#if QT_CONFIG(shortcut)
        ActionEditUndo->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        ActionEditRedo->setText(QCoreApplication::translate("MainWindow", "Redo", nullptr));
#if QT_CONFIG(shortcut)
        ActionEditRedo->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        ActionHelpAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        ActionEditDelay->setText(QCoreApplication::translate("MainWindow", "Delay", nullptr));
        ActionHelpAboutQt->setText(QCoreApplication::translate("MainWindow", "About Qt", nullptr));
        TogglePlayButton->setText(QString());
        BackwardSeekButton->setText(QString());
        StopButton->setText(QString());
        ForwardSeekButton->setText(QString());
        ToggleMuteButton->setText(QString());
        SubtitleTextEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Subtitle...", nullptr));
#if QT_CONFIG(tooltip)
        ApplySubButton->setToolTip(QCoreApplication::translate("MainWindow", "Apply", nullptr));
#endif // QT_CONFIG(tooltip)
        ApplySubButton->setText(QString());
#if QT_CONFIG(tooltip)
        RemoveSubButton->setToolTip(QCoreApplication::translate("MainWindow", "Remove", nullptr));
#endif // QT_CONFIG(tooltip)
        RemoveSubButton->setText(QString());
#if QT_CONFIG(tooltip)
        SubBoldButton->setToolTip(QCoreApplication::translate("MainWindow", "Bold", nullptr));
#endif // QT_CONFIG(tooltip)
        SubBoldButton->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
#if QT_CONFIG(tooltip)
        SubItalicButton->setToolTip(QCoreApplication::translate("MainWindow", "Italic", nullptr));
#endif // QT_CONFIG(tooltip)
        SubItalicButton->setText(QCoreApplication::translate("MainWindow", "I", nullptr));
#if QT_CONFIG(tooltip)
        SubUnderlineButton->setToolTip(QCoreApplication::translate("MainWindow", "Undeline", nullptr));
#endif // QT_CONFIG(tooltip)
        SubUnderlineButton->setText(QCoreApplication::translate("MainWindow", "U", nullptr));
#if QT_CONFIG(tooltip)
        SubStrikeoutButton->setToolTip(QCoreApplication::translate("MainWindow", "Strikeout", nullptr));
#endif // QT_CONFIG(tooltip)
        SubStrikeoutButton->setText(QCoreApplication::translate("MainWindow", "S", nullptr));
#if QT_CONFIG(tooltip)
        PrevSubButton->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Previous Subtitle</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(tooltip)
        NextSubButton->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Next Subtitle</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        DurationSubTimeEdit->setDisplayFormat(QCoreApplication::translate("MainWindow", "hh:mm:ss,zzz", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Duration:", nullptr));
        HideSubTimeEdit->setDisplayFormat(QCoreApplication::translate("MainWindow", "hh:mm:ss,zzz", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Hide:", nullptr));
        ShowSubTimeEdit->setDisplayFormat(QCoreApplication::translate("MainWindow", "hh:mm:ss,zzz", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Show:", nullptr));
        TimelineLabel->setText(QCoreApplication::translate("MainWindow", "00:00:00,000 / 00:00:00,000", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuMedia->setTitle(QCoreApplication::translate("MainWindow", "Media", nullptr));
        menuAudio->setTitle(QCoreApplication::translate("MainWindow", "Audio", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        (void)MainWindow;
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
