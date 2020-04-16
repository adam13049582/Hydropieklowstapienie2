 # ifndef MainMenuh
 # define MainMenuh
using namespace std;

/// <summary>
/// Klasa tworz¹ca i obs³uguj¹ca dzia³anie menu
/// <summary>
class MainMenu {
private:
    //szerokoœæ okna
    int width=1024;

    //wysokoœæ okna
    int height=622;

    //pole definiuj¹ce, czy odtwarzaæ muzykê
    bool playMusic;

public:
    /// <summary>
    /// Metoda tworz¹ca okno menu
    /// </summary>
    void createWindowMenu();

    /// <summary>
    /// Metoda ustawiaj¹ca szerokoœæ okna
    /// </summary>
    /// <param name="_i"> wartoœæ jak¹ trzeba przypisaæ do parametru width</param>
    void setWidth(int _i);

    /// <summary>
    /// Metoda ustawiaj¹ca szerokoœæ okna
    /// </summary>
    /// <param name="_i"> wartoœæ jak¹ trzeba przypisaæ do parametru height</param>
    void setHeight(int _i);

    /// <summary>
    /// Metoda ustawiaj¹ca parametr, czy odtwarzaæ muzykê
    /// </summary>
    /// <param name="_i"> wartoœæ jak¹ trzeba przypisaæ do parametru playMusic</param>
    void setPlayMusic(bool _i);

    /// <summary>
    /// Metoda ustawiaj¹ca pobieraj¹ca wartoœæ z pola playMusic
    /// <returns>wartoœæ pola playMusic</returns>
    /// </summary>
    bool getPlayMusic();
};
#endif