#pragma once
#include <iostream>
#include <cstdlib>
#include <algorithm>

template<typename T>
class DynamicArray
{
public:
    DynamicArray();
    DynamicArray(std::size_t size);
    DynamicArray(const DynamicArray& other);

    ~DynamicArray();

    DynamicArray& operator=(const DynamicArray& other);

    T& operator[](std::size_t index);

    void setSize(std::size_t newSize);
    std::size_t getSize() const;

    void clear();

    void push_back(T element);

    void pop_back();
    T back() const;

    void reserve(std::size_t reservedSpace);
    std::size_t getCapacity() const;

    void shrinkToFit();

    bool operator==(const DynamicArray& other) const;
private:
    T* data;
    std::size_t capacity;
    std::size_t size;
};

template<typename T>
DynamicArray<T>::DynamicArray() : data(nullptr), capacity(0), size(0) {}

template<typename T>
DynamicArray<T>::DynamicArray(std::size_t size) 
    : capacity(size), size(size) 
{
    data = new T[size];
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& other) 
    : data(nullptr), capacity(other.capacity), size(other.size) 
{
    data = new T[capacity];
    std::copy(other.data, other.data + size, data);
}

template<typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] data;
}

template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& other) {
    if (this != &other) {
        delete[] data;
        capacity = other.capacity;
        size = other.size;
        data = new T[capacity];
        std::copy(other.data, other.data + size, data);
    }
    return *this;
}

template<typename T>
T& DynamicArray<T>::operator[](std::size_t index) {
    if (index > size) {
        throw std::out_of_range("Index out of bounds in operator[]");
    }

    return data[index];
}

template<typename T>
void DynamicArray<T>::setSize(std::size_t newSize) {
    T* newData = new T[newSize];
    std::size_t minSize = std::min(size, newSize);
    std::copy(data, data + minSize, newData);
    delete[] data;
    data = newData;
    capacity = newSize;
    size = minSize;
}

template<typename T>
std::size_t DynamicArray<T>::getSize() const {
    return size;
}

template<typename T>
void DynamicArray<T>::clear() {
    delete[] data;
    data = nullptr;
    capacity = 0;
    size = 0;
}

template<typename T>
void DynamicArray<T>::push_back(T element) {
    if (size >= capacity) {
        std::size_t newCapacity = (capacity == 0) ? 1 : capacity * 2;
        reserve(newCapacity);
    }
    data[size++] = element;
}

template<typename T>
void DynamicArray<T>::pop_back() {
    if (size > 0) {
        --size;
    }
}

template<typename T>
T DynamicArray<T>::back() const {
    if (size > 0) {
        return data[size - 1];
    } else {
        throw std::out_of_range("Empty array");
    }
}

template<typename T>
void DynamicArray<T>::reserve(std::size_t reservedSpace) {
    if (reservedSpace > capacity) {
        T* newData = new T[reservedSpace];
        std::copy(data, data + size, newData);
        delete[] data;
        data = newData;
        capacity = reservedSpace;
    }
}

template<typename T>
std::size_t DynamicArray<T>::getCapacity() const {
    return capacity;
}

template<typename T>
void DynamicArray<T>::shrinkToFit() {
    if (size < capacity) {
        T* newData = new T[size];
        std::copy(data, data + size, newData);
        delete[] data;
        data = newData;
        capacity = size;
    }
}

template<typename T>
bool DynamicArray<T>::operator==(const DynamicArray<T>& other) const {
    if (size != other.size) {
        return false;
    }
    for (std::size_t i = 0; i < size; ++i) {
        if (data[i] != other.data[i]) {
            return false;
        }
    }
    return true;
}