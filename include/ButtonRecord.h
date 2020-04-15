#pragma once
#include "Button.h"
#include <string>
class ButtonRecord : public Button {
    std::string spriteState;
    sf::Texture* t_Save;
    sf::Texture* t_Record;
    public:
    ButtonRecord() : Button() {};
    ButtonRecord(sf::Texture& t_rec, sf::Texture& t_save) : Button() {
          t_Record = &t_rec;
          t_Save = &t_save;  
          getSprite().setTexture(*t_Record);
          getSprite().setPosition(70,210);
          spriteState = "record";
    };
    void press(bool value) override;
};