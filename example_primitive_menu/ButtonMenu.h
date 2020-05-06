#pragma once

#include <vector>

#include "Button.h"

class ButtonMenu {
private:
    typedef std::vector<Button> ButtonList;
    ButtonList buttonList;

    Button* activeButton = nullptr;

    float calcMenuHeight(float margin);

public:
    typedef ButtonList::iterator iterator;
    typedef ButtonList::const_iterator const_iterator;

    ButtonMenu();
    explicit ButtonMenu(ButtonList&& buttonList);

    iterator begin() { return buttonList.begin(); }

    iterator end() { return buttonList.end(); }

    Button &operator[](int index);

    void alignCenter(float margin);

    void handleEvents();

    void draw();
};
