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
    //POLIMORFIZM
    void createWindow(bool playMusic, int width, int height);

    /// <summary>
    /// Metoda ustawiaj�ca szeroko�� okna
    /// <param name="_i"> warto�� jak� trzeba przypisa� do parametru width</param>
    /// </summary>
    void setWidth(int _i);

    /// <summary>
    /// Metoda ustawiaj�ca wysoko�� okna
    /// </summary>
    /// <param name="_i"> warto�� jak� trzeba przypisa� do parametru height</param>
    void setHeight(int _i);

    /// <summary>
   /// Metoda pobieraj�ca szeroko�� okna
   /// <param name="_i"> warto�� jak� trzeba przypisa� do parametru width</param>
   /// </summary>
    int getWidth();

    /// <summary>
    /// Metoda pobieraj�ca wysoko�� okna
    /// <param name="_i"> warto�� jak� trzeba przypisa� do parametru height</param>
    /// </summary>
    int getHeight();

    /// <summary>
    /// Metoda ustawiaj�ca parametr, czy odtwarza� muzyk�
    /// <param name="_i"> warto�� jak� trzeba przypisa� do parametru playMusic</param>
    /// </summary>
    void setPlayMusic(bool _i);

    /// <summary>
    /// Metoda ustawiaj�ca pobieraj�ca warto�� z pola playMusic
    /// <returns>warto�� pola playMusic</returns>
    /// </summary>
    bool getPlayMusic();
};
#endif