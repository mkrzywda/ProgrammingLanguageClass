#include "Game.h"

int main()
{
    Game game;
    game.run();

    return 0;
}


// [DEBUG][Inventory] Konstruktor
// [DEBUG][Character] Konstruktor domyślny: Rycerz
// [DEBUG][Game] Konstruktor
// === Start gry ===

// === EPIZOD 1 ===
// Zadanie: Stworzyć postać, miecz i dodać go do ekwipunku.
// [DEBUG][Game] Wyświetlam statystyki gracza...

// === Postać ===
// Imię: Rycerz
// HP: 100
// [DEBUG][Game] Tworzę miecz...
// [DEBUG][Item] Konstruktor parametryczny: Miecz Rycerski
// [DEBUG][Game] Dodaję miecz do ekwipunku...
// [DEBUG][Inventory] Dodano: Miecz Rycerski

// --- Ekwipunek ---
// Miecz Rycerski (DMG: 15, Wartość: 50)
// [DEBUG][Item] Destruktor: Miecz Rycerski

// === EPIZOD 2 ===
// Tu będzie kolejne zadanie.
// Szczególy: 04.12.2025.

// === EPIZOD 3 ===
// Tu będzie kolejne zadanie.
// Szczególy: 11.12.2025.

// === EPIZOD 4 ===
// Tu będzie kolejne zadanie.
// Szczególy: 18.12.2025.

// === EPIZOD 5 ===
// Tu będzie kolejne zadanie.
// Szczególy: 15.01.2025.
// === Koniec gry ===
// [DEBUG][Game] Destruktor
// [DEBUG][Character] Destruktor: Rycerz
// [DEBUG][Inventory] Destruktor
// [DEBUG][Item] Destruktor: Miecz Rycerski