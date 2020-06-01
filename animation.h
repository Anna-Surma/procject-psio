#ifndef ANIMATION_H
#define ANIMATION_H

#include "game.h"
class Animation
{
public:
    Animation(sf::Texture *texture,sf::Vector2u image_count, float switch_time);
    sf::IntRect uvRec;

    void update(int row, float delta_time, bool face_right);

private:
    sf::Vector2u image_count;
    sf::Vector2u current_image;
    float total_time;
    float switch_time;

};

#endif // ANIMATION_H
