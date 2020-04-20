#pragma once
#include "Button.h"
class ButtonLoad : public Button {
     public:
    ButtonLoad();
    ButtonLoad(sf::Texture& t, sf::Texture& t_pressed);
    void press(bool value) override;
};