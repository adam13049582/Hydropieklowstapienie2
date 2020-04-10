#include "SoundsManager.h"
#include <SFML/Audio.hpp>
#include <thread>

sf::Music* SoundsManager::playMusic()
{
 //   setBuffer();    
 ///*   SoundsManager *soundManager = new SoundsManager();
 //   thread th(&SoundsManager::setBuffer,soundManager);
 //   th.join();*/
 //   //delete soundManager;
 //   sf::Sound sound;
 //   sound.setBuffer(buffer);
 //   return sound;
    sf::Music music;
    if (!music.openFromFile("sounds/My Heart Will Go On.wav"))
        std::cout << "Error: Could not open titanic sound" << std::endl;
    return &music;
}

void SoundsManager::setBuffer()
{

    if (!buffer.loadFromFile("sounds/My Heart Will Go On.wav")) {
        std::cout << "Error: Could not open titanic sound" << std::endl;
    }
}

