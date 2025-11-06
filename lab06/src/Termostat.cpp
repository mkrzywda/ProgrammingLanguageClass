#include "Termostat.h"
#include "Logger.h"

void Termostat::ustawCzujnik(Czujnik* c) { _czujnik = c; }
void Termostat::ustawTemperature(int t) {
    _tempDocelowa = t;
    Logger::info("Termostat: ustawiono " + std::to_string(t) + "°C");
}
void Termostat::wlacz() {
    _stan = true;
#ifdef DEBUG_MODE
    Logger::debug("Termostat włączony");
#endif
}
void Termostat::wylacz() {
    _stan = false;
#ifdef DEBUG_MODE
    Logger::debug("Termostat wyłączony");
#endif
}
bool Termostat::czyWlaczone() const { return _stan; }

void Termostat::aktualizuj(int tempZewn) {
    if (!czyWlaczone()) return;

#ifdef DEBUG_MODE
    Logger::debug("Temp zewn: " + std::to_string(tempZewn));
#endif

    if (tempZewn > _tempDocelowa + 2) {
        Logger::info("Termostat: grzanie włączone");
    } else if (tempZewn < _tempDocelowa - 2) {
        Logger::info("Termostat: chłodzenie włączone");
    } else {
        Logger::info("Termostat: temperatura OK");
    }
}
