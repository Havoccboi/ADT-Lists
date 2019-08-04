//
// Created by Havoc-PC on 8/4/2019.
//

#ifndef UNTITLED2_SORTEDTYPE_H
#define UNTITLED2_SORTEDTYPE_H
#include "ItemType.h"
struct NodeType{
    ItemType info;
    NodeType* next;
};

class SortedType {
private:
    NodeType* listData;
    NodeType* currentPos;
    int length;

public:
    SortedType();
    ~SortedType();
    void PutItem(ItemType);
    void DeleteItem(ItemType);
    bool IsFull();
    int GetLength();
    void MakeEmpty();
    ItemType GetItem(ItemType& item, bool& found);
    void ResetList();
    ItemType GetNextItem();

};


#endif //UNTITLED2_SORTEDTYPE_H
