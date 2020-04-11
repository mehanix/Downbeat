#include "WhiteKey.h"

WhiteKey::WhiteKey(sf::Texture& t, sf::Texture& t_Pressed) : Key(t, t_Pressed) {
    
}

void WhiteKey::playSound() {

}

void WhiteKey::setPosition(int x,int y) {
    Key::sprite.setPosition(x,y);
}

sf::Sprite& WhiteKey::getSprite() {
    return sprite;
}

