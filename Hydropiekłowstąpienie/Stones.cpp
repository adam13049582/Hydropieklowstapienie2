#include "Stones.h"
#include <iostream>
#include "MapElementTypes.h"

/// <summary>
/// Kontruktor
/// </summary>
Stones::Stones() {
    SetConfig();
}

/// <summary>
   /// Metoda nak�adaj�ca tekstur� na prostok�t imitujacy ro�liny
   /// <param name="windowWidth"> szeroko�� okna</param>
   /// <param name="windowHeight">wysoko�� okna</param>
   /// <returns> obiekt typu RectangleShape b�d�cy elementem mapy, w tym przypadku Kamienie<returns>
   /// </summary>
sf::CircleShape Stones::makeStonesElement(int windowWidth, int windowHeight)
{
    sf::CircleShape stones;

    try {
        std::vector < ConfigModel > vecOfStr(Config.begin(), Config.end());

        int stoneHeight = 0;
        int stoneCount = 0;
        for (ConfigModel str : vecOfStr) {
            if (str.key == "wysokoscKamienie")
                stoneHeight = stoi(str.value);
        }
        stones.setRadius(stoneHeight / 2);
        //stones.setOutlineColor(sf::Color::Red);
        stones.setPosition(100, windowHeight - stoneHeight);
        MapElementTypes mapElementType = StonesType;

        stones=setTexture(stones,mapElementType);
        //stones.setTexture(getTexture());

        //stones.setSize(sf::Vector2f(stoneHeight, stoneHeight));
    }
    catch (const std::exception & e) {
        std::cout << " a standard exception was caught when make stones object, with message '"
            << e.what() << "'\n";
    }
    return stones;

}