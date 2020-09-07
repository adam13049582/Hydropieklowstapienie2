#include "Ground.h"
#include <iostream>
#include "MapElementTypes.h"
#include "Music.h"

/// <summary>
/// Kontruktor
/// </summary>
Ground:: Ground() {
    SetConfig();
}

/// <summary>
   /// Metoda tworz�ca tr�jk�t imitujacy ro�liny
   /// <param name="windowWidth"> szeroko�� okna</param>
   /// <param name="positionofStones">wsp�rz�dna y prostok�tu imituj�cego kamienie</param>
   /// <returns> obiekt typu CircleShape b�d�cy elementem mapy, w tym przypadku Ziemia </returns>
   /// </summary>
sf::CircleShape Ground::makeGroundElement(int windowWidth, int positionofStones)
{
    try {
        std::vector < ConfigModel > vecOfStr(Config.begin(), Config.end());

        int groundHeight = 0;
        for (ConfigModel str : vecOfStr) {
            if (str.key == "wysokoscZiemia")
                groundHeight = stoi(str.value);
        }
        sf::CircleShape ground(groundHeight, 3);
        ground.setPosition(400, positionofStones - groundHeight);

        sf::CircleShape ground1(groundHeight, 3);
        MapElementTypes mapElementType = GroundType;
        ground1 =setTexture(ground,mapElementType);

        return ground1;

    }
    catch (const std::exception & e) {
        std::cout << " a standard exception was caught when make ground object, with message '"
            << e.what() << "'\n";
        throw;
    }

}



