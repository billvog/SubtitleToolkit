#include "UndoItem.h"

UndoItem::UndoItem(const QList<SubtitleItem> &oldItems, const QList<SubtitleItem> &newItems, ItemType type) {
  OldItems = oldItems;
  NewItems = newItems;
  Type = type;
}

UndoItem::UndoItem(const SubtitleItem &newItem, ItemType type) {
  OldItem = SubtitleItem();
  NewItem = newItem;
  Type = type;
}

UndoItem::UndoItem(const SubtitleItem &oldItem, const SubtitleItem &newItem, ItemType type) {
  OldItem = oldItem;
  NewItem = newItem;
  Type = type;
}

bool operator==(const UndoItem& lhs, const UndoItem& rhs) {
  return (
          (lhs.getNewItem() == rhs.getNewItem() &&
          lhs.getOldItem() == rhs.getOldItem()) ||
          (lhs.getNewItems() == rhs.getNewItems() && lhs.getOldItems() == rhs.getOldItems())
         ) &&
         lhs.getItemType() == rhs.getItemType();
}
