#include "game.h"

Game::Game()
{
    state = END;

    if(!font.loadFromFile("ostrich-regular.ttf"))
    {
        std::cout<<("Font not found! Can't open the game");
    }
    state = MENU;
    title_index=0;
}

void Game::runGame(sf::RenderWindow& window)
{
    while(state != END)
    {
        switch (state)
        {
        case GameState::MENU:
            menu(window);
            break;
        case GameState::GAME:
            single();
            break;
        }
    }
}

void Game::menu(sf::RenderWindow &window)
{
    title[0].setStyle(sf::Text::Bold);

    title[0].setPosition(window.getSize().x/2,50);
    title[0].setFont(font);
    title[0].setFillColor(sf::Color::Green);
    title[0].setCharacterSize(65);
    title[0].setString("Jump Buddy");

    title[1].setPosition(window.getSize().x/2,150);
    title[1].setFont(font);
    title[1].setFillColor(sf::Color::White);
    title[1].setString("Play");

    title[2].setPosition(window.getSize().x/2,200);
    title[2].setFont(font);
    title[2].setFillColor(sf::Color::White);
    title[2].setString("Exit");

    for(int i=0; i<TITLE_NUMBER; i++)
    {
        window.draw(title[i]);
    }
}

/*void Game::move_menu()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        title_index=0;
        if (title_index == 1)
        {
            title[0].setFillColor(sf::Color::Red);
            title_index--;
            title[1].setFillColor(sf::Color::White);
        }
        if (title_index == 0)
        {
            title[2].setFillColor(sf::Color::Red);
            title_index=2;
            title[0].setFillColor(sf::Color::White);
        }
        else
        std::cout<<"kupa"<<std::endl;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {

        if (title_index + 1 < TITLE_NUMBER)
        {
            title[title_index].setFillColor(sf::Color::Yellow);
            title_index++;
            title[title_index].setFillColor(sf::Color::Cyan);
        }
        else
            std::cout<<"dupa"<<std::endl;
    }
}*/

void Game::single()
{
    //Engine engine(window);

    //engine.runEngine();

    state = MENU;
}
