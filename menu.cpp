#include "menu.h"

Menu::Menu(){
    initwindow(640,480,"Antitetris",0,0,true);             
}

int Menu::start(){
    bool exit = false;
    int status = 1;
    double startTime = clock();
    std::cout << startTime;
    
    while(!exit)
    {
        processEvents();
        update(startTime);
        render();
        //delay(120);
    }
    
    return status;
}

void Menu::render(){
    cleardevice();  
    line(100,100,200,200);
    swapbuffers();
 
}

void Menu::update(float delta){

}

void Menu::processEvents(){
    
}
