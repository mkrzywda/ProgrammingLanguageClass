#include "Librarian.hpp"
#include <iomanip>
#include <iostream>

Librarian::~Librarian() {
    for (Book* b : books) {
        delete b;
    }
#ifdef DEBUG
    std::cout << "[DEBUG] Biblioteka zamknięta – usunięto wszystkie książki.\n";
#endif
}

Book* Librarian::addBook(const std::string& title,
                         const std::string& author,
                         int year)
{
    Book* b = new Book(title, author, year);
    books.push_back(b);
    return b;
}

void Librarian::showAllBooks() const {
    std::cout << "\n=== Książki w bibliotece (widok publiczny) ===\n";
    if (books.empty()) {
        std::cout << "Biblioteka jest pusta.\n";
        return;
    }
    for (const Book* b : books) {
        b->printPublicInfo();
    }
}

void Librarian::showAllBooksWithSecretInfo() const {
    std::cout << "\n=== TAJNE DANE BIBLIOTEKI (tylko dla bibliotekarza!) ===\n";
    if (books.empty()) {
        std::cout << "Brak książek.\n";
        return;
    }
    for (const Book* b : books) {
        std::cout << "Nr kat: " << std::setw(4) << b->catalogNumber
                  << " | " << b->title
                  << " | Zużycie: " << std::fixed << std::setprecision(1)
                  << (b->wearLevel * 100) << "%"
                  << " | Wypożyczono razy: " << b->borrowCount
                  << " | " << (b->isAvailable ? "Dostępna" : "Wypożyczona")
                  << "\n";
    }
}

void Librarian::borrowBookByCatalog(int catalogNumber) {
    Book* book = findBookByCatalog(catalogNumber);
    if (book) {
        book->borrowBook();
    } else {
        std::cout << "Nie znaleziono książki o numerze katalogowym: "
                  << catalogNumber << "\n";
    }
}

void Librarian::repairBook(int catalogNumber) {
    Book* book = findBookByCatalog(catalogNumber);
    if (book) {
        book->wearLevel = std::max(0.0, book->wearLevel - 0.4);
        std::cout << "Naprawiono książkę nr " << catalogNumber
                  << " («" << book->title << "») – nowe zużycie: "
                  << std::fixed << std::setprecision(1)
                  << (book->wearLevel * 100) << "%\n";
    } else {
        std::cout << "Nie znaleziono książki o numerze katalogowym: "
                  << catalogNumber << "\n";
    }
}

Book* Librarian::findBookByCatalog(int catalogNumber) const {
    for (Book* b : books) {
        if (b->catalogNumber == catalogNumber) {
            return b;
        }
    }
    return nullptr;
}