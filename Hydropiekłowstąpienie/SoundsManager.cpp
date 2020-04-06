#include "SoundsManager.h"
#include <SFML/Audio.hpp>

sf::Sound SoundsManager::playMusic()
{
    setBuffer();

    sf::Sound sound;
    sound.setBuffer(buffer);
    return sound;
}

void SoundsManager::setBuffer()
{
    if (!buffer.loadFromFile("sounds/My Heart Will Go On.wav")) {
        std::cout << "Error: Could not open titanic sound" << std::endl;
    }
}

