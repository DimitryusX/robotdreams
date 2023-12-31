#pragma once
#include <iostream>
#include "Weapon.h"

enum PlayerClass {
    ASSAULT,
    SUPPORT,
    SNIPER,
    MEDIC
};

class Player {
private:
    std::string m_name;
    int m_health = 100;
    PlayerClass m_playerClass = ASSAULT;
    Weapon* m_weapon = nullptr;

public:
    Player();
    Player(const std::string& playerName, int initialPlayerHealth, PlayerClass initialPlayerClass, Weapon* initialPlayerWeapon);
    
    void displayPlayerInfo();

    void setWeapon(Weapon* playerWeapon);
    Weapon* getWeapon();
};