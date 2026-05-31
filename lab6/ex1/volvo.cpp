#include "volvo.h"

#include <cstdio>
#include <cstdlib>

uint32_t Volvo::GetAverageSpeed(Weather weather) {
    switch (weather) {
    case RAINING: {
        return 90;
    }
    case SUNNY: {
        return 60;
    }
    case SNOWING: {
        return 30;
    }
    default: {
        exit(1);
    }
    }
}

const char* Volvo::GetName() {
    return "Volvo";
}

uint32_t Volvo::GetFuelCapacity() {
    return 10000;
}

uint32_t Volvo::GetFuelConsumption() {
    return 100;
}