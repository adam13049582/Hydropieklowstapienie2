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
void GameController::createWindowGame(bool playMusic, int width,int height) {

    sf::RenderWindow window2(sf::VideoMode(width, height), "Hydropieklowstapienie", sf::Style::Default);
    sf::Texture background;
    sf::Sprite backgroundImage;
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
    //sf::Texture texture;
    //if (!texture.loadFromFile("images/woda_test.jpg"))
    //    std::cout << "Error: Could not display kamienie image" << std::endl;
    //water.setTexture(&texture);

    water.setFillColor(sf::Color(0, 127, 255));

    MapMaker mapMaker;
    sf::RectangleShape stones = mapMaker.makeStonesElement(window2.getSize().x,window2.getSize().y);
    sf::RectangleShape ground = mapMaker.makeGroundElement(window2.getSize().x, stones.getPosition().y);
    sf::RectangleShape grass = mapMaker.makeGrassElement(window2.getSize().x, ground.getPosition().y);

        sf::Music music;
        if (!music.openFromFile("sounds/My Heart Will Go On.wav"))
            std::cout << "Error: Could not open titanic sound" << std::endl;
        if (playMusic)
             music.play();
       
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
        
    window2.clear();
    window2.draw(backgroundImage);
    window2.draw(stones);
    window2.draw(ground);
    window2.draw(grass);

    window2.draw(water);
    window2.display();
   // window2.setActive(false);
    int heightOfWater;
    int scale;
    
    while (window2.isOpen())
    {
        if ((water.getPosition().y > stones.getPosition().y) && (water.getPosition().y < (stones.getPosition().y + stones.getSize().y))) {
            heightOfWater = water.getPosition().y - 2;
            scale = 2;
            std::cout << "Collision Stones!" << std::endl;

        }
        else if ((water.getPosition().y > ground.getPosition().y) && (water.getPosition().y < (ground.getPosition().y + ground.getSize().y))) {
            heightOfWater = water.getPosition().y - 2;
            scale = 4;
            std::cout << "Collision Ground!" << std::endl;
        }
        else if ((water.getPosition().y > grass.getPosition().y) && (water.getPosition().y < (grass.getPosition().y + grass.getSize().y))) {
            heightOfWater = water.getPosition().y - 2;
            scale = 6;
            std::cout << "Collision Grass!" << std::endl;

        }
        else {
            heightOfWater = water.getPosition().y - 10;
            scale = 10;
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
        window2.display();
        if (heightOfWater == 600) {
            std::stringstream ss;
            ss << "Twoja mapa zosta³a zalana w czasie: " << stime << " sekund";
            std::string s = ss.str();
            int msgboxID = MessageBox(
                NULL,
                (LPCWSTR)L"Twoja mapa zosta³a zalana w czasie:", //" << stime << " sekund",
                (LPCWSTR)L"Mapa zatopiona!!!",
                MB_ICONINFORMATION | MB_OK | MB_DEFBUTTON2
            );

            scale = 0;
            switch (msgboxID)
            {
            case IDOK:
                music.stop();
                music.pause();
                window2.close();
                menu.createWindowMenu2();
                music.stop();
                music.pause();
               break;         
            }
            
        }
        std::cout << "Window2!" << std::endl;
        
    }
}
