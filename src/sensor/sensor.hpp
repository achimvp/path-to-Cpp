#pragma once
#include <array>
#include <memory>
#include <string>

class BaseSensor {
   public:
    BaseSensor(const std::string& name, float minVal, float maxVal);
    virtual ~BaseSensor() = default;
    virtual void update(float raw);
    virtual std::string getUnit() const = 0;
    float getValue() const;
    std::string getName() const;
    float getAverage() const;

   protected:
    std::string name;
    float value;
    float minVal;
    float maxVal;
    std::array<float, 10> history;
    size_t historyPosition = 0;
};

class TemperatureSensor : public BaseSensor {
   public:
    TemperatureSensor(const std::string& name, float minVal = -40.0f, float maxVal = 125.0f);
    std::string getUnit() const override;
    float getFahrenheit() const;
};

class PressureSensor : public BaseSensor {
   public:
    PressureSensor(const std::string& name, float minVal = 300.0f, float maxVal = 1100.0f);
    std::string getUnit() const override;
    float getAltitude() const;  // siehe barometrische Hoehenformel
};

class HumiditySensor : public BaseSensor {
   public:
    HumiditySensor(const std::string& name, float minVal = 0.0f, float maxVal = 100.0f);
    std::string getUnit() const override;
    bool isDewPointRisk() const;
};

std::ostream& operator<<(std::ostream& os, const BaseSensor& sensor);

class SensorArray {
   private:
    std::array<std::unique_ptr<BaseSensor>, 8> sensors;
    size_t numSensors = 0;

   public:
    void addSensor(std::unique_ptr<BaseSensor> s);
    void printAll() const;
    BaseSensor& getSensor(const std::string& name) const;
};