#include <iostream>
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<sstream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<String>

using namespace std;
using namespace sf;

int main()
{

    RenderWindow win(VideoMode(600, 900), "IV Wheeler",Style::Close);

    bool m=true;

    float x=2000.0;
a:
    {
        bool START,MUSIC,HIGHSCORE,ABOUT,LABEL,LHARD,LMEDIUM,LEASY,RESUME,GAMEOVER,COLLISSION;
        START=MUSIC=ABOUT=LABEL=RESUME=HIGHSCORE=LHARD=LEASY=GAMEOVER=COLLISSION=false;
        LMEDIUM=true;

///DECLARE RECTANGLESHAPE:::::::::::::::::::::::::::::::
        RectangleShape rect(Vector2f(200,45));
        rect.setPosition(Vector2f(72,230));
        rect.setOutlineThickness(15);
        rect.setOutlineColor(Color::Green);
        rect.setFillColor(Color::Transparent);

        RectangleShape vrect1(Vector2f(300,7));
        vrect1.setPosition(x,x);
        vrect1.setFillColor(Color::White);

        RectangleShape vrect2(Vector2f(120,7));
        vrect2.setPosition(x,x);
        vrect2.setFillColor(Color::Green);

        ///GET FONT FROM FILE:
        Font font;
        font.loadFromFile("font.ttf");

        Text men;
        men.setCharacterSize(45);
        men.setColor(Color::White);
        men.setPosition(x,x);
        men.setFont(font);
        men.setString("Main Menu");

        Text resume("Resume",font,45);
        resume.setColor(Color::Yellow);
        resume.setPosition(x,x);


///DECLARE TEXTURE::::::::::::::::::::::::::::::::::::::::
        Texture mainmenu,hs,road,car,car2,gameover,scoreboard,Sound,about,congo,coin,crush,label;

        road.setSmooth(true);
        car.setSmooth(true);
        car2.setSmooth(true);
        gameover.setSmooth(true);
        scoreboard.setSmooth(true);
        coin.setSmooth(true);

        SoundBuffer sound;
        sound.loadFromFile("music/crash.wav");
        sf::Sound crash(sound);

        SoundBuffer horn;
        horn.loadFromFile("music/horn.wav");
        sf::Sound Horn(horn);

///LOAD TEXTURE FROM RESOURCE:
        mainmenu.loadFromFile("picture/mainmenu.jpg");
        crush.loadFromFile("picture/crash.png");
        road.loadFromFile("picture/2.jpg");
        car.loadFromFile("picture/Bluecar1.png");
        car2.loadFromFile("picture/car4.png");
        gameover.loadFromFile("picture/gameover.jpg");
        scoreboard.loadFromFile("picture/scoreboard1.jpg");
        Sound.loadFromFile("picture/music.jpg");
        about.loadFromFile("picture/about.jpg");
        hs.loadFromFile("picture/highscore.jpg");
        congo.loadFromFile("picture/congo.jpg");
        coin.loadFromFile("picture/coin-icon.png");
        label.loadFromFile("picture/label.jpg");
///SET SPRITE:
        Sprite spLabel(label),
               menu(mainmenu),
               spRoad(road),
               spRoad2(road),
               spCar(car),
               spCar7(car),
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
               spCoin(coin),
               spCrash(crush);

        spCar3.setColor(Color::Green);
        spCar2.setColor(Color::Red);
        spCar4.setColor(Color::Magenta);
        spCar5.setColor(Color::Cyan);
        spCar6.setColor(Color::Yellow);
        // spCar.setColor(Color::Blue);
        // spCar7.setColor(Color::Blue);
        // spCrash.setColor(Color(160,100,190));
        spCar.setScale(Vector2f(1,1));

///SET SPRITE POSITION:
        spLabel.setPosition(x,x);
        Gameover.setPosition(x,x);
        spMusic.setPosition(x,x);
        spAbout.setPosition(x,x);
        spHighscore.setPosition(x,x);
        spCar.setPosition(200,600);
        spRoad2.setPosition(0,-900);
        spRoad.setPosition(0,0);
        spCongo.setPosition(x,x);
        spCoin.setPosition(x,x);
        spCar7.setPosition(x,x);
        spCrash.setPosition(x,x);
        spCar2.setPosition(Vector2f(90,-(rand()%2000+100)));
        spCar3.setPosition(Vector2f(180,-(rand()%2000+100)));
        spCar4.setPosition(Vector2f(270,-(rand()%2000+100)));
        spCar5.setPosition(Vector2f(450,-(rand()%2000+100)));
        spCar6.setPosition(Vector2f(360,-(rand()%2000+100)));

///GET HIGHSCORE FROM FILE:
        string name1,name2,name3;
        int namescore1,namescore2,namescore3;
        ifstream read("highscore.txt");
        if(read.is_open())
            read>>name1>>namescore1>>name2>>namescore2>>name3>>namescore3;
        read.close();

        int score=0,h=5;
        ostringstream sscore,hscore1,hscore2,hscore3,jump;
        sscore<<score;
        jump<<h;
        hscore1<<namescore1;
        hscore2<<namescore2;
        hscore3<<namescore3;



///DECLARE TEXT NAME:
        Text hscorer1(name1,font,25),
             hscorer2(name2,font,25),
             hscorer3(name3,font,25),
             hs1(hscore1.str(),font,25),
             hs2(hscore2.str(),font,25),
             hs3(hscore3.str(),font,25),
             text(sscore.str(),font,30),
             Name("",font,25),
             Jump(jump.str(),font,30);
///DECLARE TEXT COLOR:
        Jump.setColor(Color::Black);
        text.setColor(Color::Black);
        hs1.setColor(Color::Black);
        hs2.setColor(Color::Black);
        hs3.setColor(Color::Black);
        hscorer1.setColor(Color::Black);
        hscorer2.setColor(Color::Black);
        hscorer3.setColor(Color::Black);

///DECLARE TEXT POSITION:
        text.setPosition(Vector2f(100,45));
        Jump.setPosition(Vector2f(480,45));
        hscorer1.setPosition(x,x);
        hscorer2.setPosition(x,x);
        hscorer3.setPosition(x,x);
        hs1.setPosition(x,x);
        hs2.setPosition(x,x);
        hs3.setPosition(x,x);
///MUSIC:
        Music music;
        music.openFromFile("music/music.ogg");
        music.setLoop(true);
        music.setVolume(30);
        if(m)
            music.play();

        // int a=0,c=1,d=1;

        float y=0.2;
        string str;
        Clock clock;
        Clock clock2;
        Clock clock3;

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
                        menu.setPosition(x,x);
                        rect.setPosition(x,x);
                        clock.restart();
                        START=true;
                    }
                    if(rect.getPosition().y==325&&Keyboard::isKeyPressed(Keyboard::Enter))
                    {
                        spMusic.setPosition(Vector2f(0,0));
                        rect.setSize(Vector2f(92,45));
                        if(m)
                            rect.setPosition(Vector2f(253,145));
                        else
                            rect.setPosition(Vector2f(253,227));
                        vrect1.setPosition(Vector2f(150,350));
                        vrect2.setPosition(Vector2f(150,350));



                        MUSIC=true;

                    }

                    if(MUSIC&&Keyboard::isKeyPressed(Keyboard::BackSpace))
                    {
                        spMusic.setPosition(x,x);
                        rect.setPosition(Vector2f(72,325));
                        rect.setSize(Vector2f(200,45));
                        vrect1.setPosition(x,x);
                        vrect2.setPosition(x,x);
                        MUSIC=false;

                    }
                    if(MUSIC&&vrect2.getSize().x<300&&Keyboard::isKeyPressed(Keyboard::Right))
                    {

                        vrect2.setSize(Vector2f(vrect2.getSize().x+60,7));
                        music.setVolume(music.getVolume()+20);

                    }

                    if(MUSIC&&vrect2.getSize().x>60&&Keyboard::isKeyPressed(Keyboard::Left))
                    {

                        vrect2.setSize(Vector2f(vrect2.getSize().x-60,7));
                        music.setVolume(music.getVolume()-20);

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

                        HIGHSCORE=true;
                    }
                    if(HIGHSCORE&&Keyboard::isKeyPressed(Keyboard::BackSpace))
                    {
                        spHighscore.setPosition(x,x);
                        hs1.setPosition(x,x);
                        hs2.setPosition(x,x);
                        hs3.setPosition(x,x);
                        hscorer1.setPosition(x,x);
                        hscorer2.setPosition(x,x);
                        hscorer3.setPosition(x,x);
                        HIGHSCORE=false;
                    }
                    if(rect.getPosition().y==515&&Keyboard::isKeyPressed(Keyboard::Enter))

                    {
                        spLabel.setPosition(0,0);
                        rect.setPosition(200,200);
                        LABEL=true;
                    }
                    if(LABEL)
                    {
                        if(Keyboard::isKeyPressed(Keyboard::BackSpace))
                        {
                            spLabel.setPosition(x,x);
                            rect.setPosition(72,515);
                            LABEL=false;
                        }

                     else if(rect.getPosition().y==95&&Keyboard::isKeyPressed(Keyboard::Down))
                     {
                        LMEDIUM=true;
                        LHARD=LEASY=false;

                        rect.setPosition(200,200);
                     }
                     else if(rect.getPosition().y==200&&Keyboard::isKeyPressed(Keyboard::Up))
                     {
                         LEASY=true;
                         LHARD=LMEDIUM=false;
                        rect.setPosition(200,95);
                     }

                     else if(rect.getPosition().y==200&&Keyboard::isKeyPressed(Keyboard::Down))
                     {
                         LHARD=true;
                         LEASY=LMEDIUM=false;
                         rect.setPosition(200,310);
                     }

                     else if(rect.getPosition().y==310&&Keyboard::isKeyPressed(Keyboard::Up))
                     {
                         LMEDIUM=true;
                         LHARD=LEASY=false;
                         rect.setPosition(200,200);
                     }



                    }







                    if(rect.getPosition().y==610&&Keyboard::isKeyPressed(Keyboard::Enter))
                    {
                        spAbout.setPosition(Vector2f(0,0));
                        ABOUT=true;
                    }
                    if(ABOUT&&Keyboard::isKeyPressed(Keyboard::BackSpace))
                    {
                        spAbout.setPosition(x,x);
                        ABOUT=false;
                    }
                    if(rect.getPosition().y==705&&Keyboard::isKeyPressed(Keyboard::Enter))
                    {
                        win.close();
                    }

                    if(!START&&!MUSIC&&!LABEL)
                    {
                        if(rect.getPosition().y>230&&Keyboard::isKeyPressed(Keyboard::Up))
                            rect.setPosition(Vector2f(rect.getPosition().x,rect.getPosition().y-95));
                        if(rect.getPosition().y<705&&Keyboard::isKeyPressed(Keyboard::Down))
                            rect.setPosition(Vector2f(rect.getPosition().x,rect.getPosition().y+95));
                    }
                    else if(MUSIC)
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
                    if(START&&!GAMEOVER)

                    {
                        if(spCar.getPosition().x>50&&Keyboard::isKeyPressed(Keyboard::A))
                            if(!RESUME)
                                spCar.move(-9,0);
                        if(spCar.getPosition().x<500&&Keyboard::isKeyPressed(Keyboard::D))
                            if(!RESUME)
                                spCar.move(9,0);
                        if(spCar.getPosition().y>=30&&Keyboard::isKeyPressed(Keyboard::W))
                            if(!RESUME)
                                spCar.move(Vector2f(0,-40));
                        if(spCar.getPosition().y<690&&Keyboard::isKeyPressed(Keyboard::S))
                            if(!RESUME)
                                spCar.move(0,40);

                        if(Keyboard::isKeyPressed(Keyboard::P))
                        {
                            resume.setPosition(Vector2f(205,400));
                            men.setPosition(Vector2f(170,480));
                            RESUME=true;
                        }
                        if(h>0&&spCar.getScale().x==1.0f&&Keyboard::isKeyPressed(Keyboard::J))
                        {
                            spCar.setScale(Vector2f(1.2,1.2));
                            clock3.restart();
                            h--;
                            jump.str("");
                            jump<<h;
                            Jump.setString(jump.str());

                        }


                        if(Keyboard::isKeyPressed(Keyboard::Up)&&RESUME)
                        {
                            resume.setColor(Color::Yellow);
                            men.setColor(Color::White);
                        }
                        if(Keyboard::isKeyPressed(Keyboard::Down)&&RESUME)
                        {
                            resume.setColor(Color::White);
                            men.setColor(Color::Yellow);
                        }
                        if(resume.getColor()==Color::Yellow&&Keyboard::isKeyPressed(Keyboard::Enter))
                        {
                            RESUME=false;
                            resume.setPosition(x,x);
                            men.setPosition(x,x);
                            clock.restart();
                        }
                        if(men.getColor()==Color::Yellow&&Keyboard::isKeyPressed(Keyboard::Enter))
                        {
                            goto a;
                        }
                        if(Keyboard::isKeyPressed(Keyboard::H)&&!RESUME)
                            if(m)
                                Horn.play();



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
            //if(menu.getPosition().x==12345)
            if(START&&!COLLISSION&&!GAMEOVER&&!RESUME)
            {
                Time time=clock.getElapsedTime();

                spCar2.move(Vector2f(0,y));
                spCar3.move(Vector2f(0,y));
                spCar4.move(Vector2f(0,y));
                spCar5.move(Vector2f(0,y));
                spCar6.move(Vector2f(0,y));
                spRoad.move(Vector2f(0,0.1));
                spRoad2.move(Vector2f(0,0.1));
                spCoin.move(Vector2f(0,0.1));

            }
            if(spCar2.getPosition().y>900)
            {
                spCar2.setPosition(Vector2f(1350-spCar3.getPosition().x-spCar4.getPosition().x
                                            -spCar5.getPosition().x-spCar6.getPosition().x,-(rand()%2000+100)));
                score++;
                sscore.str("");
                sscore<<score;
                text.setString(sscore.str());
            }
            if(spCar3.getPosition().y>900)
            {
                spCar3.setPosition(Vector2f(1350-spCar2.getPosition().x-spCar4.getPosition().x
                                            -spCar5.getPosition().x-spCar6.getPosition().x,-(rand()%2000+100)));
                score++;
                sscore.str("");
                sscore<<score;
                text.setString(sscore.str());
            }
            if(spCar4.getPosition().y>900)
            {
                spCar4.setPosition(Vector2f(1350-spCar3.getPosition().x-spCar2.getPosition().x
                                            -spCar5.getPosition().x-spCar6.getPosition().x,-(rand()%2000+100)));
                score++;
                sscore.str("");
                sscore<<score;
                text.setString(sscore.str());
            }
            if(spCar5.getPosition().y>900)
            {
                spCar5.setPosition(Vector2f(1350-spCar3.getPosition().x-spCar4.getPosition().x
                                            -spCar2.getPosition().x-spCar6.getPosition().x,-(rand()%2000+100)));
                score++;
                sscore.str("");
                sscore<<score;
                text.setString(sscore.str());
            }
            if(spCar6.getPosition().y>900)
            {
                spCar6.setPosition(Vector2f(1350-spCar3.getPosition().x-spCar4.getPosition().x
                                            -spCar2.getPosition().x-spCar5.getPosition().x,-(rand()%2000+100)));
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
            {
                ///
                music.play();
                m=true;
            }

            if(rect.getPosition().y==227)
            {
                music.stop();
                m=false;
            }

///COLISSION:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
            if((spCar.getGlobalBounds().intersects(spCar2.getGlobalBounds())||       ///
                    spCar.getGlobalBounds().intersects(spCar3.getGlobalBounds())||  ///
                    spCar.getGlobalBounds().intersects(spCar4.getGlobalBounds())||  ///
                    spCar.getGlobalBounds().intersects(spCar5.getGlobalBounds())||
                    spCar.getGlobalBounds().intersects(spCar6.getGlobalBounds()))&&spCar.getScale().x!=1.2f)
            {
                COLLISSION=true;
                if(m)
                    crash.play();
                clock2.restart();
                spCrash.setPosition(Vector2f(spCar.getPosition().x-115,spCar.getPosition().y-5));
                spCar7.setPosition(Vector2f(spCar.getPosition().x,spCar.getPosition().y));
                spCar.setPosition(Vector2f(600,1000));
            }





            if(COLLISSION)
            {
                GAMEOVER=true;

                Time time2=clock2.getElapsedTime();
                //clock2.restart();
                if(time2.asSeconds()>1)
                {

                    menu.setPosition(x,x);
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
                    COLLISSION=false;
                }
            }

            //spCar.setLocalBounds(Vector2f(30,20));
            if(spCar.getGlobalBounds().intersects(spCoin.getGlobalBounds()))
            {
                spCoin.setPosition(x,x);
                //life++;
                score=score+50;
                sscore.str("");
                sscore<<score;
                text.setString(sscore.str());
            }
            if(spCoin.getPosition().y>900)
                if(score%10==0&&score!=0)
                {
                    spCoin.setPosition(Vector2f(spCar.getPosition().x+15,-300));
                }

            if( spCar.getScale().x==1.2f&&clock3.getElapsedTime().asMilliseconds()>1300)
            {
                spCar.setScale(Vector2f(1,1));
            }
///STORE HIGHSCORE::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
            if(rect.getPosition().y==340)                                          ///
            {
                ///
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
            win.clear();

            win.draw(spRoad);                        ///::
            win.draw(spRoad2);                       ///::
            win.draw(spCoin);                        ///::
            win.draw(spCar2);                        ///::
            win.draw(spCar3);                        ///::
            win.draw(spCar4);
            win.draw(spCar5);
            win.draw(spCar6);
            win.draw(spCar);
            win.draw(spCar7);
            win.draw(spCrash);
            win.draw(sb);
            win.draw(resume);
            win.draw(men);
            win.draw(Gameover);
            win.draw(spCongo);
            win.draw(text);
            win.draw(Jump);
            win.draw(menu);
            win.draw(spLabel);
            win.draw(spMusic);
            win.draw(vrect1);
            win.draw(vrect2);
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
