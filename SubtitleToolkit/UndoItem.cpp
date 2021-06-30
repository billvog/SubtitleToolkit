#include "UndoItem.h"

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
    return lhs.getNewItem() == rhs.getNewItem() &&
            lhs.getOldItem() == rhs.getOldItem() &&
            lhs.getItemType() == rhs.getItemType();
}
