#ifndef BLACKKEY_H_INCLUDED
#define BLACKKEY_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "Key.h"

class BlackKey : public Key {

    public:
    BlackKey(sf::Texture& t, sf::Texture& t_Pressed,int noteId, std::string soundPath);
    void playSound();
    void setPosition(int x,int y) override;
    sf::Sprite& getSprite() override;
    void setPressed(bool value) override;

};

#endif