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
over2.setText("Press Esc to exit");
over.setPosition(125,200);
over2.setPosition(275,300);
over.setColor(WHITE,BLACK);
over2.setColor(WHITE,BLACK);
over.setVisible(false);
over2.setVisible(false);

playerInputWait = true;

int i = 0;
int j = 0;

field = new int* [10];

for(int count = 0; count < 10; count++)
    {
        field[count] = new int[20];
    }  
    
for(int i = 0; i < 10; i++)
    for(int j = 0; j < 20; j++)
        field[i][j] = 0;     
}

int Game::start()
{
    exit = false;
    status = 1;
    
    int frames = 50000, i = 0;
    settextstyle(0,HORIZ_DIR,10);
    
    while(!exit)
    {
        delay(100);
        //while(i < frames){
            processEvents();
            update();
         //   i++;
        //} 

        render(); 
        //i = 0;

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
        
            if(key == 49) // Клавиша 1
                    temp = new Shape(I,4,0, field);
            
            if(key == 50) // Клавиша 2
                    temp = new Shape(L,4,0, field);
                    
            if(key == 51) // Клавиша 3
                    temp = new Shape(J,4,0, field);
                
            if(key == 52) // Клавиша 4
                    temp = new Shape(O,4,0, field);
                
            if(key == 53) // Клавиша 5
                    temp = new Shape(T,4,0, field);
            
            if(key == 54) // Клавиша 6
                    temp = new Shape(Z,4,0, field);
            
            if(key == 55) // Клавиша 7
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
    setcolor(BLUE);
    settextstyle(2,HORIZ_DIR,10);
    drawFigures(300,150);
        
    settextstyle(0,HORIZ_DIR,20);
    over.draw();  
    
    settextstyle(0,HORIZ_DIR,1);
    over2.draw();  
    swapbuffers();
}

void Game::update()
{       
    for(int i = 0; i < 10; i++) //Проверка на переполнение стакана ------------
    {
        if(field[i][0] == 2)
        {
            over.setVisible(true);
            over2.setVisible(true);
            gameOver = true;
        } 
    }  
    //-------------------------------------------------------------------------
    
if(!gameOver)
    { 
    bool line = false;
    int lineIndex = 0;
    int count = 0;
    
    for(int j = 0; j < 20; j++) //Проверка на сложение линий из 10
    {
        for(int i = 0; i < 10; i++)
        {
            if(field[i][j] == 2)
                     count++;
    
            if(count == 10)
            {
                lineIndex = j;
                line = true;
            }
        }
    count = 0;
    }
    
    if(line)
    {
        int** temporary = field;
        for(int i = 19, n = 19; i >0; i--, n--)
            for(int j = 9; j >= 0; j--)
            {   
                if(n == lineIndex)
                    n--;
                    
                field[j][i] = temporary[j][n];
            }
        
        for(int i = 0; i < 10; i++)
            field[i][0] = 0;
    }       
     
    //-------------------------------------------------------------------------
    
    if(!playerInputWait) //Если игрок уже выбрал фигуру ставим ее в подходящее место
    {
        bool flag = true;
        
        bool** matrix = shape->getShape();
        int x = shape->getSizeX();
        int y = shape->getSizeY();
        int If = 19 , Jf = 0;
        
        for(If; If >=0; If--) //Ищем подходящее место
        {
            //std::cout << Jf << ":" << If << std::endl;
            for(Jf = 0; Jf < 10 - (x-1); Jf ++)
            {
                for(int i = 0; i < x; i++)
                    for(int j = 0; j < y; j++)
                    {
                        if(field[Jf + i][If - j] == 2 && matrix[i][(y-1)-j] == 1)
                            flag = false;
                    }
                
                if(flag) //Ставим, если нашли
                {
                    for(int i = 0; i < x; i++)
                        for(int j = 0; j < y; j++)
                        {
                            if(matrix[i][(y-1)-j] == 1)
                                field[Jf + i][If - j] = 2;
                        } 
                     If = 0;
                     Jf = 10 - (x-1);
                     playerInputWait = true;               
                }
                else
                {
                    flag = true;
                }
            }         
        }  
    }   
    //-------------------------------------------------------------------------
    
    if(playerInputWait)
    {
        for(int i = 0; i < 10; i++)
            for(int j = 0; j < 20; j++)
                if(field[i][j] != 2)
                    field[i][j] = 0;
    }
    
    }
}

Game::~Game()
{
    //for(int i = 0; i < 10; i++)
    //    delete[] field[i];
    
    //delete[] field;
}

void Game::drawFigures(int x, int y)
{
    int startX = x;
    int startY = y;
    int tX = x;
    int tY = y;
    
    outtextxy(x,y-40,"1");
    // I
    bar(x, y, x+20, y+20);
    y+=22;    
    bar(x, y, x+20, y+20); 
    y+=22;
    bar(x, y, x+20, y+20); 
    y+=22;
    bar(x, y, x+20, y+20);
    
    tX+=44;
    x = tX;
    y = tY;
    
    outtextxy(x+6,y-40,"2");
    //L
    bar(x, y, x+20, y+20);
    y+=22;     
    bar(x, y, x+20, y+20);
    y+=22;
    bar(x, y, x+20, y+20);
    x+=22;
    bar(x, y, x+20, y+20);
    
    tX+=88;
    x = tX;
    y = tY;

    outtextxy(x-11,y-40,"3");    
    //J
    bar(x, y, x+20, y+20);
    y+=22;     
    bar(x, y, x+20, y+20);
    y+=22;
    bar(x, y, x+20, y+20);
    x-=22;
    bar(x, y, x+20, y+20);
    
    tX+=44;
    x = tX;
    y = tY;
    
    outtextxy(x+11,y-40,"4");
    //O
    bar(x, y, x+20, y+20);
    y+=22;     
    bar(x, y, x+20, y+20);
    x+=22;
    bar(x, y, x+20, y+20);
    y-=22;
    bar(x, y, x+20, y+20);
    
    tX+=66;
    x = tX;
    y = tY;
    
    outtextxy(x+11,y-40,"5");
    //T
    bar(x, y, x+20, y+20);
    y+=22;     
    bar(x, y, x+20, y+20);
    x+=22;
    bar(x, y, x+20, y+20);
    y+=22;
    x-=22;
    bar(x, y, x+20, y+20);
    
    tX = startX + 22;
    tY+=144;
    x = tX;
    y = tY;

    outtextxy(x-11,y-40,"6");
    //Z
    bar(x, y, x+20, y+20);
    y+=22;     
    bar(x, y, x+20, y+20);
    x-=22;
    bar(x, y, x+20, y+20);
    y+=22;
    bar(x, y, x+20, y+20);
    
    tX += 44;
    x = tX;
    y = tY;
    
    outtextxy(x+11,y-40,"7");
    //S
    bar(x, y, x+20, y+20);
    y+=22;     
    bar(x, y, x+20, y+20);
    x+=22;
    bar(x, y, x+20, y+20);
    y+=22;
    bar(x, y, x+20, y+20);
    
}
