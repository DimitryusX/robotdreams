#pragma once
#include <cstdlib>

class DynamicIntArray
{
public:
    // Default constructor
    DynamicIntArray();

    // Constructor with size
    DynamicIntArray(std::size_t size);

    // Copy constructor
    DynamicIntArray(const DynamicIntArray& other);

    // Destructor
    ~DynamicIntArray();

    DynamicIntArray& operator=(const DynamicIntArray& other);

    int& operator[](std::size_t index);

    void setSize(std::size_t newSize);
    std::size_t getSize() const;

    void clear();

    void push_back(int element);

private:
    int* data;
    std::size_t total;
    std::size_t size;
};