#include "Logger.h"

void Logger::debug(const std::string& msg) {
#ifdef DEBUG_MODE
    std::cout << "[DEBUG] " << msg << std::endl;
#endif
}

void Logger::info(const std::string& msg) {
    std::cout << "[INFO] " << msg << std::endl;
}

void Logger::alarm(const std::string& msg) {
    std::cout << "[ALARM] " << msg << " !!!" << std::endl;
}
