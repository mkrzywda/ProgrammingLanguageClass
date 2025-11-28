#include "Transmission.h"

Transmission::Transmission(const std::string& t)
    : type(t), currentGear(0)
{
    std::cout << "[Transmission] Created: " << type << "\n";
}

Transmission::~Transmission() {
    std::cout << "[Transmission] Destroyed: " << type << "\n";
}

std::string Transmission::gearToString() const {
    switch (currentGear) {
        case -1: return "R";
        case  0: return "N";
        default: return std::to_string(currentGear);
    }
}

std::ostream& operator<<(std::ostream& os, const Transmission& t) {
    os << "Transmission: " << t.type << " | Gear: " << t.gearToString();
    return os;
}
