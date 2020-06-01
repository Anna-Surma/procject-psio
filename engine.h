#ifndef ENGINE_H
#define ENGINE_H

#include "game.h"
#include "player.h"
#include "animated.h"


class Engine
{
public:
    Engine(sf::RenderWindow &window);
    ~Engine();

    void runEngine(sf::RenderWindow &window);

private:
    Player player;
    Animated animation;
};

#endif // ENGINE_H
