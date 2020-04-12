#ifndef PIANO_H_INCLUDED
#define PIANO_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Key.h"
/**
 * Piano: Singleton class that holds array of piano keys
 * Calculates black/white key positions.
 * Holds key textures.
 */
class Piano
{
private:
    static Piano *instance;
    std::vector<Key *> piano;
    sf::Texture tKeyWhite;
    sf::Texture tKeyBlack;
    sf::Texture tKeyWhitePressed;
    sf::Texture tKeyBlackPressed;
    Piano();
    Piano(Piano const &){};            // copy constructor is private
    Piano &operator=(Piano const &){}; // assignment operator is private

public:
    static Piano *getInstance()
    {
        if (!instance){
            instance = new Piano;
            std::cout<<"pianul a fost creat"<<std::endl;
        }
        else{
            std::cout<<"pianul a fost invocat"<<std::endl;
        }
        return instance;
    }
    ~Piano()
    {
        std::cout << "papa pian" << std::endl;
    }

    void setPositions();
    std::vector<Key *> &getKeys();
    Key* findKeyClicked(sf::Vector2f mouse);
    Key* findKeyPressed(int keyIndex);
};

#endif