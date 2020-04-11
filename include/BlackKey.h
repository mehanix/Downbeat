#ifndef BLACKKEY_H_INCLUDED
#define BLACKKEY_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "Key.h"

class BlackKey : public Key {

    public:
    BlackKey(sf::Texture& t, sf::Texture& t_Pressed, sf::Vector2f pos, std::string kcode);
    void playSound();
};

#endif