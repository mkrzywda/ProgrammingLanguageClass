#pragma once
#include <string>

class Czujnik {
public:
    void ustawID(const std::string& id);
    void ustawWartosc(int v);
    std::string id() const;
    int wartosc() const;

    inline bool czyAlarm() const { return wartosc() > 80; }

private:
    std::string _id;
    int _wartosc;
};
