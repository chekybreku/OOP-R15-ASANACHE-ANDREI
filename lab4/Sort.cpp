#include "Sort.h"
#include <cstring>
#include <cstdio>
#include <cstdarg>
#include <cstdlib>
#include <ctime>

IntStack::IntStack() : IntStack(2) {}

IntStack::IntStack(int* arr, int count) :
    m_array(new int[count]), m_count(count), m_capacity(count) {
    memcpy(m_array, arr, sizeof(int) * count);
}

IntStack::IntStack(int capacity) :
    m_capacity(capacity), m_count(0), m_array(new int[capacity]) {
}

IntStack::IntStack(IntStack& other) :
    m_array(new int[other.m_capacity]), m_capacity(other.m_capacity), m_count(other.m_count) {
    memcpy(m_array, other.m_array, sizeof(int) * other.m_count);
}

void IntStack::Push(int value) {
    ResizeIfNeeded();

    m_array[m_count++] = value;
}


void IntStack::ResizeIfNeeded() {
    if (m_count >= m_capacity) {
        m_capacity *= 2;
        int* new_array = new int[m_capacity];
        memcpy(m_array, new_array, sizeof(int) * m_count);
    }
}

void IntStack::Pop() {
    m_count--;
}

int  IntStack::Top() {
    return m_array[m_count - 1];
}

bool IntStack::Empty() {
    return m_count < 1;
}

void IntStack::Clear() {
    m_count = 0;
}

Sort::Sort(int count, int min, int max) : m_array(new int[count]), m_count(count) {
    std::srand(time(0));
    for (int i = 0; i < count; i++) {
        double rand_distributed = ((double)std::rand() / RAND_MAX) * (max - min) + min;

        m_array[i] = rand_distributed;
    }
}

Sort::Sort(const Sort& other) : m_array(new int[other.m_count]), m_count(other.m_count) {
    memcpy(m_array, other.m_array, sizeof(char) * m_count);
}

Sort::Sort(int* array, int count) : m_array(new int[count]), m_count(count) {
    memcpy(m_array, array, sizeof(int) * count);
}

Sort::Sort(int count, ...) : m_array(new int[count]), m_count(count) {
    va_list args;
    va_start(args, 0);

    for (int i = 0; i < count; i++) {
        int arg = va_arg(args, int);

        m_array[i] = arg;
    }

    va_end(args);
}

Sort::Sort(const char* str) {
    int x = 0;
    int len = 0;
    int count = 1;
    while (str[len] != '\0') {
        if (str[len] == ',') count++;
        len++;
    }

    m_array = new int[count];
    m_count = count;

    int j = 0;

    for (int i = 0; i < len; i++) {
        char c = str[i];
        if (c == ',') {
            m_array[j] = x;
            x = 0;
            j++;
        }
        else {
            int digit = (int)(c - '0');

            x = x * 10 + digit;
        }
    }

    m_array[count - 1] = x;
}

void Sort::InsertSort(bool ascendent) {
    for (int i = 1; i < m_count; i++) {
        int toAdd = m_array[i];
        int sortedIdx = i - 1;

        while (sortedIdx >= 0 &&
            (ascendent ? m_array[sortedIdx] > toAdd : m_array[sortedIdx] < toAdd)) {
            m_array[sortedIdx + 1] = m_array[sortedIdx];
            sortedIdx--;
        }

        m_array[sortedIdx + 1] = toAdd;
    }
}

int Sort::QuickSortPartition(bool ascendent, int* arr, int start, int end) {
    int pivot = arr[end];
    int i = start;

    for (int j = start; j < end; j++) {
        if (ascendent ? arr[j] <= pivot : arr[j] >= pivot) {
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;

            i++;
        }
    }

    arr[end] = arr[i];
    arr[i] = pivot;

    return i;
}

void Sort::QuickSort(bool ascendent) {
    int start = 0;
    int end = m_count - 1;

    IntStack startStack;
    IntStack endStack;
    startStack.Push(start);
    endStack.Push(end);


    while (!startStack.Empty() && !endStack.Empty()) {
        start = startStack.Top();
        end = endStack.Top();

        startStack.Pop();
        endStack.Pop();

        int pivot = QuickSortPartition(ascendent, m_array, start, end);

        if (pivot - 1 > start) {
            startStack.Push(start);
            endStack.Push(pivot - 1);
        }

        if (pivot + 1 < end) {
            startStack.Push(pivot + 1);
            endStack.Push(end);
        }
    }

}
void Sort::BubbleSort(bool ascendent) {
    for (int i = 0; i < m_count; i++) {
        bool changed = false;
        for (int j = 0; j < m_count - i - 1; j++) {
            if (ascendent ? (m_array[j] > m_array[j + 1]) : (m_array[j] < m_array[j + 1])) {
                int temp = m_array[j];
                m_array[j] = m_array[j + 1];
                m_array[j + 1] = temp;
                changed = true;
            }
        }
        if (!changed) return;
    }
}
void Sort::Print() {
    int count = GetElementsCount();
    printf("[");
    for (int i = 0; i < count - 1; i++) {
        printf("%d, ", m_array[i]);
    }

    printf("%d]\n", m_array[count - 1]);
}
int Sort::GetElementsCount() {
    return m_count;

}
int Sort::GetElementFromIndex(int index) {
    return m_array[index];
}