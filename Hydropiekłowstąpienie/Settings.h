# ifndef SettingsH
# define SettingsH
#include <iostream>

using namespace std;

/// <summary>
/// Klasa tworz¹ca obs³uguj¹ca zdarzenia w panelu Ustawienia
/// <summary>
class Settings {
	int width = 1024;
	int height = 622;
public:
	/// <summary>
	/// Metoda tworz¹ca okno ustawieñ
	/// </summary>
	void  createSettingWindow();

	/// <summary>
	/// Metoda ustawiaj¹ca szerokoœæ okna
	/// </summary>
	/// <param name="_i"> wartoœæ jak¹ trzeba przypisaæ do pola width</param>
	void setWidth(int _i);

	/// <summary>
	/// Metoda ustawiaj¹ca wysokoœæ okna
	/// </summary>
	/// <param name="_i"> wartoœæ jak¹ trzeba przypisaæ pola height</param>
	void setHeight(int _i);
};
#endif