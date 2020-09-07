#include <stdlib.h>
#include <string>
#include "FileReader.h"
#include "Music.h"
#include <vector>

/// <summary>
/// Metoda wywo�uj�ca klas� wczytuj�c� konfiguracj� i przypisuj�ca warto�� polu Config
/// </summary>
void Music::SetConfig()
{
    FileReader fileReader;
    Config = fileReader.configRead();  
}

/// <summary>
/// Metoda przetwarzaj�ca plik z muzyk�
/// </summary>
void Music::playMusic()
{
    SetConfig();
    std::vector < ConfigModel > vecOfStr(Config.begin(), Config.end());
    string fileName;
    for (ConfigModel str : vecOfStr) {
        if (str.key == "muzyka")
            fileName = "sounds/" + str.value;
    }
    if (!music.openFromFile(fileName))
        std::cout << "Error: Could not open titanic sound" << std::endl;
}