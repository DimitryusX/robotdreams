#pragma once
#include "Utils.h"
#include <ctime>
#include <random>

std::string toLowerCase(const std::string& input)
{
    std::string result = input;

    for (char& c : result) {
        c = std::tolower(c);
    }

    return result;
}

int randomNumberGenerator(const int min, const int max)
{
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uniDist(min, max);

    return uniDist(rng);
}

void compare(const char* first, const char* second, char* hidden, Complexity mode)   
{
    size_t firstCharArraySize = strlen(first);

    for (int i = 0; i < firstCharArraySize; i++)
    {
        char pointer = first[i];

        size_t secondCharArraySize = strlen(second);

        if (second[i] == pointer) {
            hidden[i] = std::toupper(pointer);
            continue;
        }

        for (int j = 0; j < secondCharArraySize; j++) {
            if (second[j] == pointer) {
                hidden[i] = (j == i) ? std::toupper(pointer) : pointer;
                break;
            }

            if (mode == Complexity::HARD) {
                hidden[i] = '*';
            }
        }
    }
}