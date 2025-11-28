#include "Car.h"
#include <vector>
#include <thread>
#include <chrono>

int main() {
    std::cout << "=== Vehicle Simulation ===\n\n";

    Car skoda("Skoda", "Octavia", "2.0 TDI");
    Car toyota("Toyota", "Supra", "3.0 Turbo", "Manual 6-speed");

    skoda.start();
    skoda.accelerate(3200);
    skoda.shiftUp();
    skoda.shiftUp();

    toyota.start();
    toyota.accelerate(6000);

    std::cout << "\n--- Status ---\n";
    skoda.printStatus();
    toyota.printStatus();

    std::cout << "\nTotal cars: " << Car::getTotalCars() << "\n";
    std::cout << "Engines running: " << Engine::getRunningEngines() << "\n";

    return 0;
}
