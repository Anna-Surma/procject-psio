#include "collision.h"
#include "player.h"

Collision::Collision()
{}

void Collision::colision(sf::Sprite &sguy, std::vector<sf::Sprite> &walls)
{
    sf::FloatRect nextPos;
    for(auto &wall: walls)
    {
        sf::FloatRect wall_bounds=wall.getGlobalBounds();
        sf::FloatRect guy_bounds = sguy.getGlobalBounds();

        nextPos=guy_bounds;
        //nextPos.left+=velocity_x_;
        //nextPos.top+=velocity_y_;

        if(wall_bounds.intersects(nextPos))
        {
            //RIGHT
            if(guy_bounds.left<wall_bounds.left
                    && guy_bounds.left+guy_bounds.width<wall_bounds.left+wall_bounds.width
                    && guy_bounds.top<wall_bounds.top+wall_bounds.height
                    && guy_bounds.top+guy_bounds.height>wall_bounds.top)
            {
            //velocity_x_=0;
            std::cout<<sguy.getOrigin().y<<std::endl;
            sguy.setPosition(wall_bounds.left - guy_bounds.width, guy_bounds.top);
            }

            //LEFT
            if(guy_bounds.left>wall_bounds.left
                    && guy_bounds.left+guy_bounds.width>wall_bounds.left+wall_bounds.width
                    && guy_bounds.top<wall_bounds.top+wall_bounds.height
                    && guy_bounds.top+guy_bounds.height>wall_bounds.top)
            {

           // velocity_x_=0;
            sguy.setPosition(wall_bounds.left + wall_bounds.width, guy_bounds.top);
            }

            //BOTTOM
            if(guy_bounds.top<wall_bounds.top
                    && guy_bounds.top+guy_bounds.height<wall_bounds.top+wall_bounds.height
                    && guy_bounds.left<wall_bounds.left+wall_bounds.width
                    && guy_bounds.left+guy_bounds.width>wall_bounds.left)
            {
                std::cout<<"WYKRYTO DOL"<<std::endl;
                bottom_collision=true;
                std::cout<<"W KOLIZJI"<<bottom_collision<<std::endl;
           // velocity_y_=0;
            sguy.setPosition(guy_bounds.left, wall_bounds.top - guy_bounds.height);
            }

            //TOP
            if(guy_bounds.top>wall_bounds.top
                    && guy_bounds.top+guy_bounds.height>wall_bounds.top+wall_bounds.height
                    && guy_bounds.left<wall_bounds.left+wall_bounds.width
                    && guy_bounds.left+guy_bounds.width>wall_bounds.left)
            {
                std::cout<<"WYKRYTO GORE"<<std::endl;
                top_collision=true;
                std::cout<<"W KOLIZJI"<<top_collision<<std::endl;
            //velocity_y_=0;
            sguy.setPosition(guy_bounds.left, wall_bounds.top + wall_bounds.height);
            }
            else
            {
                top_collision=false;
                bottom_collision=false;
            }
        }
    }
}

bool Collision::return_bottem()
{
    return bottom_collision;
}

bool Collision::return_top()
{
    return top_collision;
}
