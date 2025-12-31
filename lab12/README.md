# **EPISODE 4 – Wielopoziomowe Questy jako biblioteka statyczna**

W tym epizodzie należy zaimplementować **rozszerzony system questów**, który:

⚠️ **UWAGA ORGANIZACYJNA**

* Nie wszystkie pliki `.h` i `.cpp` wymagają uzupełnienia.
* Część plików jest dostarczona w całości lub częściowo.
* Najważniejsze jest:

  * kompletność rozwiązania,
  * poprawne relacje między klasami,
  * zgodność z dokumentacją (a jak plik .h dokumentacji nie posiada to trzeba uzupełnić)

---

## 🏷️ **1. RewardType_v2 (RewardType_v2.h)**

Typ wyliczeniowy określający **dokładną konfigurację nagrody**.

### **Wymagania:**

* Silnie typowany enum (`enum class`)
* Dostępne wartości:

  * Gold
  * Item
  * Item + Gold
  * Item + Gold + Exp
  * Exp + Item
  * Exp

Inne kombinacje są niedozwolone.

---

## 🎁 **2. Klasa Reward_v2 (Reward_v2.h / Reward_v2.cpp)**

Reprezentuje **nagrodę otrzymywaną po ukończeniu questa**.

### **Wymagania:**

#### **Konstruktory:**

* Osobny konstruktor dla każdej dozwolonej konfiguracji nagrody
* Każdy konstruktor musi być oznaczony jako `explicit` - w dokumentacji napisać dlaczego :)

#### **Pola:**

* typ nagrody (`RewardType_v2`)
* wartość złota
* wartość doświadczenia
* przedmiot (Item)
* informacja, czy nagroda zawiera przedmiot

#### **Konwersje:**

* Reward → Gold
* Reward → Exp
* Reward → Item

#### **Zasady konwersji:**

* Konwersje do typów prostych nie mogą być niejawne
* Wymuszone użycie `static_cast`
* Konwersje realizowane przez operatory konwersji klas

---

## 📜 **3. Klasa Quest_v2 (Quest_v2.h / Quest_v2.cpp)**

Reprezentuje **quest nadrzędny**, który może składać się z wielu etapów.

### **Wymagania:**

#### **Konstruktory:**

* Niejawny konstruktor z `const char*`
* Jawny konstruktor z `std::string`

#### **Pola:**

* nazwa questa
* flaga ukończenia
* lista podquestów
* indeks aktualnego etapu
* licznik wykonań (pole `mutable`)

#### **Metody:**

* dodawanie podquestów
* wykonywanie pojedynczego kroku
* sprawdzenie, czy quest jest ukończony
* jawna konwersja do `std::string`

---

## 🧩 **4. Klasa SubQuest_v2 (SubQuest_v2.h / SubQuest_v2.cpp)**

Reprezentuje **pojedynczy etap questa**.

### **Wymagania:**

#### **Konstruktory:**

* Niejawny konstruktor z `const char*`
* Jawny konstruktor z nazwą i czasem trwania

#### **Pola:**

* nazwa etapu
* timer etapu
* flaga ukończenia
* licznik kroków (mutable)

#### **Metody:**

* wykonanie pojedynczego kroku
* sprawdzenie ukończenia etapu
* pobranie postępu

---

## ⏳ **5. QuestTimer_v2 (QuestTimer_v2.h / QuestTimer_v2.cpp)**

Prosty licznik symulujący czas trwania etapu.

### **Wymagania:**

#### **Konstruktory:**

* Jawny konstruktor ustawiający czas trwania

#### **Pola:**

* czas trwania
* licznik wykonanych kroków

#### **Metody:**

* `tick()`
* `reset()`
* jawny operator `operator bool()`

---

## ⚒️ **6. questFunctions_v2 (questFunctions_v2.h / questFunctions_v2.cpp)**

Zbiór funkcji realizujących konkretne questy.

### **Wymagania dla każdej funkcji:**

* Przyjmuje obiekt `Quest_v2` przez referencję
* Wykonuje jeden krok aktualnego etapu
* Wyświetla informację o wykonywanej czynności
* Zwraca obiekt `Reward_v2` dopiero po ukończeniu całego questa

### **Obowiązkowe funkcje:**

* `miningGold_v2`
* `collectSnow_v2`
* `huntReindeer_v2`

---
