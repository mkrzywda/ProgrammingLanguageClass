#ifndef QUESTFUNCTIONS_V2_H
#define QUESTFUNCTIONS_V2_H

#include "Quest_v2.h"
#include "Reward_v2.h"

namespace RPG {
namespace Tasks {

// Funkcje wykonują "krok" questa.
// Nagroda jest zwracana dopiero gdy quest jest ukończony.
// Jeśli jeszcze nie ukończony -> zwracamy Exp(0) jako "pustą nagrodę".

RPG::Rewards::Reward_v2 miningGold_v2(RPG::Quests::Quest_v2& q);
RPG::Rewards::Reward_v2 collectSnow_v2(RPG::Quests::Quest_v2& q);
RPG::Rewards::Reward_v2 huntReindeer_v2(RPG::Quests::Quest_v2& q);

} // namespace Tasks
} // namespace RPG

#endif

