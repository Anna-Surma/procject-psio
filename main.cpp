#include "game.h"
#include "player.h"
#include "Graphics.h"
#include "bullet.h"
#include "enemy.h"
#include <random>

int main()
{
    sf::RenderWindow window(sf::VideoMode(700, 850), "My window");
    window.setVerticalSyncEnabled(true);
    sf::Clock clock;

    //ŁADOWANIE TEKSTUR I TWORZENIE OBIEKTÓW

    sf::Texture character_texture;
    character_texture.loadFromFile("Run(32x32).png");

    Player character(character_texture);

    for(int i=0; i<(12*32); i+=32)
    {
         character.add_animation_frame(sf::IntRect(i, 0, 32, 32));
    }

    for(int i=(12*32); i>0; i-=32)
    {
         character.add_animation_frame(sf::IntRect(i, 0, -32, 32));
    }

    sf::Texture platform_texture;
    platform_texture.loadFromFile("block2.png");

    Graphics platform;
    std::vector<sf::Sprite> platforms = platform.create_platforms(platform_texture, window);

    sf::Texture mount_texture;
    mount_texture.loadFromFile("mountain.png");

    sf::Texture background_texture;
    background_texture.loadFromFile("sky.png");

    sf::Texture sides_texture;
    sides_texture.loadFromFile("b_grass.png");

    sf::Texture ground_texture;
    ground_texture.loadFromFile("ground.png");
    platform.create_others(background_texture, ground_texture, sides_texture, mount_texture, platform_texture, window);

    sf::Texture enemy_texture;
    enemy_texture.loadFromFile("enemy.png");

    Enemy enemy;
    std::vector<sf::Sprite> enemys = enemy.create_enemy(platform.platforms, enemy_texture);

    for(int i=0; i<(6*160); i+=160)
    {
        enemy.add_animation_frame(sf::IntRect(i, 0, 160, 200));
    }

    for(int i=(6*160); i>0; i-=160)
    {
        enemy.add_animation_frame(sf::IntRect(i, 0, -160, 200));
    }

    sf::Texture bullet_texture;
    bullet_texture.loadFromFile("bullet.png");

    std::vector<Bullet> bullets;

    bool isShooting = false;

    int start_point =2450;

    bool is_right=true;

    float suma=0;

        sf::View view(sf::FloatRect(0,start_point, window.getSize().x, window.getSize().y));
      //  sf::View view(sf::FloatRect(0,0, window.getSize().x, window.getSize().y));

        while (window.isOpen())
        {
            sf::Event event;

            while (window.pollEvent(event))
            {
                if(event.type==sf::Event::Closed)
                    window.close();
                if(event.type == sf::Event::KeyPressed)
                {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
                    isShooting = true;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                    is_right = true;
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                    is_right = false;
                }
                }
            }
            sf::Time time = clock.restart();

            window.setView(view);

           // platform.platform_move(time);
            character.check_coll(platform.platforms);
            character.animeted_movement(time, window);
            enemy.move_enemy(platform.platforms, time);

            if (isShooting == true)
            {
                Bullet bullet(bullet_texture);
                bullet.set_Pos(sf::Vector2f(character.body.getPosition().x, character.body.getPosition().y));
                bullets.push_back(bullet);

                isShooting = false;
            }

               if (isShooting == true)
               {
                   Bullet bullet(bullet_texture);
                   bullet.set_Pos(sf::Vector2f(character.body.getPosition().x, character.body.getPosition().y));
                   bullets.push_back(bullet);

                   isShooting = false;
               }

               for (int i = 0; i < bullets.size(); i++)
               {
                   bullets[i].shoot(character.is_right);
                   enemy.check_coll(bullets[i]);

                   if (bullets[i].get_Pos().x < 0 || bullets[i].get_Pos().x > window.getSize().x)
                   {
                       bullets.erase(bullets.begin() + i);
                   }
               }

//            for (auto itr =  bullets.begin(); itr!=bullets.end(); )
//            {
//                itr->shoot(character.is_right);
//                enemy.check_coll(*itr);

//                if (itr->get_Pos().x < 0 || itr->get_Pos().x > window.getSize().x)
//                {
//                    itr = bullets.erase(itr);
//                }
//                else
//                {
//                    itr++;
//                }
//           }

               window.clear();
               platform.draw_others(window);

               platform.draw_platform(window);
               character.draw(window);
               enemy.draw_enemys(window);

               for (int i = 0; i < bullets.size(); i++) {
                   bullets[i].draw(window);
               }

               //            for (auto itr =  bullets.begin(); itr!=bullets.end();)
               //            {
               //                itr->draw(window);
               //            }

               window.display();

               suma+=time.asSeconds();
               float s=50*time.asSeconds();

               if(suma>=3)
               {
                   // view.move(0, -s);
               }
        }
        return 0;
}
