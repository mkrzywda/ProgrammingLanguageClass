#ifndef STACK_H
#define STACK_H

#include "StackElement.h"

struct sstack {
    sstackEl* top;
    int count;            
};


void init(sstack* s);

#endif // STACK_H