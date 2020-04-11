#include "Piano.h"
#include "MainWindow.h"
#include "WhiteKey.h"
Piano::Piano()
{
    tKeyWhite.loadFromFile("res/piano/key_white.png");
    tKeyWhitePressed.loadFromFile("res/piano/key_white_pressed.png");
    tKeyBlack.loadFromFile("res/piano/key_black.png");
    tKeyBlackPressed.loadFromFile("res/piano/key_black_pressed.png");
    int pos = 64;
    std::cout << "sunt un pian" << std::endl;
    for (int i = 0; i < 14; i++)
    {
        piano.push_back(new WhiteKey(tKeyWhite, tKeyWhitePressed, sf::Vector2f(pos, 280), "a"));
        pos += 48;
    }
}

std::vector<Key *> &Piano::getKeys()
{
    return piano;
}
Piano *Piano::instance = nullptr;