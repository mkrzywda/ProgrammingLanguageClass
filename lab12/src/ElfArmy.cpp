#include "ElfArmy.h"
#include "Colors.h"
#include <iostream>

ElfArmy::ElfArmy()
    : morale(0)
{
#ifdef DEBUG
    std::cout << CYAN << "[DEBUG][ElfArmy] Domyślny\n" << RESET;
#endif
}

ElfArmy::ElfArmy(int count, ElfClassType type)
    : ElfArmy()
{
    for (int i = 0; i < count; ++i)
        units.emplace_back("Elf", 70, type);

    morale = (count > 0 ? 100 : 0);
}

ElfArmy::ElfArmy(const std::vector<std::string>& names, ElfClassType type)
    : ElfArmy()
{
    for (auto& n : names)
        units.emplace_back(n, 70, type);

    morale = (units.empty() ? 0 : 100);
}

ElfArmy::ElfArmy(const ElfArmy& other)
    : units(other.units), morale(other.morale)
{
#ifdef DEBUG
    std::cout << CYAN << "[DEBUG][ElfArmy] Kopiujący\n" << RESET;
#endif
}

ElfArmy::~ElfArmy()
{
#ifdef DEBUG
    std::cout << CYAN << "[DEBUG][ElfArmy] Destruktor\n" << RESET;
#endif
}

void ElfArmy::summonRandom(int count)
{
    for (int i = 0; i < count; ++i)
        units.emplace_back(ElfClassType::Archer); // losowy łucznik

    morale = 100;

    std::cout << CYAN << "Przywołano " << count 
              << " losowych Elfów!" << RESET << "\n";
}

void ElfArmy::show() const
{
    std::cout << CYAN << "\nArmia Elfów: " 
              << units.size() 
              << " jednostek, morale: " << morale 
              << RESET << "\n";
}

bool ElfArmy::hasUnits() const
{
    return !units.empty();
}

int ElfArmy::size() const
{
    return units.size();
}

Elf& ElfArmy::getUnit(int index)
{
    return units[index];
}
