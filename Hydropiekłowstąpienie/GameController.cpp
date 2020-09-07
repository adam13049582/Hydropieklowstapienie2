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
    
    if (!background.loadFromFile("images/tlo.jpg"))
        std::cout << "Error: Could not display Menu_g³ówne image" << std::endl;

    backgroundImage.setTexture(background);
    backgroundImage.setScale(
        window2.getSize().x / backgroundImage.getLocalBounds().width,
        window2.getSize().y / backgroundImage.getLocalBounds().height);
    backgroundImage.setColor(sf::Color(250, 20, 20));
   
    sf::RectangleShape water(sf::Vector2f(0, 0));

    water.setSize(sf::Vector2f(100, 100));
    water.setPosition(window2.getSize().x, window2.getSize().y-100);

    water.setFillColor(sf::Color(0, 127, 255));

  
    Music music;


    sf::CircleShape stones = stones22.makeStonesElement(window2.getSize().x,window2.getSize().y);
    sf::CircleShape ground = ground22.makeGroundElement(window2.getSize().x, window2.getSize().y);
    sf::RectangleShape grass = grass22.makeGrassElement(window2.getSize().x, window2.getSize().y);
   
    sf::RectangleShape water2(sf::Vector2f(0, 0));
    sf::RectangleShape water3(sf::Vector2f(0, 0));

    water2.setSize(sf::Vector2f(10, 100));
    water2.setPosition(ground.getPosition().x + 0.5*ground.getRadius(), window2.getSize().y - 100);

    water2.setFillColor(sf::Color(0, 127, 255));

    water3.setSize(sf::Vector2f(10, 100));
    water3.setPosition(stones.getPosition().x + stones.getRadius(), window2.getSize().y - 100);

    water3.setFillColor(sf::Color(0, 127, 255));

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
    int widthOfWater2=water2.getPosition().x;
    int widthOfWater3=water3.getPosition().x;

    int heightOfWater = 100;
    int heightOfWater2 = 10;
    int heightOfWater3 = 10;

    int scale;
    
    while (window2.isOpen())
    {
       sf::Vector2f waterPosF(static_cast<float>(water.getPosition().x), static_cast<float>(water.getPosition().y));

       if ((water.getPosition().x <= stones.getPosition().x + 2 * stones.getRadius()) && (water.getPosition().x >= stones.getPosition().x + stones.getRadius())) {//(stones.getGlobalBounds().contains(waterPosF)){
           widthOfWater = water.getPosition().x - 6;
           cout << "colission stone";
            scale = 1;
        }
           if ((water.getPosition().x <= ground.getPosition().x + 1.6 * ground.getRadius()) && (water.getPosition().x >= ground.getPosition().x + ground.getRadius())) {// && (water.getPosition().x <= ground.getPosition().x + ground.getRadius())
               if (water.getPosition().y >= ground.getPosition().y) 
               {
                   widthOfWater = ground.getPosition().x + ground.getRadius();
                   heightOfWater += 6;
               }
               else {
                   if(heightOfWater2<50)
                        heightOfWater2 += 3;

                   if ((water2.getPosition().x <= stones.getPosition().x + 2 * stones.getRadius()) && (water2.getPosition().x >= stones.getPosition().x + stones.getRadius())) {//(stones.getGlobalBounds().contains(waterPosF)){
                       
                       if (water2.getPosition().y >= stones.getPosition().y)
                       {
                           widthOfWater2 = stones.getPosition().x + stones.getRadius();
                           heightOfWater2 += 6;
                       }
                       else {
                           if (heightOfWater3 < 50)
                               heightOfWater3 += 3;

                           if ((water3.getPosition().x <= grass.getPosition().x + grass.getSize().x) && (water3.getPosition().x >= grass.getPosition().x)) {//(stones.getGlobalBounds().contains(waterPosF)){

                               widthOfWater3 = water3.getPosition().x - 8;
                           }
                           else if (water3.getPosition().x > 0) {
                               widthOfWater3 = water3.getPosition().x - 20;
                           }
                           else {
                               if (heightOfWater3 < water2.getSize().y) {
                                   heightOfWater3 += 10;
                               }
                               else{
                                   if (water2.getSize().y < water.getSize().y) {
                                       heightOfWater3 += 10;
                                       heightOfWater2 += 10;
                                   }
                                   else {
                                       heightOfWater3 += 10;
                                       heightOfWater2 += 10;
                                       heightOfWater += 10;
                                       if (heightOfWater >= window2.getSize().y && heightOfWater2 >= window2.getSize().y && heightOfWater3 >= window2.getSize().y) {
                                           heightOfWater = window2.getSize().y;
                                           heightOfWater2 = window2.getSize().y;
                                           heightOfWater3 = window2.getSize().y;
                                       }
                                   }
                               }
                           }
                       }
                   
                        scale = 1;
                   }
                   else if(water2.getPosition().x >= stones.getPosition().x + 2 * stones.getRadius()){
                       widthOfWater2 = water2.getPosition().x - 20;
                   }
           
               }
           }
      
        else {
               if (water.getPosition().y >= ground.getPosition().y || water.getPosition().x <= ground.getPosition().x + 1.6 * ground.getRadius())
               {
                   widthOfWater = water.getPosition().x - 20;
               }
            scale = 20;

        }
            float widthWat = water.getSize().x + widthOfWater;
            float widthWat2 = water2.getSize().x + widthOfWater2;
            float widthWat3 = water3.getSize().x + widthOfWater3;

        water.setPosition(widthOfWater, window2.getSize().y - heightOfWater);
        water.setSize(sf::Vector2f(widthWat, heightOfWater));
        water2.setPosition(widthOfWater2, window2.getSize().y - heightOfWater2);
        water2.setSize(sf::Vector2f(widthWat2, heightOfWater2));
        water3.setPosition(widthOfWater3, window2.getSize().y - heightOfWater3);
        water3.setSize(sf::Vector2f(widthWat3, heightOfWater3));
        Sleep(1000);

            time++;
            std::string stime = std::to_string(time);
            timerText.setString(stime);

        window2.clear();
        window2.draw(backgroundImage);
        window2.draw(water);
        window2.draw(grass);

        if (water.getPosition().y <= ground.getPosition().y) 
        {
            window2.draw(water2);
            window2.draw(water3);            
        }
        window2.draw(stones);
        window2.draw(ground);
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
        if (heightOfWater >= window2.getSize().y && heightOfWater2 >= window2.getSize().y && heightOfWater3 >= window2.getSize().y) {

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
