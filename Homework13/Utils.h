#pragma once
#include <string>

enum class Menu {
    START = 's',
    EXIT = 'q',
    MODE = 'm',
    DAY = 'd',
    HELP = 'h',
};

enum class Complexity {
    EASY = 'e',
    HARD = 'h',
};

unsigned int getDay();
std::string toLowerCase(const std::string& input);
int randomNumberGenerator(const int min, const int max);
void compare(const char* first, const char* second, char* hidden, Complexity mode);