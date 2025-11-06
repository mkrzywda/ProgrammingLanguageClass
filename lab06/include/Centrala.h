#pragma once
#include "Lampa.h"
#include "Termostat.h"
#include <array>

class Centrala {
public:
    static const int MAX = 5;
    void dodajLampa(Lampa* l);
    void dodajTermostat(Termostat* t);
    void aktualizujWszystkie();
    inline int ileLamp() const { return _ileLamp; }
    inline int ileTermostatow() const { return _ileTerm; }

private:
    std::array<Lampa*, MAX> _lampy;
    std::array<Termostat*, MAX> _termostaty;
    int _ileLamp = 0;
    int _ileTerm = 0;
};
