#pragma once

#include "BaseGameState.h"

class PlayState : public BaseGameState {
public:
    void handleEvents() override;

    void updateEntities() override;

    void draw() override;
};