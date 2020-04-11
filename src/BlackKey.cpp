#include "BlackKey.h"

BlackKey::BlackKey(sf::Texture& t, sf::Texture& t_Pressed) : Key(t, t_Pressed) {

}

void BlackKey::playSound() {
    
}

void BlackKey::setPosition(int x, int y) {
    Key::sprite.setPosition(x,y);
}

sf::Sprite& BlackKey::getSprite() {
    return sprite;
}

