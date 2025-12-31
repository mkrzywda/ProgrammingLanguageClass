#ifndef QUESTTIMER_V2_H
#define QUESTTIMER_V2_H

namespace RPG {
namespace Quests {

class QuestTimer_v2 {
private:
    int duration;
    int counter;

public:
    explicit QuestTimer_v2(int ticks);

    void tick();
    void reset();

    int getCounter() const;
    int getDuration() const;

    explicit operator bool() const;
};

} // namespace Quests
} // namespace RPG

#endif

