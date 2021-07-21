/*
	UndoItem class is used for keeping history of user actions
	so he can undo or redo them.
*/

#pragma once

#include <QString>
#include "SubtitleItem.h"

class UndoItem {
  public:
    enum ItemType {
        ADD, // User created a new subtitle
        REMOVE, // User removed a subtitle
        EDIT, // User edited a subtitle
        UNIVERSAL_EDIT // User altered all subtitles (example: Delay action affects ALL subtitles)
    };

    UndoItem(const QList<SubtitleItem> &oldItems, const QList<SubtitleItem> &newItems, ItemType type);
    UndoItem(const SubtitleItem &newItem, ItemType type);
    UndoItem(const SubtitleItem &oldItem, const SubtitleItem &newItem, ItemType type);

    inline ItemType getItemType() const { return Type; }

	inline SubtitleItem getOldItem() const { return OldItem; }
	inline SubtitleItem getNewItem() const { return NewItem; }

	inline QList<SubtitleItem> getOldItems() const { return OldItems; }
	inline QList<SubtitleItem> getNewItems() const { return NewItems; }

    friend bool operator==(const UndoItem& lhs, const UndoItem& rhs);

  private:
    ItemType Type;

    QList<SubtitleItem> OldItems;
    QList<SubtitleItem> NewItems;

    SubtitleItem OldItem;
    SubtitleItem NewItem;
};
