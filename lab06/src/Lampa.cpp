#include "Lampa.h"
#include "Logger.h"

void Lampa::ustawCzujnik(Czujnik* c) { _czujnik = c; }
void Lampa::ustawJasność(int j) {
#ifdef DEBUG_MODE
    Logger::debug("Lampa: jasność = " + std::to_string(j) + "%");
#endif
}
void Lampa::wlacz() {
    _stan = true;
#ifdef DEBUG_MODE
    Logger::debug("Lampa włączona");
#endif
}
void Lampa::wylacz() {
    _stan = false;
#ifdef DEBUG_MODE
    Logger::debug("Lampa wyłączona");
#endif
}
bool Lampa::czyWlaczone() const { return _stan; }

void Lampa::aktualizuj() {
    if (!czyWlaczone()) return;
    if (_czujnik && _czujnik->czyAlarm()) {
        wylacz();
        Logger::alarm("Lampa wyłączona – za jasno!");
    }
}
