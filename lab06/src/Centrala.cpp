#include "Centrala.h"
#include "Logger.h"

void Centrala::dodajLampa(Lampa* l) {
    if (_ileLamp < MAX) {
        _lampy[_ileLamp++] = l;
        Logger::info("Dodano lampę");
    }
}

void Centrala::dodajTermostat(Termostat* t) {
    if (_ileTerm < MAX) {
        _termostaty[_ileTerm++] = t;
        Logger::info("Dodano termostat");
    }
}

void Centrala::aktualizujWszystkie() {
    Logger::info("--- Aktualizacja systemu ---");
    for (int i = 0; i < _ileLamp; ++i) {
        _lampy[i]->aktualizuj();
    }
    for (int i = 0; i < _ileTerm; ++i) {
        _termostaty[i]->aktualizuj(25);
    }
}
