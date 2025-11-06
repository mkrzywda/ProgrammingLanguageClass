#pragma once
#include "Czujnik.h"

class Termostat {
public:
    void ustawCzujnik(Czujnik* c);
    void ustawTemperature(int t);
    void wlacz();
    void wylacz();
    bool czyWlaczone() const;
    void aktualizuj(int tempZewn);

private:
    Czujnik* _czujnik;
    int _tempDocelowa;
    bool _stan;
};
