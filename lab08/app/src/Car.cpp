#include "Car.h"
#include <iostream>

int Car::totalCars = 0;

Car::Car(const std::string& b, const std::string& m,
         const std::string& engineCode, const std::string& transType)
    : brand(b), model(m), engine(engineCode), transmission(transType)
{
    ++totalCars;
    Logger::get().info("Car created: " + brand + " " + model);
}

Car::~Car() {
    --totalCars;
    Logger::get().info("Car destroyed: " + brand + " " + model);
}

bool Car::start() {
    if (engine.isRunning) return false;
    engine.isRunning = true;
    engine.currentRpm = 850;
    engine.temperature += 5;
    ++Engine::runningEngines;
    Logger::get().info(brand + " " + model + " started");
    return true;
}

bool Car::stop() {
    if (!engine.isRunning) return false;
    engine.isRunning = false;
    engine.currentRpm = 0;
    --Engine::runningEngines;
    transmission.currentGear = 0;
    return true;
}

bool Car::accelerate(double rpm) {
    if (!engine.isRunning || rpm < 800 || rpm > 7500) return false;
    engine.currentRpm = rpm;
    engine.temperature += rpm / 1000.0;
    return true;
}

bool Car::shiftUp() {
    if (transmission.currentGear < 6) {
        ++transmission.currentGear;
        return true;
    }
    return false;
}

bool Car::shiftDown() {
    if (transmission.currentGear > -1) {
        --transmission.currentGear;
        return true;
    }
    return false;
}

void Car::printStatus() const {
    std::cout << *this << "\n";
}

std::ostream& operator<<(std::ostream& os, const Car& c) {
    os << "Car: " << c.brand << " " << c.model << "\n"
       << "  " << c.engine << "\n"
       << "  " << c.transmission << "\n";
    return os;
}
