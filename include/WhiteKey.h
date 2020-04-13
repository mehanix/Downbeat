#ifndef WHITEKEY_H_INCLUDED
#define WHITEKEY_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "Key.h"
#include <string>
class WhiteKey : public Key {

    sf::Texture t;
    sf::Texture t_Pressed;
    
    public:
        WhiteKey(sf::Texture& t, sf::Texture& t_Pressed,int noteId,std::string soundPath);
        void playSound();
        void setPosition(int x,int y) override;
        sf::Sprite& getSprite() override;
        void setPressed(bool value) override;

};
#endif