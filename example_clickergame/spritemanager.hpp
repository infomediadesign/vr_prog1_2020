#pragma once

#include <vector>

#include "raylib.h"

#include "sprite.hpp"

class SpriteManager {
private:
    static constexpr int MARGIN_HORIZONTAL = 50;       // Todo: This depends on Sprite-Width
    static constexpr int MIN_NEGATIVE_SPACING = -100;
    static constexpr int MAX_NEGATIVE_SPACING = -700;

    typedef std::vector<Sprite> SpritesList;
    SpritesList sprites;
    std::vector<Texture2D> textures;

    Vector2 getRandomPosition();

    Texture &getRandomTexture();

public:
    SpriteManager();

    typedef SpritesList::iterator iterator;
    typedef SpritesList::const_iterator const_iterator;

    iterator begin() { return sprites.begin(); }

    iterator end() { return sprites.end(); }

    Sprite &operator[](int index);

    void respawnRandomWithRandomSprite(Sprite &sprite);

    void addSprite();
};