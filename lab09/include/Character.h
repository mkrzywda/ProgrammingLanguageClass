#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "Inventory.h"

class Character {
private:
    std::string name;
    int hp;
    Inventory inventory;

public:
    Character();
    Character(const std::string& n, int health);
    ~Character();

    void showStats() const;
    Inventory& getInventory();

};

#endif
