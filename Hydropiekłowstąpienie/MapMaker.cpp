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
#include "MapElementTypes.h"
#include <vector>

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
                stoneHeight = stoi(str.value);

        MapElementTypes mapElementType = Stones;

        setTexture(mapElementType);
        stones.setTexture(&textures[mapElementType]);

        stones.setSize(sf::Vector2f(windowWidth, stoneHeight));
        stones.setPosition(0, windowHeight - stoneHeight);
    }
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
            groundHeight = stoi(str.value);

    sf::RectangleShape ground(sf::Vector2f(0, 0));
    ground.setSize(sf::Vector2f(windowWidth, groundHeight));
    ground.setPosition(0, positionofStones - groundHeight);

     MapElementTypes mapElementType = Ground;
     setTexture(mapElementType);

     ground.setTexture(&textures[mapElementType]);

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
            grassHeight = stoi(str.value);

    sf::RectangleShape grass(sf::Vector2f(0, 0));
    grass.setSize(sf::Vector2f(windowWidth, grassHeight));
    grass.setPosition(0, positionofGround - grassHeight);
    MapElementTypes mapElementType = Grass;
    setTexture(mapElementType);

    grass.setTexture(&textures[mapElementType]);
    return grass;
}
void MapMaker::setTexture(int mapElementType) {
    string fileName = "";
    if (mapElementType == 0) {
        fileName = "images/kamienie.jpg";
    }
    else if (mapElementType == 1) {
        fileName = "images/ziemia.jpg";
    }
    else if (mapElementType == 2) {
        fileName = "images/trawa.jpg";
    }
    if (!textures[mapElementType].loadFromFile(fileName))
        std::cout << "Error: Could not display kamienie image" << std::endl;
}