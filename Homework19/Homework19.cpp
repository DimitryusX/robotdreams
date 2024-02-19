#include <iostream>
#include "DynamicIntArray.h"

int main()
{
    std::cout << "Homework #19" << std::endl;

    DynamicIntArray array1{};

    array1.push_back(10);
    array1.push_back(11);
    array1.push_back(12);

    std::cout << "DynamicIntArray array1 loop: " << std::endl;

    for (int i = 0; i < array1.getSize(); i++) {
        std::cout << array1[i] << " ";
    }

    std::cout << std::endl;

    array1.push_back(13);
    array1.push_back(14);
    array1.push_back(15);

    std::cout << "DynamicIntArray array1 loop: " << std::endl;

    for (int i = 0; i < array1.getSize(); i++) {
        std::cout << array1[i] << " ";
    }

    std::cout << std::endl;

    array1.setSize(4);

    std::cout << "DynamicIntArray array1 loop: " << std::endl;

    for (int i = 0; i < array1.getSize(); i++) {
        std::cout << array1[i] << " ";
    }

    std::cout << std::endl;

    DynamicIntArray array2{};

    array2 = array1;

    std::cout << "DynamicIntArray array2 loop: " << std::endl;

    for (int i = 0; i < array2.getSize(); i++) {
        std::cout << array2[i] << " ";
    }

    std::cout << std::endl;

    array2.clear();
    array2.push_back(16);
    array2.push_back(17);

    std::cout << "DynamicIntArray array2 loop: " << std::endl;

    for (int i = 0; i < array2.getSize(); i++) {
        std::cout << array2[i] << " ";
    }

    std::cout << std::endl;
}
