# ifndef FileReaderH
# define FileReaderH
#include <iostream>
#include <fstream>
#include <algorithm>
#include "ConfigModel.h"
#include <string>
#include <list>

using namespace std;

class FileReader {
public:
    //Metoda generuj¹ca okno z menu g³ównym
    list<ConfigModel> configRead();
};
#endif