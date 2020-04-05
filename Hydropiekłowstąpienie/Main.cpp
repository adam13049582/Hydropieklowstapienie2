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
            //sf::RenderWindow window(sf::VideoMode(1024, 622), "Hydropiek³owst¹pienie", sf::Style::Default);

            //sf::Texture background;
            //sf::Sprite backgroundImage;

            //if (!background.loadFromFile("images/Menu_g³ówne.jpg"))
            //    std::cout << "Error: Could not display Alaskan Wilderness image" << std::endl;

            //backgroundImage.setTexture(background);
            //backgroundImage.setScale(
            //    window.getSize().x / backgroundImage.getLocalBounds().width,
            //    window.getSize().y / backgroundImage.getLocalBounds().height);
            ///*sf::Font font;
            //if (!font.loadFromFile("MATURASC.TTF"))
            //    std::cout << "Can't find the font file" << std::endl;*/

            //sf::Texture newGameButton;
            //sf::Sprite newGameButtonImage;
            //if (!newGameButton.loadFromFile("images/button.png"))
            //    std::cout << "Can't find the image" << std::endl;
            //newGameButtonImage.setPosition(440.0f, 140.0f);
            //newGameButtonImage.setScale(1.0f, 1.3f);
            //newGameButtonImage.setTexture(newGameButton);


            //sf::Texture settingsButton;
            //sf::Sprite settingsButtonImage;
            //if (!settingsButton.loadFromFile("images/button.png"))
            //    std::cout << "Can't find the image" << std::endl;
            //settingsButtonImage.setPosition(380.0f, 220.0f);
            //settingsButtonImage.setTexture(settingsButton);
            //settingsButtonImage.setScale(2.6f, 1.3f);

            //sf::Texture exitButton;
            //sf::Sprite exitButtonImage;
            //if (!exitButton.loadFromFile("images/button.png"))
            //    std::cout << "Can't find the image" << std::endl;
            //exitButtonImage.setPosition(440.0f, 310.0f);
            //exitButtonImage.setScale(1.0f, 1.3f);
            //exitButtonImage.setTexture(exitButton);
            //window.clear();
            //window.draw(backgroundImage);
            //window.draw(newGameButtonImage);
            //window.draw(settingsButtonImage);
            //window.draw(exitButtonImage);
            //window.display();

            //while (window.isOpen())
            //{
            //    sf::Event Event;
            //    while (window.pollEvent(Event))
            //    {
            //        switch (Event.type)
            //        {
            //        case sf::Event::Closed:
            //            window.close();
            //            break;
            //        case sf::Event::MouseMoved:
            //        {
            //            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            //            sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
            //            if (newGameButtonImage.getGlobalBounds().contains(mousePosF))
            //            {
            //                newGameButtonImage.setColor(sf::Color(250, 20, 20));
            //            }
            //            else
            //            {
            //                newGameButtonImage.setColor(sf::Color(255, 255, 255));
            //            }
            //        }
            //        break;
            //        case sf::Event::MouseButtonPressed:
            //        {
            //            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            //            sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
            //            if (newGameButtonImage.getGlobalBounds().contains(mousePosF))
            //            {
            //                sf::RenderWindow window2(sf::VideoMode(1024, 622), "Survival Game", sf::Style::Default);
            //                 backgroundImage.setColor(sf::Color(250, 20, 20));
            //                sf::RectangleShape rectangle(sf::Vector2f(120, 50));
            //                rectangle.setSize(sf::Vector2f(1024, 100));
            //                rectangle.setPosition(0, 622);
            //                rectangle.setFillColor(sf::Color(0, 127, 255));

            //                sf::RectangleShape rectangle2(sf::Vector2f(120, 50));
            //                rectangle2.setSize(sf::Vector2f(1024, 100));
            //                rectangle2.setPosition(200, 400);
            //                rectangle2.setFillColor(sf::Color(0, 255, 255));

            //                window2.clear();
            //                window2.draw(backgroundImage);
            //                window2.draw(rectangle2);
            //                window2.draw(rectangle);
            //                window2.display();
            //                int height;
            //                int scale;
            //                while (window2.isOpen())
            //                {
            //                    window.close();
            //                    if ((rectangle.getPosition().y > rectangle2.getPosition().y) && (rectangle.getPosition().y<(rectangle2.getPosition().y+rectangle2.getSize().y))) {
            //                        height = rectangle.getPosition().y -2 ;
            //                        scale = 2;
            //                        std::cout << "Collision!" << std::endl;

            //                    }
            //                    else {
            //                         height = rectangle.getPosition().y - 10;
            //                         scale = 10;
            //                    }
            //                    
            //                            rectangle.setPosition(0, height);
            //                            rectangle.scale(1, scale);
            //                            Sleep(1000);
            //                            window2.clear();
            //                            window2.draw(backgroundImage);
            //                            window2.draw(rectangle2);
            //                            window2.draw(rectangle);
            //                            window2.display();
            //                    std::cout << "Window2!" << std::endl;
            //                }
            //                

            //                
            //                ////std::cout << "Clicked, Start!" << std::endl;
            //            }
            //            else if (settingsButtonImage.getGlobalBounds().contains(mousePosF))
            //            {
            //                std::cout << "Clicked, Settings!" << std::endl;
            //            }
            //            else if (exitButtonImage.getGlobalBounds().contains(mousePosF))
            //            {
            //                std::cout << "Clicked, Exit!" << std::endl;
            //                window.close();
            //            }
            //        }
            //        break;
            //        }
            //    }

             
          //  }
         
            MainMenu mainMenu;
            mainMenu.createWindowMenu2();
            return 0;
	/*	srand(time(0));

		RenderWindow window(VideoMode(800, 600), "Hydropiek³owst¹pienie");
        Texture t1, t2, t3;
        t1.loadFromFile("images/tiles.png");
        t2.loadFromFile("images/woda_morska.jpg");*/
      ///  t3.loadFromFile("images/frame.png");

        //Sprite s(t1), background(t2);// , frame(t3);

        //int dx = 0; bool rotate = 0; int colorNum = 1;
        //float timer = 0, delay = 0.3;

        //Clock clock;

      /*  while (window.isOpen())
        {*/
            //    float time = clock.getElapsedTime().asSeconds();
            //    clock.restart();
            //    timer += time;

            //    Event e;
            //    while (window.pollEvent(e))
            //    {
            //        if (e.type == Event::Closed)
            //            window.close();

            //        if (e.type == Event::KeyPressed)
            //            if (e.key.code == Keyboard::Up) rotate = true;
            //            else if (e.key.code == Keyboard::Left) dx = -1;
            //            else if (e.key.code == Keyboard::Right) dx = 1;
            //    }

            //    if (Keyboard::isKeyPressed(Keyboard::Down)) delay = 0.05;

            //    //// <- Move -> ///
            //    for (int i = 0; i < 4; i++) { b[i] = a[i]; a[i].x += dx; }
            //    if (!check()) for (int i = 0; i < 4; i++) a[i] = b[i];

            //    //////Rotate//////
            //    if (rotate)
            //    {
            //        Point p = a[1]; //center of rotation
            //        for (int i = 0; i < 4; i++)
            //        {
            //            int x = a[i].y - p.y;
            //            int y = a[i].x - p.x;
            //            a[i].x = p.x - x;
            //            a[i].y = p.y + y;
            //        }
            //        if (!check()) for (int i = 0; i < 4; i++) a[i] = b[i];
            //    }

            //    ///////Tick//////
            //    if (timer > delay)
            //    {
            //        for (int i = 0; i < 4; i++) { b[i] = a[i]; a[i].y += 1; }

            //        if (!check())
            //        {
            //            for (int i = 0; i < 4; i++) field[b[i].y][b[i].x] = colorNum;

            //            colorNum = 1 + rand() % 7;
            //            int n = rand() % 7;
            //            for (int i = 0; i < 4; i++)
            //            {
            //                a[i].x = figures[n][i] % 2;
            //                a[i].y = figures[n][i] / 2;
            //            }
            //        }

            //        timer = 0;
            //    }

            //    ///////check lines//////////
            //    int k = M - 1;
            //    for (int i = M - 1; i > 0; i--)
            //    {
            //        int count = 0;
            //        for (int j = 0; j < N; j++)
            //        {
            //            if (field[i][j]) count++;
            //            field[k][j] = field[i][j];
            //        }
            //        if (count < N) k--;
            //    }

            //    dx = 0; rotate = 0; delay = 0.3;

            //    /////////draw//////////
            //    window.clear(Color::White);
            //    window.draw(background);

            //    for (int i = 0; i < M; i++)
            //        for (int j = 0; j < N; j++)
            //        {
            //            if (field[i][j] == 0) continue;
            //            s.setTextureRect(IntRect(field[i][j] * 18, 0, 18, 18));
            //            s.setPosition(j * 18, i * 18);
            //            s.move(28, 31); //offset
            //            window.draw(s);
            //        }

            //    for (int i = 0; i < 4; i++)
            //    {
            //        s.setTextureRect(IntRect(colorNum * 18, 0, 18, 18));
            //        s.setPosition(a[i].x * 18, a[i].y * 18);
            //        s.move(28, 31); //offset
            //        window.draw(s);
            //    }

            /*window.draw(background);
            window.display();
        }
        return 0;*/

	}
