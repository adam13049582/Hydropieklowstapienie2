# ifndef GameControllerH
# define GameControllerH
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Graphics\Color.hpp>

using namespace std;

class GameController {
private:
public:
    //Metoda generuj¹ca okno z menu g³ównym
    void createWindowGame(bool playMusic, int width, int height);
};
#endif