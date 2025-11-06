#pragma once
#include "Czujnik.h"

class Lampa {
public:
    void ustawCzujnik(Czujnik* c);
    void ustawJasność(int j);
    void wlacz();
    void wylacz();
    bool czyWlaczone() const;
    void aktualizuj();

private:
    Czujnik* _czujnik;
    int _jasnosc;
    bool _stan;
};
