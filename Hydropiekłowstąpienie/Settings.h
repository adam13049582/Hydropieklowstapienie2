# ifndef SettingsH
# define SettingsH
#include <iostream>

using namespace std;

class Settings {
	int width = 1024;
	int height = 622;
public:
	void  createSettingWindow();
	void setWidth(int _i);
	void setHeight(int _i);
};
#endif