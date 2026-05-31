#pragma once

#include "car.h"

class BMW : public Car {
public:
    const char* GetName() override;
    uint32_t GetAverageSpeed(Weather weather) override;
    uint32_t GetFuelCapacity() override;
    uint32_t GetFuelConsumption() override;
};