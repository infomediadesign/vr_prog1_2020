#pragma once

class BaseGameState {
public:
    virtual void handleEvents() {}
    virtual void updateEntities() {}
    virtual void draw() {}
};
