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
   /// Metoda tworz¹ca ko³o imituj¹ce kamienie
   /// <param name="windowWidth"> szerokoœæ okna</param>
   /// <param name="windowHeight">wysokoœæ okna</param>
   /// <returns> obiekt typu CircleShape bêd¹cy elementem mapy, w tym przypadku Kamienie</returns>
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
        stones.setPosition(300, windowHeight - stoneHeight);
        MapElementTypes mapElementType = StonesType;

        stones=setTexture(stones,mapElementType);
    }
    catch (const std::exception & e) {
        std::cout << " a standard exception was caught when make stones object, with message '"
            << e.what() << "'\n";
    }
    return stones;

}