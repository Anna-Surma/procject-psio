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

    sf::Vector2u platform_pos[10];

    for(int i=0; i<5; i++)
    {
        i = rand()%10;
        sf::Sprite enemy(enemyTexture);
        enemyTexture.setRepeated(true);

        platform_pos[i].x = walls[i].getGlobalBounds().left;
        platform_pos[i].y = walls[i].getGlobalBounds().top;
        enemy.setTextureRect(sf::IntRect(0, 0, 20, 20));
        enemy.setPosition(platform_pos[i].x+5, platform_pos[i].y-enemy.getGlobalBounds().height+1);
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

void Enemy::move_enemy(std::vector<sf::Sprite> &walls)
{
    for(auto &wall : walls)
    {
        sf::FloatRect wall_bounds=wall.getGlobalBounds();
        for(auto &enem : enemys)
        {
            sf::FloatRect enem_bounds = enem.getGlobalBounds();

            if(wall_bounds.intersects(enem_bounds))
            {
                std::cout<<"UDERZENIE"<<std::endl;
                std::cout<<go_right<<std::endl;

                if(enem_bounds.left==wall_bounds.left)
                {
                    std::cout<<"TRUE"<<std::endl;
                    go_right=true;
                }

                if(!(enem_bounds.left<wall_bounds.left)&&!(enem_bounds.left+enem_bounds.width>wall_bounds.left+wall_bounds.width)&&go_right)
                {
                    std::cout<<"POWROT PRAWO"<<std::endl;
                    enem.move(1,0.0f);
                }
                if(enem_bounds.left+enem_bounds.width==wall_bounds.left+wall_bounds.width)
                {
                    std::cout<<"FALSE"<<std::endl;
                    go_right=false;
                }

                if(!(enem_bounds.left<wall_bounds.left)&&!(enem_bounds.left+enem_bounds.width>wall_bounds.left+wall_bounds.width)&&!go_right)
                {
                    std::cout<<"POWROT LEWO"<<std::endl;
                    enem.move(-1, 0.0f);
                }
            }
        }
    }
}
