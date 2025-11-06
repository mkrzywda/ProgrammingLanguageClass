#include "Logger.h"
#include <cstdio>

void Logger::info(const char* msg) {
    std::cout << "[INFO] " << msg << std::endl;
}

void Logger::error(const char* msg) {
    std::cerr << "[ERROR] " << msg << std::endl;
}

#ifdef DEBUG_MODE
void Logger::debug(const char* msg) {
    std::cout << "[DEBUG] " << msg << std::endl;
}
#endif

#ifdef PROFILE_MODE
void Logger::profile(const char* operation, double time_ms) {
    char buf[100];
    snprintf(buf, sizeof(buf), "%s: %.6f ms", operation, time_ms);
    std::cout << "[PROFILE] " << buf << std::endl;
}
#endif
