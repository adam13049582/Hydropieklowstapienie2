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

/// <summary>
/// Metoda tworz¹ca okno menu
/// </summary>
void MainMenu::createWindow(bool playMusic, int width, int height) {
    sf::RenderWindow window(sf::VideoMode(width, height), "Hydropieklowstapienie", sf::Style::Default);

    sf::Texture background;
    sf::Sprite backgroundImage;
    sf::Font font;
    if (!background.loadFromFile("images/woda_morska.jpg"))
        std::cout << "Error: Could not display Menu_g³ówne image" << std::endl;

    backgroundImage.setTexture(background);
    backgroundImage.setScale(
        window.getSize().x / backgroundImage.getLocalBounds().width,
        window.getSize().y / backgroundImage.getLocalBounds().height);

    if (!font.loadFromFile("fonts/impact.ttf"))
    {
        cout << "Couldn't load fonts impact" << endl;
    }

    sf::Text textStart;
    textStart.setFont(font);
    textStart.setString("START");
    textStart.setPosition((window.getSize().x / 2) - 50, window.getSize().y / 5);
    textStart.setCharacterSize(40);
    textStart.setFillColor(sf::Color(66, 58, 19));

    sf::Text textSettings;
    textSettings.setFont(font);
    textSettings.setString("USTAWIENIA");
    textSettings.setPosition((window.getSize().x / 2) - 85, window.getSize().y / 3);
    textSettings.setCharacterSize(40); 
    textSettings.setFillColor(sf::Color(66, 58, 19));

    sf::Text textExit;
    textExit.setFont(font);
    textExit.setString("KONIEC");
    textExit.setPosition((window.getSize().x / 2) - 60, window.getSize().y * 0.5);
    textExit.setCharacterSize(40); 
    textExit.setFillColor(sf::Color(66, 58, 19));

    sf::Texture newGameButton;
    sf::Sprite newGameButtonImage;
    if (!newGameButton.loadFromFile("images/button.png"))
        std::cout << "Can't find the button image" << std::endl;
    newGameButtonImage.setPosition((window.getSize().x / 2) - 50, window.getSize().y / 5);
    newGameButtonImage.setScale(1.0f, 1.3f);
    newGameButtonImage.setTexture(newGameButton);


    sf::Texture settingsButton;
    sf::Sprite settingsButtonImage;
    if (!settingsButton.loadFromFile("images/button.png"))
        std::cout << "Can't find the button image" << std::endl;
    settingsButtonImage.setPosition((window.getSize().x / 2) - 85, window.getSize().y / 3);
    settingsButtonImage.setTexture(settingsButton);
    settingsButtonImage.setScale(2.0f, 1.2f);

    sf::Texture exitButton;
    sf::Sprite exitButtonImage;
    if (!exitButton.loadFromFile("images/button.png"))
        std::cout << "Can't find the button image" << std::endl;
    exitButtonImage.setPosition((window.getSize().x / 2) - 60, window.getSize().y * 0.5);
    exitButtonImage.setScale(1.0f, 1.3f);
    exitButtonImage.setTexture(exitButton);

    window.clear();

    window.draw(backgroundImage);
    window.draw(newGameButtonImage);
    window.draw(settingsButtonImage);
    window.draw(exitButtonImage);
    window.draw(textStart);
    window.draw(textSettings);
    window.draw(textExit);
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
                    GameController* game=new GameController();
                    window.close();
                    game->createWindow(playMusic,width,height);               
               }
                else if (settingsButtonImage.getGlobalBounds().contains(mousePosF))
                {
                    WindowCreator* settings=new Settings();
                    window.close();
                    settings->createWindow(false, width, height);
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

/// <summary>
/// Metoda ustawiaj¹ca szerokoœæ okna
/// </summary>
/// <param name="_i"> wartoœæ jak¹ trzeba przypisaæ do parametru width</param>
void MainMenu::setWidth(int _i)
{
    width = _i;
}
/// <summary>
/// Metoda ustawiaj¹ca szerokoœæ okna
/// </summary>
/// <param name="_i"> wartoœæ jak¹ trzeba przypisaæ do parametru height</param>
void MainMenu::setHeight(int _i)
{
    height = _i;
}
/// <summary>
/// Metoda pobieraj¹ca szerokoœæ okna
/// </summary>
/// <param name="_i"> wartoœæ jak¹ trzeba przypisaæ do parametru width</param>
int MainMenu::getWidth()
{
    return width;
}

/// <summary>
/// Metoda pobieraj¹ca wysokoœæ okna
/// </summary>
/// <param name="_i"> wartoœæ jak¹ trzeba przypisaæ do parametru width</param>
int MainMenu::getHeight()
{
    return height;
}
/// <summary>
/// Metoda ustawiaj¹ca parametr, czy odtwarzaæ muzykê
/// </summary>
/// <param name="_i"> wartoœæ jak¹ trzeba przypisaæ do parametru playMusic</param>
void MainMenu::setPlayMusic(bool _i)
{
    playMusic = _i;
}
/// <summary>
/// Metoda ustawiaj¹ca pobieraj¹ca wartoœæ z pola playMusic
/// <returns>wartoœæ pola playMusic</returns>
/// </summary>
bool MainMenu::getPlayMusic()
{
    return playMusic;
}

