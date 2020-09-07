# ifndef configModelH
# define configModelH
#include <iostream>
#include <string>

using namespace std;

///<summary>
/// Model wartoœci zawartych w konfiguracji konfiguracji
/// </summary>
struct ConfigModel {

	/// <summary>
	/// Nazwa
	/// </summary>
	string key;

	/// <summary>
	/// Wartoœæ
	/// </summary>
	string value;
};

#endif