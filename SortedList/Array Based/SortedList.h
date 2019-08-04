//
// Created by Havoc-PC on 8/3/2019.
//

#ifndef UNTITLED1_SORTEDLIST_H
#define UNTITLED1_SORTEDLIST_H
#include "ItemType.h"

class SortedList {
public:
    SortedList();
    void MakeEmpty();
    bool IsFull();
    int GetLength();
    ItemType GetItem(ItemType item, bool& found);
    void PutItem(ItemType item);
    void DeleteItem(ItemType item);
    void ResetList();
    ItemType GetNextItem();
private :
    int length;
    ItemType info[MAX_ITEMS];
    int currentPos;
};


#endif //UNTITLED1_SORTEDLIST_H
