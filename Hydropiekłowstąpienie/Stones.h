# ifndef Stonesh
# define Stonesh
#include "Area.h"
#include <SFML\Audio\Music.hpp>
#include <SFML/Graphics.hpp>
#include "ConfigModel.h"

class Stones : public Area {
	public:

	sf::CircleShape makeStonesElement(int windowWidth, int windowHeight);

	/// <summary>
	/// Kontruktor
	/// </summary>
	Stones();

};
#endif