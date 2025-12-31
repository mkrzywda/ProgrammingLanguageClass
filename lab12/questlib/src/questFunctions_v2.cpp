#include "questFunctions_v2.h"
#include <iostream>

namespace RPG {
namespace Tasks {

using RPG::Quests::Quest_v2;
using RPG::Rewards::Reward_v2;
using RPG::Rewards::GoldAmount_v2;
using RPG::Rewards::ExpAmount_v2;

static Reward_v2 noRewardYet()
{
    return Reward_v2(ExpAmount_v2(0));
}

Reward_v2 miningGold_v2(Quest_v2& q)
{
    q.performStep();

    std::cout << "[Quest] MiningGold: " << q.getName()
              << " (step=" << q.getExecCounter() << ")\n";

    if (!q.isCompleted())
        return noRewardYet();

    // Nagroda: Gold
    return Reward_v2(GoldAmount_v2(50));
}

Reward_v2 collectSnow_v2(Quest_v2& q)
{
    q.performStep();

    std::cout << "[Quest] CollectSnow: " << q.getName()
              << " (step=" << q.getExecCounter() << ")\n";

    if (!q.isCompleted())
        return noRewardYet();

    // Nagroda: Exp + Item
    Item snow;
    snow.name = "Snow Pouch";
    snow.value = 10;

    return Reward_v2(ExpAmount_v2(15), snow);
}

Reward_v2 huntReindeer_v2(Quest_v2& q)
{
    q.performStep();

    std::cout << "[Quest] HuntReindeer: " << q.getName()
              << " (step=" << q.getExecCounter() << ")\n";

    if (!q.isCompleted())
        return noRewardYet();

    // Nagroda: Item + Gold + Exp
    Item antler;
    antler.name = "Reindeer Antler";
    antler.value = 30;

    return Reward_v2(antler, GoldAmount_v2(25), ExpAmount_v2(20));
}

} // namespace Tasks
} // namespace RPG

