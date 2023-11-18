#include <iostream>

int main()
{
    int size;

    std::cout << "Triangle, what size do you want?" << std::endl;
    std::cin >> size;

    int rows = size;
    int cols = rows;

    std::cout << std::endl;

    for (int i = 0; rows > i; i++) {

        for (int j = 0; j <= i; j++) {
            std::cout << "*";
        }

        std::cout << std::endl;
    }

    std::string text = "I love C++!";
    std::cout << text << std::endl;
    std::cout << std::endl;
}