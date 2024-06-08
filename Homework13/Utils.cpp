#include "Utils.h"
#include <ctime>
#include <random>

void toLowerCase(std::string& input)
{
    for (char& c : input) {
        c = std::tolower(c);
    }
}

int randomNumberGenerator(int min, int max)
{
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uniDist(min, max);

    return uniDist(rng);
}

void compare(std::string& first, std::string& second, char* hidden, Complexity mode)
{
    size_t firstCharArraySize = first.size();
    size_t secondCharArraySize = second.size();

    if (mode == Complexity::HARD) {
        std::memset(hidden, '*', firstCharArraySize);
    }

    for (int i = 0; i < firstCharArraySize; i++)
    {
        char searchWordChar = first[i];

        if (second[i] == first[i]) {
            hidden[i] = std::toupper(first[i]);
            second[i] = '*';
        }
    }

    for (int i = 0; i < firstCharArraySize; i++)
    {
        char searchWordChar = first[i];

        if (hidden[i] != '*') {
            continue;
        }

        for (int j = 0; j < secondCharArraySize; j++) {

            if (second[j] == searchWordChar) {
                hidden[i] = searchWordChar;
                second[j] = '*';
                break;
            }
        }
    }
}