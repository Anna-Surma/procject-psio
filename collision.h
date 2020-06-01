#ifndef COLLISION_H
#define COLLISION_H
#include <game.h>
//#include <player.h>

class Collision
{
public:
    Collision();
    void colision(sf::Sprite &sguy, std::vector<sf::Sprite> &walls);

    bool return_bottem();
    bool return_top();
    bool bottom_collision=false;
    bool top_collision=false;
};



#endif // COLLISION_H
