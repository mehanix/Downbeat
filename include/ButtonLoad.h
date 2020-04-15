#pragma once
#include "Button.h"
class ButtonLoad : public Button {
     public:
    ButtonLoad() : Button() {};
    ButtonLoad(sf::Texture& t, sf::Texture& t_pressed) : Button(t,t_pressed) {
        sprite.setPosition(190,210);
    }
    void press(bool value) override;
};