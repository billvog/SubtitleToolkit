#include "SubtitleItem.h"

SubtitleItem::SubtitleItem() {}

SubtitleItem::SubtitleItem(QTime showTimestamp, QTime hideTimestamp, QString subtitle) {
  ShowTimestamp = showTimestamp;
  HideTimestamp = hideTimestamp;
  Subtitle = subtitle;
}

bool operator==(const SubtitleItem& lhs, const SubtitleItem& rhs) {
  return lhs.getSubtitle() == rhs.getSubtitle() &&
         lhs.getShowTimestamp() == rhs.getShowTimestamp() &&
         lhs.getHideTimestamp() == rhs.getHideTimestamp();
}

void SubtitleItem::setShowTimestamp(QTime time) {
  ShowTimestamp = time;
}

void SubtitleItem::setHideTimestamp(QTime time) {
  HideTimestamp = time;
}

void SubtitleItem::setSubtitle(QString value) {
  Subtitle = value;
}

bool SubtitleItem::SortByShowTime(const SubtitleItem &s1, const SubtitleItem &s2) {
  int Sub1ShowTime = QTime(0, 0, 0).msecsTo((s1.getShowTimestamp()));
  int Sub2ShowTime = QTime(0, 0, 0).msecsTo((s2.getShowTimestamp()));

  return Sub1ShowTime < Sub2ShowTime;
}
