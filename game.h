#ifndef GAME_H
#define GAME_H
#include <QCoreApplication>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <string>
#define TITLE_NUMBER  3

class Game
{
public:
    Game();
    void runGame(sf::RenderWindow& windo);
    void menu(sf::RenderWindow& window);
    //void move_menu();
    void single();

protected:
    enum GameState {MENU,GAME,GAME_OVER,END};
    GameState state;

private:
    sf::Font font;
    int title_index;
    sf::Text title[TITLE_NUMBER];
};

#endif // GAME_H
