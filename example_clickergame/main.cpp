#include <iostream>

#include "raylib.h"

#include "scenecontroller.hpp"
#include "spritemanager.hpp"

constexpr char *GAME_NAME = (char *) "Fruit Clicker";
constexpr int GAME_FPS = 60;
constexpr int SCREEN_WIDTH = 800;
constexpr int SCREEN_HEIGHT = 450;
constexpr int INITIAL_SPRITE_NUMBER = 3;

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_NAME);
    SetConfigFlags(FLAG_VSYNC_HINT);
    SetTargetFPS(GAME_FPS);

    SpriteManager spriteManager;
    SceneController sceneController(spriteManager, INITIAL_SPRITE_NUMBER);

    while (!WindowShouldClose()) {
        // Check hits
        sceneController.checkHits();

        // Update
        sceneController.moveSprites();
        sceneController.increaseDifficulty();

        //Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);
            sceneController.drawScene();
            DrawText("Hits: ", 5, 5, 25, LIGHTGRAY);
            DrawText(std::to_string(sceneController.hits).c_str(), 65, 5, 25, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
