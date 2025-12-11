#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "Item.h"

class Inventory {
private:
    std::vector<Item> items;

public:
    Inventory();
    ~Inventory();

    void add(const Item& item);
    void show() const;
};

#endif
