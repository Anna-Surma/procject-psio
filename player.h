#ifndef PLAYER_H
#define PLAYER_H

#include "game.h"

class Player
{
public:
    Player(sf::Texture &texture);
    virtual ~Player();

    void add_animation_frame(sf::IntRect frame);
    void animeted_movement(sf::Time time, sf::Window &window);
    void draw(sf::RenderWindow &window);
    void check_coll(std::vector<sf::Sprite> &walls);

    sf::Sprite body;
    sf::Texture texture;
    sf::Sprite platf;

    bool top_coll=false;
    int numer=0;
    int zmienna=0;
    bool is_right=true;


private:
    std::vector<sf::IntRect> frames;
    size_t frame_index_=5;
    float change_time=0;
    int ground=700;

    float jump_force=400;
    float gravity_acceleration=9.8;
    float mass_=0;
    float acceleration_=0;
    float acceleriationValue_=0;

    bool is_jump=false;
    float s_x_=0;
    float s_y_=0;

    float velocity_x_=5;
    float velocity_y_=5;

};
#endif // PLAYER_H
