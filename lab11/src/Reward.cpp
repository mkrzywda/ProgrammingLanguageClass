#include "Reward.h"

// GOLD
Reward::Reward(int g)
    : type(RewardType::Gold), gold(g), itemReward(), companionReward()
{}

// ITEM
Reward::Reward(const Item& it)
    : type(RewardType::Item), gold(0), itemReward(it), companionReward()
{}

// COMPANION
Reward::Reward(const SantaClauss& sc)
    : type(RewardType::Companion), gold(0), itemReward(), companionReward(sc)
{}

// KONWERSJE
Reward::operator int() const {
    return gold;
}

Reward::operator Item() const {
    return itemReward;
}

Reward::operator SantaClauss() const {
    return companionReward;
}

RewardType Reward::getType() const {
    return type;
}
