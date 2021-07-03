#pragma once

#include <QString>
#include "SubtitleItem.h"

class UndoItem {
  public:
    enum ItemType {
        ADD,
        REMOVE,
        EDIT,
        UNIVERSAL_EDIT
    };

    UndoItem(const QList<SubtitleItem> &oldItems, const QList<SubtitleItem> &newItems, ItemType type);
    UndoItem(const SubtitleItem &newItem, ItemType type);
    UndoItem(const SubtitleItem &oldItem, const SubtitleItem &newItem, ItemType type);

    ItemType getItemType() const { return Type; }

    SubtitleItem getOldItem() const { return OldItem; }
    SubtitleItem getNewItem() const { return NewItem; }

    QList<SubtitleItem> getOldItems() const { return OldItems; }
    QList<SubtitleItem> getNewItems() const { return NewItems; }

    friend bool operator==(const UndoItem& lhs, const UndoItem& rhs);

  private:
    ItemType Type;

    QList<SubtitleItem> OldItems;
    QList<SubtitleItem> NewItems;

    SubtitleItem OldItem;
    SubtitleItem NewItem;
};
