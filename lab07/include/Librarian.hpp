#pragma once
#include <vector>
#include "Book.hpp"

class Librarian {
private:
    std::vector<Book*> books;

public:
    Librarian() = default;
    ~Librarian();

    Book* addBook(const std::string& title,
                  const std::string& author,
                  int year);

    void showAllBooks() const;
    void showAllBooksWithSecretInfo() const;

    void borrowBookByCatalog(int catalogNumber);

    void repairBook(int catalogNumber);

    Book* findBookByCatalog(int catalogNumber) const;
};