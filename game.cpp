#include "game.h"
#include "graphics.h"
#include "iostream"

Game::Game()
{

}

int Game::start()
{
    initwindow(640,480,"AntiTetris",100,100,true,true);
    setfillstyle(SOLID_FILL, RED);
    bar(0,0,getmaxx(),getmaxy());
    swapbuffers();
    getch();
    return 2;
}

void Game::processEvents()
{

}

void Game::render()
{

}

void Game::update()
{

}


