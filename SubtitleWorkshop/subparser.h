#pragma once

#include <QDebug>

#include <QList>
#include <QFile>
#include <QTextStream>

#include "subtitleitem.h"

class SubParser {
public:
    SubParser();

    // SubRip (.srt)
    static QList<SubtitleItem> ParseSrt(QString filepath);
    static bool ExportSrt(QList<SubtitleItem> items, QString filepath);

    // WebVTT (.vtt)
    static QList<SubtitleItem> ParseVtt(QString filepath);
    static bool ExportVtt(QList<SubtitleItem> items, QString filepath);
};
