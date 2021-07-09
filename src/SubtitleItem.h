/*
	SubtitleItem class stores all information for each subtitle.
*/

#pragma once

#include <QString>
#include <QTime>

class SubtitleItem {
public:
  SubtitleItem();
  SubtitleItem(QTime showTimestamp, QTime hideTimestamp, QString subtitle);
	
private:
  QTime ShowTimestamp;
  QTime HideTimestamp;
  QString Subtitle;
	
public:
  void setShowTimestamp(QTime time);
  void setHideTimestamp(QTime time);
  void setSubtitle(QString value);

  QTime getShowTimestamp() const { return ShowTimestamp; }
  QTime getHideTimestamp() const { return HideTimestamp; }
  QString getSubtitle() const { return Subtitle; }

  static bool SortByShowTime(const SubtitleItem &s1, const SubtitleItem &s2);

  friend bool operator==(const SubtitleItem& lhs, const SubtitleItem& rhs);
};
