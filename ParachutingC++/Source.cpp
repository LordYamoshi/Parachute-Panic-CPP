#include <SFML/Graphics.hpp>

int main()
{
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
=======
=======
>>>>>>> parent of addcae7 (Not many changes, but it is pretty cool)
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
>>>>>>> parent of addcae7 (Not many changes, but it is pretty cool)
=======
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
>>>>>>> parent of 4359f7d (I didn't really change much)
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
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
        sf::Vector2u windowSize = window.getSize();

        shape.setScale(
            event.size.width / shape.getLocalBounds().width,
            event.size.height / shape.getLocalBounds().height);
        shape.setPosition(windowSize.x / 2, windowSize.y / 2);

=======
>>>>>>> parent of addcae7 (Not many changes, but it is pretty cool)
=======
>>>>>>> parent of 4359f7d (I didn't really change much)
=======
>>>>>>> parent of addcae7 (Not many changes, but it is pretty cool)
        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}