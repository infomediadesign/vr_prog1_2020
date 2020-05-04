#include "raylib.h"

#include "spritemanager.hpp"

SpriteManager::SpriteManager() {
    textures.push_back(LoadTexture("../pineapple.png"));
}

void SpriteManager::respawnRandomWithRandomSprite(Sprite &sprite) {
    sprite.pos = getRandomPosition();
    sprite.texture = getRandomTexture();
}

Texture &SpriteManager::getRandomTexture() {
    return (textures[GetRandomValue(0, (int) textures.size() - 1)]);
}

Vector2 SpriteManager::getRandomPosition() {
    return ((Vector2) {(float) GetRandomValue(0, GetScreenWidth() - MARGIN_HORIZONTAL), (float) GetRandomValue(MAX_NEGATIVE_SPACING, MIN_NEGATIVE_SPACING)});
}

void SpriteManager::addSprite() {
    sprites.emplace_back(getRandomPosition(), getRandomTexture());
}

Sprite &SpriteManager::operator[](int index) {
    if (index >= sprites.size()) {
        exit(0);                // TODO: Do proper Exception handling here...
    }
    return sprites[index];
}