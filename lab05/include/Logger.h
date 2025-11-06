#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>

class Logger {
public:
    static void info(const char* msg);
    static void error(const char* msg);

#ifdef DEBUG_MODE
    static void debug(const char* msg);
#endif

#ifdef PROFILE_MODE
    static void profile(const char* operation, double time_ms);
#endif
};

#endif
