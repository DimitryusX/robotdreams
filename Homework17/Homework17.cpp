#include <iostream>
#include "Vector2d.h"

int Vector2d::count = 0;

int main()
{
    Vector2d v1;
    std::cout << "Vector v1: ";
    v1.print();

    Vector2d v2(3.0f, 4.0f);
    std::cout << "Vector v2: ";
    v2.print();

    v1 = v2;

    std::cout << "Number of active instances: " << Vector2d::getCount() << std::endl;

    std::cout << "Vector v1 after assignment: ";
    v1.print();

    Vector2d v3(4.0f, 7.0f);
    Vector2d v4(2.0f, 4.0f);

    Vector2d v5 = v3 + v4;
    Vector2d v6 = v3 - v4;

    std::cout << "Number of active instances: " << Vector2d::getCount() << std::endl;

    std::cout << "New vector v3 + v4: ";
    v5.print();

    std::cout << "New vector v3 - v4: ";
    v6.print();

    /*
    Vector2d v7(1.0f, 11.0f);
    Vector2d v8(4.0f, 5.0f);

    Vector2d v9 = v7 + v8;
    Vector2d v10 = v7 - v8;

    std::cout << "Friend function v7 + v8: ";
    v9.print();

    std::cout << "Friend function v7 - v8: ";
    v10.print();
    */

    Vector2d v11(3.0f, 4.0f);
    std::cout << "Length of v11: " << v11() << std::endl;

    std::cout << "Number of active instances: " << Vector2d::getCount() << std::endl;

    Vector2d test;
    std::cout << "Enter vector coordinates (x y): ";
    std::cin >> test;
    std::cout << "Vector entered: ";
    test.print();

    std::cout << "Number of active instances: " << Vector2d::getCount() << std::endl;
}