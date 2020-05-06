#pragma once

#include "BaseGameState.h"
#include "ButtonMenu.h"

constexpr float BUTTON_Y_MARGIN = 100.0;

class MenuState : public BaseGameState {
public:
    MenuState();

  ~MenuState();

    void handleEvents() override;

    void updateEntities() override;

    void draw() override;

private:
    ButtonMenu* menu;
};
