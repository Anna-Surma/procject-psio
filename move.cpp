#include "move.h"

move::move()
{

}

void move::movement(sf::Time elapsed)
{
        change_time+=elapsed.asSeconds();
        sprite.setTextureRect(frames[current_frame_index]);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        {
            sprite.move(-velocity_x_,0); //(POZIOM, PION)
            sprite.setTextureRect(frames[current_frame_index+3]);
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
}
