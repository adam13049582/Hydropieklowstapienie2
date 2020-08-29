# ifndef GameControllerH
# define GameControllerH
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Graphics\Color.hpp>
#include <list>
#include "ConfigModel.h"
#include <SFML/Graphics.hpp>


using namespace std;

/// <summary>
/// G³ówna klasa obs³uguj¹ca zdarzenie i zarz¹dzaj¹ca przebiegiem gry
/// <summary>
class GameController {
private:
public:
    /// <summary>
    /// Metoda tworz¹ca okno gry
    /// </summary>
    /// <param name="playMusic"> parametr, czy w³¹czyæ muzykê</param>
    /// <param name="width"> szerokoœæ okna</param>
    /// <param name="height">wysokoœæ okna</param>
    void createWindowGame(bool playMusic, int width, int height);
};
#endif