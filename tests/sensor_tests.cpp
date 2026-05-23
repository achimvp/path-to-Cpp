#include <gtest/gtest.h>

#include "sensor.hpp"

TEST(SensorTest, GetSensorName) {
    TemperatureSensor s("TestSensor", 0.0f, 100.0f);
    EXPECT_STREQ(s.getName().c_str(), "TestSensor");
};

TEST(SensorTest, MaxValueError) {
    PressureSensor s("TestSensor", 0.0f, 5.0f);
    EXPECT_THROW(s.update(5.98f), std::out_of_range);
};
TEST(SensorTest, MaxValue) {
    HumiditySensor s("TestSensor", 0.0f, 5.0f);
    EXPECT_NO_THROW(s.update(4.98f));
};

TEST(SensorTest, MinValueError) {
    TemperatureSensor s("TestSensor", 0.0f, 5.0f);
    EXPECT_THROW(s.update(-0.98f), std::out_of_range);
};

TEST(SensorTest, MinValue) {
    PressureSensor s("TestSensor", 0.0f, 5.0f);
    EXPECT_NO_THROW(s.update(0.98f));
};

TEST(SensorTest, UpdateSensor) {
    HumiditySensor s("TestSensor", 0.0f, 5.0f);
    s.update(4.98f);
    EXPECT_FLOAT_EQ(s.getValue(), 4.98f);
};

TEST(SensorTest, AverageSensorValues) {
    TemperatureSensor s("TestSensor", 0.0f, 100.0f);
    for (size_t i = 0; i < 10; i++) {
        s.update(static_cast<float>(i));
    }
    std::cout << s.getAverage() << std::endl;
    EXPECT_FLOAT_EQ(s.getAverage(), 4.5f);
}

TEST(TemperatureSensorTest, SensorValueRange) {
    TemperatureSensor s("T1");
    EXPECT_THROW(s.update(200.0f), std::out_of_range);
    EXPECT_NO_THROW(s.update(50.0f));
}

TEST(TemperatureSensorTest, GetFahrenheit) {
    TemperatureSensor s("T1");
    s.update(10.0f);
    EXPECT_FLOAT_EQ(s.getFahrenheit(), 50.0f);
}

TEST(HumiditySensorTest, SensorValueRange) {
    HumiditySensor s("H1");
    EXPECT_THROW(s.update(-1.0f), std::out_of_range);
    EXPECT_NO_THROW(s.update(50.0f));
}

TEST(HumiditySensorTest, IsDewPointRisk) {
    HumiditySensor s("H1");
    s.update(85.0f);
    EXPECT_FALSE(s.isDewPointRisk());
    s.update(86.0f);
    EXPECT_TRUE(s.isDewPointRisk());
}

TEST(PressureSensorTest, SensorValueRange) {
    PressureSensor s("H1");
    EXPECT_THROW(s.update(1.0f), std::out_of_range);
    EXPECT_NO_THROW(s.update(1000.0f));
}

TEST(PressureSensorTest, GetAltitude) {
    PressureSensor s("H1");
    s.update(1013.25f);
    EXPECT_FLOAT_EQ(s.getAltitude(), 0.0f);
    s.update(500.0f);
    EXPECT_FLOAT_EQ(s.getAltitude(), 5952.92486102f);
}
// TEST(SensorArrayTest, GetHottestSensor) {
//     Sensor s1("S1", 0.0f, 100.0f);
//     s1.update(5.0f);
//     Sensor s2("S2", 0.0f, 100.0f);
//     s2.update(10.0f);
//     SensorArray sa;
//     sa.addSensor(s1);
//     sa.addSensor(s2);
//     EXPECT_FLOAT_EQ(sa.getHottestSensor().getValue(), 10.0f);
//     EXPECT_STREQ(sa.getHottestSensor().getName().c_str(), "S2");
// }

TEST(SensorArrayTest, GetSensorByName) {
    SensorArray sa;
    sa.addSensor(std::make_unique<PressureSensor>("S1"));
    sa.addSensor(std::make_unique<HumiditySensor>("S2"));
    EXPECT_THROW(sa.getSensor("S3"), std::out_of_range);
    EXPECT_NO_THROW(sa.getSensor("S1"));
}