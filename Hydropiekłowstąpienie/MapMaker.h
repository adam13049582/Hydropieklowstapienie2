# ifndef MapMakerH
# define MapMakerH
#include <iostream>
#include <SFML\Audio\Music.hpp>

using namespace std;

/// <summary>
/// Klasa tworz¹ca elementy mapy
/// <summary>
class MapMaker {
private:
	//tablica z teksturami, które bêd¹ nanoszone na poszczególne elementy mapy
	sf::Texture textures[3];

	//lista przechowywuj¹ca elementy konfiguracjê
	list<ConfigModel> Config;

	/// <summary>
   /// Metoda wczytuj¹ca teksturê z pliku
   /// <param name="mapElementType"> typ obiektu na który bêdzie naniesiona tekstura(Enum castowany na int)</param>
   /// </summary>
	void setTexture(int mapElementType);

public:
	//pole przechowuj¹ce obiekt przechowuj¹cy muzykê do odtworzenia
	sf::Music music;

	/// <summary>
	/// Metoda wywo³uj¹ca klasê wczytuj¹c¹ konfiguracjê i przypisuj¹ca wartoœæ polu Config
	/// </summary>

	void SetConfig();

	/// <summary>
	/// Metoda nak³adaj¹ca teksturê na prostok¹t imitujacy roœliny
	/// <param name="windowWidth"> szerokoœæ okna</param>
	/// <param name="windowHeight">wysokoœæ okna</param>
	/// <returns> obiekt typu RectangleShape bêd¹cy elementem mapy, w tym przypadku Kamienie<returns>
	/// </summary>
	sf::CircleShape makeStonesElement(int windowWidth, int windowHeight);

	/// <summary>
	/// Metoda nak³adaj¹ca teksturê na prostok¹t imitujacy roœliny
	/// <param name="windowWidth"> szerokoœæ okna</param>
	/// <param name="positionofStones">wspó³rzêdna y prostok¹tu imituj¹cego kamienie</param>
	/// <returns> obiekt typu RectangleShape bêd¹cy elementem mapy, w tym przypadku Ziemia<returns>
	/// </summary>
	sf::CircleShape makeGroundElement(int windowWidth, int positionofStones);

	/// <summary>
	/// Metoda nak³adaj¹ca teksturê na prostok¹t imitujacy roœliny
	/// <param name="windowWidth"> szerokoœæ okna</param>
	/// <param name="positionofStones">wspó³rzêdna y prostok¹tu imituj¹cego kamienie</param>
	/// <returns> obiekt typu RectangleShape bêd¹cy elementem mapy, w tym przypadku Ziemia<returns>
	/// </summary>
	sf::RectangleShape makeGrassElement(int windowWidth, int positionofGround);

	/// <summary>
	/// Metoda przetwarzaj¹ca plik z muzyk¹
	/// </summary>
	void playMusic();
};
#endif
