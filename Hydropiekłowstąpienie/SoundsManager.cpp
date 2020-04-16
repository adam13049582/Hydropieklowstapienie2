#include "SoundsManager.h"
#include <SFML/Audio.hpp>
#include <thread>

void SoundsManager::playMusic()
{
 //   setBuffer();    
 ///*   SoundsManager *soundManager = new SoundsManager();
 //   thread th(&SoundsManager::setBuffer,soundManager);
 //   th.join();*/
 //   //delete soundManager;
 //   sf::Sound sound;
 //   sound.setBuffer(buffer);
 //   return sound;
    if (!music.openFromFile("sounds/My Heart Will Go On.wav"))
        std::cout << "Error: Could not open titanic sound" << std::endl;
}




