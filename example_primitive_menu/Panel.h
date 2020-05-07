#pragma once

#include <vector>

#include "Button.h"

class Panel {
private:
    float calcMenuHeight(float margin);

public:
    typedef std::vector<Button> ButtonList;
    ButtonList buttonList;

    typedef ButtonList::iterator iterator;
    typedef ButtonList::const_iterator const_iterator;

    Panel();
    explicit Panel(ButtonList&& buttonList);

    iterator begin() { return buttonList.begin(); }

    iterator end() { return buttonList.end(); }

    Button &operator[](int index);

    void alignCenter(float margin);

    void handleEvents();

    void draw();
};
