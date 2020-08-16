#include "Grass.h"
#include "MapElementTypes.h"

/// <summary>
/// Kontruktor
/// </summary>
Grass::Grass()
{
    SetConfig();
}
/// <summary>
    /// Metoda nak�adaj�ca tekstur� na prostok�t imitujacy ro�liny
    /// <param name="windowWidth"> szeroko�� okna</param>
    /// <param name="positionofStones">wsp�rz�dna y prostok�tu imituj�cego kamienie</param>
    /// <returns> obiekt typu RectangleShape b�d�cy elementem mapy, w tym przypadku Ziemia</returns>
    /// </summary>
sf::RectangleShape Grass::makeGrassElement(int windowWidth, int positionofGround)
{
    sf::RectangleShape grass(sf::Vector2f(0, 0));

    try
    {
        std::vector < ConfigModel > vecOfStr(Config.begin(), Config.end());

        int grassHeight = 0;
        for (ConfigModel str : vecOfStr) {
            if (str.key == "wysokoscRosliny")
                grassHeight = stoi(str.value);
        }

        grass.setSize(sf::Vector2f(windowWidth, grassHeight));
        grass.setPosition(0, positionofGround - grassHeight);
        MapElementTypes mapElementType = GrassType;
        setTexture(mapElementType);

        //sf::Texture testtex = getTexture();
        grass.setTexture(getTexture());
    }
    catch (const std::exception & e) {
        std::cout << " a standard exception was caught when make stones object, with message '"
            << e.what() << "'\n";
    }
    return grass;
}

