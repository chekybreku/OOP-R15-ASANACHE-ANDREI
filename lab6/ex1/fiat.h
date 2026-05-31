#pragma once

#include "car.h"

class Fiat : public Car {
public:
    uint32_t GetAverageSpeed(Weather weather) override;
    uint32_t GetFuelCapacity() override;
    uint32_t GetFuelConsumption() override;
    const char* GetName() override;
};