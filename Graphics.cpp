#include "Graphics.h"
#include <random>
#include <time.h>


Graphics::Graphics(){}

Graphics::~Graphics(){}

std::vector<sf::Sprite> Graphics::create_platforms(sf::Texture &platformTexture, sf::Window &window)
{    
    sf::Sprite platform(platformTexture);
    platformTexture.setRepeated(true);
    sf::Vector2u platform_pos[22];

        std::uniform_int_distribution<unsigned> x(0, window.getSize().x - 160);
      //  std::uniform_int_distribution<unsigned> y(0, 2500-150);
       // std::uniform_int_distribution<unsigned> w(68, 150);
        std::default_random_engine random(time(0));

        for (size_t i = 0; i < 22; ++i)
        {
            platform_pos[i].x = x(random);
            platform_pos[i].y = 3090-i*120;
            platform.setPosition(platform_pos[i].x, platform_pos[i].y);
            platform.setTextureRect(sf::IntRect(0, 0, 160, 25));
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

std::vector<sf::Sprite> Graphics::create_others(sf::Texture &background_t, sf::Texture &Texture2, sf::Texture &wall_tex, sf::Texture &mountain_text, sf::Texture &top_plat_tex,  sf::Window &window)
{
    background.setTexture(background_t);
    background.setTextureRect(sf::IntRect(200, 0, window.getSize().x, 2500));/*0, 0, window.getSize().y, window.getSize().x*/

    mountains.setTexture(mountain_text);
    mountains.setTextureRect(sf::IntRect(0, 0, 700, 1428));
    mountains.setPosition(0,3150);
    mountains.setOrigin(0, 1428.0f);

    right_wall.setTexture(wall_tex);
    right_wall.setTextureRect(sf::IntRect(906, 0, 174 ,3200));
    wall_tex.setRepeated(true);
    right_wall.setScale(0.5, 1);
    right_wall.setPosition(window.getSize().x-86,0);

    left_wall.setTexture(wall_tex);
    left_wall.setTextureRect(sf::IntRect(0, 0, 174 ,3200));
    left_wall.setScale(0.5, 1);
    left_wall.setPosition(0,0);

    top_platform.setTexture(top_plat_tex);
    top_plat_tex.setRepeated(true);
    top_platform.setTextureRect(sf::IntRect(0, 0, window.getSize().y, 25));
    top_platform.setScale(2,2);
    top_platform.setPosition(0, 450);

    ground.setTexture(Texture2);
    Texture2.setRepeated(true);
    ground.setTextureRect(sf::IntRect(0, 0, window.getSize().y, 227));
    ground.setPosition(0, 3090);

    objects.push_back(background);
    objects.push_back(mountains);
    objects.push_back(top_platform);
    objects.push_back(right_wall);
    objects.push_back(left_wall);
    objects.push_back(ground);



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

