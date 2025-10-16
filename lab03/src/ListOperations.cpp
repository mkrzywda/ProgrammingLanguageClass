#include "ListOperations.h"
#include "ListElement.h"
#include <iostream>

void show(ListElement_type* head, bool reverse) {
    std::cout << "Moja lista" << (reverse ? " (odwrotna): <" : ": <");
    ListElement_type* current = head;

    if (reverse) {
        while (current && current->next) {
            current = current->next;
        }
        while (current) {
            std::cout << current->data;
            if (current->previous) {
                std::cout << ",";
            }
            current = current->previous;
        }
    } else {
        while (current) {
            std::cout << current->data;
            if (current->next) {
                std::cout << ",";
            }
            current = current->next;
        }
    }
    std::cout << ">" << std::endl;
}

int list_size(ListElement_type* head) {
    int count = 0;
    ListElement_type* current = head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

void push_front(ListElement_type** head, int number) {
    ListElement_type* newEl = new ListElement_type;
    newEl->data = number;
    newEl->previous = nullptr;
    newEl->next = *head;
    if (*head) {
        (*head)->previous = newEl;
    }
    *head = newEl;
}

void push_back(ListElement_type** head, int number) {
    ListElement_type* newEl = new ListElement_type;
    newEl->data = number;
    newEl->next = nullptr;
    newEl->previous = nullptr;

    if (!*head) {
        *head = newEl;
    } else {
        ListElement_type* current = *head;
        while (current->next) {
            current = current->next;
        }
        current->next = newEl;
        newEl->previous = current;
    }
}

void push_by_index(ListElement_type** head, int number, int position) {
    if (position < 0) return;

    if (position == 0) {
        push_front(head, number);
        return;
    }

    ListElement_type* current = *head;
    int index = 0;
    while (current && index < position - 1) {
        current = current->next;
        index++;
    }

    if (!current) return;

    ListElement_type* newEl = new ListElement_type;
    newEl->data = number;
    newEl->next = current->next;
    newEl->previous = current;
    if (current->next) {
        current->next->previous = newEl;
    }
    current->next = newEl;
}

void pop_front(ListElement_type** head) {
    if (*head) {
        ListElement_type* temp = *head;
        *head = (*head)->next;
        if (*head) {
            (*head)->previous = nullptr;
        }
        delete temp;
    }
}

void pop_back(ListElement_type** head) {
    if (!*head) return;

    if (!(*head)->next) {
        delete *head;
        *head = nullptr;
        return;
    }

    ListElement_type* current = *head;
    while (current->next) {
        current = current->next;
    }
    current->previous->next = nullptr;
    delete current;
}

void pop_by_index(ListElement_type** head, int position) {
    if (position < 0 || !*head) return;

    if (position == 0) {
        pop_front(head);
        return;
    }

    ListElement_type* current = *head;
    int index = 0;
    while (current && index < position) {
        current = current->next;
        index++;
    }

    if (!current) return;

    current->previous->next = current->next;
    if (current->next) {
        current->next->previous = current->previous;
    }
    delete current;
}

bool empty(ListElement_type* head) {
    return head == nullptr;
}

int value(ListElement_type* head) {
    if (head) {
        return head->data;
    }
    return 0;
}