#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <pthread.h>
#include <memory.h>
#include <stdbool.h>
#include <semaphore.h>
#include <io.h>
#include <process.h>
#include <windows.h>
#include <chrono>
#include <thread>
//#include <unistd.h>
#include <stdint.h>
#include <stdexcept>
#include <string>
#include<iostream>
#include <map>
#include <vector>

using namespace std;
class CTowar {
private:
    int ilosc;
    std::string nazwa;
public:
    CTowar() { nazwa = ""; ilosc = 0; }
    void setNazwa(std::string _n) { nazwa = _n; }
    void setIlosc(int _i) { ilosc = _i; }
    void pisz() { cout << nazwa << ", ilosc: " << ilosc; }
  //  CTowar operator+(int);
};

int main() {
    std::map<std::string, int> dane;
    std::vector<int> v;

    for (map<std::string, int>::iterator it = dane.begin(); it != dane.end(); ++it) {
       //v.push_back(it->first);       
        cout << it->first << "\n";
    }
};
