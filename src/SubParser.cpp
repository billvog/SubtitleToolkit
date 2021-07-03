#include "SubParser.h"

SubParser::SubParser() {}

// SubRip (.srt)
QList<SubtitleItem> SubParser::ParseSrt(QString filepath) {
  QList<SubtitleItem> Result;

  QFile File(filepath);
  if (!File.open(QIODevice::ReadOnly | QIODevice::Text)) {
    throw "File could not open";
  }

  QTextStream in(&File);
  while (!in.atEnd()) {
    in.readLine();

    QRegExp SubTimeRegEx("[0-9]{2}:[0-9]{2}:[0-9]{2},[0-9]{3}");

    QString SubShowTime = in.read(12);
    if (!SubTimeRegEx.exactMatch(SubShowTime)) {
      throw "Unexptected token at position: " + QString::number(in.pos());
    }

    in.seek(in.pos() + 5);

    QString SubHideTime = in.read(12);
    if (!SubTimeRegEx.exactMatch(SubHideTime)) {
      throw "Unexptected token at position: " + QString::number(in.pos());
    }

    in.seek(in.pos() + 1);

    QString SubText;
    QChar c;

    while (!in.atEnd()) {
      in >> c;
      if (c == '\n') {
        in >> c;

        if (c == '\n') break;

        in.seek(in.pos() - 2);
        in >> c;
      }

      SubText.append(c);
    }

    QTime SubtitleShowTimestamp = QTime().fromString(SubShowTime);
    QTime SubtitleHideTimestamp = QTime().fromString(SubHideTime);

    SubtitleItem item(SubtitleShowTimestamp, SubtitleHideTimestamp, SubText);
    Result.push_back(item);
  }

  File.close();

  return Result;
}

bool SubParser::ExportSrt(QList<SubtitleItem> items, QString filepath) {
  QFile File(filepath);
  if (!File.open(QIODevice::WriteOnly | QIODevice::Text)) {
    return false;
  }

  QTextStream out(&File);
  int SubCount = 0;

  for (int i = 0; i < items.size(); i++) {
    out << ++SubCount << "\n";
    out << items.at(i).getShowTimestamp().toString("hh:mm:ss,zzz");
    out << " --> ";
    out << items.at(i).getHideTimestamp().toString("hh:mm:ss,zzz");
    out << "\n";
    out << items.at(i).getSubtitle();

    if (i != items.size() - 1) {
      out << "\n\n";
    }
  }

  File.close();

  return true;
}

// WebVTT (.vtt)
QList<SubtitleItem> SubParser::ParseVtt(QString filepath) {
  QList<SubtitleItem> Result;

  QFile File(filepath);
  if (!File.open(QIODevice::ReadOnly | QIODevice::Text)) {
    return Result;
  }

  QTextStream in(&File);
  if (in.read(6) == "WEBVTT") {
    in.seek(in.pos() + 4);
  }
  else {
    in.seek(0);
  }

  while (!in.atEnd()) {
    QString SubShowTime = in.read(12);
    in.seek(in.pos() + 5);
    QString SubHideTime = in.read(12);

    in.seek(in.pos() + 1);

    QString SubText;
    QChar c;
    while (!in.atEnd()) {
      in >> c;
      if (c == '\n') {
        in >> c;

        if (c == '\n') break;

        in.seek(in.pos() - 2);
        in >> c;
      }

      SubText.append(c);
    }

    QTime SubtitleShowTimestamp = QTime().fromString(SubShowTime);
    QTime SubtitleHideTimestamp = QTime().fromString(SubHideTime);

    SubtitleItem item(SubtitleShowTimestamp, SubtitleHideTimestamp, SubText);
    Result.push_back(item);
  }

  File.close();

  return Result;
}

bool SubParser::ExportVtt(QList<SubtitleItem> items, QString filepath) {
  QFile File(filepath);
  if (!File.open(QIODevice::WriteOnly | QIODevice::Text)) {
    return false;
  }

  QTextStream out(&File);

  for (int i = 0; i < items.size(); i++) {
    out << items.at(i).getShowTimestamp().toString("hh:mm:ss.zzz");
    out << " --> ";
    out << items.at(i).getHideTimestamp().toString("hh:mm:ss.zzz");
    out << "\n";
    out << items.at(i).getSubtitle();

    if (i != items.size() - 1) {
        out << "\n\n";
    }
  }

  File.close();

  return true;
}
