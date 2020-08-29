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

	//tablica z teksturami, które będą nanoszone na poszczególne elementy mapy
	//sf::Texture texture;

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

