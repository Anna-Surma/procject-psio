#include "game.h"
#include "player.h"
#include "Graphics.h"
#include "bullet.h"
#include "enemy.h"
#include <random>


int main()
{
    sf::RenderWindow window(sf::VideoMode(700, 800), "My window");
    window.setVerticalSyncEnabled(true);
    //Game game;
    Player character;
    sf::Clock clock;

    sf::Texture platform_texture;
    platform_texture.loadFromFile("platform.png");

    Graphics platform;
    std::vector<sf::Sprite> platforms = platform.create_platforms(platform_texture, window);

    sf::Texture background;
    background.loadFromFile("tlo.png");

    sf::Texture ground;
    ground.loadFromFile("grass.png");
    platform.create_others(background, ground, window);

    sf::Texture enemy_texture;

    if(!enemy_texture.loadFromFile("grass.png"))
    {
        std::cout<<"Textures not found!"<<std::endl;
    }

    Enemy enemy;
    std::vector<sf::Sprite> enemys = enemy.create_enemy(platforms, enemy_texture);


    std::vector<Bullet> bulletVec;
    bool isFiring = false;


    sf::View view;
    view.reset(sf::FloatRect(0,0, window.getSize().x, window.getSize().y));
    view.setViewport(sf::FloatRect(0,0, 1, 1));


    while (window.isOpen())
        {
        sf::Time time = clock.restart();
            sf::Event event;

            while (window.pollEvent(event))
            {
                if(event.type==sf::Event::Closed)
                    window.close();
                if(event.type == sf::Event::KeyPressed)
                {}
                            if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
                                isFiring = true;
                            }
                            if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
                                isFiring = true;
                            }
                }

            window.clear();
            window.setView(view);
            platform.draw_others(window);
            platform.draw_platform(window);
            character.draw(window);
            enemy.draw_enemys(window);

            if (isFiring == true) {
                        Bullet newBullet;
                        newBullet.set_Pos(sf::Vector2f(character.body.getPosition().x, character.body.getPosition().y));
                        bulletVec.push_back(newBullet);
                        isFiring = false;
                    }

                    for (int i = 0; i < bulletVec.size(); i++) {
                        bulletVec[i].draw(window);
                        bulletVec[i].shoot();
                        enemy.check_coll(bulletVec[i]);
                    }

            window.display();

            for(int i=0; i<(12*32); i+=32)
            {
                 character.add_animation_frame(sf::IntRect(i, 0, 32, 32));
            }
            character.check_coll(platforms);
            character.animeted_movement(time, window);
     }
    return 0;
}
