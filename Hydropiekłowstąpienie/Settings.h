# ifndef SettingsH
# define SettingsH
#include <iostream>

using namespace std;

/// <summary>
/// Klasa tworz�ca obs�uguj�ca zdarzenia w panelu Ustawienia
/// <summary>
class Settings {
	int width = 1024;
	int height = 622;
public:
	/// <summary>
	/// Metoda tworz�ca okno ustawie�
	/// </summary>
	void  createSettingWindow();

	/// <summary>
	/// Metoda ustawiaj�ca szeroko�� okna
	/// </summary>
	/// <param name="_i"> warto�� jak� trzeba przypisa� do pola width</param>
	void setWidth(int _i);

	/// <summary>
	/// Metoda ustawiaj�ca wysoko�� okna
	/// </summary>
	/// <param name="_i"> warto�� jak� trzeba przypisa� pola height</param>
	void setHeight(int _i);
};
#endif