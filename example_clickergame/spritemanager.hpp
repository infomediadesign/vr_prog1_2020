#pragma once

#include <vector>

#include "raylib.h"

#include "sprite.hpp"

class SpriteManager {
private:
    static constexpr int MARGIN_HORIZONTAL = 50;       // Todo: This depends on Sprite-Width
    static constexpr int MIN_NEGATIVE_SPACING = -100;
    static constexpr int MAX_NEGATIVE_SPACING = -700;

    std::vector<Texture2D> textures;

    Vector2 getRandomPosition();

    Texture &getRandomTexture();

public:
    std::vector<Sprite> sprites;

    SpriteManager();

    void respawnRandomWithRandomSprite(Sprite &sprite);

    void addSprite();
};