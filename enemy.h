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
    void add_animation_frame(sf::IntRect frame);

    void move_enemy(std::vector<sf::Sprite> &walls, sf::Time time);

private:
    sf::Texture texture;
    std::vector<sf::Sprite> enemys;
    bool go_right=true;

    std::vector<sf::IntRect> frames;
    size_t frame_index_=0;    
    float change_time=0;

    int platform_number=0;
};

#endif // ENEMY_H
