#include "SubQuest_v2.h"

namespace RPG {
namespace Quests {

SubQuest_v2::SubQuest_v2(const char* n)
    : name(n), timer(3), completed(false), stepCounter(0)
{}

SubQuest_v2::SubQuest_v2(const std::string& n, int ticks)
    : name(n), timer(ticks), completed(false), stepCounter(0)
{}

const std::string& SubQuest_v2::getName() const { return name; }

bool SubQuest_v2::isCompleted() const { return completed; }

void SubQuest_v2::performStep()
{
    if (completed) return;

    stepCounter++;
    timer.tick();

    if (!static_cast<bool>(timer)) {
        completed = true;
    }
}

int SubQuest_v2::progress() const { return timer.getCounter(); }
int SubQuest_v2::duration() const { return timer.getDuration(); }

} // namespace Quests
} // namespace RPG

