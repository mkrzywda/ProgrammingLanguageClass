#include "QuestTimer_v2.h"

namespace RPG {
namespace Quests {

QuestTimer_v2::QuestTimer_v2(int ticks)
    : duration(ticks), counter(0)
{}

void QuestTimer_v2::tick() { counter++; }
void QuestTimer_v2::reset() { counter = 0; }

int QuestTimer_v2::getCounter() const { return counter; }
int QuestTimer_v2::getDuration() const { return duration; }

QuestTimer_v2::operator bool() const {
    return counter < duration;
}

} // namespace Quests
} // namespace RPG

