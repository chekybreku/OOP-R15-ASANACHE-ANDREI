#pragma once

#include <cstdlib>
#include "car.h"

class CarList {
public:
    CarList();
    ~CarList();

    void Push(Car* car);
    void Clear();
    void Resize(size_t new_size);
    void Sort(Weather weather);

    size_t Size() const;

    Car* operator[](size_t index);
private:
    size_t m_capacity;
    size_t m_count;
    Car** m_cars;
};


class Circuit {
public:
    Circuit() = default;
    ~Circuit() = default;

    void SetLength(size_t len);
    void AddCar(Car* car);
    void SetWeather(Weather weather);
    void Race();
    void ShowFinalRanks();
    void ShowWhoDidNotFinish();

private:
    Weather m_weather = SUNNY;
    size_t m_length = 100;
    CarList m_cars;
    CarList m_ranked;
    CarList m_unfinished;
};