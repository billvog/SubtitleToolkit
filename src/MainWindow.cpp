#include "MainWindow.h"
#include "../Forms/ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  SetWindowTitle("");
  SetupButtonIcons();
  SetupVideoWidget();
  SetupSubtitlesTable();
  ConnectEvents();

  // Media Player Group
  SetMediaControlsEnabled(false);

  // Subtitle Group
  ui->SubtitleGroupBox->setEnabled(false);

  // Syntax Highlighing on Subtitle Text Field
  subtitlesTextHighlighter = new SubtitleTextHighlighter(ui->SubtitleTextEdit->document());
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::closeEvent(QCloseEvent *e) {
  if (!CheckIfSaved()) {
    e->ignore();
    return;
  }

  e->accept();
}

void MainWindow::resizeEvent(QResizeEvent *) {
  UpdateUI();
}

void MainWindow::dragEnterEvent(QDragEnterEvent *e) {
  if (e->mimeData()->hasUrls()) {
    e->acceptProposedAction();
  }
}

void MainWindow::dropEvent(QDropEvent *e) {
  const QMimeData *mimeData = e->mimeData();

  if (mimeData->hasUrls()) {
    QString path(mimeData->urls().at(0).toLocalFile());

    QFileInfo fileInfo(path);
    QString suffix(fileInfo.suffix());

    if (SubtitleFileSelector.contains(suffix)) {
      OpenSubtitleFile(path);
    }
    else if (MediaFileSelector.contains(suffix)) {
      OpenMediaFile(path);
    }
    else {
      QMessageBox::critical(this, "Error", "Unsupported file type: \"" + suffix + "\"");
      return;
    }
  }
}

void MainWindow::keyPressEvent(QKeyEvent *e) {
  if (e->key() == Qt::Key_Escape) {
    ui->SubtitleTextEdit->clearFocus();
  }
}

void MainWindow::SetupButtonIcons() {
  ui->TogglePlayButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
  ui->StopButton->setIcon(style()->standardIcon(QStyle::SP_MediaStop));
  ui->ToggleMuteButton->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));

  ui->BackwardSeekButton->setIcon(style()->standardIcon(QStyle::SP_MediaSeekBackward));
  ui->ForwardSeekButton->setIcon(style()->standardIcon(QStyle::SP_MediaSeekForward));

  ui->PrevSubButton->setIcon(style()->standardIcon(QStyle::SP_ArrowLeft));
  ui->NextSubButton->setIcon(style()->standardIcon(QStyle::SP_ArrowRight));

  ui->ApplySubButton->setIcon(style()->standardIcon(QStyle::SP_DialogApplyButton));
  ui->RemoveSubButton->setIcon(style()->standardIcon(QStyle::SP_DialogCancelButton));
}

void MainWindow::SetupVideoWidget() {
  videoItem = new QGraphicsVideoItem();
  subTextItem = new QGraphicsTextItem();

  scene = new QGraphicsScene(this);

  QGraphicsView *view = ui->GraphicsView;
  view->setScene(scene);
  view->show();

  scene->addItem(videoItem);
  scene->addItem(subTextItem);

  player = new QMediaPlayer(this, QMediaPlayer::VideoSurface);
  player->setVideoOutput(videoItem);
  player->setNotifyInterval(50);
  player->setVolume(ui->VolumeSlider->value());

  subTextItem->setPlainText(QString());
  subTextItem->setDefaultTextColor(QColorConstants::White);

  QFont subtitleFont = subTextItem->font();
  subtitleFont.setPixelSize(26);
  subTextItem->setFont(subtitleFont);

  QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect(this);
  shadowEffect->setOffset(1, 1);
  subTextItem->setGraphicsEffect(shadowEffect);
}

void MainWindow::SetupSubtitlesTable() {
  subtitlesModel = new QStandardItemModel(Subtitles.size(), 3, this);
  subtitlesModel->setHorizontalHeaderItem(0, new QStandardItem(QString("Show")));
  subtitlesModel->setHorizontalHeaderItem(1, new QStandardItem(QString("Hide")));
  subtitlesModel->setHorizontalHeaderItem(2, new QStandardItem(QString("Subtitle")));

  ui->SubTableView->setModel(subtitlesModel);
}

