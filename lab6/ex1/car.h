#pragma once

#include <cstdint>
#include "weather.h"

class Car {
public:
    virtual ~Car() = default;

    virtual const char* GetName() = 0;
    virtual uint32_t    GetFuelCapacity() = 0;
    virtual uint32_t    GetFuelConsumption() = 0;
    virtual uint32_t    GetAverageSpeed(Weather weather) = 0;
};