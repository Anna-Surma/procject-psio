#include "animation.h"


Animation::Animation(sf::Texture *texture, sf::Vector2u image_count, float switch_time)
{
    this->image_count=image_count;
    this->switch_time=switch_time;
    uvRec.width = texture->getSize().x/float(image_count.x);
    uvRec.height = texture->getSize().y/float(image_count.y);
}

void Animation::update(int row, float delta_time, bool face_right)
{
    current_image.y=row;
    total_time+=delta_time;

    if(total_time>switch_time)
    {
        total_time-=switch_time;
        current_image.x++;

        if(current_image.x>=image_count.x)
        {
            current_image.x =0;
        }
    }
    uvRec.top=current_image.y*uvRec.height;
    if(face_right)
    {
            uvRec.left=current_image.x*uvRec.width;
            uvRec.width=abs(uvRec.width);
}
            else
    {
            uvRec.left=(current_image.x*1)*abs(uvRec.width);
            uvRec.width=-abs(uvRec.width);
}

}


void Player::movement(sf::Time elapsed)
{
    change_time+=elapsed.asSeconds();
    body.setTextureRect(frames[current_frame_index]);


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        body.move(-velocity_x_,0); //(POZIOM, PION)
        body.setTextureRect(frames[current_frame_index+3]);
        if(change_time>1.0f/5.0f)
        {
            if(current_frame_index+3<frames.size()-1)
            {
                current_frame_index++;
            }
            else
            {
                current_frame_index=0;
            }
            change_time=0;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        body.move(velocity_x_,0);
        body.setTextureRect(frames[current_frame_index+3]);
        if(change_time>1.0f/5.0f)
        {
            if(current_frame_index+3<frames.size()-1)
            {
                current_frame_index++;
            }
            else
            {
                current_frame_index=0;
            }
            change_time=0;
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {
        body.move(0,-velocity_y_);
        body.setTextureRect(frames[6]);
        is_jumping=true;

    }

    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {
        is_jumping=false;
    }

    if(body.getPosition().y<ground && is_jumping==false)
    {
        gravitation_velocity=acceleration*change_time;
        body.move(0,gravitation_velocity);

    }
}
