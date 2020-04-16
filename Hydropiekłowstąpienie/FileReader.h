# ifndef FileReaderH
# define FileReaderH
#include <iostream>
#include <fstream>
#include <algorithm>
#include "ConfigModel.h"
#include <string>
#include <list>

using namespace std;

///summary
///Klasa do odczytu danych z pliku konfiguracyjnego
///summary
class FileReader {
public:
	/// <summary>
	/// Metoda pobieraj¹ca dane z konfiguracji
	/// </summary>
	///<returns> lista obiektów wczytanych z konfiguracji</returns>
	list<ConfigModel> configRead();
};
#endif