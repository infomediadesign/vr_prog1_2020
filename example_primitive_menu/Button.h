#pragma once

#include "raylib.h"

enum ButtonState { normal, hover };

struct Button {
    Vector2 pos;
    Texture2D normal;
    Texture2D hover;
    ButtonState buttonState = ButtonState::normal;
};
