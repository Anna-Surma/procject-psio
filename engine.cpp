#include "engine.h"

Engine::Engine(sf::RenderWindow &window)
{}

void Engine::runEngine(sf::RenderWindow &window)
{
    for(int i=0; i<(9*50); i+=50)
    {
         animation.add_animation_frame(sf::IntRect(i, 0, 50, 37)); //WYSYŁA DANE FRAGMENTY TEKTURY
    }
}
