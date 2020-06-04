#ifndef BULLET_H
#define BULLET_H
#include "game.h"
#include "player.h"
//#include "enemy.h"


class Bullet {
public:
    Bullet(sf::Texture &texture);

//    void shoot(bool isFiring, Player &character, sf::RenderWindow &window, Enemy &enemy);
    void shoot(bool direction);
    void draw(sf::RenderWindow &window);
    void set_Pos(sf::Vector2f position);
    sf::Vector2f get_Pos();

    sf::Sprite bullet_body;

    sf::Vector2f currVelocity;

private:
    int speed=5;

};

#endif // BULLET_H
