#include <iostream>
#include "FileReader.h"
#include <fstream>
#include <algorithm>
#include "ConfigModel.h"
#include <string>
#include <list>
#include <vector>

list<ConfigModel> FileReader::configRead() {
    std::ifstream cFile("config2.txt");
    list<ConfigModel> config;

    if (cFile.is_open())
    {
        std::string line;
        while (getline(cFile, line)) {
            line.erase(std::remove_if(line.begin(), line.end(), isspace),
                line.end());
            if (line[0] == '#' || line.empty())
                continue;
            auto delimiterPos = line.find("=");
            auto name = line.substr(0, delimiterPos);
            auto value = line.substr(delimiterPos + 1);
            ConfigModel conf;
            conf.key = name;
            conf.value = value;
                config.push_back(conf);
        }
    }
    else {
        std::cerr << "Couldn't open config file for reading.\n";
    }
    return config;
}
