#include "circuit.h"

#include <cstring>
#include <cmath>
#include <iostream>
#include <print>
#include <stdexcept>


CarList::CarList() : m_capacity(4), m_count(0), m_cars(new Car* [m_capacity]) {}

CarList::~CarList() {
    delete[] m_cars;
}

void CarList::Push(Car* car) {
    if (m_count > m_capacity) {
        m_capacity *= 2;

        Car** cars = m_cars;

        m_cars = new Car * [m_capacity];
        memcpy(m_cars, cars, sizeof(Car*) * m_count);

        delete[] cars;
    }

    m_cars[m_count++] = car;
}

void CarList::Clear() {
    m_count = 0;
}

void CarList::Resize(size_t new_size) {
    if (new_size <= m_capacity) return;
    m_capacity = new_size;
    Car** cars = m_cars;

    m_cars = new Car * [m_capacity];
    memcpy(m_cars, cars, sizeof(Car*) * m_count);

    delete[] cars;
}



void CarList::Sort(Weather weather) {
    for (int i = 0; i < m_count; i++) {
        bool swapped = false;
        for (int j = 0; j < m_count - i - 1; j++) {
            if (m_cars[j]->GetAverageSpeed(weather) < m_cars[j + 1]->GetAverageSpeed(weather)) {
                swapped = true;

                Car* temp = m_cars[j];
                m_cars[j] = m_cars[j + 1];
                m_cars[j + 1] = temp;
            }
        }
        if (!swapped) break;
    }
}

size_t CarList::Size() const {
    return m_count;
}

Car* CarList::operator[](size_t index) {
    if (index >= m_count) {
        std::cerr << "[CarList] Index out of bounds (" << index << " >= " << m_count << ")" << std::endl;
        exit(1);
    }

    return m_cars[index];
}

void Circuit::SetLength(size_t len) {
    m_length = len;
}

void Circuit::AddCar(Car* car) {
    m_cars.Push(car);
}

void Circuit::SetWeather(Weather weather) {
    m_weather = weather;
}

void Circuit::Race() {
    m_ranked.Clear();
    m_unfinished.Clear();

    m_ranked.Resize(m_cars.Size());
    m_unfinished.Resize(m_cars.Size());

    m_cars.Sort(m_weather);

    for (int i = 0; i < m_cars.Size(); i++) {
        Car* car = m_cars[i];

        if (m_length * car->GetFuelConsumption() > car->GetFuelCapacity()) {
            m_unfinished.Push(car);
        }
        else {
            m_ranked.Push(car);
        }
    }
}

void Circuit::ShowFinalRanks() {
    std::printf("Ranked Cars:\n");
    for (int i = 0; i < m_ranked.Size(); i++) {
        Car* car = m_ranked[i];
        std::printf("  %d - %s\n", i + 1, car->GetName());
    }
}

void Circuit::ShowWhoDidNotFinish() {
    std::printf("Cars That Did Not Finish:\n");
    for (int i = 0; i < m_unfinished.Size(); i++) {
        Car* car = m_unfinished[i];
        std::printf("  %s\n", car->GetName());
    }
}