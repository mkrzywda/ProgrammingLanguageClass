#ifndef GAME_H
#define GAME_H

#include "Character.h"
class Game {
private:
    Character player;

public:
    Game();
    ~Game();

    void run();

    void episode1();
    void episode2();
    void episode3();
    void episode4();
    void episode5();
};

#endif
