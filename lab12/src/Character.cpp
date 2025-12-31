#include "Character.h"
#include <iostream>

Character::Character()
    : name("Unknown"), hp(100), baseDamage(5)
{}

Character::Character(const std::string& n, int health)
    : name(n), hp(health), baseDamage(5)
{}

Character::Character(const std::string& n, int health, int dmg)
    : name(n), hp(health), baseDamage(dmg)
{}

Character::~Character()
{
#ifdef DEBUG
    std::cout << "[DEBUG][Character] Destructor called for " << name << "\n";
#endif
}

void Character::showStats() const
{
    std::cout << "Postać: " << name 
              << ", HP: " << hp 
              << ", DMG: " << baseDamage << "\n";
}

Inventory& Character::getInventory()
{
    return inventory;
}

int Character::getHp() const
{
    return hp;
}

int Character::getBaseDamage() const
{
    return baseDamage;
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
