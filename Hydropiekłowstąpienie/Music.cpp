#include <stdlib.h>
#include <string>
#include "FileReader.h"
#include "Music.h"
#include <vector>
/// <summary>
/// Metoda wywo³uj¹ca klasê wczytuj¹c¹ konfiguracjê i przypisuj¹ca wartoœæ polu Config
/// </summary>
void Music::SetConfig()
{
    FileReader fileReader;
    Config = fileReader.configRead();  
}
//    /// <summary>
//    /// Metoda nak³adaj¹ca teksturê na prostok¹t imitujacy roœliny
//    /// <param name="windowWidth"> szerokoœæ okna</param>
//    /// <param name="windowHeight">wysokoœæ okna</param>
//    /// <returns> obiekt typu RectangleShape bêd¹cy elementem mapy, w tym przypadku Kamienie<returns>
//    /// </summary>
//sf::CircleShape MapMaker::makeStonesElement(int windowWidth, int windowHeight)
//{
//    sf::CircleShape stones;
//  
//    try {
//        std::vector < ConfigModel > vecOfStr(Config.begin(), Config.end());
//
//        int stoneHeight = 0;
//        int stoneCount = 0;
//        for (ConfigModel str : vecOfStr) {
//            if (str.key == "wysokoscKamienie")
//                stoneHeight = stoi(str.value);
//        }
//        stones.setRadius(stoneHeight/2);
//        //stones.setOutlineColor(sf::Color::Red);
//        stones.setPosition(10, 20);
//        MapElementTypes mapElementType = StonesType;
//
//        setTexture(mapElementType);
//        stones.setTexture(&textures[mapElementType]);
//
//        //stones.setSize(sf::Vector2f(stoneHeight, stoneHeight));
//        stones.setPosition(100, windowHeight - stoneHeight);
//    }
//    catch (const std::exception & e) {
//        std::cout << " a standard exception was caught when make stones object, with message '"
//            << e.what() << "'\n";
//    }
//    return stones;
//
//}
//    /// <summary>
//    /// Metoda nak³adaj¹ca teksturê na prostok¹t imitujacy roœliny
//    /// <param name="windowWidth"> szerokoœæ okna</param>
//    /// <param name="positionofStones">wspó³rzêdna y prostok¹tu imituj¹cego kamienie</param>
//    /// <returns> obiekt typu RectangleShape bêd¹cy elementem mapy, w tym przypadku Ziemia<returns>
//    /// </summary>
//sf::CircleShape MapMaker::makeGroundElement(int windowWidth, int positionofStones)
//{
//   
//
//    try {
//        std::vector < ConfigModel > vecOfStr(Config.begin(), Config.end());
//
//        int groundHeight = 0;
//        for (ConfigModel str : vecOfStr) {
//            if (str.key == "wysokoscZiemia")
//                groundHeight = stoi(str.value);
//        }
//        sf::CircleShape ground(groundHeight, 3);
//       // ground.setSize(sf::Vector2f(windowWidth, groundHeight));
//        ground.setPosition(400, positionofStones - groundHeight);
//
//        MapElementTypes mapElementType = GroundType;
//        setTexture(mapElementType);
//
//        ground.setTexture(&textures[mapElementType]);
//        return ground;
//
//    }
//    catch (const std::exception & e) { 
//        std::cout << " a standard exception was caught when make ground object, with message '"
//            << e.what() << "'\n";
//        throw;
//    }
//
//}
//    /// <summary>
//    /// Metoda nak³adaj¹ca teksturê na prostok¹t imitujacy roœliny
//    /// <param name="windowWidth"> szerokoœæ okna</param>
//    /// <param name="positionofStones">wspó³rzêdna y prostok¹tu imituj¹cego ziemiê</param>
//    /// <returns> obiekt typu RectangleShape bêd¹cy elementem mapy, w tym przypadku Roœliny<returns>
//    /// </summary>
//sf::RectangleShape MapMaker::makeGrassElement(int windowWidth, int positionofGround)
//{
//    sf::RectangleShape grass(sf::Vector2f(0, 0));
//
//    try
//    {
//    std::vector < ConfigModel > vecOfStr(Config.begin(), Config.end());
//
//    int grassHeight = 0;
//    for (ConfigModel str : vecOfStr) {
//        if (str.key == "wysokoscRosliny")
//            grassHeight = stoi(str.value);
//    }
//
//    grass.setSize(sf::Vector2f(windowWidth, grassHeight));
//    grass.setPosition(0, positionofGround - grassHeight);
//    MapElementTypes mapElementType = GrassType;
//    setTexture(mapElementType);
//
//    grass.setTexture(&textures[mapElementType]);
//}
//catch (const std::exception & e) {
//    std::cout << " a standard exception was caught when make stones object, with message '"
//        << e.what() << "'\n";
//}
//    return grass;
//}
//    /// <summary>
//    /// Metoda wczytuj¹ca teksturê z pliku
//    /// <param name="mapElementType"> typ obiektu na który bêdzie naniesiona tekstura(Enum castowany na int)</param>
//    /// </summary>
//void MapMaker::setTexture(int mapElementType) {
//    string fileName = "";
//    std::vector < ConfigModel > vecOfStr(Config.begin(), Config.end());
//    if (mapElementType == 0) {
//        for (ConfigModel str : vecOfStr) {
//            if (str.key == "teksturaKamienie")
//                fileName = "images/" + str.value;
//        }
//    }
//    else if (mapElementType == 1) {
//        for (ConfigModel str : vecOfStr) {
//            if (str.key == "teksturaZiemia")
//                fileName = "images/" + str.value;
//        }
//    }
//    else if (mapElementType == 2) {
//        for (ConfigModel str : vecOfStr) {
//            if (str.key == "teksturaRosliny")
//                fileName = "images/" + str.value;
//        }
//    }
//    if (!textures[mapElementType].loadFromFile(fileName))
//        std::cout << "Error: Could not display image from "<<fileName << std::endl;
//}
/// <summary>
/// Metoda przetwarzaj¹ca plik z muzyk¹
/// </summary>
void Music::playMusic()
{
    SetConfig();
    std::vector < ConfigModel > vecOfStr(Config.begin(), Config.end());
    string fileName;
    for (ConfigModel str : vecOfStr) {
        if (str.key == "muzyka")
            fileName = "sounds/" + str.value;
    }
    if (!music.openFromFile(fileName))
        std::cout << "Error: Could not open titanic sound" << std::endl;
}