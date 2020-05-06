#pragma once

#include "BaseGameState.h"

class MenuState : public BaseGameState {
public:
    void handleEvents() override;

    void updateEntities() override;

    void draw() override;
};
