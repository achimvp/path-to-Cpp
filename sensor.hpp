#pragma once
#include <string>
#include <array>
#include <vector>

class Sensor
{
private:
    float value;
    std::string name;
    std::array<float, 10> history;
    size_t historyPosition = 0;
public:
    Sensor(const std::string& name);

    void update(float newValue);
    float getValue() const;
    std::string getName() const;
    float average() const;
};

class SensorArray
{
    private:
        std::vector<Sensor> sensors;
    public:
        void addSensor(const std::string& name);
        void printAll() const;
};