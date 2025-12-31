#include "Item.h"
#include <iostream>

Item::Item()
{
    name = "Nieznany";
    damage = 0;
    value = 0;

#ifdef DEBUG
    std::cout << "[DEBUG][Item] Konstruktor domyślny\n";
#endif
}

Item::Item(const std::string& n, int dmg, int val)
{
    name = n;
    damage = dmg;
    value = val;

#ifdef DEBUG
    std::cout << "[DEBUG][Item] Konstruktor parametryczny: " << name << "\n";
#endif
}

Item::~Item()
{
#ifdef DEBUG
    std::cout << "[DEBUG][Item] Destruktor: " << name << "\n";
#endif
}
