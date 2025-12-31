#include "Reward_v2.h"

namespace RPG {
namespace Rewards {

GoldAmount_v2::GoldAmount_v2(int v) : value(v) {}
GoldAmount_v2::operator int() const { return value; }

ExpAmount_v2::ExpAmount_v2(int v) : value(v) {}
ExpAmount_v2::operator int() const { return value; }

Reward_v2::Reward_v2(GoldAmount_v2 g)
    : type(RewardType_v2::Gold), gold(g), exp(ExpAmount_v2(0)), item(), hasItem(false)
{}

Reward_v2::Reward_v2(const Item& it)
    : type(RewardType_v2::Item), gold(0), exp(ExpAmount_v2(0)), item(it), hasItem(true)
{}

Reward_v2::Reward_v2(const Item& it, GoldAmount_v2 g)
    : type(RewardType_v2::ItemGold), gold(g), exp(ExpAmount_v2(0)), item(it), hasItem(true)
{}

Reward_v2::Reward_v2(const Item& it, GoldAmount_v2 g, ExpAmount_v2 e)
    : type(RewardType_v2::ItemGoldExp), gold(g), exp(e), item(it), hasItem(true)
{}

Reward_v2::Reward_v2(ExpAmount_v2 e, const Item& it)
    : type(RewardType_v2::ExpItem), gold(0), exp(e), item(it), hasItem(true)
{}

Reward_v2::Reward_v2(ExpAmount_v2 e)
    : type(RewardType_v2::Exp), gold(0), exp(e), item(), hasItem(false)
{}

RewardType_v2 Reward_v2::getType() const { return type; }
bool Reward_v2::containsItem() const { return hasItem; }

Reward_v2::operator GoldAmount_v2() const { return gold; }
Reward_v2::operator ExpAmount_v2() const { return exp; }
Reward_v2::operator Item() const { return item; }

} // namespace Rewards
} // namespace RPG

