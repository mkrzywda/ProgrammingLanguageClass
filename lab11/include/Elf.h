#ifndef ELF_H
#define ELF_H

#include "Character.h"
#include "Item.h"
#include <string>

enum class ElfClassType {
    Warrior,
    Mage,
    Archer
};

class Elf {
private:
    Character elf;
    ElfClassType type;
    int baseDamage;

public:
    Elf();                                        // domyślny
    Elf(const std::string& name, int hp, ElfClassType t); // parametryczny
    Elf(const Elf& other);                        // kopiujący
    static Elf createWarrior(const std::string& name);
    static Elf createMage(const std::string& name);
    explicit Elf(ElfClassType t);                 // losowy

    ~Elf();

    void showStats() const;
    Inventory& getInventory();

    int getHp() const;
    void takeDamage(int dmg);
    bool isAlive() const;

    int getBaseDamage() const;
};

#endif
