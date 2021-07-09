/*
	UndoItem class is used for undoing and redoing actions that user made.
	
	Each instance stores:
	- an ItemType enum that specifies the kind of action user so the program
	knows how to undo it
	- an oldItem
	- a newItem
	- and in case of universal edit (all subs where affected):
		- an oldItems
		- and a newItems
*/

#pragma once

#include <QString>
#include "SubtitleItem.h"

class UndoItem {
  public:
    enum ItemType {
        ADD, // User create a new subtitle
        REMOVE, // User removed a subtitle
        EDIT, // User edited a subtitle
        UNIVERSAL_EDIT // User altered all subtitles (ex Delay action delays ALL subtitles for a user inputted value)
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
