#include "Settings.h"
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include <SFML/Graphics.hpp>
#include "MainMenu.h"
#include "GameController.h"

/// <summary>
/// Metoda tworz¹ca okno ustawieñ
/// </summary>
void Settings::createSettingWindow()
{
    sf::RenderWindow settingsWindow(sf::VideoMode(width, height), "Hydropieklowstapienie", sf::Style::Default);

    sf::Texture background;
    sf::Sprite backgroundImage; sf::Font font;

    if (!background.loadFromFile("images/woda_morska.jpg"))
        std::cout << "Error: Could not display Menu_g³ówne image" << std::endl;

    backgroundImage.setTexture(background);
    backgroundImage.setScale(
        settingsWindow.getSize().x / backgroundImage.getLocalBounds().width,
        settingsWindow.getSize().y / backgroundImage.getLocalBounds().height);

    if (!font.loadFromFile("fonts/impact.ttf"))
    {
        cout << "Couldn't load fonts impact" << endl;
    }
    sf::Text text;
    text.setFont(font);
    text.setString("Rozdzielczosc");
    text.setPosition((settingsWindow.getSize().x/2)-50, settingsWindow.getSize().y/5);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color(66,58,19));

    sf::Text textSmallResolution;
    textSmallResolution.setFont(font);
    textSmallResolution.setString("1024 X 622");
    textSmallResolution.setPosition((settingsWindow.getSize().x / 2) - 150, settingsWindow.getSize().y / 3);
    textSmallResolution.setCharacterSize(26); 
    textSmallResolution.setFillColor(sf::Color(97, 83, 14));

    sf::Text textBigResolution;
    textBigResolution.setFont(font);
    textBigResolution.setString("1366 X 768");
    textBigResolution.setPosition((settingsWindow.getSize().x / 2) + 150, settingsWindow.getSize().y / 3);
    textBigResolution.setCharacterSize(26); 
    textBigResolution.setFillColor(sf::Color(97, 83, 14));

    sf::Texture newGameButton;
    if (!newGameButton.loadFromFile("images/button.png"))
        std::cout << "Can't find the button image" << std::endl;

    sf::Sprite smallResolutionButtonImage;
    smallResolutionButtonImage.setPosition((settingsWindow.getSize().x / 2) - 155, settingsWindow.getSize().y /3-5);
    smallResolutionButtonImage.setScale(1.0f, 1.3f);
    smallResolutionButtonImage.setTexture(newGameButton);

    sf::Sprite bigResolutionButtonImage;
    bigResolutionButtonImage.setPosition((settingsWindow.getSize().x / 2) + 145 , settingsWindow.getSize().y /3 - 5);
    bigResolutionButtonImage.setScale(1.0f, 1.3f);
    bigResolutionButtonImage.setTexture(newGameButton);

    sf::Text textMusic;
    textMusic.setFont(font);
    textMusic.setString("Muzyka");
    textMusic.setPosition((settingsWindow.getSize().x / 2) - 15, settingsWindow.getSize().y / 2);
    textMusic.setCharacterSize(30);
    textMusic.setFillColor(sf::Color(66, 58, 19));

    sf::Text textMusicYES;
    textMusicYES.setFont(font);
    textMusicYES.setString("TAK");
    textMusicYES.setPosition((settingsWindow.getSize().x / 2) - 150, (settingsWindow.getSize().y * 0.6));
    textMusicYES.setCharacterSize(26); 
    textMusicYES.setFillColor(sf::Color(97, 83, 14));

    sf::Text textMusicNO;
    textMusicNO.setFont(font);
    textMusicNO.setString("NIE");
    textMusicNO.setPosition((settingsWindow.getSize().x / 2) + 150, (settingsWindow.getSize().y * 0.6));
    textMusicNO.setCharacterSize(26); 
    textMusicNO.setFillColor(sf::Color(97, 83, 14));

    sf::Texture textMusicButton;
    if (!textMusicButton.loadFromFile("images/button.png"))
        std::cout << "Can't find the button image" << std::endl;

    sf::Sprite textMusicNOButtonImage;
    textMusicNOButtonImage.setPosition((settingsWindow.getSize().x / 2) + 150, settingsWindow.getSize().y * 0.6);
    textMusicNOButtonImage.setTexture(textMusicButton);
    textMusicNOButtonImage.setScale(1.4f, 1.3f);

    sf::Sprite textMusicYESButtonImage;
    textMusicYESButtonImage.setPosition((settingsWindow.getSize().x / 2) - 150, settingsWindow.getSize().y * 0.6);
    textMusicYESButtonImage.setTexture(textMusicButton);
    textMusicYESButtonImage.setScale(1.4f, 1.3f);

    sf::Text textBack;
    textBack.setFont(font);
    textBack.setString("Wstecz");
    textBack.setPosition((settingsWindow.getSize().x / 10) , settingsWindow.getSize().y * 0.9);
    textBack.setCharacterSize(30);
    textBack.setFillColor(sf::Color(66, 58, 19));

    sf::Texture exitButton;
    sf::Sprite exitButtonImage;
    if (!exitButton.loadFromFile("images/button.png"))
        std::cout << "Can't find the button image" << std::endl;
    exitButtonImage.setPosition((settingsWindow.getSize().x / 10) -5, (settingsWindow.getSize().y * 0.9)-5);
    exitButtonImage.setScale(1.0f, 1.0f);
    exitButtonImage.setTexture(exitButton);

    settingsWindow.clear();
    settingsWindow.draw(backgroundImage);
    settingsWindow.draw(smallResolutionButtonImage);
    settingsWindow.draw(bigResolutionButtonImage);
    settingsWindow.draw(textMusicYESButtonImage);
    settingsWindow.draw(textMusicNOButtonImage);
    settingsWindow.draw(exitButtonImage);
    settingsWindow.draw(text);
    settingsWindow.draw(textBigResolution);
    settingsWindow.draw(textSmallResolution);
    settingsWindow.draw(textMusic);
    settingsWindow.draw(textMusicYES);
    settingsWindow.draw(textMusicNO);
    settingsWindow.draw(textBack);

    settingsWindow.display();
    MainMenu menu;
    GameController game;

    while (settingsWindow.isOpen())
    {
        sf::Event Event;
        while (settingsWindow.pollEvent(Event))
        {
            switch (Event.type)
            {
            case sf::Event::Closed:
                settingsWindow.close();
                break;
            case sf::Event::MouseMoved:
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(settingsWindow);
                sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                if (smallResolutionButtonImage.getGlobalBounds().contains(mousePosF))
                {
                    smallResolutionButtonImage.setColor(sf::Color(250, 20, 20));
                }
                else
                {
                    smallResolutionButtonImage.setColor(sf::Color(255, 255, 255));
                }
            }
            break;
            case sf::Event::MouseButtonPressed:
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(settingsWindow);
                sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                if (smallResolutionButtonImage.getGlobalBounds().contains(mousePosF))
                {
                    std::cout << "Small resolution!" << std::endl;
                    menu.setWidth(1024);
                    menu.setHeight(622);
                    setWidth(1024);
                    setHeight(622);

                    backgroundImage.setScale(
                        settingsWindow.getSize().x / backgroundImage.getLocalBounds().width,
                        settingsWindow.getSize().y / backgroundImage.getLocalBounds().height);


                    textBigResolution.setFillColor(sf::Color(97, 83, 14));
                    textSmallResolution.setFillColor(sf::Color::Yellow);

                    settingsWindow.create(sf::VideoMode(width, height), "Hydropieklowstapienie", sf::Style::Default);
                }
                else if (bigResolutionButtonImage.getGlobalBounds().contains(mousePosF))
                {
                    std::cout << "Big resolution!" << std::endl;
                    menu.setWidth(1366);
                    menu.setHeight(768);
                    setWidth(1366);
                    setHeight(768);
                    settingsWindow.create(sf::VideoMode(width, height), "Hydropieklowstapienie", sf::Style::Default);

                    backgroundImage.setScale(
                        settingsWindow.getSize().x / backgroundImage.getLocalBounds().width,
                        settingsWindow.getSize().y / backgroundImage.getLocalBounds().height);

                    textBigResolution.setFillColor(sf::Color::Yellow);
                    textSmallResolution.setFillColor(sf::Color(97, 83, 14));
                }
                else if (textMusicYESButtonImage.getGlobalBounds().contains(mousePosF))
                {
                    std::cout << "Clicked, YesButton!" << std::endl;
                    menu.setPlayMusic(true);
                    textMusicYES.setFillColor(sf::Color::Yellow);
                    textMusicNO.setFillColor(sf::Color(97, 83, 14));
                    settingsWindow.draw(textMusicYES);

                }
                else if (textMusicNOButtonImage.getGlobalBounds().contains(mousePosF))
                {
                    std::cout << "Clicked, NOButton!" << std::endl;
                    menu.setPlayMusic(false);
                    textMusicNO.setFillColor(sf::Color::Yellow);
                    textMusicYES.setFillColor(sf::Color(97, 83, 14));

                }
                else if (exitButtonImage.getGlobalBounds().contains(mousePosF))
                {
                    settingsWindow.close();
                    menu.createWindowMenu();
                    std::cout << "Clicked, Exit!" << std::endl;
                }
            }
            break;
            }

            settingsWindow.clear();
            settingsWindow.draw(backgroundImage);
            settingsWindow.draw(smallResolutionButtonImage);
            settingsWindow.draw(bigResolutionButtonImage);
            settingsWindow.draw(textMusicYESButtonImage);
            settingsWindow.draw(textMusicNOButtonImage);
            settingsWindow.draw(exitButtonImage);
            settingsWindow.draw(text);
            settingsWindow.draw(textBigResolution);
            settingsWindow.draw(textSmallResolution);
            settingsWindow.draw(textMusic);
            settingsWindow.draw(textMusicYES);
            settingsWindow.draw(textMusicNO);
            settingsWindow.draw(textBack);

            settingsWindow.display();
        }

    }
}

/// <summary>
/// Metoda ustawiaj¹ca szerokoœæ okna
/// </summary>
/// <param name="_i"> wartoœæ jak¹ trzeba przypisaæ do pola width</param>
void Settings::setWidth(int _i)
{
    width = _i;
}

/// <summary>
/// Metoda ustawiaj¹ca wysokoœæ okna
/// </summary>
/// <param name="_i"> wartoœæ jak¹ trzeba przypisaæ pola height</param>
void Settings::setHeight(int _i)
{
    height = _i;
}
