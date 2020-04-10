 # ifndef MainMenuh
 # define MainMenuh
using namespace std;

class MainMenu {
private:
    int width=1024;
    int height=622;
public:
    //Metoda generuj¹ca okno z menu g³ównym
	void createWindowMenu2();
    void setWidth(int _i);
    void setHeight(int _i);
};
#endif