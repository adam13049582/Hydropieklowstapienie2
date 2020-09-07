# ifndef Groundh
# define Groundh
#include "Area.h"
#include <SFML\Audio\Music.hpp>
#include <SFML/Graphics.hpp>
#include "ConfigModel.h"

/// <summary>
/// Klasa do zarz¹dzania przeszkod¹ typu ziemia
/// </summary>
class Ground : public Area {

private:
	int width;
	int height;

public:
	/// <summary>
	/// Metoda tworz¹ca trójk¹t imitujacy ziemiê
	/// <param name="windowWidth"> szerokoœæ okna</param>
	/// <param name="positionofStones">wspó³rzêdna y prostok¹tu imituj¹cego kamienie</param>
	/// <returns> obiekt typu RectangleShape bêd¹cy elementem mapy, w tym przypadku Ziemia</returns>
	/// </summary>
	sf::CircleShape makeGroundElement(int windowWidth, int positionofStones);

	/// <summary>
	/// Kontruktor
	/// </summary>
	Ground();
};
#endif