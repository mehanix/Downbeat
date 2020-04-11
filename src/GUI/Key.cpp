#include "Key.h"
#include <iostream>


Key::Key(sf::Texture& t, sf::Texture& t_Pressed, sf::Vector2f pos, std::string kcode) : texture(t), texturePressed(t_Pressed), pos(pos), kbKeyCode(kcode) {
    sprite.setTexture(texture);
    sprite.setPosition(pos);
    std::cout<<"sunt o clapa"<<std::endl;
}

sf::Sprite& Key::getSprite() {
    return sprite;
}

