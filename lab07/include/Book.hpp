#pragma once
#include <string>
#include <iostream>

class Librarian;

class Book {
private:
    std::string title;
    std::string author;
    int year;

    const int catalogNumber;
    double wearLevel;
    bool isAvailable;
    int borrowCount; 

    static int nextCatalogNumber;

public:
    Book(const std::string& title, const std::string& author, int year);
    ~Book();

    void printPublicInfo() const;

    bool borrowBook();
    void returnBook();

    friend class Librarian;
};