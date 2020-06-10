#ifndef PLATFORM_H
#define PLATFORM_H

#include "game.h"

class Graphics
{
public:
    Graphics();
    ~Graphics();
    std::vector<sf::Sprite> create_platforms(sf::Texture &texture, sf::Window &window);
    std::vector<sf::Sprite> create_others(sf::Texture &Texture, sf::Texture &Texture2, sf::Texture &wall_tex, sf::Texture &mountain_text, sf::Texture &top_plat_tex, sf::Window &window);
    void draw_others(sf::RenderWindow &window);
    void draw_platform (sf::RenderWindow &window);
    void platform_move(sf::Time time);
    std::vector<sf::Sprite> platforms;


private:

    std::vector<sf::Sprite> objects;

    sf::Sprite background;
    sf::Sprite ground;
    sf::Sprite right_wall;
    sf::Sprite left_wall;
    sf::Sprite mountains;
    sf::Sprite top_platform;


    float platform_velocity=10;
    float s_x=0;

};
#endif // PLATFORM_H
