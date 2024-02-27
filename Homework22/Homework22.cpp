#include <iostream>
#include "DymanicArray.h"

int main()
{
    DynamicArray<int> container;
    container.reserve(3);

    std::cout << "DynamicArray array1 capacity size: " << container.getCapacity() << std::endl;

    container.push_back(25);
    container.push_back(30);
    container.push_back(10);
    container.push_back(39);
    container.push_back(55);

    std::cout << "DynamicArray array1 capacity size: " << container.getCapacity() << std::endl;

    std::cout << "DynamicArray array1 loop: " << std::endl;

    for (int i = 0; i < container.getSize(); i++) {
        std::cout << container[i] << " ";
    }

    std::cout << std::endl;

    DynamicArray<char> container2;
    container2.reserve(2);

    std::cout << "DynamicArray array2 capacity size: " << container2.getCapacity() << std::endl;

    container2.push_back('b');
    container2.push_back('c');
    container2.push_back('d');
    container2.push_back('e');
    container2.push_back('f');

    std::cout << "DynamicArray array2 capacity size: " << container2.getCapacity() << std::endl;

    std::cout << "DynamicArray array2 loop: " << std::endl;

    for (int i = 0; i < container2.getSize(); i++) {
        std::cout << container2[i] << " ";
    }

    std::cout << std::endl;

    DynamicArray<double> container3;

    std::cout << "DynamicArray array3 capacity size: " << container3.getCapacity() << std::endl;

    container3.push_back(0.1f);
    container3.push_back(1.1f);
    container3.push_back(0.2f);
    container3.push_back(2.1f);
    container3.push_back(0.5f);

    std::cout << "DynamicArray array3 capacity size: " << container3.getCapacity() << std::endl;

    std::cout << "DynamicArray array3 loop: " << std::endl;

    for (int i = 0; i < container3.getSize(); i++) {
        std::cout << container3[i] << " ";
    }

    container3.pop_back();
    container3.pop_back();
    container3.pop_back();

    container3.shrinkToFit();

    std::cout << std::endl;

    std::cout << "DynamicArray array3 capacity size: " << container3.getCapacity() << std::endl;
    std::cout << "DynamicArray array3 real size: " << container3.getSize() << std::endl;

    std::cout << std::endl;
}