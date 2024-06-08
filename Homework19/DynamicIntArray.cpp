#include "DynamicIntArray.h"
#include <algorithm>
#include "iostream"

DynamicIntArray::DynamicIntArray() : data(nullptr), total(0), size(0) {}

DynamicIntArray::DynamicIntArray(std::size_t size) 
    : total(size), size(size) 
{
	data = new int[size];
}

DynamicIntArray::DynamicIntArray(const DynamicIntArray& other) 
    : data(nullptr), total(other.total), size(other.size) 
{
	data = new int[total];
	std::copy(other.data, other.data + size, data);
}

DynamicIntArray::~DynamicIntArray() 
{
	delete[] data;
}

DynamicIntArray& DynamicIntArray::operator=(const DynamicIntArray& other) 
{
    if (this != &other) {
        delete[] data;
        total = other.total;
        size = other.size;
        data = new int[total];
        std::copy(other.data, other.data + size, data);
    }
    return *this;
}

int& DynamicIntArray::operator[](std::size_t index) 
{
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }

    return data[index];
}

void DynamicIntArray::setSize(std::size_t newSize) 
{
    int* newData = new int[newSize];
    std::size_t minSize = std::min(size, newSize);
    std::copy(data, data + minSize, newData);
    delete[] data;
    data = newData;
    total = newSize;
    size = minSize;
}

std::size_t DynamicIntArray::getSize() const 
{
    return size;
}

void DynamicIntArray::clear() 
{
    delete[] data;
    data = nullptr;
    total = 0;
    size = 0;
}

void DynamicIntArray::push_back(int element) 
{
    if (size >= total) {
        std::size_t newSize = (total == 0) ? 1 : total * 2;
        setSize(newSize);
    }
    data[size++] = element;
}
