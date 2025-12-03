#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
public:
    std::string name;
    int damage;
    int value;

    Item();
    Item(const std::string& n, int dmg, int val);
    ~Item();
};

#endif
