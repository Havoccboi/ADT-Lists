//
// Created by Havoc-PC on 8/4/2019.
//

#include "SortedType.h"
SortedType::SortedType()
{
    length = 0;
    listData = NULL;
}
bool SortedType::IsFull()
{
    NodeType* location;
    try
    {
        location = new NodeType;
        delete location;
        return false;
    }
    catch(std::bad_alloc exception){
        return true;
    }
}
int SortedType::GetLength() {
    return length;
}
void SortedType::MakeEmpty() {
    NodeType* tempPtr;
    while(listData !=NULL){
        tempPtr=listData;
        listData = listData->next;
        delete tempPtr;
    }
    length = 0;
}

ItemType SortedType::GetItem(ItemType& item, bool& found)
{
    bool moreToSearch;
    NodeType* location;
    location = listData;
    found = false;
    moreToSearch = (location != NULL);
    while(moreToSearch && !found){
        switch(item.ComparedTo(location->info)){
            case GREATER : location = location->next;
            moreToSearch = location != NULL;
            break;
            case EQUAL: found = true;
            item = location->info;
            break;
            case LESS: moreToSearch = false;
        }
    }
    return item;
}

void SortedType::PutItem(ItemType item) {
    NodeType *newNode;
    NodeType* predLoc;
    NodeType* location;
    bool moreToSearch;
    location = listData;
    predLoc = NULL;
    moreToSearch = (location !=NULL);
    while(moreToSearch){
        switch(item.ComparedTo(location->info)){
            case GREATER:
                predLoc = location;
                location = location->next;
                moreToSearch = (location!= NULL);
                break;
            case LESS : moreToSearch = false;
            break;
        }
    }

    newNode = new NodeType;
    newNode->info = item;
    if(predLoc == NULL){
        newNode->next = listData;
        listData = newNode;
    }
    else {
         predLoc->next = newNode;
         newNode->next = location;
    }
    length++;
}

void SortedType::ResetList() {
    currentPos = NULL;
}
ItemType SortedType::GetNextItem() {
    ItemType item;
    if(currentPos == NULL)
        currentPos = listData;
    item = currentPos->info;
    currentPos = currentPos->next;
    return item;
}

void SortedType::DeleteItem(ItemType item) {
    NodeType* location = listData;
    NodeType* tempLocation;
    if(item.ComparedTo(listData->info) == EQUAL){
        tempLocation = location;
        listData = listData->next;
    }
    else {
        while(item.ComparedTo(location->next->info) != EQUAL)
            location = location->next;
        tempLocation = location->next;
        location->next = (location->next)->next;
    }
    delete tempLocation;
    length--;
}





SortedType::~SortedType() {
    NodeType* tempPtr;
    while(listData != NULL){
        tempPtr = listData;
        listData = listData -> next;
        delete tempPtr;
    }
}
