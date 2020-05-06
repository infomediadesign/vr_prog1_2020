#include "raylib.h"

#include "game.h"
#include "BaseGameState.h"
#include "PlayState.h"

void PlayState::handleEvents() {

}

void PlayState::updateEntities() {

}

void PlayState::draw() {
    BeginDrawing();

    ClearBackground(RAYWHITE);
    DrawText("This is the game...", 10, 10, 55, LIGHTGRAY);

    EndDrawing();
}
