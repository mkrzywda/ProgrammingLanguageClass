#include "Game.h"
#include "Item.h"
#include <iostream>

#include <ctime>
#include "SantaArmy.h"
#include "ElfArmy.h"
#include <Colors.h>

#include "Quest.h"
#include "QuestTimer.h"
#include "Reward.h"
#include "questFunctions.h"

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
    std::cout << BOLD << BLUE
    << "\n==============================================\n"
    << "            EPIZOD 3 — KONSTRUKTORY RPG        \n"
    << "==============================================\n"
    << RESET;

std::cout << MAGENTA
    << "W krainie Zimowych Cudów rozpoczyna się wojna...\n"
    << RESET;


    std::srand(static_cast<unsigned>(std::time(nullptr)));

    std::cout << "\n=====================================================\n";
    std::cout << "                EPIZOD 3 – KONSTRUKTORY RPG           \n";
    std::cout << "=====================================================\n";

    //
    // ============================================================
    //  1. TWORZENIE MIKOŁAJA WSZYSTKIMI KONSTRUKTORAMI
    // ============================================================
    //
    std::cout << "\n=== 1. Tworzenie Mikołaja różnymi konstruktorami ===\n";

    SantaClauss m1;                                     // domyślny
    SantaClauss m2("Mikołaj Wojownik", 150, 25);        // parametryczny
    SantaClauss m3(m2);                                  // kopiujący
    SantaClauss m4(2);                                   // delegujący (difficulty level)
    SantaClauss m5(true, 130);                           // wyposażający

    std::cout << "\n[DOMYŚLNY] ";        m1.showStats();
    std::cout << "\n[PARAMETRYCZNY] ";   m2.showStats();
    std::cout << "\n[KOPIUJĄCY] ";       m3.showStats();
    std::cout << "\n[DELEGUJĄCY] ";      m4.showStats();
    std::cout << "\n[WYPOSAŻAJĄCY] ";    m5.showStats();



    //
    // ============================================================
    //  2. TWORZENIE ELFA WSZYSTKIMI KONSTRUKTORAMI
    // ============================================================
    //
    std::cout << "\n=== 2. Tworzenie Elfów różnymi konstruktorami ===\n";

    Elf e1;                                                // domyślny
    Elf e2("Elf Strażnik", 75, ElfClassType::Warrior);     // parametryczny
    Elf e3(e2);                                            // kopiujący
    Elf e4 = Elf::createWarrior("Elf Berserker");          // fabryka wojownik
    Elf e5 = Elf::createMage("Elf Czarodziej");            // fabryka mag
    Elf e6(ElfClassType::Archer);                          // losowy łucznik

    std::cout << "\n[DOMYŚLNY] ";          e1.showStats();
    std::cout << "\n[PARAMETRYCZNY] ";     e2.showStats();
    std::cout << "\n[KOPIUJĄCY] ";         e3.showStats();
    std::cout << "\n[WARRIOR FACTORY] ";   e4.showStats();
    std::cout << "\n[MAGE FACTORY] ";      e5.showStats();
    std::cout << "\n[LOSOWY ŁUCZNIK] ";    e6.showStats();



    //
    // ============================================================
    //  3. TWORZENIE ARMII ELFÓW
    // ============================================================
    //
    std::cout << "\n=== 3. Tworzenie armii Elfów różnymi konstruktorami ===\n";

    ElfArmy ea1;                                            // pusty
    ElfArmy ea2(3, ElfClassType::Mage);                     // 3 magów
    ElfArmy ea3({"Elfik", "Zefir", "Grom"}, ElfClassType::Warrior); // imienna
    ElfArmy ea4(ea2);                                       // kopiujący
    ElfArmy ea5; ea5.summonRandom(4);                       // losowa

    std::cout << "\n[PUSTA ARMIA]"; ea1.show();
    std::cout << "\n[ARMIA MAGÓW]"; ea2.show();
    std::cout << "\n[IMIENNA ARMIA]"; ea3.show();
    std::cout << "\n[KOPIA ARMII MAGÓW]"; ea4.show();
    std::cout << "\n[ARMIA LOSOWA]"; ea5.show();



    //
    // ============================================================
    //  4. TWORZENIE ARMII MIKOŁAJÓW
    // ============================================================
    //
    std::cout << "\n=== 4. Tworzenie armii Mikołajów różnymi konstruktorami ===\n";

    SantaArmy sa1;                   // pusta
    SantaArmy sa2(3);                // zwykła armia 3
    SantaArmy sa3(2, true);          // elitarna armia
    SantaArmy sa4(sa3);              // kopiująca
    SantaArmy sa5; sa5.summonElite(3); // summon

    std::cout << "\n[PUSTA]"; sa1.show();
    std::cout << "\n[3 ZWYKŁYCH]"; sa2.show();
    std::cout << "\n[ELITARNA]"; sa3.show();
    std::cout << "\n[KOPIA ELITARNEJ]"; sa4.show();
    std::cout << "\n[SAMMONE ELITARNYCH]"; sa5.show();



    //
    // ============================================================
    //  5. WALKI
    // ============================================================
    //
    std::cout << "\n=====================================================\n";
    std::cout << "                   WALKI TESTOWE                     \n";
    std::cout << "=====================================================\n";

    //
    // 5a) WALKA 1 vs 1
    //
    std::cout << "\n--- WALKA 1 vs 1: Mikołaj (delegujący) vs Elf (losowy) ---\n";

    SantaClauss fighterSanta = m4;   // delegujący konstruktor Mikołaja
    Elf fighterElf = e6;             // losowy łucznik

    std::cout << "\n> PRZED WALKĄ:\n";
    fighterSanta.showStats();
    fighterElf.showStats();

    int round = 1;
    while (fighterSanta.isAlive() && fighterElf.isAlive())
    {
        std::cout << "\n[Runda " << round << "]\n";

        int sHit = fighterSanta.getBaseDamage() + std::rand() % 10;
        int eHit = fighterElf.getBaseDamage() + std::rand() % 8;

        std::cout << "Mikołaj atakuje za " << sHit << "\n";
        fighterElf.takeDamage(sHit);

        if (!fighterElf.isAlive())
            break;

        std::cout << "Elf uderza za " << eHit << "\n";
        fighterSanta.takeDamage(eHit);

        round++;
    }

    std::cout << "\n> WYNIK WALKI 1v1:\n";
    if (fighterSanta.isAlive())
        std::cout << "Mikołaj zwycięża! 🎅\n";
    else
        std::cout << "Elf zwycięża! 🧝\n";



    //
    // 5b) WALKA ARMIA vs ARMIA
    //
    std::cout << "\n=====================================================\n";
    std::cout << "                 WALKA ARMIA vs ARMIA                \n";
    std::cout << "=====================================================\n";

    // wybierz armie utworzone różnymi konstruktorami:
    SantaArmy battleSanta = sa3;   // elitarna armia (konstruktor parametr+elite)
    ElfArmy battleElves = ea3;     // imienna armia (konstruktor listowy)

    battleSanta.show();
    battleElves.show();

    battleArmies(battleSanta, battleElves);

    std::cout << "\n=====================================================\n";
    std::cout << "                  KONIEC EPIZODU 3                    \n";
    std::cout << "=====================================================\n\n";
}


