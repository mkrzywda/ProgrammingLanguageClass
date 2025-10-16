#ifndef STACK_OPERATIONS_H
#define STACK_OPERATIONS_H

#include "Stack.h"

/**
 * @brief Dodaje znak na wierzch stosu.
 * @param s Wskaźnik na strukturę stosu.
 * @param c Znak do dodania.
 */
void push(sstack* s, char c);

void pop(sstack* s);

bool empty(sstack* s);

int size(sstack* s);

char value(sstack* s);

void prints(sstack* s);

#endif // STACK_OPERATIONS_H