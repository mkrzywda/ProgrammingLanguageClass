#ifndef QUEST_V2_H
#define QUEST_V2_H

#include <string>
#include <vector>
#include "SubQuest_v2.h"

namespace RPG {
namespace Quests {

class Quest_v2 {
private:
    std::string name;
    bool completed;

    std::vector<SubQuest_v2> subquests;
    int currentIndex;

    mutable int execCounter;

public:
    Quest_v2(const char* n);

    explicit Quest_v2(const std::string& n);

    const std::string& getName() const;

    
    void addSubQuest(const SubQuest_v2& sq);

    bool hasSubQuests() const;
    int subQuestCount() const;
    int currentSubQuestIndex() const;

    bool isCompleted() const;

    void performStep();

    explicit operator std::string() const;

    // Statystyka (mutable)
    int getExecCounter() const;
};

} // namespace Quests
} // namespace RPG

#endif

