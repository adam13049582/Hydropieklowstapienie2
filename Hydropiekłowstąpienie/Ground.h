# ifndef Groundh
# define Groundh
#include "Area.h"
#include <SFML\Audio\Music.hpp>
#include <SFML/Graphics.hpp>
#include "ConfigModel.h"

/// <summary>
/// Klasa do zarz�dzania przeszkod� typu ziemia
/// </summary>
class Ground : public Area {

private:
	int width;
	int height;

public:
	/// <summary>
	/// Metoda tworz�ca tr�jk�t imitujacy ziemi�
	/// <param name="windowWidth"> szeroko�� okna</param>
	/// <param name="positionofStones">wsp�rz�dna y prostok�tu imituj�cego kamienie</param>
	/// <returns> obiekt typu RectangleShape b�d�cy elementem mapy, w tym przypadku Ziemia</returns>
	/// </summary>
	sf::CircleShape makeGroundElement(int windowWidth, int positionofStones);

	/// <summary>
	/// Kontruktor
	/// </summary>
	Ground();
};
#endif