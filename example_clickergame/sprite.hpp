#pragma once

#include "raylib.h"

struct Sprite {
    Vector2 pos;
    Texture2D &texture;

    Sprite(Vector2 pos, Texture2D &texture);
};
