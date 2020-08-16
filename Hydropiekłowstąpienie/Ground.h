# ifndef Groundh
# define Groundh
#include "Area.h"
#include <SFML\Audio\Music.hpp>
#include <SFML/Graphics.hpp>
#include "ConfigModel.h"


class Ground : public Area {

private:
	int width;
	int height;

public:
	/// <summary>
	/// Metoda nak³adaj¹ca teksturê na prostok¹t imitujacy roœliny
	/// <param name="windowWidth"> szerokoœæ okna</param>
	/// <param name="positionofStones">wspó³rzêdna y prostok¹tu imituj¹cego kamienie</param>
	/// <returns> obiekt typu RectangleShape bêd¹cy elementem mapy, w tym przypadku Ziemia<returns>
	/// </summary>
	sf::CircleShape makeGroundElement(int windowWidth, int positionofStones);

	void absorption(int absorpPossibility);
	/// <summary>
	/// Kontruktor
	/// </summary>
	Ground();
};
#endif