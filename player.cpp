#include "player.h"
#include <math.h>


Player::Player(sf::Texture &texture)
{
    body.setTexture(texture);
    body.setPosition(position.x,position.y);
    body.setScale(1.9, 1.9);
    mass_=57;

}

void Player::add_animation_frame(sf::IntRect frame)
{
    frames.emplace_back(frame);
}

void Player::add_animation_frame_left(sf::IntRect frame)
{
    frames_left.emplace_back(frame);
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
       // std::cout<<"JEST KOLIZJI DLA FORA: "<<top_coll<<std::endl;
        sf::FloatRect wall_bounds=wall.getGlobalBounds();
        sf::FloatRect guy_bounds = body.getGlobalBounds();

        nextPos=guy_bounds;
        nextPos.left +=velocity_x_;
        nextPos.top += velocity_y_;

        if(wall_bounds.intersects(nextPos))
        {

            //RIGHT
            if(guy_bounds.left<wall_bounds.left
                    && guy_bounds.left+guy_bounds.width<wall_bounds.left+wall_bounds.width
                    && guy_bounds.top<wall_bounds.top+wall_bounds.height
                    && guy_bounds.top+guy_bounds.height>wall_bounds.top)
            {
                velocity_x_=0;
                body.setPosition(wall_bounds.left - guy_bounds.width, guy_bounds.top);
            }

            //LEFT
            if(guy_bounds.left>wall_bounds.left
                    && guy_bounds.left+guy_bounds.width>wall_bounds.left+wall_bounds.width
                    && guy_bounds.top<wall_bounds.top+wall_bounds.height
                    && guy_bounds.top+guy_bounds.height>wall_bounds.top)
            {
                velocity_x_=0;
                std::cout<<"LEFT COLIISION"<<std::endl;
                body.setPosition(wall_bounds.left + wall_bounds.width, guy_bounds.top);
            }

            //BOTTOM
            if(guy_bounds.top<wall_bounds.top-guy_bounds.height+15 //JESZCZE PRÓBOWAĆ
                    && guy_bounds.top+guy_bounds.height<=wall_bounds.top+wall_bounds.height
                    && guy_bounds.left<wall_bounds.left+wall_bounds.width
                    && guy_bounds.left+guy_bounds.width>wall_bounds.left)
            {
                velocity_y_=0;
                top_coll=true;
                std::cout<<"BOTTOM COLISION"<<std::endl;

                body.setPosition(guy_bounds.left, wall_bounds.top - guy_bounds.height);
            }

            //TOP
            if(guy_bounds.top>wall_bounds.top
                    && guy_bounds.top+guy_bounds.height>wall_bounds.top+wall_bounds.height
                    && guy_bounds.left<wall_bounds.left+wall_bounds.width
                    && guy_bounds.left+guy_bounds.width>wall_bounds.left)
            {
                velocity_y_=0;
                body.setPosition(guy_bounds.left, wall_bounds.top + wall_bounds.height);
            }
        }

        if(guy_bounds.top<=wall_bounds.top && guy_bounds.top>wall_bounds.top-100
                && guy_bounds.left>=wall_bounds.left+wall_bounds.width-20
                && top_coll==true)
        {
            top_coll=false;
        }

        if(guy_bounds.top<=wall_bounds.top && guy_bounds.top>wall_bounds.top-100
                && guy_bounds.left+guy_bounds.width<=wall_bounds.left+15
                && top_coll==true)
        {
            top_coll=false;
        }
    }
}

void Player::animeted_movement(sf::Time time, sf::Window &window)
{
    sf::FloatRect guy_bounds = body.getGlobalBounds();

    change_time+=time.asSeconds();
    body.setTextureRect(frames[frame_index_]);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        velocity_x_=movement_vel_x *time.asSeconds();
        is_right=true;
        body.move(velocity_x_,0);

        body.setTextureRect(frames[frame_index_]);
        if(change_time>0.1)
        {
            if(frame_index_<4)
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
        velocity_x_=movement_vel_x *time.asSeconds();
        is_right=false;
        body.move(-velocity_x_,0);
       // body.setTextureRect(frames[20]);
        body.setTextureRect(frames[frame_index_+19]);
        if(change_time>0.1)
        {
            if(frame_index_+19<23)
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
        top_coll=false;

        std::cout<<"TOP COLISION"<<top_coll<<std::endl;
    }

    if(is_jump)
    {
        if(is_right)
        {
        body.setTextureRect(frames[8]);
        }
        else
        {
            body.setTextureRect(frames[16]);
        }

        acceleration_-=gravity_acceleration*time.asSeconds();
        body.move(0,-acceleration_);
        if(body.getPosition().y>=(position.y))
        {
            body.setPosition(body.getPosition().x, position.y);
            is_jump=false;
            std::cout<<"zmienna"<<zmienna<<std::endl;
        }
        if(top_coll==true)
        {
            is_jump=false;
        }

    }

    if(top_coll==false && is_jump==false && guy_bounds.top<position.y)
    {
        acceleration_-=gravity_acceleration*time.asSeconds();
        body.move(0,-acceleration_);
    }


    if((body.getPosition().y>=(position.y) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
            || (top_coll && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)))
    {
        if(is_right==true)
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

        if(is_right==false)
        {
            body.setTextureRect(frames[frame_index_+21]);
            if(change_time>0.15)
            {
                if(frame_index_+21<23)
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
