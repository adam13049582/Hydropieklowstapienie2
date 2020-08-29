#include <SFML/Graphics.hpp>
#include <time.h>
#include <stdlib.h>
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include <iostream> 
#include "MainMenu.h"
using namespace std;

        int main()
        {           
            MainMenu* mainMenu = new MainMenu();
            mainMenu->createWindow( false, 1024, 622);
            return 0;	
	    }
