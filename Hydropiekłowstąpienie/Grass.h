# ifndef Grassh
# define Grassh
#include "Ground.h"
class Grass : public Ground {
private:
	int absorpPosibility = 5;
public:
	/// <summary>
	/// Metoda nak³adaj¹ca teksturê na prostok¹t imitujacy roœliny
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