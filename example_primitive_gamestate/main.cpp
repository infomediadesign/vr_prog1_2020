#include "raylib.h"

#include "game.h"

MenuState menuState;
PlayState playState;

BaseGameState* currentState;

int main(void)
{
    currentState = &menuState;

    const int screenWidth = 1024;
    const int screenHeight = 576;

    InitWindow(screenWidth, screenHeight, "Primitive Gamestate Demo");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        currentState->handleEvents();
        currentState->updateEntities();
        currentState->draw();
    }

    CloseWindow();

    return 0;
}
