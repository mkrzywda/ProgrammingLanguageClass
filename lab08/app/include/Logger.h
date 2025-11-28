#pragma once
#include <string>
#include <iostream>

class Logger {
private:
    static Logger* instance;
    Logger() = default;

public:
    static Logger& get() {
        if (!instance) instance = new Logger();
        return *instance;
    }

    void info(const std::string& msg) const {
        std::cout << "[INFO] " << msg << "\n";
    }
};
