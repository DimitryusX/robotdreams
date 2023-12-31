#pragma once
#include <iostream>

class Weapon {
private:
    std::string m_name;
    int m_damage;
    int m_range;

public:
    Weapon();
    Weapon(const std::string& weaponName, int weaponDamage, int weaponRange);

    void displayWeaponInfo();
};