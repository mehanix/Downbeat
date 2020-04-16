#include "BlackKey.h"
#include "Recorder.h"
#include <cmath>
BlackKey::BlackKey(sf::Texture &t, sf::Texture &t_Pressed,int noteId, std::string soundPath) : Key(t, t_Pressed, noteId)
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
        if(!Recorder::isPlaying())
            sprite.setTexture(texturePressed);
        sound.setVolume(100);
        playSound();
    }
    else
    {
 sf::Clock clock; // starts the clock
        sprite.setTexture(texture);
        float c;
        while (true)
        {
            //double seconds = clock.getElapsedTime().asMilliseconds();
            //std::cout<<seconds<<std::endl;

            //Init statement for if (C++17)
            if (double seconds = clock.getElapsedTime().asMilliseconds(); seconds < 100)
            {
                //Atenuare sunet :) onKeyReleased
                c = std::lerp(100, 0, seconds / 100.0);
                //std::cout << seconds << " " << c << std::endl;
                sound.setVolume(c);
                if (c <= 5.0)
                {
                    break;
                }
            }
        }
       // sprite.setTexture(texture);
        sound.stop();
    }
}
