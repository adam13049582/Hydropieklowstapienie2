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
#include "MainMenu.h"
#include "SoundsManager.h"
#include <list>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <locale>
#include "Ground.h"
#include "Stones.h"
#include "Grass.h"
#include "Music.h"
#include "MapElementTypes.h"

/// <summary>
/// Metoda tworz¹ca okno gry
/// </summary>
/// <param name="playMusic"> parametr, czy w³¹czyæ muzykê</param>
/// <param name="width"> szerokoœæ okna</param>
/// <param name="height">wysokoœæ okna</param>
void GameController::createWindow(bool playMusic, int width,int height) {

    sf::RenderWindow window2(sf::VideoMode(width, height), "Hydropieklowstapienie", sf::Style::Default);
    sf::Texture background;
    sf::Sprite backgroundImage;
    FileReader fileReader;
    WindowCreator* menu= new MainMenu();
    Ground ground22;
    Stones stones22;
    Grass grass22;
    ground22.flooding(1);
    stones22.flooding(2);

    if (!background.loadFromFile("images/tlo.jpg"))
        std::cout << "Error: Could not display Menu_g³ówne image" << std::endl;

    backgroundImage.setTexture(background);
    backgroundImage.setScale(
        window2.getSize().x / backgroundImage.getLocalBounds().width,
        window2.getSize().y / backgroundImage.getLocalBounds().height);
    backgroundImage.setColor(sf::Color(250, 20, 20));
   
    sf::RectangleShape water(sf::Vector2f(0, 0));
    sf::RectangleShape water2(sf::Vector2f(0, 0));
    sf::RectangleShape water3(sf::Vector2f(0, 0));

    water.setSize(sf::Vector2f(100, 100));
    water.setPosition(window2.getSize().x, window2.getSize().y-100);

    water.setFillColor(sf::Color(0, 127, 255));

    water2.setSize(sf::Vector2f(100, 100));
    water2.setPosition(window2.getSize().x, window2.getSize().y - 100);

    water2.setFillColor(sf::Color(0, 127, 255));

    water3.setSize(sf::Vector2f(100, 100));
    water3.setPosition(window2.getSize().x, window2.getSize().y - 100);

    water3.setFillColor(sf::Color(0, 127, 255));
    Music music;


    sf::CircleShape stones = stones22.makeStonesElement(window2.getSize().x,window2.getSize().y);
    sf::CircleShape ground = ground22.makeGroundElement(window2.getSize().x, window2.getSize().y);
    sf::RectangleShape grass = grass22.makeGrassElement(window2.getSize().x, window2.getSize().y);
   
    Area area;

    music.playMusic();
    if (playMusic)
        music.music.play();
       
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
    int widthOfWater;
    int heightOfWater = 100;
    int scale;
    
    while (window2.isOpen())
    {
       sf::Vector2f waterPosF(static_cast<float>(water.getPosition().x), static_cast<float>(water.getPosition().y));

       if ((water.getPosition().x <= stones.getPosition().x + 2 * stones.getRadius()) && (water.getPosition().x >= stones.getPosition().x + stones.getRadius())) {//(stones.getGlobalBounds().contains(waterPosF)){
           widthOfWater = water.getPosition().x - 4;
           cout << "colission stone";
           // scale = 1;
        }
     //  if (ground.getGlobalBounds().contains(waterPosF)) {
           if ((water.getPosition().x <= ground.getPosition().x + 1.6 * ground.getRadius()) && (water.getPosition().x >= ground.getPosition().x + ground.getRadius())) {// && (water.getPosition().x <= ground.getPosition().x + ground.getRadius())
               //water.setSize(sf::Vector2f(water.getSize().x, water.getSize().y+20));
               cout << "colission ground";
               if (water.getPosition().y >= ground.getPosition().y) 
               {
                   //water.setPosition(ground.getPosition().x + ground.getRadius(), water.getPosition().y);
                   widthOfWater = ground.getPosition().x + ground.getRadius();
                  // water.setSize(sf::Vector2f(window2.getSize().x-(ground.getPosition().x + ground.getRadius()),heightOfWater));
                   heightOfWater += 4;
               }
               else {
                   widthOfWater = water.getPosition().x - 4;
               }
           }
          /* cout << "colission ground";
           widthOfWater = water.getPosition().x - 2;
           heightOfWater += 4;*/
           // scale = 2;
       // }
        else if (grass.getGlobalBounds().contains(waterPosF)) {
           widthOfWater = water.getPosition().x - 8;
            scale = 3;
        }
        else {
            widthOfWater = water.getPosition().x - 20;
            scale = 20;
        }
            float widthWat = water.getSize().x + widthOfWater;
          //  float heightWat = water.getSize().y +;
        water.setPosition(widthOfWater, window2.getSize().y - heightOfWater);
        water.setSize(sf::Vector2f(widthWat, heightOfWater));
        Sleep(1000);

            time++;
            std::string stime = std::to_string(time);
            timerText.setString(stime);

        window2.clear();
        window2.draw(backgroundImage);
        window2.draw(water);

        window2.draw(stones);
        window2.draw(ground);
        window2.draw(grass);
        window2.draw(timerText);
        window2.draw(info);

        window2.display();
        if (GetAsyncKeyState(VK_ESCAPE))
        {
            music.music.stop();
            music.music.pause();
            window2.close();
            menu->createWindow(false,  width,  height);
        }
        if (widthOfWater <= 0) {
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
                music.music.stop();
                music.music.pause();
                window2.close();
                menu->createWindow(false, width, height);
               break;         
            }
            
        }        
    }
}