void MainWindow::ConnectEvents() {
	// File Menu
	connect(ui->ActionNew, SIGNAL(triggered()), this, SLOT(NewAction()));
	connect(ui->ActionOpen, SIGNAL(triggered()), this, SLOT(OpenAction()));
	connect(ui->ActionSave, SIGNAL(triggered()), this, SLOT(SaveAction()));
	connect(ui->ActionSaveAs, SIGNAL(triggered()), this, SLOT(SaveAsAction()));
	connect(ui->ActionClose, SIGNAL(triggered()), this, SLOT(CloseAction()));
	connect(ui->ActionExit, SIGNAL(triggered()), this, SLOT(ExitAction()));

	// Edit Menu
	connect(ui->ActionEditUndo, SIGNAL(triggered()), this, SLOT(UndoAction()));
	connect(ui->ActionEditRedo, SIGNAL(triggered()), this, SLOT(RedoAction()));
	connect(ui->ActionEditGotoPrevious, SIGNAL(triggered()), this, SLOT(GotoPreviousSub()));
	connect(ui->ActionEditGotoNext, SIGNAL(triggered()), this, SLOT(GotoNextSub()));
	connect(ui->ActionEditDelay, SIGNAL(triggered()), this, SLOT(DelaySubtitles()));

	// Media Menu
	connect(ui->ActionMediaOpen, SIGNAL(triggered()), this, SLOT(OpenMediaAction()));
	connect(ui->ActionMediaClose, SIGNAL(triggered()), this, SLOT(CloseMediaAction()));
	connect(ui->ActionMediaPlayPause, SIGNAL(triggered()), this, SLOT(TogglePlayVideo()));
	connect(ui->ActionMediaStop, SIGNAL(triggered()), this, SLOT(StopVideo()));
	connect(ui->ActionMediaSeekBackward, SIGNAL(triggered()), this, SLOT(SeekBackwards()));
	connect(ui->ActionMediaSeekForward, SIGNAL(triggered()), this, SLOT(SeekForwards()));
	connect(ui->ActionMediaAudioVolumeUp, SIGNAL(triggered()), this, SLOT(VolumeUp()));
	connect(ui->ActionMediaAudioVolumeDown, SIGNAL(triggered()), this, SLOT(VolumeDown()));
	connect(ui->ActionMediaAudioToggleMute, SIGNAL(triggered()), this, SLOT(ToggleMuteAudio()));

	// Help Menu
	connect(ui->ActionHelpAbout, SIGNAL(triggered()), this, SLOT(AboutHelpAction()));
	connect(ui->ActionHelpAboutQt, SIGNAL(triggered()), this, SLOT(AboutQtHelpAction()));

	// Media Player
	connect(player, SIGNAL(seekableChanged(bool)), this, SLOT(VideoSeekableChanged(bool)));
	connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(VideoPositionChanged(qint64)));
	connect(player, SIGNAL(durationChanged(qint64)), this, SLOT(VideoDurationChanged(qint64)));

	connect(ui->TimelineSlider, SIGNAL(sliderMoved(int)), this, SLOT(TimelineSliderChanged(int)));
	connect(ui->TogglePlayButton, SIGNAL(clicked()), this, SLOT(TogglePlayVideo()));
	connect(ui->StopButton, SIGNAL(clicked()), this, SLOT(StopVideo()));

	connect(ui->BackwardSeekButton, SIGNAL(clicked()), this, SLOT(SeekBackwards()));
	connect(ui->ForwardSeekButton, SIGNAL(clicked()), this, SLOT(SeekForwards()));

	connect(ui->ToggleMuteButton, SIGNAL(clicked()), this, SLOT(ToggleMuteAudio()));
	connect(ui->VolumeSlider, SIGNAL(sliderMoved(int)), this, SLOT(VolumeSliderChanged(int)));

	// Subtitle Group
	connect(ui->SubTableView, SIGNAL(clicked(QModelIndex)), this, SLOT(SubTableRowClicked(QModelIndex)));

	connect(ui->PrevSubButton, SIGNAL(clicked()), this, SLOT(GotoPreviousSub()));
	connect(ui->NextSubButton, SIGNAL(clicked()), this, SLOT(GotoNextSub()));

	connect(ui->ShowSubTimeEdit, SIGNAL(editingFinished()), this, SLOT(SubShowTimeChanged()));
	connect(ui->HideSubTimeEdit, SIGNAL(editingFinished()), this, SLOT(SubHideTimeChanged()));
	connect(ui->DurationSubTimeEdit, SIGNAL(editingFinished()), this, SLOT(SubDurationChanged()));

	connect(ui->SubtitleTextEdit, SIGNAL(textChanged()), this, SLOT(SubTextChanged()));
	connect(ui->SubtitleTextEdit, SIGNAL(cursorPositionChanged()), this, SLOT(SubCursorPosChanged()));

	connect(ui->SubBoldButton,  SIGNAL(clicked()), this, SLOT(SubBoldClicked()));
	connect(ui->SubItalicButton,  SIGNAL(clicked()), this, SLOT(SubItalicClicked()));
	connect(ui->SubUnderlineButton,  SIGNAL(clicked()), this, SLOT(SubUnderlineClicked()));
	connect(ui->SubStrikeoutButton,  SIGNAL(clicked()), this, SLOT(SubStrikeoutClicked()));

	connect(ui->ApplySubButton, SIGNAL(clicked()), this, SLOT(ApplySubtitlePressed()));
	connect(ui->RemoveSubButton, SIGNAL(clicked()), this, SLOT(RemoveSubtitle()));
}

void MainWindow::SetMediaControlsEnabled(bool isEnabled) {
  ui->TogglePlayButton->setEnabled(isEnabled);
  ui->ToggleMuteButton->setEnabled(isEnabled);
  ui->VolumeSlider->setEnabled(isEnabled);
  ui->BackwardSeekButton->setEnabled(isEnabled);
  ui->ForwardSeekButton->setEnabled(isEnabled);
  ui->StopButton->setEnabled(isEnabled);
}

void MainWindow::UpdateUI() {
  videoItem->setSize(ui->GraphicsView->size());
  scene->setSceneRect(0, 0, videoItem->size().width(), videoItem->size().height());

  // Update Subtitle Text
  subTextScaleFactor = std::clamp(scene->itemsBoundingRect().width() / 622, 0.0, 1.0);
  subTextItem->setScale(subTextScaleFactor);

  UpdateSubPosition();
}

