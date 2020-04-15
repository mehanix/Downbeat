#include "ButtonPlay.h"
#include "Recorder.h"
#include <fstream>
#include <cstring>
#include <iostream>

ButtonPlay::ButtonPlay(sf::Texture& t, sf::Texture& t_pressed) : Button(t, t_pressed)
{
    sprite.setPosition(635, 210);
}
void ButtonPlay::press(bool value)
{
    if (value == true)
    {
        //TODO set texture
        Recorder::play();
    }
}