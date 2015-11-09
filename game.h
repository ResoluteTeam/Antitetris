#ifndef GAME_H
#define GAME_H

class Game
{
public:
    Game();
    int start();

private:
    void processEvents();
    void render();
    void update();
};

#endif // GAME_H
