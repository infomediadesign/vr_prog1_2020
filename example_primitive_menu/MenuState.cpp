#include <vector>

#include "raylib.h"

#include "game.h"
#include "BaseGameState.h"
#include "MenuState.h"

#include "MainMenu.h"

MenuState::MenuState() {
    menu = new Panel(BUTTONLIST_MAINMENU);
    menu->alignCenter(BUTTON_Y_MARGIN);

    menu->buttonList[0].eventHandler = []() { currentState = playState; };
}

MenuState::~MenuState() {
    delete menu;
}

void MenuState::handleEvents() {
    menu->handleEvents();
    if (IsKeyDown(KEY_ENTER)) currentState = playState;
}

void MenuState::updateEntities() {

}

void MenuState::draw() {
    BeginDrawing();
        ClearBackground(RAYWHITE);
        menu->draw();
    EndDrawing();
}
