# ifndef GameControllerH
# define GameControllerH
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Graphics\Color.hpp>

using namespace std;

class GameController {
private:
public:
    //Metoda generuj�ca okno z menu g��wnym
    void createWindowGame(bool playMusic, int width, int height);
};
#endif