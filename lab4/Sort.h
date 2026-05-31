#pragma once
#include <initializer_list>

class IntStack
{
public:
    IntStack();
    IntStack(int* arr, int count);
    IntStack(int capacity);
    IntStack(IntStack& other);

    void Push(int value);
    void Pop();
    int  Top();

    bool Empty();

    void Clear();

private:
    void ResizeIfNeeded();
private:
    int* m_array;
    int  m_capacity;
    int  m_count;
};

class Sort
{
public:
    Sort(int count, int min, int max);
    Sort(const Sort& other);
    Sort(int* arr, int count);
    Sort(int count, ...);
    Sort(const char* str);

    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);

private:
    int QuickSortPartition(bool ascendent, int* arr, int start, int end);
private:
    int* m_array;
    int  m_count;
};
