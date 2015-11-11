#ifndef GAME_H
#define GAME_H
#include "button.h"
#include "label.h"
enum shapeClass{
    I,
    Z,
    S,
    L,
    J,
    T,
    O
};

class Game
{
public:
    Game();
    int start();

private:
    void processEvents();
    void render();
    void update();
    void drawShape(shapeClass type, int x, int y);
    
    bool exit;
    int status;
    Button exitBtn;
    Label text, text2;
    
    int** field;
};

#endif // GAME_H