void MainWindow::UpdateSubAlignment() {
  subTextItem->setTextWidth(subTextItem->boundingRect().width());
  QTextBlockFormat format;
  format.setAlignment(Qt::AlignCenter);
  QTextCursor cursor = subTextItem->textCursor();
  cursor.select(QTextCursor::Document);
  cursor.mergeBlockFormat(format);
  cursor.clearSelection();
  subTextItem->setTextCursor(cursor);
}

void MainWindow::UpdateSubPosition() {
  QSizeF textRectSize = subTextItem->boundingRect().size() * subTextScaleFactor;
  qreal target_y = videoItem->size().height() - textRectSize.height();
  qreal target_x = (videoItem->size().width() - textRectSize.width()) / 2;
  subTextItem->setPos(target_x, target_y);
}

QTime MainWindow::MsToTime(int ms) {
  if (ms < 0)
    return QTime();

  int hours, minutes, seconds, milliseconds = ms;

  if (milliseconds < 3600000)
    hours = 0;
  else {
    hours = milliseconds / 3600000;
    milliseconds -= hours * 3600000;
  }

  if (milliseconds < 60000)
    minutes = 0;
  else {
    minutes = milliseconds / 60000;
    milliseconds -= minutes * 60000;
  }

  if (milliseconds < 1000)
    seconds = 0;
  else {
    seconds = milliseconds / 1000;
    milliseconds -= seconds * 1000;
  }

  return QTime(hours, minutes, seconds, milliseconds);
}

void MainWindow::SetWindowTitle(const QString title) {
  if (title.length() == 0) {
    setWindowTitle(QString::fromStdString(SubStudio::displayName));
  }
  else {
    setWindowTitle(title + " – " + QString::fromStdString(SubStudio::displayName));
  }
}

bool MainWindow::CheckIfSaved() {
  if (hasFileOpen) {
    if (!isSaved) {
      int result = QMessageBox::question(this, "Confirm", "File \"" + QFileInfo(SubFilePath).fileName() + "\" has changed. \nDo you want to save changes?", QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel, QMessageBox::Yes);
      if (result == QMessageBox::Yes) {
        SaveAction();
      }
      else if (result == QMessageBox::Cancel) {
        return false;
      }
    }
  }

  return true;
}

void MainWindow::SetIsSaved(bool value) {
  QString windowTitle;

  QString filename = QFileInfo(SubFilePath).absoluteFilePath();

  if (filename.isEmpty())
    filename = "untitled";

  if (value) {
    windowTitle = filename;
  }
  else {
    windowTitle = "* " + filename;
  }

  SetWindowTitle(windowTitle);
  hasFileOpen = true;
  isSaved = value;
}

// Actions
// File
void MainWindow::NewAction() {
  if (!CheckIfSaved()) {
    return;
  }

  subtitlesModel->clear();
  Subtitles.clear();

  SubFilePath.clear();

  UndoItems.clear();
  RedoItems.clear();

  EditingSubtitleIndex = -1;
  PrevEditinSubtitleIndex = EditingSubtitleIndex;

  subTextItem->setPlainText(QString());

  ui->SubtitleTextEdit->setPlainText(QString());
  ui->ShowSubTimeEdit->setTime(QTime());
  ui->HideSubTimeEdit->setTime(QTime());

  ui->SubtitleGroupBox->setEnabled(true);
  SetIsSaved(false);
}

void MainWindow::OpenAction() {
  if (!CheckIfSaved()) return;

  QString file = QFileDialog::getOpenFileName(this, "Open Subtitle File", QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation), SubtitleFileSelector);

  if (file.isEmpty()) return;

  if (!QFile(file).exists()) {
    QMessageBox::critical(this, "Error", "File \"" + file + "\" doesn't exist");
    return;
  }

  OpenSubtitleFile(file);
}

void MainWindow::SaveAction() {
  if (SubFilePath.isEmpty()) {
    SaveAsAction();
    return;
  }

  QString suffix(QFileInfo(SubFilePath).suffix());
  if (suffix == "srt") {
    if (!SubParser::ExportSrt(Subtitles, SubFilePath)) {
      QMessageBox::critical(this, "Error", "Could't save file to \"" + SubFilePath + "\"");
      return;
    }
  }
  else if (suffix == "vtt") {
    if (!SubParser::ExportVtt(Subtitles, SubFilePath)) {
      QMessageBox::critical(this, "Error", "Could't save file to \"" + SubFilePath + "\"");
      return;
    }
  }
  else {
    QMessageBox::critical(this, "Error", "Unsupported file type \"" + suffix + "\"");
    return;
  }

  SetIsSaved(true);
}

void MainWindow::SaveAsAction() {
  QString file = QFileDialog::getSaveFileName(this, "Save File As", QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation), SubtitleFileSelector);

  if (file.isEmpty()) {
    return;
  }

  QString suffix(QFileInfo(file).suffix());
  if (suffix == "srt") {
    if (!SubParser::ExportSrt(Subtitles, file)) {
      QMessageBox::critical(this, "Error", "Could't save file to \"" + file + "\"");
      return;
    }
  }
  else if (suffix == "vtt") {
    if (!SubParser::ExportVtt(Subtitles, file)) {
      QMessageBox::critical(this, "Error", "Could't save file to \"" + file + "\"");
      return;
    }
  }
  else {
    QMessageBox::critical(this, "Error", "Unsupported file type \"" + suffix + "\"");
    return;
  }

  SubFilePath = file;
  SetIsSaved(true);
}

