#include "Key.h"
#include <iostream>


Key::Key(sf::Texture& t, sf::Texture& t_Pressed, int n) : texture(t), texturePressed(t_Pressed), noteId(n) {
    sprite.setTexture(texture);
    sprite.setPosition(pos);
    std::cout<<"sunt o clapa"<<std::endl;
}

int Key::getId() {
    return noteId;
}