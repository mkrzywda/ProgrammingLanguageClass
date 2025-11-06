#include "Config.h"
#include "Logger.h"
#include <cstring>

#ifdef PROFILE_MODE
#include <chrono>
using namespace std::chrono;
#endif

Config::Config() : size(0) {
    clear();
#ifdef DEBUG_MODE
    Logger::debug("Config::Config() - utworzono");
#endif
}

bool Config::add(const char* key, const char* value) {
#ifdef PROFILE_MODE
    auto start = high_resolution_clock::now();
#endif

    if (isFull()) {
        Logger::error("Config::add - brak miejsca!");
        return false;
    }

    // Sprawdź, czy klucz już istnieje
    for (int i = 0; i < size; ++i) {
        if (std::strcmp(keys[i], key) == 0) {
            // Aktualizuj wartość
            std::strncpy(values[i], value, VALUE_LEN - 1);
            values[i][VALUE_LEN - 1] = '\0';
#ifdef DEBUG_MODE
            char buf[100];
            snprintf(buf, sizeof(buf), "add: aktualizacja [%s] = [%s]", key, value);
            Logger::debug(buf);
#endif
            return true;
        }
    }

    // Nowy klucz
    std::strncpy(keys[size], key, KEY_LEN - 1);
    keys[size][KEY_LEN - 1] = '\0';
    std::strncpy(values[size], value, VALUE_LEN - 1);
    values[size][VALUE_LEN - 1] = '\0';
    size++;

#ifdef DEBUG_MODE
    char buf[100];
    snprintf(buf, sizeof(buf), "add: nowy wpis [%s] = [%s]", key, value);
    Logger::debug(buf);
#endif

#ifdef PROFILE_MODE
    auto end = high_resolution_clock::now();
    double ms = duration_cast<nanoseconds>(end - start).count() / 1e6;
    Logger::profile("add", ms);
#endif

    return true;
}

const char* Config::get(const char* key) const {
    for (int i = 0; i < size; ++i) {
        if (std::strcmp(keys[i], key) == 0) {
            return values[i];
        }
    }
    return nullptr;
}

bool Config::remove(const char* key) {
    for (int i = 0; i < size; ++i) {
        if (std::strcmp(keys[i], key) == 0) {
            // Przesuń resztę elementów
            for (int j = i; j < size - 1; ++j) {
                std::strcpy(keys[j], keys[j + 1]);
                std::strcpy(values[j], values[j + 1]);
            }
            keys[size - 1][0] = '\0';
            values[size - 1][0] = '\0';
            size--;
#ifdef DEBUG_MODE
            char buf[64];
            snprintf(buf, sizeof(buf), "remove: usunięto [%s]", key);
            Logger::debug(buf);
#endif
            return true;
        }
    }
    return false;
}

void Config::clear() {
    for (int i = 0; i < MAX_CONFIGS; ++i) {
        keys[i][0] = '\0';
        values[i][0] = '\0';
    }
    size = 0;
#ifdef DEBUG_MODE
    Logger::debug("Config::clear() - wyczyszczono");
#endif
}

int Config::count() const {
    return size;
}

void Config::print() const {
    std::cout << "Config (" << size << " ustawień):\n";
    for (int i = 0; i < size; ++i) {
        std::cout << "  [" << keys[i] << "] = [" << values[i] << "]\n";
    }
}
