# ifndef Grassh
# define Grassh
#include "Area.h"
#include <SFML/Graphics.hpp>

/// <summary>
/// Klasa do zarz¹dzania przeszkod¹ typu rosliny
/// </summary>
class Grass : public Area {

public:
	/// <summary>
	/// Metoda tworz¹ca prostok¹t imitujacy roœliny
	/// <param name="windowWidth"> szerokoœæ okna</param>
	/// <param name="positionofStones">wspó³rzêdna y prostok¹tu imituj¹cego kamienie</param>
	/// <returns> obiekt typu RectangleShape bêd¹cy elementem mapy, w tym przypadku Ziemia</returns>
	/// </summary>
	sf::RectangleShape makeGrassElement(int windowWidth, int positionofGround);

	/// <summary>
	/// Kontruktor
	/// </summary>
	Grass();
};
#endif