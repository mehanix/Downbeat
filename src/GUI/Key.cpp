#include "Key.h"
#include <iostream>

Key::Key(sf::Texture &t, sf::Texture &t_Pressed, int n) : texture(t), texturePressed(t_Pressed), noteId(n)
{
    sprite.setTexture(texture);
    sprite.setPosition(pos);
}

int Key::getId()
{
    return noteId;
}

// operator care returneaza id-ul notei.
int& Key::operator[](std::string s)
{
    if (s == "noteId")
        return noteId;
    
}
