#include "Area.h"
#include <iostream>
#include "string"
#include "ConfigModel.h"
#include <vector>
#include "FileReader.h"

void Area::flooding(int floodingLevel)
{

	if (floodingLevel == 1)
	{
		setWidth(getWidth() + 5);
		setPositionX(getPositionX() - 5);
	}
	if (floodingLevel == 2) 
	{
		setWidth(getWidth() + 2);
		setPositionX(getPositionX() - 2);
	}
}

int Area::getHeight()
{
	return height;
}

void Area::setHeight(int _height)
{
	height = _height;
}

int Area::getWidth()
{
	return width;
}

void Area::setWidth(int _width)
{
	width = _width;
}

int Area::getPositionX() {
	return positionX;
}

void Area::setPositionX(int _positionX) {
	positionX = _positionX;
}

int Area::getPositionY() {
	return positionY;
}

void Area::setPositionY(int _positionY) {
	positionY = _positionY;
}

/// <summary>
/// Metoda wywo³uj¹ca klasê wczytuj¹c¹ konfiguracjê i przypisuj¹ca wartoœæ polu Config
/// </summary>
void Area::SetConfig()
{
    FileReader fileReader;
    Config = fileReader.configRead();
}

/// <summary>
  /// Metoda wczytuj¹ca teksturê z pliku
  /// <param name="mapElementType"> typ obiektu na który bêdzie naniesiona tekstura(Enum castowany na int)</param>
  /// </summary>
void Area::setTexture(int mapElementType) {
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
}

sf::Texture* Area::getTexture()
{
    return &texture;
}
