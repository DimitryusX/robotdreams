#pragma once
#include <iostream>
#include <vector>
#include "Player.h"

class Team {
private:
    std::string m_teamName;
    int m_numberOfMembers;
    std::vector<Player*> m_listOfPlayers;

public:
    Team(const std::string& name, int members);

    bool addPlayer(Player* player);

    bool removePlayer(Player* player);

    void displayTeamInfo();
};