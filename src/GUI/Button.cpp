#include "Button.h"
#include <iostream>
Button::Button()
{
    std::cout << "initializez buton.."<<std::endl;
    if (btnTexture.loadFromFile("res/btn_small.png"))
        btnSprite.setTexture(btnTexture);
    else
        std::cout << "eroare la incarcarea texturii" << std::endl;
}

sf::Sprite& Button::getSprite()
{
    return btnSprite;
}
