#include "Engine.h"
#include <iostream>

int Engine::totalEngines = 0;
int Engine::runningEngines = 0;

Engine::Engine(const std::string& code)
    : engineCode(code), currentRpm(0.0), temperature(20.0), isRunning(false)
{
    ++totalEngines;
    std::cout << "[Engine] Created: " << engineCode << "\n";
}

Engine::~Engine() {
    --totalEngines;
    if (isRunning) --runningEngines;
    std::cout << "[Engine] Destroyed: " << engineCode << "\n";
}

std::ostream& operator<<(std::ostream& os, const Engine& e) {
    os << "Engine: " << e.engineCode
       << " | " << e.currentRpm << " RPM"
       << " | " << e.temperature << "°C"
       << " | " << (e.isRunning ? "RUNNING" : "STOPPED");
    return os;
}