#include <gtest/gtest.h>

#include "sensor.hpp"

TEST(SensorTest, GetSensorName) {
    Sensor s("TestSensor", 0.0f, 100.0f);
    EXPECT_STREQ(s.getName().c_str(), "TestSensor");
};

TEST(SensorTest, MaxValueError) {
    Sensor s("TestSensor", 0.0f, 5.0f);
    EXPECT_THROW(s.update(5.98f), std::out_of_range);
};
TEST(SensorTest, MaxValue) {
    Sensor s("TestSensor", 0.0f, 5.0f);
    EXPECT_NO_THROW(s.update(4.98f));
};

TEST(SensorTest, MinValueError) {
    Sensor s("TestSensor", 0.0f, 5.0f);
    EXPECT_THROW(s.update(-0.98f), std::out_of_range);
};

TEST(SensorTest, MinValue) {
    Sensor s("TestSensor", 0.0f, 5.0f);
    EXPECT_NO_THROW(s.update(0.98f));
};

TEST(SensorTest, UpdateSensor) {
    Sensor s("TestSensor", 0.0f, 5.0f);
    s.update(4.98f);
    EXPECT_FLOAT_EQ(s.getValue(), 4.98f);
};

TEST(SensorTest, AverageSensorValues) {
    Sensor s("TestSensor", 0.0f, 100.0f);
    for (size_t i = 0; i < 10; i++) {
        s.update(static_cast<float>(i));
    }
    std::cout << s.getAverage() << std::endl;
    EXPECT_FLOAT_EQ(s.getAverage(), 4.5f);
}

TEST(SensorArrayTest, GetHottestSensor) {
    Sensor s1("S1", 0.0f, 100.0f);
    s1.update(5.0f);
    Sensor s2("S2", 0.0f, 100.0f);
    s2.update(10.0f);
    SensorArray sa;
    sa.addSensor(s1);
    sa.addSensor(s2);
    EXPECT_FLOAT_EQ(sa.getHottestSensor().getValue(), 10.0f);
    EXPECT_STREQ(sa.getHottestSensor().getName().c_str(), "S2");
}

TEST(SensorArrayTest, GetSensorByName) {
    Sensor s1("S1", 0.0f, 100.0f);
    Sensor s2("S2", 0.0f, 100.0f);
    SensorArray sa;
    sa.addSensor(s1);
    sa.addSensor(s2);
    EXPECT_THROW(sa.getSensor("S3"), std::out_of_range);
    EXPECT_NO_THROW(sa.getSensor("S1"));
}