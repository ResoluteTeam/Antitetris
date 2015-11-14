#include "game.h"

Game::Game()
{
initwindow(640,480,"Play AntiTetris",100,100,true,true);

gameOver = false;

text.setText("Press Esc to exit");
text.setPosition(300, 20);
text.setColor(3,1);
text.setVisible(true);
text2.setText("Press 1 - 7 keys to choose figure");
text2.setPosition(300, 40);
text2.setColor(3,1);
text2.setVisible(true);

over.setText("Game Over!");
over.setPosition(140,200);
over.setColor(WHITE,BLACK);
over.setVisible(false);

playerInputWait = true;

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
        char key = getch();
        if(key == 27)
        {
            exit = true;
            status = 0;
        }
        
        if(playerInputWait && key < 56 && key > 48 && !gameOver)
        {
        Shape* temp;
        
            if(key == 49) // 1 button
                    temp = new Shape(I,4,0, field);
            
            if(key == 50) // 2 button
                    temp = new Shape(L,4,0, field);
                    
            if(key == 51) // 3 button
                    temp = new Shape(J,4,0, field);
                
            if(key == 52) // 4 button
                    temp = new Shape(O,4,0, field);
                
            if(key == 53) // 5 button
                    temp = new Shape(T,4,0, field);
            
            if(key == 54) // 6 button
                    temp = new Shape(Z,4,0, field);
            
            if(key == 55) // 7 button
                    temp = new Shape(S,4,0, field);
                    
        shape = temp;
        playerInputWait = false;
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
    
    if(!playerInputWait)
        shape -> draw();
    
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
            if(field[i][j] == 2)
            {
                bar(22 + i*22, 22 + j*22, 21 + i*22 + 20, 21 + j*22 + 20);
            }
        }
        
    settextstyle(0,HORIZ_DIR,20);
    over.draw();    
    swapbuffers();
}

void Game::update()
{   
    for(int i = 0; i < 10; i++)
        if(field[i][0] == 2)
        {
            over.setVisible(true);
            gameOver = true;
        }   
    if(!playerInputWait)
    {
        bool flag = true;
        
        bool** matrix = shape->getShape();
        int x = shape->getSizeX();
        int y = shape->getSizeY();
        int If, Jf;
        for(Jf = 19; Jf >=0; Jf--)        
            for(If = 9; If >=0; If--)
            {
                for(int i = 0; i < x; i++)
                    for(int j = 0; j < y; j++)
                    {
                        if(field[If-i][Jf-j] == 2 && matrix[x-i-1][y-j-1] == 1)
                                flag = false;
                    }
                    
                if(flag)
                {
                    
                    for(int i = 0; i < x; i++)
                        for(int j = 0; j < y; j++)
                        {
                            if(matrix[x-i-1][y-j-1] == 1)
                                field[If-i][Jf-j] = 2;
                        }
                        
                    delete shape;
                    If = 0;
                    Jf = 0;
                    playerInputWait = true;
                }
                else
                {
                    If--;
                    flag = true;
                }
            }
        

    }   
    
    if(playerInputWait)
    {
        for(int i = 0; i < 10; i++)
            for(int j = 0; j < 20; j++)
                if(field[i][j] != 2)
                    field[i][j] = 0;
    }
}

Game::~Game()
{
    delete shape;
    for(int i = 0; i < 10; i++)
        delete[] field[i];
    
    delete[] field;
}
