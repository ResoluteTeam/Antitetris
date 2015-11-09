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
    int maxx = getmaxx();
    int maxy = getmaxy();
    std::cout << maxx << " : " << maxy;
    setbkcolor(LIGHTBLUE);
    setfontcolor(BLUE);
//    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    outtextxy(100,100,"Antitetris");
//    outtextxy(maxx/2,maxy/2,"Press Enter to play!");
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


