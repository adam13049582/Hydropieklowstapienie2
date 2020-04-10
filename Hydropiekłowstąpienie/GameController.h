# ifndef GameControllerH
# define GameControllerH
#include <SFML\Graphics\RenderWindow.hpp>

using namespace std;

class GameController {
private:
    bool playMusic = true;
public:
    //Metoda generuj¹ca okno z menu g³ównym
    void createWindowGame();
    void setPlayMusic(bool _i);
};
#endif