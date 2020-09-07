# ifndef FileReaderH
# define FileReaderH
#include <iostream>
#include <fstream>
#include <algorithm>
#include "ConfigModel.h"
#include <string>
#include <list>

using namespace std;

/// <summary>
///Klasa do odczytu danych z pliku konfiguracyjnego
/// </summary>
class FileReader {
public:
	/// <summary>
	/// Metoda pobieraj�ca dane z konfiguracji
	///<returns> lista obiekt�w wczytanych z konfiguracji</returns>
	/// </summary>
	list<ConfigModel> configRead();
};
#endif