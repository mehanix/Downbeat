#include "BlackKey.h"

BlackKey::BlackKey(sf::Texture &t, sf::Texture &t_Pressed, std::string soundPath) : Key(t, t_Pressed)
{
    buffer.loadFromFile("res/sounds/" + soundPath);
}

void BlackKey::playSound()
{
    sound.setBuffer(buffer);
    sound.play();
}

void BlackKey::setPosition(int x, int y)
{
    Key::sprite.setPosition(x, y);
}

sf::Sprite &BlackKey::getSprite()
{
    return sprite;
}

void BlackKey::setPressed(bool value)
{
    if (value == true)
    {
        sprite.setTexture(texturePressed);
        playSound();
    }
    else
    {
        sprite.setTexture(texture);
        sound.stop();
    }
}
