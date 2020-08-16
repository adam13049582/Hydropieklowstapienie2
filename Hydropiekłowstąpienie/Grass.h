# ifndef Grassh
# define Grassh
#include "Ground.h"
class Grass : public Ground {
private:
	int absorpPosibility = 5;
public:
	/// <summary>
	/// Metoda nak�adaj�ca tekstur� na prostok�t imitujacy ro�liny
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