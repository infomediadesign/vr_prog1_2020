#pragma once

#include "spritemanager.hpp"

class SceneController {
private:
    SpriteManager &spriteManager;
    int difficultyFrameCounter = 0;
public:
    int hits = 0;

    explicit SceneController(SpriteManager &spriteManager, int initialSpritesNumber);

    void increaseDifficulty();

    void checkHits();

    void moveSprites();

    void drawScene();
};
