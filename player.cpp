#include "player.h"
#include <math.h>


Player::Player()
{
    if(!texture.loadFromFile("Run(32x32).png"))
    {
        std::cout<<"Textures not found!"<<std::endl;
    }

    body.setTexture(texture);
    body.setPosition(350,690);
    body.setScale(1.5,1.5);
    mass_=60;

}

void Player::add_animation_frame(sf::IntRect frame)
{
    frames.emplace_back(frame);
}

Player::~Player(){}

void Player::draw(sf::RenderWindow &window)
    {
    window.draw(body);
}

void Player::check_coll(std::vector<sf::Sprite> &walls)
{
    sf::FloatRect nextPos;
        for(auto &wall: walls)
        {
            if(numer<=10)
            {
              numer++;
            }
            else
            {
                numer=0;
            }
            sf::FloatRect wall_bounds=wall.getGlobalBounds();
            sf::FloatRect guy_bounds = body.getGlobalBounds();

            nextPos=guy_bounds;

            if(wall_bounds.intersects(nextPos))
            {
                //RIGHT
                if(guy_bounds.left<wall_bounds.left
                        && guy_bounds.left+guy_bounds.width<wall_bounds.left+wall_bounds.width
                        && guy_bounds.top<wall_bounds.top+wall_bounds.height
                        && guy_bounds.top+guy_bounds.height>wall_bounds.top)
                {
                //velocity_x_=0;
                std::cout<<body.getOrigin().y<<std::endl;
                body.setPosition(wall_bounds.left - guy_bounds.width, guy_bounds.top);
                }

                //LEFT
                if(guy_bounds.left>wall_bounds.left
                        && guy_bounds.left+guy_bounds.width>wall_bounds.left+wall_bounds.width
                        && guy_bounds.top<wall_bounds.top+wall_bounds.height
                        && guy_bounds.top+guy_bounds.height>wall_bounds.top)
                {
                body.setPosition(wall_bounds.left + wall_bounds.width, guy_bounds.top);
                }

                //BOTTOM
                if(guy_bounds.top<wall_bounds.top
                        && guy_bounds.top+guy_bounds.height<wall_bounds.top+wall_bounds.height
                        && guy_bounds.left<wall_bounds.left+wall_bounds.width
                        && guy_bounds.left+guy_bounds.width>wall_bounds.left)
                {
                    top_coll=true;
                body.setPosition(guy_bounds.left, wall_bounds.top - guy_bounds.height);
                }

                //TOP
                if(guy_bounds.top>wall_bounds.top
                        && guy_bounds.top+guy_bounds.height>wall_bounds.top+wall_bounds.height
                        && guy_bounds.left<wall_bounds.left+wall_bounds.width
                        && guy_bounds.left+guy_bounds.width>wall_bounds.left)
                {
                body.setPosition(guy_bounds.left, wall_bounds.top + wall_bounds.height);
                }
            }
        }
     }


void Player::animeted_movement(sf::Time time, sf::Window &window)
{
    change_time+=time.asSeconds();
    body.setTextureRect(frames[frame_index_]);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        is_right=true;
        body.move(velocity_x_,0);
        body.setTextureRect(frames[frame_index_]);
        if(change_time>0.1)
        {
            if(frame_index_<frames.size()-8)
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

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        is_right=false;
        body.move(-velocity_x_,0);
        body.setTextureRect(frames[frame_index_+3]);
        if(change_time>0.1)
        {
            if(frame_index_+3<frames.size()-1)
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

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) && is_jump==false)
    {
        acceleration_=jump_force/mass_;
        is_jump=true;
    }

    if(is_jump)
    {
        body.setTextureRect(frames[8]);
        acceleration_-=gravity_acceleration*time.asSeconds();
        body.move(0,-acceleration_);
        if(body.getPosition().y>=(window.getSize().y-110))
        {
            body.setPosition(body.getPosition().x, window.getSize().y-110);
            is_jump=false;
            acceleriationValue_=0;
            top_coll=false;
            std::cout<<"zmienna"<<zmienna<<std::endl;
        }
        if(top_coll==true)
        {
            is_jump=false;
            top_coll=false;
        }
    }

    if(body.getPosition().y>=(window.getSize().y-110))
    {
        body.setTextureRect(frames[frame_index_]);
        if(change_time>0.15)
        {
            if(frame_index_<2)
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
