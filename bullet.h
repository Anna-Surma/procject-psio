#ifndef BULLET_H
#define BULLET_H
#include "game.h"
#include "player.h"
//#include "enemy.h"


class Bullet {
public:
    Bullet();

//    void shoot(bool isFiring, Player &character, sf::RenderWindow &window, Enemy &enemy);
    void shoot();
    void draw(sf::RenderWindow &window);
    void set_Pos(sf::Vector2f position);

    sf::Sprite bullet_body;

private:
    sf::Texture texture;
    int speed=3;

};

#endif // BULLET_H
