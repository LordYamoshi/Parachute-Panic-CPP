#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "Parachute Panic C++");

    sf::CircleShape shape(50.f);
    shape.setFillColor(sf::Color::Green);
    shape.setOrigin(shape.getRadius(), shape.getRadius());
    shape.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::Resized)
            {
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));

                shape.setPosition(event.size.width / 2.f, event.size.height / 2.f);
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}