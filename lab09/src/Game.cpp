#include "Game.h"
#include "Item.h"
#include <iostream>


#include <ctime>

Game::Game()
{
#ifdef DEBUG
    std::cout << "[DEBUG][Game] Konstruktor\n";
#endif
}

Game::~Game()
{
#ifdef DEBUG
    std::cout << "[DEBUG][Game] Destruktor\n";
#endif
}

void Game::run()
{
    std::cout << "=== Start gry ===\n";

    //episode1();
    episode3();

    std::cout << "=== Koniec gry ===\n";
}

void Game::episode1()
{
    std::cout << "\n=== EPIZOD 1 ===\n";
    std::cout << "Tworzenie postaci i miecza.\n";

    player.showStats();

    Item sword("Miecz Rycerski", 15, 50);
    player.getInventory().add(sword);
    player.getInventory().show();
}

void Game::episode2()
{
    std::cout << "\n=== EPIZOD 2 ===\n";
    std::cout << "Tu będzie kolejne zadanie.\n";
    std::cout << "Szczególy: 04.12.2025.\n";

}

void Game::episode3()
{
    std::cout << "\n=== EPIZOD 3 ===\n";
    std::cout << "Tu będzie kolejne zadanie.\n";
    std::cout << "Szczególy: 11.12.2025.\n";

}


void Game::episode4()
{
    std::cout << "\n=== EPIZOD 4 ===\n";
    std::cout << "Tu będzie kolejne zadanie.\n";
    std::cout << "Szczególy: 18.12.2025.\n";

}

void Game::episode5()
{
    std::cout << "\n=== EPIZOD 5 ===\n";
    std::cout << "Tu będzie kolejne zadanie.\n";
    std::cout << "Szczególy: 15.01.2025.\n";

}
