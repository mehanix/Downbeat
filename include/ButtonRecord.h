#pragma once
#include "Button.h"
#include <string>
class ButtonRecord : public Button {
    std::string spriteState;
    sf::Texture* t_Save;
    sf::Texture* t_Record;
    public:
    ButtonRecord();
    ButtonRecord(sf::Texture& t_rec, sf::Texture& t_save);
    void press(bool value) override;
};