
# **EPISODE 2**

W tym zadaniu należy zaimplementować świąteczny system walki oparty na obiektowym modelu postaci i armii.
Wymagane jest wykorzystanie **różnych rodzajów konstruktorów**, mechanizmu **zaprzyjaźniania klas**, **osobnych plików**, oraz **prostej logiki walki**.

Poniżej szczegółowo wymieniono **co musi zostać zaimplementowane w każdej klasie i pliku**.

---

# 🎅 **1. Klasa SantaClauss (SantaClauss.h / SantaClauss.cpp)**

Implementacja Mikołaja jako obiektu gry.

### **Wymagania:**

* Konstruktor domyślny
* Konstruktor z parametrami (imię, HP, bazowe obrażenia)
* Konstruktor kopiujący
* Konstruktor delegujący (np. poziom trudności → automatyczne staty)
* Konstruktor wyposażający (tworzy Mikołaja z ekwipunkiem)
* Destruktor z komunikatem debug (ifdef DEBUG)
* Metody:

  * `showStats()`
  * `getInventory()`
  * `getHp()`
  * `takeDamage(int)`
  * `isAlive()`
  * `getBaseDamage()`

---

# 🧝 **2. Klasa Elf (Elf.h / Elf.cpp)**

Implementacja elfa w różnych wariantach klasowych.

### **Wymagania:**

* Enum `ElfClassType` (Warrior, Mage, Archer)
* Konstruktor domyślny
* Konstruktor z parametrami (imię, HP, typ)
* Konstruktor kopiujący
* Konstruktor fabryczny (statyczne metody):

  * `createWarrior()`
  * `createMage()`
* Konstruktor losowy (explicit Elf(ElfClassType))
* Destruktor z komunikatem debug
* Metody:

  * `showStats()`
  * `getInventory()`
  * `getHp()`
  * `takeDamage(int)`
  * `isAlive()`
  * `getBaseDamage()`

---

# ⚔️ **3. Klasa SantaArmy (SantaArmy.h / SantaArmy.cpp)**

Armia złożona z obiektów SantaClauss.

### **Wymagania:**

* Konstruktor domyślny (musi ustawiać morale = 0)
* Konstruktor z liczbą jednostek
* Konstruktor (count, elite) tworzący armię elitarną
* Konstruktor kopiujący
* Destruktor z debug
* Metody:

  * `summon(int)` (tworzy zwykłych Mikołajów, morale = 100)
  * `summonElite(int)` (tworzy elitarnych, morale = 120)
  * `show()` (kolorowy output)
  * `hasUnits()`
  * `size()`
  * `getUnit(int)`
* **Zaprzyjaźnienie:**

  * `friend class ElfArmy;`
  * `friend void battleArmies(SantaArmy&, ElfArmy&);`

---

# 🧝‍♂️ **4. Klasa ElfArmy (ElfArmy.h / ElfArmy.cpp)**

Armia elfów w różnych wariantach tworzenia.

### **Wymagania:**

* Konstruktor domyślny (morale = 0)
* Konstruktor parametryczny (count + type)
* Konstruktor z listą imion
* Konstruktor kopiujący
* Destruktor z debug
* Metody:

  * `summonRandom(int)` (losowanie typów elfów)
  * `show()`
  * `hasUnits()`
  * `size()`
  * `getUnit(int)`
* **Zaprzyjaźnienie:**

  * `friend void battleArmies(SantaArmy&, ElfArmy&);`

---

# ⚡ **5. Funkcja battleArmies (battleArmies.cpp)**

Tryb walki między armiami.

### **Wymagania:**

* Plik osobny od klas
* Funkcja zaprzyjaźniona
* Walka turowa:

  * Mikołaj zadaje losowe obrażenia
  * Elf zadaje kontratak
* Usuwanie martwych jednostek z armii
* Kolorowanie wyników:

  * atak Mikołaja → zielony
  * atak elfa → cyjan
  * śmierć jednostki → czerwony
* Ogłoszenie zwycięzcy/porazki/remisu

---

# 🎨 **6. Colors.h**

Zestaw definicji ANSI:

* RED, GREEN, BLUE, CYAN, YELLOW, MAGENTA, WHITE
* RESET
* BOLD

---

# 🎮 **7. Game.cpp — episode2()**

Prezentacja i test całego systemu.

### **Wymagania:**

* Tworzenie Mikołaja wszystkimi konstruktorami
* Tworzenie Elfa wszystkimi konstruktorami
* Tworzenie armii elfów wszystkimi konstruktorami
* Tworzenie armii Mikołajów wszystkimi konstruktorami
* Kolorowe nagłówki i opisy
* Walka 1 vs 1
* Walka armia vs armia
* Debugi w trybie DEBUG
* Czytelny, fabularny opis

---

# 🧰 **8. Character + Inventory + Item**

Upewnij się, że klasa Character zawiera:

* `getHp()`
* `takeDamage()`
* `isAlive()`
* `getInventory()`
* `showStats()`

Jeśli ich nie ma → trzeba dodać (armie ich używają).