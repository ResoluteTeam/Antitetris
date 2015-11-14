#ifndef GAME_H
#define GAME_H
#include "button.h"
#include "label.h"
#include "shape.h"
#include "label.h"
#include "graphics.h"
#include "iostream"
#include "vector"

class Game
{
public:
    Game();
    ~Game();
    int start();

private:
    void processEvents();
    void render();
    void update();
    void drawShape(shapeClass type, int x, int y);
    
    bool exit, gameOver;
    bool playerInputWait;
    int status;
    Button exitBtn;
    Label text, text2;
    
    Label over;
    Shape* shape;
    int** field;
};

#endif // GAME_H
