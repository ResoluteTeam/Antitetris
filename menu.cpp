#include "menu.h"

Menu::Menu(){
    initwindow(640,480,"Antitetris",0,0,true); 
    bkcolor = LIGHTCYAN;
    
    logo.setText("AntiTetris");
    logo.setColor(bkcolor, BLUE);
    
    startBtn.setCaption("Start!");
    startBtn.setColor(6, 14);
    startBtn.setPosition(200,200);
    
    blinkVal = 1000;   
    flag = false;  
}

int Menu::start(){
    exit = false;
    status = 1;
    int frames = 5, i = 0;
    
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
    
    return status;
}

void Menu::render(){
    cleardevice();  
    setbkcolor(bkcolor);
    xlogo.draw();
    startBtn.draw();
    swapbuffers();
}

void Menu::update(){
    time++;
    if(time > blinkVal)
    {
        logo.setColor(bkcolor, flag);
        flag = !flag;
        time = 0;
    }
}

void Menu::processEvents(){
    if(kbhit())
    {
        char key = getch();
        if(key == 'x')
        {
            status = 2; 
            exit = true;   
        }
    }    
}
