#include "sensor.hpp"

#include <cmath>
#include <iostream>

BaseSensor::BaseSensor(const std::string& name, float minVal, float maxVal)
    : name(name), minVal(minVal), maxVal(maxVal), value(0.0f) {}
void BaseSensor::update(float newValue) {
    if (newValue < minVal || newValue > maxVal) {
        throw std::out_of_range("Sensor value is not in allowed range.");
    };
    value = newValue;
    // historyPosition goes up to 2*size to distinguish full and empty buffers
    history.at(historyPosition % history.size()) = newValue;
    historyPosition = (historyPosition + 1) % (2 * history.size());
}
float BaseSensor::getValue() const { return value; }

std::string BaseSensor::getName() const { return name; }

float BaseSensor::getAverage() const {
    // In case we haven't had any measurements yet
    if (historyPosition == 0) return 0.0f;

    float sum = 0.0f;
    size_t measurementCounts = std::min(historyPosition, history.size());
    for (size_t i = 0; i < measurementCounts; i++) {
        sum += history[i];
    }
    return sum / measurementCounts;
}
TemperatureSensor::TemperatureSensor(const std::string& name, float minVal, float maxVal)
    : BaseSensor(name, minVal, maxVal){};
std::string TemperatureSensor::getUnit() const { return "°C"; }

float TemperatureSensor::getFahrenheit() const { return value * 9.0f / 5.0f + 32; }

PressureSensor::PressureSensor(const std::string& name, float minVal, float maxVal)
    : BaseSensor(name, minVal, maxVal){};
std::string PressureSensor::getUnit() const { return "hPa"; }

float PressureSensor::getAltitude() const {
    float p_0 = 1013.25f;  // hPa = kg * m^{-1} * s^{-2}
    float h_0 = 0.0f;      // m
    float g = 9.81f;       // m * s^{-2}
    float R = 8.314f;      // J * K^{-1} * mol^{-1}
    float T = 288.0f;      // K
    float M = 0.02896;     // kg * mol^{-1}
    float h_s = R * T / (M * g);
    return (std::log(p_0) - std::log(value)) * h_s + h_0;
}

HumiditySensor::HumiditySensor(const std::string& name, float minVal, float maxVal)
    : BaseSensor(name, minVal, maxVal){};
std::string HumiditySensor::getUnit() const { return "%"; }

bool HumiditySensor::isDewPointRisk() const { return value > 85.0f; }

std::ostream& operator<<(std::ostream& os, const BaseSensor& sensor) {
    os << "Sensor " << sensor.getName() << ": " << sensor.getValue() << sensor.getUnit();
    return os;
}

void SensorArray::addSensor(std::unique_ptr<BaseSensor> s) {
    if (numSensors >= sensors.size()) {
        throw std::out_of_range("SensorArray is full.");
    }
    sensors[numSensors] = std::move(s);
    numSensors++;
}

void SensorArray::printAll() const {
    std::cout << "Sensors:";
    for (size_t i = 0; i < numSensors; i++) {
        std::cout << *sensors[i] << "\n";
    }
    std::cout << std::endl;
}

BaseSensor& SensorArray::getSensor(const std::string& name) const {
    for (size_t i = 0; i < numSensors; i++) {
        if (sensors[i]->getName() == name) {
            return *sensors[i];
        }
    }
    throw std::out_of_range("Sensor was not found.");
}
