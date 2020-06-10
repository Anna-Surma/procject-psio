#include "bullet.h"

Bullet::Bullet(sf::Texture &texture)
{
    bullet_body.setTexture(texture);
    bullet_body.setTextureRect(sf::IntRect(0, 0, 860, 790));
    bullet_body.setScale(0.02,0.02);
    bullet_body.setPosition(450,690);
}

void Bullet::shoot(bool is_right)
{
    if (is_right)
    {
    bullet_body.move(speed, 0);
    std::cout<<"RIGHT"<<std::endl;
    }
    else
    {
     bullet_body.move(-speed, 0);
     std::cout<<"LEFT"<<std::endl;
    }
}

void Bullet::draw(sf::RenderWindow &window)
{
    window.draw(bullet_body);
}

void Bullet::set_Pos(sf::Vector2f position)
{
    bullet_body.setPosition(position);
}

sf::Vector2f Bullet::get_Pos()
{
   return bullet_body.getPosition();
}
