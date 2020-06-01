#include "bullet.h"

Bullet::Bullet()
{
    if(!texture.loadFromFile("grass.png"))
    {
        std::cout<<"Textures not found!"<<std::endl;
    }
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

void Bullet::shoot()
{
    bullet_body.move(speed, 0);
}


void Bullet::draw(sf::RenderWindow &window)
{
    window.draw(bullet_body);
}

void Bullet::set_Pos(sf::Vector2f position)
{
    bullet_body.setPosition(position);
}
