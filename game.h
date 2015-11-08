#ifndef GAME_H
#define GAME_H

enum gameStatus{
    EXIT,
    GAME,
    MENU
};

class Game
{
public:
    Game();
    void start();
    void exit();

private:
    gameStatus status;
    void showMenu();
    void processEvents();
    void render();
    void update();
};

#endif // GAME_H
