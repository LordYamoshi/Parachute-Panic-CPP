#include <SFML/Graphics.hpp>

int main()
{
<<<<<<< HEAD
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
    sf::CircleShape shape(100.f);
=======
    sf::RenderWindow window(sf::VideoMode(200, 200), "Parachute Panic C++");
    sf::CircleShape shape(50.f);
>>>>>>> origin/main
    shape.setFillColor(sf::Color::Green);
    shape.setOrigin({ 50.f, 50.f });

    sf::View view = window.getDefaultView();



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

=======
        shape.setOrigin(shape.getRadius(), shape.getRadius()); // Set origin to the center of the circle
        shape.setPosition(window.getSize().x / 2.f, window.getSize().y / 2.f); // Center the circle in the window
>>>>>>> origin/main

        window.clear();
        window.draw(shape);
        window.display();


    }

    return 0;
}