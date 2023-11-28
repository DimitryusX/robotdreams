#include <iostream>

enum class Menu {
    START = 's',
    EXIT = 'q',
    RESTART = 'r'
};

int main()
{
    std::cout << "Welcome to Game of number's (Homework 7)" << std::endl;

    std::cout << "In this game you need to guess the number that the computer guessed (from 0 to 50)." << std::endl;

    char start;
    Menu navigation = Menu::EXIT;
    int userNumber = 0;
    unsigned int globalGameCount = 0;
    unsigned int globalTriesCount = 0;
    unsigned int highscore = 0;

    do {
        if (navigation != Menu::RESTART) {
            std::cout << "Enter 's' for start or 'q' for exit!" << std::endl;
            std::cin >> start;
            navigation = static_cast<Menu>(start);
        }
        else {
            navigation = Menu::START;
        }

        if (navigation == Menu::START) {
            globalGameCount++;

            std::cout << std::endl;
            std::cout << "Let's start ... enter -1 for exit from game!" << std::endl;
            std::cout << "Generating number ..." << std::endl << std::endl;

            std::srand(std::time(nullptr));
            const int range = 50;
            int randomNumber = std::rand() % (range + 1);
            unsigned int tries = 0;

            while (navigation != Menu::RESTART && navigation != Menu::EXIT) {

                std::cout << "Make your guess: ";
                std::cin >> userNumber;

                if (userNumber == -1) {
                    navigation = Menu::EXIT;
                    break;
                }

                if (userNumber < 0 || userNumber > 50) {
                    std::cout << "Wow, wow, easy there, turbo ... remember, range 0-50, try again!" << std::endl;
                    continue;
                }

                tries++;

                int difference = userNumber - randomNumber;

                if (difference == 0) {

                    globalTriesCount += tries;
                    
                    if (highscore == 0 || highscore > tries) {
                        highscore = tries;
                    }
                    
                    std::cout << "Congratulations! ";
                        
                    if (tries > 1) {
                        std::cout << "You won, and for this you needed " << tries << " attempts!";
                    }
                    else {
                        std::cout << "You won, and for this you needed only one attempt!";
                    }

                    std::cout << std::endl << std::endl;

                    do {
                        std::cout << "Play again ?" << std::endl;
                        std::cout << "Enter 'r' for start or 'q' for exit !" << std::endl;
                        std::cin >> start;
                        navigation = static_cast<Menu>(start);
                    } while (navigation != Menu::RESTART && navigation != Menu::EXIT);

                } 
                else if (difference > 0 && difference > 20) 
                {
                    std::cout << "Too much, +20, try again ..." << std::endl;
                }
                else if (difference > 0 && difference > 10) 
                {
                    std::cout << "Too much, +10, try again ..." << std::endl;
                } 
                else if (difference > 0)
                {
                    std::cout << "Too much, try again ..." << std::endl;
                }
                else if(difference < 0 && difference < -20) 
                {
                    std::cout << "Too less, -20, try again ..." << std::endl;
                }
                else if (difference < 0 && difference < -10) 
                {
                    std::cout << "Too less, -10, try again ..." << std::endl;
                }
                else if (difference < 0)
                {
                    std::cout << "Too less, try again ..." << std::endl;
                }
            }
        }

    } while (navigation != Menu::EXIT);

    if (globalGameCount > 0 && globalTriesCount > 0) {
        std::cout << "*******************" << std::endl;
        std::cout << "Game count: " << globalGameCount << std::endl;
        std::cout << "Tries count: " << globalTriesCount << std::endl;
        std::cout << "Your highscore: " << highscore << " tries!" << std::endl;
        std::cout << "Your score: " << (static_cast<double>(globalGameCount) / static_cast<double>(globalTriesCount) * 100) << '%' << std::endl;
        std::cout << "*******************" << std::endl << std::endl;
    }

    std::cout << "Bye ..." << std::endl;
}
