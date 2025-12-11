#include "Inventory.h"
#include <iostream>

Inventory::Inventory()
{
#ifdef DEBUG
    std::cout << "[DEBUG][Inventory] Konstruktor\n";
#endif
}

Inventory::~Inventory()
{
#ifdef DEBUG
    std::cout << "[DEBUG][Inventory] Destruktor\n";
#endif
}

void Inventory::add(const Item& item)
{
    items.push_back(item);

#ifdef DEBUG
    std::cout << "[DEBUG][Inventory] Dodano: " << item.name << "\n";
#endif
}

void Inventory::show() const
{
    std::cout << "\n--- Ekwipunek ---\n";

    if (items.empty())
        std::cout << "(pusty)\n";

    for (const auto& item : items)
        std::cout << item.name << " (DMG: " 
                  << item.damage << ", Wartość: " 
                  << item.value << ")\n";
}
