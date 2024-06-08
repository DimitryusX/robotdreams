#include "UI.h"

std::string getModelLevelText(Complexity mode)
{
    switch (mode)
    {
        case Complexity::EASY:
            return "easy";
            break;

        case Complexity::HARD:
            return "hard";
            break;

        default:
            return "fail";
            break;
    }
}

void getMenuHelp()
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

void getHighScoreInfo(const unsigned int highscore)
{
    std::cout << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << "Your highscore: " << highscore << " tries!" << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << std::endl;
}