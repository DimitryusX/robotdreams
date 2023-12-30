#pragma once
#include <fstream>

unsigned int fileLineCounter(std::ifstream& file);
void getListOfWordsFromFile(std::ifstream& file, std::string list[]);
void parseLine(const std::string& line, std::string& word, bool& boolean);
void storeListOfWordsToFile(const std::string& filename, const std::string list[], const int listOfWordsSize);