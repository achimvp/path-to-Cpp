#pragma once
#include <array>
#include <string>

class Sensor {
   private:
    std::string name;
    float value;
    float minVal;
    float maxVal;
    std::array<float, 10> history;
    size_t historyPosition = 0;

   public:
    Sensor(const std::string& name, float minVal, float maxVal);
    Sensor();
    // ~Sensor();

    void update(float newValue);
    float getValue() const;
    std::string getName() const;
    float getAverage() const;
};

std::ostream& operator<<(std::ostream& os, const Sensor& sensor);

class SensorArray {
   private:
    std::array<Sensor, 8> sensors;
    size_t numSensors = 0;

   public:
    void addSensor(const Sensor& s);
    void printAll() const;
    Sensor getSensor(const std::string& name) const;
    Sensor getHottestSensor() const;
};