void MainWindow::CloseAction() {
  if (!CheckIfSaved()) {
    return;
  }

  subtitlesModel->clear();
  Subtitles.clear();

  SubFilePath.clear();
  SetWindowTitle("");

  EditingSubtitleIndex = -1;
  PrevEditinSubtitleIndex = EditingSubtitleIndex;

  UndoItems.clear();
  RedoItems.clear();

  subTextItem->setPlainText(QString());

  ui->SubtitleTextEdit->setPlainText(QString());
  ui->ShowSubTimeEdit->setTime(QTime());
  ui->HideSubTimeEdit->setTime(QTime());

  ui->SubtitleGroupBox->setEnabled(false);
  hasFileOpen = false;
}

void MainWindow::ExitAction() {
  this->close();
}

// Edit
void MainWindow::UndoAction() {
  if (UndoItems.isEmpty()) {
    QMessageBox::warning(this, "Warning", "There isn't anything to undo");
    return;
  }

  SubtitleItem NewItem;
  UndoItem undo = UndoItems.last();
  UndoItem::ItemType itemType = undo.getItemType();

  if (itemType == UndoItem::ItemType::ADD) {
    int i = Subtitles.indexOf(undo.getNewItem());
    if (i >= 0) {
      Subtitles.removeAt(i);
      subtitlesModel->removeRow(i);
    }
  }
  else if (itemType == UndoItem::ItemType::REMOVE) {
    SubtitleItem SubItem = undo.getNewItem();
    if (Subtitles.indexOf(SubItem) != -1) {
      RedoItems.removeLast();
      return;
    }

    subtitlesModel->setItem(Subtitles.size(), 0, new QStandardItem(SubItem.getShowTimestamp().toString("hh:mm:ss,zzz")));
    subtitlesModel->setItem(Subtitles.size(), 1, new QStandardItem(SubItem.getHideTimestamp().toString("hh:mm:ss,zzz")));
    subtitlesModel->setItem(Subtitles.size(), 2, new QStandardItem(SubItem.getSubtitle()));

    Subtitles.push_back(SubItem);

    NewItem = SubItem;
  }
  else if (itemType == UndoItem::ItemType::EDIT) {
    int i = Subtitles.indexOf(undo.getNewItem());
    if (i >= 0) {
      SubtitleItem SubItem(undo.getOldItem());

      subtitlesModel->setItem(i, 0, new QStandardItem(SubItem.getShowTimestamp().toString("hh:mm:ss,zzz")));
      subtitlesModel->setItem(i, 1, new QStandardItem(SubItem.getHideTimestamp().toString("hh:mm:ss,zzz")));
      subtitlesModel->setItem(i, 2, new QStandardItem(SubItem.getSubtitle()));

      Subtitles.replace(i, SubItem);

      NewItem = SubItem;
    }
  }
  else if (itemType == UndoItem::ItemType::UNIVERSAL_EDIT) {
      Subtitles.clear();

      for (int idx = 0; idx < undo.getOldItems().length(); idx++) {
        SubtitleItem oldItem = undo.getOldItems().at(idx);

        subtitlesModel->setItem(idx, 0, new QStandardItem(oldItem.getShowTimestamp().toString("hh:mm:ss,zzz")));
        subtitlesModel->setItem(idx, 1, new QStandardItem(oldItem.getHideTimestamp().toString("hh:mm:ss,zzz")));
        subtitlesModel->setItem(idx, 2, new QStandardItem(oldItem.getSubtitle()));

        Subtitles.append(oldItem);
      }
  }

  RedoItems.append(undo);
  UndoItems.removeLast();

  subtitlesModel->sort(0);
  std::sort(Subtitles.begin(), Subtitles.end(), SubtitleItem::SortByShowTime);

  SelectSubFromTable(Subtitles.indexOf(NewItem));

  SetIsSaved(false);

  ShowAvailableSub();
}

