#include "enemy.h"
#include "cstdlib"
#include "time.h"

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

    sf::Vector2u enemy_pos[10];

    for(int i=0; i<10; i++)
    {
        platform_number = rand()%22;
        sf::Sprite enemy(enemyTexture);
        //enemyTexture.setRepeated(true);

        enemy.setTextureRect(sf::IntRect(0, 0, 150, 200));
        enemy.setScale(0.3,0.3);
        enemy_pos[i].x = walls[platform_number].getGlobalBounds().left;
        enemy_pos[i].y = walls[platform_number].getGlobalBounds().top;

        enemy.setPosition(enemy_pos[i].x+10, enemy_pos[i].y-enemy.getGlobalBounds().height+1);

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

void Enemy::add_animation_frame(sf::IntRect frame)
{
    frames.emplace_back(frame);
}


void Enemy::move_enemy(std::vector<sf::Sprite> &walls, sf::Time time)
{
    for(auto &wall : walls)
    {
        sf::FloatRect wall_bounds=wall.getGlobalBounds();
        for(auto &enem : enemys)
        {
            sf::FloatRect enem_bounds = enem.getGlobalBounds();

            if(wall_bounds.intersects(enem_bounds))
            {

                // PRAWA STRONA
                if((enem_bounds.left+enem_bounds.width) >= (wall_bounds.left+wall_bounds.width))
                {
                    go_right=false;
                }
                // LEWA STRONA
                if(enem_bounds.left <= wall_bounds.left)
                {
                    go_right=true;
                }

                if(go_right)
                {
                    enem.move(1, 0.0f);

                    change_time+=time.asSeconds();
                        enem.setTextureRect(frames[frame_index_]);
                        if(change_time>0.7)
                        {
                            if(frame_index_<5)
                            {
                                frame_index_++;
                            }
                            else
                            {
                                frame_index_=0;
                            }
                            change_time=0;
                        }

                    }

                else
                {
                    enem.move(-1, 0.0f);

                    change_time+=time.asSeconds();
                        enem.setTextureRect(frames[frame_index_+6]);
                        if(change_time>0.8)
                        {
                            if(frame_index_+6<10)
                            {
                                frame_index_++;
                            }
                            else
                            {
                                frame_index_=0;
                            }
                            change_time=0;
                        }
                }
            }
        }
    }
}
