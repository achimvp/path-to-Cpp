#include "sensor.hpp"
#include <gtest/gtest.h>

TEST(SensorTest, GetSensorName) {
    Sensor s("TestSensor");
    EXPECT_STREQ(s.getName().c_str(), "TestSensor");
};

TEST(SensorTest, UpdateSensor) {
    Sensor s("TestSensor");
    s.update(4.98f);
    EXPECT_FLOAT_EQ(s.getValue(), 4.98f);
};

TEST(SensorTest, AverageSensorValues) {
    Sensor s("TestSensor");
    for(size_t i=0;i<10;i++){
        s.update(static_cast<float>(i));
    }
    EXPECT_FLOAT_EQ(s.average(), 4.5f);
}