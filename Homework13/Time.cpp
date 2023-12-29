#pragma once
#include "Time.h"

unsigned int getDay()
{
    std::tm bt{};
    std::time_t timer = std::time(nullptr);
    localtime_s(&bt, &timer);
    return bt.tm_mday;
}