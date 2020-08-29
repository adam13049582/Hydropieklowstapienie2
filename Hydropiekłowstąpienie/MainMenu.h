 # ifndef MainMenuh
 # define MainMenuh

#include "WindowCreator.h"

using namespace std;

/// <summary>
/// Klasa tworz�ca i obs�uguj�ca dzia�anie menu
/// <summary>
class MainMenu : public WindowCreator {
private:
    //szeroko�� okna
    int width=1024;

    //wysoko�� okna
    int height=622;

    //pole definiuj�ce, czy odtwarza� muzyk�
    bool playMusic;

public:
    /// <summary>
    /// Metoda tworz�ca okno menu
    /// </summary>
    void createWindow(bool playMusic, int width, int height);

    /// <summary>
    /// Metoda ustawiaj�ca szeroko�� okna
    /// </summary>
    /// <param name="_i"> warto�� jak� trzeba przypisa� do parametru width</param>
    void setWidth(int _i);

    /// <summary>
    /// Metoda ustawiaj�ca wysoko�� okna
    /// </summary>
    /// <param name="_i"> warto�� jak� trzeba przypisa� do parametru height</param>
    void setHeight(int _i);

    /// <summary>
   /// Metoda pobieraj�ca szeroko�� okna
   /// </summary>
   /// <param name="_i"> warto�� jak� trzeba przypisa� do parametru width</param>
    int getWidth();

    /// <summary>
    /// Metoda pobieraj�ca wysoko�� okna
    /// </summary>
    /// <param name="_i"> warto�� jak� trzeba przypisa� do parametru height</param>
    int getHeight();

    /// <summary>
    /// Metoda ustawiaj�ca parametr, czy odtwarza� muzyk�
    /// </summary>
    /// <param name="_i"> warto�� jak� trzeba przypisa� do parametru playMusic</param>
    void setPlayMusic(bool _i);

    /// <summary>
    /// Metoda ustawiaj�ca pobieraj�ca warto�� z pola playMusic
    /// <returns>warto�� pola playMusic</returns>
    /// </summary>
    bool getPlayMusic();
};
#endif