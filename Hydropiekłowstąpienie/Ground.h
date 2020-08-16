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
	/// Metoda nak�adaj�ca tekstur� na prostok�t imitujacy ro�liny
	/// <param name="windowWidth"> szeroko�� okna</param>
	/// <param name="positionofStones">wsp�rz�dna y prostok�tu imituj�cego kamienie</param>
	/// <returns> obiekt typu RectangleShape b�d�cy elementem mapy, w tym przypadku Ziemia<returns>
	/// </summary>
	sf::CircleShape makeGroundElement(int windowWidth, int positionofStones);

	void absorption(int absorpPossibility);
	/// <summary>
	/// Kontruktor
	/// </summary>
	Ground();
};
#endif