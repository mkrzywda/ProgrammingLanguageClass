#ifndef REWARD_H
#define REWARD_H

#include "RewardType.h"
#include "Item.h"
#include "SantaClauss.h"

class Reward {
private:
    RewardType type;
    int gold;
    Item itemReward;
    SantaClauss companionReward;

public:
    // GOLD REWARD
    explicit Reward(int g);

    // ITEM REWARD
    explicit Reward(const Item& it);

    // COMPANION REWARD
    explicit Reward(const SantaClauss& sc);

    // KONWERSJE
    explicit operator int() const;
    explicit operator Item() const;
    explicit operator SantaClauss() const;

    RewardType getType() const;
};

#endif
