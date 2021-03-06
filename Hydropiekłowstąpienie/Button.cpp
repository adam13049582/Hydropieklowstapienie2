#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>


bool isSpriteHover(sf::FloatRect sprite, sf::Vector2f mp)
{
    if (sprite.contains(mp)) {
        return true;
    }
    return false;
}


int main()
{

    sf::RenderWindow window, window2, window3;
    window.create(sf::VideoMode(800, 600), "My first Visual Studio window!");

    sf::Texture texture;
    if (!texture.loadFromFile("button1.png"))
    {
        return 1;
    }
    sf::Sprite sprite;
    sprite.setTexture(texture);

    sf::Vector2f mp;
    mp.x = sf::Mouse::getPosition(window).x;
    mp.y = sf::Mouse::getPosition(window).y;



    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (isSpriteHover) //this should check if the bool is true right?
            {
                if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Right)
                {
                    sf::Window window;
                    window.create(sf::VideoMode(400, 200), "The button worked!");
                }

            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))
            {
                window2.create(sf::VideoMode(400, 200), "Another window!");
                while (window2.isOpen())
                {
                    sf::Event event;
                    while (window2.pollEvent(event))
                    {
                        if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
                        {
                            window2.close();
                        }
                    }
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
            {
                window3.create(sf::VideoMode(500, 300), "The third window!");
                while (window3.isOpen())
                {
                    sf::Event event;

                    while (window3.pollEvent(event))
                        if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
                        {
                            window3.close();
                        }
                }
            }

        }




        window.clear(sf::Color::Black);

        sprite.setPosition(sf::Vector2f(50, 300));

        window.draw(sprite);

        window.display();

    }

    return 0;
}