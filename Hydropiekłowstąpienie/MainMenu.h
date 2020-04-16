 # ifndef MainMenuh
 # define MainMenuh
using namespace std;

/// <summary>
/// Klasa tworz�ca i obs�uguj�ca dzia�anie menu
/// <summary>
class MainMenu {
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
    void createWindowMenu();

    /// <summary>
    /// Metoda ustawiaj�ca szeroko�� okna
    /// </summary>
    /// <param name="_i"> warto�� jak� trzeba przypisa� do parametru width</param>
    void setWidth(int _i);

    /// <summary>
    /// Metoda ustawiaj�ca szeroko�� okna
    /// </summary>
    /// <param name="_i"> warto�� jak� trzeba przypisa� do parametru height</param>
    void setHeight(int _i);

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