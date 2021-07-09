/*
	SubParser class handles the parsing and exporting job for subtitles.
	Currently, it can only read two types of subtitle files (.srt and .vtt)
*/

#pragma once

#include <QDebug>
#include <QList>
#include <QFile>
#include <QTextStream>

#include "SubtitleItem.h"

class SubParser {
public:
  // SubRip (.srt)
  static QList<SubtitleItem> ParseSrt(QString filepath);
  static bool ExportSrt(QList<SubtitleItem> items, QString filepath);

  // WebVTT (.vtt)
  static QList<SubtitleItem> ParseVtt(QString filepath);
  static bool ExportVtt(QList<SubtitleItem> items, QString filepath);
};
