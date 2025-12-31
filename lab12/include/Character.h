#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "Inventory.h"

class Character {
private:
    std::string name;
    int hp;
    int baseDamage;     // <-- BRAKOWAŁO!!!
    Inventory inventory;

public:
    Character();
    Character(const std::string& n, int health);
    Character(const std::string& n, int health, int dmg);

    ~Character();

    void showStats() const;
    Inventory& getInventory();

    int getHp() const;
    int getBaseDamage() const;
    void takeDamage(int dmg);
    bool isAlive() const;
};

#endif
