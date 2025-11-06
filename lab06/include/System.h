#pragma once
#include "Centrala.h"
#include "Logger.h"

class System {
public:
    void uruchom();
    void symulujZmianeStanu();
    void podsumowanie();

private:
    Centrala _centrala;
    Czujnik* _czujniki[3] = {nullptr, nullptr, nullptr};  // do przechowywania
};
