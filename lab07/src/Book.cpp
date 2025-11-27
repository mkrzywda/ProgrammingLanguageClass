#include "Book.hpp"

int Book::nextCatalogNumber = 1000;

Book::Book(const std::string& t, const std::string& a, int y)
    : title(t), author(a), year(y),
      catalogNumber(++nextCatalogNumber),
      wearLevel(0.0), isAvailable(true), borrowCount(0)
{
    #ifdef DEBUG
    std::cout << "[DEBUG] Dodano książkę: " << title
              << " | Nr katalogowy: " << catalogNumber << "\n";
    #endif
}

Book::~Book() {
    #ifdef DEBUG
    std::cout << "[DEBUG] Usunięto książkę: " << title << "\n";
    #endif
}

void Book::printPublicInfo() const {
    std::cout << title << " - " << author << " (" << year << ")"
              << " | " << (isAvailable ? "Dostępna" : "Wypożyczona")
              << " | Wypożyczono razy: " << borrowCount << "\n";
}

bool Book::borrowBook() {
    if (!isAvailable) {
        std::cout << "Książka \"" << title << "\" jest już wypożyczona!\n";
        return false;
    }

    isAvailable = false;
    borrowCount++;
    wearLevel += 0.05;

    std::cout << "Bibliotekarz wypożyczył: \"" << title << "\"\n";
    std::cout << "   → To już " << borrowCount << ". raz ta książka została wypożyczona!\n";

    return true;
}

void Book::returnBook() {
    isAvailable = true;
    std::cout << "Zwrócono książkę: \"" << title << "\"\n";
}