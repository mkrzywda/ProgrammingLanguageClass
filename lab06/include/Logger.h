#pragma once
#include <string>
#include <iostream>

class Logger {
public:
    static void debug(const std::string& msg);
    static void info(const std::string& msg);
    static void alarm(const std::string& msg);
};
