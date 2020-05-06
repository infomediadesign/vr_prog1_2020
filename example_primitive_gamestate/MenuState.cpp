#include "raylib.h"

#include "game.h"
#include "BaseGameState.h"
#include "MenuState.h"

void MenuState::handleEvents() {
    if (IsKeyDown(KEY_ENTER)) currentState = &playState;
}

void MenuState::updateEntities() {

}

void MenuState::draw() {
    BeginDrawing();

    ClearBackground(RAYWHITE);
    DrawText("Menu - press ENTER to start", 10, 10, 55, LIGHTGRAY);

    EndDrawing();
}
