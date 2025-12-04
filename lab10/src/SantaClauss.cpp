#include "SantaClauss.h"
#include <iostream>
#include <cstdlib>

SantaClauss::SantaClauss()
    : SantaClauss("Święty Mikołaj", 120, 15)
{
#ifdef DEBUG
    std::cout << "[DEBUG][SantaClauss] Domyślny\n";
#endif
}

SantaClauss::SantaClauss(const std::string& name, int hp, int dmg)
    : santa(name, hp), baseDamage(dmg)
{
#ifdef DEBUG
    std::cout << "[DEBUG][SantaClauss] Parametryczny\n";
#endif
}

SantaClauss::SantaClauss(const SantaClauss& other)
    : santa(other.santa), baseDamage(other.baseDamage)
{
#ifdef DEBUG
    std::cout << "[DEBUG][SantaClauss] Kopiujący\n";
#endif
}

SantaClauss::SantaClauss(int difficultyLevel)
    : SantaClauss(
        "Mikołaj (Poziom " + std::to_string(difficultyLevel) + ")",
        100 + difficultyLevel * 20,
        10 + difficultyLevel * 5
      )
{
#ifdef DEBUG
    std::cout << "[DEBUG][SantaClauss] Delegujący (difficulty)\n";
#endif
}

SantaClauss::SantaClauss(bool withEquipment, int hp)
    : SantaClauss("Uzbrojony Mikołaj", hp, 20)
{
#ifdef DEBUG
    std::cout << "[DEBUG][SantaClauss] Wyposażający\n";
#endif
    if (withEquipment) {
        santa.getInventory().add(Item("Cukrowa Laska", 15, 20));
        santa.getInventory().add(Item("Czapka Mikołaja", 5, 10));
    }
}

SantaClauss::~SantaClauss()
{
#ifdef DEBUG
    std::cout << "[DEBUG][SantaClauss] Destruktor\n";
#endif
}

void SantaClauss::showStats() const
{
    santa.showStats();
    std::cout << "Bazowe obrażenia: " << baseDamage << "\n";
}

Inventory& SantaClauss::getInventory()
{
    return santa.getInventory();
}

int SantaClauss::getHp() const
{
    return santa.getHp();
}

void SantaClauss::takeDamage(int dmg)
{
    santa.takeDamage(dmg);
}

bool SantaClauss::isAlive() const
{
    return santa.isAlive();
}

int SantaClauss::getBaseDamage() const
{
    return baseDamage;
}
