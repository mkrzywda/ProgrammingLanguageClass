#include "Elf.h"
#include <iostream>
#include <cstdlib>

Elf::Elf()
    : elf("Elf", 70), type(ElfClassType::Warrior), baseDamage(12)
{
#ifdef DEBUG
    std::cout << "[DEBUG][Elf] Domyślny\n";
#endif
}

Elf::Elf(const std::string& name, int hp, ElfClassType t)
    : elf(name, hp), type(t)
{
    switch (type) {
        case ElfClassType::Warrior: baseDamage = 14; break;
        case ElfClassType::Mage:    baseDamage = 10; break;
        case ElfClassType::Archer:  baseDamage = 12; break;
    }

#ifdef DEBUG
    std::cout << "[DEBUG][Elf] Parametryczny\n";
#endif
}

Elf::Elf(const Elf& other)
    : elf(other.elf), type(other.type), baseDamage(other.baseDamage)
{
#ifdef DEBUG
    std::cout << "[DEBUG][Elf] Kopiujący\n";
#endif
}

Elf Elf::createWarrior(const std::string& name)
{
    return Elf(name, 80, ElfClassType::Warrior);
}

Elf Elf::createMage(const std::string& name)
{
    return Elf(name, 55, ElfClassType::Mage);
}

Elf::Elf(ElfClassType t)
    : elf("Losowy Elf", 0), type(t)
{
    int hpMin = 50, hpMax = 90;

    switch (t) {
        case ElfClassType::Warrior:
            hpMin = 70; hpMax = 100; baseDamage = 14; break;
        case ElfClassType::Mage:
            hpMin = 45; hpMax = 65;  baseDamage = 16; break;
        case ElfClassType::Archer:
            hpMin = 55; hpMax = 85;  baseDamage = 12; break;
    }

    int hp = hpMin + std::rand() % (hpMax - hpMin + 1);
    elf = Character("Losowy Elf", hp);

#ifdef DEBUG
    std::cout << "[DEBUG][Elf] Losowy\n";
#endif
}

Elf::~Elf()
{
#ifdef DEBUG
    std::cout << "[DEBUG][Elf] Destruktor\n";
#endif
}

void Elf::showStats() const
{
    elf.showStats();
    std::cout << "Bazowe obrażenia: " << baseDamage << "\n";
}

Inventory& Elf::getInventory()
{
    return elf.getInventory();
}

int Elf::getHp() const
{
    return elf.getHp();
}

void Elf::takeDamage(int dmg)
{
    elf.takeDamage(dmg);
}

bool Elf::isAlive() const
{
    return elf.isAlive();
}

int Elf::getBaseDamage() const
{
    return baseDamage;
}
