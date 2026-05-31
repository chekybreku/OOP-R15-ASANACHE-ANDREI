#include "seat.h"

uint32_t Seat::GetAverageSpeed(Weather weather) {
    return 40;
}

uint32_t Seat::GetFuelCapacity() {
    return 100;
}

uint32_t Seat::GetFuelConsumption() {
    return 10;
}

const char* Seat::GetName() {
    return "Seat";
}