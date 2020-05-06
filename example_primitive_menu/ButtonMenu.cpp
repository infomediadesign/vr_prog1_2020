#include "raylib.h"

#include "ButtonMenu.h"

#include <utility>

ButtonMenu::ButtonMenu() = default;

ButtonMenu::ButtonMenu(ButtonList buttonList) {
    //this->buttonList = std::move(buttonList);
    this->buttonList = buttonList;
}

Button &ButtonMenu::operator[](int index) {
    if (index >= buttonList.size()) {
        exit(0);                                            // TODO: Do proper Exception handling here...
    }
    return buttonList[index];
}

void ButtonMenu::handleEvents() {
    for (auto &button : buttonList) {
        Rectangle bounds = {(float) button.pos.x,
                            (float) button.pos.y,
                            (float) button.normal.width,    // TODO: If hover, size might differ from "normal"
                            (float) button.normal.height};  // TODO: If hover, size might differ from "normal"

        if (CheckCollisionPointRec(GetMousePosition(), bounds)) {
            activeButton = &button;
        }
    }
}

void ButtonMenu::draw() {
    for (const auto &button : buttonList) {
        if (&button == activeButton)
            DrawTextureV(button.hover, button.pos, WHITE);
        else
            DrawTextureV(button.normal, button.pos, WHITE);
    }
}

void ButtonMenu::alignCenter() {
    float offsetY = (float) GetScreenHeight() / 2 - calcMenuHeight() / 2;
    for (auto &button : buttonList) {
        button.pos.x = (float) GetScreenWidth() / 2 - (float) button.normal.width / 2;
        button.pos.y = offsetY;
        offsetY += BUTTON_Y_MARGIN;

        if(button.buttonState == ButtonState::hover)
            activeButton = &button;
    }
}

float ButtonMenu::calcMenuHeight() {
    float height = 0.0;
    for (const auto &button : buttonList) {
        height += (float) button.normal.height;
    }
    height += ((float) buttonList.size() - 1) * BUTTON_Y_MARGIN;
    return height;
}
