#ifndef PLATFORM_H
#define PLATFORM_H

#include "game.h"

class Graphics
{
public:
    Graphics();
    ~Graphics();
    std::vector<sf::Sprite> create_platforms(sf::Texture &texture, sf::Window &window);
    std::vector<sf::Sprite> create_others(sf::Texture &Texture, sf::Texture &Texture2, sf::Window &window);
    void draw_others(sf::RenderWindow &window);
    void draw_platform (sf::RenderWindow &window);
    void platform_move(sf::Time time);


private:
    std::vector<sf::Sprite> platforms;
    std::vector<sf::Sprite> objects;

    sf::Sprite background;
    sf::Sprite ground;

    float platform_velocity=10;
    float s_x=0;

};
#endif // PLATFORM_H
