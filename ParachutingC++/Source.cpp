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

        sf::Vector2u windowSize = window.getSize();

        shape.setScale(
            event.size.width / shape.getLocalBounds().width,
            event.size.height / shape.getLocalBounds().height);
        shape.setPosition(windowSize.x / 2, windowSize.y / 2);

		if (sf::keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		{
			shape.move(-0.1f, 0.0f);
		}


        window.clear();
        window.draw(shape);
        window.display();


    }

    return 0;
}