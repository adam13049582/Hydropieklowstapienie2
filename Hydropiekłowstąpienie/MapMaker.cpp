#include <SFML/Graphics.hpp>
#include <time.h>
#include <stdlib.h>
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include <iostream>
#include <windows.h>
#include <string>
#include <list> 
#include "ConfigModel.h"
#include "FileReader.h"
#include "MapMaker.h"

sf::RectangleShape MapMaker::makeStonesElement(int windowWidth, int windowHeight)
{
    sf::RectangleShape stones(sf::Vector2f(0, 0));

    try {
        FileReader fileReader;
        list<ConfigModel>config = fileReader.configRead();
        std::vector < ConfigModel > vecOfStr(config.begin(), config.end());

        int stoneHeight = 0;
        for (ConfigModel str : vecOfStr)
            if (str.key == "kamienie")
                // std::cout << str.key << "= " << str.value << std::endl;
                stoneHeight = stoi(str.value);


        //sf::Texture background;
        //// sf::Sprite backgroundImage;
        //if (!background.loadFromFile("images/kamienie.jpg"))
        //    std::cout << "Error: Could not display kamienie image" << std::endl;

        //const sf::Texture* pBackground = &background;

        setTexture("stones");

        stones.setTexture(&texture);

        stones.setSize(sf::Vector2f(windowWidth, stoneHeight));
        stones.setPosition(0, windowHeight - stoneHeight);
    }
    //stones.setFillColor(sf::Color(0, 255, 255));
    catch (const std::exception & e) { // caught by reference to base
        std::cout << " a standard exception was caught, with message '"
            << e.what() << "'\n";
    }
    return stones;

}

sf::RectangleShape MapMaker::makeGroundElement(int windowWidth, int positionofStones)
{
    FileReader fileReader;
    list<ConfigModel>config = fileReader.configRead();
    std::vector < ConfigModel > vecOfStr(config.begin(), config.end());

    int groundHeight = 0;
    for (ConfigModel str : vecOfStr)
        if (str.key == "ziemia")
            // std::cout << str.key << "= " << str.value << std::endl;
            groundHeight = stoi(str.value);

    sf::RectangleShape ground(sf::Vector2f(0, 0));
    ground.setSize(sf::Vector2f(windowWidth, groundHeight));
    ground.setPosition(0, positionofStones - groundHeight);
    setTexture("ground");

    ground.setTexture(&texture);
  //  ground.setFillColor(sf::Color(0, 255, 255));

    return ground;
}

sf::RectangleShape MapMaker::makeGrassElement(int windowWidth, int positionofGround)
{
    FileReader fileReader;
    list<ConfigModel>config = fileReader.configRead();
    std::vector < ConfigModel > vecOfStr(config.begin(), config.end());

    int grassHeight = 0;
    for (ConfigModel str : vecOfStr)
        if (str.key == "ziemia")
            // std::cout << str.key << "= " << str.value << std::endl;
            grassHeight = stoi(str.value);

    sf::RectangleShape grass(sf::Vector2f(0, 0));
    grass.setSize(sf::Vector2f(windowWidth, grassHeight));
    grass.setPosition(0, positionofGround - grassHeight);
    grass.setFillColor(sf::Color(0, 255, 255));

    return grass;
}
void MapMaker::setTexture(string object) {
    string fileName = "";
    if (object == "stones") {
        fileName = "images/kamienie.jpg";
    }
    else if ("ground") {
        fileName = "images/ziemia.jpg";
    }
    if (!texture.loadFromFile(fileName))
        std::cout << "Error: Could not display kamienie image" << std::endl;
}