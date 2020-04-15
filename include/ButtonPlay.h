#pragma once
#include "Button.h"
class ButtonPlay : public Button {
     public:
    ButtonPlay() : Button() {};
    ButtonPlay(sf::Texture& t, sf::Texture& t_pressed) : Button(t,t_pressed) {
        sprite.setPosition(600,210);
    }
    void press(bool value) override;
};