void Game::episode3()
{
    std::cout << BOLD << BLUE 
              << "\n====== EPISODE 04 — KONWERSJE + QUESTY ======\n" 
              << RESET;

    // ===== 1. TWORZENIE NOWYCH POSTACI =====

    Character goldMiner("GoldMiner", 100, 5);
    Character snowCollector(std::string("SnowCollector"), 90, 3);
    Character reindeerHunter("ReindeerHunter", 110, 6);

    std::cout << GREEN << "Utworzono 3 nowe postacie wykonujące questy!\n" << RESET;

    goldMiner.showStats();
    snowCollector.showStats();
    reindeerHunter.showStats();

    // ===== 2. TWORZENIE QUESTÓW =====

    Quest q1 = "Mining Gold";                // implicit
    Quest q2(std::string("Collect Snow"));    // explicit
    Quest q3("Hunt Reindeer");                // implicit

    // ===== 3. TIMER TICK-BASED (BEZ THREADÓW) =====

    QuestTimer timer1(q1.getDuration());
    QuestTimer timer2(q2.getDuration());
    QuestTimer timer3(q3.getDuration());

    std::cout << "\n" << YELLOW << "Rozpoczynamy wykonywanie questów!\n" << RESET;

    // ===== QUEST 1: goldMiner wykonuje miningGold =====

    while (static_cast<bool>(timer1)) {
        miningGold(q1);
        timer1.tick();            // symulacja upływu czasu
    }

    Reward r1 = miningGold(q1);
    int gold = static_cast<int>(r1);

    std::cout << GREEN << "GoldMiner zdobył: " << gold << " złota!\n" << RESET;

    // ===== QUEST 2: snowCollector =====

    while (static_cast<bool>(timer2)) {
        collectSnow(q2);
        timer2.tick();
    }

    Reward r2 = collectSnow(q2);
    Item snowItem = static_cast<Item>(r2);

    std::cout << CYAN << "SnowCollector zdobył przedmiot: " << snowItem.name << RESET << "\n";

    // ===== QUEST 3: reindeerHunter =====

    while (static_cast<bool>(timer3)) {
        huntReindeer(q3);
        timer3.tick();
    }

    Reward r3 = huntReindeer(q3);
    SantaClauss guardian = static_cast<SantaClauss>(r3);

    std::cout << MAGENTA << "ReindeerHunter otrzymał strażnika nagrody!\n" << RESET;
    guardian.showStats();

    // reinterpret_cast demonstracja

    Reward* p = &r3;
    void* raw = reinterpret_cast<void*>(p);
    Reward* back = reinterpret_cast<Reward*>(raw);

#ifdef DEBUG
    std::cout << YELLOW 
              << "[DEBUG] reinterpret_cast poprawny? "
              << (p == back ? "TAK" : "NIE") << RESET << "\n";
#endif
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
