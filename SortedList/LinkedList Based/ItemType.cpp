//
// Created by Havoc-PC on 8/3/2019.
//

#include "ItemType.h"
#include<fstream>
#include<iostream>
ItemType::ItemType() {
    value = 0;
}

RelationType ItemType::ComparedTo(ItemType otherItem) {
    if(value < otherItem.value)
        return LESS;
    else if (value > otherItem.value)
        return GREATER;
    else return EQUAL;
}
void ItemType::Initialize(int number) {
    value = number;
}
void ItemType::Print(std::ostream& out) {
    out<<value;
}