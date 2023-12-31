#include "Weapon.h"

Weapon::Weapon() : m_name("Unknown"), m_damage(0), m_range(0) {};
Weapon::Weapon(const std::string& weaponName, int weaponDamage, int weaponRange)
    : m_name(weaponName), m_damage(weaponDamage), m_range(weaponRange) {};

void Weapon::displayWeaponInfo() {
    std::cout << "Weapon: " << m_name << std::endl;
    std::cout << "Damage: " << m_damage << std::endl;
    std::cout << "Range: " << m_range << std::endl;
}