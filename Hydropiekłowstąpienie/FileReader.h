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
    //Metoda generuj�ca okno z menu g��wnym
    list<ConfigModel> configRead();
};
#endif