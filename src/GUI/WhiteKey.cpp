#include "WhiteKey.h"

WhiteKey::WhiteKey(sf::Texture& t, sf::Texture& t_Pressed, std::string soundPath) : Key(t, t_Pressed) {
        buffer.loadFromFile("res/sounds/" + soundPath);
}

void WhiteKey::playSound() {
    sound.setBuffer(buffer);
    sound.play();
}


void WhiteKey::setPosition(int x,int y) {
    sprite.setPosition(x,y);
}

sf::Sprite& WhiteKey::getSprite() {
    return sprite;
}

void WhiteKey::setPressed(bool value) {
    if (value==true) {
        sprite.setTexture(texturePressed);
        playSound();
    }
    else {
        sprite.setTexture(texture);
        sound.stop();
    }
}

