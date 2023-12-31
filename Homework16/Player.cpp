#include "Player.h"
#include "Weapon.h"

Player::Player() 
    : m_name("Guest") {};

Player::Player(const std::string& playerName, int initialPlayerHealth, PlayerClass initialPlayerClass, Weapon* initialPlayerWeapon)
    : m_name(playerName), 
    m_health(initialPlayerHealth), 
    m_playerClass(initialPlayerClass), 
    m_weapon(initialPlayerWeapon) {};

void Player::displayPlayerInfo() {
    std::cout << "Player: " << m_name << std::endl;
    std::cout << "Health: " << m_health << std::endl;
    std::cout << "Class: ";

    switch (m_playerClass) {
    case ASSAULT:
        std::cout << "Assault";
        break;
    case SUPPORT:
        std::cout << "Support";
        break;
    case SNIPER:
        std::cout << "Sniper";
        break;
    case MEDIC:
        std::cout << "Medic";
        break;
    default:
        std::cout << "Unknown";
        break;
    }

    std::cout << std::endl;

    if (m_weapon) {
        std::cout << "Weapon Info:" << std::endl;
        m_weapon->displayWeaponInfo();
    }
    else {
        std::cout << "No weapon equipped" << std::endl;
    }

    std::cout << std::endl;
}

void Player::setWeapon(Weapon* playerWeapon) {
    m_weapon = playerWeapon;
}

Weapon* Player::getWeapon() {
    return m_weapon;
}