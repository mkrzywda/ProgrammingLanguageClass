#include "System.h"
#include "Czujnik.h"
#include "Lampa.h"
#include "Termostat.h"
#include "Licznik.h"
#include <unistd.h>

void System::uruchom() {
    globalneUruchomienia++;
    Logger::info("=== URUCHOMIENIE " + std::to_string(globalneUruchomienia) + " ===");

    Czujnik c1, c2, c3;
    c1.ustawID("Światło"); c1.ustawWartosc(95);
    c2.ustawID("Salon");   c2.ustawWartosc(18);
    c3.ustawID("Kuchnia"); c3.ustawWartosc(28);

    _czujniki[0] = &c1;
    _czujniki[1] = &c2;
    _czujniki[2] = &c3;

    Lampa l1;
    l1.ustawCzujnik(&c1);
    l1.ustawJasność(80);
    l1.wlacz();

    Termostat t1, t2;
    t1.ustawCzujnik(&c2);
    t1.ustawTemperature(21);
    t1.wlacz();

    t2.ustawCzujnik(&c3);
    t2.ustawTemperature(20);
    t2.wlacz();

    _centrala.dodajLampa(&l1);
    _centrala.dodajTermostat(&t1);
    _centrala.dodajTermostat(&t2);

    _centrala.aktualizujWszystkie();
}

void System::symulujZmianeStanu() {
    Logger::info("=== SYMULACJA: zmiana po 3s ===");
    sleep(3);

    if (_czujniki[0]) _czujniki[0]->ustawWartosc(70);
    if (_czujniki[1]) _czujniki[1]->ustawWartosc(22);
    if (_czujniki[2]) _czujniki[2]->ustawWartosc(19);

    _centrala.aktualizujWszystkie();
}

void System::podsumowanie() {
    Logger::info("=== PODSUMOWANIE ===");
    Logger::info("Lamp: " + std::to_string(_centrala.ileLamp()));
    Logger::info("Termostatów: " + std::to_string(_centrala.ileTermostatow()));
    Logger::info("Uruchomienia: " + std::to_string(globalneUruchomienia));
}
