#include <iostream>
#include <cmath>

int main()
{
    double size;

    std::cout << "Tree, what size do you want ?" << std::endl;
    std::cout << "Recommendation: 7-17\n";
    std::cin >> size;

    if (size > 25 || size < 5) {
        do {
            std::cout << "No, no, no ... recommendation: 7-17\n";
            std::cin >> size;
        } while (size > 25 || size < 5);
    }

    int rows = ceil(size / 2);
    int cols = size * 2;

    int starLeft = ceil(cols / 2) - 1;
    int starRight = starLeft;

    std::cout << std::endl;

    for (int i = 0; rows > i; i++) {

        for (int j = 0; cols > j; j++) {
            if (starLeft == 0) {
                std::cout << "*";
            }
            else if (starLeft <= j && starRight >= j) {
                std::cout << "*";
            }
            else {
                std::cout << " ";
            }
        }

        starLeft = abs(starLeft - 2);
        starRight = abs(starRight + 2);

        std::cout << std::endl;
    }

    std::string text = "I love C++!";

    if (text.length() < size * 2) {
        int emptyChars = (size * 2 - text.length()) / 2;

        for (int k = 0; emptyChars > k; k++) {
            text = ' ' + text + ' ';
        }
    }

    std::cout << text << std::endl;

    std::cout << std::endl;
}