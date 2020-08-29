# ifndef Areah
# define Areah
#include <iostream>
#include <SFML\Graphics\Texture.hpp>
#include <list>
#include "ConfigModel.h"
#include <SFML/Graphics.hpp>


using namespace std;

class Area {
private:
	int width;
	int height;
	int positionX;
	int positionY;
	sf::Texture texture;

	//tablica z teksturami, kt�re b�d� nanoszone na poszczeg�lne elementy mapy
	//sf::Texture texture;

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
	template <typename T>
	T setTexture(T area, int mapElementType) {
		string fileName = "";
		std::vector < ConfigModel > vecOfStr(Config.begin(), Config.end());
		if (mapElementType == 0) {
			for (ConfigModel str : vecOfStr) {
				if (str.key == "teksturaKamienie")
					fileName = "images/" + str.value;
			}
		}
		else if (mapElementType == 1) {
			for (ConfigModel str : vecOfStr) {
				if (str.key == "teksturaZiemia")
					fileName = "images/" + str.value;
			}
		}
		else if (mapElementType == 2) {
			for (ConfigModel str : vecOfStr) {
				if (str.key == "teksturaRosliny")
					fileName = "images/" + str.value;
			}
		}
		if (!texture.loadFromFile(fileName))
			std::cout << "Error: Could not display image from " << fileName << std::endl;

		area.setTexture(&texture);
		return area;
	}
	//sf::Texture* getTexture();

};

#endif

