# ifndef GameControllerH
# define GameControllerH
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Graphics\Color.hpp>
#include <list>
#include "ConfigModel.h"
#include <SFML/Graphics.hpp>


using namespace std;

/// <summary>
/// G��wna klasa obs�uguj�ca zdarzenie i zarz�dzaj�ca przebiegiem gry
/// <summary>
class GameController {
private:
public:
    /// <summary>
    /// Metoda tworz�ca okno gry
    /// </summary>
    /// <param name="playMusic"> parametr, czy w��czy� muzyk�</param>
    /// <param name="width"> szeroko�� okna</param>
    /// <param name="height">wysoko�� okna</param>
    void createWindowGame(bool playMusic, int width, int height);
};
#endif