# ifndef SettingsH
# define SettingsH
#include <iostream>

using namespace std;

/// <summary>
/// Klasa tworz�ca obs�uguj�ca zdarzenia w panelu Ustawienia
/// <summary>
class Settings {
	//szeroko�� okna
	int width = 1024;

	//wysoko�� okna
	int height = 622;

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
public:
	/// <summary>
	/// Metoda tworz�ca okno ustawie�
	/// </summary>
	void  createSettingWindow();

	
};
#endif