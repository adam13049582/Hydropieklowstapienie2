# ifndef GameControllerH
# define GameControllerH
#include <SFML\Graphics\RenderWindow.hpp>

using namespace std;

class GameController {
private:
    bool playMusic = true;
public:
    //Metoda generuj�ca okno z menu g��wnym
    void createWindowGame();
    void setPlayMusic(bool _i);
};
#endif