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
    void move_enemy(std::vector<sf::Sprite> &walls);

private:
    sf::Texture texture;
    std::vector<sf::Sprite> enemys;
    bool go_right=true;
};

#endif // ENEMY_H
