#include <iostream>
#include "List.h"
#include "ListOperations.h"
using namespace std;

int main(int argc, char** argv) 
{
    ListElement_type* List = nullptr;
	
    init(&List);
	
    // Wywołanie empty na pustej liście
    cout << "Czy lista pusta (przed push): " << (empty(List) ? "tak" : "nie") << endl;

    // Dodajemy kody ASCII napisu "Jezyk C++" w odwrotnej kolejności (push_back)
    push_back(&List, 43);  // '+'
    push_back(&List, 43);  // '+'
    push_back(&List, 67);  // 'C'
    push_back(&List, 32);  // ' '
    push_back(&List, 107); // 'k'
    push_back(&List, 121); // 'y'
    push_back(&List, 122); // 'z'
    push_back(&List, 101); // 'e'
    push_back(&List, 74);  // 'J'

    // Wywołanie list_size
    cout << "Rozmiar listy: " << list_size(List) << endl;

    // Wywołanie value
    cout << "Wartość na początku: " << value(List) << endl;

    // Wywołanie show (od początku do końca)
    show(List);

    show(List, true);

    // Wywołanie pop_front
    pop_front(&List);
    cout << "Po pop_front, rozmiar: " << list_size(List) << endl;
    show(List);
    show(List, true);

    // Wywołanie push_front
    push_front(&List, 43); // '+'
    cout << "Po push_front(43), rozmiar: " << list_size(List) << endl;
    show(List);

    // Wywołanie push_by_index
    push_by_index(&List, 100, 2); // Dodajemy 100 na pozycji 2
    cout << "Po push_by_index(100, 2), rozmiar: " << list_size(List) << endl;
    show(List);

    // Wywołanie pop_back
    pop_back(&List);
    cout << "Po pop_back, rozmiar: " << list_size(List) << endl;
    show(List);

    // Wywołanie pop_by_index
    pop_by_index(&List, 2);
    cout << "Po pop_by_index(2), rozmiar: " << list_size(List) << endl;
    show(List);

    // Wywołanie empty na niepustej liście
    cout << "Czy lista pusta (po operacjach): " << (empty(List) ? "tak" : "nie") << endl;	

    ListElement_type* current = List;
    ListElement_type* next;
    while (current != nullptr) {
        next = current->next; // Save next pointer
        delete current;       // Use delete, not free
        current = next;       // Move to next
    }
    List = nullptr; // Avoid dangling pointer


    return 0;
}
