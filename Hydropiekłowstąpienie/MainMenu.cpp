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
#include "Settings.h"
#include <thread>

using namespace std;

void MainMenu::createWindowMenu2() {
    sf::RenderWindow window(sf::VideoMode(width, height), "Hydropieklowstapienie", sf::Style::Default);

    sf::Texture background;
    sf::Sprite backgroundImage;

    if (!background.loadFromFile("images/Menu_g³ówne.jpg"))
        std::cout << "Error: Could not display Menu_g³ówne image" << std::endl;

    backgroundImage.setTexture(background);
    backgroundImage.setScale(
        window.getSize().x / backgroundImage.getLocalBounds().width,
        window.getSize().y / backgroundImage.getLocalBounds().height);

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
                    //GameController *game = new GameController();
                    window.close();
                    game.createWindowGame();
                    //thread th1(
                      //  &GameController::createWindowGame,game
                   // );
                   // th1.join();
                    //delete game;                
               }
                else if (settingsButtonImage.getGlobalBounds().contains(mousePosF))
                {
                    Settings settings;
                    //GameController *game = new GameController();
                    window.close();
                    settings.createSettingWindow();
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

void MainMenu::setWidth(int _i)
{
    width = _i;
}

void MainMenu::setHeight(int _i)
{
    height = _i;
}

