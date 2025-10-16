#include "MyLibrary.h"
#include <iostream>

void PrintName(const char* name) {
    std::cout << "[INFO]:: Name: " << name << std::endl;
}

void PrintInfo(const char* path) {
    std::cout << "[INFO]:: " << path << std::endl;
}