void MainWindow::RedoAction() {
  if (RedoItems.isEmpty()) {
    QMessageBox::warning(this, "Warning", "There isn't anything to redo");
    return;
  }

  SubtitleItem NewItem;
  UndoItem redo = RedoItems.last();
  UndoItem::ItemType itemType = redo.getItemType();

  if (itemType == UndoItem::ItemType::ADD) {
    SubtitleItem SubItem = redo.getNewItem();
    if (Subtitles.indexOf(SubItem) != -1) {
      RedoItems.removeLast();
      return;
    }

    subtitlesModel->setItem(Subtitles.size(), 0, new QStandardItem(SubItem.getShowTimestamp().toString("hh:mm:ss,zzz")));
    subtitlesModel->setItem(Subtitles.size(), 1, new QStandardItem(SubItem.getHideTimestamp().toString("hh:mm:ss,zzz")));
    subtitlesModel->setItem(Subtitles.size(), 2, new QStandardItem(SubItem.getSubtitle()));

    Subtitles.push_back(SubItem);

    NewItem = SubItem;
  }
  else if (itemType == UndoItem::ItemType::REMOVE) {
    int i = Subtitles.indexOf(redo.getNewItem());
    if (i >= 0) {
      Subtitles.removeAt(i);
      subtitlesModel->removeRow(i);
    }
  }
  else if (itemType == UndoItem::ItemType::EDIT) {
    int i = Subtitles.indexOf(redo.getOldItem());
    if (i >= 0) {
      SubtitleItem SubItem(redo.getNewItem());

      subtitlesModel->setItem(i, 0, new QStandardItem(SubItem.getShowTimestamp().toString("hh:mm:ss,zzz")));
      subtitlesModel->setItem(i, 1, new QStandardItem(SubItem.getHideTimestamp().toString("hh:mm:ss,zzz")));
      subtitlesModel->setItem(i, 2, new QStandardItem(SubItem.getSubtitle()));

      Subtitles.replace(i, SubItem);

      NewItem = SubItem;
    }
  }
  else if (itemType == UndoItem::ItemType::UNIVERSAL_EDIT) {
    Subtitles.clear();

    for (int idx = 0; idx < redo.getNewItems().length(); idx++) {
      SubtitleItem newItem = redo.getNewItems().at(idx);

      subtitlesModel->setItem(idx, 0, new QStandardItem(newItem.getShowTimestamp().toString("hh:mm:ss,zzz")));
      subtitlesModel->setItem(idx, 1, new QStandardItem(newItem.getHideTimestamp().toString("hh:mm:ss,zzz")));
      subtitlesModel->setItem(idx, 2, new QStandardItem(newItem.getSubtitle()));

      Subtitles.append(newItem);
    }
  }

  UndoItems.append(redo);
  RedoItems.removeLast();

  subtitlesModel->sort(0);
  std::sort(Subtitles.begin(), Subtitles.end(), SubtitleItem::SortByShowTime);

  SelectSubFromTable(Subtitles.indexOf(NewItem));

  SetIsSaved(false);

  ShowAvailableSub();
}

// Media
void MainWindow::OpenMediaAction() {
  QString file = QFileDialog::getOpenFileName(this, "Open Movie", QStandardPaths::writableLocation(QStandardPaths::MoviesLocation), MediaFileSelector);

  if (file.isEmpty()) {
    return;
  }

  if (!QFile(file).exists()) {
    QMessageBox::critical(this, "Error", "File \"" + file + "\" doesn't exist");
    return;
  }

  OpenMediaFile(file);
}

void MainWindow::CloseMediaAction() {
  player->setMedia(QMediaContent());
  player->stop();

  SetMediaControlsEnabled(false);

  ui->TogglePlayButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
}

// Help
void MainWindow::AboutHelpAction() {
  AboutDialog *dialog = new AboutDialog(this);
  dialog->show();
}

void MainWindow::AboutQtHelpAction() {
	QMessageBox::aboutQt(this);
}

// Media player
void MainWindow::OpenMediaFile(const QString &Path) {
  player->setMedia(QUrl::fromLocalFile(Path));
  player->play();

  ui->TogglePlayButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
  ui->StopButton->setIcon(style()->standardIcon(QStyle::SP_MediaStop));

  SetMediaControlsEnabled(true);
}

void MainWindow::VideoSeekableChanged(bool) {
  UpdateUI();
}

void MainWindow::VideoDurationChanged(qint64 value) {
  if (value == 0) {
    ui->TimelineSlider->setMaximum(1);
    ui->TimelineSlider->setEnabled(false);
  }

  ui->TimelineSlider->setEnabled(true);
  ui->TimelineSlider->setMaximum(value);
}

void MainWindow::VideoPositionChanged(qint64 value) {
  int TotalDuration = player->duration();
  int CurrentPosition = value;

  if (!ui->TimelineSlider->isSliderDown())
    ui->TimelineSlider->setValue(value);

  int SubDuration = QTime(0, 0, 0).msecsTo(ui->DurationSubTimeEdit->time());

  ui->ShowSubTimeEdit->setTime(MsToTime(CurrentPosition));
  ui->HideSubTimeEdit->setTime(MsToTime(CurrentPosition + SubDuration));

  ui->TimelineLabel->setText(MsToTime(CurrentPosition).toString("hh:mm:ss,zzz") + " / " + MsToTime(TotalDuration).toString("hh:mm:ss,zzz"));

  ShowAvailableSub();
}

void MainWindow::TimelineSliderChanged(int value) {
  player->setPosition(value);
}

void MainWindow::TogglePlayVideo() {
  if (player->mediaStatus() == QMediaPlayer::NoMedia)
    return;

  if (player->state() == QMediaPlayer::PlayingState) {
    ui->TogglePlayButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    player->pause();
  }
  else {
    ui->StopButton->setEnabled(true);
    ui->TogglePlayButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
    player->play();
  }
}

void MainWindow::StopVideo() {
  ui->TogglePlayButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
  ui->StopButton->setEnabled(false);

  player->stop();
}

void MainWindow::SeekForwards() {
  if (player->mediaStatus() == QMediaPlayer::NoMedia)
    return;

  player->setPosition(player->position() + mediaSeekFactor);
}

void MainWindow::SeekBackwards() {
  if (player->mediaStatus() == QMediaPlayer::NoMedia)
    return;

  player->setPosition(player->position() - mediaSeekFactor);
}

void MainWindow::VolumeUp() {
  ui->VolumeSlider->setValue(ui->VolumeSlider->value() + 5);
}

void MainWindow::VolumeDown() {
  ui->VolumeSlider->setValue(ui->VolumeSlider->value() - 5);
}

