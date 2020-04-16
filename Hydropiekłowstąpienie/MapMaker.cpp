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
/// <summary>
/// Metoda wywo�uj�ca klas� wczytuj�c� konfiguracj� i przypisuj�ca warto�� polu Config
/// </summary>
void MapMaker::SetConfig()
{
    FileReader fileReader;
    Config = fileReader.configRead();  
}
    /// <summary>
    /// Metoda nak�adaj�ca tekstur� na prostok�t imitujacy ro�liny
    /// <param name="windowWidth"> szeroko�� okna</param>
    /// <param name="windowHeight">wysoko�� okna</param>
    /// <returns> obiekt typu RectangleShape b�d�cy elementem mapy, w tym przypadku Kamienie<returns>
    /// </summary>
sf::RectangleShape MapMaker::makeStonesElement(int windowWidth, int windowHeight)
{
    sf::RectangleShape stones(sf::Vector2f(0, 0));

    try {
        std::vector < ConfigModel > vecOfStr(Config.begin(), Config.end());

        int stoneHeight = 0;
        for (ConfigModel str : vecOfStr) {
            if (str.key == "kamienie")
                stoneHeight = stoi(str.value);
        }

        MapElementTypes mapElementType = Stones;

        setTexture(mapElementType);
        stones.setTexture(&textures[mapElementType]);

        stones.setSize(sf::Vector2f(windowWidth, stoneHeight));
        stones.setPosition(0, windowHeight - stoneHeight);
    }
    catch (const std::exception & e) {
        std::cout << " a standard exception was caught when make stones object, with message '"
            << e.what() << "'\n";
    }
    return stones;

}
    /// <summary>
    /// Metoda nak�adaj�ca tekstur� na prostok�t imitujacy ro�liny
    /// <param name="windowWidth"> szeroko�� okna</param>
    /// <param name="positionofStones">wsp�rz�dna y prostok�tu imituj�cego kamienie</param>
    /// <returns> obiekt typu RectangleShape b�d�cy elementem mapy, w tym przypadku Ziemia<returns>
    /// </summary>
sf::RectangleShape MapMaker::makeGroundElement(int windowWidth, int positionofStones)
{
    sf::RectangleShape ground(sf::Vector2f(0, 0));

    try {
        std::vector < ConfigModel > vecOfStr(Config.begin(), Config.end());

        int groundHeight = 0;
        for (ConfigModel str : vecOfStr) {
            if (str.key == "ziemia")
                groundHeight = stoi(str.value);
        }

        ground.setSize(sf::Vector2f(windowWidth, groundHeight));
        ground.setPosition(0, positionofStones - groundHeight);

        MapElementTypes mapElementType = Ground;
        setTexture(mapElementType);

        ground.setTexture(&textures[mapElementType]);
    }
    catch (const std::exception & e) { 
        std::cout << " a standard exception was caught when make ground object, with message '"
            << e.what() << "'\n";
    }

    return ground;
}
    /// <summary>
    /// Metoda nak�adaj�ca tekstur� na prostok�t imitujacy ro�liny
    /// <param name="windowWidth"> szeroko�� okna</param>
    /// <param name="positionofStones">wsp�rz�dna y prostok�tu imituj�cego ziemi�</param>
    /// <returns> obiekt typu RectangleShape b�d�cy elementem mapy, w tym przypadku Ro�liny<returns>
    /// </summary>
sf::RectangleShape MapMaker::makeGrassElement(int windowWidth, int positionofGround)
{
    sf::RectangleShape grass(sf::Vector2f(0, 0));

    try
    {
    std::vector < ConfigModel > vecOfStr(Config.begin(), Config.end());

    int grassHeight = 0;
    for (ConfigModel str : vecOfStr) {
        if (str.key == "ziemia")
            grassHeight = stoi(str.value);
    }

    grass.setSize(sf::Vector2f(windowWidth, grassHeight));
    grass.setPosition(0, positionofGround - grassHeight);
    MapElementTypes mapElementType = Grass;
    setTexture(mapElementType);

    grass.setTexture(&textures[mapElementType]);
}
catch (const std::exception & e) { // caught by reference to base
    std::cout << " a standard exception was caught when make stones object, with message '"
        << e.what() << "'\n";
}
    return grass;
}
    /// <summary>
    /// Metoda wczytuj�ca tekstur� z pliku
    /// <param name="mapElementType"> typ obiektu na kt�ry b�dzie naniesiona tekstura(Enum castowany na int)</param>
    /// </summary>
void MapMaker::setTexture(int mapElementType) {
    string fileName = "";
    std::vector < ConfigModel > vecOfStr(Config.begin(), Config.end());
    if (mapElementType == 0) {
        for (ConfigModel str : vecOfStr) {
            if (str.key == "teksturaKamienie")
                fileName = "images/" + str.value;
        }
    }
    else if (mapElementType == 1) {
        for (ConfigModel str : vecOfStr) {
            if (str.key == "teksturaZiemia")
                fileName = "images/" + str.value;
        }
    }
    else if (mapElementType == 2) {
        for (ConfigModel str : vecOfStr) {
            if (str.key == "teksturaRosliny")
                fileName = "images/" + str.value;
        }
    }
    if (!textures[mapElementType].loadFromFile(fileName))
        std::cout << "Error: Could not display image from "<<fileName << std::endl;
}
/// <summary>
/// Metoda przetwarzaj�ca plik z muzyk�
/// </summary>
void MapMaker::playMusic()
{
    std::vector < ConfigModel > vecOfStr(Config.begin(), Config.end());
    string fileName;
    for (ConfigModel str : vecOfStr) {
        if (str.key == "muzyka")
            fileName = "sounds/" + str.value;
    }
    if (!music.openFromFile(fileName))
        std::cout << "Error: Could not open titanic sound" << std::endl;
}