#include <iostream>
#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
using namespace std;
using namespace sf;
int main()
{

    RenderWindow win(VideoMode(600, 800), "SFML Test");

    Texture road;
    Texture car;
    Texture car2;
    Texture gameover;

    road.setSmooth(true);
    car.setSmooth(true);
    car2.setSmooth(true);
    gameover.setSmooth(true);

    road.loadFromFile("picture/road1.jpg");
    car.loadFromFile("picture/car.png");
    car2.loadFromFile("picture/car2.png");
    gameover.loadFromFile("picture/gameover.jpg");

    Sprite spRoad(road);
    Sprite spRoad2(road);
    Sprite spCar(car);
    Sprite spCar2(car2);
    Sprite spCar3(car2);
    Sprite spCar4(car2);
    Sprite spCar5(car2);
    Sprite Gameover(gameover);

    Gameover.setPosition(Vector2f(2000,2000));
    spCar.setPosition(Vector2f(240,690));
    spCar2.setPosition(Vector2f(240,0));
    spCar3.setPosition(Vector2f(390,-300));
    spCar4.setPosition(Vector2f(240,-200));
    spCar5.setPosition(Vector2f(135,-500));
    spRoad2.setPosition(Vector2f(0,-900));
    spRoad.setPosition(Vector2f(0,0));

    Music music;
    music.openFromFile("music/music.ogg");
    music.setLoop(true);
    music.play();



    /*int score=0;
    Font myfont;
    myfont.loadFromFile("myfont.ttf");
    std::ostringstream Score;
    Score<<"score: "<<score;
    Text t;
    t.setFont(myfont);
    t.setCharacterSize(30);
    t.setPosition(Vector2f(30,30));
    t.setString(Score.str());*/

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
                if(spCar.getPosition().x>90)
                {
                    if(Keyboard::isKeyPressed(Keyboard::Left))
                        spCar.setPosition(spCar.getPosition().x-75,spCar.getPosition().y);
                }
                if(spCar.getPosition().x<460)
                {
                    if(Keyboard::isKeyPressed(Keyboard::Right))
                        spCar.setPosition(spCar.getPosition().x+75,spCar.getPosition().y);
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

        }

        Time time=clock.getElapsedTime();
        spCar2.move(Vector2f(0,0.2+time.asSeconds()/1000));
        spCar3.move(Vector2f(0,0.2+time.asSeconds()/1100));
        spRoad.move(Vector2f(0,0.08));
        spRoad2.move(Vector2f(0,0.08));
        spCar4.move(Vector2f(0,0.2+time.asSeconds()/1200));
        spCar5.move(Vector2f(0,0.2+time.asSeconds()/1400));



        if(spCar2.getPosition().y>900&&spCar.getPosition().x<460)
            spCar2.setPosition(Vector2f(spCar.getPosition().x+75,-60));

        if(spCar3.getPosition().y>900&&spCar.getPosition().x>90)
            spCar3.setPosition(Vector2f(spCar.getPosition().x-75,-120));

        if(spCar4.getPosition().y>900&&spCar.getPosition().x>165)
            spCar4.setPosition(Vector2f(spCar.getPosition().x-150,-170));

        if(spCar5.getPosition().y>900)
            spCar5.setPosition(Vector2f(spCar.getPosition().x,-220));


        if(spRoad.getPosition().y>=890)
            spRoad.setPosition(Vector2f(0,-900));

        if(spRoad2.getPosition().y>=890)
            spRoad2.setPosition(Vector2f(0,-900));

         if(spCar2.getGlobalBounds().intersects(spCar3.getGlobalBounds())||
            spCar2.getGlobalBounds().intersects(spCar4.getGlobalBounds())||
            spCar2.getGlobalBounds().intersects(spCar5.getGlobalBounds())&&
            spCar2.getPosition().x<460)
          spCar2.move(Vector2f(75,0));
        if(spCar2.getGlobalBounds().intersects(spCar3.getGlobalBounds())||
            spCar2.getGlobalBounds().intersects(spCar4.getGlobalBounds())||
            spCar2.getGlobalBounds().intersects(spCar5.getGlobalBounds())&&
            spCar2.getPosition().x>90)
          spCar2.move(Vector2f(-75,0));
        if(spCar3.getGlobalBounds().intersects(spCar4.getGlobalBounds())||
            spCar3.getGlobalBounds().intersects(spCar5.getGlobalBounds())&&
            spCar3.getPosition().x<460)
          spCar3.move(Vector2f(75,0));
        if( spCar3.getGlobalBounds().intersects(spCar4.getGlobalBounds())||
            spCar3.getGlobalBounds().intersects(spCar5.getGlobalBounds())&&
            spCar3.getPosition().x>90)
          spCar3.move(Vector2f(-75,0));
        if(spCar4.getGlobalBounds().intersects(spCar5.getGlobalBounds())&&
            spCar2.getPosition().x<460)
          spCar4.move(Vector2f(75,0));
        if(spCar4.getGlobalBounds().intersects(spCar5.getGlobalBounds())&&
            spCar2.getPosition().x>90)
          spCar4.move(Vector2f(-75,0));
        if(spCar.getGlobalBounds().intersects(spCar2.getGlobalBounds())||
           spCar.getGlobalBounds().intersects(spCar3.getGlobalBounds())||
           spCar.getGlobalBounds().intersects(spCar4.getGlobalBounds())||
           spCar.getGlobalBounds().intersects(spCar5.getGlobalBounds()))


            Gameover.setPosition(Vector2f(0,0));


    /*  if(clock.getElapsedTime().asSeconds()>1)
      {
          score++;

      }*/

        win.clear();

        win.draw(spRoad);
        win.draw(spRoad2);
        win.draw(spCar);
        win.draw(spCar2);
        win.draw(spCar3);
        win.draw(spCar4);
        win.draw(spCar5);
        win.draw(Gameover);
        win.display();
    }

    return 0;
}

