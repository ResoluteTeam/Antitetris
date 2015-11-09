#ifndef MENU_H
#define MENU_H
#include "graphics.h"
#include "time.h"
#include <iostream>

class Menu{
public:
       Menu();
       int start();

private:
        void render();
        void update(float delta);
        void processEvents();    
};

#endif
