# ifndef Grassh
# define Grassh
#include "Area.h"
#include <SFML/Graphics.hpp>

/// <summary>
/// Klasa do zarz�dzania przeszkod� typu rosliny
/// </summary>
class Grass : public Area {

public:
	/// <summary>
	/// Metoda tworz�ca prostok�t imitujacy ro�liny
	/// <param name="windowWidth"> szeroko�� okna</param>
	/// <param name="positionofStones">wsp�rz�dna y prostok�tu imituj�cego kamienie</param>
	/// <returns> obiekt typu RectangleShape b�d�cy elementem mapy, w tym przypadku Ziemia</returns>
	/// </summary>
	sf::RectangleShape makeGrassElement(int windowWidth, int positionofGround);

	/// <summary>
	/// Kontruktor
	/// </summary>
	Grass();
};
#endif