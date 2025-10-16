#ifndef LIST_ELEMENT_H
#define LIST_ELEMENT_H

/**
 * @brief Struktura reprezentująca pojedynczy element listy dwukierunkowej.
 *
 * Przechowuje liczbę całkowitą oraz wskaźniki na poprzedni i następny element.
 */
typedef struct ListElement {
    int data;                     ///< Liczba całkowita przechowywana w elemencie.
    struct ListElement* previous;  ///< Wskaźnik na poprzedni element listy.
    struct ListElement* next;      ///< Wskaźnik na kolejny element listy.
} ListElement_type;

#endif // LIST_ELEMENT_H