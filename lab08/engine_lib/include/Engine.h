#pragma once
#include <string>
#include <iostream>

class Engine {
private:
    const std::string engineCode;
    double currentRpm;
    double temperature;
    bool isRunning;

    static int totalEngines;
    static int runningEngines;

    // Tylko Car może sterować silnikiem
    friend class Car;

    Engine(const std::string& code);

public:
    ~Engine();

    const std::string& getCode() const { return engineCode; }
    double getRpm() const { return currentRpm; }
    double getTemp() const { return temperature; }
    bool isRunningState() const { return isRunning; }

    static int getTotalEngines() { return totalEngines; }
    static int getRunningEngines() { return runningEngines; }

    friend std::ostream& operator<<(std::ostream& os, const Engine& e);
};