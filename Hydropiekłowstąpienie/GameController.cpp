#include <SFML/Graphics.hpp>
#include <time.h>
#include <stdlib.h>
#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Graphics\Sprite.hpp>
#include <iostream>
#include <SFML/Audio.hpp>
#include <windows.h>
#include <string>
#include <stdio.h>
#include "GameController.h"
#include "ConfigModel.h"
#include "FileReader.h"
#include "MapMaker.h"
#include "MainMenu.h"
#include "SoundsManager.h"
#include <list>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <locale>

/// <summary>
/// Metoda tworz¹ca okno gry
/// </summary>
/// <param name="playMusic"> parametr, czy w³¹czyæ muzykê</param>
/// <param name="width"> szerokoœæ okna</param>
/// <param name="height">wysokoœæ okna</param>
void GameController::createWindowGame(bool playMusic, int width,int height) {

    sf::RenderWindow window2(sf::VideoMode(width, height), "Hydropieklowstapienie", sf::Style::Default);
    sf::Texture background;
    sf::Sprite backgroundImage;
    FileReader fileReader;
    MainMenu menu;
    if (!background.loadFromFile("images/woda_morska.jpg"))
        std::cout << "Error: Could not display Menu_g³ówne image" << std::endl;

    backgroundImage.setTexture(background);
    backgroundImage.setScale(
        window2.getSize().x / backgroundImage.getLocalBounds().width,
        window2.getSize().y / backgroundImage.getLocalBounds().height);
    backgroundImage.setColor(sf::Color(250, 20, 20));
   
    sf::RectangleShape water(sf::Vector2f(0, 0));
    water.setSize(sf::Vector2f(window2.getSize().x, 100));
    water.setPosition(0, window2.getSize().y);

    water.setFillColor(sf::Color(0, 127, 255));

    MapMaker mapMaker;
    mapMaker.SetConfig();
    sf::RectangleShape stones = mapMaker.makeStonesElement(window2.getSize().x,window2.getSize().y);
    sf::RectangleShape ground = mapMaker.makeGroundElement(window2.getSize().x, stones.getPosition().y);
    sf::RectangleShape grass = mapMaker.makeGrassElement(window2.getSize().x, ground.getPosition().y);
    
    mapMaker.playMusic();
    if (playMusic)
        mapMaker.music.play();
       
        sf::Font font;
        int time = 0;

        if (!font.loadFromFile("fonts/impact.ttf"))
        {
            cout << "Couldn't load fonts impact" << endl;
        }

        //LOAD FONT AND TEXT
        sf::Text timerText;
        timerText.setFont(font);
        timerText.setPosition(10, 10);
        timerText.setCharacterSize(40);

        sf::Text info;
        info.setFont(font);
        info.setPosition(width-200, 10);
        info.setCharacterSize(15);
        info.setString("Nacisnij 'Esc' aby przerwac");

    window2.clear();
    window2.draw(backgroundImage);
    window2.draw(stones);
    window2.draw(ground);
    window2.draw(grass);
    window2.draw(water);
    window2.draw(info);
    window2.display();
    int heightOfWater;
    int scale;
    
    while (window2.isOpen())
    {
        if ((water.getPosition().y > stones.getPosition().y) && (water.getPosition().y < (stones.getPosition().y + stones.getSize().y))) {
            heightOfWater = water.getPosition().y - 4;
            scale = 1;
        }
        else if ((water.getPosition().y > ground.getPosition().y) && (water.getPosition().y < (ground.getPosition().y + ground.getSize().y))) {
            heightOfWater = water.getPosition().y - 6;
            scale = 2;
        }
        else if ((water.getPosition().y > grass.getPosition().y) && (water.getPosition().y < (grass.getPosition().y + grass.getSize().y))) {
            heightOfWater = water.getPosition().y - 8;
            scale = 3;
        }
        else {
            heightOfWater = water.getPosition().y - 10;
            scale = 3;
        }

        water.setPosition(0, heightOfWater);
        water.scale(1, scale);
        Sleep(1000);

            time++;
            std::string stime = std::to_string(time);
            timerText.setString(stime);

        window2.clear();
        window2.draw(backgroundImage);
        window2.draw(stones);
        window2.draw(ground);
        window2.draw(grass);
        window2.draw(water);
        window2.draw(timerText);
        window2.draw(info);

        window2.display();
        if (GetAsyncKeyState(VK_ESCAPE))
        {
            mapMaker.music.stop();
            mapMaker.music.pause();
            window2.close();
            menu.createWindowMenu();
        }
        if (heightOfWater <= 0) {
            int msgboxID = MessageBox(
                NULL,
                (L"Twoja mapa zostala zalana w czasie: "s + to_wstring(time) + L" sekund"s).c_str(),
                (LPCWSTR)L"Mapa zatopiona!!!",
                MB_ICONINFORMATION | MB_OK | MB_DEFBUTTON2
            );

            scale = 0;
            switch (msgboxID)
            {
            case IDOK:
                mapMaker.music.stop();
                mapMaker.music.pause();
                window2.close();
                menu.createWindowMenu();
               break;         
            }
            
        }        
    }
}
