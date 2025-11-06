#include "Config.h"
#include "Logger.h"

int main() {
    Logger::info("=== SimpleConfig – ROZBUDOWANY TEST BIBLIOTEKI ===");

    Config cfg;

    // === 1. Dodawanie wielu ustawień ===
    Logger::info("1. Dodawanie ustawień...");
    cfg.add("user", "Anna");
    cfg.add("theme", "light");
    cfg.add("language", "en");
    cfg.add("volume", "75");
    cfg.add("fullscreen", "true");
    cfg.add("auto_save", "yes");
    cfg.add("notifications", "on");
    cfg.add("debug_mode", "false");
    cfg.add("port", "8080");
    cfg.add("timeout", "30");

    // === 2. Próba przekroczenia limitu (MAX_CONFIGS = 10) ===
    Logger::info("2. Próba dodania 11. elementu (powinien się nie udać)...");
    if (!cfg.add("extra", "value")) {
        Logger::error("Nie udało się dodać 'extra' – tablica pełna!");
    }

    // === 3. Wyświetlanie stanu ===
    Logger::info("3. Aktualny stan konfiguracji:");
    cfg.print();

    char countBuf[64];
    snprintf(countBuf, sizeof(countBuf), "Liczba elementów: %d (max: %d)", cfg.count(), MAX_CONFIGS);
    Logger::info(countBuf);

    // === 4. Test isFull() ===
    if (cfg.isFull()) {
        Logger::info("Tablica konfiguracji jest PEŁNA!");
    } else {
        Logger::info("Tablica ma jeszcze miejsce.");
    }

    // === 5. Pobieranie różnych wartości ===
    Logger::info("4. Test pobierania wartości:");
    const char* keys[] = {"user", "theme", "port", "invalid_key", "auto_save"};
    for (int i = 0; i < 5; ++i) {
        const char* val = cfg.get(keys[i]);
        char buf[128];
        if (val) {
            snprintf(buf, sizeof(buf), "get(\"%s\") = \"%s\"", keys[i], val);
            Logger::info(buf);
        } else {
            snprintf(buf, sizeof(buf), "get(\"%s\") = [NIE ZNALEZIONO]", keys[i]);
            Logger::error(buf);
        }
    }

    // === 6. Aktualizacja istniejących kluczy ===
    Logger::info("5. Aktualizacja istniejących ustawień...");
    cfg.add("user", "Krzysztof");
    cfg.add("theme", "dark");
    cfg.add("volume", "50");
    cfg.add("debug_mode", "true");

    Logger::info("Po aktualizacji:");
    cfg.print();

    // === 7. Usuwanie elementów (w tym wielokrotne) ===
    Logger::info("6. Usuwanie elementów...");
    const char* toRemove[] = {"language", "fullscreen", "timeout", "port", "invalid_key"};
    for (int i = 0; i < 5; ++i) {
        bool removed = cfg.remove(toRemove[i]);
        char buf[100];
        if (removed) {
            snprintf(buf, sizeof(buf), "Usunięto: \"%s\"", toRemove[i]);
            Logger::info(buf);
        } else {
            snprintf(buf, sizeof(buf), "Nie znaleziono do usunięcia: \"%s\"", toRemove[i]);
            Logger::info(buf);
        }
    }

    Logger::info("Po usuwaniu:");
    cfg.print();

    // === 8. Ponowne dodawanie (miejsce się zwolniło) ===
    Logger::info("7. Ponowne dodawanie po zwolnieniu miejsca...");
    cfg.add("language", "pl");
    cfg.add("port", "9000");
    cfg.add("theme", "ocean");

    Logger::info("Po ponownym dodaniu:");
    cfg.print();

    // === 9. Czyszczenie całej konfiguracji ===
    Logger::info("8. Czyszczenie całej konfiguracji...");
    cfg.clear();
    Logger::info("Po clear():");
    cfg.print();

    snprintf(countBuf, sizeof(countBuf), "Liczba elementów po clear: %d", cfg.count());
    Logger::info(countBuf);

    // === 10. Finalny test dodawania po clear ===
    Logger::info("9. Finalne dodawanie po wyczyszczeniu...");
    cfg.add("app_name", "MyApp");
    cfg.add("version", "1.0.0");
    cfg.print();

    Logger::info("=== KONIEC ROZBUDOWANEGO TESTU ===");
    return 0;
}
