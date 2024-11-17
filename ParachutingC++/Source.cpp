#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "Parachute Panic C++");
    sf::CircleShape shape(50.f);
    shape.setFillColor(sf::Color::Green);



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                 window.close();

        }

        shape.setOrigin(shape.getRadius(), shape.getRadius()); // Set origin to the center of the circle
        shape.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f); // Center the circle in the window

        window.clear();
        window.draw(shape);
        window.display();


    }

    return 0;
}