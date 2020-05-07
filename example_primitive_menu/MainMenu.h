#pragma once

/* Example menu structure - Please make sure that only one of the elements is marked as active.
 *
 */

#define BUTTON_DEFAULT_POS {0, 0}
#define BUTTON_STATE_NORMAL ButtonState::normal
#define BUTTON_STATE_ACTIVE ButtonState::active
#define BUTTON_EVENTHANDLER_EMPTY [](){}

#define BUTTONLIST_MAINMENU std::vector<Button> { \
                            Button{BUTTON_DEFAULT_POS, LoadTexture("assets/btn_startgame.png"),LoadTexture("assets/btn_startgame_hover.png"), BUTTON_STATE_ACTIVE, BUTTON_EVENTHANDLER_EMPTY }, \
                            Button{BUTTON_DEFAULT_POS, LoadTexture("assets/btn_highscore.png"),LoadTexture("assets/btn_highscore_hover.png"), BUTTON_STATE_NORMAL, BUTTON_EVENTHANDLER_EMPTY }, \
                            Button{BUTTON_DEFAULT_POS, LoadTexture("assets/btn_credits.png"),LoadTexture("assets/btn_credits_hover.png"), BUTTON_STATE_NORMAL, BUTTON_EVENTHANDLER_EMPTY } \
                            }