void MainWindow::ToggleMuteAudio() {
  if (player->isMuted()) {
    player->setMuted(false);
    ui->ToggleMuteButton->setIcon(style()->standardIcon(QStyle::SP_MediaVolume));
  }
  else {
    player->setMuted(true);
    ui->ToggleMuteButton->setIcon(style()->standardIcon(QStyle::SP_MediaVolumeMuted));
  }
}

void MainWindow::VolumeSliderChanged(int value) {
  player->setVolume(value);
}

// Subtitle Group
void MainWindow::OpenSubtitleFile(const QString &Path) {
  SubFilePath = Path;
  QFileInfo fileInfo(SubFilePath);

  UndoItems.clear();
  RedoItems.clear();

  EditingSubtitleIndex = -1;
  PrevEditinSubtitleIndex = EditingSubtitleIndex;

  QString suffix(fileInfo.suffix());

  try {
    if (suffix == "srt") {
      Subtitles = SubParser::ParseSrt(SubFilePath);
    }
    else if (suffix == "vtt") {
      Subtitles = SubParser::ParseVtt(SubFilePath);
    }
    else {
      QMessageBox::critical(this, "Error", "Unsupported file type: \"" + suffix + "\"");
      CloseAction();
      return;
    }
  }  catch (const QString error) {
    QMessageBox::critical(this, "Parse Error", error);
    CloseAction();
    return;
  }

  subtitlesModel->clear();

  if (Subtitles.length() == 0) {
    QMessageBox::critical(this, "Parse Error", "File format is corrupt and could not be parsed.");
    CloseAction();
    return;
  }

  for (int i = 0; i < Subtitles.size(); i++) {
    subtitlesModel->setItem(i, 0, new QStandardItem(Subtitles.at(i).getShowTimestamp().toString("hh:mm:ss,zzz")));
    subtitlesModel->setItem(i, 1, new QStandardItem(Subtitles.at(i).getHideTimestamp().toString("hh:mm:ss,zzz")));
    subtitlesModel->setItem(i, 2, new QStandardItem(Subtitles.at(i).getSubtitle()));
  }

  subtitlesModel->sort(0);

  ui->SubtitleGroupBox->setEnabled(true);
  SetIsSaved(true);
}

void MainWindow::ShowAvailableSub() {
  int Position = player->position();

  ClearSubtitle();

  for (int i = 0; i < Subtitles.size(); i++) {
    int SubShowTime = QTime(0, 0, 0).msecsTo(Subtitles.at(i).getShowTimestamp());
    int SubHideTime = QTime(0, 0, 0).msecsTo(Subtitles.at(i).getHideTimestamp());

    int NextSubShowTime = -1;
    if (Subtitles.size()-1 >= i+1) {
      NextSubShowTime = QTime(0, 0, 0).msecsTo(Subtitles.at(i+1).getShowTimestamp());
    }

    if (SubShowTime <= Position && Position <= SubHideTime && (Position != NextSubShowTime)) {
      DisplaySubtitle(Subtitles.at(i));
      break;
    }
  }
}

void MainWindow::DisplaySubtitle(const SubtitleItem &subItem) {
  int index = Subtitles.indexOf(subItem);
  if (index == -1)
    return;

  // Display Subtitle on Video
  subTextItem->setHtml(subItem.getSubtitle().replace('\n', "<br>"));

  UpdateSubAlignment();
  UpdateSubPosition();

  // Fill active Subtitle values on fields
  int SubShowTime = QTime(0, 0, 0).msecsTo(subItem.getShowTimestamp());
  int SubHideTime = QTime(0, 0, 0).msecsTo(subItem.getHideTimestamp());

  ui->ShowSubTimeEdit->setTime(subItem.getShowTimestamp());
  ui->HideSubTimeEdit->setTime(subItem.getHideTimestamp());
  ui->SubtitleTextEdit->setPlainText(subItem.getSubtitle());
  ui->DurationSubTimeEdit->setTime(MsToTime(SubHideTime - SubShowTime));

  // Select active Subtitle on table
  ui->SubTableView->selectRow(index);
  EditingSubtitleIndex = index;
  PrevEditinSubtitleIndex = EditingSubtitleIndex;

  isSubApplied = true;
}

void MainWindow::ClearSubtitle() {
  subTextItem->setPlainText(QString());

  ui->ShowSubTimeEdit->setTime(QTime());
  ui->HideSubTimeEdit->setTime(QTime());
  ui->SubtitleTextEdit->setPlainText(QString());

  ui->SubTableView->clearSelection();

  EditingSubtitleIndex = -1;
  isSubApplied = true;
}

void MainWindow::SelectSubFromTable(int row) {
  if (0 > row || row >= Subtitles.size())
    return;

  if (!isSubApplied && EditingSubtitleIndex >= 0) {
    SubtitleItem currentSub = Subtitles.at(EditingSubtitleIndex);
    QString Timestamps = currentSub.getShowTimestamp().toString("hh:mm:ss,zzz") + " - " + currentSub.getHideTimestamp().toString("hh:mm:ss,zzz");

    int result = QMessageBox::question(this, "Confirm", "Subtitle at \"" + Timestamps + "\" has changed. Apply?", QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel, QMessageBox::Yes);
    if (result == QMessageBox::Yes) {
      ApplySubtitlePressed();
    }
    else if (result == QMessageBox::Cancel) {
      ui->SubTableView->selectRow(PrevEditinSubtitleIndex);
      return;
    }
  }

  player->setPosition(QTime(0, 0, 0).msecsTo(Subtitles.at(row).getShowTimestamp()));
}

