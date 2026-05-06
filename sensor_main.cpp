#include "sensor.hpp"
#include <iostream>

int main() {
    Sensor s("TestSensor");
    for(int i=0;i<11;i++){
        float a = i * 2.0f;
        s.update(a);
    }
    std::cout << "Average sensor reading for " << s.getName() << ": " << s.average() << std::endl;

    SensorArray sa;
    sa.addSensor("TestSensor");
    sa.addSensor("IMU Sensor");
    sa.printAll();
    return 0;
}