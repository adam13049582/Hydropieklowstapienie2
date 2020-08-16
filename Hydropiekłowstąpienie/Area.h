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

	//tablica z teksturami, które będą nanoszone na poszczególne elementy mapy
	sf::Texture texture;

public:

	//lista przechowywująca elementy konfigurację
	std::list<ConfigModel> Config;

	//zalewanie
	void flooding(int floodingLevel); 
	//pobieranie wysokości
	int getHeight();
	//ustawianie wysokości
	void setHeight(int _height);
	//ustawianie szerokości
	int getWidth();
	//ustawianie szerokości
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

