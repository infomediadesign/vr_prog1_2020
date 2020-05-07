#pragma once

#include "raylib.h"

enum ButtonState {
    normal, active
};

struct Button {
    Vector2 pos;
    Texture2D textureNormal;
    Texture2D textureActive;
    ButtonState buttonState = ButtonState::normal;

    void (*eventHandler)();            // TODO: Could be enhanced, e.g. by std::function
};
