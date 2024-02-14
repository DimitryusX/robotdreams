#include <iostream>
#include <vector>
#include "Weapon.h"
#include "Player.h"
#include "Team.h"
#include "Rectangle.h"

int main()
{
    Rectangle rectangle1;
    Rectangle rectangle2(8.0f, 5.0f);

    std::cout << "Rectangle 1 Area: " << rectangle1.getArea() << std::endl;
    std::cout << "Rectangle 1 Perimeter: " << rectangle1.getPerimeter() << std::endl;

    std::cout << "Rectangle 2 Area: " << rectangle2.getArea() << std::endl;
    std::cout << "Rectangle 2 Perimeter: " << rectangle2.getPerimeter() << std::endl;

    std::cout << std::endl;

    Weapon m16("M16", 25, 250);
    Weapon machete("Machete", 50, 20);
    Weapon knife("Knife", 30, 10);
    Weapon m38("M38 DMR", 100, 500);

    Player player1("Mike", 90, PlayerClass::ASSAULT, &machete);
    Player player2("Helen", 85, PlayerClass::SUPPORT, &m16);
    Player player3("Jo", 85, PlayerClass::ASSAULT, &knife);
    Player player4("Ivan", 85, PlayerClass::SNIPER, &m38);

    Team redTeam("Red Team", 4);
    redTeam.addPlayer(&player1);
    redTeam.addPlayer(&player2);

    Team blueTeam("Blue Team", 4);
    blueTeam.addPlayer(&player3);
    blueTeam.addPlayer(&player4);

    redTeam.displayTeamInfo();

    std::cout << std::endl;

    blueTeam.displayTeamInfo();

    std::cout << std::endl;
}