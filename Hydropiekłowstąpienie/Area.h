# ifndef Areah
# define Areah
#include <iostream>
#include <SFML\Graphics\Texture.hpp>
#include <list>
#include "ConfigModel.h"
#include <SFML/Graphics.hpp>


using namespace std;

/// <summary>
/// podstawowa klasa do tworzenia obiektów gry(przeszkód) implementuje podstawowe i uniwersalne pola oraz metody
/// </summary>
class Area {
private:
	int width;
	int height;
	int positionX;
	int positionY;
	sf::Texture texture;

public:

	//lista przechowywuj¹ca elementy konfiguracjê
	std::list<ConfigModel> Config;

	//zalewanie
	//pobieranie wysokoœci
	int getHeight();
	//ustawianie wysokoœci
	void setHeight(int _height);
	//ustawianie szerokoœci
	int getWidth();
	//ustawianie szerokoœci
	void setWidth(int _width);

	//ustawianie wartoœci w liœcie Config
	void SetConfig();

	/// <summary>
	/// Szablon metody nak³adaj¹cej tekstury na obiekty w zale¿noœci od jego typu 
	/// </summary>
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

};

#endif

