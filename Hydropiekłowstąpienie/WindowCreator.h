# ifndef WindowCreatorh
# define WindowCreatorh

/// <summary>
/// podstawowa klasa do tworzenia okien gry
/// </summary>
class WindowCreator {

public:
    /// <summary>
    /// Metoda tworz¹ca okno 
    /// </summary>
    virtual void createWindow(bool playMusic, int width, int height);

};
#endif
