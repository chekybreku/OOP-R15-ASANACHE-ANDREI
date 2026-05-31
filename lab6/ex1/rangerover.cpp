#include "rangerover.h"

uint32_t RangeRover::GetAverageSpeed(Weather weather) {
    return 60;
}

uint32_t RangeRover::GetFuelCapacity() {
    return 120;
}

uint32_t RangeRover::GetFuelConsumption() {
    return 60;
}

const char* RangeRover::GetName() {
    return "RangeRover";
}