#ifndef ELFARMY_H
#define ELFARMY_H

#include "Elf.h"
#include <vector>

class SantaArmy;

class ElfArmy {
private:
    std::vector<Elf> units;
    int morale;

public:
    ElfArmy();
    ElfArmy(int count, ElfClassType type);
    ElfArmy(const std::vector<std::string>& names, ElfClassType type);
    ElfArmy(const ElfArmy& other);

    ~ElfArmy();

    void summonRandom(int count);
    void show() const;

    bool hasUnits() const;
    int size() const;

    Elf& getUnit(int index);

    friend void battleArmies(SantaArmy&, ElfArmy&);
};

#endif
