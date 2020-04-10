# ifndef SoundsManagerH
# define SoundsManagerH
#include <iostream>
#include <SFML/Audio.hpp>


using namespace std;

class SoundsManager {
private:
	sf::SoundBuffer buffer;

public:	
	sf::Music* playMusic();
	void setBuffer();
};
#endif