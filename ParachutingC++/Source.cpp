#include <SFML/Graphics.hpp>

int main()
{
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                 window.close();

        }

<<<<<<< HEAD
        sf::Vector2u windowSize = window.getSize();

        shape.setScale(
            event.size.width / shape.getLocalBounds().width,
            event.size.height / shape.getLocalBounds().height);
        shape.setPosition(windowSize.x / 2, windowSize.y / 2);

        window.clear();
        window.draw(shape);
        window.display();


    }

    return 0;
}