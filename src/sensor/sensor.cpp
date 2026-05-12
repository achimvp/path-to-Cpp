#include "sensor.hpp"

#include <iostream>

Sensor::Sensor(const std::string& name, float minVal, float maxVal)
    : name(name), minVal(minVal), maxVal(maxVal), value(0.0f) {}
Sensor::Sensor() : name(""), minVal(0.0f), maxVal(0.0f), value(0.0f) {};
void Sensor::update(float newValue) {
    if (newValue < minVal || newValue > maxVal) {
        throw std::out_of_range("Sensor value is not in allowed range.");
    };
    value = newValue;
    history.at(historyPosition % history.size()) = newValue;
    historyPosition = (historyPosition + 1) % (2 * history.size());
}
float Sensor::getValue() const { return value; }

std::string Sensor::getName() const { return name; }

float Sensor::getAverage() const {
    // In case we haven't had any measurements yet
    if (historyPosition == 0) return 0.0f;

    float sum = 0.0f;
    size_t measurementCounts = std::min(historyPosition, history.size());
    for (size_t i = 0; i < measurementCounts; i++) {
        sum += history[i];
    }
    return sum / measurementCounts;
}

std::ostream& operator<<(std::ostream& os, const Sensor& sensor) {
    os << "Sensor " << sensor.getName() << ": " << sensor.getValue();
    return os;
}

void SensorArray::addSensor(const Sensor& s) {
    sensors[numSensors] = s;
    numSensors++;
}

void SensorArray::printAll() const {
    std::cout << "Sensors:";
    for (size_t i = 0; i < numSensors; i++) {
        std::cout << sensors[i] << "\n";
    }
    std::cout << std::endl;
}

Sensor SensorArray::getSensor(const std::string& name) const {
    for (Sensor s : sensors) {
        if (s.getName() == name) {
            return s;
        }
    }
    throw std::out_of_range("Sensor was not found.");
}

Sensor SensorArray::getHottestSensor() const {
    size_t hottestSensorIndex = 0;
    for (size_t i = 0; i < numSensors; i++) {
        if (sensors[i].getValue() > sensors[hottestSensorIndex].getValue()) {
            hottestSensorIndex = i;
        }
    }
    return sensors[hottestSensorIndex];
}