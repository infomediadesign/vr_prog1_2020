#include "raylib.h"

#include "Panel.h"

#include <utility>

Panel::Panel() = default;

Panel::Panel(ButtonList &&buttonList) {
    this->buttonList = std::move(buttonList);
    activeButtonID = getActiveButton();
}

std::size_t Panel::getActiveButton() {
    for (std::size_t id = 0; auto &button : buttonList) {
        if (button.buttonState == ButtonState::active)
            return id;
        id++;
    }

    return 0;
}

Button &Panel::operator[](std::size_t index) {
    if (index >= buttonList.size()) {
        exit(0);                                            // TODO: Do proper Exception handling here...
    }
    return buttonList[index];
}

void Panel::handleEvents() {
    if (IsKeyPressed(KEY_DOWN)) {
        activeButtonIncrement();
        return;
    }
    else
        if (IsKeyPressed(KEY_UP)) {
            activeButtonDecrement();
            return;
        }

    for (std::size_t id = 0; auto &button : buttonList) {   // NOTE: In order for the keys to work when the mouse pointer is pointing to them, this block should be at the top. But then we would still have to iterate here...
        if (button.buttonState == ButtonState::active && IsKeyDown(KEY_ENTER)) {
            button.eventHandler();
            return;
        }

        Rectangle bounds = {(float) button.pos.x,
                            (float) button.pos.y,
                            (float) button.textureNormal.width,    // TODO: active size might differ from "normal"
                            (float) button.textureNormal.height};  // TODO: active size might differ from "normal"

        if (CheckCollisionPointRec(GetMousePosition(), bounds)) {
            buttonList[activeButtonID].buttonState = ButtonState::normal;
            activeButtonID = id;
            button.buttonState = ButtonState::active;
            if(IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
                button.eventHandler();
        }
        id++;
    }
}

void Panel::draw() {
    for (const auto &button : buttonList) {
        if (button.buttonState == ButtonState::active)
            DrawTextureV(button.textureActive, button.pos, WHITE);
        else
            DrawTextureV(button.textureNormal, button.pos, WHITE);
    }
}

void Panel::alignCenter(float margin) {
    float offsetY = (float) GetScreenHeight() / 2 - calcMenuHeight(margin) / 2;
    for (auto &button : buttonList) {
        button.pos.x = (float) GetScreenWidth() / 2 - (float) button.textureNormal.width / 2;
        button.pos.y = offsetY;
        offsetY += margin;
    }
}

float Panel::calcMenuHeight(float margin) {
    float height = 0.0;
    for (const auto &button : buttonList) {
        height += (float) button.textureNormal.height;
    }
    height += ((float) buttonList.size() - 1) * margin;
    return height;
}

void Panel::activeButtonIncrement() {
    buttonList[activeButtonID].buttonState = ButtonState::normal;

    if (activeButtonID == buttonList.size() - 1)
        activeButtonID = 0;
    else activeButtonID++;

    buttonList[activeButtonID].buttonState = ButtonState::active;
}

void Panel::activeButtonDecrement() {
    buttonList[activeButtonID].buttonState = ButtonState::normal;

    if (activeButtonID == 0)
        activeButtonID = (std::size_t) buttonList.size() - 1;
    else
        activeButtonID--;

    buttonList[activeButtonID].buttonState = ButtonState::active;
}
