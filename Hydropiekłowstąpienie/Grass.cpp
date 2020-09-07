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
    /// Metoda tworz¹ca prostok¹t imitujacy roœliny
    /// <param name="windowWidth"> szerokoœæ okna</param>
    /// <param name="positionofStones">wspó³rzêdna y prostok¹tu imituj¹cego kamienie</param>
    /// <returns> obiekt typu RectangleShape bêd¹cy elementem mapy, w tym przypadku Ziemia</returns>
    /// </summary>
sf::RectangleShape Grass::makeGrassElement(int windowWidth, int positionofGround)
{
    sf::RectangleShape grass(sf::Vector2f(50, 0));

    try
    {
        std::vector < ConfigModel > vecOfStr(Config.begin(), Config.end());

        int grassHeight = 0;
        for (ConfigModel str : vecOfStr) {
            if (str.key == "wysokoscRosliny")
                grassHeight = stoi(str.value);
        }

        grass.setSize(sf::Vector2f(150, grassHeight));
        grass.setPosition(0, positionofGround - grassHeight);
        MapElementTypes mapElementType = GrassType;
        grass=setTexture(grass,mapElementType);
    }
    catch (const std::exception & e) {
        std::cout << " a standard exception was caught when make stones object, with message '"
            << e.what() << "'\n";
    }
    return grass;
}

