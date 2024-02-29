#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");

    sf::CircleShape shape(100.f);
    sf::RectangleShape shape2(sf::Vector2f(50, 45));
    sf::RectangleShape shape3(sf::Vector2f(40, 60));

    shape.setFillColor(sf::Color::Red);
    shape2.setFillColor(sf::Color::Cyan);
    shape3.setFillColor(sf::Color::Yellow);

    shape2.setPosition(sf::Vector2f(40, 60));
    shape3.setPosition(sf::Vector2f(100, 100));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        window.draw(shape);
        window.draw(shape2);
        window.draw(shape3);

        window.display();
    }

    return 0;
}