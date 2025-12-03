#ifndef SANTAARMY_H
#define SANTAARMY_H

#include "SantaClauss.h"
#include <vector>

class ElfArmy; // forward

class SantaArmy {
private:
    std::vector<SantaClauss> units;
    int morale;

public:
    SantaArmy();                 
    explicit SantaArmy(int count);
    SantaArmy(int count, bool elite);
    SantaArmy(const SantaArmy& other);

    ~SantaArmy();

    void summon(int count);
    void summonElite(int count);
    void show() const;

    bool hasUnits() const;
    int size() const;

    SantaClauss& getUnit(int index);

    friend class ElfArmy;
    friend void battleArmies(SantaArmy&, ElfArmy&);
};

#endif
