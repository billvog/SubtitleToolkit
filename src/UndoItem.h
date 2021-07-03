#pragma once

#include <QString>
#include "SubtitleItem.h"

class UndoItem {
  public:
    enum ItemType {
        ADD,
        REMOVE,
        EDIT
    };

    UndoItem(const SubtitleItem &newItem, ItemType type);
    UndoItem(const SubtitleItem &oldItem, const SubtitleItem &newItem, ItemType type);

    ItemType getItemType() const { return Type; }
    SubtitleItem getOldItem() const { return OldItem; }
    SubtitleItem getNewItem() const { return NewItem; }

    friend bool operator==(const UndoItem& lhs, const UndoItem& rhs);

  private:
    ItemType Type;
    SubtitleItem OldItem;
    SubtitleItem NewItem;
};
