# ifndef MapMakerH
# define MapMakerH
#include <iostream>
#include "LocalizationElement.h"

using namespace std;

class MapMaker {
private:
	sf::Texture texture;

public:
	sf::RectangleShape makeStonesElement(int windowWidth, int windowHeight);
	sf::RectangleShape makeGroundElement(int windowWidth, int positionofStones);
	sf::RectangleShape makeGrassElement(int windowWidth, int positionofGround);
	void setTexture(string stones);
};
#endif
