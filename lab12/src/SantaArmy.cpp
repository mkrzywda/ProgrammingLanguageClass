#include "SantaArmy.h"
#include "Colors.h"
#include <iostream>

SantaArmy::SantaArmy()
    : morale(0)
{
#ifdef DEBUG
    std::cout << YELLOW << "[DEBUG][SantaArmy] Domyślny\n" << RESET;
#endif
}

SantaArmy::SantaArmy(int count)
    : SantaArmy()
{
    summon(count);
}

SantaArmy::SantaArmy(int count, bool elite)
    : SantaArmy()
{
    if (elite) summonElite(count);
    else summon(count);
}

SantaArmy::SantaArmy(const SantaArmy& other)
    : units(other.units), morale(other.morale)
{
#ifdef DEBUG
    std::cout << YELLOW << "[DEBUG][SantaArmy] Kopiujący\n" << RESET;
#endif
}

SantaArmy::~SantaArmy()
{
#ifdef DEBUG
    std::cout << YELLOW << "[DEBUG][SantaArmy] Destruktor\n" << RESET;
#endif
}

void SantaArmy::summon(int count)
{
    for (int i = 0; i < count; ++i)
        units.emplace_back();

    morale = 100;

    std::cout << GREEN << "Przywołano " << count 
              << " zwykłych Mikołajów!" << RESET << "\n";
}

void SantaArmy::summonElite(int count)
{
    for (int i = 0; i < count; ++i)
        units.emplace_back(SantaClauss(3));

    morale = 120;

    std::cout << GREEN << "Przywołano " << count 
              << " elitarnych Mikołajów!" << RESET << "\n";
}

void SantaArmy::show() const
{
    std::cout << GREEN << "\nArmia Mikołajów: " 
              << units.size() 
              << " jednostek, morale: " << morale 
              << RESET << "\n";
}

bool SantaArmy::hasUnits() const
{
    return !units.empty();
}

int SantaArmy::size() const
{
    return units.size();
}

SantaClauss& SantaArmy::getUnit(int index)
{
    return units[index];
}
