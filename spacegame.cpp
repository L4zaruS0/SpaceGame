#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <SFML/Audio.hpp>
#include <string>
#include <ctime>

using namespace std;
using namespace sf;

int main()
{
		
    RenderWindow window(VideoMode(1280, 720), "ONLY FORWARD!!!");
    window.setFramerateLimit(60);

    int mx,my;

    Clock clock;
    Time time1;

bool flag1 = false;
bool flag2 = false;
bool flag3 = false;

    srand(time(NULL));
    int a,b,c,d,a1=1280,b1=0,s;
    a=rand()%720;
    b=rand()%720;
    c=rand()%720;
    d=rand()%720;
    s=6;

    double T;

    Texture t1;
    t1.loadFromFile("pexels-francesco-ungaro-998641.png");
    Sprite r;
    r.setTexture(t1);
    r.setScale(0.34,0.34);
    Texture tt;
    tt.loadFromFile("pexels-francesco-ungaro-998641 reset.png");
    Sprite rr;
    rr.setTexture(tt);
    rr.setScale(0.34,0.34);
    rr.setPosition(1280, 0);

    Texture t2;
    t2.loadFromFile("SpaceShip.png");
    Sprite r1;
    r1.setTexture(t2);
    r1.setScale(0.25,0.25);
    r1.setRotation(90);
    r1.setPosition(240,290);
    r1.setOrigin(150,250);

    Texture t3;
    t3.loadFromFile("asteroid.png");
    Sprite k1;
    k1.setTexture(t3);
    k1.setScale(0.18,0.18);

    Texture t4;
    t4.loadFromFile("Mars.png");
    Sprite ast;
    ast.setTexture(t4);
    ast.setScale(2,2);
    ast.setPosition(-700,-150);

    RectangleShape k2 (Vector2f(100,30));
    k2.setFillColor(Color(0,255,64));
    k2.setPosition(1270,a);

    RectangleShape k2 (Vector2f(100,30));
    k2.setFillColor(Color(0,255,64));
    k2.setPosition(1270,b);

    RectangleShape k3 (Vector2f(100,30));
    k3.setFillColor(Color(0,255,64));
    k3.setPosition(1270,c);

    RectangleShape k4 (Vector2f(100,30));
    k4.setFillColor(Color(0,255,64));
    k4.setPosition(1270,d);

    Sprite mas[s];

    for (int i=0; i<s; i++){
        mas[i] = k1;
    }

    for (int i=0; i<s; i++){
        mas[i].setPosition(a1=a1+(1280-s*100/s), c);
        c=rand()%720;
    }


    Font font;
    font.loadFromFile("StickNoBills-Bold.ttf");
    Text text;
    text.setFont(font);
    text.setString("PLAY");
    text.setScale(4,4);
    text.setColor(Color::White);
    text.setPosition(520,280);

    Text text1;
    text1.setFont(font);
    text1.setString("Score: ");
    text1.setScale(4,4);
    text1.setColor(Color::White);
    text1.setPosition(420,140);

    Text text2;
    text2.setFont(font);
    text2.setString("Score: ");
    text2.setColor(Color::White);

    Text text3;
    text3.setFont(font);
    text3.setString("Menu");
    text3.setScale(4,4);
    text3.setColor(Color::White);
    text3.setPosition(480,360);

    int t=time1.asSeconds();
    Text textS;
    textS.setFont(font);
    textS.setScale(1,1);
    textS.setColor(Color::White);
    textS.setString(to_string(t));
    textS.setPosition(80,0);
    textS.setScale(1,1);


    Text textSS;
    textSS.setFont(font);


    /*SoundBuffer buffer;
    buffer.loadFromFile("megalovania.wav");
    Sound sound;
    sound.setBuffer(buffer);
    sound.play();*/

    int Mx, My;
    int scene=0;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))

        {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::MouseButtonPressed){
                if (event.mouseButton.button==Mouse::Left){
                    Mx=event.mouseButton.x;
                    My=event.mouseButton.y;
                    cout<<Mx<<" "<<My<<endl;
                }
            }
                if(event.type==Event::MouseMoved){


                mx = event.mouseMove.x;
                my = event.mouseMove.y;

                    r1.setPosition(mx,my);

        }

        //cout<<mx<<" "<<my<<endl;
if(event.type ==Event::KeyPressed){
                if(event.key.code==Keyboard::A)
                    r1.move(-15,0);
                if(event.key.code==Keyboard::D)
                    r1.move(15,0);
                if(event.key.code==Keyboard::W)
                    r1.move(0,-15);
                if(event.key.code==Keyboard::S)
                    r1.move(0,15);

            }




        }

        if (r1.getPosition().x<=mx){
                    r1.move(5,0);
                }
                if (r1.getPosition().x>=mx){
                    r1.move(-5,0);
                }
                if (r1.getPosition().y<=my){
                    r1.move(0,5);
                }
                if (r1.getPosition().y>=my){
                    r1.move(0,-5);
                }

        if (scene==1){

        flag1 = true;

        if(r1.getPosition().x<111){scene = 2;}
        if(r1.getPosition().y<0){scene = 2;}
        if(r1.getPosition().x>1280){scene = 2;}
        if(r1.getPosition().y>642){scene = 2;}

        if(r.getPosition().x>=-1280){
            r.move(-1,0);
        } else {
            r.setPosition(1280, 0);
        }

        if(rr.getPosition().x>=-1280){
            rr.move(-1,0);
        } else {
            rr.setPosition(1280, 0);
        }

        if(flag1 == true){
        for (int i=0; i<s; i++){
            if (mas[i].getPosition().x<=0){
                mas[i].setPosition(1372, a);
                a = rand()%720;
            }
        }
        }


        time1 = clock.getElapsedTime();
        t = time1.asSeconds(); //cout<<t<<endl;
        T = time1.asSeconds();

        textS.setString(to_string(t));

        if (ast.getPosition().x>-1000){
            ast.move(-2,0);
        }

        for (int i=0; i<s; i++){
            mas[i].move(-(4+T*0.04), 0);
        }

        for (int i=0; i<s; i++){
            if(r1.getGlobalBounds().intersects(mas[i].getGlobalBounds())){
                scene=2;
            }
        }

    textS.setPosition(80,0);
    textS.setScale(1,1);

    }


        if(scene == 0){
            if(text.getGlobalBounds().contains(Mx, My)){
                    scene=1;
                    clock.restart();

        for (int i=0; i<s; i++){
        mas[i].setPosition(a1=a1+((1280-s*92)/s+92), c);
        c=rand()%720;
    }

    a1=1280;

        r1.setPosition(240,280);

                }
            }
        if(scene == 2){

            r.setPosition(0,0);
            rr.setPosition(1280,0);

            textS.setPosition(720,140);
            textS.setScale(4,4);

 /9+++               if(text3.getGlobalBounds().contains(Mx, My)){
                        scene = 0;
                    }
            ast.setPosition(-700,-150);

                textSS.setString(to_string(time1.asSeconds()));
                textSS.setScale(4,4);
                textSS.setColor(Color::White);
                textSS.setPosition(590,280);

        }






        window.clear();

        if (scene==0){
        window.draw(r);
        window.draw(text);
        } else if(scene==1){
        window.draw(r);
        window.draw(rr);
        window.draw(ast);
        window.draw(r1);
        for (int i=0; i<s; i++){
            window.draw(mas[i]);
        }
        window.draw(text2);
        window.draw(textS);
        } else if(scene==2){
            window.draw(r);
            window.draw(text1);
            window.draw(text3);
            window.draw(textS);

        }
        window.display();
    }

    return 0;
}
