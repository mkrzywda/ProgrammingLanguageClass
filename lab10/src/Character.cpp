#include "Character.h"
#include <iostream>

Character::Character()
{
    name = "Rycerz";
    hp = 100;

#ifdef DEBUG
    std::cout << "[DEBUG][Character] Konstruktor domyślny: " << name << "\n";
#endif
}

Character::Character(const std::string& n, int health)
{
    name = n;
    hp = health;

#ifdef DEBUG
    std::cout << "[DEBUG][Character] Konstruktor parametryczny: " << name << "\n";
#endif
}

Character::~Character()
{
#ifdef DEBUG
    std::cout << "[DEBUG][Character] Destruktor: " << name << "\n";
#endif
}

void Character::showStats() const
{
    std::cout << "\n=== Postać ===\n";
    std::cout << "Imię: " << name << "\n";
    std::cout << "HP: " << hp << "\n";
}

Inventory& Character::getInventory()
{
    return inventory;
}

int Character::getHp() const
{
    return hp;
}

void Character::takeDamage(int dmg)
{
    hp -= dmg;
    if (hp < 0) hp = 0;
}

bool Character::isAlive() const
{
    return hp > 0;
}
