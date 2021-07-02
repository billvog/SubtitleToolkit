#include "AboutDialog.h"
#include "ui_AboutDialog.h"

AboutDialog::AboutDialog(QWidget *parent): QDialog(parent), ui(new Ui::AboutDialog) {
    ui->setupUi(this);
    setFixedSize(size());

    ui->AboutText->setText("<html><body><p>Subtitle Toolkit is a free software developed by BILLVOG licensed under the GPLv3 license.</p><p>It helps you create subtitles with ease using it's simple yet powerful user interface.</p><p>Open Source: <a href=\"https://github.com/billvog/SubtitleToolkit\"><span style=\"text-decoration: underline; color:#0068da;\">github.com</span></a></p><p>Installed version: " + QString(PROGRAM_VERSION) + "</p></body></html>");
}

AboutDialog::~AboutDialog() {
    delete ui;
}
