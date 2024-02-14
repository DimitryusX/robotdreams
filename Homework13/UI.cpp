#pragma once
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