#ifndef WHITEKEY_H_INCLUDED
#define WHITEKEY_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "Key.h"
class WhiteKey : public Key {

    static sf::Texture t;
    static sf::Texture t_Pressed;
    public:
        WhiteKey(sf::Texture& t, sf::Texture& t_Pressed, sf::Vector2f pos, std::string kcode);
        void playSound();
};
#endif