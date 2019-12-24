#include <iostream>
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<sstream>
#include<fstream>
#include<string>
#include<String>
#include "coin.hpp"
using namespace std;
using namespace sf;
int main()
{

    RenderWindow win(VideoMode(600, 900), "IV Wheeler",Style::Close);
    coin s;
   // s.hello();
a:
    {
///DECLARE RECTANGLESHAPE:::::::::::::::::::::::::::::::
        RectangleShape rect(Vector2f(200,45));
        rect.setPosition(Vector2f(72,230));
        rect.setOutlineThickness(15);
        rect.setOutlineColor(Color::Green);
        rect.setFillColor(Color::Transparent);

///DECLARE TEXTURE::::::::::::::::::::::::::::::::::::::::
        Texture mainmenu,hs,road,car,car2,gameover,scoreboard,Sound,about,congo,coin;

        road.setSmooth(true);
        car.setSmooth(true);
        car2.setSmooth(true);
        gameover.setSmooth(true);
        scoreboard.setSmooth(true);
        coin.setSmooth(true);


///LOAD TEXTURE FROM RESOURCE:
        mainmenu.loadFromFile("picture/mainmenu.jpg");
        road.loadFromFile("picture/road2.jpg");
        car.loadFromFile("picture/car3.png");
        car2.loadFromFile("picture/car4.png");
        gameover.loadFromFile("picture/gameover.jpg");
        scoreboard.loadFromFile("picture/scoreboard.jpg");
        Sound.loadFromFile("picture/music.jpg");
        about.loadFromFile("picture/about.jpg");
        hs.loadFromFile("picture/highscore.jpg");
        congo.loadFromFile("picture/congo.jpg");
        coin.loadFromFile("picture/coin-icon.png");
///SET SPRITE:
        Sprite menu(mainmenu),
               spRoad(road),
               spRoad2(road),
               spCar(car),
               spCar2(car2),
               spCar3(car2),
               spCar4(car2),
               spCar5(car2),
               spCar6(car2),
               Gameover(gameover),
               sb(scoreboard),
               spMusic(Sound),
               spAbout(about),
               spHighscore(hs),
               spCongo(congo),
               spCoin(coin);
///SET SPRITE POSITION:
        Gameover.setPosition(Vector2f(2000,2000));
        spMusic.setPosition(Vector2f(2000,2000));
        spAbout.setPosition(Vector2f(2000,2000));
        spHighscore.setPosition(Vector2f(2000,2000));
        spCar.setPosition(Vector2f(270,680));
        spCar2.setPosition(Vector2f(90,-100));
        spCar3.setPosition(Vector2f(180,-500));
        spCar4.setPosition(Vector2f(270,-900));
        spCar5.setPosition(Vector2f(450,-1200));
        spCar6.setPosition(Vector2f(360,-2000));
        spRoad2.setPosition(Vector2f(0,-900));
        spRoad.setPosition(Vector2f(0,0));
        spCongo.setPosition(2000,2000);
        spCoin.setPosition(2000,2000);

///GET HIGHSCORE FROM FILE:
        string name1,name2,name3;
        int namescore1,namescore2,namescore3;
        ifstream read("highscore.txt");
        if(read.is_open())
            read>>name1>>namescore1>>name2>>namescore2>>name3>>namescore3;
        read.close();

        int score=0;
        ostringstream sscore,hscore1,hscore2,hscore3;
        sscore<<score;
        hscore1<<namescore1;
        hscore2<<namescore2;
        hscore3<<namescore3;

///GET FONT FROM FILE:
        Font font;
        font.loadFromFile("font.ttf");

///DECLARE TEXT NAME:
        Text hscorer1(name1,font,25),
             hscorer2(name2,font,25),
             hscorer3(name3,font,25),
             hs1(hscore1.str(),font,25),
             hs2(hscore2.str(),font,25),
             hs3(hscore3.str(),font,25),
             text(sscore.str(),font,25),
             Name("",font,25);
///DECLARE TEXT COLOR:
        text.setColor(Color::White);
        hs1.setColor(Color::Black);
        hs2.setColor(Color::Black);
        hs3.setColor(Color::Black);
        hscorer1.setColor(Color::Black);
        hscorer2.setColor(Color::Black);
        hscorer3.setColor(Color::Black);

///DECLARE TEXT POSITION:
        text.setPosition(Vector2f(60,30));
        hscorer1.setPosition(Vector2f(2000,2000));
        hscorer2.setPosition(Vector2f(2000,2000));
        hscorer3.setPosition(Vector2f(2000,2000));
        hs1.setPosition(Vector2f(2000,2000));
        hs2.setPosition(Vector2f(2000,2000));
        hs3.setPosition(Vector2f(2000,2000));
///MUSIC:
        Music music;
        music.openFromFile("music/music.ogg");
        music.setLoop(true);
        music.play();

        int a=0,b=1,c=1,life=1;
        string str;
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

///Main_menu_event:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::


                    if(event.type==Event::KeyPressed)
                    {


                        if(rect.getPosition().y==230&&Keyboard::isKeyPressed(Keyboard::Enter))
                        {
                            menu.setPosition(Vector2f(12345,12345));
                            rect.setPosition(Vector2f(2345,2345));
                            clock.restart();
                            a=1;
                        }
                        if(rect.getPosition().y==325&&Keyboard::isKeyPressed(Keyboard::Enter))
                        {
                            spMusic.setPosition(Vector2f(0,0));
                            rect.setSize(Vector2f(92,45));
                            if(b==1)
                                rect.setPosition(Vector2f(253,145));
                            else if(b==0)
                                rect.setPosition(Vector2f(253,227));

                            a=2;

                        }

                        if(a==2&&Keyboard::isKeyPressed(Keyboard::BackSpace))
                        {
                            spMusic.setPosition(Vector2f(2000,2000));
                            rect.setPosition(Vector2f(72,325));
                            rect.setSize(Vector2f(200,45));
                            a=0;
                        }
                        if(rect.getPosition().y==420&&Keyboard::isKeyPressed(Keyboard::Enter))
                        {
                            spHighscore.setPosition(Vector2f(0,0));
                            hs1.setPosition(Vector2f(400,103));
                            hs2.setPosition(Vector2f(400,195));
                            hs3.setPosition(Vector2f(400,290));
                            hscorer1.setPosition(Vector2f(100,103));
                            hscorer2.setPosition(Vector2f(100,195));
                            hscorer3.setPosition(Vector2f(100,290));

                            a=3;
                        }
                        if(rect.getPosition().y==420&&Keyboard::isKeyPressed(Keyboard::BackSpace))
                        {
                            spHighscore.setPosition(Vector2f(2000,2000));
                            hs1.setPosition(Vector2f(2000,2000));
                            hs2.setPosition(Vector2f(2000,2000));
                            hs3.setPosition(Vector2f(2000,2000));
                            hscorer1.setPosition(Vector2f(2000,2000));
                            hscorer2.setPosition(Vector2f(2000,2000));
                            hscorer3.setPosition(Vector2f(2000,2000));
                            a=0;
                        }
                        if(rect.getPosition().y==515&&Keyboard::isKeyPressed(Keyboard::Enter))

                        {

                        }
                        if(rect.getPosition().y==610&&Keyboard::isKeyPressed(Keyboard::Enter))
                        {
                            spAbout.setPosition(Vector2f(0,0));
                            a=3;
                        }
                        if(rect.getPosition().y==610&&Keyboard::isKeyPressed(Keyboard::BackSpace))
                        {
                            spAbout.setPosition(Vector2f(2000,2000));
                            a=0;
                        }
                        if(rect.getPosition().y==705&&Keyboard::isKeyPressed(Keyboard::Enter))
                        {
                            win.close();
                        }

                        if(a==0)
                        {
                            if(rect.getPosition().y>230&&Keyboard::isKeyPressed(Keyboard::Up))
                                rect.setPosition(Vector2f(rect.getPosition().x,rect.getPosition().y-95));
                            if(rect.getPosition().y<705&&Keyboard::isKeyPressed(Keyboard::Down))
                                rect.setPosition(Vector2f(rect.getPosition().x,rect.getPosition().y+95));
                        }
                        else if(a==2)
                        {
                            if(Keyboard::isKeyPressed(Keyboard::Up))
                                rect.setPosition(Vector2f(253,145));
                            else if(Keyboard::isKeyPressed(Keyboard::Down))
                                rect.setPosition(Vector2f(253,227));
                        }


                }
///Game_Events:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

                    if(event.type==Event::KeyPressed)
                    {
                        if(menu.getPosition().x==12345)

                        {
                            if(spCar.getPosition().x>90)
                            {
                                if(Keyboard::isKeyPressed(Keyboard::Left))
                                    spCar.setPosition(spCar.getPosition().x-90,spCar.getPosition().y);
                                   //spCar.move(Vector2f(-10,0));
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
                                   //spCar.move(Vector2f(0,-4));
                            }
                            if(spCar.getPosition().y<690)
                            {
                                if(Keyboard::isKeyPressed(Keyboard::Down))
                                    spCar.setPosition(spCar.getPosition().x,spCar.getPosition().y+40);
                                    //spCar.move(Vector2f(0,+4));
                            }
                        }

                    }

///close_menu:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::


                    if(event.type==Event::KeyPressed )
                    {
                        if(spCongo.getPosition().y==0)
                        {
                        if(rect.getPosition().y==340&&Keyboard::isKeyPressed(Keyboard::Enter))
                            rect.setPosition(Vector2f(200,440));
                       else if(rect.getPosition().y==440&&Keyboard::isKeyPressed(Keyboard::Up))
                            rect.setPosition(Vector2f(200,340));
                       else if(rect.getPosition().y==440&&Keyboard::isKeyPressed(Keyboard::Down))
                            rect.setPosition(Vector2f(200,540));

                       else if(rect.getPosition().y==540&&Keyboard::isKeyPressed(Keyboard::Up))
                            rect.setPosition(Vector2f(200,440));
                       else if(rect.getPosition().y==440&&Keyboard::isKeyPressed(Keyboard::Enter))
                            goto a;
                       else if(rect.getPosition().y==540&&Keyboard::isKeyPressed(Keyboard::Enter))
                            win.close();
                        }
                      else if(Gameover.getPosition().y==0)
                      {

                       if(rect.getPosition().y==440&&Keyboard::isKeyPressed(Keyboard::Down))
                            rect.setPosition(Vector2f(200,540));

                       else if(rect.getPosition().y==540&&Keyboard::isKeyPressed(Keyboard::Up))
                            rect.setPosition(Vector2f(200,440));
                       else if(rect.getPosition().y==440&&Keyboard::isKeyPressed(Keyboard::Enter))
                            goto a;
                       else if(rect.getPosition().y==540&&Keyboard::isKeyPressed(Keyboard::Enter))
                            win.close();
                      }

                    }
                    else if(event.type==Event::TextEntered)
                    {
                        if(rect.getPosition().y==340)
                        {
                            if(event.text.unicode==8)
                            {
                                if(str.size()>0)
                                {
                                    str.erase(str.size()-1,1);
                                }
                            }
                            else if(event.text.unicode>32&&event.text.unicode<=126)
                            {
                                if(str.size()<11)
                                {
                                    str+=(char)event.text.unicode;
                                }
                            }
                            Name.setString(str);
                            Name.setColor(Color::White);
                        }
                    }


            }

///GAME LOOPS:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
            if(menu.getPosition().x==12345)
                if(Gameover.getPosition().x==2000||spCongo.getPosition().x==2000)
                {
                    Time time=clock.getElapsedTime();
                    spCar2.move(Vector2f(0,0.2+time.asSeconds()/650));
                    spCar3.move(Vector2f(0,0.2+time.asSeconds()/1300));
                    spCar4.move(Vector2f(0,0.2+time.asSeconds()/700));
                    spCar5.move(Vector2f(0,0.2+time.asSeconds()/1200));
                    spCar6.move(Vector2f(0,0.2+time.asSeconds()/1000));
                    spRoad.move(Vector2f(0,0.09));
                    spRoad2.move(Vector2f(0,0.09));
                    spCoin.move(Vector2f(0,0.09));
                }
            if(spCar2.getPosition().y>900)
            {
                spCar2.setPosition(Vector2f(1350-spCar3.getPosition().x-spCar4.getPosition().x
                                            -spCar5.getPosition().x-spCar6.getPosition().x,-200));
                score++;
                sscore.str("");
                sscore<<score;
                text.setString(sscore.str());
            }
            if(spCar3.getPosition().y>900)
            {
                spCar3.setPosition(Vector2f(1350-spCar2.getPosition().x-spCar4.getPosition().x
                                            -spCar5.getPosition().x-spCar6.getPosition().x,-600));
                score++;
                sscore.str("");
                sscore<<score;
                text.setString(sscore.str());
            }
            if(spCar4.getPosition().y>900)
            {
                spCar4.setPosition(Vector2f(1350-spCar3.getPosition().x-spCar2.getPosition().x
                                            -spCar5.getPosition().x-spCar6.getPosition().x,-1000));
                score++;
                sscore.str("");
                sscore<<score;
                text.setString(sscore.str());
            }
            if(spCar5.getPosition().y>900)
            {
                spCar5.setPosition(Vector2f(1350-spCar3.getPosition().x-spCar4.getPosition().x
                                            -spCar2.getPosition().x-spCar6.getPosition().x,-1500));
                score++;
                sscore.str("");
                sscore<<score;
                text.setString(sscore.str());
            }
            if(spCar6.getPosition().y>900)
            {
                spCar6.setPosition(Vector2f(1350-spCar3.getPosition().x-spCar4.getPosition().x
                                            -spCar2.getPosition().x-spCar5.getPosition().x,-2000));
                score++;
                sscore.str("");
                sscore<<score;
                text.setString(sscore.str());
            }

            if(spRoad.getPosition().y>=890)
            {
                spRoad.setPosition(Vector2f(0,-890));
            }

            if(spRoad2.getPosition().y>=890)
            {
                spRoad2.setPosition(Vector2f(0,-890));
            }


///MUSIC::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
            if(rect.getPosition().y==145)                                          ///
            {                                                                      ///
                music.play();
                b=1;
            }

            if(rect.getPosition().y==227)
            {
                music.stop();
                b=0;
            }

///COLISSION:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
            if(spCar.getGlobalBounds().intersects(spCar2.getGlobalBounds())||       ///
                    spCar.getGlobalBounds().intersects(spCar3.getGlobalBounds())||  ///
                    spCar.getGlobalBounds().intersects(spCar4.getGlobalBounds())||  ///
                    spCar.getGlobalBounds().intersects(spCar5.getGlobalBounds())||
                    spCar.getGlobalBounds().intersects(spCar6.getGlobalBounds()))
            {
                if(life>0)
                {
           life--;
          spCar.setPosition(Vector2f(270,680));
          spCar2.setPosition(Vector2f(90,-100));
          spCar3.setPosition(Vector2f(180,-500));
          spCar4.setPosition(Vector2f(270,-900));
          spCar5.setPosition(Vector2f(450,-1200));
          spCar6.setPosition(Vector2f(360,-2000));
                }
             if(life==0)
               {
                menu.setPosition(Vector2f(2345,2345));
                if(score>namescore3)
                {
                    spCongo.setPosition(Vector2f(0,0));
                    Name.setPosition(Vector2f(212,346));
                    rect.setPosition(Vector2f(200,340));
                }
                else
                {
                    Gameover.setPosition(Vector2f(0,0));
                    rect.setPosition(Vector2f(200,440));
                }
                //spCar.setPosition(Vector2f(900,0));
                //spCar2.setPosition(Vector2f(900,0));
                text.setPosition(Vector2f(300,150));
                text.setCharacterSize(45);
                text.setColor(Color::Black);
                text.setOutlineColor(Color::White);
                text.setOutlineThickness(2);
                text.setLetterSpacing(2);
            }
            }
            //spCar.setLocalBounds(Vector2f(30,20));
          if(spCar.getGlobalBounds().intersects(spCoin.getGlobalBounds()))
          {
              spCoin.setPosition(Vector2f(300,1000));
              //life++;
              score=score+50;
          }
          if(spCoin.getPosition().y>900)
          if(score%10==0&&score!=0)
          {
              spCoin.setPosition(Vector2f(spCar.getPosition().x+15,-300));
          }
///STORE HIGHSCORE::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
            if(rect.getPosition().y==340)                                          ///
            {                                                                      ///
                                                                                   ///
                ofstream write("highscore.txt");
                if(write.is_open())
                {
                    if(str.size()>0)
                    {
                        if(score>namescore1)
                        {
                            write<<str<<" "<<score<<" "<<name1<<" "<<namescore1<<" "<<name2<<" "<<namescore2;
                        }
                        else if(score>namescore2)
                        {
                            write<<name1<<" "<<namescore1<<" "<<str<<" "<<score<<" "<<name2<<" "<<namescore2;
                        }
                        else if(score>namescore3)
                        {
                            write<<name1<<" "<<namescore1<<" "<<name2<<" "<<namescore2<<" "<<str<<" "<<score;
                        }
                    }
                    else
                    {
                        write<<name1<<" "<<namescore1<<" "<<name2<<" "<<namescore2<<" "<<name3<<" "<<namescore3;
                    }
                }
                write.close();

                hscore1<<namescore1;
                hscore2<<namescore2;
                hscore3<<namescore3;
            }
///DRAW ON WINDOW:::::::::::::::::::::::::::::::::::::::::
            win.clear();                             ///::
            win.draw(spRoad);                        ///::
            win.draw(spRoad2);                       ///::
            win.draw(spCar);
                                  ///::
            win.draw(spCar2);                        ///::
            win.draw(spCar3);                        ///::
            win.draw(spCar4);
            win.draw(spCar5);
            win.draw(spCar6);
            win.draw(sb);
            win.draw(Gameover);
            win.draw(spCongo);
            win.draw(text);
            win.draw(menu);
            win.draw(spMusic);
            win.draw(rect);
            win.draw(spHighscore);
            win.draw(spAbout);
            win.draw(hscorer1);
            win.draw(hscorer2);
            win.draw(hscorer3);
            win.draw(hs1);
            win.draw(hs2);
            win.draw(hs3);
            win.draw(Name);
            win.display();

        }
    }

    return 0;
}
