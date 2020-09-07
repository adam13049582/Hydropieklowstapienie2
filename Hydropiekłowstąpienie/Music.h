# ifndef MusicHrH
# define MusicH
#include <iostream>
#include <SFML\Audio\Music.hpp>
#include <list>
#include "ConfigModel.h"
using namespace std;


/// <summary>
/// Klasa do zarz¹dzania dŸwiêkami
/// </summary>
class Music {

private:
	//lista przechowywuj¹ca elementy konfiguracjê
	list<ConfigModel> Config;

public:
	//pole przechowuj¹ce obiekt przechowuj¹cy muzykê do odtworzenia
	sf::Music music;

	/// <summary>
	/// Metoda wywo³uj¹ca klasê wczytuj¹c¹ konfiguracjê i przypisuj¹ca wartoœæ polu Config
	/// </summary>
	void SetConfig();

	/// <summary>
	/// Metoda przetwarzaj¹ca plik z muzyk¹
	/// </summary>
	void playMusic();
};
#endif
