#ifndef QUEST_H
#define QUEST_H

#include <string>
#include <iostream>
#include "Colors.h"

class Quest {
private:
    std::string name;
    int duration;
    bool completed;
    mutable int execCount;

public:
    Quest(const char* n) : name(n), duration(5), completed(false), execCount(0) {}

    explicit Quest(const std::string& n, int d = 5)
        : name(n), duration(d), completed(false), execCount(0) {}

    explicit operator std::string() const { return name; }

    void execute() const { execCount++; }

    int getDuration() const { return duration; }
    const std::string& getName() const { return name; }
    void markCompleted() { completed = true; }
    bool isCompleted() const { return completed; }
};

#endif
