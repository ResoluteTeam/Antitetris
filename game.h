#ifndef GAME_H
#define GAME_H
#include "button.h"
#include "label.h"
class Game
{
public:
    Game();
    int start();

private:
    void processEvents();
    void render();
    void update();
    
    bool exit;
    int status;
    Button exitBtn;
    Label text, text2;
    
    int** field;
};

#endif // GAME_H
