#pragma once
#include "Button.h"
class ButtonPlay : public Button {
     public:
    ButtonPlay() : Button() {};
    ButtonPlay(sf::Texture& t, sf::Texture& t_pressed);
    void press(bool value) override;
};