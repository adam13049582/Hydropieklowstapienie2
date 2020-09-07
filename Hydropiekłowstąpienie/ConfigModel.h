# ifndef configModelH
# define configModelH
#include <iostream>
#include <string>

using namespace std;

///<summary>
/// Model warto�ci zawartych w konfiguracji konfiguracji
/// </summary>
struct ConfigModel {

	/// <summary>
	/// Nazwa
	/// </summary>
	string key;

	/// <summary>
	/// Warto��
	/// </summary>
	string value;
};

#endif