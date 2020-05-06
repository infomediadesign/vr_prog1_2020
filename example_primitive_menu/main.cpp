#include "raylib.h"

#include "game.h"

BaseGameState* menuState;
BaseGameState* playState;
BaseGameState* currentState;

int main()
{
    const int screenWidth = 1024;
    const int screenHeight = 576;

    InitWindow(screenWidth, screenHeight, "Primitive Mainmenu Demo");
    SetTargetFPS(60);

    menuState = new MenuState();
    playState = new PlayState();

    currentState = menuState;

    while (!WindowShouldClose())
    {
        currentState->handleEvents();
        currentState->updateEntities();
        currentState->draw();
    }

    CloseWindow();

    delete menuState;
    delete playState;

    return 0;
}
