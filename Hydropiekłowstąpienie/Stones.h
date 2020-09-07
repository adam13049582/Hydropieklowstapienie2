# ifndef Stonesh
# define Stonesh
#include "Area.h"
#include <SFML\Audio\Music.hpp>
#include <SFML/Graphics.hpp>
#include "ConfigModel.h"

/// <summary>
/// Klasa do zarz�dzania przeszkod� typu kamienie
/// </summary>
class Stones : public Area {
	public:
		/// <summary>
	/// Metoda tworz�ca ko�o imitujace kamienie
	/// <param name="windowWidth"> szeroko�� okna</param>
	/// <param name="positionofStones">wsp�rz�dna y prostok�tu imituj�cego kamienie</param>
	/// <returns> obiekt typu CircleShape b�d�cy elementem mapy, w tym przypadku Ziemia</returns>
	/// </summary>
	sf::CircleShape makeStonesElement(int windowWidth, int windowHeight);

	/// <summary>
	/// Kontruktor
	/// </summary>
	Stones();

};
#endif