#include "enemy.h"
#include "cstdlib"


Enemy::Enemy()
{}

void Enemy::check_coll(Bullet bullet)
{
    for(auto &enem : enemys)
    {
    if (bullet.bullet_body.getPosition().x + bullet.bullet_body.getGlobalBounds().width > enem.getPosition().x &&
            bullet.bullet_body.getPosition().y < enem.getPosition().y + enem.getGlobalBounds().height
            && bullet.bullet_body.getPosition().y + bullet.bullet_body.getGlobalBounds().height > enem.getPosition().y)
    {
        enem.setPosition(sf::Vector2f(4200, 4200));
    }
    }
}

std::vector<sf::Sprite> Enemy::create_enemy(std::vector<sf::Sprite> &walls, sf::Texture &enemyTexture)
{
    srand(time(NULL));
    sf::Sprite enemy(enemyTexture);
    enemyTexture.setRepeated(true);
    sf::Vector2u platform_pos[3];

    for(int i=0; i<5; i++)
    {
        i = rand()%10;
        platform_pos[i].x = walls[i].getGlobalBounds().left;
        platform_pos[i].y = walls[i].getGlobalBounds().top;
        enemy.setTextureRect(sf::IntRect(0, 0, 20, 20));
        enemy.setPosition(platform_pos[i].x, platform_pos[i].y-enemy.getGlobalBounds().height);
        enemys.push_back(enemy);
    }
    return enemys;
}


void Enemy::draw_enemys(sf::RenderWindow &window)
{
    for(auto &enem : enemys)
    {
        window.draw(enem);
    }
}
