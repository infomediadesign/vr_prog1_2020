#pragma once

#include <vector>

#include "Button.h"

constexpr float BUTTON_Y_MARGIN = 100.0;

class ButtonMenu {
private:
    typedef std::vector<Button> ButtonList;
    ButtonList buttonList;

    Button* activeButton = nullptr;

    float calcMenuHeight();

public:
    typedef ButtonList::iterator iterator;
    typedef ButtonList::const_iterator const_iterator;

    ButtonMenu();
    explicit ButtonMenu(ButtonList buttonList);

    iterator begin() { return buttonList.begin(); }

    iterator end() { return buttonList.end(); }

    Button &operator[](int index);

    void alignCenter();

    void handleEvents();

    void draw();
};
