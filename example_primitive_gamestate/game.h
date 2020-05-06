#pragma once

#include "BaseGameState.h"
#include "MenuState.h"
#include "PlayState.h"

extern MenuState menuState;
extern PlayState playState;

extern BaseGameState* currentState;