//
// Created by Havoc-PC on 8/3/2019.
//

#include "SortedList.h"

SortedList::SortedList() {
    length = 0;
}
void SortedList::MakeEmpty() {
    length = 0;
}
bool SortedList::IsFull() {
    return (MAX_ITEMS == length);
}

int SortedList::GetLength() {
   return length;
}
ItemType SortedList::GetItem(ItemType item, bool &found) {
    found  = false;
    int first  = 0;
    int last = length-1;
    bool moreToSearch = first<=last;

    while(moreToSearch && !found){
        int mid = (first+last)/2;
        switch(item.ComparedTo(info[mid])){
            case GREATER : first = mid+1; moreToSearch = (first<=last); break;
            case LESS : last = mid-1; moreToSearch = (first<=last); break;
            default :
                found = true;
                 item = info[mid];
                 break;
        }
    }
    return item;
}
void SortedList::PutItem(ItemType item) {
    bool moreToSearch ;
    int location =0;
    moreToSearch = location < length;
    while(moreToSearch){
        switch(item.ComparedTo(info[location])){
            case LESS : moreToSearch = false;
            break;
            case GREATER : location++;
            moreToSearch = (location < length);
            break;
        }
    }

    for(int i = length; i > location ; i-- ){
        info[i] =  info[i-1];
    }
    info[location] = item;
    length++;
}
void SortedList::DeleteItem(ItemType item) {
    int location = 0 ;
    while(item.ComparedTo(info[location])!= EQUAL)
        location++;
    for(int index = location+1;index<length;index++)
    {
        info[index - 1] = info[index];
    }
    length--;
}

void SortedList::ResetList()
{
    currentPos = -1;
}
ItemType SortedList::GetNextItem()
{
    currentPos++;
    return info[currentPos];
}