#include <iostream>
#include <fstream>
#include "File.h"
#include "Utils.h"
#include "Time.h"
#include "UI.h"

const size_t MAX_LINE_SIZE = 32;
const size_t MAX_WORD_ARRAY_SIZE = 64;
unsigned int highscore = INT_MAX;

int main()
{
    std::string filename = "library.txt";
    std::ifstream file;

    file.open(filename, std::ios::in);

    // Try open file
    while (!file.is_open()) {
        std::cerr << "File can't open" << std::endl;
        std::cout << "Enter path to file: ";
        std::cin >> filename;

        file.open(filename, std::ios::in);
    }

    // Get line count (array size)
    const unsigned int listOfWordsSize = fileLineCounter(file);

    // Exit if we don't have words
    if (listOfWordsSize == 0) {
        std::cerr << "Empty library!" << std::endl;
        exit(0);
    }

    // Reset file cursor
    file.clear();
    file.seekg(0);

    // Store list of words to array
    std::string listOfWords[MAX_WORD_ARRAY_SIZE];
    getListOfWordsFromFile(file, listOfWords);

    file.close();

    char inputMenuChar;
    Complexity mode = Complexity::EASY;
    Menu navigation = Menu::EXIT;

    std::cout << "Welcome to 'WORD' game!" << std::endl;
    std::cout << "Your current mode level: " << getModelLevelText(mode) << std::endl;

    do {
        std::cout << "Enter 's' (random word) for start, 'q' for exit or 'h' for help: ";

        do {
            std::cin >> inputMenuChar;
            navigation = static_cast<Menu>(inputMenuChar);

            if (navigation == Menu::START
                || navigation == Menu::HELP
                || navigation == Menu::EXIT
                || navigation == Menu::MODE
                || navigation == Menu::DAY
                ) {
                break;
            }

            std::cout << "Incorrect input value, try again: ";
        } while (true);

        if (navigation == Menu::START || navigation == Menu::DAY) {

            int randomNumber = 0;
            std::string searchWord;
            bool isCompleted;

            if (navigation == Menu::DAY) {
                
                randomNumber = getDay();

                parseLine(listOfWords[randomNumber], searchWord, isCompleted);

                if (isCompleted)
                {
                    std::cout << "Word of day is completed, please, wait next day!" << std::endl;
                    continue;
                }
            }
            else {
                // Get random number for set searchable word
                randomNumber = randomNumberGenerator(0, listOfWordsSize - 1);
                parseLine(listOfWords[randomNumber], searchWord, isCompleted);
            }

            searchWord = toLowerCase(searchWord);

            // Create hidden word
            char* hiddenWord = new char[searchWord.size() + 1];
            std::memset(hiddenWord, '*', searchWord.size());
            hiddenWord[searchWord.size()] = '\0';

            std::string inputWord;
            unsigned int tries = 0;

            std::cout << std::endl;

            do {
                std::cout << "Result : " << hiddenWord << std::endl;

                do {
                    std::cout << "Enter  : ";
                    std::cin >> inputWord;

                    inputWord = toLowerCase(inputWord);

                    if (inputWord.size() == searchWord.size()) {
                        break;
                    }

                    std::cout << "Word has length " << searchWord.size() << ", please, try again." << std::endl;
                } while (true);

                std::cout << std::endl;

                tries++;

                if (searchWord == inputWord) {
                    std::cout << "That's right!" << std::endl;
                    std::cout << "You made " << tries << " tries." << std::endl;

                    if (tries < highscore) {
                        highscore = tries;
                    }

                    if (navigation == Menu::DAY) {
                        // Put result to file
                        listOfWords[randomNumber] = searchWord + ":true";
                        storeListOfWordsToFile(filename, listOfWords, listOfWordsSize);
                    }

                    break;
                }

                compare(inputWord, searchWord, hiddenWord, mode);
            } while (true);

            std::cout << std::endl;
        }

        if (navigation == Menu::MODE) {
            std::cout << std::endl;
            std::cout << "Your current mode level: " << getModelLevelText(mode) << std::endl;
            std::cout << "Enter 'e' (easy) or 'h' (hard) for change complexity level: ";

            do {
                std::cin >> inputMenuChar;
                mode = static_cast<Complexity>(inputMenuChar);

                if (mode == Complexity::EASY || mode == Complexity::HARD) {
                    break;
                }

                std::cout << std::endl << "Incorrect input value, try again: ";
            } while (true);

            std::cout << "Now your mode level: " << getModelLevelText(mode) << std::endl;
            std::cout << std::endl;
        }

        if (navigation == Menu::HELP)
        {
            std::cout << std::endl;
            std::cout << "==================================" << std::endl;
            std::cout << "| 's' - start new game           |" << std::endl;
            std::cout << "| 'm' - change mode level        |" << std::endl;
            std::cout << "| 'd' - start play 'word of day' |" << std::endl;
            std::cout << "| 'q' - exit                     |" << std::endl;
            std::cout << "==================================" << std::endl;
            std::cout << std::endl;
        }

    } while (navigation != Menu::EXIT);

    if (highscore != INT_MAX) {
        std::cout << std::endl;
        std::cout << "====================================" << std::endl;
        std::cout << "Your highscore: " << highscore << " tries!" << std::endl;
        std::cout << "====================================" << std::endl;
        std::cout << std::endl;
    }

    std::cout << "Bye ... " << std::endl;
}