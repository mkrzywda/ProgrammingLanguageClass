#ifndef SUBQUEST_V2_H
#define SUBQUEST_V2_H

#include <string>
#include "QuestTimer_v2.h"

namespace RPG {
namespace Quests {

class SubQuest_v2 {
private:
    std::string name;
    QuestTimer_v2 timer;
    bool completed;

    mutable int stepCounter;

public:
    SubQuest_v2(const char* n);

    explicit SubQuest_v2(const std::string& n, int ticks);

    const std::string& getName() const;

    bool isCompleted() const;

    void performStep();

    int progress() const;
    int duration() const;
};

} // namespace Quests
} // namespace RPG

#endif

