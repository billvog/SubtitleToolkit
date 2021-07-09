/********************************************************************************
** Form generated from reading UI file 'AboutDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_AboutDialog
{
public:
    QDialogButtonBox *ButtonBox;
    QLabel *AboutText;
    QLabel *Icon;

    void setupUi(QDialog *AboutDialog)
    {
        if (AboutDialog->objectName().isEmpty())
            AboutDialog->setObjectName(QString::fromUtf8("AboutDialog"));
        AboutDialog->resize(400, 310);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/assets/colored-icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        AboutDialog->setWindowIcon(icon);
        AboutDialog->setModal(true);
        ButtonBox = new QDialogButtonBox(AboutDialog);
        ButtonBox->setObjectName(QString::fromUtf8("ButtonBox"));
        ButtonBox->setGeometry(QRect(9, 270, 381, 31));
        ButtonBox->setOrientation(Qt::Horizontal);
        ButtonBox->setStandardButtons(QDialogButtonBox::Close);
        ButtonBox->setCenterButtons(true);
        AboutText = new QLabel(AboutDialog);
        AboutText->setObjectName(QString::fromUtf8("AboutText"));
        AboutText->setGeometry(QRect(20, 120, 361, 141));
        AboutText->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        AboutText->setWordWrap(true);
        AboutText->setOpenExternalLinks(true);
        Icon = new QLabel(AboutDialog);
        Icon->setObjectName(QString::fromUtf8("Icon"));
        Icon->setGeometry(QRect(150, 10, 100, 100));
        Icon->setPixmap(QPixmap(QString::fromUtf8(":/assets/colored-icon.ico")));
        Icon->setScaledContents(true);
        Icon->setAlignment(Qt::AlignCenter);

        retranslateUi(AboutDialog);
        QObject::connect(ButtonBox, SIGNAL(accepted()), AboutDialog, SLOT(accept()));
        QObject::connect(ButtonBox, SIGNAL(rejected()), AboutDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(AboutDialog);
    } // setupUi

    void retranslateUi(QDialog *AboutDialog)
    {
        AboutDialog->setWindowTitle(QCoreApplication::translate("AboutDialog", "About", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AboutDialog: public Ui_AboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
