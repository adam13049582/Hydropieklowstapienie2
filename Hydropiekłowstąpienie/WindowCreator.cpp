#include "WindowCreator.h"
#include <SFML\Graphics\RenderWindow.hpp>

using namespace std;

/// <summary>
   /// Metoda tworz¹ca okno 
   /// </summary>
void WindowCreator::createWindow(bool playMusic, int width, int height)
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Hydropieklowstapienie", sf::Style::Default);
	window.clear();
	window.display();
	while (window.isOpen())
	{
	}
}
