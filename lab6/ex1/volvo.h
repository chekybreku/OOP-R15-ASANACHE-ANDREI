#pragma once

#include "car.h"

class Volvo : public Car {
public:
    virtual const char* GetName() override;
    virtual uint32_t    GetFuelCapacity() override;
    virtual uint32_t    GetFuelConsumption() override;
    virtual uint32_t    GetAverageSpeed(Weather weather) override;
};