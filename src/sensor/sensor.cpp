#include "sensor.hpp"

#include <iostream>

Sensor::Sensor(const std::string& name) : name(name), value(0.0f) {}
void Sensor::update(float newValue) {
    value = newValue;
    history.at(historyPosition) = newValue;
    historyPosition = (historyPosition + 1) % history.size();
}
float Sensor::getValue() const { return value; }
std::string Sensor::getName() const { return name; }
float Sensor::average() const {
    float sum = 0.0f;
    for (float measurement : history) {
        sum += measurement;
    }
    return sum / history.size();
}

void SensorArray::addSensor(const std::string& name) { sensors.push_back(Sensor(name)); }

void SensorArray::printAll() const {
    std::cout << "Sensors:";
    for (Sensor s : sensors) {
        std::cout << " " << s.getName();
    }
    std::cout << std::endl;
}