#include "literals.h"

float operator""_Kelvin(unsigned long long n) {
    return n + 273.15f;
}

float operator""_Fahrenheit(unsigned long long n) {
    return n * 1.8f + 32;
}