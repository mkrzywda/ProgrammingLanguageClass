#include "Librarian.hpp"
#include <iostream>

int main() {
    std::cout << "=== SYSTEM BIBLIOTECZNY – DEMO Z FRIEND ===\n\n";

    Librarian bib;

    // Dodajemy książki do systemu
    bib.addBook("1984", "George Orwell", 1949);
    bib.addBook("Zabić drozda", "Harper Lee", 1960);
    bib.addBook("Władca Pierścieni", "J.R.R. Tolkien", 1954);
    bib.addBook("Mały Książę", "Antoine de Saint-Exupéry", 1943);
    bib.addBook("Dune", "Frank Herbert", 1965);

    bib.showAllBooks();

    std::cout << "\n=== Faza 1: Masowe wypożyczenia (czytelnicy szaleją) ===\n";
    bib.borrowBookByCatalog(1001);  // 1984
    bib.borrowBookByCatalog(1004);  // Mały Książę
    bib.borrowBookByCatalog(1001);  // 1984 – już wypożyczona → nie da rady
    bib.borrowBookByCatalog(1003);  // Władca Pierścieni
    bib.borrowBookByCatalog(1004);  // Mały Książę – drugi raz
    bib.borrowBookByCatalog(1005);  // Dune
    bib.borrowBookByCatalog(1004);  // Mały Książę – trzeci raz!

    bib.showAllBooks();
    bib.showAllBooksWithSecretInfo();

    std::cout << "\n=== Faza 2: Zwroty książek ===\n";
    Book* returned;
    returned = bib.findBookByCatalog(1001);
    if (returned) returned->returnBook();

    returned = bib.findBookByCatalog(1004);
    if (returned) returned->returnBook();

    returned = bib.findBookByCatalog(1005);
    if (returned) returned->returnBook();

    bib.showAllBooks();

    std::cout << "\n=== Faza 3: Bibliotekarz sprawdza zużycie i naprawia książki ===\n";
    bib.showAllBooksWithSecretInfo();

    std::cout << "\n→ Naprawiamy mocno zużyty egzemplarz \"Małego Księcia\"\n";
    bib.repairBook(1004);

    std::cout << "\n→ Naprawiamy też \"1984\" (była wypożyczana 2 razy)\n";
    bib.repairBook(1001);

    bib.showAllBooksWithSecretInfo();

    std::cout << "\n=== Faza 4: Jeszcze jedno wypożyczenie po naprawie ===\n";
    bib.borrowBookByCatalog(1004); 
    bib.borrowBookByCatalog(1001);

    std::cout << "\n=== Końcowy stan biblioteki ===\n";
    bib.showAllBooks();
    bib.showAllBooksWithSecretInfo();

    std::cout << "\nKoniec dnia pracy. Bibliotekarz zamyka bibliotekę.\n";
    std::cout << "Wszystkie książki zostaną automatycznie usunięte przez destruktory.\n";

    return 0;
}