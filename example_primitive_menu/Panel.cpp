#include "raylib.h"

#include "Panel.h"

#include <utility>
#include <iostream>

Panel::Panel() = default;

Panel::Panel(ButtonList&& buttonList) {
    this->buttonList = std::move(buttonList);
}

Button &Panel::operator[](int index) {
    if (index >= buttonList.size()) {
        exit(0);                                            // TODO: Do proper Exception handling here...
    }
    return buttonList[index];
}

void Panel::handleEvents() {
    for (auto &button : buttonList) {
        Rectangle bounds = {(float) button.pos.x,
                            (float) button.pos.y,
                            (float) button.normal.width,    // TODO: If hover, size might differ from "normal"
                            (float) button.normal.height};  // TODO: If hover, size might differ from "normal"

        if (CheckCollisionPointRec(GetMousePosition(), bounds)) {
            activeButton = &button;
            if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
                button.eventHandler();
        }
    }
}

void Panel::draw() {
    for (const auto &button : buttonList) {
        if (&button == activeButton)
            DrawTextureV(button.hover, button.pos, WHITE);
        else
            DrawTextureV(button.normal, button.pos, WHITE);
    }
}

void Panel::alignCenter(float margin) {
    float offsetY = (float) GetScreenHeight() / 2 - calcMenuHeight(margin) / 2;
    for (auto &button : buttonList) {
        button.pos.x = (float) GetScreenWidth() / 2 - (float) button.normal.width / 2;
        button.pos.y = offsetY;
        offsetY += margin;

        if(button.buttonState == ButtonState::hover)
            activeButton = &button;
    }
}

float Panel::calcMenuHeight(float margin) {
    float height = 0.0;
    for (const auto &button : buttonList) {
        height += (float) button.normal.height;
    }
    height += ((float) buttonList.size() - 1) * margin;
    return height;
}
