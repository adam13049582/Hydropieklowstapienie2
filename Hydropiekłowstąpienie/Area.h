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

	//tablica z teksturami, kt�re b�d� nanoszone na poszczeg�lne elementy mapy
	sf::Texture texture;

public:

	//lista przechowywuj�ca elementy konfiguracj�
	std::list<ConfigModel> Config;

	//zalewanie
	void flooding(int floodingLevel); 
	//pobieranie wysoko�ci
	int getHeight();
	//ustawianie wysoko�ci
	void setHeight(int _height);
	//ustawianie szeroko�ci
	int getWidth();
	//ustawianie szeroko�ci
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

