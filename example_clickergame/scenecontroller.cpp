#include "scenecontroller.hpp"
#include <iostream>
#include "raylib.h"

SceneController::SceneController(SpriteManager &spriteManager, int initialSpritesNumber) : spriteManager(
        spriteManager) {
    for (int i = 0; i < initialSpritesNumber; i++)
        spriteManager.addSprite();
}

void SceneController::moveSprites() {
    int screenheight = GetScreenHeight();
    for (auto &sprite : spriteManager.sprites) {
        if (sprite.pos.y > (float) screenheight)
            spriteManager.respawnRandomWithRandomSprite(sprite);
        else
            sprite.pos.y += 1;
    }
}

void SceneController::drawScene() {
    for (auto sprite : spriteManager.sprites)
        DrawTextureV(sprite.texture, sprite.pos, WHITE);
}

void SceneController::increaseDifficulty() {
    difficultyFrameCounter++;

    if (((difficultyFrameCounter / 120) % 2) == 1) {    // TODO: Fixed value
        spriteManager.addSprite();
        difficultyFrameCounter = 0;
    }
}

void SceneController::checkHits() {
    for (auto &sprite : spriteManager.sprites) {
        Rectangle spriteBounds = {(float) sprite.pos.x,
                                  (float) sprite.pos.y,
                                  (float) sprite.texture.width,
                                  (float) sprite.texture.height};

        if (CheckCollisionPointRec(GetMousePosition(), spriteBounds)) {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
                hits++;
                spriteManager.respawnRandomWithRandomSprite(sprite);
                return;
            }
        }
    }
}
