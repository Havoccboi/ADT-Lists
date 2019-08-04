//
// Created by Havoc-PC on 8/3/2019.
//

#ifndef UNTITLED1_ITEMTYPE_H
#define UNTITLED1_ITEMTYPE_H

#include<fstream>
const int MAX_ITEMS = 5;
enum RelationType {LESS,EQUAL,GREATER};
class ItemType {
public:
    ItemType();
    RelationType ComparedTo(ItemType);
    void Print(std::ostream&);
    void Initialize(int number);

private:
    int value;
};


#endif //UNTITLED1_ITEMTYPE_H