void MainWindow::SubTableRowClicked(QModelIndex index) {
  SelectSubFromTable(index.row());
}

void MainWindow::GotoPreviousSub() {
  SelectSubFromTable(PrevEditinSubtitleIndex - 1);
}

void MainWindow::GotoNextSub() {
  SelectSubFromTable(PrevEditinSubtitleIndex + 1);
}

void MainWindow::DelaySubtitles() {
  if (!hasFileOpen) {
    QMessageBox::critical(this, "Error", "You need to open a file first");
    return;
  }

  int maxValue = 1000;
  double delayValue = QInputDialog::getDouble(this, "Delay", "Delay time (seconds): ", 0, -maxValue, maxValue, 3);

  QList<SubtitleItem> newItems;

  for (int idx = 0; idx < Subtitles.length(); idx++) {
    SubtitleItem item = Subtitles.at(idx);
    item.setShowTimestamp(item.getShowTimestamp().addMSecs(delayValue * 1000));
    item.setHideTimestamp(item.getHideTimestamp().addMSecs(delayValue * 1000));

    newItems.append(item);
  }

  ApplySubtitles(newItems);
}

void MainWindow::SubShowTimeChanged() {
  int SubShowTime = QTime(0, 0, 0).msecsTo(ui->ShowSubTimeEdit->time());
  int SubHideTime = QTime(0, 0, 0).msecsTo(ui->HideSubTimeEdit->time());

  if (SubHideTime - SubShowTime < 0) {
    int SubDuration = QTime(0, 0, 0).msecsTo(ui->DurationSubTimeEdit->time());
    ui->HideSubTimeEdit->setTime(MsToTime(SubShowTime + SubDuration));
  }
}

void MainWindow::SubHideTimeChanged() {
  int SubShowTime = QTime(0, 0, 0).msecsTo(ui->ShowSubTimeEdit->time());
  int SubHideTime = QTime(0, 0, 0).msecsTo(ui->HideSubTimeEdit->time());

  ui->DurationSubTimeEdit->setTime(MsToTime(SubHideTime - SubShowTime));
}

void MainWindow::SubDurationChanged() {
  int SubShowTime = QTime(0, 0, 0).msecsTo(ui->ShowSubTimeEdit->time());
  int SubDuration = QTime(0, 0, 0).msecsTo(ui->DurationSubTimeEdit->time());

  ui->HideSubTimeEdit->setTime(MsToTime(SubShowTime + SubDuration));
}

void MainWindow::SubTextToggleTag(const QString &tag) {
  QTextCursor textCursor = ui->SubtitleTextEdit->textCursor();

  if (textCursor.hasSelection()) {
    QString selectedText(textCursor.selectedText());
    QRegExp expression("<" + tag + ">(.*)</" + tag + ">");

    if (expression.exactMatch(selectedText)) {
      selectedText.replace(expression, "\\1");
      textCursor.insertText(selectedText);
    }
    else {
      textCursor.insertText("<" + tag + ">" + selectedText + "</" + tag + ">");
    }
  }
  else {
    textCursor.select(QTextCursor::WordUnderCursor);
    QString selectedWord = textCursor.selectedText();

    int AbsoluteEndPos = textCursor.position();
    int RelativeEndPos = textCursor.positionInBlock();

    textCursor.select(QTextCursor::BlockUnderCursor);
    QString selectedBlock = textCursor.selectedText();

    QRegExp expression("(.*)<" + tag + ">(.*)(" + selectedWord + ")(.*)</" + tag + ">(.*)");
    expression.setMinimal(true);
    expression.indexIn(selectedBlock, 0, QRegExp::CaretAtOffset);
    int foundPosition = expression.pos(3);

    if ((AbsoluteEndPos == RelativeEndPos && foundPosition == RelativeEndPos - selectedWord.length()) ||
        (AbsoluteEndPos != RelativeEndPos && foundPosition == RelativeEndPos - selectedWord.length() + 1)) {
      selectedBlock.replace(expression, "\\1\\2\\3\\4\\5");

      textCursor.insertText(selectedBlock);
      textCursor.setPosition(AbsoluteEndPos - 2 - tag.length());

      ui->SubtitleTextEdit->setTextCursor(textCursor);
    }
  }
}

void MainWindow::SubTextChanged() {
  isSubApplied = false;
}

void MainWindow::SubCursorPosChanged() {
  QTextCursor textCursor = ui->SubtitleTextEdit->textCursor();

  int TagsLength = 4;
  QString Tags[] = { "b", "i", "u", "s" };
  QToolButton *Buttons[] = { ui->SubBoldButton, ui->SubItalicButton, ui->SubUnderlineButton, ui->SubStrikeoutButton };

  if (textCursor.hasSelection()) {
    QString selectedText(textCursor.selectedText());
    for (int i = 0; i < TagsLength; i++) {
      QString regExp("<" + Tags[i] + ">(.*)</" + Tags[i] + ">");
      Buttons[i]->setChecked(QRegExp(regExp).exactMatch(selectedText));
    }
  }
  else {
    textCursor.select(QTextCursor::WordUnderCursor);
    QString selectedWord = textCursor.selectedText();

    int AbsoluteEndPos = textCursor.position();
    int RelativeEndPos = textCursor.positionInBlock();

    textCursor.select(QTextCursor::BlockUnderCursor);
    QString selectedBlock = textCursor.selectedText();

    for (int i = 0; i < TagsLength; i++) {
      QRegExp expression(".*<" + Tags[i] + ">.*(" + selectedWord + ").*</" + Tags[i] + ">.*");
      expression.indexIn(selectedBlock, 0, QRegExp::CaretAtOffset);
      int foundPosition = expression.pos(1);

      if (AbsoluteEndPos == RelativeEndPos) {
        Buttons[i]->setChecked(foundPosition == RelativeEndPos - selectedWord.length());
      }
      else {
        Buttons[i]->setChecked(foundPosition == RelativeEndPos - selectedWord.length() + 1);
      }
    }
  }
}

