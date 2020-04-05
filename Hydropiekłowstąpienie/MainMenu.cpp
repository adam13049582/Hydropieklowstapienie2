#include <SFML/Graphics.hpp>
#include <time.h>
#include <stdlib.h>
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include <iostream>
#include <SFML/Audio.hpp>
#include <windows.h>
#include <string>
#include "MainMenu.h"
#include "GameController.h"

using namespace std;

void MainMenu::createWindowMenu2() {
    cout << "kurwa";
    sf::RenderWindow window(sf::VideoMode(1024, 622), "Hydropieklowstapienie", sf::Style::Default);

    sf::Texture background;
    sf::Sprite backgroundImage;

    if (!background.loadFromFile("images/Menu_g³ówne.jpg"))
        std::cout << "Error: Could not display Menu_g³ówne image" << std::endl;

    backgroundImage.setTexture(background);
    backgroundImage.setScale(
        window.getSize().x / backgroundImage.getLocalBounds().width,
        window.getSize().y / backgroundImage.getLocalBounds().height);
    /*sf::Font font;
    if (!font.loadFromFile("MATURASC.TTF"))
        std::cout << "Can't find the font file" << std::endl;*/

    sf::Texture newGameButton;
    sf::Sprite newGameButtonImage;
    if (!newGameButton.loadFromFile("images/button.png"))
        std::cout << "Can't find the button image" << std::endl;
    newGameButtonImage.setPosition(440.0f, 140.0f);
    newGameButtonImage.setScale(1.0f, 1.3f);
    newGameButtonImage.setTexture(newGameButton);


    sf::Texture settingsButton;
    sf::Sprite settingsButtonImage;
    if (!settingsButton.loadFromFile("images/button.png"))
        std::cout << "Can't find the button image" << std::endl;
    settingsButtonImage.setPosition(380.0f, 220.0f);
    settingsButtonImage.setTexture(settingsButton);
    settingsButtonImage.setScale(2.6f, 1.3f);

    sf::Texture exitButton;
    sf::Sprite exitButtonImage;
    if (!exitButton.loadFromFile("images/button.png"))
        std::cout << "Can't find the button image" << std::endl;
    exitButtonImage.setPosition(440.0f, 310.0f);
    exitButtonImage.setScale(1.0f, 1.3f);
    exitButtonImage.setTexture(exitButton);
    window.clear();
    window.draw(backgroundImage);
    window.draw(newGameButtonImage);
    window.draw(settingsButtonImage);
    window.draw(exitButtonImage);
    window.display();

    while (window.isOpen())
    {
        sf::Event Event;
        while (window.pollEvent(Event))
        {
            switch (Event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseMoved:
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                if (newGameButtonImage.getGlobalBounds().contains(mousePosF))
                {
                    newGameButtonImage.setColor(sf::Color(250, 20, 20));
                }
                else
                {
                    newGameButtonImage.setColor(sf::Color(255, 255, 255));
                }
            }
            break;
            case sf::Event::MouseButtonPressed:
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                if (newGameButtonImage.getGlobalBounds().contains(mousePosF))
                {
                    GameController game;
                    window.close();
                    game.createWindowGame();
                   /* sf::RenderWindow window2(sf::VideoMode(1024, 622), "Hydropieklowstapienie", sf::Style::Default);
                    backgroundImage.setColor(sf::Color(250, 20, 20));
                    sf::RectangleShape rectangle(sf::Vector2f(120, 50));
                    rectangle.setSize(sf::Vector2f(1024, 100));
                    rectangle.setPosition(0, 622);
                    rectangle.setFillColor(sf::Color(0, 127, 255));

                    sf::RectangleShape rectangle2(sf::Vector2f(120, 50));
                    rectangle2.setSize(sf::Vector2f(1024, 100));
                    rectangle2.setPosition(200, 400);
                    rectangle2.setFillColor(sf::Color(0, 255, 255));

                    window2.clear();
                    window2.draw(backgroundImage);
                    window2.draw(rectangle2);
                    window2.draw(rectangle);
                    window2.display();
                    int height;
                    int scale;
                    while (window2.isOpen())
                    {
                        window.close();
                        if ((rectangle.getPosition().y > rectangle2.getPosition().y) && (rectangle.getPosition().y < (rectangle2.getPosition().y + rectangle2.getSize().y))) {
                            height = rectangle.getPosition().y - 2;
                            scale = 2;
                            std::cout << "Collision!" << std::endl;

                        }
                        else {
                            height = rectangle.getPosition().y - 10;
                            scale = 10;
                        }

                        rectangle.setPosition(0, height);
                        rectangle.scale(1, scale);
                        Sleep(1000);
                        window2.clear();
                        window2.draw(backgroundImage);
                        window2.draw(rectangle2);
                        window2.draw(rectangle);
                        window2.display();
                        std::cout << "Window2!" << std::endl;
                    }*/



                    ////std::cout << "Clicked, Start!" << std::endl;
                }
                else if (settingsButtonImage.getGlobalBounds().contains(mousePosF))
                {
                    std::cout << "Clicked, Settings!" << std::endl;
                }
                else if (exitButtonImage.getGlobalBounds().contains(mousePosF))
                {
                    std::cout << "Clicked, Exit!" << std::endl;
                    window.close();
                }
            }
            break;
            }
        }


    }
}

