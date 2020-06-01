#ifndef MOVE_H
#define MOVE_H

#include <game.h>

class move
{
public:
    move();
    void movement(sf::Time elapsed);

    sf::Sprite sprite;
    sf::Texture texture;

    std::vector<sf::IntRect> frames;
    size_t current_frame_index=0;
    float change_time=0;
    float acceleration=0.02;
    float velocity_x_=0.05;
    float velocity_y_=0.05;
    float gravitation_velocity;
    bool is_jumping=false;
    int ground=500;

};


#endif // MOVE_H
