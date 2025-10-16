#include "StackOperations.h"
#include "StackElement.h"
#include <iostream>

void push(sstack* s, char c) {
    sstackEl* newEl = new sstackEl;
    newEl->data = c;
    newEl->next = s->top;
    s->top = newEl;
    s->count++;
}

void pop(sstack* s) {
    if (s->top) {
        sstackEl* temp = s->top;
        s->top = s->top->next;
        delete temp;
        s->count--;
    }
}

bool empty(sstack* s) {
    return s->top == nullptr;
}

int size(sstack* s) {
    return s->count;
}

char value(sstack* s) {
    if (s->top) {
        return s->top->data;
    }
    return '\0';
}

void prints(sstack* s) {
    std::cout << "Stack element: <";
    sstackEl* current = s->top;
    while (current) {
        std::cout << current->data;
        current = current->next;
    }
    std::cout << ">" << std::endl;
}