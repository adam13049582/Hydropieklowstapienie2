#include "Area.h"
#include <iostream>
#include "string"
#include "ConfigModel.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "FileReader.h"


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

/// <summary>
/// Metoda wywo�uj�ca klas� wczytuj�c� konfiguracj� i przypisuj�ca warto�� polu Config
/// </summary>
void Area::SetConfig()
{
    FileReader fileReader;
    Config = fileReader.configRead();
}