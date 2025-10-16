#ifndef STACK_ELEMENT_H
#define STACK_ELEMENT_H


struct sstackEl {
    char data;            ///< Znak przechowywany w elemencie stosu
    sstackEl* next;       ///< Wskaźnik na kolejny element stosu
};

#endif // STACK_ELEMENT_H