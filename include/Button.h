#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED
#include <SFML/Graphics.hpp>
class Button {
    sf::Texture btnTexture;
    public:
        Button();
        sf::Sprite& getSprite();
        sf::Sprite btnSprite;


};

#endif