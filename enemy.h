#ifndef ENEMY_H
#define ENEMY_H
#include "game.h"
#include "bullet.h"


class Enemy {
public:
    Enemy();

    void check_coll(Bullet bullet);
    std::vector<sf::Sprite> create_enemy(std::vector<sf::Sprite> &walls, sf::Texture &platformTexture);
    void draw_enemys(sf::RenderWindow &window);

private:
    sf::Texture texture;
    std::vector<sf::Sprite> enemys;
};

#endif // ENEMY_H
