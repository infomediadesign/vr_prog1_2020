#include <vector>

#include "raylib.h"

#include "game.h"
#include "BaseGameState.h"
#include "MenuState.h"

#include "MainMenu.h"

MenuState::MenuState() {
    menu = new Panel(BUTTONLIST_MAINMENU);
    menu->alignCenter(BUTTON_Y_MARGIN);

    // Connect eventHandler to buttons
    menu->buttonList[0].eventHandler = []() { currentState = playState; };  // TODO: It may be necessary to do stuff before the switch, therefore the switch should only be allowed by calling a dedicated function.
}

MenuState::~MenuState() {
    delete menu;
}

void MenuState::handleEvents() {
    menu->handleEvents();
}

void MenuState::updateEntities() {

}

void MenuState::draw() {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    menu->draw();
    EndDrawing();
}
