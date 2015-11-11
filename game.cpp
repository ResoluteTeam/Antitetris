#include "game.h"
#include "graphics.h"
#include "iostream"

Game::Game()
{
initwindow(640,480,"PLay AntiTetris",100,100,true,true);

text.setText("Press Esc to exit");
text.setPosition(300, 20);
text.setColor(3,1);
text.setVisible(true);
text2.setText("Press 1 - 7 keys to choose figure");
text2.setPosition(300, 40);
text2.setColor(3,1);
text2.setVisible(true);



int i = 0;
int j = 0;

field = new int* [10];
for(int count = 0; count < 10; count++)
    {
        field[count] = new int[20];
    }       
}

int Game::start()
{
    exit = false;
    status = 1;
    
    int frames = 5000, i = 0;
    settextstyle(0,HORIZ_DIR,10);
    
    while(!exit)
    {
        while(i < frames){
            processEvents();
            update();
            i++;
        }   

        render(); 
        i = 0;
    }
    closegraph();
    return status;
}

void Game::processEvents()
{
    if(kbhit())
    {
        for(int i = 0; i < 10; i++)
            for(int j = 0; j < 20; j++)
                field[i][j] = 0;
        
        char key = getch();
        if(key == 27)
        {
            exit = true;
            status = 0;
        }
        
        if(key == 49) // 1 button
        {
            drawShape(I,4,0);
        }
        
        if(key == 50) // 2 button
        {
            drawShape(S,4,0);
        }
        
        if(key == 51) // 3 button
        {
            drawShape(Z,4,0);
        }
        
        if(key == 52) // 4 button
        {
            drawShape(O,4,0);
        }
        
        if(key == 53) // 5 button
        {
            drawShape(T,4,0);
        }
        
        if(key == 54) // 6 button
        {
            drawShape(L,4,0);
        }
        
        if(key == 55) // 7 button
        {
            drawShape(J,4,0);
        }
    }
}

void Game::render()
{
    setfillstyle(SOLID_FILL, CYAN);
    bar(0,0,getmaxx(),getmaxy());
    
    settextstyle(0,HORIZ_DIR,0);
    text.draw();
    text2.draw();
    
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(20,20,240,460);
    
    setcolor(DARKGRAY);
    for(int i = 0; i <= 10; i++)
        {
            line(20 + i*22, 20,20 + i*22, 460);
        }
    
    for(int i = 0; i <= 20; i++)
        {
            line(20,20 + i*22,240,20 + i*22);
        }        
    
    setfillstyle(SOLID_FILL, BLACK);
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 20; j++)
        {
            if(field[i][j] == 1)
            {
                bar(22 + i*22, 22 + j*22, 21 + i*22 + 20, 21 + j*22 + 20);
            }
        }
        
    swapbuffers();
}

void Game::update()
{
}

void Game::drawShape(shapeClass type, int x, int y) 
{
    switch(type)
    {
        case I:
        {
            for(int i = 0; i < 4; i++)
                field[x][y+i] = 1;    
        }
            break;
            
        case L:
        {
            field[x][y] = 1;
            field[x][y+1] = 1;
            field[x][y+2] = 1;
            field[x+1][y+2] = 1;
        }
            break;
            
        case J:
        {
            field[x+1][y] = 1; 
            field[x+1][y+1] = 1;
            field[x+1][y+2] = 1;
            field[x][y+2] = 1;
        }
            break;
            
        case O:
        {
            field[x][y] = 1;
            field[x][y+1] = 1;
            field[x+1][y] = 1;
            field[x+1][y+1] = 1;
            
        }
            break;
            
        case T:
        {
            field[x+1][y] = 1;
            field[x][y+1] = 1;
            field[x+1][y+1] = 1;
            field[x+2][y+1] = 1;    
        }
            break;
            
        case Z:
        {
            field[x+1][y] = 1;
            field[x+1][y+1] = 1;
            field[x][y+1] = 1;
            field[x][y+2] = 1;
        }
            break;
            
        case S:
        {
            field[x][y] = 1;
            field[x][y+1] = 1;
            field[x+1][y+1] = 1;
            field[x+1][y+2] = 1;
        }
            break;
    }
}
