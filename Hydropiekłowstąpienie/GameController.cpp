#include <SFML/Graphics.hpp>
#include <time.h>
#include <stdlib.h>
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include <iostream>
#include <SFML/Audio.hpp>
#include <windows.h>
#include <string>
#include <stdio.h>
#include "GameController.h"
#include "ConfigModel.h"
#include "FileReader.h"
#include "MapMaker.h"
#include <list>

void GameController::createWindowGame() {

    sf::RenderWindow window2(sf::VideoMode(1024, 622), "Hydropieklowstapienie", sf::Style::Default);
    sf::Texture background;
    sf::Sprite backgroundImage;
    if (!background.loadFromFile("images/woda_morska.jpg"))
        std::cout << "Error: Could not display Menu_g³ówne image" << std::endl;

    backgroundImage.setTexture(background);
    backgroundImage.setScale(
        window2.getSize().x / backgroundImage.getLocalBounds().width,
        window2.getSize().y / backgroundImage.getLocalBounds().height);
    backgroundImage.setColor(sf::Color(250, 20, 20));

    //FileReader fileReader;
    //list<ConfigModel>config = fileReader.configRead();
    //std::vector < ConfigModel > vecOfStr(config.begin(), config.end());

    //int stoneHeight = 0;
    //for (ConfigModel str : vecOfStr)
    //    if (str.key == "kamienie")
    //        // std::cout << str.key << "= " << str.value << std::endl;
    //        stoneHeight = stoi(str.value);

    sf::RectangleShape water(sf::Vector2f(120, 50));
    water.setSize(sf::Vector2f(1024, 100));
    water.setPosition(0, 622);
    water.setFillColor(sf::Color(0, 127, 255));
    //
    //sf::RectangleShape rectangle2(sf::Vector2f(0, 0));
    //rectangle2.setSize(sf::Vector2f(1024, stoneHeight));
    //rectangle2.setPosition(0, window2.getSize().y-stoneHeight);
    //rectangle2.setFillColor(sf::Color(0, 255, 255));

    //window2.clear();
    //window2.draw(backgroundImage);
    //window2.draw(rectangle2);
    //window2.draw(water);
    ////window2.display();
    MapMaker mapMaker;
    sf::RectangleShape stones = mapMaker.makeStonesElement(window2.getSize().x,window2.getSize().y);
    sf::RectangleShape ground = mapMaker.makeGroundElement(window2.getSize().x, stones.getPosition().y);
    sf::RectangleShape grass = mapMaker.makeGrassElement(window2.getSize().x, ground.getPosition().y);

    //sf::Texture backgroundStones;
    //// sf::Sprite backgroundImage;
    //if (!backgroundStones.loadFromFile("images/kamienie.jpg"))
    //    std::cout << "Error: Could not display kamienie image" << std::endl;

    //const sf::Texture* pBackground = &backgroundStones;

    //stones.setTexture(pBackground);

    window2.clear();
    window2.draw(backgroundImage);
    window2.draw(stones);
    window2.draw(ground);
    window2.draw(grass);

    window2.draw(water);
    window2.display();

    int height;
    int scale;
    
    //sf::RenderWindow rwindow=&window2;
    while (window2.isOpen())
    {
        /*if ((water.getPosition().y > rectangle2.getPosition().y) && (water.getPosition().y < (rectangle2.getPosition().y + rectangle2.getSize().y))) {
            height = water.getPosition().y - 2;
            scale = 2;
            std::cout << "Collision!" << std::endl;

        }
        else {
            height = water.getPosition().y - 10;
            scale = 10;

        }

        water.setPosition(0, height);
        water.scale(1, scale);
        Sleep(1000);
        window2.clear();
        window2.draw(backgroundImage);
        window2.draw(rectangle2);
        window2.draw(water);
        window2.display();
        std::cout << "Window2!" << std::endl;*/
    }
}