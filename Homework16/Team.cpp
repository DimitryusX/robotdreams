#include "Team.h"

Team::Team(const std::string& name, int members) 
    : m_teamName(name), m_numberOfMembers(members) {};

bool Team::addPlayer(Player* player) {
    if (m_listOfPlayers.size() < static_cast<size_t>(m_numberOfMembers)) {
        m_listOfPlayers.push_back(player);
        return true;
    }
    else {
        std::cout << "Team is full." << std::endl;
        return false;
    }
}

bool Team::removePlayer(Player* player) {
    auto it = std::find(m_listOfPlayers.begin(), m_listOfPlayers.end(), player);
    if (it != m_listOfPlayers.end()) {
        m_listOfPlayers.erase(it);
        return true;
    }
    else {
        std::cout << "Player not found in the team." << std::endl;
        return false;
    }
}

void Team::displayTeamInfo() {
    std::cout << "Team: " << m_teamName << std::endl;
    std::cout << "Number of Members: " << m_numberOfMembers << std::endl;

    std::cout << "Players:" << std::endl;
    for (const auto& player : m_listOfPlayers) {
        player->displayPlayerInfo();
        std::cout << "------------------------" << std::endl;
    }
};