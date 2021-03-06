#ifndef KEY_H_INCLUDED
#define KEY_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream>
/* 
    Key: Abstract class.
*/
class Key
{

protected:
    sf::Texture texture;
    sf::Texture texturePressed;
    sf::Sprite sprite;
    sf::Text label;
    sf::Vector2f pos;
    std::string kbKeyCode;
    sf::SoundBuffer buffer;
    sf::Sound sound;
    int noteId;

public:
    Key();
    Key(sf::Texture &t, sf::Texture &t_Pressed, int noteId);
    int getId();
    virtual sf::Sprite &getSprite() = 0;
    virtual void playSound() = 0;
    virtual void setPosition(int x, int y) = 0;
    virtual void setPressed(bool value) = 0;
    int &operator[](std::string s);
};
#endif