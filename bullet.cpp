#include "bullet.h"

Bullet::Bullet(sf::Texture &texture)
{
    bullet_body.setTexture(texture);
    bullet_body.setTextureRect(sf::IntRect(0, 0, 10, 10));
    bullet_body.setPosition(450,690);
}

//void Bullet::shoot(bool isFiring, Player &character, sf::RenderWindow &window, Enemy &enemy)
//{
//    bullet_body.move(speed, 0);

//    if (isFiring == true) {
//                Bullet newBullet;
//                newBullet.set_Pos(sf::Vector2f(character.body.getPosition().x, character.body.getPosition().y));
//                bulletVec.push_back(newBullet);
//                isFiring = false;
//            }

//            for (int i = 0; i < bulletVec.size(); i++) {
//                bulletVec[i].draw(window);
//               // bulletVec[i].shoot();
//                enemy.check_coll(bulletVec[i]);
//            }
//}

void Bullet::shoot(bool direction)
{
    if (direction)
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
