#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED
#include <SFML/Graphics.hpp>
class Button {
     protected:
     sf::Texture texture;
     sf::Texture texturePressed;
     sf::Sprite sprite;

    public:
        Button() {};
        Button(sf::Texture &t, sf::Texture &t_pressed);
        virtual void press(bool value) = 0;
        sf::Sprite& getSprite();
        sf::Sprite btnSprite;

};

#endif