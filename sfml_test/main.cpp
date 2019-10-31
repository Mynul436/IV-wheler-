#include <iostream>
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<sstream>
using namespace std;
using namespace sf;
int main()
{

    RenderWindow win(VideoMode(600, 900), "IV Wheeler");
  a:
      {


    RectangleShape rect(Vector2f(230,53));
    RectangleShape rect1(Vector2f(100,50));
    RectangleShape rect2(Vector2f(100,50));
    RectangleShape rect3(Vector2f(95,45));

    rect.setPosition(Vector2f(181,76));
    rect1.setPosition(Vector2f(1234,1234));
    rect2.setPosition(Vector2f(1234,1234));
    rect3.setPosition(Vector2f(1234,1234));


    rect.setOutlineThickness(20);
    rect3.setOutlineThickness(10);

    rect.setOutlineColor(Color::Green);
    rect3.setOutlineColor(Color::Green);

    rect.setFillColor(Color::Transparent);
    rect3.setFillColor(Color::Transparent);

    Texture mainmenu;
    Texture road;
    Texture car;
    Texture car2;
    Texture gameover;
    Texture scoreboard;

    road.setSmooth(true);
    car.setSmooth(true);
    car2.setSmooth(true);
    gameover.setSmooth(true);
    scoreboard.setSmooth(true);

    mainmenu.loadFromFile("picture/screen1.jpeg");
    road.loadFromFile("picture/road2.jpg");
    car.loadFromFile("picture/car3.png");
    car2.loadFromFile("picture/car2.png");
    gameover.loadFromFile("picture/screen.jpeg");
    scoreboard.loadFromFile("picture/scoreboard.jpg");


    Sprite menu(mainmenu);
    Sprite spRoad(road);
    Sprite spRoad2(road);
    Sprite spCar(car);
    Sprite spCar2(car2);
    Sprite spCar3(car2);
    Sprite spCar4(car2);
    Sprite spCar5(car2);
    Sprite Gameover(gameover);
    Sprite sb(scoreboard);

    Gameover.setPosition(Vector2f(2000,2000));
    spCar.setPosition(Vector2f(270,680));
    spCar2.setPosition(Vector2f(90,-100));
    spCar3.setPosition(Vector2f(180,-500));
    spCar4.setPosition(Vector2f(270,-900));
    spCar5.setPosition(Vector2f(450,-1200));
    spRoad2.setPosition(Vector2f(0,-900));
    spRoad.setPosition(Vector2f(0,0));

    int score=0;

    ostringstream sscore;
    sscore<<score;

    Font font;
    font.loadFromFile("font.ttf");

    Text text1;
    Text text2;
    Text text;

    text.setCharacterSize(20);
    text1.setCharacterSize(30);
    text2.setCharacterSize(30);

    text.setColor(Color::White);
    text1.setColor(Color::Black);
    text2.setColor(Color::Black);

    text.setPosition(Vector2f(60,30));
    text1.setPosition(Vector2f(1234,1234));
    text2.setPosition(Vector2f(1234,1234));

    text.setString(sscore.str());
    text1.setString("ON");
    text2.setString("OFF");

    text.setFont(font);
    text1.setFont(font);
    text2.setFont(font);

    Music music;
    music.openFromFile("music/music.ogg");
    music.setLoop(true);
    music.play();

    int y=610;
    Clock clock;
    while (win.isOpen())
    {




        Event event;
        while (win.pollEvent(event))
        {
            if( event.type==Event::Closed)
            {
                win.close();
            }
            if(event.type==Event::KeyPressed)
            {
                if(rect.getPosition().y==76)
                    if(Keyboard::isKeyPressed(Keyboard::Enter))
                    {
                        menu.setPosition(Vector2f(12345,12345));
                        rect.setPosition(Vector2f(2345,2345));
                        clock.restart();
                    }
                if(rect.getPosition().y==512)
                    if(Keyboard::isKeyPressed(Keyboard::Enter))
                    {
                        win.close();
                    }

                    if(rect.getPosition().y==720)
                    if(Keyboard::isKeyPressed(Keyboard::Enter))
                    {
                        win.close();
                    }
                    if(rect.getPosition().y==610)
                    if(Keyboard::isKeyPressed(Keyboard::Enter))
                    {
                        goto a;
                    }

                if(rect.getPosition().y==403)
                {
                    if(Keyboard::isKeyPressed(Keyboard::Enter))
                    {
                        rect1.setPosition(Vector2f(50,403));
                        rect2.setPosition(Vector2f(450,403));
                        if(rect3.getPosition().x==1234)
                        rect3.setPosition(Vector2f(50,403));
                        else if(rect3.getPosition().x==1235)
                        rect3.setPosition(Vector2f(450,403));

                        text1.setPosition(Vector2f(70,403));
                        text2.setPosition(Vector2f(470,403));
                    }
                    if(rect3.getPosition().y==403)
                    {
                        if(Keyboard::isKeyPressed(Keyboard::Left))
                        rect3.setPosition(Vector2f(50,403));
                       if(Keyboard::isKeyPressed(Keyboard::Right))
                        rect3.setPosition(Vector2f(450,403));
                    }
                }
                if(rect.getPosition().y==403)
                {
                    if(Keyboard::isKeyPressed(Keyboard::Up))
                    {
                        rect1.setPosition(Vector2f(1234,1234));
                        rect2.setPosition(Vector2f(1234,1234));
                        if(rect3.getPosition().x==50)
                        rect3.setPosition(Vector2f(1234,1234));
                        else if(rect3.getPosition().x==450)
                        rect3.setPosition(Vector2f(1235,1234));

                        text1.setPosition(Vector2f(1234,1234));
                        text2.setPosition(Vector2f(1234,1234));
                    }
                }
                if(rect.getPosition().y==403)
                {
                    if(Keyboard::isKeyPressed(Keyboard::Down))
                    {
                        rect1.setPosition(Vector2f(1234,1234));
                        rect2.setPosition(Vector2f(1234,1234));
                        if(rect3.getPosition().x==50)
                        rect3.setPosition(Vector2f(1234,1234));
                        else if(rect3.getPosition().x==450)
                        rect3.setPosition(Vector2f(1235,1234));

                        text1.setPosition(Vector2f(1234,1234));
                        text2.setPosition(Vector2f(1234,1234));
                    }
                }


                if(menu.getPosition().x==12345)

                {
                    if(spCar.getPosition().x>90)
                    {
                        if(Keyboard::isKeyPressed(Keyboard::Left))
                            spCar.setPosition(spCar.getPosition().x-90,spCar.getPosition().y);
                    }
                    if(spCar.getPosition().x<450)
                    {
                        if(Keyboard::isKeyPressed(Keyboard::Right))
                            spCar.setPosition(spCar.getPosition().x+90,spCar.getPosition().y);
                    }
                    if(spCar.getPosition().y>=30)
                    {
                        if(Keyboard::isKeyPressed(Keyboard::Up))
                            spCar.setPosition(spCar.getPosition().x,spCar.getPosition().y-40);
                    }
                    if(spCar.getPosition().y<690)
                    {
                        if(Keyboard::isKeyPressed(Keyboard::Down))
                            spCar.setPosition(spCar.getPosition().x,spCar.getPosition().y+40);
                    }
                }
                else if(menu.getPosition().x==0)
                {
                    if(rect.getPosition().y>76)
                        if(Keyboard::isKeyPressed(Keyboard::Up))
                            rect.setPosition(Vector2f(rect.getPosition().x,rect.getPosition().y-109));
                    if(rect.getPosition().y<512)
                        if(Keyboard::isKeyPressed(Keyboard::Down))
                            rect.setPosition(Vector2f(rect.getPosition().x,rect.getPosition().y+109));

                }
                else
                {
                        if(Keyboard::isKeyPressed(Keyboard::Down))
                            y=720;
                        if(Keyboard::isKeyPressed(Keyboard::Up))
                            y=610;

                }

            }

        }
        if(menu.getPosition().x==12345)
        if(Gameover.getPosition().x==2000)
        {

            Time time=clock.getElapsedTime();
            spCar2.move(Vector2f(0,0.2+time.asSeconds()/800));
            spCar3.move(Vector2f(0,0.2+time.asSeconds()/800));
            spCar4.move(Vector2f(0,0.2+time.asSeconds()/800));
            spCar5.move(Vector2f(0,0.2+time.asSeconds()/800));
            spRoad.move(Vector2f(0,0.08));
            spRoad2.move(Vector2f(0,0.08));
        }



        if(spCar2.getPosition().y>900)
        {
            spCar2.setPosition(Vector2f(spCar.getPosition().x,-200));
            score++;
            sscore.str("");
            sscore<<score;
            text.setString(sscore.str());
        }
        if(spCar3.getPosition().y>900&&spCar2.getPosition().x<450)
        {
            spCar3.setPosition(Vector2f(spCar2.getPosition().x+90,-600));
            score++;
            sscore.str("");
            sscore<<score;
            text.setString(sscore.str());
        }
        if(spCar4.getPosition().y>900&&spCar3.getPosition().x>180)
        {

            spCar4.setPosition(Vector2f(spCar3.getPosition().x-180,-1000));
            score++;
            sscore.str("");
            sscore<<score;
            text.setString(sscore.str());
        }
        if(spCar5.getPosition().y>900&&spCar4.getPosition().x>90)
        {


            spCar5.setPosition(Vector2f(spCar4.getPosition().x-90,-1500));
            score++;
            sscore.str("");
            sscore<<score;
            text.setString(sscore.str());

        }


        if(spRoad.getPosition().y>=890)
            spRoad.setPosition(Vector2f(0,-900));
        if(spRoad2.getPosition().y>=890)
            spRoad2.setPosition(Vector2f(0,-900));

        if(rect3.getPosition().x==50)
        {
            music.play();
        }

        if(rect3.getPosition().x==450)
        {
        music.stop();
        }
        if(spCar.getGlobalBounds().intersects(spCar2.getGlobalBounds())||
                spCar.getGlobalBounds().intersects(spCar3.getGlobalBounds())||
                spCar.getGlobalBounds().intersects(spCar4.getGlobalBounds())||
                spCar.getGlobalBounds().intersects(spCar5.getGlobalBounds()))
        {


            menu.setPosition(Vector2f(2345,2345));
            Gameover.setPosition(Vector2f(0,0));
            text.setPosition(Vector2f(410,470));
            text.setCharacterSize(35);
            text.setColor(Color::Black);
            text.setOutlineColor(Color::White);
            text.setOutlineThickness(2);
            text.setLetterSpacing(2);

        }
        if(Gameover.getPosition().x==0)
            rect.setPosition(Vector2f(188,y));

        win.clear();


        win.draw(spRoad);
        win.draw(spRoad2);
        win.draw(spCar);
        win.draw(spCar2);
        win.draw(spCar3);
        win.draw(spCar4);
        win.draw(spCar5);
        win.draw(sb);

        win.draw(Gameover);
        win.draw(text);
        win.draw(menu);
        win.draw(rect);
        win.draw(rect1);
        win.draw(rect2);
        win.draw(rect3);
        win.draw(text1);
        win.draw(text2);
        win.display();

    }
    }

    return 0;
}
