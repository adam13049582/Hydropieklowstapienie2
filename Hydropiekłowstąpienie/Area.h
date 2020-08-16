# ifndef Areah
# define Areah
#include <iostream>
#include <SFML\Graphics\Texture.hpp>
#include <list>
#include "ConfigModel.h"

using namespace std;

class Area {
private:
	int width;
	int height;
	int positionX;
	int positionY;

	//tablica z teksturami, które bêd¹ nanoszone na poszczególne elementy mapy
	sf::Texture texture;

public:

	//lista przechowywuj¹ca elementy konfiguracjê
	std::list<ConfigModel> Config;

	//zalewanie
	void flooding(int floodingLevel); 
	//pobieranie wysokoœci
	int getHeight();
	//ustawianie wysokoœci
	void setHeight(int _height);
	//ustawianie szerokoœci
	int getWidth();
	//ustawianie szerokoœci
	void setWidth(int _width);
	int getPositionX();
	void setPositionX(int _positionX);
	int getPositionY();
	void setPositionY(int _positionY);
	void SetConfig();
	void setTexture(int mapElementType);
	sf::Texture* getTexture();

};

#endif

