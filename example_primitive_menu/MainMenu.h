#pragma once

#define BUTTONLIST_MAINMENU std::vector<Button> { \
                            Button{{0, 0}, LoadTexture("assets/btn_startgame.png"),LoadTexture("assets/btn_startgame_hover.png"), ButtonState::hover}, \
                            Button{{0, 0}, LoadTexture("assets/btn_startgame.png"),LoadTexture("assets/btn_startgame_hover.png")}, \
                            Button{{0, 0}, LoadTexture("assets/btn_credits.png"),LoadTexture("assets/btn_credits_hover.png")} \
                            }