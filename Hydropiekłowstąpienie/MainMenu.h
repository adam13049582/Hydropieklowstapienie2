 # ifndef MainMenuh
 # define MainMenuh
using namespace std;

class MainMenu {
private:
    int width=1024;
    int height=622;
public:
    //Metoda generuj�ca okno z menu g��wnym
	void createWindowMenu2();
    void setWidth(int _i);
    void setHeight(int _i);
};
#endif