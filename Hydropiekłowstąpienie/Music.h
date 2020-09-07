# ifndef MusicHrH
# define MusicH
#include <iostream>
#include <SFML\Audio\Music.hpp>
#include <list>
#include "ConfigModel.h"
using namespace std;


/// <summary>
/// Klasa do zarz�dzania d�wi�kami
/// </summary>
class Music {

private:
	//lista przechowywuj�ca elementy konfiguracj�
	list<ConfigModel> Config;

public:
	//pole przechowuj�ce obiekt przechowuj�cy muzyk� do odtworzenia
	sf::Music music;

	/// <summary>
	/// Metoda wywo�uj�ca klas� wczytuj�c� konfiguracj� i przypisuj�ca warto�� polu Config
	/// </summary>
	void SetConfig();

	/// <summary>
	/// Metoda przetwarzaj�ca plik z muzyk�
	/// </summary>
	void playMusic();
};
#endif
