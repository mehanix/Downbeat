#include "Button.h"
#include <iostream>
Button::Button(sf::Texture &t, sf::Texture &t_pressed) : texture(t), texturePressed(t_pressed)
{
    sprite.setTexture(t);
}

sf::Sprite& Button::getSprite()
{
    return sprite;
}

