#pragma once
#include <iostream>
#include <sstream>
#include "File.h"

unsigned int fileLineCounter(std::ifstream& file)
{
    std::string line;
    unsigned int i = 0;

    while (std::getline(file, line)) {
        if (line == "") continue;
        i++;
    }

    return i;
}

void getListOfWordsFromFile(std::ifstream& file, std::string list[])
{
    std::string line;
    size_t i = 0;

    while (std::getline(file, line)) {
        if (line == "") continue;
        list[i] += line;
        i++;
    }
}

void parseLine(const std::string& line, std::string& word, bool& boolean)
{
    std::istringstream iss(line);

    if (!(std::getline(iss, word, ':') >> std::boolalpha >> boolean)) {
        std::cerr << "Error parsing line: " << line << std::endl;
        exit(0);
    }
}

void storeListOfWordsToFile(const std::string& filename, const std::string list[], const int listOfWordsSize)
{
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening file for writing." << std::endl;
        return;
    }

    for (int i = 0; i < listOfWordsSize; i++) {
        file << list[i] << std::endl;
    }

    file.close();
}