#include <SFML/Graphics.hpp>
#include <time.h>
#include <stdlib.h>
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Graphics\Sprite.hpp>
using namespace sf;
//const int M = 20;
//const int N = 10;
//
//int field[M][N] = { 0 };
//
//struct Point
//{
//    int x, y;
//} a[4], b[4];
//
//int figures[7][4] =
//{
//    1,3,5,7, // I
//    2,4,5,7, // Z
//    3,5,4,6, // S
//    3,5,4,7, // T
//    2,3,5,7, // L
//    3,5,7,6, // J
//    2,3,4,5, // O
//};
//
//bool check()
//{
//    for (int i = 0; i < 4; i++)
//        if (a[i].x < 0 || a[i].x >= N || a[i].y >= M) return 0;
//        else if (field[a[i].y][a[i].x]) return 0;
//
//    return 1;
//};
//
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <windows.h>
#include <string>
#include <iostream> 
#include "MainMenu.h"

        int main()
        {           
            MainMenu mainMenu;
            mainMenu.createWindowMenu2();
            return 0;	
	    }
