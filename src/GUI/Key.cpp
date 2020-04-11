#include "Key.h"
#include <iostream>


Key::Key(sf::Texture& t, sf::Texture& t_Pressed) : texture(t), texturePressed(t_Pressed) {
    sprite.setTexture(texture);
    sprite.setPosition(pos);
    std::cout<<"sunt o clapa"<<std::endl;
}

