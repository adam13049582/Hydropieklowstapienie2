# ifndef MapMakerH
# define MapMakerH
#include <iostream>
#include <SFML\Audio\Music.hpp>

using namespace std;

/// <summary>
/// Klasa tworz�ca elementy mapy
/// <summary>
class MapMaker {
private:
	//tablica z teksturami, kt�re b�d� nanoszone na poszczeg�lne elementy mapy
	sf::Texture textures[3];

	//lista przechowywuj�ca elementy konfiguracj�
	list<ConfigModel> Config;

	/// <summary>
   /// Metoda wczytuj�ca tekstur� z pliku
   /// <param name="mapElementType"> typ obiektu na kt�ry b�dzie naniesiona tekstura(Enum castowany na int)</param>
   /// </summary>
	void setTexture(int mapElementType);

public:
	//pole przechowuj�ce obiekt przechowuj�cy muzyk� do odtworzenia
	sf::Music music;

	/// <summary>
	/// Metoda wywo�uj�ca klas� wczytuj�c� konfiguracj� i przypisuj�ca warto�� polu Config
	/// </summary>

	void SetConfig();

	/// <summary>
	/// Metoda nak�adaj�ca tekstur� na prostok�t imitujacy ro�liny
	/// <param name="windowWidth"> szeroko�� okna</param>
	/// <param name="windowHeight">wysoko�� okna</param>
	/// <returns> obiekt typu RectangleShape b�d�cy elementem mapy, w tym przypadku Kamienie<returns>
	/// </summary>
	sf::CircleShape makeStonesElement(int windowWidth, int windowHeight);

	/// <summary>
	/// Metoda nak�adaj�ca tekstur� na prostok�t imitujacy ro�liny
	/// <param name="windowWidth"> szeroko�� okna</param>
	/// <param name="positionofStones">wsp�rz�dna y prostok�tu imituj�cego kamienie</param>
	/// <returns> obiekt typu RectangleShape b�d�cy elementem mapy, w tym przypadku Ziemia<returns>
	/// </summary>
	sf::CircleShape makeGroundElement(int windowWidth, int positionofStones);

	/// <summary>
	/// Metoda nak�adaj�ca tekstur� na prostok�t imitujacy ro�liny
	/// <param name="windowWidth"> szeroko�� okna</param>
	/// <param name="positionofStones">wsp�rz�dna y prostok�tu imituj�cego kamienie</param>
	/// <returns> obiekt typu RectangleShape b�d�cy elementem mapy, w tym przypadku Ziemia<returns>
	/// </summary>
	sf::RectangleShape makeGrassElement(int windowWidth, int positionofGround);

	/// <summary>
	/// Metoda przetwarzaj�ca plik z muzyk�
	/// </summary>
	void playMusic();
};
#endif
