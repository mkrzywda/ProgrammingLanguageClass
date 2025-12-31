#ifndef REWARD_V2_H
#define REWARD_V2_H

#include "RewardType_v2.h"
#include "Item.h"

namespace RPG {
namespace Rewards {

class GoldAmount_v2 {
    int value;
public:
    GoldAmount_v2(int v);
    operator int() const;
};

class ExpAmount_v2 {
    int value;
public:
    explicit ExpAmount_v2(int v);
    operator int() const;
};

class Reward_v2 {
private:
    RewardType_v2 type;

    GoldAmount_v2 gold;
    ExpAmount_v2 exp;
    Item item;
    bool hasItem;

public:
    explicit Reward_v2(GoldAmount_v2 g);                                 // Gold
    explicit Reward_v2(const Item& it);                                  // Item
    explicit Reward_v2(const Item& it, GoldAmount_v2 g);                 // Item + Gold
    explicit Reward_v2(const Item& it, GoldAmount_v2 g, ExpAmount_v2 e); // Item + Gold + Exp
    explicit Reward_v2(ExpAmount_v2 e, const Item& it);                  // Exp + Item
    explicit Reward_v2(ExpAmount_v2 e);                                  // Exp

    RewardType_v2 getType() const;
    bool containsItem() const;

    explicit operator GoldAmount_v2() const;
    explicit operator ExpAmount_v2() const;
    explicit operator Item() const;
};

} // namespace Rewards
} // namespace RPG

#endif

