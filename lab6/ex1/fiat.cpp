#include "fiat.h"

uint32_t Fiat::GetAverageSpeed(Weather weather) {
    return 50;
}

uint32_t Fiat::GetFuelCapacity() {
    return 80;
}

uint32_t Fiat::GetFuelConsumption() {
    return 10;
}

const char* Fiat::GetName() {
    return "Fiat";
}