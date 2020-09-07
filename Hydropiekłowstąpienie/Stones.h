# ifndef Stonesh
# define Stonesh
#include "Area.h"
#include <SFML\Audio\Music.hpp>
#include <SFML/Graphics.hpp>
#include "ConfigModel.h"

/// <summary>
/// Klasa do zarz¹dzania przeszkod¹ typu kamienie
/// </summary>
class Stones : public Area {
	public:
		/// <summary>
	/// Metoda tworz¹ca ko³o imitujace kamienie
	/// <param name="windowWidth"> szerokoœæ okna</param>
	/// <param name="positionofStones">wspó³rzêdna y prostok¹tu imituj¹cego kamienie</param>
	/// <returns> obiekt typu CircleShape bêd¹cy elementem mapy, w tym przypadku Ziemia</returns>
	/// </summary>
	sf::CircleShape makeStonesElement(int windowWidth, int windowHeight);

	/// <summary>
	/// Kontruktor
	/// </summary>
	Stones();

};
#endif