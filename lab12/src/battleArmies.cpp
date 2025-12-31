#include "SantaArmy.h"
#include "ElfArmy.h"
#include "Colors.h"
#include <iostream>
#include <cstdlib>

void battleArmies(SantaArmy& santaArmy, ElfArmy& elfArmy)
{
    std::cout << BOLD << "\n=== BITWA ARMII: "
              << GREEN << "Mikołaje" << RESET << " vs "
              << CYAN << "Elfy" << RESET
              << " ===\n";

    int round = 1;

    while (santaArmy.hasUnits() && elfArmy.hasUnits())
    {
        std::cout << YELLOW << "\n----- RUNDA " << round << " -----" << RESET << "\n";

        SantaClauss& santa = santaArmy.getUnit(0);
        Elf& elf           = elfArmy.getUnit(0);

        int santaHit = santa.getBaseDamage() + std::rand() % 11;
        int elfHit   = elf.getBaseDamage() + std::rand() % 9;

        std::cout << GREEN << "Mikołaj uderza za " << santaHit << RESET << "\n";
        elf.takeDamage(santaHit);

        if (!elf.isAlive()) {
            std::cout << RED << "Elf poległ!" << RESET << "\n";
            elfArmy.units.erase(elfArmy.units.begin());
            round++;
            continue;
        }

        std::cout << CYAN << "Elf kontratakuje za " << elfHit << RESET << "\n";
        santa.takeDamage(elfHit);

        if (!santa.isAlive()) {
            std::cout << RED << "Mikołaj poległ!" << RESET << "\n";
            santaArmy.units.erase(santaArmy.units.begin());
        }

        round++;
    }

    std::cout << BOLD << "\n=== WYNIK BITWY ===\n" << RESET;

    if (santaArmy.hasUnits())
        std::cout << GREEN << ">>> Mikołaje wygrywają! 🎅" << RESET << "\n";
    else if (elfArmy.hasUnits())
        std::cout << RED << ">>> Elfy zwyciężają! 🧝" << RESET << "\n";
    else
        std::cout << YELLOW << ">>> Remis — nikt nie przetrwał 🤯" << RESET << "\n";
}