void MainWindow::SubBoldClicked() {
  SubTextToggleTag("b");
}

void MainWindow::SubItalicClicked() {
  SubTextToggleTag("i");
}

void MainWindow::SubUnderlineClicked() {
  SubTextToggleTag("u");
}

void MainWindow::SubStrikeoutClicked() {
  SubTextToggleTag("s");
}

bool MainWindow::ApplySubtitle(const SubtitleItem &item, const int index) {
  if (index < 0) {
    subtitlesModel->setItem(Subtitles.size(), 0, new QStandardItem(item.getShowTimestamp().toString("hh:mm:ss,zzz")));
    subtitlesModel->setItem(Subtitles.size(), 1, new QStandardItem(item.getHideTimestamp().toString("hh:mm:ss,zzz")));
    subtitlesModel->setItem(Subtitles.size(), 2, new QStandardItem(item.getSubtitle()));

    Subtitles.push_back(item);
    UndoItems.append(UndoItem(item, UndoItem::ItemType::ADD));
  }
  else {
    subtitlesModel->setItem(index, 0, new QStandardItem(item.getShowTimestamp().toString("hh:mm:ss,zzz")));
    subtitlesModel->setItem(index, 1, new QStandardItem(item.getHideTimestamp().toString("hh:mm:ss,zzz")));
    subtitlesModel->setItem(index, 2, new QStandardItem(item.getSubtitle()));

    UndoItems.append(UndoItem(Subtitles.at(index), item, UndoItem::ItemType::EDIT));
    Subtitles.replace(index, item);
  }

  subtitlesModel->sort(0);
  std::sort(Subtitles.begin(), Subtitles.end(), SubtitleItem::SortByShowTime);

  isSubApplied = true;
  SetIsSaved(false);

  ShowAvailableSub();

  return true;
}

bool MainWindow::ApplySubtitles(const QList<SubtitleItem> &items) {
  UndoItems.append(UndoItem(Subtitles, items, UndoItem::ItemType::UNIVERSAL_EDIT));
  Subtitles.clear();

  for (int idx = 0; idx < items.length(); idx++) {
    SubtitleItem item = items.at(idx);

    subtitlesModel->setItem(idx, 0, new QStandardItem(item.getShowTimestamp().toString("hh:mm:ss,zzz")));
    subtitlesModel->setItem(idx, 1, new QStandardItem(item.getHideTimestamp().toString("hh:mm:ss,zzz")));
    subtitlesModel->setItem(idx, 2, new QStandardItem(item.getSubtitle()));

    Subtitles.append(item);
  }

  subtitlesModel->sort(0);
  std::sort(Subtitles.begin(), Subtitles.end(), SubtitleItem::SortByShowTime);

  isSubApplied = true;
  SetIsSaved(false);

  ShowAvailableSub();

  return true;
}

void MainWindow::ApplySubtitlePressed() {
  if (!hasFileOpen) {
    QMessageBox::critical(this, "Error", "You need to open a file first");
    return;
  }

  QString SubText = ui->SubtitleTextEdit->toPlainText();
  QTime SubShowTime = ui->ShowSubTimeEdit->time();
  QTime SubHideTime = ui->HideSubTimeEdit->time();

  SubtitleItem SubItem(SubShowTime, SubHideTime, SubText);

  if (SubText.isEmpty()) {
    QMessageBox::warning(this, "Warning", "Subtitle text cannot be empty");
    return;
  }

  if (ApplySubtitle(SubItem, EditingSubtitleIndex)) {
    ui->SubtitleTextEdit->clearFocus();
  }
}

void MainWindow::RemoveSubtitle() {
  if (!hasFileOpen) {
      QMessageBox::critical(this, "Error", "You need to open a file first");
      return;
  }

  if (EditingSubtitleIndex < 0) {
      QMessageBox::warning(this, "Warning", "You need to select a subtitle first");
      return;
  }

  subtitlesModel->removeRow(EditingSubtitleIndex);
  subtitlesModel->sort(0);

  UndoItems.append(UndoItem(Subtitles.at(EditingSubtitleIndex), UndoItem::ItemType::REMOVE));

  Subtitles.removeAt(EditingSubtitleIndex);
  std::sort(Subtitles.begin(), Subtitles.end(), SubtitleItem::SortByShowTime);

  ui->SubtitleTextEdit->setPlainText(QString());
  ui->ShowSubTimeEdit->setTime(QTime());
  ui->HideSubTimeEdit->setTime(QTime());

  EditingSubtitleIndex = -1;
  isSubApplied = true;

  SetIsSaved(false);

  ui->SubtitleTextEdit->clearFocus();
}
