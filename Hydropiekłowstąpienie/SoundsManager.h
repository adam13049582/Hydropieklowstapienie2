# ifndef SoundsManagerH
# define SoundsManagerH
#include <iostream>
#include <SFML/Audio.hpp>


using namespace std;

class SoundsManager {
private:

public:	
	sf::Music music;

	void playMusic();
};
#endif