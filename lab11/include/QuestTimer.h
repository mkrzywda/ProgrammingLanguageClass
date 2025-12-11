#ifndef QUESTTIMER_H
#define QUESTTIMER_H

class QuestTimer {
private:
    int duration;
    int counter;

public:
    explicit QuestTimer(int sec)
        : duration(sec), counter(0) {}

    void tick() { counter++; }

    explicit operator bool() const {
        return counter < duration;
    }
};

#endif

