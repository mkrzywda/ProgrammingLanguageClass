#include "Czujnik.h"

void Czujnik::ustawID(const std::string& id) { _id = id; }
void Czujnik::ustawWartosc(int v) { _wartosc = v; }
std::string Czujnik::id() const { return _id; }
int Czujnik::wartosc() const { return _wartosc; }
