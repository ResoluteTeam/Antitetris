#include "game.h"
#include "graphics.h"
#include "iostream"

Game::Game()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    status = MENU;
    showMenu();
}

void Game::start()
{
    while(status == GAME || status == MENU)
    {
        if(status == GAME)
        {
            processEvents();
            update();
            render();
        }
        if(status == MENU)
        {
            showMenu();
        }
    }
}

void Game::exit()
{
    closegraph();
}

void Game::showMenu()
{
    outtextxy(100,100,"Press Enter to play!");
    char key = getch();
    std::cout << key;
    if(key == 'x')
        status = EXIT;
    if(key == '\r')
        status = GAME;
}

void Game::processEvents()
{
    status = EXIT;
}

void Game::render()
{

}

void Game::update()
{

}


