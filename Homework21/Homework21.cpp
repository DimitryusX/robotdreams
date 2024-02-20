#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool compareByLength(const std::string& a, const std::string& b) {
    return a.length() < b.length();
}

class LengthComparator {
public:
    bool operator()(const std::string& a, const std::string& b) const {
        return a.length() < b.length();
    }
};

int countDivisibleBy(const std::vector<int>& data, int number) {
    return std::count_if(data.begin(), data.end(), [number](int x) {
        return x % number == 0;
    });
}

int main()
{
    std::cout << "Homework 21" << std::endl;

    std::vector<std::string> array1 = { "BMW", "Tesla", "Audi", "Gilly" };

    std::sort(array1.begin(), array1.end(), compareByLength);
    std::cout << "Sorted by function:" << std::endl;
    for (const auto& str : array1) {
        std::cout << str << std::endl;
    }
    std::cout << std::endl;

    std::sort(array1.begin(), array1.end(), LengthComparator());
    std::cout << "Sorted by functor:" << std::endl;
    for (const auto& str : array1) {
        std::cout << str << std::endl;
    }
    std::cout << std::endl;

    std::sort(array1.begin(), array1.end(), [](const std::string& a, const std::string& b) {
        return a.length() < b.length();
    });

    std::cout << "Sorted by lambda:" << std::endl;
    for (const auto& str : array1) {
        std::cout << str << std::endl;
    }
    std::cout << std::endl;

    std::vector<int> numberList = { 12, 34, 23, 1, 23, 93, 21, 76, 63, 28 };

    int number = 3;
    int count = countDivisibleBy(numberList, number);

    std::cout << "Number of elements divisible by " << number << ": " << count << std::endl;
}
