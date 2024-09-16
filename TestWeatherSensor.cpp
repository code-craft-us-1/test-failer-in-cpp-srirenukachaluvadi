#include <assert.h>
#include <string>
#include <iostream>
#include "WeatherSensor.h"

/// This is a stub for a weather sensor. For the sake of testing
/// we create a stub that generates weather data and allows us to
/// test the other parts of this application in isolation
/// without needing the actual Sensor during development

class SensorStub : public WeatherSpace::IWeatherSensor {
    int Humidity() const override {
        return 72;
    }

    int Precipitation() const override {
        return 70;
    }

    double TemperatureInC() const override {
        return 26;
    }

    int WindSpeedKMPH() const override {
        return 52;
    }
};
class SensorStub2 : public WeatherSpace::IWeatherSensor {
    int Humidity() const override {
        return 72;
    }

    int Precipitation() const override {
        return 70;
    }

    double TemperatureInC() const override {
        return 26;
    }

    int WindSpeedKMPH() const override {
        return 30;
    }
};

// This is a function to predict the weather, based on readings
// from a sensor

std::string Report(const WeatherSpace::IWeatherSensor& sensor) {
    int precipitation = sensor.Precipitation();
    // precipitation < 20 is a sunny day
    std::string report = "Sunny day";

    if (sensor.TemperatureInC() > 25) {
        if (precipitation >= 20 && precipitation < 60)
            report = "Partly cloudy";
        else if (sensor.WindSpeedKMPH() > 50)
            report = "Alert, Stormy with heavy rain";
    }
    return report;
}

// Test a rainy day

void TestRainy() {
    SensorStub sensor;
    std::string report = Report(sensor);
    std::cout << report << std::endl;
    assert(report.find("rain") != std::string::npos);
}

// Test another rainy day

void TestHighPrecipitationAndLowWindspeed() {
    // This instance of stub needs to be different-
    // to give high precipitation (>60) and low wind-speed (<50)
    SensorStub2 sensor;

    // strengthen the assert to expose the bug
    // (function returns Sunny day, it should predict rain)
    std::string report = Report(sensor);
    assert(report.find("Sunny") == std::string::npos);
}

int main() {
    TestRainy();
    TestHighPrecipitationAndLowWindspeed();
    std::cout << "All is well (maybe)\n";
    return 0;
}
