#include "Graphics.h"
#include <random>
#include <time.h>


Graphics::Graphics(){}

Graphics::~Graphics(){}

std::vector<sf::Sprite> Graphics::create_platforms(sf::Texture &platformTexture, sf::Window &window)
{    
    sf::Sprite platform(platformTexture);
    platformTexture.setRepeated(true);
    sf::Vector2u platform_pos[10];

        std::uniform_int_distribution<unsigned> x(0, window.getSize().x - 128);
        std::uniform_int_distribution<unsigned> y(0, window.getSize().y-150);
       // std::uniform_int_distribution<unsigned> w(68, 150);
        std::default_random_engine random(time(0));

        for (size_t i = 0; i < 10; ++i)
        {
            platform_pos[i].x = x(random);
            platform_pos[i].y = window.getSize().y-150-i*100;
            platform.setPosition(platform_pos[i].x, platform_pos[i].y);
            platform.setTextureRect(sf::IntRect(0, 0, 128, 25));
//          platform.setTextureRect(sf::IntRect(0, 0, w(random), 14));

            platforms.push_back(platform);
        }
        return platforms;
}

void Graphics::platform_move(sf::Time time)
{
    s_x=platform_velocity*time.asSeconds();

    for(auto &plat : platforms)
    {
        plat.move(s_x, 0);
    }
//        sf::FloatRect platform_bounds=plat.getGlobalBounds();
//        sf::FloatRect right_bounds = right_wall.getGlobalBounds();

//        if(platform_bounds.intersects(right_bounds))
//        {
//        plat.move(s_x, 0);
//        }
}

std::vector<sf::Sprite> Graphics::create_others(sf::Texture &background_t, sf::Texture &Texture2, sf::Texture &wall_tex, sf::Window &window)
{
    background.setTexture(background_t);
    background.setTextureRect(sf::IntRect(300, 300, window.getSize().y, window.getSize().x+80));/*0, 0, window.getSize().y, window.getSize().x*/

    ground.setTexture(Texture2);
    Texture2.setRepeated(true);
    ground.setTextureRect(sf::IntRect(0, 0, window.getSize().y, 80));
    ground.setPosition(0,window.getSize().y-80);

    right_wall.setTexture(wall_tex);
    right_wall.setTextureRect(sf::IntRect(0, 0, 96 ,window.getSize().y));
    wall_tex.setRepeated(true);
    right_wall.setPosition(window.getSize().x-96,0);

    left_wall.setTexture(wall_tex);
    left_wall.setTextureRect(sf::IntRect(0, 0, 96 ,window.getSize().y));
    wall_tex.setRepeated(true);
    left_wall.setPosition(0,0);

    objects.push_back(background);
    objects.push_back(ground);
//    objects.push_back(right_wall);
//    objects.push_back(left_wall);

    return objects;
}


void Graphics::draw_platform(sf::RenderWindow &window)
{
    for(auto &plat : platforms)
    {
        window.draw(plat);
    }
}

void Graphics::draw_others(sf::RenderWindow &window)
{
    for(auto &obj : objects)
    {
        window.draw(obj);
    }
}

