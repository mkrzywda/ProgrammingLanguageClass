#pragma once
#include <string>
#include <iostream>

class Transmission {
private:
    const std::string type;
    int currentGear; // -1=R, 0=N, 1..6

    friend class Car;

    explicit Transmission(const std::string& t = "Manual 6-speed");

public:
    ~Transmission();

    const std::string& getType() const { return type; }
    int getGear() const { return currentGear; }
    std::string gearToString() const;

    friend std::ostream& operator<<(std::ostream& os, const Transmission& t);
};
